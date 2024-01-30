# 1 "data/maps/SootopolisCity_House2/scripts.pory"

# 2 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_MapScripts:: @ 8226A76
# 3 "data/maps/SootopolisCity_House2/scripts.pory"
	.byte 0
# 4 "data/maps/SootopolisCity_House2/scripts.pory"

# 5 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_EventScript_ExpertF:: @ 8226A77
# 6 "data/maps/SootopolisCity_House2/scripts.pory"
	lock
# 7 "data/maps/SootopolisCity_House2/scripts.pory"
	faceplayer
# 8 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
# 9 "data/maps/SootopolisCity_House2/scripts.pory"
	compare VAR_RESULT, YES
# 10 "data/maps/SootopolisCity_House2/scripts.pory"
	call_if_eq SootopolisCity_House2_EventScript_KnowAboutOrbs
# 11 "data/maps/SootopolisCity_House2/scripts.pory"
	compare VAR_RESULT, NO
# 12 "data/maps/SootopolisCity_House2/scripts.pory"
	call_if_eq SootopolisCity_House2_EventScript_DontKnowAboutOrbs
# 13 "data/maps/SootopolisCity_House2/scripts.pory"
	release
# 14 "data/maps/SootopolisCity_House2/scripts.pory"
	end
# 15 "data/maps/SootopolisCity_House2/scripts.pory"

# 16 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_EventScript_KnowAboutOrbs:: @ 8226A99
# 17 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
# 18 "data/maps/SootopolisCity_House2/scripts.pory"
	return
# 19 "data/maps/SootopolisCity_House2/scripts.pory"

# 20 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_EventScript_DontKnowAboutOrbs:: @ 8226AA2
# 21 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
# 22 "data/maps/SootopolisCity_House2/scripts.pory"
	return
# 23 "data/maps/SootopolisCity_House2/scripts.pory"

# 24 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_EventScript_DracoMeteorTutor::
# 25 "data/maps/SootopolisCity_House2/scripts.pory"
	lock
# 26 "data/maps/SootopolisCity_House2/scripts.pory"
	faceplayer
# 27 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_Text_DracoMeteorTeach, MSGBOX_YESNO
# 28 "data/maps/SootopolisCity_House2/scripts.pory"
	compare VAR_RESULT, NO
# 29 "data/maps/SootopolisCity_House2/scripts.pory"
	goto_if_eq SootopolisCity_House2_EventScript_DracoMeteorDeclined
# 30 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_Text_DracoMeteorWhichMon, MSGBOX_DEFAULT
# 31 "data/maps/SootopolisCity_House2/scripts.pory"
	setvar VAR_0x8008, TRUE @ Used to indicate a tutor move requires max happiness
# 32 "data/maps/SootopolisCity_House2/scripts.pory"
	setvar VAR_0x8005, TUTOR_MOVE_DRACO_METEOR
# 33 "data/maps/SootopolisCity_House2/scripts.pory"
	call SootopolisCity_House2_EventScript_OpenPartyMenu
# 34 "data/maps/SootopolisCity_House2/scripts.pory"
	compare VAR_RESULT, 0
# 35 "data/maps/SootopolisCity_House2/scripts.pory"
	goto_if_eq SootopolisCity_House2_EventScript_DracoMeteorDeclined
# 36 "data/maps/SootopolisCity_House2/scripts.pory"
	goto SootopolisCity_House2_EventScript_DracoMeteorTaught
# 37 "data/maps/SootopolisCity_House2/scripts.pory"
	end
# 38 "data/maps/SootopolisCity_House2/scripts.pory"

# 39 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_EventScript_DracoMeteorDeclined::
# 40 "data/maps/SootopolisCity_House2/scripts.pory"
	setvar VAR_0x8008, FALSE
# 41 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_Text_DracoMeteorDeclined, MSGBOX_DEFAULT
# 42 "data/maps/SootopolisCity_House2/scripts.pory"
	release
# 43 "data/maps/SootopolisCity_House2/scripts.pory"
	end
# 44 "data/maps/SootopolisCity_House2/scripts.pory"

# 45 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_EventScript_OpenPartyMenu:: @ 82C8326
# 46 "data/maps/SootopolisCity_House2/scripts.pory"
	special ChooseMonForMoveTutor
# 47 "data/maps/SootopolisCity_House2/scripts.pory"
	waitstate
# 48 "data/maps/SootopolisCity_House2/scripts.pory"
	lock
# 49 "data/maps/SootopolisCity_House2/scripts.pory"
	faceplayer
# 50 "data/maps/SootopolisCity_House2/scripts.pory"
	return
# 51 "data/maps/SootopolisCity_House2/scripts.pory"

# 52 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_EventScript_DracoMeteorTaught::
# 53 "data/maps/SootopolisCity_House2/scripts.pory"
	setvar VAR_0x8008, FALSE
# 54 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_Text_DracoMeteorTaught, MSGBOX_DEFAULT
# 55 "data/maps/SootopolisCity_House2/scripts.pory"
	release
# 56 "data/maps/SootopolisCity_House2/scripts.pory"
	end
# 57 "data/maps/SootopolisCity_House2/scripts.pory"

# 58 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs: @ 8226AAB
# 59 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Mt. Pyre…\p"
# 60 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "At its peak are two orbs placed side\n"
# 61 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "by side. Did you know?$"
# 62 "data/maps/SootopolisCity_House2/scripts.pory"

# 63 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_Text_YesTwoOrbsSideBySide: @ 8226AF1
# 64 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Yes, two orbs side by side…\p"
# 65 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "The sight of them together…\n"
# 66 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "It is somehow soothing…$"
# 67 "data/maps/SootopolisCity_House2/scripts.pory"

# 68 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_Text_OughtToVisitAndSee: @ 8226B41
# 69 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Is that so?\n"
# 70 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Perhaps you ought to visit and see…$"
# 71 "data/maps/SootopolisCity_House2/scripts.pory"

# 72 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_Text_DracoMeteorTeach:
# 73 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "If you wish, I can teach your Pokémon\n"
# 74 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "the strongest Dragon-type move.\p"
# 75 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Would you like your Pokémon to learn\n"
# 76 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "that move?$"
# 77 "data/maps/SootopolisCity_House2/scripts.pory"

# 78 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_Text_DracoMeteorDeclined:
# 79 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Understood. Come again if you change\n"
# 80 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "your mind.$"
# 81 "data/maps/SootopolisCity_House2/scripts.pory"

# 82 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_Text_DracoMeteorWhichMon:
# 83 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Which Pokémon should learn this move?$"
# 84 "data/maps/SootopolisCity_House2/scripts.pory"

# 85 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_Text_DracoMeteorTaught:
# 86 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Draco Meteor's power is exceptional,\n"
# 87 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "but using it lowers the user's Sp. Atk.$"
