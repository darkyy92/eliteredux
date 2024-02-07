# 1 "data/maps/FallarborTown/scripts.pory"

# 2 "data/maps/FallarborTown/scripts.pory"
FallarborTown_MapScripts:: @ 81EB1FA
# 3 "data/maps/FallarborTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
# 4 "data/maps/FallarborTown/scripts.pory"
	.byte 0
# 5 "data/maps/FallarborTown/scripts.pory"

# 6 "data/maps/FallarborTown/scripts.pory"
FallarborTown_OnTransition: @ 81EB200
# 7 "data/maps/FallarborTown/scripts.pory"
	setflag FLAG_VISITED_FALLARBOR_TOWN
# 8 "data/maps/FallarborTown/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 9 "data/maps/FallarborTown/scripts.pory"
	clearflag FLAG_CONTEST_SKETCH_CREATED
# 10 "data/maps/FallarborTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 11 "data/maps/FallarborTown/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 12 "data/maps/FallarborTown/scripts.pory"
	end
# 13 "data/maps/FallarborTown/scripts.pory"

# 14 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_ExpertM:: @ 81EB20C
# 15 "data/maps/FallarborTown/scripts.pory"
	lock
# 16 "data/maps/FallarborTown/scripts.pory"
	faceplayer
# 17 "data/maps/FallarborTown/scripts.pory"
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
# 18 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
# 19 "data/maps/FallarborTown/scripts.pory"
	release
# 20 "data/maps/FallarborTown/scripts.pory"
	end
# 21 "data/maps/FallarborTown/scripts.pory"

# 22 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_ExpertMNormal:: @ 81EB221
# 23 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
# 24 "data/maps/FallarborTown/scripts.pory"
	release
# 25 "data/maps/FallarborTown/scripts.pory"
	end
# 26 "data/maps/FallarborTown/scripts.pory"

# 27 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_Girl:: @ 81EB22B
# 28 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
# 29 "data/maps/FallarborTown/scripts.pory"
	end
# 30 "data/maps/FallarborTown/scripts.pory"

# 31 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_Gentleman:: @ 81EB234
# 32 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
# 33 "data/maps/FallarborTown/scripts.pory"
	end
# 34 "data/maps/FallarborTown/scripts.pory"

# 35 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_Azurill:: @ 81EB23D
# 36 "data/maps/FallarborTown/scripts.pory"
	lock
# 37 "data/maps/FallarborTown/scripts.pory"
	faceplayer
# 38 "data/maps/FallarborTown/scripts.pory"
	waitse
# 39 "data/maps/FallarborTown/scripts.pory"
	playmoncry SPECIES_AZURILL, 0
# 40 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
# 41 "data/maps/FallarborTown/scripts.pory"
	waitmoncry
# 42 "data/maps/FallarborTown/scripts.pory"
	release
# 43 "data/maps/FallarborTown/scripts.pory"
	end
# 44 "data/maps/FallarborTown/scripts.pory"

# 45 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_BattleTentSign:: @ 81EB250
# 46 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
# 47 "data/maps/FallarborTown/scripts.pory"
	end
# 48 "data/maps/FallarborTown/scripts.pory"

# 49 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_TownSign:: @ 81EB259
# 50 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
# 51 "data/maps/FallarborTown/scripts.pory"
	end
# 52 "data/maps/FallarborTown/scripts.pory"

# 53 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_MoveTutorSign:: @ 81EB262
# 54 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
# 55 "data/maps/FallarborTown/scripts.pory"
	end
# 56 "data/maps/FallarborTown/scripts.pory"

# 57 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_RivalTrigger1::
# 58 "data/maps/FallarborTown/scripts.pory"
	setvar VAR_0x8004, 1
# 59 "data/maps/FallarborTown/scripts.pory"
	goto FallarborTown_EventScript_RivalScene
# 60 "data/maps/FallarborTown/scripts.pory"
	end
# 61 "data/maps/FallarborTown/scripts.pory"

# 62 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_RivalTrigger2::
# 63 "data/maps/FallarborTown/scripts.pory"
	setvar VAR_0x8004, 2
# 64 "data/maps/FallarborTown/scripts.pory"
	goto FallarborTown_EventScript_RivalScene
# 65 "data/maps/FallarborTown/scripts.pory"
	end
# 66 "data/maps/FallarborTown/scripts.pory"

# 67 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_RivalTrigger3::
# 68 "data/maps/FallarborTown/scripts.pory"
	setvar VAR_0x8004, 3
# 69 "data/maps/FallarborTown/scripts.pory"
	goto FallarborTown_EventScript_RivalScene
# 70 "data/maps/FallarborTown/scripts.pory"
	end
# 71 "data/maps/FallarborTown/scripts.pory"

# 72 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_RivalTrigger4::
# 73 "data/maps/FallarborTown/scripts.pory"
	setvar VAR_0x8004, 4
# 74 "data/maps/FallarborTown/scripts.pory"
	goto FallarborTown_EventScript_RivalScene
# 75 "data/maps/FallarborTown/scripts.pory"
	end
# 76 "data/maps/FallarborTown/scripts.pory"
	
# 77 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_RivalTrigger5::
# 78 "data/maps/FallarborTown/scripts.pory"
	setvar VAR_0x8004, 5
# 79 "data/maps/FallarborTown/scripts.pory"
	goto FallarborTown_EventScript_RivalScene
# 80 "data/maps/FallarborTown/scripts.pory"
	end
# 81 "data/maps/FallarborTown/scripts.pory"

# 82 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_RivalScene::
# 83 "data/maps/FallarborTown/scripts.pory"
	lockall
# 84 "data/maps/FallarborTown/scripts.pory"
	playse SE_PIN
# 85 "data/maps/FallarborTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 86 "data/maps/FallarborTown/scripts.pory"
	applymovement 5, Common_Movement_ExclamationMark
# 87 "data/maps/FallarborTown/scripts.pory"
	waitmovement 0
# 88 "data/maps/FallarborTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
# 89 "data/maps/FallarborTown/scripts.pory"
	waitmovement 0
# 90 "data/maps/FallarborTown/scripts.pory"
	checkplayergender
# 91 "data/maps/FallarborTown/scripts.pory"
	compare VAR_RESULT, MALE
# 92 "data/maps/FallarborTown/scripts.pory"
	goto_if_eq FallarborTown_EventScript_MayScene
# 93 "data/maps/FallarborTown/scripts.pory"
	compare VAR_RESULT, FEMALE
# 94 "data/maps/FallarborTown/scripts.pory"
	goto_if_eq FallarborTown_EventScript_BrendanScene
# 95 "data/maps/FallarborTown/scripts.pory"

# 96 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_MayScene::
# 97 "data/maps/FallarborTown/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, 1
# 98 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_MayDisaster, MSGBOX_DEFAULT
# 99 "data/maps/FallarborTown/scripts.pory"
	closemessage
# 100 "data/maps/FallarborTown/scripts.pory"
	call FallarborTown_EventScript_MoveToPlayer
# 101 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_MayWeirdos, MSGBOX_DEFAULT
# 102 "data/maps/FallarborTown/scripts.pory"
	closemessage
# 103 "data/maps/FallarborTown/scripts.pory"
	goto FallarborTown_EventScript_RivalExit
# 104 "data/maps/FallarborTown/scripts.pory"

# 105 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_BrendanScene::
# 106 "data/maps/FallarborTown/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, 1
# 107 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_BrendanComeHere, MSGBOX_DEFAULT
# 108 "data/maps/FallarborTown/scripts.pory"
	closemessage
# 109 "data/maps/FallarborTown/scripts.pory"
	call FallarborTown_EventScript_MoveToPlayer
# 110 "data/maps/FallarborTown/scripts.pory"
	msgbox FallarborTown_Text_BrendanNuts, MSGBOX_DEFAULT
# 111 "data/maps/FallarborTown/scripts.pory"
	closemessage
# 112 "data/maps/FallarborTown/scripts.pory"
	goto FallarborTown_EventScript_RivalExit
# 113 "data/maps/FallarborTown/scripts.pory"

# 114 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_RivalExit::
# 115 "data/maps/FallarborTown/scripts.pory"
	setobjectxyperm 6, 12, 10
# 116 "data/maps/FallarborTown/scripts.pory"
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_DOWN
# 117 "data/maps/FallarborTown/scripts.pory"
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_DOWN
# 118 "data/maps/FallarborTown/scripts.pory"
	removeobject 5
# 119 "data/maps/FallarborTown/scripts.pory"
	addobject 6
# 120 "data/maps/FallarborTown/scripts.pory"
	delay 45
# 121 "data/maps/FallarborTown/scripts.pory"
	applymovement 6, FallarborTown_Movement_RivalExit
# 122 "data/maps/FallarborTown/scripts.pory"
	waitmovement 0
# 123 "data/maps/FallarborTown/scripts.pory"
	removeobject 6
# 124 "data/maps/FallarborTown/scripts.pory"
	setvar VAR_FALLARBOR_TOWN_STATE, 1
# 125 "data/maps/FallarborTown/scripts.pory"
	savebgm MUS_DUMMY
# 126 "data/maps/FallarborTown/scripts.pory"
	fadedefaultbgm
# 127 "data/maps/FallarborTown/scripts.pory"
	releaseall
# 128 "data/maps/FallarborTown/scripts.pory"
	end
# 129 "data/maps/FallarborTown/scripts.pory"

# 130 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_MoveToPlayer::
# 131 "data/maps/FallarborTown/scripts.pory"
	compare VAR_0x8004, 1
# 132 "data/maps/FallarborTown/scripts.pory"
	call_if_eq FallarborTown_EventScript_PlayerApproach1
# 133 "data/maps/FallarborTown/scripts.pory"
	compare VAR_0x8004, 2
# 134 "data/maps/FallarborTown/scripts.pory"
	call_if_eq FallarborTown_EventScript_PlayerApproach2
# 135 "data/maps/FallarborTown/scripts.pory"
	compare VAR_0x8004, 3
# 136 "data/maps/FallarborTown/scripts.pory"
	call_if_eq FallarborTown_EventScript_PlayerApproach3
# 137 "data/maps/FallarborTown/scripts.pory"
	compare VAR_0x8004, 4
# 138 "data/maps/FallarborTown/scripts.pory"
	call_if_eq FallarborTown_EventScript_PlayerApproach4
# 139 "data/maps/FallarborTown/scripts.pory"
	compare VAR_0x8004, 5
# 140 "data/maps/FallarborTown/scripts.pory"
	call_if_eq FallarborTown_EventScript_PlayerApproach5
# 141 "data/maps/FallarborTown/scripts.pory"
	return
# 142 "data/maps/FallarborTown/scripts.pory"

# 143 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_PlayerApproach1::
# 144 "data/maps/FallarborTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_Movement_PlayerApproach1
# 145 "data/maps/FallarborTown/scripts.pory"
	applymovement 5, FallarborTown_Movement_RivalApproach
# 146 "data/maps/FallarborTown/scripts.pory"
	waitmovement 0
# 147 "data/maps/FallarborTown/scripts.pory"
	return
# 148 "data/maps/FallarborTown/scripts.pory"

# 149 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_PlayerApproach2::
# 150 "data/maps/FallarborTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_Movement_PlayerApproach2
# 151 "data/maps/FallarborTown/scripts.pory"
	applymovement 5, FallarborTown_Movement_RivalApproach
# 152 "data/maps/FallarborTown/scripts.pory"
	waitmovement 0
# 153 "data/maps/FallarborTown/scripts.pory"
	return
# 154 "data/maps/FallarborTown/scripts.pory"

# 155 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_PlayerApproach3::
# 156 "data/maps/FallarborTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_Movement_PlayerApproach3
# 157 "data/maps/FallarborTown/scripts.pory"
	applymovement 5, FallarborTown_Movement_RivalApproach
# 158 "data/maps/FallarborTown/scripts.pory"
	waitmovement 0
# 159 "data/maps/FallarborTown/scripts.pory"
	return
# 160 "data/maps/FallarborTown/scripts.pory"

# 161 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_PlayerApproach4::
# 162 "data/maps/FallarborTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_Movement_PlayerApproach4
# 163 "data/maps/FallarborTown/scripts.pory"
	applymovement 5, FallarborTown_Movement_RivalApproach
# 164 "data/maps/FallarborTown/scripts.pory"
	waitmovement 0
# 165 "data/maps/FallarborTown/scripts.pory"
	return
# 166 "data/maps/FallarborTown/scripts.pory"

# 167 "data/maps/FallarborTown/scripts.pory"
FallarborTown_EventScript_PlayerApproach5::
# 168 "data/maps/FallarborTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_Movement_PlayerApproach5
# 169 "data/maps/FallarborTown/scripts.pory"
	applymovement 5, FallarborTown_Movement_RivalApproach
# 170 "data/maps/FallarborTown/scripts.pory"
	waitmovement 0
# 171 "data/maps/FallarborTown/scripts.pory"
	return
# 172 "data/maps/FallarborTown/scripts.pory"

# 173 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Movement_PlayerApproach1:
# 174 "data/maps/FallarborTown/scripts.pory"
	walk_down
# 175 "data/maps/FallarborTown/scripts.pory"
	walk_down
# 176 "data/maps/FallarborTown/scripts.pory"
	face_left
# 177 "data/maps/FallarborTown/scripts.pory"
	step_end
# 178 "data/maps/FallarborTown/scripts.pory"

# 179 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Movement_PlayerApproach2:
# 180 "data/maps/FallarborTown/scripts.pory"
	walk_down
# 181 "data/maps/FallarborTown/scripts.pory"
	face_left
# 182 "data/maps/FallarborTown/scripts.pory"
	step_end
# 183 "data/maps/FallarborTown/scripts.pory"

# 184 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Movement_PlayerApproach3:
# 185 "data/maps/FallarborTown/scripts.pory"
	face_left
# 186 "data/maps/FallarborTown/scripts.pory"
	step_end
# 187 "data/maps/FallarborTown/scripts.pory"

# 188 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Movement_PlayerApproach4:
# 189 "data/maps/FallarborTown/scripts.pory"
	walk_up
# 190 "data/maps/FallarborTown/scripts.pory"
	face_left
# 191 "data/maps/FallarborTown/scripts.pory"
	step_end
# 192 "data/maps/FallarborTown/scripts.pory"

# 193 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Movement_PlayerApproach5:
# 194 "data/maps/FallarborTown/scripts.pory"
	walk_up
# 195 "data/maps/FallarborTown/scripts.pory"
	walk_up
# 196 "data/maps/FallarborTown/scripts.pory"
	face_left
# 197 "data/maps/FallarborTown/scripts.pory"
	step_end
# 198 "data/maps/FallarborTown/scripts.pory"

# 199 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Movement_RivalApproach:
# 200 "data/maps/FallarborTown/scripts.pory"
	walk_fast_right
# 201 "data/maps/FallarborTown/scripts.pory"
	walk_fast_right
# 202 "data/maps/FallarborTown/scripts.pory"
	walk_fast_right
# 203 "data/maps/FallarborTown/scripts.pory"
	walk_fast_right
# 204 "data/maps/FallarborTown/scripts.pory"
	walk_fast_right
# 205 "data/maps/FallarborTown/scripts.pory"
	walk_fast_right
# 206 "data/maps/FallarborTown/scripts.pory"
	step_end
# 207 "data/maps/FallarborTown/scripts.pory"

# 208 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Movement_RivalExit:
# 209 "data/maps/FallarborTown/scripts.pory"
	walk_fast_left
# 210 "data/maps/FallarborTown/scripts.pory"
	walk_fast_left
# 211 "data/maps/FallarborTown/scripts.pory"
	walk_fast_left
# 212 "data/maps/FallarborTown/scripts.pory"
	walk_fast_left
# 213 "data/maps/FallarborTown/scripts.pory"
	walk_fast_left
# 214 "data/maps/FallarborTown/scripts.pory"
	walk_fast_left
# 215 "data/maps/FallarborTown/scripts.pory"
	walk_fast_left
# 216 "data/maps/FallarborTown/scripts.pory"
	walk_fast_left
# 217 "data/maps/FallarborTown/scripts.pory"
	step_end
# 218 "data/maps/FallarborTown/scripts.pory"

# 219 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_MayDisaster:
# 220 "data/maps/FallarborTown/scripts.pory"
	.string "May: Oh! {PLAYER}{KUN}! Help!$"
# 221 "data/maps/FallarborTown/scripts.pory"

# 222 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_BrendanComeHere:
# 223 "data/maps/FallarborTown/scripts.pory"
	.string "Brendan: {PLAYER}! C'mere!$"
# 224 "data/maps/FallarborTown/scripts.pory"

# 225 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_MayWeirdos:
# 226 "data/maps/FallarborTown/scripts.pory"
	.string "May: You've got to come with me!\p"
# 227 "data/maps/FallarborTown/scripts.pory"
	.string "Y-you see…\n"
# 228 "data/maps/FallarborTown/scripts.pory"
	.string "Professor Cozmo…\p"
# 229 "data/maps/FallarborTown/scripts.pory"
	.string "He got abducted by some weirdos\n"
# 230 "data/maps/FallarborTown/scripts.pory"
	.string "calling themselves Team Magma!\p"
# 231 "data/maps/FallarborTown/scripts.pory"
	.string "{PLAYER}{KUN}, please…\n"
# 232 "data/maps/FallarborTown/scripts.pory"
	.string "You've got to help me save him!\p"
# 233 "data/maps/FallarborTown/scripts.pory"
	.string "I… I'm going to head after them\n"
# 234 "data/maps/FallarborTown/scripts.pory"
	.string "right away!\l"
# 235 "data/maps/FallarborTown/scripts.pory"
	.string "Let's meet up at Meteor Falls!$"
# 236 "data/maps/FallarborTown/scripts.pory"

# 237 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_BrendanNuts:
# 238 "data/maps/FallarborTown/scripts.pory"
	.string "Brendan: Everything's a mess!\p"
# 239 "data/maps/FallarborTown/scripts.pory"
	.string "It's ridiculous…\n"
# 240 "data/maps/FallarborTown/scripts.pory"
	.string "Professor Cozmo…\p"
# 241 "data/maps/FallarborTown/scripts.pory"
	.string "They say that he was just up and\n"
# 242 "data/maps/FallarborTown/scripts.pory"
	.string "kidnapped by some nuts calling\l"
# 243 "data/maps/FallarborTown/scripts.pory"
	.string "themselves Team Magma!\p"
# 244 "data/maps/FallarborTown/scripts.pory"
	.string "{PLAYER}… I know it's a lot to ask,\n"
# 245 "data/maps/FallarborTown/scripts.pory"
	.string "but we've gotta help Cozmo!\p"
# 246 "data/maps/FallarborTown/scripts.pory"
	.string "I'm going to head to Meteor Falls\n"
# 247 "data/maps/FallarborTown/scripts.pory"
	.string "right away. Come catch up to me\l"
# 248 "data/maps/FallarborTown/scripts.pory"
	.string "as soon as you can.$"
# 249 "data/maps/FallarborTown/scripts.pory"

# 250 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_ShadyCharactersCozmosHome: @ 81EB26B
# 251 "data/maps/FallarborTown/scripts.pory"
	.string "Something's happening,\n"
# 252 "data/maps/FallarborTown/scripts.pory"
	.string "and I don't like it!\p"
# 253 "data/maps/FallarborTown/scripts.pory"
	.string "I've seen shady characters wandering\n"
# 254 "data/maps/FallarborTown/scripts.pory"
	.string "in and out of Prof. Cozmo's home…$"
# 255 "data/maps/FallarborTown/scripts.pory"

# 256 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_RegionKnownForMeteors: @ 81EB2DE
# 257 "data/maps/FallarborTown/scripts.pory"
	.string "This region's been known for meteors\n"
# 258 "data/maps/FallarborTown/scripts.pory"
	.string "since the olden days.\p"
# 259 "data/maps/FallarborTown/scripts.pory"
	.string "They say Meteor Falls was gouged out\n"
# 260 "data/maps/FallarborTown/scripts.pory"
	.string "by a falling meteorite long ago.$"
# 261 "data/maps/FallarborTown/scripts.pory"

# 262 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_MyPreciousAzurill: @ 81EB35F
# 263 "data/maps/FallarborTown/scripts.pory"
	.string "See! Take a look!\n"
# 264 "data/maps/FallarborTown/scripts.pory"
	.string "This is my precious Azurill!\p"
# 265 "data/maps/FallarborTown/scripts.pory"
	.string "It's slick and smooth and plushy, too!$"
# 266 "data/maps/FallarborTown/scripts.pory"

# 267 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_Azurill: @ 81EB3B5
# 268 "data/maps/FallarborTown/scripts.pory"
	.string "Azurill: Rooreelooo.$"
# 269 "data/maps/FallarborTown/scripts.pory"

# 270 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_HaveYouChallengedFlannery: @ 81EB3CA
# 271 "data/maps/FallarborTown/scripts.pory"
	.string "Have you already challenged Flannery,\n"
# 272 "data/maps/FallarborTown/scripts.pory"
	.string "the Leader of Lavaridge Gym?\p"
# 273 "data/maps/FallarborTown/scripts.pory"
	.string "The girl's grandfather was famous.\n"
# 274 "data/maps/FallarborTown/scripts.pory"
	.string "He was one of the Elite Four in the\l"
# 275 "data/maps/FallarborTown/scripts.pory"
	.string "Pokémon League at one point.\p"
# 276 "data/maps/FallarborTown/scripts.pory"
	.string "It wouldn't surprise me to see Flannery\n"
# 277 "data/maps/FallarborTown/scripts.pory"
	.string "become a great Trainer in her own\l"
# 278 "data/maps/FallarborTown/scripts.pory"
	.string "right.$"
# 279 "data/maps/FallarborTown/scripts.pory"

# 280 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_BattleTentSign: @ 81EB4C2
# 281 "data/maps/FallarborTown/scripts.pory"
	.string "Battle Tent Fallarbor Site\n"
# 282 "data/maps/FallarborTown/scripts.pory"
	.string "“May the Greatest Teams Gather!”$"
# 283 "data/maps/FallarborTown/scripts.pory"

# 284 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_TownSign: @ 81EB4FE
# 285 "data/maps/FallarborTown/scripts.pory"
	.string "Fallarbor Town\n"
# 286 "data/maps/FallarborTown/scripts.pory"
	.string "“A farm community with small gardens.”$"
# 287 "data/maps/FallarborTown/scripts.pory"

# 288 "data/maps/FallarborTown/scripts.pory"
FallarborTown_Text_MoveTutorSign: @ 81EB534
# 289 "data/maps/FallarborTown/scripts.pory"
	.string "Ivy and Evie's House\n"
# 290 "data/maps/FallarborTown/scripts.pory"
	.string "Abandoned.$"
