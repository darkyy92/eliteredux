# 1 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 2 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
.set LOCALID_COZMO, 1
# 3 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 4 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_MapScripts:: @ 8200F12
# 5 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.byte 0
# 6 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 7 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_ProfCozmo:: @ 8200F13
# 8 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	lockall
# 9 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	faceplayer
# 10 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_HANDED_OVER_METEORITE, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
# 11 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	checkitem ITEM_METEORITE, 1
# 12 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	compare VAR_RESULT, TRUE
# 13 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_eq FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
# 14 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
# 15 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
# 16 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 17 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 18 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite:: @ 8200F38
# 19 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
# 20 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
# 21 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	compare VAR_RESULT, NO
# 22 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_eq FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
# 23 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
# 24 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	givecustommon SPECIES_PIKACHU_PH_D, 45, ITEM_LIGHT_BALL, ITEM_PREMIER_BALL, NATURE_NAIVE, 2, 0, 180, 0, 252, 76, 0, 0, 0, 0, 0, 0, 0, MOVE_FAKE_OUT, MOVE_ZIPPY_ZAP, MOVE_SPLISHY_SPLASH, MOVE_EXTREME_SPEED, FALSE
# 25 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	playfanfare(MUS_OBTAIN_ITEM)
# 26 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	message FallarborTown_CozmosHouse_Text_PlayerGotAPikachu
# 27 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	waitfanfare
# 28 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	setvar VAR_0x8004, ITEM_METEORITE
# 29 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 30 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_HANDED_OVER_METEORITE
# 31 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
# 32 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
# 33 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 34 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 35 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_NoticeMeteorite:: @ 8200F8B
# 36 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
# 37 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
# 38 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	return
# 39 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 40 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_AskForMeteorite:: @ 8200F9C
# 41 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
# 42 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	return
# 43 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 44 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite:: @ 8200FA5
# 45 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_TEMP_2
# 46 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
# 47 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
# 48 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 49 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 50 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_GaveMeteorite:: @ 8200FB2
# 51 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	checkPartyHasSpecies SPECIES_DEOXYS
# 52 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	compare VAR_RESULT, TRUE
# 53 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_eq FallarborTown_CozmosHouse_EventScript_ExplainDeoxysFormChange
# 54 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
# 55 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
# 56 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 57 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 58 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_ExplainDeoxysFormChange::
# 59 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_SHOWN_DEOXYS_TO_COSMO, FallarborTown_CozmosHouse_EventScript_ShouldChangeDeoxysForm
# 60 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_SHOWN_DEOXYS_TO_COSMO
# 61 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_MeteorAffectsDeoxys, MSGBOX_DEFAULT
# 62 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	delay 40
# 63 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	playse SE_PIN
# 64 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	applymovement LOCALID_COZMO, Common_Movement_ExclamationMark
# 65 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	waitmovement 0
# 66 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	applymovement LOCALID_COZMO, Common_Movement_Delay48
# 67 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	waitmovement 0
# 68 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_ShouldChangeDeoxysForm::
# 69 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_YouHaveDeoxys, MSGBOX_YESNO
# 70 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	compare VAR_RESULT, YES
# 71 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_eq FallarborTown_CozmosHouse_EventScript_ChangeDeoxysForm
# 72 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
# 73 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 74 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 75 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_ChangeDeoxysForm::
# 76 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    msgbox FallarborTown_CozmosHouse_Text_WhichDeoxys, MSGBOX_DEFAULT
# 77 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    special ChoosePartyMon
# 78 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	waitstate
# 79 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    compare VAR_0x8004, 255
# 80 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_eq FallarborTown_CozmosHouse_EventScript_Exit
# 81 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	special IsSelectedMonEgg
# 82 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	compare VAR_RESULT, TRUE
# 83 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    goto_if_eq FallarborTown_CozmosHouse_EventScript_MonIsEgg
# 84 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    isChosenMonSpecies SPECIES_DEOXYS
# 85 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    compare VAR_RESULT, FALSE
# 86 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    goto_if_eq FallarborTown_CozmosHouse_EventScript_MonIsNotDeoxys
# 87 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	compare VAR_0x8004, PARTY_SIZE
# 88 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_ge FallarborTown_CozmosHouse_EventScript_Exit
# 89 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 90 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    copyvar VAR_0x8006, VAR_RESULT
# 91 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	lockall
# 92 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	faceplayer
# 93 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_DeoxysMultichoice::
# 94 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    bufferpartymonnick 0, VAR_0x8004
# 95 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    message FallarborTown_CozmosHouse_Text_WhichForm
# 96 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    waitmessage
# 97 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	multichoice 0, 0, MULTI_DEOXYS_FORMES, 0
# 98 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	switch VAR_RESULT
# 99 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	case 0, FallarborTown_CozmosHouse_DeoxysNormal
# 100 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    case 1, FallarborTown_CozmosHouse_DeoxysAttack
# 101 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	case 2, FallarborTown_CozmosHouse_DeoxysDefense
# 102 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    case 3, FallarborTown_CozmosHouse_DeoxysSpeed
# 103 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	case 4, FallarborTown_CozmosHouse_EventScript_Exit
# 104 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    case MULTI_B_PRESSED, FallarborTown_CozmosHouse_EventScript_Exit
# 105 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    end
# 106 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 107 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_Exit::
# 108 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
# 109 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 110 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 111 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_MonIsEgg::
# 112 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_EggIsNotReacting, MSGBOX_DEFAULT
# 113 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
# 114 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 115 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 116 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_MonIsNotDeoxys::
# 117 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_PokemonIsNotReacting, MSGBOX_DEFAULT
# 118 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
# 119 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 120 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 121 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_DeoxysNormal::
# 122 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    setvar VAR_0x8005, SPECIES_DEOXYS
# 123 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    compare VAR_0x8006, VAR_0x8005
# 124 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    goto_if_eq FallarborTown_CozmosHouse_EventScript_DeoxysAlreadyThatForme
# 125 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	special ChangeMonSpecies
# 126 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    msgbox FallarborTown_CozmosHouse_Text_DeoxysBalancedStats, MSGBOX_DEFAULT
# 127 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
# 128 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 129 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 130 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_DeoxysAttack::
# 131 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    setvar VAR_0x8005, SPECIES_DEOXYS_ATTACK
# 132 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    compare VAR_0x8006, VAR_0x8005
# 133 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    goto_if_eq FallarborTown_CozmosHouse_EventScript_DeoxysAlreadyThatForme
# 134 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	special ChangeMonSpecies
# 135 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    msgbox FallarborTown_CozmosHouse_Text_DeoxysAttackingStats, MSGBOX_DEFAULT
# 136 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
# 137 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 138 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 139 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_DeoxysDefense::
# 140 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    setvar VAR_0x8005, SPECIES_DEOXYS_DEFENSE
# 141 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    compare VAR_0x8006, VAR_0x8005
# 142 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    goto_if_eq FallarborTown_CozmosHouse_EventScript_DeoxysAlreadyThatForme
# 143 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	special ChangeMonSpecies
# 144 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    msgbox FallarborTown_CozmosHouse_Text_DeoxysDefendingStats, MSGBOX_DEFAULT
# 145 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
# 146 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 147 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 148 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_DeoxysSpeed::
# 149 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    setvar VAR_0x8005, SPECIES_DEOXYS_SPEED
# 150 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    compare VAR_0x8006, VAR_0x8005
# 151 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    goto_if_eq FallarborTown_CozmosHouse_EventScript_DeoxysAlreadyThatForme
# 152 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	special ChangeMonSpecies
# 153 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
    msgbox FallarborTown_CozmosHouse_Text_DeoxysSanicStats, MSGBOX_DEFAULT
# 154 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
# 155 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 156 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 157 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_DeoxysAlreadyThatForme::
# 158 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_DeoxysAlreadyThatForme, MSGBOX_DEFAULT
# 159 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
# 160 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 161 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 162 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_CozmosWife:: @ 8200FBC
# 163 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	lockall
# 164 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	faceplayer
# 165 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_HANDED_OVER_METEORITE, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
# 166 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
# 167 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
# 168 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
# 169 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 170 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 171 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_CozmoIsSad:: @ 8200FDA
# 172 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_unset FLAG_RECEIVED_GALLADITE, FallarborTown_CozmosHouse_EventScript_GiveGalladite
# 173 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
# 174 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
# 175 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 176 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 177 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_GiveGalladite::
# 178 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_PleaseTakeThis, MSGBOX_DEFAULT
# 179 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	givecustommon SPECIES_GALLADE, 40, ITEM_ASSAULT_VEST, ITEM_POKE_BALL, NATURE_JOLLY, 2, 0, 252, 4, 252, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_SACRED_SWORD, MOVE_PSYCHO_CUT, MOVE_LEAF_BLADE, MOVE_EXCALIBUR, TRUE
# 180 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 181 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	message FallarborTown_CozmosHouse_Text_Got_Gallade
# 182 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	waitfanfare
# 183 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_RECEIVED_GALLADITE
# 184 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
# 185 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 186 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 187 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_CozmoIsHappy:: @ 8200FE4
# 188 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_unset FLAG_RECEIVED_GALLADITE, FallarborTown_CozmosHouse_EventScript_GiveGalladite
# 189 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
# 190 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
# 191 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 192 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 193 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow: @ 8200FEE
# 194 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Prof. Cozmo: Oh…\n"
# 195 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I never should have let myself be\l"
# 196 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "conned into telling Team Magma where\l"
# 197 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "you can find Meteorites…\p"
# 198 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "That Meteorite from Meteor Falls…\n"
# 199 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "It's never going to be mine now…$"
# 200 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 201 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt: @ 82010A2
# 202 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Oh!\n"
# 203 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Hah?\p"
# 204 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "That item…\p"
# 205 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Could it be?\p"
# 206 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Is it the Meteorite that Team Magma\n"
# 207 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "took from Meteor Falls?\p"
# 208 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Please, may I have it?\p"
# 209 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I'm not asking for it for free.\n"
# 210 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "How about in exchange for a Pokémon?$"
# 211 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 212 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_PleaseUseThisTM: @ 8201159
# 213 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Prof. Cozmo: Please take this$"
# 214 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 215 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch: @ 82011A5
# 216 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Prof. Cozmo: Oh, I can't believe it.\n"
# 217 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "This is really, really great!\p"
# 218 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "This is really going to help my research!$"
# 219 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 220 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_CrushedWithDisappointment: @ 8201212
# 221 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Prof. Cozmo: Oh, but…\n"
# 222 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I'm crushed with disappointment…$"
# 223 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 224 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_MayIHaveMeteorite: @ 8201249
# 225 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Prof. Cozmo: Please, may I have that\n"
# 226 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Meteorite?\p"
# 227 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I'm not asking for it for free.\n"
# 228 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "How about a special Pikachu?$"
# 229 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 230 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls: @ 82012BC
# 231 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Prof. Cozmo went off to Meteor Falls\n"
# 232 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "on Route 114 with some people from\l"
# 233 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Team Magma.$"
# 234 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 235 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_FeelSorryForCozmo: @ 8201310
# 236 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Poor Prof. Cozmo…\n"
# 237 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "He's so depressed… I feel sorry for him.$"
# 238 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 239 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_CozmoIsSoHappy: @ 820134B
# 240 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Look at Prof. Cozmo…\n"
# 241 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "He's so happy! I think it's cute.$"
# 242 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 243 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_PleaseTakeThis:
# 244 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Thank you for saving Prof. Cozmo!\p"
# 245 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Please take this {COLOR BLUE}Gallade{COLOR DARK_GRAY}\n"
# 246 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "as a sign of our gratitude.$"
# 247 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 248 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_MeteorAffectsDeoxys:
# 249 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Ah! It's you! I've made a discovery!\p"
# 250 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "It seems the Meteorite has something\n"
# 251 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "to do with a Pokémon called Deoxys.\p"
# 252 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "If exposed to the Meteorite, it'll\n"
# 253 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "change shape!$"
# 254 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 255 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_YouHaveDeoxys::
# 256 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Oh! Is that a Deoxys with you?\p"
# 257 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Would you like to bring it closer to\n"
# 258 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "the Meteorite?$"
# 259 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 260 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_WhichDeoxys::
# 261 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Which Deoxys would you like to bring\n"
# 262 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "closer to the Meteorite?$"
# 263 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 264 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_EggIsNotReacting:
# 265 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "The Egg is not reacting to the\n"
# 266 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Meteorite.$"
# 267 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 268 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_PokemonIsNotReacting:
# 269 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "The Pokémon is not reacting to the\n"
# 270 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Meteorite.$"
# 271 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 272 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_WhichForm:
# 273 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "{STR_VAR_1} is reacting to the\n"
# 274 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Meteorite!\p"
# 275 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Which Forme should it change into?$"
# 276 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 277 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_DeoxysBalancedStats:
# 278 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "{STR_VAR_1} has changed to have\n"
# 279 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "balanced stats!$"
# 280 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 281 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_DeoxysAttackingStats:
# 282 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "{STR_VAR_1} has changed to have\n"
# 283 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "superior stats for attacking!$"
# 284 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 285 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_DeoxysDefendingStats:
# 286 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "{STR_VAR_1} has changed to have\n"
# 287 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "superior stats for defending!$"
# 288 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 289 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_DeoxysSanicStats:
# 290 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "{STR_VAR_1} has changed to have\n"
# 291 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "increased Speed!$"
# 292 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 293 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_DeoxysAlreadyThatForme:
# 294 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "{STR_VAR_1} is already in that Forme!$"

FallarborTown_CozmosHouse_Text_PlayerGotAPikachu::
# 297 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Pikachu{COLOR DARK_GRAY} as a gift!$"

FallarborTown_CozmosHouse_Text_Got_Gallade::
# 301 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Gallade{COLOR DARK_GRAY} as a gift!$"
