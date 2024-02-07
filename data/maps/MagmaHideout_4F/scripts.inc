# 1 "data/maps/MagmaHideout_4F/scripts.pory"

# 2 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_GROUDON, 1
# 3 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_GRUNT_1, 2
# 4 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_GRUNT_2, 3
# 5 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_GRUNT_3, 4
# 6 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_TABITHA, 5
# 7 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_MAXIE, 6
# 8 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_GROUDON_SLEEPING, 7
# 9 "data/maps/MagmaHideout_4F/scripts.pory"

# 10 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_MapScripts:: @ 823A55F
# 11 "data/maps/MagmaHideout_4F/scripts.pory"
	.byte 0
# 12 "data/maps/MagmaHideout_4F/scripts.pory"

# 13 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_EventScript_Maxie:: @ 823A560
# 14 "data/maps/MagmaHideout_4F/scripts.pory"
	lockall
# 15 "data/maps/MagmaHideout_4F/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 16 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
# 17 "data/maps/MagmaHideout_4F/scripts.pory"
	closemessage
# 18 "data/maps/MagmaHideout_4F/scripts.pory"
	delay 20
# 19 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_RESULT, 1
# 20 "data/maps/MagmaHideout_4F/scripts.pory"
	playse SE_M_DETECT
# 21 "data/maps/MagmaHideout_4F/scripts.pory"
	dofieldeffectsparkle 18, 42, 0
# 22 "data/maps/MagmaHideout_4F/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 23 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_RESULT, 0
# 24 "data/maps/MagmaHideout_4F/scripts.pory"
	playfanfare MUS_AWAKEN_LEGEND
# 25 "data/maps/MagmaHideout_4F/scripts.pory"
	playse SE_ORB
# 26 "data/maps/MagmaHideout_4F/scripts.pory"
	special DoOrbEffect
# 27 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 28 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 29 "data/maps/MagmaHideout_4F/scripts.pory"
	delay 150
# 30 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_GROUDON_SLEEPING
# 31 "data/maps/MagmaHideout_4F/scripts.pory"
	addobject LOCALID_GROUDON
# 32 "data/maps/MagmaHideout_4F/scripts.pory"
	waitstate
# 33 "data/maps/MagmaHideout_4F/scripts.pory"
	delay 60
# 34 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
# 35 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 36 "data/maps/MagmaHideout_4F/scripts.pory"
	special FadeOutOrbEffect
# 37 "data/maps/MagmaHideout_4F/scripts.pory"
	waitstate
# 38 "data/maps/MagmaHideout_4F/scripts.pory"
	playmoncry SPECIES_GROUDON, 2
# 39 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmoncry
# 40 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 41 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 42 "data/maps/MagmaHideout_4F/scripts.pory"
	delay 30
# 43 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
# 44 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 45 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
# 46 "data/maps/MagmaHideout_4F/scripts.pory"
	closemessage
# 47 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFastestUp
# 48 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 49 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 50 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_MaxieWowItsGroudon, MSGBOX_DEFAULT
# 51 "data/maps/MagmaHideout_4F/scripts.pory"
	closemessage
# 52 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
# 53 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 54 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 55 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_MaxieFightMe, MSGBOX_DEFAULT
# 56 "data/maps/MagmaHideout_4F/scripts.pory"
	closemessage
# 57 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
# 58 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 59 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 60 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 61 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 62 "data/maps/MagmaHideout_4F/scripts.pory"
	special ShakeCamera
# 63 "data/maps/MagmaHideout_4F/scripts.pory"
	waitstate
# 64 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFastestUp
# 65 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 66 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 67 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonExit
# 68 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 69 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_GROUDON
# 70 "data/maps/MagmaHideout_4F/scripts.pory"
	delay 4
# 71 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8004, 2  @ vertical pan
# 72 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 73 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 74 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 75 "data/maps/MagmaHideout_4F/scripts.pory"
	special ShakeCamera
# 76 "data/maps/MagmaHideout_4F/scripts.pory"
	waitstate
# 77 "data/maps/MagmaHideout_4F/scripts.pory"
	delay 30
# 78 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
# 79 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 80 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 81 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
# 82 "data/maps/MagmaHideout_4F/scripts.pory"
	closemessage
# 83 "data/maps/MagmaHideout_4F/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
# 84 "data/maps/MagmaHideout_4F/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
# 85 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_SLATEPORT_CITY_STATE, 1
# 86 "data/maps/MagmaHideout_4F/scripts.pory"
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
# 87 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
# 88 "data/maps/MagmaHideout_4F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 89 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_MAXIE
# 90 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 91 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 92 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_GRUNT_3
# 93 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_TABITHA
# 94 "data/maps/MagmaHideout_4F/scripts.pory"
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
# 95 "data/maps/MagmaHideout_4F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 96 "data/maps/MagmaHideout_4F/scripts.pory"
	releaseall
# 97 "data/maps/MagmaHideout_4F/scripts.pory"
	end
# 98 "data/maps/MagmaHideout_4F/scripts.pory"

# 99 "data/maps/MagmaHideout_4F/scripts.pory"
	@msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
# 100 "data/maps/MagmaHideout_4F/scripts.pory"
	@closemessage
# 101 "data/maps/MagmaHideout_4F/scripts.pory"

# 102 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Movement_GroudonApproach: @ 823A672
# 103 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 104 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 105 "data/maps/MagmaHideout_4F/scripts.pory"
	walk_slow_down
# 106 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 107 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 108 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 109 "data/maps/MagmaHideout_4F/scripts.pory"
	walk_slow_down
# 110 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 111 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 112 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 113 "data/maps/MagmaHideout_4F/scripts.pory"
	step_end
# 114 "data/maps/MagmaHideout_4F/scripts.pory"

# 115 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Movement_GroudonExit: @ 823A67D
# 116 "data/maps/MagmaHideout_4F/scripts.pory"
	slide_up
# 117 "data/maps/MagmaHideout_4F/scripts.pory"
	slide_up
# 118 "data/maps/MagmaHideout_4F/scripts.pory"
	step_end
# 119 "data/maps/MagmaHideout_4F/scripts.pory"

# 120 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Movement_MaxieLookAround: @ 823A680
# 121 "data/maps/MagmaHideout_4F/scripts.pory"
	face_left
# 122 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 123 "data/maps/MagmaHideout_4F/scripts.pory"
	face_right
# 124 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 125 "data/maps/MagmaHideout_4F/scripts.pory"
	face_left
# 126 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 127 "data/maps/MagmaHideout_4F/scripts.pory"
	face_right
# 128 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 129 "data/maps/MagmaHideout_4F/scripts.pory"
	face_up
# 130 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 131 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 132 "data/maps/MagmaHideout_4F/scripts.pory"
	step_end
# 133 "data/maps/MagmaHideout_4F/scripts.pory"

# 134 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_EventScript_Grunt11:: @ 823A68C
# 135 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
# 136 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
# 137 "data/maps/MagmaHideout_4F/scripts.pory"
	end
# 138 "data/maps/MagmaHideout_4F/scripts.pory"

# 139 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_EventScript_Grunt12:: @ 823A6A3
# 140 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
# 141 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
# 142 "data/maps/MagmaHideout_4F/scripts.pory"
	end
# 143 "data/maps/MagmaHideout_4F/scripts.pory"

# 144 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_EventScript_Grunt13:: @ 823A6BA
# 145 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
# 146 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
# 147 "data/maps/MagmaHideout_4F/scripts.pory"
	end
# 148 "data/maps/MagmaHideout_4F/scripts.pory"

# 149 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_EventScript_Tabitha::
# 150 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
# 151 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
# 152 "data/maps/MagmaHideout_4F/scripts.pory"
	end
# 153 "data/maps/MagmaHideout_4F/scripts.pory"

# 154 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_EventScript_Courtney::
# 155 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_single TRAINER_COURTNEY_MAGMA_HIDEOUT, MagmaHideout_4F_Text_CourtneyIntro, MagmaHideout_4F_Text_CourtneyDefeat
# 156 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_CourtneyPostBattle, MSGBOX_AUTOCLOSE
# 157 "data/maps/MagmaHideout_4F/scripts.pory"
	end
# 158 "data/maps/MagmaHideout_4F/scripts.pory"

# 159 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt11Intro: @ 823A6E8
# 160 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I want to see Groudon, too, but they\n"
# 161 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "won't let me see even its tail…\p"
# 162 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "It's got me feeling really frustrated.\p"
# 163 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Oh, no!\n"
# 164 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I blabbed about Groudon!$"
# 165 "data/maps/MagmaHideout_4F/scripts.pory"

# 166 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt11Defeat: @ 823A775
# 167 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I guess it's impossible to win if one\n"
# 168 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "doesn't have a calm mind…$"
# 169 "data/maps/MagmaHideout_4F/scripts.pory"

# 170 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt11PostBattle: @ 823A7B5
# 171 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I wonder if Groudon even has a tail?$"
# 172 "data/maps/MagmaHideout_4F/scripts.pory"

# 173 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt12Intro: @ 823A7DA
# 174 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Fuhahaha!\n"
# 175 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Soon! Very soon!\l"
# 176 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Our grand objective will be achieved!$"
# 177 "data/maps/MagmaHideout_4F/scripts.pory"

# 178 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt12Defeat: @ 823A81B
# 179 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Grrr…\n"
# 180 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I've come so far, but now this?$"
# 181 "data/maps/MagmaHideout_4F/scripts.pory"

# 182 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt12PostBattle: @ 823A841
# 183 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Maxie, sir!\n"
# 184 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "An intruder is headed your way!$"
# 185 "data/maps/MagmaHideout_4F/scripts.pory"

# 186 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt13Intro: @ 823A86D
# 187 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "You're not finished yet!\n"
# 188 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "You're not getting by me easily!$"
# 189 "data/maps/MagmaHideout_4F/scripts.pory"

# 190 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt13Defeat: @ 823A8A7
# 191 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Was I that easy to knock down?$"
# 192 "data/maps/MagmaHideout_4F/scripts.pory"

# 193 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt13PostBattle: @ 823A8C6
# 194 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "C-come on, one more match…$"
# 195 "data/maps/MagmaHideout_4F/scripts.pory"

# 196 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_TabithaIntro: @ 823A8E1
# 197 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Hehehe!\n"
# 198 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "You made it this far, so I'll tell you!\p"
# 199 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "That's right!\n"
# 200 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Up ahead, Groudon is sleeping!\p"
# 201 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Maxie went to Groudon just seconds\n"
# 202 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "ago!\p"
# 203 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "It's going to awaken real soon!\n"
# 204 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Hehe! Hehehe!$"
# 205 "data/maps/MagmaHideout_4F/scripts.pory"

# 206 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_TabithaDefeat: @ 823A994
# 207 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Taken down again…\n"
# 208 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Hehe…$"
# 209 "data/maps/MagmaHideout_4F/scripts.pory"

# 210 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_TabithaPostBattle: @ 823A9AC
# 211 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "…And while you wasted time with us,\n"
# 212 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Maxie should have awakened Groudon…$"
# 213 "data/maps/MagmaHideout_4F/scripts.pory"

# 214 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_CourtneyIntro:
# 215 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Ahahaha!\n"
# 216 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "So glad you could make it, brat!\p"
# 217 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "You're just in time to watch Team Magma's\n"
# 218 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "ambitions become reality!\p"
# 219 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "With Groudon's power, we'll expand the\n"
# 220 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "landmass for the good of all!$"
# 221 "data/maps/MagmaHideout_4F/scripts.pory"

# 222 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_CourtneyDefeat:
# 223 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Ahaha… ha…\n"
# 224 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "That could have gone better…$"
# 225 "data/maps/MagmaHideout_4F/scripts.pory"

# 226 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_CourtneyPostBattle:
# 227 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "You might have beaten us, but we're\n"
# 228 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "still the winners here!$"
# 229 "data/maps/MagmaHideout_4F/scripts.pory"

# 230 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_MaxieAwakenGroudon: @ 823A9F4
# 231 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Maxie: Groudon…\p"
# 232 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Nothing could awaken you from your\n"
# 233 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "sleep bathed in magma…\p"
# 234 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "This Red Orb is what you sought.\n"
# 235 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Wasn't it?\p"
# 236 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I have brought you the Red Orb.\n"
# 237 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Let its shine awaken you!\p"
# 238 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "And show me…\n"
# 239 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Show me the full extent of your power!$"
# 240 "data/maps/MagmaHideout_4F/scripts.pory"

# 241 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_MaxieGroudonWhatsWrong: @ 823AADA
# 242 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Maxie: Groudon!\n"
# 243 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "What's wrong?\p"
# 244 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Wasn't the Red Orb the key?\p"
# 245 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Groudon!\n"
# 246 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Where have you gone…$"
# 247 "data/maps/MagmaHideout_4F/scripts.pory"

# 248 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_MaxieOhItWasYou: @ 823AB33
# 249 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Maxie: Oh? You again?\p"
# 250 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I've seen you poking around uninvited\n"
# 251 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "here and there…\p"
# 252 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I suppose you came to meddle in our\n"
# 253 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "affairs yet again?\p"
# 254 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Or perhaps you wanted to see Groudon\n"
# 255 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "up close? Very well…$"
# 256 "data/maps/MagmaHideout_4F/scripts.pory"

# 257 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_MaxieWowItsGroudon:
# 258 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Maxie: Behold! Groudon, the\n"
# 259 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "super-ancient Pokémon of the land!\p"
# 260 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "With the Red Orb in my possession, I\n"
# 261 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "have complete control over it.$"
# 262 "data/maps/MagmaHideout_4F/scripts.pory"

# 263 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_MaxieFightMe:
# 264 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Maxie: With Groudon's power, Team Magma's\n"
# 265 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "grand ambition will finally be realized!\p"
# 266 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Maxie: But first… I shall put an end\n"
# 267 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "to your meddling, once and for all!$"
# 268 "data/maps/MagmaHideout_4F/scripts.pory"

# 269 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_MaxieDefeat: @ 823ABB5
# 270 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "What makes you so adept at handling\n"
# 271 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Pokémon?$"
# 272 "data/maps/MagmaHideout_4F/scripts.pory"

# 273 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_MaxieImGoingAfterGroudon: @ 823ABE2
# 274 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Maxie: No!\p"
# 275 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "It seems you defeating Groudon was\n"
# 276 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "enough to free it from my control…\n"
# 277 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "With Groudon gone, there is no longer\n"
# 278 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "any need for this blasted volcano.\p"
# 279 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I am going after Groudon, so this\n"
# 280 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "is where we part!$"
