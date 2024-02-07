# 1 "data/maps/VictoryRoad_B1F/scripts.pory"

# 2 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_MapScripts:: @ 82364E4
# 3 "data/maps/VictoryRoad_B1F/scripts.pory"
	.byte 0
# 4 "data/maps/VictoryRoad_B1F/scripts.pory"

# 5 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_EventScript_Samuel:: @ 82364E5
# 6 "data/maps/VictoryRoad_B1F/scripts.pory"
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
# 7 "data/maps/VictoryRoad_B1F/scripts.pory"
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
# 8 "data/maps/VictoryRoad_B1F/scripts.pory"
	end
# 9 "data/maps/VictoryRoad_B1F/scripts.pory"

# 10 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_EventScript_Shannon:: @ 82364FC
# 11 "data/maps/VictoryRoad_B1F/scripts.pory"
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
# 12 "data/maps/VictoryRoad_B1F/scripts.pory"
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
# 13 "data/maps/VictoryRoad_B1F/scripts.pory"
	end
# 14 "data/maps/VictoryRoad_B1F/scripts.pory"

# 15 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_EventScript_Michelle:: @ 8236513
# 16 "data/maps/VictoryRoad_B1F/scripts.pory"
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
# 17 "data/maps/VictoryRoad_B1F/scripts.pory"
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
# 18 "data/maps/VictoryRoad_B1F/scripts.pory"
	end
# 19 "data/maps/VictoryRoad_B1F/scripts.pory"

# 20 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_EventScript_Mitchell:: @ 823652A
# 21 "data/maps/VictoryRoad_B1F/scripts.pory"
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
# 22 "data/maps/VictoryRoad_B1F/scripts.pory"
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
# 23 "data/maps/VictoryRoad_B1F/scripts.pory"
	end
# 24 "data/maps/VictoryRoad_B1F/scripts.pory"

# 25 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_EventScript_Halle:: @ 8236541
# 26 "data/maps/VictoryRoad_B1F/scripts.pory"
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
# 27 "data/maps/VictoryRoad_B1F/scripts.pory"
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
# 28 "data/maps/VictoryRoad_B1F/scripts.pory"
	end
# 29 "data/maps/VictoryRoad_B1F/scripts.pory"

# 30 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_SamuelIntro: @ 8236558
# 31 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "The thought that I'm getting closer to\n"
# 32 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "the Pokémon League…\p"
# 33 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "I'm getting stage fright…$"
# 34 "data/maps/VictoryRoad_B1F/scripts.pory"

# 35 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_SamuelDefeat: @ 82365AD
# 36 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "I couldn't do a thing…$"
# 37 "data/maps/VictoryRoad_B1F/scripts.pory"

# 38 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_SamuelPostBattle: @ 82365C4
# 39 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "The Pokémon League became distant\n"
# 40 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "again… What a letdown…$"
# 41 "data/maps/VictoryRoad_B1F/scripts.pory"

# 42 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_ShannonIntro: @ 82365FD
# 43 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "To win your way through the Pokémon\n"
# 44 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "League, you need the trust of your\l"
# 45 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Pokémon.$"
# 46 "data/maps/VictoryRoad_B1F/scripts.pory"

# 47 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_ShannonDefeat: @ 823664D
# 48 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Your relationship is based on\n"
# 49 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "solid trust.$"
# 50 "data/maps/VictoryRoad_B1F/scripts.pory"

# 51 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_ShannonPostBattle: @ 8236678
# 52 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "By being together all the time, trust\n"
# 53 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "grows between Pokémon and Trainers.$"
# 54 "data/maps/VictoryRoad_B1F/scripts.pory"

# 55 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_MichelleIntro: @ 82366C2
# 56 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "This isn't the goal. It's only a place\n"
# 57 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "on the way to the Pokémon League.$"
# 58 "data/maps/VictoryRoad_B1F/scripts.pory"

# 59 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_MichelleDefeat: @ 823670B
# 60 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "That's the way!$"
# 61 "data/maps/VictoryRoad_B1F/scripts.pory"

# 62 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_MichellePostBattle: @ 823671B
# 63 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "You'll do fine, for sure!\n"
# 64 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Your Pokémon are all eager to go!$"
# 65 "data/maps/VictoryRoad_B1F/scripts.pory"

# 66 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_MitchellIntro: @ 8236757
# 67 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "My Pokémon are cosmically\n"
# 68 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "awe inspiring!$"
# 69 "data/maps/VictoryRoad_B1F/scripts.pory"

# 70 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_MitchellDefeat: @ 8236780
# 71 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "I've never met anyone like you before.$"
# 72 "data/maps/VictoryRoad_B1F/scripts.pory"

# 73 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_MitchellPostBattle: @ 82367A7
# 74 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Even outside of battle, I sense\n"
# 75 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "incredible power emanating from you\l"
# 76 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "and your Pokémon.$"
# 77 "data/maps/VictoryRoad_B1F/scripts.pory"

# 78 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_HalleIntro: @ 82367FD
# 79 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Okay, no need to get your back up!\n"
# 80 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Relax, let's take it easy!$"
# 81 "data/maps/VictoryRoad_B1F/scripts.pory"

# 82 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_HalleDefeat: @ 823683B
# 83 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Whoa!\n"
# 84 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Wonderful!$"
# 85 "data/maps/VictoryRoad_B1F/scripts.pory"

# 86 "data/maps/VictoryRoad_B1F/scripts.pory"
VictoryRoad_B1F_Text_HallePostBattle: @ 823684C
# 87 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Sure, this is Victory Road.\p"
# 88 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "But it's not all that different from\n"
# 89 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "the path you've taken so far.\p"
# 90 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Try to enjoy things the rest of\n"
# 91 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "the way!$"

VictoryRoad_B1F_EventScript_LegendaryNPC::
# 96 "data/maps/VictoryRoad_B1F/scripts.pory"
	lock
# 97 "data/maps/VictoryRoad_B1F/scripts.pory"
	faceplayer
# 98 "data/maps/VictoryRoad_B1F/scripts.pory"
	msgbox VictoryRoad_B1F_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 99 "data/maps/VictoryRoad_B1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq VictoryRoad_B1F_EventScript_LegendaryNPC_2
# 120 "data/maps/VictoryRoad_B1F/scripts.pory"
	msgbox VictoryRoad_B1F_EventScript_LegendaryNPC_Text_4
VictoryRoad_B1F_EventScript_LegendaryNPC_1:
# 122 "data/maps/VictoryRoad_B1F/scripts.pory"
	release
	end

VictoryRoad_B1F_EventScript_LegendaryNPC_2:
# 100 "data/maps/VictoryRoad_B1F/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, VictoryRoad_B1F_EventScript_LegendaryNPC_5
# 108 "data/maps/VictoryRoad_B1F/scripts.pory"
	checktrainerflag TRAINER_HALLE
	goto_if 1, VictoryRoad_B1F_EventScript_LegendaryNPC_11
VictoryRoad_B1F_EventScript_LegendaryNPC_9:
# 115 "data/maps/VictoryRoad_B1F/scripts.pory"
	msgbox VictoryRoad_B1F_EventScript_LegendaryNPC_Text_3
	goto VictoryRoad_B1F_EventScript_LegendaryNPC_1

VictoryRoad_B1F_EventScript_LegendaryNPC_5:
# 101 "data/maps/VictoryRoad_B1F/scripts.pory"
	msgbox VictoryRoad_B1F_EventScript_LegendaryNPC_Text_1
	goto VictoryRoad_B1F_EventScript_LegendaryNPC_1

VictoryRoad_B1F_EventScript_LegendaryNPC_8:
# 112 "data/maps/VictoryRoad_B1F/scripts.pory"
	msgbox VictoryRoad_B1F_EventScript_LegendaryNPC_Text_2
	goto VictoryRoad_B1F_EventScript_LegendaryNPC_1

VictoryRoad_B1F_EventScript_LegendaryNPC_10:
# 110 "data/maps/VictoryRoad_B1F/scripts.pory"
	checktrainerflag TRAINER_SHANNON
	goto_if 1, VictoryRoad_B1F_EventScript_LegendaryNPC_14
	goto VictoryRoad_B1F_EventScript_LegendaryNPC_9

VictoryRoad_B1F_EventScript_LegendaryNPC_11:
# 109 "data/maps/VictoryRoad_B1F/scripts.pory"
	checktrainerflag TRAINER_MITCHELL
	goto_if 1, VictoryRoad_B1F_EventScript_LegendaryNPC_10
	goto VictoryRoad_B1F_EventScript_LegendaryNPC_9

VictoryRoad_B1F_EventScript_LegendaryNPC_14:
# 111 "data/maps/VictoryRoad_B1F/scripts.pory"
	checktrainerflag TRAINER_SAMUEL
	goto_if 1, VictoryRoad_B1F_EventScript_LegendaryNPC_8
	goto VictoryRoad_B1F_EventScript_LegendaryNPC_9


VictoryRoad_B1F_EventScript_LegendaryNPC_Text_0:
# 98 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Sage: The hostile nature of these\n"
	.string "crevaces turn away most without a\l"
	.string "fighting spirit... but not you. Am I\l"
	.string "right?$"

VictoryRoad_B1F_EventScript_LegendaryNPC_Text_1:
# 101 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "This treacherous cave has drawn those\n"
	.string "with a fighting spirit that matches its\l"
	.string "own!\p"
	.string "Whether born from nature or forged\n"
	.string "through life's trials, renegade spirits\l"
	.string "are naturally attracted to these dank\l"
	.string "corridors.\p"
	.string "Take the story of Type:Null: once\n"
	.string "created to eliminate the Ultra Beasts,\l"
	.string "they went berserk and turned rogue\l"
	.string "against their creators.\p"
	.string "They now reside here with Marshadow, a\n"
	.string "mysterious shadow brought to life\l"
	.string "thanks to their sheer willpower and\l"
	.string "indomitable spirit.\p"
	.string "Meeting these two is not an affair to\n"
	.string "take lightly. First, beat the Pokémon\l"
	.string "League, then come back to me.$"

VictoryRoad_B1F_EventScript_LegendaryNPC_Text_2:
# 112 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "Your spirit is aligned with the\n"
	.string "creatures residing in this place. They\l"
	.string "have allowed me to reveal their\l"
	.string "locations to you: I added their info to\l"
	.string "your DexNav. I can't wait to see your\l"
	.string "fight against them!$"

VictoryRoad_B1F_EventScript_LegendaryNPC_Text_3:
# 115 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "I commend your dedication, becoming\n"
	.string "champion must've been a difficult\l"
	.string "affair. But, if you managed to do that,\l"
	.string "I'm sure you'll also be able to beat the\l"
	.string "last few trainers in this cave. Defeat\l"
	.string "them and come back to me.$"

VictoryRoad_B1F_EventScript_LegendaryNPC_Text_4:
# 120 "data/maps/VictoryRoad_B1F/scripts.pory"
	.string "...but you're at Victory Road? Why would\n"
	.string "you NOT have a fighting spirit?$"
