# 1 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 2 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_MapScripts:: @ 8228174
# 3 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_PhoebesRoom_OnLoad
# 4 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_PhoebesRoom_OnWarp
# 5 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_PhoebesRoom_OnFrame
# 6 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.byte 0
# 7 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 8 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_OnWarp: @ 8228184
# 9 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth
# 10 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.2byte 0
# 11 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 12 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth:: @ 822818E
# 13 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 14 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	end
# 15 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 16 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_OnFrame: @ 8228193
# 17 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	map_script_2 VAR_ELITE_4_STATE, 1, EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor
# 18 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.2byte 0
# 19 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 20 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor:: @ 822819D
# 21 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	lockall
# 22 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
# 23 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	setvar VAR_ELITE_4_STATE, 2
# 24 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	releaseall
# 25 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	end
# 26 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 27 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_OnLoad: @ 82281AA
# 28 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	call_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom
# 29 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	compare VAR_ELITE_4_STATE, 2
# 30 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	call_if_eq EverGrandeCity_PhoebesRoom_EventScript_CloseDoor
# 31 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	end
# 32 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 33 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom:: @ 82281BF
# 34 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
# 35 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	return
# 36 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 37 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_CloseDoor:: @ 82281C5
# 38 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_CloseDoor
# 39 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	return
# 40 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 41 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_Phoebe:: @ 82281CB
# 42 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	lock
# 43 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	faceplayer
# 44 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_PhoebesRoom_EventScript_PhoebeRematch
# 45 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech
# 46 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
# 47 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	msgbox EverGrandeCity_PhoebesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 48 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_PHOEBE, EverGrandeCity_PhoebesRoom_Text_Defeat
# 49 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated
# 50 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	end
# 51 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 52 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_PhoebeRematch::
# 53 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeechRematch
# 54 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_ELITE_FOUR, 0
# 55 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	msgbox EverGrandeCity_PhoebesRoom_Text_IntroSpeechRematch, MSGBOX_DEFAULT
# 56 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	switch VAR_ELITE_4_MODE
# 57 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	case 0, EverGrandeCity_PhoebesRoom_EventScript_PhoebeSingles
# 58 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	case 1, EverGrandeCity_PhoebesRoom_EventScript_PhoebeSinglesLegends
# 59 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	case 2, EverGrandeCity_PhoebesRoom_EventScript_PhoebeDoubles
# 60 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	case 3, EverGrandeCity_PhoebesRoom_EventScript_PhoebeDoublesLegends
# 61 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 62 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_PhoebeSingles::
# 63 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_PHOEBE, EverGrandeCity_PhoebesRoom_Text_Defeat
# 64 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	goto EverGrandeCity_PhoebesRoom_EventScript_DefeatedRematch
# 65 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	end
# 66 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 67 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_PhoebeSinglesLegends::
# 68 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_PHOEBE_3, EverGrandeCity_PhoebesRoom_Text_Defeat
# 69 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	goto EverGrandeCity_PhoebesRoom_EventScript_DefeatedRematch
# 70 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	end
# 71 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 72 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_PhoebeDoubles::
# 73 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_PHOEBE_2, EverGrandeCity_PhoebesRoom_Text_Defeat
# 74 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	goto EverGrandeCity_PhoebesRoom_EventScript_DefeatedRematch
# 75 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	end
# 76 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 77 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_PhoebeDoublesLegends::
# 78 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_PHOEBE_4, EverGrandeCity_PhoebesRoom_Text_Defeat
# 79 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	goto EverGrandeCity_PhoebesRoom_EventScript_DefeatedRematch
# 80 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	end
# 81 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 82 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech:: @ 82281F2
# 83 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 84 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	release
# 85 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	end
# 86 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 87 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeechRematch::
# 88 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeechRematch, MSGBOX_DEFAULT
# 89 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	release
# 90 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	end
# 91 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 92 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_Defeated:: @ 82281FC
# 93 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_PHOEBE
# 94 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 95 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 96 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	release
# 97 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	end
# 98 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 99 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_EventScript_DefeatedRematch::
# 100 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_PHOEBE
# 101 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 102 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeechRematch, MSGBOX_DEFAULT
# 103 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	release
# 104 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	end
# 105 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 106 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_Text_IntroSpeech: @ 822820E
# 107 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "Ahahaha!\p"
# 108 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "I'm Phoebe of the Elite Four.\n"
# 109 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "I did my training on Mt. Pyre.\p"
# 110 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "While I trained, I gained the ability\n"
# 111 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "to commune with Ghost-type Pokémon.\p"
# 112 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "Yes, the bond I developed with Pokémon\n"
# 113 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "is extremely tight.\p"
# 114 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "So, come on, just try and see if you can\n"
# 115 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "even inflict damage on my Pokémon!$"
# 116 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 117 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_Text_Defeat: @ 8228325
# 118 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "Oh, darn.\n"
# 119 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "I've gone and lost.$"
# 120 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 121 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech: @ 8228343
# 122 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "There's a definite bond between you\n"
# 123 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "and your Pokémon, too.\p"
# 124 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "I didn't recognize it, so it's only\n"
# 125 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "natural that I lost.\p"
# 126 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "Yup, I'd like to see how far your bond\n"
# 127 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "will carry you.\p"
# 128 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "Go ahead, move on to the next room.$"
# 129 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 130 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_Text_IntroSpeechRematch:
# 131 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "Ahaha! I've been waiting for you!\p"
# 132 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "I'm bringing a little something\n"
# 133 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "new to the table this time!\p"
# 134 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "Prepare yourself and bring it on!$"
# 135 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"

# 136 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
EverGrandeCity_PhoebesRoom_Text_PostBattleSpeechRematch:
# 137 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "Hmmp, what a shame.\n"
# 138 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "I lost again, huh?\p"
# 139 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "But on the bright side…\n"
# 140 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "We fought together, so the bonds\l"
# 141 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "between my Pokémon and me got even\l" 
# 142 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "deeper!\p"
# 143 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "I look forward to being able to\n"
# 144 "data/maps/EverGrandeCity_PhoebesRoom/scripts.pory"
	.string "battle you again sometime!$"
