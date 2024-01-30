# 1 "data/maps/VictoryRoad_B2F/scripts.pory"

# 2 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_MapScripts:: @ 82368D4
# 3 "data/maps/VictoryRoad_B2F/scripts.pory"
	.byte 0
# 4 "data/maps/VictoryRoad_B2F/scripts.pory"

# 5 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_Vito:: @ 82368D5
# 6 "data/maps/VictoryRoad_B2F/scripts.pory"
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
# 7 "data/maps/VictoryRoad_B2F/scripts.pory"
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
# 8 "data/maps/VictoryRoad_B2F/scripts.pory"
	end
# 9 "data/maps/VictoryRoad_B2F/scripts.pory"

# 10 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_Owen:: @ 82368EC
# 11 "data/maps/VictoryRoad_B2F/scripts.pory"
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
# 12 "data/maps/VictoryRoad_B2F/scripts.pory"
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
# 13 "data/maps/VictoryRoad_B2F/scripts.pory"
	end
# 14 "data/maps/VictoryRoad_B2F/scripts.pory"

# 15 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_Caroline:: @ 8236903
# 16 "data/maps/VictoryRoad_B2F/scripts.pory"
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
# 17 "data/maps/VictoryRoad_B2F/scripts.pory"
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
# 18 "data/maps/VictoryRoad_B2F/scripts.pory"
	end
# 19 "data/maps/VictoryRoad_B2F/scripts.pory"

# 20 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_Julie:: @ 823691A
# 21 "data/maps/VictoryRoad_B2F/scripts.pory"
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
# 22 "data/maps/VictoryRoad_B2F/scripts.pory"
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
# 23 "data/maps/VictoryRoad_B2F/scripts.pory"
	end
# 24 "data/maps/VictoryRoad_B2F/scripts.pory"

# 25 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_Felix:: @ 8236931
# 26 "data/maps/VictoryRoad_B2F/scripts.pory"
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
# 27 "data/maps/VictoryRoad_B2F/scripts.pory"
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
# 28 "data/maps/VictoryRoad_B2F/scripts.pory"
	end
# 29 "data/maps/VictoryRoad_B2F/scripts.pory"

# 30 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_EventScript_Dianne:: @ 8236948
# 31 "data/maps/VictoryRoad_B2F/scripts.pory"
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
# 32 "data/maps/VictoryRoad_B2F/scripts.pory"
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
# 33 "data/maps/VictoryRoad_B2F/scripts.pory"
	end
# 34 "data/maps/VictoryRoad_B2F/scripts.pory"

# 35 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_VitoIntro: @ 823695F
# 36 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "I trained together with my whole family,\n"
# 37 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "every one of us!\l"
# 38 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "I'm not losing to anyone!$"
# 39 "data/maps/VictoryRoad_B2F/scripts.pory"

# 40 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_VitoDefeat: @ 82369B3
# 41 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Better than my family?!\n"
# 42 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Is that possible?!$"
# 43 "data/maps/VictoryRoad_B2F/scripts.pory"

# 44 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_VitoPostBattle: @ 82369DE
# 45 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "I was better than everyone in my\n"
# 46 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "family. I've never lost before…\p"
# 47 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "I've lost my confidence…\n"
# 48 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Maybe I'll go home…$"
# 49 "data/maps/VictoryRoad_B2F/scripts.pory"

# 50 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_OwenIntro: @ 8236A4C
# 51 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "I'd heard that there was a tough\n"
# 52 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "little kid around. Do they mean you?$"
# 53 "data/maps/VictoryRoad_B2F/scripts.pory"

# 54 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_OwenDefeat: @ 8236A92
# 55 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "The little shrimp is tough!$"
# 56 "data/maps/VictoryRoad_B2F/scripts.pory"

# 57 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_OwenPostBattle: @ 8236AAE
# 58 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "The rumors I heard, that tough little\n"
# 59 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "kid is from Petalburg City.$"
# 60 "data/maps/VictoryRoad_B2F/scripts.pory"

# 61 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_CarolineIntro: @ 8236AF0
# 62 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "You must be getting a little tired.$"
# 63 "data/maps/VictoryRoad_B2F/scripts.pory"

# 64 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_CarolineDefeat: @ 8236B14
# 65 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "No signs of tiring at all!$"
# 66 "data/maps/VictoryRoad_B2F/scripts.pory"

# 67 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_CarolinePostBattle: @ 8236B2F
# 68 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Victory Road and the Pokémon League\n"
# 69 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "are long and grueling challenges.\l"
# 70 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Beware of fatigue!$"
# 71 "data/maps/VictoryRoad_B2F/scripts.pory"

# 72 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_JulieIntro: @ 8236B88
# 73 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "You shouldn't get complacent just\n"
# 74 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "because you have a lot of Gym Badges.\p"
# 75 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "There's always going to be someone\n"
# 76 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "who's better than you!$"
# 77 "data/maps/VictoryRoad_B2F/scripts.pory"

# 78 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_JulieDefeat: @ 8236C0A
# 79 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "You're better than me!$"
# 80 "data/maps/VictoryRoad_B2F/scripts.pory"

# 81 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_JuliePostBattle: @ 8236C21
# 82 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Gaze on your collected Badges and\n"
# 83 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "remember the Trainers you've faced.$"
# 84 "data/maps/VictoryRoad_B2F/scripts.pory"

# 85 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_FelixIntro: @ 8236C67
# 86 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "I've come this far, but the tension's\n"
# 87 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "giving me awful stomach pain…$"
# 88 "data/maps/VictoryRoad_B2F/scripts.pory"

# 89 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_FelixDefeat: @ 8236CAB
# 90 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Ooh…\n"
# 91 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "It hurts…$"
# 92 "data/maps/VictoryRoad_B2F/scripts.pory"

# 93 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_FelixPostBattle: @ 8236CBA
# 94 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "I can't help getting all tense knowing\n"
# 95 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "that I'm nearing the Pokémon League.\p"
# 96 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "It's all I can do to feign calm.$"
# 97 "data/maps/VictoryRoad_B2F/scripts.pory"

# 98 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_DianneIntro: @ 8236D27
# 99 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "The elite among the elite gather in\n"
# 100 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "this cave.\p"
# 101 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "How are you finding it?$"
# 102 "data/maps/VictoryRoad_B2F/scripts.pory"

# 103 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_DianneDefeat: @ 8236D6E
# 104 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Not rattled in the least bit!$"
# 105 "data/maps/VictoryRoad_B2F/scripts.pory"

# 106 "data/maps/VictoryRoad_B2F/scripts.pory"
VictoryRoad_B2F_Text_DiannePostBattle: @ 8236D8C
# 107 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "You do have guts! I like that!\n"
# 108 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Keep it going!$"

VictoryRoad_B2F_EventScript_LegendaryNPC::
# 113 "data/maps/VictoryRoad_B2F/scripts.pory"
	lock
# 114 "data/maps/VictoryRoad_B2F/scripts.pory"
	faceplayer
# 115 "data/maps/VictoryRoad_B2F/scripts.pory"
	msgbox VictoryRoad_B2F_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 116 "data/maps/VictoryRoad_B2F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq VictoryRoad_B2F_EventScript_LegendaryNPC_2
# 148 "data/maps/VictoryRoad_B2F/scripts.pory"
	msgbox VictoryRoad_B2F_EventScript_LegendaryNPC_Text_4
VictoryRoad_B2F_EventScript_LegendaryNPC_1:
# 150 "data/maps/VictoryRoad_B2F/scripts.pory"
	release
	end

VictoryRoad_B2F_EventScript_LegendaryNPC_2:
# 117 "data/maps/VictoryRoad_B2F/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, VictoryRoad_B2F_EventScript_LegendaryNPC_5
# 134 "data/maps/VictoryRoad_B2F/scripts.pory"
	checktrainerflag TRAINER_JULIE
	goto_if 1, VictoryRoad_B2F_EventScript_LegendaryNPC_11
VictoryRoad_B2F_EventScript_LegendaryNPC_9:
# 143 "data/maps/VictoryRoad_B2F/scripts.pory"
	msgbox VictoryRoad_B2F_EventScript_LegendaryNPC_Text_3
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_1

VictoryRoad_B2F_EventScript_LegendaryNPC_5:
# 118 "data/maps/VictoryRoad_B2F/scripts.pory"
	msgbox VictoryRoad_B2F_EventScript_LegendaryNPC_Text_1
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_1

VictoryRoad_B2F_EventScript_LegendaryNPC_8:
# 140 "data/maps/VictoryRoad_B2F/scripts.pory"
	msgbox VictoryRoad_B2F_EventScript_LegendaryNPC_Text_2
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_1

VictoryRoad_B2F_EventScript_LegendaryNPC_10:
# 136 "data/maps/VictoryRoad_B2F/scripts.pory"
	checktrainerflag TRAINER_OWEN
	goto_if 1, VictoryRoad_B2F_EventScript_LegendaryNPC_15
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_9

VictoryRoad_B2F_EventScript_LegendaryNPC_11:
# 135 "data/maps/VictoryRoad_B2F/scripts.pory"
	checktrainerflag TRAINER_CAROLINE
	goto_if 1, VictoryRoad_B2F_EventScript_LegendaryNPC_10
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_9

VictoryRoad_B2F_EventScript_LegendaryNPC_14:
# 138 "data/maps/VictoryRoad_B2F/scripts.pory"
	checktrainerflag TRAINER_FELIX
	goto_if 1, VictoryRoad_B2F_EventScript_LegendaryNPC_18
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_9

VictoryRoad_B2F_EventScript_LegendaryNPC_15:
# 137 "data/maps/VictoryRoad_B2F/scripts.pory"
	checktrainerflag TRAINER_VITO
	goto_if 1, VictoryRoad_B2F_EventScript_LegendaryNPC_14
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_9

VictoryRoad_B2F_EventScript_LegendaryNPC_18:
# 139 "data/maps/VictoryRoad_B2F/scripts.pory"
	checktrainerflag TRAINER_DIANNE
	goto_if 1, VictoryRoad_B2F_EventScript_LegendaryNPC_8
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_9


VictoryRoad_B2F_EventScript_LegendaryNPC_Text_0:
# 115 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Sage: Once upon a time, I was a bard and\n"
	.string "lorekeeper of these lands. I'm now\l"
	.string "retired, like another colleague of mine,\l"
	.string "but together we told the story of King\l"
	.string "Calyrex. I happen to know the SECOND\l"
	.string "part of the story, an infamous one. Do\l"
	.string "you want to hear it?$"

VictoryRoad_B2F_EventScript_LegendaryNPC_Text_1:
# 118 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "You might have heard the first part of\n"
	.string "the legend of King Calyrex. If you have,\l"
	.string "let me tell you the latter part of the\l"
	.string "story, one that many people don't know\l"
	.string "about.\p"
	.string "After pushing back Necrozma to outer\n"
	.string "space, Alola was still invaded by the\l"
	.string "Ultra Beasts, which were far too many\l"
	.string "to deal with.\p"
	.string "Calyrex knew that, if left unchecked,\n"
	.string "they would eventually consume the\l"
	.string "entire world and turn it into a whitered\l"
	.string "wasteland.\p"
	.string "He was powerful, but with only the\n"
	.string "Tapus by his side, he knew he had no\l"
	.string "chance of winning.\p"
	.string "Dire situations call for methods that\n"
	.string "allow no half measures to be taken. This\l"
	.string "was one of those situations.\p"
	.string "You see, the King had so far only rode\n"
	.string "on Glastrier, his lawful companion\l"
	.string "during his daily strolls.\p"
	.string "But Calyrex had an ace up his sleeve: a\n"
	.string "sinister and deadly steed, that he\l"
	.string "himself locked away in the castle\l"
	.string "dungeons fearing for what it could do\l"
	.string "if left unchecked.\p"
	.string "Spectrier was its name: a spectral\n"
	.string "stallion of pure power and evil. Calyrex,\l"
	.string "initially hesitant and unwilling, was\l"
	.string "forced to bring\p"
	.string "Spectrier into the fray to save what\n"
	.string "remained of Alola. He succeded, thanks\l"
	.string "to the destructive powers of his\l"
	.string "companion, but paid an enormous price:\l"
	.string "Spectrier turned the King from a\p"
	.string "benevolent, wise leader to a hateful,\n"
	.string "cynical, almost feral being, hungry for\l"
	.string "power, blood and death. The Tapus,\l"
	.string "watching this sudden transformation,\l"
	.string "decided not to take any risks:\p"
	.string "they tricked Calyrex into dismounting\n"
	.string "from Spectrier using deceit, and then\l"
	.string "trapped the once-King and the stallion\l"
	.string "in the deepest\p"
	.string "pits of Earth. Livid from the trick\n"
	.string "pulled on them, to this day it is said\l"
	.string "they're plotting revenge on the\l"
	.string "ungrateful and cruel Tapus.\p"
	.string "The incantation holding the King\n"
	.string "hostage can be severed only once in a\l"
	.string "thousand years, but the fated day has\l"
	.string "finally arrived.\p"
	.string "Should you want to free Calyrex and his\n"
	.string "steed, defeat the Pokémon league and\l"
	.string "come back to me.$"

VictoryRoad_B2F_EventScript_LegendaryNPC_Text_2:
# 140 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "It is done: I have severed the Tapu's\n"
	.string "incantation holding The King hostage.\l"
	.string "Use your DexNav to meet him. Good luck.$"

VictoryRoad_B2F_EventScript_LegendaryNPC_Text_3:
# 143 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "It is time for the King to come back to\n"
	.string "us. Defeat every trainer in this route\l"
	.string "and come back to me: that's when I know\l"
	.string "you'll be ready to withstand his power.$"

VictoryRoad_B2F_EventScript_LegendaryNPC_Text_4:
# 148 "data/maps/VictoryRoad_B2F/scripts.pory"
	.string "Not today, not today, not today, not\n"
	.string "today, not today, not today, not today,\l"
	.string "not today... Nobody wants to hear the\l"
	.string "misfortunes that could befall them.\l"
	.string "Fools.$"
