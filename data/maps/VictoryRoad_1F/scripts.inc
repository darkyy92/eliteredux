# 1 "data/maps/VictoryRoad_1F/scripts.pory"

# 2 "data/maps/VictoryRoad_1F/scripts.pory"
.set LOCALID_WALLY_ENTRANCE, 4
# 3 "data/maps/VictoryRoad_1F/scripts.pory"

# 4 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_MapScripts:: @ 8235D7A
# 5 "data/maps/VictoryRoad_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
# 6 "data/maps/VictoryRoad_1F/scripts.pory"
	.byte 0
# 7 "data/maps/VictoryRoad_1F/scripts.pory"

# 8 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_OnTransition: @ 8235D80
# 9 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_VICTORY_ROAD_1F_STATE, 1
# 10 "data/maps/VictoryRoad_1F/scripts.pory"
	call_if_eq VictoryRoad_1F_EventScript_SetEntranceWallyPos1
# 11 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_VICTORY_ROAD_1F_STATE, 2
# 12 "data/maps/VictoryRoad_1F/scripts.pory"
	call_if_eq VictoryRoad_1F_EventScript_SetEntranceWallyPos2
# 13 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 14 "data/maps/VictoryRoad_1F/scripts.pory"

# 15 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_SetEntranceWallyPos1:: @ 8235D97
# 16 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 2, 24
# 17 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
# 18 "data/maps/VictoryRoad_1F/scripts.pory"
	return
# 19 "data/maps/VictoryRoad_1F/scripts.pory"

# 20 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_SetEntranceWallyPos2:: @ 8235DA3
# 21 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 3, 24
# 22 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
# 23 "data/maps/VictoryRoad_1F/scripts.pory"
	return
# 24 "data/maps/VictoryRoad_1F/scripts.pory"

# 25 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_WallyBattleTrigger1:: @ 8235DAF
# 26 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 27 "data/maps/VictoryRoad_1F/scripts.pory"
	setvar VAR_0x8008, 1
# 28 "data/maps/VictoryRoad_1F/scripts.pory"
	addobject LOCALID_WALLY_ENTRANCE
# 29 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer1
# 30 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 31 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
# 32 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 33 "data/maps/VictoryRoad_1F/scripts.pory"

# 34 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_WallyBattleTrigger2:: @ 8235DC8
# 35 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 36 "data/maps/VictoryRoad_1F/scripts.pory"
	setvar VAR_0x8008, 2
# 37 "data/maps/VictoryRoad_1F/scripts.pory"
	addobject LOCALID_WALLY_ENTRANCE
# 38 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer2
# 39 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 40 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
# 41 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 42 "data/maps/VictoryRoad_1F/scripts.pory"

# 43 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_WallyEntranceBattle:: @ 8235DE1
# 44 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
# 45 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 46 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
# 47 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
# 48 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
# 49 "data/maps/VictoryRoad_1F/scripts.pory"
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
# 50 "data/maps/VictoryRoad_1F/scripts.pory"
	copyobjectxytoperm LOCALID_WALLY_ENTRANCE
# 51 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
# 52 "data/maps/VictoryRoad_1F/scripts.pory"
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
# 53 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
# 54 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 55 "data/maps/VictoryRoad_1F/scripts.pory"

# 56 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_WallyApproachPlayer1: @ 8235E15
# 57 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 58 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 59 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 60 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 61 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 62 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 63 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 64 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 65 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 66 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 67 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 68 "data/maps/VictoryRoad_1F/scripts.pory"
	step_end
# 69 "data/maps/VictoryRoad_1F/scripts.pory"

# 70 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_WallyApproachPlayer2: @ 8235E21
# 71 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 72 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 73 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 74 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 75 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 76 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 77 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 78 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 79 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 80 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 81 "data/maps/VictoryRoad_1F/scripts.pory"
	step_end
# 82 "data/maps/VictoryRoad_1F/scripts.pory"

# 83 "data/maps/VictoryRoad_1F/scripts.pory"
@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
# 84 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_EntranceWally:: @ 8235E2C
# 85 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
# 86 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 87 "data/maps/VictoryRoad_1F/scripts.pory"

# 88 "data/maps/VictoryRoad_1F/scripts.pory"
@ This Wally appears and remains at the exit after the Hall of Fame is entered 
# 89 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_ExitWally:: @ 8235E35
# 90 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
# 91 "data/maps/VictoryRoad_1F/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 92 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, TRUE
# 93 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_eq VictoryRoad_1F_EventScript_RematchWally
# 94 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
# 95 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 96 "data/maps/VictoryRoad_1F/scripts.pory"

# 97 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_RematchWally:: @ 8235E5C
# 98 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
# 99 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
# 100 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 101 "data/maps/VictoryRoad_1F/scripts.pory"

# 102 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Edgar:: @ 8235E73
# 103 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
# 104 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
# 105 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 106 "data/maps/VictoryRoad_1F/scripts.pory"

# 107 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Albert:: @ 8235E8A
# 108 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
# 109 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
# 110 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 111 "data/maps/VictoryRoad_1F/scripts.pory"

# 112 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Hope:: @ 8235EA1
# 113 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
# 114 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
# 115 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 116 "data/maps/VictoryRoad_1F/scripts.pory"

# 117 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Quincy:: @ 8235EB8
# 118 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
# 119 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
# 120 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 121 "data/maps/VictoryRoad_1F/scripts.pory"

# 122 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Katelynn:: @ 8235ECF
# 123 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
# 124 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
# 125 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 126 "data/maps/VictoryRoad_1F/scripts.pory"

# 127 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore: @ 8235EE6
# 128 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Wally: Hi! {PLAYER}!\p"
# 129 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I bet you're surprised to see me here!\p"
# 130 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I made it all the way here, and it's\n"
# 131 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "all thanks to you!\p"
# 132 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}, losing to you that time\n"
# 133 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "made me stronger!\p"
# 134 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "But I'm not going to lose anymore!\p"
# 135 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I'm going to win! For the Pokémon who\n"
# 136 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "gave me courage and strength!\p"
# 137 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Okay… Here I come!$"
# 138 "data/maps/VictoryRoad_1F/scripts.pory"

# 139 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyEntranceDefeat: @ 8235FFC
# 140 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Wow!\n"
# 141 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}, you are strong, after all!$"
# 142 "data/maps/VictoryRoad_1F/scripts.pory"

# 143 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyPostEntranceBattle: @ 8236020
# 144 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Wally: I couldn't beat you today,\n"
# 145 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}, but one of these days, I'll\l"
# 146 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "catch up to you!$"
# 147 "data/maps/VictoryRoad_1F/scripts.pory"

# 148 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyIntro: @ 8236073
# 149 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Wally: Hi! {PLAYER}!\p"
# 150 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I've gotten stronger since that last\n"
# 151 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "time! I wanted to show you, {PLAYER}!\p"
# 152 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Okay… Here I come!$"
# 153 "data/maps/VictoryRoad_1F/scripts.pory"

# 154 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyDefeat: @ 82360DA
# 155 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Wow!\n"
# 156 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}, you are strong, after all!$"
# 157 "data/maps/VictoryRoad_1F/scripts.pory"

# 158 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyPostBattle: @ 82360FE
# 159 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Wally: I couldn't beat you this time,\n"
# 160 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "too… But one of these days, {PLAYER},\l"
# 161 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I'm going to catch up to you…\p"
# 162 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "And challenge the Pokémon League!$"
# 163 "data/maps/VictoryRoad_1F/scripts.pory"

# 164 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_EdgarIntro: @ 8236184
# 165 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I've made it this far a couple times,\n"
# 166 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "but the last stretch is so long…$"
# 167 "data/maps/VictoryRoad_1F/scripts.pory"

# 168 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_EdgarDefeat: @ 82361CB
# 169 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "My dream ends here again…$"
# 170 "data/maps/VictoryRoad_1F/scripts.pory"

# 171 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_EdgarPostBattle: @ 82361E5
# 172 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "You've made it this far. Keep the\n"
# 173 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "momentum going and become the\l"
# 174 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Champion! If anyone can, it's you!$"
# 175 "data/maps/VictoryRoad_1F/scripts.pory"

# 176 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_AlbertIntro: @ 8236248
# 177 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I didn't come all this way to lose now.\n"
# 178 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "That possibility doesn't exist!$"
# 179 "data/maps/VictoryRoad_1F/scripts.pory"

# 180 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_AlbertDefeat: @ 8236290
# 181 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Impossible…\n"
# 182 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I lost?$"
# 183 "data/maps/VictoryRoad_1F/scripts.pory"

# 184 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_AlbertPostBattle: @ 82362A4
# 185 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I lost here…\p"
# 186 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "That means I lack the qualifications\n"
# 187 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "to become the Champion…$"
# 188 "data/maps/VictoryRoad_1F/scripts.pory"

# 189 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_HopeIntro: @ 82362EE
# 190 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "This seemingly infinite and harsh road\n"
# 191 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "lives up to its name of Victory.$"
# 192 "data/maps/VictoryRoad_1F/scripts.pory"

# 193 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_HopeDefeat: @ 8236336
# 194 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Your battle style is fantastic…$"
# 195 "data/maps/VictoryRoad_1F/scripts.pory"

# 196 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_HopePostBattle: @ 8236356
# 197 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "You seem to have the potential for\n"
# 198 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "becoming the Champion.$"
# 199 "data/maps/VictoryRoad_1F/scripts.pory"

# 200 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_QuincyIntro: @ 8236390
# 201 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "What is the Victory Road?\n"
# 202 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I'll tell you if you win!$"
# 203 "data/maps/VictoryRoad_1F/scripts.pory"

# 204 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_QuincyDefeat: @ 82363C4
# 205 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Okay!\n"
# 206 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Well done!$"
# 207 "data/maps/VictoryRoad_1F/scripts.pory"

# 208 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_QuincyPostBattle: @ 82363D5
# 209 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Getting through here safely--that's\n"
# 210 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "the final test for any Trainer aiming\l"
# 211 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "to become the Pokémon Champion.\p"
# 212 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "That's why it's called the Victory\n"
# 213 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Road.$"
# 214 "data/maps/VictoryRoad_1F/scripts.pory"

# 215 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_KatelynnIntro: @ 8236468
# 216 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I have nothing to say to anyone\n"
# 217 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "that's come this far. Come on!$"
# 218 "data/maps/VictoryRoad_1F/scripts.pory"

# 219 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_KatelynnDefeat: @ 82364A7
# 220 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "This is a disgrace…$"
# 221 "data/maps/VictoryRoad_1F/scripts.pory"

# 222 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_KatelynnPostBattle: @ 82364BB
# 223 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Humph, go right on ahead.\n"
# 224 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "See if I care.$"

VictoryRoad_1F_EventScript_LegendaryNPC::
# 228 "data/maps/VictoryRoad_1F/scripts.pory"
	lock
# 229 "data/maps/VictoryRoad_1F/scripts.pory"
	faceplayer
# 230 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 232 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq VictoryRoad_1F_EventScript_LegendaryNPC_2
# 254 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_EventScript_LegendaryNPC_Text_4
VictoryRoad_1F_EventScript_LegendaryNPC_1:
# 271 "data/maps/VictoryRoad_1F/scripts.pory"
	release
	end

VictoryRoad_1F_EventScript_LegendaryNPC_2:
# 233 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, VictoryRoad_1F_EventScript_LegendaryNPC_5
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	checktrainerflag TRAINER_WALLY_VR_1
	goto_if 1, VictoryRoad_1F_EventScript_LegendaryNPC_11
VictoryRoad_1F_EventScript_LegendaryNPC_9:
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_EventScript_LegendaryNPC_Text_3
	goto VictoryRoad_1F_EventScript_LegendaryNPC_1

VictoryRoad_1F_EventScript_LegendaryNPC_5:
# 234 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_EventScript_LegendaryNPC_Text_1
	goto VictoryRoad_1F_EventScript_LegendaryNPC_1

VictoryRoad_1F_EventScript_LegendaryNPC_8:
# 246 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_EventScript_LegendaryNPC_Text_2
	goto VictoryRoad_1F_EventScript_LegendaryNPC_1

VictoryRoad_1F_EventScript_LegendaryNPC_10:
# 242 "data/maps/VictoryRoad_1F/scripts.pory"
	checktrainerflag TRAINER_ALBERT
	goto_if 1, VictoryRoad_1F_EventScript_LegendaryNPC_15
	goto VictoryRoad_1F_EventScript_LegendaryNPC_9

VictoryRoad_1F_EventScript_LegendaryNPC_11:
# 241 "data/maps/VictoryRoad_1F/scripts.pory"
	checktrainerflag TRAINER_EDGAR
	goto_if 1, VictoryRoad_1F_EventScript_LegendaryNPC_10
	goto VictoryRoad_1F_EventScript_LegendaryNPC_9

VictoryRoad_1F_EventScript_LegendaryNPC_14:
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	checktrainerflag TRAINER_QUINCY
	goto_if 1, VictoryRoad_1F_EventScript_LegendaryNPC_18
	goto VictoryRoad_1F_EventScript_LegendaryNPC_9

VictoryRoad_1F_EventScript_LegendaryNPC_15:
# 243 "data/maps/VictoryRoad_1F/scripts.pory"
	checktrainerflag TRAINER_HOPE
	goto_if 1, VictoryRoad_1F_EventScript_LegendaryNPC_14
	goto VictoryRoad_1F_EventScript_LegendaryNPC_9

VictoryRoad_1F_EventScript_LegendaryNPC_18:
# 245 "data/maps/VictoryRoad_1F/scripts.pory"
	checktrainerflag TRAINER_KATELYNN
	goto_if 1, VictoryRoad_1F_EventScript_LegendaryNPC_8
	goto VictoryRoad_1F_EventScript_LegendaryNPC_9


VictoryRoad_1F_EventScript_Calvin::
# 276 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_CALVIN_E4, VictoryRoad_1F_EventScript_Calvin_Text_0, VictoryRoad_1F_EventScript_Calvin_Text_1
# 277 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_EventScript_Calvin_Text_2, MSGBOX_NPC
# 278 "data/maps/VictoryRoad_1F/scripts.pory"
	settrainerflag TRAINER_CALVIN_E4
# 279 "data/maps/VictoryRoad_1F/scripts.pory"
	release
	end


VictoryRoad_1F_EventScript_LegendaryNPC_Text_0:
# 230 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Sage intern: Why did I choose to get an\n"
	.string "internship at the Academy of Pokémon\l"
	.string "sages? I could've become an investment\l"
	.string "banker like my brother, or an insurance\l"
	.string "lawyer like my sister... but no! I chose\l"
	.string "an academic profession, and now I'm\l"
	.string "stuck here for FREE all day long!\p"
	.string "Oh, sorry I didn't notice you... wait, I\n"
	.string "forgot my script... did I have any?\l"
	.string "Whatever. Just choose yes in the\l"
	.string "message box. Please. They didn't code a\l"
	.string "response for 'no' and the game's gonna\l"
	.string "crash.$"

VictoryRoad_1F_EventScript_LegendaryNPC_Text_1:
# 234 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "My colleagues might have bombarded you\n"
	.string "with information about their route's\l"
	.string "legendaries, but I'm different!\p"
	.string "Those residing in this dank cave... just\n"
	.string "happened to randomly like it, so they\l"
	.string "stayed. I tried asking my colleagues\l"
	.string "about it, but they ignored my emails...\l"
	.string "shame on them!\p"
	.string "Two are poisonous dragons, one's a\n"
	.string "football player, and they've got\l"
	.string "nothing to do with each other!\p"
	.string "You seem like a smart fella, so no\n"
	.string "beating around the bush this time:\l"
	.string "become champion, beat every trainer,\l"
	.string "talk to me, use your DexNav, and pronto!\l"
	.string "Three legendaries for you!$"

VictoryRoad_1F_EventScript_LegendaryNPC_Text_2:
# 246 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Poipole, Naganadel and Zeraora... done,\n"
	.string "your DexNav should show their location\l"
	.string "now. Good luck champ, let's leave this\l"
	.string "place!$"

VictoryRoad_1F_EventScript_LegendaryNPC_Text_3:
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Hey lad! Congrats on becoming champion,\n"
	.string "but as you might have guessed, your\l"
	.string "work's not done! It's not my fault tho!\l"
	.string "Rules say so (I despise them too!)! So\l"
	.string "beat every trainer, then come back here\l"
	.string "so we can leave this cave behind us, ok?$"

VictoryRoad_1F_EventScript_LegendaryNPC_Text_4:
# 254 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "ERROR AT ADDRESS 0X0009B1F\p"
	.string "CORRUPTION WARNING ADDRESS\n"
	.string "0X0009DA32\p"
	.string "SAV\l"
	.string "ING DAT\p"
	.string "A DO N OT TURN Y\p"
	.string "o\p"
	.string "u\p"
	.string "r\p"
	.string "\p"
	.string "SAVE DATA S++++++UC\p"
	.string "0x000E34F ESFULLY DEL\p"
	.string "ETED\p"
	.string "Come on. Did I really fool you. Admit it.\n"
	.string "I did, if only for a split second. You're\l"
	.string "lucky I can't change music through\l"
	.string "Poryscript... that would've been funny.\l"
	.string "Jokes aside, you have to explain to me\l"
	.string "why you clicked 'no' when I EXPLICITLY\l"
	.string "told you it would crash the game. Come\l"
	.string "on. You're an adult! Why would you crash\l"
	.string "the game and make all the NPC's here\l"
	.string "suffer? That's sick of you!\p"
	.string "Imagine if I came into your house and\n"
	.string "broke all the windows because you put\l"
	.string "up a sing saying 'please don't break my\l"
	.string "windows!'. I imagine you'd be pissed off.\l"
	.string "I would be too! But you did anyway.\p"
	.string "Imagine if you were a streamer playing\n"
	.string "the hack and this message stalled out\l"
	.string "your 'ultra hardcore no restarts no\l"
	.string "breathing blind deaf colourblind no\l"
	.string "hands no setup no terrain no weather\l"
	.string "bridge-wed-egg-soul locke run.\p"
	.string "Would you keep mashing A hoping this\n"
	.string "dialogue ends? Or would you rather\l"
	.string "reload the save and just answer 'YES' to\l"
	.string "my question?\p"
	.string "There's a concept in economics called\n"
	.string "'sunk cost'. Yes, it's releveant.\l"
	.string "Basically, sunk costs are those which\l"
	.string "have already been incurred and which\l"
	.string "are unrecoverable. The time you spent\l"
	.string "reading this is a sunk cost, for\l"
	.string "example.\p"
	.string "Now, would it make sense for you to end\n"
	.string "this dialogue now by reloading your\l"
	.string "save, and stop incurring sunk costs, or\l"
	.string "would it be better to keep on reading?\p"
	.string "That's an interesting question, and it\n"
	.string "all depends on when you last saved, if\l"
	.string "you're enjoying this dialogue, your\l"
	.string "attention level, the amount of speedup\l"
	.string "your emulator is playing at, et cetera.\p"
	.string "(un)fortunately for you, my heated SPA\n"
	.string "has reached 37 degrees Celsius, so it's\l"
	.string "time for me to take a hot bath. I would\l"
	.string "keep on talking otherwise.. Consider\l"
	.string "yourself lucky, kid! - Luca$"

VictoryRoad_1F_EventScript_Calvin_Text_0:
# 276 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Hehe! I'm almost at the Pokémon League.\n"
	.string "Some say I'm not ready. Look at me now,\l"
	.string "I'm Calvin, and I'm a wall before the\l"
	.string "League! Ready for a real challenge?$"

VictoryRoad_1F_EventScript_Calvin_Text_1:
# 276 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Whoa, you're tough!$"

VictoryRoad_1F_EventScript_Calvin_Text_2:
# 277 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Hey, give the E4 a run for their money,\n"
	.string "will ya? Good luck!$"
