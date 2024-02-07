# 1 "data/maps/Route107/scripts.pory"

# 2 "data/maps/Route107/scripts.pory"
Route107_MapScripts:: @ 81EE594
# 3 "data/maps/Route107/scripts.pory"
	.byte 0
# 4 "data/maps/Route107/scripts.pory"

# 5 "data/maps/Route107/scripts.pory"
Route107_EventScript_Darrin:: @ 81EE595
# 6 "data/maps/Route107/scripts.pory"
	trainerbattle_single TRAINER_DARRIN, Route107_Text_DarrinIntro, Route107_Text_DarrinDefeated
# 7 "data/maps/Route107/scripts.pory"
	msgbox Route107_Text_DarrinPostBattle, MSGBOX_AUTOCLOSE
# 8 "data/maps/Route107/scripts.pory"
	end
# 9 "data/maps/Route107/scripts.pory"

# 10 "data/maps/Route107/scripts.pory"
Route107_EventScript_Tony:: @ 81EE5AC
# 11 "data/maps/Route107/scripts.pory"
	trainerbattle_single TRAINER_TONY_1, Route107_Text_TonyIntro, Route107_Text_TonyDefeated, Route107_EventScript_TonyRegisterMatchCallAfterBattle
# 12 "data/maps/Route107/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 13 "data/maps/Route107/scripts.pory"
	compare VAR_RESULT, TRUE
# 14 "data/maps/Route107/scripts.pory"
	goto_if_eq Route107_EventScript_TonyRematch
# 15 "data/maps/Route107/scripts.pory"
	msgbox Route107_Text_TonyPostBattle, MSGBOX_DEFAULT
# 16 "data/maps/Route107/scripts.pory"
	release
# 17 "data/maps/Route107/scripts.pory"
	end
# 18 "data/maps/Route107/scripts.pory"

# 19 "data/maps/Route107/scripts.pory"
Route107_EventScript_TonyRegisterMatchCallAfterBattle:: @ 81EE5D8
# 20 "data/maps/Route107/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 21 "data/maps/Route107/scripts.pory"
	waitmovement 0
# 22 "data/maps/Route107/scripts.pory"
	msgbox Route107_Text_TonyRegister, MSGBOX_DEFAULT
# 23 "data/maps/Route107/scripts.pory"
	register_matchcall TRAINER_TONY_1
# 24 "data/maps/Route107/scripts.pory"
	release
# 25 "data/maps/Route107/scripts.pory"
	end
# 26 "data/maps/Route107/scripts.pory"

# 27 "data/maps/Route107/scripts.pory"
Route107_EventScript_TonyRematch:: @ 81EE5F7
# 28 "data/maps/Route107/scripts.pory"
	trainerbattle_rematch TRAINER_TONY_1, Route107_Text_TonyRematchIntro, Route107_Text_TonyRematchDefeated
# 29 "data/maps/Route107/scripts.pory"
	msgbox Route107_Text_TonyRematchPostBattle, MSGBOX_AUTOCLOSE
# 30 "data/maps/Route107/scripts.pory"
	end
# 31 "data/maps/Route107/scripts.pory"

# 32 "data/maps/Route107/scripts.pory"
Route107_EventScript_Denise:: @ 81EE60E
# 33 "data/maps/Route107/scripts.pory"
	trainerbattle_single TRAINER_DENISE, Route107_Text_DeniseIntro, Route107_Text_DeniseDefeated
# 34 "data/maps/Route107/scripts.pory"
	msgbox Route107_Text_DenisePostBattle, MSGBOX_AUTOCLOSE
# 35 "data/maps/Route107/scripts.pory"
	end
# 36 "data/maps/Route107/scripts.pory"

# 37 "data/maps/Route107/scripts.pory"
Route107_EventScript_Beth:: @ 81EE625
# 38 "data/maps/Route107/scripts.pory"
	trainerbattle_single TRAINER_BETH, Route107_Text_BethIntro, Route107_Text_BethDefeated
# 39 "data/maps/Route107/scripts.pory"
	msgbox Route107_Text_BethPostBattle, MSGBOX_AUTOCLOSE
# 40 "data/maps/Route107/scripts.pory"
	end
# 41 "data/maps/Route107/scripts.pory"

# 42 "data/maps/Route107/scripts.pory"
Route107_EventScript_Lisa:: @ 81EE63C
# 43 "data/maps/Route107/scripts.pory"
	trainerbattle_double TRAINER_LISA_AND_RAY, Route107_Text_LisaIntro, Route107_Text_LisaDefeated, Route107_Text_LisaNotEnoughPokemon
# 44 "data/maps/Route107/scripts.pory"
	msgbox Route107_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
# 45 "data/maps/Route107/scripts.pory"
	end
# 46 "data/maps/Route107/scripts.pory"

# 47 "data/maps/Route107/scripts.pory"
Route107_EventScript_Ray:: @ 81EE657
# 48 "data/maps/Route107/scripts.pory"
	trainerbattle_double TRAINER_LISA_AND_RAY, Route107_Text_RayIntro, Route107_Text_RayDefeated, Route107_Text_RayNotEnoughPokemon
# 49 "data/maps/Route107/scripts.pory"
	msgbox Route107_Text_RayPostBattle, MSGBOX_AUTOCLOSE
# 50 "data/maps/Route107/scripts.pory"
	end
# 51 "data/maps/Route107/scripts.pory"

# 52 "data/maps/Route107/scripts.pory"
Route107_EventScript_Camron:: @ 81EE672
# 53 "data/maps/Route107/scripts.pory"
	trainerbattle_single TRAINER_CAMRON, Route107_Text_CamronIntro, Route107_Text_CamronDefeated
# 54 "data/maps/Route107/scripts.pory"
	msgbox Route107_Text_CamronPostBattle, MSGBOX_AUTOCLOSE
# 55 "data/maps/Route107/scripts.pory"
	end
