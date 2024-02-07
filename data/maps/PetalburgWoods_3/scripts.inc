# 1 "data/maps/PetalburgWoods_3/scripts.pory"

# 2 "data/maps/PetalburgWoods_3/scripts.pory"
PetalburgWoods_3_MapScripts:: 
# 3 "data/maps/PetalburgWoods_3/scripts.pory"
	.byte 0

PetalburgWoods3_EventScript_PrimalCascoon_Battle::
# 7 "data/maps/PetalburgWoods_3/scripts.pory"
	lock
# 8 "data/maps/PetalburgWoods_3/scripts.pory"
	faceplayer
# 9 "data/maps/PetalburgWoods_3/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgWoods3_EventScript_PrimalCascoon_Battle_2
# 31 "data/maps/PetalburgWoods_3/scripts.pory"
	msgbox PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_7, MSGBOX_NPC
PetalburgWoods3_EventScript_PrimalCascoon_Battle_1:
# 33 "data/maps/PetalburgWoods_3/scripts.pory"
	release
	end

PetalburgWoods3_EventScript_PrimalCascoon_Battle_2:
# 11 "data/maps/PetalburgWoods_3/scripts.pory"
	checktrainerflag FLAG_TRAINER_BANEFUL_PETALBURG_WOODS
	goto_if 0, PetalburgWoods3_EventScript_PrimalCascoon_Battle_5
# 27 "data/maps/PetalburgWoods_3/scripts.pory"
	msgbox PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_6, MSGBOX_NPC
	goto PetalburgWoods3_EventScript_PrimalCascoon_Battle_1

PetalburgWoods3_EventScript_PrimalCascoon_Battle_5:
# 12 "data/maps/PetalburgWoods_3/scripts.pory"
	msgbox PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_0, MSGBOX_YESNO
# 13 "data/maps/PetalburgWoods_3/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq PetalburgWoods3_EventScript_PrimalCascoon_Battle_8
# 23 "data/maps/PetalburgWoods_3/scripts.pory"
	msgbox PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_5, MSGBOX_NPC
	goto PetalburgWoods3_EventScript_PrimalCascoon_Battle_1

PetalburgWoods3_EventScript_PrimalCascoon_Battle_8:
# 14 "data/maps/PetalburgWoods_3/scripts.pory"
	msgbox PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_1, MSGBOX_NPC
# 15 "data/maps/PetalburgWoods_3/scripts.pory"
	trainerbattle_no_intro TRAINER_BANEFUL_PETALBURG_WOODS, PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_2
# 16 "data/maps/PetalburgWoods_3/scripts.pory"
	msgbox PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_3, MSGBOX_NPC
# 17 "data/maps/PetalburgWoods_3/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 18 "data/maps/PetalburgWoods_3/scripts.pory"
	giveitem ITEM_PURPLE_ORB, 1
# 19 "data/maps/PetalburgWoods_3/scripts.pory"
	waitmessage
# 20 "data/maps/PetalburgWoods_3/scripts.pory"
	msgbox PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_4, MSGBOX_NPC
	goto PetalburgWoods3_EventScript_PrimalCascoon_Battle_1


PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_0:
# 12 "data/maps/PetalburgWoods_3/scripts.pory"
	.string "All Pokémon have their limits, right?\n"
	.string "Wrong.\p"
	.string "{PLAYER}, you must be dead strong to\n"
	.string "have found me here.\p"
	.string "I've raised my Pokémon beyond their\n"
	.string "normal limits and I've been waiting here\l"
	.string "just dying for a challenge.\p"
	.string "You wanna have a crack at it?$"

PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_1:
# 14 "data/maps/PetalburgWoods_3/scripts.pory"
	.string "Let's have it then! Cascoon, you ready\n"
	.string "to take some names?$"

PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_2:
# 15 "data/maps/PetalburgWoods_3/scripts.pory"
	.string "Amazing... You've broken the limits too...$"

PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_3:
# 16 "data/maps/PetalburgWoods_3/scripts.pory"
	.string "I'm well impressed, mate. I reckon you're\n"
	.string "champion material. I've got a great\l"
	.string "reward for you since you've put the\l"
	.string "work in. Here.$"

PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_4:
# 20 "data/maps/PetalburgWoods_3/scripts.pory"
	.string "If you dream of further defying the\n"
	.string "limits you'll want that Purple Orb.\p"
	.string "It allows Cascoon to unlock it's\n"
	.string "potential that was lost to time...$"

PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_5:
# 23 "data/maps/PetalburgWoods_3/scripts.pory"
	.string "Sound. Come back when you're ready\n"
	.string "then.$"

PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_6:
# 27 "data/maps/PetalburgWoods_3/scripts.pory"
	.string "I come from a distant land called\n"
	.string "Liverpool. It's not very well known\l"
	.string "around here.$"

PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_7:
# 31 "data/maps/PetalburgWoods_3/scripts.pory"
	.string "Oi there, {PLAYER}! Thought you'd\n"
	.string "come and have a go, did ya? But listen,\l"
	.string "I'm lookin' for a certain level of\l"
	.string "challenge, somethin' only a Champion\l"
	.string "can give me.\p"
	.string "Get yourself that title, become the\n"
	.string "Champion, and then we'll have ourselves\l"
	.string "a proper scrap, eh? Until then, keep it\l"
	.string "on the down low that you've seen me,\l"
	.string "alright?$"
