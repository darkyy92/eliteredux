# 1 "data/maps/MeteorFalls_StevensCave/scripts.pory"

# 2 "data/maps/MeteorFalls_StevensCave/scripts.pory"
.set LOCALID_STEVEN, 1
# 3 "data/maps/MeteorFalls_StevensCave/scripts.pory"

# 4 "data/maps/MeteorFalls_StevensCave/scripts.pory"
MeteorFalls_StevensCave_MapScripts:: @ 823B181
# 5 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.byte 0
# 6 "data/maps/MeteorFalls_StevensCave/scripts.pory"

# 7 "data/maps/MeteorFalls_StevensCave/scripts.pory"
MeteorFalls_StevensCave_EventScript_Steven:: @ 823B182
# 8 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	lock
# 9 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	//goto_if_set FLAG_DAILY_REMATCH_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
# 10 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	waitse
# 11 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	playse SE_PIN
# 12 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
# 13 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	waitmovement 0
# 14 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
# 15 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	waitmovement 0
# 16 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
# 17 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	waitmovement 0
# 18 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
# 19 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
# 20 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
# 21 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_STEVEN
# 22 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	goto_if_unset FLAG_RECEIVED_AURORA_TICKET, MeteorFalls_StevensCave_EventScript_GiveAuroraTicket
# 23 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	release
# 24 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	end
# 25 "data/maps/MeteorFalls_StevensCave/scripts.pory"

# 26 "data/maps/MeteorFalls_StevensCave/scripts.pory"
MeteorFalls_StevensCave_EventScript_Defeated:: @ 823B1CD
# 27 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
# 28 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	waitmovement 0
# 29 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
# 30 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	release
# 31 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	end
# 32 "data/maps/MeteorFalls_StevensCave/scripts.pory"

# 33 "data/maps/MeteorFalls_StevensCave/scripts.pory"
MeteorFalls_StevensCave_EventScript_GiveAuroraTicket:
# 34 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	msgbox MeteorFalls_StevensCave_Text_BirthIsland, MSGBOX_DEFAULT
# 35 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	giveitem ITEM_AURORA_TICKET
# 36 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	setflag FLAG_RECEIVED_AURORA_TICKET
# 37 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
# 38 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	release
# 39 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	end
# 40 "data/maps/MeteorFalls_StevensCave/scripts.pory"

# 41 "data/maps/MeteorFalls_StevensCave/scripts.pory"
MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst: @ 823B1E1
# 42 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "Steven: Oh, wow, {PLAYER}{KUN}.\n"
# 43 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "I'm amazed you knew where to find me.\p"
# 44 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "Do you, uh… maybe think of me as\n"
# 45 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "just a rock maniac?\p"
# 46 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "No, that can't be right.\p"
# 47 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "We battled alongside each other at\n"
# 48 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "the Mossdeep Space Center.\p"
# 49 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "You should have a very good idea\n"
# 50 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "about how good I am.\p"
# 51 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "Okay, {PLAYER}{KUN}, if you're going to mount\n"
# 52 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "a serious challenge, expect the worst!$"
# 53 "data/maps/MeteorFalls_StevensCave/scripts.pory"

# 54 "data/maps/MeteorFalls_StevensCave/scripts.pory"
MeteorFalls_StevensCave_Text_StevenDefeat: @ 823B32D
# 55 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "You…\n"
# 56 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "I had no idea you'd become so strong…$"
# 57 "data/maps/MeteorFalls_StevensCave/scripts.pory"

# 58 "data/maps/MeteorFalls_StevensCave/scripts.pory"
MeteorFalls_StevensCave_Text_MyPredictionCameTrue: @ 823B358
# 59 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "Steven: Come to think of it, ever since\n"
# 60 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "our paths first crossed in Granite\l"
# 61 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "Cave in Dewford, I had this feeling.\p"
# 62 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "I thought that you would eventually\n"
# 63 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "become the Champion.\p"
# 64 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "My predictions usually come true.\p"
# 65 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "And where will you go from here?\p"
# 66 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "… … … … … …\n"
# 67 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "… … … … … …\p"
# 68 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "Fufufu, even I couldn't tell you that.$"
# 69 "data/maps/MeteorFalls_StevensCave/scripts.pory"

# 70 "data/maps/MeteorFalls_StevensCave/scripts.pory"
MeteorFalls_StevensCave_Text_BirthIsland:
# 71 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "But… maybe you'd like to\n"
# 72 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "investigate the strange stone that's\l"
# 73 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "appeared on Birth Island?\p"
# 74 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "Here, take this ticket to the harbor\n"
# 75 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "in Lilycove.\p"
# 76 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "Perhaps you'll find something useful…$"
