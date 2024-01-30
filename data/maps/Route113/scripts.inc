# 1 "data/maps/Route113/scripts.pory"

# 2 "data/maps/Route113/scripts.pory"
Route113_MapScripts:: @ 81F2153
# 3 "data/maps/Route113/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route113_OnResume
# 4 "data/maps/Route113/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route113_OnTransition
# 5 "data/maps/Route113/scripts.pory"
	.byte 0
# 6 "data/maps/Route113/scripts.pory"

# 7 "data/maps/Route113/scripts.pory"
Route113_OnResume: @ 81F215E
# 8 "data/maps/Route113/scripts.pory"
	setstepcallback STEP_CB_ASH
# 9 "data/maps/Route113/scripts.pory"
	end
# 10 "data/maps/Route113/scripts.pory"

# 11 "data/maps/Route113/scripts.pory"
Route113_OnTransition: @ 81F2161
# 12 "data/maps/Route113/scripts.pory"
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
# 13 "data/maps/Route113/scripts.pory"
	call Route113_EventScript_CheckSetAshWeather
# 14 "data/maps/Route113/scripts.pory"
	end
# 15 "data/maps/Route113/scripts.pory"

# 16 "data/maps/Route113/scripts.pory"
Route113_EventScript_CheckSetAshWeather:: @ 81F216A
# 17 "data/maps/Route113/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 18 "data/maps/Route113/scripts.pory"
	compare VAR_TEMP_0, 19
# 19 "data/maps/Route113/scripts.pory"
	goto_if_lt Route113_EventScript_DontSetAshWeather
# 20 "data/maps/Route113/scripts.pory"
	compare VAR_TEMP_0, 84
# 21 "data/maps/Route113/scripts.pory"
	goto_if_gt Route113_EventScript_DontSetAshWeather
# 22 "data/maps/Route113/scripts.pory"
	setweather WEATHER_VOLCANIC_ASH
# 23 "data/maps/Route113/scripts.pory"
	return
# 24 "data/maps/Route113/scripts.pory"

# 25 "data/maps/Route113/scripts.pory"
Route113_EventScript_DontSetAshWeather:: @ 81F2189
# 26 "data/maps/Route113/scripts.pory"
	return
# 27 "data/maps/Route113/scripts.pory"

# 28 "data/maps/Route113/scripts.pory"
Route113_EventScript_Gentleman:: @ 81F218A
# 29 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_AshCanBeFashionedIntoGlass, MSGBOX_NPC
# 30 "data/maps/Route113/scripts.pory"
	end
# 31 "data/maps/Route113/scripts.pory"

# 32 "data/maps/Route113/scripts.pory"
Route113_EventScript_NinjaBoy:: @ 81F2193
# 33 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_FunWalkingThroughAsh, MSGBOX_NPC
# 34 "data/maps/Route113/scripts.pory"
	end
# 35 "data/maps/Route113/scripts.pory"

# 36 "data/maps/Route113/scripts.pory"
Route113_EventScript_RouteSign111:: @ 81F219C
# 37 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_RouteSign111, MSGBOX_SIGN
# 38 "data/maps/Route113/scripts.pory"
	end
# 39 "data/maps/Route113/scripts.pory"

# 40 "data/maps/Route113/scripts.pory"
Route113_EventScript_RouteSignFallarbor:: @ 81F21A5
# 41 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_RouteSignFallarbor, MSGBOX_SIGN
# 42 "data/maps/Route113/scripts.pory"
	end
# 43 "data/maps/Route113/scripts.pory"

# 44 "data/maps/Route113/scripts.pory"
Route113_EventScript_GlassWorkshopSign:: @ 81F21AE
# 45 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_GlassWorkshopSign, MSGBOX_SIGN
# 46 "data/maps/Route113/scripts.pory"
	end
# 47 "data/maps/Route113/scripts.pory"

# 48 "data/maps/Route113/scripts.pory"
Route113_EventScript_TrainerTipsRegisterKeyItems:: @ 81F21B7
# 49 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_TrainerTipsRegisterKeyItems, MSGBOX_SIGN
# 50 "data/maps/Route113/scripts.pory"
	end
# 51 "data/maps/Route113/scripts.pory"

# 52 "data/maps/Route113/scripts.pory"
Route113_EventScript_Jaylen:: @ 81F21C0
# 53 "data/maps/Route113/scripts.pory"
	trainerbattle_single TRAINER_JAYLEN, Route113_Text_JaylenIntro, Route113_Text_JaylenDefeat
# 54 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_JaylenPostBattle, MSGBOX_AUTOCLOSE
# 55 "data/maps/Route113/scripts.pory"
	end
# 56 "data/maps/Route113/scripts.pory"

# 57 "data/maps/Route113/scripts.pory"
Route113_EventScript_Dillon:: @ 81F21D7
# 58 "data/maps/Route113/scripts.pory"
	trainerbattle_single TRAINER_DILLON, Route113_Text_DillonIntro, Route113_Text_DillonDefeat
# 59 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_DillonPostBattle, MSGBOX_AUTOCLOSE
# 60 "data/maps/Route113/scripts.pory"
	end
# 61 "data/maps/Route113/scripts.pory"

# 62 "data/maps/Route113/scripts.pory"
Route113_EventScript_Madeline:: @ 81F21EE
# 63 "data/maps/Route113/scripts.pory"
	trainerbattle_single TRAINER_MADELINE_1, Route113_Text_MadelineIntro, Route113_Text_MadelineDefeat, Route113_EventScript_RegisterMadeline
# 64 "data/maps/Route113/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 65 "data/maps/Route113/scripts.pory"
	compare VAR_RESULT, TRUE
# 66 "data/maps/Route113/scripts.pory"
	goto_if_eq Route113_EventScript_RematchMadeline
# 67 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_MadelinePostBattle, MSGBOX_DEFAULT
# 68 "data/maps/Route113/scripts.pory"
	release
# 69 "data/maps/Route113/scripts.pory"
	end
# 70 "data/maps/Route113/scripts.pory"

# 71 "data/maps/Route113/scripts.pory"
Route113_EventScript_RegisterMadeline:: @ 81F221A
# 72 "data/maps/Route113/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 73 "data/maps/Route113/scripts.pory"
	waitmovement 0
# 74 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_MadelineRegister, MSGBOX_DEFAULT
# 75 "data/maps/Route113/scripts.pory"
	register_matchcall TRAINER_MADELINE_1
# 76 "data/maps/Route113/scripts.pory"
	release
# 77 "data/maps/Route113/scripts.pory"
	end
# 78 "data/maps/Route113/scripts.pory"

# 79 "data/maps/Route113/scripts.pory"
Route113_EventScript_RematchMadeline:: @ 81F2239
# 80 "data/maps/Route113/scripts.pory"
	trainerbattle_rematch TRAINER_MADELINE_1, Route113_Text_MadelineRematchIntro, Route113_Text_MadelineRematchDefeat
# 81 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_MadelinePostRematch, MSGBOX_AUTOCLOSE
# 82 "data/maps/Route113/scripts.pory"
	end
# 83 "data/maps/Route113/scripts.pory"

# 84 "data/maps/Route113/scripts.pory"
Route113_EventScript_Lao:: @ 81F2250
# 85 "data/maps/Route113/scripts.pory"
	trainerbattle_single TRAINER_LAO_1, Route113_Text_LaoIntro, Route113_Text_LaoDefeat, Route113_EventScript_RegisterLao
# 86 "data/maps/Route113/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 87 "data/maps/Route113/scripts.pory"
	compare VAR_RESULT, TRUE
# 88 "data/maps/Route113/scripts.pory"
	goto_if_eq Route113_EventScript_RematchLao
# 89 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_LaoPostBattle, MSGBOX_DEFAULT
# 90 "data/maps/Route113/scripts.pory"
	release
# 91 "data/maps/Route113/scripts.pory"
	end
# 92 "data/maps/Route113/scripts.pory"

# 93 "data/maps/Route113/scripts.pory"
Route113_EventScript_RegisterLao:: @ 81F227C
# 94 "data/maps/Route113/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 95 "data/maps/Route113/scripts.pory"
	waitmovement 0
# 96 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_LaoRegister, MSGBOX_DEFAULT
# 97 "data/maps/Route113/scripts.pory"
	register_matchcall TRAINER_LAO_1
# 98 "data/maps/Route113/scripts.pory"
	release
# 99 "data/maps/Route113/scripts.pory"
	end
# 100 "data/maps/Route113/scripts.pory"

# 101 "data/maps/Route113/scripts.pory"
Route113_EventScript_RematchLao:: @ 81F229B
# 102 "data/maps/Route113/scripts.pory"
	trainerbattle_rematch TRAINER_LAO_1, Route113_Text_LaoRematchIntro, Route113_Text_LaoRematchDefeat
# 103 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_LaoPostRematch, MSGBOX_AUTOCLOSE
# 104 "data/maps/Route113/scripts.pory"
	end
# 105 "data/maps/Route113/scripts.pory"

# 106 "data/maps/Route113/scripts.pory"
Route113_EventScript_Lung:: @ 81F22B2
# 107 "data/maps/Route113/scripts.pory"
	trainerbattle_single TRAINER_LUNG, Route113_Text_LungIntro, Route113_Text_LungDefeat
# 108 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_LungPostBattle, MSGBOX_AUTOCLOSE
# 109 "data/maps/Route113/scripts.pory"
	end
# 110 "data/maps/Route113/scripts.pory"

# 111 "data/maps/Route113/scripts.pory"
Route113_EventScript_Tori:: @ 81F22C9
# 112 "data/maps/Route113/scripts.pory"
	trainerbattle_double TRAINER_TORI_AND_TIA, Route113_Text_ToriIntro, Route113_Text_ToriDefeat, Route113_Text_ToriNotEnoughMons
# 113 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_ToriPostBattle, MSGBOX_AUTOCLOSE
# 114 "data/maps/Route113/scripts.pory"
	end
# 115 "data/maps/Route113/scripts.pory"

# 116 "data/maps/Route113/scripts.pory"
Route113_EventScript_Tia:: @ 81F22E4
# 117 "data/maps/Route113/scripts.pory"
	trainerbattle_double TRAINER_TORI_AND_TIA, Route113_Text_TiaIntro, Route113_Text_TiaDefeat, Route113_Text_TiaNotEnoughMons
# 118 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_TiaPostBattle, MSGBOX_AUTOCLOSE
# 119 "data/maps/Route113/scripts.pory"
	end
# 120 "data/maps/Route113/scripts.pory"

# 121 "data/maps/Route113/scripts.pory"
Route113_EventScript_Sophie:: @ 81F22FF
# 122 "data/maps/Route113/scripts.pory"
	trainerbattle_single TRAINER_SOPHIE, Route113_Text_SophieIntro, Route113_Text_SophieDefeat
# 123 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_SophiePostBattle, MSGBOX_AUTOCLOSE
# 124 "data/maps/Route113/scripts.pory"
	end
# 125 "data/maps/Route113/scripts.pory"

# 126 "data/maps/Route113/scripts.pory"
Route113_EventScript_Coby:: @ 81F2316
# 127 "data/maps/Route113/scripts.pory"
	trainerbattle_single TRAINER_COBY, Route113_Text_CobyIntro, Route113_Text_CobyDefeat
# 128 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_CobyPostBattle, MSGBOX_AUTOCLOSE
# 129 "data/maps/Route113/scripts.pory"
	end
# 130 "data/maps/Route113/scripts.pory"

# 131 "data/maps/Route113/scripts.pory"
Route113_EventScript_Lawrence:: @ 81F232D
# 132 "data/maps/Route113/scripts.pory"
	trainerbattle_single TRAINER_LAWRENCE, Route113_Text_LawrenceIntro, Route113_Text_LawrenceDefeat
# 133 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_LawrencePostBattle, MSGBOX_AUTOCLOSE
# 134 "data/maps/Route113/scripts.pory"
	end
# 135 "data/maps/Route113/scripts.pory"

# 136 "data/maps/Route113/scripts.pory"
Route113_EventScript_Wyatt:: @ 81F2344
# 137 "data/maps/Route113/scripts.pory"
	trainerbattle_single TRAINER_WYATT, Route113_Text_WyattIntro, Route113_Text_WyattDefeat
# 138 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_WyattPostBattle, MSGBOX_AUTOCLOSE
# 139 "data/maps/Route113/scripts.pory"
	end
# 140 "data/maps/Route113/scripts.pory"

# 141 "data/maps/Route113/scripts.pory"
Route113_Text_AshCanBeFashionedIntoGlass: @ 81F235B
# 142 "data/maps/Route113/scripts.pory"
	.string "Wahahaha! Today's technology is a\n"
# 143 "data/maps/Route113/scripts.pory"
	.string "wondrous thing!\p"
# 144 "data/maps/Route113/scripts.pory"
	.string "Take this volcanic ash here.\n"
# 145 "data/maps/Route113/scripts.pory"
	.string "It can be fashioned into glass.$"
# 146 "data/maps/Route113/scripts.pory"

# 147 "data/maps/Route113/scripts.pory"
Route113_Text_FunWalkingThroughAsh: @ 81F23CA
# 148 "data/maps/Route113/scripts.pory"
	.string "It's fun walking through the volcano's\n"
# 149 "data/maps/Route113/scripts.pory"
	.string "ashes on the ground and grass.\p"
# 150 "data/maps/Route113/scripts.pory"
	.string "You can see where you walked--it's\n"
# 151 "data/maps/Route113/scripts.pory"
	.string "really neat!$"
# 152 "data/maps/Route113/scripts.pory"

# 153 "data/maps/Route113/scripts.pory"
Route113_Text_RouteSign111: @ 81F2440
# 154 "data/maps/Route113/scripts.pory"
	.string "Route 113\n"
# 155 "data/maps/Route113/scripts.pory"
	.string "{RIGHT_ARROW} Route 111$"
# 156 "data/maps/Route113/scripts.pory"

# 157 "data/maps/Route113/scripts.pory"
Route113_Text_RouteSignFallarbor: @ 81F2456
# 158 "data/maps/Route113/scripts.pory"
	.string "Route 113\n"
# 159 "data/maps/Route113/scripts.pory"
	.string "{LEFT_ARROW} Fallarbor Town$"
# 160 "data/maps/Route113/scripts.pory"

# 161 "data/maps/Route113/scripts.pory"
Route113_Text_TrainerTipsRegisterKeyItems: @ 81F2471
# 162 "data/maps/Route113/scripts.pory"
	.string "Trainer Tips\p"
# 163 "data/maps/Route113/scripts.pory"
	.string "You may register one of the Key Items\n"
# 164 "data/maps/Route113/scripts.pory"
	.string "in your Bag as Select.\p"
# 165 "data/maps/Route113/scripts.pory"
	.string "Simply press Select to use\n"
# 166 "data/maps/Route113/scripts.pory"
	.string "the registered item conveniently.$"
# 167 "data/maps/Route113/scripts.pory"

# 168 "data/maps/Route113/scripts.pory"
Route113_Text_GlassWorkshopSign: @ 81F24F8
# 169 "data/maps/Route113/scripts.pory"
	.string "Glass Workshop\n"
# 170 "data/maps/Route113/scripts.pory"
	.string "“Turning Volcanic Ash into Glass Items”$"

Route113_EventScript_LegendaryNPC::
# 174 "data/maps/Route113/scripts.pory"
	lock
# 175 "data/maps/Route113/scripts.pory"
	faceplayer
# 176 "data/maps/Route113/scripts.pory"
	msgbox Route113_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 177 "data/maps/Route113/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route113_EventScript_LegendaryNPC_2
# 203 "data/maps/Route113/scripts.pory"
	msgbox Route113_EventScript_LegendaryNPC_Text_4, MSGBOX_NPC
Route113_EventScript_LegendaryNPC_1:
# 205 "data/maps/Route113/scripts.pory"
	release
	end

Route113_EventScript_LegendaryNPC_2:
# 178 "data/maps/Route113/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route113_EventScript_LegendaryNPC_5
# 185 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_JAYLEN
	goto_if 1, Route113_EventScript_LegendaryNPC_11
Route113_EventScript_LegendaryNPC_9:
# 198 "data/maps/Route113/scripts.pory"
	msgbox Route113_EventScript_LegendaryNPC_Text_3
	goto Route113_EventScript_LegendaryNPC_1

Route113_EventScript_LegendaryNPC_5:
# 179 "data/maps/Route113/scripts.pory"
	msgbox Route113_EventScript_LegendaryNPC_Text_1
	goto Route113_EventScript_LegendaryNPC_1

Route113_EventScript_LegendaryNPC_8:
# 195 "data/maps/Route113/scripts.pory"
	msgbox Route113_EventScript_LegendaryNPC_Text_2
	goto Route113_EventScript_LegendaryNPC_1

Route113_EventScript_LegendaryNPC_10:
# 187 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_MADELINE_1
	goto_if 1, Route113_EventScript_LegendaryNPC_15
	goto Route113_EventScript_LegendaryNPC_9

Route113_EventScript_LegendaryNPC_11:
# 186 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_DILLON
	goto_if 1, Route113_EventScript_LegendaryNPC_10
	goto Route113_EventScript_LegendaryNPC_9

Route113_EventScript_LegendaryNPC_14:
# 189 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_LUNG
	goto_if 1, Route113_EventScript_LegendaryNPC_19
	goto Route113_EventScript_LegendaryNPC_9

Route113_EventScript_LegendaryNPC_15:
# 188 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_LAO_1
	goto_if 1, Route113_EventScript_LegendaryNPC_14
	goto Route113_EventScript_LegendaryNPC_9

Route113_EventScript_LegendaryNPC_18:
# 191 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_SOPHIE
	goto_if 1, Route113_EventScript_LegendaryNPC_23
	goto Route113_EventScript_LegendaryNPC_9

Route113_EventScript_LegendaryNPC_19:
# 190 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_TORI_AND_TIA
	goto_if 1, Route113_EventScript_LegendaryNPC_18
	goto Route113_EventScript_LegendaryNPC_9

Route113_EventScript_LegendaryNPC_22:
# 193 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_LAWRENCE
	goto_if 1, Route113_EventScript_LegendaryNPC_26
	goto Route113_EventScript_LegendaryNPC_9

Route113_EventScript_LegendaryNPC_23:
# 192 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_COBY
	goto_if 1, Route113_EventScript_LegendaryNPC_22
	goto Route113_EventScript_LegendaryNPC_9

Route113_EventScript_LegendaryNPC_26:
# 194 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_WYATT
	goto_if 1, Route113_EventScript_LegendaryNPC_8
	goto Route113_EventScript_LegendaryNPC_9


Route113_EventScript_Gen8_NPC::
# 210 "data/maps/Route113/scripts.pory"
	lock
# 211 "data/maps/Route113/scripts.pory"
	faceplayer
# 212 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_JAYLEN
	goto_if 1, Route113_EventScript_Gen8_NPC_5
Route113_EventScript_Gen8_NPC_3:
# 231 "data/maps/Route113/scripts.pory"
	msgbox Route113_EventScript_Gen8_NPC_Text_2
Route113_EventScript_Gen8_NPC_1:
# 233 "data/maps/Route113/scripts.pory"
	release
	end

Route113_EventScript_Gen8_NPC_2:
# 223 "data/maps/Route113/scripts.pory"
	msgbox Route113_EventScript_Gen8_NPC_Text_0
# 224 "data/maps/Route113/scripts.pory"
	givemon SPECIES_DREEPY, 10, ITEM_NONE
# 225 "data/maps/Route113/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 226 "data/maps/Route113/scripts.pory"
	message Route113_EventScript_Gen8_NPC_Text_1
# 227 "data/maps/Route113/scripts.pory"
	waitfanfare
	goto Route113_EventScript_Gen8_NPC_1

Route113_EventScript_Gen8_NPC_4:
# 214 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_MADELINE_1
	goto_if 1, Route113_EventScript_Gen8_NPC_9
	goto Route113_EventScript_Gen8_NPC_3

Route113_EventScript_Gen8_NPC_5:
# 213 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_DILLON
	goto_if 1, Route113_EventScript_Gen8_NPC_4
	goto Route113_EventScript_Gen8_NPC_3

Route113_EventScript_Gen8_NPC_8:
# 216 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_LUNG
	goto_if 1, Route113_EventScript_Gen8_NPC_13
	goto Route113_EventScript_Gen8_NPC_3

Route113_EventScript_Gen8_NPC_9:
# 215 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_LAO_1
	goto_if 1, Route113_EventScript_Gen8_NPC_8
	goto Route113_EventScript_Gen8_NPC_3

Route113_EventScript_Gen8_NPC_12:
# 218 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_SOPHIE
	goto_if 1, Route113_EventScript_Gen8_NPC_17
	goto Route113_EventScript_Gen8_NPC_3

Route113_EventScript_Gen8_NPC_13:
# 217 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_TORI_AND_TIA
	goto_if 1, Route113_EventScript_Gen8_NPC_12
	goto Route113_EventScript_Gen8_NPC_3

Route113_EventScript_Gen8_NPC_16:
# 220 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_LAWRENCE
	goto_if 1, Route113_EventScript_Gen8_NPC_20
	goto Route113_EventScript_Gen8_NPC_3

Route113_EventScript_Gen8_NPC_17:
# 219 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_COBY
	goto_if 1, Route113_EventScript_Gen8_NPC_16
	goto Route113_EventScript_Gen8_NPC_3

Route113_EventScript_Gen8_NPC_20:
# 221 "data/maps/Route113/scripts.pory"
	checktrainerflag TRAINER_WYATT
	goto_if 1, Route113_EventScript_Gen8_NPC_2
	goto Route113_EventScript_Gen8_NPC_3


Route113_EventScript_LegendaryNPC_Text_0:
# 176 "data/maps/Route113/scripts.pory"
	.string "Sage: I know the fate of some\n"
	.string "legendary birds you might have heard\l"
	.string "about. Want to find out more?\p"
	.string "$"

Route113_EventScript_LegendaryNPC_Text_1:
# 179 "data/maps/Route113/scripts.pory"
	.string "These ashes seem to have affected\n"
	.string "even the most noble of bird lineages:\p"
	.string "that of Articuno, Zapdos and Moltres.\p"
	.string "Their kin has been spotted roaming this\n"
	.string "smoke-filled land, looking for a valiant\l"
	.string "aid...\p"
	.string "Could you be the one they're looking\n"
	.string "for? Come back after becoming champion\l"
	.string "to meet them.$"

Route113_EventScript_LegendaryNPC_Text_2:
# 195 "data/maps/Route113/scripts.pory"
	.string "You are now worthy of catching the\n"
	.string "legendary birds trio. Just use your\l"
	.string "DexNav, they will now appear. Their\l"
	.string "appearance might even surprise you...$"

Route113_EventScript_LegendaryNPC_Text_3:
# 198 "data/maps/Route113/scripts.pory"
	.string "I heard of your accomplishments, and\n"
	.string "the birds must have sensed that too.\l"
	.string "Show these last few trainers what\l"
	.string "you're capable of to finally meet them.$"

Route113_EventScript_LegendaryNPC_Text_4:
# 203 "data/maps/Route113/scripts.pory"
	.string "Clearly you must be very uninformed...$"

Route113_EventScript_Gen8_NPC_Text_0:
# 223 "data/maps/Route113/scripts.pory"
	.string "Way to go champ! Here, take this little\n"
	.string "creature and nurture it, you'll reach\l"
	.string "the ends of the world if you stick with\l"
	.string "it enough!$"

Route113_EventScript_Gen8_NPC_Text_1:
# 226 "data/maps/Route113/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Dreepy{COLOR DARK_GRAY} as a gift for\n"
	.string "defeating every trainer here!$"

Route113_EventScript_Gen8_NPC_Text_2:
# 231 "data/maps/Route113/scripts.pory"
	.string "This raging volcano calls for a raging\n"
	.string "trainer! Soar to new heights in battle\l"
	.string "to meet the ghost of a powerful\l"
	.string "caretaker!$"
