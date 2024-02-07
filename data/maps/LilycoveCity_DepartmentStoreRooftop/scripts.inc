# 1 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 2 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_MapScripts:: @ 8220207
# 3 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_DepartmentStoreRooftop_OnTransition
# 4 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.byte 0
# 5 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 6 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_OnTransition: @ 822020D
# 7 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	getpricereduction POKENEWS_LILYCOVE
# 8 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	compare VAR_RESULT, TRUE
# 9 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_ShowSaleWoman
# 10 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	compare VAR_RESULT, FALSE
# 11 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_HideSaleWoman
# 12 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 13 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 14 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_ShowSaleWoman:: @ 8220227
# 15 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
# 16 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	return
# 17 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 18 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_HideSaleWoman:: @ 822022B
# 19 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
# 20 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	return
# 21 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 22 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman:: @ 822022F
# 23 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	lock
# 24 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	faceplayer
# 25 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	message gText_HowMayIServeYou
# 26 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	waitmessage
# 27 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	pokemartdecoration LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale
# 28 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 29 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	release
# 30 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 31 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 32 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.align 2
# 33 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale: @ 8220248
# 34 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_MUD_BALL
# 35 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_FENCE_LENGTH
# 36 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_FENCE_WIDTH
# 37 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_TIRE
# 38 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_BREAKABLE_DOOR
# 39 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_SOLID_BOARD
# 40 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_SAND_ORNAMENT
# 41 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_STAND
# 42 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_SLIDE
# 43 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_TV
# 44 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_ROUND_TV
# 45 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_CUTE_TV
# 46 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_WAILMER_DOLL
# 47 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_RHYDON_DOLL
# 48 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte 0
# 49 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	release
# 50 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 51 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 52 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_Man:: @ 8220268
# 53 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	lock
# 54 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	faceplayer
# 55 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	getpricereduction POKENEWS_LILYCOVE
# 56 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	compare VAR_RESULT, TRUE
# 57 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale
# 58 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales, MSGBOX_DEFAULT
# 59 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	release
# 60 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 61 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 62 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale:: @ 8220282
# 63 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_BeenWaitingForClearOutSale, MSGBOX_DEFAULT
# 64 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	release
# 65 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 66 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 67 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyMan:: @ 822028C
# 68 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty, MSGBOX_NPC
# 69 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 70 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 71 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_VendingMachine:: @ 8220295
# 72 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	lockall
# 73 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike
# 74 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	waitmessage
# 75 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	showmoneybox 0, 0, 0
# 76 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink
# 77 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 78 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 79 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink:: @ 82202A6
# 80 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	multichoice 16, 0, MULTI_VENDING_MACHINE, FALSE
# 81 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 82 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	switch VAR_TEMP_1
# 83 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	case 0, LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater
# 84 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	case 1, LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop
# 85 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	case 2, LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade
# 86 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
# 87 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
# 88 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 89 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 90 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater:: @ 82202E4
# 91 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	setvar VAR_TEMP_0, ITEM_FRESH_WATER
# 92 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
# 93 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 94 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 95 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop:: @ 82202EF
# 96 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	setvar VAR_TEMP_0, ITEM_SODA_POP
# 97 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
# 98 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 99 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 100 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade:: @ 82202FA
# 101 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	setvar VAR_TEMP_0, ITEM_LEMONADE
# 102 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
# 103 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 104 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 105 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater:: @ 8220305
# 106 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	checkmoney 200, 0
# 107 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	return
# 108 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 109 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop:: @ 822030C
# 110 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	checkmoney 300, 0
# 111 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	return
# 112 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 113 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade:: @ 8220313
# 114 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	checkmoney 350, 0
# 115 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	return
# 116 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 117 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater:: @ 822031A
# 118 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	removemoney 200, 0
# 119 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	return
# 120 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 121 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop:: @ 8220321
# 122 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	removemoney 300, 0
# 123 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	return
# 124 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 125 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade:: @ 8220328
# 126 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	removemoney 350, 0
# 127 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	return
# 128 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 129 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink:: @ 822032F
# 130 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	compare VAR_TEMP_1, 0
# 131 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater
# 132 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	compare VAR_TEMP_1, 1
# 133 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop
# 134 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	compare VAR_TEMP_1, 2
# 135 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade
# 136 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	compare VAR_RESULT, FALSE
# 137 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForDrink
# 138 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	checkitemspace VAR_TEMP_0, 1
# 139 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	compare VAR_RESULT, FALSE
# 140 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
# 141 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	compare VAR_TEMP_1, 0
# 142 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater
# 143 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	compare VAR_TEMP_1, 1
# 144 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop
# 145 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	compare VAR_TEMP_1, 2
# 146 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	call_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade
# 147 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	updatemoneybox 0, 0
# 148 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	bufferitemname 0, VAR_TEMP_0
# 149 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	playse SE_VEND
# 150 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
# 151 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	additem VAR_TEMP_0
# 152 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	bufferitemname 1, VAR_TEMP_0
# 153 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	bufferstdstring 2, STDSTRING_ITEMS
# 154 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
# 155 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	random 32  @ 1/32 chance of an additional drink dropping
# 156 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	compare VAR_RESULT, 0
# 157 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto_if_ne LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
# 158 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	checkitemspace VAR_TEMP_0, 1
# 159 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	compare VAR_RESULT, FALSE
# 160 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
# 161 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	playse SE_VEND
# 162 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
# 163 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	additem VAR_TEMP_0
# 164 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	bufferitemname 1, VAR_TEMP_0
# 165 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	bufferstdstring 2, STDSTRING_ITEMS
# 166 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
# 167 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	random 32  @ 1/32 * the prev 1/32 chance of a third additional drink dropping, ~ 0.1% chance
# 168 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	compare VAR_RESULT, 0
# 169 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto_if_ne LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
# 170 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	checkitemspace VAR_TEMP_0, 1
# 171 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	compare VAR_RESULT, 0
# 172 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
# 173 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	playse SE_VEND
# 174 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
# 175 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	additem VAR_TEMP_0
# 176 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	bufferitemname 1, VAR_TEMP_0
# 177 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	bufferstdstring 2, STDSTRING_ITEMS
# 178 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
# 179 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
# 180 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 181 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 182 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink:: @ 8220436
# 183 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike
# 184 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	waitmessage
# 185 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink
# 186 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 187 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 188 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForDrink:: @ 8220442
# 189 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney, MSGBOX_DEFAULT
# 190 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
# 191 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 192 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 193 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink:: @ 8220450
# 194 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
# 195 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
# 196 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 197 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 198 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine:: @ 822045E
# 199 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	hidemoneybox
# 200 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	releaseall
# 201 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 202 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 203 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteTM::
# 204 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	lock
# 205 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	faceplayer
# 206 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_HaveTM90, MSGBOX_DEFAULT
# 207 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	release
# 208 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 209 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 210 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_ReceivedTM90::
# 211 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_HaveTM90, MSGBOX_DEFAULT
# 212 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	release
# 213 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 214 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 215 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales: @ 8220463
# 216 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Don't they have set dates for their\n"
# 217 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "clear-out sales?\p"
# 218 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "I watch TV, but they never show any\n"
# 219 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "commercials.$"
# 220 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 221 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_Text_BeenWaitingForClearOutSale: @ 82204C9
# 222 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Yes! I've been waiting a long time for\n"
# 223 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "this clear-out sale.\p"
# 224 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "They have items that you can only get\n"
# 225 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "here. I'm going to load up, that I am!$"
# 226 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 227 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty: @ 8220552
# 228 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Ohh… I'm bone-dry thirsty!$"
# 229 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 230 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike: @ 822056D
# 231 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "It's a Vending Machine.\n"
# 232 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Which drink would you like?$"
# 233 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 234 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_Text_CanOfDrinkDroppedDown: @ 82205A1
# 235 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Clang!\p"
# 236 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "A can of {STR_VAR_1} dropped down.$"
# 237 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 238 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown: @ 82205C2
# 239 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Clang!\p"
# 240 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Score! An extra can of {STR_VAR_1}\n"
# 241 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "dropped down!$"
# 242 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 243 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney: @ 82205F1
# 244 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Not enough money…$"
# 245 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 246 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingDrink: @ 8220603
# 247 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Decided against buying a drink.$"
# 248 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 249 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_Text_GiveSubstitute:
# 250 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "When I see the wide world from up\n"
# 251 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "here on the roof…\p"
# 252 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "I think about how nice it would be\n"
# 253 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "if there were more than just one me\l"
# 254 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "so I could enjoy all sorts of lives.\p"
# 255 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Of course it's not possible.\n"
# 256 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Giggle…\p"
# 257 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "I know! Take this TM, and you can have\n"
# 258 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "your Pokémon learn Substitute!$"
# 259 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 260 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_Text_HaveTM90:
# 261 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "We human beings should enjoy our\n"
# 262 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "own lives to the utmost!\p"
# 263 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "I hope you'll get that way, too!$"
