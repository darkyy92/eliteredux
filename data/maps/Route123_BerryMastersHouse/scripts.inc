# 1 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 2 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_MapScripts:: @ 826F83B
# 3 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_BerryMastersHouse_OnTransition
# 4 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	.byte 0
# 5 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 6 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_OnTransition: @ 826F841
# 7 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_LANDMARK_BERRY_MASTERS_HOUSE
# 8 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 9 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 10 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_BerryMaster:: @ 826F845
# 11 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	lock
# 12 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	faceplayer
# 13 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	dotimebasedevents
# 14 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY, Route123_BerryMastersHouse_EventScript_ReceivedBerryToday
# 15 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_YoureDeservingOfBerry, MSGBOX_DEFAULT
# 16 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	random NUM_BERRY_MASTER_BERRIES
# 17 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, NUM_BERRY_MASTER_BERRIES_SKIPPED
# 18 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 19 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem VAR_RESULT
# 20 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 21 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 22 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY
# 23 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_WhyBeStingyTakeAnother, MSGBOX_DEFAULT
# 24 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	random NUM_BERRY_MASTER_BERRIES
# 25 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, NUM_BERRY_MASTER_BERRIES_SKIPPED
# 26 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 27 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem VAR_RESULT
# 28 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 29 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 30 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_VisitPrettyPetalFlowerShop, MSGBOX_DEFAULT
# 31 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 32 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 33 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 34 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_ReceivedBerryToday:: @ 826F8B6
# 35 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_DoneForToday, MSGBOX_DEFAULT
# 36 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 37 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 38 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 39 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_BerryMastersWife:: @ 826F8C0
# 40 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	lock
# 41 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	faceplayer
# 42 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	dotimebasedevents
# 43 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_DAILY_BERRY_MASTERS_WIFE, Route123_BerryMastersHouse_EventScript_ReceivedWifeBerryToday
# 44 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_HeardAGoodSayingLately, MSGBOX_DEFAULT
# 45 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_GOOD_SAYING
# 46 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	call Common_ShowEasyChatScreen
# 47 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	lock
# 48 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	faceplayer
# 49 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	compare VAR_RESULT, TRUE
# 50 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq Route123_BerryMastersHouse_EventScript_GavePhrase
# 51 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 52 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq Route123_BerryMastersHouse_EventScript_CancelPhrase
# 53 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 54 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 55 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_CancelPhrase:: @ 826F8F7
# 56 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_Ah, MSGBOX_DEFAULT
# 57 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife, MSGBOX_DEFAULT
# 58 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 59 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 60 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 61 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GavePhrase:: @ 826F909
# 62 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	compare VAR_0x8004, NOT_SPECIAL_PHRASE
# 63 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 64 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	compare VAR_0x8004, PHRASE_GREAT_BATTLE
# 65 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq Route123_BerryMastersHouse_EventScript_GiveSpelonBerry
# 66 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	compare VAR_0x8004, PHRASE_CHALLENGE_CONTEST
# 67 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq Route123_BerryMastersHouse_EventScript_GivePamtreBerry
# 68 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	compare VAR_0x8004, PHRASE_OVERWHELMING_LATIAS
# 69 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq Route123_BerryMastersHouse_EventScript_GiveWatmelBerry
# 70 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	compare VAR_0x8004, PHRASE_COOL_LATIOS
# 71 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq Route123_BerryMastersHouse_EventScript_GiveDurinBerry
# 72 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	compare VAR_0x8004, PHRASE_SUPER_HUSTLE
# 73 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq Route123_BerryMastersHouse_EventScript_GiveBelueBerry
# 74 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 75 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 76 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveNormalBerry:: @ 826F94C
# 77 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_GoodSayingTakeThis, MSGBOX_DEFAULT
# 78 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	random NUM_BERRY_MASTER_WIFE_BERRIES
# 79 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 80 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem VAR_RESULT
# 81 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 82 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 83 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 84 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 85 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 86 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 87 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveSpelonBerry:: @ 826F97A
# 88 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_SPELON_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 89 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 90 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_SPELON_BERRY
# 91 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 92 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 93 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_SPELON_BERRY
# 94 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 95 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 96 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 97 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GivePamtreBerry:: @ 826F9AB
# 98 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_PAMTRE_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 99 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 100 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_PAMTRE_BERRY
# 101 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 102 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 103 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_PAMTRE_BERRY
# 104 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 105 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 106 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 107 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveWatmelBerry:: @ 826F9DC
# 108 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_WATMEL_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 109 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 110 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_WATMEL_BERRY
# 111 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 112 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 113 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_WATMEL_BERRY
# 114 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 115 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 116 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 117 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveDurinBerry:: @ 826FA0D
# 118 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_DURIN_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 119 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 120 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_DURIN_BERRY
# 121 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 122 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 123 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_DURIN_BERRY
# 124 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 125 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 126 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 127 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveBelueBerry:: @ 826FA3E
# 128 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_BELUE_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 129 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 130 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_BELUE_BERRY
# 131 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 132 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 133 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_BELUE_BERRY
# 134 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 135 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 136 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 137 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_ReceivedWifeBerryToday:: @ 826FA6F
# 138 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife, MSGBOX_DEFAULT
# 139 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 140 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 141 "data/maps/Route123_BerryMastersHouse/scripts.pory"

# 142 "data/maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GaveBerry:: @ 826FA79
# 143 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_DAILY_BERRY_MASTERS_WIFE
# 144 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife, MSGBOX_DEFAULT
# 145 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 146 "data/maps/Route123_BerryMastersHouse/scripts.pory"
	end
