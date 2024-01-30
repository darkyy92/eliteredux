# 1 "data/maps/Route117/scripts.pory"

# 2 "data/maps/Route117/scripts.pory"
.set LOCALID_DAYCARE_MAN, 3
# 3 "data/maps/Route117/scripts.pory"

# 4 "data/maps/Route117/scripts.pory"
Route117_MapScripts:: @ 81F397D
# 5 "data/maps/Route117/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_OnTransition
# 6 "data/maps/Route117/scripts.pory"
	.byte 0
# 7 "data/maps/Route117/scripts.pory"

# 8 "data/maps/Route117/scripts.pory"
Route117_OnTransition: @ 81F3983
# 9 "data/maps/Route117/scripts.pory"
	call Route117_EventScript_TryMoveDayCareMan
# 10 "data/maps/Route117/scripts.pory"
	end
# 11 "data/maps/Route117/scripts.pory"

# 12 "data/maps/Route117/scripts.pory"
Route117_EventScript_TryMoveDayCareMan:: @ 81F3989
# 13 "data/maps/Route117/scripts.pory"
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, Route117_EventScript_StopMoveDayCareMan
# 14 "data/maps/Route117/scripts.pory"
	setobjectxyperm LOCALID_DAYCARE_MAN, 47, 6
# 15 "data/maps/Route117/scripts.pory"
Route117_EventScript_StopMoveDayCareMan:: @ 81F3999
# 16 "data/maps/Route117/scripts.pory"
	return
# 17 "data/maps/Route117/scripts.pory"

# 18 "data/maps/Route117/scripts.pory"
Route117_EventScript_Woman:: @ 81F399A
# 19 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_ArentTheseFlowersPretty, MSGBOX_NPC
# 20 "data/maps/Route117/scripts.pory"
	end
# 21 "data/maps/Route117/scripts.pory"

# 22 "data/maps/Route117/scripts.pory"
Route117_EventScript_LittleBoy:: @ 81F39A3
# 23 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AirIsTastyHere, MSGBOX_NPC
# 24 "data/maps/Route117/scripts.pory"
	end
# 25 "data/maps/Route117/scripts.pory"

# 26 "data/maps/Route117/scripts.pory"
Route117_EventScript_Girl:: @ 81F39AC
# 27 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DayCarePokemonHadNewMove, MSGBOX_NPC
# 28 "data/maps/Route117/scripts.pory"
	end
# 29 "data/maps/Route117/scripts.pory"

# 30 "data/maps/Route117/scripts.pory"
Route117_EventScript_RouteSignVerdanturf:: @ 81F39B5
# 31 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_RouteSignVerdanturf, MSGBOX_SIGN
# 32 "data/maps/Route117/scripts.pory"
	end
# 33 "data/maps/Route117/scripts.pory"

# 34 "data/maps/Route117/scripts.pory"
Route117_EventScript_RouteSignMauville:: @ 81F39BE
# 35 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_RouteSignMauville, MSGBOX_SIGN
# 36 "data/maps/Route117/scripts.pory"
	end
# 37 "data/maps/Route117/scripts.pory"

# 38 "data/maps/Route117/scripts.pory"
Route117_EventScript_DayCareSign:: @ 81F39C7
# 39 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DayCareSign, MSGBOX_SIGN
# 40 "data/maps/Route117/scripts.pory"
	end
# 41 "data/maps/Route117/scripts.pory"

# 42 "data/maps/Route117/scripts.pory"
Route117_EventScript_Isaac:: @ 81F39D0
# 43 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_ISAAC_1, Route117_Text_IsaacIntro, Route117_Text_IsaacDefeat, Route117_EventScript_RegisterIsaac
# 44 "data/maps/Route117/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 45 "data/maps/Route117/scripts.pory"
	compare VAR_RESULT, TRUE
# 46 "data/maps/Route117/scripts.pory"
	goto_if_eq Route117_EventScript_RematchIsaac
# 47 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_IsaacPostBattle, MSGBOX_DEFAULT
# 48 "data/maps/Route117/scripts.pory"
	release
# 49 "data/maps/Route117/scripts.pory"
	end
# 50 "data/maps/Route117/scripts.pory"

# 51 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterIsaac:: @ 81F39FC
# 52 "data/maps/Route117/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 53 "data/maps/Route117/scripts.pory"
	waitmovement 0
# 54 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_IsaacRegister, MSGBOX_DEFAULT
# 55 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_ISAAC_1
# 56 "data/maps/Route117/scripts.pory"
	release
# 57 "data/maps/Route117/scripts.pory"
	end
# 58 "data/maps/Route117/scripts.pory"

# 59 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchIsaac:: @ 81F3A1B
# 60 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch TRAINER_ISAAC_1, Route117_Text_IsaacRematchIntro, Route117_Text_IsaacRematchDefeat
# 61 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_IsaacPostRematch, MSGBOX_AUTOCLOSE
# 62 "data/maps/Route117/scripts.pory"
	end
# 63 "data/maps/Route117/scripts.pory"

# 64 "data/maps/Route117/scripts.pory"
Route117_EventScript_Lydia:: @ 81F3A32
# 65 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_LYDIA_1, Route117_Text_LydiaIntro, Route117_Text_LydiaDefeat, Route117_EventScript_RegisterLydia
# 66 "data/maps/Route117/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 67 "data/maps/Route117/scripts.pory"
	compare VAR_RESULT, TRUE
# 68 "data/maps/Route117/scripts.pory"
	goto_if_eq Route117_EventScript_RematchLydia
# 69 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_LydiaPostBattle, MSGBOX_DEFAULT
# 70 "data/maps/Route117/scripts.pory"
	release
# 71 "data/maps/Route117/scripts.pory"
	end
# 72 "data/maps/Route117/scripts.pory"

# 73 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterLydia:: @ 81F3A5E
# 74 "data/maps/Route117/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 75 "data/maps/Route117/scripts.pory"
	waitmovement 0
# 76 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_LydiaRegister, MSGBOX_DEFAULT
# 77 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_LYDIA_1
# 78 "data/maps/Route117/scripts.pory"
	release
# 79 "data/maps/Route117/scripts.pory"
	end
# 80 "data/maps/Route117/scripts.pory"

# 81 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchLydia:: @ 81F3A7D
# 82 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch TRAINER_LYDIA_1, Route117_Text_LydiaRematchIntro, Route117_Text_LydiaRematchDefeat
# 83 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_LydiaPostRematch, MSGBOX_AUTOCLOSE
# 84 "data/maps/Route117/scripts.pory"
	end
# 85 "data/maps/Route117/scripts.pory"

# 86 "data/maps/Route117/scripts.pory"
Route117_EventScript_Dylan:: @ 81F3A94
# 87 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_DYLAN_1, Route117_Text_DylanIntro, Route117_Text_DylanDefeat, Route117_EventScript_RegisterDylan
# 88 "data/maps/Route117/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 89 "data/maps/Route117/scripts.pory"
	compare VAR_RESULT, TRUE
# 90 "data/maps/Route117/scripts.pory"
	goto_if_eq Route117_EventScript_RematchDylan
# 91 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DylanPostBattle, MSGBOX_DEFAULT
# 92 "data/maps/Route117/scripts.pory"
	release
# 93 "data/maps/Route117/scripts.pory"
	end
# 94 "data/maps/Route117/scripts.pory"

# 95 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterDylan:: @ 81F3AC0
# 96 "data/maps/Route117/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 97 "data/maps/Route117/scripts.pory"
	waitmovement 0
# 98 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DylanRegister, MSGBOX_DEFAULT
# 99 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_DYLAN_1
# 100 "data/maps/Route117/scripts.pory"
	release
# 101 "data/maps/Route117/scripts.pory"
	end
# 102 "data/maps/Route117/scripts.pory"

# 103 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchDylan:: @ 81F3ADF
# 104 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch TRAINER_DYLAN_1, Route117_Text_DylanRematchIntro, Route117_Text_DylanRematchDefeat
# 105 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DylanPostRematch, MSGBOX_AUTOCLOSE
# 106 "data/maps/Route117/scripts.pory"
	end
# 107 "data/maps/Route117/scripts.pory"

# 108 "data/maps/Route117/scripts.pory"
Route117_EventScript_Maria:: @ 81F3AF6
# 109 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_MARIA_1, Route117_Text_MariaIntro, Route117_Text_MariaDefeat, Route117_EventScript_RegisterMaria
# 110 "data/maps/Route117/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 111 "data/maps/Route117/scripts.pory"
	compare VAR_RESULT, TRUE
# 112 "data/maps/Route117/scripts.pory"
	goto_if_eq Route117_EventScript_RematchMaria
# 113 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MariaPostBattle, MSGBOX_DEFAULT
# 114 "data/maps/Route117/scripts.pory"
	release
# 115 "data/maps/Route117/scripts.pory"
	end
# 116 "data/maps/Route117/scripts.pory"

# 117 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterMaria:: @ 81F3B22
# 118 "data/maps/Route117/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 119 "data/maps/Route117/scripts.pory"
	waitmovement 0
# 120 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MariaRegister, MSGBOX_DEFAULT
# 121 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_MARIA_1
# 122 "data/maps/Route117/scripts.pory"
	release
# 123 "data/maps/Route117/scripts.pory"
	end
# 124 "data/maps/Route117/scripts.pory"

# 125 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchMaria:: @ 81F3B41
# 126 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch TRAINER_MARIA_1, Route117_Text_MariaRematchIntro, Route117_Text_MariaRematchDefeat
# 127 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MariaPostRematch, MSGBOX_AUTOCLOSE
# 128 "data/maps/Route117/scripts.pory"
	end
# 129 "data/maps/Route117/scripts.pory"

# 130 "data/maps/Route117/scripts.pory"
Route117_EventScript_Derek:: @ 81F3B58
# 131 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_DEREK, Route117_Text_DerekIntro, Route117_Text_DerekDefeat
# 132 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DerekPostBattle, MSGBOX_AUTOCLOSE
# 133 "data/maps/Route117/scripts.pory"
	end
# 134 "data/maps/Route117/scripts.pory"

# 135 "data/maps/Route117/scripts.pory"
Route117_EventScript_Anna:: @ 81F3B6F
# 136 "data/maps/Route117/scripts.pory"
	trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route117_Text_AnnaIntro, Route117_Text_AnnaDefeat, Route117_Text_AnnaNotEnoughMons, Route117_EventScript_RegisterAnna
# 137 "data/maps/Route117/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 138 "data/maps/Route117/scripts.pory"
	compare VAR_RESULT, TRUE
# 139 "data/maps/Route117/scripts.pory"
	goto_if_eq Route117_EventScript_RematchAnna
# 140 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AnnaPostBattle, MSGBOX_DEFAULT
# 141 "data/maps/Route117/scripts.pory"
	release
# 142 "data/maps/Route117/scripts.pory"
	end
# 143 "data/maps/Route117/scripts.pory"

# 144 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterAnna:: @ 81F3B9F
# 145 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AnnaAndMegRegister, MSGBOX_DEFAULT
# 146 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_ANNA_AND_MEG_1
# 147 "data/maps/Route117/scripts.pory"
	release
# 148 "data/maps/Route117/scripts.pory"
	end
# 149 "data/maps/Route117/scripts.pory"

# 150 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchAnna:: @ 81F3BB8
# 151 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route117_Text_AnnaRematchIntro, Route117_Text_AnnaRematchDefeat, Route117_Text_AnnaRematchNotEnoughMons
# 152 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AnnaPostRematch, MSGBOX_AUTOCLOSE
# 153 "data/maps/Route117/scripts.pory"
	end
# 154 "data/maps/Route117/scripts.pory"

# 155 "data/maps/Route117/scripts.pory"
Route117_EventScript_Meg:: @ 81F3BD3
# 156 "data/maps/Route117/scripts.pory"
	trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route117_Text_MegIntro, Route117_Text_MegDefeat, Route117_Text_MegNotEnoughMons, Route117_EventScript_RegisterMeg
# 157 "data/maps/Route117/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 158 "data/maps/Route117/scripts.pory"
	compare VAR_RESULT, TRUE
# 159 "data/maps/Route117/scripts.pory"
	goto_if_eq Route117_EventScript_RematchMeg
# 160 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MegPostBattle, MSGBOX_DEFAULT
# 161 "data/maps/Route117/scripts.pory"
	release
# 162 "data/maps/Route117/scripts.pory"
	end
# 163 "data/maps/Route117/scripts.pory"

# 164 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterMeg:: @ 81F3C03
# 165 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AnnaAndMegRegister, MSGBOX_DEFAULT
# 166 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_ANNA_AND_MEG_1
# 167 "data/maps/Route117/scripts.pory"
	release
# 168 "data/maps/Route117/scripts.pory"
	end
# 169 "data/maps/Route117/scripts.pory"

# 170 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchMeg:: @ 81F3C1C
# 171 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route117_Text_MegRematchIntro, Route117_Text_MegRematchDefeat, Route117_Text_MegRematchNotEnoughMons
# 172 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MegPostRematch, MSGBOX_AUTOCLOSE
# 173 "data/maps/Route117/scripts.pory"
	end
# 174 "data/maps/Route117/scripts.pory"

# 175 "data/maps/Route117/scripts.pory"
Route117_EventScript_Melina:: @ 81F3C37
# 176 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_MELINA, Route117_Text_MelinaIntro, Route117_Text_MelinaDefeat
# 177 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MelinaPostBattle, MSGBOX_AUTOCLOSE
# 178 "data/maps/Route117/scripts.pory"
	end
# 179 "data/maps/Route117/scripts.pory"

# 180 "data/maps/Route117/scripts.pory"
Route117_EventScript_Brandi:: @ 81F3C4E
# 181 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_BRANDI, Route117_Text_BrandiIntro, Route117_Text_BrandiDefeat
# 182 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_BrandiPostBattle, MSGBOX_AUTOCLOSE
# 183 "data/maps/Route117/scripts.pory"
	end
# 184 "data/maps/Route117/scripts.pory"

# 185 "data/maps/Route117/scripts.pory"
Route117_EventScript_Aisha:: @ 81F3C65
# 186 "data/maps/Route117/scripts.pory"
	trainerbattle_single TRAINER_AISHA, Route117_Text_AishaIntro, Route117_Text_AishaDefeat
# 187 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AishaPostBattle, MSGBOX_AUTOCLOSE
# 188 "data/maps/Route117/scripts.pory"
	end
# 189 "data/maps/Route117/scripts.pory"

# 190 "data/maps/Route117/scripts.pory"
Route117_Text_DayCarePokemonHadNewMove: @ 81F3C7C
# 191 "data/maps/Route117/scripts.pory"
	.string "I left my Pokémon at the Day Care.\p"
# 192 "data/maps/Route117/scripts.pory"
	.string "When I got it back, it had a new move\n"
# 193 "data/maps/Route117/scripts.pory"
	.string "that I didn't teach it.\l"
# 194 "data/maps/Route117/scripts.pory"
	.string "I was really, really surprised.$"
# 195 "data/maps/Route117/scripts.pory"

# 196 "data/maps/Route117/scripts.pory"
Route117_Text_ArentTheseFlowersPretty: @ 81F3CFD
# 197 "data/maps/Route117/scripts.pory"
	.string "What do you think?\n"
# 198 "data/maps/Route117/scripts.pory"
	.string "Aren't these flowers pretty?\p"
# 199 "data/maps/Route117/scripts.pory"
	.string "I planted them all!$"
# 200 "data/maps/Route117/scripts.pory"

# 201 "data/maps/Route117/scripts.pory"
Route117_Text_AirIsTastyHere: @ 81F3D41
# 202 "data/maps/Route117/scripts.pory"
	.string "The air is tasty here!$"
# 203 "data/maps/Route117/scripts.pory"

# 204 "data/maps/Route117/scripts.pory"
Route117_Text_RouteSignVerdanturf: @ 81F3D58
# 205 "data/maps/Route117/scripts.pory"
	.string "Route 117\n"
# 206 "data/maps/Route117/scripts.pory"
	.string "{LEFT_ARROW} Verdanturf Town$"
# 207 "data/maps/Route117/scripts.pory"

# 208 "data/maps/Route117/scripts.pory"
Route117_Text_RouteSignMauville: @ 81F3D74
# 209 "data/maps/Route117/scripts.pory"
	.string "Route 117\n"
# 210 "data/maps/Route117/scripts.pory"
	.string "{RIGHT_ARROW} Mauville City$"
# 211 "data/maps/Route117/scripts.pory"

# 212 "data/maps/Route117/scripts.pory"
Route117_Text_DayCareSign: @ 81F3D8E
# 213 "data/maps/Route117/scripts.pory"
	.string "Pokémon Day Care\n"
# 214 "data/maps/Route117/scripts.pory"
	.string "“Let us raise your Pokémon.”$"

Route117_EventScript_LegendaryNPC::
# 218 "data/maps/Route117/scripts.pory"
	lock
# 219 "data/maps/Route117/scripts.pory"
	faceplayer
# 220 "data/maps/Route117/scripts.pory"
	msgbox Route117_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 221 "data/maps/Route117/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route117_EventScript_LegendaryNPC_2
# 249 "data/maps/Route117/scripts.pory"
	msgbox Route117_EventScript_LegendaryNPC_Text_4
Route117_EventScript_LegendaryNPC_1:
# 251 "data/maps/Route117/scripts.pory"
	release
	end

Route117_EventScript_LegendaryNPC_2:
# 222 "data/maps/Route117/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route117_EventScript_LegendaryNPC_5
# 232 "data/maps/Route117/scripts.pory"
	checktrainerflag TRAINER_ISAAC_1
	goto_if 1, Route117_EventScript_LegendaryNPC_11
Route117_EventScript_LegendaryNPC_9:
# 244 "data/maps/Route117/scripts.pory"
	msgbox Route117_EventScript_LegendaryNPC_Text_3
	goto Route117_EventScript_LegendaryNPC_1

Route117_EventScript_LegendaryNPC_5:
# 223 "data/maps/Route117/scripts.pory"
	msgbox Route117_EventScript_LegendaryNPC_Text_1
	goto Route117_EventScript_LegendaryNPC_1

Route117_EventScript_LegendaryNPC_8:
# 241 "data/maps/Route117/scripts.pory"
	msgbox Route117_EventScript_LegendaryNPC_Text_2
	goto Route117_EventScript_LegendaryNPC_1

Route117_EventScript_LegendaryNPC_10:
# 234 "data/maps/Route117/scripts.pory"
	checktrainerflag TRAINER_DYLAN_1
	goto_if 1, Route117_EventScript_LegendaryNPC_15
	goto Route117_EventScript_LegendaryNPC_9

Route117_EventScript_LegendaryNPC_11:
# 233 "data/maps/Route117/scripts.pory"
	checktrainerflag TRAINER_LYDIA_1
	goto_if 1, Route117_EventScript_LegendaryNPC_10
	goto Route117_EventScript_LegendaryNPC_9

Route117_EventScript_LegendaryNPC_14:
# 236 "data/maps/Route117/scripts.pory"
	checktrainerflag TRAINER_DEREK
	goto_if 1, Route117_EventScript_LegendaryNPC_19
	goto Route117_EventScript_LegendaryNPC_9

Route117_EventScript_LegendaryNPC_15:
# 235 "data/maps/Route117/scripts.pory"
	checktrainerflag TRAINER_MARIA_1
	goto_if 1, Route117_EventScript_LegendaryNPC_14
	goto Route117_EventScript_LegendaryNPC_9

Route117_EventScript_LegendaryNPC_18:
# 238 "data/maps/Route117/scripts.pory"
	checktrainerflag TRAINER_MELINA
	goto_if 1, Route117_EventScript_LegendaryNPC_23
	goto Route117_EventScript_LegendaryNPC_9

Route117_EventScript_LegendaryNPC_19:
# 237 "data/maps/Route117/scripts.pory"
	checktrainerflag TRAINER_ANNA_AND_MEG_1
	goto_if 1, Route117_EventScript_LegendaryNPC_18
	goto Route117_EventScript_LegendaryNPC_9

Route117_EventScript_LegendaryNPC_22:
# 240 "data/maps/Route117/scripts.pory"
	checktrainerflag TRAINER_AISHA
	goto_if 1, Route117_EventScript_LegendaryNPC_8
	goto Route117_EventScript_LegendaryNPC_9

Route117_EventScript_LegendaryNPC_23:
# 239 "data/maps/Route117/scripts.pory"
	checktrainerflag TRAINER_BRANDI
	goto_if 1, Route117_EventScript_LegendaryNPC_22
	goto Route117_EventScript_LegendaryNPC_9


Route117_EventScript_Gen8_NPC::
# 256 "data/maps/Route117/scripts.pory"
	lock
# 257 "data/maps/Route117/scripts.pory"
	faceplayer
# 258 "data/maps/Route117/scripts.pory"
	checktrainerflag TRAINER_ISAAC_1
	goto_if 1, Route117_EventScript_Gen8_NPC_5
Route117_EventScript_Gen8_NPC_3:
# 276 "data/maps/Route117/scripts.pory"
	msgbox Route117_EventScript_Gen8_NPC_Text_2
Route117_EventScript_Gen8_NPC_1:
# 278 "data/maps/Route117/scripts.pory"
	release
	end

Route117_EventScript_Gen8_NPC_2:
# 268 "data/maps/Route117/scripts.pory"
	msgbox Route117_EventScript_Gen8_NPC_Text_0
# 269 "data/maps/Route117/scripts.pory"
	givemon SPECIES_APPLIN, 10, ITEM_NONE
# 270 "data/maps/Route117/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 271 "data/maps/Route117/scripts.pory"
	message Route117_EventScript_Gen8_NPC_Text_1
# 272 "data/maps/Route117/scripts.pory"
	waitfanfare
	goto Route117_EventScript_Gen8_NPC_1

Route117_EventScript_Gen8_NPC_4:
# 260 "data/maps/Route117/scripts.pory"
	checktrainerflag TRAINER_DYLAN_1
	goto_if 1, Route117_EventScript_Gen8_NPC_9
	goto Route117_EventScript_Gen8_NPC_3

Route117_EventScript_Gen8_NPC_5:
# 259 "data/maps/Route117/scripts.pory"
	checktrainerflag TRAINER_LYDIA_1
	goto_if 1, Route117_EventScript_Gen8_NPC_4
	goto Route117_EventScript_Gen8_NPC_3

Route117_EventScript_Gen8_NPC_8:
# 262 "data/maps/Route117/scripts.pory"
	checktrainerflag TRAINER_DEREK
	goto_if 1, Route117_EventScript_Gen8_NPC_13
	goto Route117_EventScript_Gen8_NPC_3

Route117_EventScript_Gen8_NPC_9:
# 261 "data/maps/Route117/scripts.pory"
	checktrainerflag TRAINER_MARIA_1
	goto_if 1, Route117_EventScript_Gen8_NPC_8
	goto Route117_EventScript_Gen8_NPC_3

Route117_EventScript_Gen8_NPC_12:
# 264 "data/maps/Route117/scripts.pory"
	checktrainerflag TRAINER_MELINA
	goto_if 1, Route117_EventScript_Gen8_NPC_17
	goto Route117_EventScript_Gen8_NPC_3

Route117_EventScript_Gen8_NPC_13:
# 263 "data/maps/Route117/scripts.pory"
	checktrainerflag TRAINER_ANNA_AND_MEG_1
	goto_if 1, Route117_EventScript_Gen8_NPC_12
	goto Route117_EventScript_Gen8_NPC_3

Route117_EventScript_Gen8_NPC_16:
# 266 "data/maps/Route117/scripts.pory"
	checktrainerflag TRAINER_AISHA
	goto_if 1, Route117_EventScript_Gen8_NPC_2
	goto Route117_EventScript_Gen8_NPC_3

Route117_EventScript_Gen8_NPC_17:
# 265 "data/maps/Route117/scripts.pory"
	checktrainerflag TRAINER_BRANDI
	goto_if 1, Route117_EventScript_Gen8_NPC_16
	goto Route117_EventScript_Gen8_NPC_3


Route117_EventScript_LegendaryNPC_Text_0:
# 220 "data/maps/Route117/scripts.pory"
	.string "Sage: I chant the legend of Light,\n"
	.string "Darkness and Justice, also known as the\l"
	.string "Legend of the hundred-year struggle.\l"
	.string "Will you listen to it?$"

Route117_EventScript_LegendaryNPC_Text_1:
# 223 "data/maps/Route117/scripts.pory"
	.string "Once upon a time, Cresselia, soother of\n"
	.string "troubled souls, was challenged by\l"
	.string "Darkrai, the essence of the Moon's\l"
	.string "darkest allure.\p"
	.string "What Darkrai anticipated as a swift\n"
	.string "engagement instead transformed into a\l"
	.string "struggle lasting a hundred years. Their\l"
	.string "battle ravaged the whole world.\p"
	.string "Skies cloaked under eternal darkness.\n"
	.string "Life whitered. Cities crumbled. Seas\l"
	.string "surged in turmoil.\p"
	.string "But, when all hope was lost, Keldeo, a\n"
	.string "valiant warrior of unyielding spirit,\l"
	.string "swung his sword at the prince of\l"
	.string "darkness, tearing apart his plans for\l"
	.string "domination and ending the century long\l"
	.string "conflict.\p"
	.string "And so, the order once lost was finally\n"
	.string "restored. With Darkrai defeated and his\l"
	.string "malevolent influence banished,\l"
	.string "Cresselia's soothing aura spread\l"
	.string "across the world, mending the scars\l"
	.string "left by the long-standing battle.\p"
	.string "And so, the lands thrived once again, a\n"
	.string "testament to the resilience of the\l"
	.string "human spirit and the everlasting hope\l"
	.string "that resides in the hearts of all.\p"
	.string "If you want to meet these creatures of\n"
	.string "legend, become champion and come back\l"
	.string "to me!$"

Route117_EventScript_LegendaryNPC_Text_2:
# 241 "data/maps/Route117/scripts.pory"
	.string "The might of Justice and purpouse\n"
	.string "shines brightly inside your soul. No one\l"
	.string "is more worthy of meeting Darkrai,\l"
	.string "Cresselia and Keldeo than you. Use your\l"
	.string "DexNav to discover their precise\l"
	.string "location. Which side of their conflict\l"
	.string "will you choose?$"

Route117_EventScript_LegendaryNPC_Text_3:
# 244 "data/maps/Route117/scripts.pory"
	.string "I see a star on that trainer card... you\n"
	.string "have become champion, haven't you?\l"
	.string "Keldeo, Darkrai and Cresselia are almost\l"
	.string "among us. Just defeat these last few\l"
	.string "trainers and you'll be able to meet\l"
	.string "them.$"

Route117_EventScript_LegendaryNPC_Text_4:
# 249 "data/maps/Route117/scripts.pory"
	.string "Ah, a wicked heart that shies away from\n"
	.string "the enchantment of a story. May your\l"
	.string "path find its own light.$"

Route117_EventScript_Gen8_NPC_Text_0:
# 268 "data/maps/Route117/scripts.pory"
	.string "Tasteful battles you provided indeed! I\n"
	.string "love the smell of sweet victory!$"

Route117_EventScript_Gen8_NPC_Text_1:
# 271 "data/maps/Route117/scripts.pory"
	.string "{PLAYER} got an {COLOR BLUE}Applin{COLOR DARK_GRAY} as a gift for\n"
	.string "defeating every trainer here!$"

Route117_EventScript_Gen8_NPC_Text_2:
# 276 "data/maps/Route117/scripts.pory"
	.string "This meadow really is a delight to the\n"
	.string "eye, but I can hook you up with a\l"
	.string "delight for your mouth... for a price.\l"
	.string "And a show!$"
