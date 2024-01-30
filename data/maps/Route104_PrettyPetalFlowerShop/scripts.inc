# 1 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 2 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
.set LOCALID_OWNER, 1
# 3 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 4 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_MapScripts:: @ 822A34C
# 5 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_PrettyPetalFlowerShop_OnTransition
# 6 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.byte 0
# 7 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 8 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_OnTransition: @ 822A352
# 9 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_LANDMARK_FLOWER_SHOP
# 10 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_PrettyPetalFlowerShop_EventScript_MoveShopOwner
# 11 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, Route104_PrettyPetalFlowerShop_EventScript_MoveShopOwner
# 12 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_TEMP_1
# 13 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 14 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 15 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_MoveShopOwner:: @ 822A36B
# 16 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setobjectxyperm LOCALID_OWNER, 4, 6
# 17 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 18 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 19 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_ShopOwner:: @ 822A373
# 20 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	lock
# 21 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	faceplayer
# 22 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_set FLAG_TEMP_1, Route104_PrettyPetalFlowerShop_EventScript_SellDecorations
# 23 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_ThisIsPrettyPetalFlowerShop, MSGBOX_DEFAULT
# 24 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_set FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_PrettyPetalFlowerShop_EventScript_AlreadyMet
# 25 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_MET_PRETTY_PETAL_SHOP_OWNER
# 26 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_IntroLearnAboutBerries, MSGBOX_YESNO
# 27 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	compare VAR_RESULT, YES
# 28 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	call_if_eq Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries
# 29 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	compare VAR_RESULT, NO
# 30 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	call_if_eq Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries
# 31 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 32 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 33 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 34 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_AlreadyMet:: @ 822A3B2
# 35 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_LearnAboutBerries, MSGBOX_YESNO
# 36 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	compare VAR_RESULT, YES
# 37 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	call_if_eq Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries
# 38 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	compare VAR_RESULT, NO
# 39 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	call_if_eq Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries
# 40 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 41 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 42 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 43 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries:: @ 822A3D2
# 44 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_BerriesExplanation, MSGBOX_DEFAULT
# 45 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	return
# 46 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 47 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries:: @ 822A3DB
# 48 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_FlowersBringHappiness, MSGBOX_DEFAULT
# 49 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	return
# 50 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 51 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_SellDecorations:: @ 822A3E4
# 52 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	message gText_PlayerWhatCanIDoForYou
# 53 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	waitmessage
# 54 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	pokemartdecoration2 Route104_PrettyPetalFlowerShop_Pokemart_Plants
# 55 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 56 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 57 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 58 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 59 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.align 2
# 60 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_Pokemart_Plants: @ 822A3FC
# 61 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_RED_PLANT
# 62 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_TROPICAL_PLANT
# 63 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_PRETTY_FLOWERS
# 64 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_COLORFUL_PLANT
# 65 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_BIG_PLANT
# 66 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_GORGEOUS_PLANT
# 67 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_NONE
# 68 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 69 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 70 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 71 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_WailmerPailGirl:: @ 822A40C
# 72 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	lock
# 73 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	faceplayer
# 74 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_unset FLAG_RECEIVED_WAILMER_PAIL, Route104_PrettyPetalFlowerShop_EventScript_GiveWailmerPail
# 75 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_WailmerPailExplanation, MSGBOX_DEFAULT
# 76 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 77 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 78 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 79 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_GiveWailmerPail:: @ 822A421
# 80 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_YouCanHaveThis, MSGBOX_DEFAULT
# 81 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	giveitem ITEM_WAILMER_PAIL
# 82 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_WailmerPailExplanation, MSGBOX_DEFAULT
# 83 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_RECEIVED_WAILMER_PAIL
# 84 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 85 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 86 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 87 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_RandomBerryGirl:: @ 822A442
# 88 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	lock
# 89 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	faceplayer
# 90 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	dotimebasedevents
# 91 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_set FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY, Route104_PrettyPetalFlowerShop_EventScript_AlreadyReceivedBerry
# 92 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_ImGrowingFlowers, MSGBOX_DEFAULT
# 93 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	random 8
# 94 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 95 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	giveitem VAR_RESULT
# 96 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	compare VAR_RESULT, 0
# 97 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 98 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	giveitem ITEM_POMEG_BERRY
# 99 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	compare VAR_RESULT, 0
# 100 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 101 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	giveitem ITEM_KELPSY_BERRY
# 102 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	compare VAR_RESULT, 0
# 103 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 104 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	giveitem ITEM_QUALOT_BERRY
# 105 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	compare VAR_RESULT, 0
# 106 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 107 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	giveitem ITEM_HONDEW_BERRY
# 108 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	compare VAR_RESULT, 0
# 109 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 110 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	giveitem ITEM_GREPA_BERRY
# 111 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	compare VAR_RESULT, 0
# 112 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 113 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	giveitem ITEM_TAMATO_BERRY
# 114 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	compare VAR_RESULT, 0
# 115 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 116 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY
# 117 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
# 118 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 119 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 120 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 121 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_AlreadyReceivedBerry:: @ 822A482
# 122 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
# 123 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 124 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
