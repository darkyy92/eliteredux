.set LOCALID_DAYCARE_MAN, 3

Route117_MapScripts:: @ 81F397D
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_OnTransition
	.byte 0

Route117_OnTransition: @ 81F3983
	call Route117_EventScript_TryMoveDayCareMan
	end

Route117_EventScript_TryMoveDayCareMan:: @ 81F3989
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, Route117_EventScript_StopMoveDayCareMan
	setobjectxyperm LOCALID_DAYCARE_MAN, 47, 6
Route117_EventScript_StopMoveDayCareMan:: @ 81F3999
	return

Route117_EventScript_Woman:: @ 81F399A
	msgbox Route117_Text_ArentTheseFlowersPretty, MSGBOX_NPC
	end

Route117_EventScript_LittleBoy:: @ 81F39A3
	msgbox Route117_Text_AirIsTastyHere, MSGBOX_NPC
	end

Route117_EventScript_Girl:: @ 81F39AC
	msgbox Route117_Text_DayCarePokemonHadNewMove, MSGBOX_NPC
	end

Route117_EventScript_RouteSignVerdanturf:: @ 81F39B5
	msgbox Route117_Text_RouteSignVerdanturf, MSGBOX_SIGN
	end

Route117_EventScript_RouteSignMauville:: @ 81F39BE
	msgbox Route117_Text_RouteSignMauville, MSGBOX_SIGN
	end

Route117_EventScript_DayCareSign:: @ 81F39C7
	msgbox Route117_Text_DayCareSign, MSGBOX_SIGN
	end

Route117_EventScript_Isaac:: @ 81F39D0
	trainerbattle_single TRAINER_ISAAC_1, Route117_Text_IsaacIntro, Route117_Text_IsaacDefeat, Route117_EventScript_RegisterIsaac
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route117_EventScript_RematchIsaac
	msgbox Route117_Text_IsaacPostBattle, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_RegisterIsaac:: @ 81F39FC
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route117_Text_IsaacRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISAAC_1
	release
	end

Route117_EventScript_RematchIsaac:: @ 81F3A1B
	trainerbattle_rematch TRAINER_ISAAC_1, Route117_Text_IsaacRematchIntro, Route117_Text_IsaacRematchDefeat
	msgbox Route117_Text_IsaacPostRematch, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Lydia:: @ 81F3A32
	trainerbattle_single TRAINER_LYDIA_1, Route117_Text_LydiaIntro, Route117_Text_LydiaDefeat, Route117_EventScript_RegisterLydia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route117_EventScript_RematchLydia
	msgbox Route117_Text_LydiaPostBattle, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_RegisterLydia:: @ 81F3A5E
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route117_Text_LydiaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LYDIA_1
	release
	end

Route117_EventScript_RematchLydia:: @ 81F3A7D
	trainerbattle_rematch TRAINER_LYDIA_1, Route117_Text_LydiaRematchIntro, Route117_Text_LydiaRematchDefeat
	msgbox Route117_Text_LydiaPostRematch, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Dylan:: @ 81F3A94
	trainerbattle_single TRAINER_DYLAN_1, Route117_Text_DylanIntro, Route117_Text_DylanDefeat, Route117_EventScript_RegisterDylan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route117_EventScript_RematchDylan
	msgbox Route117_Text_DylanPostBattle, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_RegisterDylan:: @ 81F3AC0
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route117_Text_DylanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DYLAN_1
	release
	end

Route117_EventScript_RematchDylan:: @ 81F3ADF
	trainerbattle_rematch TRAINER_DYLAN_1, Route117_Text_DylanRematchIntro, Route117_Text_DylanRematchDefeat
	msgbox Route117_Text_DylanPostRematch, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Maria:: @ 81F3AF6
	trainerbattle_single TRAINER_MARIA_1, Route117_Text_MariaIntro, Route117_Text_MariaDefeat, Route117_EventScript_RegisterMaria
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route117_EventScript_RematchMaria
	msgbox Route117_Text_MariaPostBattle, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_RegisterMaria:: @ 81F3B22
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route117_Text_MariaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MARIA_1
	release
	end

Route117_EventScript_RematchMaria:: @ 81F3B41
	trainerbattle_rematch TRAINER_MARIA_1, Route117_Text_MariaRematchIntro, Route117_Text_MariaRematchDefeat
	msgbox Route117_Text_MariaPostRematch, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Derek:: @ 81F3B58
	trainerbattle_single TRAINER_DEREK, Route117_Text_DerekIntro, Route117_Text_DerekDefeat
	msgbox Route117_Text_DerekPostBattle, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Anna:: @ 81F3B6F
	trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route117_Text_AnnaIntro, Route117_Text_AnnaDefeat, Route117_Text_AnnaNotEnoughMons, Route117_EventScript_RegisterAnna
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route117_EventScript_RematchAnna
	msgbox Route117_Text_AnnaPostBattle, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_RegisterAnna:: @ 81F3B9F
	msgbox Route117_Text_AnnaAndMegRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANNA_AND_MEG_1
	release
	end

Route117_EventScript_RematchAnna:: @ 81F3BB8
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route117_Text_AnnaRematchIntro, Route117_Text_AnnaRematchDefeat, Route117_Text_AnnaRematchNotEnoughMons
	msgbox Route117_Text_AnnaPostRematch, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Meg:: @ 81F3BD3
	trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route117_Text_MegIntro, Route117_Text_MegDefeat, Route117_Text_MegNotEnoughMons, Route117_EventScript_RegisterMeg
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route117_EventScript_RematchMeg
	msgbox Route117_Text_MegPostBattle, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_RegisterMeg:: @ 81F3C03
	msgbox Route117_Text_AnnaAndMegRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANNA_AND_MEG_1
	release
	end

Route117_EventScript_RematchMeg:: @ 81F3C1C
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route117_Text_MegRematchIntro, Route117_Text_MegRematchDefeat, Route117_Text_MegRematchNotEnoughMons
	msgbox Route117_Text_MegPostRematch, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Melina:: @ 81F3C37
	trainerbattle_single TRAINER_MELINA, Route117_Text_MelinaIntro, Route117_Text_MelinaDefeat
	msgbox Route117_Text_MelinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Brandi:: @ 81F3C4E
	trainerbattle_single TRAINER_BRANDI, Route117_Text_BrandiIntro, Route117_Text_BrandiDefeat
	msgbox Route117_Text_BrandiPostBattle, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Aisha:: @ 81F3C65
	trainerbattle_single TRAINER_AISHA, Route117_Text_AishaIntro, Route117_Text_AishaDefeat
	msgbox Route117_Text_AishaPostBattle, MSGBOX_AUTOCLOSE
	end

Route117_Text_DayCarePokemonHadNewMove: @ 81F3C7C
	.string "I left my Pokémon at the Day Care.\p"
	.string "When I got it back, it had a new move\n"
	.string "that I didn't teach it.\l"
	.string "I was really, really surprised.$"

Route117_Text_ArentTheseFlowersPretty: @ 81F3CFD
	.string "What do you think?\n"
	.string "Aren't these flowers pretty?\p"
	.string "I planted them all!$"

Route117_Text_AirIsTastyHere: @ 81F3D41
	.string "The air is tasty here!$"

Route117_Text_RouteSignVerdanturf: @ 81F3D58
	.string "Route 117\n"
	.string "{LEFT_ARROW} Verdanturf Town$"

Route117_Text_RouteSignMauville: @ 81F3D74
	.string "Route 117\n"
	.string "{RIGHT_ARROW} Mauville City$"

Route117_Text_DayCareSign: @ 81F3D8E
	.string "Pokémon Day Care\n"
	.string "“Let us raise your Pokémon.”$"

Route117_EventScript_LegendaryNPC::
	lock
	faceplayer
	msgbox Route117_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route117_EventScript_LegendaryNPC_2
	msgbox Route117_EventScript_LegendaryNPC_Text_4
Route117_EventScript_LegendaryNPC_1:
	release
	end

Route117_EventScript_LegendaryNPC_2:
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route117_EventScript_LegendaryNPC_5
	checktrainerflag TRAINER_ISAAC_1
	goto_if 1, Route117_EventScript_LegendaryNPC_11
Route117_EventScript_LegendaryNPC_9:
	msgbox Route117_EventScript_LegendaryNPC_Text_3
	goto Route117_EventScript_LegendaryNPC_1

Route117_EventScript_LegendaryNPC_5:
	msgbox Route117_EventScript_LegendaryNPC_Text_1
	goto Route117_EventScript_LegendaryNPC_1

Route117_EventScript_LegendaryNPC_8:
	msgbox Route117_EventScript_LegendaryNPC_Text_2
	goto Route117_EventScript_LegendaryNPC_1

Route117_EventScript_LegendaryNPC_10:
	checktrainerflag TRAINER_DYLAN_1
	goto_if 1, Route117_EventScript_LegendaryNPC_15
	goto Route117_EventScript_LegendaryNPC_9

Route117_EventScript_LegendaryNPC_11:
	checktrainerflag TRAINER_LYDIA_1
	goto_if 1, Route117_EventScript_LegendaryNPC_10
	goto Route117_EventScript_LegendaryNPC_9

Route117_EventScript_LegendaryNPC_14:
	checktrainerflag TRAINER_DEREK
	goto_if 1, Route117_EventScript_LegendaryNPC_19
	goto Route117_EventScript_LegendaryNPC_9

Route117_EventScript_LegendaryNPC_15:
	checktrainerflag TRAINER_MARIA_1
	goto_if 1, Route117_EventScript_LegendaryNPC_14
	goto Route117_EventScript_LegendaryNPC_9

Route117_EventScript_LegendaryNPC_18:
	checktrainerflag TRAINER_MELINA
	goto_if 1, Route117_EventScript_LegendaryNPC_23
	goto Route117_EventScript_LegendaryNPC_9

Route117_EventScript_LegendaryNPC_19:
	checktrainerflag TRAINER_ANNA_AND_MEG_1
	goto_if 1, Route117_EventScript_LegendaryNPC_18
	goto Route117_EventScript_LegendaryNPC_9

Route117_EventScript_LegendaryNPC_22:
	checktrainerflag TRAINER_AISHA
	goto_if 1, Route117_EventScript_LegendaryNPC_8
	goto Route117_EventScript_LegendaryNPC_9

Route117_EventScript_LegendaryNPC_23:
	checktrainerflag TRAINER_BRANDI
	goto_if 1, Route117_EventScript_LegendaryNPC_22
	goto Route117_EventScript_LegendaryNPC_9


Route117_EventScript_Gen8_NPC::
	lock
	faceplayer
	checktrainerflag TRAINER_ISAAC_1
	goto_if 1, Route117_EventScript_Gen8_NPC_5
Route117_EventScript_Gen8_NPC_3:
	msgbox Route117_EventScript_Gen8_NPC_Text_2
Route117_EventScript_Gen8_NPC_1:
	release
	end

Route117_EventScript_Gen8_NPC_2:
	msgbox Route117_EventScript_Gen8_NPC_Text_0
	givemon SPECIES_APPLIN, 10, ITEM_NONE
	playfanfare MUS_OBTAIN_ITEM
	message Route117_EventScript_Gen8_NPC_Text_1
	waitfanfare
	goto Route117_EventScript_Gen8_NPC_1

Route117_EventScript_Gen8_NPC_4:
	checktrainerflag TRAINER_DYLAN_1
	goto_if 1, Route117_EventScript_Gen8_NPC_9
	goto Route117_EventScript_Gen8_NPC_3

Route117_EventScript_Gen8_NPC_5:
	checktrainerflag TRAINER_LYDIA_1
	goto_if 1, Route117_EventScript_Gen8_NPC_4
	goto Route117_EventScript_Gen8_NPC_3

Route117_EventScript_Gen8_NPC_8:
	checktrainerflag TRAINER_DEREK
	goto_if 1, Route117_EventScript_Gen8_NPC_13
	goto Route117_EventScript_Gen8_NPC_3

Route117_EventScript_Gen8_NPC_9:
	checktrainerflag TRAINER_MARIA_1
	goto_if 1, Route117_EventScript_Gen8_NPC_8
	goto Route117_EventScript_Gen8_NPC_3

Route117_EventScript_Gen8_NPC_12:
	checktrainerflag TRAINER_MELINA
	goto_if 1, Route117_EventScript_Gen8_NPC_17
	goto Route117_EventScript_Gen8_NPC_3

Route117_EventScript_Gen8_NPC_13:
	checktrainerflag TRAINER_ANNA_AND_MEG_1
	goto_if 1, Route117_EventScript_Gen8_NPC_12
	goto Route117_EventScript_Gen8_NPC_3

Route117_EventScript_Gen8_NPC_16:
	checktrainerflag TRAINER_AISHA
	goto_if 1, Route117_EventScript_Gen8_NPC_2
	goto Route117_EventScript_Gen8_NPC_3

Route117_EventScript_Gen8_NPC_17:
	checktrainerflag TRAINER_BRANDI
	goto_if 1, Route117_EventScript_Gen8_NPC_16
	goto Route117_EventScript_Gen8_NPC_3


Route117_EventScript_LegendaryNPC_Text_0:
	.string "Sage: I chant the legend of Light,\n"
	.string "Darkness and Justice, also known as\l"
	.string "the Legend of the hundred-year\l"
	.string "struggle. Will you listen to it?$"

Route117_EventScript_LegendaryNPC_Text_1:
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
	.string "restored. With Darkrai defeated and\l"
	.string "his malevolent influence banished,\l"
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
	.string "The might of Justice and purpouse\n"
	.string "shines brightly inside your soul. No one\l"
	.string "is more worthy of meeting Darkrai,\l"
	.string "Cresselia and Keldeo than you. Use your\l"
	.string "DexNav to discover their precise\l"
	.string "location. Which side of their conflict\l"
	.string "will you choose?$"

Route117_EventScript_LegendaryNPC_Text_3:
	.string "I see a star on that trainer card... you\n"
	.string "have become champion, haven't you?\l"
	.string "Keldeo, Darkrai and Cresselia are\l"
	.string "almost among us. Just defeat these\l"
	.string "last few trainers and you'll be able to\l"
	.string "meet them.$"

Route117_EventScript_LegendaryNPC_Text_4:
	.string "Ah, a wicked heart that shies away from\n"
	.string "the enchantment of a story. May your\l"
	.string "path find its own light.$"

Route117_EventScript_Gen8_NPC_Text_0:
	.string "Tasteful battles you provided indeed! I\n"
	.string "love the smell of sweet victory!$"

Route117_EventScript_Gen8_NPC_Text_1:
	.string "{PLAYER} got an {COLOR BLUE}Applin{COLOR DARK_GRAY} as a gift for\n"
	.string "defeating every trainer here!$"

Route117_EventScript_Gen8_NPC_Text_2:
	.string "This meadow really is a delight to the\n"
	.string "eye, but I can hook you up with a\l"
	.string "delight for your mouth... for a price.\l"
	.string "And a show!$"
