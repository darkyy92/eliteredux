# 1 "data/maps/Route111_OldLadysRestStop/scripts.pory"

# 2 "data/maps/Route111_OldLadysRestStop/scripts.pory"
Route111_OldLadysRestStop_MapScripts:: @ 822A916
# 3 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
# 4 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.byte 0
# 5 "data/maps/Route111_OldLadysRestStop/scripts.pory"

# 6 "data/maps/Route111_OldLadysRestStop/scripts.pory"
Route111_OldLadysRestStop_OnTransition: @ 822A91C
# 7 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
# 8 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	end
# 9 "data/maps/Route111_OldLadysRestStop/scripts.pory"

# 10 "data/maps/Route111_OldLadysRestStop/scripts.pory"
Route111_OldLadysRestStop_EventScript_OldLady:: @ 822A920
# 11 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	lock
# 12 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	faceplayer
# 13 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
# 14 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	compare VAR_RESULT, YES
# 15 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	goto_if_eq Route111_OldLadysRestStop_EventScript_Rest
# 16 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	compare VAR_RESULT, NO
# 17 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	goto_if_eq Route111_OldLadysRestStop_EventScript_DeclineRest
# 18 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	end
# 19 "data/maps/Route111_OldLadysRestStop/scripts.pory"

# 20 "data/maps/Route111_OldLadysRestStop/scripts.pory"
Route111_OldLadysRestStop_EventScript_Rest:: @ 822A941
# 21 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
# 22 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	closemessage
# 23 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 24 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
# 25 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	compare VAR_RESULT, YES
# 26 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	goto_if_eq Route111_OldLadysRestStop_EventScript_Rest
# 27 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	compare VAR_RESULT, NO
# 28 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	goto_if_eq Route111_OldLadysRestStop_EventScript_DeclineRest
# 29 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	end
# 30 "data/maps/Route111_OldLadysRestStop/scripts.pory"

# 31 "data/maps/Route111_OldLadysRestStop/scripts.pory"
Route111_OldLadysRestStop_EventScript_DeclineRest:: @ 822A96E
# 32 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
# 33 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	release
# 34 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	end
# 35 "data/maps/Route111_OldLadysRestStop/scripts.pory"

# 36 "data/maps/Route111_OldLadysRestStop/scripts.pory"
Route111_OldLadysRestStop_Text_RestUpHere: @ 822A978
# 37 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "Oh, dear, dear.\n"
# 38 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "Aren't your Pokémon exhausted?\p"
# 39 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "If you'd like, rest up here.\n"
# 40 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "That's a fine idea! You should do that.$"
# 41 "data/maps/Route111_OldLadysRestStop/scripts.pory"

# 42 "data/maps/Route111_OldLadysRestStop/scripts.pory"
Route111_OldLadysRestStop_Text_TakeYourTimeRestUp: @ 822A9EC
# 43 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "That's right.\n"
# 44 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "Take your time and rest up!$"
# 45 "data/maps/Route111_OldLadysRestStop/scripts.pory"

# 46 "data/maps/Route111_OldLadysRestStop/scripts.pory"
Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest: @ 822AA16
# 47 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "Oh, dear, dear.\n"
# 48 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "Are your Pokémon still tired?\p"
# 49 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "You should take another rest here.\n"
# 50 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "That's a fine idea. You should do that.$"
# 51 "data/maps/Route111_OldLadysRestStop/scripts.pory"

# 52 "data/maps/Route111_OldLadysRestStop/scripts.pory"
Route111_OldLadysRestStop_Text_DontNeedToBeShy: @ 822AA8F
# 53 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "Is that so?\n"
# 54 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "You don't need to be shy about it.$"
