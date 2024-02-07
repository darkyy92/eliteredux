# 1 "data/maps/MtPyre_Exterior/scripts.pory"

# 2 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_MapScripts:: @ 8231FCC
# 3 "data/maps/MtPyre_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Exterior_OnTransition
# 4 "data/maps/MtPyre_Exterior/scripts.pory"
	.byte 0
# 5 "data/maps/MtPyre_Exterior/scripts.pory"

# 6 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_OnTransition: @ 8231FD2
# 7 "data/maps/MtPyre_Exterior/scripts.pory"
	call MtPyre_Exterior_EventScript_CheckEnterFromSummit
# 8 "data/maps/MtPyre_Exterior/scripts.pory"
	end
# 9 "data/maps/MtPyre_Exterior/scripts.pory"

# 10 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_EventScript_CheckEnterFromSummit:: @ 8231FD8
# 11 "data/maps/MtPyre_Exterior/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 12 "data/maps/MtPyre_Exterior/scripts.pory"
	compare VAR_TEMP_1, 12
# 13 "data/maps/MtPyre_Exterior/scripts.pory"
	goto_if_lt MtPyre_Exterior_EventScript_EnterFromSummit
# 14 "data/maps/MtPyre_Exterior/scripts.pory"
	return
# 15 "data/maps/MtPyre_Exterior/scripts.pory"

# 16 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_EventScript_EnterFromSummit:: @ 8231FE9
# 17 "data/maps/MtPyre_Exterior/scripts.pory"
	setweather WEATHER_FOG_HORIZONTAL
# 18 "data/maps/MtPyre_Exterior/scripts.pory"
	return
# 19 "data/maps/MtPyre_Exterior/scripts.pory"

# 20 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_EventScript_FogTrigger:: @ 8231FED
# 21 "data/maps/MtPyre_Exterior/scripts.pory"
	setweather WEATHER_FOG_HORIZONTAL
# 22 "data/maps/MtPyre_Exterior/scripts.pory"
	doweather
# 23 "data/maps/MtPyre_Exterior/scripts.pory"
	end
# 24 "data/maps/MtPyre_Exterior/scripts.pory"

# 25 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_EventScript_SunTrigger:: @ 8231FF2
# 26 "data/maps/MtPyre_Exterior/scripts.pory"
	setweather WEATHER_SUNNY
# 27 "data/maps/MtPyre_Exterior/scripts.pory"
	doweather
# 28 "data/maps/MtPyre_Exterior/scripts.pory"
	end

MtPyre_Exterior_EventScript_Yda::
# 33 "data/maps/MtPyre_Exterior/scripts.pory"
	trainerbattle_single TRAINER_YDA_MTPYRE, MtPyre_Exterior_EventScript_Yda_Text_0, MtPyre_Exterior_EventScript_Yda_Text_1
# 34 "data/maps/MtPyre_Exterior/scripts.pory"
	msgbox MtPyre_Exterior_EventScript_Yda_Text_2, MSGBOX_NPC
# 35 "data/maps/MtPyre_Exterior/scripts.pory"
	release
	end


MtPyre_Exterior_EventScript_Yda_Text_0:
# 33 "data/maps/MtPyre_Exterior/scripts.pory"
	.string "Hey there, sorry, but you can't go any\n"
	.string "further.\p"
	.string "Why not?...\p"
	.string "...Don't you know who am I?\p"
	.string "I'm Ydarissep, the great oracle!\p"
	.string "I have the extraordinary ability to\n"
	.string "predict where and when a new Pokémon\l"
	.string "species will show up just by sniffing\l"
	.string "the air.\p"
	.string "Anyone trying to steal this discovery\n"
	.string "from me is in for a battle!$"

MtPyre_Exterior_EventScript_Yda_Text_1:
# 33 "data/maps/MtPyre_Exterior/scripts.pory"
	.string "I bet you didn't see that coming, I lost!$"

MtPyre_Exterior_EventScript_Yda_Text_2:
# 34 "data/maps/MtPyre_Exterior/scripts.pory"
	.string "Smell ya later.$"
