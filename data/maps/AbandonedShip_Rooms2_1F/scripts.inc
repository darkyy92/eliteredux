# 1 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 2 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_MapScripts:: @ 82380A6
# 3 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.byte 0
# 4 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 5 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_EventScript_Dan:: @ 82380A7
# 6 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
# 7 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 8 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	compare VAR_RESULT, TRUE
# 9 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	goto_if_eq AbandonedShip_Rooms2_1F_EventScript_DanRematch
# 10 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
# 11 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	release
# 12 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	end
# 13 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 14 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_EventScript_RegisterDan:: @ 82380D7
# 15 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
# 16 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	register_matchcall TRAINER_KIRA_AND_DAN_1
# 17 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	release
# 18 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	end
# 19 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 20 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_EventScript_DanRematch:: @ 82380F0
# 21 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
# 22 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
# 23 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	end
# 24 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 25 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_EventScript_Kira:: @ 823810B
# 26 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
# 27 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 28 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	compare VAR_RESULT, TRUE
# 29 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	goto_if_eq AbandonedShip_Rooms2_1F_EventScript_KiraRematch
# 30 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
# 31 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	release
# 32 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	end
# 33 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 34 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_EventScript_RegisterKira:: @ 823813B
# 35 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
# 36 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	register_matchcall TRAINER_KIRA_AND_DAN_1
# 37 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	release
# 38 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	end
# 39 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 40 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_EventScript_KiraRematch:: @ 8238154
# 41 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
# 42 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
# 43 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	end
# 44 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 45 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_EventScript_Jani:: @ 823816F
# 46 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
# 47 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
# 48 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	end
# 49 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 50 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_EventScript_Garrison:: @ 8238186
# 51 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
# 52 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
# 53 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	end
# 54 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 55 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_DanIntro: @ 823819D
# 56 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Dan: While searching for treasures,\n"
# 57 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "we discovered a Trainer!$"
# 58 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 59 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_DanDefeat: @ 82381DA
# 60 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Dan: We couldn't win even though\n"
# 61 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "we worked together…$"
# 62 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 63 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_DanPostBattle: @ 823820F
# 64 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Dan: We can't find any treasures…\n"
# 65 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "I wonder if someone got them already?$"
# 66 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 67 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons: @ 8238257
# 68 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Dan: You don't even have two Pokémon.\n"
# 69 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "You can't expect to beat us like that.$"
# 70 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 71 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_KiraIntro: @ 82382A4
# 72 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Kira: Oh?\n"
# 73 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "We were searching for treasures.\l"
# 74 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "But we discovered a Trainer instead!$"
# 75 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 76 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_KiraDefeat: @ 82382F4
# 77 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Kira: Ooh, so strong!$"
# 78 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 79 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_KiraPostBattle: @ 823830A
# 80 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Kira: Where could the treasures be?\p"
# 81 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "I've already decided what I'm buying\n"
# 82 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "when we find the treasures!$"
# 83 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 84 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons: @ 823836F
# 85 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Kira: Oh, you don't have two Pokémon?\n"
# 86 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "We'll have to battle some other time!$"
# 87 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 88 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_KiraRegister: @ 82383BB
# 89 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Kira: Oh, you make me so angry!\n"
# 90 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "I'm going to register you for that!$"
# 91 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 92 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_DanRematchIntro: @ 82383FF
# 93 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Dan: We've been searching for\n"
# 94 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "treasures all this time.\p"
# 95 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Our Pokémon have grown stronger, too.\n"
# 96 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Let us show you, okay?$"
# 97 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 98 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_DanRematchDefeat: @ 8238473
# 99 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Dan: You're strong, as usual!$"
# 100 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 101 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_DanPostRematch: @ 8238491
# 102 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Dan: We can't find any treasures,\n"
# 103 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "we lose at Pokémon…\p"
# 104 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "I want to go home… But if I say that,\n"
# 105 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "she gets all angry with me…$"
# 106 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 107 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons: @ 8238509
# 108 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Dan: You don't even have two Pokémon.\n"
# 109 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "You can't expect to beat us like that.$"
# 110 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 111 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_KiraRematchIntro: @ 8238556
# 112 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Kira: Oh? We meet again!\p"
# 113 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Just like us, you still haven't given up\n"
# 114 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "searching for treasures, have you?\p"
# 115 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Want to make it so the loser has\n"
# 116 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "to give up searching?$"
# 117 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 118 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat: @ 82385F2
# 119 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Kira: Oh, we lost again…$"
# 120 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 121 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_KiraPostRematch: @ 823860B
# 122 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Kira: We're not leaving until we raise\n"
# 123 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "our Pokémon some more and we find\l"
# 124 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "the treasures here!$"
# 125 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 126 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons: @ 8238668
# 127 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Kira: Oh, you don't have two Pokémon?\n"
# 128 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "We'll have to battle some other time!$"
# 129 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 130 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_JaniIntro: @ 82386B4
# 131 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "I'm not good at swimming,\n"
# 132 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "but I am good at battles!$"
# 133 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 134 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_JaniDefeat: @ 82386E8
# 135 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Oops.\n"
# 136 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "That didn't go very well.$"
# 137 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 138 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_JaniPostBattle: @ 8238708
# 139 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Walking around barefoot in this ship\n"
# 140 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "is kind of gross.$"
# 141 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 142 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_GarrisonIntro: @ 823873F
# 143 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Strength and compassion…\n"
# 144 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Those are a Trainer's treasures!$"
# 145 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 146 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_GarrisonDefeat: @ 8238779
# 147 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Ah, there is something about you\n"
# 148 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "that sparkles.$"
# 149 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"

# 150 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle: @ 82387A9
# 151 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "In a cabin somewhere on board,\n"
# 152 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "I saw something sparkle.$"
