# 1 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 2 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_MapScripts:: @ 8228412
# 3 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_GlaciasRoom_OnFrame
# 4 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_GlaciasRoom_OnLoad
# 5 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_GlaciasRoom_OnWarp
# 6 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.byte 0
# 7 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 8 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_OnWarp: @ 8228422
# 9 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth
# 10 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.2byte 0
# 11 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 12 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth:: @ 822842C
# 13 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 14 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 15 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 16 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_OnFrame: @ 8228431
# 17 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script_2 VAR_ELITE_4_STATE, 2, EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor
# 18 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.2byte 0
# 19 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 20 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor:: @ 822843B
# 21 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	lockall
# 22 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
# 23 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	setvar VAR_ELITE_4_STATE, 3
# 24 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	releaseall
# 25 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 26 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 27 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_OnLoad: @ 8228448
# 28 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom
# 29 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	compare VAR_ELITE_4_STATE, 3
# 30 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call_if_eq EverGrandeCity_GlaciasRoom_EventScript_CloseDoor
# 31 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 32 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 33 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom:: @ 822845D
# 34 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
# 35 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	return
# 36 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 37 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_CloseDoor:: @ 8228463
# 38 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_CloseDoor
# 39 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	return
# 40 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 41 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_Glacia:: @ 8228469
# 42 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	lock
# 43 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	faceplayer
# 44 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_GlaciasRoom_EventScript_GlaciaRematch
# 45 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech
# 46 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
# 47 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	msgbox EverGrandeCity_GlaciasRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 48 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_GLACIA, EverGrandeCity_GlaciasRoom_Text_Defeat
# 49 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
# 50 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 51 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 52 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_GlaciaRematch::
# 53 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeechRematch
# 54 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_ELITE_FOUR, 0
# 55 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	msgbox EverGrandeCity_GlaciasRoom_Text_IntroSpeechRematch, MSGBOX_DEFAULT
# 56 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	switch VAR_ELITE_4_MODE
# 57 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	case 0, EverGrandeCity_GlaciasRoom_EventScript_GlaciaSingles
# 58 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	case 1, EverGrandeCity_GlaciasRoom_EventScript_GlaciaSinglesLegends
# 59 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	case 2, EverGrandeCity_GlaciasRoom_EventScript_GlaciaDoubles
# 60 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	case 3, EverGrandeCity_GlaciasRoom_EventScript_GlaciaDoublesLegends
# 61 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 62 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_GlaciaSingles::
# 63 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_GLACIA, EverGrandeCity_GlaciasRoom_Text_Defeat
# 64 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	goto EverGrandeCity_GlaciasRoom_EventScript_DefeatedRematch
# 65 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 66 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 67 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_GlaciaSinglesLegends::
# 68 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_GLACIA_3, EverGrandeCity_GlaciasRoom_Text_Defeat
# 69 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	goto EverGrandeCity_GlaciasRoom_EventScript_DefeatedRematch
# 70 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 71 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 72 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_GlaciaDoubles::
# 73 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_GLACIA_2, EverGrandeCity_GlaciasRoom_Text_Defeat
# 74 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	goto EverGrandeCity_GlaciasRoom_EventScript_DefeatedRematch
# 75 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 76 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 77 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_GlaciaDoublesLegends::
# 78 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_GLACIA_4, EverGrandeCity_GlaciasRoom_Text_Defeat
# 79 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	goto EverGrandeCity_GlaciasRoom_EventScript_DefeatedRematch
# 80 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 81 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 82 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech:: @ 8228490
# 83 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 84 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	release
# 85 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 86 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 87 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeechRematch::
# 88 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeechRematch, MSGBOX_DEFAULT
# 89 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	release
# 90 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 91 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 92 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_Defeated:: @ 822849A
# 93 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_GLACIA
# 94 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 95 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 96 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	release
# 97 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 98 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 99 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_DefeatedRematch::
# 100 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_GLACIA
# 101 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 102 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeechRematch, MSGBOX_DEFAULT
# 103 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	release
# 104 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 105 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 106 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_Text_IntroSpeech: @ 82284AC
# 107 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "Welcome, my name is Glacia\n"
# 108 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "of the Elite Four.\p"
# 109 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "I've traveled from afar to Hoenn\n"
# 110 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "so that I may hone my ice skills.\p"
# 111 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "But all I have seen are challenges by\n"
# 112 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "weak Trainers and their Pokémon.\p"
# 113 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "What about you?\p"
# 114 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "It would please me to no end if I could\n"
# 115 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "go all out against you!$"
# 116 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 117 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_Text_Defeat: @ 82285B4
# 118 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "You and your Pokémon…\n"
# 119 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "How hot your spirits burn!\p"
# 120 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "The all-consuming heat overwhelms.\p"
# 121 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "It's no surprise that my icy skills\n"
# 122 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "failed to harm you.$"
# 123 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 124 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech: @ 8228640
# 125 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "Advance to the next room.\p"
# 126 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "And there, confirm the truly fearsome\n"
# 127 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "side of the Pokémon League.$"
# 128 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 129 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_Text_IntroSpeechRematch:
# 130 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "I've been waiting for a Trainer\n"
# 131 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "with a burning-hot soul.\p"
# 132 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "How can you oppose Mega Evolution\n"
# 133 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "that can freeze everything?$"
# 134 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 135 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_Text_PostBattleSpeechRematch:
# 136 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "Hmmph…\n"
# 137 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "Do you intend to thaw my very heart?\p"
# 138 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "That actually wouldn't bother me.\p"
# 139 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "Anyway, continue onward!\n"
# 140 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "Drake is waiting for you as well.$"
