# 1 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 2 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
.set LOCALID_SCOTT, 1
# 3 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 4 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_MapScripts:: @ 82636A7
# 5 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 7 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_Scott:: @ 82636A8
# 8 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	lock
# 9 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	faceplayer
# 10 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_GivenBerry
# 11 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_GivenShield
# 12 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints
# 13 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveItems
# 14 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 15 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 16 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_CheckGiveItems:: @ 82636CB
# 17 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier
# 18 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols
# 19 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_COLLECTED_ALL_GOLD_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols
# 20 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 21 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 22 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 23 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_CheckGiveShield:: @ 82636EC
# 24 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield
# 25 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield
# 26 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
# 27 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 28 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 29 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols:: @ 8263704
# 30 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 31 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 32 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 33 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 34 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 35 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 36 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 37 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols, MSGBOX_DEFAULT
# 38 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	giveitem ITEM_LANSAT_BERRY
# 39 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 40 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
# 41 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
# 42 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_TEMP_4
# 43 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 44 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 45 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 46 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols:: @ 826376A
# 47 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 48 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 49 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 50 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 51 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 52 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 53 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
# 54 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols, MSGBOX_DEFAULT
# 55 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	giveitem ITEM_STARF_BERRY
# 56 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 57 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
# 58 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_COLLECTED_ALL_GOLD_SYMBOLS
# 59 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_TEMP_4
# 60 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 61 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 62 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 63 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_BerryPocketFull:: @ 82637D0
# 64 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_BerryPocketStuffed, MSGBOX_DEFAULT
# 65 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 66 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 67 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 68 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_GivenBerry:: @ 82637DA
# 69 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere, MSGBOX_DEFAULT
# 70 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 71 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 72 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 73 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_RandomComment:: @ 82637E4
# 74 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	random 3
# 75 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	compare VAR_RESULT, 1
# 76 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment
# 77 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	compare VAR_RESULT, 2
# 78 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment
# 79 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers, MSGBOX_DEFAULT
# 80 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 81 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 82 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 83 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment:: @ 8263807
# 84 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain, MSGBOX_DEFAULT
# 85 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 86 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 87 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 88 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment:: @ 8263811
# 89 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier, MSGBOX_DEFAULT
# 90 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 91 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 92 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 93 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield:: @ 826381B
# 94 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 95 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
# 96 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	tower_get TOWER_DATA_WIN_STREAK
# 97 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	compare VAR_RESULT, 50
# 98 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_ge BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
# 99 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
# 100 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	tower_get TOWER_DATA_WIN_STREAK
# 101 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	compare VAR_RESULT, 50
# 102 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_ge BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
# 103 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
# 104 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 105 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 106 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_GiveSilverShield:: @ 826387A
# 107 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow, MSGBOX_DEFAULT
# 108 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	givedecoration DECOR_SILVER_SHIELD
# 109 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 110 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
# 111 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_RECEIVED_SILVER_SHIELD
# 112 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_TEMP_3
# 113 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
# 114 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 115 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 116 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_NoRoomForShield:: @ 82638A0
# 117 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_ComeBackForThisLater, MSGBOX_DEFAULT
# 118 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 119 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 120 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 121 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_GivenShield:: @ 82638AA
# 122 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings, MSGBOX_DEFAULT
# 123 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 124 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 125 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 126 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield:: @ 82638B4
# 127 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 128 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
# 129 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	tower_get TOWER_DATA_WIN_STREAK
# 130 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	compare VAR_RESULT, 100
# 131 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_ge BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
# 132 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
# 133 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	tower_get TOWER_DATA_WIN_STREAK
# 134 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	compare VAR_RESULT, 100
# 135 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_ge BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
# 136 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
# 137 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 138 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 139 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_GiveGoldShield:: @ 8263913
# 140 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow, MSGBOX_DEFAULT
# 141 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	givedecoration DECOR_GOLD_SHIELD
# 142 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 143 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
# 144 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_RECEIVED_GOLD_SHIELD
# 145 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_TEMP_3
# 146 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
# 147 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 148 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 149 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints:: @ 8263939
# 150 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingGreatThings, MSGBOX_DEFAULT
# 151 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 152 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 153 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 154 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier:: @ 8263943
# 155 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
# 156 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	closemessage
# 157 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	delay 30
# 158 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 159 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	call_if_eq BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth
# 160 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 161 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	call_if_eq BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth
# 162 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 163 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	call_if_eq BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast
# 164 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 165 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	call_if_eq BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest
# 166 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal, MSGBOX_DEFAULT
# 167 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	applymovement LOCALID_SCOTT, Common_Movement_FacePlayer
# 168 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	waitmovement 0
# 169 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing, MSGBOX_DEFAULT
# 170 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	compare VAR_SCOTT_STATE, 13
# 171 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_eq BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints
# 172 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	compare VAR_SCOTT_STATE, 9
# 173 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_ge BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints
# 174 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	compare VAR_SCOTT_STATE, 6
# 175 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto_if_ge BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints
# 176 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint
# 177 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 178 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 179 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints:: @ 82639BC
# 180 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	buffernumberstring 0, 4
# 181 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	setvar VAR_0x8004, 4
# 182 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
# 183 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 184 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 185 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints:: @ 82639CB
# 186 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	buffernumberstring 0, 3
# 187 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	setvar VAR_0x8004, 3
# 188 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
# 189 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 190 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 191 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints:: @ 82639DA
# 192 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	buffernumberstring 0, 2
# 193 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	setvar VAR_0x8004, 2
# 194 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
# 195 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 196 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 197 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint:: @ 82639E9
# 198 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	buffernumberstring 0, 1
# 199 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	setvar VAR_0x8004, 1
# 200 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
# 201 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 202 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 203 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints:: @ 82639F8
# 204 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	special GiveFrontierBattlePoints
# 205 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 206 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	msgbox BattleFrontier_ScottsHouse_Text_ExplainBattlePoints, MSGBOX_DEFAULT
# 207 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
# 208 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	setflag FLAG_TEMP_2
# 209 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	release
# 210 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	end
# 211 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 212 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth:: @ 8263A13
# 213 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFastestUp
# 214 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	waitmovement 0
# 215 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	return
# 216 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 217 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth:: @ 8263A1E
# 218 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFastestDown
# 219 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	waitmovement 0
# 220 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	return
# 221 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 222 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast:: @ 8263A29
# 223 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFastestRight
# 224 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	waitmovement 0
# 225 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	return
# 226 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 227 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest:: @ 8263A34
# 228 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFastestLeft
# 229 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	waitmovement 0
# 230 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	return
# 231 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 232 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier: @ 8263A3F
# 233 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Scott: Well, hello and welcome!\n"
# 234 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Heheh… Sorry about the cramped space.\p"
# 235 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Anyway, {PLAYER}{KUN}, let me formally\n"
# 236 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "welcome you to the Battle Frontier.\p"
# 237 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "This is my dream come true.\n"
# 238 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "It took me years and years, but I've\l"
# 239 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "finally given shape to my dream.$"
# 240 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 241 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal: @ 8263B29
# 242 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "On reflection, it was a terribly long\n"
# 243 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "journey…\p"
# 244 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I left home alone on a quest to find\n"
# 245 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "strong Trainers.\p"
# 246 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "No one can imagine how much effort\n"
# 247 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "or time it took to make this real.$"
# 248 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 249 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing: @ 8263BD4
# 250 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "But that's all in the past.\n"
# 251 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "No point dwelling on that!\p"
# 252 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "All I want for you is to enjoy battling\n"
# 253 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "to your heart's content here.\p"
# 254 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "{PLAYER}{KUN}, I want you to have this\n"
# 255 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "as a memento for all the time our\l"
# 256 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "paths crossed on our journeys.$"
# 257 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 258 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints: @ 8263CB0
# 259 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "{PLAYER} obtained\n"
# 260 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "{STR_VAR_1} Battle Point(s).$"
# 261 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 262 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_ExplainBattlePoints: @ 8263CD0
# 263 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Scott: You can check your Battle\n"
# 264 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Points on your FRONTIER PASS.\p"
# 265 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "The more success you have here at\n"
# 266 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "the Battle Frontier, the more Battle\l"
# 267 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Points you will collect.\p"
# 268 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Use your Battle Points the way you\n"
# 269 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "see fit, like trading them for items.$"
# 270 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 271 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_ExpectingGreatThings: @ 8263DB8
# 272 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I'm expecting great things from you!$"
# 273 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 274 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers: @ 8263DDD
# 275 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Scott: Every Trainer is an individual.\n"
# 276 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "They all lead lives of their own.\p"
# 277 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "But when they're in a battle,\n"
# 278 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "it doesn't matter who they are.\p"
# 279 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "They're all the same!\p"
# 280 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I love the purity of battle,\n"
# 281 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "where everyone is equal.\p"
# 282 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "That's why I go everywhere seeking\n"
# 283 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Trainers who are serious about\l"
# 284 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "battling, and invite them here.$"
# 285 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 286 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain: @ 8263F12
# 287 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Scott: Have you met any of\n"
# 288 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "the FRONTIER BRAINS?\p"
# 289 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Better yet, have you obtained any\n"
# 290 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "symbols from them?\p"
# 291 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I handpicked the FRONTIER BRAINS\n"
# 292 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "as the toughest Trainers anywhere.\p"
# 293 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "But I'm sure that seeing how tough\n"
# 294 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "you are will startle even them!$"
# 295 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 296 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier: @ 8263FFE
# 297 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Scott: You don't just train for battle,\n"
# 298 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "right?\p"
# 299 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I think I remember you working on\n"
# 300 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "a Pokédex as well.\p"
# 301 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Well, guess what?\p"
# 302 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "You may run into wild Pokémon in\n"
# 303 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "the Battle Frontier somewhere…\l"
# 304 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Fufufu!$"
# 305 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 306 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols: @ 82640BC
# 307 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Scott: Are you enjoying things in\n"
# 308 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "the Battle Frontier?\p"
# 309 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "…Wait a second…\n"
# 310 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Oh!\p"
# 311 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Your FRONTIER PASS!\n"
# 312 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "You've collected the full set\l"
# 313 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "of silver symbols!\p"
# 314 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "That's more than impressive!\n"
# 315 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "You are tough, just as I suspected!\p"
# 316 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Normally, I wouldn't do something\n"
# 317 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "like this, but this is a special time!\p"
# 318 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I want you to have this.\n"
# 319 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I'm sure you can put it to proper use.$"
# 320 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 321 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols: @ 8264216
# 322 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Scott: I hope you're enjoying\n"
# 323 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "everything in the Battle Frontier.\p"
# 324 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "…Wait a second…\n"
# 325 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Oh, my disbelieving eyes!\p"
# 326 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Your FRONTIER PASS!\n"
# 327 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "You've gathered up the full set\l"
# 328 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "of gold symbols!\p"
# 329 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "That's more than stupendous!\n"
# 330 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "You're incredible, just as I suspected!\p"
# 331 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "… … … … … …\p"
# 332 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "{PLAYER}, you've got to accept this!\p"
# 333 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I think you will be able to\n"
# 334 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "appreciate the value of my gift!$"
# 335 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 336 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere: @ 8264373
# 337 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I must say I have the gift of knowing\n"
# 338 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "a good Trainer when I see one.\p"
# 339 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I'm so glad I had the foresight to\n"
# 340 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "bring you here!$"
# 341 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 342 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_BerryPocketStuffed: @ 82643EB
# 343 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Your Berry Pocket seems to\n"
# 344 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "be stuffed.$"
# 345 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 346 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow: @ 8264412
# 347 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Scott: Oh, I heard about you!\n"
# 348 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "How you ruled the Battle Tower!\l"
# 349 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "You beat over 50 Trainers in a row?\p"
# 350 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "That's fantastic!\n"
# 351 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I want you to have this!$"
# 352 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 353 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow: @ 826449F
# 354 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Scott: Oh, my! I heard about you!\n"
# 355 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "How you overwhelmed the Battle Tower!\l"
# 356 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "You beat over 100 Trainers in a row?\p"
# 357 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "That's ridiculously spectacular!\n"
# 358 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "You've got to have this!$"
# 359 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 360 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings: @ 8264546
# 361 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "I'll be expecting to hear even greater\n"
# 362 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "things about you now!$"
# 363 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"

# 364 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
BattleFrontier_ScottsHouse_Text_ComeBackForThisLater: @ 8264583
# 365 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "Oops, well, if you have too much\n"
# 366 "data/maps/BattleFrontier_ScottsHouse/scripts.pory"
	.string "stuff, come back for this later.$"
