# 1 "data/maps/SeafloorCavern_Entrance/scripts.pory"

# 2 "data/maps/SeafloorCavern_Entrance/scripts.pory"
.set LOCALID_GRUNT, 1
# 3 "data/maps/SeafloorCavern_Entrance/scripts.pory"

# 4 "data/maps/SeafloorCavern_Entrance/scripts.pory"
SeafloorCavern_Entrance_MapScripts:: @ 823446E
# 5 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SeafloorCavern_Entrance_OnResume
# 6 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.byte 0
# 7 "data/maps/SeafloorCavern_Entrance/scripts.pory"

# 8 "data/maps/SeafloorCavern_Entrance/scripts.pory"
SeafloorCavern_Entrance_OnResume: @ 8234474
# 9 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	setdivewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 255, 6, 5
# 10 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	setescapewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 255, 6, 5
# 11 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	end
# 12 "data/maps/SeafloorCavern_Entrance/scripts.pory"

# 13 "data/maps/SeafloorCavern_Entrance/scripts.pory"
SeafloorCavern_Entrance_EventScript_Grunt:: @ 8234485
# 14 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	lockall
# 15 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	compare VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1
# 16 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	goto_if_eq SeafloorCavern_Entrance_EventScript_GruntSpeechShort
# 17 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	waitse
# 18 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	playse SE_PIN
# 19 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	applymovement LOCALID_GRUNT, Common_Movement_ExclamationMark
# 20 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	waitmovement 0
# 21 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	applymovement LOCALID_GRUNT, Common_Movement_Delay48
# 22 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	waitmovement 0
# 23 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	delay 20
# 24 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 25 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
# 26 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 27 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
# 28 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 29 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
# 30 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	delay 30
# 31 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	setvar VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1
# 32 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	copyobjectxytoperm LOCALID_GRUNT
# 33 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep, MSGBOX_DEFAULT
# 34 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	closemessage
# 35 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFastestUp
# 36 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	waitmovement 0
# 37 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	releaseall
# 38 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	end
# 39 "data/maps/SeafloorCavern_Entrance/scripts.pory"

# 40 "data/maps/SeafloorCavern_Entrance/scripts.pory"
SeafloorCavern_Entrance_EventScript_GruntSpeechShort:: @ 82344ED
# 41 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 42 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
# 43 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 44 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
# 45 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 46 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
# 47 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort, MSGBOX_DEFAULT
# 48 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	closemessage
# 49 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFastestUp
# 50 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	waitmovement 0
# 51 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	releaseall
# 52 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	end
# 53 "data/maps/SeafloorCavern_Entrance/scripts.pory"

# 54 "data/maps/SeafloorCavern_Entrance/scripts.pory"
SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast:: @ 8234523
# 55 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFastestLeft
# 56 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	waitmovement 0
# 57 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	return
# 58 "data/maps/SeafloorCavern_Entrance/scripts.pory"

# 59 "data/maps/SeafloorCavern_Entrance/scripts.pory"
SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest:: @ 823452E
# 60 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFastestRight
# 61 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	waitmovement 0
# 62 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	return
# 63 "data/maps/SeafloorCavern_Entrance/scripts.pory"

# 64 "data/maps/SeafloorCavern_Entrance/scripts.pory"
SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth:: @ 8234539
# 65 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFastestDown
# 66 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	waitmovement 0
# 67 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	return
# 68 "data/maps/SeafloorCavern_Entrance/scripts.pory"

# 69 "data/maps/SeafloorCavern_Entrance/scripts.pory"
SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep: @ 8234544
# 70 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "Hey!\n"
# 71 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "I remember your face!\p"
# 72 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "If you're here, it must mean that\n"
# 73 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "you're about to mess with us again!\p"
# 74 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "A punk like you, do you really think\n"
# 75 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "you can take on Team Aqua?\p"
# 76 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "I'd say you're too early by about\n"
# 77 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "a trillion years!\p"
# 78 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "You're a perfect fit for the likes of\n"
# 79 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "Team Magma!\p"
# 80 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "Speaking of Team Magma, I hear they\n"
# 81 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "were spotted near Mossdeep.\p"
# 82 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "That bunch of goons, they sure don't\n"
# 83 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "look good near the sea!$"
# 84 "data/maps/SeafloorCavern_Entrance/scripts.pory"

# 85 "data/maps/SeafloorCavern_Entrance/scripts.pory"
SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort: @ 82346C8
# 86 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "A punk like you, do you really think\n"
# 87 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "you can take on Team Aqua?\p"
# 88 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "I'd say you're too early by about\n"
# 89 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "a trillion years!\p"
# 90 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "You're a perfect fit for the likes of\n"
# 91 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "Team Magma!\p"
# 92 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "Speaking of Team Magma, I hear they\n"
# 93 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "were spotted near Mossdeep.\p"
# 94 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "That bunch of goons, they sure don't\n"
# 95 "data/maps/SeafloorCavern_Entrance/scripts.pory"
	.string "look good near the sea!$"
