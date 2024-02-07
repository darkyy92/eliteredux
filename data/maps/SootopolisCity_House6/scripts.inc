# 1 "data/maps/SootopolisCity_House6/scripts.pory"

# 2 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_MapScripts:: @ 8226F5B
# 3 "data/maps/SootopolisCity_House6/scripts.pory"
	.byte 0
# 4 "data/maps/SootopolisCity_House6/scripts.pory"

# 5 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_EventScript_Woman:: @ 8226F5C
# 6 "data/maps/SootopolisCity_House6/scripts.pory"
	lock
# 7 "data/maps/SootopolisCity_House6/scripts.pory"
	faceplayer
# 8 "data/maps/SootopolisCity_House6/scripts.pory"
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_ReceivedWailmerDoll
# 9 "data/maps/SootopolisCity_House6/scripts.pory"
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
# 10 "data/maps/SootopolisCity_House6/scripts.pory"
	compare VAR_RESULT, NO
# 11 "data/maps/SootopolisCity_House6/scripts.pory"
	call_if_eq SootopolisCity_House6_EventScript_DeclineWailmerDoll
# 12 "data/maps/SootopolisCity_House6/scripts.pory"
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
# 13 "data/maps/SootopolisCity_House6/scripts.pory"
	givedecoration DECOR_WAILMER_DOLL
# 14 "data/maps/SootopolisCity_House6/scripts.pory"
	compare VAR_RESULT, FALSE
# 15 "data/maps/SootopolisCity_House6/scripts.pory"
	goto_if_eq SootopolisCity_House6_EventScript_NoRoomForWailmerDoll
# 16 "data/maps/SootopolisCity_House6/scripts.pory"
	setflag FLAG_RECEIVED_WAILMER_DOLL
# 17 "data/maps/SootopolisCity_House6/scripts.pory"
	release
# 18 "data/maps/SootopolisCity_House6/scripts.pory"
	end
# 19 "data/maps/SootopolisCity_House6/scripts.pory"

# 20 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_EventScript_DeclineWailmerDoll:: @ 8226F99
# 21 "data/maps/SootopolisCity_House6/scripts.pory"
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
# 22 "data/maps/SootopolisCity_House6/scripts.pory"
	release
# 23 "data/maps/SootopolisCity_House6/scripts.pory"
	end
# 24 "data/maps/SootopolisCity_House6/scripts.pory"

# 25 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_EventScript_ReceivedWailmerDoll:: @ 8226FA3
# 26 "data/maps/SootopolisCity_House6/scripts.pory"
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
# 27 "data/maps/SootopolisCity_House6/scripts.pory"
	release
# 28 "data/maps/SootopolisCity_House6/scripts.pory"
	end
# 29 "data/maps/SootopolisCity_House6/scripts.pory"

# 30 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_EventScript_NoRoomForWailmerDoll:: @ 8226FAD
# 31 "data/maps/SootopolisCity_House6/scripts.pory"
	bufferdecorationname 1, DECOR_WAILMER_DOLL
# 32 "data/maps/SootopolisCity_House6/scripts.pory"
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
# 33 "data/maps/SootopolisCity_House6/scripts.pory"
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
# 34 "data/maps/SootopolisCity_House6/scripts.pory"
	release
# 35 "data/maps/SootopolisCity_House6/scripts.pory"
	end
# 36 "data/maps/SootopolisCity_House6/scripts.pory"

# 37 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll: @ 8226FC3
# 38 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "Hello! You're our first guest in\n"
# 39 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "a good while.\p"
# 40 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "You've brightened up my day, so I'll\n"
# 41 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "give you a big Wailmer Doll.$"
# 42 "data/maps/SootopolisCity_House6/scripts.pory"

# 43 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_Text_TakeGoodCareOfIt: @ 8227034
# 44 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "Take good care of it!$"
# 45 "data/maps/SootopolisCity_House6/scripts.pory"

# 46 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_Text_IllHoldItForYou: @ 822704A
# 47 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "Oh, you want it, but not right now?\n"
# 48 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "Okay, then I'll hold it for you.$"
# 49 "data/maps/SootopolisCity_House6/scripts.pory"

# 50 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_Text_DontWantThisDoll: @ 822708F
# 51 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "Are you sure?\n"
# 52 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "You don't want this Doll?$"
# 53 "data/maps/SootopolisCity_House6/scripts.pory"

# 54 "data/maps/SootopolisCity_House6/scripts.pory"
SootopolisCity_House6_Text_LovePlushDolls: @ 82270B7
# 55 "data/maps/SootopolisCity_House6/scripts.pory"
	.string "I love plush Dolls!$"
