# 1 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
.set LOCALID_LUCY, 8
# 4 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 5 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_MapScripts:: @ 81FFAFA
# 6 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
# 7 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 8 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.byte 0
# 9 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 10 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_OnTransition: @ 81FFB05
# 11 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
# 12 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_UpdateBrineyLocation
# 13 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	end
# 14 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 15 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_Nurse:: @ 81FFB0E
# 16 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 17 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 18 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 19 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 20 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	release
# 21 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	end
# 22 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 23 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_Youngster:: @ 81FFB1C
# 24 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate, MSGBOX_NPC
# 25 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	end
# 26 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 27 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_Woman:: @ 81FFB25
# 28 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether, MSGBOX_NPC
# 29 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	end
# 30 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 31 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_Gentleman:: @ 81FFB2E
# 32 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo, MSGBOX_NPC
# 33 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	end
# 34 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 35 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_MoomooMilk::
# 36 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	lock
# 37 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 38 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	showmoneybox 0, 0, 0
# 39 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_1F_Text_WantToBuyMoomooMilk, MSGBOX_DEFAULT
# 40 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	multichoice 16, 0, MULTI_MOOMOO_MILK, 0
# 41 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	switch VAR_RESULT
# 42 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	case 0, LavaridgeTown_PokemonCenter_1F_EventScript_Buy1MoomooMilk
# 43 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	case 1, LavaridgeTown_PokemonCenter_1F_EventScript_Buy12MoomooMilk
# 44 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	case 2, LavaridgeTown_PokemonCenter_1F_EventScript_ExitWithoutBuying
# 45 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	case 127, LavaridgeTown_PokemonCenter_1F_EventScript_ExitWithoutBuying
# 46 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	release
# 47 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	end
# 48 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 49 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_Buy1MoomooMilk::
# 50 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	checkmoney 500, 0
# 51 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
# 52 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq LavaridgeTown_PokemonCenter_1F_EventScript_NotEnoughMoney
# 53 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	checkitemspace ITEM_MOOMOO_MILK, 1
# 54 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
# 55 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq LavaridgeTown_PokemonCenter_1F_EventScript_NotEnoughSpace
# 56 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HereYouGo, MSGBOX_DEFAULT
# 57 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	removemoney 500, 0
# 58 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	updatemoneybox 0, 0
# 59 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_MOOMOO_MILK
# 60 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	hidemoneybox
# 61 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	release
# 62 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	end
# 63 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 64 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_Buy12MoomooMilk::
# 65 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	checkmoney 6000, 0
# 66 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
# 67 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq LavaridgeTown_PokemonCenter_1F_EventScript_NotEnoughMoney
# 68 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	checkitemspace ITEM_MOOMOO_MILK, 12
# 69 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
# 70 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq LavaridgeTown_PokemonCenter_1F_EventScript_NotEnoughSpace
# 71 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HereYouGo, MSGBOX_DEFAULT
# 72 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	removemoney 6000, 0
# 73 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	updatemoneybox 0, 0
# 74 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_MOOMOO_MILK, 12
# 75 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	hidemoneybox
# 76 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	release
# 77 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	end
# 78 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 79 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_ExitWithoutBuying::
# 80 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_1F_Text_ThatsTooBad, MSGBOX_DEFAULT
# 81 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	hidemoneybox
# 82 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	release
# 83 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	end
# 84 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 85 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_NotEnoughMoney::
# 86 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
# 87 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	hidemoneybox
# 88 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	release
# 89 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	end
# 90 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 91 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_NotEnoughSpace::
# 92 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 93 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	hidemoneybox
# 94 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	release
# 95 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	end
# 96 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 97 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_LucyTrigger::
# 98 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	lock
# 99 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	addobject LOCALID_LUCY
# 100 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_LAVARIDGE_LUCY_STATE, 1
# 101 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	clearflag FLAG_HIDE_LAVARIDGE_POKECENTER_LUCY
# 102 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_1F_Text_LucyYouThere, MSGBOX_AUTOCLOSE
# 103 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	playse SE_PIN
# 104 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 105 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 106 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
# 107 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 108 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	applymovement LOCALID_LUCY, LavaridgeTown_PokemonCenter_1F_Movement_LucyEnter
# 109 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 110 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_1F_Text_ScottSaid, MSGBOX_YESNO
# 111 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
# 112 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq LavaridgeTown_PokemonCenter_1F_EventScript_LucyRefuse
# 113 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_LucyBattle::
# 114 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_1F_Text_LucyBattle, MSGBOX_DEFAULT
# 115 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_LUCY_LAVARIDGE, LavaridgeTown_PokemonCenter_1F_Text_LucyDefeat
# 116 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_LAVARIDGE_LUCY_STATE, 2
# 117 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_1F_Text_LucyGiveChoiceBand, MSGBOX_DEFAULT
# 118 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	givecustommon SPECIES_MILOTIC, 40, ITEM_LEFTOVERS, ITEM_POKE_BALL, NATURE_MODEST, 2, 252, 0, 4, 0, 0, 252, 0, 0, 0, 0, 0, 0, MOVE_SCALD, MOVE_ICE_BEAM, MOVE_ATTRACT, MOVE_RECOVER, TRUE
# 119 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 120 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	message LavaridgeTown_PokemonCenter_1F_Text_Got_Milotic
# 121 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 122 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_1F_Text_LucyGoodbye, MSGBOX_AUTOCLOSE
# 123 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 124 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 125 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8004, 2
# 126 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq LavaridgeTown_PokemonCenter_1F_EventScript_LucyExitFromSprings
# 127 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	switch VAR_FACING
# 128 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	case DIR_NORTH, LavaridgeTown_PokemonCenter_1F_EventScript_LucyExitNorth
# 129 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	case DIR_WEST, LavaridgeTown_PokemonCenter_1F_EventScript_LucyExitWest
# 130 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	case DIR_EAST, LavaridgeTown_PokemonCenter_1F_EventScript_LucyExitEast
# 131 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	end
# 132 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 133 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_Lucy::
# 134 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	applymovement LOCALID_LUCY, Common_Movement_FacePlayer
# 135 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 136 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	goto LavaridgeTown_PokemonCenter_1F_EventScript_LucyBattle
# 137 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 138 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_LucyRefuse::
# 139 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_1F_Text_VeryWell, MSGBOX_AUTOCLOSE	
# 140 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	applymovement LOCALID_LUCY, LavaridgeTown_PokemonCenter_1F_Movement_LucyGoWait
# 141 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 142 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	release
# 143 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	end
# 144 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 145 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_LucyExitFromSprings::
# 146 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	applymovement LOCALID_LUCY, LavaridgeTown_PokemonCenter_1F_Movement_LucyExitFromSprings
# 147 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 148 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	goto LavaridgeTown_PokemonCenter_1F_EventScript_LucyLeave
# 149 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 150 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_LucyExitNorth:
# 151 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	applymovement LOCALID_LUCY, LavaridgeTown_PokemonCenter_1F_Movement_LucyExitNorth
# 152 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 153 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	goto LavaridgeTown_PokemonCenter_1F_EventScript_LucyLeave
# 154 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 155 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_LucyExitWest:
# 156 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	applymovement LOCALID_LUCY, LavaridgeTown_PokemonCenter_1F_Movement_LucyExitNorth
# 157 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 158 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	goto LavaridgeTown_PokemonCenter_1F_EventScript_LucyLeave
# 159 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 160 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_LucyExitEast:
# 161 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	applymovement LOCALID_LUCY, LavaridgeTown_PokemonCenter_1F_Movement_LucyExitEast
# 162 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 163 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	goto LavaridgeTown_PokemonCenter_1F_EventScript_LucyLeave
# 164 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 165 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_EventScript_LucyLeave::
# 166 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	playse SE_SLIDING_DOOR
# 167 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	removeobject LOCALID_LUCY
# 168 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	release
# 169 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	end
# 170 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 171 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Text_LucyYouThere:
# 172 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "???: You there… Stop.$"
# 173 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 174 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Text_ScottSaid:
# 175 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "???: Scott said I might find you here.\n"
# 176 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "I am Lucy…\p"
# 177 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "I'm not one for idle chatter… I want\n"
# 178 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "to battle. Are you ready?$"
# 179 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 180 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Text_VeryWell:
# 181 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "Lucy: Very well…\n"
# 182 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "I'll be by the PC.\p"
# 183 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "Don't keep me waiting…$"
# 184 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 185 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Text_LucyDefeat:
# 186 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "Urk…$"
# 187 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 188 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Text_LucyBattle:
# 189 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "Lucy: Ready? Good.\n"
# 190 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "Let's make this quick…$"
# 191 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 192 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Text_LucyGiveChoiceBand:
# 193 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "Lucy: You were lucky, this time…\n"
# 194 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "Here. Take one of my Pokémon…$"
# 195 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 196 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Text_LucyGoodbye:
# 197 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "Lucy: Perhaps we'll meet again…\n"
# 198 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "If your luck holds up.\p"
# 199 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "Good-bye, for now…$"
# 200 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 201 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Text_WantToBuyMoomooMilk:
# 202 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "Moomoo Milk?\p"
# 203 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "It's great before entering the\n"
# 204 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "hot spring!\p"
# 205 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "And even better afterward.\n"
# 206 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "How about some?$"
# 207 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 208 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Text_ThatsTooBad:
# 209 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "Well, now I feel udder-ly useless!$"
# 210 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 211 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Text_HereYouGo:
# 212 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "Here's your Moomoo Milk. Drink up!$"
# 213 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 214 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Text_NotEnoughMoney:
# 215 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "You don't have enough money.$"
# 216 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 217 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether: @ 81FFB37
# 218 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "I think Pokémon get closer to their\n"
# 219 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "Trainers if they spend time together.\p"
# 220 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "The longer the better.\n"
# 221 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "That's what I think.$"
# 222 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 223 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate: @ 81FFBAD
# 224 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "It's sort of magical how just sitting\n"
# 225 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "in a hot-spring pool can invigorate.\p"
# 226 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "I wish I could let my Pokémon\n"
# 227 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "soak, too.$"
# 228 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 229 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo: @ 81FFC21
# 230 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "Hohoho! Hey, kid, you can reach\n"
# 231 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "the hot springs from here.\p"
# 232 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "If Pokémon are getting rest, so too\n"
# 233 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "should their Trainers.$"
# 234 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 235 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Movement_LucyEnter:
# 236 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 237 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 238 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 239 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 240 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 241 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 242 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 243 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 244 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_up
# 245 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	step_end
# 246 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 247 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Movement_LucyGoWait:
# 248 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 249 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_right
# 250 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_right
# 251 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_right
# 252 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_right
# 253 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_right
# 254 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_right
# 255 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_right
# 256 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_right
# 257 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	face_down
# 258 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	step_end
# 259 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 260 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Movement_LucyExitFromSprings:
# 261 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 262 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 263 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 264 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_right
# 265 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_right
# 266 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_right
# 267 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_right
# 268 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_right
# 269 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 270 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 271 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	step_end
# 272 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 273 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Movement_LucyExitNorth:
# 274 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 275 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 276 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 277 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 278 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 279 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 280 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	delay_8
# 281 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	step_end
# 282 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"

# 283 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
LavaridgeTown_PokemonCenter_1F_Movement_LucyExitEast:
# 284 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 285 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 286 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 287 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 288 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 289 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 290 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	delay_8
# 291 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	step_end

LavaridgeTown_PokemonCenter_1F_Text_Got_Milotic::
# 293 "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Milotic{COLOR DARK_GRAY} as a gift!$"
