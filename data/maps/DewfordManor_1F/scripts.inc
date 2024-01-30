# 1 "data/maps/DewfordManor_1F/scripts.pory"

# 2 "data/maps/DewfordManor_1F/scripts.pory"
DewfordManor_1F_MapScripts::
# 3 "data/maps/DewfordManor_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordManor_1F_OnTransition
# 4 "data/maps/DewfordManor_1F/scripts.pory"
	.byte 0
# 5 "data/maps/DewfordManor_1F/scripts.pory"

# 6 "data/maps/DewfordManor_1F/scripts.pory"
DewfordManor_1F_OnTransition:
# 7 "data/maps/DewfordManor_1F/scripts.pory"
	setflag FLAG_LANDMARK_DEWFORD_MANOR
# 8 "data/maps/DewfordManor_1F/scripts.pory"
	end

DewfordManor_1F_EventScript_Crobatite_Battle::
# 12 "data/maps/DewfordManor_1F/scripts.pory"
	lock
# 13 "data/maps/DewfordManor_1F/scripts.pory"
	faceplayer
# 14 "data/maps/DewfordManor_1F/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, DewfordManor_1F_EventScript_Crobatite_Battle_2
# 35 "data/maps/DewfordManor_1F/scripts.pory"
	msgbox DewfordManor_1F_EventScript_Crobatite_Battle_Text_6, MSGBOX_NPC
DewfordManor_1F_EventScript_Crobatite_Battle_1:
# 37 "data/maps/DewfordManor_1F/scripts.pory"
	release
	end

DewfordManor_1F_EventScript_Crobatite_Battle_2:
# 16 "data/maps/DewfordManor_1F/scripts.pory"
	checktrainerflag TRAINER_CROBATITE_DEWFORD_MANOR
	goto_if 0, DewfordManor_1F_EventScript_Crobatite_Battle_5
# 31 "data/maps/DewfordManor_1F/scripts.pory"
	msgbox DewfordManor_1F_EventScript_Crobatite_Battle_Text_5, MSGBOX_NPC
	goto DewfordManor_1F_EventScript_Crobatite_Battle_1

DewfordManor_1F_EventScript_Crobatite_Battle_5:
# 17 "data/maps/DewfordManor_1F/scripts.pory"
	msgbox DewfordManor_1F_EventScript_Crobatite_Battle_Text_0, MSGBOX_YESNO
# 18 "data/maps/DewfordManor_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordManor_1F_EventScript_Crobatite_Battle_8
# 27 "data/maps/DewfordManor_1F/scripts.pory"
	msgbox DewfordManor_1F_EventScript_Crobatite_Battle_Text_4, MSGBOX_NPC
	goto DewfordManor_1F_EventScript_Crobatite_Battle_1

DewfordManor_1F_EventScript_Crobatite_Battle_8:
# 19 "data/maps/DewfordManor_1F/scripts.pory"
	msgbox DewfordManor_1F_EventScript_Crobatite_Battle_Text_1, MSGBOX_NPC
# 20 "data/maps/DewfordManor_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_CROBATITE_DEWFORD_MANOR, DewfordManor_1F_EventScript_Crobatite_Battle_Text_2
# 21 "data/maps/DewfordManor_1F/scripts.pory"
	msgbox DewfordManor_1F_EventScript_Crobatite_Battle_Text_3, MSGBOX_NPC
# 22 "data/maps/DewfordManor_1F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 23 "data/maps/DewfordManor_1F/scripts.pory"
	giveitem ITEM_CROBATITE, 1
# 24 "data/maps/DewfordManor_1F/scripts.pory"
	waitmessage
	goto DewfordManor_1F_EventScript_Crobatite_Battle_1


DewfordManor_1F_EventScript_Crobatite_Battle_Text_0:
# 17 "data/maps/DewfordManor_1F/scripts.pory"
	.string "Child, dare you battle an old soul?$"

DewfordManor_1F_EventScript_Crobatite_Battle_Text_1:
# 19 "data/maps/DewfordManor_1F/scripts.pory"
	.string "Ohoho, dear! Even in age, I shan't shy\n"
	.string "from a duel. Beware, for once, this old\l"
	.string "soul was a formidable trainer!$"

DewfordManor_1F_EventScript_Crobatite_Battle_Text_2:
# 20 "data/maps/DewfordManor_1F/scripts.pory"
	.string "My, my! Your strength is remarkable,\n"
	.string "young one!$"

DewfordManor_1F_EventScript_Crobatite_Battle_Text_3:
# 21 "data/maps/DewfordManor_1F/scripts.pory"
	.string "You're quite mighty, especially for one\n"
	.string "so young. Please, accept this from an\l"
	.string "elderly maiden, grateful for a moment of\l"
	.string "excitement.$"

DewfordManor_1F_EventScript_Crobatite_Battle_Text_4:
# 27 "data/maps/DewfordManor_1F/scripts.pory"
	.string "I see.$"

DewfordManor_1F_EventScript_Crobatite_Battle_Text_5:
# 31 "data/maps/DewfordManor_1F/scripts.pory"
	.string "I'm sorry, dear. This old soul has no\n"
	.string "more to give you.$"

DewfordManor_1F_EventScript_Crobatite_Battle_Text_6:
# 35 "data/maps/DewfordManor_1F/scripts.pory"
	.string "A traveler, eh? You look quite young to\n"
	.string "be in a place like this. If you're looking\l"
	.string "for Pokémon, there are quite a few here,\l"
	.string "looking for new trainers. Have you\l"
	.string "heard of those psychic twins in\l"
	.string "Mossdeep? Once you defeat them, come\l"
	.string "back here.$"
