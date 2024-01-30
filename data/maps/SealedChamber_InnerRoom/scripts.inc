# 1 "data/maps/SealedChamber_InnerRoom/scripts.pory"

# 2 "data/maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_MapScripts::
# 3 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Common_EventScript_RemoveOverworldAfterBattle
# 4 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	.byte 0
# 5 "data/maps/SealedChamber_InnerRoom/scripts.pory"

# 6 "data/maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_Regigigas::
# 7 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	lock
# 8 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	msgbox SealedChamber_InnerRoom_Text_RegigigasStatue, MSGBOX_DEFAULT
# 9 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	closemessage
# 10 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	braillemessage SealedChamber_InnerRoom_Braille_Regigigas
# 11 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	waitbuttonpress
# 12 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	closebraillemessage
# 13 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	setvar VAR_0x8004, SPECIES_REGICE
# 14 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	setvar VAR_0x8005, SPECIES_REGIROCK
# 15 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	setvar VAR_0x8006, SPECIES_REGISTEEL
# 16 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	setvar VAR_0x8007, 3
# 17 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	specialvar VAR_RESULT, CheckSpeciesInParty
# 18 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 19 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	goto_if_eq SealedChamber_InnerRoom_EventScript_RegigigasStatue
# 20 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	waitse
# 21 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	playmoncry SPECIES_REGIGIGAS, 2
# 22 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	delay 40
# 23 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	waitmoncry
# 24 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 25 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 26 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	setwildbattle SPECIES_REGIGIGAS, VAR_0x800A, ITEM_NORMAL_GEM
# 27 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 28 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 29 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	waitstate
# 30 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 31 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 32 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 33 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	goto_if_eq SealedChamber_InnerRoom_EventScript_DefeatedRegigigas
# 34 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 35 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	goto_if_eq SealedChamber_InnerRoom_EventScript_RanFromRegigigas
# 36 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 37 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	goto_if_eq SealedChamber_InnerRoom_EventScript_RanFromRegigigas
# 38 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	setflag FLAG_DEFEATED_REGIGIGAS
# 39 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	release
# 40 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 41 "data/maps/SealedChamber_InnerRoom/scripts.pory"

# 42 "data/maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_DefeatedRegigigas::
# 43 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	setflag FLAG_DEFEATED_REGIGIGAS
# 44 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 45 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 46 "data/maps/SealedChamber_InnerRoom/scripts.pory"

# 47 "data/maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_RanFromRegigigas::
# 48 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	setvar VAR_0x8004, SPECIES_REGIGIGAS
# 49 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 50 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 51 "data/maps/SealedChamber_InnerRoom/scripts.pory"

# 52 "data/maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_RegigigasStatue::
# 53 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	release
# 54 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 55 "data/maps/SealedChamber_InnerRoom/scripts.pory"

# 56 "data/maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleBackWall:: @ 82391F8
# 57 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 58 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	braillemessage SealedChamber_InnerRoom_Braille_FirstWailordLastRelicanth
# 59 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	waitbuttonpress
# 60 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	closebraillemessage
# 61 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	goto_if_set FLAG_REGI_DOORS_OPENED, SealedChamber_InnerRoom_EventScript_NoEffect
# 62 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	specialvar VAR_RESULT, CheckRelicanthWailord
# 63 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 64 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	goto_if_eq SealedChamber_InnerRoom_EventScript_NoEffect
# 65 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	fadeoutbgm 0
# 66 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	playse SE_TRUCK_MOVE
# 67 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	special DoSealedChamberShakingEffect1
# 68 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	waitstate
# 69 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	delay 40
# 70 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	special DoSealedChamberShakingEffect2
# 71 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	waitstate
# 72 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	playse SE_DOOR
# 73 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	delay 40
# 74 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	special DoSealedChamberShakingEffect2
# 75 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	waitstate
# 76 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	playse SE_DOOR
# 77 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	delay 40
# 78 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	special DoSealedChamberShakingEffect2
# 79 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	waitstate
# 80 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	playse SE_DOOR
# 81 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	delay 40
# 82 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	msgbox gText_DoorOpenedFarAway, MSGBOX_DEFAULT
# 83 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	closemessage
# 84 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	fadeinbgm 0
# 85 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	setflag FLAG_REGI_DOORS_OPENED
# 86 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 87 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 88 "data/maps/SealedChamber_InnerRoom/scripts.pory"

# 89 "data/maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_NoEffect:: @ 8239253
# 90 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 91 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 92 "data/maps/SealedChamber_InnerRoom/scripts.pory"

# 93 "data/maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleStoryPart1:: @ 8239255
# 94 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 95 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	braillemessage SealedChamber_InnerRoom_Braille_InThisCaveWeHaveLived
# 96 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	waitbuttonpress
# 97 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	closebraillemessage
# 98 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 99 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 100 "data/maps/SealedChamber_InnerRoom/scripts.pory"

# 101 "data/maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleStoryPart2:: @ 823925F
# 102 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 103 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	braillemessage SealedChamber_InnerRoom_Braille_WeOweAllToThePokemon
# 104 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	waitbuttonpress
# 105 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	closebraillemessage
# 106 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 107 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 108 "data/maps/SealedChamber_InnerRoom/scripts.pory"

# 109 "data/maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleStoryPart3:: @ 8239269
# 110 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 111 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	braillemessage SealedChamber_InnerRoom_Braille_ButWeSealedThePokemonAway
# 112 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	waitbuttonpress
# 113 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	closebraillemessage
# 114 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 115 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 116 "data/maps/SealedChamber_InnerRoom/scripts.pory"

# 117 "data/maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleStoryPart4:: @ 8239273
# 118 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 119 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	braillemessage SealedChamber_InnerRoom_Braille_WeFearedIt
# 120 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	waitbuttonpress
# 121 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	closebraillemessage
# 122 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 123 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 124 "data/maps/SealedChamber_InnerRoom/scripts.pory"

# 125 "data/maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleStoryPart5:: @ 823927D
# 126 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 127 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	braillemessage SealedChamber_InnerRoom_Braille_ThoseWithCourageHope
# 128 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	waitbuttonpress
# 129 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	closebraillemessage
# 130 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 131 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 132 "data/maps/SealedChamber_InnerRoom/scripts.pory"

# 133 "data/maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleStoryPart6:: @ 8239287
# 134 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 135 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	braillemessage SealedChamber_InnerRoom_Braille_OpenDoorEternalPokemonWaits
# 136 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	waitbuttonpress
# 137 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	closebraillemessage
# 138 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 139 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 140 "data/maps/SealedChamber_InnerRoom/scripts.pory"

# 141 "data/maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_Text_RegigigasStatue:
# 142 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	.string "It's a statue of a Pokémon.\n"
# 143 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	.string "It exudes tremendous power…\p"
# 144 "data/maps/SealedChamber_InnerRoom/scripts.pory"
	.string "There's something engraved on it…$"
