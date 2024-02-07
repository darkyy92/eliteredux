# 1 "data/maps/Route102/scripts.pory"

# 2 "data/maps/Route102/scripts.pory"
Route102_MapScripts:: @ 81EC0E0
# 3 "data/maps/Route102/scripts.pory"
	.byte 0
# 4 "data/maps/Route102/scripts.pory"

# 5 "data/maps/Route102/scripts.pory"
Route102_EventScript_LittleBoy:: @ 81EC0E1
# 6 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
# 7 "data/maps/Route102/scripts.pory"
	end
# 8 "data/maps/Route102/scripts.pory"

# 9 "data/maps/Route102/scripts.pory"
Route102_EventScript_RouteSignOldale:: @ 81EC0EA
# 10 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
# 11 "data/maps/Route102/scripts.pory"
	end
# 12 "data/maps/Route102/scripts.pory"

# 13 "data/maps/Route102/scripts.pory"
Route102_EventScript_RouteSignPetalburg:: @ 81EC0F3
# 14 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
# 15 "data/maps/Route102/scripts.pory"
	end
# 16 "data/maps/Route102/scripts.pory"

# 17 "data/maps/Route102/scripts.pory"
Route102_EventScript_Boy:: @ 81EC0FC
# 18 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
# 19 "data/maps/Route102/scripts.pory"
	end
# 20 "data/maps/Route102/scripts.pory"

# 21 "data/maps/Route102/scripts.pory"
Route102_EventScript_Oldplayer::
# 22 "data/maps/Route102/scripts.pory"
	trainerbattle_no_intro TRAINER_OLDPLAYER, Route102_Text_CalvinDefeated
# 23 "data/maps/Route102/scripts.pory"
	release
# 24 "data/maps/Route102/scripts.pory"
	end
# 25 "data/maps/Route102/scripts.pory"

# 26 "data/maps/Route102/scripts.pory"

# 27 "data/maps/Route102/scripts.pory"
Route102_EventScript_Calvin:: @ 81EC105
# 28 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
# 29 "data/maps/Route102/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 30 "data/maps/Route102/scripts.pory"
	compare VAR_RESULT, TRUE
# 31 "data/maps/Route102/scripts.pory"
	goto_if_eq Route102_EventScript_CalvinRematch
# 32 "data/maps/Route102/scripts.pory"
	setvar VAR_0x8004, TRAINER_CALVIN_1
# 33 "data/maps/Route102/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 34 "data/maps/Route102/scripts.pory"
	compare VAR_RESULT, FALSE
# 35 "data/maps/Route102/scripts.pory"
	goto_if_eq Route102_EventScript_CalvinTryRegister
# 36 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
# 37 "data/maps/Route102/scripts.pory"
	release
# 38 "data/maps/Route102/scripts.pory"
	end
# 39 "data/maps/Route102/scripts.pory"

# 40 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegisterMatchCallAfterBattle:: @ 81EC146
# 41 "data/maps/Route102/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 42 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 43 "data/maps/Route102/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
# 44 "data/maps/Route102/scripts.pory"
	release
# 45 "data/maps/Route102/scripts.pory"
	end
# 46 "data/maps/Route102/scripts.pory"

# 47 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegisterMatchCall:: @ 81EC157
# 48 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
# 49 "data/maps/Route102/scripts.pory"
	register_matchcall TRAINER_CALVIN_1
# 50 "data/maps/Route102/scripts.pory"
	release
# 51 "data/maps/Route102/scripts.pory"
	end
# 52 "data/maps/Route102/scripts.pory"

# 53 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinTryRegister:: @ 81EC170
# 54 "data/maps/Route102/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
# 55 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
# 56 "data/maps/Route102/scripts.pory"
	release
# 57 "data/maps/Route102/scripts.pory"
	end
# 58 "data/maps/Route102/scripts.pory"

# 59 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegister:: @ 81EC183
# 60 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
# 61 "data/maps/Route102/scripts.pory"
	register_matchcall TRAINER_CALVIN_1
# 62 "data/maps/Route102/scripts.pory"
	release
# 63 "data/maps/Route102/scripts.pory"
	end
# 64 "data/maps/Route102/scripts.pory"

# 65 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRematch:: @ 81EC19C
# 66 "data/maps/Route102/scripts.pory"
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
# 67 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
# 68 "data/maps/Route102/scripts.pory"
	end
# 69 "data/maps/Route102/scripts.pory"

# 70 "data/maps/Route102/scripts.pory"
Route102_EventScript_Rick:: @ 81EC1B3
# 71 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
# 72 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
# 73 "data/maps/Route102/scripts.pory"
	end
# 74 "data/maps/Route102/scripts.pory"

# 75 "data/maps/Route102/scripts.pory"
Route102_EventScript_Tiana:: @ 81EC1CA
# 76 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
# 77 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
# 78 "data/maps/Route102/scripts.pory"
	end
# 79 "data/maps/Route102/scripts.pory"

# 80 "data/maps/Route102/scripts.pory"
Route102_EventScript_Allen:: @ 81EC1E1
# 81 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
# 82 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
# 83 "data/maps/Route102/scripts.pory"
	end
# 84 "data/maps/Route102/scripts.pory"

# 85 "data/maps/Route102/scripts.pory"
Route102_Text_WatchMeCatchPokemon: @ 81EC1F8
# 86 "data/maps/Route102/scripts.pory"
	.string "Wally: {PLAYER}…\n"
# 87 "data/maps/Route102/scripts.pory"
	.string "Pokémon hide in tall grass like this,\l"
# 88 "data/maps/Route102/scripts.pory"
	.string "don't they?\p"
# 89 "data/maps/Route102/scripts.pory"
	.string "Please watch me and see if I can\n"
# 90 "data/maps/Route102/scripts.pory"
	.string "catch one properly.\p"
# 91 "data/maps/Route102/scripts.pory"
	.string "Go, Zigzagoon!$"
# 92 "data/maps/Route102/scripts.pory"

# 93 "data/maps/Route102/scripts.pory"
Route102_Text_WallyIDidIt: @ 81EC271
# 94 "data/maps/Route102/scripts.pory"
	.string "Wally: Come on, Poké Ball!\n"
# 95 "data/maps/Route102/scripts.pory"
	.string "Just shake a few more times...\p"
# 96 "data/maps/Route102/scripts.pory"
	.string "...\p"
# 97 "data/maps/Route102/scripts.pory"
	.string "Wally: Yes! I did it… It's my…\n"
# 98 "data/maps/Route102/scripts.pory"
	.string "My first Pokémon!\p"
# 99 "data/maps/Route102/scripts.pory"
	.string "I'll never forget this moment!$"
# 100 "data/maps/Route102/scripts.pory"

# 101 "data/maps/Route102/scripts.pory"
Route102_Text_LetsGoBack: @ 81EC297
# 102 "data/maps/Route102/scripts.pory"
	.string "{PLAYER}, thank you!\n"
# 103 "data/maps/Route102/scripts.pory"
	.string "Let's go back to the Gym!$"
# 104 "data/maps/Route102/scripts.pory"

# 105 "data/maps/Route102/scripts.pory"
Route102_Text_ImNotVeryTall: @ 81EC2C0
# 106 "data/maps/Route102/scripts.pory"
	.string "I'm… not very tall, so I sink right\n"
# 107 "data/maps/Route102/scripts.pory"
	.string "into tall grass.\p"
# 108 "data/maps/Route102/scripts.pory"
	.string "The grass goes up my nose and…\n"
# 109 "data/maps/Route102/scripts.pory"
	.string "Fwafwafwafwafwa…\p"
# 110 "data/maps/Route102/scripts.pory"
	.string "Fwatchoo!$"
# 111 "data/maps/Route102/scripts.pory"

# 112 "data/maps/Route102/scripts.pory"
Route102_Text_CatchWholeBunchOfPokemon: @ 81EC32E
# 113 "data/maps/Route102/scripts.pory"
	.string "I'm going to catch a whole bunch of\n"
# 114 "data/maps/Route102/scripts.pory"
	.string "Pokémon!$"
# 115 "data/maps/Route102/scripts.pory"

# 116 "data/maps/Route102/scripts.pory"
Route102_Text_RouteSignOldale: @ 81EC35B
# 117 "data/maps/Route102/scripts.pory"
	.string "Route 102\n"
# 118 "data/maps/Route102/scripts.pory"
	.string "{RIGHT_ARROW} Oldale Town$"
# 119 "data/maps/Route102/scripts.pory"

# 120 "data/maps/Route102/scripts.pory"
Route102_Text_RouteSignPetalburg: @ 81EC373
# 121 "data/maps/Route102/scripts.pory"
	.string "Route 102\n"
# 122 "data/maps/Route102/scripts.pory"
	.string "{LEFT_ARROW} Petalburg City$"

Route102_EventScript_Gen8_NPC::
# 125 "data/maps/Route102/scripts.pory"
	lock
# 126 "data/maps/Route102/scripts.pory"
	faceplayer
# 127 "data/maps/Route102/scripts.pory"
	checktrainerflag TRAINER_CALVIN_1
	goto_if 1, Route102_EventScript_Gen8_NPC_5
Route102_EventScript_Gen8_NPC_3:
# 140 "data/maps/Route102/scripts.pory"
	msgbox Route102_EventScript_Gen8_NPC_Text_2
Route102_EventScript_Gen8_NPC_1:
# 142 "data/maps/Route102/scripts.pory"
	release
	end

Route102_EventScript_Gen8_NPC_2:
# 132 "data/maps/Route102/scripts.pory"
	msgbox Route102_EventScript_Gen8_NPC_Text_0
# 133 "data/maps/Route102/scripts.pory"
	givemon SPECIES_ROOKIDEE, 10, ITEM_NONE
# 134 "data/maps/Route102/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 135 "data/maps/Route102/scripts.pory"
	message Route102_EventScript_Gen8_NPC_Text_1
# 136 "data/maps/Route102/scripts.pory"
	waitfanfare
	goto Route102_EventScript_Gen8_NPC_1

Route102_EventScript_Gen8_NPC_4:
# 129 "data/maps/Route102/scripts.pory"
	checktrainerflag TRAINER_ALLEN
	goto_if 1, Route102_EventScript_Gen8_NPC_8
	goto Route102_EventScript_Gen8_NPC_3

Route102_EventScript_Gen8_NPC_5:
# 128 "data/maps/Route102/scripts.pory"
	checktrainerflag TRAINER_RICK
	goto_if 1, Route102_EventScript_Gen8_NPC_4
	goto Route102_EventScript_Gen8_NPC_3

Route102_EventScript_Gen8_NPC_8:
# 130 "data/maps/Route102/scripts.pory"
	checktrainerflag TRAINER_TIANA
	goto_if 1, Route102_EventScript_Gen8_NPC_2
	goto Route102_EventScript_Gen8_NPC_3


Route102_EventScript_Gen8_NPC_Text_0:
# 132 "data/maps/Route102/scripts.pory"
	.string "Great job winning those battles! Take\n"
	.string "this Pokémon from Galar, you can have\l"
	.string "as many of them as you like!$"

Route102_EventScript_Gen8_NPC_Text_1:
# 135 "data/maps/Route102/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Rookidee{COLOR DARK_GRAY} as a gift for\n"
	.string "defeating every trainer here!$"

Route102_EventScript_Gen8_NPC_Text_2:
# 140 "data/maps/Route102/scripts.pory"
	.string "Hey there, fellow trainer! Have you\n"
	.string "heard about the exciting promotion\l"
	.string "we're running? We're students from\l"
	.string "Galar, and we've traveled all the way to\l"
	.string "beautiful Hoenn to show off the\l"
	.string "awesomeness of our home region and its\l"
	.string "incredible Pokémons. If you defeat\l"
	.string "every trainer in a route and speak to\l"
	.string "us, we'll gladly give you one, free of\l"
	.string "charge!$"
