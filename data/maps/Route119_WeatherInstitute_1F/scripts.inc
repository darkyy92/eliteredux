# 1 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 2 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
.set LOCALID_LITTLE_BOY, 5
# 3 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 4 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_MapScripts:: @ 826FA86
# 5 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
# 6 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.byte 0
# 7 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 8 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_OnTransition: @ 826FA8C
# 9 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	compare VAR_WEATHER_INSTITUTE_STATE, 0
# 10 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	call_if_eq Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
# 11 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 12 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 13 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos:: @ 826FA98
# 14 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	setobjectxyperm LOCALID_LITTLE_BOY, 0, 5
# 15 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	setobjectmovementtype LOCALID_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
# 16 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	return
# 17 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 18 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_LittleBoy:: @ 826FAA4
# 19 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	lock
# 20 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	faceplayer
# 21 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	special GetPlayerBigGuyGirlString
# 22 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	compare VAR_WEATHER_INSTITUTE_STATE, 0
# 23 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
# 24 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	goto_if_set FLAG_WEATHER_INSTITUTE_ROCKS, Route119_WeatherInstitute_1F_EventScript_LittleBoyGaveRocks
# 25 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
# 26 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	giveitem ITEM_HEAT_ROCK
# 27 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	giveitem ITEM_DAMP_ROCK
# 28 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	giveitem ITEM_ICY_ROCK
# 29 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	giveitem ITEM_SMOOTH_ROCK
# 30 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	setflag FLAG_WEATHER_INSTITUTE_ROCKS
# 31 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_LittleBoyGaveRocks:
# 32 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_Rocks, MSGBOX_DEFAULT
# 33 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	release
# 34 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 35 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 36 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere:: @ 826FABE
# 37 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
# 38 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	release
# 39 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 40 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 41 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_InstituteWorker1:: @ 826FAC8
# 42 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	lock
# 43 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	faceplayer
# 44 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
# 45 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	setvar VAR_0x8004, 0
# 46 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
# 47 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
# 48 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	compare VAR_0x8004, 2  @ Both defeated
# 49 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_StudyingRain
# 50 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
# 51 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	release
# 52 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 53 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 54 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated:: @ 826FAFF
# 55 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	addvar VAR_0x8004, 1
# 56 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	return
# 57 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 58 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_StudyingRain:: @ 826FB05
# 59 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
# 60 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	release
# 61 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 62 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 63 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_InstituteWorker2:: @ 826FB0F
# 64 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	lock
# 65 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	faceplayer
# 66 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	goto_if_set FLAG_WEATHER_INSTITUTE_BOTTLE_CAPS, Route119_WeatherInstitute_1F_EventScript_ReceivedCaps
# 67 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_PleaseTakeThese, MSGBOX_DEFAULT
# 68 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	giveitem ITEM_BOTTLE_CAP, 4
# 69 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	setflag FLAG_WEATHER_INSTITUTE_BOTTLE_CAPS
# 70 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_ReceivedCaps::
# 71 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_AUTOCLOSE
# 72 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	release
# 73 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 74 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 75 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_Bed:: @ 826FB18
# 76 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	lockall
# 77 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
# 78 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	closemessage
# 79 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	goto_if_set FLAG_IS_DAYNIGHT_INVERTED, Route119_WeatherInstitute_1F_EventScript_Bed2
# 80 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	setflag FLAG_IS_DAYNIGHT_INVERTED
# 81 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 82 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	releaseall
# 83 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 84 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	
# 85 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_Bed2:: @ 826FB18
# 86 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	clearflag FLAG_IS_DAYNIGHT_INVERTED
# 87 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 88 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	releaseall
# 89 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 90 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 91 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_Grunt1:: @ 826FB29
# 92 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
# 93 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 94 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 95 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 96 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_Grunt4:: @ 826FB40
# 97 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
# 98 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 99 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 100 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 101 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Grunt1Intro: @ 826FB57
# 102 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "The Boss got interested in\n"
# 103 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "the research they have going here,\l"
# 104 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "so he sent us out.\p"
# 105 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "You quit meddling!$"
# 106 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 107 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Grunt1Defeat: @ 826FBBB
# 108 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Blast it…\n"
# 109 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Blasted by a kid…$"
# 110 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 111 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Grunt1PostBattle: @ 826FBD7
# 112 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Our Boss knows everything.\p"
# 113 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "But I'm just a Grunt. What would I know\n"
# 114 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "about what he's thinking?$"
# 115 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 116 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Grunt4Intro: @ 826FC34
# 117 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Huh?\n"
# 118 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "What's a kid doing here?$"
# 119 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 120 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Grunt4Defeat: @ 826FC52
# 121 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Huh?\n"
# 122 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "I lost?!$"
# 123 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 124 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Grunt4PostBattle: @ 826FC60
# 125 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Oh, no…\n"
# 126 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "I'll catch an earful for losing to a kid…\p"
# 127 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "I should just take a nap in the bed…$"
# 128 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 129 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
# 130 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "While I was sleeping, everyone went\n"
# 131 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "upstairs!$"
# 132 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 133 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_WowYoureStrong:
# 134 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Wow, you're really strong!\p"
# 135 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "A Trainer like you should have these!$"
# 136 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 137 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Rocks:
# 138 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "We've got lots of these rocks here!\p"
# 139 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "They make weather from moves like\n"
# 140 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Rain Dance last longer.$"
# 141 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 142 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_ProfStudyingRain: @ 826FD2E
# 143 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "The Professor loves rain.\n"
# 144 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "That's a fact.\p"
# 145 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "But if it keeps raining, people will be in\n"
# 146 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "trouble. That's another fact.\p"
# 147 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "And thus, the Professor is studying\n"
# 148 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "if the rain can be put to good use.$"
# 149 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 150 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather: @ 826FDE8
# 151 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "On the 2nd floor of the Institute,\n"
# 152 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "we study the weather patterns over\l"
# 153 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "the Hoenn region.\p"
# 154 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "We've been noticing temporary and\n"
# 155 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "isolated cases of droughts and\l"
# 156 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "heavy rain lately…$"
# 157 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 158 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_PleaseTakeThese:
# 159 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Hello!\n"
# 160 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "We've been saved by your actions!\p"
# 161 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Please take these as a reward!$"
# 162 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 163 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
# 164 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "What I don't understand is what on\n"
# 165 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "earth the Aquas were up to.$"
# 166 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 167 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_TakeRestInBed: @ 826FEFC
# 168 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "There's a bed…\n"
# 169 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Let's take a rest.$"
