# 1 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 2 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_MapScripts:: @ 8270A28
# 3 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route124_DivingTreasureHuntersHouse_OnTransition
# 4 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.byte 0
# 5 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 6 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_OnTransition: @ 8270A2E
# 7 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setflag FLAG_LANDMARK_HUNTERS_HOUSE
# 8 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 9 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 10 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_TreasureHunter:: @ 8270A32
# 11 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	lock
# 12 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	faceplayer
# 13 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto_if_set FLAG_MET_DIVING_TREASURE_HUNTER, Route124_DivingTreasureHuntersHouse_EventScript_SkipGreeting
# 14 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_Greeting, MSGBOX_DEFAULT
# 15 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setflag FLAG_MET_DIVING_TREASURE_HUNTER
# 16 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_CheckPlayerHasShard
# 17 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 18 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 19 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_SkipGreeting:: @ 8270A4E
# 20 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_HaveYouSeenAnyShards, MSGBOX_DEFAULT
# 21 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_CheckPlayerHasShard
# 22 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 23 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 24 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_CheckPlayerHasShard:: @ 8270A5C
# 25 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	call Route124_DivingTreasureHuntersHouse_EventScript_GetPlayersShards
# 26 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	compare VAR_TEMP_1, 0
# 27 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_NoShards
# 28 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_HasShard
# 29 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 30 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 31 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_GetPlayersShards:: @ 8270A72
# 32 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setvar VAR_TEMP_1, 0
# 33 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	checkitem ITEM_RED_SHARD, 1
# 34 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	compare VAR_RESULT, TRUE
# 35 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	call_if_eq Route124_DivingTreasureHuntersHouse_EventScript_HasRedShard
# 36 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	checkitem ITEM_YELLOW_SHARD, 1
# 37 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	compare VAR_RESULT, TRUE
# 38 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	call_if_eq Route124_DivingTreasureHuntersHouse_EventScript_HasYellowShard
# 39 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	checkitem ITEM_BLUE_SHARD, 1
# 40 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	compare VAR_RESULT, TRUE
# 41 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	call_if_eq Route124_DivingTreasureHuntersHouse_EventScript_HasBlueShard
# 42 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	checkitem ITEM_GREEN_SHARD, 1
# 43 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	compare VAR_RESULT, TRUE
# 44 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	call_if_eq Route124_DivingTreasureHuntersHouse_EventScript_HasGreenShard
# 45 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	return
# 46 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 47 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_HasRedShard:: @ 8270AB8
# 48 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	addvar VAR_TEMP_1, 1
# 49 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	return
# 50 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 51 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_HasYellowShard:: @ 8270ABE
# 52 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	addvar VAR_TEMP_1, 2
# 53 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	return
# 54 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 55 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_HasBlueShard:: @ 8270AC4
# 56 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	addvar VAR_TEMP_1, 4
# 57 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	return
# 58 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 59 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_HasGreenShard:: @ 8270ACA
# 60 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	addvar VAR_TEMP_1, 8
# 61 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	return
# 62 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 63 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_HasShard:: @ 8270AD0
# 64 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_ThatsAShardIllTradeYou, MSGBOX_DEFAULT
# 65 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_ShowTradeOptions
# 66 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 67 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 68 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
@ lmao wtf is this. Should really replace it with something less stupid sometime.
# 69 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShowTradeOptions:: @ 8270ADE
# 70 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	message Route124_DivingTreasureHuntersHouse_Text_WhatDoYouWantToTrade
# 71 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	waitmessage
# 72 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_TEMP_1
# 73 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsR
# 74 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsY
# 75 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 3,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRY
# 76 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 4,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsB
# 77 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 5,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRB
# 78 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 6,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYB
# 79 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 7,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYB
# 80 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 8,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsG
# 81 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 9,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRG
# 82 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 10, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYG
# 83 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 11, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYG
# 84 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 12, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsBG
# 85 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 13, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRBG
# 86 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 14, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYBG
# 87 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 15, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYBG
# 88 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 89 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 90 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsR:: @ 8270B8F
# 91 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_R, FALSE
# 92 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 93 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
# 94 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 95 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 96 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 97 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 98 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsY:: @ 8270BB5
# 99 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_Y, FALSE
# 100 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 101 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
# 102 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 103 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 104 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 105 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 106 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRY:: @ 8270BDB
# 107 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_RY, FALSE
# 108 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 109 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
# 110 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
# 111 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 112 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 113 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 114 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 115 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsB:: @ 8270C0C
# 116 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_B, FALSE
# 117 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 118 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
# 119 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 120 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 121 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 122 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 123 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRB:: @ 8270C32
# 124 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_RB, FALSE
# 125 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 126 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
# 127 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
# 128 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 129 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 130 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 131 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 132 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYB:: @ 8270C63
# 133 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_YB, FALSE
# 134 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 135 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
# 136 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
# 137 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 138 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 139 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 140 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 141 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYB:: @ 8270C94
# 142 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_RYB, FALSE
# 143 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 144 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
# 145 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
# 146 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
# 147 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 148 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 149 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 150 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 151 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsG:: @ 8270CD0
# 152 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_G, FALSE
# 153 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 154 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
# 155 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 156 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 157 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 158 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 159 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRG:: @ 8270CF6
# 160 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_RG, FALSE
# 161 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 162 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
# 163 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
# 164 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 165 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 166 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 167 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 168 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYG:: @ 8270D27
# 169 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_YG, FALSE
# 170 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 171 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
# 172 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
# 173 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 174 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 175 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 176 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 177 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYG:: @ 8270D58
# 178 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_RYG, FALSE
# 179 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 180 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
# 181 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
# 182 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
# 183 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 184 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 185 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 186 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 187 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsBG:: @ 8270D94
# 188 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_BG, FALSE
# 189 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 190 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
# 191 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
# 192 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 193 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 194 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 195 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 196 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRBG:: @ 8270DC5
# 197 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_RBG, FALSE
# 198 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 199 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
# 200 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
# 201 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
# 202 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 203 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 204 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 205 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 206 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYBG:: @ 8270E01
# 207 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_YBG, FALSE
# 208 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 209 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
# 210 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
# 211 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
# 212 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 213 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 214 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 215 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 216 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYBG:: @ 8270E3D
# 217 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	multichoice 0, 0, MULTI_SHARDS_RYBG, FALSE
# 218 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	switch VAR_RESULT
# 219 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
# 220 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
# 221 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
# 222 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
# 223 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	case 4, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 224 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 225 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 226 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 227 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard:: @ 8270E84
# 228 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setvar VAR_0x8008, ITEM_RED_SHARD
# 229 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setvar VAR_0x8009, ITEM_BOTTLE_CAP
# 230 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard
# 231 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 232 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard:: @ 8270E93
# 233 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setvar VAR_0x8008, ITEM_YELLOW_SHARD
# 234 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setvar VAR_0x8009, ITEM_BOTTLE_CAP
# 235 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard
# 236 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 237 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard:: @ 8270EA2
# 238 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setvar VAR_0x8008, ITEM_BLUE_SHARD
# 239 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setvar VAR_0x8009, ITEM_BOTTLE_CAP
# 240 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard
# 241 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 242 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard:: @ 8270EB1
# 243 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setvar VAR_0x8008, ITEM_GREEN_SHARD
# 244 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	setvar VAR_0x8009, ITEM_BOTTLE_CAP
# 245 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard
# 246 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 247 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard:: @ 8270EC0
# 248 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	bufferitemname 0, VAR_0x8008
# 249 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	bufferitemname 1, VAR_0x8009
# 250 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_YoullTradeShardForStone, MSGBOX_YESNO
# 251 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	compare VAR_RESULT, NO
# 252 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 253 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	checkitemspace VAR_0x8009, 1
# 254 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	compare VAR_RESULT, TRUE
# 255 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_TradeShard
# 256 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	checkitem VAR_0x8008, 2
# 257 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 258 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_TradeShard
# 259 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_BagFull
# 260 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 261 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 262 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_TradeShard:: @ 8270F01
# 263 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	removeitem VAR_0x8008
# 264 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	giveitem VAR_0x8009
# 265 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_ItsADeal, MSGBOX_DEFAULT
# 266 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	call Route124_DivingTreasureHuntersHouse_EventScript_GetPlayersShards
# 267 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	compare VAR_TEMP_1, 0
# 268 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_EndTrade
# 269 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_TradeSomethingElse, MSGBOX_YESNO
# 270 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	compare VAR_RESULT, YES
# 271 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_ShowTradeOptions
# 272 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
# 273 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 274 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 275 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_BagFull:: @ 8270F43
# 276 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_BagFull, MSGBOX_DEFAULT
# 277 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	release
# 278 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 279 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 280 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade:: @ 8270F4D
# 281 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_ComeBackIfYouChangeMind, MSGBOX_DEFAULT
# 282 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	release
# 283 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 284 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 285 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_NoShards:: @ 8270F57
# 286 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	msgbox Route124_DivingTreasureHuntersHouse_Text_YouHaventGotAnyShards, MSGBOX_DEFAULT
# 287 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	release
# 288 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 289 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 290 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_EventScript_EndTrade:: @ 8270F61
# 291 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	release
# 292 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	end
# 293 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 294 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_Greeting: @ 8270F6C
# 295 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "I'm the Diving Treasure Hunter!\p"
# 296 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "I'm the awesome dude who makes\n"
# 297 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "deep-sea dives to gather treasures\l"
# 298 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "resting at the bottom.$"
# 299 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 300 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_HaveYouSeenAnyShards: @ 8270FE5
# 301 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "Tell me, have you seen any Shards of\n"
# 302 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "tools made in ancient times?$"
# 303 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 304 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_YouHaventGotAnyShards: @ 8271027
# 305 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "You haven't got any treasures\n"
# 306 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "for me…\p"
# 307 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "If you see any Shards, like the Red\n"
# 308 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "Shard, you've got to trade it with me!$"
# 309 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 310 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_ThatsAShardIllTradeYou: @ 8271098
# 311 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "Oh, hey! That…\n"
# 312 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "That's a Shard! I'm looking for those!\p"
# 313 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "Oh, man, you've got to trade that\n"
# 314 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "with me! I'll give you something good!$"
# 315 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 316 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_WhatDoYouWantToTrade: @ 8271117
# 317 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "What do you want to trade?$"
# 318 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 319 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_YoullTradeShardForStone: @ 8271132
# 320 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "You'll trade your {STR_VAR_1} for\n"
# 321 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "my Bottle Cap, then?$"
# 322 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 323 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_ItsADeal: @ 8271158
# 324 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "It's a done deal!\n"
# 325 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "Use that wisely!$"
# 326 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 327 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_TradeSomethingElse: @ 827117B
# 328 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "Do you want to trade something else?$"
# 329 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 330 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_BagFull: @ 82711A0
# 331 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "Whoops, your Bag's full.\n"
# 332 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "Get rid of some items, friend!$"
# 333 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"

# 334 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
Route124_DivingTreasureHuntersHouse_Text_ComeBackIfYouChangeMind: @ 82711D8
# 335 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "No? That's a downer.\n"
# 336 "data/maps/Route124_DivingTreasureHuntersHouse/scripts.pory"
	.string "Well, if you change your mind, come back.$"
