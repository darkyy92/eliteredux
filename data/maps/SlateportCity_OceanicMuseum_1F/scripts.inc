# 1 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 2 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
.set LOCALID_FAMILIAR_GRUNT, 13
# 3 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 4 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_MapScripts:: @ 820AD95
# 5 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.byte 0
# 6 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 7 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant:: @ 820AD96
# 8 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
# 9 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 10 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 11 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft:: @ 820AD9F
# 12 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	lockall
# 13 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 14 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitmovement 0
# 15 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
# 16 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 17 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 18 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight:: @ 820ADB0
# 19 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	lockall
# 20 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 21 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitmovement 0
# 22 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
# 23 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 24 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 25 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee:: @ 820ADC1
# 26 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	showmoneybox 0, 0, 0
# 27 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
# 28 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	compare VAR_RESULT, YES
# 29 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
# 30 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	closemessage
# 31 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	hidemoneybox
# 32 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
# 33 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitmovement 0
# 34 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	releaseall
# 35 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 36 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 37 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee:: @ 820ADE8
# 38 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	checkmoney 50, 0
# 39 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	compare VAR_RESULT, FALSE
# 40 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
# 41 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	playse SE_SHOP
# 42 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	removemoney 50, 0
# 43 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	updatemoneybox 0, 0
# 44 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
# 45 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
# 46 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	hidemoneybox
# 47 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	releaseall
# 48 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 49 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 50 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney:: @ 820AE18
# 51 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
# 52 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
# 53 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	closemessage
# 54 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	hidemoneybox
# 55 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
# 56 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitmovement 0
# 57 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	releaseall
# 58 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 59 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 60 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway:: @ 820AE39
# 61 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
# 62 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
# 63 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	hidemoneybox
# 64 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	releaseall
# 65 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 66 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 67 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter: @ 820AE4B
# 68 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_down
# 69 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	step_end
# 70 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 71 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1:: @ 820AE4D
# 72 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
# 73 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 74 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 75 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2:: @ 820AE56
# 76 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
# 77 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 78 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 79 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3:: @ 820AE5F
# 80 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
# 81 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 82 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 83 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4:: @ 820AE68
# 84 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
# 85 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 86 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 87 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5:: @ 820AE71
# 88 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
# 89 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 90 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 91 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6:: @ 820AE7A
# 92 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
# 93 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 94 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 95 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment:: @ 820AE83
# 96 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
# 97 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 98 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 99 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment:: @ 820AE8C
# 100 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
# 101 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 102 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 103 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay:: @ 820AE95
# 104 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
# 105 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 106 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 107 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay:: @ 820AE9E
# 108 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
# 109 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 110 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 111 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1:: @ 820AEA7
# 112 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
# 113 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 114 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 115 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2:: @ 820AEB0
# 116 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
# 117 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 118 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 119 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3:: @ 820AEB9
# 120 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
# 121 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 122 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 123 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay:: @ 820AEC2
# 124 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
# 125 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 126 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 127 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine:: @ 820AECB
# 128 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
# 129 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 130 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 131 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1:: @ 820AED4
# 132 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
# 133 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 134 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 135 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2:: @ 820AEDD
# 136 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
# 137 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 138 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 139 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3:: @ 820AEE6
# 140 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
# 141 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 142 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 143 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4:: @ 820AEEF
# 144 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
# 145 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 146 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 147 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt:: @ 820AEF8
# 148 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	lock
# 149 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	faceplayer
# 150 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	delay 8
# 151 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	playse SE_PIN
# 152 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
# 153 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitmovement 0
# 154 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_Delay48
# 155 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitmovement 0
# 156 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
# 157 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	givecustommon SPECIES_CLAUNCHER, 20, ITEM_CHOICE_SCARF, ITEM_DIVE_BALL, NATURE_MODEST, 0, 0, 0, 4, 252, 252, 0, 0, 0, 0, 0, 0, 0, MOVE_U_TURN, MOVE_WATER_PULSE, MOVE_DARK_PULSE, MOVE_AURA_SPHERE, TRUE
# 158 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 159 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	message SlateportCity_OceanicMuseum_1F_Text_Got_Clauncher
# 160 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitfanfare
# 161 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	setflag FLAG_RECEIVED_TM46
# 162 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
# 163 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	closemessage
# 164 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 165 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
# 166 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 167 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
# 168 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 169 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
# 170 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 171 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
# 172 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 173 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 174 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth:: @ 820AF6C
# 175 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
# 176 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
# 177 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitmovement 0
# 178 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
# 179 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 180 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 181 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth:: @ 820AF83
# 182 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
# 183 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitmovement 0
# 184 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
# 185 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 186 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 187 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast:: @ 820AF93
# 188 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
# 189 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
# 190 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	waitmovement 0
# 191 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
# 192 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 193 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 194 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited:: @ 820AFAA
# 195 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
# 196 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	playse SE_EXIT
# 197 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	removeobject LOCALID_FAMILIAR_GRUNT
# 198 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	release
# 199 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 200 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 201 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief:: @ 820AFB5
# 202 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
# 203 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	release
# 204 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	end
# 205 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 206 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth: @ 820AFBF
# 207 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	delay_16
# 208 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	delay_8
# 209 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	delay_4
# 210 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_in_place_fastest_down
# 211 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	step_end
# 212 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 213 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast: @ 820AFC4
# 214 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	delay_16
# 215 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_in_place_fastest_down
# 216 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	step_end
# 217 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 218 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit: @ 820AFC7
# 219 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	face_down
# 220 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_fast_down
# 221 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_fast_down
# 222 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_fast_down
# 223 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_fast_down
# 224 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	delay_8
# 225 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	step_end
# 226 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 227 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth: @ 820AFCE
# 228 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_fast_right
# 229 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_fast_down
# 230 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_fast_down
# 231 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_fast_down
# 232 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	walk_fast_down
# 233 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	delay_8
# 234 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	step_end
# 235 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 236 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter: @ 820AFD5
# 237 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Welcome to the Oceanic Museum.\p"
# 238 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "The entrance fee is ¥50.\n"
# 239 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Would you like to enter?$"
# 240 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 241 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself: @ 820B026
# 242 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Please enjoy yourself.$"
# 243 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 244 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney: @ 820B03D
# 245 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Oh? I'm sorry, but you don't seem to\n"
# 246 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "have enough money.$"
# 247 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 248 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup: @ 820B075
# 249 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Oh? You're with that group that\n"
# 250 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "went in earlier?\p"
# 251 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "You're the only one who's late.\n"
# 252 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "You'd better go catch up to them!$"
# 253 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 254 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll: @ 820B0E8
# 255 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "We, Team Aqua, exist for the good\n"
# 256 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "of all!$"
# 257 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 258 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere: @ 820B112
# 259 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "We were told to assemble here,\n"
# 260 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "so we did, but…\p"
# 261 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Our Boss, the linchpin, isn't here.$"
# 262 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 263 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich: @ 820B165
# 264 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "If I ripped off the stuff here,\n"
# 265 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "would it make me rich?$"
# 266 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 267 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds: @ 820B19C
# 268 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "What I learn here, I can put to use on\n"
# 269 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "nefarious deeds…$"
# 270 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 271 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_RustboroBungled: @ 820B1D4
# 272 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "If our goons didn't bungle things\n"
# 273 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "in Rustboro, we wouldn't be here!$"
# 274 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 275 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney: @ 820B218
# 276 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "I didn't have ¥50, so it took a long\n"
# 277 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "time getting by the receptionist.$"
# 278 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 279 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling: @ 820B25F
# 280 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "I want to learn about the sea and\n"
# 281 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "use that knowledge for battling.$"
# 282 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 283 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel: @ 820B2A2
# 284 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "I get all giddy and gooey when\n"
# 285 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "I see the sea!\p"
# 286 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "For me, Capt. Stern is the number\n"
# 287 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "one role model!$"
# 288 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 289 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow: @ 820B302
# 290 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "The sea is vast without end, and\n"
# 291 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "infinitely deep…\p"
# 292 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "There must be many Pokémon that\n"
# 293 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "we don't know about.$"
# 294 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 295 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon: @ 820B369
# 296 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "I want a sea Pokémon.\p"
# 297 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "I think it would feel cool and nice\n"
# 298 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "to hug.$"
# 299 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 300 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis: @ 820B3AB
# 301 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Aiyeeeh!\n"
# 302 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "What are you doing here?\p"
# 303 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Me? I'm the Team Aqua member\n"
# 304 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "you thumped before, remember?\l"
# 305 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Back in Rusturf Tunnel?\p"
# 306 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Here, take this {COLOR BLUE}Clauncher{COLOR DARK_GRAY}!\n"
# 307 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "You have to forgive me!$"
# 308 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 309 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain: @ 820B449
# 310 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "That Pokémon, it gets really strong\n"
# 311 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "when you evolve it at level 37.\p"
# 312 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Hope I never see you again!\n"
# 313 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Wahahaha!$"
# 314 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 315 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis: @ 820B49B
# 316 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Awww, come on!\n"
# 317 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "You have to take this and let me go!$"
# 318 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 319 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment: @ 820B4CF
# 320 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "A blue fluid is spiraling inside\n"
# 321 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "a glass vessel.\p"
# 322 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“This is an experiment to create a\n"
# 323 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Whirlpool artificially using wind.”$"
# 324 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 325 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment: @ 820B547
# 326 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "A red ball is bobbing up and down\n"
# 327 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "inside a glass vessel.\p"
# 328 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“This is an experiment simulating a\n"
# 329 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Waterfall using the ball's buoyancy.”$"
# 330 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 331 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay: @ 820B5CA
# 332 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "It's a sample of soil from the ocean\n"
# 333 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "floor.\p"
# 334 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“Over many years, the remains of\n"
# 335 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "life-forms settle at the bottom of\l"
# 336 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "the sea, making sedimentary layers.\p"
# 337 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“By analyzing these layers, the\n"
# 338 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "ancient past is revealed.”$"
# 339 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 340 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay: @ 820B699
# 341 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "It's a sample of beach sand.\p"
# 342 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“Stones from mountains are washed\n"
# 343 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "down by rivers where they are\l"
# 344 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "chipped and ground down.\p"
# 345 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“They are reduced to grains and end\n"
# 346 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "up as sand on beaches.”$"
# 347 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 348 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1: @ 820B74B
# 349 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“OCEANIC MINIFACT 1\n"
# 350 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Why is seawater blue?\p"
# 351 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“Light is composed of many colors.\p"
# 352 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“When light passes through water,\n"
# 353 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "most kinds of light lose color.\p"
# 354 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“However, blue light retains its\n"
# 355 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "color, making the sea appear blue.”$"
# 356 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 357 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2: @ 820B81F
# 358 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“OCEANIC MINIFACT 2\n"
# 359 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Why is the sea salty?\p"
# 360 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“Seawater contains dissolved salt in\n"
# 361 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "the form of sodium and chlorine ions.\p"
# 362 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“These ions leech out of rocks\n"
# 363 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "and are carried out to sea by rain.\p"
# 364 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“The concentration of dissolved salt\n"
# 365 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "makes the sea salty.”$"
# 366 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 367 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3: @ 820B912
# 368 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“OCEANIC MINIFACT 3\n"
# 369 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Which is bigger? The sea or land?\p"
# 370 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“The sea covers about 70% of\n"
# 371 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "the planet, and the rest is land.\p"
# 372 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“The sea is therefore more than twice\n"
# 373 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "the size of land.”$"
# 374 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 375 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_FossilDisplay: @ 820B9C0
# 376 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "It's a fossil with wavy ridges on it.\p"
# 377 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“Soil on the ocean floor gets scoured\n"
# 378 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "by the tide.\p"
# 379 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“The flowing seawater marks the soil\n"
# 380 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "with small ridges and valleys.\p"
# 381 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "“If this soil becomes fossilized, it is\n"
# 382 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "called a ripple mark.”$"
# 383 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"

# 384 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine: @ 820BA9C
# 385 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "A strange machine is rotating under\n"
# 386 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "a glass dome.\p"
# 387 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "Maybe it's for measuring the depth\n"
# 388 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "of something…$"

SlateportCity_OceanicMuseum_1F_Text_Got_Clauncher::
# 391 "data/maps/SlateportCity_OceanicMuseum_1F/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Clauncher{COLOR DARK_GRAY} as a gift!$"
