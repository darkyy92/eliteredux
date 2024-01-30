# 1 "data/maps/SootopolisCity_House3/scripts.pory"

# 2 "data/maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_MapScripts:: @ 8226B71
# 3 "data/maps/SootopolisCity_House3/scripts.pory"
	.byte 0
# 4 "data/maps/SootopolisCity_House3/scripts.pory"

# 5 "data/maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_Woman:: @ 8226B72
# 6 "data/maps/SootopolisCity_House3/scripts.pory"
	lock
# 7 "data/maps/SootopolisCity_House3/scripts.pory"
	faceplayer
# 8 "data/maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
# 9 "data/maps/SootopolisCity_House3/scripts.pory"
	compare VAR_RESULT, YES
# 10 "data/maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq SootopolisCity_House3_EventScript_HaveFans
# 11 "data/maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
# 12 "data/maps/SootopolisCity_House3/scripts.pory"
	release
# 13 "data/maps/SootopolisCity_House3/scripts.pory"
	end
# 14 "data/maps/SootopolisCity_House3/scripts.pory"

# 15 "data/maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_HaveFans:: @ 8226B91
# 16 "data/maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
# 17 "data/maps/SootopolisCity_House3/scripts.pory"
	release
# 18 "data/maps/SootopolisCity_House3/scripts.pory"
	end
# 19 "data/maps/SootopolisCity_House3/scripts.pory"

# 20 "data/maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_Girl:: @ 8226B9B
# 21 "data/maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
# 22 "data/maps/SootopolisCity_House3/scripts.pory"
	end
# 23 "data/maps/SootopolisCity_House3/scripts.pory"

# 24 "data/maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_JuanHasManyFansDoYou: @ 8226BA4
# 25 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "You're a Pokémon Trainer, aren't you?\p"
# 26 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "Sootopolis's Juan has many fans.\n"
# 27 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "Even more than his student Wallace!\p"
# 28 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "Do you have any?$"
# 29 "data/maps/SootopolisCity_House3/scripts.pory"

# 30 "data/maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_YouMustBePrettyStrong: @ 8226C20
# 31 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "Oh, then you must be pretty strong.$"
# 32 "data/maps/SootopolisCity_House3/scripts.pory"

# 33 "data/maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_LonesomeTryWorkingHarder: @ 8226C44
# 34 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "Oh, dear…\n"
# 35 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "That's a little lonesome.\p"
# 36 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "Try working a little harder to get\n"
# 37 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "a fan following.$"
# 38 "data/maps/SootopolisCity_House3/scripts.pory"

# 39 "data/maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_TrainerFanClubWasWild: @ 8226C9C
# 40 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "Dedicated fans come over from even\n"
# 41 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "outside of Hoenn.\p"
# 42 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "It was really wild when I went to the\n"
# 43 "data/maps/SootopolisCity_House3/scripts.pory"
	.string "Trainer Fan Club in Lilycove.$"
