# 1 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 2 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
.set LOCALID_STEVEN, 1
# 3 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
.set LOCALID_MELTAN_BALL, 2
# 4 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 5 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_MapScripts:: @ 8222784
# 6 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_StevensHouse_OnLoad
# 7 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_StevensHouse_OnTransition
# 8 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_StevensHouse_OnFrame
# 9 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.byte 0
# 10 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 11 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_OnLoad: @ 8222794
# 12 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call_if_unset FLAG_SYS_GAME_CLEAR, MossdeepCity_StevensHouse_EventScript_HideStevensNote
# 13 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 14 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 15 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_HideStevensNote:: @ 822279E
# 16 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setmetatile 6, 4, METATILE_GenericBuilding_TableEdge, 1
# 17 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	return
# 18 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 19 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_OnTransition: @ 82227A8
# 20 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	compare VAR_STEVENS_HOUSE_STATE, 2
# 21 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call_if_eq MossdeepCity_StevensHouse_EventScript_SetStevenPos
# 22 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 23 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 24 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_SetStevenPos:: @ 82227B4
# 25 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setobjectxyperm LOCALID_STEVEN, 6, 5
# 26 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setobjectmovementtype LOCALID_STEVEN, MOVEMENT_TYPE_FACE_UP
# 27 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	return
# 28 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 29 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_OnFrame: @ 82227C0
# 30 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	map_script_2 VAR_STEVENS_HOUSE_STATE, 1, MossdeepCity_StevensHouse_EventScript_StevenGivesDive
# 31 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.2byte 0
# 32 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 33 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_StevenGivesDive:: @ 82227CA
# 34 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	lockall
# 35 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFastestLeft
# 36 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitmovement 0
# 37 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	playse SE_PIN
# 38 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
# 39 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitmovement 0
# 40 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
# 41 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitmovement 0
# 42 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	applymovement LOCALID_STEVEN, MossdeepCity_StevensHouse_Movement_StevenApproachPlayer
# 43 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitmovement 0
# 44 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_YouveEarnedHMDive, MSGBOX_DEFAULT
# 45 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	giveitem ITEM_HM08_DIVE
# 46 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_RECEIVED_HM08
# 47 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_OMIT_DIVE_FROM_STEVEN_LETTER
# 48 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_ExplainDive, MSGBOX_DEFAULT
# 49 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	closemessage
# 50 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	delay 20
# 51 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	applymovement LOCALID_STEVEN, MossdeepCity_StevensHouse_Movement_StevenReturn
# 52 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitmovement 0
# 53 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
# 54 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
# 55 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setvar VAR_STEVENS_HOUSE_STATE, 2
# 56 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	releaseall
# 57 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 58 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 59 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Movement_StevenApproachPlayer: @ 8222833
# 60 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_left
# 61 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_left
# 62 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_left
# 63 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_left
# 64 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_left
# 65 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_left
# 66 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_in_place_fastest_down
# 67 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	step_end
# 68 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 69 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Movement_StevenReturn: @ 822283B
# 70 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_up
# 71 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_right
# 72 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_right
# 73 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_right
# 74 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	walk_in_place_fastest_up
# 75 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	step_end
# 76 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 77 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_MeltanPokeball:: @ 8222841
# 78 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	lockall
# 79 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_TakeBallContainingMeltan, MSGBOX_YESNO
# 80 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	compare VAR_RESULT, NO
# 81 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto_if_eq MossdeepCity_StevensHouse_EventScript_LeaveMeltan
# 82 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto MossdeepCity_StevensHouse_EventScript_GiveMeltan
# 83 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 84 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 85 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_LeaveMeltan:: @ 822285B
# 86 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas, MSGBOX_DEFAULT
# 87 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	releaseall
# 88 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 89 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 90 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_GiveMeltan:: @ 8222865
# 91 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_MELTAN
# 92 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	givemon SPECIES_MELTAN, 5, ITEM_NONE
# 93 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	compare VAR_RESULT, 0
# 94 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto_if_eq MossdeepCity_StevensHouse_EventScript_SendMeltanParty
# 95 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	compare VAR_RESULT, 1
# 96 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto_if_eq MossdeepCity_StevensHouse_EventScript_SendMeltanPC
# 97 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 98 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 99 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 100 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_SendMeltanParty:: @ 8222895
# 101 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call MossdeepCity_StevensHouse_EventScript_ReceivedMeltanFanfare
# 102 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 103 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	compare VAR_RESULT, NO
# 104 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto_if_eq MossdeepCity_StevensHouse_EventScript_ReceivedMeltan
# 105 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 106 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 107 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto MossdeepCity_StevensHouse_EventScript_ReceivedMeltan
# 108 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 109 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 110 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_SendMeltanPC:: @ 82228BD
# 111 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call MossdeepCity_StevensHouse_EventScript_ReceivedMeltanFanfare
# 112 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 113 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	compare VAR_RESULT, NO
# 114 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto_if_eq MossdeepCity_StevensHouse_EventScript_MeltanTransferredToPC
# 115 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 116 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto MossdeepCity_StevensHouse_EventScript_MeltanTransferredToPC
# 117 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 118 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 119 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_MeltanTransferredToPC:: @ 82228E0
# 120 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	call Common_EventScript_TransferredToPC
# 121 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	goto MossdeepCity_StevensHouse_EventScript_ReceivedMeltan
# 122 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 123 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 124 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_ReceivedMeltanFanfare:: @ 82228EB
# 125 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	bufferspeciesname 1, SPECIES_MELTAN
# 126 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	removeobject LOCALID_MELTAN_BALL
# 127 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 128 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	message MossdeepCity_StevensHouse_Text_ObtainedMeltan
# 129 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitmessage
# 130 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	waitfanfare
# 131 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	bufferspeciesname 0, SPECIES_MELTAN
# 132 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	return
# 133 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 134 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_ReceivedMeltan:: @ 8222901
# 135 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_MELTAN_POKEBALL
# 136 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_RECEIVED_MELTAN
# 137 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	releaseall
# 138 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 139 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 140 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_RockDisplay:: @ 8222909
# 141 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_CollectionOfRareRocks, MSGBOX_SIGN
# 142 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 143 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 144 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_Steven:: @ 8222912
# 145 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis, MSGBOX_NPC
# 146 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 147 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 148 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_Letter:: @ 822291B
# 149 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	lockall
# 150 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_LetterFromSteven, MSGBOX_DEFAULT
# 151 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	releaseall
# 152 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 153 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 154 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
@ Unused, leftover from RS
# 155 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_EventScript_DiveItemBall:: @ 8222926
# 156 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	finditem ITEM_HM08_DIVE
# 157 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	setflag FLAG_RECEIVED_HM08
# 158 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	end
# 159 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 160 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_YouveEarnedHMDive: @ 8222936
# 161 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Steven: {PLAYER}{KUN}…\p"
# 162 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "As you can see, there's not much here,\n"
# 163 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "but this is my home.\p"
# 164 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Thank you for all that you've done.\p"
# 165 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "This is my token of appreciation.\n"
# 166 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "It's the Hidden Machine Dive.\p"
# 167 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "No need to be shy--you've earned\n"
# 168 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "this HM.$"
# 169 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 170 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_ExplainDive: @ 8222A0E
# 171 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Steven: While you're using Surf, you\n"
# 172 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "should notice dark patches of water.\p"
# 173 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Use Dive if you come to deep water\n"
# 174 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "like it. You'll drop to the seafloor.\p"
# 175 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "When you want to come back up, use\n"
# 176 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Dive again.\p"
# 177 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "In some places, it won't be possible\n"
# 178 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "for you to surface, though.$"
# 179 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 180 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis: @ 8222B11
# 181 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Steven: Apparently, there's an\n"
# 182 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "underwater cavern between\l"
# 183 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Mossdeep and Sootopolis.\p"
# 184 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "You know, the one that Capt. Stern\n"
# 185 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "found in his submarine.$"
# 186 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 187 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_TakeBallContainingMeltan: @ 8222B9E
# 188 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "{PLAYER} checked the Poké Ball.\p"
# 189 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "It contained the Pokémon\n"
# 190 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Meltan.\p"
# 191 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Take the Poké Ball?$"
# 192 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 193 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_ObtainedMeltan: @ 8222BED
# 194 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "{PLAYER} obtained a Meltan.$"
# 195 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 196 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
@ Unused
# 197 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_NoSpaceForAnotherMon: @ 8222C03
# 198 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "There is no space for another Pokémon.$"
# 199 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 200 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas: @ 8222C2A
# 201 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "{PLAYER} left the Poké Ball where\n"
# 202 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "it was.$"
# 203 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 204 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_LetterFromSteven: @ 8222C4E
# 205 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "It's a letter.\p"
# 206 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "… … … … … …\p"
# 207 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "To {PLAYER}{KUN}…\p"
# 208 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "I've decided to do a little soul-\n"
# 209 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "searching and train on the road.\p"
# 210 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "I don't plan to return home for some\n"
# 211 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "time.\p"
# 212 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "I have a favor to ask of you.\p"
# 213 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "I want you to take the Poké Ball on\n"
# 214 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "the desk.\p"
# 215 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Inside it is a Meltan, one of my\n"
# 216 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "favorite Pokémon.\p"
# 217 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "I'm counting on you.\p"
# 218 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "May our paths cross someday.\p"
# 219 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "Steven Stone$"
# 220 "data/maps/MossdeepCity_StevensHouse/scripts.pory"

# 221 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
MossdeepCity_StevensHouse_Text_CollectionOfRareRocks: @ 8222D97
# 222 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "It's a collection of rare rocks and\n"
# 223 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "stones assembled by Steven.$"
