DewfordManor_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordManor_1F_OnTransition
	.byte 0

DewfordManor_1F_OnTransition:
	setflag FLAG_LANDMARK_DEWFORD_MANOR
	end

DewfordManor_1F_EventScript_Crobatite_Battle::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, DewfordManor_1F_EventScript_Crobatite_Battle_2
	msgbox DewfordManor_1F_EventScript_Crobatite_Battle_Text_6, MSGBOX_NPC
DewfordManor_1F_EventScript_Crobatite_Battle_1:
	release
	end

DewfordManor_1F_EventScript_Crobatite_Battle_2:
	checktrainerflag TRAINER_CROBATITE_DEWFORD_MANOR
	goto_if 0, DewfordManor_1F_EventScript_Crobatite_Battle_5
	msgbox DewfordManor_1F_EventScript_Crobatite_Battle_Text_5, MSGBOX_NPC
	goto DewfordManor_1F_EventScript_Crobatite_Battle_1

DewfordManor_1F_EventScript_Crobatite_Battle_5:
	msgbox DewfordManor_1F_EventScript_Crobatite_Battle_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq DewfordManor_1F_EventScript_Crobatite_Battle_8
	msgbox DewfordManor_1F_EventScript_Crobatite_Battle_Text_4, MSGBOX_NPC
	goto DewfordManor_1F_EventScript_Crobatite_Battle_1

DewfordManor_1F_EventScript_Crobatite_Battle_8:
	msgbox DewfordManor_1F_EventScript_Crobatite_Battle_Text_1, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_CROBATITE_DEWFORD_MANOR, DewfordManor_1F_EventScript_Crobatite_Battle_Text_2
	msgbox DewfordManor_1F_EventScript_Crobatite_Battle_Text_3, MSGBOX_NPC
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_CROBATITE, 1
	waitmessage
	goto DewfordManor_1F_EventScript_Crobatite_Battle_1


DewfordManor_1F_EventScript_Crobatite_Battle_Text_0:
	.string "Child, dare you battle an old soul?$"

DewfordManor_1F_EventScript_Crobatite_Battle_Text_1:
	.string "Ohoho, dear! Even in age, I shan't shy\n"
	.string "from a duel. Beware, for once, this old\l"
	.string "soul was a formidable trainer!$"

DewfordManor_1F_EventScript_Crobatite_Battle_Text_2:
	.string "My, my! Your strength is remarkable,\n"
	.string "young one!$"

DewfordManor_1F_EventScript_Crobatite_Battle_Text_3:
	.string "You're quite mighty, especially for one\n"
	.string "so young. Please, accept this from an\l"
	.string "elderly maiden, grateful for a moment\l"
	.string "of excitement.$"

DewfordManor_1F_EventScript_Crobatite_Battle_Text_4:
	.string "I see.$"

DewfordManor_1F_EventScript_Crobatite_Battle_Text_5:
	.string "I'm sorry, dear. This old soul has no\n"
	.string "more to give you.$"

DewfordManor_1F_EventScript_Crobatite_Battle_Text_6:
	.string "A traveler, eh? You look quite young to\n"
	.string "be in a place like this. If you're\l"
	.string "looking for Pokémon, there are quite a\l"
	.string "few here, looking for new trainers.\l"
	.string "Have you heard of those psychic twins\l"
	.string "in Mossdeep? Once you defeat them,\l"
	.string "come back here.$"
