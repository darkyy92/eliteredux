# 1 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 2 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_MapScripts:: @ 822869C
# 3 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
# 4 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
# 5 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
# 6 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.byte 0
# 7 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 8 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
@ Unused, Drake uses Sidneys identical OnWarp for some reason
# 9 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_OnWarp: @ 82286AC
# 10 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
# 11 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.2byte 0
# 12 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 13 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth:: @ 82286B6
# 14 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 15 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 16 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 17 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_OnFrame: @ 82286BB
# 18 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
# 19 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.2byte 0
# 20 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 21 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor:: @ 82286C5
# 22 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	lockall
# 23 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
# 24 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	setvar VAR_ELITE_4_STATE, 4
# 25 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	releaseall
# 26 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 27 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 28 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_OnLoad: @ 82286D2
# 29 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
# 30 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	compare VAR_ELITE_4_STATE, 4
# 31 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call_if_eq EverGrandeCity_DrakesRoom_EventScript_CloseDoor
# 32 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 33 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 34 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom:: @ 82286E7
# 35 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
# 36 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	return
# 37 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 38 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_CloseDoor:: @ 82286ED
# 39 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_CloseDoor
# 40 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	return
# 41 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 42 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_Drake:: @ 82286F3
# 43 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	lock
# 44 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	faceplayer
# 45 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_DrakesRoom_EventScript_DrakeRematch
# 46 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
# 47 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
# 48 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 49 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
# 50 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
# 51 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 52 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 53 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_DrakeRematch::
# 54 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeechRematch
# 55 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_ELITE_FOUR, 0
# 56 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeechRematch, MSGBOX_DEFAULT
# 57 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	switch VAR_ELITE_4_MODE
# 58 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	case 0, EverGrandeCity_DrakesRoom_EventScript_DrakeSingles
# 59 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	case 1, EverGrandeCity_DrakesRoom_EventScript_DrakeSinglesLegends
# 60 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	case 2, EverGrandeCity_DrakesRoom_EventScript_DrakeDoubles
# 61 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	case 3, EverGrandeCity_DrakesRoom_EventScript_DrakeDoublesLegends
# 62 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 63 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 64 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_DrakeSingles::
# 65 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
# 66 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	goto EverGrandeCity_DrakesRoom_EventScript_DefeatedRematch
# 67 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 68 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 69 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_DrakeSinglesLegends::
# 70 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_DRAKE_3, EverGrandeCity_DrakesRoom_Text_Defeat
# 71 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	goto EverGrandeCity_DrakesRoom_EventScript_DefeatedRematch
# 72 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 73 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 74 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_DrakeDoubles::
# 75 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_DRAKE_2, EverGrandeCity_DrakesRoom_Text_Defeat
# 76 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	goto EverGrandeCity_DrakesRoom_EventScript_DefeatedRematch
# 77 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 78 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 79 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_DrakeDoublesLegends::
# 80 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_DRAKE_4, EverGrandeCity_DrakesRoom_Text_Defeat
# 81 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	goto EverGrandeCity_DrakesRoom_EventScript_DefeatedRematch
# 82 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 83 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 84 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech:: @ 822871A
# 85 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 86 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	release
# 87 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 88 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 89 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeechRematch::
# 90 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeechRematch, MSGBOX_DEFAULT
# 91 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	release
# 92 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 93 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 94 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_Defeated:: @ 8228724
# 95 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
# 96 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	special Script_TryGainNewFanFromCounter
# 97 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
# 98 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 99 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 100 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	release
# 101 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 102 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 103 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_DefeatedRematch::
# 104 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
# 105 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	special Script_TryGainNewFanFromCounter
# 106 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
# 107 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 108 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeechRematch, MSGBOX_DEFAULT
# 109 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	release
# 110 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 111 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 112 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_Text_IntroSpeech: @ 822873E
# 113 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "I am the last of the Pokémon League\n"
# 114 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Elite Four, Drake the Dragon master!\p"
# 115 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "In their natural state, Pokémon are\n"
# 116 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "wild living things. They are free.\p"
# 117 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "At times, they hinder us.\n"
# 118 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "At times, they help us.\p"
# 119 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "For us to battle with Pokémon as\n"
# 120 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "partners, do you know what it takes?\p"
# 121 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Do you know what is needed?\p"
# 122 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "If you don't, then you will never\n"
# 123 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "prevail over me!$"
# 124 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 125 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_Text_Defeat: @ 8228895
# 126 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Superb, it should be said.$"
# 127 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 128 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_Text_PostBattleSpeech: @ 82288B0
# 129 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "You deserve every credit for coming\n"
# 130 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "this far as a Trainer of Pokémon.\p"
# 131 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "You do seem to know what is needed.\p"
# 132 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Yes, what a Trainer needs is a\n"
# 133 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "virtuous heart.\p"
# 134 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Pokémon touch the good hearts of\n"
# 135 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Trainers and learn good from wrong.\p"
# 136 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "They touch the good hearts of\n"
# 137 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Trainers and grow strong.\p"
# 138 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Go! Go onwards!\n"
# 139 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "The Champion is waiting!$"
# 140 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 141 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_Text_IntroSpeechRematch:
# 142 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Oh, I've been waitin' for you!\p"
# 143 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "My Pokémon and I are going to\n"
# 144 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "show you everything we've got!\p"
# 145 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Well then, you had better\n"
# 146 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "get ready to try and stop me!$"
# 147 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 148 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_Text_PostBattleSpeechRematch:
# 149 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "I got a glimpse inside your heart!\n"
# 150 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "There's nothing for me to say to you!\p"
# 151 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Go forth, Trainer!\p"
# 152 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Go on to your next challenge\n"
# 153 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "with your head held high!$"
