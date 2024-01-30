# 1 "data/maps/Route123/scripts.pory"

# 2 "data/maps/Route123/scripts.pory"
Route123_MapScripts:: @ 81F6147
# 3 "data/maps/Route123/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_OnTransition
# 4 "data/maps/Route123/scripts.pory"
	.byte 0
# 5 "data/maps/Route123/scripts.pory"

# 6 "data/maps/Route123/scripts.pory"
Route123_OnTransition: @ 81F614D
# 7 "data/maps/Route123/scripts.pory"
	special SetRoute123Weather
# 8 "data/maps/Route123/scripts.pory"
	end
# 9 "data/maps/Route123/scripts.pory"

# 10 "data/maps/Route123/scripts.pory"
Route123_EventScript_GigaDrainGirl:: @ 81F6151
# 11 "data/maps/Route123/scripts.pory"
	lock
# 12 "data/maps/Route123/scripts.pory"
	faceplayer
# 13 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
# 14 "data/maps/Route123/scripts.pory"
	release
# 15 "data/maps/Route123/scripts.pory"
	end
# 16 "data/maps/Route123/scripts.pory"

# 17 "data/maps/Route123/scripts.pory"
Route123_EventScript_NoGrassMons:: @ 81F619E
# 18 "data/maps/Route123/scripts.pory"
	release
# 19 "data/maps/Route123/scripts.pory"
	end
# 20 "data/maps/Route123/scripts.pory"

# 21 "data/maps/Route123/scripts.pory"
Route123_EventScript_ReceivedGigaDrain:: @ 81F61A0
# 22 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
# 23 "data/maps/Route123/scripts.pory"
	release
# 24 "data/maps/Route123/scripts.pory"
	end
# 25 "data/maps/Route123/scripts.pory"

# 26 "data/maps/Route123/scripts.pory"
Route123_EventScript_RouteSign:: @ 81F61AA
# 27 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_RouteSign, MSGBOX_SIGN
# 28 "data/maps/Route123/scripts.pory"
	end
# 29 "data/maps/Route123/scripts.pory"

# 30 "data/maps/Route123/scripts.pory"
Route123_EventScript_RouteSignMtPyre:: @ 81F61B3
# 31 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_RouteSignMtPyre, MSGBOX_SIGN
# 32 "data/maps/Route123/scripts.pory"
	end
# 33 "data/maps/Route123/scripts.pory"

# 34 "data/maps/Route123/scripts.pory"
Route123_EventScript_BerryMastersHouseSign:: @ 81F61BC
# 35 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_BerryMastersHouse, MSGBOX_SIGN
# 36 "data/maps/Route123/scripts.pory"
	end
# 37 "data/maps/Route123/scripts.pory"

# 38 "data/maps/Route123/scripts.pory"
Route123_EventScript_Wendy:: @ 81F61C5
# 39 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_WENDY, Route123_Text_WendyIntro, Route123_Text_WendyDefeat
# 40 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_WendyPostBattle, MSGBOX_AUTOCLOSE
# 41 "data/maps/Route123/scripts.pory"
	end
# 42 "data/maps/Route123/scripts.pory"

# 43 "data/maps/Route123/scripts.pory"
Route123_EventScript_Braxton:: @ 81F61DC
# 44 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_BRAXTON, Route123_Text_BraxtonIntro, Route123_Text_BraxtonDefeat
# 45 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_BraxtonPostBattle, MSGBOX_AUTOCLOSE
# 46 "data/maps/Route123/scripts.pory"
	end
# 47 "data/maps/Route123/scripts.pory"

# 48 "data/maps/Route123/scripts.pory"
Route123_EventScript_Violet:: @ 81F61F3
# 49 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_VIOLET, Route123_Text_VioletIntro, Route123_Text_VioletDefeat
# 50 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_VioletPostBattle, MSGBOX_AUTOCLOSE
# 51 "data/maps/Route123/scripts.pory"
	end
# 52 "data/maps/Route123/scripts.pory"

# 53 "data/maps/Route123/scripts.pory"
Route123_EventScript_Cameron:: @ 81F620A
# 54 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_CAMERON_1, Route123_Text_CameronIntro, Route123_Text_CameronDefeat, Route123_EventScript_RegisterCameron
# 55 "data/maps/Route123/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 56 "data/maps/Route123/scripts.pory"
	compare VAR_RESULT, TRUE
# 57 "data/maps/Route123/scripts.pory"
	goto_if_eq Route123_EventScript_RematchCameron
# 58 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronPostBattle, MSGBOX_DEFAULT
# 59 "data/maps/Route123/scripts.pory"
	release
# 60 "data/maps/Route123/scripts.pory"
	end
# 61 "data/maps/Route123/scripts.pory"

# 62 "data/maps/Route123/scripts.pory"
Route123_EventScript_RegisterCameron:: @ 81F6236
# 63 "data/maps/Route123/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 64 "data/maps/Route123/scripts.pory"
	waitmovement 0
# 65 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronRegister, MSGBOX_DEFAULT
# 66 "data/maps/Route123/scripts.pory"
	register_matchcall TRAINER_CAMERON_1
# 67 "data/maps/Route123/scripts.pory"
	release
# 68 "data/maps/Route123/scripts.pory"
	end
# 69 "data/maps/Route123/scripts.pory"

# 70 "data/maps/Route123/scripts.pory"
Route123_EventScript_RematchCameron:: @ 81F6255
# 71 "data/maps/Route123/scripts.pory"
	trainerbattle_rematch TRAINER_CAMERON_1, Route123_Text_CameronRematchIntro, Route123_Text_CameronRematchDefeat
# 72 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronPostRematch, MSGBOX_AUTOCLOSE
# 73 "data/maps/Route123/scripts.pory"
	end
# 74 "data/maps/Route123/scripts.pory"

# 75 "data/maps/Route123/scripts.pory"
Route123_EventScript_Jacki:: @ 81F626C
# 76 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_JACKI_1, Route123_Text_JackiIntro, Route123_Text_JackiDefeat, Route123_EventScript_RegisterJacki
# 77 "data/maps/Route123/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 78 "data/maps/Route123/scripts.pory"
	compare VAR_RESULT, TRUE
# 79 "data/maps/Route123/scripts.pory"
	goto_if_eq Route123_EventScript_RematchJacki
# 80 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiPostBattle, MSGBOX_DEFAULT
# 81 "data/maps/Route123/scripts.pory"
	release
# 82 "data/maps/Route123/scripts.pory"
	end
# 83 "data/maps/Route123/scripts.pory"

# 84 "data/maps/Route123/scripts.pory"
Route123_EventScript_RegisterJacki:: @ 81F6298
# 85 "data/maps/Route123/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 86 "data/maps/Route123/scripts.pory"
	waitmovement 0
# 87 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiRegister, MSGBOX_DEFAULT
# 88 "data/maps/Route123/scripts.pory"
	register_matchcall TRAINER_JACKI_1
# 89 "data/maps/Route123/scripts.pory"
	release
# 90 "data/maps/Route123/scripts.pory"
	end
# 91 "data/maps/Route123/scripts.pory"

# 92 "data/maps/Route123/scripts.pory"
Route123_EventScript_RematchJacki:: @ 81F62B7
# 93 "data/maps/Route123/scripts.pory"
	trainerbattle_rematch TRAINER_JACKI_1, Route123_Text_JackiRematchIntro, Route123_Text_JackiRematchDefeat
# 94 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiPostRematch, MSGBOX_AUTOCLOSE
# 95 "data/maps/Route123/scripts.pory"
	end
# 96 "data/maps/Route123/scripts.pory"

# 97 "data/maps/Route123/scripts.pory"
Route123_EventScript_Miu:: @ 81F62CE
# 98 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_MiuIntro, Route123_Text_MiuDefeat, Route123_Text_MiuNotEnoughMons
# 99 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_MiuPostBattle, MSGBOX_AUTOCLOSE
# 100 "data/maps/Route123/scripts.pory"
	end
# 101 "data/maps/Route123/scripts.pory"

# 102 "data/maps/Route123/scripts.pory"
Route123_EventScript_Yuki:: @ 81F62E9
# 103 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_YukiIntro, Route123_Text_YukiDefeat, Route123_Text_YukiNotEnoughMons
# 104 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_YukiPostBattle, MSGBOX_AUTOCLOSE
# 105 "data/maps/Route123/scripts.pory"
	end
# 106 "data/maps/Route123/scripts.pory"

# 107 "data/maps/Route123/scripts.pory"
Route123_EventScript_Kindra:: @ 81F6304
# 108 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_KINDRA, Route123_Text_KindraIntro, Route123_Text_KindraDefeat
# 109 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_KindraPostBattle, MSGBOX_AUTOCLOSE
# 110 "data/maps/Route123/scripts.pory"
	end
# 111 "data/maps/Route123/scripts.pory"

# 112 "data/maps/Route123/scripts.pory"
Route123_EventScript_Frederick:: @ 81F631B
# 113 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_FREDRICK, Route123_Text_FrederickIntro, Route123_Text_FrederickDefeat
# 114 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FrederickPostBattle, MSGBOX_AUTOCLOSE
# 115 "data/maps/Route123/scripts.pory"
	end
# 116 "data/maps/Route123/scripts.pory"

# 117 "data/maps/Route123/scripts.pory"
Route123_EventScript_Alberto:: @ 81F6332
# 118 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_ALBERTO, Route123_Text_AlbertoIntro, Route123_Text_AlbertoDefeat
# 119 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_AlbertoPostBattle, MSGBOX_AUTOCLOSE
# 120 "data/maps/Route123/scripts.pory"
	end
# 121 "data/maps/Route123/scripts.pory"

# 122 "data/maps/Route123/scripts.pory"
Route123_EventScript_Ed:: @ 81F6349
# 123 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_ED, Route123_Text_EdIntro, Route123_Text_EdDefeat
# 124 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_EdPostBattle, MSGBOX_AUTOCLOSE
# 125 "data/maps/Route123/scripts.pory"
	end
# 126 "data/maps/Route123/scripts.pory"

# 127 "data/maps/Route123/scripts.pory"
Route123_EventScript_Kayley:: @ 81F6360
# 128 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_KAYLEY, Route123_Text_KayleyIntro, Route123_Text_KayleyDefeat
# 129 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_KayleyPostBattle, MSGBOX_AUTOCLOSE
# 130 "data/maps/Route123/scripts.pory"
	end
# 131 "data/maps/Route123/scripts.pory"

# 132 "data/maps/Route123/scripts.pory"
Route123_EventScript_Jonas:: @ 81F6377
# 133 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_JONAS, Route123_Text_JonasIntro, Route123_Text_JonasDefeat
# 134 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JonasPostBattle, MSGBOX_AUTOCLOSE
# 135 "data/maps/Route123/scripts.pory"
	end
# 136 "data/maps/Route123/scripts.pory"

# 137 "data/maps/Route123/scripts.pory"
Route123_EventScript_Jazmyn:: @ 81F638E
# 138 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_JAZMYN, Route123_Text_JazmynIntro, Route123_Text_JazmynDefeat
# 139 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JazmynPostBattle, MSGBOX_AUTOCLOSE
# 140 "data/maps/Route123/scripts.pory"
	end
# 141 "data/maps/Route123/scripts.pory"

# 142 "data/maps/Route123/scripts.pory"
Route123_EventScript_Davis:: @ 81F63A5
# 143 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_DAVIS, Route123_Text_DavisIntro, Route123_Text_DavisDefeat
# 144 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_DavisPostBattle, MSGBOX_AUTOCLOSE
# 145 "data/maps/Route123/scripts.pory"
	end
# 146 "data/maps/Route123/scripts.pory"

# 147 "data/maps/Route123/scripts.pory"
Route123_EventScript_Fernando:: @ 81F63BC
# 148 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_FERNANDO_1, Route123_Text_FernandoIntro, Route123_Text_FernandoDefeat, Route123_EventScript_RegisterFernando
# 149 "data/maps/Route123/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 150 "data/maps/Route123/scripts.pory"
	compare VAR_RESULT, TRUE
# 151 "data/maps/Route123/scripts.pory"
	goto_if_eq Route123_EventScript_RematchFernando
# 152 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoPostBattle, MSGBOX_DEFAULT
# 153 "data/maps/Route123/scripts.pory"
	release
# 154 "data/maps/Route123/scripts.pory"
	end
# 155 "data/maps/Route123/scripts.pory"

# 156 "data/maps/Route123/scripts.pory"
Route123_EventScript_RegisterFernando:: @ 81F63E8
# 157 "data/maps/Route123/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 158 "data/maps/Route123/scripts.pory"
	waitmovement 0
# 159 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoRegister, MSGBOX_DEFAULT
# 160 "data/maps/Route123/scripts.pory"
	register_matchcall TRAINER_FERNANDO_1
# 161 "data/maps/Route123/scripts.pory"
	release
# 162 "data/maps/Route123/scripts.pory"
	end
# 163 "data/maps/Route123/scripts.pory"

# 164 "data/maps/Route123/scripts.pory"
Route123_EventScript_RematchFernando:: @ 81F6407
# 165 "data/maps/Route123/scripts.pory"
	trainerbattle_rematch TRAINER_FERNANDO_1, Route123_Text_FernandoRematchIntro, Route123_Text_FernandoRematchDefeat
# 166 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoPostRematch, MSGBOX_AUTOCLOSE
# 167 "data/maps/Route123/scripts.pory"
	end
# 168 "data/maps/Route123/scripts.pory"

# 169 "data/maps/Route123/scripts.pory"
Route123_Text_LoveGrassMonsHaveAny: @ 81F641E
# 170 "data/maps/Route123/scripts.pory"
	.string "I love Grass-type Pokémon!\p"
# 171 "data/maps/Route123/scripts.pory"
	.string "Do you have any Grass-type Pokémon?$"
# 172 "data/maps/Route123/scripts.pory"

# 173 "data/maps/Route123/scripts.pory"
Route123_Text_YouLikeGrassMonsTooHaveThis: @ 81F645D
# 174 "data/maps/Route123/scripts.pory"
	.string "Oh?\p"
# 175 "data/maps/Route123/scripts.pory"
	.string "You like Grass-type Pokémon, too,\n"
# 176 "data/maps/Route123/scripts.pory"
	.string "don't you?\p"
# 177 "data/maps/Route123/scripts.pory"
	.string "I'm so happy, you can have this!\n"
# 178 "data/maps/Route123/scripts.pory"
	.string "It's a token of our friendship.$"
# 179 "data/maps/Route123/scripts.pory"

# 180 "data/maps/Route123/scripts.pory"
Route123_Text_CheckTreesWithMyGrassMon: @ 81F64CF
# 181 "data/maps/Route123/scripts.pory"
	.string "I check trees with my Grass-type\n"
# 182 "data/maps/Route123/scripts.pory"
	.string "Pokémon. I'm like a tree doctor.$"
# 183 "data/maps/Route123/scripts.pory"

# 184 "data/maps/Route123/scripts.pory"
Route123_Text_RouteSign: @ 81F6511
# 185 "data/maps/Route123/scripts.pory"
	.string "{RIGHT_ARROW} Route 123\n"
# 186 "data/maps/Route123/scripts.pory"
	.string "{LEFT_ARROW} Route 118$"
# 187 "data/maps/Route123/scripts.pory"

# 188 "data/maps/Route123/scripts.pory"
Route123_Text_RouteSignMtPyre: @ 81F6529
# 189 "data/maps/Route123/scripts.pory"
	.string "{UP_ARROW} Mt. Pyre\n"
# 190 "data/maps/Route123/scripts.pory"
	.string "“Forbidden to the faint of heart.”$"
# 191 "data/maps/Route123/scripts.pory"

# 192 "data/maps/Route123/scripts.pory"
Route123_Text_BerryMastersHouse: @ 81F6557
# 193 "data/maps/Route123/scripts.pory"
	.string "Berry Master's House$"

Route123_EventScript_LegendaryNPC::
# 197 "data/maps/Route123/scripts.pory"
	lock
# 198 "data/maps/Route123/scripts.pory"
	faceplayer
# 199 "data/maps/Route123/scripts.pory"
	msgbox Route123_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 200 "data/maps/Route123/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route123_EventScript_LegendaryNPC_2
# 232 "data/maps/Route123/scripts.pory"
	msgbox Route123_EventScript_LegendaryNPC_Text_4
Route123_EventScript_LegendaryNPC_1:
# 234 "data/maps/Route123/scripts.pory"
	release
	end

Route123_EventScript_LegendaryNPC_2:
# 201 "data/maps/Route123/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route123_EventScript_LegendaryNPC_5
# 209 "data/maps/Route123/scripts.pory"
	checktrainerflag TRAINER_WENDY
	goto_if 1, Route123_EventScript_LegendaryNPC_11
Route123_EventScript_LegendaryNPC_9:
# 227 "data/maps/Route123/scripts.pory"
	msgbox Route123_EventScript_LegendaryNPC_Text_3
	goto Route123_EventScript_LegendaryNPC_1

Route123_EventScript_LegendaryNPC_5:
# 202 "data/maps/Route123/scripts.pory"
	msgbox Route123_EventScript_LegendaryNPC_Text_1
	goto Route123_EventScript_LegendaryNPC_1

Route123_EventScript_LegendaryNPC_8:
# 224 "data/maps/Route123/scripts.pory"
	msgbox Route123_EventScript_LegendaryNPC_Text_2
	goto Route123_EventScript_LegendaryNPC_1

Route123_EventScript_LegendaryNPC_10:
# 211 "data/maps/Route123/scripts.pory"
	checktrainerflag TRAINER_VIOLET
	goto_if 1, Route123_EventScript_LegendaryNPC_15
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_11:
# 210 "data/maps/Route123/scripts.pory"
	checktrainerflag TRAINER_BRAXTON
	goto_if 1, Route123_EventScript_LegendaryNPC_10
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_14:
# 213 "data/maps/Route123/scripts.pory"
	checktrainerflag TRAINER_JACKI_1
	goto_if 1, Route123_EventScript_LegendaryNPC_19
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_15:
# 212 "data/maps/Route123/scripts.pory"
	checktrainerflag TRAINER_CAMERON_1
	goto_if 1, Route123_EventScript_LegendaryNPC_14
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_18:
# 215 "data/maps/Route123/scripts.pory"
	checktrainerflag TRAINER_KINDRA
	goto_if 1, Route123_EventScript_LegendaryNPC_23
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_19:
# 214 "data/maps/Route123/scripts.pory"
	checktrainerflag TRAINER_MIU_AND_YUKI
	goto_if 1, Route123_EventScript_LegendaryNPC_18
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_22:
# 217 "data/maps/Route123/scripts.pory"
	checktrainerflag TRAINER_ALBERTO
	goto_if 1, Route123_EventScript_LegendaryNPC_27
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_23:
# 216 "data/maps/Route123/scripts.pory"
	checktrainerflag TRAINER_FREDRICK
	goto_if 1, Route123_EventScript_LegendaryNPC_22
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_26:
# 219 "data/maps/Route123/scripts.pory"
	checktrainerflag TRAINER_KAYLEY
	goto_if 1, Route123_EventScript_LegendaryNPC_31
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_27:
# 218 "data/maps/Route123/scripts.pory"
	checktrainerflag TRAINER_ED
	goto_if 1, Route123_EventScript_LegendaryNPC_26
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_30:
# 221 "data/maps/Route123/scripts.pory"
	checktrainerflag TRAINER_JAZMYN
	goto_if 1, Route123_EventScript_LegendaryNPC_35
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_31:
# 220 "data/maps/Route123/scripts.pory"
	checktrainerflag TRAINER_JONAS
	goto_if 1, Route123_EventScript_LegendaryNPC_30
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_34:
# 223 "data/maps/Route123/scripts.pory"
	checktrainerflag TRAINER_FERNANDO_1
	goto_if 1, Route123_EventScript_LegendaryNPC_8
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_35:
# 222 "data/maps/Route123/scripts.pory"
	checktrainerflag TRAINER_DAVIS
	goto_if 1, Route123_EventScript_LegendaryNPC_34
	goto Route123_EventScript_LegendaryNPC_9


Route123_EventScript_Granbullite_Battle::
# 239 "data/maps/Route123/scripts.pory"
	lock
# 240 "data/maps/Route123/scripts.pory"
	faceplayer
# 241 "data/maps/Route123/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, Route123_EventScript_Granbullite_Battle_2
# 263 "data/maps/Route123/scripts.pory"
	msgbox Route123_EventScript_Granbullite_Battle_Text_6, MSGBOX_NPC
Route123_EventScript_Granbullite_Battle_1:
# 265 "data/maps/Route123/scripts.pory"
	release
	end

Route123_EventScript_Granbullite_Battle_2:
# 243 "data/maps/Route123/scripts.pory"
	checktrainerflag TRAINER_GRANBULLITE_ROUTE123
	goto_if 0, Route123_EventScript_Granbullite_Battle_5
# 259 "data/maps/Route123/scripts.pory"
	msgbox Route123_EventScript_Granbullite_Battle_Text_5, MSGBOX_NPC
	goto Route123_EventScript_Granbullite_Battle_1

Route123_EventScript_Granbullite_Battle_5:
# 244 "data/maps/Route123/scripts.pory"
	msgbox Route123_EventScript_Granbullite_Battle_Text_0, MSGBOX_YESNO
# 245 "data/maps/Route123/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route123_EventScript_Granbullite_Battle_8
# 255 "data/maps/Route123/scripts.pory"
	msgbox Route123_EventScript_Granbullite_Battle_Text_4, MSGBOX_NPC
	goto Route123_EventScript_Granbullite_Battle_1

Route123_EventScript_Granbullite_Battle_8:
# 246 "data/maps/Route123/scripts.pory"
	msgbox Route123_EventScript_Granbullite_Battle_Text_1, MSGBOX_NPC
# 248 "data/maps/Route123/scripts.pory"
	trainerbattle_no_intro TRAINER_GRANBULLITE_ROUTE123, Route123_EventScript_Granbullite_Battle_Text_2
# 249 "data/maps/Route123/scripts.pory"
	msgbox Route123_EventScript_Granbullite_Battle_Text_3, MSGBOX_NPC
# 250 "data/maps/Route123/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 251 "data/maps/Route123/scripts.pory"
	giveitem ITEM_GRANBULLITE, 1
# 252 "data/maps/Route123/scripts.pory"
	waitmessage
	goto Route123_EventScript_Granbullite_Battle_1


Route123_EventScript_LegendaryNPC_Text_0:
# 199 "data/maps/Route123/scripts.pory"
	.string "Sage: three Dragons of legend tread\n"
	.string "carefully around us. Want to learn more\l"
	.string "about who they are?$"

Route123_EventScript_LegendaryNPC_Text_1:
# 202 "data/maps/Route123/scripts.pory"
	.string "The armonious imbalance of the Tao\n"
	.string "dragons can be felt all the way from\l"
	.string "here.\p"
	.string "They embody the paradoxical nature of\n"
	.string "our world, one where the fiery, flaming\l"
	.string "passion of Reshiram can coexist with\l"
	.string "the methodical, unburdened rhythm of\l"
	.string "Zekrom.\p"
	.string "They dance in eternal opposition, and\n"
	.string "yet, they somehow managed to find a\l"
	.string "point of equilibrium.\p"
	.string "Kyurem, embodiment of all orderly\n"
	.string "things, is a testament to how even the\l"
	.string "most disorderly of creatures can find\l"
	.string "harmony within themselves.\p"
	.string "Keep training your poise, and come back\n"
	.string "once you've become champion.$"

Route123_EventScript_LegendaryNPC_Text_2:
# 224 "data/maps/Route123/scripts.pory"
	.string "Your Chi is harmonious, and your soul is\n"
	.string "in accord with itself. I grant you the\l"
	.string "privilege of meeting the Tao trio. Use\l"
	.string "your Dexnav, they will now appear.$"

Route123_EventScript_LegendaryNPC_Text_3:
# 227 "data/maps/Route123/scripts.pory"
	.string "Seeker of balance, your efforts have\n"
	.string "been noticed. The Tao dragons have\l"
	.string "taken notice of your actions, but would\l"
	.string "like one final confirmation. Defeat\l"
	.string "every trainer on the route to meet\l"
	.string "them!$"

Route123_EventScript_LegendaryNPC_Text_4:
# 232 "data/maps/Route123/scripts.pory"
	.string "Well then, I suppose we won't get along.$"

Route123_EventScript_Granbullite_Battle_Text_0:
# 244 "data/maps/Route123/scripts.pory"
	.string "Why hello there. Do you want to pet my\n"
	.string "dogs? They don't bite!$"

Route123_EventScript_Granbullite_Battle_Text_1:
# 246 "data/maps/Route123/scripts.pory"
	.string "Ah! Granbull, no!$"

Route123_EventScript_Granbullite_Battle_Text_2:
# 248 "data/maps/Route123/scripts.pory"
	.string "I'm so, so, so, sorry!$"

Route123_EventScript_Granbullite_Battle_Text_3:
# 249 "data/maps/Route123/scripts.pory"
	.string "I'm so sorry! I didn't expect all 6 of\n"
	.string "them to jump out of their Pokéballs like\l"
	.string "that! They usually don't bite. Please,\l"
	.string "take this as compensation.$"

Route123_EventScript_Granbullite_Battle_Text_4:
# 255 "data/maps/Route123/scripts.pory"
	.string "Aww, alright. I swear, they don't bite.$"

Route123_EventScript_Granbullite_Battle_Text_5:
# 259 "data/maps/Route123/scripts.pory"
	.string "Again, I'm so sorry. My dogs are all\n"
	.string "usually very kind, and wouldn't hurt a\l"
	.string "fly!$"

Route123_EventScript_Granbullite_Battle_Text_6:
# 263 "data/maps/Route123/scripts.pory"
	.string "Hm? Ooh. You seem fun. Hey, if you come\n"
	.string "back after defeating those twins in\l"
	.string "Mossdeep, I'll give you something!$"
