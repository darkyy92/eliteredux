# 1 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 2 "data/maps/Route104_MrBrineysHouse/scripts.pory"
.set LOCALID_BRINEY, 1
# 3 "data/maps/Route104_MrBrineysHouse/scripts.pory"
.set LOCALID_PEEKO, 2
# 4 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 5 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_MapScripts:: @ 8229D2E
# 6 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
# 7 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.byte 0
# 8 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 9 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_OnTransition: @ 8229D34
# 10 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
# 11 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	compare VAR_BRINEY_HOUSE_STATE, 1
# 12 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	call_if_eq Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
# 13 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	call_if_set FLAG_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_HideRustboroRival
# 14 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 15 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 16 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_HideRustboroRival:: @ 8229D4C
# 17 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
# 18 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	return
# 19 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 20 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos:: @ 8229D50
# 21 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setobjectxyperm LOCALID_BRINEY, 9, 3
# 22 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setobjectmovementtype LOCALID_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
# 23 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setobjectxyperm LOCALID_PEEKO, 9, 6
# 24 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setobjectmovementtype LOCALID_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
# 25 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	return
# 26 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 27 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_Briney:: @ 8229D67
# 28 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	lock
# 29 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	faceplayer
# 30 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
# 31 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
# 32 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
# 33 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
# 34 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 35 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 36 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_SailingIntro:: @ 8229D8A
# 37 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_MR_BRINEY_SAILING_INTRO
# 38 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
# 39 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford, MSGBOX_YESNO
# 40 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	compare VAR_RESULT, NO
# 41 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto_if_eq Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
# 42 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
# 43 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 44 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 45 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_WhereAreWeBound:: @ 8229DAE
# 46 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
# 47 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	waitmessage
# 48 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
# 49 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	switch VAR_RESULT
# 50 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	case 0, Route104_MrBrineysHouse_EventScript_SailToDewford
# 51 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
# 52 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
# 53 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 54 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 55 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_SailBothDeliveries:: @ 8229DE1
# 56 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
# 57 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	compare VAR_RESULT, NO
# 58 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto_if_eq Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
# 59 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
# 60 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 61 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 62 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_SailDeliverPackage:: @ 8229DFA
# 63 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
# 64 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	compare VAR_RESULT, NO
# 65 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto_if_eq Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
# 66 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
# 67 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 68 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 69 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing:: @ 8229E13
# 70 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
# 71 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	release
# 72 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 73 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 74 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_DeclineSailing:: @ 8229E1D
# 75 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
# 76 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	release
# 77 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 78 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 79 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_SailToDewford:: @ 8229E27
# 80 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
# 81 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	call EventScript_BackupMrBrineyLocation
# 82 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
# 83 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
# 84 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 85 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 86 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 10
# 87 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 88 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
# 89 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_RIVAL
# 90 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	warp MAP_ROUTE104, 255, 13, 51
# 91 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	waitstate
# 92 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	releaseall
# 93 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 94 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 95 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_EventScript_Peeko:: @ 8229E5D
# 96 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	lock
# 97 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	faceplayer
# 98 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	waitse
# 99 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	playmoncry SPECIES_WINGULL, 0
# 100 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
# 101 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	waitmoncry
# 102 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	release
# 103 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	end
# 104 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 105 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_WaitUpPeeko: @ 8229E70
# 106 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Mr. Briney: Hold on, lass!\n"
# 107 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Wait up, Peeko!$"
# 108 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 109 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford: @ 8229E9B
# 110 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Hm? You're {PLAYER}{KUN}!\n"
# 111 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You saved my darling Peeko!\l"
# 112 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "We owe so much to you!\p"
# 113 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "What's that?\n"
# 114 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You want to sail with me?\p"
# 115 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Hmhm…\p"
# 116 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You have a Letter bound for Dewford\n"
# 117 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "and a package for Slateport, then?\p"
# 118 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Quite the busy life you must lead!\p"
# 119 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "But, certainly, what you're asking is\n"
# 120 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "no problem at all.\p"
# 121 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You've come to the right man!\n"
# 122 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "We'll set sail for Dewford.$"
# 123 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 124 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_SetSailForDewford: @ 8229FE9
# 125 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Mr. Briney: Dewford it is, then!\p"
# 126 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Anchors aweigh!\n"
# 127 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Peeko, we're setting sail, my darling!$"
# 128 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 129 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_DeclineDeliverySail: @ 822A041
# 130 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Mr. Briney: Is that so?\n"
# 131 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Your deliveries can wait?\p"
# 132 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You just go on and tell me whenever\n"
# 133 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "you want to set sail!$"
# 134 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 135 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford: @ 822A0AD
# 136 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Mr. Briney: Ahoy!\n"
# 137 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "I know exactly what you want to say!\p"
# 138 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You're to deliver a Letter to Dewford\n"
# 139 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "and a package to Slateport.\p"
# 140 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "What you need me to do is no problem\n"
# 141 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "at all--I'm the man for the job!\p"
# 142 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "First, we'll set sail for Dewford.$"
# 143 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 144 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford: @ 822A18F
# 145 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Mr. Briney: Ahoy!\n"
# 146 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "I know exactly what you want to say!\p"
# 147 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You're to deliver a package to\n"
# 148 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Capt. Stern in Slateport.\p"
# 149 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "What you need me to do is no problem\n"
# 150 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "at all--I'm the man for the job!\p"
# 151 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "First, we'll set sail for Dewford.$"
# 152 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 153 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_WhereAreWeBound: @ 822A268
# 154 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Mr. Briney: Ahoy!\n"
# 155 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "For you, I'll go out to sea anytime!\p"
# 156 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Now, my friend, where are we bound?$"
# 157 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 158 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail: @ 822A2C3
# 159 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Mr. Briney: Is that so?\n"
# 160 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Well, Peeko owes her life to you.\p"
# 161 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "You just go on and tell me whenever\n"
# 162 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "you want to set sail!$"
# 163 "data/maps/Route104_MrBrineysHouse/scripts.pory"

# 164 "data/maps/Route104_MrBrineysHouse/scripts.pory"
Route104_MrBrineysHouse_Text_Peeko: @ 822A337
# 165 "data/maps/Route104_MrBrineysHouse/scripts.pory"
	.string "Peeko: Pii piihyoro!$"
