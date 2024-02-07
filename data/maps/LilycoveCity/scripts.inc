# 1 "data/maps/LilycoveCity/scripts.pory"

# 2 "data/maps/LilycoveCity/scripts.pory"
.set LOCALID_WOMAN_1, 18
# 3 "data/maps/LilycoveCity/scripts.pory"
.set LOCALID_MAN_1, 19
# 4 "data/maps/LilycoveCity/scripts.pory"

# 5 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_MapScripts:: @ 81E2B3C
# 6 "data/maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
# 7 "data/maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
# 8 "data/maps/LilycoveCity/scripts.pory"
	.byte 0
# 9 "data/maps/LilycoveCity/scripts.pory"

# 10 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_OnTransition: @ 81E2B47
# 11 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_VISITED_LILYCOVE_CITY
# 12 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 13 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
# 14 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 15 "data/maps/LilycoveCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 16 "data/maps/LilycoveCity/scripts.pory"
	end
# 17 "data/maps/LilycoveCity/scripts.pory"

# 18 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_OnLoad: @ 81E2B61
# 19 "data/maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
# 20 "data/maps/LilycoveCity/scripts.pory"
	end
# 21 "data/maps/LilycoveCity/scripts.pory"

# 22 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SetWailmerMetatiles:: @ 81E2B6B
# 23 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, 1
# 24 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, 1
# 25 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, 1
# 26 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, 1
# 27 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, 1
# 28 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, 1
# 29 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, 1
# 30 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, 1
# 31 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, 1
# 32 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, 1
# 33 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, 1
# 34 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, 1
# 35 "data/maps/LilycoveCity/scripts.pory"
	return
# 36 "data/maps/LilycoveCity/scripts.pory"

# 37 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BerryGentleman:: @ 81E2BD8
# 38 "data/maps/LilycoveCity/scripts.pory"
	lock
# 39 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 40 "data/maps/LilycoveCity/scripts.pory"
	dotimebasedevents
# 41 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
# 42 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
# 43 "data/maps/LilycoveCity/scripts.pory"
	random 10
# 44 "data/maps/LilycoveCity/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 45 "data/maps/LilycoveCity/scripts.pory"
	giveitem VAR_RESULT
# 46 "data/maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, FALSE
# 47 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 48 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
# 49 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
# 50 "data/maps/LilycoveCity/scripts.pory"
	release
# 51 "data/maps/LilycoveCity/scripts.pory"
	end
# 52 "data/maps/LilycoveCity/scripts.pory"

# 53 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ReceivedBerry:: @ 81E2C18
# 54 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
# 55 "data/maps/LilycoveCity/scripts.pory"
	release
# 56 "data/maps/LilycoveCity/scripts.pory"
	end
# 57 "data/maps/LilycoveCity/scripts.pory"

# 58 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man3:: @ 81E2C22
# 59 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
# 60 "data/maps/LilycoveCity/scripts.pory"
	end
# 61 "data/maps/LilycoveCity/scripts.pory"

# 62 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Girl:: @ 81E2C2B
# 63 "data/maps/LilycoveCity/scripts.pory"
	lock
# 64 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 65 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
# 66 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
# 67 "data/maps/LilycoveCity/scripts.pory"
	release
# 68 "data/maps/LilycoveCity/scripts.pory"
	end
# 69 "data/maps/LilycoveCity/scripts.pory"

# 70 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_GirlAquaGone:: @ 81E2C40
# 71 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
# 72 "data/maps/LilycoveCity/scripts.pory"
	release
# 73 "data/maps/LilycoveCity/scripts.pory"
	end
# 74 "data/maps/LilycoveCity/scripts.pory"

# 75 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RichBoy:: @ 81E2C4A
# 76 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
# 77 "data/maps/LilycoveCity/scripts.pory"
	end
# 78 "data/maps/LilycoveCity/scripts.pory"

# 79 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2:: @ 81E2C53
# 80 "data/maps/LilycoveCity/scripts.pory"
	lock
# 81 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 82 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
# 83 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
# 84 "data/maps/LilycoveCity/scripts.pory"
	release
# 85 "data/maps/LilycoveCity/scripts.pory"
	end
# 86 "data/maps/LilycoveCity/scripts.pory"

# 87 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2AquaGone:: @ 81E2C68
# 88 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
# 89 "data/maps/LilycoveCity/scripts.pory"
	release
# 90 "data/maps/LilycoveCity/scripts.pory"
	end
# 91 "data/maps/LilycoveCity/scripts.pory"

# 92 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2:: @ 81E2C72
# 93 "data/maps/LilycoveCity/scripts.pory"
	lock
# 94 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 95 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
# 96 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
# 97 "data/maps/LilycoveCity/scripts.pory"
	release
# 98 "data/maps/LilycoveCity/scripts.pory"
	end
# 99 "data/maps/LilycoveCity/scripts.pory"

# 100 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2AquaGone:: @ 81E2C87
# 101 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
# 102 "data/maps/LilycoveCity/scripts.pory"
	release
# 103 "data/maps/LilycoveCity/scripts.pory"
	end
# 104 "data/maps/LilycoveCity/scripts.pory"

# 105 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man2:: @ 81E2C91
# 106 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
# 107 "data/maps/LilycoveCity/scripts.pory"
	end
# 108 "data/maps/LilycoveCity/scripts.pory"

# 109 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM1:: @ 81E2C9A
# 110 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
# 111 "data/maps/LilycoveCity/scripts.pory"
	end
# 112 "data/maps/LilycoveCity/scripts.pory"

# 113 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertF:: @ 81E2CA3
# 114 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
# 115 "data/maps/LilycoveCity/scripts.pory"
	end
# 116 "data/maps/LilycoveCity/scripts.pory"

# 117 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2:: @ 81E2CAC
# 118 "data/maps/LilycoveCity/scripts.pory"
	lock
# 119 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 120 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
# 121 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
# 122 "data/maps/LilycoveCity/scripts.pory"
	release
# 123 "data/maps/LilycoveCity/scripts.pory"
	end
# 124 "data/maps/LilycoveCity/scripts.pory"

# 125 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2AquaGone:: @ 81E2CC1
# 126 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
# 127 "data/maps/LilycoveCity/scripts.pory"
	release
# 128 "data/maps/LilycoveCity/scripts.pory"
	end
# 129 "data/maps/LilycoveCity/scripts.pory"

# 130 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor1:: @ 81E2CCB
# 131 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
# 132 "data/maps/LilycoveCity/scripts.pory"
	end
# 133 "data/maps/LilycoveCity/scripts.pory"

# 134 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_FatMan:: @ 81E2CD4
# 135 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
# 136 "data/maps/LilycoveCity/scripts.pory"
	end
# 137 "data/maps/LilycoveCity/scripts.pory"

# 138 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man1:: @ 81E2CDD
# 139 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 140 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
# 141 "data/maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_MAN_1, Common_Movement_FaceOriginalDirection
# 142 "data/maps/LilycoveCity/scripts.pory"
	end
# 143 "data/maps/LilycoveCity/scripts.pory"

# 144 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman1:: @ 81E2CEE
# 145 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 146 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
# 147 "data/maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
# 148 "data/maps/LilycoveCity/scripts.pory"
	end
# 149 "data/maps/LilycoveCity/scripts.pory"

# 150 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CitySign:: @ 81E2CFF
# 151 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
# 152 "data/maps/LilycoveCity/scripts.pory"
	end
# 153 "data/maps/LilycoveCity/scripts.pory"

# 154 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ContestHallSign:: @ 81E2D08
# 155 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
# 156 "data/maps/LilycoveCity/scripts.pory"
	end
# 157 "data/maps/LilycoveCity/scripts.pory"

# 158 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MotelSign:: @ 81E2D11
# 159 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
# 160 "data/maps/LilycoveCity/scripts.pory"
	end
# 161 "data/maps/LilycoveCity/scripts.pory"

# 162 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSign:: @ 81E2D1A
# 163 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 164 "data/maps/LilycoveCity/scripts.pory"
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
# 165 "data/maps/LilycoveCity/scripts.pory"
	switch VAR_0x8004
# 166 "data/maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
# 167 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
# 168 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 169 "data/maps/LilycoveCity/scripts.pory"
	end
# 170 "data/maps/LilycoveCity/scripts.pory"

# 171 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSignNoPaintings:: @ 81E2D3A
# 172 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
# 173 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 174 "data/maps/LilycoveCity/scripts.pory"
	end
# 175 "data/maps/LilycoveCity/scripts.pory"

# 176 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSign:: @ 81E2D44
# 177 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 178 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
# 179 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
# 180 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 181 "data/maps/LilycoveCity/scripts.pory"
	end
# 182 "data/maps/LilycoveCity/scripts.pory"

# 183 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSignFerryReady:: @ 81E2D58
# 184 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
# 185 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 186 "data/maps/LilycoveCity/scripts.pory"
	end
# 187 "data/maps/LilycoveCity/scripts.pory"

# 188 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_TrainerFanClubSign:: @ 81E2D62
# 189 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
# 190 "data/maps/LilycoveCity/scripts.pory"
	end
# 191 "data/maps/LilycoveCity/scripts.pory"

# 192 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DepartmentStoreSign:: @ 81E2D6B
# 193 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
# 194 "data/maps/LilycoveCity/scripts.pory"
	end
# 195 "data/maps/LilycoveCity/scripts.pory"

# 196 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BallSwappersHouseSign::
# 197 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BallSwappersHouseSign, MSGBOX_SIGN
# 198 "data/maps/LilycoveCity/scripts.pory"
	end
# 199 "data/maps/LilycoveCity/scripts.pory"

# 200 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_WailmerTrainerGrunt:: @ 81E2D7D
# 201 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 202 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
# 203 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 204 "data/maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 205 "data/maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 206 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
# 207 "data/maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 208 "data/maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 209 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_WAILMER_TRAINER
# 210 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 211 "data/maps/LilycoveCity/scripts.pory"
	end
# 212 "data/maps/LilycoveCity/scripts.pory"

# 213 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MetWailmerTrainer:: @ 81E2DB0
# 214 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 215 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 216 "data/maps/LilycoveCity/scripts.pory"
	end
# 217 "data/maps/LilycoveCity/scripts.pory"

# 218 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt1:: @ 81E2DBA
# 219 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
# 220 "data/maps/LilycoveCity/scripts.pory"
	end
# 221 "data/maps/LilycoveCity/scripts.pory"

# 222 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt2:: @ 81E2DC3
# 223 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
# 224 "data/maps/LilycoveCity/scripts.pory"
	end
# 225 "data/maps/LilycoveCity/scripts.pory"

# 226 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt3:: @ 81E2DCC
# 227 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
# 228 "data/maps/LilycoveCity/scripts.pory"
	end
# 229 "data/maps/LilycoveCity/scripts.pory"

# 230 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt4:: @ 81E2DD5
# 231 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
# 232 "data/maps/LilycoveCity/scripts.pory"
	end
# 233 "data/maps/LilycoveCity/scripts.pory"

# 234 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Rival:: @ 81E2DDE
# 235 "data/maps/LilycoveCity/scripts.pory"
	lock
# 236 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 237 "data/maps/LilycoveCity/scripts.pory"
	checkplayergender
# 238 "data/maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, MALE
# 239 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq LilycoveCity_EventScript_May
# 240 "data/maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, FEMALE
# 241 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq LilycoveCity_EventScript_Brendan
# 242 "data/maps/LilycoveCity/scripts.pory"
	end
# 243 "data/maps/LilycoveCity/scripts.pory"

# 244 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_May:: @ 81E2DF8
# 245 "data/maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 246 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
# 247 "data/maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
# 248 "data/maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, NO
# 249 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq LilycoveCity_EventScript_DeclineMayBattle
# 250 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
# 251 "data/maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 252 "data/maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_BattleMayTreecko
# 253 "data/maps/LilycoveCity/scripts.pory"
	case 1, LilycoveCity_EventScript_BattleMayTorchic
# 254 "data/maps/LilycoveCity/scripts.pory"
	case 2, LilycoveCity_EventScript_BattleMayMudkip
# 255 "data/maps/LilycoveCity/scripts.pory"
	end
# 256 "data/maps/LilycoveCity/scripts.pory"

# 257 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattleAgain:: @ 81E2E48
# 258 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
# 259 "data/maps/LilycoveCity/scripts.pory"
	return
# 260 "data/maps/LilycoveCity/scripts.pory"

# 261 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattle:: @ 81E2E51
# 262 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
# 263 "data/maps/LilycoveCity/scripts.pory"
	return
# 264 "data/maps/LilycoveCity/scripts.pory"

# 265 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineMayBattle:: @ 81E2E5A
# 266 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 267 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
# 268 "data/maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 269 "data/maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 270 "data/maps/LilycoveCity/scripts.pory"
	release
# 271 "data/maps/LilycoveCity/scripts.pory"
	end
# 272 "data/maps/LilycoveCity/scripts.pory"

# 273 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Brendan:: @ 81E2E6B
# 274 "data/maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 275 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
# 276 "data/maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
# 277 "data/maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, NO
# 278 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq LilycoveCity_EventScript_DeclineBrendanBattle
# 279 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
# 280 "data/maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 281 "data/maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
# 282 "data/maps/LilycoveCity/scripts.pory"
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
# 283 "data/maps/LilycoveCity/scripts.pory"
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
# 284 "data/maps/LilycoveCity/scripts.pory"
	end
# 285 "data/maps/LilycoveCity/scripts.pory"

# 286 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattleAgain:: @ 81E2EBB
# 287 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
# 288 "data/maps/LilycoveCity/scripts.pory"
	return
# 289 "data/maps/LilycoveCity/scripts.pory"

# 290 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattle:: @ 81E2EC4
# 291 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
# 292 "data/maps/LilycoveCity/scripts.pory"
	return
# 293 "data/maps/LilycoveCity/scripts.pory"

# 294 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineBrendanBattle:: @ 81E2ECD
# 295 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 296 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 297 "data/maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 298 "data/maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 299 "data/maps/LilycoveCity/scripts.pory"
	release
# 300 "data/maps/LilycoveCity/scripts.pory"
	end
# 301 "data/maps/LilycoveCity/scripts.pory"

# 302 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayTreecko:: @ 81E2EDE
# 303 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
# 304 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 305 "data/maps/LilycoveCity/scripts.pory"
	end
# 306 "data/maps/LilycoveCity/scripts.pory"

# 307 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayTorchic:: @ 81E2EEE
# 308 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
# 309 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 310 "data/maps/LilycoveCity/scripts.pory"
	end
# 311 "data/maps/LilycoveCity/scripts.pory"

# 312 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayMudkip:: @ 81E2EFE
# 313 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
# 314 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 315 "data/maps/LilycoveCity/scripts.pory"
	end
# 316 "data/maps/LilycoveCity/scripts.pory"

# 317 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanTreecko:: @ 81E2F0E
# 318 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
# 319 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 320 "data/maps/LilycoveCity/scripts.pory"
	end
# 321 "data/maps/LilycoveCity/scripts.pory"

# 322 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanTorchic:: @ 81E2F1E
# 323 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
# 324 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 325 "data/maps/LilycoveCity/scripts.pory"
	end
# 326 "data/maps/LilycoveCity/scripts.pory"

# 327 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanMudkip:: @ 81E2F2E
# 328 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
# 329 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 330 "data/maps/LilycoveCity/scripts.pory"
	end
# 331 "data/maps/LilycoveCity/scripts.pory"

# 332 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedMay:: @ 81E2F3E
# 333 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
# 334 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 335 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 336 "data/maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, FALSE
# 337 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq LilycoveCity_EventScript_MayCollectBadges
# 338 "data/maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, TRUE
# 339 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq LilycoveCity_EventScript_MayPokemonLeague
# 340 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 341 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
# 342 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 343 "data/maps/LilycoveCity/scripts.pory"
	end
# 344 "data/maps/LilycoveCity/scripts.pory"

# 345 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CheckFinalBadge:: @ 81E2F76
# 346 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
# 347 "data/maps/LilycoveCity/scripts.pory"
	return
# 348 "data/maps/LilycoveCity/scripts.pory"

# 349 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HasFinalBadge:: @ 81E2F80
# 350 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, TRUE
# 351 "data/maps/LilycoveCity/scripts.pory"
	return
# 352 "data/maps/LilycoveCity/scripts.pory"

# 353 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayCollectBadges:: @ 81E2F86
# 354 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
# 355 "data/maps/LilycoveCity/scripts.pory"
	return
# 356 "data/maps/LilycoveCity/scripts.pory"

# 357 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayPokemonLeague:: @ 81E2F8F
# 358 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
# 359 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 360 "data/maps/LilycoveCity/scripts.pory"
	return
# 361 "data/maps/LilycoveCity/scripts.pory"

# 362 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayBattleFrontier:: @ 81E2FA1
# 363 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 364 "data/maps/LilycoveCity/scripts.pory"
	return
# 365 "data/maps/LilycoveCity/scripts.pory"

# 366 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedBrendan:: @ 81E2FAA
# 367 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
# 368 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 369 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 370 "data/maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, FALSE
# 371 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq LilycoveCity_EventScript_BrendanCollectBadges
# 372 "data/maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, TRUE
# 373 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq LilycoveCity_EventScript_BrendanPokemonLeague
# 374 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 375 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
# 376 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 377 "data/maps/LilycoveCity/scripts.pory"
	end
# 378 "data/maps/LilycoveCity/scripts.pory"

# 379 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanCollectBadges:: @ 81E2FE2
# 380 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
# 381 "data/maps/LilycoveCity/scripts.pory"
	return
# 382 "data/maps/LilycoveCity/scripts.pory"

# 383 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanPokemonLeague:: @ 81E2FEB
# 384 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
# 385 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 386 "data/maps/LilycoveCity/scripts.pory"
	return
# 387 "data/maps/LilycoveCity/scripts.pory"

# 388 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanBattleFrontier:: @ 81E2FFD
# 389 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 390 "data/maps/LilycoveCity/scripts.pory"
	return
# 391 "data/maps/LilycoveCity/scripts.pory"

# 392 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RivalFlyAway:: @ 81E3006
# 393 "data/maps/LilycoveCity/scripts.pory"
	closemessage
# 394 "data/maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
# 395 "data/maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 396 "data/maps/LilycoveCity/scripts.pory"
	delay 50
# 397 "data/maps/LilycoveCity/scripts.pory"
	setfieldeffectargument 0, 1
# 398 "data/maps/LilycoveCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 399 "data/maps/LilycoveCity/scripts.pory"
	delay 15
# 400 "data/maps/LilycoveCity/scripts.pory"
	removeobject VAR_LAST_TALKED
# 401 "data/maps/LilycoveCity/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 402 "data/maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 403 "data/maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 404 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_RIVAL_LILYCOVE
# 405 "data/maps/LilycoveCity/scripts.pory"
	release
# 406 "data/maps/LilycoveCity/scripts.pory"
	end
# 407 "data/maps/LilycoveCity/scripts.pory"

# 408 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SchoolKidM:: @ 81E302D
# 409 "data/maps/LilycoveCity/scripts.pory"
	lock
# 410 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 411 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
# 412 "data/maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, YES
# 413 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq LilycoveCity_EventScript_KnowAboutBerryBlender
# 414 "data/maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, NO
# 415 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq LilycoveCity_EventScript_DontKnowAboutBerryBlender
# 416 "data/maps/LilycoveCity/scripts.pory"
	release
# 417 "data/maps/LilycoveCity/scripts.pory"
	end
# 418 "data/maps/LilycoveCity/scripts.pory"

# 419 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_KnowAboutBerryBlender:: @ 81E304F
# 420 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
# 421 "data/maps/LilycoveCity/scripts.pory"
	return
# 422 "data/maps/LilycoveCity/scripts.pory"

# 423 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DontKnowAboutBerryBlender:: @ 81E3058
# 424 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
# 425 "data/maps/LilycoveCity/scripts.pory"
	return
# 426 "data/maps/LilycoveCity/scripts.pory"

# 427 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_GiveAltarianite::
# 428 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 429 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 430 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_ITEM_LILYCOVE_CITY_ALTARIANITE, LilycoveCity_EventScript_ExplainAltarianite
# 431 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_CloudDragon, MSGBOX_YESNO
# 432 "data/maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, NO
# 433 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq LilycoveCity_EventScript_AltariaRefuse
# 434 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_YesAltaria
# 435 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 436 "data/maps/LilycoveCity/scripts.pory"
	end
# 437 "data/maps/LilycoveCity/scripts.pory"

# 438 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_YesAltaria::
# 439 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_YesAltaria, MSGBOX_DEFAULT
# 440 "data/maps/LilycoveCity/scripts.pory"
	givecustommon SPECIES_ALTARIA, 55, ITEM_LEFTOVERS, ITEM_POKE_BALL, NATURE_TIMID, 1, 76, 0, 0, 180, 252, 0, 0, 0, 0, 0, 0, 0, MOVE_BOOMBURST, MOVE_FIERY_DANCE, MOVE_QUIVER_DANCE, MOVE_ROOST, TRUE
# 441 "data/maps/LilycoveCity/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM 
# 442 "data/maps/LilycoveCity/scripts.pory"
	message LilycoveCity_Text_Got_Altaria
# 443 "data/maps/LilycoveCity/scripts.pory"
	waitfanfare
# 444 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_ITEM_LILYCOVE_CITY_ALTARIANITE
# 445 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExplainAltarianite::
# 446 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ExplainAltarianite, MSGBOX_DEFAULT
# 447 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 448 "data/maps/LilycoveCity/scripts.pory"
	end
# 449 "data/maps/LilycoveCity/scripts.pory"

# 450 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AltariaRefuse::
# 451 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_AltariaRefuse, MSGBOX_DEFAULT
# 452 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 453 "data/maps/LilycoveCity/scripts.pory"
	end
# 454 "data/maps/LilycoveCity/scripts.pory"

# 455 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayShoppingLetsBattle: @ 81E3061
# 456 "data/maps/LilycoveCity/scripts.pory"
	.string "May: Oh, hey?\n"
# 457 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, are you shopping, too?\p"
# 458 "data/maps/LilycoveCity/scripts.pory"
	.string "I bought a whole bunch of Dolls and\n"
# 459 "data/maps/LilycoveCity/scripts.pory"
	.string "Posters.\p"
# 460 "data/maps/LilycoveCity/scripts.pory"
	.string "Of course, I've also caught a lot of\n"
# 461 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokémon, and I'm raising them\l"
# 462 "data/maps/LilycoveCity/scripts.pory"
	.string "properly, too.\p"
# 463 "data/maps/LilycoveCity/scripts.pory"
	.string "Actually, I'm more worried if you're\n"
# 464 "data/maps/LilycoveCity/scripts.pory"
	.string "raising Pokémon properly, {PLAYER}{KUN}.\p"
# 465 "data/maps/LilycoveCity/scripts.pory"
	.string "I'll battle with you, so you can show\n"
# 466 "data/maps/LilycoveCity/scripts.pory"
	.string "me your Pokémon, {PLAYER}{KUN}.$"
# 467 "data/maps/LilycoveCity/scripts.pory"

# 468 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayNotRaisingPokemon: @ 81E318D
# 469 "data/maps/LilycoveCity/scripts.pory"
	.string "May: Oh, why? {PLAYER}{KUN}, haven't you\n"
# 470 "data/maps/LilycoveCity/scripts.pory"
	.string "been raising your Pokémon?\p"
# 471 "data/maps/LilycoveCity/scripts.pory"
	.string "That's not a very good showing as a\n"
# 472 "data/maps/LilycoveCity/scripts.pory"
	.string "Trainer…$"
# 473 "data/maps/LilycoveCity/scripts.pory"

# 474 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayBattleMe: @ 81E31F5
# 475 "data/maps/LilycoveCity/scripts.pory"
	.string "May: Come on, battle with me, so I can\n"
# 476 "data/maps/LilycoveCity/scripts.pory"
	.string "check out your Pokémon!$"
# 477 "data/maps/LilycoveCity/scripts.pory"

# 478 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayWontBeBeaten: @ 81E3234
# 479 "data/maps/LilycoveCity/scripts.pory"
	.string "May: The Pokémon I raised won't be\n"
# 480 "data/maps/LilycoveCity/scripts.pory"
	.string "beaten by your Pokémon, {PLAYER}{KUN}!$"
# 481 "data/maps/LilycoveCity/scripts.pory"

# 482 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayDefeat: @ 81E3275
# 483 "data/maps/LilycoveCity/scripts.pory"
	.string "… … … … … … … …\p"
# 484 "data/maps/LilycoveCity/scripts.pory"
	.string "I remember the battle I had with you,\n"
# 485 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, on Route 103.\p"
# 486 "data/maps/LilycoveCity/scripts.pory"
	.string "That battle helped you become this\n"
# 487 "data/maps/LilycoveCity/scripts.pory"
	.string "strong, {PLAYER}{KUN}, didn't it?$"
# 488 "data/maps/LilycoveCity/scripts.pory"

# 489 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayGoingBackToLittleroot: @ 81E32FB
# 490 "data/maps/LilycoveCity/scripts.pory"
	.string "May: I'm thinking of going back to\n"
# 491 "data/maps/LilycoveCity/scripts.pory"
	.string "Littleroot soon.\p"
# 492 "data/maps/LilycoveCity/scripts.pory"
	.string "I've caught a decent group of Pokémon,\n"
# 493 "data/maps/LilycoveCity/scripts.pory"
	.string "and my Pokédex is coming along, so\l"
# 494 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm going home to show my dad.$"
# 495 "data/maps/LilycoveCity/scripts.pory"

# 496 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToCollectBadges: @ 81E3398
# 497 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 498 "data/maps/LilycoveCity/scripts.pory"
	.string "Collect all the Gym Badges and take\n"
# 499 "data/maps/LilycoveCity/scripts.pory"
	.string "the Pokémon League challenge?\p"
# 500 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, while you're collecting Badges,\n"
# 501 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, I'm going to work on my\l"
# 502 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokédex. I'll complete it before you!\p"
# 503 "data/maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 504 "data/maps/LilycoveCity/scripts.pory"

# 505 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToPokemonLeague: @ 81E346D
# 506 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 507 "data/maps/LilycoveCity/scripts.pory"
	.string "Are you taking the Pokémon League\n"
# 508 "data/maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 509 "data/maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 510 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokédex?\p"
# 511 "data/maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 512 "data/maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my Pokédex before you!\p"
# 513 "data/maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 514 "data/maps/LilycoveCity/scripts.pory"

# 515 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToBattleFrontier: @ 81E353A
# 516 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 517 "data/maps/LilycoveCity/scripts.pory"
	.string "Are you taking the Battle Frontier\n"
# 518 "data/maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 519 "data/maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 520 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokédex?\p"
# 521 "data/maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 522 "data/maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my Pokédex before you!\p"
# 523 "data/maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 524 "data/maps/LilycoveCity/scripts.pory"

# 525 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanShoppingLetsBattle: @ 81E3608
# 526 "data/maps/LilycoveCity/scripts.pory"
	.string "Brendan: Oh, hey, it's {PLAYER}.\p"
# 527 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm running an errand for my dad.\n"
# 528 "data/maps/LilycoveCity/scripts.pory"
	.string "No, I'm not buying any Dolls.\p"
# 529 "data/maps/LilycoveCity/scripts.pory"
	.string "Anyways, it's been a while.\p"
# 530 "data/maps/LilycoveCity/scripts.pory"
	.string "Want to have a battle to see who's been\n"
# 531 "data/maps/LilycoveCity/scripts.pory"
	.string "raising Pokémon better?$"
# 532 "data/maps/LilycoveCity/scripts.pory"

# 533 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanNoConfidence: @ 81E36BF
# 534 "data/maps/LilycoveCity/scripts.pory"
	.string "Brendan: Oh, what's the matter?\n"
# 535 "data/maps/LilycoveCity/scripts.pory"
	.string "Don't have the confidence?$"
# 536 "data/maps/LilycoveCity/scripts.pory"

# 537 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanBattleMe: @ 81E36FA
# 538 "data/maps/LilycoveCity/scripts.pory"
	.string "Brendan: Want to battle to see who's\n"
# 539 "data/maps/LilycoveCity/scripts.pory"
	.string "been raising Pokémon better?$"
# 540 "data/maps/LilycoveCity/scripts.pory"

# 541 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanWontBeBeaten: @ 81E373C
# 542 "data/maps/LilycoveCity/scripts.pory"
	.string "Brendan: Aww, but you know I'm not\n"
# 543 "data/maps/LilycoveCity/scripts.pory"
	.string "going to lose to no {PLAYER}.$"
# 544 "data/maps/LilycoveCity/scripts.pory"

# 545 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanDefeat: @ 81E3777
# 546 "data/maps/LilycoveCity/scripts.pory"
	.string "Humph…\n"
# 547 "data/maps/LilycoveCity/scripts.pory"
	.string "You've done a lot of raising.\p"
# 548 "data/maps/LilycoveCity/scripts.pory"
	.string "That stings a bit--I had a head start\n"
# 549 "data/maps/LilycoveCity/scripts.pory"
	.string "on you as a Trainer…$"
# 550 "data/maps/LilycoveCity/scripts.pory"

# 551 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanGoingBackToLittleroot: @ 81E37D7
# 552 "data/maps/LilycoveCity/scripts.pory"
	.string "Brendan: I…\n"
# 553 "data/maps/LilycoveCity/scripts.pory"
	.string "I plan on going home to Littleroot.\p"
# 554 "data/maps/LilycoveCity/scripts.pory"
	.string "You know I'm helping out my dad on his\n"
# 555 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokédex. It's coming together pretty\l"
# 556 "data/maps/LilycoveCity/scripts.pory"
	.string "decently, so I should go show him.$"
# 557 "data/maps/LilycoveCity/scripts.pory"

# 558 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToCollectBadges: @ 81E3876
# 559 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 560 "data/maps/LilycoveCity/scripts.pory"
	.string "Collect all the Gym Badges and take\n"
# 561 "data/maps/LilycoveCity/scripts.pory"
	.string "the Pokémon League challenge?\p"
# 562 "data/maps/LilycoveCity/scripts.pory"
	.string "Maybe I'll do that, too…\p"
# 563 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 564 "data/maps/LilycoveCity/scripts.pory"

# 565 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToPokemonLeague: @ 81E390C
# 566 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 567 "data/maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, are you\n"
# 568 "data/maps/LilycoveCity/scripts.pory"
	.string "taking the Pokémon League challenge?\p"
# 569 "data/maps/LilycoveCity/scripts.pory"
	.string "Heh, even me--if I trained my Pokémon\n"
# 570 "data/maps/LilycoveCity/scripts.pory"
	.string "a bit more, I should be stronger than\l"
# 571 "data/maps/LilycoveCity/scripts.pory"
	.string "you, {PLAYER}.\p"
# 572 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 573 "data/maps/LilycoveCity/scripts.pory"

# 574 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToBattleFrontier: @ 81E39E3
# 575 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 576 "data/maps/LilycoveCity/scripts.pory"
	.string "Are you taking the Battle Frontier\n"
# 577 "data/maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 578 "data/maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 579 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokédex?\p"
# 580 "data/maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, you should\n"
# 581 "data/maps/LilycoveCity/scripts.pory"
	.string "consider the Battle Frontier.\p"
# 582 "data/maps/LilycoveCity/scripts.pory"
	.string "Heh, if I train my Pokémon a bit more,\n"
# 583 "data/maps/LilycoveCity/scripts.pory"
	.string "I'll get stronger than you, {PLAYER}.\p"
# 584 "data/maps/LilycoveCity/scripts.pory"
	.string "Maybe I should go to the BATTLE\n"
# 585 "data/maps/LilycoveCity/scripts.pory"
	.string "FRONTIER.\p"
# 586 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 587 "data/maps/LilycoveCity/scripts.pory"

# 588 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MovedLootIntoHideoutToday: @ 81E3B2C
# 589 "data/maps/LilycoveCity/scripts.pory"
	.string "Fufufu…\p"
# 590 "data/maps/LilycoveCity/scripts.pory"
	.string "We moved more loot into our secret\n"
# 591 "data/maps/LilycoveCity/scripts.pory"
	.string "Hideout today…\p"
# 592 "data/maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 593 "data/maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 594 "data/maps/LilycoveCity/scripts.pory"

# 595 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ChanceToDoBigThings: @ 81E3B95
# 596 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm just a Grunt, so I don't know what\n"
# 597 "data/maps/LilycoveCity/scripts.pory"
	.string "the Boss is thinking…\p"
# 598 "data/maps/LilycoveCity/scripts.pory"
	.string "But being on Team Aqua, I know I'll get\n"
# 599 "data/maps/LilycoveCity/scripts.pory"
	.string "the chance to do big things!\p"
# 600 "data/maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 601 "data/maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 602 "data/maps/LilycoveCity/scripts.pory"

# 603 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DontGoNearCaveInCove: @ 81E3C46
# 604 "data/maps/LilycoveCity/scripts.pory"
	.string "Hey, you!\p"
# 605 "data/maps/LilycoveCity/scripts.pory"
	.string "Don't go near the cave in the cove!\p"
# 606 "data/maps/LilycoveCity/scripts.pory"
	.string "Why? You don't need a reason why!\n"
# 607 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm an adult, so you just listen to me!$"
# 608 "data/maps/LilycoveCity/scripts.pory"

# 609 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_IfWorldBecomesOurs: @ 81E3CBE
# 610 "data/maps/LilycoveCity/scripts.pory"
	.string "If this whole wide world becomes ours,\n"
# 611 "data/maps/LilycoveCity/scripts.pory"
	.string "Team Aqua's, it will be a happier\l"
# 612 "data/maps/LilycoveCity/scripts.pory"
	.string "place for Pokémon, too.$"
# 613 "data/maps/LilycoveCity/scripts.pory"

# 614 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_WailmerLeapOutOfWater: @ 81E3D1F
# 615 "data/maps/LilycoveCity/scripts.pory"
	.string "There! Wailmer!\n"
# 616 "data/maps/LilycoveCity/scripts.pory"
	.string "Leap out of the water now!$"
# 617 "data/maps/LilycoveCity/scripts.pory"

# 618 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GetLostMessingUpTraining: @ 81E3D4A
# 619 "data/maps/LilycoveCity/scripts.pory"
	.string "Hunh? What do you want?\p"
# 620 "data/maps/LilycoveCity/scripts.pory"
	.string "You're messing up our training,\n"
# 621 "data/maps/LilycoveCity/scripts.pory"
	.string "so can you, like, get lost?$"
# 622 "data/maps/LilycoveCity/scripts.pory"

# 623 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallInTown: @ 81E3D9E
# 624 "data/maps/LilycoveCity/scripts.pory"
	.string "There's a Pokémon Contest Hall\n"
# 625 "data/maps/LilycoveCity/scripts.pory"
	.string "right in this here town. \p"
# 626 "data/maps/LilycoveCity/scripts.pory"
	.string "That means well-raised Pokémon will\n"
# 627 "data/maps/LilycoveCity/scripts.pory"
	.string "come from all over the country.\p"
# 628 "data/maps/LilycoveCity/scripts.pory"
	.string "My heart swells with excitement!$"
# 629 "data/maps/LilycoveCity/scripts.pory"

# 630 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_StrangeCaveInCove: @ 81E3E3C
# 631 "data/maps/LilycoveCity/scripts.pory"
	.string "Have you seen that strange cave in\n"
# 632 "data/maps/LilycoveCity/scripts.pory"
	.string "the cove at the edge of town?$"
# 633 "data/maps/LilycoveCity/scripts.pory"

# 634 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GoingToMoveDeleterForHMs: @ 81E3E7D
# 635 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm going to teach my Pokémon some new\n"
# 636 "data/maps/LilycoveCity/scripts.pory"
	.string "moves for entering a Contest.\p"
# 637 "data/maps/LilycoveCity/scripts.pory"
	.string "So, I'm going to see the Move Deleter\n"
# 638 "data/maps/LilycoveCity/scripts.pory"
	.string "and make it forget HM moves.$"
# 639 "data/maps/LilycoveCity/scripts.pory"

# 640 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImFromKanto: @ 81E3F05
# 641 "data/maps/LilycoveCity/scripts.pory"
	.string "I came from Kanto.\p"
# 642 "data/maps/LilycoveCity/scripts.pory"
	.string "The Hoenn region is beautiful with\n"
# 643 "data/maps/LilycoveCity/scripts.pory"
	.string "all its water and verdant nature.\p"
# 644 "data/maps/LilycoveCity/scripts.pory"
	.string "Hunh? Wait a second…\p"
# 645 "data/maps/LilycoveCity/scripts.pory"
	.string "Could there be rare Pokémon that live\n"
# 646 "data/maps/LilycoveCity/scripts.pory"
	.string "only in this area?$"
# 647 "data/maps/LilycoveCity/scripts.pory"

# 648 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaBeenTrainingWailmer: @ 81E3FAB
# 649 "data/maps/LilycoveCity/scripts.pory"
	.string "Team Aqua's been training their\n"
# 650 "data/maps/LilycoveCity/scripts.pory"
	.string "Wailmer in the cove.\p"
# 651 "data/maps/LilycoveCity/scripts.pory"
	.string "We Sailors can't get our boats out\n"
# 652 "data/maps/LilycoveCity/scripts.pory"
	.string "to sea with them in the way!$"
# 653 "data/maps/LilycoveCity/scripts.pory"

# 654 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeonePuntedTeamAquaOut: @ 81E4020
# 655 "data/maps/LilycoveCity/scripts.pory"
	.string "Ahoy, did you know?\p"
# 656 "data/maps/LilycoveCity/scripts.pory"
	.string "Someone punted Team Aqua out of\n"
# 657 "data/maps/LilycoveCity/scripts.pory"
	.string "the way for us!\p"
# 658 "data/maps/LilycoveCity/scripts.pory"
	.string "That got the Wailmer out of the cove,\n"
# 659 "data/maps/LilycoveCity/scripts.pory"
	.string "so we can get our boats out again.$"
# 660 "data/maps/LilycoveCity/scripts.pory"

# 661 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeoneStoleMyPokemon: @ 81E40AD
# 662 "data/maps/LilycoveCity/scripts.pory"
	.string "I was taking a relaxing snooze at the\n"
# 663 "data/maps/LilycoveCity/scripts.pory"
	.string "seaside inn to the sound of waves…\p"
# 664 "data/maps/LilycoveCity/scripts.pory"
	.string "When someone stole my Pokémon!\p"
# 665 "data/maps/LilycoveCity/scripts.pory"
	.string "Who's the abductor?\n"
# 666 "data/maps/LilycoveCity/scripts.pory"
	.string "Team Aqua? Is it Team Aqua?$"
# 667 "data/maps/LilycoveCity/scripts.pory"

# 668 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MissingPokemonCameBack: @ 81E4145
# 669 "data/maps/LilycoveCity/scripts.pory"
	.string "My missing Pokémon…\n"
# 670 "data/maps/LilycoveCity/scripts.pory"
	.string "It came back without me noticing!$"
# 671 "data/maps/LilycoveCity/scripts.pory"

# 672 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImArtDealer: @ 81E417B
# 673 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm an Art Dealer.\p"
# 674 "data/maps/LilycoveCity/scripts.pory"
	.string "I am a buyer and seller of fine art,\n"
# 675 "data/maps/LilycoveCity/scripts.pory"
	.string "especially paintings.\p"
# 676 "data/maps/LilycoveCity/scripts.pory"
	.string "I've heard that the Museum here has\n"
# 677 "data/maps/LilycoveCity/scripts.pory"
	.string "magnificent works on exhibit…$"
# 678 "data/maps/LilycoveCity/scripts.pory"

# 679 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SeaRemainsForeverYoung: @ 81E420B
# 680 "data/maps/LilycoveCity/scripts.pory"
	.string "Even as we grow old and wrinkled,\n"
# 681 "data/maps/LilycoveCity/scripts.pory"
	.string "the sea remains forever young with\l"
# 682 "data/maps/LilycoveCity/scripts.pory"
	.string "the vivid brilliance of life…\p"
# 683 "data/maps/LilycoveCity/scripts.pory"
	.string "Fwohoho fwohohohoho…$"
# 684 "data/maps/LilycoveCity/scripts.pory"

# 685 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SixtyYearsAgoHusbandProposed: @ 81E4283
# 686 "data/maps/LilycoveCity/scripts.pory"
	.string "It was sixty years ago that my husband\n"
# 687 "data/maps/LilycoveCity/scripts.pory"
	.string "proposed to me here.\l"
# 688 "data/maps/LilycoveCity/scripts.pory"
	.string "The sea remains as beautiful as ever.\p"
# 689 "data/maps/LilycoveCity/scripts.pory"
	.string "Mufufufu mufufufufufu…$"
# 690 "data/maps/LilycoveCity/scripts.pory"

# 691 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaRenovatedCavern: @ 81E42FC
# 692 "data/maps/LilycoveCity/scripts.pory"
	.string "Hm, you know of the peculiar cavern\n"
# 693 "data/maps/LilycoveCity/scripts.pory"
	.string "in this cove?\p"
# 694 "data/maps/LilycoveCity/scripts.pory"
	.string "That had been a natural formation,\n"
# 695 "data/maps/LilycoveCity/scripts.pory"
	.string "but then that Team Aqua lot came\l"
# 696 "data/maps/LilycoveCity/scripts.pory"
	.string "along and made their renovations.\p"
# 697 "data/maps/LilycoveCity/scripts.pory"
	.string "They call themselves\n"
# 698 "data/maps/LilycoveCity/scripts.pory"
	.string "the “nature-loving Team Aqua”!\p"
# 699 "data/maps/LilycoveCity/scripts.pory"
	.string "But what they do and what they say\n"
# 700 "data/maps/LilycoveCity/scripts.pory"
	.string "don't match at all!$"
# 701 "data/maps/LilycoveCity/scripts.pory"

# 702 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaLotGoneForGood: @ 81E43FF
# 703 "data/maps/LilycoveCity/scripts.pory"
	.string "That cave in the cove…\p"
# 704 "data/maps/LilycoveCity/scripts.pory"
	.string "I didn't notice it right away,\n"
# 705 "data/maps/LilycoveCity/scripts.pory"
	.string "but it's completely empty now.\p"
# 706 "data/maps/LilycoveCity/scripts.pory"
	.string "That Team Aqua lot, they must\n"
# 707 "data/maps/LilycoveCity/scripts.pory"
	.string "have gone away for good.$"
# 708 "data/maps/LilycoveCity/scripts.pory"

# 709 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_CitySign: @ 81E448B
# 710 "data/maps/LilycoveCity/scripts.pory"
	.string "Lilycove City\p"
# 711 "data/maps/LilycoveCity/scripts.pory"
	.string "“Where the land ends and the\n"
# 712 "data/maps/LilycoveCity/scripts.pory"
	.string "sea begins.”$"
# 713 "data/maps/LilycoveCity/scripts.pory"

# 714 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallSign: @ 81E44C3
# 715 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokémon Contest Hall\n"
# 716 "data/maps/LilycoveCity/scripts.pory"
	.string "“The gathering place for Trainers!”$"
# 717 "data/maps/LilycoveCity/scripts.pory"

# 718 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MotelSign: @ 81E44FC
# 719 "data/maps/LilycoveCity/scripts.pory"
	.string "Cove Lily Motel\p"
# 720 "data/maps/LilycoveCity/scripts.pory"
	.string "“Remember us as Cove Lily of\n"
# 721 "data/maps/LilycoveCity/scripts.pory"
	.string "Lilycove.”$"
# 722 "data/maps/LilycoveCity/scripts.pory"

# 723 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSign: @ 81E4534
# 724 "data/maps/LilycoveCity/scripts.pory"
	.string "Lilycove Museum\p"
# 725 "data/maps/LilycoveCity/scripts.pory"
	.string "“Pokémon Masterpiece Collection\n"
# 726 "data/maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 727 "data/maps/LilycoveCity/scripts.pory"

# 728 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSignPlayersExhibit: @ 81E4571
# 729 "data/maps/LilycoveCity/scripts.pory"
	.string "Lilycove Museum\p"
# 730 "data/maps/LilycoveCity/scripts.pory"
	.string "“{PLAYER}'s Pokémon Collection\n"
# 731 "data/maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 732 "data/maps/LilycoveCity/scripts.pory"

# 733 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSignUnderConstruction: @ 81E45A7
# 734 "data/maps/LilycoveCity/scripts.pory"
	.string "Lilycove City Harbor\p"
# 735 "data/maps/LilycoveCity/scripts.pory"
	.string "“The ferry S.S. Tidal is under\n"
# 736 "data/maps/LilycoveCity/scripts.pory"
	.string "construction in Slateport City.\p"
# 737 "data/maps/LilycoveCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 738 "data/maps/LilycoveCity/scripts.pory"
	.string "shortly.”$"
# 739 "data/maps/LilycoveCity/scripts.pory"

# 740 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSign: @ 81E4624
# 741 "data/maps/LilycoveCity/scripts.pory"
	.string "Lilycove City Harbor\p"
# 742 "data/maps/LilycoveCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 743 "data/maps/LilycoveCity/scripts.pory"
	.string "the ferry S.S. Tidal.”$"
# 744 "data/maps/LilycoveCity/scripts.pory"

# 745 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TrainerFanClubSign: @ 81E466E
# 746 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokémon Trainer Fan Club\p"
# 747 "data/maps/LilycoveCity/scripts.pory"
	.string "The names of Trainers are scribbled\n"
# 748 "data/maps/LilycoveCity/scripts.pory"
	.string "all over the sign…$"
# 749 "data/maps/LilycoveCity/scripts.pory"

# 750 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DepartmentStoreSign: @ 81E46BE
# 751 "data/maps/LilycoveCity/scripts.pory"
	.string "Lilycove Department Store\p"
# 752 "data/maps/LilycoveCity/scripts.pory"
	.string "“Overflowing with great merchandise\n"
# 753 "data/maps/LilycoveCity/scripts.pory"
	.string "and excitement!\p"
# 754 "data/maps/LilycoveCity/scripts.pory"
	.string "“A great place to find that something\n"
# 755 "data/maps/LilycoveCity/scripts.pory"
	.string "you need!”$"
# 756 "data/maps/LilycoveCity/scripts.pory"

# 757 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BallSwappersHouseSign: @ 81E473D
# 758 "data/maps/LilycoveCity/scripts.pory"
	.string "Poké Ball Swapper's House\p"
# 759 "data/maps/LilycoveCity/scripts.pory"
	.string "“Move your Pokémon to a new home!”$"
# 760 "data/maps/LilycoveCity/scripts.pory"

# 761 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DoYouKnowAboutBerryBlender: @ 81E4774
# 762 "data/maps/LilycoveCity/scripts.pory"
	.string "Do you know about the machine\n"
# 763 "data/maps/LilycoveCity/scripts.pory"
	.string "Berry Blender?$"
# 764 "data/maps/LilycoveCity/scripts.pory"

# 765 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_FasterSpinBetterPokeblocks: @ 81E47A1
# 766 "data/maps/LilycoveCity/scripts.pory"
	.string "People have to work together to get it\n"
# 767 "data/maps/LilycoveCity/scripts.pory"
	.string "to spin faster.\p"
# 768 "data/maps/LilycoveCity/scripts.pory"
	.string "The faster you can make it spin, the\n"
# 769 "data/maps/LilycoveCity/scripts.pory"
	.string "better {POKEBLOCK}S you can get, I've heard.$"
# 770 "data/maps/LilycoveCity/scripts.pory"

# 771 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ExplainBerryBlender: @ 81E4824
# 772 "data/maps/LilycoveCity/scripts.pory"
	.string "It's used for making a kind of candy\n"
# 773 "data/maps/LilycoveCity/scripts.pory"
	.string "called a {POKEBLOCK}.\p"
# 774 "data/maps/LilycoveCity/scripts.pory"
	.string "If you give a good {POKEBLOCK} to a Pokémon,\n"
# 775 "data/maps/LilycoveCity/scripts.pory"
	.string "its condition will improve by a lot.$"
# 776 "data/maps/LilycoveCity/scripts.pory"

# 777 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HeardTowerCalledSkyPillar: @ 81E48A5
# 778 "data/maps/LilycoveCity/scripts.pory"
	.string "I heard there's a tower somewhere out\n"
# 779 "data/maps/LilycoveCity/scripts.pory"
	.string "on the sea routes.\p"
# 780 "data/maps/LilycoveCity/scripts.pory"
	.string "It's called the Sky Pillar, I hear.$"
# 781 "data/maps/LilycoveCity/scripts.pory"

# 782 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SawTallTowerOnRoute131: @ 81E4902
# 783 "data/maps/LilycoveCity/scripts.pory"
	.string "I saw this tall tower somewhere\n"
# 784 "data/maps/LilycoveCity/scripts.pory"
	.string "around Route 131.\p"
# 785 "data/maps/LilycoveCity/scripts.pory"
	.string "Could that possibly be…?$"
# 786 "data/maps/LilycoveCity/scripts.pory"

# 787 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_JustArrivedAndSawRarePokemon: @ 81E494D
# 788 "data/maps/LilycoveCity/scripts.pory"
	.string "We just arrived here on our\n"
# 789 "data/maps/LilycoveCity/scripts.pory"
	.string "honeymoon vacation.\p"
# 790 "data/maps/LilycoveCity/scripts.pory"
	.string "We happened to see a Dragon-type\n"
# 791 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokémon flying way up in the sky.\p"
# 792 "data/maps/LilycoveCity/scripts.pory"
	.string "Do cool Pokémon like that live in\n"
# 793 "data/maps/LilycoveCity/scripts.pory"
	.string "the Hoenn region?$"
# 794 "data/maps/LilycoveCity/scripts.pory"

# 795 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HoneymoonVowToSeeRarePokemon: @ 81E49F4
# 796 "data/maps/LilycoveCity/scripts.pory"
	.string "On our honeymoon, we vowed to see as\n"
# 797 "data/maps/LilycoveCity/scripts.pory"
	.string "many rare Pokémon as we can.\p"
# 798 "data/maps/LilycoveCity/scripts.pory"
	.string "So we were delighted to see a rare\n"
# 799 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokémon as soon as we arrived.\p"
# 800 "data/maps/LilycoveCity/scripts.pory"
	.string "I mean, we are totally happy!$"
# 801 "data/maps/LilycoveCity/scripts.pory"

# 802 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_CloudDragon:
# 803 "data/maps/LilycoveCity/scripts.pory"
	.string "Do you know which Dragon Pokémon\n"
# 804 "data/maps/LilycoveCity/scripts.pory"
	.string "looks like a cloud?$"
# 805 "data/maps/LilycoveCity/scripts.pory"

# 806 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_YesAltaria:
# 807 "data/maps/LilycoveCity/scripts.pory"
	.string "Yes! That's it! An Altaria,\n"
# 808 "data/maps/LilycoveCity/scripts.pory"
	.string "just like Winona's!\p"
# 809 "data/maps/LilycoveCity/scripts.pory"
	.string "You can have this Altaria!\p"
# 810 "data/maps/LilycoveCity/scripts.pory"
	.string "It has some special moves.$"
# 811 "data/maps/LilycoveCity/scripts.pory"

# 812 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_AltariaRefuse:
# 813 "data/maps/LilycoveCity/scripts.pory"
	.string "That's a shame. I'll give you something\n"
# 814 "data/maps/LilycoveCity/scripts.pory"
	.string "nice if you change your mind.$"
# 815 "data/maps/LilycoveCity/scripts.pory"

# 816 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_NotAltaria:
# 817 "data/maps/LilycoveCity/scripts.pory"
	.string "Hmmm, no. Try again!$"
# 818 "data/maps/LilycoveCity/scripts.pory"

# 819 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ExplainAltarianite:
# 820 "data/maps/LilycoveCity/scripts.pory"
	.string "If you don't already know how strong\n"
# 821 "data/maps/LilycoveCity/scripts.pory"
	.string "Altaria is, Winona can show you.\p"
# 822 "data/maps/LilycoveCity/scripts.pory"
	.string "Just challenge her to a battle\n"
# 823 "data/maps/LilycoveCity/scripts.pory"
	.string "and see for yourself!$"

LilycoveCity_Text_Got_Altaria::
# 825 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER} got an {COLOR BLUE}Altaria{COLOR DARK_GRAY} as a gift!$"
