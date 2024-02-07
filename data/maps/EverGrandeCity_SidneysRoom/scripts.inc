# 1 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 2 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_MapScripts:: @ 8227F01
# 3 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_SidneysRoom_OnLoad
# 4 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
# 5 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_SidneysRoom_OnTransition
# 6 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_SidneysRoom_OnFrame
# 7 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.byte 0
# 8 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 9 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_OnTransition: @ 8227F16
# 10 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
# 11 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	setflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
# 12 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 13 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 14 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_OnLoad: @ 8227F1D
# 15 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom
# 16 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	compare VAR_ELITE_4_STATE, 1
# 17 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call_if_eq EverGrandeCity_SidneysRoom_EventScript_CloseDoor
# 18 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 19 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 20 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom:: @ 8227F32
# 21 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
# 22 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	return
# 23 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 24 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_CloseDoor:: @ 8227F38
# 25 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_CloseDoor
# 26 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	return
# 27 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 28 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_OnWarp: @ 8227F3E
# 29 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth
# 30 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.2byte 0
# 31 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 32 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth:: @ 8227F48
# 33 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 34 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 35 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 36 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_OnFrame: @ 8227F4D
# 37 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	map_script_2 VAR_ELITE_4_STATE, 0, EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor
# 38 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.2byte 0
# 39 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 40 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor:: @ 8227F57
# 41 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	lockall
# 42 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
# 43 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	setvar VAR_ELITE_4_STATE, 1
# 44 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	releaseall
# 45 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 46 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 47 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_Sidney:: @ 8227F64
# 48 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	lock
# 49 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	faceplayer
# 50 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	cleartrainerflag(TRAINER_CALVIN_E4)
# 51 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_SidneysRoom_EventScript_SidneyRematch
# 52 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech
# 53 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
# 54 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	msgbox EverGrandeCity_SidneysRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 55 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_SIDNEY, EverGrandeCity_SidneysRoom_Text_Defeat
# 56 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	goto EverGrandeCity_SidneysRoom_EventScript_Defeated
# 57 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 58 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 59 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_SidneyRematch::
# 60 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeechRematch
# 61 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_ELITE_FOUR, 0
# 62 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	msgbox EverGrandeCity_SidneysRoom_Text_IntroSpeechRematch, MSGBOX_DEFAULT
# 63 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	switch VAR_ELITE_4_MODE
# 64 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	case 0, EverGrandeCity_SidneysRoom_EventScript_SidneySingles
# 65 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	case 1, EverGrandeCity_SidneysRoom_EventScript_SidneySinglesLegends
# 66 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	case 2, EverGrandeCity_SidneysRoom_EventScript_SidneyDoubles
# 67 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	case 3, EverGrandeCity_SidneysRoom_EventScript_SidneyDoublesLegends
# 68 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 69 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_SidneySingles::
# 70 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_SIDNEY, EverGrandeCity_SidneysRoom_Text_Defeat
# 71 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	goto EverGrandeCity_SidneysRoom_EventScript_DefeatedRematch
# 72 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 73 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 74 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_SidneySinglesLegends::
# 75 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_SIDNEY_3, EverGrandeCity_SidneysRoom_Text_Defeat
# 76 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	goto EverGrandeCity_SidneysRoom_EventScript_DefeatedRematch
# 77 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 78 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 79 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_SidneyDoubles::
# 80 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_SIDNEY_2, EverGrandeCity_SidneysRoom_Text_Defeat
# 81 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	goto EverGrandeCity_SidneysRoom_EventScript_DefeatedRematch
# 82 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 83 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 84 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_SidneyDoublesLegends::
# 85 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_SIDNEY_4, EverGrandeCity_SidneysRoom_Text_Defeat
# 86 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	goto EverGrandeCity_SidneysRoom_EventScript_DefeatedRematch
# 87 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 88 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 89 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech:: @ 8227F8B
# 90 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 91 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	release
# 92 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 93 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 94 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeechRematch::
# 95 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeechRematch, MSGBOX_DEFAULT
# 96 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	release
# 97 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 98 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 99 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_Defeated:: @ 8227F95
# 100 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_SIDNEY
# 101 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 102 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 103 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	release
# 104 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 105 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 106 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_DefeatedRematch::
# 107 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_SIDNEY
# 108 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 109 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeechRematch, MSGBOX_DEFAULT
# 110 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	release
# 111 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 112 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 113 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_Text_IntroSpeech: @ 8227FA7
# 114 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Welcome, challenger!\n"
# 115 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "I'm Sidney of the Elite Four.\p"
# 116 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "I like that look you're giving me.\n"
# 117 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "I guess you'll give me a good match.\l"
# 118 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "That's good! Looking real good!\p"
# 119 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "All right! You and me, let's enjoy\n"
# 120 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "a battle that can only be staged\l"
# 121 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "here in the Pokémon League!$"
# 122 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 123 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_Text_Defeat: @ 82280A2
# 124 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Well, how do you like that? I lost!\n"
# 125 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Eh, it was fun, so it doesn't matter.$"
# 126 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 127 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_Text_PostBattleSpeech: @ 82280EC
# 128 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Well, listen to what this loser has\n"
# 129 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "to say.\p"
# 130 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "You've got what it takes to go far.\n"
# 131 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Now, go on to the next room and enjoy\l"
# 132 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "your next battle!$"
# 133 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 134 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_Text_IntroSpeechRematch:
# 135 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "I was waiting for you, Champion.\n"
# 136 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "No matter who wins, no hard feelings!\p"
# 137 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Let's get our most excellent\n"
# 138 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "battle underway!$"
# 139 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 140 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_Text_PostBattleSpeechRematch:
# 141 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Heh…\n"
# 142 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "I knew you really were the strongest…\p"
# 143 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Well, hurry up and get out of here!\n"
# 144 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Everybody else is still waiting\l"
# 145 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "for you!$"
