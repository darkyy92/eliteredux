# 1 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 2 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
.set LOCALID_AIDE, 1
# 3 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
.set LOCALID_BIRCH, 2
# 4 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
.set LOCALID_RIVAL, 3
# 5 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
.set LOCALID_BALL_CYNDAQUIL, 4
# 6 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
.set LOCALID_BALL_TOTODILE, 5
# 7 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
.set LOCALID_BALL_CHIKORITA, 6
# 8 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 9 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_MapScripts:: @ 81F9C91
# 10 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_OnTransition
# 11 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_OnWarp
# 12 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_OnFrame
# 13 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.byte 0
# 14 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 15 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ State descriptions for VAR_DEX_UPGRADE_JOHTO_STARTER_STATE
# 16 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 1: Beat Elite Four, Dex upgrade ready
# 17 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 2: Received National Dex
# 18 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 3: Left lab after receiving National Dex
# 19 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 4: Entered lab after catching all Hoenn mons
# 20 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 5: Birch told player to choose Johto starter
# 21 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 6: Chose Johto starter
# 22 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 23 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ State descriptions for VAR_BIRCH_LAB_STATE
# 24 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 1: Never occurs
# 25 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 2: Chose starter
# 26 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 3: Received starter in lab
# 27 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 4: Defeated rival on Route 103
# 28 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 5: Received pokedex
# 29 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 30 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_OnTransition: @ 81F9CA1
# 31 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 32 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 33 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 34 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout
# 35 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
# 36 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
# 37 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
# 38 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter
# 39 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 40 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 41 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter:: @ 81F9CCD
# 42 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	specialvar VAR_RESULT, HasAllHoennMons
# 43 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
# 44 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter
# 45 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 46 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 5, 10
# 47 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 48 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 49 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter:: @ 81F9CE9
# 50 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
# 51 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
# 52 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 53 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout:: @ 81F9CF3
# 54 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
# 55 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 56 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 57 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout:: @ 81F9CF7
# 58 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
# 59 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 60 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 5, 10
# 61 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 62 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 63 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_OnWarp: @ 81F9D06
# 64 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter
# 65 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
# 66 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
# 67 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
# 68 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
# 69 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
# 70 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
# 71 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.2byte 0
# 72 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 73 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter:: @ 81F9D40
# 74 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 75 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 76 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 77 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade:: @ 81F9D45
# 78 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 79 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCH
# 80 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_RIVAL
# 81 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_RIVAL, DIR_NORTH
# 82 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_RIVAL, 5, 5
# 83 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCH, DIR_SOUTH
# 84 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCH, 6, 4
# 85 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_AIDE, DIR_EAST
# 86 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_AIDE, 10, 10
# 87 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 88 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 89 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject:: @ 81F9D71
# 90 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_RIVAL
# 91 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 92 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 93 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters:: @ 81F9D75
# 94 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BALL_CYNDAQUIL
# 95 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BALL_TOTODILE
# 96 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BALL_CHIKORITA
# 97 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_RIVAL
# 98 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BALL_CYNDAQUIL, DIR_SOUTH
# 99 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BALL_CYNDAQUIL, 8, 4
# 100 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BALL_TOTODILE, DIR_SOUTH
# 101 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BALL_TOTODILE, 9, 4
# 102 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BALL_CHIKORITA, DIR_SOUTH
# 103 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BALL_CHIKORITA, 10, 4
# 104 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCH, DIR_SOUTH
# 105 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCH, 6, 4
# 106 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_RIVAL, DIR_EAST
# 107 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_RIVAL, 5, 5
# 108 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 109 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 110 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_OnFrame: @ 81F9DB9
# 111 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent
# 112 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent
# 113 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex
# 114 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter
# 115 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.2byte 0
# 116 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 117 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ The starter is technically given prior to this on Route 101 by special ChooseStarter
# 118 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ This is just where the game tells you its yours and lets you nickname it
# 119 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent:: @ 81F9DDB
# 120 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 121 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferleadmonspeciesname 0
# 122 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon
# 123 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 124 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 125 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 126 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
# 127 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
# 128 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter
# 129 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, NO
# 130 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
# 131 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 132 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 133 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter:: @ 81F9E07
# 134 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_0x8004, 0
# 135 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 136 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
# 137 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 138 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 139 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival:: @ 81F9E17
# 140 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival, MSGBOX_YESNO
# 141 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
# 142 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
# 143 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, NO
# 144 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
# 145 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 146 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 147 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival:: @ 81F9E36
# 148 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou, MSGBOX_DEFAULT
# 149 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_101_BOY
# 150 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 3
# 151 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 152 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 153 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 154 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival:: @ 81F9E48
# 155 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay, MSGBOX_YESNO
# 156 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
# 157 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
# 158 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, NO
# 159 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
# 160 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 161 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 162 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent:: @ 81F9E67
# 163 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 164 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
# 165 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 166 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex
# 167 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 168 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 169 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex: @ 81F9E78
# 170 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 171 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 172 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 173 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 174 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 175 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 176 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 177 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 178 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 179 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex::
# 180 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 181 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 182 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OtherDimensionsTakeCosmog, MSGBOX_DEFAULT
# 183 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 184 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchGiveCosmogs
# 185 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 186 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_COSMOG
# 187 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	special GetStaticEncounterLevel
# 188 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_COSMOG, VAR_0x800A, ITEM_LUCKY_EGG
# 189 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_COSMOG, VAR_0x800A, ITEM_LUCKY_EGG
# 190 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, 0
# 191 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_ReceiveCosmogParty
# 192 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, 1
# 193 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_ReceiveCosmogPC
# 194 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 195 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 196 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 197 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceiveCosmogParty::
# 198 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCosmogFanfare
# 199 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 200 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, NO
# 201 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_RivalCosmog
# 202 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 203 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 204 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_RivalCosmog
# 205 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 206 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 207 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceiveCosmogPC::
# 208 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCosmogFanfare
# 209 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 210 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, NO
# 211 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_SendCosmogToPC
# 212 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 213 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_SendCosmogToPC
# 214 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 215 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 216 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendCosmogToPC:: @ 82700D0
# 217 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 218 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_RivalCosmog
# 219 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 220 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 221 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCosmogFanfare:: @ 82700DB
# 222 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 223 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedCosmog
# 224 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 225 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 226 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname 0, SPECIES_COSMOG
# 227 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 228 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 229 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_RivalCosmog::
# 230 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 231 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MALE
# 232 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment
# 233 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, FEMALE
# 234 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment
# 235 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
# 236 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 237 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestRight
# 238 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 239 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 240 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 241 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MALE
# 242 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_MayGoRoute103
# 243 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, FEMALE
# 244 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGoRoute103
# 245 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 246 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
# 247 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_ProfessorBirchsLab_Movement_RivalLeaves
# 248 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 249 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_RIVAL
# 250 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_103_RIVAL
# 251 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 252 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 253 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
# 254 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0
# 255 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
# 256 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 257 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 258 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 259 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment:: @ 81F9F32
# 260 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool, MSGBOX_DEFAULT
# 261 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 262 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 263 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 264 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment:: @ 81F9F3C
# 265 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe, MSGBOX_DEFAULT
# 266 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 267 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 268 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 269 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter:: @ 81F9F62
# 270 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 271 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter
# 272 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 273 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon, MSGBOX_DEFAULT
# 274 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
# 275 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 276 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 277 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 278 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_RivalLeaves:
# 279 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 280 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 281 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 282 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 283 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 284 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 285 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 286 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 287 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 288 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 289 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_BirchGiveCosmogs:
# 290 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 291 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_fastest_down
# 292 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 293 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 294 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 295 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_fastest_down
# 296 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 297 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 298 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 299 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 300 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter: @ 81F9F7C
# 301 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 302 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 303 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 304 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 305 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 306 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 307 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 308 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 309 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 310 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Aide:: @ 81F9F84
# 311 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 312 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 313 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_BIRCH_LAB_STATE, 3
# 314 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter
# 315 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_set FLAG_BIRCH_AIDE_MET, LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet
# 316 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork, MSGBOX_DEFAULT
# 317 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_BIRCH_AIDE_MET
# 318 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 319 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 320 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 321 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet:: @ 81F9FA7
# 322 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork, MSGBOX_DEFAULT
# 323 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 324 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 325 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 326 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter:: @ 81F9FB1
# 327 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo, MSGBOX_DEFAULT
# 328 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 329 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 330 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 331 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Cyndaquil:: @ 81F9FBB
# 332 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 333 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 334 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 335 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFastestRight
# 336 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 337 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_CYNDAQUIL, 10, 3
# 338 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil, MSGBOX_YESNO
# 339 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, NO
# 340 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 341 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil
# 342 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 343 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 344 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Totodile:: @ 81F9FEF
# 345 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 346 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 347 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 348 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFastestRight
# 349 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 350 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_TOTODILE, 10, 3
# 351 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile, MSGBOX_YESNO
# 352 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, NO
# 353 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 354 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile
# 355 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 356 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 357 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Chikorita:: @ 81FA023
# 358 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 359 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 360 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 361 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFastestRight
# 362 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 363 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_CHIKORITA, 10, 3
# 364 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita, MSGBOX_YESNO
# 365 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, NO
# 366 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 367 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita
# 368 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 369 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 370 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter:: @ 81FA057
# 371 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone, MSGBOX_DEFAULT
# 372 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 373 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 374 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 375 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime:: @ 81FA061
# 376 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 377 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
# 378 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 379 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 380 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 381 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil:: @ 81FA06C
# 382 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname 0, SPECIES_CYNDAQUIL
# 383 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_CYNDAQUIL
# 384 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_CYNDAQUIL, 5, ITEM_NONE
# 385 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, 0
# 386 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty
# 387 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, 1
# 388 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC
# 389 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 390 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 391 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 392 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 393 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty:: @ 81FA0A1
# 394 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 395 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BALL_CYNDAQUIL
# 396 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 397 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, NO
# 398 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 399 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 400 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 401 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 402 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 403 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 404 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC:: @ 81FA0CC
# 405 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 406 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BALL_CYNDAQUIL
# 407 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 408 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, NO
# 409 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
# 410 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 411 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
# 412 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 413 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 414 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC:: @ 81FA0F2
# 415 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 416 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 417 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 418 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 419 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil:: @ 81FA0FD
# 420 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 421 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 422 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 423 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 424 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 425 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 426 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile:: @ 81FA10D
# 427 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname 0, SPECIES_TOTODILE
# 428 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_TOTODILE
# 429 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_TOTODILE, 5, ITEM_NONE
# 430 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, 0
# 431 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty
# 432 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, 1
# 433 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC
# 434 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 435 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 436 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 437 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 438 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty:: @ 81FA142
# 439 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 440 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BALL_TOTODILE
# 441 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 442 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, NO
# 443 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 444 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 445 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 446 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 447 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 448 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 449 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC:: @ 81FA16D
# 450 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 451 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BALL_TOTODILE
# 452 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 453 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, NO
# 454 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
# 455 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 456 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
# 457 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 458 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 459 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC:: @ 81FA193
# 460 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 461 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 462 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 463 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 464 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile:: @ 81FA19E
# 465 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 466 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 467 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 468 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 469 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 470 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 471 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita:: @ 81FA1AE
# 472 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname 0, SPECIES_CHIKORITA
# 473 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_CHIKORITA
# 474 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_CHIKORITA, 5, ITEM_NONE
# 475 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, 0
# 476 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty
# 477 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, 1
# 478 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC
# 479 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 480 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 481 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 482 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 483 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty:: @ 81FA1E3
# 484 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 485 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BALL_CHIKORITA
# 486 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 487 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, NO
# 488 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 489 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 490 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 491 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 492 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 493 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 494 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC:: @ 81FA20E
# 495 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 496 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BALL_CHIKORITA
# 497 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 498 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, NO
# 499 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
# 500 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 501 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
# 502 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 503 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 504 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC:: @ 81FA234
# 505 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 506 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 507 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 508 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 509 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita:: @ 81FA23F
# 510 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 511 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 512 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 513 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 514 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 515 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 516 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter:: @ 81FA24F
# 517 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 518 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter
# 519 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 520 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 521 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 522 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 523 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Birch:: @ 81FA25A
# 524 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 525 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 526 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
# 527 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon
# 528 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
# 529 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting
# 530 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
# 531 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
# 532 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
# 533 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 534 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 535 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon:: @ 81FA28A
# 536 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon, MSGBOX_DEFAULT
# 537 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 538 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 539 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 540 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting:: @ 81FA294
# 541 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
# 542 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 543 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 544 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 545 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister:: @ 81FA29E
# 546 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
# 547 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
# 548 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq ProfBirch_EventScript_RatePokedexOrRegister
# 549 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 550 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge ProfBirch_EventScript_RatePokedexOrRegister
# 551 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_BIRCH_LAB_STATE, 5
# 552 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait
# 553 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome, MSGBOX_DEFAULT
# 554 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 555 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 556 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 557 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
EventScript_RegisterProfBirch:: @ 81FA2D2
# 558 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
# 559 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 560 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 561 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 562 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
# 563 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 564 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 565 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 566 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 567 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_REGISTER_BIRCH_STATE, 2
# 568 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 569 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 570 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 571 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex:: @ 81FA2F8
# 572 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
# 573 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex
# 574 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
# 575 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 576 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer
# 577 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 578 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 579 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 580 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 581 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MALE
# 582 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls
# 583 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, FEMALE
# 584 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls
# 585 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 5
# 586 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 587 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_OLDALE_TOWN_STATE, 1
# 588 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
# 589 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
# 590 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 591 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 592 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 593 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls:: @ 81FA352
# 594 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese, MSGBOX_DEFAULT
# 595 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	//giveitem ITEM_CHERISH_BALL, 30
# 596 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	//compare VAR_RESULT, FALSE
# 597 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	//call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls
# 598 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls, MSGBOX_DEFAULT
# 599 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_RESULT, 0
# 600 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 601 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 602 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls:: @ 81FA37F
# 603 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese, MSGBOX_DEFAULT
# 604 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	//giveitem ITEM_CHERISH_BALL, 30
# 605 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	//compare VAR_RESULT, FALSE
# 606 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	//call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls
# 607 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls, MSGBOX_DEFAULT
# 608 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_RESULT, 1
# 609 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 610 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 611 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex:: @ 81FA3AC
# 612 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 613 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
# 614 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 615 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 616 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	special SetUnlockedPokedexFlags
# 617 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 618 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
# 619 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	special EnableNationalPokedex
# 620 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
# 621 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 622 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 623 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait:: @ 81FA3C4
# 624 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
# 625 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 626 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 627 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 628 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls:: @ 81FA3CE
# 629 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
# 630 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 631 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 632 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls:: @ 81FA3D7
# 633 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull, MSGBOX_DEFAULT
# 634 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 635 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 636 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer: @ 81FA3E0
# 637 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 638 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_fastest_left
# 639 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 640 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 641 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Machine:: @ 81FA3E3
# 642 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
# 643 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 644 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 645 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Rival:: @ 81FA3EC
# 646 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 647 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 648 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
# 649 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans
# 650 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 651 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier
# 652 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
# 653 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork
# 654 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 655 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MALE
# 656 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext
# 657 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, FEMALE
# 658 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext
# 659 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 660 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 661 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 662 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext:: @ 81FA428
# 663 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
# 664 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 665 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 666 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext:: @ 81FA431
# 667 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
# 668 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 669 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 670 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans:: @ 81FA43A
# 671 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 672 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MALE
# 673 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere
# 674 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, FEMALE
# 675 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly
# 676 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 677 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 678 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 679 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere:: @ 81FA453
# 680 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere, MSGBOX_DEFAULT
# 681 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 682 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 683 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly: @ 81FA45C
# 684 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly, MSGBOX_DEFAULT
# 685 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 686 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 687 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier:: @ 81FA465
# 688 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 689 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MALE
# 690 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier
# 691 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, FEMALE
# 692 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier
# 693 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 694 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 695 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 696 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier:: @ 81FA47E
# 697 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
# 698 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 699 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 700 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier:: @ 81FA487
# 701 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
# 702 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 703 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 704 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork::
# 705 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 706 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MALE
# 707 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_MayGoRoute103
# 708 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, FEMALE
# 709 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGoRoute103
# 710 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 711 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 712 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 713 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayGoRoute103:: @ 81FA4A9
# 714 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayGoRoute103, MSGBOX_DEFAULT
# 715 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 716 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 717 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGoRoute103:: @ 81FA4B2
# 718 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanGoRoute103, MSGBOX_DEFAULT
# 719 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 720 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 721 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_PC:: @ 81FA4BB
# 722 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch, MSGBOX_SIGN
# 723 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 724 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 725 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf:: @ 81FA4C4
# 726 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
# 727 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 728 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 729 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Book:: @ 81FA4CD
# 730 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead, MSGBOX_SIGN
# 731 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 732 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 733 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall:: @ 81FA4D6
# 734 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 735 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	pokenavcall LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall
# 736 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 737 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	clearflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
# 738 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 739 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 740 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 741 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork: @ 81FA4E2
# 742 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Hunh? Prof. Birch?\p"
# 743 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The Prof's away on fieldwork.\n"
# 744 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Ergo, he isn't here.\p"
# 745 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh, let me explain what fieldwork is.\p"
# 746 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It is to study things in the natural\n"
# 747 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "environment, like fields and mountains,\l"
# 748 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "instead of a laboratory.\p"
# 749 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The Prof isn't one for doing desk work.\n"
# 750 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "He's the type of person who would\l"
# 751 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "rather go outside and experience\l"
# 752 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "things than read about them here.$"
# 753 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 754 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork: @ 81FA641
# 755 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The Prof isn't one for doing desk work.\n"
# 756 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "He's the type of person who would\l"
# 757 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "rather go outside and experience\l"
# 758 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "things than read about them here.$"
# 759 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 760 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo: @ 81FA6CE
# 761 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch is studying the habitats\n"
# 762 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and distribution of Pokémon.\p"
# 763 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The Prof enjoys {RIVAL}'s help, too.\n"
# 764 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "There's a lot of love there.$"
# 765 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 766 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon: @ 81FA74D
# 767 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch: So, {PLAYER}{KUN}.\p"
# 768 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I've heard so much about you from\n"
# 769 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "your father.\p"
# 770 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I've heard that you don't have your\n"
# 771 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "own Pokémon yet.\p"
# 772 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "But the way you battled earlier,\n"
# 773 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "you pulled it off with aplomb!\p"
# 774 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I guess you have your father's blood\n"
# 775 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "in your veins after all!\p"
# 776 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh, yes. As thanks for rescuing me,\n"
# 777 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'd like you to have the Pokémon you\l"
# 778 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "used earlier.\p"
# 779 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the {STR_VAR_1}!$"
# 780 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 781 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon: @ 81FA8B1
# 782 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch: While you're at it, why not\n"
# 783 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "give a nickname to that {STR_VAR_1}?$"
# 784 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 785 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival: @ 81FA8F6
# 786 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch: If you work at Pokémon\n"
# 787 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and gain experience, I think you'll make\l"
# 788 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "an extremely good Trainer.\p"
# 789 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "My kid, {RIVAL}, is also studying\n"
# 790 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Pokémon while helping me out.\p"
# 791 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER}{KUN}, don't you think it might be\n"
# 792 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "a good idea to go see {RIVAL}?$"
# 793 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 794 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou: @ 81FA9D5
# 795 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch: Great!\n"
# 796 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL} should be happy, too.\p"
# 797 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Get {RIVAL} to teach you what it\n"
# 798 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "means to be a Trainer.$"
# 799 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 800 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay: @ 81FAA35
# 801 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch: Oh, don't be that way.\n"
# 802 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You should go meet my kid.$"
# 803 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 804 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome: @ 81FAA74
# 805 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch: {RIVAL}?\n"
# 806 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Gone home, I think.\p"
# 807 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Or maybe that kid's scrabbling around\n"
# 808 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "in tall grass again somewhere…\p"
# 809 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "If you or your Pokémon get tired,\n"
# 810 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "you should get some rest at home.$"
# 811 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 812 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex: @ 81FAB22
# 813 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch: Oh, hi, {PLAYER}{KUN}!\p"
# 814 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I heard you beat {RIVAL} on\n"
# 815 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "your first try. That's excellent!\p"
# 816 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL}'s been helping with my research\n"
# 817 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "for a long time.\p"
# 818 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL} has an extensive history as\n"
# 819 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "a Trainer already.\p"
# 820 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Here, {PLAYER}{KUN}, I ordered this for my\n"
# 821 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "research, but I think you should have\l"
# 822 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "this Pokédex.$"
# 823 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 824 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex: @ 81FAC32
# 825 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the National Pokédex!$"
# 826 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 827 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex: @ 81FAC4B
# 828 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch: The Pokédex is a high-tech\n"
# 829 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "tool that automatically makes a record\l"
# 830 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "of any Pokémon you meet or catch.\p"
# 831 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "My kid, {RIVAL}, goes everywhere\n"
# 832 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "with it.\p"
# 833 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Whenever my kid catches a rare Pokémon\n"
# 834 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and records its data in the Pokédex,\l"
# 835 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "why, {RIVAL} looks for me while I'm out\l"
# 836 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "doing fieldwork, and shows me.$"
# 837 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 838 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait: @ 81FAD6F
# 839 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch: Countless Pokémon\n"
# 840 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "await you!\p"
# 841 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Argh, I'm getting the itch to get out\n"
# 842 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and do fieldwork again!$"
# 843 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 844 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese: @ 81FADD7
# 845 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "May: Oh, wow, {PLAYER}{KUN}!\n"
# 846 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You got a Pokédex, too!\p"
# 847 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Did you know that Nurse Joy\n"
# 848 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "gives you free Poké Balls?$"
# 849 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 850 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls: @ 81FAE40
# 851 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "May: It's fun if you can get a lot of\n"
# 852 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Pokémon!\p"
# 853 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm going to look all over the place\n"
# 854 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "because I want different Pokémon.\p"
# 855 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "If I find any cute Pokémon, I'll catch\n"
# 856 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "them with Poké Balls!$"
# 857 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 858 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull: @ 81FAEF3
# 859 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh? Your Bag's full.$"
# 860 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 861 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext: @ 81FAF08
# 862 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "May: I wonder where I should go look\n"
# 863 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "for Pokémon next?$"
# 864 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 865 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese: @ 81FAF3F
# 866 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Brendan: Huh…\n"
# 867 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So you got a Pokédex, too.\p"
# 868 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Did you know that Nurse Joy\n"
# 869 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "gives you free Poké Balls?$"
# 870 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 871 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls: @ 81FAF8E
# 872 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Brendan: You know it's more fun to\n"
# 873 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "have a whole bunch of Pokémon.\p"
# 874 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm going to explore all over the place\n"
# 875 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "to find different Pokémon.\p"
# 876 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "If I find any cool Pokémon, you bet\n"
# 877 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll try to get them with Poké Balls.$"
# 878 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 879 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull: @ 81FB05D
# 880 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Hey, your Bag's full.$"
# 881 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 882 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext: @ 81FB073
# 883 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Brendan: Where should I look for\n"
# 884 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Pokémon next…$"
# 885 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 886 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine: @ 81FB0A2
# 887 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's a serious-looking machine.\n"
# 888 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The Prof must use this for research.$"
# 889 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 890 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch: @ 81FB0E7
# 891 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's a PC used for research.\n"
# 892 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Better not mess around with it.$"
# 893 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 894 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon: @ 81FB124
# 895 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's crammed with books on Pokémon.$"
# 896 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 897 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead: @ 81FB148
# 898 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's a book that's too hard to read.$"
# 899 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 900 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_OtherDimensionsTakeCosmog:
# 901 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch: Now…\p"
# 902 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER}{KUN} and {RIVAL}, I've had the two\n"
# 903 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "of you help me study Pokémon.\p"
# 904 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Thanks to your help, new facts\n"
# 905 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "are coming to light.\p"
# 906 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It appears that in the Hoenn region,\n"
# 907 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "there are also Pokémon from other\l"
# 908 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "dimensions!\p"
# 909 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So far I've only identified one of\n"
# 910 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "them: Cosmog!\p"
# 911 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It seems to be pretty weak, but maybe\n"
# 912 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "you'll be able to draw out its power.\p"
# 913 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Here, I've got one for each of you.$"
# 914 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 915 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool: @ 81FB30F
# 916 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "May: Eheheh!\p"
# 917 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's so cute! I wonder if it evolves?\n"
# 918 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I guess we'll find out,\n"
# 919 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "eh {PLAYER}{KUN}?$"
# 920 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 921 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe: @ 81FB38E
# 922 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Brendan: Huh, so it's like a space…\n"
# 923 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "cloud… Magikarp…?\p"
# 924 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Guess we'll see what it can do,\n"
# 925 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "huh, {PLAYER}?$"
# 926 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 927 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2: @ 81FB466
# 928 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch: But listen.\n"
# 929 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You've become the Champion,\l"
# 930 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "but your Pokémon journey isn't over.\p"
# 931 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "There is no end to the road\n"
# 932 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "that is Pokémon.\p"
# 933 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Somewhere, there is a grassy patch\n"
# 934 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "that's waiting for you!$"
# 935 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 936 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayGoRoute103: @ 81FB528
# 937 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "May: I'm going to Route 103 to do some\n"
# 938 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "fieldwork for a while.\p"
# 939 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll see you out there, {PLAYER}{KUN}!$"
# 940 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 941 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanGoRoute103: @ 81FB58A
# 942 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Brendan: Right, I'm headed out to\n"
# 943 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Route 103 for a while.\p"
# 944 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Maybe I'll see you there, {PLAYER}?$"
# 945 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 946 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon: @ 81FB5F9
# 947 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch: Oh, {PLAYER}{KUN}!\n"
# 948 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Let's have a look at your Pokédex.\p"
# 949 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\n"
# 950 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\p"
# 951 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Yes, there's no doubt about it.\p"
# 952 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You really have completed the Hoenn\n"
# 953 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "region's Pokédex.\p"
# 954 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "That's more than just impressive.\p"
# 955 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I have a gift for you.\p"
# 956 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Consider it my show of appreciation\n"
# 957 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "for the fantastic work you've done.\p"
# 958 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "My gift is a rare Pokémon only found\n"
# 959 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "in another region!\p"
# 960 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You can have any one of these\n"
# 961 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "three Pokémon!$"
# 962 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 963 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon: @ 81FB787
# 964 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch: These are rare Pokémon\n"
# 965 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "only found in another region!\p"
# 966 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You can have any one of these\n"
# 967 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "three Pokémon!$"
# 968 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 969 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil: @ 81FB7F6
# 970 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch: The FIRE Pokémon\n"
# 971 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "CYNDAQUIL caught your eye!\p"
# 972 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You're as sharp as ever!\p"
# 973 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So the CYNDAQUIL is your choice?$"
# 974 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 975 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile: @ 81FB869
# 976 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch: The WATER Pokémon\n"
# 977 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "TOTODILE is your choice!\p"
# 978 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You know how to pick a good one.\p"
# 979 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So, you'll take the TOTODILE?$"
# 980 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 981 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita: @ 81FB8E0
# 982 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch: The GRASS Pokémon\n"
# 983 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "CHIKORITA is your choice!\p"
# 984 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You sure know what you're doing.\p"
# 985 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So, you'll take the CHIKORITA?$"
# 986 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 987 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable: @ 81FB959
# 988 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch: Take your time before\n"
# 989 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "you decide.\p"
# 990 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "They're all invaluable Pokémon.$"
# 991 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 992 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_ReceivedCosmog:
# 993 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received two Cosmogs\n"
# 994 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "from Prof. Birch!$"
# 995 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 996 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter: @ 81FB9D7
# 997 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the {STR_VAR_1}\n"
# 998 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "from Prof. Birch!$"
# 999 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1000 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ Unused
# 1001 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_NicknameJohtoStarter: @ 81FB9FC
# 1002 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Want to give a nickname to\n"
# 1003 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the {STR_VAR_1} you received?$"
# 1004 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1005 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting: @ 81FBA2C
# 1006 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Prof. Birch: Listen, {PLAYER}{KUN}.\n"
# 1007 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You've completed the Hoenn Pokédex,\l"
# 1008 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "but your Pokémon journey isn't over.\p"
# 1009 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "There is no end to the road\n"
# 1010 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "that is Pokémon.\p"
# 1011 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Somewhere, there is a grassy patch\n"
# 1012 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "that's waiting for you!$"
# 1013 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1014 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone: @ 81FBAF8
# 1015 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You received the promised Pokémon.\n"
# 1016 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Better leave the others alone.$"
# 1017 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1018 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ Unused
# 1019 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_DontHaveAnyRoomForPokemon: @ 81FBB3A
# 1020 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh, you don't have any room for\n"
# 1021 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "this Pokémon.$"
# 1022 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1023 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere: @ 81FBB68
# 1024 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "May: {PLAYER}{KUN}, after this…\n"
# 1025 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "What are you going to do?\p"
# 1026 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Are you going to keep battling\n"
# 1027 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and sharpening your skills?\p"
# 1028 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Or are you going to try filling\n"
# 1029 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the National Pokédex?\p"
# 1030 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm staying here to help the Prof.$"
# 1031 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1032 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly: @ 81FBC2D
# 1033 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Brendan: Rather than collecting\n"
# 1034 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Pokémon, I prefer slowly and \l"
# 1035 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "steadily raising the one I chose.$"
# 1036 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1037 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier: @ 81FBC8D
# 1038 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "May: Oh, hi, {PLAYER}{KUN}!\n"
# 1039 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Have you gone to that place,\l"
# 1040 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the Battle Frontier?$"
# 1041 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1042 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier: @ 81FBCD2
# 1043 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Brendan: Hey, {PLAYER}!\n"
# 1044 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Have you gone out to that place,\l"
# 1045 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the Battle Frontier?$"
# 1046 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1047 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall: @ 81FBD1A
# 1048 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\n"
# 1049 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … Beep!\p"
# 1050 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Scott: Hi, hi, {PLAYER}!\n"
# 1051 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's me, Scott.\p"
# 1052 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm aboard the S.S. Tidal now.\n"
# 1053 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It feels great to be on the sea!\p"
# 1054 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "By the way…\p"
# 1055 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "There's this place that I'd like to\n"
# 1056 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "invite you to for a visit.\p"
# 1057 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "If you're interested, board a ferry\n"
# 1058 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "at either Slateport or Lilycove.\p"
# 1059 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll fill you in on the details when\n"
# 1060 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "we meet. I'll be waiting!\p"
# 1061 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\n"
# 1062 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … Click!$"
