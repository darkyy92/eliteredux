# 1 "data/maps/Route103/scripts.pory"

# 2 "data/maps/Route103/scripts.pory"
.set LOCALID_RIVAL, 2
# 3 "data/maps/Route103/scripts.pory"

# 4 "data/maps/Route103/scripts.pory"
Route103_MapScripts:: @ 81EC38E
# 5 "data/maps/Route103/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
# 6 "data/maps/Route103/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
# 7 "data/maps/Route103/scripts.pory"
	.byte 0
# 8 "data/maps/Route103/scripts.pory"

# 9 "data/maps/Route103/scripts.pory"
Route103_OnTransition: @ 81EC399
# 10 "data/maps/Route103/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 11 "data/maps/Route103/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 12 "data/maps/Route103/scripts.pory"
	end
# 13 "data/maps/Route103/scripts.pory"

# 14 "data/maps/Route103/scripts.pory"
Route103_OnLoad: @ 81EC3A4
# 15 "data/maps/Route103/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
# 16 "data/maps/Route103/scripts.pory"
	end
# 17 "data/maps/Route103/scripts.pory"

# 18 "data/maps/Route103/scripts.pory"
Route103_EventScript_OpenAlteringCave:: @ 81EC3AE
# 19 "data/maps/Route103/scripts.pory"
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, 1
# 20 "data/maps/Route103/scripts.pory"
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, 0
# 21 "data/maps/Route103/scripts.pory"
	return
# 22 "data/maps/Route103/scripts.pory"

# 23 "data/maps/Route103/scripts.pory"
Route103_EventScript_Rival:: @ 81EC3C1
# 24 "data/maps/Route103/scripts.pory"
	lockall
# 25 "data/maps/Route103/scripts.pory"
	checkplayergender
# 26 "data/maps/Route103/scripts.pory"
	compare VAR_RESULT, MALE
# 27 "data/maps/Route103/scripts.pory"
	goto_if_eq Route103_EventScript_RivalMay
# 28 "data/maps/Route103/scripts.pory"
	compare VAR_RESULT, FEMALE
# 29 "data/maps/Route103/scripts.pory"
	goto_if_eq Route103_EventScript_RivalBrendan
# 30 "data/maps/Route103/scripts.pory"
	end
# 31 "data/maps/Route103/scripts.pory"

# 32 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalMay:: @ 81EC3DA
# 33 "data/maps/Route103/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_RivalMayRematch
# 34 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
# 35 "data/maps/Route103/scripts.pory"
	closemessage
# 36 "data/maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 37 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 38 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 39 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 40 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 41 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 42 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 43 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
# 44 "data/maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 45 "data/maps/Route103/scripts.pory"
	case 0, Route103_EventScript_StartMayBattleTreecko
# 46 "data/maps/Route103/scripts.pory"
	case 1, Route103_EventScript_StartMayBattleTorchic
# 47 "data/maps/Route103/scripts.pory"
	case 2, Route103_EventScript_StartMayBattleMudkip
# 48 "data/maps/Route103/scripts.pory"
	end
# 49 "data/maps/Route103/scripts.pory"

# 50 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalBrendan:: @ 81EC434
# 51 "data/maps/Route103/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_RivalBrendanRematch
# 52 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
# 53 "data/maps/Route103/scripts.pory"
	closemessage
# 54 "data/maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 55 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 56 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 57 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 58 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 59 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 60 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 61 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
# 62 "data/maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 63 "data/maps/Route103/scripts.pory"
	case 0, Route103_EventScript_StartBrendanBattleTreecko
# 64 "data/maps/Route103/scripts.pory"
	case 1, Route103_EventScript_StartBrendanBattleTorchic
# 65 "data/maps/Route103/scripts.pory"
	case 2, Route103_EventScript_StartBrendanBattleMudkip
# 66 "data/maps/Route103/scripts.pory"
	end
# 67 "data/maps/Route103/scripts.pory"

# 68 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalMayRematch::
# 69 "data/maps/Route103/scripts.pory"
	goto_if_set FLAG_DAILY_REMATCH_RIVAL, Route103_EventScript_AfterMayRematch
# 70 "data/maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, 1
# 71 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 72 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 73 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 74 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 75 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 76 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 77 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayRematch, MSGBOX_DEFAULT
# 78 "data/maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 79 "data/maps/Route103/scripts.pory"
	case 0, Route103_EventScript_StartMayRematchTreecko
# 80 "data/maps/Route103/scripts.pory"
	case 1, Route103_EventScript_StartMayRematchTorchic
# 81 "data/maps/Route103/scripts.pory"
	case 2, Route103_EventScript_StartMayRematchMudkip
# 82 "data/maps/Route103/scripts.pory"
	end
# 83 "data/maps/Route103/scripts.pory"

# 84 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalBrendanRematch:: @ 81EC434
# 85 "data/maps/Route103/scripts.pory"
	goto_if_set FLAG_DAILY_REMATCH_RIVAL, Route103_EventScript_AfterBrendanRematch
# 86 "data/maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, 1
# 87 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 88 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 89 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 90 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 91 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 92 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 93 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanRematch, MSGBOX_DEFAULT
# 94 "data/maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 95 "data/maps/Route103/scripts.pory"
	case 0, Route103_EventScript_StartBrendanRematchTreecko
# 96 "data/maps/Route103/scripts.pory"
	case 1, Route103_EventScript_StartBrendanRematchTorchic
# 97 "data/maps/Route103/scripts.pory"
	case 2, Route103_EventScript_StartBrendanRematchMudkip
# 98 "data/maps/Route103/scripts.pory"
	end
# 99 "data/maps/Route103/scripts.pory"

# 100 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleTreecko:: @ 81EC48E
# 101 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
# 102 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 103 "data/maps/Route103/scripts.pory"
	end
# 104 "data/maps/Route103/scripts.pory"

# 105 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleTorchic:: @ 81EC49E
# 106 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
# 107 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 108 "data/maps/Route103/scripts.pory"
	end
# 109 "data/maps/Route103/scripts.pory"

# 110 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleMudkip:: @ 81EC4AE
# 111 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
# 112 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 113 "data/maps/Route103/scripts.pory"
	end
# 114 "data/maps/Route103/scripts.pory"

# 115 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleTreecko:: @ 81EC4BE
# 116 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
# 117 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 118 "data/maps/Route103/scripts.pory"
	end
# 119 "data/maps/Route103/scripts.pory"

# 120 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleTorchic:: @ 81EC4CE
# 121 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
# 122 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 123 "data/maps/Route103/scripts.pory"
	end
# 124 "data/maps/Route103/scripts.pory"

# 125 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleMudkip:: @ 81EC4DE
# 126 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
# 127 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 128 "data/maps/Route103/scripts.pory"
	end
# 129 "data/maps/Route103/scripts.pory"

# 130 "data/maps/Route103/scripts.pory"
@@@@@@@@@@@@@@@@@@@@@@@@ Rematch teams @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
# 131 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayRematchTreecko:: @ 81EC48E
# 132 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, Route103_Text_MayRematchDefeated
# 133 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayRematch
# 134 "data/maps/Route103/scripts.pory"
	end
# 135 "data/maps/Route103/scripts.pory"

# 136 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayRematchTorchic:: @ 81EC49E
# 137 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, Route103_Text_MayRematchDefeated
# 138 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayRematch
# 139 "data/maps/Route103/scripts.pory"
	end
# 140 "data/maps/Route103/scripts.pory"

# 141 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayRematchMudkip:: @ 81EC4AE
# 142 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, Route103_Text_MayRematchDefeated
# 143 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayRematch
# 144 "data/maps/Route103/scripts.pory"
	end
# 145 "data/maps/Route103/scripts.pory"

# 146 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanRematchTreecko:: @ 81EC4BE
# 147 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, Route103_Text_BrendanRematchDefeated
# 148 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanRematch
# 149 "data/maps/Route103/scripts.pory"
	end
# 150 "data/maps/Route103/scripts.pory"

# 151 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanRematchTorchic:: @ 81EC4CE
# 152 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, Route103_Text_BrendanRematchDefeated
# 153 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanRematch
# 154 "data/maps/Route103/scripts.pory"
	end
# 155 "data/maps/Route103/scripts.pory"

# 156 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanRematchMudkip:: @ 81EC4DE
# 157 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, Route103_Text_BrendanRematchDefeated
# 158 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanRematch
# 159 "data/maps/Route103/scripts.pory"
	end
# 160 "data/maps/Route103/scripts.pory"

# 161 "data/maps/Route103/scripts.pory"
Route103_EventScript_AfterMayBattle:: @ 81EC4EE
# 162 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
# 163 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 164 "data/maps/Route103/scripts.pory"
	end
# 165 "data/maps/Route103/scripts.pory"

# 166 "data/maps/Route103/scripts.pory"
Route103_EventScript_AfterBrendanBattle:: @ 81EC4FC
# 167 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
# 168 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 169 "data/maps/Route103/scripts.pory"
	end
# 170 "data/maps/Route103/scripts.pory"

# 171 "data/maps/Route103/scripts.pory"
Route103_EventScript_AfterMayRematch:: @ 81EC4EE
# 172 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayPostRematch, MSGBOX_DEFAULT
# 173 "data/maps/Route103/scripts.pory"
	setflag FLAG_DAILY_REMATCH_RIVAL
# 174 "data/maps/Route103/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, Route103_EventScript_MayGiveEonTicket
# 175 "data/maps/Route103/scripts.pory"
	releaseall
# 176 "data/maps/Route103/scripts.pory"
	end
# 177 "data/maps/Route103/scripts.pory"

# 178 "data/maps/Route103/scripts.pory"
Route103_EventScript_AfterBrendanRematch:: @ 81EC4FC
# 179 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanPostRematch, MSGBOX_DEFAULT
# 180 "data/maps/Route103/scripts.pory"
	setflag FLAG_DAILY_REMATCH_RIVAL
# 181 "data/maps/Route103/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, Route103_EventScript_BrendanGiveEonTicket
# 182 "data/maps/Route103/scripts.pory"
	releaseall
# 183 "data/maps/Route103/scripts.pory"
	end
# 184 "data/maps/Route103/scripts.pory"

# 185 "data/maps/Route103/scripts.pory"
Route103_EventScript_BrendanGiveEonTicket::
# 186 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanGiveEonTicket, MSGBOX_DEFAULT
# 187 "data/maps/Route103/scripts.pory"
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
# 188 "data/maps/Route103/scripts.pory"
	giveitem ITEM_EON_TICKET
# 189 "data/maps/Route103/scripts.pory"
	savebgm MUS_DUMMY
# 190 "data/maps/Route103/scripts.pory"
	fadedefaultbgm
# 191 "data/maps/Route103/scripts.pory"
	releaseall
# 192 "data/maps/Route103/scripts.pory"
	end
# 193 "data/maps/Route103/scripts.pory"

# 194 "data/maps/Route103/scripts.pory"
Route103_EventScript_MayGiveEonTicket::
# 195 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayGiveEonTicket, MSGBOX_DEFAULT
# 196 "data/maps/Route103/scripts.pory"
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
# 197 "data/maps/Route103/scripts.pory"
	giveitem ITEM_EON_TICKET
# 198 "data/maps/Route103/scripts.pory"
	savebgm MUS_DUMMY
# 199 "data/maps/Route103/scripts.pory"
	fadedefaultbgm
# 200 "data/maps/Route103/scripts.pory"
	releaseall
# 201 "data/maps/Route103/scripts.pory"
	end
# 202 "data/maps/Route103/scripts.pory"

# 203 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExit:: @ 81EC50A
# 204 "data/maps/Route103/scripts.pory"
	closemessage
# 205 "data/maps/Route103/scripts.pory"
	switch VAR_FACING
# 206 "data/maps/Route103/scripts.pory"
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
# 207 "data/maps/Route103/scripts.pory"
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
# 208 "data/maps/Route103/scripts.pory"
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
# 209 "data/maps/Route103/scripts.pory"
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
# 210 "data/maps/Route103/scripts.pory"
	end
# 211 "data/maps/Route103/scripts.pory"

# 212 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingNorth:: @ 81EC53D
# 213 "data/maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
# 214 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth1
# 215 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 216 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 217 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_EventScript_RivalExitFacingNorth2
# 218 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 219 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 220 "data/maps/Route103/scripts.pory"
	end
# 221 "data/maps/Route103/scripts.pory"

# 222 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingEastOrWest:: @ 81EC561
# 223 "data/maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
# 224 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 225 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 226 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 227 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 228 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 229 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 230 "data/maps/Route103/scripts.pory"
	end
# 231 "data/maps/Route103/scripts.pory"

# 232 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingSouth:: @ 81EC585
# 233 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 234 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 235 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 236 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 237 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 238 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 239 "data/maps/Route103/scripts.pory"
	end
# 240 "data/maps/Route103/scripts.pory"

# 241 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalEnd:: @ 81EC5A2
# 242 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_RIVAL
# 243 "data/maps/Route103/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 4
# 244 "data/maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 245 "data/maps/Route103/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
# 246 "data/maps/Route103/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 1
# 247 "data/maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 248 "data/maps/Route103/scripts.pory"
	savebgm MUS_DUMMY
# 249 "data/maps/Route103/scripts.pory"
	fadedefaultbgm
# 250 "data/maps/Route103/scripts.pory"
	releaseall
# 251 "data/maps/Route103/scripts.pory"
	end
# 252 "data/maps/Route103/scripts.pory"

# 253 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth1: @ 81EC5BE
# 254 "data/maps/Route103/scripts.pory"
	walk_left
# 255 "data/maps/Route103/scripts.pory"
	walk_down
# 256 "data/maps/Route103/scripts.pory"
	step_end
# 257 "data/maps/Route103/scripts.pory"

# 258 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingNorth2: @ 81EC5C1
# 259 "data/maps/Route103/scripts.pory"
	jump_2_down
# 260 "data/maps/Route103/scripts.pory"
	delay_16
# 261 "data/maps/Route103/scripts.pory"
	walk_down
# 262 "data/maps/Route103/scripts.pory"
	walk_down
# 263 "data/maps/Route103/scripts.pory"
	walk_down
# 264 "data/maps/Route103/scripts.pory"
	walk_down
# 265 "data/maps/Route103/scripts.pory"
	step_end
# 266 "data/maps/Route103/scripts.pory"

# 267 "data/maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingNorth: @ 81EC5C8
# 268 "data/maps/Route103/scripts.pory"
	delay_16
# 269 "data/maps/Route103/scripts.pory"
	delay_4
# 270 "data/maps/Route103/scripts.pory"
	walk_in_place_fastest_left
# 271 "data/maps/Route103/scripts.pory"
	delay_16
# 272 "data/maps/Route103/scripts.pory"
	walk_in_place_fastest_down
# 273 "data/maps/Route103/scripts.pory"
	step_end
# 274 "data/maps/Route103/scripts.pory"

# 275 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExit1: @ 81EC5CE
# 276 "data/maps/Route103/scripts.pory"
	walk_down
# 277 "data/maps/Route103/scripts.pory"
	step_end
# 278 "data/maps/Route103/scripts.pory"

# 279 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExit2: @ 81EC5D0
# 280 "data/maps/Route103/scripts.pory"
	jump_2_down
# 281 "data/maps/Route103/scripts.pory"
	delay_16
# 282 "data/maps/Route103/scripts.pory"
	walk_down
# 283 "data/maps/Route103/scripts.pory"
	walk_down
# 284 "data/maps/Route103/scripts.pory"
	walk_down
# 285 "data/maps/Route103/scripts.pory"
	step_end
# 286 "data/maps/Route103/scripts.pory"

# 287 "data/maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingEastOrWest: @ 81EC5D6
# 288 "data/maps/Route103/scripts.pory"
	delay_16
# 289 "data/maps/Route103/scripts.pory"
	walk_in_place_fastest_down
# 290 "data/maps/Route103/scripts.pory"
	step_end
# 291 "data/maps/Route103/scripts.pory"

# 292 "data/maps/Route103/scripts.pory"
Route103_EventScript_Boy:: @ 81EC5D9
# 293 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
# 294 "data/maps/Route103/scripts.pory"
	end
# 295 "data/maps/Route103/scripts.pory"

# 296 "data/maps/Route103/scripts.pory"
Route103_EventScript_Man:: @ 81EC5E2
# 297 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
# 298 "data/maps/Route103/scripts.pory"
	end
# 299 "data/maps/Route103/scripts.pory"

# 300 "data/maps/Route103/scripts.pory"
Route103_EventScript_RouteSign:: @ 81EC5EB
# 301 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
# 302 "data/maps/Route103/scripts.pory"
	end
# 303 "data/maps/Route103/scripts.pory"

# 304 "data/maps/Route103/scripts.pory"
Route103_EventScript_Daisy:: @ 81EC5F4
# 305 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
# 306 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
# 307 "data/maps/Route103/scripts.pory"
	end
# 308 "data/maps/Route103/scripts.pory"

# 309 "data/maps/Route103/scripts.pory"
Route103_EventScript_Amy:: @ 81EC60B
# 310 "data/maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
# 311 "data/maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 312 "data/maps/Route103/scripts.pory"
	compare VAR_RESULT, TRUE
# 313 "data/maps/Route103/scripts.pory"
	goto_if_eq Route102_EventScript_AmyRematch
# 314 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
# 315 "data/maps/Route103/scripts.pory"
	end
# 316 "data/maps/Route103/scripts.pory"

# 317 "data/maps/Route103/scripts.pory"
Route102_EventScript_AmyRegisterMatchCallAfterBattle:: @ 81EC63A
# 318 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 319 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 320 "data/maps/Route103/scripts.pory"
	release
# 321 "data/maps/Route103/scripts.pory"
	end
# 322 "data/maps/Route103/scripts.pory"

# 323 "data/maps/Route103/scripts.pory"
Route102_EventScript_AmyRematch:: @ 81EC653
# 324 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
# 325 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
# 326 "data/maps/Route103/scripts.pory"
	end
# 327 "data/maps/Route103/scripts.pory"

# 328 "data/maps/Route103/scripts.pory"
Route103_EventScript_Liv:: @ 81EC66E
# 329 "data/maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
# 330 "data/maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 331 "data/maps/Route103/scripts.pory"
	compare VAR_RESULT, TRUE
# 332 "data/maps/Route103/scripts.pory"
	goto_if_eq Route102_EventScript_LivRematch
# 333 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
# 334 "data/maps/Route103/scripts.pory"
	end
# 335 "data/maps/Route103/scripts.pory"

# 336 "data/maps/Route103/scripts.pory"
Route102_EventScript_LivRegisterMatchCallAfterBattle:: @ 81EC69D
# 337 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 338 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 339 "data/maps/Route103/scripts.pory"
	release
# 340 "data/maps/Route103/scripts.pory"
	end
# 341 "data/maps/Route103/scripts.pory"

# 342 "data/maps/Route103/scripts.pory"
Route102_EventScript_LivRematch:: @ 81EC6B6
# 343 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
# 344 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
# 345 "data/maps/Route103/scripts.pory"
	end
# 346 "data/maps/Route103/scripts.pory"

# 347 "data/maps/Route103/scripts.pory"
Route103_EventScript_Andrew:: @ 81EC6D1
# 348 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
# 349 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
# 350 "data/maps/Route103/scripts.pory"
	end
# 351 "data/maps/Route103/scripts.pory"

# 352 "data/maps/Route103/scripts.pory"
Route103_EventScript_Miguel:: @ 81EC6E8
# 353 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
# 354 "data/maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 355 "data/maps/Route103/scripts.pory"
	compare VAR_RESULT, TRUE
# 356 "data/maps/Route103/scripts.pory"
	goto_if_eq Route103_EventScript_MiguelRematch
# 357 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
# 358 "data/maps/Route103/scripts.pory"
	release
# 359 "data/maps/Route103/scripts.pory"
	end
# 360 "data/maps/Route103/scripts.pory"

# 361 "data/maps/Route103/scripts.pory"
Route102_EventScript_MiguelRegisterMatchCallAfterBattle:: @ 81EC714
# 362 "data/maps/Route103/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 363 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 364 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
# 365 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_MIGUEL_1
# 366 "data/maps/Route103/scripts.pory"
	release
# 367 "data/maps/Route103/scripts.pory"
	end
# 368 "data/maps/Route103/scripts.pory"

# 369 "data/maps/Route103/scripts.pory"
Route103_EventScript_MiguelRematch:: @ 81EC733
# 370 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
# 371 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
# 372 "data/maps/Route103/scripts.pory"
	end
# 373 "data/maps/Route103/scripts.pory"

# 374 "data/maps/Route103/scripts.pory"
Route103_EventScript_Marcos:: @ 81EC74A
# 375 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
# 376 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
# 377 "data/maps/Route103/scripts.pory"
	end
# 378 "data/maps/Route103/scripts.pory"

# 379 "data/maps/Route103/scripts.pory"
Route103_EventScript_Rhett:: @ 81EC761
# 380 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
# 381 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
# 382 "data/maps/Route103/scripts.pory"
	end
# 383 "data/maps/Route103/scripts.pory"

# 384 "data/maps/Route103/scripts.pory"
Route103_EventScript_Pete:: @ 81EC778
# 385 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
# 386 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
# 387 "data/maps/Route103/scripts.pory"
	end
# 388 "data/maps/Route103/scripts.pory"

# 389 "data/maps/Route103/scripts.pory"
Route103_EventScript_Isabelle:: @ 81EC78F
# 390 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
# 391 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
# 392 "data/maps/Route103/scripts.pory"
	end
# 393 "data/maps/Route103/scripts.pory"

# 394 "data/maps/Route103/scripts.pory"
Route103_Text_MayRoute103Pokemon: @ 81EC7A6
# 395 "data/maps/Route103/scripts.pory"
	.string "May: Let's see… The Pokémon found\n"
# 396 "data/maps/Route103/scripts.pory"
	.string "on Route 103 include…$"
# 397 "data/maps/Route103/scripts.pory"

# 398 "data/maps/Route103/scripts.pory"
Route103_Text_MayLetsBattle: @ 81EC7DE
# 399 "data/maps/Route103/scripts.pory"
	.string "Oh, hi, {PLAYER}{KUN}!\p"
# 400 "data/maps/Route103/scripts.pory"
	.string "…Oh, I see, my dad gave you\n"
# 401 "data/maps/Route103/scripts.pory"
	.string "a Pokémon as a gift.\p"
# 402 "data/maps/Route103/scripts.pory"
	.string "Since we're here, let's have a quick\n"
# 403 "data/maps/Route103/scripts.pory"
	.string "battle!\p"
# 404 "data/maps/Route103/scripts.pory"
	.string "I'll give you a taste of what being\n"
# 405 "data/maps/Route103/scripts.pory"
	.string "a Trainer is like.$"
# 406 "data/maps/Route103/scripts.pory"

# 407 "data/maps/Route103/scripts.pory"
Route103_Text_MayDefeated: @ 81EC881
# 408 "data/maps/Route103/scripts.pory"
	.string "Wow! That's great!\n"
# 409 "data/maps/Route103/scripts.pory"
	.string "{PLAYER}{KUN}, you're pretty good!$"
# 410 "data/maps/Route103/scripts.pory"

# 411 "data/maps/Route103/scripts.pory"
Route103_Text_MayTimeToHeadBack: @ 81EC8AE
# 412 "data/maps/Route103/scripts.pory"
	.string "May: I think I know why my dad has\n"
# 413 "data/maps/Route103/scripts.pory"
	.string "an eye out for you now.\p"
# 414 "data/maps/Route103/scripts.pory"
	.string "I mean, you just got that Pokémon,\n"
# 415 "data/maps/Route103/scripts.pory"
	.string "but it already likes you.\p"
# 416 "data/maps/Route103/scripts.pory"
	.string "You might be able to befriend any\n"
# 417 "data/maps/Route103/scripts.pory"
	.string "kind of Pokémon easily.\p"
# 418 "data/maps/Route103/scripts.pory"
	.string "Well, it's time to head back to\n"
# 419 "data/maps/Route103/scripts.pory"
	.string "the Lab.$"
# 420 "data/maps/Route103/scripts.pory"

# 421 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanRoute103Pokemon: @ 81EC989
# 422 "data/maps/Route103/scripts.pory"
	.string "Brendan: Okay, so it's this one and\n"
# 423 "data/maps/Route103/scripts.pory"
	.string "that one that live on Route 103…$"
# 424 "data/maps/Route103/scripts.pory"

# 425 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanLetsBattle: @ 81EC9CE
# 426 "data/maps/Route103/scripts.pory"
	.string "Hey, it's {PLAYER}!\p"
# 427 "data/maps/Route103/scripts.pory"
	.string "…Oh, yeah, Dad gave you a Pokémon.\p"
# 428 "data/maps/Route103/scripts.pory"
	.string "Since we're here, how about a little\n"
# 429 "data/maps/Route103/scripts.pory"
	.string "battle?\p"
# 430 "data/maps/Route103/scripts.pory"
	.string "I'll teach you what being a Trainer's\n"
# 431 "data/maps/Route103/scripts.pory"
	.string "about!$"
# 432 "data/maps/Route103/scripts.pory"

# 433 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanDefeated: @ 81ECA59
# 434 "data/maps/Route103/scripts.pory"
	.string "Huh, {PLAYER}, you're not too shabby.$"
# 435 "data/maps/Route103/scripts.pory"

# 436 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanTimeToHeadBack: @ 81ECA79
# 437 "data/maps/Route103/scripts.pory"
	.string "Brendan: I think I get it.\n"
# 438 "data/maps/Route103/scripts.pory"
	.string "I think I know why my dad has his eye\l"
# 439 "data/maps/Route103/scripts.pory"
	.string "out for you now.\p"
# 440 "data/maps/Route103/scripts.pory"
	.string "Look, your Pokémon already likes you,\n"
# 441 "data/maps/Route103/scripts.pory"
	.string "even though you just got it.\p"
# 442 "data/maps/Route103/scripts.pory"
	.string "{PLAYER}, I get the feeling that you\n"
# 443 "data/maps/Route103/scripts.pory"
	.string "could befriend any Pokémon with ease.\p"
# 444 "data/maps/Route103/scripts.pory"
	.string "We should head back to the Lab.$"
# 445 "data/maps/Route103/scripts.pory"

# 446 "data/maps/Route103/scripts.pory"
Route103_Text_ShouldHaveBroughtPotion: @ 81ECB73
# 447 "data/maps/Route103/scripts.pory"
	.string "My Pokémon is staggeringly tired…\n"
# 448 "data/maps/Route103/scripts.pory"
	.string "I should have brought a Potion…$"
# 449 "data/maps/Route103/scripts.pory"

# 450 "data/maps/Route103/scripts.pory"
Route103_Text_ShortcutToOldale: @ 81ECBB5
# 451 "data/maps/Route103/scripts.pory"
	.string "If you cross the sea from here,\n"
# 452 "data/maps/Route103/scripts.pory"
	.string "it'll be a shortcut to Oldale Town.\p"
# 453 "data/maps/Route103/scripts.pory"
	.string "Fufufu, that's useful, isn't it?$"
# 454 "data/maps/Route103/scripts.pory"

# 455 "data/maps/Route103/scripts.pory"
Route103_Text_RouteSign: @ 81ECC1A
# 456 "data/maps/Route103/scripts.pory"
	.string "Route 103\n"
# 457 "data/maps/Route103/scripts.pory"
	.string "{DOWN_ARROW} Oldale Town$"
# 458 "data/maps/Route103/scripts.pory"

# 459 "data/maps/Route103/scripts.pory"
Route103_Text_MayRematch:
# 460 "data/maps/Route103/scripts.pory"
	.string "May: Here we are on Route 103 again!\n"
# 461 "data/maps/Route103/scripts.pory"
	.string "Wow, it's so nostalgic, you know?\p"
# 462 "data/maps/Route103/scripts.pory"
	.string "This is where we first battled,\n"
# 463 "data/maps/Route103/scripts.pory"
	.string "isn't it?\p"
# 464 "data/maps/Route103/scripts.pory"
	.string "… {PLAYER}!\n"
# 465 "data/maps/Route103/scripts.pory"
	.string "Could you do something for me?\p"
# 466 "data/maps/Route103/scripts.pory"
	.string "Come on!\n"
# 467 "data/maps/Route103/scripts.pory"
	.string "Let's battle one more time!\p"
# 468 "data/maps/Route103/scripts.pory"
	.string "I wanna know what you saw on\n"
# 469 "data/maps/Route103/scripts.pory"
	.string "your journey, how you felt,\l"
# 470 "data/maps/Route103/scripts.pory"
	.string "and what you experienced out there.\p"
# 471 "data/maps/Route103/scripts.pory"
	.string "I want to understand everything about\n"
# 472 "data/maps/Route103/scripts.pory"
	.string "you and your Pokémon, {PLAYER}!\p"
# 473 "data/maps/Route103/scripts.pory"
	.string "And then…\p"
# 474 "data/maps/Route103/scripts.pory"
	.string "I want you to understand everything\l"
# 475 "data/maps/Route103/scripts.pory"
	.string "about me and mine!$"
# 476 "data/maps/Route103/scripts.pory"

# 477 "data/maps/Route103/scripts.pory"
Route103_Text_MayRematchDefeated:
# 478 "data/maps/Route103/scripts.pory"
	.string "…\p"
# 479 "data/maps/Route103/scripts.pory"
	.string "Thanks, {PLAYER}!\n"
# 480 "data/maps/Route103/scripts.pory"
	.string "You really are a Champion!$"
# 481 "data/maps/Route103/scripts.pory"

# 482 "data/maps/Route103/scripts.pory"
Route103_Text_MayPostRematch:
# 483 "data/maps/Route103/scripts.pory"
	.string "May: Meeting so many different people…\n"
# 484 "data/maps/Route103/scripts.pory"
	.string "And encountering so many Pokémon…\p"
# 485 "data/maps/Route103/scripts.pory"
	.string "It's just really…\n"
# 486 "data/maps/Route103/scripts.pory"
	.string "It's been really, really fun!$"
# 487 "data/maps/Route103/scripts.pory"

# 488 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanRematch:
# 489 "data/maps/Route103/scripts.pory"
	.string "Brendan: Man, this is nostalgic.\n"
# 490 "data/maps/Route103/scripts.pory"
	.string "Back on Route 103, huh?\p"
# 491 "data/maps/Route103/scripts.pory"
	.string "This is where we battled the first\n"
# 492 "data/maps/Route103/scripts.pory"
	.string "time, huh?\p"
# 493 "data/maps/Route103/scripts.pory"
	.string "Hey, {PLAYER}…\n"
# 494 "data/maps/Route103/scripts.pory"
	.string "Do me a favor?\p"
# 495 "data/maps/Route103/scripts.pory"
	.string "Come on!\n"
# 496 "data/maps/Route103/scripts.pory"
	.string "Let's battle one more time!\p"
# 497 "data/maps/Route103/scripts.pory"
	.string "I wanna know about what you saw on\n"
# 498 "data/maps/Route103/scripts.pory"
	.string "your journey, how you felt,\l"
# 499 "data/maps/Route103/scripts.pory"
	.string "and what you experienced out there.\p"
# 500 "data/maps/Route103/scripts.pory"
	.string "I want to know all about you\n"
# 501 "data/maps/Route103/scripts.pory"
	.string "and your Pokémon, {PLAYER}.\p"
# 502 "data/maps/Route103/scripts.pory"
	.string "But that's not all…\p"
# 503 "data/maps/Route103/scripts.pory"
	.string "I want you to know all about\n"
# 504 "data/maps/Route103/scripts.pory"
	.string "me and mine!$"
# 505 "data/maps/Route103/scripts.pory"

# 506 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanRematchDefeated:
# 507 "data/maps/Route103/scripts.pory"
	.string "…\p"
# 508 "data/maps/Route103/scripts.pory"
	.string "Thanks, {PLAYER}!\n"
# 509 "data/maps/Route103/scripts.pory"
	.string "Just what I'd expect from a Champion!$"
# 510 "data/maps/Route103/scripts.pory"

# 511 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanPostRematch:
# 512 "data/maps/Route103/scripts.pory"
	.string "Brendan: Getting to meet so many\n"
# 513 "data/maps/Route103/scripts.pory"
	.string "different people…\p"
# 514 "data/maps/Route103/scripts.pory"
	.string "And so many different Pokémon…\p"
# 515 "data/maps/Route103/scripts.pory"
	.string "It's like… I don't know…\n"
# 516 "data/maps/Route103/scripts.pory"
	.string "It's been really, really fun!$"
# 517 "data/maps/Route103/scripts.pory"

# 518 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanGiveEonTicket:
# 519 "data/maps/Route103/scripts.pory"
	.string "Brendan: One more thing, {PLAYER}.\n"
# 520 "data/maps/Route103/scripts.pory"
	.string "Take this as thanks for a great battle!$"
# 521 "data/maps/Route103/scripts.pory"

# 522 "data/maps/Route103/scripts.pory"
Route103_Text_MayGiveEonTicket:
# 523 "data/maps/Route103/scripts.pory"
	.string "May: Oh, by the way, {PLAYER}.\n"
# 524 "data/maps/Route103/scripts.pory"
	.string "I've got something for you!\p"
# 525 "data/maps/Route103/scripts.pory"
	.string "Please take this Ticket!$"
