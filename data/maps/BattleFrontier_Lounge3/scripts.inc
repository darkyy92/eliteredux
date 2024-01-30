# 1 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 2 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_MapScripts:: @ 8261D82
# 3 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.byte 0
# 4 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 5 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.set BET_AMOUNT_5,  5
# 6 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.set BET_AMOUNT_10, 10
# 7 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.set BET_AMOUNT_15, 15
# 8 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 9 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_Gambler:: @ 8261D83
# 10 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	lock
# 11 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	faceplayer
# 12 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
# 13 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
# 14 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	compare VAR_0x8004, 2
# 15 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto_if_le BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
# 16 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
# 17 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
# 18 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
# 19 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 20 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 21 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_AskToEnterChallenge:: @ 8261DAF
# 22 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	special ShowFrontierGamblerLookingMessage
# 23 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	waitmessage
# 24 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	waitbuttonpress
# 25 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
# 26 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	compare VAR_RESULT, NO
# 27 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto_if_eq BattleFrontier_Lounge3_EventScript_DeclineChallenge
# 28 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
# 29 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	compare VAR_RESULT, NO
# 30 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto_if_eq BattleFrontier_Lounge3_EventScript_DeclineChallenge
# 31 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
# 32 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	waitmessage
# 33 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	special ShowBattlePointsWindow
# 34 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
# 35 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 36 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 37 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_ChooseBetAmount:: @ 8261DE9
# 38 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
# 39 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
# 40 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	switch VAR_RESULT
# 41 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
# 42 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
# 43 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
# 44 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
# 45 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
# 46 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 47 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 48 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_Bet5:: @ 8261E30
# 49 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_0x8008, BET_AMOUNT_5
# 50 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
# 51 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 52 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 53 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_Bet10:: @ 8261E3B
# 54 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_0x8008, BET_AMOUNT_10
# 55 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
# 56 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 57 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 58 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_Bet15:: @ 8261E46
# 59 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_0x8008, BET_AMOUNT_15
# 60 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
# 61 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 62 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 63 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_TryPlaceBet:: @ 8261E51
# 64 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
# 65 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	compare VAR_TEMP_1, VAR_0x8008
# 66 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto_if_ge BattleFrontier_Lounge3_EventScript_PlaceBet
# 67 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
# 68 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
# 69 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	waitmessage
# 70 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
# 71 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 72 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 73 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_PlaceBet:: @ 8261E75
# 74 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 75 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	special TakeFrontierBattlePoints
# 76 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
# 77 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	special UpdateBattlePointsWindow
# 78 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	playse SE_SHOP
# 79 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
# 80 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_FinishBet
# 81 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 82 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 83 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_FinishBet:: @ 8261E96
# 84 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	special ShowFrontierGamblerGoMessage
# 85 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	waitmessage
# 86 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	waitbuttonpress
# 87 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	special CloseBattlePointsWindow
# 88 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	release
# 89 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 90 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 91 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_CountSilverSymbols:: @ 8261EA0
# 92 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_0x8004, 0
# 93 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
# 94 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
# 95 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
# 96 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
# 97 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
# 98 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
# 99 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
# 100 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	return
# 101 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 102 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount:: @ 8261EE5
# 103 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	addvar VAR_0x8004, 1
# 104 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	return
# 105 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 106 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols:: @ 8261EEB
# 107 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
# 108 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
# 109 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 110 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 111 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_AlreadyMetGambler:: @ 8261EF9
# 112 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
# 113 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	compare VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
# 114 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto_if_ge BattleFrontier_Lounge3_EventScript_CheckBetResults
# 115 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
# 116 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 117 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 118 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_CheckBetResults:: @ 8261F12
# 119 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	compare VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
# 120 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto_if_eq BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
# 121 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	compare VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON
# 122 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto_if_eq BattleFrontier_Lounge3_EventScript_WonChallenge
# 123 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
# 124 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 125 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 126 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_WonChallenge:: @ 8261F2E
# 127 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
# 128 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	compare VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5
# 129 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_eq BattleFrontier_Lounge3_EventScript_RewardBet5
# 130 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	compare VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10
# 131 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_eq BattleFrontier_Lounge3_EventScript_RewardBet10
# 132 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	compare VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15
# 133 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	call_if_eq BattleFrontier_Lounge3_EventScript_RewardBet15
# 134 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
# 135 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	special GiveFrontierBattlePoints
# 136 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
# 137 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
# 138 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	release
# 139 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 140 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 141 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_LostChallenge:: @ 8261F71
# 142 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
# 143 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
# 144 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	release
# 145 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 146 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 147 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_RewardBet5:: @ 8261F80
# 148 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	buffernumberstring 0, (BET_AMOUNT_5 * 2)
# 149 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
# 150 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	return
# 151 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 152 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_RewardBet10:: @ 8261F8A
# 153 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	buffernumberstring 0, (BET_AMOUNT_10 * 2)
# 154 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
# 155 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	return
# 156 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 157 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_RewardBet15:: @ 8261F94
# 158 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	buffernumberstring 0, (BET_AMOUNT_15 * 2)
# 159 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
# 160 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	return
# 161 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 162 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted:: @ 8261F9E
# 163 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	special ShowFrontierGamblerGoMessage
# 164 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	waitmessage
# 165 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	waitbuttonpress
# 166 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	release
# 167 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 168 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 169 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_DeclineChallenge:: @ 8261FA5
# 170 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
# 171 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	release
# 172 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 173 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 174 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_CancelBet:: @ 8261FAF
# 175 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	special CloseBattlePointsWindow
# 176 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
# 177 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 178 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 179 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_Man:: @ 8261FB8
# 180 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
# 181 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 182 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 183 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_Woman:: @ 8261FC1
# 184 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	lock
# 185 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	faceplayer
# 186 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
# 187 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
# 188 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 189 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 190 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_PokefanF:: @ 8261FD1
# 191 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	lock
# 192 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	faceplayer
# 193 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
# 194 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
# 195 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 196 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 197 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_FatMan:: @ 8261FE1
# 198 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	lock
# 199 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	faceplayer
# 200 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
# 201 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
# 202 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 203 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 204 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_EventScript_FaceOriginalDirection:: @ 8261FF1
# 205 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	closemessage
# 206 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 207 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	waitmovement 0
# 208 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	release
# 209 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	end
# 210 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 211 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere:: @ 8261FFE
# 212 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "…What's that you want?\p"
# 213 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Can't you see we're kind of busy here?\n"
# 214 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Can't your business wait till later?$"
# 215 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 216 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_YouLookToughExplainGambling:: @ 8262061
# 217 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "…Huh?\n"
# 218 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "You look to me like a tough Trainer.\p"
# 219 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Heheh…\n"
# 220 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Listen, I have this proposition.\p"
# 221 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "We have a little group going here,\n"
# 222 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "and we play a little game with what\l"
# 223 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "goes on in the Battle Frontier.\p"
# 224 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "The rules are really simple.\p"
# 225 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "First, we pick one of the facilities\n"
# 226 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "in the Battle Frontier.\p"
# 227 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Then, we each pick a different Trainer\n"
# 228 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "who's taking that facility's challenge,\l"
# 229 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "and bet with our Battle Points.\p"
# 230 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "The guy who bet on the Trainer with\n"
# 231 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "the best record takes all the Battle\l"
# 232 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Points in the pool.\p"
# 233 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Sounds simple, huh?\n"
# 234 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "So, anyway…$"
# 235 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 236 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle:: @ 8262261
# 237 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a Trainer who's\n"
# 238 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be challenging the BATTLE\l"
# 239 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "TOWER's SINGLE BATTLE ROOMS.\p"
# 240 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a Trainer\n"
# 241 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 242 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 243 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble:: @ 826230D
# 244 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a Trainer who's\n"
# 245 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be challenging the BATTLE\l"
# 246 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "TOWER's Double Battle ROOMS.\p"
# 247 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a Trainer\n"
# 248 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 249 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 250 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti:: @ 82623B9
# 251 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a Trainer who's\n"
# 252 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be challenging the BATTLE\l"
# 253 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "TOWER's MULTI BATTLE ROOMS.\p"
# 254 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a Trainer\n"
# 255 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 256 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 257 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle:: @ 8262464
# 258 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a Trainer who's\n"
# 259 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be entering the BATTLE\l"
# 260 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "DOME's SINGLE BATTLE Tourney.\p"
# 261 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a Trainer\n"
# 262 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 263 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 264 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble:: @ 826250E
# 265 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a Trainer who's\n"
# 266 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be entering the BATTLE\l"
# 267 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "DOME's Double Battle Tourney.\p"
# 268 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a Trainer\n"
# 269 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 270 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 271 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle:: @ 82625B8
# 272 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a Trainer who's\n"
# 273 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be entering the BATTLE\l"
# 274 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "FACTORY's Battle Swap Single Tourney.\p"
# 275 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a Trainer\n"
# 276 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 277 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 278 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble:: @ 826266A
# 279 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a Trainer who's\n"
# 280 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be entering the BATTLE\l"
# 281 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "FACTORY's Battle Swap Double Tourney.\p"
# 282 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a Trainer\n"
# 283 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 284 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 285 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle:: @ 826271C
# 286 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a Trainer who's\n"
# 287 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be challenging the BATTLE\l"
# 288 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "PALACE's SINGLE BATTLE HALLS.\p"
# 289 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a Trainer\n"
# 290 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 291 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 292 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble:: @ 82627C9
# 293 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a Trainer who's\n"
# 294 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be challenging the BATTLE\l"
# 295 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "PALACE's Double Battle HALLS.\p"
# 296 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a Trainer\n"
# 297 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 298 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 299 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattleArena:: @ 8262876
# 300 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a Trainer who's\n"
# 301 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be entering the BATTLE\l"
# 302 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "ARENA's Set KO Tourney.\p"
# 303 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a Trainer\n"
# 304 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 305 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 306 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattlePike:: @ 826291A
# 307 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a Trainer who's\n"
# 308 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be entering the BATTLE PIKE's\l"
# 309 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Battle Choice.\p"
# 310 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a Trainer\n"
# 311 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 312 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 313 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ChallengeBattlePyramid:: @ 82629BC
# 314 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What I'm looking for is a Trainer who's\n"
# 315 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "going to be entering the BATTLE\l"
# 316 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "PYRAMID's Battle Quest.\p"
# 317 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "But so far, I haven't seen a Trainer\n"
# 318 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "that has that winning quality.$"
# 319 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 320 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe:: @ 8262A60
# 321 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "I'll see to it that you benefit, too.\n"
# 322 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "So how about it?\l"
# 323 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "How about entering that event for me?$"
# 324 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 325 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints:: @ 8262ABD
# 326 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "All right, that's perfect.\n"
# 327 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "So, uh… How about spotting me some\l"
# 328 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "of your Battle Points?\p"
# 329 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Trust me, I'll show you my gratitude\n"
# 330 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "afterward.$"
# 331 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 332 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_HowMuchCanYouSpot:: @ 8262B42
# 333 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Great, great!\n"
# 334 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "So, how much can you spot me?$"
# 335 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 336 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints:: @ 8262B6E
# 337 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Oh, no, no, no!\n"
# 338 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "You don't have enough Battle Points!\p"
# 339 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "I wish you wouldn't monkey around and\n"
# 340 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "waste everyone's time!$"
# 341 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 342 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ThanksOffYouGo:: @ 8262BE0
# 343 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Heheh! Thanks much!\n"
# 344 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "So, off you go!$"
# 345 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 346 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattleTowerSingle:: @ 8262C04
# 347 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the Battle Tower's\n"
# 348 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "SINGLE BATTLE ROOMS pronto!\p"
# 349 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 350 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 351 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 352 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 353 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattleTowerDouble:: @ 8262C90
# 354 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the Battle Tower's\n"
# 355 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Double Battle ROOMS pronto!\p"
# 356 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 357 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 358 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 359 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 360 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattleTowerMulti:: @ 8262D1C
# 361 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the Battle Tower's\n"
# 362 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "MULTI BATTLE ROOMS pronto!\p"
# 363 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 364 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 365 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 366 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 367 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattleDomeSingle:: @ 8262DA7
# 368 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE DOME's\n"
# 369 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "SINGLE BATTLE Tourney pronto!\p"
# 370 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 371 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 372 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 373 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 374 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattleDomeDouble:: @ 8262E34
# 375 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE DOME's\n"
# 376 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Double Battle Tourney pronto!\p"
# 377 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 378 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 379 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 380 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 381 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattleFactorySingle:: @ 8262EC1
# 382 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE FACTORY's\n"
# 383 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Battle Swap Single Tourney pronto!\p"
# 384 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 385 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 386 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 387 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 388 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble:: @ 8262F56
# 389 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE FACTORY's\n"
# 390 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Battle Swap Double Tourney pronto!\p"
# 391 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 392 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 393 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 394 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 395 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle:: @ 8262FEB
# 396 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE PALACE's\n"
# 397 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "SINGLE BATTLE HALLS pronto!\p"
# 398 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 399 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 400 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 401 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 402 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble:: @ 8263078
# 403 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE PALACE's\n"
# 404 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Double Battle HALLS pronto!\p"
# 405 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 406 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 407 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 408 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 409 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattleArena:: @ 8263105
# 410 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE ARENA's\n"
# 411 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Set KO Tourney pronto!\p"
# 412 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 413 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 414 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 415 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 416 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattlePike:: @ 826318C
# 417 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE PIKE's\n"
# 418 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Battle Choice pronto!\p"
# 419 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 420 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 421 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 422 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 423 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_GetToBattlePyramid:: @ 8263211
# 424 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Get to the BATTLE PYRAMID's\n"
# 425 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Battle Quest pronto!\p"
# 426 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "It's a must-win situation!\n"
# 427 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Don't blow your chance!\l"
# 428 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Both of our futures depend on you!$"
# 429 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 430 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints:: @ 8263298
# 431 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Oh, it's you…\n"
# 432 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Nice try…\p"
# 433 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "I hate to break it to you, but I can't\n"
# 434 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "return your Battle Points…\p"
# 435 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "I guess we'll have to let it motivate\n"
# 436 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "us to try harder next time!$"
# 437 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 438 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints:: @ 8263334
# 439 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Oh, yes!\n"
# 440 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Hello there, champ!\p"
# 441 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "I knew you could!\n"
# 442 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "I knew you would!\l"
# 443 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "We're both big winners!\p"
# 444 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "I'll return your Battle Points and,\n"
# 445 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "of course, a little extra from me!$"
# 446 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 447 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ObtainedBattlePoints:: @ 82633D4
# 448 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "{PLAYER} obtained\n"
# 449 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "{STR_VAR_1} Battle Points.$"
# 450 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 451 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge:: @ 82633F2
# 452 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "If you're up for another challenge,\n"
# 453 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "please do think of me!$"
# 454 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 455 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_NotInterested:: @ 826342D
# 456 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Not interested?! You shouldn't be\n"
# 457 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "so afraid to take a chance!$"
# 458 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 459 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_Oh:: @ 826346B
# 460 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Oh…$"
# 461 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 462 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_BackedWrongTrainer:: @ 826346F
# 463 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "I backed the wrong Trainer again!\p"
# 464 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Maybe I should be battling normally\n"
# 465 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "like everyone else…$"
# 466 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 467 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_TrainerGoodButRattled:: @ 82634C9
# 468 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "That Trainer…\p"
# 469 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "He's good, but he gets rattled too\n"
# 470 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "easily to survive the BATTLE DOME…$"
# 471 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 472 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne:: @ 826351D
# 473 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Giggle!\n"
# 474 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "I know a winner when I see one!$"
# 475 "data/maps/BattleFrontier_Lounge3/scripts.pory"

# 476 "data/maps/BattleFrontier_Lounge3/scripts.pory"
BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges:: @ 8263545
# 477 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "Those TRAINERS…\n"
# 478 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "What are they doing?\l"
# 479 "data/maps/BattleFrontier_Lounge3/scripts.pory"
	.string "They should be taking challenges.$"
