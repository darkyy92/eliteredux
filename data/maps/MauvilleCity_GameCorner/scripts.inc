# 1 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 2 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_MapScripts:: @ 820FBB8
# 3 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.byte 0
# 4 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 5 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    @ Game Corner prices
# 6 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set PORYGON_COINS,  	10
# 7 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set MUNCHLAX_COINS,  	10
# 8 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set VULPIX_COINS,  	10
# 9 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set SANDSHREW_COINS,  	10
# 10 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set RATTATA_COINS,  	10
# 11 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set MEOWTH_COINS,  	10
# 12 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set GRIMER_COINS,  	10
# 13 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set DIGLETT_COINS,  	10
# 14 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set GEODUDE_COINS,  	10
# 15 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set RAICHU_COINS,  	10
# 16 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set MAROWAK_COINS,  	10
# 17 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set EXEGGUTOR_COINS,  	10
# 18 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set STARTER_COINS, 	10
# 19 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set DOLL_COINS,  		10
# 20 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 21 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set COINS_PRICE_50,    500
# 22 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set COINS_PRICE_500,   5000
# 23 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set COINS_PRICE_5000,  50000
# 24 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 25 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CoinsClerk:: @ 820FBB9
# 26 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 27 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 28 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
# 29 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE, 1
# 30 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 31 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NeedCoinCase
# 32 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WereYouLookingForCoins
# 33 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 34 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmoneybox 0, 0, 0
# 35 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 6
# 36 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50
# 37 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 38 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50:: @ 820FBE5
# 39 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
# 40 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 41 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
# 42 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
# 43 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_Buy5000Coins
# 44 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
# 45 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 46 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 47 "data/maps/MauvilleCity_GameCorner/scripts.pory"
@ Unused
# 48 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault500:: @ 820FC0C
# 49 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
# 50 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 51 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
# 52 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
# 53 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
# 54 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 55 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 56 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Buy50Coins:: @ 820FC33
# 57 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 58 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_TEMP_1, (MAX_COINS + 1 - 50)
# 59 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_ge MauvilleCity_GameCorner_EventScript_NoRoomForCoins
# 60 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkmoney COINS_PRICE_50, 0
# 61 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 62 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NotEnoughMoney
# 63 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins 50
# 64 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removemoney COINS_PRICE_50, 0
# 65 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatemoneybox 0, 0
# 66 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 6
# 67 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 68 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
# 69 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 70 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 71 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 72 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 73 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 74 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Buy500Coins:: @ 820FC75
# 75 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 76 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_TEMP_1, (MAX_COINS + 1 - 500)
# 77 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_ge MauvilleCity_GameCorner_EventScript_NoRoomForCoins
# 78 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkmoney COINS_PRICE_500, 0
# 79 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 80 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NotEnoughMoney
# 81 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins 500
# 82 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removemoney COINS_PRICE_500, 0
# 83 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatemoneybox 0, 0
# 84 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 6
# 85 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 86 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
# 87 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 88 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 89 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 90 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 91 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 92 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Buy5000Coins::
# 93 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8005, COINS_PRICE_5000
# 94 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 95 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_TEMP_1, (MAX_COINS + 1 - 5000)
# 96 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_ge MauvilleCity_GameCorner_EventScript_NoRoomForCoins
# 97 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
# 98 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 99 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NotEnoughMoney
# 100 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins 5000
# 101 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special SubtractMoneyFromVar0x8005
# 102 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatemoneybox 0, 0
# 103 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 6
# 104 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 105 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
# 106 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 107 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 108 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 109 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 110 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 111 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NeedCoinCase:: @ 820FCB7
# 112 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
# 113 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 114 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 115 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 116 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NotEnoughMoney:: @ 820FCC1
# 117 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
# 118 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 119 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 120 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 121 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 122 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 123 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CancelBuyCoins:: @ 820FCD1
# 124 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
# 125 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 126 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 127 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 128 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 129 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 130 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForCoins:: @ 820FCE1
# 131 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
# 132 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 133 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 134 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 135 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 136 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 137 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PrizeCornerDolls:: @ 820FCF1
# 138 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 139 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 140 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
# 141 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE, 1
# 142 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
# 143 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage
# 144 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 145 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 146 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 147 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage:: @ 820FD0D
# 148 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 149 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 150 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 0
# 151 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 152 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize
# 153 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 154 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize:: @ 820FD20
# 155 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 156 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 157 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize
# 158 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 159 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseDollPrize:: @ 820FD2B
# 160 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS, FALSE
# 161 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 162 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_TreeckoDoll
# 163 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_TorchicDoll
# 164 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_MudkipDoll
# 165 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_CancelDollSelect
# 166 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelDollSelect
# 167 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 168 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 169 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TreeckoDoll:: @ 820FD67
# 170 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 1
# 171 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname 0, DECOR_TREECKO_DOLL
# 172 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize
# 173 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 174 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TorchicDoll:: @ 820FD75
# 175 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 2
# 176 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname 0, DECOR_TORCHIC_DOLL
# 177 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize
# 178 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 179 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_MudkipDoll:: @ 820FD83
# 180 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 3
# 181 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname 0, DECOR_MUDKIP_DOLL
# 182 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize
# 183 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 184 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ConfirmDollPrize:: @ 820FD91
# 185 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
# 186 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, NO
# 187 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_CancelDollSelect
# 188 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_TEMP_1
# 189 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll
# 190 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_BuyTorchicDoll
# 191 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_BuyMudkipDoll
# 192 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 193 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 194 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll:: @ 820FDCB
# 195 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 196 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_TEMP_2, DOLL_COINS
# 197 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
# 198 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname 1, DECOR_TREECKO_DOLL
# 199 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TREECKO_DOLL
# 200 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 201 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForDoll
# 202 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins DOLL_COINS
# 203 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	adddecoration DECOR_TREECKO_DOLL
# 204 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 205 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 206 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 207 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 208 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 209 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 210 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTorchicDoll:: @ 820FE05
# 211 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 212 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_TEMP_2, DOLL_COINS
# 213 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
# 214 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname 1, DECOR_TORCHIC_DOLL
# 215 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TORCHIC_DOLL
# 216 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 217 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForDoll
# 218 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins DOLL_COINS
# 219 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	adddecoration DECOR_TORCHIC_DOLL
# 220 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 221 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 222 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 223 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 224 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 225 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 226 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyMudkipDoll:: @ 820FE3F
# 227 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 228 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_TEMP_2, DOLL_COINS
# 229 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
# 230 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname 1, DECOR_MUDKIP_DOLL
# 231 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_MUDKIP_DOLL
# 232 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 233 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForDoll
# 234 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins DOLL_COINS
# 235 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	adddecoration DECOR_MUDKIP_DOLL
# 236 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 237 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 238 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 239 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 240 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 241 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 242 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll:: @ 820FE79
# 243 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
# 244 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 245 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 246 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 247 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForDoll:: @ 820FE87
# 248 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 249 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 250 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 251 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 252 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CancelDollSelect:: @ 820FE92
# 253 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
# 254 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 0
# 255 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 256 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 257 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 258 "data/maps/MauvilleCity_GameCorner/scripts.pory"
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Rare Pokemon Prizes @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
# 259 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 260 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PrizeCornerPokemon::
# 261 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 262 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 263 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPokemon, MSGBOX_DEFAULT
# 264 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE, 1
# 265 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
# 266 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_ChoosePokemonPrizeMessage
# 267 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 268 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 269 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 270 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChoosePokemonPrizeMessage::
# 271 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPokemon
# 272 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 273 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 0
# 274 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 275 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChoosePokemonPrize
# 276 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 277 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChoosePokemonPrize::
# 278 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_GAMECORNER_POKEMON
# 279 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special ShowScrollableMultichoice
# 280 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitstate
# 281 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 282 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_Porygon
# 283 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_Munchlax
# 284 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_Vulpix
# 285 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_Sandshrew
# 286 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 4, MauvilleCity_GameCorner_EventScript_Rattata
# 287 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 5, MauvilleCity_GameCorner_EventScript_Meowth
# 288 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 6, MauvilleCity_GameCorner_EventScript_Grimer
# 289 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 7, MauvilleCity_GameCorner_EventScript_Diglett
# 290 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 8, MauvilleCity_GameCorner_EventScript_Geodude
# 291 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 9, MauvilleCity_GameCorner_EventScript_Raichu
# 292 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 10, MauvilleCity_GameCorner_EventScript_Marowak
# 293 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 11, MauvilleCity_GameCorner_EventScript_Exeggutor
# 294 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 12, MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
# 295 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
# 296 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 297 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 298 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Porygon::
# 299 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_PORYGON
# 300 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8006, PORYGON_COINS
# 301 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize
# 302 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 303 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Munchlax::
# 304 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_MUNCHLAX
# 305 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8006, MUNCHLAX_COINS
# 306 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize
# 307 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 308 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Vulpix::
# 309 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_VULPIX_ALOLAN
# 310 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8006, VULPIX_COINS
# 311 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize
# 312 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 313 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Sandshrew::
# 314 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_SANDSHREW_ALOLAN
# 315 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8006, SANDSHREW_COINS
# 316 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize
# 317 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 318 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Rattata::
# 319 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_RATTATA_ALOLAN
# 320 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8006, RATTATA_COINS
# 321 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize
# 322 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 323 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Meowth::
# 324 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_MEOWTH_ALOLAN
# 325 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8006, MEOWTH_COINS
# 326 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize
# 327 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 328 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Grimer::
# 329 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_GRIMER_ALOLAN
# 330 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8006, GRIMER_COINS
# 331 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize
# 332 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 333 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Diglett::
# 334 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_DIGLETT_ALOLAN
# 335 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8006, DIGLETT_COINS
# 336 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize
# 337 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 338 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Geodude::
# 339 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_GEODUDE_ALOLAN
# 340 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8006, GEODUDE_COINS
# 341 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize
# 342 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 343 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Raichu::
# 344 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_RAICHU_ALOLAN
# 345 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8006, RAICHU_COINS
# 346 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize
# 347 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 348 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Marowak::
# 349 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_MAROWAK_ALOLAN
# 350 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8006, MAROWAK_COINS
# 351 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize
# 352 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 353 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Exeggutor::
# 354 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_EXEGGUTOR_ALOLAN
# 355 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8006, EXEGGUTOR_COINS
# 356 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize
# 357 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 358 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize::
# 359 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferspeciesname 0, VAR_TEMP_1
# 360 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsThePokemonX, MSGBOX_YESNO
# 361 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, NO
# 362 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
# 363 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_0x8007
# 364 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_0x8007, VAR_0x8006
# 365 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPokemon
# 366 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReceivePokemon
# 367 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 368 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CancelPokemonSelect::
# 369 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
# 370 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 0
# 371 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 372 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 373 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 374 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPokemon::
# 375 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
# 376 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChoosePokemonPrizeMessage
# 377 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 378 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 379 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReceivePokemon::
# 380 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
# 381 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins VAR_0x8006
# 382 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 383 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special GetStaticEncounterLevel
# 384 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon VAR_TEMP_1, VAR_0x800A, ITEM_NONE
# 385 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 0
# 386 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_ReceivePokemonParty
# 387 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 1
# 388 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_ReceivePokemonPC
# 389 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 390 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 391 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReceivePokemonParty::
# 392 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call MauvilleCity_GameCorner_EventScript_ReceivedPokemonFanfare
# 393 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 394 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, NO
# 395 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_TakeCareOfPokemon
# 396 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 397 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 398 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_TakeCareOfPokemon
# 399 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 400 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReceivePokemonPC::
# 401 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call MauvilleCity_GameCorner_EventScript_ReceivedPokemonFanfare
# 402 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 403 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, NO
# 404 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_SendPokemonToPC
# 405 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 406 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_SendPokemonToPC
# 407 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 408 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SendPokemonToPC::
# 409 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_TransferredToPC
# 410 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_TakeCareOfPokemon
# 411 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 412 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReceivedPokemonFanfare::
# 413 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferspeciesname 0, VAR_TEMP_1
# 414 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 415 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_PlayerReceivedPokemon
# 416 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 417 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitfanfare
# 418 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	@ bufferspeciesname 0, VAR_TEMP_1
# 419 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	return
# 420 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 421 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TakeCareOfPokemon::
# 422 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferspeciesname 0, VAR_TEMP_1
# 423 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_TakeCareOfPokemon, MSGBOX_DEFAULT
# 424 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 0
# 425 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 426 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 427 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 428 "data/maps/MauvilleCity_GameCorner/scripts.pory"
@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Starter Pokemon Prizes @@@@@@@@@@@@@@@@@@@@@@@@@@@@
# 429 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 430 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PrizeCornerStarter::
# 431 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 432 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 433 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPokemon, MSGBOX_DEFAULT
# 434 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE, 1
# 435 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
# 436 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_ChooseStarterPrizeMessage
# 437 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 438 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 439 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 440 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseStarterPrizeMessage::
# 441 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichStarterType
# 442 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 443 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 0
# 444 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 445 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	multichoice 0, 0, MULTI_GRASS_FIRE_WATER, 0
# 446 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 447 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_ChooseGrassStarter
# 448 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_ChooseFireStarter
# 449 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_ChooseWaterStarter
# 450 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
# 451 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case MULTI_B_PRESSED, MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
# 452 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
# 453 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 454 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 455 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseGrassStarter::
# 456 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_GAMECORNER_GRASS_STARTERS
# 457 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8006, STARTER_COINS
# 458 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special ShowScrollableMultichoice
# 459 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitstate
# 460 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 461 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_Bulbasaur
# 462 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_Chikorita
# 463 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_Treecko
# 464 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_Turtwig
# 465 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 4, MauvilleCity_GameCorner_EventScript_Snivy
# 466 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 5, MauvilleCity_GameCorner_EventScript_Chespin
# 467 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 6, MauvilleCity_GameCorner_EventScript_Rowlet
# 468 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 7, MauvilleCity_GameCorner_EventScript_Grookey
# 469 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 8, MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
# 470 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
# 471 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 472 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 473 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseFireStarter::
# 474 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_GAMECORNER_FIRE_STARTERS
# 475 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8006, STARTER_COINS
# 476 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special ShowScrollableMultichoice
# 477 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitstate
# 478 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 479 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_Charmander
# 480 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_Cyndaquil
# 481 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_Torchic
# 482 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_Chimchar
# 483 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 4, MauvilleCity_GameCorner_EventScript_Tepig
# 484 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 5, MauvilleCity_GameCorner_EventScript_Fennekin
# 485 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 6, MauvilleCity_GameCorner_EventScript_Litten
# 486 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 7, MauvilleCity_GameCorner_EventScript_Scorbunny
# 487 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 8, MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
# 488 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
# 489 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 490 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 491 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseWaterStarter::
# 492 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_GAMECORNER_WATER_STARTERS
# 493 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8006, STARTER_COINS
# 494 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special ShowScrollableMultichoice
# 495 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitstate
# 496 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 497 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_Squirtle
# 498 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_Totodile
# 499 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_Mudkip
# 500 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_Piplup
# 501 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 4, MauvilleCity_GameCorner_EventScript_Oshawott
# 502 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 5, MauvilleCity_GameCorner_EventScript_Froakie
# 503 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 6, MauvilleCity_GameCorner_EventScript_Popplio
# 504 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 7, MauvilleCity_GameCorner_EventScript_Sobble
# 505 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 8, MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
# 506 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
# 507 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 508 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 509 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Bulbasaur::
# 510 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_BULBASAUR
# 511 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 512 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 513 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Chikorita::
# 514 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_CHIKORITA
# 515 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 516 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 517 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Treecko::
# 518 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_TREECKO
# 519 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 520 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 521 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Turtwig::
# 522 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_TURTWIG
# 523 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 524 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 525 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Snivy::
# 526 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_SNIVY
# 527 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 528 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 529 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Chespin::
# 530 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_CHESPIN
# 531 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 532 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 533 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Rowlet::
# 534 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_ROWLET
# 535 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 536 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 537 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Grookey::
# 538 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_GROOKEY
# 539 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 540 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 541 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Charmander::
# 542 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_CHARMANDER
# 543 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 544 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 545 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Cyndaquil::
# 546 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_CYNDAQUIL
# 547 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 548 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 549 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Torchic::
# 550 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_TORCHIC
# 551 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 552 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 553 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Chimchar::
# 554 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_CHIMCHAR
# 555 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 556 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 557 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Tepig::
# 558 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_TEPIG
# 559 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 560 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 561 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Fennekin::
# 562 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_FENNEKIN
# 563 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 564 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 565 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Litten::
# 566 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_LITTEN
# 567 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 568 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 569 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Squirtle::
# 570 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_SQUIRTLE
# 571 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 572 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 573 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Totodile::
# 574 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_TOTODILE
# 575 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 576 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 577 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Mudkip::
# 578 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_MUDKIP
# 579 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 580 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 581 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Piplup::
# 582 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_PIPLUP
# 583 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 584 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 585 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Oshawott::
# 586 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_OSHAWOTT
# 587 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 588 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 589 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Froakie::
# 590 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_FROAKIE
# 591 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 592 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 593 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Popplio::
# 594 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_POPPLIO
# 595 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 596 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 597 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Scorbunny::
# 598 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_SCORBUNNY
# 599 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 600 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 601 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Sobble::
# 602 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_SOBBLE
# 603 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
# 604 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 605 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize::
# 606 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferspeciesname 0, VAR_TEMP_1
# 607 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsThePokemonX, MSGBOX_YESNO
# 608 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, NO
# 609 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
# 610 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_0x8007
# 611 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_0x8007, VAR_0x8006
# 612 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForStarter
# 613 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReceivePokemon
# 614 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 615 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForStarter::
# 616 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
# 617 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseStarterPrizeMessage
# 618 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 619 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 620 "data/maps/MauvilleCity_GameCorner/scripts.pory"
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
# 621 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 622 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 623 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Woman2:: @ 8210125
# 624 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay, MSGBOX_NPC
# 625 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 626 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 627 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Gentleman:: @ 821012E
# 628 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
# 629 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 630 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 631 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Girl:: @ 8210137
# 632 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 633 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 634 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 635 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne, MSGBOX_YESNO
# 636 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, NO
# 637 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_DeclineStarterDoll
# 638 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_STARTER_MON
# 639 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
# 640 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
# 641 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
# 642 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 643 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 644 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll:: @ 821017C
# 645 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname 1, DECOR_TREECKO_DOLL
# 646 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TREECKO_DOLL
# 647 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 648 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
# 649 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
# 650 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givedecoration DECOR_TREECKO_DOLL
# 651 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 652 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 653 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 654 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 655 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_GiveTorchicDoll:: @ 82101A6
# 656 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname 1, DECOR_TORCHIC_DOLL
# 657 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TORCHIC_DOLL
# 658 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 659 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
# 660 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
# 661 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givedecoration DECOR_TORCHIC_DOLL
# 662 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 663 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 664 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 665 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 666 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_GiveMudkipDoll:: @ 82101D0
# 667 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname 1, DECOR_MUDKIP_DOLL
# 668 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_MUDKIP_DOLL
# 669 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 670 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
# 671 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
# 672 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givedecoration DECOR_MUDKIP_DOLL
# 673 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 674 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 675 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 676 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 677 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll:: @ 82101FA
# 678 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 679 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_YouWantItButNotNow, MSGBOX_DEFAULT
# 680 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 681 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 682 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 683 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_DeclineStarterDoll:: @ 8210209
# 684 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DontBeNegative, MSGBOX_DEFAULT
# 685 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 686 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 687 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 688 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll:: @ 8210213
# 689 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CantWinJackpot, MSGBOX_DEFAULT
# 690 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 691 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 692 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 693 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PokefanM:: @ 821021D
# 694 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 695 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 696 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE, 1
# 697 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
# 698 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_TryGive20Coins
# 699 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
# 700 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 701 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 702 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 703 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TryGive20Coins:: @ 821023D
# 704 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_RECEIVED_20_COINS, MauvilleCity_GameCorner_EventScript_PokefanMNormal
# 705 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 706 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_TEMP_1, 1  @ Only give 20 coins if player has no coins
# 707 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_ge MauvilleCity_GameCorner_EventScript_PokefanMNormal
# 708 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_20_COINS
# 709 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins 20
# 710 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
# 711 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 712 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_PokefanMNormal
# 713 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 714 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 715 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PokefanMNormal:: @ 821026B
# 716 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
# 717 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 718 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 719 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 720 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_OldMan:: @ 8210279
# 721 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 722 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 723 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
# 724 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 725 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 726 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 727 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Cook:: @ 8210289
# 728 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 729 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 730 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
# 731 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 732 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 733 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 734 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Man:: @ 8210299
# 735 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 736 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 737 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
# 738 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 739 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 740 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 741 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NPCReturnToSlots:: @ 82102A9
# 742 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 743 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 744 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmovement 0
# 745 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 746 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 747 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 748 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Maniac:: @ 82102B6
# 749 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 750 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 751 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DifficultToStopOn7, MSGBOX_DEFAULT
# 752 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 753 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 754 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 755 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Woman:: @ 82102C6
# 756 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 757 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 758 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
# 759 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 760 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 761 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 762 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine0:: @ 82102D6
# 763 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 764 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE, 1
# 765 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 766 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
# 767 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 0
# 768 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 769 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 770 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 771 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 772 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 773 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine1:: @ 82102F6
# 774 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 775 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE, 1
# 776 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 777 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
# 778 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 1
# 779 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 780 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 781 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 782 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 783 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 784 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine2:: @ 8210316
# 785 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 786 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE, 1
# 787 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 788 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
# 789 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 2
# 790 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 791 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 792 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 793 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 794 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 795 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine3:: @ 8210336
# 796 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 797 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE, 1
# 798 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 799 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
# 800 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 3
# 801 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 802 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 803 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 804 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 805 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 806 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine4:: @ 8210356
# 807 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 808 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE, 1
# 809 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 810 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
# 811 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 4
# 812 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 813 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 814 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 815 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 816 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 817 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine5:: @ 8210376
# 818 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 819 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE, 1
# 820 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 821 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
# 822 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 5
# 823 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 824 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 825 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 826 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 827 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 828 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine6:: @ 8210396
# 829 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 830 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE, 1
# 831 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 832 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
# 833 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 6
# 834 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 835 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 836 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 837 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 838 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 839 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine7:: @ 82103B6
# 840 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 841 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE, 1
# 842 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 843 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
# 844 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 7
# 845 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 846 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 847 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 848 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 849 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 850 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine8:: @ 82103D6
# 851 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 852 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE, 1
# 853 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 854 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
# 855 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 8
# 856 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 857 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 858 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 859 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 860 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 861 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine9:: @ 82103F6
# 862 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 863 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE, 1
# 864 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 865 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
# 866 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 9
# 867 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 868 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 869 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 870 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 871 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 872 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine10:: @ 8210416
# 873 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 874 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE, 1
# 875 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 876 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
# 877 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 10
# 878 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 879 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 880 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 881 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 882 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 883 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine11:: @ 8210436
# 884 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 885 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE, 1
# 886 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 887 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
# 888 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 11
# 889 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 890 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 891 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 892 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 893 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 894 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoCoinCase:: @ 8210456
# 895 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
# 896 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 897 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 898 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 899 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner: @ 8210460
# 900 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "This is Mauville Game Corner.$"
# 901 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 902 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins: @ 821047E
# 903 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Okay, you wanted some Coins for\n"
# 904 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the games?\p"
# 905 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "But you don't have a Coin Case for\n"
# 906 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "stowing the Coins.$"
# 907 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 908 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_WereYouLookingForCoins: @ 82104DF
# 909 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Were you looking for Coins?\p"
# 910 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's ¥500 for 50 Coins.\n"
# 911 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Would you like some?$"
# 912 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 913 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins: @ 8210529
# 914 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Thank you very much!\n"
# 915 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here are your Coins!$"
# 916 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 917 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DontHaveEnoughMoney: @ 8210553
# 918 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Um… You don't appear to have\n"
# 919 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "enough money…$"
# 920 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 921 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CoinCaseIsFull: @ 821057E
# 922 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh?\n"
# 923 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Your Coin Case is full.$"
# 924 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 925 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DontNeedCoinsThen: @ 821059A
# 926 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh… You don't need Coins, then?\n"
# 927 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Good luck on your adventure!$"
# 928 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 929 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes: @ 82105D7
# 930 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Welcome.\p"
# 931 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You can exchange your Coins for\n"
# 932 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "prizes here.$"
# 933 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 934 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_WhichPrize: @ 821060D
# 935 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Which prize would you like?$"
# 936 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 937 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_SendToYourHomePC: @ 8210646
# 938 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Thank you!\n"
# 939 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "We'll send it to your PC at home.$"
# 940 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 941 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NotEnoughCoins: @ 8210673
# 942 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You don't have enough Coins.$"
# 943 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 944 "data/maps/MauvilleCity_GameCorner/scripts.pory"
@ Unused
# 945 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NoRoomForPlacingDecor: @ 8210690
# 946 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "There isn't any room available for\n"
# 947 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "placing {STR_VAR_1}.$"
# 948 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 949 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_OhIsThatSo: @ 82106BF
# 950 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh, is that so? \n"
# 951 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You need to save some Coins before\l"
# 952 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "coming back here.$"
# 953 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 954 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_SoYourChoiceIsX: @ 8210705
# 955 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "So your choice is {STR_VAR_1}?$"
# 956 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 957 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_HereYouGo: @ 821071B
# 958 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here you go!$"
# 959 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 960 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_ExchangeCoinsForPokemon:
# 961 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Welcome.\p"
# 962 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You can exchange your Coins for\n"
# 963 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "rare Pokémon here.$"
# 964 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 965 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_WhichPokemon:
# 966 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Which Pokémon would you like?$"
# 967 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 968 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_SoYourChoiceIsThePokemonX:
# 969 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "So your choice is {STR_VAR_1}?$"
# 970 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 971 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_ThanksPleaseTakePokemon:
# 972 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Thank you!\p"
# 973 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Please take your new Pokémon.$"
# 974 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 975 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_PlayerReceivedPokemon:
# 976 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "{PLAYER} received {STR_VAR_1}!$"
# 977 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 978 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_TakeCareOfPokemon:
# 979 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Take good care of {STR_VAR_1}!$"
# 980 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 981 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_WhichStarterType:
# 982 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Which Type of Pokémon would you like?$"
# 983 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 984 "data/maps/MauvilleCity_GameCorner/scripts.pory"
@ Unused
# 985 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CantCarryAnyMore: @ 8210728
# 986 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh, you can't carry any more than that.$"
# 987 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 988 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne: @ 8210750
# 989 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I made a mistake and got two of\n"
# 990 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the same Dolls.\p"
# 991 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Would you like one of them?$"
# 992 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 993 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_HereYouGo2: @ 821079C
# 994 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here you go!$"
# 995 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 996 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_YouWantItButNotNow: @ 82107A9
# 997 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Huh?\n"
# 998 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You want it, but not right now?$"
# 999 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1000 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DontBeNegative: @ 82107CE
# 1001 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh, don't be so negative!\n"
# 1002 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You can have this!$"
# 1003 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1004 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CantWinJackpot: @ 82107FB
# 1005 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "There's a prize I want, but I can't win\n"
# 1006 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the jackpot.$"
# 1007 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1008 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor: @ 8210830
# 1009 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Hey, kid, if you want to play here,\n"
# 1010 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "you need a Coin Case.\p"
# 1011 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I think the young lady next door\n"
# 1012 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "had one. Go see her!$"
# 1013 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1014 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins: @ 82108A0
# 1015 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "My luck can only last so long.\n"
# 1016 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "This is too much for me.\l"
# 1017 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here, take some Coins!$"
# 1018 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1019 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone: @ 82108EF
# 1020 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Mauville has something for\n"
# 1021 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "everyone.\p"
# 1022 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "For me, it's the Game Corner.$"
# 1023 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1024 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates: @ 8210932
# 1025 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The Roulette tables have different\n"
# 1026 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "rates.\p"
# 1027 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Check your Coins if you're going to\n"
# 1028 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "pick a table.$"
# 1029 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1030 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime: @ 821098E
# 1031 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's easy to lose track of time in here. \n"
# 1032 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I should get back to work.$"
# 1033 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1034 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay: @ 82109D3
# 1035 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Coins are needed to play here\n"
# 1036 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "in the Game Corner.$"
# 1037 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1038 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_RouletteOnlyLuck: @ 8210A05
# 1039 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "This Roulette thing…\n"
# 1040 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's rather demanding.\p"
# 1041 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Win or lose, it's only by luck.$"
# 1042 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1043 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed: @ 8210A51
# 1044 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Up to three Coins can be used to play\n"
# 1045 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the Slots.$"
# 1046 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1047 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DifficultToStopOn7: @ 8210A82
# 1048 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's very difficult to make it stop\n"
# 1049 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "right on “7.”\p"
# 1050 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "If it stops on “7” during the Reel Time\n"
# 1051 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "bonus game, you'll receive extra Coins.$"
# 1052 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1053 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo: @ 8210B04
# 1054 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here's some information for you\n"
# 1055 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "about the Slots.\p"
# 1056 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The more lightning bolts you stock,\n"
# 1057 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the more Reel Time chances you get.\p"
# 1058 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "In a game with the maximum five\n"
# 1059 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Reel Time chances…\p"
# 1060 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It is possible to receive four regular\n"
# 1061 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "bonuses, then a big bonus.\p"
# 1062 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "That would total 660 Coins, but it's\n"
# 1063 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "very difficult to get.$"
# 1064 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1065 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase: @ 8210C2E
# 1066 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You can't play if you don't have\n"
# 1067 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "a Coin Case.$"

MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle::
# 1071 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 1072 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 1073 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_2
# 1096 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_1, MSGBOX_NPC
MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_1:
# 1098 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
	end

MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_2:
# 1075 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checktrainerflag TRAINER_SINNOH_MEGAS_MAUVILLE_GAME_CORNER
	goto_if 0, MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_5
# 1092 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_1, MSGBOX_NPC
	goto MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_1

MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_5:
# 1076 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_0, MSGBOX_YESNO
# 1077 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_8
# 1088 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_1, MSGBOX_NPC
	goto MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_1

MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_8:
# 1078 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_1, MSGBOX_NPC
# 1079 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	trainerbattle_no_intro TRAINER_SINNOH_MEGAS_MAUVILLE_GAME_CORNER, MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_2
# 1080 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_1, MSGBOX_NPC
# 1081 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1082 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	giveitem ITEM_INFERNAPENITE, 1
# 1083 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	giveitem ITEM_TORTERRANITE, 1
# 1084 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	giveitem ITEM_EMPOLEONITE, 1
# 1085 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_1


MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_0:
# 1076 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "FUCK YOU???$"

MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_1:
# 1078 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "FUCK YOU!!!$"

MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_2:
# 1079 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "FUCK ME???$"
