# 1 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 2 "data/maps/GraniteCave_StevensRoom/scripts.pory"
.set LOCALID_STEVEN, 1
# 3 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 4 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_MapScripts:: @ 822DC7A
# 5 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.byte 0
# 6 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 7 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_EventScript_Steven:: @ 822DC7B
# 8 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
# 9 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setvar VAR_0x8004, ITEM_LETTER
# 10 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 11 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setflag FLAG_DELIVERED_STEVEN_LETTER
# 12 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
# 13 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	givemon SPECIES_HONEDGE, 20, ITEM_BERRY_JUICE
# 14 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 15 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	message GraniteCave_StevensRoom_Text_ObtainedHonedge
# 16 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	waitfanfare
# 17 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	waitmessage
# 18 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
# 19 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	closemessage
# 20 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	delay 30
# 21 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 22 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
# 23 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	waitfanfare
# 24 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	closemessage
# 25 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	delay 30
# 26 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setflag FLAG_REGISTERED_STEVEN_POKENAV
# 27 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
# 28 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	closemessage
# 29 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 30 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	call_if_eq GraniteCave_StevensRoom_EventScript_StevenExitNorth
# 31 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 32 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	call_if_eq GraniteCave_StevensRoom_EventScript_StevenExitSouth
# 33 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 34 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	call_if_eq GraniteCave_StevensRoom_EventScript_StevenExitWestEast
# 35 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 36 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	call_if_eq GraniteCave_StevensRoom_EventScript_StevenExitWestEast
# 37 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	playse SE_EXIT
# 38 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	removeobject LOCALID_STEVEN
# 39 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	release
# 40 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	end
# 41 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 42 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 43 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_ObtainedHonedge::
# 44 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Honedge{COLOR DARK_GRAY} as a gift!$"
# 45 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 46 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_EventScript_StevenExitNorth:: @ 822DD0D
# 47 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
# 48 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	waitmovement 0
# 49 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	return
# 50 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 51 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_EventScript_StevenExitWestEast:: @ 822DD18
# 52 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
# 53 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
# 54 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	waitmovement 0
# 55 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	return
# 56 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 57 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_EventScript_StevenExitSouth:: @ 822DD2A
# 58 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
# 59 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
# 60 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	waitmovement 0
# 61 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	return
# 62 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 63 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_EventScript_BagFull:: @ 822DD3C
# 64 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
# 65 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	return
# 66 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 67 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Movement_StevenExit: @ 822DD45
# 68 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 69 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 70 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 71 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 72 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 73 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	delay_8
# 74 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	step_end
# 75 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 76 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit: @ 822DD4C
# 77 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	delay_16
# 78 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	delay_16
# 79 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	delay_16
# 80 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_in_place_fastest_up
# 81 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	step_end
# 82 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 83 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Movement_StevenExitSouth: @ 822DD51
# 84 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_left
# 85 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 86 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 87 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 88 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_right
# 89 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 90 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 91 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	delay_8
# 92 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	step_end
# 93 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 94 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_ImStevenLetterForMe: @ 822DD5A
# 95 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "My name is Steven.\p"
# 96 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "I'm interested in rare stones,\n"
# 97 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "so I travel here and there.\p"
# 98 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Oh?\n"
# 99 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "A Letter for me?$"
# 100 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 101 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_ThankYouTakeThis: @ 822DDBD
# 102 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Steven: Okay, thank you.\p"
# 103 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "You went through all this trouble to\n"
# 104 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "deliver that. I need to thank you.\p"
# 105 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Let me see…\n"
# 106 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "I'll give you this!\p"
# 107 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "It could be useful for the Gym\n"
# 108 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "here thanks to its Ghost typing.$"
# 109 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 110 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister: @ 822DE6B
# 111 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Steven: Your Pokémon appear quite\n"
# 112 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "capable.\p"
# 113 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "If you keep training, you could even\n"
# 114 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "become the Champion of the Pokémon\l"
# 115 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "League one day. That's what I think.\p"
# 116 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "I know, since we've gotten to know each\n"
# 117 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "other, let's register one another in\l"
# 118 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "our PokéNavs.\p"
# 119 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "… … … … … …$"
# 120 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 121 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_RegisteredSteven: @ 822DF6A
# 122 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Registered Steven\n"
# 123 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "in the PokéNav.$"
# 124 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 125 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_IveGotToHurryAlong: @ 822DF8C
# 126 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Now, I've got to hurry along.$"
# 127 "data/maps/GraniteCave_StevensRoom/scripts.pory"

# 128 "data/maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_OhBagIsFull: @ 822DFAA
# 129 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Oh, your Bag is full…\n"
# 130 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "That's too bad, then.$"

GraniteCave_StevensRoom_EventScript_Steven_Battle::
# 134 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	lock
# 135 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	faceplayer
# 136 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	trainerbattle_single TRAINER_STEVEN_GRANITE_CAVE, GraniteCave_StevensRoom_EventScript_Steven_Battle_Text_0, GraniteCave_StevensRoom_EventScript_Steven_Battle_Text_1, GraniteCave_StevensRoom_EventScript_Steven, NO_MUSIC
	return


GraniteCave_StevensRoom_EventScript_Steven_Battle_Text_0:
# 136 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Steven: Young trainer, show me what\n"
	.string "you've got, before we talk.$"

GraniteCave_StevensRoom_EventScript_Steven_Battle_Text_1:
# 136 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Steven: You have great potential.$"
