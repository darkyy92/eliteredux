# 1 "data/maps/PacifidlogTown_House2/scripts.pory"

# 2 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_MapScripts::
# 3 "data/maps/PacifidlogTown_House2/scripts.pory"
	.byte 0
# 4 "data/maps/PacifidlogTown_House2/scripts.pory"

# 5 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
# 6 "data/maps/PacifidlogTown_House2/scripts.pory"
	lock
# 7 "data/maps/PacifidlogTown_House2/scripts.pory"
	faceplayer
# 8 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
# 9 "data/maps/PacifidlogTown_House2/scripts.pory"
	releaseall
# 10 "data/maps/PacifidlogTown_House2/scripts.pory"
	end
# 11 "data/maps/PacifidlogTown_House2/scripts.pory"

# 12 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_EventScript_GiveDiancite::
# 13 "data/maps/PacifidlogTown_House2/scripts.pory"
	playse SE_PIN
# 14 "data/maps/PacifidlogTown_House2/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 15 "data/maps/PacifidlogTown_House2/scripts.pory"
	waitmovement 0
# 16 "data/maps/PacifidlogTown_House2/scripts.pory"
	applymovement 1, Common_Movement_Delay48
# 17 "data/maps/PacifidlogTown_House2/scripts.pory"
	waitmovement 0
# 18 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_DiancieLikesYou, MSGBOX_DEFAULT
# 19 "data/maps/PacifidlogTown_House2/scripts.pory"
	giveitem ITEM_DIANCITE
# 20 "data/maps/PacifidlogTown_House2/scripts.pory"
	compare VAR_RESULT, FALSE
# 21 "data/maps/PacifidlogTown_House2/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 22 "data/maps/PacifidlogTown_House2/scripts.pory"
	setflag FLAG_RECEIVED_DIANCITE
# 23 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_EventScript_HaveDiancite::
# 24 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_ExplainDiancite, MSGBOX_DEFAULT
# 25 "data/maps/PacifidlogTown_House2/scripts.pory"
	release
# 26 "data/maps/PacifidlogTown_House2/scripts.pory"
	end
# 27 "data/maps/PacifidlogTown_House2/scripts.pory"

# 28 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_FanClubYoungerBrotherIntro::
# 29 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
# 30 "data/maps/PacifidlogTown_House2/scripts.pory"
	return
# 31 "data/maps/PacifidlogTown_House2/scripts.pory"

# 32 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_FanClubYoungerBrotherStrongBond::
# 33 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_StrongBond, MSGBOX_DEFAULT
# 34 "data/maps/PacifidlogTown_House2/scripts.pory"
	return
# 35 "data/maps/PacifidlogTown_House2/scripts.pory"

# 36 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_EventScript_HappyAzurill::
# 37 "data/maps/PacifidlogTown_House2/scripts.pory"
	lock
# 38 "data/maps/PacifidlogTown_House2/scripts.pory"
	faceplayer
# 39 "data/maps/PacifidlogTown_House2/scripts.pory"
	waitse
# 40 "data/maps/PacifidlogTown_House2/scripts.pory"
	playmoncry SPECIES_AZURILL, 0
# 41 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
# 42 "data/maps/PacifidlogTown_House2/scripts.pory"
	waitmoncry
# 43 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
# 44 "data/maps/PacifidlogTown_House2/scripts.pory"
	release
# 45 "data/maps/PacifidlogTown_House2/scripts.pory"
	end
# 46 "data/maps/PacifidlogTown_House2/scripts.pory"

# 47 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_EventScript_UnhappyAzurill::
# 48 "data/maps/PacifidlogTown_House2/scripts.pory"
	lock
# 49 "data/maps/PacifidlogTown_House2/scripts.pory"
	faceplayer
# 50 "data/maps/PacifidlogTown_House2/scripts.pory"
	waitse
# 51 "data/maps/PacifidlogTown_House2/scripts.pory"
	playmoncry SPECIES_AZURILL, 2
# 52 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
# 53 "data/maps/PacifidlogTown_House2/scripts.pory"
	waitmoncry
# 54 "data/maps/PacifidlogTown_House2/scripts.pory"
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
# 55 "data/maps/PacifidlogTown_House2/scripts.pory"
	release
# 56 "data/maps/PacifidlogTown_House2/scripts.pory"
	end
# 57 "data/maps/PacifidlogTown_House2/scripts.pory"

# 58 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
# 59 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "Er-hem!\p"
# 60 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "I am the Pokémon Fan Club's most\n"
# 61 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "important person, the Chairman's\l"
# 62 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "younger brother.\p"
# 63 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "I'm here enjoying my vacation with\n"
# 64 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "Pokémon, yes, indeed.\p"
# 65 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "Have a great day!$"
# 66 "data/maps/PacifidlogTown_House2/scripts.pory"

# 67 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_AlasNotYou:
# 68 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "But alas, it seems you are not that\n"
# 69 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "Trainer…$"
# 70 "data/maps/PacifidlogTown_House2/scripts.pory"

# 71 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_DiancieLikesYou:
# 72 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "Oho! That's a Diancie you have with you!\p"
# 73 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "And it seems to like you very much.\n"
# 74 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "You are worthy of this Mega Stone.\n"
# 75 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "Please take it!$"
# 76 "data/maps/PacifidlogTown_House2/scripts.pory"

# 77 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_ExplainDiancite:
# 78 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "If you let Diancie hold that stone, it\n"
# 79 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "will be able to Mega Evolve in battle.$"
# 80 "data/maps/PacifidlogTown_House2/scripts.pory"

# 81 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_StrongBond:
# 82 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "Er-hem!\p"
# 83 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "I will only give this stone to a\n"
# 84 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "Trainer who has a strong bond with\l"
# 85 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "a certain Mythical Pokémon.$"
# 86 "data/maps/PacifidlogTown_House2/scripts.pory"

# 87 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_Rurii: @ 8203B8D
# 88 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "Azurill: Rurii.$"
# 89 "data/maps/PacifidlogTown_House2/scripts.pory"

# 90 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_VeryFriendlyWithTrainer: @ 8203B9D
# 91 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "It appears to be very friendly with the\n"
# 92 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "Trainer.$"
# 93 "data/maps/PacifidlogTown_House2/scripts.pory"

# 94 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_Rururi: @ 8203BCE
# 95 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "Azurill: Rururi!$"
# 96 "data/maps/PacifidlogTown_House2/scripts.pory"

# 97 "data/maps/PacifidlogTown_House2/scripts.pory"
PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch: @ 8203BDF
# 98 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "It doesn't appear to like the Trainer\n"
# 99 "data/maps/PacifidlogTown_House2/scripts.pory"
	.string "very much.$"
