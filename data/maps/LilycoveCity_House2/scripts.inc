# 1 "data/maps/LilycoveCity_House2/scripts.pory"

# 2 "data/maps/LilycoveCity_House2/scripts.pory"
LilycoveCity_House2_MapScripts:: @ 821ED74
# 3 "data/maps/LilycoveCity_House2/scripts.pory"
	.byte 0
# 4 "data/maps/LilycoveCity_House2/scripts.pory"

# 5 "data/maps/LilycoveCity_House2/scripts.pory"
LilycoveCity_House2_EventScript_FatMan:: @ 821ED75
# 6 "data/maps/LilycoveCity_House2/scripts.pory"
	lock
# 7 "data/maps/LilycoveCity_House2/scripts.pory"
	faceplayer
# 8 "data/maps/LilycoveCity_House2/scripts.pory"
	msgbox LilycoveCity_House2_Text_SleepIsEssential, MSGBOX_DEFAULT
# 9 "data/maps/LilycoveCity_House2/scripts.pory"
	release
# 10 "data/maps/LilycoveCity_House2/scripts.pory"
	end
# 11 "data/maps/LilycoveCity_House2/scripts.pory"

# 12 "data/maps/LilycoveCity_House2/scripts.pory"
LilycoveCity_House2_EventScript_ReceivedRest:: @ 821EDAC
# 13 "data/maps/LilycoveCity_House2/scripts.pory"
	msgbox LilycoveCity_House2_Text_SleepIsEssential, MSGBOX_DEFAULT
# 14 "data/maps/LilycoveCity_House2/scripts.pory"
	release
# 15 "data/maps/LilycoveCity_House2/scripts.pory"
	end
# 16 "data/maps/LilycoveCity_House2/scripts.pory"

# 17 "data/maps/LilycoveCity_House2/scripts.pory"
LilycoveCity_House2_Text_NotAwakeYetHaveThis: @ 821EDB6
# 18 "data/maps/LilycoveCity_House2/scripts.pory"
	.string "Huh? What? What's that?\p"
# 19 "data/maps/LilycoveCity_House2/scripts.pory"
	.string "I'm not near awake yet…\n"
# 20 "data/maps/LilycoveCity_House2/scripts.pory"
	.string "You can have this…$"
# 21 "data/maps/LilycoveCity_House2/scripts.pory"

# 22 "data/maps/LilycoveCity_House2/scripts.pory"
LilycoveCity_House2_Text_SleepIsEssential: @ 821EDF9
# 23 "data/maps/LilycoveCity_House2/scripts.pory"
	.string "Yawn…\p"
# 24 "data/maps/LilycoveCity_House2/scripts.pory"
	.string "Sleep is essential for good health…\n"
# 25 "data/maps/LilycoveCity_House2/scripts.pory"
	.string "Sleep and regain health…$"
