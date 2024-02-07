# 1 "data/maps/Route106/scripts.pory"

# 2 "data/maps/Route106/scripts.pory"
Route106_MapScripts:: @ 81EE489
# 3 "data/maps/Route106/scripts.pory"
	.byte 0
# 4 "data/maps/Route106/scripts.pory"

# 5 "data/maps/Route106/scripts.pory"
Route106_EventScript_TrainerTipsSign:: @ 81EE48A
# 6 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
# 7 "data/maps/Route106/scripts.pory"
	end
# 8 "data/maps/Route106/scripts.pory"

# 9 "data/maps/Route106/scripts.pory"
Route106_EventScript_Douglas:: @ 81EE493
# 10 "data/maps/Route106/scripts.pory"
	trainerbattle_single TRAINER_DOUGLAS, Route106_Text_DouglasIntro, Route106_Text_DouglasDefeated
# 11 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
# 12 "data/maps/Route106/scripts.pory"
	end
# 13 "data/maps/Route106/scripts.pory"

# 14 "data/maps/Route106/scripts.pory"
Route106_EventScript_Kyla:: @ 81EE4AA
# 15 "data/maps/Route106/scripts.pory"
	trainerbattle_single TRAINER_KYLA, Route106_Text_KylaIntro, Route106_Text_KylaDefeated
# 16 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
# 17 "data/maps/Route106/scripts.pory"
	end
# 18 "data/maps/Route106/scripts.pory"

# 19 "data/maps/Route106/scripts.pory"
Route106_EventScript_Elliot:: @ 81EE4C1
# 20 "data/maps/Route106/scripts.pory"
	trainerbattle_single TRAINER_ELLIOT_1, Route106_Text_ElliotIntro, Route106_Text_ElliotDefeated, Route106_EventScript_ElliotRegisterMatchCallAfterBattle
# 21 "data/maps/Route106/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 22 "data/maps/Route106/scripts.pory"
	compare VAR_RESULT, TRUE
# 23 "data/maps/Route106/scripts.pory"
	goto_if_eq Route106_EventScript_ElliotRematch
# 24 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_ElliotPostBattle, MSGBOX_DEFAULT
# 25 "data/maps/Route106/scripts.pory"
	release
# 26 "data/maps/Route106/scripts.pory"
	end
# 27 "data/maps/Route106/scripts.pory"

# 28 "data/maps/Route106/scripts.pory"
Route106_EventScript_ElliotRegisterMatchCallAfterBattle:: @ 81EE4ED
# 29 "data/maps/Route106/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 30 "data/maps/Route106/scripts.pory"
	waitmovement 0
# 31 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_ElliotRegister, MSGBOX_DEFAULT
# 32 "data/maps/Route106/scripts.pory"
	register_matchcall TRAINER_ELLIOT_1
# 33 "data/maps/Route106/scripts.pory"
	release
# 34 "data/maps/Route106/scripts.pory"
	end
# 35 "data/maps/Route106/scripts.pory"

# 36 "data/maps/Route106/scripts.pory"
Route106_EventScript_ElliotRematch:: @ 81EE50C
# 37 "data/maps/Route106/scripts.pory"
	trainerbattle_rematch TRAINER_ELLIOT_1, Route106_Text_ElliotRematchIntro, Route106_Text_ElliotRematchDefeated
# 38 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_ElliotRematchPostBattle, MSGBOX_AUTOCLOSE
# 39 "data/maps/Route106/scripts.pory"
	end
# 40 "data/maps/Route106/scripts.pory"

# 41 "data/maps/Route106/scripts.pory"
Route106_EventScript_Ned:: @ 81EE523
# 42 "data/maps/Route106/scripts.pory"
	trainerbattle_single TRAINER_NED, Route106_Text_NedIntro, Route106_Text_NedDefeated
# 43 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_NedPostBattle, MSGBOX_AUTOCLOSE
# 44 "data/maps/Route106/scripts.pory"
	end
# 45 "data/maps/Route106/scripts.pory"

# 46 "data/maps/Route106/scripts.pory"
Route106_Text_TrainerTips: @ 81EE53A
# 47 "data/maps/Route106/scripts.pory"
	.string "Trainer Tips\p"
# 48 "data/maps/Route106/scripts.pory"
	.string "Advice on catching Pokémon with a Rod:\n"
# 49 "data/maps/Route106/scripts.pory"
	.string "Press the A Button if you get a bite.$"
