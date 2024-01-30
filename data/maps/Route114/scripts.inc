# 1 "data/maps/Route114/scripts.pory"

# 2 "data/maps/Route114/scripts.pory"
Route114_MapScripts:: @ 81F252F
# 3 "data/maps/Route114/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_OnTransition
# 4 "data/maps/Route114/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route114_OnLoad
# 5 "data/maps/Route114/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route114_OnFrame
# 6 "data/maps/Route114/scripts.pory"
	.byte 0
# 7 "data/maps/Route114/scripts.pory"

# 8 "data/maps/Route114/scripts.pory"
Route114_OnTransition: @ 81F253F
# 9 "data/maps/Route114/scripts.pory"
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
# 10 "data/maps/Route114/scripts.pory"
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
# 11 "data/maps/Route114/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_NORTH
# 12 "data/maps/Route114/scripts.pory"
	call_if_eq AbnormalWeather_StartGroudonWeather
# 13 "data/maps/Route114/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_SOUTH
# 14 "data/maps/Route114/scripts.pory"
	call_if_eq AbnormalWeather_StartGroudonWeather
# 15 "data/maps/Route114/scripts.pory"
	end
# 16 "data/maps/Route114/scripts.pory"

# 17 "data/maps/Route114/scripts.pory"
Route114_OnLoad: @ 81F2561
# 18 "data/maps/Route114/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_NORTH
# 19 "data/maps/Route114/scripts.pory"
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute114North
# 20 "data/maps/Route114/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_SOUTH
# 21 "data/maps/Route114/scripts.pory"
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute114South
# 22 "data/maps/Route114/scripts.pory"
	end
# 23 "data/maps/Route114/scripts.pory"

# 24 "data/maps/Route114/scripts.pory"
Route114_OnFrame: @ 81F2578
# 25 "data/maps/Route114/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 26 "data/maps/Route114/scripts.pory"
	.2byte 0
# 27 "data/maps/Route114/scripts.pory"

# 28 "data/maps/Route114/scripts.pory"
Route114_EventScript_Man:: @ 81F2582
# 29 "data/maps/Route114/scripts.pory"
	lock
# 30 "data/maps/Route114/scripts.pory"
	faceplayer
# 31 "data/maps/Route114/scripts.pory"
	dotimebasedevents
# 32 "data/maps/Route114/scripts.pory"
	goto_if_set FLAG_DAILY_ROUTE_114_RECEIVED_BERRY, Route114_EventScript_ReceivedBerry
# 33 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_LoveUsingBerryCrushShareBerry, MSGBOX_DEFAULT
# 34 "data/maps/Route114/scripts.pory"
	random NUM_ROUTE_114_MAN_BERRIES
# 35 "data/maps/Route114/scripts.pory"
	addvar VAR_RESULT, NUM_ROUTE_114_MAN_BERRIES_SKIPPED
# 36 "data/maps/Route114/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 37 "data/maps/Route114/scripts.pory"
	giveitem VAR_RESULT
# 38 "data/maps/Route114/scripts.pory"
	compare VAR_RESULT, FALSE
# 39 "data/maps/Route114/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 40 "data/maps/Route114/scripts.pory"
	setflag FLAG_DAILY_ROUTE_114_RECEIVED_BERRY
# 41 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_TryBerryCrushWithFriends, MSGBOX_DEFAULT
# 42 "data/maps/Route114/scripts.pory"
	release
# 43 "data/maps/Route114/scripts.pory"
	end
# 44 "data/maps/Route114/scripts.pory"

# 45 "data/maps/Route114/scripts.pory"
Route114_EventScript_ReceivedBerry:: @ 81F25C7
# 46 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_FunToThinkAboutBerries, MSGBOX_DEFAULT
# 47 "data/maps/Route114/scripts.pory"
	release
# 48 "data/maps/Route114/scripts.pory"
	end
# 49 "data/maps/Route114/scripts.pory"

# 50 "data/maps/Route114/scripts.pory"
Route114_EventScript_RoarGentleman:: @ 81F25D1
# 51 "data/maps/Route114/scripts.pory"
	lock
# 52 "data/maps/Route114/scripts.pory"
	faceplayer
# 53 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_AllMyMonDoesIsRoarTakeThis, MSGBOX_DEFAULT
# 54 "data/maps/Route114/scripts.pory"
	release
# 55 "data/maps/Route114/scripts.pory"
	end
# 56 "data/maps/Route114/scripts.pory"

# 57 "data/maps/Route114/scripts.pory"
Route114_EventScript_ReceivedRoar:: @ 81F2608
# 58 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_ExplainRoar, MSGBOX_DEFAULT
# 59 "data/maps/Route114/scripts.pory"
	release
# 60 "data/maps/Route114/scripts.pory"
	end
# 61 "data/maps/Route114/scripts.pory"

# 62 "data/maps/Route114/scripts.pory"
Route114_EventScript_Poochyena:: @ 81F2612
# 63 "data/maps/Route114/scripts.pory"
	lock
# 64 "data/maps/Route114/scripts.pory"
	faceplayer
# 65 "data/maps/Route114/scripts.pory"
	waitse
# 66 "data/maps/Route114/scripts.pory"
	playmoncry SPECIES_POOCHYENA, 2
# 67 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_Poochyena, MSGBOX_DEFAULT
# 68 "data/maps/Route114/scripts.pory"
	waitmoncry
# 69 "data/maps/Route114/scripts.pory"
	release
# 70 "data/maps/Route114/scripts.pory"
	end
# 71 "data/maps/Route114/scripts.pory"

# 72 "data/maps/Route114/scripts.pory"
Route114_EventScript_MeteorFallsSign:: @ 81F2625
# 73 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_MeteorFallsSign, MSGBOX_SIGN
# 74 "data/maps/Route114/scripts.pory"
	end
# 75 "data/maps/Route114/scripts.pory"

# 76 "data/maps/Route114/scripts.pory"
Route114_EventScript_FossilManiacsHouseSign:: @ 81F262E
# 77 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_FossilManiacsHouseSign, MSGBOX_SIGN
# 78 "data/maps/Route114/scripts.pory"
	end
# 79 "data/maps/Route114/scripts.pory"

# 80 "data/maps/Route114/scripts.pory"
Route114_EventScript_LanettesHouseSign:: @ 81F2637
# 81 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_LanettesHouse, MSGBOX_SIGN
# 82 "data/maps/Route114/scripts.pory"
	end
# 83 "data/maps/Route114/scripts.pory"

# 84 "data/maps/Route114/scripts.pory"
Route114_EventScript_Lenny:: @ 81F2640
# 85 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_LENNY, Route114_Text_LennyIntro, Route114_Text_LennyDefeat
# 86 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
# 87 "data/maps/Route114/scripts.pory"
	end
# 88 "data/maps/Route114/scripts.pory"

# 89 "data/maps/Route114/scripts.pory"
Route114_EventScript_Lucas:: @ 81F2657
# 90 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_LUCAS_1, Route114_Text_LucasIntro, Route114_Text_LucasDefeat
# 91 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
# 92 "data/maps/Route114/scripts.pory"
	end
# 93 "data/maps/Route114/scripts.pory"

# 94 "data/maps/Route114/scripts.pory"
Route114_EventScript_Shane:: @ 81F266E
# 95 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_SHANE, Route114_Text_ShaneIntro, Route114_Text_ShaneDefeat
# 96 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_ShanePostBattle, MSGBOX_AUTOCLOSE
# 97 "data/maps/Route114/scripts.pory"
	end
# 98 "data/maps/Route114/scripts.pory"

# 99 "data/maps/Route114/scripts.pory"
Route114_EventScript_Nancy:: @ 81F2685
# 100 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_NANCY, Route114_Text_NancyIntro, Route114_Text_NancyDefeat
# 101 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_NancyPostBattle, MSGBOX_AUTOCLOSE
# 102 "data/maps/Route114/scripts.pory"
	end
# 103 "data/maps/Route114/scripts.pory"

# 104 "data/maps/Route114/scripts.pory"
Route114_EventScript_Steve:: @ 81F269C
# 105 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_STEVE_1, Route114_Text_SteveIntro, Route114_Text_SteveDefeat, Route114_EventScript_RegisterSteve
# 106 "data/maps/Route114/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 107 "data/maps/Route114/scripts.pory"
	compare VAR_RESULT, TRUE
# 108 "data/maps/Route114/scripts.pory"
	goto_if_eq Route114_EventScript_RematchSteve
# 109 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_StevePostBattle, MSGBOX_DEFAULT
# 110 "data/maps/Route114/scripts.pory"
	release
# 111 "data/maps/Route114/scripts.pory"
	end
# 112 "data/maps/Route114/scripts.pory"

# 113 "data/maps/Route114/scripts.pory"
Route114_EventScript_RegisterSteve:: @ 81F26C8
# 114 "data/maps/Route114/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 115 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 116 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_SteveRegister, MSGBOX_DEFAULT
# 117 "data/maps/Route114/scripts.pory"
	register_matchcall TRAINER_STEVE_1
# 118 "data/maps/Route114/scripts.pory"
	release
# 119 "data/maps/Route114/scripts.pory"
	end
# 120 "data/maps/Route114/scripts.pory"

# 121 "data/maps/Route114/scripts.pory"
Route114_EventScript_RematchSteve:: @ 81F26E7
# 122 "data/maps/Route114/scripts.pory"
	trainerbattle_rematch TRAINER_STEVE_1, Route114_Text_SteveRematchIntro, Route114_Text_SteveRematchDefeat
# 123 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_StevePostRematch, MSGBOX_AUTOCLOSE
# 124 "data/maps/Route114/scripts.pory"
	end
# 125 "data/maps/Route114/scripts.pory"

# 126 "data/maps/Route114/scripts.pory"
Route114_EventScript_Bernie:: @ 81F26FE
# 127 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_BERNIE_1, Route114_Text_BernieIntro, Route114_Text_BernieDefeat, Route114_EventScript_RegisterBernie
# 128 "data/maps/Route114/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 129 "data/maps/Route114/scripts.pory"
	compare VAR_RESULT, TRUE
# 130 "data/maps/Route114/scripts.pory"
	goto_if_eq Route114_EventScript_RematchBernie
# 131 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_BerniePostBattle, MSGBOX_DEFAULT
# 132 "data/maps/Route114/scripts.pory"
	release
# 133 "data/maps/Route114/scripts.pory"
	end
# 134 "data/maps/Route114/scripts.pory"

# 135 "data/maps/Route114/scripts.pory"
Route114_EventScript_RegisterBernie:: @ 81F272A
# 136 "data/maps/Route114/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 137 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 138 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_BernieRegister, MSGBOX_DEFAULT
# 139 "data/maps/Route114/scripts.pory"
	register_matchcall TRAINER_BERNIE_1
# 140 "data/maps/Route114/scripts.pory"
	release
# 141 "data/maps/Route114/scripts.pory"
	end
# 142 "data/maps/Route114/scripts.pory"

# 143 "data/maps/Route114/scripts.pory"
Route114_EventScript_RematchBernie:: @ 81F2749
# 144 "data/maps/Route114/scripts.pory"
	trainerbattle_rematch TRAINER_BERNIE_1, Route114_Text_BernieRematchIntro, Route114_Text_BernieRematchDefeat
# 145 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_BerniePostRematch, MSGBOX_AUTOCLOSE
# 146 "data/maps/Route114/scripts.pory"
	end
# 147 "data/maps/Route114/scripts.pory"

# 148 "data/maps/Route114/scripts.pory"
Route114_EventScript_Claude:: @ 81F2760
# 149 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_CLAUDE, Route114_Text_ClaudeIntro, Route114_Text_ClaudeDefeat
# 150 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_ClaudePostBattle, MSGBOX_AUTOCLOSE
# 151 "data/maps/Route114/scripts.pory"
	end
# 152 "data/maps/Route114/scripts.pory"

# 153 "data/maps/Route114/scripts.pory"
Route114_EventScript_Nolan:: @ 81F2777
# 154 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_NOLAN, Route114_Text_NolanIntro, Route114_Text_NolanDefeat
# 155 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_NolanPostBattle, MSGBOX_AUTOCLOSE
# 156 "data/maps/Route114/scripts.pory"
	end
# 157 "data/maps/Route114/scripts.pory"

# 158 "data/maps/Route114/scripts.pory"
Route114_EventScript_Tyra:: @ 81F278E
# 159 "data/maps/Route114/scripts.pory"
	trainerbattle_double TRAINER_TYRA_AND_IVY, Route114_Text_TyraIntro, Route114_Text_TyraDefeat, Route114_Text_TyraNotEnoughMons
# 160 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
# 161 "data/maps/Route114/scripts.pory"
	end
# 162 "data/maps/Route114/scripts.pory"

# 163 "data/maps/Route114/scripts.pory"
Route114_EventScript_Ivy:: @ 81F27A9
# 164 "data/maps/Route114/scripts.pory"
	trainerbattle_double TRAINER_TYRA_AND_IVY, Route114_Text_IvyIntro, Route114_Text_IvyDefeat, Route114_Text_IvyNotEnoughMons
# 165 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_IvyPostBattle, MSGBOX_AUTOCLOSE
# 166 "data/maps/Route114/scripts.pory"
	end
# 167 "data/maps/Route114/scripts.pory"

# 168 "data/maps/Route114/scripts.pory"
Route114_EventScript_Angelina:: @ 81F27C4
# 169 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_ANGELINA, Route114_Text_AngelinaIntro, Route114_Text_AngelinaDefeat
# 170 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_AngelinaPostBattle, MSGBOX_AUTOCLOSE
# 171 "data/maps/Route114/scripts.pory"
	end
# 172 "data/maps/Route114/scripts.pory"

# 173 "data/maps/Route114/scripts.pory"
Route114_EventScript_Charlotte:: @ 81F27DB
# 174 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_CHARLOTTE, Route114_Text_CharlotteIntro, Route114_Text_CharlotteDefeat
# 175 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_CharlottePostBattle, MSGBOX_AUTOCLOSE
# 176 "data/maps/Route114/scripts.pory"
	end
# 177 "data/maps/Route114/scripts.pory"

# 178 "data/maps/Route114/scripts.pory"
Route114_EventScript_Kai:: @ 81F27F2
# 179 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_KAI, Route114_Text_KaiIntro, Route114_Text_KaiDefeat
# 180 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_KaiPostBattle, MSGBOX_AUTOCLOSE
# 181 "data/maps/Route114/scripts.pory"
	end
# 182 "data/maps/Route114/scripts.pory"

# 183 "data/maps/Route114/scripts.pory"
Route114_Text_AllMyMonDoesIsRoarTakeThis: @ 81F2809
# 184 "data/maps/Route114/scripts.pory"
	.string "All my Pokémon does is Roar…\n"
# 185 "data/maps/Route114/scripts.pory"
	.string "No one dares to come near me…$"
# 186 "data/maps/Route114/scripts.pory"

# 187 "data/maps/Route114/scripts.pory"
Route114_Text_ExplainRoar: @ 81F2872
# 188 "data/maps/Route114/scripts.pory"
	.string "TM05 contains Roar.\n"
# 189 "data/maps/Route114/scripts.pory"
	.string "A Roar sends Pokémon scurrying.$"
# 190 "data/maps/Route114/scripts.pory"

# 191 "data/maps/Route114/scripts.pory"
Route114_Text_Poochyena: @ 81F28A6
# 192 "data/maps/Route114/scripts.pory"
	.string "Bow! Bowwow!$"
# 193 "data/maps/Route114/scripts.pory"

# 194 "data/maps/Route114/scripts.pory"
Route114_Text_MeteorFallsSign: @ 81F28B3
# 195 "data/maps/Route114/scripts.pory"
	.string "Meteor Falls\n"
# 196 "data/maps/Route114/scripts.pory"
	.string "RUSTBORO CITY THROUGH HERE$"
# 197 "data/maps/Route114/scripts.pory"

# 198 "data/maps/Route114/scripts.pory"
Route114_Text_FossilManiacsHouseSign: @ 81F28DB
# 199 "data/maps/Route114/scripts.pory"
	.string "Fossil Maniac's House\n"
# 200 "data/maps/Route114/scripts.pory"
	.string "“Fossils gratefully accepted!”$"
# 201 "data/maps/Route114/scripts.pory"

# 202 "data/maps/Route114/scripts.pory"
Route114_Text_LanettesHouse: @ 81F2910
# 203 "data/maps/Route114/scripts.pory"
	.string "Lanette's House$"

Route114_EventScript_LegendaryNPC::
# 207 "data/maps/Route114/scripts.pory"
	lock
# 208 "data/maps/Route114/scripts.pory"
	faceplayer
# 209 "data/maps/Route114/scripts.pory"
	msgbox Route114_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 210 "data/maps/Route114/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route114_EventScript_LegendaryNPC_2
# 239 "data/maps/Route114/scripts.pory"
	msgbox Route114_EventScript_LegendaryNPC_Text_4, MSGBOX_NPC
Route114_EventScript_LegendaryNPC_1:
# 241 "data/maps/Route114/scripts.pory"
	release
	end

Route114_EventScript_LegendaryNPC_2:
# 211 "data/maps/Route114/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route114_EventScript_LegendaryNPC_5
# 219 "data/maps/Route114/scripts.pory"
	checktrainerflag TRAINER_LENNY
	goto_if 1, Route114_EventScript_LegendaryNPC_11
Route114_EventScript_LegendaryNPC_9:
# 234 "data/maps/Route114/scripts.pory"
	msgbox Route114_EventScript_LegendaryNPC_Text_3
	goto Route114_EventScript_LegendaryNPC_1

Route114_EventScript_LegendaryNPC_5:
# 212 "data/maps/Route114/scripts.pory"
	msgbox Route114_EventScript_LegendaryNPC_Text_1
	goto Route114_EventScript_LegendaryNPC_1

Route114_EventScript_LegendaryNPC_8:
# 231 "data/maps/Route114/scripts.pory"
	msgbox Route114_EventScript_LegendaryNPC_Text_2
	goto Route114_EventScript_LegendaryNPC_1

Route114_EventScript_LegendaryNPC_10:
# 221 "data/maps/Route114/scripts.pory"
	checktrainerflag TRAINER_SHANE
	goto_if 1, Route114_EventScript_LegendaryNPC_15
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_11:
# 220 "data/maps/Route114/scripts.pory"
	checktrainerflag TRAINER_LUCAS_1
	goto_if 1, Route114_EventScript_LegendaryNPC_10
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_14:
# 223 "data/maps/Route114/scripts.pory"
	checktrainerflag TRAINER_STEVE_1
	goto_if 1, Route114_EventScript_LegendaryNPC_19
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_15:
# 222 "data/maps/Route114/scripts.pory"
	checktrainerflag TRAINER_NANCY
	goto_if 1, Route114_EventScript_LegendaryNPC_14
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_18:
# 225 "data/maps/Route114/scripts.pory"
	checktrainerflag TRAINER_CLAUDE
	goto_if 1, Route114_EventScript_LegendaryNPC_23
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_19:
# 224 "data/maps/Route114/scripts.pory"
	checktrainerflag TRAINER_BERNIE_1
	goto_if 1, Route114_EventScript_LegendaryNPC_18
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_22:
# 227 "data/maps/Route114/scripts.pory"
	checktrainerflag TRAINER_TYRA_AND_IVY
	goto_if 1, Route114_EventScript_LegendaryNPC_27
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_23:
# 226 "data/maps/Route114/scripts.pory"
	checktrainerflag TRAINER_NOLAN
	goto_if 1, Route114_EventScript_LegendaryNPC_22
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_26:
# 229 "data/maps/Route114/scripts.pory"
	checktrainerflag TRAINER_CHARLOTTE
	goto_if 1, Route114_EventScript_LegendaryNPC_30
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_27:
# 228 "data/maps/Route114/scripts.pory"
	checktrainerflag TRAINER_ANGELINA
	goto_if 1, Route114_EventScript_LegendaryNPC_26
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_30:
# 230 "data/maps/Route114/scripts.pory"
	checktrainerflag TRAINER_KAI
	goto_if 1, Route114_EventScript_LegendaryNPC_8
	goto Route114_EventScript_LegendaryNPC_9


Route114_EventScript_Feraligatr::
# 246 "data/maps/Route114/scripts.pory"
	lock
# 247 "data/maps/Route114/scripts.pory"
	faceplayer
# 248 "data/maps/Route114/scripts.pory"
	goto_if_set FLAG_DEFEATED_ROUTE114_FERALIGATR, Route114_EventScript_Feraligatr_Join
# 249 "data/maps/Route114/scripts.pory"
	goto_if_unset FLAG_BADGE05_GET, Route114_EventScript_Feraligatr_PreNorman
# 250 "data/maps/Route114/scripts.pory"
	playmoncry SPECIES_FERALIGATR, 2
# 251 "data/maps/Route114/scripts.pory"
	msgbox Route114_EventScript_Feraligatr_Text_0, MSGBOX_YESNO
# 252 "data/maps/Route114/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route114_EventScript_Feraligatr_2
# 289 "data/maps/Route114/scripts.pory"
	playmoncry SPECIES_FERALIGATR, 2
# 290 "data/maps/Route114/scripts.pory"
	msgbox Route114_EventScript_Feraligatr_Text_3, MSGBOX_DEFAULT
Route114_EventScript_Feraligatr_1:
# 292 "data/maps/Route114/scripts.pory"
	release
	end

Route114_EventScript_Feraligatr_2:
# 253 "data/maps/Route114/scripts.pory"
	playmoncry SPECIES_FERALIGATR, 2
# 254 "data/maps/Route114/scripts.pory"
	msgbox Route114_EventScript_Feraligatr_Text_1, MSGBOX_DEFAULT
# 255 "data/maps/Route114/scripts.pory"
	delay 40
# 256 "data/maps/Route114/scripts.pory"
	waitmoncry
# 257 "data/maps/Route114/scripts.pory"
	setflag FLAG_TOTEM_BATTLE
# 258 "data/maps/Route114/scripts.pory"
	setvar VAR_TOTEM_POKEMON_ATK_BOOST, 2
# 259 "data/maps/Route114/scripts.pory"
	setvar VAR_TOTEM_POKEMON_DEF_BOOST, 2
# 260 "data/maps/Route114/scripts.pory"
	setvar VAR_TOTEM_POKEMON_SP_ATK_BOOST, 2
# 261 "data/maps/Route114/scripts.pory"
	setvar VAR_TOTEM_POKEMON_SP_DEF_BOOST, 2
# 262 "data/maps/Route114/scripts.pory"
	setvar VAR_TOTEM_POKEMON_SPEED_BOOST, 1
# 263 "data/maps/Route114/scripts.pory"
	setvar VAR_TOTEM_POKEMON_ACCURACY_BOOST, 2
# 264 "data/maps/Route114/scripts.pory"
	setvar VAR_TOTEM_POKEMON_EVASION_BOOST, 0
# 265 "data/maps/Route114/scripts.pory"
	setvar VAR_TOTEM_MESSAGE, TOTEM_FIGHT_FERALIGATR
# 267 "data/maps/Route114/scripts.pory"
	setwildbattlewithcustommoves SPECIES_FERALIGATR, 0, ITEM_FERALIGATRITE_Y, MOVE_HYDRO_CANNON, MOVE_HYPER_BEAM, MOVE_BLIZZARD, MOVE_HYPER_VOICE, 0, NATURE_MODEST, 252, 252, 252, 252, 252, 252
# 268 "data/maps/Route114/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 269 "data/maps/Route114/scripts.pory"
	dowildbattle
# 270 "data/maps/Route114/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 271 "data/maps/Route114/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 272 "data/maps/Route114/scripts.pory"
	switch VAR_RESULT
# 273 "data/maps/Route114/scripts.pory"
	case B_OUTCOME_CAUGHT, Route114_EventScript_Feraligatr_6
# 274 "data/maps/Route114/scripts.pory"
	case B_OUTCOME_WON, Route114_EventScript_Feraligatr_6
# 277 "data/maps/Route114/scripts.pory"
	case B_OUTCOME_RAN, Route114_EventScript_Feraligatr_7
# 278 "data/maps/Route114/scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Route114_EventScript_Feraligatr_7
	goto Route114_EventScript_Feraligatr_1

Route114_EventScript_Feraligatr_6:
# 275 "data/maps/Route114/scripts.pory"
	goto Route114_EventScript_Feraligatr_Join
	goto Route114_EventScript_Feraligatr_1

Route114_EventScript_Feraligatr_7:
# 279 "data/maps/Route114/scripts.pory"
	setvar VAR_0x8004, SPECIES_FERALIGATR
# 280 "data/maps/Route114/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 281 "data/maps/Route114/scripts.pory"
	removeobject VAR_LAST_TALKED
# 282 "data/maps/Route114/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 283 "data/maps/Route114/scripts.pory"
	bufferspeciesname 0, VAR_0x8004
# 284 "data/maps/Route114/scripts.pory"
	msgbox Route114_EventScript_Feraligatr_Text_2, MSGBOX_DEFAULT
	goto Route114_EventScript_Feraligatr_1


Route114_EventScript_Feraligatr_PreNorman::
# 297 "data/maps/Route114/scripts.pory"
	message Route114_EventScript_Feraligatr_PreNorman_Text_0
# 298 "data/maps/Route114/scripts.pory"
	waitmessage
# 299 "data/maps/Route114/scripts.pory"
	release
	end


Route114_EventScript_Feraligatr_Join::
# 304 "data/maps/Route114/scripts.pory"
	msgbox Route114_EventScript_Feraligatr_Join_Text_0, MSGBOX_YESNO
# 305 "data/maps/Route114/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route114_EventScript_Feraligatr_Join_2
Route114_EventScript_Feraligatr_Join_1:
# 315 "data/maps/Route114/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ROUTE114_FERALIGATR, Route114_EventScript_Feraligatr_Join_5
Route114_EventScript_Feraligatr_Join_4:
# 322 "data/maps/Route114/scripts.pory"
	release
	end

Route114_EventScript_Feraligatr_Join_2:
# 306 "data/maps/Route114/scripts.pory"
	setflag FLAG_OBTAINED_ROUTE114_FERALIGATR
# 307 "data/maps/Route114/scripts.pory"
	givecustommon SPECIES_FERALIGATR, 50, ITEM_NONE, ITEM_CHERISH_BALL, NATURE_MODEST, 0, 252, 0, 0, 0, 252, 4, 0, 0, 0, 0, 0, 0, MOVE_HYDRO_CANNON, MOVE_HYPER_BEAM, MOVE_BLIZZARD, MOVE_HYPER_VOICE, FALSE
# 308 "data/maps/Route114/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 309 "data/maps/Route114/scripts.pory"
	message Route114_EventScript_Feraligatr_Join_Text_1
# 310 "data/maps/Route114/scripts.pory"
	waitfanfare
# 311 "data/maps/Route114/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 312 "data/maps/Route114/scripts.pory"
	removeobject VAR_LAST_TALKED
# 313 "data/maps/Route114/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Route114_EventScript_Feraligatr_Join_1

Route114_EventScript_Feraligatr_Join_5:
# 316 "data/maps/Route114/scripts.pory"
	setflag FLAG_DEFEATED_ROUTE114_FERALIGATR
# 317 "data/maps/Route114/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 318 "data/maps/Route114/scripts.pory"
	giveitem ITEM_FERALIGATRITE_Y, 1
# 319 "data/maps/Route114/scripts.pory"
	message Route114_EventScript_Feraligatr_Join_Text_2
# 320 "data/maps/Route114/scripts.pory"
	waitfanfare
	goto Route114_EventScript_Feraligatr_Join_4


Route114_EventScript_LegendaryNPC_Text_0:
# 209 "data/maps/Route114/scripts.pory"
	.string "Sage: Are you one of those trainers\n"
	.string "trying to become champion?$"

Route114_EventScript_LegendaryNPC_Text_1:
# 212 "data/maps/Route114/scripts.pory"
	.string "I assume you want confirmation on the\n"
	.string "fact that legendary Pokémon roam this\l"
	.string "route.\p"
	.string "Rest assured: they do. The Legendary\n"
	.string "beastly trio of Raikou, Suicune and\l"
	.string "Entei\p"
	.string "have chosen these wind-swept lands as\n"
	.string "their lair.\p"
	.string "Should you continue to display such\n"
	.string "promise, the privilege of capturing\l"
	.string "these majestic creatures may fall upon\l"
	.string "you.\p"
	.string "Embrace your burgeoning strength, for\n"
	.string "it may lead you to an extraordinary\l"
	.string "fate.$"

Route114_EventScript_LegendaryNPC_Text_2:
# 231 "data/maps/Route114/scripts.pory"
	.string "At last, we meet again. Your prowess in\n"
	.string "battle has been recognized by many,\l"
	.string "including the Beasts. Walk this path\l"
	.string "with your DexNav, and their greatness\l"
	.string "shall be revealed to you.$"

Route114_EventScript_LegendaryNPC_Text_3:
# 234 "data/maps/Route114/scripts.pory"
	.string "Ah, an interesting development indeed.\n"
	.string "Your capabilities have surpassed my\l"
	.string "initial expectations. While your journey\l"
	.string "has not yet reached its climax, you\l"
	.string "have shown remarkable potential. Your\l"
	.string "destiny is calling: finish these last\l"
	.string "few battles to finally greet the\l"
	.string "Beasts.$"

Route114_EventScript_LegendaryNPC_Text_4:
# 239 "data/maps/Route114/scripts.pory"
	.string "Then why are we even talking?$"

Route114_EventScript_Feraligatr_Text_0:
# 251 "data/maps/Route114/scripts.pory"
	.string "With a thunderous roar, Feraligatr\n"
	.string "lunges forward, launching a fierce\l"
	.string "attack against you!$"

Route114_EventScript_Feraligatr_Text_1:
# 254 "data/maps/Route114/scripts.pory"
	.string "Feraligatr: Fera!$"

Route114_EventScript_Feraligatr_Text_2:
# 284 "data/maps/Route114/scripts.pory"
	.string "The {STR_VAR_1} ran away!$"

Route114_EventScript_Feraligatr_Text_3:
# 290 "data/maps/Route114/scripts.pory"
	.string "Feraligatr: Fera...$"

Route114_EventScript_Feraligatr_PreNorman_Text_0:
# 297 "data/maps/Route114/scripts.pory"
	.string "Feraligatr regards you with disdain.\n"
	.string "Maybe come back once you've become\l"
	.string "more formidable?{PAUSE_UNTIL_PRESS}$"

Route114_EventScript_Feraligatr_Join_Text_0:
# 304 "data/maps/Route114/scripts.pory"
	.string "Feraligatr seems to want to join your\n"
	.string "team, will you let this Feraligatr join\l"
	.string "you?$"

Route114_EventScript_Feraligatr_Join_Text_1:
# 309 "data/maps/Route114/scripts.pory"
	.string "{PLAYER} received a Feraligatr!$"

Route114_EventScript_Feraligatr_Join_Text_2:
# 319 "data/maps/Route114/scripts.pory"
	.string "{PLAYER} received a Feraligatrite Y!$"
