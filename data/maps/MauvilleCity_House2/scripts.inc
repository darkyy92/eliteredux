# 1 "data/maps/MauvilleCity_House2/scripts.pory"

# 2 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_MapScripts:: @ 8210C5C
# 3 "data/maps/MauvilleCity_House2/scripts.pory"
	.byte 0
# 4 "data/maps/MauvilleCity_House2/scripts.pory"

# 5 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_EventScript_AskToTradeForIceStone:: @ 8210C82
# 6 "data/maps/MauvilleCity_House2/scripts.pory"
	playse SE_PIN
# 7 "data/maps/MauvilleCity_House2/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 8 "data/maps/MauvilleCity_House2/scripts.pory"
	waitmovement 0
# 9 "data/maps/MauvilleCity_House2/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
# 10 "data/maps/MauvilleCity_House2/scripts.pory"
	waitmovement 0
# 11 "data/maps/MauvilleCity_House2/scripts.pory"
	msgbox MauvilleCity_House2_Text_TradeIceStoneForCoinCase, MSGBOX_YESNO
# 12 "data/maps/MauvilleCity_House2/scripts.pory"
	compare VAR_RESULT, YES
# 13 "data/maps/MauvilleCity_House2/scripts.pory"
	goto_if_eq MauvilleCity_House2_EventScript_AcceptTrade
# 14 "data/maps/MauvilleCity_House2/scripts.pory"
	compare VAR_RESULT, NO
# 15 "data/maps/MauvilleCity_House2/scripts.pory"
	goto_if_eq MauvilleCity_House2_EventScript_DeclineTrade
# 16 "data/maps/MauvilleCity_House2/scripts.pory"
	end
# 17 "data/maps/MauvilleCity_House2/scripts.pory"

# 18 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_EventScript_AcceptTrade:: @ 8210CB8
# 19 "data/maps/MauvilleCity_House2/scripts.pory"
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
# 20 "data/maps/MauvilleCity_House2/scripts.pory"
	removeitem ITEM_ICE_STONE
# 21 "data/maps/MauvilleCity_House2/scripts.pory"
	giveitem ITEM_COIN_CASE
# 22 "data/maps/MauvilleCity_House2/scripts.pory"
	setflag FLAG_RECEIVED_COIN_CASE
# 23 "data/maps/MauvilleCity_House2/scripts.pory"
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
# 24 "data/maps/MauvilleCity_House2/scripts.pory"
	end
# 25 "data/maps/MauvilleCity_House2/scripts.pory"

# 26 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_EventScript_ReceivedCoinCase:: @ 8210CDA
# 27 "data/maps/MauvilleCity_House2/scripts.pory"
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
# 28 "data/maps/MauvilleCity_House2/scripts.pory"
	release
# 29 "data/maps/MauvilleCity_House2/scripts.pory"
	end
# 30 "data/maps/MauvilleCity_House2/scripts.pory"

# 31 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_EventScript_DeclineTrade:: @ 8210CE4
# 32 "data/maps/MauvilleCity_House2/scripts.pory"
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
# 33 "data/maps/MauvilleCity_House2/scripts.pory"
	release
# 34 "data/maps/MauvilleCity_House2/scripts.pory"
	end
# 35 "data/maps/MauvilleCity_House2/scripts.pory"

# 36 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_EventScript_Tutor::
# 37 "data/maps/MauvilleCity_House2/scripts.pory"
	lock
# 38 "data/maps/MauvilleCity_House2/scripts.pory"
	faceplayer
# 39 "data/maps/MauvilleCity_House2/scripts.pory"
	msgbox MauvilleCity_House2_Text_StarterMoveTeach, MSGBOX_YESNO
# 40 "data/maps/MauvilleCity_House2/scripts.pory"
	compare VAR_RESULT, NO
# 41 "data/maps/MauvilleCity_House2/scripts.pory"
	goto_if_eq MauvilleCity_House2_EventScript_StarterMoveDeclined
# 42 "data/maps/MauvilleCity_House2/scripts.pory"
	setvar VAR_0x8008, TRUE
# 43 "data/maps/MauvilleCity_House2/scripts.pory"
	message MauvilleCity_House2_Text_StarterMoveWhichMove
# 44 "data/maps/MauvilleCity_House2/scripts.pory"
	waitmessage
# 45 "data/maps/MauvilleCity_House2/scripts.pory"
	multichoice 0, 0, MULTI_STARTER_MOVES, 0
# 46 "data/maps/MauvilleCity_House2/scripts.pory"
	switch VAR_RESULT
# 47 "data/maps/MauvilleCity_House2/scripts.pory"
	case 0, MauvilleCity_House2_EventScript_StarterMoveGrassPledge
# 48 "data/maps/MauvilleCity_House2/scripts.pory"
	case 1, MauvilleCity_House2_EventScript_StarterMoveFirePledge
# 49 "data/maps/MauvilleCity_House2/scripts.pory"
	case 2, MauvilleCity_House2_EventScript_StarterMoveWaterPledge
# 50 "data/maps/MauvilleCity_House2/scripts.pory"
	case 3, MauvilleCity_House2_EventScript_StarterMoveFrenzyPlant
# 51 "data/maps/MauvilleCity_House2/scripts.pory"
	case 4, MauvilleCity_House2_EventScript_StarterMoveBlastBurn
# 52 "data/maps/MauvilleCity_House2/scripts.pory"
	case 5, MauvilleCity_House2_EventScript_StarterMoveHydroCannon
# 53 "data/maps/MauvilleCity_House2/scripts.pory"
	case MULTI_B_PRESSED, MauvilleCity_House2_EventScript_StarterMoveDeclined
# 54 "data/maps/MauvilleCity_House2/scripts.pory"
	goto MauvilleCity_House2_EventScript_StarterMoveDeclined
# 55 "data/maps/MauvilleCity_House2/scripts.pory"
	end
# 56 "data/maps/MauvilleCity_House2/scripts.pory"

# 57 "data/maps/MauvilleCity_House2/scripts.pory"
	MauvilleCity_House2_EventScript_StarterMoveGrassPledge::
# 58 "data/maps/MauvilleCity_House2/scripts.pory"
	setvar VAR_0x8005, TUTOR_MOVE_GRASS_PLEDGE
# 59 "data/maps/MauvilleCity_House2/scripts.pory"
	setvar VAR_0x8006, MOVE_GRASS_PLEDGE
# 60 "data/maps/MauvilleCity_House2/scripts.pory"
	goto MauvilleCity_House2_EventScript_TeachMove
# 61 "data/maps/MauvilleCity_House2/scripts.pory"

# 62 "data/maps/MauvilleCity_House2/scripts.pory"
	MauvilleCity_House2_EventScript_StarterMoveFirePledge::
# 63 "data/maps/MauvilleCity_House2/scripts.pory"
	setvar VAR_0x8005, TUTOR_MOVE_FIRE_PLEDGE
# 64 "data/maps/MauvilleCity_House2/scripts.pory"
	setvar VAR_0x8006, MOVE_FIRE_PLEDGE
# 65 "data/maps/MauvilleCity_House2/scripts.pory"
	goto MauvilleCity_House2_EventScript_TeachMove
# 66 "data/maps/MauvilleCity_House2/scripts.pory"

# 67 "data/maps/MauvilleCity_House2/scripts.pory"
	MauvilleCity_House2_EventScript_StarterMoveWaterPledge::
# 68 "data/maps/MauvilleCity_House2/scripts.pory"
	setvar VAR_0x8005, TUTOR_MOVE_WATER_PLEDGE
# 69 "data/maps/MauvilleCity_House2/scripts.pory"
	setvar VAR_0x8006, MOVE_WATER_PLEDGE
# 70 "data/maps/MauvilleCity_House2/scripts.pory"
	goto MauvilleCity_House2_EventScript_TeachMove
# 71 "data/maps/MauvilleCity_House2/scripts.pory"

# 72 "data/maps/MauvilleCity_House2/scripts.pory"
	MauvilleCity_House2_EventScript_StarterMoveFrenzyPlant::
# 73 "data/maps/MauvilleCity_House2/scripts.pory"
	setvar VAR_0x8005, TUTOR_MOVE_FRENZY_PLANT
# 74 "data/maps/MauvilleCity_House2/scripts.pory"
	setvar VAR_0x8006, MOVE_FRENZY_PLANT
# 75 "data/maps/MauvilleCity_House2/scripts.pory"
	goto MauvilleCity_House2_EventScript_TeachMove
# 76 "data/maps/MauvilleCity_House2/scripts.pory"

# 77 "data/maps/MauvilleCity_House2/scripts.pory"
	MauvilleCity_House2_EventScript_StarterMoveBlastBurn::
# 78 "data/maps/MauvilleCity_House2/scripts.pory"
	setvar VAR_0x8005, TUTOR_MOVE_BLAST_BURN
# 79 "data/maps/MauvilleCity_House2/scripts.pory"
	setvar VAR_0x8006, MOVE_BLAST_BURN
# 80 "data/maps/MauvilleCity_House2/scripts.pory"
	goto MauvilleCity_House2_EventScript_TeachMove
# 81 "data/maps/MauvilleCity_House2/scripts.pory"

# 82 "data/maps/MauvilleCity_House2/scripts.pory"
	MauvilleCity_House2_EventScript_StarterMoveHydroCannon::
# 83 "data/maps/MauvilleCity_House2/scripts.pory"
	setvar VAR_0x8005, TUTOR_MOVE_HYDRO_CANNON
# 84 "data/maps/MauvilleCity_House2/scripts.pory"
	setvar VAR_0x8006, MOVE_HYDRO_CANNON
# 85 "data/maps/MauvilleCity_House2/scripts.pory"
	goto MauvilleCity_House2_EventScript_TeachMove
# 86 "data/maps/MauvilleCity_House2/scripts.pory"

# 87 "data/maps/MauvilleCity_House2/scripts.pory"
	MauvilleCity_House2_EventScript_TeachMove::
# 88 "data/maps/MauvilleCity_House2/scripts.pory"
	buffermovename 0, VAR_0x8006
# 89 "data/maps/MauvilleCity_House2/scripts.pory"
	msgbox MauvilleCity_House2_Text_StarterMoveWhichMon, MSGBOX_DEFAULT
# 90 "data/maps/MauvilleCity_House2/scripts.pory"
	call MauvilleCity_House2_EventScript_OpenPartyMenu
# 91 "data/maps/MauvilleCity_House2/scripts.pory"
	compare VAR_RESULT, 0
# 92 "data/maps/MauvilleCity_House2/scripts.pory"
	goto_if_eq MauvilleCity_House2_EventScript_StarterMoveDeclined
# 93 "data/maps/MauvilleCity_House2/scripts.pory"
	goto MauvilleCity_House2_EventScript_StarterMoveTaught
# 94 "data/maps/MauvilleCity_House2/scripts.pory"
	end
# 95 "data/maps/MauvilleCity_House2/scripts.pory"

# 96 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_EventScript_StarterMoveDeclined::
# 97 "data/maps/MauvilleCity_House2/scripts.pory"
	setvar VAR_0x8008, FALSE
# 98 "data/maps/MauvilleCity_House2/scripts.pory"
	msgbox MauvilleCity_House2_Text_StarterMoveDeclined, MSGBOX_DEFAULT
# 99 "data/maps/MauvilleCity_House2/scripts.pory"
	release
# 100 "data/maps/MauvilleCity_House2/scripts.pory"
	end
# 101 "data/maps/MauvilleCity_House2/scripts.pory"

# 102 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_EventScript_OpenPartyMenu:: @ 82C8326
# 103 "data/maps/MauvilleCity_House2/scripts.pory"
	special ChooseMonForMoveTutor
# 104 "data/maps/MauvilleCity_House2/scripts.pory"
	waitstate
# 105 "data/maps/MauvilleCity_House2/scripts.pory"
	lock
# 106 "data/maps/MauvilleCity_House2/scripts.pory"
	faceplayer
# 107 "data/maps/MauvilleCity_House2/scripts.pory"
	return
# 108 "data/maps/MauvilleCity_House2/scripts.pory"

# 109 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_EventScript_StarterMoveTaught::
# 110 "data/maps/MauvilleCity_House2/scripts.pory"
	setvar VAR_0x8008, FALSE
# 111 "data/maps/MauvilleCity_House2/scripts.pory"
	msgbox MauvilleCity_House2_Text_StarterMoveTaught, MSGBOX_DEFAULT
# 112 "data/maps/MauvilleCity_House2/scripts.pory"
	release
# 113 "data/maps/MauvilleCity_House2/scripts.pory"
	end
# 114 "data/maps/MauvilleCity_House2/scripts.pory"

# 115 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_Text_BuyIceStoneAtSlateport: @ 8210CEE
# 116 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "If I had a Bike, it'd be easy to cycle to\n"
# 117 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Slateport for some shopping.\p"
# 118 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "I'd be able to buy an Ice Stone at the\n"
# 119 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Pokémon Mart in Slateport.$"
# 120 "data/maps/MauvilleCity_House2/scripts.pory"

# 121 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_Text_TradeIceStoneForCoinCase: @ 8210D76
# 122 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Oh! You have an Ice Stone?\n"
# 123 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Will you trade it for a Coin Case?$"
# 124 "data/maps/MauvilleCity_House2/scripts.pory"

# 125 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_Text_IllTradeYouCoinCase: @ 8210DB3
# 126 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Oh, now I can evolve my Eevee!\n"
# 127 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "I'm so happy!\p"
# 128 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Okay, I'll trade you a Coin Case!$"
# 129 "data/maps/MauvilleCity_House2/scripts.pory"

# 130 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_Text_UseCoinCaseAtGameCorner: @ 8210DE7
# 131 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "That Coin Case can be used\n"
# 132 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "at the Game Corner.$"
# 133 "data/maps/MauvilleCity_House2/scripts.pory"

# 134 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_Text_ThatsDisappointing: @ 8210E16
# 135 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Oh, that's disappointing.\p"
# 136 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "A Coin Case is needed for the\n"
# 137 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Game Corner.$"
# 138 "data/maps/MauvilleCity_House2/scripts.pory"

# 139 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_Text_StarterMoveTeach:
# 140 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "If you've got any Pokémon from a\n"
# 141 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Professor - starter Pokémon, in other\l"
# 142 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "words - I can teach them special moves.\p"
# 143 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Would you like a Pokémon to learn one?$"
# 144 "data/maps/MauvilleCity_House2/scripts.pory"

# 145 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_Text_StarterMoveDeclined:
# 146 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Suit yourself. Come back if you change\n"
# 147 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "your mind.$"
# 148 "data/maps/MauvilleCity_House2/scripts.pory"

# 149 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_Text_StarterMoveTaught:
# 150 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "If you want to try out more of these\n"
# 151 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "moves, you can get more starter\l"
# 152 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Pokémon at the Game Corner.$"
# 153 "data/maps/MauvilleCity_House2/scripts.pory"

# 154 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_Text_StarterMoveWhichMove:
# 155 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Which move should I teach?$"
# 156 "data/maps/MauvilleCity_House2/scripts.pory"

# 157 "data/maps/MauvilleCity_House2/scripts.pory"
MauvilleCity_House2_Text_StarterMoveWhichMon:
# 158 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "Which Pokémon should learn\n"
# 159 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "{STR_VAR_1}?$"

MauvilleCity_House2_EventScript_Woman::
# 162 "data/maps/MauvilleCity_House2/scripts.pory"
	lock
# 163 "data/maps/MauvilleCity_House2/scripts.pory"
	faceplayer
# 164 "data/maps/MauvilleCity_House2/scripts.pory"
	msgbox MauvilleCity_House2_EventScript_Woman_Text_0
# 165 "data/maps/MauvilleCity_House2/scripts.pory"
	release
	end


MauvilleCity_House2_EventScript_Woman_Text_0:
# 164 "data/maps/MauvilleCity_House2/scripts.pory"
	.string "You can get awesome Pokémon in the\n"
	.string "Casino.$"
