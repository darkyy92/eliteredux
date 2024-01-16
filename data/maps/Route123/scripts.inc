Route123_MapScripts:: @ 81F6147
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_OnTransition
	.byte 0

Route123_OnTransition: @ 81F614D
	special SetRoute123Weather
	end

Route123_EventScript_GigaDrainGirl:: @ 81F6151
	lock
	faceplayer
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_NoGrassMons:: @ 81F619E
	release
	end

Route123_EventScript_ReceivedGigaDrain:: @ 81F61A0
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RouteSign:: @ 81F61AA
	msgbox Route123_Text_RouteSign, MSGBOX_SIGN
	end

Route123_EventScript_RouteSignMtPyre:: @ 81F61B3
	msgbox Route123_Text_RouteSignMtPyre, MSGBOX_SIGN
	end

Route123_EventScript_BerryMastersHouseSign:: @ 81F61BC
	msgbox Route123_Text_BerryMastersHouse, MSGBOX_SIGN
	end

Route123_EventScript_Wendy:: @ 81F61C5
	trainerbattle_single TRAINER_WENDY, Route123_Text_WendyIntro, Route123_Text_WendyDefeat
	msgbox Route123_Text_WendyPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Braxton:: @ 81F61DC
	trainerbattle_single TRAINER_BRAXTON, Route123_Text_BraxtonIntro, Route123_Text_BraxtonDefeat
	msgbox Route123_Text_BraxtonPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Violet:: @ 81F61F3
	trainerbattle_single TRAINER_VIOLET, Route123_Text_VioletIntro, Route123_Text_VioletDefeat
	msgbox Route123_Text_VioletPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Cameron:: @ 81F620A
	trainerbattle_single TRAINER_CAMERON_1, Route123_Text_CameronIntro, Route123_Text_CameronDefeat, Route123_EventScript_RegisterCameron
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route123_EventScript_RematchCameron
	msgbox Route123_Text_CameronPostBattle, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RegisterCameron:: @ 81F6236
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route123_Text_CameronRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CAMERON_1
	release
	end

Route123_EventScript_RematchCameron:: @ 81F6255
	trainerbattle_rematch TRAINER_CAMERON_1, Route123_Text_CameronRematchIntro, Route123_Text_CameronRematchDefeat
	msgbox Route123_Text_CameronPostRematch, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Jacki:: @ 81F626C
	trainerbattle_single TRAINER_JACKI_1, Route123_Text_JackiIntro, Route123_Text_JackiDefeat, Route123_EventScript_RegisterJacki
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route123_EventScript_RematchJacki
	msgbox Route123_Text_JackiPostBattle, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RegisterJacki:: @ 81F6298
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route123_Text_JackiRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACKI_1
	release
	end

Route123_EventScript_RematchJacki:: @ 81F62B7
	trainerbattle_rematch TRAINER_JACKI_1, Route123_Text_JackiRematchIntro, Route123_Text_JackiRematchDefeat
	msgbox Route123_Text_JackiPostRematch, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Miu:: @ 81F62CE
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_MiuIntro, Route123_Text_MiuDefeat, Route123_Text_MiuNotEnoughMons
	msgbox Route123_Text_MiuPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Yuki:: @ 81F62E9
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_YukiIntro, Route123_Text_YukiDefeat, Route123_Text_YukiNotEnoughMons
	msgbox Route123_Text_YukiPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Kindra:: @ 81F6304
	trainerbattle_single TRAINER_KINDRA, Route123_Text_KindraIntro, Route123_Text_KindraDefeat
	msgbox Route123_Text_KindraPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Frederick:: @ 81F631B
	trainerbattle_single TRAINER_FREDRICK, Route123_Text_FrederickIntro, Route123_Text_FrederickDefeat
	msgbox Route123_Text_FrederickPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Alberto:: @ 81F6332
	trainerbattle_single TRAINER_ALBERTO, Route123_Text_AlbertoIntro, Route123_Text_AlbertoDefeat
	msgbox Route123_Text_AlbertoPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Ed:: @ 81F6349
	trainerbattle_single TRAINER_ED, Route123_Text_EdIntro, Route123_Text_EdDefeat
	msgbox Route123_Text_EdPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Kayley:: @ 81F6360
	trainerbattle_single TRAINER_KAYLEY, Route123_Text_KayleyIntro, Route123_Text_KayleyDefeat
	msgbox Route123_Text_KayleyPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Jonas:: @ 81F6377
	trainerbattle_single TRAINER_JONAS, Route123_Text_JonasIntro, Route123_Text_JonasDefeat
	msgbox Route123_Text_JonasPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Jazmyn:: @ 81F638E
	trainerbattle_single TRAINER_JAZMYN, Route123_Text_JazmynIntro, Route123_Text_JazmynDefeat
	msgbox Route123_Text_JazmynPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Davis:: @ 81F63A5
	trainerbattle_single TRAINER_DAVIS, Route123_Text_DavisIntro, Route123_Text_DavisDefeat
	msgbox Route123_Text_DavisPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Fernando:: @ 81F63BC
	trainerbattle_single TRAINER_FERNANDO_1, Route123_Text_FernandoIntro, Route123_Text_FernandoDefeat, Route123_EventScript_RegisterFernando
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route123_EventScript_RematchFernando
	msgbox Route123_Text_FernandoPostBattle, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RegisterFernando:: @ 81F63E8
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route123_Text_FernandoRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_FERNANDO_1
	release
	end

Route123_EventScript_RematchFernando:: @ 81F6407
	trainerbattle_rematch TRAINER_FERNANDO_1, Route123_Text_FernandoRematchIntro, Route123_Text_FernandoRematchDefeat
	msgbox Route123_Text_FernandoPostRematch, MSGBOX_AUTOCLOSE
	end

Route123_Text_LoveGrassMonsHaveAny: @ 81F641E
	.string "I love Grass-type Pokémon!\p"
	.string "Do you have any Grass-type Pokémon?$"

Route123_Text_YouLikeGrassMonsTooHaveThis: @ 81F645D
	.string "Oh?\p"
	.string "You like Grass-type Pokémon, too,\n"
	.string "don't you?\p"
	.string "I'm so happy, you can have this!\n"
	.string "It's a token of our friendship.$"

Route123_Text_CheckTreesWithMyGrassMon: @ 81F64CF
	.string "I check trees with my Grass-type\n"
	.string "Pokémon. I'm like a tree doctor.$"

Route123_Text_RouteSign: @ 81F6511
	.string "{RIGHT_ARROW} Route 123\n"
	.string "{LEFT_ARROW} Route 118$"

Route123_Text_RouteSignMtPyre: @ 81F6529
	.string "{UP_ARROW} Mt. Pyre\n"
	.string "“Forbidden to the faint of heart.”$"

Route123_Text_BerryMastersHouse: @ 81F6557
	.string "Berry Master's House$"

Route123_EventScript_LegendaryNPC::
	lock
	faceplayer
	msgbox Route123_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route123_EventScript_LegendaryNPC_2
	msgbox Route123_EventScript_LegendaryNPC_Text_4
Route123_EventScript_LegendaryNPC_1:
	release
	end

Route123_EventScript_LegendaryNPC_2:
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route123_EventScript_LegendaryNPC_5
	checktrainerflag TRAINER_WENDY
	goto_if 1, Route123_EventScript_LegendaryNPC_11
Route123_EventScript_LegendaryNPC_9:
	msgbox Route123_EventScript_LegendaryNPC_Text_3
	goto Route123_EventScript_LegendaryNPC_1

Route123_EventScript_LegendaryNPC_5:
	msgbox Route123_EventScript_LegendaryNPC_Text_1
	goto Route123_EventScript_LegendaryNPC_1

Route123_EventScript_LegendaryNPC_8:
	msgbox Route123_EventScript_LegendaryNPC_Text_2
	goto Route123_EventScript_LegendaryNPC_1

Route123_EventScript_LegendaryNPC_10:
	checktrainerflag TRAINER_VIOLET
	goto_if 1, Route123_EventScript_LegendaryNPC_15
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_11:
	checktrainerflag TRAINER_BRAXTON
	goto_if 1, Route123_EventScript_LegendaryNPC_10
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_14:
	checktrainerflag TRAINER_JACKI_1
	goto_if 1, Route123_EventScript_LegendaryNPC_19
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_15:
	checktrainerflag TRAINER_CAMERON_1
	goto_if 1, Route123_EventScript_LegendaryNPC_14
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_18:
	checktrainerflag TRAINER_KINDRA
	goto_if 1, Route123_EventScript_LegendaryNPC_23
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_19:
	checktrainerflag TRAINER_MIU_AND_YUKI
	goto_if 1, Route123_EventScript_LegendaryNPC_18
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_22:
	checktrainerflag TRAINER_ALBERTO
	goto_if 1, Route123_EventScript_LegendaryNPC_27
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_23:
	checktrainerflag TRAINER_FREDRICK
	goto_if 1, Route123_EventScript_LegendaryNPC_22
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_26:
	checktrainerflag TRAINER_KAYLEY
	goto_if 1, Route123_EventScript_LegendaryNPC_31
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_27:
	checktrainerflag TRAINER_ED
	goto_if 1, Route123_EventScript_LegendaryNPC_26
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_30:
	checktrainerflag TRAINER_JAZMYN
	goto_if 1, Route123_EventScript_LegendaryNPC_35
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_31:
	checktrainerflag TRAINER_JONAS
	goto_if 1, Route123_EventScript_LegendaryNPC_30
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_34:
	checktrainerflag TRAINER_FERNANDO_1
	goto_if 1, Route123_EventScript_LegendaryNPC_8
	goto Route123_EventScript_LegendaryNPC_9

Route123_EventScript_LegendaryNPC_35:
	checktrainerflag TRAINER_DAVIS
	goto_if 1, Route123_EventScript_LegendaryNPC_34
	goto Route123_EventScript_LegendaryNPC_9


Route123_EventScript_Granbullite_Battle::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, Route123_EventScript_Granbullite_Battle_2
	msgbox Route123_EventScript_Granbullite_Battle_Text_6, MSGBOX_NPC
Route123_EventScript_Granbullite_Battle_1:
	release
	end

Route123_EventScript_Granbullite_Battle_2:
	checktrainerflag TRAINER_GRANBULLITE_ROUTE123
	goto_if 0, Route123_EventScript_Granbullite_Battle_5
	msgbox Route123_EventScript_Granbullite_Battle_Text_5, MSGBOX_NPC
	goto Route123_EventScript_Granbullite_Battle_1

Route123_EventScript_Granbullite_Battle_5:
	msgbox Route123_EventScript_Granbullite_Battle_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route123_EventScript_Granbullite_Battle_8
	msgbox Route123_EventScript_Granbullite_Battle_Text_4, MSGBOX_NPC
	goto Route123_EventScript_Granbullite_Battle_1

Route123_EventScript_Granbullite_Battle_8:
	msgbox Route123_EventScript_Granbullite_Battle_Text_1, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_GRANBULLITE_ROUTE123, Route123_EventScript_Granbullite_Battle_Text_2
	msgbox Route123_EventScript_Granbullite_Battle_Text_3, MSGBOX_NPC
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_GRANBULLITE, 1
	waitmessage
	goto Route123_EventScript_Granbullite_Battle_1


Route123_EventScript_LegendaryNPC_Text_0:
	.string "Sage: three Dragons of legend tread\n"
	.string "carefully around us. Want to learn more\l"
	.string "about who they are?$"

Route123_EventScript_LegendaryNPC_Text_1:
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
	.string "Your Chi is harmonious, and your soul is\n"
	.string "in accord with itself. I grant you the\l"
	.string "privilege of meeting the Tao trio. Use\l"
	.string "your Dexnav, they will now appear.$"

Route123_EventScript_LegendaryNPC_Text_3:
	.string "Seeker of balance, your efforts have\n"
	.string "been noticed. The Tao dragons have\l"
	.string "taken notice of your actions, but\l"
	.string "would like one final confirmation.\l"
	.string "Defeat every trainer on the route to\l"
	.string "meet them!$"

Route123_EventScript_LegendaryNPC_Text_4:
	.string "Well then, I suppose we won't get along.$"

Route123_EventScript_Granbullite_Battle_Text_0:
	.string "Why hello there. Do you want to pet my\n"
	.string "dogs? They don't bite!$"

Route123_EventScript_Granbullite_Battle_Text_1:
	.string "Ah! Granbull, no!$"

Route123_EventScript_Granbullite_Battle_Text_2:
	.string "I'm so, so, so, sorry!$"

Route123_EventScript_Granbullite_Battle_Text_3:
	.string "I'm so sorry! I didn't expect all 6 of\n"
	.string "them to jump out of their Pokéballs\l"
	.string "like that! They usually don't bite.\l"
	.string "Please, take this as compensation.$"

Route123_EventScript_Granbullite_Battle_Text_4:
	.string "Aww, alright. I swear, they don't bite.$"

Route123_EventScript_Granbullite_Battle_Text_5:
	.string "Again, I'm so sorry. My dogs are all\n"
	.string "usually very kind, and wouldn't hurt a\l"
	.string "fly!$"

Route123_EventScript_Granbullite_Battle_Text_6:
	.string "Hm? Ooh. You seem fun. Hey, if you come\n"
	.string "back after defeating those twins in\l"
	.string "Mossdeep, I'll give you something!$"
