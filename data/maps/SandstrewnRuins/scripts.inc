# 1 "data/maps/SandstrewnRuins/scripts.pory"

# 2 "data/maps/SandstrewnRuins/scripts.pory"
.set LOCALID_ODD_KEYSTONE, 18
# 3 "data/maps/SandstrewnRuins/scripts.pory"

# 4 "data/maps/SandstrewnRuins/scripts.pory"
SandstrewnRuins_MapScripts::
# 5 "data/maps/SandstrewnRuins/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SandstrewnRuins_OnLoad
# 6 "data/maps/SandstrewnRuins/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SandstrewnRuins_OnTransition
# 7 "data/maps/SandstrewnRuins/scripts.pory"
	.byte 0
# 8 "data/maps/SandstrewnRuins/scripts.pory"

# 9 "data/maps/SandstrewnRuins/scripts.pory"
SandstrewnRuins_OnTransition:
# 10 "data/maps/SandstrewnRuins/scripts.pory"
	setflag FLAG_LANDMARK_SANDSTREWN_RUINS
# 11 "data/maps/SandstrewnRuins/scripts.pory"
	end
# 12 "data/maps/SandstrewnRuins/scripts.pory"

# 13 "data/maps/SandstrewnRuins/scripts.pory"
SandstrewnRuins_OnLoad::
# 14 "data/maps/SandstrewnRuins/scripts.pory"
	goto_if_set FLAG_CHOSE_ROOT_FOSSIL, SandstrewnRuins_BlockMirageTower
# 15 "data/maps/SandstrewnRuins/scripts.pory"
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, SandstrewnRuins_BlockMirageTower
# 16 "data/maps/SandstrewnRuins/scripts.pory"
	setflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
# 17 "data/maps/SandstrewnRuins/scripts.pory"
	end
# 18 "data/maps/SandstrewnRuins/scripts.pory"

# 19 "data/maps/SandstrewnRuins/scripts.pory"
SandstrewnRuins_BlockMirageTower:: @ Block the entrances to room one
# 20 "data/maps/SandstrewnRuins/scripts.pory"
	setmetatile 11, 119, METATILE_MirageTower_Ledge, 1
# 21 "data/maps/SandstrewnRuins/scripts.pory"
	setmetatile 12, 119, METATILE_MirageTower_Ledge, 1
# 22 "data/maps/SandstrewnRuins/scripts.pory"
	setmetatile 13, 119, METATILE_MirageTower_Ledge, 1
# 23 "data/maps/SandstrewnRuins/scripts.pory"
	setmetatile 12, 118, METATILE_MirageTower_Floor, 0
# 24 "data/maps/SandstrewnRuins/scripts.pory"
	setmetatile 3, 105, METATILE_MirageTower_Ledge, 1
# 25 "data/maps/SandstrewnRuins/scripts.pory"
	setmetatile 4, 105, METATILE_MirageTower_Ledge, 1
# 26 "data/maps/SandstrewnRuins/scripts.pory"
	setmetatile 5, 105, METATILE_MirageTower_Ledge, 1
# 27 "data/maps/SandstrewnRuins/scripts.pory"
	setmetatile 4, 104, METATILE_MirageTower_Floor, 0
# 28 "data/maps/SandstrewnRuins/scripts.pory"
	end
# 29 "data/maps/SandstrewnRuins/scripts.pory"

# 30 "data/maps/SandstrewnRuins/scripts.pory"
Sandstrewn_Ruins_EventScript_OddKeystone::
# 31 "data/maps/SandstrewnRuins/scripts.pory"
	lock
# 32 "data/maps/SandstrewnRuins/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 33 "data/maps/SandstrewnRuins/scripts.pory"
	msgbox Sandstrewn_Ruins_Text_OddKeystone, MSGBOX_DEFAULT
# 34 "data/maps/SandstrewnRuins/scripts.pory"
	waitmessage
# 35 "data/maps/SandstrewnRuins/scripts.pory"
	waitfanfare
# 36 "data/maps/SandstrewnRuins/scripts.pory"
	additem ITEM_ODD_KEYSTONE, 1
# 37 "data/maps/SandstrewnRuins/scripts.pory"
	removeobject LOCALID_ODD_KEYSTONE
# 38 "data/maps/SandstrewnRuins/scripts.pory"
	release
# 39 "data/maps/SandstrewnRuins/scripts.pory"
	end
# 40 "data/maps/SandstrewnRuins/scripts.pory"

# 41 "data/maps/SandstrewnRuins/scripts.pory"
Sandstrewn_Ruins_Text_OddKeystone:
# 42 "data/maps/SandstrewnRuins/scripts.pory"
	.string "{PLAYER} found one Odd Keystone!\p"
# 43 "data/maps/SandstrewnRuins/scripts.pory"
	.string "There's a faint message scratched into\n"
# 44 "data/maps/SandstrewnRuins/scripts.pory"
	.string "the back of it…\p"
# 45 "data/maps/SandstrewnRuins/scripts.pory"
	.string "“Rou… 108”\n"
# 46 "data/maps/SandstrewnRuins/scripts.pory"
	.string "“Bring Poké… … 108”\l"
# 47 "data/maps/SandstrewnRuins/scripts.pory"
	.string "“Aband… …ip.”\l"
# 48 "data/maps/SandstrewnRuins/scripts.pory"
	.string "“Storage … …sh can.”\p"
# 49 "data/maps/SandstrewnRuins/scripts.pory"
	.string "{PLAYER} put away the Odd Keystone\n"
# 50 "data/maps/SandstrewnRuins/scripts.pory"
	.string "in the Key Items Pocket.$"
