# 1 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 2 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
.set LOCALID_SS_TIDAL, 2
# 3 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
.set LOCALID_FERRY_ATTENDANT, 3
# 4 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
.set LOCALID_MANIAC_1, 9
# 5 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
.set LOCALID_MANIAC_2, 10
# 6 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
.set LOCALID_GIRL, 12
# 7 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
.set LOCALID_CAMPER, 14
# 8 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
.set LOCALID_FISHERMAN_2, 18
# 9 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
.set LOCALID_MAN_4, 23
# 10 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 11 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_MapScripts:: @ 823D3E1
# 12 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
# 13 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.byte 0
# 14 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 15 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_OnTransition: @ 823D3E7
# 16 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
# 17 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
# 18 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 19 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 20 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FerryAttendant:: @ 823D3F0
# 21 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 22 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 23 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
# 24 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	checkitem ITEM_SS_TICKET, 1
# 25 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	compare VAR_RESULT, FALSE
# 26 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto_if_eq BattleFrontier_OutsideWest_EventScript_NoSSTicket
# 27 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
# 28 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmessage
# 29 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
# 30 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 31 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 32 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination:: @ 823D416
# 33 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
# 34 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	switch VAR_RESULT
# 35 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
# 36 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
# 37 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
# 38 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
# 39 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 40 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 41 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_NoSSTicket:: @ 823D44E
# 42 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
# 43 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 44 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 45 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 46 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FerryToSlateport:: @ 823D458
# 47 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
# 48 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	compare VAR_RESULT, NO
# 49 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto_if_eq BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
# 50 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
# 51 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
# 52 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	warp MAP_SLATEPORT_CITY_HARBOR, 255, 8, 11
# 53 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitstate
# 54 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 55 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 56 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 57 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FerryToLilycove:: @ 823D483
# 58 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
# 59 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	compare VAR_RESULT, NO
# 60 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto_if_eq BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
# 61 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
# 62 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
# 63 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	warp MAP_LILYCOVE_CITY_HARBOR, 255, 8, 11
# 64 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitstate
# 65 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 66 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 67 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 68 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination:: @ 823D4AE
# 69 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
# 70 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmessage
# 71 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
# 72 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 73 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 74 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_BoardFerry:: @ 823D4BA
# 75 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	closemessage
# 76 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
# 77 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 78 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	delay 30
# 79 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	hideobjectat LOCALID_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
# 80 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	setvar VAR_0x8004, LOCALID_SS_TIDAL
# 81 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call Common_EventScript_FerryDepartIsland
# 82 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 83 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 84 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_CancelFerrySelect:: @ 823D4D8
# 85 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
# 86 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 87 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 88 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 89 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_BattleDomeSign:: @ 823D4E2
# 90 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
# 91 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 92 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 93 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_BattleFactorySign:: @ 823D4EB
# 94 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
# 95 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 96 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 97 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_BattlePikeSign:: @ 823D4F4
# 98 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
# 99 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 100 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 101 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
@ Unused. Of note, Battle Tower is in the East section in the final release
# 102 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_UnusedNPC1:: @ 823D4FD
# 103 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
# 104 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 105 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 106 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
@ Unused
# 107 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_UnusedNPC2:: @ 823D4FD
# 108 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
# 109 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 110 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 111 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Boy1:: @ 823D50F
# 112 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
# 113 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 114 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 115 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Fisherman2:: @ 823D518
# 116 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 117 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 118 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
# 119 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmessage
# 120 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FISHERMAN_2, Common_Movement_FaceAwayPlayer
# 121 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 122 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitbuttonpress
# 123 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 124 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 125 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 126 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Man1:: @ 823D52D
# 127 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
# 128 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 129 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 130 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Maniac1:: @ 823D536
# 131 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 132 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
# 133 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 134 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 135 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Maniac2:: @ 823D53D
# 136 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 137 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
# 138 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 139 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 140 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk:: @ 823D544
# 141 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFastestRight
# 142 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 143 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
# 144 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFastestLeft
# 145 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 146 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
# 147 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	closemessage
# 148 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	delay 25
# 149 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFastestUp
# 150 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFastestUp
# 151 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 152 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 153 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 154 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 155 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Camper:: @ 823D57F
# 156 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 157 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 158 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	delay 20
# 159 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 160 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
# 161 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 162 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
# 163 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 164 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
# 165 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 166 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
# 167 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
# 168 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 169 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 170 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 171 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_CamperFaceFactory:: @ 823D5BA
# 172 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_CAMPER, Common_Movement_WalkInPlaceFastestUp
# 173 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 174 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 175 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 176 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory:: @ 823D5C5
# 177 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 178 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 179 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Girl:: @ 823D5C6
# 180 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 181 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 182 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
# 183 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmessage
# 184 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 185 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
# 186 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 187 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
# 188 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 189 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq BattleFrontier_OutsideWest_EventScript_GirlShudderWest
# 190 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 191 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq BattleFrontier_OutsideWest_EventScript_GirlShudderEast
# 192 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitbuttonpress
# 193 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 194 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 195 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 196 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_GirlShudderNorth:: @ 823D5FD
# 197 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
# 198 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 199 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 200 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 201 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_GirlShudderSouth:: @ 823D608
# 202 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
# 203 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 204 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 205 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 206 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_GirlShudderWest:: @ 823D613
# 207 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
# 208 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 209 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 210 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 211 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_GirlShudderEast:: @ 823D61E
# 212 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
# 213 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 214 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 215 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 216 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Movement_GirlShudderNorth: @ 823D629
# 217 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_fastest_down
# 218 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_fastest_down
# 219 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 220 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 221 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Movement_GirlShudderSouth: @ 823D62C
# 222 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_fastest_up
# 223 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_fastest_up
# 224 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 225 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 226 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Movement_GirlShudderWest: @ 823D62F
# 227 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_fastest_right
# 228 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_fastest_right
# 229 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 230 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 231 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Movement_GirlShudderEast: @ 823D632
# 232 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_fastest_left
# 233 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_fastest_left
# 234 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 235 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 236 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Woman2:: @ 823D635
# 237 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 238 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 239 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
# 240 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	random 2
# 241 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	compare VAR_RESULT, 1
# 242 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto_if_eq BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
# 243 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
# 244 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 245 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 246 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors:: @ 823D653
# 247 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
# 248 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 249 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 250 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 251 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors:: @ 823D65D
# 252 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
# 253 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 254 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 255 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 256 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Fisherman1:: @ 823D667
# 257 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
# 258 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 259 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 260 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
@ Unused
# 261 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_UnusedNPC3:: @ 823D670
# 262 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
# 263 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 264 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 265 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Gentleman:: @ 823D679
# 266 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
# 267 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 268 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 269 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Lass:: @ 823D682
# 270 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
# 271 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 272 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 273 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_ExpertM:: @ 823D68B
# 274 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
# 275 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 276 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 277 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Man2:: @ 823D694
# 278 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
# 279 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 280 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 281 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Woman1:: @ 823D69D
# 282 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
# 283 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 284 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 285 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FatMan1:: @ 823D6A6
# 286 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
# 287 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 288 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 289 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FatMan2:: @ 823D6AF
# 290 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
# 291 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 292 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 293 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Woman3:: @ 823D6B8
# 294 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 295 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
# 296 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 297 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 298 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 299 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Boy2:: @ 823D6C3
# 300 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 301 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
# 302 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 303 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 304 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 305 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_OldMan:: @ 823D6CE
# 306 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
# 307 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 308 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 309 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Man4:: @ 823D6D7
# 310 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 311 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 312 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
# 313 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	closemessage
# 314 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_MAN_4, Common_Movement_FaceOriginalDirection
# 315 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 316 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 317 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 318 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 319 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_PokefanF:: @ 823D6EE
# 320 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
# 321 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 322 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 323 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BattleDomeSign: @ 823D6F7
# 324 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This is the BATTLE DOME!\n"
# 325 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Your path to the invincible superstar!$"
# 326 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 327 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BattleFactorySign: @ 823D737
# 328 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This is the BATTLE FACTORY!\n"
# 329 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Seek out the toughest Pokémon!$"
# 330 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 331 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BattlePikeSign: @ 823D772
# 332 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This is the BATTLE PIKE!\n"
# 333 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Choose one of three paths!$"
# 334 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 335 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_ThisIsBattleTower: @ 823D7A6
# 336 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This is the Battle Tower.\p"
# 337 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Trainers bring their best-raised\n"
# 338 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Pokémon for elimination-style matches.$"
# 339 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 340 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_MayISeeYourTicket: @ 823D808
# 341 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Hello, are you here for the ferry?\n"
# 342 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "May I see your Ticket?$"
# 343 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 344 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard: @ 823D842
# 345 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "{PLAYER} doesn't have the Ticket…\p"
# 346 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm terribly sorry.\p"
# 347 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "You must have a Ticket to board\n"
# 348 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "the ferry.$"
# 349 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 350 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo: @ 823D89D
# 351 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "{PLAYER} flashed the Ticket.\p"
# 352 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Perfect! That's all you need!\p"
# 353 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "And where would you like to go?$"
# 354 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 355 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_SlateportItIs: @ 823D8F2
# 356 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Slateport City it is, then!$"
# 357 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 358 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_LilycoveItIs: @ 823D90E
# 359 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Lilycove City it is, then!$"
# 360 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 361 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime: @ 823D929
# 362 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Please sail with us another time!$"
# 363 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 364 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_PleaseBoardFerry: @ 823D94B
# 365 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Please board the ferry and wait for\n"
# 366 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "departure.$"
# 367 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 368 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo: @ 823D97A
# 369 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Then, where would you like to go?$"
# 370 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 371 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends: @ 823D99C
# 372 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm the best out of all my friends.\n"
# 373 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But here…\l"
# 374 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I've been useless!$"
# 375 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 376 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_CantFindBattleTower: @ 823D9DD
# 377 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I want to go to the Battle Tower,\n"
# 378 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "but I can't find it even though I have\l"
# 379 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "a map of the Battle Frontier.\p"
# 380 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This place is just too big!$"
# 381 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 382 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere: @ 823DA60
# 383 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I wanted to take a challenge as soon\n"
# 384 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "as I arrived here.\p"
# 385 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But on the way, I got seasick…\n"
# 386 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Urrrrp…$"
# 387 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 388 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere: @ 823DABF
# 389 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It's not as if just anyone can come\n"
# 390 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "here, you know?\p"
# 391 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Only those Trainers who've been\n"
# 392 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "recognized as tough are brought here.\p"
# 393 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That's why many Trainers don't even\n"
# 394 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "know about the Battle Frontier.$"
# 395 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 396 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons: @ 823DB7D
# 397 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Hey, bro…\p"
# 398 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Are you sure we can make challenges\n"
# 399 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "even if we don't have any Pokémon?$"
# 400 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 401 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons: @ 823DBCE
# 402 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Uh…\n"
# 403 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm sure it'll be okay.\p"
# 404 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I think…\p"
# 405 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But remember that big scary guy?\n"
# 406 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "He said, “I'll lend you Pokémon!”$"
# 407 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 408 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons: @ 823DC36
# 409 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That's the BATTLE FACTORY.\n"
# 410 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "You can rent strong Pokémon there.\p"
# 411 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But it makes me wonder.\n"
# 412 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Who's raising those rental Pokémon?$"
# 413 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 414 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper: @ 823DCB0
# 415 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm scared of going into the BATTLE\n"
# 416 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "PIKE because of SEVIPER…\p"
# 417 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "B-but I came all the way here, so I will\n"
# 418 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "try to conquer everything!\l"
# 419 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "…Shudder…$"
# 420 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 421 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors: @ 823DD3B
# 422 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Let's play rock, paper, scissors!\n"
# 423 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "One, two, three!\p"
# 424 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "… … … … … …$"
# 425 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 426 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge: @ 823DD7A
# 427 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Yay! I won!\n"
# 428 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I will take the BATTLE PIKE challenge!$"
# 429 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 430 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge: @ 823DDAD
# 431 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Oh, no…\n"
# 432 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I lost.\p"
# 433 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I guess I'm not very lucky today.\n"
# 434 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'll put off my BATTLE PIKE challenge\l"
# 435 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "until tomorrow.$"
# 436 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 437 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling: @ 823DE15
# 438 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I believe I'm the only person here who,\n"
# 439 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "for some unknown reason, would choose\l"
# 440 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "fishing over battling.\p"
# 441 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Huh? You can't catch anything here?\n"
# 442 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That's disappointing…$"
# 443 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 444 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol: @ 823DEB4
# 445 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Today, I'm going to keep battling, no\n"
# 446 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "matter what, until I get a Symbol.$"
# 447 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 448 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome: @ 823DEFD
# 449 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Oh? You're off to challenge\n"
# 450 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "the BATTLE DOME?\p"
# 451 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'll wish you the best of luck.\n"
# 452 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Let us both win our way up and meet\l"
# 453 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "in challenges.$"
# 454 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 455 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa: @ 823DF7D
# 456 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Grandpa, over here!\n"
# 457 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "The BATTLE DOME is here!\l"
# 458 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Go get 'em, Grandpa!$"
# 459 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 460 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe: @ 823DFBF
# 461 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Ah, so this here is the BATTLE DOME?\n"
# 462 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I won't let GENTLEMEN beat me!\p"
# 463 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But where is the entrance?$"
# 464 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 465 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo: @ 823E01E
# 466 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "There used to be nothing here not all\n"
# 467 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "that long ago.\p"
# 468 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But, now look at this place! Amazing!\n"
# 469 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'll bring my mother out to see this.$"
# 470 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 471 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier: @ 823E09F
# 472 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I've finally arrived at the BATTLE\n"
# 473 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "FRONTIER!\p"
# 474 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm sure to grab attention with\n"
# 475 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "my looks and ability!$"
# 476 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 477 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople: @ 823E102
# 478 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Munch, munch…\p"
# 479 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It looks like this square's filled with\n"
# 480 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "tough people.\p"
# 481 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Munch, munch…$"
# 482 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 483 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike: @ 823E154
# 484 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Crunch, munch…\p"
# 485 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "A while back, I met this older girl\n"
# 486 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "at the BATTLE PIKE.\p"
# 487 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "She had these eyes that were scary\n"
# 488 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "in a real ornery way.\p"
# 489 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Crunch, munch…\p"
# 490 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "She got all furious: “Will you quit\n"
# 491 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "eating!” Then she whaled on me.\p"
# 492 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It was a hair-raising kind of\n"
# 493 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "scary experience, sure enough.\p"
# 494 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Crunch, munch…$"
# 495 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 496 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet: @ 823E273
# 497 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Huh? Will you listen to yourself?\n"
# 498 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That's nothing!\p"
# 499 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Why, the last time I cheered for him,\n"
# 500 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "our eyes met and sparks flew!$"
# 501 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 502 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering: @ 823E2E9
# 503 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Whaaaaaat?!\n"
# 504 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Pfft!\p"
# 505 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That only happened because\n"
# 506 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I happened to be sitting next to you!\p"
# 507 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "The DOME ACE only looked our way\n"
# 508 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "because my cheering was so loud!$"
# 509 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 510 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_DomeAceIsMine: @ 823E37E
# 511 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Oh, shush!\n"
# 512 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Keep that racket down!\p"
# 513 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "You fair-weather fans should stick\n"
# 514 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "to cheering for some Gym Leader!\p"
# 515 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "The DOME ACE is mine!\n"
# 516 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "The only idol for me!$"
# 517 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 518 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers: @ 823E410
# 519 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Those people squabbling over there…\p"
# 520 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It's hard to believe, but they once\n"
# 521 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "were TRAINERS, and good ones, too.\p"
# 522 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "They used to be incredibly tough,\n"
# 523 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "and they were famous, too.\p"
# 524 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But they were obliterated by this\n"
# 525 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "certain Trainer at a tournament.\p"
# 526 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "They were so thoroughly whipped,\n"
# 527 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "they became smitten by the Trainer.\p"
# 528 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Now they're just fans of the Trainer.\n"
# 529 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "They go cheer for their idol at the\l"
# 530 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "BATTLE DOME every day now.$"
# 531 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 532 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier: @ 823E5A5
# 533 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I heard a rumor that someone saw\n"
# 534 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "a Pokémon with an unusually long tail\l"
# 535 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "somewhere in the Battle Frontier.\p"
# 536 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It must be adorable. I'm sure of it…\p"
# 537 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Oh, challenges can wait. I feel driven\n"
# 538 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "to find the delightful creature!$"
