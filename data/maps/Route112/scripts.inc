# 1 "data/maps/Route112/scripts.pory"

# 2 "data/maps/Route112/scripts.pory"
.set LOCALID_GRUNT_1, 1
# 3 "data/maps/Route112/scripts.pory"
.set LOCALID_GRUNT_2, 6
# 4 "data/maps/Route112/scripts.pory"
.set LOCALID_CHANSEY, 14
# 5 "data/maps/Route112/scripts.pory"

# 6 "data/maps/Route112/scripts.pory"
Route112_MapScripts:: @ 81F1DA8
# 7 "data/maps/Route112/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_OnTransition
# 8 "data/maps/Route112/scripts.pory"
	.byte 0
# 9 "data/maps/Route112/scripts.pory"

# 10 "data/maps/Route112/scripts.pory"
Route112_OnTransition: @ 81F1DAE
# 11 "data/maps/Route112/scripts.pory"
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
# 12 "data/maps/Route112/scripts.pory"
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
# 13 "data/maps/Route112/scripts.pory"
	end
# 14 "data/maps/Route112/scripts.pory"

# 15 "data/maps/Route112/scripts.pory"
Route112_EventScript_MagmaGrunts:: @ 81F1DB7
# 16 "data/maps/Route112/scripts.pory"
	lockall
# 17 "data/maps/Route112/scripts.pory"
	delay 40
# 18 "data/maps/Route112/scripts.pory"
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFastestRight
# 19 "data/maps/Route112/scripts.pory"
	waitmovement 0
# 20 "data/maps/Route112/scripts.pory"
	delay 20
# 21 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_LeaderGoingToAwakenThing, MSGBOX_DEFAULT
# 22 "data/maps/Route112/scripts.pory"
	closemessage
# 23 "data/maps/Route112/scripts.pory"
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
# 24 "data/maps/Route112/scripts.pory"
	waitmovement 0
# 25 "data/maps/Route112/scripts.pory"
	delay 40
# 26 "data/maps/Route112/scripts.pory"
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFastestLeft
# 27 "data/maps/Route112/scripts.pory"
	waitmovement 0
# 28 "data/maps/Route112/scripts.pory"
	delay 20
# 29 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_YeahWeNeedMeteorite, MSGBOX_DEFAULT
# 30 "data/maps/Route112/scripts.pory"
	closemessage
# 31 "data/maps/Route112/scripts.pory"
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
# 32 "data/maps/Route112/scripts.pory"
	waitmovement 0
# 33 "data/maps/Route112/scripts.pory"
	delay 40
# 34 "data/maps/Route112/scripts.pory"
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFastestRight
# 35 "data/maps/Route112/scripts.pory"
	waitmovement 0
# 36 "data/maps/Route112/scripts.pory"
	delay 20
# 37 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_OhThatsWhyCrewWentToFallarbor, MSGBOX_DEFAULT
# 38 "data/maps/Route112/scripts.pory"
	closemessage
# 39 "data/maps/Route112/scripts.pory"
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
# 40 "data/maps/Route112/scripts.pory"
	waitmovement 0
# 41 "data/maps/Route112/scripts.pory"
	delay 40
# 42 "data/maps/Route112/scripts.pory"
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFastestLeft
# 43 "data/maps/Route112/scripts.pory"
	waitmovement 0
# 44 "data/maps/Route112/scripts.pory"
	delay 20
# 45 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_CantLetAnyonePassUntilTheyreBack, MSGBOX_DEFAULT
# 46 "data/maps/Route112/scripts.pory"
	closemessage
# 47 "data/maps/Route112/scripts.pory"
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
# 48 "data/maps/Route112/scripts.pory"
	waitmovement 0
# 49 "data/maps/Route112/scripts.pory"
	releaseall
# 50 "data/maps/Route112/scripts.pory"
	end
# 51 "data/maps/Route112/scripts.pory"

# 52 "data/maps/Route112/scripts.pory"
Route112_EventScript_ChanseyBlob::
# 53 "data/maps/Route112/scripts.pory"
	lockall
# 54 "data/maps/Route112/scripts.pory"
	applymovement LOCALID_CHANSEY, Route112_Movement_ChanseyJump
# 55 "data/maps/Route112/scripts.pory"
	waitmovement 0
# 56 "data/maps/Route112/scripts.pory"
	waitse
# 57 "data/maps/Route112/scripts.pory"
	playmoncry SPECIES_CHANSEY, 0
# 58 "data/maps/Route112/scripts.pory"
	delay 40
# 59 "data/maps/Route112/scripts.pory"
	waitmoncry
# 60 "data/maps/Route112/scripts.pory"
	applymovement LOCALID_CHANSEY, Route112_Movement_ChanseyEscape
# 61 "data/maps/Route112/scripts.pory"
	waitmovement 0
# 62 "data/maps/Route112/scripts.pory"
	setvar VAR_CHANSEY_NURSE_STATE, 2
# 63 "data/maps/Route112/scripts.pory"
	removeobject LOCALID_CHANSEY
# 64 "data/maps/Route112/scripts.pory"
	releaseall
# 65 "data/maps/Route112/scripts.pory"
	end
# 66 "data/maps/Route112/scripts.pory"

# 67 "data/maps/Route112/scripts.pory"
Route112_EventScript_MtChimneyCableCarSign:: @ 81F1E46
# 68 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_MtChimneyCableCarSign, MSGBOX_SIGN
# 69 "data/maps/Route112/scripts.pory"
	end
# 70 "data/maps/Route112/scripts.pory"

# 71 "data/maps/Route112/scripts.pory"
Route112_EventScript_MtChimneySign:: @ 81F1E4F
# 72 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_MtChimneySign, MSGBOX_SIGN
# 73 "data/maps/Route112/scripts.pory"
	end
# 74 "data/maps/Route112/scripts.pory"

# 75 "data/maps/Route112/scripts.pory"
Route112_EventScript_RouteSignLavaridge:: @ 81F1E58
# 76 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_RouteSignLavaridge, MSGBOX_SIGN
# 77 "data/maps/Route112/scripts.pory"
	end
# 78 "data/maps/Route112/scripts.pory"

# 79 "data/maps/Route112/scripts.pory"
Route112_EventScript_Hiker:: @ 81F1E61
# 80 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_NotEasyToGetBackToLavaridge, MSGBOX_NPC
# 81 "data/maps/Route112/scripts.pory"
	end
# 82 "data/maps/Route112/scripts.pory"

# 83 "data/maps/Route112/scripts.pory"
Route112_EventScript_Brice:: @ 81F1E6A
# 84 "data/maps/Route112/scripts.pory"
	trainerbattle_single TRAINER_BRICE, Route112_Text_BriceIntro, Route112_Text_BriceDefeat
# 85 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_BricePostBattle, MSGBOX_AUTOCLOSE
# 86 "data/maps/Route112/scripts.pory"
	end
# 87 "data/maps/Route112/scripts.pory"

# 88 "data/maps/Route112/scripts.pory"
Route112_EventScript_Trent:: @ 81F1E81
# 89 "data/maps/Route112/scripts.pory"
	trainerbattle_single TRAINER_TRENT_1, Route112_Text_TrentIntro, Route112_Text_TrentDefeat, Route112_EventScript_RegisterTrent
# 90 "data/maps/Route112/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 91 "data/maps/Route112/scripts.pory"
	compare VAR_RESULT, TRUE
# 92 "data/maps/Route112/scripts.pory"
	goto_if_eq Route112_EventScript_RematchTrent
# 93 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_TrentPostBattle, MSGBOX_DEFAULT
# 94 "data/maps/Route112/scripts.pory"
	release
# 95 "data/maps/Route112/scripts.pory"
	end
# 96 "data/maps/Route112/scripts.pory"

# 97 "data/maps/Route112/scripts.pory"
Route112_EventScript_RegisterTrent:: @ 81F1EAD
# 98 "data/maps/Route112/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 99 "data/maps/Route112/scripts.pory"
	waitmovement 0
# 100 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_TrentRegister, MSGBOX_DEFAULT
# 101 "data/maps/Route112/scripts.pory"
	register_matchcall TRAINER_TRENT_1
# 102 "data/maps/Route112/scripts.pory"
	release
# 103 "data/maps/Route112/scripts.pory"
	end
# 104 "data/maps/Route112/scripts.pory"

# 105 "data/maps/Route112/scripts.pory"
Route112_EventScript_RematchTrent:: @ 81F1ECC
# 106 "data/maps/Route112/scripts.pory"
	trainerbattle_rematch TRAINER_TRENT_1, Route112_Text_TrentRematchIntro, Route112_Text_TrentRematchDefeat
# 107 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_TrentRematchPostBattle, MSGBOX_AUTOCLOSE
# 108 "data/maps/Route112/scripts.pory"
	end
# 109 "data/maps/Route112/scripts.pory"

# 110 "data/maps/Route112/scripts.pory"
Route112_EventScript_Larry:: @ 81F1EE3
# 111 "data/maps/Route112/scripts.pory"
	trainerbattle_single TRAINER_LARRY, Route112_Text_LarryIntro, Route112_Text_LarryDefeat
# 112 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
# 113 "data/maps/Route112/scripts.pory"
	end
# 114 "data/maps/Route112/scripts.pory"

# 115 "data/maps/Route112/scripts.pory"
Route112_EventScript_Carol:: @ 81F1EFA
# 116 "data/maps/Route112/scripts.pory"
	trainerbattle_single TRAINER_CAROL, Route112_Text_CarolIntro, Route112_Text_CarolDefeat
# 117 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_CarolPostBattle, MSGBOX_AUTOCLOSE
# 118 "data/maps/Route112/scripts.pory"
	end
# 119 "data/maps/Route112/scripts.pory"

# 120 "data/maps/Route112/scripts.pory"
Route112_EventScript_Bryant:: @ 81F1F11
# 121 "data/maps/Route112/scripts.pory"
	trainerbattle_single TRAINER_BRYANT, Route112_Text_BryantIntro, Route112_Text_BryantDefeat
# 122 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_BryantPostBattle, MSGBOX_AUTOCLOSE
# 123 "data/maps/Route112/scripts.pory"
	end
# 124 "data/maps/Route112/scripts.pory"

# 125 "data/maps/Route112/scripts.pory"
Route112_EventScript_Shayla:: @ 81F1F28
# 126 "data/maps/Route112/scripts.pory"
	trainerbattle_single TRAINER_SHAYLA, Route112_Text_ShaylaIntro, Route112_Text_ShaylaDefeat
# 127 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_ShaylaPostBattle, MSGBOX_AUTOCLOSE
# 128 "data/maps/Route112/scripts.pory"
	end
# 129 "data/maps/Route112/scripts.pory"

# 130 "data/maps/Route112/scripts.pory"
Route112_Movement_ChanseyJump:
# 131 "data/maps/Route112/scripts.pory"
	jump_in_place_down
# 132 "data/maps/Route112/scripts.pory"
	delay_4
# 133 "data/maps/Route112/scripts.pory"
	jump_in_place_down
# 134 "data/maps/Route112/scripts.pory"
	step_end
# 135 "data/maps/Route112/scripts.pory"

# 136 "data/maps/Route112/scripts.pory"
Route112_Movement_ChanseyEscape:
# 137 "data/maps/Route112/scripts.pory"
	walk_right
# 138 "data/maps/Route112/scripts.pory"
	walk_right
# 139 "data/maps/Route112/scripts.pory"
	walk_right
# 140 "data/maps/Route112/scripts.pory"
	walk_up
# 141 "data/maps/Route112/scripts.pory"
	walk_up
# 142 "data/maps/Route112/scripts.pory"
	step_end
# 143 "data/maps/Route112/scripts.pory"

# 144 "data/maps/Route112/scripts.pory"
Route112_Text_LeaderGoingToAwakenThing: @ 81F1F3F
# 145 "data/maps/Route112/scripts.pory"
	.string "Hey, man, is our leader really going\n"
# 146 "data/maps/Route112/scripts.pory"
	.string "to awaken that thing?$"
# 147 "data/maps/Route112/scripts.pory"

# 148 "data/maps/Route112/scripts.pory"
Route112_Text_YeahWeNeedMeteorite: @ 81F1F7A
# 149 "data/maps/Route112/scripts.pory"
	.string "Sounds like it, yeah. But I heard\n"
# 150 "data/maps/Route112/scripts.pory"
	.string "we need a Meteorite to do it.$"
# 151 "data/maps/Route112/scripts.pory"

# 152 "data/maps/Route112/scripts.pory"
Route112_Text_OhThatsWhyCrewWentToFallarbor: @ 81F1FBA
# 153 "data/maps/Route112/scripts.pory"
	.string "Oh, I get it now. That's why the rest\n"
# 154 "data/maps/Route112/scripts.pory"
	.string "of the crew went out to Fallarbor.$"
# 155 "data/maps/Route112/scripts.pory"

# 156 "data/maps/Route112/scripts.pory"
Route112_Text_CantLetAnyonePassUntilTheyreBack: @ 81F2003
# 157 "data/maps/Route112/scripts.pory"
	.string "You got it. And until they come back,\n"
# 158 "data/maps/Route112/scripts.pory"
	.string "we're not to let anyone pass, right.$"
# 159 "data/maps/Route112/scripts.pory"

# 160 "data/maps/Route112/scripts.pory"
Route112_Text_NotEasyToGetBackToLavaridge: @ 81F204E
# 161 "data/maps/Route112/scripts.pory"
	.string "Eh, I'd like to get to Mauville, but if\n"
# 162 "data/maps/Route112/scripts.pory"
	.string "I went down these ledges, it'd be no\l"
# 163 "data/maps/Route112/scripts.pory"
	.string "easy matter to get back to Lavaridge.$"
# 164 "data/maps/Route112/scripts.pory"

# 165 "data/maps/Route112/scripts.pory"
Route112_Text_MtChimneyCableCarSign: @ 81F20C1
# 166 "data/maps/Route112/scripts.pory"
	.string "Mt. Chimney Cable Car\n"
# 167 "data/maps/Route112/scripts.pory"
	.string "“A short walk {UP_ARROW} way!”$"
# 168 "data/maps/Route112/scripts.pory"

# 169 "data/maps/Route112/scripts.pory"
Route112_Text_MtChimneySign: @ 81F20ED
# 170 "data/maps/Route112/scripts.pory"
	.string "Mt. Chimney\p"
# 171 "data/maps/Route112/scripts.pory"
	.string "“For Lavaridge Town or the summit,\n"
# 172 "data/maps/Route112/scripts.pory"
	.string "please take the Cable Car.”$"
# 173 "data/maps/Route112/scripts.pory"

# 174 "data/maps/Route112/scripts.pory"
Route112_Text_RouteSignLavaridge: @ 81F2138
# 175 "data/maps/Route112/scripts.pory"
	.string "Route 112\n"
# 176 "data/maps/Route112/scripts.pory"
	.string "{LEFT_ARROW} Lavaridge Town$"
