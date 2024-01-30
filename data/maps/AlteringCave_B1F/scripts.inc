# 1 "data/maps/AlteringCave_B1F/scripts.pory"

# 2 "data/maps/AlteringCave_B1F/scripts.pory"
.set LOCALID_LEAF, 11
# 3 "data/maps/AlteringCave_B1F/scripts.pory"

# 4 "data/maps/AlteringCave_B1F/scripts.pory"
AlteringCave_B1F_MapScripts::
# 5 "data/maps/AlteringCave_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Common_EventScript_RemoveOverworldAfterBattle
# 6 "data/maps/AlteringCave_B1F/scripts.pory"
	.byte 0
# 7 "data/maps/AlteringCave_B1F/scripts.pory"

# 8 "data/maps/AlteringCave_B1F/scripts.pory"
AlteringCave_B1F_EventScript_Mewtwo::
# 9 "data/maps/AlteringCave_B1F/scripts.pory"
	lock
# 10 "data/maps/AlteringCave_B1F/scripts.pory"
	faceplayer
# 11 "data/maps/AlteringCave_B1F/scripts.pory"
	waitse
# 12 "data/maps/AlteringCave_B1F/scripts.pory"
	playmoncry SPECIES_MEWTWO, 2
# 13 "data/maps/AlteringCave_B1F/scripts.pory"
	delay 40
# 14 "data/maps/AlteringCave_B1F/scripts.pory"
	waitmoncry
# 15 "data/maps/AlteringCave_B1F/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 16 "data/maps/AlteringCave_B1F/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 17 "data/maps/AlteringCave_B1F/scripts.pory"
	setwildbattle SPECIES_MEWTWO, VAR_0x800A, ITEM_PSYCHIC_GEM
# 18 "data/maps/AlteringCave_B1F/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 19 "data/maps/AlteringCave_B1F/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 20 "data/maps/AlteringCave_B1F/scripts.pory"
	waitstate
# 21 "data/maps/AlteringCave_B1F/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 22 "data/maps/AlteringCave_B1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 23 "data/maps/AlteringCave_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 24 "data/maps/AlteringCave_B1F/scripts.pory"
	goto_if_eq AlteringCave_B1F_EventScript_DefeatedMewtwo
# 25 "data/maps/AlteringCave_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 26 "data/maps/AlteringCave_B1F/scripts.pory"
	goto_if_eq AlteringCave_B1F_EventScript_RanFromMewtwo
# 27 "data/maps/AlteringCave_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 28 "data/maps/AlteringCave_B1F/scripts.pory"
	goto_if_eq AlteringCave_B1F_EventScript_RanFromMewtwo
# 29 "data/maps/AlteringCave_B1F/scripts.pory"
	setflag FLAG_DEFEATED_MEWTWO
# 30 "data/maps/AlteringCave_B1F/scripts.pory"
	release
# 31 "data/maps/AlteringCave_B1F/scripts.pory"
	end
# 32 "data/maps/AlteringCave_B1F/scripts.pory"

# 33 "data/maps/AlteringCave_B1F/scripts.pory"
AlteringCave_B1F_EventScript_DefeatedMewtwo::
# 34 "data/maps/AlteringCave_B1F/scripts.pory"
	setflag FLAG_DEFEATED_MEWTWO
# 35 "data/maps/AlteringCave_B1F/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 36 "data/maps/AlteringCave_B1F/scripts.pory"
	end
# 37 "data/maps/AlteringCave_B1F/scripts.pory"

# 38 "data/maps/AlteringCave_B1F/scripts.pory"
AlteringCave_B1F_EventScript_RanFromMewtwo::
# 39 "data/maps/AlteringCave_B1F/scripts.pory"
	setvar VAR_0x8004, SPECIES_MEWTWO
# 40 "data/maps/AlteringCave_B1F/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 41 "data/maps/AlteringCave_B1F/scripts.pory"
	end
# 42 "data/maps/AlteringCave_B1F/scripts.pory"

# 43 "data/maps/AlteringCave_B1F/scripts.pory"
AlteringCave_B1F_EventScript_Leaf::
# 44 "data/maps/AlteringCave_B1F/scripts.pory"
	lockall
# 45 "data/maps/AlteringCave_B1F/scripts.pory"
	playse SE_PIN
# 46 "data/maps/AlteringCave_B1F/scripts.pory"
	applymovement LOCALID_LEAF, Common_Movement_ExclamationMark
# 47 "data/maps/AlteringCave_B1F/scripts.pory"
	waitmovement 0
# 48 "data/maps/AlteringCave_B1F/scripts.pory"
	applymovement LOCALID_LEAF, Common_Movement_WalkInPlaceFastestDown
# 49 "data/maps/AlteringCave_B1F/scripts.pory"
	waitmovement 0
# 50 "data/maps/AlteringCave_B1F/scripts.pory"
	delay 40
# 51 "data/maps/AlteringCave_B1F/scripts.pory"
	msgbox AlteringCave_Text_LeafPreBattle, MSGBOX_DEFAULT
# 52 "data/maps/AlteringCave_B1F/scripts.pory"
	closemessage
# 53 "data/maps/AlteringCave_B1F/scripts.pory"
	applymovement LOCALID_LEAF, AlteringCave_Movement_Leaf
# 54 "data/maps/AlteringCave_B1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, AlteringCave_Movement_Player
# 55 "data/maps/AlteringCave_B1F/scripts.pory"
	waitmovement 0
# 56 "data/maps/AlteringCave_B1F/scripts.pory"
	trainerbattle_no_intro TRAINER_LEAF_ALTERING_CAVE, AlteringCave_Text_LeafDefeated
# 57 "data/maps/AlteringCave_B1F/scripts.pory"
	setvar VAR_LEAF_STATE, 1
# 58 "data/maps/AlteringCave_B1F/scripts.pory"
	msgbox AlteringCave_Text_LeafGift, MSGBOX_DEFAULT
# 59 "data/maps/AlteringCave_B1F/scripts.pory"
	giveitem ITEM_BOTTLE_CAP, 30
# 60 "data/maps/AlteringCave_B1F/scripts.pory"
	msgbox AlteringCave_Text_LeafExit, MSGBOX_DEFAULT
# 61 "data/maps/AlteringCave_B1F/scripts.pory"
	closemessage
# 62 "data/maps/AlteringCave_B1F/scripts.pory"
	applymovement  OBJ_EVENT_ID_PLAYER, AlteringCave_Movement_GiveWay
# 63 "data/maps/AlteringCave_B1F/scripts.pory"
	applymovement  LOCALID_LEAF, AlteringCave_Movement_LeafLeaves
# 64 "data/maps/AlteringCave_B1F/scripts.pory"
	waitmovement 0
# 65 "data/maps/AlteringCave_B1F/scripts.pory"
	removeobject LOCALID_LEAF
# 66 "data/maps/AlteringCave_B1F/scripts.pory"
	releaseall
# 67 "data/maps/AlteringCave_B1F/scripts.pory"
	end
# 68 "data/maps/AlteringCave_B1F/scripts.pory"

# 69 "data/maps/AlteringCave_B1F/scripts.pory"
AlteringCave_Text_LeafPreBattle:
# 70 "data/maps/AlteringCave_B1F/scripts.pory"
	.string "???: Are you here looking for\n"
# 71 "data/maps/AlteringCave_B1F/scripts.pory"
	.string "something?\p"
# 72 "data/maps/AlteringCave_B1F/scripts.pory"
	.string "Maybe a certain Legendary Pokémon?\p"
# 73 "data/maps/AlteringCave_B1F/scripts.pory"
	.string "Well, you're in the right place.\n"
# 74 "data/maps/AlteringCave_B1F/scripts.pory"
	.string "Mewtwo's just ahead!\p"
# 75 "data/maps/AlteringCave_B1F/scripts.pory"
	.string "Oh, I'm Green, by the way!\n"
# 76 "data/maps/AlteringCave_B1F/scripts.pory"
	.string "Nice to meet you!\p"
# 77 "data/maps/AlteringCave_B1F/scripts.pory"
	.string "But if you want to meet Mewtwo,\n"
# 78 "data/maps/AlteringCave_B1F/scripts.pory"
	.string "you'll have to get past me first!$"
# 79 "data/maps/AlteringCave_B1F/scripts.pory"

# 80 "data/maps/AlteringCave_B1F/scripts.pory"
AlteringCave_Text_LeafDefeated:
# 81 "data/maps/AlteringCave_B1F/scripts.pory"
	.string "Wow, you're strong!$"
# 82 "data/maps/AlteringCave_B1F/scripts.pory"

# 83 "data/maps/AlteringCave_B1F/scripts.pory"
AlteringCave_Text_LeafGift:
# 84 "data/maps/AlteringCave_B1F/scripts.pory"
	.string "Green: Well, I guess that's that!\p"
# 85 "data/maps/AlteringCave_B1F/scripts.pory"
	.string "Here, take these.$"
# 86 "data/maps/AlteringCave_B1F/scripts.pory"

# 87 "data/maps/AlteringCave_B1F/scripts.pory"
AlteringCave_Text_LeafExit:
# 88 "data/maps/AlteringCave_B1F/scripts.pory"
	.string "This is goodbye for now, {PLAYER}.\n"
# 89 "data/maps/AlteringCave_B1F/scripts.pory"
	.string "But I'm sure we'll meet again!$"
# 90 "data/maps/AlteringCave_B1F/scripts.pory"

# 91 "data/maps/AlteringCave_B1F/scripts.pory"
AlteringCave_Movement_Leaf:
# 92 "data/maps/AlteringCave_B1F/scripts.pory"
	walk_down
# 93 "data/maps/AlteringCave_B1F/scripts.pory"
	step_end
# 94 "data/maps/AlteringCave_B1F/scripts.pory"

# 95 "data/maps/AlteringCave_B1F/scripts.pory"
AlteringCave_Movement_Player:
# 96 "data/maps/AlteringCave_B1F/scripts.pory"
	walk_up
# 97 "data/maps/AlteringCave_B1F/scripts.pory"
	step_end
# 98 "data/maps/AlteringCave_B1F/scripts.pory"

# 99 "data/maps/AlteringCave_B1F/scripts.pory"
AlteringCave_Movement_GiveWay:
# 100 "data/maps/AlteringCave_B1F/scripts.pory"
	walk_left
# 101 "data/maps/AlteringCave_B1F/scripts.pory"
	walk_in_place_fast_right
# 102 "data/maps/AlteringCave_B1F/scripts.pory"
	step_end
# 103 "data/maps/AlteringCave_B1F/scripts.pory"

# 104 "data/maps/AlteringCave_B1F/scripts.pory"
AlteringCave_Movement_LeafLeaves:
# 105 "data/maps/AlteringCave_B1F/scripts.pory"
	walk_down
# 106 "data/maps/AlteringCave_B1F/scripts.pory"
	walk_down
# 107 "data/maps/AlteringCave_B1F/scripts.pory"
	walk_down
# 108 "data/maps/AlteringCave_B1F/scripts.pory"
	walk_right
# 109 "data/maps/AlteringCave_B1F/scripts.pory"
	walk_right
# 110 "data/maps/AlteringCave_B1F/scripts.pory"
	walk_right
# 111 "data/maps/AlteringCave_B1F/scripts.pory"
	walk_right
# 112 "data/maps/AlteringCave_B1F/scripts.pory"
	walk_right
# 113 "data/maps/AlteringCave_B1F/scripts.pory"
	walk_right
# 114 "data/maps/AlteringCave_B1F/scripts.pory"
	walk_right
# 115 "data/maps/AlteringCave_B1F/scripts.pory"
	step_end
