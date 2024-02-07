# 1 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 2 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
.set LOCALID_EVIE, 1
# 3 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
.set LOCALID_IVY,  2
# 4 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 5 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_MapScripts::
# 6 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_MoveRelearnersHouse_OnFrame
# 7 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.byte 0
# 8 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 9 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_OnFrame:
# 10 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	map_script_2 VAR_IVY_EVIE_HOUSE_STATE, 0, FallarborTown_EventScript_IvyEvieIntro
# 11 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte 0
# 12 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
		
# 13 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_EventScript_IvyEvieIntro::
# 14 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_IVY_EVIE_HOUSE_STATE, 1
# 15 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
# 16 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 17 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 18 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_Movement_MoveEvieDown:
# 19 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	walk_fastest_down
# 20 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	walk_fastest_down
# 21 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	walk_fastest_left
# 22 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	walk_in_place_fastest_down
# 23 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	step_end
# 24 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 25 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_Movement_MoveIvyDown:
# 26 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	walk_fastest_down
# 27 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	walk_fastest_down
# 28 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	walk_fastest_left
# 29 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	walk_fastest_left
# 30 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	walk_fastest_left
# 31 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	walk_in_place_fastest_down
# 32 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	step_end
# 33 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 34 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_Text_AnnoyingIntroPart1:
# 35 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Hey there, Trainer!\p"
# 36 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "If you want your Pokémon to be the very\n"
# 37 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "best in all of Hoenn, you've come to\l"
# 38 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "the right place!\p"
# 39 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I'm Evie, and this is my sister, Ivy.$"
# 40 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 41 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_Text_AnnoyingIntroPart2:
# 42 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "We offer special training\n"
# 43 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "programs that will seriously beef up\l"
# 44 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "your team!$"
# 45 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 46 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_Text_AnnoyingIntroPart3:
# 47 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "But our services don't come cheap.\n"
# 48 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Well, mine don't, at least.\p"
# 49 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "You can pay Ivy with junk-$"
# 50 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 51 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_Text_AnnoyingIntroPart4:
# 52 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Hey!\n"
# 53 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Those Bottle Caps aren't junk!\p"
# 54 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "They're highly collectable, thank\n"
# 55 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "you very much!$"
# 56 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 57 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_Text_AnnoyingIntroPart5:
# 58 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Yeah, yeah, if you say so…\p"
# 59 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Anyway, do you know about your Pokémon's\n"
# 60 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Effort Values, or EVs for short?$"
# 61 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 62 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_Text_AnnoyingIntroPart6:
# 63 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "OK! now, how about Individual\n"
# 64 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Values, or IVs?\p"
# 65 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Do you want me to explain them?$"
# 66 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 67 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_Text_AnnoyingIntroPart7:
# 68 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Right, here's the deal. For ¥100,\n"
# 69 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I'll increase a Pokémon's EVs by one.$"
# 70 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 71 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_Text_AnnoyingIntroPart8:
# 72 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "And for one Bottle Cap, I'll change\n"
# 73 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "one of a Pokémon's IVs to whatever\l"
# 74 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "you want.\p"
# 75 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Also, for three Caps, I'll change all\n"
# 76 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "of a Pokémon's IVs to give them a new\l"
# 77 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Hidden Power type.$"
# 78 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 79 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
		
# 80 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
		
# 81 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
@@@@@@@@@@@@@@@@ Super Training Script @@@@@@@@@@@@@@@@
# 82 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 83 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_SuperTrainer::
# 84 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	lock
# 85 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	faceplayer
# 86 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox SuperTraining_Text_ChoosePokemon, MSGBOX_DEFAULT
# 87 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special ChoosePartyMon
# 88 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitstate
# 89 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_0x8004, PARTY_SIZE
# 90 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_ge SuperTraining_Refuse
# 91 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 92 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
# 93 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq SuperTraining_Egg
# 94 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 95 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox SuperTraining_Text_TakeALookatEVs, MSGBOX_DEFAULT
# 96 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_SuperMainMenu
# 97 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 98 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_SuperMainMenu::
# 99 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 100 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox SuperTraining_Text_HowCanIHelp, MSGBOX_DEFAULT
# 101 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SUPER_TRAINING_MENU, 0
# 102 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	switch VAR_RESULT
# 103 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 0, FallarborTown_ChangeEV
# 104 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 1, FallarborTown_ResetEVs
# 105 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 2, Call_FallarborTown_Explain_EVs
# 106 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 3, HyperTraining_EventScript_DoNothing
# 107 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 127, HyperTraining_EventScript_DoNothing
# 108 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
# 109 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 110 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 111 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
Call_FallarborTown_Explain_EVs::
# 112 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	call FallarborTown_Explain_EVs
# 113 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_SuperMainMenu
# 114 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 115 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_Explain_EVs::
# 116 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_Text_ExplainEvs, MSGBOX_DEFAULT
# 117 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	return
# 118 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 119 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChangeEV::
# 120 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 121 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	@specialvar VAR_RESULT, AreChosenMonEVsMaxedOut
# 122 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	@compare VAR_RESULT, 1
# 123 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	@goto_if_eq FallarborTown_EVsMaxedOut
# 124 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox SuperTraining_Text_ThisIsMonsCurrentSpread, MSGBOX_DEFAULT
# 125 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special BufferChosenMonAllEVs
# 126 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	multichoice 0, 0, MULTI_BASE_STATS, 0
# 127 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	switch VAR_RESULT
# 128 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 0, HyperTraining_EventScript_ChangeHPEV
# 129 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 1, FallarborTown_ChangeATKEV
# 130 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 2, FallarborTown_ChangeDEFEV
# 131 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 3, FallarborTown_ChangeSPEEDEV
# 132 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 4, FallarborTown_ChangeSPATKEV
# 133 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 5, FallarborTown_ChangeSPDEFEV
# 134 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 127, FallarborTown_SuperMainMenu
# 135 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
# 136 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 137 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 138 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHPEV::
# 139 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8005, 0
# 140 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special BufferChosenMonEV
# 141 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 142 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	buffernumberstring 1, VAR_0x8006
# 143 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_0x8006, 252
# 144 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq FallarborTown_MaxEVs
# 145 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox SuperTraining_ReportHP
# 146 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_ChooseNewEV
# 147 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 148 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChangeATKEV::
# 149 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8005, 1
# 150 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special BufferChosenMonEV
# 151 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 152 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	buffernumberstring 1, VAR_0x8006
# 153 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_0x8006, 252
# 154 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq FallarborTown_MaxEVs
# 155 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox SuperTraining_ReportAtk
# 156 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_ChooseNewEV
# 157 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 158 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChangeDEFEV::
# 159 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8005, 2
# 160 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special BufferChosenMonEV
# 161 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 162 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	buffernumberstring 1, VAR_0x8006
# 163 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_0x8006, 252
# 164 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq FallarborTown_MaxEVs
# 165 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox SuperTraining_ReportDef
# 166 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_ChooseNewEV
# 167 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 168 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChangeSPEEDEV::
# 169 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8005, 3
# 170 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special BufferChosenMonEV
# 171 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 172 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	buffernumberstring 1, VAR_0x8006
# 173 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_0x8006, 252
# 174 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq FallarborTown_MaxEVs
# 175 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox SuperTraining_ReportSpeed
# 176 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_ChooseNewEV
# 177 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 178 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChangeSPATKEV::
# 179 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8005, 4
# 180 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special BufferChosenMonEV
# 181 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 182 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	buffernumberstring 1, VAR_0x8006
# 183 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_0x8006, 252
# 184 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq FallarborTown_MaxEVs
# 185 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox SuperTraining_ReportSpAtk
# 186 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_ChooseNewEV
# 187 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 188 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChangeSPDEFEV::
# 189 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8005, 5
# 190 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special BufferChosenMonEV
# 191 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 192 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	buffernumberstring 1, VAR_0x8006
# 193 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_0x8006, 252
# 194 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq FallarborTown_MaxEVs
# 195 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox SuperTraining_ReportSpDef
# 196 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_ChooseNewEV
# 197 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 198 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MaxEVs::
# 199 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox SuperTraining_ReportMaxEVs
# 200 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_ChangeEV
# 201 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 202 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_EVsMaxedOut::
# 203 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox SuperTraining_ReportMaxTotalEVs
# 204 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_SuperMainMenu
# 205 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 206 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChooseNewEV::
# 207 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	multichoice 0, 0, MULTI_EV_MENU, 0
# 208 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	switch VAR_RESULT
# 209 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 0, FallarborTown_ChangeEV4
# 210 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 1, FallarborTown_ChangeEV8
# 211 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 2, FallarborTown_ChangeEV12
# 212 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 3, FallarborTown_ChangeEV64
# 213 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 4, FallarborTown_ChangeEV128
# 214 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 5, FallarborTown_ChangeEV252
# 215 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 127, FallarborTown_ChangeEV
# 216 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 217 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChangeEV4::
# 218 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8006, 4
# 219 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8009, 400
# 220 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_DoSuperTraining
# 221 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 222 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChangeEV8::
# 223 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8006, 8
# 224 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8009, 800
# 225 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_DoSuperTraining
# 226 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 227 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChangeEV12::
# 228 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8006, 12
# 229 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8009, 1200
# 230 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_DoSuperTraining
# 231 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 232 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChangeEV64::
# 233 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8006, 64
# 234 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8009, 6400
# 235 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_DoSuperTraining
# 236 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 237 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChangeEV128::
# 238 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8006, 128
# 239 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8009, 12800
# 240 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_DoSuperTraining
# 241 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 242 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChangeEV252::
# 243 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8006, 252
# 244 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8009, 25200
# 245 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_DoSuperTraining
# 246 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 247 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ResetEVs::
# 248 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox SuperTraining_Text_ICanResetEVs, MSGBOX_YESNO
# 249 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 0
# 250 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq FallarborTown_SuperMainMenu
# 251 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special ResetChosenMonEVs
# 252 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox SuperTraining_Text_EVsReset, MSGBOX_DEFAULT
# 253 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_SuperMainMenu
# 254 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	
# 255 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_DoSuperTraining::
# 256 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special CheckChosenMonCanGainEVs
# 257 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 0
# 258 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq FallarborTown_CantExceedEVLimit
# 259 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	showmoneybox 15, 0, 0
# 260 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	buffernumberstring 2, VAR_0x8009
# 261 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox SuperTraining_ShowPrice, MSGBOX_YESNO
# 262 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 0
# 263 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq FallarborTown_WontPay
# 264 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	checkmoney VAR_0x8009, 0
# 265 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 0
# 266 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq FallarborTown_CantAfford
# 267 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	removemoney VAR_0x8009, 0
# 268 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	updatemoneybox 0, 0
# 269 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special IncreaseChosenMonEVs
# 270 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 271 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	buffernumberstring 1, VAR_0x8007
# 272 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox SuperTraining_Text_EVsHaveIncreased
# 273 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	hidemoneybox
# 274 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_ChangeEV
# 275 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 276 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_CantExceedEVLimit::
# 277 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	buffernumberstring 1, VAR_0x8008
# 278 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox SuperTraining_TooManyEVs, MSGBOX_DEFAULT
# 279 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_ChangeEV
# 280 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 281 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_WontPay::
# 282 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	hidemoneybox
# 283 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_ChangeEV
# 284 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 285 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_CantAfford::
# 286 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_CantAfford_String, MSGBOX_DEFAULT
# 287 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	hidemoneybox
# 288 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_ChangeEV
# 289 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 290 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_DoNothing::
# 291 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
# 292 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 293 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 294 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_Egg::
# 295 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_Text_CantTrainEgg, MSGBOX_DEFAULT
# 296 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
# 297 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 298 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 299 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_Refuse::
# 300 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_Text_SomeOtherTime, MSGBOX_DEFAULT
# 301 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
# 302 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 303 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 304 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_Text_ChoosePokemon:
# 305 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Which Pokémon would you like me\n"
# 306 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "to train?$"
# 307 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 308 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_Text_CantTrainEgg:
# 309 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Oh come on, I can't train an Egg!\n"
# 310 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Bring it back once it's hatched.$"
# 311 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 312 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_Text_SomeOtherTime:
# 313 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Oh, OK.\n"
# 314 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Some other time, then?$"
# 315 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 316 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_Text_RememberEvs:
# 317 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "And you remember how EVs work, right?$"
# 318 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 319 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_Text_ExplainEvs:
# 320 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "EVs are part of every stat a\n"
# 321 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "a Pokémon has.\p"
# 322 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "They can have HP EVs, Attack EVs,\n"
# 323 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Defense EVs… you get the idea.\p"
# 324 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Every time your Pokémon gains\n"
# 325 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "experience in battle, it also gains EVs.\p"
# 326 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "The kind of EVs gained depends on the\n"
# 327 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "kind of Pokémon you defeated.\p"
# 328 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "For example, beating a Zubat will give\n"
# 329 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "your Pokémon one Speed EV.\p"
# 330 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Once you have enough EVs in a stat,\n"
# 331 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "that stat will go up!\p"
# 332 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "You can have up to 252 EVs in one stat,\n"
# 333 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "but you can only have 510 EVs in total.\p"
# 334 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "It's normally good to put 252 EVs in\n"
# 335 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "two of your Pokémon's best stats,\l"
# 336 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "but you can get creative with EVs too!$"
# 337 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 338 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_Text_TakeALookatEVs:
# 339 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Let's take a look at your {STR_VAR_1}'s EVs.$"
# 340 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 341 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_Text_ThisIsMonsCurrentSpread:
# 342 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "This is {STR_VAR_1}'s current EV\n"
# 343 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "spread.\p"
# 344 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Which stat would you like it to train?$"
# 345 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 346 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_ReportHP:
# 347 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1} has {STR_VAR_2} HP EVs.\n"
# 348 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "How many EVs would you like to add?$"
# 349 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 350 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_ReportAtk:
# 351 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1} has {STR_VAR_2} Attack EVs.\n"
# 352 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "How many EVs would you like to add?$"
# 353 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 354 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_ReportDef:
# 355 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1} has {STR_VAR_2} Defense EVs.\n"
# 356 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "How many EVs would you like to add?$"
# 357 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 358 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_ReportSpeed:
# 359 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1} has {STR_VAR_2} Speed EVs.\n"
# 360 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "How many EVs would you like to add?$"
# 361 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 362 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_ReportSpAtk:
# 363 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1} has {STR_VAR_2} Sp. Atk EVs.\n"
# 364 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "How many EVs would you like to add?$"
# 365 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 366 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_ReportSpDef:
# 367 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1} has {STR_VAR_2} Sp. Def EVs.\n"
# 368 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "How many EVs would you like to add?$"
# 369 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 370 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_Text_EVsHaveIncreased:
# 371 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1}'s EVs in that stat have\n"
# 372 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "increased to {STR_VAR_2}!$"
# 373 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 374 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_Text_ICanResetEVs:
# 375 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I can completely reset your\n"
# 376 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1}'s EVs for free!\p"
# 377 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "This will remove all of its EVs, so\n"
# 378 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "you can add more to the stats you want\l"
# 379 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1} to focus on.\p"
# 380 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Would you like me to reset\n"
# 381 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1}'s EVs?$"
# 382 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 383 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_Text_HowCanIHelp:
# 384 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "How can I help {STR_VAR_1} today?$"
# 385 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	
# 386 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_Text_EVsReset::
# 387 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1}'s EVs have been reset!$"
# 388 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 389 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_ReportMaxEVs:
# 390 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1} has 252 EVs in that stat!\n"
# 391 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "It can't gain any more!$"
# 392 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 393 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_ReportMaxTotalEVs:
# 394 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1}'s EVs are maxed out!\n"
# 395 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "It can't gain any more!$"
# 396 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 397 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_TooManyEVs:
# 398 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1} already has {STR_VAR_2} EVs in total!\n"
# 399 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "It can't gain that many more!$"
# 400 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 401 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
SuperTraining_ShowPrice:
# 402 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "That'll cost ¥{STR_VAR_3}. Is that OK?$"
# 403 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 404 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_CantAfford_String:
# 405 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "You don't have the money.$"
# 406 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 407 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
@@@@@@@@@@@@@@@@ Hyper Training Script @@@@@@@@@@@@@@@@
# 408 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 409 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_HyperTrainer::
# 410 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	lockall
# 411 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	faceplayer
# 412 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox HyperTraining_Text_ChoosePokemon, MSGBOX_DEFAULT
# 413 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special ChoosePartyMon
# 414 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitstate
# 415 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_0x8004, PARTY_SIZE
# 416 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_ge SuperTraining_Refuse
# 417 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 418 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
# 419 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq SuperTraining_Egg
# 420 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 421 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox HyperTraining_Text_LetsTakeALook, MSGBOX_DEFAULT
# 422 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_HyperMainMenu
# 423 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 424 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_HyperMainMenu::
# 425 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 426 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox HyperTraining_Text_HowCanIHelp, MSGBOX_DEFAULT
# 427 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	multichoice 0, 0, MULTI_HYPER_TRAINING_MENU, 0
# 428 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	switch VAR_RESULT
# 429 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 0, HyperTraining_EventScript_ChangeIV
# 430 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 1, HyperTraining_EventScript_ChangeHiddenPower
# 431 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 2, Call_HyperTraining_EventScript_Explain_IVs
# 432 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 3, HyperTraining_EventScript_DoNothing
# 433 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 127, HyperTraining_EventScript_DoNothing
# 434 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
# 435 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 436 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 437 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
Call_HyperTraining_EventScript_Explain_IVs::
# 438 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	call HyperTraining_EventScript_Explain_IVs
# 439 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_HyperMainMenu
# 440 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 441 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_Explain_IVs::
# 442 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox HyperTraining_Text_ExplainIVs, MSGBOX_DEFAULT
# 443 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	return
# 444 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 445 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeIV::
# 446 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 447 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox HyperTraining_Text_WhichIVShouldChange, MSGBOX_DEFAULT
# 448 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special BufferChosenMonAllIVs
# 449 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	multichoice 0, 0, MULTI_BASE_STATS, 0
# 450 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	switch VAR_RESULT
# 451 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 0, HyperTraining_EventScript_ChangeHPIV
# 452 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 1, FallarborTown_ChangeATKIV
# 453 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 2, FallarborTown_ChangeDEFIV
# 454 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 3, FallarborTown_ChangeSPEEDIV
# 455 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 4, FallarborTown_ChangeSPATKIV
# 456 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 5, FallarborTown_ChangeSPDEFIV
# 457 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 127, FallarborTown_HyperMainMenu
# 458 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
# 459 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 460 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 461 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHPIV::
# 462 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8005, 0
# 463 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special BufferChosenMonIV
# 464 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 465 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	buffernumberstring 1, VAR_0x8006
# 466 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox HyperTraining_ReportHP
# 467 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_ChooseNewIV
# 468 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 469 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChangeATKIV::
# 470 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8005, 1
# 471 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special BufferChosenMonIV
# 472 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 473 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	buffernumberstring 1, VAR_0x8006
# 474 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox HyperTraining_ReportAtk
# 475 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_ChooseNewIV
# 476 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 477 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChangeDEFIV::
# 478 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8005, 2
# 479 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special BufferChosenMonIV
# 480 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 481 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	buffernumberstring 1, VAR_0x8006
# 482 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox HyperTraining_ReportDef
# 483 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_ChooseNewIV
# 484 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 485 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChangeSPEEDIV::
# 486 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8005, 3
# 487 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special BufferChosenMonIV
# 488 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 489 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	buffernumberstring 1, VAR_0x8006
# 490 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox HyperTraining_ReportSpeed
# 491 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_ChooseNewIV
# 492 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 493 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChangeSPATKIV::
# 494 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8005, 4
# 495 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special BufferChosenMonIV
# 496 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 497 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	buffernumberstring 1, VAR_0x8006
# 498 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox HyperTraining_ReportSpAtk
# 499 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_ChooseNewIV
# 500 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 501 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChangeSPDEFIV::
# 502 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8005, 5
# 503 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special BufferChosenMonIV
# 504 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 505 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	buffernumberstring 1, VAR_0x8006
# 506 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox HyperTraining_ReportSpDef
# 507 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_ChooseNewIV
# 508 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 509 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_ChooseNewIV::
# 510 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	multichoice 0, 0, MULTI_IV_MENU, 0
# 511 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	switch VAR_RESULT
# 512 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 0, HyperTraining_EventScript_ChangeIV0
# 513 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 1, HyperTraining_EventScript_ChangeIV1
# 514 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 2, HyperTraining_EventScript_ChangeIV14
# 515 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 3, HyperTraining_EventScript_ChangeIV15
# 516 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 4, HyperTraining_EventScript_ChangeIV30
# 517 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 5, HyperTraining_EventScript_ChangeIV31
# 518 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 127, HyperTraining_EventScript_ChangeIV
# 519 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 520 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeIV0::
# 521 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8006, 0
# 522 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeOneIV
# 523 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 524 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeIV1::
# 525 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8006, 1
# 526 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeOneIV
# 527 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 528 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeIV14::
# 529 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8006, 14
# 530 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeOneIV
# 531 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 532 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeIV15::
# 533 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8006, 15
# 534 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeOneIV
# 535 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 536 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeIV30::
# 537 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8006, 30
# 538 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeOneIV
# 539 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 540 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeIV31::
# 541 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8006, 31
# 542 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeOneIV
# 543 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 544 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeOneIV::
# 545 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special ChangeChosenMonIVs
# 546 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_DoHyperTraining
# 547 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 548 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHiddenPower::
# 549 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox HyperTraining_Text_ChangeAllIVs, MSGBOX_DEFAULT
# 550 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	copyvar VAR_0x800A, VAR_0x8004
# 551 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_HIDDEN_POWER
# 552 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special ShowScrollableMultichoice
# 553 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitstate
# 554 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	switch VAR_RESULT
# 555 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 0, HyperTraining_EventScript_ChangeHPFighting
# 556 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 1, HyperTraining_EventScript_ChangeHPFlying
# 557 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 2, HyperTraining_EventScript_ChangeHPPoison
# 558 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 3, HyperTraining_EventScript_ChangeHPGround
# 559 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 4, HyperTraining_EventScript_ChangeHPRock
# 560 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 5, HyperTraining_EventScript_ChangeHPBug
# 561 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 6, HyperTraining_EventScript_ChangeHPGhost
# 562 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 7, HyperTraining_EventScript_ChangeHPSteel
# 563 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 8, HyperTraining_EventScript_ChangeHPFire
# 564 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 9, HyperTraining_EventScript_ChangeHPWater
# 565 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 10, HyperTraining_EventScript_ChangeHPGrass
# 566 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 11, HyperTraining_EventScript_ChangeHPElectric
# 567 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 12, HyperTraining_EventScript_ChangeHPPsychic
# 568 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 13, HyperTraining_EventScript_ChangeHPIce
# 569 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 14, HyperTraining_EventScript_ChangeHPDragon
# 570 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 15, HyperTraining_EventScript_ChangeHPDark
# 571 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 16, HyperTraining_EventScript_RebufferChosenMon
# 572 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case 127, HyperTraining_EventScript_RebufferChosenMon
# 573 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
# 574 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 575 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 576 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHPFighting::
# 577 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar 0x8007, 0
# 578 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeAllIVs
# 579 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 580 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHPFlying::
# 581 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar 0x8007, 1
# 582 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeAllIVs
# 583 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 584 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHPPoison::
# 585 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar 0x8007, 2
# 586 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeAllIVs
# 587 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 588 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHPGround::
# 589 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar 0x8007, 3
# 590 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeAllIVs
# 591 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 592 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHPRock::
# 593 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar 0x8007, 4
# 594 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeAllIVs
# 595 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 596 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHPBug::
# 597 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar 0x8007, 5
# 598 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeAllIVs
# 599 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 600 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHPGhost::
# 601 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar 0x8007, 6
# 602 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeAllIVs
# 603 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 604 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHPSteel::
# 605 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar 0x8007, 7
# 606 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeAllIVs
# 607 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 608 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHPFire::
# 609 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar 0x8007, 8
# 610 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeAllIVs
# 611 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 612 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHPWater::
# 613 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar 0x8007, 9
# 614 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeAllIVs
# 615 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 616 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHPGrass::
# 617 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar 0x8007, 10
# 618 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeAllIVs
# 619 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 620 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHPElectric::
# 621 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar 0x8007, 11
# 622 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeAllIVs
# 623 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 624 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHPPsychic::
# 625 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar 0x8007, 12
# 626 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeAllIVs
# 627 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 628 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHPIce::
# 629 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar 0x8007, 13
# 630 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeAllIVs
# 631 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 632 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHPDragon::
# 633 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar 0x8007, 14
# 634 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeAllIVs
# 635 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 636 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeHPDark::
# 637 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar 0x8007, 15
# 638 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_ChangeAllIVs
# 639 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 640 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_ChangeAllIVs::
# 641 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special ChangeChosenMonHiddenPower
# 642 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto HyperTraining_EventScript_DoHyperTraining
# 643 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 644 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_DoHyperTraining::
# 645 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox HyperTraining_Text_StartHyperTraining, MSGBOX_AUTOCLOSE
# 646 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	fadescreen 1
# 647 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	playfanfare 0x173
# 648 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitfanfare
# 649 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	fadescreen 0
# 650 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox HyperTraining_Text_HyperTrainingMadeMonStronger, MSGBOX_YESNO
# 651 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, YES
# 652 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq FallarborTown_HyperTrainer
# 653 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
# 654 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 655 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 656 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_NotEnoughCaps::
# 657 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox HyperTraining_Text_NotEnoughCaps, MSGBOX_DEFAULT
# 658 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
# 659 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 660 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 661 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_EventScript_RebufferChosenMon::
# 662 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	copyvar VAR_0x8004, VAR_0x800A
# 663 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_HyperMainMenu
# 664 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 665 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_Text_ChoosePokemon:
# 666 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Which Pokémon needs some\n"
# 667 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Hyper Training?$"
# 668 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 669 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_Text_WantMeExplainIVs:
# 670 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Would you like me to explain IVs again?$"
# 671 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 672 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_Text_ExplainIVs:
# 673 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "IVs are a hidden part of your\n"
# 674 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Pokémon's stats that can only be\l"
# 675 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "changed with special training,\l"
# 676 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "or raised by giving them Vitamins.\p"
# 677 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "They can be any value between\n"
# 678 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "0 and 31, and affect things like\l"
# 679 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "the type of the move Hidden Power.\p"
# 680 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Higher IVs means higher stats, but\n"
# 681 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "higher stats aren't always better!\p"
# 682 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Example: If your Pokémon relies on\n"
# 683 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Special Attacks, a low Attack IV will\l"
# 684 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "reduce the damage it takes if it hits\l"
# 685 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "itself in confusion.$"
# 686 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 687 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_Text_LetsTakeALook:
# 688 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "OK! Let's take a look at your\n"
# 689 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1}'s IVs.$"
# 690 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 691 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_Text_WhichIVShouldChange:
# 692 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Which of {STR_VAR_1}'s IVs\n"
# 693 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "would you like to change?$"
# 694 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 695 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_ReportHP:
# 696 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1}'s HP IV is {STR_VAR_2}.\n"
# 697 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "What would you like to change it to?$"
# 698 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 699 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_ReportAtk:
# 700 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1}'s Attack IV is {STR_VAR_2}.\n"
# 701 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "What would you like to change it to?$"
# 702 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 703 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_ReportDef:
# 704 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1}'s Defense IV is {STR_VAR_2}.\n"
# 705 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "What would you like to change it to?$"
# 706 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 707 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_ReportSpeed:
# 708 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1}'s Speed IV is {STR_VAR_2}.\n"
# 709 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "What would you like to change it to?$"
# 710 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 711 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_ReportSpAtk:
# 712 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1}'s Sp. Atk IV is {STR_VAR_2}.\n"
# 713 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "What would you like to change it to?$"
# 714 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 715 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_ReportSpDef:
# 716 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{STR_VAR_1}'s Sp. Def IV is {STR_VAR_2}.\n"
# 717 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "What would you like to change it to?$"
# 718 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 719 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_Text_HyperTrainingMadeMonStronger:
# 720 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "The Hyper Training made {STR_VAR_1}\n"
# 721 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "stronger!\p"
# 722 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Would you like to train some more?$"
# 723 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 724 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_Text_ChangeAllIVs:
# 725 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I can change all of a Pokémon's IVs\n"
# 726 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "to give a new Hidden Power type.\p"
# 727 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Would you like to change {STR_VAR_1}'s\n"
# 728 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Hidden Power to one of these types?$"
# 729 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 730 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_Text_HowCanIHelp:
# 731 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "How can I help {STR_VAR_1} today?$"
# 732 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 733 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_Text_StartHyperTraining:
# 734 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Got it! Let's do some Hyper Training!$"
# 735 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 736 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_Text_NotEnoughCaps:
# 737 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "You don't have enough Bottle Caps.$"
# 738 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 739 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_Text_PayOneCap:
# 740 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{PLAYER} handed over one Bottle Cap.$"
# 741 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 742 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
HyperTraining_Text_PayThreeCaps:
# 743 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{PLAYER} handed over three Bottle Caps.$"
