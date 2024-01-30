# 1 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 2 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_MapScripts:: @ 82693F4
# 3 "data/maps/Route109_SeashoreHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
# 4 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.byte 0
# 5 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 6 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_OnTransition: @ 82693FA
# 7 "data/maps/Route109_SeashoreHouse/scripts.pory"
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
# 8 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 9 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 10 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_Owner:: @ 82693FE
# 11 "data/maps/Route109_SeashoreHouse/scripts.pory"
	lock
# 12 "data/maps/Route109_SeashoreHouse/scripts.pory"
	faceplayer
# 13 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
# 14 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
# 15 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
# 16 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
# 17 "data/maps/Route109_SeashoreHouse/scripts.pory"
	setflag FLAG_TEMP_2
# 18 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 19 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 20 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 21 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction:: @ 8269428
# 22 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
# 23 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 24 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 25 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 26 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_DefeatedTrainers:: @ 8269432
# 27 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
# 28 "data/maps/Route109_SeashoreHouse/scripts.pory"
	giveitem ITEM_SODA_POP, 6
# 29 "data/maps/Route109_SeashoreHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 30 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_eq Route109_SeashoreHouse_EventScript_BagFull
# 31 "data/maps/Route109_SeashoreHouse/scripts.pory"
	setflag FLAG_RECEIVED_6_SODA_POP
# 32 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 33 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 34 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 35 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_BagFull:: @ 8269456
# 36 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
# 37 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 38 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 39 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 40 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop:: @ 8269460
# 41 "data/maps/Route109_SeashoreHouse/scripts.pory"
	showmoneybox 0, 0, 0
# 42 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
# 43 "data/maps/Route109_SeashoreHouse/scripts.pory"
	compare VAR_RESULT, YES
# 44 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_eq Route109_SeashoreHouse_EventScript_BuySodaPop
# 45 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
# 46 "data/maps/Route109_SeashoreHouse/scripts.pory"
	hidemoneybox
# 47 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 48 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 49 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 50 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_BuySodaPop:: @ 8269484
# 51 "data/maps/Route109_SeashoreHouse/scripts.pory"
	checkmoney 300, 0
# 52 "data/maps/Route109_SeashoreHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 53 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_eq Route109_SeashoreHouse_EventScript_NotEnoughMoney
# 54 "data/maps/Route109_SeashoreHouse/scripts.pory"
	checkitemspace ITEM_SODA_POP, 1
# 55 "data/maps/Route109_SeashoreHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 56 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_eq Route109_SeashoreHouse_EventScript_NotEnoughSpace
# 57 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
# 58 "data/maps/Route109_SeashoreHouse/scripts.pory"
	removemoney 300, 0
# 59 "data/maps/Route109_SeashoreHouse/scripts.pory"
	updatemoneybox 0, 0
# 60 "data/maps/Route109_SeashoreHouse/scripts.pory"
	giveitem ITEM_SODA_POP
# 61 "data/maps/Route109_SeashoreHouse/scripts.pory"
	hidemoneybox
# 62 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 63 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 64 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 65 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_NotEnoughMoney:: @ 82694C8
# 66 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
# 67 "data/maps/Route109_SeashoreHouse/scripts.pory"
	hidemoneybox
# 68 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 69 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 70 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 71 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_NotEnoughSpace:: @ 82694D5
# 72 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 73 "data/maps/Route109_SeashoreHouse/scripts.pory"
	hidemoneybox
# 74 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 75 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 76 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 77 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_Dwayne:: @ 82694E2
# 78 "data/maps/Route109_SeashoreHouse/scripts.pory"
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
# 79 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
# 80 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 81 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 82 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_Johanna:: @ 82694FD
# 83 "data/maps/Route109_SeashoreHouse/scripts.pory"
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
# 84 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
# 85 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 86 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 87 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_Simon:: @ 8269518
# 88 "data/maps/Route109_SeashoreHouse/scripts.pory"
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
# 89 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
# 90 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 91 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 92 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_CheckTrainersCompletion:: @ 8269533
# 93 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
# 94 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
# 95 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
# 96 "data/maps/Route109_SeashoreHouse/scripts.pory"
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
# 97 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 98 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 99 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 100 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_TrainersNotCompleted:: @ 8269553
# 101 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 102 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 103 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 104 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_SeashoreHouseIntro: @ 8269555
# 105 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I'm the owner of the Seashore House.\n"
# 106 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "But you can call me Mr. Sea!\p"
# 107 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "What I love above all is to see hot\n"
# 108 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Pokémon battles.\p"
# 109 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Let me see that your heart burns hot!\p"
# 110 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "If you can defeat all the Trainers\n"
# 111 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "here, I'll reward your efforts.$"
# 112 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 113 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_ShowMeSomeHotMatches: @ 8269635
# 114 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Show me some hot matches!\p"
# 115 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I run this Seashore House just for\n"
# 116 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "that reason alone!$"
# 117 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 118 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles: @ 8269685
# 119 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "You're scorching hot!\n"
# 120 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Those battles blazed!\l"
# 121 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I'm more than just satisfied!\p"
# 122 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "As thanks for showing me your hot\n"
# 123 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "streak, I want you to take these.\p"
# 124 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "It's half a dozen bottles of Soda Pop!$"
# 125 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 126 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_BagFull: @ 826973A
# 127 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Oh, but hey, your Bag's jammed full.\n"
# 128 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I'll hang on to these for you.$"
# 129 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 130 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_WantToBuySodaPop: @ 826977E
# 131 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Want to buy some Soda Pop?\n"
# 132 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Pokémon love it!\p"
# 133 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Just ¥300 a bottle!\n"
# 134 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Buy some!$"
# 135 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 136 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_HereYouGo: @ 82697C8
# 137 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Here you go!$"
# 138 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 139 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_NotEnoughMoney: @ 82697D5
# 140 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "You don't have the money.$"
# 141 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 142 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_ThatsTooBad: @ 82697EF
# 143 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "No?\n"
# 144 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "That's too bad.$"
# 145 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 146 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_DwayneIntro: @ 8269803
# 147 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "If you're looking for a battle in the\n"
# 148 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Seashore House, you'll find no\l"
# 149 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "hotter Trainer than me, matey!$"
# 150 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 151 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_DwayneDefeated: @ 8269867
# 152 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "That was a hot battle!\n"
# 153 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I can accept that loss, matey!$"
# 154 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 155 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_DwaynePostBattle: @ 826989D
# 156 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Whenever I'm in Slateport, I enjoy\n"
# 157 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "hot battles and ice-cold Soda Pop!$"
# 158 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 159 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_JohannaIntro: @ 82698E3
# 160 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Boring battles aren't worth the effort.\p"
# 161 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Fiery hot battles are what toughen up\n"
# 162 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Trainers and Pokémon!$"
# 163 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 164 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_JohannaDefeated: @ 8269947
# 165 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "That's hot!$"
# 166 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 167 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_JohannaPostBattle: @ 8269953
# 168 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Whew, I'm all thirsty.\n"
# 169 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Maybe I'll have a Soda Pop.$"
# 170 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 171 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_SimonIntro: @ 8269986
# 172 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I'm going to show you how great\n"
# 173 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "my Pokémon are, but don't cry!$"
# 174 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 175 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_SimonDefeated: @ 82699C5
# 176 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "…I lost, but I won't cry…$"
# 177 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 178 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_SimonPostBattle: @ 82699DF
# 179 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "If one of my Pokémon knew the move\n"
# 180 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "for carrying me across water on its\l"
# 181 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "back, I could get rid of this inner tube.$"

Route109_SeashoreHouse_EventScript_Gen8_NPC::
# 185 "data/maps/Route109_SeashoreHouse/scripts.pory"
	lock
# 186 "data/maps/Route109_SeashoreHouse/scripts.pory"
	faceplayer
# 187 "data/maps/Route109_SeashoreHouse/scripts.pory"
	checktrainerflag TRAINER_DWAYNE
	goto_if 1, Route109_SeashoreHouse_EventScript_Gen8_NPC_5
Route109_SeashoreHouse_EventScript_Gen8_NPC_3:
# 199 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_EventScript_Gen8_NPC_Text_2
Route109_SeashoreHouse_EventScript_Gen8_NPC_1:
# 201 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
	end

Route109_SeashoreHouse_EventScript_Gen8_NPC_2:
# 191 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_EventScript_Gen8_NPC_Text_0
# 192 "data/maps/Route109_SeashoreHouse/scripts.pory"
	givemon SPECIES_YAMPER, 10, ITEM_NONE
# 193 "data/maps/Route109_SeashoreHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 194 "data/maps/Route109_SeashoreHouse/scripts.pory"
	message Route109_SeashoreHouse_EventScript_Gen8_NPC_Text_1
# 195 "data/maps/Route109_SeashoreHouse/scripts.pory"
	waitfanfare
	goto Route109_SeashoreHouse_EventScript_Gen8_NPC_1

Route109_SeashoreHouse_EventScript_Gen8_NPC_4:
# 189 "data/maps/Route109_SeashoreHouse/scripts.pory"
	checktrainerflag TRAINER_SIMON
	goto_if 1, Route109_SeashoreHouse_EventScript_Gen8_NPC_2
	goto Route109_SeashoreHouse_EventScript_Gen8_NPC_3

Route109_SeashoreHouse_EventScript_Gen8_NPC_5:
# 188 "data/maps/Route109_SeashoreHouse/scripts.pory"
	checktrainerflag TRAINER_JOHANNA
	goto_if 1, Route109_SeashoreHouse_EventScript_Gen8_NPC_4
	goto Route109_SeashoreHouse_EventScript_Gen8_NPC_3


Route109_SeashoreHouse_EventScript_Gen8_NPC_Text_0:
# 191 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Excellent work! Here's your new friend,\n"
	.string "on the house!$"

Route109_SeashoreHouse_EventScript_Gen8_NPC_Text_1:
# 194 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Yamper{COLOR DARK_GRAY} as a gift for\n"
	.string "defeating every trainer here!$"

Route109_SeashoreHouse_EventScript_Gen8_NPC_Text_2:
# 199 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "In Galar, we call them 'men's best\n"
	.string "friend'! And they can be your best\l"
	.string "friend too, as long as your battling\l"
	.string "skills are on par!$"
