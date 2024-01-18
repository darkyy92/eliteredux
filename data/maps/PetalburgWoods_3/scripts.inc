PetalburgWoods_3_MapScripts:: 
	.byte 0

PetalburgWoods3_EventScript_PrimalCascoon_Battle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgWoods3_EventScript_PrimalCascoon_Battle_2
	msgbox PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_7, MSGBOX_NPC
PetalburgWoods3_EventScript_PrimalCascoon_Battle_1:
	release
	end

PetalburgWoods3_EventScript_PrimalCascoon_Battle_2:
	checktrainerflag FLAG_TRAINER_BANEFUL_PETALBURG_WOODS
	goto_if 0, PetalburgWoods3_EventScript_PrimalCascoon_Battle_5
	msgbox PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_6, MSGBOX_NPC
	goto PetalburgWoods3_EventScript_PrimalCascoon_Battle_1

PetalburgWoods3_EventScript_PrimalCascoon_Battle_5:
	msgbox PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgWoods3_EventScript_PrimalCascoon_Battle_8
	msgbox PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_5, MSGBOX_NPC
	goto PetalburgWoods3_EventScript_PrimalCascoon_Battle_1

PetalburgWoods3_EventScript_PrimalCascoon_Battle_8:
	msgbox PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_1, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_BANEFUL_PETALBURG_WOODS, PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_2
	msgbox PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_3, MSGBOX_NPC
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_PURPLE_ORB, 1
	waitmessage
	msgbox PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_4, MSGBOX_NPC
	goto PetalburgWoods3_EventScript_PrimalCascoon_Battle_1


PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_0:
	.string "All Pokémon have their limits, right?\n"
	.string "Wrong.\p"
	.string "{PLAYER}, you must be dead strong to\n"
	.string "have found me here.\p"
	.string "I've raised my Pokémon beyond their\n"
	.string "normal limits and I've been waiting here\l"
	.string "just dying for a challenge.\p"
	.string "You wanna have a crack at it?$"

PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_1:
	.string "Let's have it then! Cascoon, you ready\n"
	.string "to take some names?$"

PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_2:
	.string "Amazing... You've broken the limits too...$"

PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_3:
	.string "I'm well impressed, mate. I reckon you're\n"
	.string "champion material. I've got a great\l"
	.string "reward for you since you've put the\l"
	.string "work in. Here.$"

PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_4:
	.string "If you dream of further defying the\n"
	.string "limits you'll want that Purple Orb.\p"
	.string "It allows Cascoon to unlock it's\n"
	.string "potential that was lost to time...$"

PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_5:
	.string "Sound. Come back when you're ready\n"
	.string "then.$"

PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_6:
	.string "I come from a distant land called\n"
	.string "Liverpool. It's not very well known\l"
	.string "around here.$"

PetalburgWoods3_EventScript_PrimalCascoon_Battle_Text_7:
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
