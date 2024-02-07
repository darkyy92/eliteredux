# 1 "data/maps/MtPyre_Summit/scripts.pory"

# 2 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_ARCHIE, 2
# 3 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_OLD_LADY, 3
# 4 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_GRUNT_1, 4
# 5 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_GRUNT_2, 5
# 6 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_GRUNT_3, 6
# 7 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_GRUNT_4, 7
# 8 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_MAXIE, 8
# 9 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_MATT, 9
# 10 "data/maps/MtPyre_Summit/scripts.pory"

# 11 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_MapScripts:: @ 8231FF7
# 12 "data/maps/MtPyre_Summit/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
# 13 "data/maps/MtPyre_Summit/scripts.pory"
	.byte 0
# 14 "data/maps/MtPyre_Summit/scripts.pory"

# 15 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_OnTransition: @ 8231FFD
# 16 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_MT_PYRE_STATE, 2
# 17 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_SetArchieMaxiePositions
# 18 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 19 "data/maps/MtPyre_Summit/scripts.pory"

# 20 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_SetArchieMaxiePositions:: @ 8232009
# 21 "data/maps/MtPyre_Summit/scripts.pory"
	setobjectxyperm LOCALID_MAXIE, 23, 6
# 22 "data/maps/MtPyre_Summit/scripts.pory"
	setobjectxyperm LOCALID_ARCHIE, 22, 6
# 23 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 24 "data/maps/MtPyre_Summit/scripts.pory"

# 25 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaTrigger0:: @ 8232018
# 26 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 27 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 0
# 28 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_TeamAquaExits
# 29 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 30 "data/maps/MtPyre_Summit/scripts.pory"

# 31 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaTrigger1:: @ 8232024
# 32 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 33 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 1
# 34 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_TeamAquaExits
# 35 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 36 "data/maps/MtPyre_Summit/scripts.pory"

# 37 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaTrigger2:: @ 8232030
# 38 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 39 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 2
# 40 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_TeamAquaExits
# 41 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 42 "data/maps/MtPyre_Summit/scripts.pory"

# 43 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaExits:: @ 823203C
# 44 "data/maps/MtPyre_Summit/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 45 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 46 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 47 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFastestDown
# 48 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 49 "data/maps/MtPyre_Summit/scripts.pory"
	delay 50
# 50 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_0x8008, 0
# 51 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_ArchieFacePlayer0
# 52 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_0x8008, 1
# 53 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_ArchieFacePlayer1
# 54 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_0x8008, 2
# 55 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_ArchieFacePlayer2
# 56 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
# 57 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 58 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_TO_BLACK
# 59 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_ARCHIE
# 60 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 61 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 62 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_GRUNT_3
# 63 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_GRUNT_4
# 64 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MATT
# 65 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
# 66 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
# 67 "data/maps/MtPyre_Summit/scripts.pory"
	fadedefaultbgm
# 68 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 69 "data/maps/MtPyre_Summit/scripts.pory"
	delay 20
# 70 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 1
# 71 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_0x8008, 0
# 72 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_OldLadyApproachPlayer0
# 73 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_0x8008, 1
# 74 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_OldLadyApproachPlayer1
# 75 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_0x8008, 2
# 76 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_OldLadyApproachPlayer2
# 77 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
# 78 "data/maps/MtPyre_Summit/scripts.pory"
	giveitem ITEM_MAGMA_EMBLEM
# 79 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
# 80 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
# 81 "data/maps/MtPyre_Summit/scripts.pory"
	releaseall
# 82 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 83 "data/maps/MtPyre_Summit/scripts.pory"

# 84 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieFacePlayer0:: @ 82320E0
# 85 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
# 86 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 87 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 88 "data/maps/MtPyre_Summit/scripts.pory"

# 89 "data/maps/MtPyre_Summit/scripts.pory"
@ Archie is already facing player
# 90 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieFacePlayer1:: @ 82320EB
# 91 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 92 "data/maps/MtPyre_Summit/scripts.pory"

# 93 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieFacePlayer2:: @ 82320EC
# 94 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
# 95 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 96 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 97 "data/maps/MtPyre_Summit/scripts.pory"

# 98 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyApproachPlayer0:: @ 82320F7
# 99 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
# 100 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 101 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 102 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 103 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 104 "data/maps/MtPyre_Summit/scripts.pory"

# 105 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyApproachPlayer1:: @ 823210C
# 106 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
# 107 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 108 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 109 "data/maps/MtPyre_Summit/scripts.pory"

# 110 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyApproachPlayer2:: @ 8232117
# 111 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
# 112 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 113 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 114 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 115 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 116 "data/maps/MtPyre_Summit/scripts.pory"

# 117 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_OldLadyApproachPlayer0: @ 823212C
# 118 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 119 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 120 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_left
# 121 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 122 "data/maps/MtPyre_Summit/scripts.pory"

# 123 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_OldLadyApproachPlayer1: @ 8232130
# 124 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 125 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 126 "data/maps/MtPyre_Summit/scripts.pory"

# 127 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_OldLadyApproachPlayer2: @ 8232132
# 128 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 129 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 130 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_right
# 131 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 132 "data/maps/MtPyre_Summit/scripts.pory"

# 133 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieFacePlayer0: @ 8232136
# 134 "data/maps/MtPyre_Summit/scripts.pory"
	walk_left
# 135 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_down
# 136 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 137 "data/maps/MtPyre_Summit/scripts.pory"

# 138 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieFacePlayer2: @ 8232139
# 139 "data/maps/MtPyre_Summit/scripts.pory"
	walk_right
# 140 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_down
# 141 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 142 "data/maps/MtPyre_Summit/scripts.pory"

# 143 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldMan:: @ 823213C
# 144 "data/maps/MtPyre_Summit/scripts.pory"
	lock
# 145 "data/maps/MtPyre_Summit/scripts.pory"
	faceplayer
# 146 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
# 147 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
# 148 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_RESULT, YES
# 149 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_OldManTale
# 150 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_RESULT, NO
# 151 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_DeclineOldManTale
# 152 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 153 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 154 "data/maps/MtPyre_Summit/scripts.pory"

# 155 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldManAfterRayquaza:: @ 8232167
# 156 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
# 157 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_RESULT, YES
# 158 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_OldManNewTale
# 159 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_RESULT, NO
# 160 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_DeclineOldManTale
# 161 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 162 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 163 "data/maps/MtPyre_Summit/scripts.pory"

# 164 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldManTale:: @ 8232187
# 165 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
# 166 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 167 "data/maps/MtPyre_Summit/scripts.pory"

# 168 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_DeclineOldManTale:: @ 8232190
# 169 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
# 170 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 171 "data/maps/MtPyre_Summit/scripts.pory"

# 172 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldManNewTale:: @ 8232199
# 173 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
# 174 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 175 "data/maps/MtPyre_Summit/scripts.pory"

# 176 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLady:: @ 82321A2
# 177 "data/maps/MtPyre_Summit/scripts.pory"
	lock
# 178 "data/maps/MtPyre_Summit/scripts.pory"
	faceplayer
# 179 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
# 180 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_MT_PYRE_STATE, 3
# 181 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_ge MtPyre_Summit_EventScript_OldLadyOrbsReturned
# 182 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
# 183 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
# 184 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 185 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 186 "data/maps/MtPyre_Summit/scripts.pory"

# 187 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyOrbsReturned:: @ 82321CB
# 188 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
# 189 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
# 190 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 191 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 192 "data/maps/MtPyre_Summit/scripts.pory"

# 193 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyLegendariesAwake:: @ 82321D8
# 194 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
# 195 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 196 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 197 "data/maps/MtPyre_Summit/scripts.pory"

# 198 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned:: @ 82321E2
# 199 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
# 200 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 201 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 202 "data/maps/MtPyre_Summit/scripts.pory"

# 203 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieTrigger0:: @ 82321EC
# 204 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 205 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 0
# 206 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
# 207 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 208 "data/maps/MtPyre_Summit/scripts.pory"

# 209 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieTrigger1:: @ 82321F8
# 210 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 211 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 1
# 212 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
# 213 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 214 "data/maps/MtPyre_Summit/scripts.pory"

# 215 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieTrigger2:: @ 8232204
# 216 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 217 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 2
# 218 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
# 219 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 220 "data/maps/MtPyre_Summit/scripts.pory"

# 221 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs:: @ 8232210
# 222 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 223 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 224 "data/maps/MtPyre_Summit/scripts.pory"
	delay 60
# 225 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_0x8008, 0
# 226 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
# 227 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_0x8008, 1
# 228 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
# 229 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_0x8008, 2
# 230 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
# 231 "data/maps/MtPyre_Summit/scripts.pory"
	playse SE_PIN
# 232 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
# 233 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 234 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
# 235 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 236 "data/maps/MtPyre_Summit/scripts.pory"
	delay 30
# 237 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_0x8008, 0
# 238 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_MaxieApproachPlayer0
# 239 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_0x8008, 1
# 240 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_MaxieApproachPlayer1
# 241 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_0x8008, 2
# 242 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_MaxieApproachPlayer2
# 243 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
# 244 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 245 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_0x8008, 0
# 246 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_MaxieApproachArchie0
# 247 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_0x8008, 1
# 248 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_MaxieApproachArchie1
# 249 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_0x8008, 2
# 250 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq MtPyre_Summit_EventScript_MaxieApproachArchie2
# 251 "data/maps/MtPyre_Summit/scripts.pory"
	delay 30
# 252 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 253 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 254 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 255 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_ARCHIE
# 256 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MAXIE
# 257 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 3
# 258 "data/maps/MtPyre_Summit/scripts.pory"
	releaseall
# 259 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 260 "data/maps/MtPyre_Summit/scripts.pory"

# 261 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieBeginExit0:: @ 82322C4
# 262 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
# 263 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 264 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 265 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 266 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 267 "data/maps/MtPyre_Summit/scripts.pory"

# 268 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieBeginExit1:: @ 82322DD
# 269 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
# 270 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 271 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 272 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 273 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 274 "data/maps/MtPyre_Summit/scripts.pory"

# 275 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieBeginExit2:: @ 82322F6
# 276 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
# 277 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 278 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 279 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 280 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 281 "data/maps/MtPyre_Summit/scripts.pory"

# 282 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachPlayer0:: @ 823230F
# 283 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
# 284 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
# 285 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
# 286 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 287 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 288 "data/maps/MtPyre_Summit/scripts.pory"

# 289 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachPlayer1:: @ 8232328
# 290 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
# 291 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
# 292 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
# 293 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 294 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 295 "data/maps/MtPyre_Summit/scripts.pory"

# 296 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachPlayer2:: @ 8232341
# 297 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
# 298 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
# 299 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
# 300 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 301 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 302 "data/maps/MtPyre_Summit/scripts.pory"

# 303 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachArchie0:: @ 823235A
# 304 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
# 305 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
# 306 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 307 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFastestRight
# 308 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 309 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 310 "data/maps/MtPyre_Summit/scripts.pory"

# 311 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachArchie1:: @ 8232376
# 312 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
# 313 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
# 314 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 315 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFastestRight
# 316 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 317 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 318 "data/maps/MtPyre_Summit/scripts.pory"

# 319 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachArchie2:: @ 8232392
# 320 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
# 321 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
# 322 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 323 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFastestRight
# 324 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 325 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 326 "data/maps/MtPyre_Summit/scripts.pory"

# 327 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerFaceMaxie0: @ 82323AE
# 328 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 329 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 330 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_right
# 331 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 332 "data/maps/MtPyre_Summit/scripts.pory"

# 333 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerFaceMaxie: @ 82323B2
# 334 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 335 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 336 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_left
# 337 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 338 "data/maps/MtPyre_Summit/scripts.pory"

# 339 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieExit: @ 82323B6
# 340 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 341 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 342 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 343 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 344 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 345 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 346 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 347 "data/maps/MtPyre_Summit/scripts.pory"

# 348 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieExit: @ 82323BD
# 349 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 350 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 351 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 352 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 353 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 354 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 355 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 356 "data/maps/MtPyre_Summit/scripts.pory"

# 357 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0: @ 82323C4
# 358 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 359 "data/maps/MtPyre_Summit/scripts.pory"
	delay_8
# 360 "data/maps/MtPyre_Summit/scripts.pory"
	walk_left
# 361 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_right
# 362 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 363 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_down
# 364 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 365 "data/maps/MtPyre_Summit/scripts.pory"

# 366 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1: @ 82323CB
# 367 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 368 "data/maps/MtPyre_Summit/scripts.pory"
	delay_8
# 369 "data/maps/MtPyre_Summit/scripts.pory"
	walk_right
# 370 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_left
# 371 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 372 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_down
# 373 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 374 "data/maps/MtPyre_Summit/scripts.pory"

# 375 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2: @ 82323D2
# 376 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 377 "data/maps/MtPyre_Summit/scripts.pory"
	delay_8
# 378 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_left
# 379 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 380 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_down
# 381 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 382 "data/maps/MtPyre_Summit/scripts.pory"

# 383 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachPlayer0: @ 82323D8
# 384 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 385 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 386 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 387 "data/maps/MtPyre_Summit/scripts.pory"
	walk_left
# 388 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 389 "data/maps/MtPyre_Summit/scripts.pory"

# 390 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachPlayer1: @ 82323DD
# 391 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 392 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 393 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 394 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_right
# 395 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 396 "data/maps/MtPyre_Summit/scripts.pory"

# 397 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachPlayer2: @ 82323E2
# 398 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 399 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 400 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 401 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_right
# 402 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 403 "data/maps/MtPyre_Summit/scripts.pory"

# 404 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieWatchMaxie: @ 82323E7
# 405 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 406 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_up
# 407 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 408 "data/maps/MtPyre_Summit/scripts.pory"

# 409 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchMaxie: @ 82323EA
# 410 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 411 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_down
# 412 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 413 "data/maps/MtPyre_Summit/scripts.pory"

# 414 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachArchie0: @ 82323ED
# 415 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 416 "data/maps/MtPyre_Summit/scripts.pory"
	walk_right
# 417 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 418 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 419 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_left
# 420 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 421 "data/maps/MtPyre_Summit/scripts.pory"

# 422 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachArchie1: @ 82323F3
# 423 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 424 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 425 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 426 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_left
# 427 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 428 "data/maps/MtPyre_Summit/scripts.pory"

# 429 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachArchie2: @ 82323F8
# 430 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 431 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 432 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 433 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_fastest_left
# 434 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 435 "data/maps/MtPyre_Summit/scripts.pory"

# 436 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt1:: @ 82323FD
# 437 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
# 438 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 439 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 440 "data/maps/MtPyre_Summit/scripts.pory"

# 441 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt2:: @ 8232414
# 442 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
# 443 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 444 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 445 "data/maps/MtPyre_Summit/scripts.pory"

# 446 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt3:: @ 823242B
# 447 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
# 448 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 449 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 450 "data/maps/MtPyre_Summit/scripts.pory"

# 451 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt4:: @ 8232442
# 452 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
# 453 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 454 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 455 "data/maps/MtPyre_Summit/scripts.pory"

# 456 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Matt::
# 457 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_MATT_MT_PYRE, MtPyre_Summit_Text_MattIntro, MtPyre_Summit_Text_MattDefeat
# 458 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_MattPostBattle, MSGBOX_AUTOCLOSE
# 459 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 460 "data/maps/MtPyre_Summit/scripts.pory"

# 461 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_MattIntro:
# 462 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Hehehe!\n"
# 463 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You must be the infamous {PLAYER}!\p"
# 464 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Come to mess with us here too,\n"
# 465 "data/maps/MtPyre_Summit/scripts.pory"
	.string "have you?\p"
# 466 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Well, tough luck!\p"
# 467 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I'm a cut above the Grunts you've seen\n"
# 468 "data/maps/MtPyre_Summit/scripts.pory"
	.string "so far.\p"
# 469 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You're not getting past me!$"
# 470 "data/maps/MtPyre_Summit/scripts.pory"

# 471 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_MattDefeat:
# 472 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Hehehe…\n"
# 473 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Guess I'll let you pass after all…$"
# 474 "data/maps/MtPyre_Summit/scripts.pory"

# 475 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_MattPostBattle:
# 476 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Hehehe…\n"
# 477 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You're strong, {PLAYER}, but too slow!\p"
# 478 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We've already got what we came for.$"
# 479 "data/maps/MtPyre_Summit/scripts.pory"

# 480 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt1Intro: @ 8232459
# 481 "data/maps/MtPyre_Summit/scripts.pory"
	.string "No! Those Team Magma goons got\n"
# 482 "data/maps/MtPyre_Summit/scripts.pory"
	.string "here ahead of us!\p"
# 483 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We can't fall behind!$"
# 484 "data/maps/MtPyre_Summit/scripts.pory"

# 485 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt1Defeat: @ 82324A0
# 486 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I thought you were one of the Magmas\n"
# 487 "data/maps/MtPyre_Summit/scripts.pory"
	.string "who happened to come back…$"
# 488 "data/maps/MtPyre_Summit/scripts.pory"

# 489 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt1PostBattle: @ 82324E0
# 490 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Yeah, so you are strong…\n"
# 491 "data/maps/MtPyre_Summit/scripts.pory"
	.string "But there're a lot of us!$"
# 492 "data/maps/MtPyre_Summit/scripts.pory"

# 493 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt2Intro: @ 8232513
# 494 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Hah!\n"
# 495 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Too bad for you!\p"
# 496 "data/maps/MtPyre_Summit/scripts.pory"
	.string "If you came earlier, you only would've\n"
# 497 "data/maps/MtPyre_Summit/scripts.pory"
	.string "had to battle the wimpy Team Magma.\p"
# 498 "data/maps/MtPyre_Summit/scripts.pory"
	.string "But since you arrived now, you have\n"
# 499 "data/maps/MtPyre_Summit/scripts.pory"
	.string "to take on us toughies!$"
# 500 "data/maps/MtPyre_Summit/scripts.pory"

# 501 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt2Defeat: @ 82325B0
# 502 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Urgh… I should've let you take on\n"
# 503 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Team Magma first…$"
# 504 "data/maps/MtPyre_Summit/scripts.pory"

# 505 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt2PostBattle: @ 82325E4
# 506 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You don't know anything!\n"
# 507 "data/maps/MtPyre_Summit/scripts.pory"
	.string "So why are you messing with us?$"
# 508 "data/maps/MtPyre_Summit/scripts.pory"

# 509 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt3Intro: @ 823261D
# 510 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You…\n"
# 511 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We saw you at Mt. Chimney.\p"
# 512 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You don't belong to either Team,\n"
# 513 "data/maps/MtPyre_Summit/scripts.pory"
	.string "so why would you be here?$"
# 514 "data/maps/MtPyre_Summit/scripts.pory"

# 515 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt3Defeat: @ 8232678
# 516 "data/maps/MtPyre_Summit/scripts.pory"
	.string "If you're going to mess with anyone,\n"
# 517 "data/maps/MtPyre_Summit/scripts.pory"
	.string "let it be Team Magma…$"
# 518 "data/maps/MtPyre_Summit/scripts.pory"

# 519 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt3PostBattle: @ 82326B3
# 520 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Heh, it doesn't matter!\n"
# 521 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We bought ourselves some time!\p"
# 522 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The Boss should have snatched what\n"
# 523 "data/maps/MtPyre_Summit/scripts.pory"
	.string "he was after!$"
# 524 "data/maps/MtPyre_Summit/scripts.pory"

# 525 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt4Intro: @ 823271B
# 526 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, I know!\n"
# 527 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You tried to join Team Magma,\l"
# 528 "data/maps/MtPyre_Summit/scripts.pory"
	.string "but they wouldn't have you!\p"
# 529 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Well, don't think that we'll let you\n"
# 530 "data/maps/MtPyre_Summit/scripts.pory"
	.string "join our Team Aqua!$"
# 531 "data/maps/MtPyre_Summit/scripts.pory"

# 532 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt4Defeat: @ 823279A
# 533 "data/maps/MtPyre_Summit/scripts.pory"
	.string "If you want to join Team Aqua that\n"
# 534 "data/maps/MtPyre_Summit/scripts.pory"
	.string "badly, we can consider it…$"
# 535 "data/maps/MtPyre_Summit/scripts.pory"

# 536 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt4PostBattle: @ 82327D8
# 537 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We have a great combination going\n"
# 538 "data/maps/MtPyre_Summit/scripts.pory"
	.string "with us members and our leader.$"
# 539 "data/maps/MtPyre_Summit/scripts.pory"

# 540 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo: @ 823281A
# 541 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Archie: Team Magma's Maxie got ahead\n"
# 542 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of us, but we also got what we wanted.\p"
# 543 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The Blue Orb preserved at Mt. Pyre…\n"
# 544 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I, Archie, now have it in my possession!\p"
# 545 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Fufufu… Now we can bring our ultimate\n"
# 546 "data/maps/MtPyre_Summit/scripts.pory"
	.string "objective to fruition!\p"
# 547 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Okay, Team!\n"
# 548 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We're pulling out!$"
# 549 "data/maps/MtPyre_Summit/scripts.pory"

# 550 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis: @ 823290E
# 551 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, no…\n"
# 552 "data/maps/MtPyre_Summit/scripts.pory"
	.string "This cannot happen…\p"
# 553 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Not only the Blue Orb, but even\n"
# 554 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the Red Orb has been taken…\p"
# 555 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The Blue Orb and Red Orb must never\n"
# 556 "data/maps/MtPyre_Summit/scripts.pory"
	.string "be separated. They belong together.\p"
# 557 "data/maps/MtPyre_Summit/scripts.pory"
	.string "What are those men trying to do with\n"
# 558 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the two Orbs?\p"
# 559 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …\n"
# 560 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …\p"
# 561 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, yes. Was it Team Magma who came\n"
# 562 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and took the Red Orb first?\p"
# 563 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Well, in their haste, they left this\n"
# 564 "data/maps/MtPyre_Summit/scripts.pory"
	.string "behind.\p"
# 565 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I couldn't imagine what exactly it\n"
# 566 "data/maps/MtPyre_Summit/scripts.pory"
	.string "could be.\p"
# 567 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I would like you to have it.\n"
# 568 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Perhaps it will be useful in some way.$"
# 569 "data/maps/MtPyre_Summit/scripts.pory"

# 570 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_OrbsHaveBeenTaken: @ 8232AD8
# 571 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The Blue Orb and Red Orb taken by\n"
# 572 "data/maps/MtPyre_Summit/scripts.pory"
	.string "those sinister men…\p"
# 573 "data/maps/MtPyre_Summit/scripts.pory"
	.string "They must never be apart…\n"
# 574 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I fear something terrible will happen…$"
# 575 "data/maps/MtPyre_Summit/scripts.pory"

# 576 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_GroudonKyogreAwakened: @ 8232B4F
# 577 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, my goodness…\p"
# 578 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You say that both Groudon and Kyogre\n"
# 579 "data/maps/MtPyre_Summit/scripts.pory"
	.string "have been awakened?\p"
# 580 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It is said that the Blue Orb and\n"
# 581 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the Red Orb quelled the rage of\l"
# 582 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the two Pokémon…\p"
# 583 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It is also said that the true owner\n"
# 584 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of the Orbs still exists.\p"
# 585 "data/maps/MtPyre_Summit/scripts.pory"
	.string "However, no one knows who, or what\n"
# 586 "data/maps/MtPyre_Summit/scripts.pory"
	.string "exactly, the Orbs belong to.\p"
# 587 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It could be a human, or perhaps\n"
# 588 "data/maps/MtPyre_Summit/scripts.pory"
	.string "a Pokémon, but no one knows.$"
# 589 "data/maps/MtPyre_Summit/scripts.pory"

# 590 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs: @ 8232CA6
# 591 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The two men who took the Orbs came\n"
# 592 "data/maps/MtPyre_Summit/scripts.pory"
	.string "back to return them on their own.\p"
# 593 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Those men…\n"
# 594 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Perhaps they are not so evil after all…$"
# 595 "data/maps/MtPyre_Summit/scripts.pory"

# 596 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_SuperAncientPokemonTaughtUs: @ 8232D1E
# 597 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The embodiments of the land, sea,\n"
# 598 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and the sky…\p"
# 599 "data/maps/MtPyre_Summit/scripts.pory"
	.string "That is said to be the identities of\n"
# 600 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the super-ancient Pokémon…\p"
# 601 "data/maps/MtPyre_Summit/scripts.pory"
	.string "In the same way that we humans and\n"
# 602 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Pokémon have life, our world, too,\l"
# 603 "data/maps/MtPyre_Summit/scripts.pory"
	.string "is alive…\p"
# 604 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The super-ancient Pokémon have\n"
# 605 "data/maps/MtPyre_Summit/scripts.pory"
	.string "taught us that…$"
# 606 "data/maps/MtPyre_Summit/scripts.pory"

# 607 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_WillYouHearOutMyTale: @ 8232E0C
# 608 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Mt. Pyre is where we calm the spirits\n"
# 609 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of Pokémon that have passed on…\p"
# 610 "data/maps/MtPyre_Summit/scripts.pory"
	.string "This is a high place where one can\n"
# 611 "data/maps/MtPyre_Summit/scripts.pory"
	.string "see all of Hoenn…\p"
# 612 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The disembodied spirits of Pokémon\n"
# 613 "data/maps/MtPyre_Summit/scripts.pory"
	.string "must find solace here…\p"
# 614 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Is it coincidence that you are here…\p"
# 615 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Will you hear out my tale? A tale long\n"
# 616 "data/maps/MtPyre_Summit/scripts.pory"
	.string "told in the Hoenn region?$"
# 617 "data/maps/MtPyre_Summit/scripts.pory"

# 618 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_GroudonKyogreTale: @ 8232F27
# 619 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It happened long, long ago…\p"
# 620 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was wracked by a ferocious\n"
# 621 "data/maps/MtPyre_Summit/scripts.pory"
	.string "clash between the Pokémon of the land\l"
# 622 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and the Pokémon of the sea…\p"
# 623 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The Pokémon of the land raised\n"
# 624 "data/maps/MtPyre_Summit/scripts.pory"
	.string "mountains and created continents…\p"
# 625 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The Pokémon of the sea raised huge\n"
# 626 "data/maps/MtPyre_Summit/scripts.pory"
	.string "waves and carved out oceans…\p"
# 627 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Their fierce duel raged without end.\p"
# 628 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was engulfed in massive\n"
# 629 "data/maps/MtPyre_Summit/scripts.pory"
	.string "infernos and vicious storms.\p"
# 630 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The Blue Orb and the Red Orb brought\n"
# 631 "data/maps/MtPyre_Summit/scripts.pory"
	.string "an end to the calamity.\p"
# 632 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Light poured from the two Orbs and\n"
# 633 "data/maps/MtPyre_Summit/scripts.pory"
	.string "becalmed the enraged adversaries.\p"
# 634 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The pair, made docile, dove deep into\n"
# 635 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the sea where eventually they\l"
# 636 "data/maps/MtPyre_Summit/scripts.pory"
	.string "disappeared…$"
# 637 "data/maps/MtPyre_Summit/scripts.pory"

# 638 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_WellThatTooIsFine: @ 8233162
# 639 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I see…\n"
# 640 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Well, that, too, is fine…$"
# 641 "data/maps/MtPyre_Summit/scripts.pory"

# 642 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_MaxieSilence: @ 8233183
# 643 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Maxie: {PLAYER}…\p"
# 644 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …\n"
# 645 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …$"
# 646 "data/maps/MtPyre_Summit/scripts.pory"

# 647 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_HearTheNewLegendOfHoenn: @ 82331A6
# 648 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It is my role to pass on the legends\n"
# 649 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of Hoenn to future generations.\p"
# 650 "data/maps/MtPyre_Summit/scripts.pory"
	.string "And the crisis that just ended in\n"
# 651 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Sootopolis rewrote a legend…\p"
# 652 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Have you the time to hear the new\n"
# 653 "data/maps/MtPyre_Summit/scripts.pory"
	.string "legend of Hoenn?$"
# 654 "data/maps/MtPyre_Summit/scripts.pory"

# 655 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_HoennTrioTale: @ 823325D
# 656 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It happened long, long ago…\p"
# 657 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was wracked by a ferocious\n"
# 658 "data/maps/MtPyre_Summit/scripts.pory"
	.string "clash between the Pokémon of the land\l"
# 659 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and the Pokémon of the sea…\p"
# 660 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The Pokémon of the land raised\n"
# 661 "data/maps/MtPyre_Summit/scripts.pory"
	.string "mountains and created continents…\p"
# 662 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The Pokémon of the sea raised huge\n"
# 663 "data/maps/MtPyre_Summit/scripts.pory"
	.string "waves and carved out oceans…\p"
# 664 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Their fierce duel raged without end.\p"
# 665 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was engulfed in massive\n"
# 666 "data/maps/MtPyre_Summit/scripts.pory"
	.string "fires and vicious storms.\p"
# 667 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It was then that the Pokémon of\n"
# 668 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the sky descended from a storm.\p"
# 669 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The Pokémon, shining a vivid green,\n"
# 670 "data/maps/MtPyre_Summit/scripts.pory"
	.string "becalmed the two enraged Pokémon.\p"
# 671 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Then, its duty done, the green Pokémon\n"
# 672 "data/maps/MtPyre_Summit/scripts.pory"
	.string "flew off into the wild blue yonder…$"
