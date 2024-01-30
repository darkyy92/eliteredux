# 1 "data/maps/Route121/scripts.pory"

# 2 "data/maps/Route121/scripts.pory"
.set LOCALID_GRUNT_1, 12
# 3 "data/maps/Route121/scripts.pory"
.set LOCALID_GRUNT_2, 13
# 4 "data/maps/Route121/scripts.pory"
.set LOCALID_GRUNT_3, 14
# 5 "data/maps/Route121/scripts.pory"

# 6 "data/maps/Route121/scripts.pory"
Route121_MapScripts:: @ 81F5DFC
# 7 "data/maps/Route121/scripts.pory"
	.byte 0
# 8 "data/maps/Route121/scripts.pory"

# 9 "data/maps/Route121/scripts.pory"
Route121_EventScript_Skitty::
# 10 "data/maps/Route121/scripts.pory"
	lock
# 11 "data/maps/Route121/scripts.pory"
	faceplayer
# 12 "data/maps/Route121/scripts.pory"
	waitse
# 13 "data/maps/Route121/scripts.pory"
	playmoncry SPECIES_SKITTY, 0
# 14 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_Skitty, MSGBOX_DEFAULT
# 15 "data/maps/Route121/scripts.pory"
	waitmoncry
# 16 "data/maps/Route121/scripts.pory"
	release
# 17 "data/maps/Route121/scripts.pory"
	end
# 18 "data/maps/Route121/scripts.pory"

# 19 "data/maps/Route121/scripts.pory"
Route121_EventScript_Nurse::
# 20 "data/maps/Route121/scripts.pory"
	lock
# 21 "data/maps/Route121/scripts.pory"
	faceplayer
# 22 "data/maps/Route121/scripts.pory"
	msgbox Route121_Nurse_Text_YouNeedHealing, MSGBOX_YESNO
# 23 "data/maps/Route121/scripts.pory"
	compare VAR_RESULT, YES
# 24 "data/maps/Route121/scripts.pory"
	goto_if_eq Route121_Nurse_EventScript_PlayerIsGenji
# 25 "data/maps/Route121/scripts.pory"
	compare VAR_RESULT, NO
# 26 "data/maps/Route121/scripts.pory"
	goto_if_eq Route121_Nurse_EventScript_PlayerNotGenji
# 27 "data/maps/Route121/scripts.pory"
	end
# 28 "data/maps/Route121/scripts.pory"

# 29 "data/maps/Route121/scripts.pory"
Route121_Nurse_EventScript_PlayerIsGenji::
# 30 "data/maps/Route121/scripts.pory"
	closemessage
# 31 "data/maps/Route121/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 32 "data/maps/Route121/scripts.pory"
	msgbox Route121_Nurse_Text_AllBetter, MSGBOX_DEFAULT
# 33 "data/maps/Route121/scripts.pory"
	release
# 34 "data/maps/Route121/scripts.pory"
	end
# 35 "data/maps/Route121/scripts.pory"

# 36 "data/maps/Route121/scripts.pory"
Route121_Nurse_EventScript_PlayerNotGenji::
# 37 "data/maps/Route121/scripts.pory"
	msgbox Route121_Nurse_Text_GoodLuck, MSGBOX_DEFAULT
# 38 "data/maps/Route121/scripts.pory"
	release
# 39 "data/maps/Route121/scripts.pory"
	end
# 40 "data/maps/Route121/scripts.pory"

# 41 "data/maps/Route121/scripts.pory"
Route121_EventScript_Woman:: @ 81F5DFD
# 42 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_AheadLoomsMtPyre, MSGBOX_NPC
# 43 "data/maps/Route121/scripts.pory"
	end
# 44 "data/maps/Route121/scripts.pory"

# 45 "data/maps/Route121/scripts.pory"
Route121_EventScript_MtPyrePierSign:: @ 81F5E06
# 46 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MtPyrePierSign, MSGBOX_SIGN
# 47 "data/maps/Route121/scripts.pory"
	end
# 48 "data/maps/Route121/scripts.pory"

# 49 "data/maps/Route121/scripts.pory"
Route121_EventScript_SafariZoneSign:: @ 81F5E0F
# 50 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_SafariZoneSign, MSGBOX_SIGN
# 51 "data/maps/Route121/scripts.pory"
	end
# 52 "data/maps/Route121/scripts.pory"

# 53 "data/maps/Route121/scripts.pory"
Route121_EventScript_AquaGruntsMoveOut:: @ 81F5E18
# 54 "data/maps/Route121/scripts.pory"
	lockall
# 55 "data/maps/Route121/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 56 "data/maps/Route121/scripts.pory"
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceRight
# 57 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 58 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_OkayMoveOutToMtPyre, MSGBOX_DEFAULT
# 59 "data/maps/Route121/scripts.pory"
	closemessage
# 60 "data/maps/Route121/scripts.pory"
	applymovement LOCALID_GRUNT_1, Route121_Movement_Grunt1Exit
# 61 "data/maps/Route121/scripts.pory"
	applymovement LOCALID_GRUNT_2, Route121_Movement_Grunt2Exit
# 62 "data/maps/Route121/scripts.pory"
	applymovement LOCALID_GRUNT_3, Route121_Movement_Grunt3Exit
# 63 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 64 "data/maps/Route121/scripts.pory"
	fadedefaultbgm
# 65 "data/maps/Route121/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 66 "data/maps/Route121/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 67 "data/maps/Route121/scripts.pory"
	removeobject LOCALID_GRUNT_3
# 68 "data/maps/Route121/scripts.pory"
	setvar VAR_ROUTE121_STATE, 1
# 69 "data/maps/Route121/scripts.pory"
	releaseall
# 70 "data/maps/Route121/scripts.pory"
	end
# 71 "data/maps/Route121/scripts.pory"

# 72 "data/maps/Route121/scripts.pory"
Route121_Movement_Grunt1Exit: @ 81F5E59
# 73 "data/maps/Route121/scripts.pory"
	walk_down
# 74 "data/maps/Route121/scripts.pory"
	walk_down
# 75 "data/maps/Route121/scripts.pory"
	walk_down
# 76 "data/maps/Route121/scripts.pory"
	walk_down
# 77 "data/maps/Route121/scripts.pory"
	walk_down
# 78 "data/maps/Route121/scripts.pory"
	walk_down
# 79 "data/maps/Route121/scripts.pory"
	walk_down
# 80 "data/maps/Route121/scripts.pory"
	walk_down
# 81 "data/maps/Route121/scripts.pory"
	step_end
# 82 "data/maps/Route121/scripts.pory"

# 83 "data/maps/Route121/scripts.pory"
Route121_Movement_Grunt2Exit: @ 81F5E62
# 84 "data/maps/Route121/scripts.pory"
	walk_down
# 85 "data/maps/Route121/scripts.pory"
	walk_down
# 86 "data/maps/Route121/scripts.pory"
	walk_down
# 87 "data/maps/Route121/scripts.pory"
	walk_down
# 88 "data/maps/Route121/scripts.pory"
	walk_down
# 89 "data/maps/Route121/scripts.pory"
	walk_down
# 90 "data/maps/Route121/scripts.pory"
	walk_down
# 91 "data/maps/Route121/scripts.pory"
	walk_down
# 92 "data/maps/Route121/scripts.pory"
	step_end
# 93 "data/maps/Route121/scripts.pory"

# 94 "data/maps/Route121/scripts.pory"
Route121_Movement_Grunt3Exit: @ 81F5E6B
# 95 "data/maps/Route121/scripts.pory"
	walk_down
# 96 "data/maps/Route121/scripts.pory"
	walk_down
# 97 "data/maps/Route121/scripts.pory"
	walk_down
# 98 "data/maps/Route121/scripts.pory"
	walk_down
# 99 "data/maps/Route121/scripts.pory"
	walk_down
# 100 "data/maps/Route121/scripts.pory"
	walk_down
# 101 "data/maps/Route121/scripts.pory"
	walk_down
# 102 "data/maps/Route121/scripts.pory"
	walk_down
# 103 "data/maps/Route121/scripts.pory"
	step_end
# 104 "data/maps/Route121/scripts.pory"

# 105 "data/maps/Route121/scripts.pory"
Route121_EventScript_Vanessa:: @ 81F5E74
# 106 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_VANESSA, Route121_Text_VanessaIntro, Route121_Text_VanessaDefeat
# 107 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_VanessaPostBattle, MSGBOX_AUTOCLOSE
# 108 "data/maps/Route121/scripts.pory"
	end
# 109 "data/maps/Route121/scripts.pory"

# 110 "data/maps/Route121/scripts.pory"
Route121_EventScript_Walter:: @ 81F5E8B
# 111 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_WALTER_1, Route121_Text_WalterIntro, Route121_Text_WalterDefeat, Route121_EventScript_RegisterWalter
# 112 "data/maps/Route121/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 113 "data/maps/Route121/scripts.pory"
	compare VAR_RESULT, TRUE
# 114 "data/maps/Route121/scripts.pory"
	goto_if_eq Route121_EventScript_RematchWalter
# 115 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_WalterPostBattle, MSGBOX_DEFAULT
# 116 "data/maps/Route121/scripts.pory"
	release
# 117 "data/maps/Route121/scripts.pory"
	end
# 118 "data/maps/Route121/scripts.pory"

# 119 "data/maps/Route121/scripts.pory"
Route121_EventScript_RegisterWalter:: @ 81F5EB7
# 120 "data/maps/Route121/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 121 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 122 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_WalterRegister, MSGBOX_DEFAULT
# 123 "data/maps/Route121/scripts.pory"
	register_matchcall TRAINER_WALTER_1
# 124 "data/maps/Route121/scripts.pory"
	release
# 125 "data/maps/Route121/scripts.pory"
	end
# 126 "data/maps/Route121/scripts.pory"

# 127 "data/maps/Route121/scripts.pory"
Route121_EventScript_RematchWalter:: @ 81F5ED6
# 128 "data/maps/Route121/scripts.pory"
	trainerbattle_rematch TRAINER_WALTER_1, Route121_Text_WalterRematchIntro, Route121_Text_WalterRematchDefeat
# 129 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_WalterPostRematch, MSGBOX_AUTOCLOSE
# 130 "data/maps/Route121/scripts.pory"
	end
# 131 "data/maps/Route121/scripts.pory"

# 132 "data/maps/Route121/scripts.pory"
Route121_EventScript_Tammy:: @ 81F5EED
# 133 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_TAMMY, Route121_Text_TammyIntro, Route121_Text_TammyDefeat
# 134 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
# 135 "data/maps/Route121/scripts.pory"
	end
# 136 "data/maps/Route121/scripts.pory"

# 137 "data/maps/Route121/scripts.pory"
Route121_EventScript_Kate:: @ 81F5F04
# 138 "data/maps/Route121/scripts.pory"
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_KateIntro, Route121_Text_KateDefeat, Route121_Text_KateNotEnoughMons
# 139 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_KatePostBattle, MSGBOX_AUTOCLOSE
# 140 "data/maps/Route121/scripts.pory"
	end
# 141 "data/maps/Route121/scripts.pory"

# 142 "data/maps/Route121/scripts.pory"
Route121_EventScript_Joy:: @ 81F5F1F
# 143 "data/maps/Route121/scripts.pory"
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_JoyIntro, Route121_Text_JoyDefeat, Route121_Text_JoyNotEnoughMons
# 144 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_JoyPostBattle, MSGBOX_AUTOCLOSE
# 145 "data/maps/Route121/scripts.pory"
	end
# 146 "data/maps/Route121/scripts.pory"

# 147 "data/maps/Route121/scripts.pory"
Route121_EventScript_Jessica:: @ 81F5F3A
# 148 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_JESSICA_1, Route121_Text_JessicaIntro, Route121_Text_JessicaDefeat, Route121_EventScript_RegisterJessica
# 149 "data/maps/Route121/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 150 "data/maps/Route121/scripts.pory"
	compare VAR_RESULT, TRUE
# 151 "data/maps/Route121/scripts.pory"
	goto_if_eq Route121_EventScript_RematchJessica
# 152 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_JessicaPostBattle, MSGBOX_DEFAULT
# 153 "data/maps/Route121/scripts.pory"
	release
# 154 "data/maps/Route121/scripts.pory"
	end
# 155 "data/maps/Route121/scripts.pory"

# 156 "data/maps/Route121/scripts.pory"
Route121_EventScript_RegisterJessica:: @ 81F5F66
# 157 "data/maps/Route121/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 158 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 159 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_JessicaRegister, MSGBOX_DEFAULT
# 160 "data/maps/Route121/scripts.pory"
	register_matchcall TRAINER_JESSICA_1
# 161 "data/maps/Route121/scripts.pory"
	release
# 162 "data/maps/Route121/scripts.pory"
	end
# 163 "data/maps/Route121/scripts.pory"

# 164 "data/maps/Route121/scripts.pory"
Route121_EventScript_RematchJessica:: @ 81F5F85
# 165 "data/maps/Route121/scripts.pory"
	trainerbattle_rematch TRAINER_JESSICA_1, Route121_Text_JessicaRematchIntro, Route121_Text_JessicaRematchDefeat
# 166 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_JessicaPostRematch, MSGBOX_AUTOCLOSE
# 167 "data/maps/Route121/scripts.pory"
	end
# 168 "data/maps/Route121/scripts.pory"

# 169 "data/maps/Route121/scripts.pory"
Route121_EventScript_Cale:: @ 81F5F9C
# 170 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_CALE, Route121_Text_CaleIntro, Route121_Text_CaleDefeat
# 171 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_CalePostBattle, MSGBOX_AUTOCLOSE
# 172 "data/maps/Route121/scripts.pory"
	end
# 173 "data/maps/Route121/scripts.pory"

# 174 "data/maps/Route121/scripts.pory"
Route121_EventScript_Myles:: @ 81F5FB3
# 175 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_MYLES, Route121_Text_MylesIntro, Route121_Text_MylesDefeat
# 176 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MylesPostBattle, MSGBOX_AUTOCLOSE
# 177 "data/maps/Route121/scripts.pory"
	end
# 178 "data/maps/Route121/scripts.pory"

# 179 "data/maps/Route121/scripts.pory"
Route121_EventScript_Pat:: @ 81F5FCA
# 180 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_PAT, Route121_Text_PatIntro, Route121_Text_PatDefeat
# 181 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_PatPostBattle, MSGBOX_AUTOCLOSE
# 182 "data/maps/Route121/scripts.pory"
	end
# 183 "data/maps/Route121/scripts.pory"

# 184 "data/maps/Route121/scripts.pory"
Route121_EventScript_Marcel:: @ 81F5FE1
# 185 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_MARCEL, Route121_Text_MarcelIntro, Route121_Text_MarcelDefeat
# 186 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MarcelPostBattle, MSGBOX_AUTOCLOSE
# 187 "data/maps/Route121/scripts.pory"
	end
# 188 "data/maps/Route121/scripts.pory"

# 189 "data/maps/Route121/scripts.pory"
Route121_EventScript_Cristin:: @ 81F5FF8
# 190 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_CRISTIN_1, Route121_Text_CristinIntro, Route121_Text_CristinDefeat, Route121_EventScript_RegisterCristin
# 191 "data/maps/Route121/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 192 "data/maps/Route121/scripts.pory"
	compare VAR_RESULT, TRUE
# 193 "data/maps/Route121/scripts.pory"
	goto_if_eq Route121_EventScript_RematchCristin
# 194 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_CristinPostBattle, MSGBOX_DEFAULT
# 195 "data/maps/Route121/scripts.pory"
	release
# 196 "data/maps/Route121/scripts.pory"
	end
# 197 "data/maps/Route121/scripts.pory"

# 198 "data/maps/Route121/scripts.pory"
Route121_EventScript_RegisterCristin:: @ 81F6024
# 199 "data/maps/Route121/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 200 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 201 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_CristinRegister, MSGBOX_DEFAULT
# 202 "data/maps/Route121/scripts.pory"
	register_matchcall TRAINER_CRISTIN_1
# 203 "data/maps/Route121/scripts.pory"
	release
# 204 "data/maps/Route121/scripts.pory"
	end
# 205 "data/maps/Route121/scripts.pory"

# 206 "data/maps/Route121/scripts.pory"
Route121_EventScript_RematchCristin:: @ 81F6043
# 207 "data/maps/Route121/scripts.pory"
	trainerbattle_rematch TRAINER_CRISTIN_1, Route121_Text_CristinRematchIntro, Route121_Text_CristinRematchDefeat
# 208 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_CristinPostRematch, MSGBOX_AUTOCLOSE
# 209 "data/maps/Route121/scripts.pory"
	end
# 210 "data/maps/Route121/scripts.pory"

# 211 "data/maps/Route121/scripts.pory"
Route121_Text_OkayMoveOutToMtPyre: @ 81F605A
# 212 "data/maps/Route121/scripts.pory"
	.string "Okay!\n"
# 213 "data/maps/Route121/scripts.pory"
	.string "We're to move out to Mt. Pyre!$"
# 214 "data/maps/Route121/scripts.pory"

# 215 "data/maps/Route121/scripts.pory"
Route121_Text_AheadLoomsMtPyre: @ 81F607F
# 216 "data/maps/Route121/scripts.pory"
	.string "Ahead looms Mt. Pyre…\p"
# 217 "data/maps/Route121/scripts.pory"
	.string "It is a natural monument to the spirits\n"
# 218 "data/maps/Route121/scripts.pory"
	.string "of departed Pokémon…$"
# 219 "data/maps/Route121/scripts.pory"

# 220 "data/maps/Route121/scripts.pory"
Route121_Text_MtPyrePierSign: @ 81F60D3
# 221 "data/maps/Route121/scripts.pory"
	.string "Mt. Pyre Pier\p"
# 222 "data/maps/Route121/scripts.pory"
	.string "…The sign is old and worn out.\n"
# 223 "data/maps/Route121/scripts.pory"
	.string "The words are barely legible…$"
# 224 "data/maps/Route121/scripts.pory"

# 225 "data/maps/Route121/scripts.pory"
Route121_Text_SafariZoneSign: @ 81F611E
# 226 "data/maps/Route121/scripts.pory"
	.string "“Filled with rare Pokémon!”\n"
# 227 "data/maps/Route121/scripts.pory"
	.string "Safari Zone$"
# 228 "data/maps/Route121/scripts.pory"

# 229 "data/maps/Route121/scripts.pory"
Route121_Text_Skitty:
# 230 "data/maps/Route121/scripts.pory"
	.string "Skitty: Meenya?$"
# 231 "data/maps/Route121/scripts.pory"

# 232 "data/maps/Route121/scripts.pory"
Route121_Nurse_Text_YouNeedHealing:
# 233 "data/maps/Route121/scripts.pory"
	.string "I am a wandering\n"
# 234 "data/maps/Route121/scripts.pory"
	.string "Pokémon Center employee.\p"
# 235 "data/maps/Route121/scripts.pory"
	.string "Why don't I take care of your\n"
# 236 "data/maps/Route121/scripts.pory"
	.string "Pokémon's ills in a flash?$"
# 237 "data/maps/Route121/scripts.pory"

# 238 "data/maps/Route121/scripts.pory"
Route121_Nurse_Text_AllBetter:
# 239 "data/maps/Route121/scripts.pory"
	.string "I took care of all that ailed\n"
# 240 "data/maps/Route121/scripts.pory"
	.string "your Pokémon in a flash!$"
# 241 "data/maps/Route121/scripts.pory"

# 242 "data/maps/Route121/scripts.pory"
Route121_Nurse_Text_GoodLuck:
# 243 "data/maps/Route121/scripts.pory"
	.string "Okay then!\n"
# 244 "data/maps/Route121/scripts.pory"
	.string "Good luck on your journey!$"

Route121_EventScript_LegendaryNPC::
# 247 "data/maps/Route121/scripts.pory"
	lock
# 248 "data/maps/Route121/scripts.pory"
	faceplayer
# 249 "data/maps/Route121/scripts.pory"
	msgbox Route121_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 251 "data/maps/Route121/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route121_EventScript_LegendaryNPC_2
# 299 "data/maps/Route121/scripts.pory"
	msgbox Route121_EventScript_LegendaryNPC_Text_4
Route121_EventScript_LegendaryNPC_1:
# 301 "data/maps/Route121/scripts.pory"
	release
	end

Route121_EventScript_LegendaryNPC_2:
# 252 "data/maps/Route121/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route121_EventScript_LegendaryNPC_5
# 275 "data/maps/Route121/scripts.pory"
	checktrainerflag TRAINER_VANESSA
	goto_if 1, Route121_EventScript_LegendaryNPC_11
Route121_EventScript_LegendaryNPC_9:
# 291 "data/maps/Route121/scripts.pory"
	msgbox Route121_EventScript_LegendaryNPC_Text_3
	goto Route121_EventScript_LegendaryNPC_1

Route121_EventScript_LegendaryNPC_5:
# 253 "data/maps/Route121/scripts.pory"
	msgbox Route121_EventScript_LegendaryNPC_Text_1
	goto Route121_EventScript_LegendaryNPC_1

Route121_EventScript_LegendaryNPC_8:
# 285 "data/maps/Route121/scripts.pory"
	msgbox Route121_EventScript_LegendaryNPC_Text_2
	goto Route121_EventScript_LegendaryNPC_1

Route121_EventScript_LegendaryNPC_10:
# 277 "data/maps/Route121/scripts.pory"
	checktrainerflag TRAINER_TAMMY
	goto_if 1, Route121_EventScript_LegendaryNPC_15
	goto Route121_EventScript_LegendaryNPC_9

Route121_EventScript_LegendaryNPC_11:
# 276 "data/maps/Route121/scripts.pory"
	checktrainerflag TRAINER_WALTER_1
	goto_if 1, Route121_EventScript_LegendaryNPC_10
	goto Route121_EventScript_LegendaryNPC_9

Route121_EventScript_LegendaryNPC_14:
# 279 "data/maps/Route121/scripts.pory"
	checktrainerflag TRAINER_JESSICA_1
	goto_if 1, Route121_EventScript_LegendaryNPC_19
	goto Route121_EventScript_LegendaryNPC_9

Route121_EventScript_LegendaryNPC_15:
# 278 "data/maps/Route121/scripts.pory"
	checktrainerflag TRAINER_KATE_AND_JOY
	goto_if 1, Route121_EventScript_LegendaryNPC_14
	goto Route121_EventScript_LegendaryNPC_9

Route121_EventScript_LegendaryNPC_18:
# 281 "data/maps/Route121/scripts.pory"
	checktrainerflag TRAINER_MYLES
	goto_if 1, Route121_EventScript_LegendaryNPC_23
	goto Route121_EventScript_LegendaryNPC_9

Route121_EventScript_LegendaryNPC_19:
# 280 "data/maps/Route121/scripts.pory"
	checktrainerflag TRAINER_CALE
	goto_if 1, Route121_EventScript_LegendaryNPC_18
	goto Route121_EventScript_LegendaryNPC_9

Route121_EventScript_LegendaryNPC_22:
# 283 "data/maps/Route121/scripts.pory"
	checktrainerflag TRAINER_MARCEL
	goto_if 1, Route121_EventScript_LegendaryNPC_26
	goto Route121_EventScript_LegendaryNPC_9

Route121_EventScript_LegendaryNPC_23:
# 282 "data/maps/Route121/scripts.pory"
	checktrainerflag TRAINER_PAT
	goto_if 1, Route121_EventScript_LegendaryNPC_22
	goto Route121_EventScript_LegendaryNPC_9

Route121_EventScript_LegendaryNPC_26:
# 284 "data/maps/Route121/scripts.pory"
	checktrainerflag TRAINER_CRISTIN_1
	goto_if 1, Route121_EventScript_LegendaryNPC_8
	goto Route121_EventScript_LegendaryNPC_9


Route121_EventScript_LegendaryNPC_Text_0:
# 249 "data/maps/Route121/scripts.pory"
	.string "Sage: Hear me now, fair wanderer, for I\n"
	.string "bring forth a tale of valor and might,\p"
	.string "Of three noble swords that shimmer in\n"
	.string "justice's light.$"

Route121_EventScript_LegendaryNPC_Text_1:
# 253 "data/maps/Route121/scripts.pory"
	.string "In the realm where justice's light doth\n"
	.string "shine,\p"
	.string "Three swords emerged with valor strong\n"
	.string "and true.\p"
	.string "Virizion, Cobalion, Terrakion,\p"
	.string "they wield their blades as the most\n"
	.string "noble, righteous crew.\p"
	.string "Virizion, swift and graceful as the\n"
	.string "breeze,\p"
	.string "With verdant elegance and keen insight.\p"
	.string "Its blade cuts through deceit and\n"
	.string "brings release,\p"
	.string "Ensuring truth prevails with all its\n"
	.string "might.\p"
	.string "Cobalion, sturdy guardian of law,\p"
	.string "With iron will and virtue as its guide.\p"
	.string "Its sword strikes down the wicked,\n"
	.string "without flaw,\p"
	.string "Protecting innocent souls far and wide.\p"
	.string "Terrakion, a force with strength\n"
	.string "untamed,\p"
	.string "Its blade unyielding, never to relent.\p"
	.string "Defending those in need, it stands\n"
	.string "unblamed,\p"
	.string "A beacon of justice brightly sent.\p"
	.string "With hearts determined and spirits\n"
	.string "aligned,\p"
	.string "You embark on a noble quest.\p"
	.string "Two destinies entwined, two wills put to\n"
	.string "test,\p"
	.string "To seize the Swords of Justice, a quest\n"
	.string "expressed.$"

Route121_EventScript_LegendaryNPC_Text_2:
# 285 "data/maps/Route121/scripts.pory"
	.string "Triumphant now, your quest complete,\p"
	.string "your efforts rewarded, the Swords now\n"
	.string "near.\p"
	.string "Show yourself, give them a treat,\p"
	.string "Victory's embrace, your heart holds\n"
	.string "dear.$"

Route121_EventScript_LegendaryNPC_Text_3:
# 291 "data/maps/Route121/scripts.pory"
	.string "You stand at the route's final bend,\p"
	.string "For your journey is near completion,\n"
	.string "victory in sight!\p"
	.string "To catch the Swords of Justice, you\n"
	.string "must transcend,\p"
	.string "by triumphing over others with might!$"

Route121_EventScript_LegendaryNPC_Text_4:
# 299 "data/maps/Route121/scripts.pory"
	.string "Fair traveler, I see your heart seeks a\n"
	.string "different path,\p"
	.string "Yet do reconsider, this tale may kindle\n"
	.string "a lasting aftermath.$"
