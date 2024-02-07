# 1 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 4 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_MapScripts:: @ 82079E8
# 5 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
# 6 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 7 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.byte 0
# 8 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 9 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_OnTransition: @ 82079F3
# 10 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_PETALBURG_CITY
# 11 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_UpdateBrineyLocation
# 12 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 13 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 14 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_Nurse:: @ 82079FC
# 15 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 16 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 17 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 18 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 19 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
# 20 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 21 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 22 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_FatMan:: @ 8207A0A
# 23 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
# 24 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 25 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 26 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_Youngster:: @ 8207A13
# 27 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
# 28 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 29 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 30 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_Woman:: @ 8207A1C
# 31 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	lock
# 32 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 33 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
# 34 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, IsStarterInParty
# 35 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
# 36 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
# 37 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
# 38 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 39 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 40 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo:: @ 8207A38
# 41 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	compare VAR_STARTER_MON, 0
# 42 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
# 43 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	compare VAR_STARTER_MON, 1
# 44 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
# 45 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	compare VAR_STARTER_MON, 2
# 46 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
# 47 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
# 48 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 49 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 50 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType:: @ 8207A5B
# 51 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
# 52 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	return
# 53 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 54 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType:: @ 8207A64
# 55 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
# 56 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	return
# 57 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 58 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType:: @ 8207A6D
# 59 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
# 60 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	return
# 61 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 62 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem: @ 8207A76
# 63 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "That PC-based Pokémon Storage\n"
# 64 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "System…\p"
# 65 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Whoever made it must be some kind\n"
# 66 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "of a scientific wizard!$"
# 67 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 68 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP: @ 8207AD6
# 69 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "When my Pokémon ate an\n"
# 70 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Oran Berry, it regained HP!$"
# 71 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 72 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon: @ 8207B09
# 73 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "There are many types of Pokémon.\p"
# 74 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "All types have their strengths and\n"
# 75 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "weaknesses against other types.\p"
# 76 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Depending on the types of Pokémon,\n"
# 77 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "a battle could be easy or hard.$"
# 78 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 79 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType: @ 8207BB0
# 80 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "For example, your starter Pokémon\n"
# 81 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "is a Grass type.\p"
# 82 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "It's strong against the Water and\n"
# 83 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Ground types.\p"
# 84 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "But, it's weak against Fire-type\n"
# 85 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Pokémon.$"
# 86 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 87 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType: @ 8207C35
# 88 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "For example, your starter Pokémon\n"
# 89 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "is a Fire type.\p"
# 90 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "It's strong against the Grass and\n"
# 91 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Bug types.\p"
# 92 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "But, it's weak against Water-type\n"
# 93 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Pokémon.$"
# 94 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 95 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType: @ 8207CB7
# 96 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "For example, your starter Pokémon\n"
# 97 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "is a Water type.\p"
# 98 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "It's strong against the Fire type.\p"
# 99 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "But, it's weak against Grass-type\n"
# 100 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "and Electric-type Pokémon.$"
