# 1 "data/maps/AquaHideout_B1F/scripts.pory"

# 2 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_MapScripts:: @ 82339A7
# 3 "data/maps/AquaHideout_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, AquaHideout_B1F_OnResume
# 4 "data/maps/AquaHideout_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B1F_OnTransition
# 5 "data/maps/AquaHideout_B1F/scripts.pory"
	.byte 0
# 6 "data/maps/AquaHideout_B1F/scripts.pory"

# 7 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_OnResume: @ 82339B2
# 8 "data/maps/AquaHideout_B1F/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AquaHideout_B1F_EventScript_TryRemoveElectrode
# 9 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 10 "data/maps/AquaHideout_B1F/scripts.pory"

# 11 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_TryRemoveElectrode:: @ 82339BC
# 12 "data/maps/AquaHideout_B1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 13 "data/maps/AquaHideout_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
# 14 "data/maps/AquaHideout_B1F/scripts.pory"
	goto_if_ne Common_EventScript_NopReturn
# 15 "data/maps/AquaHideout_B1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 16 "data/maps/AquaHideout_B1F/scripts.pory"
	return
# 17 "data/maps/AquaHideout_B1F/scripts.pory"

# 18 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_OnTransition: @ 82339D0
# 19 "data/maps/AquaHideout_B1F/scripts.pory"
	call_if_unset FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode1
# 20 "data/maps/AquaHideout_B1F/scripts.pory"
	call_if_unset FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode2
# 21 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 22 "data/maps/AquaHideout_B1F/scripts.pory"

# 23 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_ShowElectrode1:: @ 82339E3
# 24 "data/maps/AquaHideout_B1F/scripts.pory"
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_1
# 25 "data/maps/AquaHideout_B1F/scripts.pory"
	return
# 26 "data/maps/AquaHideout_B1F/scripts.pory"

# 27 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_ShowElectrode2:: @ 82339E7
# 28 "data/maps/AquaHideout_B1F/scripts.pory"
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_2
# 29 "data/maps/AquaHideout_B1F/scripts.pory"
	return
# 30 "data/maps/AquaHideout_B1F/scripts.pory"

# 31 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_Electrode1:: @ 82339EB
# 32 "data/maps/AquaHideout_B1F/scripts.pory"
	lock
# 33 "data/maps/AquaHideout_B1F/scripts.pory"
	faceplayer
# 34 "data/maps/AquaHideout_B1F/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 35 "data/maps/AquaHideout_B1F/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 36 "data/maps/AquaHideout_B1F/scripts.pory"
	setwildbattle SPECIES_ELECTRODE, VAR_0x800A, ITEM_NONE
# 37 "data/maps/AquaHideout_B1F/scripts.pory"
	waitse
# 38 "data/maps/AquaHideout_B1F/scripts.pory"
	playmoncry SPECIES_ELECTRODE, 2
# 39 "data/maps/AquaHideout_B1F/scripts.pory"
	delay 40
# 40 "data/maps/AquaHideout_B1F/scripts.pory"
	waitmoncry
# 41 "data/maps/AquaHideout_B1F/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 42 "data/maps/AquaHideout_B1F/scripts.pory"
	dowildbattle
# 43 "data/maps/AquaHideout_B1F/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 44 "data/maps/AquaHideout_B1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 45 "data/maps/AquaHideout_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 46 "data/maps/AquaHideout_B1F/scripts.pory"
	goto_if_eq AquaHideout_B1F_EventScript_DefeatedElectrode1
# 47 "data/maps/AquaHideout_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 48 "data/maps/AquaHideout_B1F/scripts.pory"
	goto_if_eq AquaHideout_B1F_EventScript_DefeatedElectrode1
# 49 "data/maps/AquaHideout_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 50 "data/maps/AquaHideout_B1F/scripts.pory"
	goto_if_eq AquaHideout_B1F_EventScript_DefeatedElectrode1
# 51 "data/maps/AquaHideout_B1F/scripts.pory"
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
# 52 "data/maps/AquaHideout_B1F/scripts.pory"
	release
# 53 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 54 "data/maps/AquaHideout_B1F/scripts.pory"

# 55 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_DefeatedElectrode1:: @ 8233A2F
# 56 "data/maps/AquaHideout_B1F/scripts.pory"
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
# 57 "data/maps/AquaHideout_B1F/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 58 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 59 "data/maps/AquaHideout_B1F/scripts.pory"

# 60 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_Electrode2:: @ 8233A38
# 61 "data/maps/AquaHideout_B1F/scripts.pory"
	lock
# 62 "data/maps/AquaHideout_B1F/scripts.pory"
	faceplayer
# 63 "data/maps/AquaHideout_B1F/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 64 "data/maps/AquaHideout_B1F/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 65 "data/maps/AquaHideout_B1F/scripts.pory"
	setwildbattle SPECIES_ELECTRODE, VAR_0x800A, ITEM_NONE
# 66 "data/maps/AquaHideout_B1F/scripts.pory"
	waitse
# 67 "data/maps/AquaHideout_B1F/scripts.pory"
	playmoncry SPECIES_ELECTRODE, 2
# 68 "data/maps/AquaHideout_B1F/scripts.pory"
	delay 40
# 69 "data/maps/AquaHideout_B1F/scripts.pory"
	waitmoncry
# 70 "data/maps/AquaHideout_B1F/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 71 "data/maps/AquaHideout_B1F/scripts.pory"
	dowildbattle
# 72 "data/maps/AquaHideout_B1F/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 73 "data/maps/AquaHideout_B1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 74 "data/maps/AquaHideout_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 75 "data/maps/AquaHideout_B1F/scripts.pory"
	goto_if_eq AquaHideout_B1F_EventScript_DefeatedElectrode2
# 76 "data/maps/AquaHideout_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 77 "data/maps/AquaHideout_B1F/scripts.pory"
	goto_if_eq AquaHideout_B1F_EventScript_DefeatedElectrode2
# 78 "data/maps/AquaHideout_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 79 "data/maps/AquaHideout_B1F/scripts.pory"
	goto_if_eq AquaHideout_B1F_EventScript_DefeatedElectrode2
# 80 "data/maps/AquaHideout_B1F/scripts.pory"
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
# 81 "data/maps/AquaHideout_B1F/scripts.pory"
	release
# 82 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 83 "data/maps/AquaHideout_B1F/scripts.pory"

# 84 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_DefeatedElectrode2:: @ 8233A7C
# 85 "data/maps/AquaHideout_B1F/scripts.pory"
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
# 86 "data/maps/AquaHideout_B1F/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 87 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 88 "data/maps/AquaHideout_B1F/scripts.pory"

# 89 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_Grunt2:: @ 8233A85
# 90 "data/maps/AquaHideout_B1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_2, AquaHideout_B1F_Text_Grunt2Intro, AquaHideout_B1F_Text_Grunt2Defeat, AquaHideout_B1F_EventScript_Grunt2Defeated
# 91 "data/maps/AquaHideout_B1F/scripts.pory"
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 92 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 93 "data/maps/AquaHideout_B1F/scripts.pory"

# 94 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_Grunt2Defeated:: @ 8233AA0
# 95 "data/maps/AquaHideout_B1F/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 96 "data/maps/AquaHideout_B1F/scripts.pory"
	waitmovement 0
# 97 "data/maps/AquaHideout_B1F/scripts.pory"
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
# 98 "data/maps/AquaHideout_B1F/scripts.pory"
	release
# 99 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 100 "data/maps/AquaHideout_B1F/scripts.pory"

# 101 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_Grunt3:: @ 8233AB0
# 102 "data/maps/AquaHideout_B1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_3, AquaHideout_B1F_Text_Grunt3Intro, AquaHideout_B1F_Text_Grunt3Defeat, AquaHideout_B1F_EventScript_Grunt3Defeated
# 103 "data/maps/AquaHideout_B1F/scripts.pory"
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 104 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 105 "data/maps/AquaHideout_B1F/scripts.pory"

# 106 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_Grunt3Defeated:: @ 8233ACB
# 107 "data/maps/AquaHideout_B1F/scripts.pory"
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_DEFAULT
# 108 "data/maps/AquaHideout_B1F/scripts.pory"
	release
# 109 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 110 "data/maps/AquaHideout_B1F/scripts.pory"

# 111 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_Grunt5:: @ 8233AD5
# 112 "data/maps/AquaHideout_B1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_5, AquaHideout_B1F_Text_Grunt5Intro, AquaHideout_B1F_Text_Grunt5Defeat
# 113 "data/maps/AquaHideout_B1F/scripts.pory"
	msgbox AquaHideout_B1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
# 114 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 115 "data/maps/AquaHideout_B1F/scripts.pory"

# 116 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_EventScript_Grunt7:: @ 8233AEC
# 117 "data/maps/AquaHideout_B1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_7, AquaHideout_B1F_Text_Grunt7Intro, AquaHideout_B1F_Text_Grunt7Defeat
# 118 "data/maps/AquaHideout_B1F/scripts.pory"
	msgbox AquaHideout_B1F_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
# 119 "data/maps/AquaHideout_B1F/scripts.pory"
	end
# 120 "data/maps/AquaHideout_B1F/scripts.pory"

# 121 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt2Intro: @ 8233B03
# 122 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "If you want to know the secret about\n"
# 123 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "our Hideout, you have me to beat!$"
# 124 "data/maps/AquaHideout_B1F/scripts.pory"

# 125 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt2Defeat: @ 8233B4A
# 126 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "I can't win at all…$"
# 127 "data/maps/AquaHideout_B1F/scripts.pory"

# 128 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt2PostBattle: @ 8233B5E
# 129 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Our Hideout's secret?\p"
# 130 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Well, let's just say…\n"
# 131 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "There's a submarine at the far end!\p"
# 132 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "But, by now…\n"
# 133 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Kekekeke…$"
# 134 "data/maps/AquaHideout_B1F/scripts.pory"

# 135 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt3Intro: @ 8233BC5
# 136 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Fuel supply loaded A-OK!\n"
# 137 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "In-cruise snacks loaded A-OK!\p"
# 138 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Nothing left to do but KO a pesky\n"
# 139 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "meddler!$"
# 140 "data/maps/AquaHideout_B1F/scripts.pory"

# 141 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt3Defeat: @ 8233C27
# 142 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "I took a serious licking!$"
# 143 "data/maps/AquaHideout_B1F/scripts.pory"

# 144 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt3PostBattle: @ 8233C41
# 145 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Humph!\n"
# 146 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "This was supposed to happen!\p"
# 147 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "My mission was to just hold you up!$"
# 148 "data/maps/AquaHideout_B1F/scripts.pory"

# 149 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt5Intro: @ 8233C89
# 150 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Yawn… Keeping watch over the\n"
# 151 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Hideout bores me. I'll take you on.$"
# 152 "data/maps/AquaHideout_B1F/scripts.pory"

# 153 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt5Defeat: @ 8233CCA
# 154 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Yawn…\n"
# 155 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Oh, I lost…$"
# 156 "data/maps/AquaHideout_B1F/scripts.pory"

# 157 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt5PostBattle: @ 8233CDC
# 158 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "If you scurry too much, other Team\n"
# 159 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Aqua members might get you.$"
# 160 "data/maps/AquaHideout_B1F/scripts.pory"

# 161 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt7Intro: @ 8233D1B
# 162 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Hey!\n"
# 163 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "You there!\p"
# 164 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Which do you think is cooler?\n"
# 165 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "Team Aqua's uniform or Team Magma's?$"
# 166 "data/maps/AquaHideout_B1F/scripts.pory"

# 167 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt7Defeat: @ 8233D6E
# 168 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "I lost in a cool way…$"
# 169 "data/maps/AquaHideout_B1F/scripts.pory"

# 170 "data/maps/AquaHideout_B1F/scripts.pory"
AquaHideout_B1F_Text_Grunt7PostBattle: @ 8233D84
# 171 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "If you have a cool uniform, you look\n"
# 172 "data/maps/AquaHideout_B1F/scripts.pory"
	.string "good even in a loss, don't you think?$"
