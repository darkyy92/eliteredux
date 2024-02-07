# 1 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 2 "data/maps/LilycoveCity_Harbor/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/LilycoveCity_Harbor/scripts.pory"
.set LOCALID_SS_TIDAL, 2
# 4 "data/maps/LilycoveCity_Harbor/scripts.pory"
.set LOCALID_FERRY_SAILOR, 4
# 5 "data/maps/LilycoveCity_Harbor/scripts.pory"
.set LOCALID_BRINEY, 5
# 6 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 7 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_MapScripts:: @ 821E000
# 8 "data/maps/LilycoveCity_Harbor/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_Harbor_OnTransition
# 9 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.byte 0
# 10 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 11 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_OnTransition: @ 821E006
# 12 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setescapewarp MAP_LILYCOVE_CITY, 255, 12, 33
# 13 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 14 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 15 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_FerryAttendant:: @ 821E00F
# 16 "data/maps/LilycoveCity_Harbor/scripts.pory"
	lock
# 17 "data/maps/LilycoveCity_Harbor/scripts.pory"
	faceplayer
# 18 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, LilycoveCity_Harbor_EventScript_FerryUnavailable
# 19 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetEonTicketState
# 20 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetAuroraTicketState
# 21 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetOldSeaMapState
# 22 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetMysticTicketState
# 23 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetFirstTimeShowingTicket
# 24 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetHasTicketsState
# 25 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_TEMP_C, 2
# 26 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq LilycoveCity_Harbor_EventScript_OldSeaMapFirstTime
# 27 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_TEMP_B, 1
# 28 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq LilycoveCity_Harbor_EventScript_EonTicketFirstTime
# 29 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_TEMP_B, 2
# 30 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq LilycoveCity_Harbor_EventScript_AuroraTicketFirstTime
# 31 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_TEMP_B, 4
# 32 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq LilycoveCity_Harbor_EventScript_OldSeaMapFirstTime
# 33 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_TEMP_B, 8 
# 34 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq LilycoveCity_Harbor_EventScript_MysticTicketFirstTime
# 35 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_TEMP_B, 0
# 36 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_ne LilycoveCity_Harbor_EventScript_MultipleEventTicketsFirstTime
# 37 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_NoFirstTimeEventTickets
# 38 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 39 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 40 "data/maps/LilycoveCity_Harbor/scripts.pory"
@ First goto_if_eq is unnecessary; identical scripts
# 41 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_NoFirstTimeEventTickets:: @ 821E080
# 42 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_TEMP_A, 0
# 43 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq LilycoveCity_Harbor_EventScript_NoEventTickets
# 44 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
# 45 "data/maps/LilycoveCity_Harbor/scripts.pory"
	message LilycoveCity_Harbor_Text_FlashTicketWhereTo
# 46 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmessage
# 47 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
# 48 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 49 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 50 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect:: @ 821E09F
# 51 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_0x8004, 0
# 52 "data/maps/LilycoveCity_Harbor/scripts.pory"
	special ScriptMenu_CreateLilycoveSSTidalMultichoice
# 53 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 54 "data/maps/LilycoveCity_Harbor/scripts.pory"
	special GetLilycoveSSTidalSelection
# 55 "data/maps/LilycoveCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 56 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 0, LilycoveCity_Harbor_EventScript_GoToSlateport
# 57 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 1, LilycoveCity_Harbor_EventScript_GoToBattleFrontierTemp
# 58 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 2, LilycoveCity_Harbor_EventScript_GoToSouthernIsland
# 59 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 3, LilycoveCity_Harbor_EventScript_GoToNavelRock
# 60 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 4, LilycoveCity_Harbor_EventScript_GoToBirthIsland
# 61 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 5, LilycoveCity_Harbor_EventScript_GoToFarawayIsland
# 62 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 6, LilycoveCity_Harbor_EventScript_ExitSailSelect
# 63 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_Harbor_EventScript_ExitSailSelect
# 64 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 65 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 66 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToSouthernIsland:: @ 821E109
# 67 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 68 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 255, 13, 22
# 69 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 70 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 71 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 72 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 73 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToNavelRock:: @ 821E119
# 74 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 75 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_NAVEL_ROCK_HARBOR, 255, 8, 4
# 76 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 77 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 78 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 79 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 80 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToBirthIsland:: @ 821E129
# 81 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 82 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_BIRTH_ISLAND_HARBOR, 255, 8, 4
# 83 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 84 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 85 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 86 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 87 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToFarawayIsland:: @ 821E139
# 88 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 89 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 255, 13, 38
# 90 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 91 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 92 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 93 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 94 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToSlateport:: @ 821E149
# 95 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SlateportItIs, MSGBOX_YESNO
# 96 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_RESULT, NO
# 97 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
# 98 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE
# 99 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 100 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_SS_TIDAL_CORRIDOR, 255, 1, 10
# 101 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 102 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 103 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 104 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 105 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToBattleFrontierTemp::
# 106 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_BattleFrontierProjectHasStarted, MSGBOX_DEFAULT
# 107 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 108 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 109 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 110 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToBattleFrontier:: @ 821E171
# 111 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
# 112 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_RESULT, NO
# 113 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
# 114 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 115 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 255, 19, 67
# 116 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 117 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 118 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 119 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 120 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetEonTicketState:: @ 821E194
# 121 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_E, 0
# 122 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, Common_EventScript_NopReturn
# 123 "data/maps/LilycoveCity_Harbor/scripts.pory"
	checkitem ITEM_EON_TICKET, 1
# 124 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_RESULT, FALSE
# 125 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq Common_EventScript_NopReturn
# 126 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_E, 1
# 127 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_SHOWN_EON_TICKET, Common_EventScript_NopReturn
# 128 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_E, 2
# 129 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 130 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 131 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetAuroraTicketState:: @ 821E1C6
# 132 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_D, 0
# 133 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, Common_EventScript_NopReturn
# 134 "data/maps/LilycoveCity_Harbor/scripts.pory"
	checkitem ITEM_AURORA_TICKET, 1
# 135 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_RESULT, FALSE
# 136 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq Common_EventScript_NopReturn
# 137 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_D, 1
# 138 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_SHOWN_AURORA_TICKET, Common_EventScript_NopReturn
# 139 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_D, 2
# 140 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 141 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 142 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetOldSeaMapState:: @ 821E1F8
# 143 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_C, 0
# 144 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_FARAWAY_ISLAND, Common_EventScript_NopReturn
# 145 "data/maps/LilycoveCity_Harbor/scripts.pory"
	checkitem ITEM_OLD_SEA_MAP, 1
# 146 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_RESULT, FALSE
# 147 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq Common_EventScript_NopReturn
# 148 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_C, 1
# 149 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_SHOWN_OLD_SEA_MAP, Common_EventScript_NopReturn
# 150 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_C, 2
# 151 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 152 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 153 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetMysticTicketState:: @ 821E22A
# 154 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_9, 0
# 155 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, Common_EventScript_NopReturn
# 156 "data/maps/LilycoveCity_Harbor/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET, 1
# 157 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_RESULT, FALSE
# 158 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq Common_EventScript_NopReturn
# 159 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_9, 1
# 160 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_SHOWN_MYSTIC_TICKET, Common_EventScript_NopReturn
# 161 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_9, 2
# 162 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 163 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 164 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetFirstTimeShowingTicket:: @ 821E25C
# 165 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_B, 0
# 166 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_TEMP_E, 2
# 167 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_SetFirstTimeShowingEonTicket
# 168 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_TEMP_D, 2
# 169 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_SetFirstTimeShowingAuroraTicket
# 170 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_TEMP_C, 2
# 171 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_SetFirstTimeShowingOldSeaMap
# 172 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_TEMP_9, 2
# 173 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_SetFirstTimeShowingMysticTicket
# 174 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 175 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 176 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetFirstTimeShowingEonTicket:: @ 821E28E
# 177 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_B, 1
# 178 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 179 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 180 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetFirstTimeShowingAuroraTicket:: @ 821E294
# 181 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_B, 2
# 182 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 183 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 184 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetFirstTimeShowingOldSeaMap:: @ 821E29A
# 185 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_B, 4
# 186 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 187 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 188 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetFirstTimeShowingMysticTicket:: @ 821E2A0
# 189 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_B, 8
# 190 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 191 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 192 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetHasTicketsState:: @ 821E2A6
# 193 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_TEMP_A, 0
# 194 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_TEMP_E, 1
# 195 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_SetHasEonTicket
# 196 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_TEMP_D, 1
# 197 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_SetHasAuroraTicket
# 198 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_TEMP_C, 1
# 199 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_SetHasOldSeaMap
# 200 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_TEMP_9, 1
# 201 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_SetHasMysticTicket
# 202 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 203 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 204 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetHasEonTicket:: @ 821E2D8
# 205 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_A, 1
# 206 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 207 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 208 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetHasAuroraTicket:: @ 821E2DE
# 209 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_A, 2
# 210 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 211 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 212 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetHasOldSeaMap:: @ 821E2E4
# 213 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_A, 4
# 214 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 215 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 216 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SetHasMysticTicket:: @ 821E2EA
# 217 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addvar VAR_TEMP_A, 8
# 218 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 219 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 220 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_EonTicketFirstTime:: @ 821E2F0
# 221 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setflag FLAG_SHOWN_EON_TICKET
# 222 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
# 223 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 224 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
# 225 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ShowEonTicket, MSGBOX_DEFAULT
# 226 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime
# 227 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 228 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 229 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime:: @ 821E30F
# 230 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 231 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
# 232 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 255, 13, 22
# 233 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 234 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 235 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 236 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 237 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_AuroraTicketFirstTime:: @ 821E320
# 238 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setflag FLAG_SHOWN_AURORA_TICKET
# 239 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
# 240 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 241 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
# 242 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_OddTicketGetOnBoard, MSGBOX_DEFAULT
# 243 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime
# 244 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 245 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 246 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime:: @ 821E33F
# 247 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 248 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
# 249 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_BIRTH_ISLAND_HARBOR, 255, 8, 4
# 250 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 251 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 252 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 253 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 254 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_OldSeaMapFirstTime:: @ 821E350
# 255 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setflag FLAG_SHOWN_OLD_SEA_MAP
# 256 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ShowOldSeaMap, MSGBOX_DEFAULT
# 257 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 258 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
# 259 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_OldSeaMapTooFar, MSGBOX_DEFAULT
# 260 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 261 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFastestUp
# 262 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 263 "data/maps/LilycoveCity_Harbor/scripts.pory"
	playse SE_PIN
# 264 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_ExclamationMark
# 265 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 266 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_Delay48
# 267 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 268 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 269 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayNorth
# 270 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 271 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayEast
# 272 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addobject LOCALID_BRINEY
# 273 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 274 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_BrineyFaceSailorNorth
# 275 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 276 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_BrineyFaceSailorEast
# 277 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_BrineyHoldOnASecond, MSGBOX_DEFAULT
# 278 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 279 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_BrineyFacePlayerNorth
# 280 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 281 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_BrineyFacePlayerEast
# 282 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_BrineyLetsSail, MSGBOX_DEFAULT
# 283 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 284 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 285 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorNorth
# 286 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 287 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorEast
# 288 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_SS_TIDAL
# 289 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call Common_EventScript_FerryDepart
# 290 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 255, 13, 38
# 291 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 292 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 293 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 294 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 295 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToFarawayIslandFirstTime:: @ 821E40C
# 296 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 297 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
# 298 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 255, 13, 38
# 299 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 300 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 301 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 302 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 303 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_MysticTicketFirstTime:: @ 821E41D
# 304 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setflag FLAG_SHOWN_MYSTIC_TICKET
# 305 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
# 306 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 307 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
# 308 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_OddTicketGetOnBoard, MSGBOX_DEFAULT
# 309 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime
# 310 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 311 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 312 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime:: @ 821E43C
# 313 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 314 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
# 315 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_NAVEL_ROCK_HARBOR, 255, 8, 4
# 316 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 317 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 318 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 319 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 320 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_MultipleEventTicketsFirstTime:: @ 821E44D
# 321 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
# 322 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 323 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
# 324 "data/maps/LilycoveCity_Harbor/scripts.pory"
	message EventTicket_Text_OddTicketsWhereTo
# 325 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmessage
# 326 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_0x8004, 1
# 327 "data/maps/LilycoveCity_Harbor/scripts.pory"
	special ScriptMenu_CreateLilycoveSSTidalMultichoice
# 328 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 329 "data/maps/LilycoveCity_Harbor/scripts.pory"
	special GetLilycoveSSTidalSelection
# 330 "data/maps/LilycoveCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 331 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 2, LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime
# 332 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 3, LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime
# 333 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 4, LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime
# 334 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 5, LilycoveCity_Harbor_EventScript_GoToFarawayIslandFirstTime
# 335 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case 6, LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect
# 336 "data/maps/LilycoveCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect
# 337 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 338 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 339 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 340 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect:: @ 821E4B6
# 341 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
# 342 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 343 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFastestUp
# 344 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 345 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 346 "data/maps/LilycoveCity_Harbor/scripts.pory"
	removeobject LOCALID_FERRY_SAILOR
# 347 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 348 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFastestDown
# 349 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 350 "data/maps/LilycoveCity_Harbor/scripts.pory"
	showobjectat LOCALID_ATTENDANT, MAP_LILYCOVE_CITY_HARBOR
# 351 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 352 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
# 353 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 354 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 355 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 356 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GetEventTicketSailor:: @ 821E4EE
# 357 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestUp
# 358 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 359 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 360 "data/maps/LilycoveCity_Harbor/scripts.pory"
	hideobjectat VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
# 361 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 60
# 362 "data/maps/LilycoveCity_Harbor/scripts.pory"
	addobject LOCALID_FERRY_SAILOR
# 363 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 364 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_FacePlayer
# 365 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 366 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 367 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 368 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BoardFerryWithSailor:: @ 821E514
# 369 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFastestUp
# 370 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 371 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 372 "data/maps/LilycoveCity_Harbor/scripts.pory"
	removeobject LOCALID_FERRY_SAILOR
# 373 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 374 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth
# 375 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 376 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast
# 377 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 378 "data/maps/LilycoveCity_Harbor/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 379 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_SS_TIDAL
# 380 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call Common_EventScript_FerryDepart
# 381 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 382 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 383 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_FerryUnavailable:: @ 821E54D
# 384 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_FerryUnavailable, MSGBOX_DEFAULT
# 385 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 386 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 387 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 388 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_NoEventTickets:: @ 821E557
# 389 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
# 390 "data/maps/LilycoveCity_Harbor/scripts.pory"
	message LilycoveCity_Harbor_Text_FlashTicketWhereTo
# 391 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmessage
# 392 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
# 393 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 394 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 395 "data/maps/LilycoveCity_Harbor/scripts.pory"
@ Unused
# 396 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_NoTicket:: @ 821E56B
# 397 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_NoTicket, MSGBOX_DEFAULT
# 398 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 399 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 400 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 401 "data/maps/LilycoveCity_Harbor/scripts.pory"
@ Unused
# 402 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToSlateportUnused:: @ 821E575
# 403 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SlateportItIs, MSGBOX_YESNO
# 404 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_RESULT, NO
# 405 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
# 406 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE
# 407 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 408 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_SS_TIDAL_CORRIDOR, 255, 1, 10
# 409 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 410 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 411 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 412 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 413 "data/maps/LilycoveCity_Harbor/scripts.pory"
@ Unused
# 414 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_GoToBattleFrontierUnused:: @ 821E59D
# 415 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
# 416 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_RESULT, NO
# 417 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_eq LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
# 418 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 419 "data/maps/LilycoveCity_Harbor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 255, 19, 67
# 420 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitstate
# 421 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 422 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 423 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 424 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind:: @ 821E5C0
# 425 "data/maps/LilycoveCity_Harbor/scripts.pory"
	message LilycoveCity_Harbor_Text_WhereWouldYouLikeToGo
# 426 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmessage
# 427 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
# 428 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 429 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 430 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BoardFerry:: @ 821E5CC
# 431 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_PleaseBoard, MSGBOX_DEFAULT
# 432 "data/maps/LilycoveCity_Harbor/scripts.pory"
	closemessage
# 433 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestUp
# 434 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 435 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 436 "data/maps/LilycoveCity_Harbor/scripts.pory"
	hideobjectat VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
# 437 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 438 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth
# 439 "data/maps/LilycoveCity_Harbor/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 440 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast
# 441 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay 30
# 442 "data/maps/LilycoveCity_Harbor/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 443 "data/maps/LilycoveCity_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_SS_TIDAL
# 444 "data/maps/LilycoveCity_Harbor/scripts.pory"
	call Common_EventScript_FerryDepart
# 445 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 446 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 447 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast:: @ 821E610
# 448 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardFerryEast
# 449 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 450 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 451 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 452 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth:: @ 821E61B
# 453 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardFerryNorth
# 454 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 455 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 456 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 457 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_ExitSailSelect:: @ 821E626
# 458 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
# 459 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 460 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 461 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 462 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_PlayerBoardFerryEast: @ 821E630
# 463 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_right
# 464 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_in_place_fastest_up
# 465 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 466 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 467 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_PlayerBoardFerryNorth: @ 821E633
# 468 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_up
# 469 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 470 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 471 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_UnusedBoardFerry: @ 821E635
# 472 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_up
# 473 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 474 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 475 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_Sailor:: @ 821E637
# 476 "data/maps/LilycoveCity_Harbor/scripts.pory"
	lock
# 477 "data/maps/LilycoveCity_Harbor/scripts.pory"
	faceplayer
# 478 "data/maps/LilycoveCity_Harbor/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_Harbor_EventScript_SailorFerryAvailable
# 479 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SailorFerryUnavailable, MSGBOX_DEFAULT
# 480 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 481 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 482 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 483 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_SailorFerryAvailable:: @ 821E64C
# 484 "data/maps/LilycoveCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SailorFerryAvailable, MSGBOX_DEFAULT
# 485 "data/maps/LilycoveCity_Harbor/scripts.pory"
	release
# 486 "data/maps/LilycoveCity_Harbor/scripts.pory"
	end
# 487 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 488 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayNorth:: @ 821E656
# 489 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorOutOfWayNorth
# 490 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 491 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 492 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 493 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayEast:: @ 821E661
# 494 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorOutOfWayEast
# 495 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 496 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 497 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 498 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_SailorOutOfWayNorth: @ 821E66C
# 499 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_in_place_fastest_right
# 500 "data/maps/LilycoveCity_Harbor/scripts.pory"
	lock_facing_direction
# 501 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_left
# 502 "data/maps/LilycoveCity_Harbor/scripts.pory"
	unlock_facing_direction
# 503 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 504 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 505 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_SailorOutOfWayEast: @ 821E671
# 506 "data/maps/LilycoveCity_Harbor/scripts.pory"
	lock_facing_direction
# 507 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_down
# 508 "data/maps/LilycoveCity_Harbor/scripts.pory"
	unlock_facing_direction
# 509 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 510 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 511 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BrineyFaceSailorNorth:: @ 821E675
# 512 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFastestLeft
# 513 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 514 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 515 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 516 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BrineyFaceSailorEast:: @ 821E680
# 517 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFastestDown
# 518 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 519 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 520 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 521 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BrineyFacePlayerNorth:: @ 821E68B
# 522 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFastestDown
# 523 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 524 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 525 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 526 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BrineyFacePlayerEast:: @ 821E696
# 527 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFastestLeft
# 528 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 529 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 530 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 531 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorNorth:: @ 821E6A1
# 532 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_BRINEY, LilycoveCity_Harbor_Movement_BrineyBoardFerry
# 533 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyNorth
# 534 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorBoardWithBrineyNorth
# 535 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 536 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 537 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 538 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorEast:: @ 821E6BA
# 539 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_BRINEY, LilycoveCity_Harbor_Movement_BrineyBoardFerry
# 540 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyEast
# 541 "data/maps/LilycoveCity_Harbor/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorBoardWithBrineyEast
# 542 "data/maps/LilycoveCity_Harbor/scripts.pory"
	waitmovement 0
# 543 "data/maps/LilycoveCity_Harbor/scripts.pory"
	return
# 544 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 545 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_BrineyBoardFerry: @ 821E6D3
# 546 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_in_place_fastest_up
# 547 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_8
# 548 "data/maps/LilycoveCity_Harbor/scripts.pory"
	set_invisible
# 549 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 550 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 551 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyNorth: @ 821E6D7
# 552 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 553 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_up
# 554 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 555 "data/maps/LilycoveCity_Harbor/scripts.pory"
	set_invisible
# 556 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 557 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 558 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_SailorBoardWithBrineyNorth: @ 821E6DC
# 559 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 560 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 561 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 562 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_right
# 563 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_in_place_fastest_up
# 564 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 565 "data/maps/LilycoveCity_Harbor/scripts.pory"
	set_invisible
# 566 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 567 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 568 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyEast: @ 821E6E4
# 569 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 570 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_right
# 571 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_in_place_fastest_up
# 572 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 573 "data/maps/LilycoveCity_Harbor/scripts.pory"
	set_invisible
# 574 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 575 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 576 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Movement_SailorBoardWithBrineyEast: @ 821E6EA
# 577 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 578 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 579 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 580 "data/maps/LilycoveCity_Harbor/scripts.pory"
	walk_up
# 581 "data/maps/LilycoveCity_Harbor/scripts.pory"
	delay_16
# 582 "data/maps/LilycoveCity_Harbor/scripts.pory"
	set_invisible
# 583 "data/maps/LilycoveCity_Harbor/scripts.pory"
	step_end
# 584 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 585 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_FerryUnavailable: @ 821E6F1
# 586 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "I beg your pardon?\n"
# 587 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "You're looking for a ship?\p"
# 588 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "I'm sorry, the ferry service isn't\n"
# 589 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "available at present…$"
# 590 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 591 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_MayISeeYourTicket: @ 821E758
# 592 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Hello, are you here for the ferry?\n"
# 593 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "May I see your Ticket?$"
# 594 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 595 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_NoTicket: @ 821E792
# 596 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "{PLAYER} doesn't have the Ticket\p"
# 597 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "I'm terribly sorry.\p"
# 598 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "You must have a Ticket to board\n"
# 599 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "the ferry.$"
# 600 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 601 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_FlashTicketWhereTo: @ 821E7ED
# 602 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "{PLAYER} flashed the Ticket.\p"
# 603 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Perfect! That's all you need!\p"
# 604 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "And where would you like to go?$"
# 605 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 606 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_SailAnotherTime: @ 821E842
# 607 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Please sail with us another time!$"
# 608 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 609 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_SlateportItIs: @ 821E864
# 610 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Slateport City it is, then!$"
# 611 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 612 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_BattleFrontierItIs: @ 821E880
# 613 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Battle Frontier it is, then!$"
# 614 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 615 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_PleaseBoard: @ 821E89D
# 616 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Please board the ferry and wait for\n"
# 617 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "departure.$"
# 618 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 619 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_WhereWouldYouLikeToGo: @ 821E8CC
# 620 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Then, where would you like to go?$"
# 621 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 622 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_SailorFerryUnavailable: @ 821E8EE
# 623 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Until they finish making the ferry,\n"
# 624 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "we sailors have nothing to do…\p"
# 625 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "I wish they'd get a move on, the folks\n"
# 626 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "at the Shipyard in Slateport.$"
# 627 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 628 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_SailorFerryAvailable: @ 821E976
# 629 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "The ferry S.S. Tidal is finally in\n"
# 630 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "operation.\p"
# 631 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "The folks at the Shipyard in Slateport\n"
# 632 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "must've worked extra hard.\p"
# 633 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Well, it's my turn to get busy now!$"
# 634 "data/maps/LilycoveCity_Harbor/scripts.pory"

# 635 "data/maps/LilycoveCity_Harbor/scripts.pory"
LilycoveCity_Harbor_Text_BattleFrontierProjectHasStarted:
# 636 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "The Battle Frontier Project has\n"
# 637 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "started!\p"
# 638 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Seriously though, it's not ready yet.\l"
# 639 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Parts of it are broken and it needs a\n"
# 640 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "complete overhaul to include all the\l"
# 641 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "new Pokémon and mechanics.\p"
# 642 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "Please come back in a later version\n"
# 643 "data/maps/LilycoveCity_Harbor/scripts.pory"
	.string "of the hack.$"
