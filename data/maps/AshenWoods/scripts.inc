# 1 "data/maps/AshenWoods/scripts.pory"

# 2 "data/maps/AshenWoods/scripts.pory"
.set LOCALID_CHANSEY, 6
# 3 "data/maps/AshenWoods/scripts.pory"
.set LOCALID_POKE_BALL, 7
# 4 "data/maps/AshenWoods/scripts.pory"

# 5 "data/maps/AshenWoods/scripts.pory"
AshenWoods_MapScripts::
# 6 "data/maps/AshenWoods/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, AshenWoods_OnResume
# 7 "data/maps/AshenWoods/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AshenWoods_OnTransition
# 8 "data/maps/AshenWoods/scripts.pory"
	.byte 0
# 9 "data/maps/AshenWoods/scripts.pory"

# 10 "data/maps/AshenWoods/scripts.pory"
AshenWoods_OnResume::
# 11 "data/maps/AshenWoods/scripts.pory"
	setstepcallback STEP_CB_ASH
# 12 "data/maps/AshenWoods/scripts.pory"
	end
# 13 "data/maps/AshenWoods/scripts.pory"

# 14 "data/maps/AshenWoods/scripts.pory"
AshenWoods_OnTransition::
# 15 "data/maps/AshenWoods/scripts.pory"
	setflag FLAG_LANDMARK_ASHEN_WOODS
# 16 "data/maps/AshenWoods/scripts.pory"
	compare VAR_JAGGED_PASS_ASH_WEATHER, 1
# 17 "data/maps/AshenWoods/scripts.pory"
	call_if_eq AshenWoods_EventScript_SetWeatherAsh
# 18 "data/maps/AshenWoods/scripts.pory"
	switch VAR_CHANSEY_NURSE_STATE
# 19 "data/maps/AshenWoods/scripts.pory"
	case 4, AshenWoods_EventScript_ChanseySetPos1
# 20 "data/maps/AshenWoods/scripts.pory"
	case 5, AshenWoods_EventScript_ChanseySetPos2
# 21 "data/maps/AshenWoods/scripts.pory"
	end
# 22 "data/maps/AshenWoods/scripts.pory"

# 23 "data/maps/AshenWoods/scripts.pory"
AshenWoods_EventScript_SetWeatherAsh::
# 24 "data/maps/AshenWoods/scripts.pory"
	setweather WEATHER_VOLCANIC_ASH
# 25 "data/maps/AshenWoods/scripts.pory"
	doweather
# 26 "data/maps/AshenWoods/scripts.pory"
	return
# 27 "data/maps/AshenWoods/scripts.pory"

# 28 "data/maps/AshenWoods/scripts.pory"
AshenWoods_EventScript_Chef::
# 29 "data/maps/AshenWoods/scripts.pory"
	msgbox AshenWoods_Text_Mushrooms, MSGBOX_NPC
# 30 "data/maps/AshenWoods/scripts.pory"
	end
# 31 "data/maps/AshenWoods/scripts.pory"

# 32 "data/maps/AshenWoods/scripts.pory"
AshenWoods_EventScript_ChanseyTrigger::
# 33 "data/maps/AshenWoods/scripts.pory"
	lockall
# 34 "data/maps/AshenWoods/scripts.pory"
	waitse
# 35 "data/maps/AshenWoods/scripts.pory"
	playse SE_PIN
# 36 "data/maps/AshenWoods/scripts.pory"
	applymovement LOCALID_CHANSEY, Common_Movement_ExclamationMark
# 37 "data/maps/AshenWoods/scripts.pory"
	waitmovement 0
# 38 "data/maps/AshenWoods/scripts.pory"
	applymovement LOCALID_CHANSEY, Common_Movement_Delay48
# 39 "data/maps/AshenWoods/scripts.pory"
	waitmovement 0
# 40 "data/maps/AshenWoods/scripts.pory"
	applymovement LOCALID_CHANSEY, AshenWoods_Movement_ChanseyJumpRight
# 41 "data/maps/AshenWoods/scripts.pory"
	waitmovement 0
# 42 "data/maps/AshenWoods/scripts.pory"
	waitse
# 43 "data/maps/AshenWoods/scripts.pory"
	playmoncry SPECIES_CHANSEY, 0
# 44 "data/maps/AshenWoods/scripts.pory"
	delay 40
# 45 "data/maps/AshenWoods/scripts.pory"
	waitmoncry
# 46 "data/maps/AshenWoods/scripts.pory"
	applymovement LOCALID_CHANSEY, AshenWoods_Movement_ChanseyEscape1
# 47 "data/maps/AshenWoods/scripts.pory"
	waitmovement 0
# 48 "data/maps/AshenWoods/scripts.pory"
	call AshenWoods_EventScript_ChanseySetPos1
# 49 "data/maps/AshenWoods/scripts.pory"
	setvar VAR_CHANSEY_NURSE_STATE, 4
# 50 "data/maps/AshenWoods/scripts.pory"
	releaseall
# 51 "data/maps/AshenWoods/scripts.pory"
	end
# 52 "data/maps/AshenWoods/scripts.pory"

# 53 "data/maps/AshenWoods/scripts.pory"
AshenWoods_EventScript_ChanseyTrigger2::
# 54 "data/maps/AshenWoods/scripts.pory"
	lockall
# 55 "data/maps/AshenWoods/scripts.pory"
	waitse
# 56 "data/maps/AshenWoods/scripts.pory"
	playse SE_PIN
# 57 "data/maps/AshenWoods/scripts.pory"
	applymovement LOCALID_CHANSEY, Common_Movement_ExclamationMark
# 58 "data/maps/AshenWoods/scripts.pory"
	waitmovement 0
# 59 "data/maps/AshenWoods/scripts.pory"
	applymovement LOCALID_CHANSEY, Common_Movement_Delay48
# 60 "data/maps/AshenWoods/scripts.pory"
	waitmovement 0
# 61 "data/maps/AshenWoods/scripts.pory"
	applymovement LOCALID_CHANSEY, AshenWoods_Movement_ChanseyJumpUp
# 62 "data/maps/AshenWoods/scripts.pory"
	waitmovement 0
# 63 "data/maps/AshenWoods/scripts.pory"
	waitse
# 64 "data/maps/AshenWoods/scripts.pory"
	playmoncry SPECIES_CHANSEY, 0
# 65 "data/maps/AshenWoods/scripts.pory"
	delay 40
# 66 "data/maps/AshenWoods/scripts.pory"
	waitmoncry
# 67 "data/maps/AshenWoods/scripts.pory"
	applymovement LOCALID_CHANSEY, AshenWoods_Movement_ChanseyEscape2
# 68 "data/maps/AshenWoods/scripts.pory"
	waitmovement 0
# 69 "data/maps/AshenWoods/scripts.pory"
	call AshenWoods_EventScript_ChanseySetPos2
# 70 "data/maps/AshenWoods/scripts.pory"
	setvar VAR_CHANSEY_NURSE_STATE, 5
# 71 "data/maps/AshenWoods/scripts.pory"
	releaseall
# 72 "data/maps/AshenWoods/scripts.pory"
	end
# 73 "data/maps/AshenWoods/scripts.pory"

# 74 "data/maps/AshenWoods/scripts.pory"
AshenWoods_EventScript_ChanseySetPos1::
# 75 "data/maps/AshenWoods/scripts.pory"
	setobjectxy LOCALID_CHANSEY, 6, 40
# 76 "data/maps/AshenWoods/scripts.pory"
	copyobjectxytoperm LOCALID_CHANSEY
# 77 "data/maps/AshenWoods/scripts.pory"
	return
# 78 "data/maps/AshenWoods/scripts.pory"

# 79 "data/maps/AshenWoods/scripts.pory"
AshenWoods_EventScript_ChanseySetPos2::
# 80 "data/maps/AshenWoods/scripts.pory"
	setobjectxy LOCALID_CHANSEY, 27, 43
# 81 "data/maps/AshenWoods/scripts.pory"
	copyobjectxytoperm LOCALID_CHANSEY
# 82 "data/maps/AshenWoods/scripts.pory"
	return
# 83 "data/maps/AshenWoods/scripts.pory"

# 84 "data/maps/AshenWoods/scripts.pory"
AshenWoods_EventScript_Chansey::
# 85 "data/maps/AshenWoods/scripts.pory"
	lockall
# 86 "data/maps/AshenWoods/scripts.pory"
	faceplayer
# 87 "data/maps/AshenWoods/scripts.pory"
	applymovement LOCALID_CHANSEY, AshenWoods_Movement_ChanseyJumpRight
# 88 "data/maps/AshenWoods/scripts.pory"
	waitmovement 0
# 89 "data/maps/AshenWoods/scripts.pory"
	waitse
# 90 "data/maps/AshenWoods/scripts.pory"
	playmoncry SPECIES_CHANSEY, 0
# 91 "data/maps/AshenWoods/scripts.pory"
	delay 40
# 92 "data/maps/AshenWoods/scripts.pory"
	waitmoncry
# 93 "data/maps/AshenWoods/scripts.pory"
	msgbox AshenWoods_Text_BlobNowhereToRun, MSGBOX_DEFAULT
# 94 "data/maps/AshenWoods/scripts.pory"
	checkitem ITEM_HEAL_BALL, 1
# 95 "data/maps/AshenWoods/scripts.pory"
	compare VAR_RESULT, FALSE
# 96 "data/maps/AshenWoods/scripts.pory"
	goto_if_eq AshenWoods_EventScript_BlobNoHealBall
# 97 "data/maps/AshenWoods/scripts.pory"
	msgbox AshenWoods_Text_CatchBlob, MSGBOX_DEFAULT
# 98 "data/maps/AshenWoods/scripts.pory"
	removeitem ITEM_HEAL_BALL, 1
# 99 "data/maps/AshenWoods/scripts.pory"
	playse SE_BALL_THROW
# 100 "data/maps/AshenWoods/scripts.pory"
	waitse
# 101 "data/maps/AshenWoods/scripts.pory"
	removeobject LOCALID_CHANSEY
# 102 "data/maps/AshenWoods/scripts.pory"
	addobject LOCALID_POKE_BALL
# 103 "data/maps/AshenWoods/scripts.pory"
	playse SE_BALL_BOUNCE_1
# 104 "data/maps/AshenWoods/scripts.pory"
	waitse
# 105 "data/maps/AshenWoods/scripts.pory"
	playse SE_BALL_BOUNCE_2
# 106 "data/maps/AshenWoods/scripts.pory"
	waitse
# 107 "data/maps/AshenWoods/scripts.pory"
	playse SE_BALL_BOUNCE_4
# 108 "data/maps/AshenWoods/scripts.pory"
	waitse
# 109 "data/maps/AshenWoods/scripts.pory"
	playse SE_RG_BALL_CLICK
# 110 "data/maps/AshenWoods/scripts.pory"
	waitse
# 111 "data/maps/AshenWoods/scripts.pory"
	msgbox AshenWoods_Text_BlobCaught, MSGBOX_DEFAULT
# 112 "data/maps/AshenWoods/scripts.pory"
	removeobject LOCALID_POKE_BALL
# 113 "data/maps/AshenWoods/scripts.pory"
	setvar VAR_CHANSEY_NURSE_STATE, 6
# 114 "data/maps/AshenWoods/scripts.pory"
	releaseall
# 115 "data/maps/AshenWoods/scripts.pory"
	end
# 116 "data/maps/AshenWoods/scripts.pory"

# 117 "data/maps/AshenWoods/scripts.pory"
AshenWoods_EventScript_BlobNoHealBall::
# 118 "data/maps/AshenWoods/scripts.pory"
	msgbox AshenWoods_Text_BlobNoHealBall, MSGBOX_DEFAULT
# 119 "data/maps/AshenWoods/scripts.pory"
	releaseall
# 120 "data/maps/AshenWoods/scripts.pory"
	end
# 121 "data/maps/AshenWoods/scripts.pory"

# 122 "data/maps/AshenWoods/scripts.pory"
AshenWoods_Movement_ChanseyJumpRight:
# 123 "data/maps/AshenWoods/scripts.pory"
	jump_in_place_right
# 124 "data/maps/AshenWoods/scripts.pory"
	delay_4
# 125 "data/maps/AshenWoods/scripts.pory"
	jump_in_place_right
# 126 "data/maps/AshenWoods/scripts.pory"
	step_end
# 127 "data/maps/AshenWoods/scripts.pory"

# 128 "data/maps/AshenWoods/scripts.pory"
AshenWoods_Movement_ChanseyJumpUp:
# 129 "data/maps/AshenWoods/scripts.pory"
	jump_in_place_up
# 130 "data/maps/AshenWoods/scripts.pory"
	delay_4
# 131 "data/maps/AshenWoods/scripts.pory"
	jump_in_place_up
# 132 "data/maps/AshenWoods/scripts.pory"
	step_end
# 133 "data/maps/AshenWoods/scripts.pory"

# 134 "data/maps/AshenWoods/scripts.pory"
AshenWoods_Movement_ChanseyEscape1:
# 135 "data/maps/AshenWoods/scripts.pory"
	walk_fast_down
# 136 "data/maps/AshenWoods/scripts.pory"
	walk_fast_down
# 137 "data/maps/AshenWoods/scripts.pory"
	walk_fast_down
# 138 "data/maps/AshenWoods/scripts.pory"
	walk_fast_down
# 139 "data/maps/AshenWoods/scripts.pory"
	walk_fast_down
# 140 "data/maps/AshenWoods/scripts.pory"
	walk_fast_left
# 141 "data/maps/AshenWoods/scripts.pory"
	walk_fast_left
# 142 "data/maps/AshenWoods/scripts.pory"
	walk_fast_left
# 143 "data/maps/AshenWoods/scripts.pory"
	walk_fast_left
# 144 "data/maps/AshenWoods/scripts.pory"
	walk_fast_left
# 145 "data/maps/AshenWoods/scripts.pory"
	walk_fast_left
# 146 "data/maps/AshenWoods/scripts.pory"
	walk_fast_left
# 147 "data/maps/AshenWoods/scripts.pory"
	face_up
# 148 "data/maps/AshenWoods/scripts.pory"
	step_end
# 149 "data/maps/AshenWoods/scripts.pory"

# 150 "data/maps/AshenWoods/scripts.pory"
AshenWoods_Movement_ChanseyEscape2:
# 151 "data/maps/AshenWoods/scripts.pory"
	walk_fast_right
# 152 "data/maps/AshenWoods/scripts.pory"
	walk_fast_right
# 153 "data/maps/AshenWoods/scripts.pory"
	walk_fast_right
# 154 "data/maps/AshenWoods/scripts.pory"
	walk_fast_down
# 155 "data/maps/AshenWoods/scripts.pory"
	walk_fast_right
# 156 "data/maps/AshenWoods/scripts.pory"
	walk_fast_right
# 157 "data/maps/AshenWoods/scripts.pory"
	walk_fast_right
# 158 "data/maps/AshenWoods/scripts.pory"
	walk_fast_right
# 159 "data/maps/AshenWoods/scripts.pory"
	walk_fast_right
# 160 "data/maps/AshenWoods/scripts.pory"
	walk_fast_right
# 161 "data/maps/AshenWoods/scripts.pory"
	walk_fast_right
# 162 "data/maps/AshenWoods/scripts.pory"
	step_end
# 163 "data/maps/AshenWoods/scripts.pory"

# 164 "data/maps/AshenWoods/scripts.pory"
AshenWoods_EventScript_Alannah::
# 165 "data/maps/AshenWoods/scripts.pory"
	trainerbattle_single TRAINER_ALANNAH, AshenWoods_Text_AlannahIntro, AshenWoods_Text_AlannahDefeat
# 166 "data/maps/AshenWoods/scripts.pory"
	msgbox AshenWoods_Text_AlannahPostBattle, MSGBOX_AUTOCLOSE
# 167 "data/maps/AshenWoods/scripts.pory"
	end
# 168 "data/maps/AshenWoods/scripts.pory"

# 169 "data/maps/AshenWoods/scripts.pory"
AshenWoods_EventScript_Martin::
# 170 "data/maps/AshenWoods/scripts.pory"
	trainerbattle_single TRAINER_MARTIN, AshenWoods_Text_MartinIntro, AshenWoods_Text_MartinDefeat
# 171 "data/maps/AshenWoods/scripts.pory"
	msgbox AshenWoods_Text_MartinPostBattle, MSGBOX_AUTOCLOSE
# 172 "data/maps/AshenWoods/scripts.pory"
	end
# 173 "data/maps/AshenWoods/scripts.pory"

# 174 "data/maps/AshenWoods/scripts.pory"
AshenWoods_EventScript_Roman::
# 175 "data/maps/AshenWoods/scripts.pory"
	trainerbattle_single TRAINER_ROMAN, AshenWoods_Text_RomanIntro, AshenWoods_Text_RomanDefeat
# 176 "data/maps/AshenWoods/scripts.pory"
	msgbox AshenWoods_Text_RomanPostBattle, MSGBOX_AUTOCLOSE
# 177 "data/maps/AshenWoods/scripts.pory"
	end
# 178 "data/maps/AshenWoods/scripts.pory"

# 179 "data/maps/AshenWoods/scripts.pory"
AshenWoods_EventScript_Elmer::
# 180 "data/maps/AshenWoods/scripts.pory"
	trainerbattle_single TRAINER_ELMER, AshenWoods_Text_ElmerIntro, AshenWoods_Text_ElmerDefeat
# 181 "data/maps/AshenWoods/scripts.pory"
	msgbox AshenWoods_Text_ElmerPostBattle, MSGBOX_AUTOCLOSE
# 182 "data/maps/AshenWoods/scripts.pory"
	end
# 183 "data/maps/AshenWoods/scripts.pory"

# 184 "data/maps/AshenWoods/scripts.pory"
AshenWoods_Text_Mushrooms:
# 185 "data/maps/AshenWoods/scripts.pory"
	.string "The mushrooms that grow here are\n"
# 186 "data/maps/AshenWoods/scripts.pory"
	.string "a highly sought after ingredient.\p"
# 187 "data/maps/AshenWoods/scripts.pory"
	.string "They're quite valuable, and they\n"
# 188 "data/maps/AshenWoods/scripts.pory"
	.string "seem to grow back overnight!\n"
# 189 "data/maps/AshenWoods/scripts.pory"

# 190 "data/maps/AshenWoods/scripts.pory"
AshenWoods_Text_BlobNowhereToRun:
# 191 "data/maps/AshenWoods/scripts.pory"
	.string "Blob has nowhere to run!$"
# 192 "data/maps/AshenWoods/scripts.pory"

# 193 "data/maps/AshenWoods/scripts.pory"
AshenWoods_Text_BlobNoHealBall:
# 194 "data/maps/AshenWoods/scripts.pory"
	.string "But {PLAYER} doesn't have a\n"
# 195 "data/maps/AshenWoods/scripts.pory"
	.string "Heal Ball to catch it…$"
# 196 "data/maps/AshenWoods/scripts.pory"

# 197 "data/maps/AshenWoods/scripts.pory"
AshenWoods_Text_CatchBlob:
# 198 "data/maps/AshenWoods/scripts.pory"
	.string "{PLAYER} threw a Heal Ball at Blob!$"
# 199 "data/maps/AshenWoods/scripts.pory"

# 200 "data/maps/AshenWoods/scripts.pory"
AshenWoods_Text_BlobCaught:
# 201 "data/maps/AshenWoods/scripts.pory"
	.string "Blob was caught!\p"
# 202 "data/maps/AshenWoods/scripts.pory"
	.string "Blob was sent to the nurse's PC.$"

AshenWoods_EventScript_Typhlosionite_Battle::
# 206 "data/maps/AshenWoods/scripts.pory"
	lock
# 207 "data/maps/AshenWoods/scripts.pory"
	faceplayer
# 208 "data/maps/AshenWoods/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, AshenWoods_EventScript_Typhlosionite_Battle_2
# 229 "data/maps/AshenWoods/scripts.pory"
	msgbox AshenWoods_EventScript_Typhlosionite_Battle_Text_6, MSGBOX_NPC
AshenWoods_EventScript_Typhlosionite_Battle_1:
# 231 "data/maps/AshenWoods/scripts.pory"
	release
	end

AshenWoods_EventScript_Typhlosionite_Battle_2:
# 210 "data/maps/AshenWoods/scripts.pory"
	checktrainerflag TRAINER_TYPHLOSIONITE_ASHEN_WOODS
	goto_if 0, AshenWoods_EventScript_Typhlosionite_Battle_5
# 225 "data/maps/AshenWoods/scripts.pory"
	msgbox AshenWoods_EventScript_Typhlosionite_Battle_Text_5, MSGBOX_NPC
	goto AshenWoods_EventScript_Typhlosionite_Battle_1

AshenWoods_EventScript_Typhlosionite_Battle_5:
# 211 "data/maps/AshenWoods/scripts.pory"
	msgbox AshenWoods_EventScript_Typhlosionite_Battle_Text_0, MSGBOX_YESNO
# 212 "data/maps/AshenWoods/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq AshenWoods_EventScript_Typhlosionite_Battle_8
# 221 "data/maps/AshenWoods/scripts.pory"
	msgbox AshenWoods_EventScript_Typhlosionite_Battle_Text_4, MSGBOX_NPC
	goto AshenWoods_EventScript_Typhlosionite_Battle_1

AshenWoods_EventScript_Typhlosionite_Battle_8:
# 213 "data/maps/AshenWoods/scripts.pory"
	msgbox AshenWoods_EventScript_Typhlosionite_Battle_Text_1, MSGBOX_NPC
# 214 "data/maps/AshenWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_TYPHLOSIONITE_ASHEN_WOODS, AshenWoods_EventScript_Typhlosionite_Battle_Text_2
# 215 "data/maps/AshenWoods/scripts.pory"
	msgbox AshenWoods_EventScript_Typhlosionite_Battle_Text_3, MSGBOX_NPC
# 216 "data/maps/AshenWoods/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 217 "data/maps/AshenWoods/scripts.pory"
	giveitem ITEM_TYPHLOSIONITE, 1
# 218 "data/maps/AshenWoods/scripts.pory"
	waitmessage
	goto AshenWoods_EventScript_Typhlosionite_Battle_1


AshenWoods_EventScript_Typhlosionite_Battle_Text_0:
# 211 "data/maps/AshenWoods/scripts.pory"
	.string "You seem strong, kid! How about this, we\n"
	.string "have a little match, and if you beat me,\l"
	.string "I'll give you a little something!$"

AshenWoods_EventScript_Typhlosionite_Battle_Text_1:
# 213 "data/maps/AshenWoods/scripts.pory"
	.string "Let's play with fire!$"

AshenWoods_EventScript_Typhlosionite_Battle_Text_2:
# 214 "data/maps/AshenWoods/scripts.pory"
	.string "That was a great fight, kid!$"

AshenWoods_EventScript_Typhlosionite_Battle_Text_3:
# 215 "data/maps/AshenWoods/scripts.pory"
	.string "Sheesh! This young, and you're already\n"
	.string "giving someone like me a beating like\l"
	.string "this! You got potential, kid. Take this\l"
	.string "Typhlosionite, and make sure to burn all\l"
	.string "who challenge you to ash!$"

AshenWoods_EventScript_Typhlosionite_Battle_Text_4:
# 221 "data/maps/AshenWoods/scripts.pory"
	.string "Then you better come back here when\n"
	.string "you're ready! Don't disappoint me!$"

AshenWoods_EventScript_Typhlosionite_Battle_Text_5:
# 225 "data/maps/AshenWoods/scripts.pory"
	.string "I got nothin' left for you, kid. Now\n"
	.string "scram!$"

AshenWoods_EventScript_Typhlosionite_Battle_Text_6:
# 229 "data/maps/AshenWoods/scripts.pory"
	.string "Hmmm... You ain't strong enough, kid!\n"
	.string "Don't come back here until you can beat\l"
	.string "that guy in Petalburg!$"
