# 1 "data/maps/TrainerHill_Roof/scripts.pory"

# 2 "data/maps/TrainerHill_Roof/scripts.pory"
TrainerHill_Roof_MapScripts:: @ 8268FA7
# 3 "data/maps/TrainerHill_Roof/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_OnResume
# 4 "data/maps/TrainerHill_Roof/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_OnFrame
# 5 "data/maps/TrainerHill_Roof/scripts.pory"
	.byte 0
# 6 "data/maps/TrainerHill_Roof/scripts.pory"

# 7 "data/maps/TrainerHill_Roof/scripts.pory"
TrainerHill_Roof_EventScript_Owner:: @ 8268FB2
# 8 "data/maps/TrainerHill_Roof/scripts.pory"
	trainerhill_settrainerflags
# 9 "data/maps/TrainerHill_Roof/scripts.pory"
	lock
# 10 "data/maps/TrainerHill_Roof/scripts.pory"
	faceplayer
# 11 "data/maps/TrainerHill_Roof/scripts.pory"
	trainerhill_getownerstate
# 12 "data/maps/TrainerHill_Roof/scripts.pory"
	switch VAR_RESULT
# 13 "data/maps/TrainerHill_Roof/scripts.pory"
	case 0, TrainerHill_Roof_EventScript_Arrived
# 14 "data/maps/TrainerHill_Roof/scripts.pory"
	case 1, TrainerHill_Roof_EventScript_GivePrize
# 15 "data/maps/TrainerHill_Roof/scripts.pory"
	case 2, TrainerHill_Roof_EventScript_AlreadyReceivedPrize
# 16 "data/maps/TrainerHill_Roof/scripts.pory"
TrainerHill_Roof_EventScript_Arrived:: @ 8268FEA
# 17 "data/maps/TrainerHill_Roof/scripts.pory"
	msgbox TrainerHill_Roof_Text_YouFinallyCameBravo, MSGBOX_DEFAULT
# 18 "data/maps/TrainerHill_Roof/scripts.pory"
TrainerHill_Roof_EventScript_GivePrize:: @ 8268FF2
# 19 "data/maps/TrainerHill_Roof/scripts.pory"
	trainerhill_giveprize
# 20 "data/maps/TrainerHill_Roof/scripts.pory"
	switch VAR_RESULT
# 21 "data/maps/TrainerHill_Roof/scripts.pory"
	case 0, TrainerHill_Roof_EventScript_ReceivePrize
# 22 "data/maps/TrainerHill_Roof/scripts.pory"
	case 1, TrainerHill_Roof_EventScript_NoRoomForPrize
# 23 "data/maps/TrainerHill_Roof/scripts.pory"
	case 2, TrainerHill_Roof_EventScript_CheckFinalTime
# 24 "data/maps/TrainerHill_Roof/scripts.pory"
TrainerHill_Roof_EventScript_ReceivePrize:: @ 8269020
# 25 "data/maps/TrainerHill_Roof/scripts.pory"
	msgbox TrainerHill_Roof_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
# 26 "data/maps/TrainerHill_Roof/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 27 "data/maps/TrainerHill_Roof/scripts.pory"
	message gText_ObtainedTheItem
# 28 "data/maps/TrainerHill_Roof/scripts.pory"
	waitfanfare
# 29 "data/maps/TrainerHill_Roof/scripts.pory"
	waitmessage
# 30 "data/maps/TrainerHill_Roof/scripts.pory"
	goto TrainerHill_Roof_EventScript_CheckFinalTime
# 31 "data/maps/TrainerHill_Roof/scripts.pory"

# 32 "data/maps/TrainerHill_Roof/scripts.pory"
TrainerHill_Roof_EventScript_NoRoomForPrize:: @ 8269037
# 33 "data/maps/TrainerHill_Roof/scripts.pory"
	msgbox TrainerHill_Roof_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
# 34 "data/maps/TrainerHill_Roof/scripts.pory"
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
# 35 "data/maps/TrainerHill_Roof/scripts.pory"
	msgbox TrainerHill_Roof_Text_FullUpBeBackLaterForThis, MSGBOX_DEFAULT
# 36 "data/maps/TrainerHill_Roof/scripts.pory"
	goto TrainerHill_Roof_EventScript_CheckFinalTime
# 37 "data/maps/TrainerHill_Roof/scripts.pory"

# 38 "data/maps/TrainerHill_Roof/scripts.pory"
TrainerHill_Roof_EventScript_CheckFinalTime:: @ 8269054
# 39 "data/maps/TrainerHill_Roof/scripts.pory"
	trainerhill_finaltime
# 40 "data/maps/TrainerHill_Roof/scripts.pory"
	switch VAR_RESULT
# 41 "data/maps/TrainerHill_Roof/scripts.pory"
	case 0, TrainerHill_Roof_EventScript_NewRecord
# 42 "data/maps/TrainerHill_Roof/scripts.pory"
	case 1, TrainerHill_Roof_EventScript_NoNewRecord
# 43 "data/maps/TrainerHill_Roof/scripts.pory"
	case 2, TrainerHill_Roof_EventScript_EndSpeakToOwner
# 44 "data/maps/TrainerHill_Roof/scripts.pory"
TrainerHill_Roof_EventScript_NewRecord:: @ 8269082
# 45 "data/maps/TrainerHill_Roof/scripts.pory"
	msgbox TrainerHill_Roof_Text_GotHereMarvelouslyQuickly, MSGBOX_DEFAULT
# 46 "data/maps/TrainerHill_Roof/scripts.pory"
	goto TrainerHill_Roof_EventScript_EndSpeakToOwner
# 47 "data/maps/TrainerHill_Roof/scripts.pory"
	end
# 48 "data/maps/TrainerHill_Roof/scripts.pory"

# 49 "data/maps/TrainerHill_Roof/scripts.pory"
TrainerHill_Roof_EventScript_NoNewRecord:: @ 8269090
# 50 "data/maps/TrainerHill_Roof/scripts.pory"
	msgbox TrainerHill_Roof_Text_YouWerentVeryQuick, MSGBOX_DEFAULT
# 51 "data/maps/TrainerHill_Roof/scripts.pory"
	goto TrainerHill_Roof_EventScript_EndSpeakToOwner
# 52 "data/maps/TrainerHill_Roof/scripts.pory"
	end
# 53 "data/maps/TrainerHill_Roof/scripts.pory"

# 54 "data/maps/TrainerHill_Roof/scripts.pory"
TrainerHill_Roof_EventScript_EndSpeakToOwner:: @ 826909E
# 55 "data/maps/TrainerHill_Roof/scripts.pory"
	msgbox TrainerHill_Roof_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
# 56 "data/maps/TrainerHill_Roof/scripts.pory"
	release
# 57 "data/maps/TrainerHill_Roof/scripts.pory"
	end
# 58 "data/maps/TrainerHill_Roof/scripts.pory"

# 59 "data/maps/TrainerHill_Roof/scripts.pory"
TrainerHill_Roof_EventScript_AlreadyReceivedPrize:: @ 82690A8
# 60 "data/maps/TrainerHill_Roof/scripts.pory"
	msgbox TrainerHill_Roof_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
# 61 "data/maps/TrainerHill_Roof/scripts.pory"
	release
# 62 "data/maps/TrainerHill_Roof/scripts.pory"
	end
