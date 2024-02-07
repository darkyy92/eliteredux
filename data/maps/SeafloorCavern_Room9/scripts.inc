# 1 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 2 "data/maps/SeafloorCavern_Room9/scripts.pory"
.set LOCALID_KYOGRE, 1
# 3 "data/maps/SeafloorCavern_Room9/scripts.pory"
.set LOCALID_ARCHIE, 2
# 4 "data/maps/SeafloorCavern_Room9/scripts.pory"
.set LOCALID_MAXIE, 3
# 5 "data/maps/SeafloorCavern_Room9/scripts.pory"
.set LOCALID_GRUNT_1, 4
# 6 "data/maps/SeafloorCavern_Room9/scripts.pory"
.set LOCALID_GRUNT_2, 5
# 7 "data/maps/SeafloorCavern_Room9/scripts.pory"
.set LOCALID_KYOGRE_SLEEPING, 6
# 8 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 9 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_MapScripts:: @ 8234DC8
# 10 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.byte 0
# 11 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 12 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre:: @ 8234DC9
# 13 "data/maps/SeafloorCavern_Room9/scripts.pory"
	lockall
# 14 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, LOCALID_ARCHIE
# 15 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, LOCALID_MAXIE
# 16 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, LOCALID_GRUNT_1
# 17 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, LOCALID_GRUNT_2
# 18 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 19 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 20 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
# 21 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 22 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 23 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
# 24 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 25 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8004
# 26 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 27 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 28 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
# 29 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 30 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
# 31 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestUp
# 32 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 33 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
# 34 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_FacePlayer
# 35 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 36 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setweather WEATHER_NONE
# 37 "data/maps/SeafloorCavern_Room9/scripts.pory"
	doweather
# 38 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special Script_FadeOutMapMusic
# 39 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 40 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestUp
# 41 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 42 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_BlueOrbShinesByItself, MSGBOX_DEFAULT
# 43 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special WaitWeather
# 44 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 45 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_RESULT, 1
# 46 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_M_DETECT
# 47 "data/maps/SeafloorCavern_Room9/scripts.pory"
	dofieldeffectsparkle 16, 42, 0
# 48 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 49 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 50 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_RESULT, 1
# 51 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playfanfare MUS_AWAKEN_LEGEND
# 52 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_ORB
# 53 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special DoOrbEffect
# 54 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestUp
# 55 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 56 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 57 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 150
# 58 "data/maps/SeafloorCavern_Room9/scripts.pory"
	removeobject LOCALID_KYOGRE_SLEEPING
# 59 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject LOCALID_KYOGRE
# 60 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 61 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 60
# 62 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
# 63 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 64 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special FadeOutOrbEffect
# 65 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 66 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playmoncry SPECIES_KYOGRE, 2
# 67 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmoncry
# 68 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_FacePlayer
# 69 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 70 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 71 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
# 72 "data/maps/SeafloorCavern_Room9/scripts.pory"
	trainerbattle_no_intro TRAINER_ARCHIE, SeafloorCavern_Room9_Text_ArchieDefeat
# 73 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisBlueOrb, MSGBOX_DEFAULT
# 74 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestUp
# 75 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 76 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 77 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 78 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 79 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 80 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special ShakeCamera
# 81 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 82 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
# 83 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 84 "data/maps/SeafloorCavern_Room9/scripts.pory"
	removeobject LOCALID_KYOGRE
# 85 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 4
# 86 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, 2  @ vertical pan
# 87 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 88 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 89 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 90 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special ShakeCamera
# 91 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 92 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 30
# 93 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, LOCALID_ARCHIE
# 94 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, LOCALID_MAXIE
# 95 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, LOCALID_GRUNT_1
# 96 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, LOCALID_GRUNT_2
# 97 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
# 98 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_PC_LOGIN
# 99 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 100 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 101 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
# 102 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 103 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
# 104 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 105 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
# 106 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 107 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_PC_OFF
# 108 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 20
# 109 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestDown
# 110 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 111 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
# 112 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 113 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8005
# 114 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8006
# 115 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8007
# 116 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
# 117 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
# 118 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
# 119 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 120 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestLeft
# 121 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 122 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
# 123 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_PIN
# 124 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
# 125 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 126 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_Delay48
# 127 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 128 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
# 129 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
# 130 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 131 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
# 132 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
# 133 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 134 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
# 135 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_ROUTE128_STATE, 1
# 136 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 1
# 137 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
# 138 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
# 139 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
# 140 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
# 141 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
# 142 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
# 143 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
# 144 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 145 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_128_ARCHIE
# 146 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_128_MAXIE
# 147 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_SYS_WEATHER_CTRL
# 148 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
# 149 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
# 150 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_STEVENS_HOUSE_STATE, 2
# 151 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
# 152 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
# 153 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
# 154 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
# 155 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
# 156 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
# 157 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 158 "data/maps/SeafloorCavern_Room9/scripts.pory"
	warp MAP_ROUTE128, 255, 38, 22
# 159 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 160 "data/maps/SeafloorCavern_Room9/scripts.pory"
	releaseall
# 161 "data/maps/SeafloorCavern_Room9/scripts.pory"
	end
# 162 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 163 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_ArchieApproachPlayer: @ 823502A
# 164 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 165 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 166 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 167 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 168 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 169 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 170 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 171 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 172 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 173 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_Unused1: @ 8235032
# 174 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_left
# 175 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_left
# 176 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 177 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 178 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_ArchieListenMessage: @ 8235035
# 179 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_left
# 180 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 181 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 182 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 183 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_Unused2: @ 8235038
# 184 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 185 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 186 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 187 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_ArchieExit: @ 823503A
# 188 "data/maps/SeafloorCavern_Room9/scripts.pory"
	face_up
# 189 "data/maps/SeafloorCavern_Room9/scripts.pory"
	lock_facing_direction
# 190 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_down
# 191 "data/maps/SeafloorCavern_Room9/scripts.pory"
	unlock_facing_direction
# 192 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_in_place_fastest_right
# 193 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 194 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 195 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_KyogreApproach: @ 8235040
# 196 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 197 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 198 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_slow_down
# 199 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 200 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 201 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 202 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_slow_down
# 203 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 204 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 205 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 206 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 207 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 208 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_KyogreExit: @ 823504B
# 209 "data/maps/SeafloorCavern_Room9/scripts.pory"
	slide_up
# 210 "data/maps/SeafloorCavern_Room9/scripts.pory"
	slide_up
# 211 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 212 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 213 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_MaxieArrive: @ 823504E
# 214 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 215 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 216 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 217 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 218 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 219 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 220 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 221 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_MaxieExit: @ 8235054
# 222 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 223 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 224 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 225 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 226 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_MagmaGruntArrive: @ 8235057
# 227 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 228 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 229 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 230 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 231 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 232 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 233 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_Delay32: @ 823505C
# 234 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 235 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 236 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 237 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 238 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieHoldItRightThere: @ 823505F
# 239 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Hold it right there.$"
# 240 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 241 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieSoItWasYou: @ 823507C
# 242 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Fufufu…\n"
# 243 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "So it was you, after all.$"
# 244 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 245 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieBeholdKyogre: @ 82350A6
# 246 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Behold!\p"
# 247 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "See how beautiful it is, the sleeping\n"
# 248 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "form of the ancient Pokémon Kyogre!\p"
# 249 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I have waited so long for this day to\n"
# 250 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "come…$"
# 251 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 252 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_BlueOrbShinesByItself: @ 8235279
# 253 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Now! Awaken, Kyogre!\p"
# 254 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Return the world back to nature, for\n"
# 255 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "the good of Pokémon everywhere!$"
# 256 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 257 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieYouMustDisappear: @ 823512C
# 258 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: It surprises me, how you've\n"
# 259 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "managed to chase me here.\p"
# 260 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "But that's all over now.\p"
# 261 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "For the realization of my dream,\n"
# 262 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "you must disappear now!$"
# 263 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 264 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieDefeat: @ 82351BC
# 265 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "What?!\n"
# 266 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I lost to a mere child like you?!$"
# 267 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 268 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWithThisBlueOrb: @ 82351E5
# 269 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Fufufu…\p"
# 270 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I commend you. I must recognize that\n"
# 271 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "you are truly gifted.\p"
# 272 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "But!\n"
# 273 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I have this in my possession!\p"
# 274 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "With this Blue Orb, I can make Kyogre…$"
# 275 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 276 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo: @ 82352A7
# 277 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: What?!\p"
# 278 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I didn't do anything.\n"
# 279 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Where did Kyogre go?$"
# 280 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 281 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieAMessageFromOutside: @ 82352F6
# 282 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Hm? It's a message from our\n"
# 283 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "members outside…$"
# 284 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 285 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard: @ 823532B
# 286 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Yes, what is it?\p"
# 287 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Hm…\n"
# 288 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "It's raining heavily?\p"
# 289 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Good… That should have happened.\n"
# 290 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "That is why we awakened Kyogre,\l"
# 291 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "to realize Team Aqua's vision of\l"
# 292 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "expanding the sea.\p"
# 293 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "What?!\p"
# 294 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "It's raining far harder than we\n"
# 295 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "envisioned? You're in danger?\p"
# 296 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "That can't be…\n"
# 297 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "That's just not possible…\p"
# 298 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Hold your position and monitor\n"
# 299 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "the situation!$"
# 300 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 301 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear: @ 823546F
# 302 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: There's something wrong…\p"
# 303 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "The Blue Orb is supposed to awaken\n"
# 304 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "and control Kyogre…\p"
# 305 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "But… Why?\n"
# 306 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Why did Kyogre disappear?\p"
# 307 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Why?!$"
# 308 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 309 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought: @ 82354F0
# 310 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Maxie: What have you wrought?\p"
# 311 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie… You've finally awoken Kyogre,\n"
# 312 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "haven't you?\p"
# 313 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "What will happen to the world if this\n"
# 314 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "downpour continues for all eternity?\p"
# 315 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "The world's landmass will drown in\n"
# 316 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "the deepening sea…$"
# 317 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 318 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty: @ 82355C2
# 319 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: W-what?!\n"
# 320 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Don't get all high and mighty with me!\p"
# 321 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Wasn't it you, Team Magma, that\n"
# 322 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "infuriated Groudon?\p"
# 323 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "So long as I have this Blue Orb,\n"
# 324 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I should be able to control Kyogre…\p"
# 325 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I should be able to control it…$"
# 326 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 327 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue: @ 8235692
# 328 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Maxie: We don't have the time to\n"
# 329 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "argue about it here!\p"
# 330 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Get outside and see for yourself!\p"
# 331 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "See if what you've wrought is the\n"
# 332 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "world that we desired!$"
# 333 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 334 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_MaxieComeOnPlayer: @ 8235723
# 335 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Maxie: {PLAYER}, come on, you have\n"
# 336 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "to get out of here, too!$"
