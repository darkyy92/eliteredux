VictoryRoad_B2F_MapScripts:: @ 82368D4
	.byte 0

VictoryRoad_B2F_EventScript_Vito:: @ 82368D5
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen:: @ 82368EC
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline:: @ 8236903
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie:: @ 823691A
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix:: @ 8236931
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne:: @ 8236948
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro: @ 823695F
	.string "I trained together with my whole family,\n"
	.string "every one of us!\l"
	.string "I'm not losing to anyone!$"

VictoryRoad_B2F_Text_VitoDefeat: @ 82369B3
	.string "Better than my family?!\n"
	.string "Is that possible?!$"

VictoryRoad_B2F_Text_VitoPostBattle: @ 82369DE
	.string "I was better than everyone in my\n"
	.string "family. I've never lost before…\p"
	.string "I've lost my confidence…\n"
	.string "Maybe I'll go home…$"

VictoryRoad_B2F_Text_OwenIntro: @ 8236A4C
	.string "I'd heard that there was a tough\n"
	.string "little kid around. Do they mean you?$"

VictoryRoad_B2F_Text_OwenDefeat: @ 8236A92
	.string "The little shrimp is tough!$"

VictoryRoad_B2F_Text_OwenPostBattle: @ 8236AAE
	.string "The rumors I heard, that tough little\n"
	.string "kid is from Petalburg City.$"

VictoryRoad_B2F_Text_CarolineIntro: @ 8236AF0
	.string "You must be getting a little tired.$"

VictoryRoad_B2F_Text_CarolineDefeat: @ 8236B14
	.string "No signs of tiring at all!$"

VictoryRoad_B2F_Text_CarolinePostBattle: @ 8236B2F
	.string "Victory Road and the Pokémon League\n"
	.string "are long and grueling challenges.\l"
	.string "Beware of fatigue!$"

VictoryRoad_B2F_Text_JulieIntro: @ 8236B88
	.string "You shouldn't get complacent just\n"
	.string "because you have a lot of Gym Badges.\p"
	.string "There's always going to be someone\n"
	.string "who's better than you!$"

VictoryRoad_B2F_Text_JulieDefeat: @ 8236C0A
	.string "You're better than me!$"

VictoryRoad_B2F_Text_JuliePostBattle: @ 8236C21
	.string "Gaze on your collected Badges and\n"
	.string "remember the Trainers you've faced.$"

VictoryRoad_B2F_Text_FelixIntro: @ 8236C67
	.string "I've come this far, but the tension's\n"
	.string "giving me awful stomach pain…$"

VictoryRoad_B2F_Text_FelixDefeat: @ 8236CAB
	.string "Ooh…\n"
	.string "It hurts…$"

VictoryRoad_B2F_Text_FelixPostBattle: @ 8236CBA
	.string "I can't help getting all tense knowing\n"
	.string "that I'm nearing the Pokémon League.\p"
	.string "It's all I can do to feign calm.$"

VictoryRoad_B2F_Text_DianneIntro: @ 8236D27
	.string "The elite among the elite gather in\n"
	.string "this cave.\p"
	.string "How are you finding it?$"

VictoryRoad_B2F_Text_DianneDefeat: @ 8236D6E
	.string "Not rattled in the least bit!$"

VictoryRoad_B2F_Text_DiannePostBattle: @ 8236D8C
	.string "You do have guts! I like that!\n"
	.string "Keep it going!$"

VictoryRoad_B2F_EventScript_LegendaryNPC::
	lock
	faceplayer
	msgbox VictoryRoad_B2F_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq VictoryRoad_B2F_EventScript_LegendaryNPC_2
	msgbox VictoryRoad_B2F_EventScript_LegendaryNPC_Text_4
VictoryRoad_B2F_EventScript_LegendaryNPC_1:
	release
	end

VictoryRoad_B2F_EventScript_LegendaryNPC_2:
	goto_if_unset FLAG_SYS_GAME_CLEAR, VictoryRoad_B2F_EventScript_LegendaryNPC_5
	checktrainerflag TRAINER_JULIE
	goto_if 1, VictoryRoad_B2F_EventScript_LegendaryNPC_11
VictoryRoad_B2F_EventScript_LegendaryNPC_9:
	msgbox VictoryRoad_B2F_EventScript_LegendaryNPC_Text_3
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_1

VictoryRoad_B2F_EventScript_LegendaryNPC_5:
	msgbox VictoryRoad_B2F_EventScript_LegendaryNPC_Text_1
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_1

VictoryRoad_B2F_EventScript_LegendaryNPC_8:
	msgbox VictoryRoad_B2F_EventScript_LegendaryNPC_Text_2
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_1

VictoryRoad_B2F_EventScript_LegendaryNPC_10:
	checktrainerflag TRAINER_OWEN
	goto_if 1, VictoryRoad_B2F_EventScript_LegendaryNPC_15
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_9

VictoryRoad_B2F_EventScript_LegendaryNPC_11:
	checktrainerflag TRAINER_CAROLINE
	goto_if 1, VictoryRoad_B2F_EventScript_LegendaryNPC_10
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_9

VictoryRoad_B2F_EventScript_LegendaryNPC_14:
	checktrainerflag TRAINER_FELIX
	goto_if 1, VictoryRoad_B2F_EventScript_LegendaryNPC_18
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_9

VictoryRoad_B2F_EventScript_LegendaryNPC_15:
	checktrainerflag TRAINER_VITO
	goto_if 1, VictoryRoad_B2F_EventScript_LegendaryNPC_14
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_9

VictoryRoad_B2F_EventScript_LegendaryNPC_18:
	checktrainerflag TRAINER_DIANNE
	goto_if 1, VictoryRoad_B2F_EventScript_LegendaryNPC_8
	goto VictoryRoad_B2F_EventScript_LegendaryNPC_9


VictoryRoad_B2F_EventScript_LegendaryNPC_Text_0:
	.string "Sage: Once upon a time, I was a bard and\n"
	.string "lorekeeper of these lands. I'm now\l"
	.string "retired, like another colleague of mine,\l"
	.string "but together we told the story of King\l"
	.string "Calyrex. I happen to know the SECOND\l"
	.string "part of the story, an infamous one. Do\l"
	.string "you want to hear it?$"

VictoryRoad_B2F_EventScript_LegendaryNPC_Text_1:
	.string "You might have heard the first part of\n"
	.string "the legend of King Calyrex. If you\l"
	.string "have, let me tell you the latter part of\l"
	.string "the story, one that many people don't\l"
	.string "know about.\p"
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
	.string "allow no half measures to be taken.\l"
	.string "This was one of those situations.\p"
	.string "You see, the King had so far only rode\n"
	.string "on Glastrier, his lawful companion\l"
	.string "during his daily strolls.\p"
	.string "But Calyrex had an ace up his sleeve: a\n"
	.string "sinister and deadly steed, that he\l"
	.string "himself locked away in the castle\l"
	.string "dungeons fearing for what it could do\l"
	.string "if left unchecked.\p"
	.string "Spectrier was its name: a spectral\n"
	.string "stallion of pure power and evil.\l"
	.string "Calyrex, initially hesitant and\l"
	.string "unwilling, was forced to bring\p"
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
	.string "It is done: I have severed the Tapu's\n"
	.string "incantation holding The King hostage.\l"
	.string "Use your DexNav to meet him. Good luck.$"

VictoryRoad_B2F_EventScript_LegendaryNPC_Text_3:
	.string "It is time for the King to come back to\n"
	.string "us. Defeat every trainer in this route\l"
	.string "and come back to me: that's when I\l"
	.string "know you'll be ready to withstand his\l"
	.string "power.$"

VictoryRoad_B2F_EventScript_LegendaryNPC_Text_4:
	.string "Not today, not today, not today, not\n"
	.string "today, not today, not today, not today,\l"
	.string "not today... Nobody wants to hear the\l"
	.string "misfortunes that could befall them.\l"
	.string "Fools.$"
