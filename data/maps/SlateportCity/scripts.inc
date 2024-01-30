# 1 "data/maps/SlateportCity/scripts.pory"

# 2 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_FAT_MAN, 1
# 3 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_MAN_1, 2
# 4 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_RICH_BOY, 3
# 5 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_1, 5
# 6 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_COOK, 6
# 7 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_OLD_WOMAN, 7
# 8 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GIRL, 8
# 9 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_TY, 9
# 10 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GABBY, 10
# 11 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_CAPT_STERN, 11
# 12 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_2, 18
# 13 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_3, 19
# 14 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_4, 26
# 15 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_5, 27
# 16 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_6, 28
# 17 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_7, 29
# 18 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_8, 30
# 19 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_9, 30
# 20 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_11, 32
# 21 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_SCOTT, 34
# 22 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_BRAWLY, 38
# 23 "data/maps/SlateportCity/scripts.pory"

# 24 "data/maps/SlateportCity/scripts.pory"
SlateportCity_MapScripts:: @ 81DCC61
# 25 "data/maps/SlateportCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
# 26 "data/maps/SlateportCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
# 27 "data/maps/SlateportCity/scripts.pory"
	.byte 0
# 28 "data/maps/SlateportCity/scripts.pory"

# 29 "data/maps/SlateportCity/scripts.pory"
SlateportCity_OnTransition: @ 81DCC6C
# 30 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
# 31 "data/maps/SlateportCity/scripts.pory"
	call SlateportCity_EventScript_EnterSlateport
# 32 "data/maps/SlateportCity/scripts.pory"
	compare VAR_SLATEPORT_CITY_STATE, 1
# 33 "data/maps/SlateportCity/scripts.pory"
	call_if_eq SlateportCity_EventScript_MovePeopleForSternInterview
# 34 "data/maps/SlateportCity/scripts.pory"
	compare VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
# 35 "data/maps/SlateportCity/scripts.pory"
	call_if_eq SlateportCity_EventScript_SetReadyForScottScene
# 36 "data/maps/SlateportCity/scripts.pory"
	end
# 37 "data/maps/SlateportCity/scripts.pory"

# 38 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnterSlateport:: @ 81DCC8D
# 39 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_VISITED_SLATEPORT_CITY
# 40 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 41 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
# 42 "data/maps/SlateportCity/scripts.pory"
	return
# 43 "data/maps/SlateportCity/scripts.pory"

# 44 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MovePeopleForSternInterview:: @ 81DCC99
# 45 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_CAPT_STERN, 28, 13
# 46 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_OLD_WOMAN, 25, 13
# 47 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_RICH_BOY, 25, 14
# 48 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_COOK, 27, 16
# 49 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_GIRL, 28, 16
# 50 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_FAT_MAN, 29, 16
# 51 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_MAN_1, 31, 14
# 52 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
# 53 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
# 54 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
# 55 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_COOK, MOVEMENT_TYPE_FACE_UP
# 56 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_GIRL, MOVEMENT_TYPE_FACE_UP
# 57 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_FAT_MAN, MOVEMENT_TYPE_FACE_UP
# 58 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_MAN_1, MOVEMENT_TYPE_FACE_LEFT
# 59 "data/maps/SlateportCity/scripts.pory"
	return
# 60 "data/maps/SlateportCity/scripts.pory"

# 61 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SetReadyForScottScene:: @ 81DCCE7
# 62 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 63 "data/maps/SlateportCity/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 64 "data/maps/SlateportCity/scripts.pory"
	compare VAR_0x8004, 30
# 65 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq SlateportCity_EventScript_MoveScottLeft
# 66 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 23, 27
# 67 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
# 68 "data/maps/SlateportCity/scripts.pory"
	return
# 69 "data/maps/SlateportCity/scripts.pory"

# 70 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MoveScottLeft:: @ 81DCD06
# 71 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 22, 27
# 72 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
# 73 "data/maps/SlateportCity/scripts.pory"
	return
# 74 "data/maps/SlateportCity/scripts.pory"

# 75 "data/maps/SlateportCity/scripts.pory"
SlateportCity_OnFrame: @ 81DCD12
# 76 "data/maps/SlateportCity/scripts.pory"
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
# 77 "data/maps/SlateportCity/scripts.pory"
	.2byte 0
# 78 "data/maps/SlateportCity/scripts.pory"

# 79 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ScottScene:: @ 81DCD1C
# 80 "data/maps/SlateportCity/scripts.pory"
	lockall
# 81 "data/maps/SlateportCity/scripts.pory"
	addobject LOCALID_SCOTT
# 82 "data/maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceScott
# 83 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottApproachPlayer
# 84 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 85 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
# 86 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 87 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFastestLeft
# 88 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 89 "data/maps/SlateportCity/scripts.pory"
	delay 60
# 90 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
# 91 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFastestRight
# 92 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 93 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
# 94 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 95 "data/maps/SlateportCity/scripts.pory"
	delay 30
# 96 "data/maps/SlateportCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 97 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
# 98 "data/maps/SlateportCity/scripts.pory"
	waitfanfare
# 99 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 100 "data/maps/SlateportCity/scripts.pory"
	delay 30
# 101 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
# 102 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
# 103 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 104 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExit
# 105 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 106 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SCOTT
# 107 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 10, 12
# 108 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_DOWN
# 109 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 110 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
# 111 "data/maps/SlateportCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 112 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 113 "data/maps/SlateportCity/scripts.pory"
	end
# 114 "data/maps/SlateportCity/scripts.pory"

# 115 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerFaceScott: @ 81DCDA8
# 116 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 117 "data/maps/SlateportCity/scripts.pory"
	delay_8
# 118 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_fastest_left
# 119 "data/maps/SlateportCity/scripts.pory"
	step_end
# 120 "data/maps/SlateportCity/scripts.pory"

# 121 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottApproachPlayer: @ 81DCDAC
# 122 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 123 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 124 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 125 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 126 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 127 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 128 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 129 "data/maps/SlateportCity/scripts.pory"
	step_end
# 130 "data/maps/SlateportCity/scripts.pory"

# 131 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExit: @ 81DCDB4
# 132 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 133 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 134 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 135 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 136 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 137 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 138 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 139 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 140 "data/maps/SlateportCity/scripts.pory"
	step_end
# 141 "data/maps/SlateportCity/scripts.pory"

# 142 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyGuru:: @ 81DCDBD
# 143 "data/maps/SlateportCity/scripts.pory"
	lock
# 144 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 145 "data/maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
# 146 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 147 "data/maps/SlateportCity/scripts.pory"
	pokemart SlateportCity_Pokemart_EnergyGuru
# 148 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 149 "data/maps/SlateportCity/scripts.pory"
	release
# 150 "data/maps/SlateportCity/scripts.pory"
	end
# 151 "data/maps/SlateportCity/scripts.pory"

# 152 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Pokemart_EnergyGuru: @ 81DCDD4
# 153 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_PROTEIN
# 154 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_IRON
# 155 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_CARBOS
# 156 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_ZINC
# 157 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_CALCIUM
# 158 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_HP_UP
# 159 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_NONE
# 160 "data/maps/SlateportCity/scripts.pory"
	release
# 161 "data/maps/SlateportCity/scripts.pory"
	end
# 162 "data/maps/SlateportCity/scripts.pory"

# 163 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PowerItems::
# 164 "data/maps/SlateportCity/scripts.pory"
	lock
# 165 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 166 "data/maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_PowerItemsSellWhatYouNeed
# 167 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 168 "data/maps/SlateportCity/scripts.pory"
	pokemart SlateportCity_Pokemart_PowerItems
# 169 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 170 "data/maps/SlateportCity/scripts.pory"
	release
# 171 "data/maps/SlateportCity/scripts.pory"
	end
# 172 "data/maps/SlateportCity/scripts.pory"

# 173 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 174 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Pokemart_PowerItems::
# 175 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TRAINING_BAND
# 176 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_POWER_BRACER
# 177 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_POWER_BELT
# 178 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_POWER_LENS
# 179 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_POWER_BAND
# 180 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_POWER_ANKLET
# 181 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_POWER_WEIGHT
# 182 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_NONE
# 183 "data/maps/SlateportCity/scripts.pory"
	release
# 184 "data/maps/SlateportCity/scripts.pory"
	end
# 185 "data/maps/SlateportCity/scripts.pory"

# 186 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_IncenseStand::
# 187 "data/maps/SlateportCity/scripts.pory"
	lock
# 188 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 189 "data/maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_IncenseStand
# 190 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 191 "data/maps/SlateportCity/scripts.pory"
	pokemart SlateportCity_Pokemart_Incense
# 192 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 193 "data/maps/SlateportCity/scripts.pory"
	release
# 194 "data/maps/SlateportCity/scripts.pory"
	end
# 195 "data/maps/SlateportCity/scripts.pory"

# 196 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 197 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Pokemart_Incense::
# 198 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_SEA_INCENSE
# 199 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_LAX_INCENSE
# 200 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_ROSE_INCENSE
# 201 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_PURE_INCENSE
# 202 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_ROCK_INCENSE
# 203 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_ODD_INCENSE
# 204 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_LUCK_INCENSE
# 205 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_FULL_INCENSE
# 206 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_WAVE_INCENSE
# 207 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_NONE
# 208 "data/maps/SlateportCity/scripts.pory"
	release
# 209 "data/maps/SlateportCity/scripts.pory"
	end
# 210 "data/maps/SlateportCity/scripts.pory"

# 211 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EffortRibbonWoman:: @ 81DCDE4
# 212 "data/maps/SlateportCity/scripts.pory"
	lock
# 213 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 214 "data/maps/SlateportCity/scripts.pory"
	bufferleadmonspeciesname 0
# 215 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
# 216 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
# 217 "data/maps/SlateportCity/scripts.pory"
	compare VAR_RESULT, TRUE
# 218 "data/maps/SlateportCity/scripts.pory"
	call_if_eq SlateportCity_EventScript_MonHasEffortRibbon
# 219 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
# 220 "data/maps/SlateportCity/scripts.pory"
	compare VAR_RESULT, FALSE
# 221 "data/maps/SlateportCity/scripts.pory"
	call_if_eq SlateportCity_EventScript_MonEVsNotMaxed
# 222 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
# 223 "data/maps/SlateportCity/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 224 "data/maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_ReceivedEffortRibbon
# 225 "data/maps/SlateportCity/scripts.pory"
	waitfanfare
# 226 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
# 227 "data/maps/SlateportCity/scripts.pory"
	special GiveLeadMonEffortRibbon
# 228 "data/maps/SlateportCity/scripts.pory"
	release
# 229 "data/maps/SlateportCity/scripts.pory"
	end
# 230 "data/maps/SlateportCity/scripts.pory"

# 231 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MonEVsNotMaxed:: @ 81DCE2E
# 232 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
# 233 "data/maps/SlateportCity/scripts.pory"
	release
# 234 "data/maps/SlateportCity/scripts.pory"
	end
# 235 "data/maps/SlateportCity/scripts.pory"

# 236 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MonHasEffortRibbon:: @ 81DCE38
# 237 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
# 238 "data/maps/SlateportCity/scripts.pory"
	release
# 239 "data/maps/SlateportCity/scripts.pory"
	end
# 240 "data/maps/SlateportCity/scripts.pory"

# 241 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Cook:: @ 81DCE42
# 242 "data/maps/SlateportCity/scripts.pory"
	lock
# 243 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 244 "data/maps/SlateportCity/scripts.pory"
	compare VAR_SLATEPORT_CITY_STATE, 1
# 245 "data/maps/SlateportCity/scripts.pory"
	call_if_eq SlateportCity_EventScript_CookSternInterview
# 246 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
# 247 "data/maps/SlateportCity/scripts.pory"
	release
# 248 "data/maps/SlateportCity/scripts.pory"
	end
# 249 "data/maps/SlateportCity/scripts.pory"

# 250 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CookSternInterview:: @ 81DCE59
# 251 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
# 252 "data/maps/SlateportCity/scripts.pory"
	release
# 253 "data/maps/SlateportCity/scripts.pory"
	end
# 254 "data/maps/SlateportCity/scripts.pory"

# 255 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OldWoman:: @ 81DCE63
# 256 "data/maps/SlateportCity/scripts.pory"
	lock
# 257 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 258 "data/maps/SlateportCity/scripts.pory"
	compare VAR_SLATEPORT_CITY_STATE, 1
# 259 "data/maps/SlateportCity/scripts.pory"
	call_if_eq SlateportCity_EventScript_OldWomanSternInterview
# 260 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
# 261 "data/maps/SlateportCity/scripts.pory"
	release
# 262 "data/maps/SlateportCity/scripts.pory"
	end
# 263 "data/maps/SlateportCity/scripts.pory"

# 264 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OldWomanSternInterview:: @ 81DCE7A
# 265 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
# 266 "data/maps/SlateportCity/scripts.pory"
	release
# 267 "data/maps/SlateportCity/scripts.pory"
	end
# 268 "data/maps/SlateportCity/scripts.pory"

# 269 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Girl:: @ 81DCE84
# 270 "data/maps/SlateportCity/scripts.pory"
	lock
# 271 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 272 "data/maps/SlateportCity/scripts.pory"
	compare VAR_SLATEPORT_CITY_STATE, 1
# 273 "data/maps/SlateportCity/scripts.pory"
	call_if_eq SlateportCity_EventScript_GirlSternInterview
# 274 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
# 275 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
# 276 "data/maps/SlateportCity/scripts.pory"
	release
# 277 "data/maps/SlateportCity/scripts.pory"
	end
# 278 "data/maps/SlateportCity/scripts.pory"

# 279 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_GirlSternInterview:: @ 81DCEA4
# 280 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
# 281 "data/maps/SlateportCity/scripts.pory"
	release
# 282 "data/maps/SlateportCity/scripts.pory"
	end
# 283 "data/maps/SlateportCity/scripts.pory"

# 284 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_GirlSecretBase:: @ 81DCEAE
# 285 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
# 286 "data/maps/SlateportCity/scripts.pory"
	release
# 287 "data/maps/SlateportCity/scripts.pory"
	end
# 288 "data/maps/SlateportCity/scripts.pory"

# 289 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RichBoy:: @ 81DCEB8
# 290 "data/maps/SlateportCity/scripts.pory"
	lock
# 291 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 292 "data/maps/SlateportCity/scripts.pory"
	compare VAR_SLATEPORT_CITY_STATE, 1
# 293 "data/maps/SlateportCity/scripts.pory"
	call_if_eq SlateportCity_EventScript_RichBoySternInterview
# 294 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
# 295 "data/maps/SlateportCity/scripts.pory"
	release
# 296 "data/maps/SlateportCity/scripts.pory"
	end
# 297 "data/maps/SlateportCity/scripts.pory"

# 298 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RichBoySternInterview:: @ 81DCECF
# 299 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
# 300 "data/maps/SlateportCity/scripts.pory"
	release
# 301 "data/maps/SlateportCity/scripts.pory"
	end
# 302 "data/maps/SlateportCity/scripts.pory"

# 303 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_FatMan:: @ 81DCED9
# 304 "data/maps/SlateportCity/scripts.pory"
	compare VAR_SLATEPORT_CITY_STATE, 1
# 305 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq SlateportCity_EventScript_FatManSternInterview
# 306 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
# 307 "data/maps/SlateportCity/scripts.pory"
	end
# 308 "data/maps/SlateportCity/scripts.pory"

# 309 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_FatManSternInterview:: @ 81DCEED
# 310 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
# 311 "data/maps/SlateportCity/scripts.pory"
	end
# 312 "data/maps/SlateportCity/scripts.pory"

# 313 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man1:: @ 81DCEF6
# 314 "data/maps/SlateportCity/scripts.pory"
	lock
# 315 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 316 "data/maps/SlateportCity/scripts.pory"
	compare VAR_SLATEPORT_CITY_STATE, 1
# 317 "data/maps/SlateportCity/scripts.pory"
	call_if_eq SlateportCity_EventScript_Man1SternInterview
# 318 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
# 319 "data/maps/SlateportCity/scripts.pory"
	release
# 320 "data/maps/SlateportCity/scripts.pory"
	end
# 321 "data/maps/SlateportCity/scripts.pory"

# 322 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man1SternInterview:: @ 81DCF0D
# 323 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
# 324 "data/maps/SlateportCity/scripts.pory"
	release
# 325 "data/maps/SlateportCity/scripts.pory"
	end
# 326 "data/maps/SlateportCity/scripts.pory"

# 327 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman1:: @ 81DCF17
# 328 "data/maps/SlateportCity/scripts.pory"
	lock
# 329 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 330 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA, SlateportCity_EventScript_Woman1AquaGone
# 331 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
# 332 "data/maps/SlateportCity/scripts.pory"
	release
# 333 "data/maps/SlateportCity/scripts.pory"
	end
# 334 "data/maps/SlateportCity/scripts.pory"

# 335 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman1AquaGone:: @ 81DCF2C
# 336 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
# 337 "data/maps/SlateportCity/scripts.pory"
	release
# 338 "data/maps/SlateportCity/scripts.pory"
	end
# 339 "data/maps/SlateportCity/scripts.pory"

# 340 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BattleTentSign:: @ 81DCF36
# 341 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
# 342 "data/maps/SlateportCity/scripts.pory"
	end
# 343 "data/maps/SlateportCity/scripts.pory"

# 344 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardSign:: @ 81DCF3F
# 345 "data/maps/SlateportCity/scripts.pory"
	lockall
# 346 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
# 347 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
# 348 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
# 349 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 350 "data/maps/SlateportCity/scripts.pory"
	end
# 351 "data/maps/SlateportCity/scripts.pory"

# 352 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardNearsCompletion:: @ 81DCF5C
# 353 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
# 354 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 355 "data/maps/SlateportCity/scripts.pory"
	end
# 356 "data/maps/SlateportCity/scripts.pory"

# 357 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardFerryComplete:: @ 81DCF66
# 358 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
# 359 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 360 "data/maps/SlateportCity/scripts.pory"
	end
# 361 "data/maps/SlateportCity/scripts.pory"

# 362 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PokemonFanClubSign:: @ 81DCF70
# 363 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 364 "data/maps/SlateportCity/scripts.pory"
	end
# 365 "data/maps/SlateportCity/scripts.pory"

# 366 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OceanicMuseumSign:: @ 81DCF79
# 367 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
# 368 "data/maps/SlateportCity/scripts.pory"
	end
# 369 "data/maps/SlateportCity/scripts.pory"

# 370 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CitySign:: @ 81DCF82
# 371 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
# 372 "data/maps/SlateportCity/scripts.pory"
	end
# 373 "data/maps/SlateportCity/scripts.pory"

# 374 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MarketSign:: @ 81DCF8B
# 375 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
# 376 "data/maps/SlateportCity/scripts.pory"
	end
# 377 "data/maps/SlateportCity/scripts.pory"

# 378 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HarborSign:: @ 81DCF94
# 379 "data/maps/SlateportCity/scripts.pory"
	lockall
# 380 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
# 381 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
# 382 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 383 "data/maps/SlateportCity/scripts.pory"
	end
# 384 "data/maps/SlateportCity/scripts.pory"

# 385 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HarborSignFerryComplete:: @ 81DCFA8
# 386 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
# 387 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 388 "data/maps/SlateportCity/scripts.pory"
	end
# 389 "data/maps/SlateportCity/scripts.pory"

# 390 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NameRatersHouseSign:: @ 81DCFB2
# 391 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
# 392 "data/maps/SlateportCity/scripts.pory"
	end
# 393 "data/maps/SlateportCity/scripts.pory"

# 394 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Maniac:: @ 81DCFBB
# 395 "data/maps/SlateportCity/scripts.pory"
	lock
# 396 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 397 "data/maps/SlateportCity/scripts.pory"
	compare VAR_SLATEPORT_CITY_STATE, 1
# 398 "data/maps/SlateportCity/scripts.pory"
	call_if_eq SlateportCity_EventScript_ManiacSternInterview
# 399 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
# 400 "data/maps/SlateportCity/scripts.pory"
	release
# 401 "data/maps/SlateportCity/scripts.pory"
	end
# 402 "data/maps/SlateportCity/scripts.pory"

# 403 "data/maps/SlateportCity/scripts.pory"
@ Unclear if the text here was meant to be different, but its not
# 404 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ManiacSternInterview:: @ 81DCFD2
# 405 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
# 406 "data/maps/SlateportCity/scripts.pory"
	release
# 407 "data/maps/SlateportCity/scripts.pory"
	end
# 408 "data/maps/SlateportCity/scripts.pory"

# 409 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman2:: @ 81DCFDC
# 410 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
# 411 "data/maps/SlateportCity/scripts.pory"
	end
# 412 "data/maps/SlateportCity/scripts.pory"

# 413 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Sailor1:: @ 81DCFE5
# 414 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
# 415 "data/maps/SlateportCity/scripts.pory"
	end
# 416 "data/maps/SlateportCity/scripts.pory"

# 417 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Sailor2:: @ 81DCFEE
# 418 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
# 419 "data/maps/SlateportCity/scripts.pory"
	end
# 420 "data/maps/SlateportCity/scripts.pory"

# 421 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PokefanF:: @ 81DCFF7
# 422 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
# 423 "data/maps/SlateportCity/scripts.pory"
	end
# 424 "data/maps/SlateportCity/scripts.pory"

# 425 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man2:: @ 81DD000
# 426 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
# 427 "data/maps/SlateportCity/scripts.pory"
	end
# 428 "data/maps/SlateportCity/scripts.pory"

# 429 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt1:: @ 81DD009
# 430 "data/maps/SlateportCity/scripts.pory"
	lock
# 431 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 432 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
# 433 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 434 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
# 435 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 436 "data/maps/SlateportCity/scripts.pory"
	release
# 437 "data/maps/SlateportCity/scripts.pory"
	end
# 438 "data/maps/SlateportCity/scripts.pory"

# 439 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt2:: @ 81DD020
# 440 "data/maps/SlateportCity/scripts.pory"
	lock
# 441 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 442 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
# 443 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 444 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
# 445 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 446 "data/maps/SlateportCity/scripts.pory"
	release
# 447 "data/maps/SlateportCity/scripts.pory"
	end
# 448 "data/maps/SlateportCity/scripts.pory"

# 449 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt3:: @ 81DD037
# 450 "data/maps/SlateportCity/scripts.pory"
	lock
# 451 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 452 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
# 453 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 454 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_3, Common_Movement_FaceOriginalDirection
# 455 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 456 "data/maps/SlateportCity/scripts.pory"
	release
# 457 "data/maps/SlateportCity/scripts.pory"
	end
# 458 "data/maps/SlateportCity/scripts.pory"

# 459 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt4:: @ 81DD04E
# 460 "data/maps/SlateportCity/scripts.pory"
	lock
# 461 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 462 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
# 463 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 464 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_4, Common_Movement_FaceOriginalDirection
# 465 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 466 "data/maps/SlateportCity/scripts.pory"
	release
# 467 "data/maps/SlateportCity/scripts.pory"
	end
# 468 "data/maps/SlateportCity/scripts.pory"

# 469 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt5:: @ 81DD065
# 470 "data/maps/SlateportCity/scripts.pory"
	lock
# 471 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 472 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
# 473 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 474 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_5, Common_Movement_FaceOriginalDirection
# 475 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 476 "data/maps/SlateportCity/scripts.pory"
	release
# 477 "data/maps/SlateportCity/scripts.pory"
	end
# 478 "data/maps/SlateportCity/scripts.pory"

# 479 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt6:: @ 81DD07C
# 480 "data/maps/SlateportCity/scripts.pory"
	lock
# 481 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 482 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
# 483 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 484 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_6, Common_Movement_FaceOriginalDirection
# 485 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 486 "data/maps/SlateportCity/scripts.pory"
	release
# 487 "data/maps/SlateportCity/scripts.pory"
	end
# 488 "data/maps/SlateportCity/scripts.pory"

# 489 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt7:: @ 81DD093
# 490 "data/maps/SlateportCity/scripts.pory"
	lock
# 491 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 492 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
# 493 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 494 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_7, Common_Movement_FaceOriginalDirection
# 495 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 496 "data/maps/SlateportCity/scripts.pory"
	release
# 497 "data/maps/SlateportCity/scripts.pory"
	end
# 498 "data/maps/SlateportCity/scripts.pory"

# 499 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt8:: @ 81DD0AA
# 500 "data/maps/SlateportCity/scripts.pory"
	lock
# 501 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 502 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
# 503 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 504 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_8, Common_Movement_FaceOriginalDirection
# 505 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 506 "data/maps/SlateportCity/scripts.pory"
	release
# 507 "data/maps/SlateportCity/scripts.pory"
	end
# 508 "data/maps/SlateportCity/scripts.pory"

# 509 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt9:: @ 81DD0C1
# 510 "data/maps/SlateportCity/scripts.pory"
	lock
# 511 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 512 "data/maps/SlateportCity/scripts.pory"
	playse SE_PIN
# 513 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_ExclamationMark
# 514 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 515 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_Delay48
# 516 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 517 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
# 518 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 519 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
# 520 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 521 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 522 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 523 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
# 524 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 525 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
# 526 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 527 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
# 528 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 529 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 530 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 531 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
# 532 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 533 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
# 534 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 535 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 536 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 537 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
# 538 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 539 "data/maps/SlateportCity/scripts.pory"
	release
# 540 "data/maps/SlateportCity/scripts.pory"
	end
# 541 "data/maps/SlateportCity/scripts.pory"

# 542 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_DelayAquaGrunt: @ 81DD147
# 543 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 544 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 545 "data/maps/SlateportCity/scripts.pory"
	step_end
# 546 "data/maps/SlateportCity/scripts.pory"

# 547 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt10:: @ 81DD14A
# 548 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
# 549 "data/maps/SlateportCity/scripts.pory"
	end
# 550 "data/maps/SlateportCity/scripts.pory"

# 551 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt11:: @ 81DD153
# 552 "data/maps/SlateportCity/scripts.pory"
	lock
# 553 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 554 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
# 555 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 556 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_11, Common_Movement_FaceOriginalDirection
# 557 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 558 "data/maps/SlateportCity/scripts.pory"
	release
# 559 "data/maps/SlateportCity/scripts.pory"
	end
# 560 "data/maps/SlateportCity/scripts.pory"

# 561 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_DollClerk:: @ 81DD16A
# 562 "data/maps/SlateportCity/scripts.pory"
	lock
# 563 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 564 "data/maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 565 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 566 "data/maps/SlateportCity/scripts.pory"
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
# 567 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 568 "data/maps/SlateportCity/scripts.pory"
	release
# 569 "data/maps/SlateportCity/scripts.pory"
	end
# 570 "data/maps/SlateportCity/scripts.pory"

# 571 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 572 "data/maps/SlateportCity/scripts.pory"
SlateportCity_PokemartDecor_Dolls: @ 81DD184
# 573 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_AZURILL_DOLL
# 574 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_MARILL_DOLL
# 575 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_SKITTY_DOLL
# 576 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_NONE
# 577 "data/maps/SlateportCity/scripts.pory"
	release
# 578 "data/maps/SlateportCity/scripts.pory"
	end
# 579 "data/maps/SlateportCity/scripts.pory"

# 580 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ComeBackWithSecretPower:: @ 81DD18E
# 581 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
# 582 "data/maps/SlateportCity/scripts.pory"
	release
# 583 "data/maps/SlateportCity/scripts.pory"
	end
# 584 "data/maps/SlateportCity/scripts.pory"

# 585 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_DecorClerk:: @ 81DD198
# 586 "data/maps/SlateportCity/scripts.pory"
	lock
# 587 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 588 "data/maps/SlateportCity/scripts.pory"
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
# 589 "data/maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 590 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 591 "data/maps/SlateportCity/scripts.pory"
	pokemartdecoration SlateportCity_PokemartDecor
# 592 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 593 "data/maps/SlateportCity/scripts.pory"
	release
# 594 "data/maps/SlateportCity/scripts.pory"
	end
# 595 "data/maps/SlateportCity/scripts.pory"

# 596 "data/maps/SlateportCity/scripts.pory"
SlateportCity_PokemartDecor: @ 81DD1B8
# 597 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_RED_BRICK
# 598 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_BLUE_BRICK
# 599 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_YELLOW_BRICK
# 600 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_RED_BALLOON
# 601 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_BLUE_BALLOON
# 602 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_YELLOW_BALLOON
# 603 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_C_LOW_NOTE_MAT
# 604 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_D_NOTE_MAT
# 605 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_E_NOTE_MAT
# 606 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_F_NOTE_MAT
# 607 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_G_NOTE_MAT
# 608 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_A_NOTE_MAT
# 609 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_B_NOTE_MAT
# 610 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_C_HIGH_NOTE_MAT
# 611 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_NONE
# 612 "data/maps/SlateportCity/scripts.pory"
	release
# 613 "data/maps/SlateportCity/scripts.pory"
	end
# 614 "data/maps/SlateportCity/scripts.pory"

# 615 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PowerTMClerk:: @ 81DD1D8
# 616 "data/maps/SlateportCity/scripts.pory"
	lock
# 617 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 618 "data/maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 619 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 620 "data/maps/SlateportCity/scripts.pory"
	pokemart SlateportCity_Pokemart_PowerTMs
# 621 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 622 "data/maps/SlateportCity/scripts.pory"
	release
# 623 "data/maps/SlateportCity/scripts.pory"
	end
# 624 "data/maps/SlateportCity/scripts.pory"

# 625 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 626 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Pokemart_PowerTMs: @ 81DD1F0
# 627 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM57_CHARGE_BEAM
# 628 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM67_RECYCLE	
# 629 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM73_THUNDER_WAVE
# 630 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM78_BULLDOZE
# 631 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM82_DRAGON_TAIL
# 632 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM88_LOW_SWEEP
# 633 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_NONE
# 634 "data/maps/SlateportCity/scripts.pory"
	release
# 635 "data/maps/SlateportCity/scripts.pory"
	end
# 636 "data/maps/SlateportCity/scripts.pory"

# 637 "data/maps/SlateportCity/scripts.pory"
@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
# 638 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CaptStern:: @ 81DD1F8
# 639 "data/maps/SlateportCity/scripts.pory"
	lockall
# 640 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
# 641 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
# 642 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 643 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GABBY, Common_Movement_WalkInPlaceFastestRight
# 644 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 645 "data/maps/SlateportCity/scripts.pory"
	delay 10
# 646 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_TY, Common_Movement_WalkInPlaceFastestDown
# 647 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 648 "data/maps/SlateportCity/scripts.pory"
	delay 25
# 649 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
# 650 "data/maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceStern
# 651 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GABBY, SlateportCity_Movement_GabbyExit
# 652 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_TY, SlateportCity_Movement_TyExit
# 653 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 654 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_GABBY
# 655 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_TY
# 656 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
# 657 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFastestUp
# 658 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 659 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
# 660 "data/maps/SlateportCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 661 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
# 662 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_COOK, Common_Movement_WalkInPlaceFastestLeft
# 663 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_FAT_MAN, Common_Movement_WalkInPlaceFastestLeft
# 664 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
# 665 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_RICH_BOY, Common_Movement_QuestionMark
# 666 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_MAN_1, SlateportCity_Movement_ManConcern
# 667 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 668 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFastestDown
# 669 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 670 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
# 671 "data/maps/SlateportCity/scripts.pory"
	playse SE_PIN
# 672 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_ExclamationMark
# 673 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 674 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_Delay48
# 675 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 676 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFastestUp
# 677 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 678 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
# 679 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 680 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 681 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
# 682 "data/maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
# 683 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 684 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_CAPT_STERN
# 685 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
# 686 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
# 687 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
# 688 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
# 689 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_CITY_STATE, 2
# 690 "data/maps/SlateportCity/scripts.pory"
	warp MAP_SLATEPORT_CITY_HARBOR, 255, 11, 14
# 691 "data/maps/SlateportCity/scripts.pory"
	waitstate
# 692 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 693 "data/maps/SlateportCity/scripts.pory"
	end
# 694 "data/maps/SlateportCity/scripts.pory"

# 695 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Greta::
# 696 "data/maps/SlateportCity/scripts.pory"
	lock
# 697 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 698 "data/maps/SlateportCity/scripts.pory"
	checkflag FLAG_DEFEATED_SLATEPORT_GRETA
# 699 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq SlateportCity_EventScript_GretaDefeated
# 700 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GretaHowdy, MSGBOX_DEFAULT
# 701 "data/maps/SlateportCity/scripts.pory"
	goto_if_unset FLAG_HIDE_LAVARIDGE_POKECENTER_LUCY, SlateportCity_EventScript_GretaNotStrongEnough
# 702 "data/maps/SlateportCity/scripts.pory"
	goto_if_unset FLAG_HIDE_FORTREE_POKECENTER_SPENSER, SlateportCity_EventScript_GretaNotStrongEnough
# 703 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GretaReadyForBattle, MSGBOX_YESNO
# 704 "data/maps/SlateportCity/scripts.pory"
	compare VAR_RESULT, NO
# 705 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq SlateportCity_EventScript_GretaRefuse
# 706 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GretaLetsBattle, MSGBOX_DEFAULT
# 707 "data/maps/SlateportCity/scripts.pory"
	trainerbattle_no_intro TRAINER_GRETA_SLATEPORT, SlateportCity_Text_GretaDefeat
# 708 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GretaHereHaveStuff, MSGBOX_AUTOCLOSE
# 709 "data/maps/SlateportCity/scripts.pory"
	givecustommon SPECIES_GENGAR, 55, ITEM_GENGARITE, ITEM_PARK_BALL, NATURE_TIMID, 1, 0, 0, 0, 252, 252, 4, 0, 0, 0, 0, 0, 0, MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, MOVE_SUBSTITUTE, MOVE_ENCORE, TRUE
# 710 "data/maps/SlateportCity/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 711 "data/maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_Got_Gengar
# 712 "data/maps/SlateportCity/scripts.pory"
	waitfanfare
# 713 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_DEFEATED_SLATEPORT_GRETA
# 714 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_GretaDefeated::
# 715 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GretaDefeated, MSGBOX_AUTOCLOSE
# 716 "data/maps/SlateportCity/scripts.pory"
	release
# 717 "data/maps/SlateportCity/scripts.pory"
	end
# 718 "data/maps/SlateportCity/scripts.pory"

# 719 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_GretaNotStrongEnough::
# 720 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GretaMaybeNot, MSGBOX_DEFAULT
# 721 "data/maps/SlateportCity/scripts.pory"
	release
# 722 "data/maps/SlateportCity/scripts.pory"
	end
# 723 "data/maps/SlateportCity/scripts.pory"

# 724 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_GretaRefuse::
# 725 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GretaRefused, MSGBOX_DEFAULT
# 726 "data/maps/SlateportCity/scripts.pory"
	release
# 727 "data/maps/SlateportCity/scripts.pory"
	end
# 728 "data/maps/SlateportCity/scripts.pory"

# 729 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_OldWomanConcern: @ 81DD309
# 730 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 731 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 732 "data/maps/SlateportCity/scripts.pory"
	emote_question_mark
# 733 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_fastest_right
# 734 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 735 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 736 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_fastest_left
# 737 "data/maps/SlateportCity/scripts.pory"
	step_end
# 738 "data/maps/SlateportCity/scripts.pory"

# 739 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ManConcern: @ 81DD311
# 740 "data/maps/SlateportCity/scripts.pory"
	emote_question_mark
# 741 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_fastest_up
# 742 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 743 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_fastest_down
# 744 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 745 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 746 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_fastest_left
# 747 "data/maps/SlateportCity/scripts.pory"
	step_end
# 748 "data/maps/SlateportCity/scripts.pory"

# 749 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_GabbyExit: @ 81DD319
# 750 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 751 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 752 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 753 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 754 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 755 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 756 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 757 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 758 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 759 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 760 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 761 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 762 "data/maps/SlateportCity/scripts.pory"
	step_end
# 763 "data/maps/SlateportCity/scripts.pory"

# 764 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_TyExit: @ 81DD326
# 765 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 766 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 767 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 768 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 769 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 770 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 771 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 772 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 773 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 774 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 775 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 776 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 777 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 778 "data/maps/SlateportCity/scripts.pory"
	step_end
# 779 "data/maps/SlateportCity/scripts.pory"

# 780 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_Unused: @ 81DD334
# 781 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 782 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_fastest_up
# 783 "data/maps/SlateportCity/scripts.pory"
	step_end
# 784 "data/maps/SlateportCity/scripts.pory"

# 785 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_SternEnterHarbor: @ 81DD337
# 786 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 787 "data/maps/SlateportCity/scripts.pory"
	walk_up
# 788 "data/maps/SlateportCity/scripts.pory"
	walk_up
# 789 "data/maps/SlateportCity/scripts.pory"
	set_invisible
# 790 "data/maps/SlateportCity/scripts.pory"
	step_end
# 791 "data/maps/SlateportCity/scripts.pory"

# 792 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_SternWatchGabbyAndTyExit: @ 81DD33C
# 793 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 794 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 795 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 796 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 797 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 798 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 799 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 800 "data/maps/SlateportCity/scripts.pory"
	step_end
# 801 "data/maps/SlateportCity/scripts.pory"

# 802 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerEnterHarbor: @ 81DD344
# 803 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_fastest_right
# 804 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 805 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 806 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 807 "data/maps/SlateportCity/scripts.pory"
	walk_up
# 808 "data/maps/SlateportCity/scripts.pory"
	step_end
# 809 "data/maps/SlateportCity/scripts.pory"

# 810 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerFaceStern: @ 81DD34A
# 811 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 812 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 813 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 814 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 815 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 816 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 817 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 818 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_fastest_down
# 819 "data/maps/SlateportCity/scripts.pory"
	step_end
# 820 "data/maps/SlateportCity/scripts.pory"

# 821 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Ty:: @ 81DD353
# 822 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
# 823 "data/maps/SlateportCity/scripts.pory"
	end
# 824 "data/maps/SlateportCity/scripts.pory"

# 825 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Gabby:: @ 81DD35C
# 826 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
# 827 "data/maps/SlateportCity/scripts.pory"
	end
# 828 "data/maps/SlateportCity/scripts.pory"

# 829 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man3:: @ 81DD365
# 830 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
# 831 "data/maps/SlateportCity/scripts.pory"
	end
# 832 "data/maps/SlateportCity/scripts.pory"

# 833 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BerryPowderClerk:: @ 81DD36E
# 834 "data/maps/SlateportCity/scripts.pory"
	lock
# 835 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 836 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
# 837 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
# 838 "data/maps/SlateportCity/scripts.pory"
	giveitem ITEM_POWDER_JAR
# 839 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_RECEIVED_POWDER_JAR
# 840 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
# 841 "data/maps/SlateportCity/scripts.pory"
	release
# 842 "data/maps/SlateportCity/scripts.pory"
	end
# 843 "data/maps/SlateportCity/scripts.pory"

# 844 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ReceivedPowderJar:: @ 81DD39A
# 845 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8004, 1
# 846 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, HasEnoughBerryPowder
# 847 "data/maps/SlateportCity/scripts.pory"
	compare VAR_RESULT, FALSE
# 848 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq SlateportCity_EventScript_ExplainBerryPowder
# 849 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
# 850 "data/maps/SlateportCity/scripts.pory"
	special DisplayBerryPowderVendorMenu
# 851 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_ChooseBerryPowderItem
# 852 "data/maps/SlateportCity/scripts.pory"
	end
# 853 "data/maps/SlateportCity/scripts.pory"

# 854 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ExplainBerryPowder:: @ 81DD3C0
# 855 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
# 856 "data/maps/SlateportCity/scripts.pory"
	release
# 857 "data/maps/SlateportCity/scripts.pory"
	end
# 858 "data/maps/SlateportCity/scripts.pory"

# 859 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ChooseBerryPowderItem:: @ 81DD3CA
# 860 "data/maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_ExchangeWhatWithIt
# 861 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 862 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
# 863 "data/maps/SlateportCity/scripts.pory"
	special ShowScrollableMultichoice
# 864 "data/maps/SlateportCity/scripts.pory"
	waitstate
# 865 "data/maps/SlateportCity/scripts.pory"
	switch VAR_RESULT
# 866 "data/maps/SlateportCity/scripts.pory"
	case 0, SlateportCity_EventScript_EnergyPowder
# 867 "data/maps/SlateportCity/scripts.pory"
	case 1, SlateportCity_EventScript_EnergyRoot
# 868 "data/maps/SlateportCity/scripts.pory"
	case 2, SlateportCity_EventScript_HealPowder
# 869 "data/maps/SlateportCity/scripts.pory"
	case 3, SlateportCity_EventScript_RevivalHerb
# 870 "data/maps/SlateportCity/scripts.pory"
	case 4, SlateportCity_EventScript_Protein
# 871 "data/maps/SlateportCity/scripts.pory"
	case 5, SlateportCity_EventScript_Iron
# 872 "data/maps/SlateportCity/scripts.pory"
	case 6, SlateportCity_EventScript_Carbos
# 873 "data/maps/SlateportCity/scripts.pory"
	case 7, SlateportCity_EventScript_Calcium
# 874 "data/maps/SlateportCity/scripts.pory"
	case 8, SlateportCity_EventScript_Zinc
# 875 "data/maps/SlateportCity/scripts.pory"
	case 9, SlateportCity_EventScript_HPUp
# 876 "data/maps/SlateportCity/scripts.pory"
	case 10, SlateportCity_EventScript_PPUp
# 877 "data/maps/SlateportCity/scripts.pory"
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
# 878 "data/maps/SlateportCity/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
# 879 "data/maps/SlateportCity/scripts.pory"
	end
# 880 "data/maps/SlateportCity/scripts.pory"

# 881 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyPowder:: @ 81DD46E
# 882 "data/maps/SlateportCity/scripts.pory"
	bufferitemname 0, ITEM_ENERGY_POWDER
# 883 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
# 884 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 50
# 885 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 886 "data/maps/SlateportCity/scripts.pory"
	end
# 887 "data/maps/SlateportCity/scripts.pory"

# 888 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyRoot:: @ 81DD482
# 889 "data/maps/SlateportCity/scripts.pory"
	bufferitemname 0, ITEM_ENERGY_ROOT
# 890 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
# 891 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 80
# 892 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 893 "data/maps/SlateportCity/scripts.pory"
	end
# 894 "data/maps/SlateportCity/scripts.pory"

# 895 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HealPowder:: @ 81DD496
# 896 "data/maps/SlateportCity/scripts.pory"
	bufferitemname 0, ITEM_HEAL_POWDER
# 897 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_HEAL_POWDER
# 898 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 50
# 899 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 900 "data/maps/SlateportCity/scripts.pory"
	end
# 901 "data/maps/SlateportCity/scripts.pory"

# 902 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RevivalHerb:: @ 81DD4AA
# 903 "data/maps/SlateportCity/scripts.pory"
	bufferitemname 0, ITEM_REVIVAL_HERB
# 904 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
# 905 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 300
# 906 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 907 "data/maps/SlateportCity/scripts.pory"
	end
# 908 "data/maps/SlateportCity/scripts.pory"

# 909 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Protein:: @ 81DD4BE
# 910 "data/maps/SlateportCity/scripts.pory"
	bufferitemname 0, ITEM_PROTEIN
# 911 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_PROTEIN
# 912 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 913 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 914 "data/maps/SlateportCity/scripts.pory"
	end
# 915 "data/maps/SlateportCity/scripts.pory"

# 916 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Iron:: @ 81DD4D2
# 917 "data/maps/SlateportCity/scripts.pory"
	bufferitemname 0, ITEM_IRON
# 918 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_IRON
# 919 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 920 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 921 "data/maps/SlateportCity/scripts.pory"
	end
# 922 "data/maps/SlateportCity/scripts.pory"

# 923 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Carbos:: @ 81DD4E6
# 924 "data/maps/SlateportCity/scripts.pory"
	bufferitemname 0, ITEM_CARBOS
# 925 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_CARBOS
# 926 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 927 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 928 "data/maps/SlateportCity/scripts.pory"
	end
# 929 "data/maps/SlateportCity/scripts.pory"

# 930 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Calcium:: @ 81DD4FA
# 931 "data/maps/SlateportCity/scripts.pory"
	bufferitemname 0, ITEM_CALCIUM
# 932 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_CALCIUM
# 933 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 934 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 935 "data/maps/SlateportCity/scripts.pory"
	end
# 936 "data/maps/SlateportCity/scripts.pory"

# 937 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Zinc:: @ 81DD50E
# 938 "data/maps/SlateportCity/scripts.pory"
	bufferitemname 0, ITEM_ZINC
# 939 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ZINC
# 940 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 941 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 942 "data/maps/SlateportCity/scripts.pory"
	end
# 943 "data/maps/SlateportCity/scripts.pory"

# 944 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HPUp:: @ 81DD522
# 945 "data/maps/SlateportCity/scripts.pory"
	bufferitemname 0, ITEM_HP_UP
# 946 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_HP_UP
# 947 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 948 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 949 "data/maps/SlateportCity/scripts.pory"
	end
# 950 "data/maps/SlateportCity/scripts.pory"

# 951 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PPUp:: @ 81DD536
# 952 "data/maps/SlateportCity/scripts.pory"
	bufferitemname 0, ITEM_PP_UP
# 953 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_PP_UP
# 954 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 3000
# 955 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 956 "data/maps/SlateportCity/scripts.pory"
	end
# 957 "data/maps/SlateportCity/scripts.pory"

# 958 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CancelPowderItemSelect:: @ 81DD54A
# 959 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
# 960 "data/maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 961 "data/maps/SlateportCity/scripts.pory"
	release
# 962 "data/maps/SlateportCity/scripts.pory"
	end
# 963 "data/maps/SlateportCity/scripts.pory"

# 964 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_TryBuyBerryPowderItem:: @ 81DD557
# 965 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
# 966 "data/maps/SlateportCity/scripts.pory"
	compare VAR_RESULT, NO
# 967 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq SlateportCity_EventScript_ChooseBerryPowderItem
# 968 "data/maps/SlateportCity/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8009
# 969 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, HasEnoughBerryPowder
# 970 "data/maps/SlateportCity/scripts.pory"
	compare VAR_RESULT, FALSE
# 971 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq SlateportCity_EventScript_NotEnoughBerryPowder
# 972 "data/maps/SlateportCity/scripts.pory"
	giveitem VAR_0x8008
# 973 "data/maps/SlateportCity/scripts.pory"
	compare VAR_RESULT, FALSE
# 974 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq SlateportCity_EventScript_NoRoomForBerryPowderItem
# 975 "data/maps/SlateportCity/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8009
# 976 "data/maps/SlateportCity/scripts.pory"
	special TakeBerryPowder
# 977 "data/maps/SlateportCity/scripts.pory"
	special PrintPlayerBerryPowderAmount
# 978 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
# 979 "data/maps/SlateportCity/scripts.pory"
	compare VAR_RESULT, YES
# 980 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq SlateportCity_EventScript_ChooseBerryPowderItem
# 981 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
# 982 "data/maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 983 "data/maps/SlateportCity/scripts.pory"
	release
# 984 "data/maps/SlateportCity/scripts.pory"
	end
# 985 "data/maps/SlateportCity/scripts.pory"

# 986 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NoRoomForBerryPowderItem:: @ 81DD5C1
# 987 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
# 988 "data/maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 989 "data/maps/SlateportCity/scripts.pory"
	release
# 990 "data/maps/SlateportCity/scripts.pory"
	end
# 991 "data/maps/SlateportCity/scripts.pory"

# 992 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NotEnoughBerryPowder:: @ 81DD5CE
# 993 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
# 994 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_ChooseBerryPowderItem
# 995 "data/maps/SlateportCity/scripts.pory"
	end
# 996 "data/maps/SlateportCity/scripts.pory"

# 997 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ScottBattleTentScene:: @ 81DD5DC
# 998 "data/maps/SlateportCity/scripts.pory"
	lockall
# 999 "data/maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 1000 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 1001 "data/maps/SlateportCity/scripts.pory"
	opendoor 10, 12
# 1002 "data/maps/SlateportCity/scripts.pory"
	waitdooranim
# 1003 "data/maps/SlateportCity/scripts.pory"
	addobject LOCALID_SCOTT
# 1004 "data/maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PushPlayerDown
# 1005 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitBattleTent
# 1006 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 1007 "data/maps/SlateportCity/scripts.pory"
	closedoor 10, 12
# 1008 "data/maps/SlateportCity/scripts.pory"
	waitdooranim
# 1009 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
# 1010 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 1011 "data/maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
# 1012 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
# 1013 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 1014 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SCOTT
# 1015 "data/maps/SlateportCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 1016 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
# 1017 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 1018 "data/maps/SlateportCity/scripts.pory"
	end
# 1019 "data/maps/SlateportCity/scripts.pory"

# 1020 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Brawly::
# 1021 "data/maps/SlateportCity/scripts.pory"
	lockall
# 1022 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhoahLineSoLong, MSGBOX_DEFAULT
# 1023 "data/maps/SlateportCity/scripts.pory"
	waitse
# 1024 "data/maps/SlateportCity/scripts.pory"
	playse SE_PIN
# 1025 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_BRAWLY, Common_Movement_ExclamationMark
# 1026 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 1027 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_BRAWLY, Common_Movement_Delay48
# 1028 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 1029 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 1030 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_LookingForBrawly, MSGBOX_DEFAULT
# 1031 "data/maps/SlateportCity/scripts.pory"
	fadescreen FADE_TO_BLACK
# 1032 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 1033 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_BRAWLY
# 1034 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_BRAWLY
# 1035 "data/maps/SlateportCity/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 1036 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 1037 "data/maps/SlateportCity/scripts.pory"
	end
# 1038 "data/maps/SlateportCity/scripts.pory"

# 1039 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PushPlayerDown: @ 81DD630
# 1040 "data/maps/SlateportCity/scripts.pory"
	lock_facing_direction
# 1041 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 1042 "data/maps/SlateportCity/scripts.pory"
	unlock_facing_direction
# 1043 "data/maps/SlateportCity/scripts.pory"
	step_end
# 1044 "data/maps/SlateportCity/scripts.pory"

# 1045 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerWatchScottExit: @ 81DD634
# 1046 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 1047 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_fastest_right
# 1048 "data/maps/SlateportCity/scripts.pory"
	step_end
# 1049 "data/maps/SlateportCity/scripts.pory"

# 1050 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExitBattleTent: @ 81DD637
# 1051 "data/maps/SlateportCity/scripts.pory"
	delay_8
# 1052 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 1053 "data/maps/SlateportCity/scripts.pory"
	step_end
# 1054 "data/maps/SlateportCity/scripts.pory"

# 1055 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExitAfterBattleTent: @ 81DD63A
# 1056 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 1057 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 1058 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 1059 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 1060 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 1061 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 1062 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 1063 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 1064 "data/maps/SlateportCity/scripts.pory"
	step_end
# 1065 "data/maps/SlateportCity/scripts.pory"

# 1066 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BerryCrushRankingsSign:: @ 81DD643
# 1067 "data/maps/SlateportCity/scripts.pory"
	lockall
# 1068 "data/maps/SlateportCity/scripts.pory"
	special ShowBerryCrushRankings
# 1069 "data/maps/SlateportCity/scripts.pory"
	waitstate
# 1070 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 1071 "data/maps/SlateportCity/scripts.pory"
	end
# 1072 "data/maps/SlateportCity/scripts.pory"

# 1073 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhoahLineSoLong:
# 1074 "data/maps/SlateportCity/scripts.pory"
	.string "Whoah! This line's way too long,\n"
# 1075 "data/maps/SlateportCity/scripts.pory"
	.string "dude! What's the deal?$"
# 1076 "data/maps/SlateportCity/scripts.pory"

# 1077 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_LookingForBrawly:
# 1078 "data/maps/SlateportCity/scripts.pory"
	.string "Oh, hey there!\p"
# 1079 "data/maps/SlateportCity/scripts.pory"
	.string "Hmm? You're looking for the\n"
# 1080 "data/maps/SlateportCity/scripts.pory"
	.string "Dewford Gym Leader?\p"
# 1081 "data/maps/SlateportCity/scripts.pory"
	.string "That'd be me, Brawly!\n"
# 1082 "data/maps/SlateportCity/scripts.pory"
	.string "I guess you want a battle, yeah?\p"
# 1083 "data/maps/SlateportCity/scripts.pory"
	.string "Gnarly! I'll head back to the Gym.\n"
# 1084 "data/maps/SlateportCity/scripts.pory"
	.string "You better be ready to make a splash!$"
# 1085 "data/maps/SlateportCity/scripts.pory"

# 1086 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_EnergyGuruSellWhatYouNeed:
# 1087 "data/maps/SlateportCity/scripts.pory"
	.string "I'm the Energy Guru! I'll go for it and\n"
# 1088 "data/maps/SlateportCity/scripts.pory"
	.string "sell you what you need!$"
# 1089 "data/maps/SlateportCity/scripts.pory"

# 1090 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PowerItemsSellWhatYouNeed:
# 1091 "data/maps/SlateportCity/scripts.pory"
	.string "Need to boost your Pokémon's\n"
# 1092 "data/maps/SlateportCity/scripts.pory"
	.string "training?\p"
# 1093 "data/maps/SlateportCity/scripts.pory"
	.string "Give these a try!$"
# 1094 "data/maps/SlateportCity/scripts.pory"

# 1095 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_IncenseStand:
# 1096 "data/maps/SlateportCity/scripts.pory"
	.string "Wouldn't you like some fragrant\n"
# 1097 "data/maps/SlateportCity/scripts.pory"
	.string "incense?$"
# 1098 "data/maps/SlateportCity/scripts.pory"

# 1099 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_OhYourPokemon: @ 81DD68A
# 1100 "data/maps/SlateportCity/scripts.pory"
	.string "Oh?\n"
# 1101 "data/maps/SlateportCity/scripts.pory"
	.string "Your {STR_VAR_1}…$"
# 1102 "data/maps/SlateportCity/scripts.pory"

# 1103 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PleaseGiveItThisEffortRibbon: @ 81DD697
# 1104 "data/maps/SlateportCity/scripts.pory"
	.string "Went for it stupendously!\p"
# 1105 "data/maps/SlateportCity/scripts.pory"
	.string "As its reward, please give it this\n"
# 1106 "data/maps/SlateportCity/scripts.pory"
	.string "Effort Ribbon.$"
# 1107 "data/maps/SlateportCity/scripts.pory"

# 1108 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ReceivedEffortRibbon: @ 81DD6E3
# 1109 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER} received the Effort Ribbon.$"
# 1110 "data/maps/SlateportCity/scripts.pory"

# 1111 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PutEffortRibbonOnMon: @ 81DD702
# 1112 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER} put the Effort Ribbon\n"
# 1113 "data/maps/SlateportCity/scripts.pory"
	.string "on {STR_VAR_1}.$"
# 1114 "data/maps/SlateportCity/scripts.pory"

# 1115 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GoForItLittleHarder: @ 81DD722
# 1116 "data/maps/SlateportCity/scripts.pory"
	.string "You have to go for it a little harder.\p"
# 1117 "data/maps/SlateportCity/scripts.pory"
	.string "If you do, I'll give your Pokémon\n"
# 1118 "data/maps/SlateportCity/scripts.pory"
	.string "something nice.$"
# 1119 "data/maps/SlateportCity/scripts.pory"

# 1120 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_EffortRibbonLooksGoodOnIt: @ 81DD77B
# 1121 "data/maps/SlateportCity/scripts.pory"
	.string "Oh! Your {STR_VAR_1}, that Effort\n"
# 1122 "data/maps/SlateportCity/scripts.pory"
	.string "Ribbon looks good on it!$"
# 1123 "data/maps/SlateportCity/scripts.pory"

# 1124 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WonderIfLighthouseStartlesPokemon: @ 81DD7AD
# 1125 "data/maps/SlateportCity/scripts.pory"
	.string "The light of the lighthouse reaches\n"
# 1126 "data/maps/SlateportCity/scripts.pory"
	.string "dozens of miles away.\p"
# 1127 "data/maps/SlateportCity/scripts.pory"
	.string "I wonder if it doesn't startle Pokémon\n"
# 1128 "data/maps/SlateportCity/scripts.pory"
	.string "in the sea.$"
# 1129 "data/maps/SlateportCity/scripts.pory"

# 1130 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SeaweedFullOfLife: @ 81DD81A
# 1131 "data/maps/SlateportCity/scripts.pory"
	.string "Ooh, look at this!\p"
# 1132 "data/maps/SlateportCity/scripts.pory"
	.string "The seaweed you can get around these\n"
# 1133 "data/maps/SlateportCity/scripts.pory"
	.string "parts is fresh and full of life.\p"
# 1134 "data/maps/SlateportCity/scripts.pory"
	.string "Why, it looks like it can even rear up\n"
# 1135 "data/maps/SlateportCity/scripts.pory"
	.string "and attack!$"
# 1136 "data/maps/SlateportCity/scripts.pory"

# 1137 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HowTownIsBornAndGrows: @ 81DD8A6
# 1138 "data/maps/SlateportCity/scripts.pory"
	.string "Where the water is clean, the fruits\n"
# 1139 "data/maps/SlateportCity/scripts.pory"
	.string "of bountiful harvest gather.\p"
# 1140 "data/maps/SlateportCity/scripts.pory"
	.string "And where people gather, a market\n"
# 1141 "data/maps/SlateportCity/scripts.pory"
	.string "soon starts.\p"
# 1142 "data/maps/SlateportCity/scripts.pory"
	.string "That is how a town is born and grows.$"
# 1143 "data/maps/SlateportCity/scripts.pory"

# 1144 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SlateportWonderfulPlace: @ 81DD93D
# 1145 "data/maps/SlateportCity/scripts.pory"
	.string "Shopping where you can breathe the\n"
# 1146 "data/maps/SlateportCity/scripts.pory"
	.string "scent of the ocean…\p"
# 1147 "data/maps/SlateportCity/scripts.pory"
	.string "Slateport is such a wonderful place!$"
# 1148 "data/maps/SlateportCity/scripts.pory"

# 1149 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BuyBricksSoDecorWontGetDirty: @ 81DD999
# 1150 "data/maps/SlateportCity/scripts.pory"
	.string "If you put Dolls or Cushions on\n"
# 1151 "data/maps/SlateportCity/scripts.pory"
	.string "the floor, they'll get dirty.\p"
# 1152 "data/maps/SlateportCity/scripts.pory"
	.string "I'm going to buy some Bricks so my\n"
# 1153 "data/maps/SlateportCity/scripts.pory"
	.string "Dolls and Cushions won't get dirty\l"
# 1154 "data/maps/SlateportCity/scripts.pory"
	.string "when I leave them out.$"
# 1155 "data/maps/SlateportCity/scripts.pory"

# 1156 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GoingToCompeteInBattleTent: @ 81DDA34
# 1157 "data/maps/SlateportCity/scripts.pory"
	.string "Wroooar! I'm going to compete in\n"
# 1158 "data/maps/SlateportCity/scripts.pory"
	.string "the Battle Tent, too!\p"
# 1159 "data/maps/SlateportCity/scripts.pory"
	.string "But before that, I need to catch\n"
# 1160 "data/maps/SlateportCity/scripts.pory"
	.string "some Pokémon!$"
# 1161 "data/maps/SlateportCity/scripts.pory"

# 1162 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BushedHikingFromMauville: @ 81DDA9A
# 1163 "data/maps/SlateportCity/scripts.pory"
	.string "Whew… I'm just bushed…\p"
# 1164 "data/maps/SlateportCity/scripts.pory"
	.string "I hiked over from Mauville City.\n"
# 1165 "data/maps/SlateportCity/scripts.pory"
	.string "But, boy, this city's huge.\p"
# 1166 "data/maps/SlateportCity/scripts.pory"
	.string "If I'd known this, I would've ridden\n"
# 1167 "data/maps/SlateportCity/scripts.pory"
	.string "my Bike here.$"
# 1168 "data/maps/SlateportCity/scripts.pory"

# 1169 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_EveryoneCallsHimCaptStern: @ 81DDB21
# 1170 "data/maps/SlateportCity/scripts.pory"
	.string "Stern, the fellow who built the\n"
# 1171 "data/maps/SlateportCity/scripts.pory"
	.string "MUSEUM, also happens to be the leader\l"
# 1172 "data/maps/SlateportCity/scripts.pory"
	.string "of an undersea exploration team.\p"
# 1173 "data/maps/SlateportCity/scripts.pory"
	.string "So, everyone calls him Capt. Stern.$"
# 1174 "data/maps/SlateportCity/scripts.pory"

# 1175 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatsLongLineOverThere: @ 81DDBAC
# 1176 "data/maps/SlateportCity/scripts.pory"
	.string "What is that over there?\n"
# 1177 "data/maps/SlateportCity/scripts.pory"
	.string "That long line…$"
# 1178 "data/maps/SlateportCity/scripts.pory"

# 1179 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_VisitedMuseumOften: @ 81DDBD5
# 1180 "data/maps/SlateportCity/scripts.pory"
	.string "When I was a child, I visited\n"
# 1181 "data/maps/SlateportCity/scripts.pory"
	.string "the Museum often.\p"
# 1182 "data/maps/SlateportCity/scripts.pory"
	.string "I used to dream about the mysteries of\n"
# 1183 "data/maps/SlateportCity/scripts.pory"
	.string "the sea after seeing the exhibits.$"
# 1184 "data/maps/SlateportCity/scripts.pory"

# 1185 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_QuitPushing: @ 81DDC4F
# 1186 "data/maps/SlateportCity/scripts.pory"
	.string "Hey, there! Quit pushing!\n"
# 1187 "data/maps/SlateportCity/scripts.pory"
	.string "This is the line, can't you see?$"
# 1188 "data/maps/SlateportCity/scripts.pory"

# 1189 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_AquaHasPolicy: @ 81DDC8A
# 1190 "data/maps/SlateportCity/scripts.pory"
	.string "Team Aqua has a policy of\n"
# 1191 "data/maps/SlateportCity/scripts.pory"
	.string "assembling and dispersing at\l"
# 1192 "data/maps/SlateportCity/scripts.pory"
	.string "the operation site.$"
# 1193 "data/maps/SlateportCity/scripts.pory"

# 1194 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BossIsBrilliant: @ 81DDCD5
# 1195 "data/maps/SlateportCity/scripts.pory"
	.string "Our Boss is brilliant.\p"
# 1196 "data/maps/SlateportCity/scripts.pory"
	.string "What would he want to do with\n"
# 1197 "data/maps/SlateportCity/scripts.pory"
	.string "a Museum now?$"
# 1198 "data/maps/SlateportCity/scripts.pory"

# 1199 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatsNewSchemeIWonder: @ 81DDD18
# 1200 "data/maps/SlateportCity/scripts.pory"
	.string "What's the new scheme, I wonder?\p"
# 1201 "data/maps/SlateportCity/scripts.pory"
	.string "Our Boss is scary when he's mad, so\n"
# 1202 "data/maps/SlateportCity/scripts.pory"
	.string "I'd better not screw things up…$"
# 1203 "data/maps/SlateportCity/scripts.pory"

# 1204 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ShouldTakeItAll: @ 81DDD7D
# 1205 "data/maps/SlateportCity/scripts.pory"
	.string "If there's something we need in\n"
# 1206 "data/maps/SlateportCity/scripts.pory"
	.string "the Museum, we should take it all!$"
# 1207 "data/maps/SlateportCity/scripts.pory"

# 1208 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_DontButtIn: @ 81DDDC0
# 1209 "data/maps/SlateportCity/scripts.pory"
	.string "Hey, you there!\n"
# 1210 "data/maps/SlateportCity/scripts.pory"
	.string "Don't butt in!$"
# 1211 "data/maps/SlateportCity/scripts.pory"

# 1212 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_RemindsMeOfLongLineForGames: @ 81DDDDF
# 1213 "data/maps/SlateportCity/scripts.pory"
	.string "A long line, huh?\p"
# 1214 "data/maps/SlateportCity/scripts.pory"
	.string "It reminds me of the times I lined up to\n"
# 1215 "data/maps/SlateportCity/scripts.pory"
	.string "buy smash-hit games…$"
# 1216 "data/maps/SlateportCity/scripts.pory"

# 1217 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhyAreWeLiningUp: @ 81DDE2F
# 1218 "data/maps/SlateportCity/scripts.pory"
	.string "Why are we even lining up and paying?\n"
# 1219 "data/maps/SlateportCity/scripts.pory"
	.string "We should just march in!$"
# 1220 "data/maps/SlateportCity/scripts.pory"

# 1221 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatDoYouWant: @ 81DDE6E
# 1222 "data/maps/SlateportCity/scripts.pory"
	.string "What?\n"
# 1223 "data/maps/SlateportCity/scripts.pory"
	.string "What do you want?$"
# 1224 "data/maps/SlateportCity/scripts.pory"

# 1225 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_IllReadSignForYou: @ 81DDE86
# 1226 "data/maps/SlateportCity/scripts.pory"
	.string "You want to read this sign?\n"
# 1227 "data/maps/SlateportCity/scripts.pory"
	.string "I'll read it for you!$"
# 1228 "data/maps/SlateportCity/scripts.pory"

# 1229 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SaysSomethingLikeSeaIsEndless: @ 81DDEB8
# 1230 "data/maps/SlateportCity/scripts.pory"
	.string "Let's see…\p"
# 1231 "data/maps/SlateportCity/scripts.pory"
	.string "Um… I think it says something like\n"
# 1232 "data/maps/SlateportCity/scripts.pory"
	.string "“the life in the sea is endless.”\p"
# 1233 "data/maps/SlateportCity/scripts.pory"
	.string "Yup, I'm pretty sure that's what\n"
# 1234 "data/maps/SlateportCity/scripts.pory"
	.string "it says.$"
# 1235 "data/maps/SlateportCity/scripts.pory"

# 1236 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ShouldveBroughtMyGameBoy: @ 81DDF32
# 1237 "data/maps/SlateportCity/scripts.pory"
	.string "Grumble…\p"
# 1238 "data/maps/SlateportCity/scripts.pory"
	.string "I should've brought Elite Redux\n"
# 1239 "data/maps/SlateportCity/scripts.pory"
	.string "so I wouldn't get bored in line…\p"
# 1240 "data/maps/SlateportCity/scripts.pory"
	.string "Grumble…$"
# 1241 "data/maps/SlateportCity/scripts.pory"

# 1242 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HotSpringsAfterOperation: @ 81DDF8D
# 1243 "data/maps/SlateportCity/scripts.pory"
	.string "When this operation's over, I'll take\n"
# 1244 "data/maps/SlateportCity/scripts.pory"
	.string "you to a hot spring spa!\p"
# 1245 "data/maps/SlateportCity/scripts.pory"
	.string "That's what our leader said.\n"
# 1246 "data/maps/SlateportCity/scripts.pory"
	.string "I can't wait!$"
# 1247 "data/maps/SlateportCity/scripts.pory"

# 1248 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SeaIsSoWet: @ 81DDFF7
# 1249 "data/maps/SlateportCity/scripts.pory"
	.string "The sea is just so vast…\p"
# 1250 "data/maps/SlateportCity/scripts.pory"
	.string "Could the sea have been made by\n"
# 1251 "data/maps/SlateportCity/scripts.pory"
	.string "the tears shed by Pokémon?$"
# 1252 "data/maps/SlateportCity/scripts.pory"

# 1253 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SinkOldBoats: @ 81DE04B
# 1254 "data/maps/SlateportCity/scripts.pory"
	.string "Do you know what they do with old\n"
# 1255 "data/maps/SlateportCity/scripts.pory"
	.string "ships that become too creaky to sail?\p"
# 1256 "data/maps/SlateportCity/scripts.pory"
	.string "They sink them in the sea so they\n"
# 1257 "data/maps/SlateportCity/scripts.pory"
	.string "become habitats for Pokémon.$"
# 1258 "data/maps/SlateportCity/scripts.pory"

# 1259 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BuyTooMuch: @ 81DE0D2
# 1260 "data/maps/SlateportCity/scripts.pory"
	.string "Whenever I visit here, I get carried\n"
# 1261 "data/maps/SlateportCity/scripts.pory"
	.string "away and buy too much.$"
# 1262 "data/maps/SlateportCity/scripts.pory"

# 1263 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GetNameRaterToHelpYou: @ 81DE10E
# 1264 "data/maps/SlateportCity/scripts.pory"
	.string "If you want to change your Pokémon's\n"
# 1265 "data/maps/SlateportCity/scripts.pory"
	.string "nickname, you'll have to get a Name\l"
# 1266 "data/maps/SlateportCity/scripts.pory"
	.string "Rater to help you.\p"
# 1267 "data/maps/SlateportCity/scripts.pory"
	.string "You can find one in every Pokémon\n"
# 1268 "data/maps/SlateportCity/scripts.pory"
	.string "Center.$"
# 1269 "data/maps/SlateportCity/scripts.pory"

# 1270 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CantChangeTradeMonName: @ 81DE16C
# 1271 "data/maps/SlateportCity/scripts.pory"
	.string "Any Pokémon you get in a trade,\n"
# 1272 "data/maps/SlateportCity/scripts.pory"
	.string "you can't change its nickname.\p"
# 1273 "data/maps/SlateportCity/scripts.pory"
	.string "The original Trainer's love for that\n"
# 1274 "data/maps/SlateportCity/scripts.pory"
	.string "Pokémon is in the nickname.$"
# 1275 "data/maps/SlateportCity/scripts.pory"

# 1276 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BattleTentBuiltRecently: @ 81DE1EC
# 1277 "data/maps/SlateportCity/scripts.pory"
	.string "Recently, a Battle Tent was built\n"
# 1278 "data/maps/SlateportCity/scripts.pory"
	.string "in Slateport.\p"
# 1279 "data/maps/SlateportCity/scripts.pory"
	.string "Gyms are fun, but the Battle Tent's\n"
# 1280 "data/maps/SlateportCity/scripts.pory"
	.string "awesome in its own way.\p"
# 1281 "data/maps/SlateportCity/scripts.pory"
	.string "You should go find tough Pokémon\n"
# 1282 "data/maps/SlateportCity/scripts.pory"
	.string "for the Battle Tent!$"
# 1283 "data/maps/SlateportCity/scripts.pory"

# 1284 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptSternBeingInterviewed: @ 81DE28E
# 1285 "data/maps/SlateportCity/scripts.pory"
	.string "I was hoping that it was a famous star\n"
# 1286 "data/maps/SlateportCity/scripts.pory"
	.string "so I could get an autograph.\p"
# 1287 "data/maps/SlateportCity/scripts.pory"
	.string "But who's that being interviewed?\n"
# 1288 "data/maps/SlateportCity/scripts.pory"
	.string "Isn't that Capt. Stern?$"
# 1289 "data/maps/SlateportCity/scripts.pory"

# 1290 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_InterviewerSoCool: @ 81DE30C
# 1291 "data/maps/SlateportCity/scripts.pory"
	.string "That lady interviewer is so cool\n"
# 1292 "data/maps/SlateportCity/scripts.pory"
	.string "and pretty.\p"
# 1293 "data/maps/SlateportCity/scripts.pory"
	.string "When I grow up, I'm going to be\n"
# 1294 "data/maps/SlateportCity/scripts.pory"
	.string "an international journalist!$"
# 1295 "data/maps/SlateportCity/scripts.pory"

# 1296 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternSaysDiscoveredSomething: @ 81DE376
# 1297 "data/maps/SlateportCity/scripts.pory"
	.string "Capt. Stern says they discovered\n"
# 1298 "data/maps/SlateportCity/scripts.pory"
	.string "something at the bottom of the sea.\p"
# 1299 "data/maps/SlateportCity/scripts.pory"
	.string "I wonder what it is?\n"
# 1300 "data/maps/SlateportCity/scripts.pory"
	.string "What could it be?$"
# 1301 "data/maps/SlateportCity/scripts.pory"

# 1302 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptainComeBackWithBigFish: @ 81DE3E2
# 1303 "data/maps/SlateportCity/scripts.pory"
	.string "What's going on here?\p"
# 1304 "data/maps/SlateportCity/scripts.pory"
	.string "Did the good Captain come back with\n"
# 1305 "data/maps/SlateportCity/scripts.pory"
	.string "a big fish from the ocean floor?$"
# 1306 "data/maps/SlateportCity/scripts.pory"

# 1307 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_AmIOnTV: @ 81DE43D
# 1308 "data/maps/SlateportCity/scripts.pory"
	.string "Hey! Are you watching?\n"
# 1309 "data/maps/SlateportCity/scripts.pory"
	.string "Am I on TV?$"
# 1310 "data/maps/SlateportCity/scripts.pory"

# 1311 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptainsACelebrity: @ 81DE460
# 1312 "data/maps/SlateportCity/scripts.pory"
	.string "A TV interview! Here!\n"
# 1313 "data/maps/SlateportCity/scripts.pory"
	.string "The Captain's a celebrity!$"
# 1314 "data/maps/SlateportCity/scripts.pory"

# 1315 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BigSmileForCamera: @ 81DE491
# 1316 "data/maps/SlateportCity/scripts.pory"
	.string "TY: Okay, Capt. Stern, a big smile\n"
# 1317 "data/maps/SlateportCity/scripts.pory"
	.string "for the camera!$"
# 1318 "data/maps/SlateportCity/scripts.pory"

# 1319 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_MostInvaluableExperience: @ 81DE4C4
# 1320 "data/maps/SlateportCity/scripts.pory"
	.string "Gabby: I see, I see. You've had a most\n"
# 1321 "data/maps/SlateportCity/scripts.pory"
	.string "invaluable experience…$"
# 1322 "data/maps/SlateportCity/scripts.pory"

# 1323 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternMoveAheadWithExploration: @ 81DE502
# 1324 "data/maps/SlateportCity/scripts.pory"
	.string "Capt. Stern: Yes, indeed. We intend to\n"
# 1325 "data/maps/SlateportCity/scripts.pory"
	.string "move ahead with our exploration.$"
# 1326 "data/maps/SlateportCity/scripts.pory"

# 1327 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GabbyWonderfulThanksForInterview: @ 81DE54A
# 1328 "data/maps/SlateportCity/scripts.pory"
	.string "Gabby: That's wonderful, Capt. Stern!\n"
# 1329 "data/maps/SlateportCity/scripts.pory"
	.string "Thank you for taking the time from\l"
# 1330 "data/maps/SlateportCity/scripts.pory"
	.string "your busy schedule to talk to us.\p"
# 1331 "data/maps/SlateportCity/scripts.pory"
	.string "We hope we can interview you again\n"
# 1332 "data/maps/SlateportCity/scripts.pory"
	.string "with news of more discoveries!$"
# 1333 "data/maps/SlateportCity/scripts.pory"

# 1334 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternWhewFirstInterview: @ 81DE5F7
# 1335 "data/maps/SlateportCity/scripts.pory"
	.string "Capt. Stern: Whew…\p"
# 1336 "data/maps/SlateportCity/scripts.pory"
	.string "That was my first time to be filmed for\n"
# 1337 "data/maps/SlateportCity/scripts.pory"
	.string "TV. That was nerve-wracking.$"
# 1338 "data/maps/SlateportCity/scripts.pory"

# 1339 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_OhPlayerWeMadeDiscovery: @ 81DE64F
# 1340 "data/maps/SlateportCity/scripts.pory"
	.string "Oh! {PLAYER}{KUN}!\n"
# 1341 "data/maps/SlateportCity/scripts.pory"
	.string "You're looking great!\p"
# 1342 "data/maps/SlateportCity/scripts.pory"
	.string "We made a huge discovery on our last\n"
# 1343 "data/maps/SlateportCity/scripts.pory"
	.string "seafloor exploration.\p"
# 1344 "data/maps/SlateportCity/scripts.pory"
	.string "We found an underwater cavern on\n"
# 1345 "data/maps/SlateportCity/scripts.pory"
	.string "Route 128.\p"
# 1346 "data/maps/SlateportCity/scripts.pory"
	.string "We think it's the habitat of a Pokémon\n"
# 1347 "data/maps/SlateportCity/scripts.pory"
	.string "that's said to have been long extinct.$"
# 1348 "data/maps/SlateportCity/scripts.pory"

# 1349 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_AquaWillAssumeControlOfSubmarine: @ 81DE724
# 1350 "data/maps/SlateportCity/scripts.pory"
	.string "Fufufu…\n"
# 1351 "data/maps/SlateportCity/scripts.pory"
	.string "Capt. Stern, I presume.\p"
# 1352 "data/maps/SlateportCity/scripts.pory"
	.string "We of Team Aqua will assume\n"
# 1353 "data/maps/SlateportCity/scripts.pory"
	.string "control of your submarine!\p"
# 1354 "data/maps/SlateportCity/scripts.pory"
	.string "Your objections are meaningless!\n"
# 1355 "data/maps/SlateportCity/scripts.pory"
	.string "We expect your total cooperation!\p"
# 1356 "data/maps/SlateportCity/scripts.pory"
	.string "Fufufu…\n"
# 1357 "data/maps/SlateportCity/scripts.pory"
	.string "Just watch and learn what Team\l"
# 1358 "data/maps/SlateportCity/scripts.pory"
	.string "Aqua has planned!$"
# 1359 "data/maps/SlateportCity/scripts.pory"

# 1360 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternWhatWasAllThat: @ 81DE7F7
# 1361 "data/maps/SlateportCity/scripts.pory"
	.string "Capt. Stern: What was that all about?\p"
# 1362 "data/maps/SlateportCity/scripts.pory"
	.string "It sounded like someone using\n"
# 1363 "data/maps/SlateportCity/scripts.pory"
	.string "a megaphone…\p"
# 1364 "data/maps/SlateportCity/scripts.pory"
	.string "Where did it come from?$"
# 1365 "data/maps/SlateportCity/scripts.pory"

# 1366 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_FromHarborTryingToTakeSub: @ 81DE860
# 1367 "data/maps/SlateportCity/scripts.pory"
	.string "It's from the Harbor!\p"
# 1368 "data/maps/SlateportCity/scripts.pory"
	.string "The submarine!\n"
# 1369 "data/maps/SlateportCity/scripts.pory"
	.string "They're trying to take it!$"
# 1370 "data/maps/SlateportCity/scripts.pory"

# 1371 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PleaseComeWithMe: @ 81DE8A0
# 1372 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER}{KUN}!\n"
# 1373 "data/maps/SlateportCity/scripts.pory"
	.string "Please, come with me!$"
# 1374 "data/maps/SlateportCity/scripts.pory"

# 1375 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BattleTentSign: @ 81DE8BC
# 1376 "data/maps/SlateportCity/scripts.pory"
	.string "Battle Tent Slateport Site\n"
# 1377 "data/maps/SlateportCity/scripts.pory"
	.string "“Find it! The ultimate Pokémon!”$"
# 1378 "data/maps/SlateportCity/scripts.pory"

# 1379 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardWantedSign: @ 81DE8F8
# 1380 "data/maps/SlateportCity/scripts.pory"
	.string "Stern's Shipyard\p"
# 1381 "data/maps/SlateportCity/scripts.pory"
	.string "“Wanted: A sailor capable of sailing\n"
# 1382 "data/maps/SlateportCity/scripts.pory"
	.string "in all currents.”$"
# 1383 "data/maps/SlateportCity/scripts.pory"

# 1384 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardNearsCompletion: @ 81DE940
# 1385 "data/maps/SlateportCity/scripts.pory"
	.string "Stern's Shipyard\p"
# 1386 "data/maps/SlateportCity/scripts.pory"
	.string "“The ferry S.S. Tidal nears\n"
# 1387 "data/maps/SlateportCity/scripts.pory"
	.string "completion for serving the ports of\l"
# 1388 "data/maps/SlateportCity/scripts.pory"
	.string "Slateport and Lilycove.”$"
# 1389 "data/maps/SlateportCity/scripts.pory"

# 1390 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardFerryComplete: @ 81DE9AA
# 1391 "data/maps/SlateportCity/scripts.pory"
	.string "Stern's Shipyard\p"
# 1392 "data/maps/SlateportCity/scripts.pory"
	.string "“Boarding of the Slateport-Lilycove\n"
# 1393 "data/maps/SlateportCity/scripts.pory"
	.string "ferry S.S. Tidal is handled at the\l"
# 1394 "data/maps/SlateportCity/scripts.pory"
	.string "Harbor.”$"
# 1395 "data/maps/SlateportCity/scripts.pory"

# 1396 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PokemonFanClubSign: @ 81DEA0B
# 1397 "data/maps/SlateportCity/scripts.pory"
	.string "Pokémon Fan Club\n"
# 1398 "data/maps/SlateportCity/scripts.pory"
	.string "“Calling all fans of Pokémon!”$"
# 1399 "data/maps/SlateportCity/scripts.pory"

# 1400 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_OceanicMuseumSign: @ 81DEA3B
# 1401 "data/maps/SlateportCity/scripts.pory"
	.string "“The endless sea sustains\n"
# 1402 "data/maps/SlateportCity/scripts.pory"
	.string "all life.”\p"
# 1403 "data/maps/SlateportCity/scripts.pory"
	.string "Oceanic Museum$"
# 1404 "data/maps/SlateportCity/scripts.pory"

# 1405 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CitySign: @ 81DEA6F
# 1406 "data/maps/SlateportCity/scripts.pory"
	.string "Slateport City\p"
# 1407 "data/maps/SlateportCity/scripts.pory"
	.string "“The port where people and Pokémon\n"
# 1408 "data/maps/SlateportCity/scripts.pory"
	.string "cross paths.”$"
# 1409 "data/maps/SlateportCity/scripts.pory"

# 1410 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_MarketSign: @ 81DEAAF
# 1411 "data/maps/SlateportCity/scripts.pory"
	.string "Slateport Market\n"
# 1412 "data/maps/SlateportCity/scripts.pory"
	.string "“Unique items found nowhere else!”$"
# 1413 "data/maps/SlateportCity/scripts.pory"

# 1414 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HarborFerryUnderConstruction: @ 81DEAE3
# 1415 "data/maps/SlateportCity/scripts.pory"
	.string "Slateport Harbor\p"
# 1416 "data/maps/SlateportCity/scripts.pory"
	.string "“The ferry S.S. Tidal is under\n"
# 1417 "data/maps/SlateportCity/scripts.pory"
	.string "construction in the Shipyard.\p"
# 1418 "data/maps/SlateportCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 1419 "data/maps/SlateportCity/scripts.pory"
	.string "shortly.”$"
# 1420 "data/maps/SlateportCity/scripts.pory"

# 1421 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HarborSign: @ 81DEB5A
# 1422 "data/maps/SlateportCity/scripts.pory"
	.string "Slateport Harbor\p"
# 1423 "data/maps/SlateportCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 1424 "data/maps/SlateportCity/scripts.pory"
	.string "the ferry S.S. Tidal.”$"
# 1425 "data/maps/SlateportCity/scripts.pory"

# 1426 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_NameRatersHouseSign: @ 81DEBA0
# 1427 "data/maps/SlateportCity/scripts.pory"
	.string "Pokémon Chef's House\n"
# 1428 "data/maps/SlateportCity/scripts.pory"
	.string "Abandoned.$"
# 1429 "data/maps/SlateportCity/scripts.pory"

# 1430 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExplainBerries: @ 81DEBCE
# 1431 "data/maps/SlateportCity/scripts.pory"
	.string "If a wild Pokémon gets hurt, it heals\n"
# 1432 "data/maps/SlateportCity/scripts.pory"
	.string "itself by chewing on Berries.\p"
# 1433 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1434 "data/maps/SlateportCity/scripts.pory"
	.string "Somebody saw that and got the idea\n"
# 1435 "data/maps/SlateportCity/scripts.pory"
	.string "of making medicine from Berries.\p"
# 1436 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1437 "data/maps/SlateportCity/scripts.pory"
	.string "To turn Berries into medicine,\n"
# 1438 "data/maps/SlateportCity/scripts.pory"
	.string "they must be crushed into powder.\p"
# 1439 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1440 "data/maps/SlateportCity/scripts.pory"
	.string "You seem to have an interest\n"
# 1441 "data/maps/SlateportCity/scripts.pory"
	.string "in Berries!\p"
# 1442 "data/maps/SlateportCity/scripts.pory"
	.string "I've got something good for someone\n"
# 1443 "data/maps/SlateportCity/scripts.pory"
	.string "like you.$"
# 1444 "data/maps/SlateportCity/scripts.pory"

# 1445 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExplainBerryPowder: @ 81DED27
# 1446 "data/maps/SlateportCity/scripts.pory"
	.string "I recently had machines installed at\n"
# 1447 "data/maps/SlateportCity/scripts.pory"
	.string "Pokémon Centers for crushing Berries.\p"
# 1448 "data/maps/SlateportCity/scripts.pory"
	.string "The Berry Crush machines are at\n"
# 1449 "data/maps/SlateportCity/scripts.pory"
	.string "the Direct Corner upstairs.\p"
# 1450 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know?\p"
# 1451 "data/maps/SlateportCity/scripts.pory"
	.string "Could you make Berry Powder for\n"
# 1452 "data/maps/SlateportCity/scripts.pory"
	.string "me using those machines?\p"
# 1453 "data/maps/SlateportCity/scripts.pory"
	.string "I can make you all sorts of medicine\n"
# 1454 "data/maps/SlateportCity/scripts.pory"
	.string "if you bring me lots of Berry Powder.$"
# 1455 "data/maps/SlateportCity/scripts.pory"

# 1456 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BroughtMeSomeBerryPowder: @ 81DEE40
# 1457 "data/maps/SlateportCity/scripts.pory"
	.string "Have you brought me some\n"
# 1458 "data/maps/SlateportCity/scripts.pory"
	.string "Berry Powder?$"
# 1459 "data/maps/SlateportCity/scripts.pory"

# 1460 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExchangeWhatWithIt: @ 81DEE67
# 1461 "data/maps/SlateportCity/scripts.pory"
	.string "What would you like to exchange\n"
# 1462 "data/maps/SlateportCity/scripts.pory"
	.string "it with?$"
# 1463 "data/maps/SlateportCity/scripts.pory"

# 1464 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExchangeBerryPowderForItem: @ 81DEE90
# 1465 "data/maps/SlateportCity/scripts.pory"
	.string "Okay, you want to exchange your\n"
# 1466 "data/maps/SlateportCity/scripts.pory"
	.string "Berry Powder for one {STR_VAR_1}?$"
# 1467 "data/maps/SlateportCity/scripts.pory"

# 1468 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_DontHaveEnoughBerryPowder: @ 81DEEC9
# 1469 "data/maps/SlateportCity/scripts.pory"
	.string "Oh, dear. You don't have enough\n"
# 1470 "data/maps/SlateportCity/scripts.pory"
	.string "Berry Powder.$"
# 1471 "data/maps/SlateportCity/scripts.pory"

# 1472 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_FineBerryPowderTradeSomethingElse: @ 81DEEF7
# 1473 "data/maps/SlateportCity/scripts.pory"
	.string "This is fine Berry Powder.\n"
# 1474 "data/maps/SlateportCity/scripts.pory"
	.string "It will make excellent medicine.\p"
# 1475 "data/maps/SlateportCity/scripts.pory"
	.string "Would you like to trade more of your\n"
# 1476 "data/maps/SlateportCity/scripts.pory"
	.string "Berry Powder for something else?$"
# 1477 "data/maps/SlateportCity/scripts.pory"

# 1478 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhenYouGetMoreBringItToMe: @ 81DEF79
# 1479 "data/maps/SlateportCity/scripts.pory"
	.string "Okay! When you get some more\n"
# 1480 "data/maps/SlateportCity/scripts.pory"
	.string "Berry Powder, bring it to me, please!$"
# 1481 "data/maps/SlateportCity/scripts.pory"

# 1482 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ComeBackToTradeBerryPowder: @ 81DEFBC
# 1483 "data/maps/SlateportCity/scripts.pory"
	.string "Come back if you'd like to trade your\n"
# 1484 "data/maps/SlateportCity/scripts.pory"
	.string "Berry Powder for some medicine.\p"
# 1485 "data/maps/SlateportCity/scripts.pory"
	.string "I'm always running a bazaar here.\p"
# 1486 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know?$"
# 1487 "data/maps/SlateportCity/scripts.pory"

# 1488 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_YouDroveTeamAquaAway: @ 81DF032
# 1489 "data/maps/SlateportCity/scripts.pory"
	.string "Scott: Huh?\n"
# 1490 "data/maps/SlateportCity/scripts.pory"
	.string "I'm sure I met you somewhere before.\p"
# 1491 "data/maps/SlateportCity/scripts.pory"
	.string "Have I introduced myself to you?\n"
# 1492 "data/maps/SlateportCity/scripts.pory"
	.string "If not, my name's SCOTT.\p"
# 1493 "data/maps/SlateportCity/scripts.pory"
	.string "I just saw Team Aqua run away from\n"
# 1494 "data/maps/SlateportCity/scripts.pory"
	.string "here like they were stung.\p"
# 1495 "data/maps/SlateportCity/scripts.pory"
	.string "Let me guess--you drove them away?$"
# 1496 "data/maps/SlateportCity/scripts.pory"

# 1497 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_MaybeThisTrainer: @ 81DF0FE
# 1498 "data/maps/SlateportCity/scripts.pory"
	.string "Scott: Hmm…\n"
# 1499 "data/maps/SlateportCity/scripts.pory"
	.string "Maybe, just maybe, this Trainer…$"
# 1500 "data/maps/SlateportCity/scripts.pory"

# 1501 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_LetsRegisterEachOther: @ 81DF12B
# 1502 "data/maps/SlateportCity/scripts.pory"
	.string "Scott: All right! I think you're going\n"
# 1503 "data/maps/SlateportCity/scripts.pory"
	.string "to become a good friend.\p"
# 1504 "data/maps/SlateportCity/scripts.pory"
	.string "So, let's register each other in our\n"
# 1505 "data/maps/SlateportCity/scripts.pory"
	.string "PokéNavs.\p"
# 1506 "data/maps/SlateportCity/scripts.pory"
	.string "… … … … … …$"
# 1507 "data/maps/SlateportCity/scripts.pory"

# 1508 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_RegisteredScott: @ 81DF1A6
# 1509 "data/maps/SlateportCity/scripts.pory"
	.string "Registered this Scott person\n"
# 1510 "data/maps/SlateportCity/scripts.pory"
	.string "in the PokéNav.$"
# 1511 "data/maps/SlateportCity/scripts.pory"

# 1512 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou: @ 81DF1D3
# 1513 "data/maps/SlateportCity/scripts.pory"
	.string "Scott: What I'd like to do is tag along\n"
# 1514 "data/maps/SlateportCity/scripts.pory"
	.string "with you, but I do want to keep an eye\l"
# 1515 "data/maps/SlateportCity/scripts.pory"
	.string "on the talents of other people, too.\p"
# 1516 "data/maps/SlateportCity/scripts.pory"
	.string "So, I'll be off to roam other towns\n"
# 1517 "data/maps/SlateportCity/scripts.pory"
	.string "a bit more.\p"
# 1518 "data/maps/SlateportCity/scripts.pory"
	.string "Be seeing you, {PLAYER}{KUN}!$"
# 1519 "data/maps/SlateportCity/scripts.pory"

# 1520 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_TakingBattleTentChallenge: @ 81DF28C
# 1521 "data/maps/SlateportCity/scripts.pory"
	.string "Scott: Oh, hey!\n"
# 1522 "data/maps/SlateportCity/scripts.pory"
	.string "If it isn't {PLAYER}{KUN}!\p"
# 1523 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER}{KUN}, let me guess--you're going\n"
# 1524 "data/maps/SlateportCity/scripts.pory"
	.string "to take the Battle Tent challenge?\p"
# 1525 "data/maps/SlateportCity/scripts.pory"
	.string "Yeah! That's a good idea!\n"
# 1526 "data/maps/SlateportCity/scripts.pory"
	.string "That's a really great idea!\p"
# 1527 "data/maps/SlateportCity/scripts.pory"
	.string "After all, a tough Trainer is\n"
# 1528 "data/maps/SlateportCity/scripts.pory"
	.string "the perfect fit for the Battle Tent!\p"
# 1529 "data/maps/SlateportCity/scripts.pory"
	.string "Give it your best effort!$"
# 1530 "data/maps/SlateportCity/scripts.pory"

# 1531 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GretaHowdy:
# 1532 "data/maps/SlateportCity/scripts.pory"
	.string "Hey! Howdy! Up for a battle, Trainer?$"
# 1533 "data/maps/SlateportCity/scripts.pory"

# 1534 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GretaReadyForBattle:
# 1535 "data/maps/SlateportCity/scripts.pory"
	.string "Hmm… yeah, you look like you're up\n"
# 1536 "data/maps/SlateportCity/scripts.pory"
	.string "for this. Is your team ready to go?$"
# 1537 "data/maps/SlateportCity/scripts.pory"

# 1538 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GretaMaybeNot:
# 1539 "data/maps/SlateportCity/scripts.pory"
	.string "Hmm… no, maybe not. To be blunt, you\n"
# 1540 "data/maps/SlateportCity/scripts.pory"
	.string "look pretty weak.\p"
# 1541 "data/maps/SlateportCity/scripts.pory"
	.string "Come see me again once you've trained\n"
# 1542 "data/maps/SlateportCity/scripts.pory"
	.string "up a bit more. Or a lot more!$"
# 1543 "data/maps/SlateportCity/scripts.pory"

# 1544 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GretaLetsBattle:
# 1545 "data/maps/SlateportCity/scripts.pory"
	.string "Great! Be ready for a thrashing!$"
# 1546 "data/maps/SlateportCity/scripts.pory"

# 1547 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GretaRefused:
# 1548 "data/maps/SlateportCity/scripts.pory"
	.string "Huh? Really? Shouldn't you always be\n"
# 1549 "data/maps/SlateportCity/scripts.pory"
	.string "ready for a battle?$"
# 1550 "data/maps/SlateportCity/scripts.pory"

# 1551 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GretaDefeat:
# 1552 "data/maps/SlateportCity/scripts.pory"
	.string "No way! You're tough after all!$"
# 1553 "data/maps/SlateportCity/scripts.pory"

# 1554 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GretaHereHaveStuff:
# 1555 "data/maps/SlateportCity/scripts.pory"
	.string "Hey, not bad! {PLAYER}, was it?\n"
# 1556 "data/maps/SlateportCity/scripts.pory"
	.string "I'll remember that.\p"
# 1557 "data/maps/SlateportCity/scripts.pory"
	.string "Here, take my Pokémon!$"
# 1558 "data/maps/SlateportCity/scripts.pory"

# 1559 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GretaDefeated:
# 1560 "data/maps/SlateportCity/scripts.pory"
	.string "Next time we battle will be a lot more\n"
# 1561 "data/maps/SlateportCity/scripts.pory"
	.string "fun, but I won't lose again!\p"
# 1562 "data/maps/SlateportCity/scripts.pory"
	.string "You'd better do some serious training;\n"
# 1563 "data/maps/SlateportCity/scripts.pory"
	.string "no halfhearted rematch allowed!$"

SlateportCity_Text_Got_Gengar::
# 1565 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Gengar{COLOR DARK_GRAY} as a gift!$"
