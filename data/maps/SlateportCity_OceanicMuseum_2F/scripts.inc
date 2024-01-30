# 1 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 2 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
.set LOCALID_CAPT_STERN, 1
# 3 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
.set LOCALID_ARCHIE, 2
# 4 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
.set LOCALID_GRUNT_1, 3
# 5 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
.set LOCALID_GRUNT_2, 4
# 6 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 7 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_MapScripts:: @ 820BAFF
# 8 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.byte 0
# 9 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 10 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_CaptStern:: @ 820BB00
# 11 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	lock
# 12 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	faceplayer
# 13 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setflag FLAG_SYS_DISABLE_AUTOHEAL
# 14 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	special HealPlayerParty
# 15 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
# 16 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 17 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, TRUE
# 18 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	addobject LOCALID_GRUNT_1
# 19 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
# 20 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 21 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	addobject LOCALID_GRUNT_2
# 22 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
# 23 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 24 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
# 25 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
# 26 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 27 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 28 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
# 29 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 30 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
# 31 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
# 32 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 33 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call_if_ne SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
# 34 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
# 35 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
# 36 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 37 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
# 38 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 39 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 40 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
# 41 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 42 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
# 43 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
# 44 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
# 45 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 46 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
# 47 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 48 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
# 49 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 50 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
# 51 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
# 52 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
# 53 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 54 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFastestDown
# 55 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFastestUp
# 56 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 57 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
# 58 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 59 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay 35
# 60 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	addobject LOCALID_ARCHIE
# 61 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
# 62 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
# 63 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 64 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
# 65 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 66 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
# 67 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 68 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
# 69 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	//special HealPlayerParty
# 70 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_ARCHIE_SLATEPORT, SlateportCity_OceanicMuseum_2F_Text_ArchieDefeat
# 71 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieDefeated, MSGBOX_DEFAULT
# 72 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 73 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	savebgm MUS_DUMMY
# 74 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	fadedefaultbgm
# 75 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 76 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	removeobject LOCALID_ARCHIE
# 77 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 78 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 79 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 80 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay 30
# 81 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
# 82 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 83 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 84 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
# 85 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setvar VAR_0x8004, ITEM_DEVON_GOODS
# 86 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 87 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
# 88 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 89 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 90 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	playfanfare MUS_HEAL
# 91 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitfanfare
# 92 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	special HealPlayerParty
# 93 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	removeobject LOCALID_CAPT_STERN
# 94 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
# 95 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	compare VAR_REGISTER_BIRCH_STATE, 0
# 96 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
# 97 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setflag FLAG_DELIVERED_DEVON_GOODS
# 98 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
# 99 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
# 100 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
# 101 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 102 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	clearflag FLAG_SYS_DISABLE_AUTOHEAL
# 103 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	release
# 104 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 105 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 106 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch:: @ 820BC8C
# 107 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	setvar VAR_REGISTER_BIRCH_STATE, 1
# 108 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	return
# 109 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 110 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts:: @ 820BC92
# 111 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 112 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 113 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	return
# 114 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 115 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts:: @ 820BC9D
# 116 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFastestLeft
# 117 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 118 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	return
# 119 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 120 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth:: @ 820BCA8
# 121 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
# 122 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 123 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	return
# 124 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 125 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest:: @ 820BCB3
# 126 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
# 127 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 128 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	return
# 129 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 130 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth: @ 820BCBE
# 131 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 132 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 133 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_in_place_fastest_left
# 134 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 135 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 136 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest: @ 820BCC2
# 137 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_up
# 138 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 139 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 140 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 141 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_in_place_fastest_left
# 142 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 143 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 144 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_Unused: @ 820BCC8
# 145 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_up
# 146 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 147 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 148 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 149 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 150 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 151 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_up
# 152 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_up
# 153 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 154 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 155 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_up
# 156 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_up
# 157 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_8
# 158 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 159 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 160 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer: @ 820BCD6
# 161 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 162 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 163 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 164 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter: @ 820BCD8
# 165 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 166 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 167 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 168 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 169 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 170 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 171 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 172 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 173 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 174 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 175 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 176 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle: @ 820BCE2
# 177 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 178 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 179 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 180 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter: @ 820BCE4
# 181 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 182 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 183 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_in_place_fastest_down
# 184 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 185 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 186 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach: @ 820BCE8
# 187 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 188 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 189 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 190 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 191 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 192 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 193 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 194 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 195 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated: @ 820BCEF
# 196 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	lock_facing_direction
# 197 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_left
# 198 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	unlock_facing_direction
# 199 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 200 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 201 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter: @ 820BCF3
# 202 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 203 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 204 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 205 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach: @ 820BCF5
# 206 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 207 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 208 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 209 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_down
# 210 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 211 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 212 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 213 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_right
# 214 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 215 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 216 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie: @ 820BCFE
# 217 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 218 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 219 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 220 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 221 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 222 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 223 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 224 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_16
# 225 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	delay_8
# 226 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_fast_down
# 227 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	walk_in_place_fastest_up
# 228 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	step_end
# 229 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 230 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1:: @ 820BD0A
# 231 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
# 232 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 233 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 234 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2:: @ 820BD13
# 235 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
# 236 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 237 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 238 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment:: @ 820BD1C
# 239 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
# 240 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 241 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 242 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_HoennModel:: @ 820BD25
# 243 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
# 244 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 245 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 246 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay:: @ 820BD2E
# 247 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
# 248 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 249 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 250 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay:: @ 820BD37
# 251 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
# 252 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 253 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 254 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica:: @ 820BD40
# 255 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
# 256 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 257 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 258 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica:: @ 820BD49
# 259 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
# 260 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 261 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 262 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica:: @ 820BD52
# 263 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
# 264 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 265 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 266 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica:: @ 820BD5B
# 267 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
# 268 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 269 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 270 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1:: @ 820BD64
# 271 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
# 272 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 273 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 274 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2:: @ 820BD6D
# 275 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
# 276 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 277 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 278 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3:: @ 820BD76
# 279 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	lock
# 280 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	faceplayer
# 281 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
# 282 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	closemessage
# 283 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 284 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	waitmovement 0
# 285 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	release
# 286 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	end
# 287 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 288 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts: @ 820BD8D
# 289 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Yes? If you're looking for Stern,\n"
# 290 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "that would be me.\p"
# 291 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Ah! Those must be the parts I ordered\n"
# 292 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "from Mr. Stone of Devon.\p"
# 293 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Thank you! That's great!\n"
# 294 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "We can prepare for our expedition now.$"
# 295 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 296 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts: @ 820BE40
# 297 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Hehehe, hold it!\n"
# 298 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "We'll take those parts!$"
# 299 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 300 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou: @ 820BE69
# 301 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Capt. Stern: Wh-what?\n"
# 302 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Who are you people?$"
# 303 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 304 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua: @ 820BE93
# 305 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "We're Team Aqua!\p"
# 306 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Our Boss wants those parts!\n"
# 307 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Shut your yap and fork them over!$"
# 308 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 309 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat: @ 820BEE2
# 310 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Awaaaah!\n"
# 311 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "A kid beat me!$"
# 312 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 313 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious: @ 820BEFA
# 314 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Oh, man, what a disaster…\n"
# 315 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "The Boss is going to be furious…$"
# 316 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 317 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis: @ 820BF35
# 318 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Humph, sniveling wimp!\n"
# 319 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Let me take care of this!$"
# 320 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 321 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat: @ 820BF66
# 322 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "What?!\n"
# 323 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "I lost, too!$"
# 324 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 325 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_MeddlingKid: @ 820BF7A
# 326 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Now what? If we don't get the parts,\n"
# 327 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "we're in for it!\p"
# 328 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Arrgh, I didn't count on being meddled\n"
# 329 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "with by some meddling kid!$"
# 330 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 331 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong: @ 820BFF2
# 332 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "I came to see what was taking so\n"
# 333 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "long to snatch some parts, and you\l"
# 334 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "simps are held up by a mere child?$"
# 335 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 336 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_ArchieWarning: @ 820C059
# 337 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "We are Team Aqua,\n"
# 338 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "and we love the sea!\p"
# 339 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "And I am Team Aqua's leader,\n"
# 340 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Archie!\p"
# 341 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "What makes you interfere with us?\p"
# 342 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "…No! You can't be!\n"
# 343 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "You're not one of Team Magma?\p"
# 344 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Wait, that can't be right.\n"
# 345 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "You're not dressed for the part.\p"
# 346 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "… … … … … …\n"
# 347 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "… … … … … …\p"
# 348 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Pokémon, people… All life depends on\n"
# 349 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "the sea.\p"
# 350 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "So, Team Aqua is dedicated to\n"
# 351 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "the expansion of the sea.\p"
# 352 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Don't you agree? What we are doing\n"
# 353 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "is a magnificent undertaking.\p"
# 354 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Ah, fine…\n"
# 355 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "You're still too young to understand\l"
# 356 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "our noble objective.\p"
# 357 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "But, I warn you, don't even consider\n"
# 358 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "interfering with our plans again.\p"
# 359 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "The consequences will cost you\n"
# 360 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "dearly!\p"
# 361 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Hmph! That look on your face!\p"
# 362 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "You're not taking this seriously,\n"
# 363 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "are you?\p"
# 364 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Fine!\p"
# 365 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "I, Archie, will put a stop to\n"
# 366 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "your meddling!$"
# 367 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 368 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_ArchieDefeat:
# 369 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "What?!\n"
# 370 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "I, Archie, was caught off guard?$"
# 371 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 372 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_ArchieDefeated:
# 373 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Ah, whatever. You can keep the parts\n"
# 374 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "for the time being.\p"
# 375 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "But no one can ever stop us!\n"
# 376 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Team Aqua will prevail!\p"
# 377 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "And don't you forget it!$"
# 378 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 379 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs: @ 820C2BE
# 380 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Capt. Stern: You're…\n"
# 381 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Ah, okay, you're {PLAYER}{KUN}…\p"
# 382 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Anyway, that was a tense situation!\n"
# 383 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Thank you for saving us!\p"
# 384 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Oh, yes, I almost forgot that you\n"
# 385 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "even brought the parts from Devon!$"
# 386 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 387 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo: @ 820C36C
# 388 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Capt. Stern: Whoops!\n"
# 389 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "There's no time to lose!\p"
# 390 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "We have to set out on our ocean-floor\n"
# 391 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "expedition really soon.\p"
# 392 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Thanks again, but now I've got\n"
# 393 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "to go!\p"
# 394 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Feel free to wander around and check\n"
# 395 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "out our facilities, though.$"
# 396 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 397 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip: @ 820C43F
# 398 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "I saw a model of a ship here.\p"
# 399 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "It reminded me of the Abandoned Ship\n"
# 400 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "near Dewford Town…$"
# 401 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 402 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum: @ 820C495
# 403 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Don't you dare run around inside\n"
# 404 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "the Museum!$"
# 405 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 406 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine: @ 820C4C2
# 407 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Wow, the submarine's awesome!\n"
# 408 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "I want to go for a ride!$"
# 409 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 410 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1: @ 820C4F9
# 411 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“WATER QUALITY SAMPLE 1,” the\n"
# 412 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "label says.\p"
# 413 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "The sea is all connected, but the\n"
# 414 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "water seems to differ by region.$"
# 415 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 416 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2: @ 820C566
# 417 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“WATER QUALITY SAMPLE 2,” the\n"
# 418 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "label says.\p"
# 419 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Does the saltiness of seawater differ\n"
# 420 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "by region, too?$"
# 421 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 422 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_PressureExperiment: @ 820C5C6
# 423 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "A rubber ball is expanding and\n"
# 424 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "shrinking.\p"
# 425 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“In the sea, the weight of water itself\n"
# 426 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "exerts pressure.\p"
# 427 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“In shallow water, the pressure is not\n"
# 428 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "very heavy.\p"
# 429 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“However, in extremely deep water,\n"
# 430 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "the pressure can reach even tens of\l"
# 431 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "thousands of tons on a small area.”$"
# 432 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 433 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_HoennModel: @ 820C6C7
# 434 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“MODEL OF HOENN REGION”\p"
# 435 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "It's a miniature diorama of the\n"
# 436 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Hoenn region.\p"
# 437 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "Where is Littleroot Town on this?$"
# 438 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 439 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay: @ 820C72F
# 440 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "It's a display on the flow of seawater.\p"
# 441 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“Near the bottom of the sea, water\n"
# 442 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "flows due to differences in such\l"
# 443 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "factors as temperature and salinity.”$"
# 444 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 445 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay: @ 820C7C1
# 446 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "It's a display on the flow of seawater.\p"
# 447 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“Toward the surface, seawater flows\n"
# 448 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "as currents driven by the winds.”$"
# 449 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 450 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica: @ 820C82F
# 451 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“THE FERRY S.S. TIDAL\p"
# 452 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“A scale replica of the ship under\n"
# 453 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "construction at Stern's Shipyard.”$"
# 454 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 455 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica: @ 820C88B
# 456 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“SUBMARINE EXPLORER 1\p"
# 457 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“A replica of the high-performance\n"
# 458 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "ocean floor exploration submarine.”$"
# 459 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 460 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica: @ 820C8E8
# 461 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“SUBMERSIBLE POD\p"
# 462 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“A replica of a compact, unmanned\n"
# 463 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "pod for seafloor exploration.”$"
# 464 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"

# 465 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica: @ 820C93A
# 466 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“S.S. ANNE\p"
# 467 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "“A replica of the luxury liner that\n"
# 468 "data/maps/SlateportCity_OceanicMuseum_2F/scripts.pory"
	.string "circles the globe.”$"
