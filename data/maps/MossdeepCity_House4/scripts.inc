# 1 "data/maps/MossdeepCity_House4/scripts.pory"

# 2 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_MapScripts:: @ 8222DD7
# 3 "data/maps/MossdeepCity_House4/scripts.pory"
	.byte 0
# 4 "data/maps/MossdeepCity_House4/scripts.pory"

# 5 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_EventScript_Woman:: @ 8222DD8
# 6 "data/maps/MossdeepCity_House4/scripts.pory"
	lock
# 7 "data/maps/MossdeepCity_House4/scripts.pory"
	faceplayer
# 8 "data/maps/MossdeepCity_House4/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_House4_EventScript_CanBattleAtSecretBases
# 9 "data/maps/MossdeepCity_House4/scripts.pory"
	msgbox MossdeepCity_House4_Text_BrotherLikesToFindBases, MSGBOX_DEFAULT
# 10 "data/maps/MossdeepCity_House4/scripts.pory"
	release
# 11 "data/maps/MossdeepCity_House4/scripts.pory"
	end
# 12 "data/maps/MossdeepCity_House4/scripts.pory"

# 13 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_EventScript_CanBattleAtSecretBases:: @ 8222DED
# 14 "data/maps/MossdeepCity_House4/scripts.pory"
	msgbox MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle, MSGBOX_DEFAULT
# 15 "data/maps/MossdeepCity_House4/scripts.pory"
	release
# 16 "data/maps/MossdeepCity_House4/scripts.pory"
	end
# 17 "data/maps/MossdeepCity_House4/scripts.pory"

# 18 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_EventScript_NinjaBoy:: @ 8222DF7
# 19 "data/maps/MossdeepCity_House4/scripts.pory"
	lock
# 20 "data/maps/MossdeepCity_House4/scripts.pory"
	faceplayer
# 21 "data/maps/MossdeepCity_House4/scripts.pory"
	special CheckPlayerHasSecretBase
# 22 "data/maps/MossdeepCity_House4/scripts.pory"
	compare VAR_RESULT, FALSE
# 23 "data/maps/MossdeepCity_House4/scripts.pory"
	goto_if_eq MossdeepCity_House4_EventScript_NoSecretBase
# 24 "data/maps/MossdeepCity_House4/scripts.pory"
	special GetSecretBaseNearbyMapName
# 25 "data/maps/MossdeepCity_House4/scripts.pory"
	msgbox MossdeepCity_House4_Text_YouMadeSecretBaseNearX, MSGBOX_DEFAULT
# 26 "data/maps/MossdeepCity_House4/scripts.pory"
	release
# 27 "data/maps/MossdeepCity_House4/scripts.pory"
	end
# 28 "data/maps/MossdeepCity_House4/scripts.pory"

# 29 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_EventScript_NoSecretBase:: @ 8222E14
# 30 "data/maps/MossdeepCity_House4/scripts.pory"
	msgbox MossdeepCity_House4_Text_MakeSecretBase, MSGBOX_DEFAULT
# 31 "data/maps/MossdeepCity_House4/scripts.pory"
	release
# 32 "data/maps/MossdeepCity_House4/scripts.pory"
	end
# 33 "data/maps/MossdeepCity_House4/scripts.pory"

# 34 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_EventScript_Skitty:: @ 8222E1E
# 35 "data/maps/MossdeepCity_House4/scripts.pory"
	lock
# 36 "data/maps/MossdeepCity_House4/scripts.pory"
	faceplayer
# 37 "data/maps/MossdeepCity_House4/scripts.pory"
	waitse
# 38 "data/maps/MossdeepCity_House4/scripts.pory"
	playmoncry SPECIES_SKITTY, 0
# 39 "data/maps/MossdeepCity_House4/scripts.pory"
	msgbox MossdeepCity_House4_Text_Skitty, MSGBOX_DEFAULT
# 40 "data/maps/MossdeepCity_House4/scripts.pory"
	waitmoncry
# 41 "data/maps/MossdeepCity_House4/scripts.pory"
	release
# 42 "data/maps/MossdeepCity_House4/scripts.pory"
	end
# 43 "data/maps/MossdeepCity_House4/scripts.pory"

# 44 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_Text_BrotherLikesToFindBases: @ 8222E31
# 45 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "My little brother says he likes to go\n"
# 46 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "find people's Secret Bases.$"
# 47 "data/maps/MossdeepCity_House4/scripts.pory"

# 48 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle: @ 8222E73
# 49 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "My little brother says he likes to\n"
# 50 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "visit people's Secret Bases and have\l"
# 51 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "Pokémon battles.$"
# 52 "data/maps/MossdeepCity_House4/scripts.pory"

# 53 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_Text_YouMadeSecretBaseNearX: @ 8222ECC
# 54 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "Was it you who made a Secret Base\n"
# 55 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "near {STR_VAR_1}?$"
# 56 "data/maps/MossdeepCity_House4/scripts.pory"

# 57 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_Text_MakeSecretBase: @ 8222EF7
# 58 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "You should make a Secret Base\n"
# 59 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "somewhere. I'll go find it!$"
# 60 "data/maps/MossdeepCity_House4/scripts.pory"

# 61 "data/maps/MossdeepCity_House4/scripts.pory"
MossdeepCity_House4_Text_Skitty: @ 8222F31
# 62 "data/maps/MossdeepCity_House4/scripts.pory"
	.string "Skitty: Miyaan?$"
