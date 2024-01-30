# 1 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 2 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
.set LOCALID_DOCK, 1
# 3 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 4 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_MapScripts:: @ 8207F3F
# 5 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.byte 0
# 6 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 7 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_Dock:: @ 8207F40
# 8 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	lockall
# 9 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
# 10 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
# 11 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
# 12 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
# 13 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
# 14 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
# 15 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 16 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
# 17 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	closemessage
# 18 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
# 19 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 20 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
# 21 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	releaseall
# 22 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 23 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 24 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_FerryReady:: @ 8207F92
# 25 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
# 26 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 27 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
# 28 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	releaseall
# 29 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 30 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 31 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined:: @ 8207FA6
# 32 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
# 33 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 34 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
# 35 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	releaseall
# 36 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 37 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 38 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_GoFindStern:: @ 8207FBA
# 39 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
# 40 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 41 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
# 42 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	closemessage
# 43 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
# 44 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 45 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	releaseall
# 46 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 47 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 48 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran:: @ 8207FD9
# 49 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
# 50 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	waitmovement 0
# 51 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
# 52 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	releaseall
# 53 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 54 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 55 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_Scientist1:: @ 8207FED
# 56 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
# 57 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 58 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 59 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_Scientist2:: @ 8207FF6
# 60 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
# 61 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 62 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 63 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_EventScript_Briney:: @ 8207FFF
# 64 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
# 65 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	end
# 66 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 67 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails: @ 8208008
# 68 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Umm… If this goes here, and that\n"
# 69 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "goes over there…\p"
# 70 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Then where does this thing go?\n"
# 71 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "And what about that doohickey?\p"
# 72 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Aaargh! I can't make heads or tails\n"
# 73 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "of this!$"
# 74 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 75 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern: @ 82080A5
# 76 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Hm?\n"
# 77 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Hi, I'm Dock.\p"
# 78 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Capt. Stern commissioned me to\n"
# 79 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "design a ferry.\p"
# 80 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Oh! That there…\n"
# 81 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Are they Devon Parts?\p"
# 82 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "But, hmm…\n"
# 83 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "This won't do…\p"
# 84 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Capt. Stern went off somewhere.\n"
# 85 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "He said he had some work to do.\p"
# 86 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Could I get you to go find Capt.\n"
# 87 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Stern and deliver that to him?$"
# 88 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 89 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern: @ 82081A5
# 90 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Dock: Where could Capt. Stern have\n"
# 91 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "gone off to?\p"
# 92 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Could you go find Capt. Stern and\n"
# 93 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "deliver that parcel to him?$"
# 94 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 95 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran: @ 8208213
# 96 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Dock: Shipbuilding is an art.\p"
# 97 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "A lot of things can't be figured out\n"
# 98 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "just by calculating.\p"
# 99 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "I really could use advice from a veteran\n"
# 100 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "who knows the seas…$"
# 101 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 102 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs: @ 82082A8
# 103 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Dock: Hi! Mr. Briney's joined us to\n"
# 104 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "lend us his help.\p"
# 105 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Thanks to the veteran sailor, the\n"
# 106 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "ferry is steadily coming together.$"
# 107 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 108 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_FerryIsReady: @ 8208323
# 109 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Dock: The ferry is finally ready!\p"
# 110 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "The new S.S. Tidal is truly a marvel\n"
# 111 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "of technology!\p"
# 112 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "But, I get the feeling that we can\n"
# 113 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "make something even better.\p"
# 114 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "You know, there's never an end to\n"
# 115 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "technology's march.$"
# 116 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 117 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock: @ 82083EE
# 118 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Mr. Briney: Ah, {PLAYER}{KUN}!\n"
# 119 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "It's been too long!\p"
# 120 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Aye, since I met you, this old sea dog's\n"
# 121 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "been feeling frisky!\p"
# 122 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "So I've decided to help Dock make\n"
# 123 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "a ferry.\p"
# 124 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "Aye, after all, a ferry would be able\n"
# 125 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "to carry a lot of people.\p"
# 126 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "But, you know, that Dock is really\n"
# 127 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "something special.\p"
# 128 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "With his knack for technology and\n"
# 129 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "my experience, I'm sure that we can\l"
# 130 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "build one great ship, aye!$"
# 131 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 132 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing: @ 8208558
# 133 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "The seasons, the weather, where\n"
# 134 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "the moon sits in the sky…\p"
# 135 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "These and other conditions make\n"
# 136 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "the sea change its expression.\p"
# 137 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "That's right!\n"
# 138 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "The sea is like a living thing!$"
# 139 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"

# 140 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily: @ 82085FF
# 141 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "I get seasick real easily.\n"
# 142 "data/maps/SlateportCity_SternsShipyard_1F/scripts.pory"
	.string "So I get to help out here instead.$"
