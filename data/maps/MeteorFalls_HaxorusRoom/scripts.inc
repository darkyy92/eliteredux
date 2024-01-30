MeteorFalls_HaxorusRoom_MapScripts::
	.byte 0


MeteorFalls_HaxorusRoom_EventScript_Haxorus::
# 4 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	lock
# 5 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	faceplayer
# 6 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_HAXORUS, MeteorFalls_HaxorusRoom_EventScript_Haxorus_Join
# 7 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	playmoncry SPECIES_HAXORUS, 2
# 8 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	msgbox MeteorFalls_HaxorusRoom_EventScript_Haxorus_Text_0, MSGBOX_DEFAULT
# 9 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	delay 40
# 10 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	waitmoncry
# 11 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setflag FLAG_TOTEM_BATTLE
# 12 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setvar VAR_TOTEM_POKEMON_ATK_BOOST, 2
# 13 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setvar VAR_TOTEM_POKEMON_DEF_BOOST, 2
# 14 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setvar VAR_TOTEM_POKEMON_SP_ATK_BOOST, 2
# 15 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setvar VAR_TOTEM_POKEMON_SP_DEF_BOOST, 2
# 16 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setvar VAR_TOTEM_POKEMON_SPEED_BOOST, 1
# 17 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setvar VAR_TOTEM_POKEMON_ACCURACY_BOOST, 2
# 18 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setvar VAR_TOTEM_POKEMON_EVASION_BOOST, 0
# 19 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setvar VAR_TOTEM_MESSAGE, TOTEM_FIGHT_HAXORUS
# 20 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setflag FLAG_SHINY_CREATION
# 21 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setwildbattlewithcustommoves SPECIES_HAXORUS, 0, ITEM_HAXORUSITE, MOVE_DUAL_CHOP, MOVE_EXCALIBUR, MOVE_DRAIN_PUNCH, MOVE_TAUNT, 0, NATURE_ADAMANT, 252, 252, 252, 252, 252, 252
# 22 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 23 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	dowildbattle
# 24 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 25 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 26 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	switch VAR_RESULT
# 27 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	case B_OUTCOME_CAUGHT, MeteorFalls_HaxorusRoom_EventScript_Haxorus_3
# 28 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	case B_OUTCOME_WON, MeteorFalls_HaxorusRoom_EventScript_Haxorus_3
# 31 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	case B_OUTCOME_RAN, MeteorFalls_HaxorusRoom_EventScript_Haxorus_4
# 32 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, MeteorFalls_HaxorusRoom_EventScript_Haxorus_4
MeteorFalls_HaxorusRoom_EventScript_Haxorus_1:
# 41 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	release
	end

MeteorFalls_HaxorusRoom_EventScript_Haxorus_3:
# 29 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	goto MeteorFalls_HaxorusRoom_EventScript_Haxorus_Join
	goto MeteorFalls_HaxorusRoom_EventScript_Haxorus_1

MeteorFalls_HaxorusRoom_EventScript_Haxorus_4:
# 33 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setvar VAR_0x8004, SPECIES_HAXORUS
# 34 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 35 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	removeobject VAR_LAST_TALKED
# 36 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 37 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	bufferspeciesname 0, VAR_0x8004
# 38 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	msgbox MeteorFalls_HaxorusRoom_EventScript_Haxorus_Text_1, MSGBOX_DEFAULT
	goto MeteorFalls_HaxorusRoom_EventScript_Haxorus_1


MeteorFalls_HaxorusRoom_EventScript_Haxorus_Join::
# 46 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	msgbox MeteorFalls_HaxorusRoom_EventScript_Haxorus_Join_Text_0, MSGBOX_YESNO
# 47 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_Haxorus_Join_2
MeteorFalls_HaxorusRoom_EventScript_Haxorus_Join_1:
# 57 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	goto_if_unset FLAG_DEFEATED_METEOR_FALLS_HAXORUS, MeteorFalls_HaxorusRoom_EventScript_Haxorus_Join_5
MeteorFalls_HaxorusRoom_EventScript_Haxorus_Join_4:
# 64 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	release
	end

MeteorFalls_HaxorusRoom_EventScript_Haxorus_Join_2:
# 48 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setflag FLAG_OBTAINED_METEOR_FALLS_HAXORUS
# 49 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	givecustommon SPECIES_HAXORUS, 50, ITEM_NONE, ITEM_CHERISH_BALL, NATURE_ADAMANT, 0, 4, 252, 0, 252, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_DUAL_CHOP, MOVE_EXCALIBUR, MOVE_DRAIN_PUNCH, MOVE_TAUNT, TRUE
# 50 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 51 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	message MeteorFalls_HaxorusRoom_EventScript_Haxorus_Join_Text_1
# 52 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	waitfanfare
# 53 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 54 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	removeobject VAR_LAST_TALKED
# 55 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto MeteorFalls_HaxorusRoom_EventScript_Haxorus_Join_1

MeteorFalls_HaxorusRoom_EventScript_Haxorus_Join_5:
# 58 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setflag FLAG_DEFEATED_METEOR_FALLS_HAXORUS
# 59 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 60 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_HAXORUSITE, 1
# 61 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	message MeteorFalls_HaxorusRoom_EventScript_Haxorus_Join_Text_2
# 62 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	waitfanfare
	goto MeteorFalls_HaxorusRoom_EventScript_Haxorus_Join_4


MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest::
# 69 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	lock
# 70 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	msgbox MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_Text_0, MSGBOX_YESNO
# 71 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_2
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_1:
# 537 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	release
	end

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_2:
# 72 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_ABOMASITE, 1
# 73 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_5
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_4:
# 77 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_ABSOLITE, 1
# 78 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_8
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_7:
# 82 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_AERODACTYLITE, 1
# 83 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_11
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_10:
# 87 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_AGGRONITE, 1
# 88 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_14
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_13:
# 92 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_ALAKAZITE, 1
# 93 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_17
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_16:
# 97 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_ALTARIANITE, 1
# 98 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_20
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_19:
# 102 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_AMPHAROSITE, 1
# 103 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_23
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_22:
# 107 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_AUDINITE, 1
# 108 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_26
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_25:
# 112 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_BANETTITE, 1
# 113 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_29
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_28:
# 117 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_BEEDRILLITE, 1
# 118 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_32
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_31:
# 122 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_BLASTOISINITE, 1
# 123 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_35
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_34:
# 127 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_CAMERUPTITE, 1
# 128 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_38
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_37:
# 132 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_CHARIZARDITE_X, 1
# 133 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_41
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_40:
# 137 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_CHARIZARDITE_Y, 1
# 138 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_44
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_43:
# 142 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_DIANCITE, 1
# 143 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_47
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_46:
# 147 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_GALLADITE, 1
# 148 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_50
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_49:
# 152 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_GARCHOMPITE, 1
# 153 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_53
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_52:
# 157 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_GARDEVOIRITE, 1
# 158 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_56
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_55:
# 162 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_GENGARITE, 1
# 163 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_59
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_58:
# 167 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_GLALITITE, 1
# 168 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_62
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_61:
# 172 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_GYARADOSITE, 1
# 173 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_65
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_64:
# 177 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_HERACRONITE, 1
# 178 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_68
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_67:
# 182 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_HOUNDOOMINITE, 1
# 183 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_71
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_70:
# 187 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_KANGASKHANITE, 1
# 188 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_74
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_73:
# 192 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_LATIASITE, 1
# 193 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_77
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_76:
# 197 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_LATIOSITE, 1
# 198 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_80
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_79:
# 202 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_LOPUNNITE, 1
# 203 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_83
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_82:
# 207 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_LUCARIONITE, 1
# 208 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_86
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_85:
# 212 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_MANECTITE, 1
# 213 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_89
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_88:
# 217 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_MAWILITE, 1
# 218 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_92
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_91:
# 222 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_MEDICHAMITE, 1
# 223 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_95
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_94:
# 227 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_METAGROSSITE, 1
# 228 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_98
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_97:
# 232 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_MEWTWONITE_X, 1
# 233 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_101
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_100:
# 237 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_MEWTWONITE_Y, 1
# 238 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_104
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_103:
# 242 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_PIDGEOTITE, 1
# 243 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_107
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_106:
# 247 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_PINSIRITE, 1
# 248 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_110
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_109:
# 252 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_SABLENITE, 1
# 253 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_113
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_112:
# 257 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_SALAMENCITE, 1
# 258 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_116
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_115:
# 262 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_SCEPTILITE, 1
# 263 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_119
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_118:
# 267 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_SCIZORITE, 1
# 268 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_122
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_121:
# 272 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_SHARPEDONITE, 1
# 273 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_125
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_124:
# 277 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_SLOWBRONITE, 1
# 278 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_128
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_127:
# 282 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_STEELIXITE, 1
# 283 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_131
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_130:
# 287 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_SWAMPERTITE, 1
# 288 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_134
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_133:
# 292 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_TYRANITARITE, 1
# 293 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_137
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_136:
# 297 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_VENUSAURITE, 1
# 298 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_140
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_139:
# 302 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_MILOTICITE, 1
# 303 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_143
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_142:
# 307 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_RED_ORB, 1
# 308 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_146
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_145:
# 312 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_BLUE_ORB, 1
# 313 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_149
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_148:
# 317 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_FLYGONITE, 1
# 318 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_152
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_151:
# 322 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_BUTTERFRENITE, 1
# 323 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_155
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_154:
# 327 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_LAPRASITE_Y, 1
# 328 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_158
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_157:
# 332 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_MACHAMPITE, 1
# 333 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_161
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_160:
# 337 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_KINGLERITE, 1
# 338 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_164
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_163:
# 342 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_KINGDRANITE, 1
# 343 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_167
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_166:
# 347 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_DEWGONGITE, 1
# 348 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_170
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_169:
# 352 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_HITMONCHANITE, 1
# 353 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_173
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_172:
# 357 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_HITMONLEENITE, 1
# 358 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_176
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_175:
# 362 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_HITMONTOPITE, 1
# 363 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_179
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_178:
# 367 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_CROBATITE, 1
# 368 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_182
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_181:
# 372 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_SKARMORITE, 1
# 373 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_185
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_184:
# 377 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_BRUXISHITE, 1
# 378 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_188
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_187:
# 382 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_TORTERRANITE, 1
# 383 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_191
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_190:
# 387 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_INFERNAPENITE, 1
# 388 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_194
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_193:
# 392 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_EMPOLEONITE, 1
# 393 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_197
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_196:
# 397 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_SHUCKLENITE, 1
# 398 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_200
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_199:
# 402 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_RELICANTHITE, 1
# 403 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_203
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_202:
# 407 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_QUAGSIRENITE, 1
# 408 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_206
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_205:
# 412 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_JELLICENTITE, 1
# 413 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_209
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_208:
# 417 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_IRON_PILL, 1
# 418 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_212
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_211:
# 422 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_TOUCANNONITE, 1
# 423 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_215
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_214:
# 427 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_DRAGONITENITE, 1
# 428 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_218
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_217:
# 432 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_BRELOOMITE, 1
# 433 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_221
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_220:
# 437 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_SLAKINGITE, 1
# 438 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_224
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_223:
# 442 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_PURPLE_ORB, 1
# 443 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_227
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_226:
# 447 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_SLOWKINGITE, 1
# 448 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_230
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_229:
# 452 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_GYARADOSITE_Y, 1
# 453 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_233
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_232:
# 457 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_FERALIGATRITE_X, 1
# 458 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_236
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_235:
# 462 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_FERALIGATRITE_Y, 1
# 463 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_239
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_238:
# 467 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_HAXORUSITE, 1
# 468 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_242
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_241:
# 472 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_LUXRAYNITE, 1
# 473 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_245
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_244:
# 477 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_GRANBULLITE, 1
# 478 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_248
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_247:
# 482 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_TYPHLOSIONITE, 1
# 483 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_251
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_250:
# 487 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_NIDOQUEENITE, 1
# 488 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_254
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_253:
# 492 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_NIDOKINGITE, 1
# 493 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_257
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_256:
# 497 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_SANDSLASHITE, 1
# 498 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_260
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_259:
# 502 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_MEGANIUMITE, 1
# 503 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_263
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_262:
# 507 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_KROOKODILENITE, 1
# 508 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_266
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_265:
# 512 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_MAGNEZONITE, 1
# 513 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_269
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_268:
# 517 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_SHEDINJITE, 1
# 518 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_272
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_271:
# 522 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_SWALOTITE, 1
# 523 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_275
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_274:
# 527 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_LANTURNITE, 1
# 528 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_278
MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_277:
# 532 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	checkitem ITEM_LAPRASITE_X, 1
# 533 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_280
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_1

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_5:
# 74 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_ABOMASITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_4

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_8:
# 79 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_ABSOLITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_7

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_11:
# 84 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_AERODACTYLITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_10

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_14:
# 89 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_AGGRONITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_13

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_17:
# 94 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_ALAKAZITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_16

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_20:
# 99 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_ALTARIANITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_19

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_23:
# 104 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_AMPHAROSITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_22

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_26:
# 109 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_AUDINITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_25

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_29:
# 114 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_BANETTITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_28

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_32:
# 119 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_BEEDRILLITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_31

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_35:
# 124 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_BLASTOISINITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_34

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_38:
# 129 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_CAMERUPTITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_37

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_41:
# 134 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_CHARIZARDITE_X, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_40

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_44:
# 139 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_CHARIZARDITE_Y, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_43

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_47:
# 144 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_DIANCITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_46

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_50:
# 149 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_GALLADITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_49

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_53:
# 154 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_GARCHOMPITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_52

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_56:
# 159 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_GARDEVOIRITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_55

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_59:
# 164 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_GENGARITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_58

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_62:
# 169 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_GLALITITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_61

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_65:
# 174 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_GYARADOSITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_64

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_68:
# 179 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_HERACRONITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_67

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_71:
# 184 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_HOUNDOOMINITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_70

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_74:
# 189 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_KANGASKHANITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_73

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_77:
# 194 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_LATIASITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_76

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_80:
# 199 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_LATIOSITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_79

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_83:
# 204 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_LOPUNNITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_82

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_86:
# 209 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_LUCARIONITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_85

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_89:
# 214 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_MANECTITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_88

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_92:
# 219 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_MAWILITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_91

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_95:
# 224 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_MEDICHAMITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_94

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_98:
# 229 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_METAGROSSITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_97

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_101:
# 234 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_MEWTWONITE_X, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_100

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_104:
# 239 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_MEWTWONITE_Y, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_103

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_107:
# 244 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_PIDGEOTITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_106

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_110:
# 249 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_PINSIRITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_109

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_113:
# 254 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_SABLENITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_112

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_116:
# 259 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_SALAMENCITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_115

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_119:
# 264 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_SCEPTILITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_118

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_122:
# 269 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_SCIZORITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_121

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_125:
# 274 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_SHARPEDONITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_124

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_128:
# 279 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_SLOWBRONITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_127

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_131:
# 284 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_STEELIXITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_130

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_134:
# 289 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_SWAMPERTITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_133

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_137:
# 294 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_TYRANITARITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_136

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_140:
# 299 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_VENUSAURITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_139

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_143:
# 304 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_MILOTICITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_142

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_146:
# 309 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_RED_ORB, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_145

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_149:
# 314 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_BLUE_ORB, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_148

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_152:
# 319 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_FLYGONITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_151

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_155:
# 324 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_BUTTERFRENITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_154

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_158:
# 329 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_LAPRASITE_Y, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_157

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_161:
# 334 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_MACHAMPITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_160

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_164:
# 339 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_KINGLERITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_163

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_167:
# 344 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_KINGDRANITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_166

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_170:
# 349 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_DEWGONGITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_169

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_173:
# 354 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_HITMONCHANITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_172

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_176:
# 359 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_HITMONLEENITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_175

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_179:
# 364 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_HITMONTOPITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_178

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_182:
# 369 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_CROBATITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_181

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_185:
# 374 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_SKARMORITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_184

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_188:
# 379 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_BRUXISHITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_187

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_191:
# 384 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_TORTERRANITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_190

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_194:
# 389 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_INFERNAPENITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_193

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_197:
# 394 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_EMPOLEONITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_196

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_200:
# 399 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_SHUCKLENITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_199

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_203:
# 404 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_RELICANTHITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_202

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_206:
# 409 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_QUAGSIRENITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_205

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_209:
# 414 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_JELLICENTITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_208

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_212:
# 419 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_IRON_PILL, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_211

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_215:
# 424 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_TOUCANNONITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_214

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_218:
# 429 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_DRAGONITENITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_217

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_221:
# 434 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_BRELOOMITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_220

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_224:
# 439 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_SLAKINGITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_223

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_227:
# 444 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_PURPLE_ORB, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_226

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_230:
# 449 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_SLOWKINGITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_229

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_233:
# 454 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_GYARADOSITE_Y, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_232

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_236:
# 459 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_FERALIGATRITE_X, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_235

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_239:
# 464 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_FERALIGATRITE_Y, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_238

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_242:
# 469 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_HAXORUSITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_241

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_245:
# 474 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_LUXRAYNITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_244

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_248:
# 479 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_GRANBULLITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_247

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_251:
# 484 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_TYPHLOSIONITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_250

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_254:
# 489 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_NIDOQUEENITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_253

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_257:
# 494 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_NIDOKINGITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_256

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_260:
# 499 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_SANDSLASHITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_259

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_263:
# 504 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_MEGANIUMITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_262

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_266:
# 509 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_KROOKODILENITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_265

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_269:
# 514 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_MAGNEZONITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_268

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_272:
# 519 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_SHEDINJITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_271

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_275:
# 524 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_SWALOTITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_274

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_278:
# 529 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_LANTURNITE, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_277

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_280:
# 534 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	giveitem ITEM_LAPRASITE_X, 1
	goto MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_1


EventScript_ObtainedItem_PC::
# 542 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	bufferitemnameplural 1, VAR_0x8000, VAR_0x8001
# 543 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 544 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	message EventScript_ObtainedItem_PC_Text_0
# 545 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	waitmessage
# 546 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	waitfanfare
# 547 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setvar VAR_RESULT, 1
	return


EventScript_Debug_CheatStart::
# 552 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 553 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 554 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 555 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 556 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 557 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 558 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 559 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
	end


MeteorFalls_HaxorusRoom_EventScript_Haxorus_Text_0:
# 8 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	.string "Haxorus: Hax!$"

MeteorFalls_HaxorusRoom_EventScript_Haxorus_Text_1:
# 38 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	.string "The {STR_VAR_1} ran away!$"

MeteorFalls_HaxorusRoom_EventScript_Haxorus_Join_Text_0:
# 46 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	.string "Haxorus seems to want to join your\n"
	.string "team, will you let this Haxorus join you?$"

MeteorFalls_HaxorusRoom_EventScript_Haxorus_Join_Text_1:
# 51 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	.string "{PLAYER} received a Haxorus!$"

MeteorFalls_HaxorusRoom_EventScript_Haxorus_Join_Text_2:
# 61 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	.string "{PLAYER} received a Haxorusite!$"

MeteorFalls_HaxorusRoom_EventScript_MegaStoneTest_Text_0:
# 70 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	.string "Do you want to check all the mega\n"
	.string "stones?$"

EventScript_ObtainedItem_PC_Text_0:
# 544 "data/maps/MeteorFalls_HaxorusRoom/scripts.pory"
	.string "{PLAYER} obtained the\n"
	.string "{STR_VAR_2} and transferred it to\l"
	.string "the PC!$"
