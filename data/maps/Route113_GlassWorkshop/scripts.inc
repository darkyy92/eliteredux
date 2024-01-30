# 1 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 2 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_MapScripts:: @ 826ED03
# 3 "data/maps/Route113_GlassWorkshop/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route113_GlassWorkshop_OnTransition
# 4 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.byte 0
# 5 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 6 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set BLUE_FLUTE_PRICE,   250
# 7 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set YELLOW_FLUTE_PRICE, 500
# 8 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set RED_FLUTE_PRICE,    500
# 9 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set WHITE_FLUTE_PRICE,  1000
# 10 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set BLACK_FLUTE_PRICE,  1000
# 11 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set PRETTY_CHAIR_PRICE, 6000
# 12 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set PRETTY_DESK_PRICE,  8000
# 13 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set LOWEST_ASH_PRICE,   BLUE_FLUTE_PRICE
# 14 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 15 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_OnTransition: @ 826ED09
# 16 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setflag FLAG_LANDMARK_GLASS_WORKSHOP
# 17 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_GLASS_WORKSHOP_STATE, 1
# 18 "data/maps/Route113_GlassWorkshop/scripts.pory"
	call_if_eq Route113_GlassWorkshop_EventScript_ReenterWorkshopAfterSootSack
# 19 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 20 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 21 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_ReenterWorkshopAfterSootSack:: @ 826ED18
# 22 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 2
# 23 "data/maps/Route113_GlassWorkshop/scripts.pory"
	return
# 24 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 25 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GlassWorker:: @ 826ED1E
# 26 "data/maps/Route113_GlassWorkshop/scripts.pory"
	lock
# 27 "data/maps/Route113_GlassWorkshop/scripts.pory"
	faceplayer
# 28 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_GLASS_WORKSHOP_STATE, 10
# 29 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_ge Route113_GlassWorkshop_EventScript_GiveItemAfterNoRoom
# 30 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_GLASS_WORKSHOP_STATE, 2
# 31 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq Route113_GlassWorkshop_EventScript_CheckCollectedAsh
# 32 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_GLASS_WORKSHOP_STATE, 1
# 33 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq Route113_GlassWorkshop_EventScript_ExplainSootSack
# 34 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_GoCollectAshWithThis, MSGBOX_DEFAULT
# 35 "data/maps/Route113_GlassWorkshop/scripts.pory"
	giveitem ITEM_SOOT_SACK
# 36 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 1
# 37 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_ExplainSootSack, MSGBOX_DEFAULT
# 38 "data/maps/Route113_GlassWorkshop/scripts.pory"
	release
# 39 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 40 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 41 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_ExplainSootSack:: @ 826ED64
# 42 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_ExplainSootSack, MSGBOX_DEFAULT
# 43 "data/maps/Route113_GlassWorkshop/scripts.pory"
	release
# 44 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 45 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 46 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_CheckCollectedAsh:: @ 826ED6E
# 47 "data/maps/Route113_GlassWorkshop/scripts.pory"
	checkitem ITEM_SOOT_SACK, 1
# 48 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_RESULT, FALSE
# 49 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq Route113_GlassWorkshop_EventScript_SootSackNotInBag
# 50 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_LetsSeeCollectedAshes, MSGBOX_DEFAULT
# 51 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_ASH_GATHER_COUNT, LOWEST_ASH_PRICE
# 52 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_lt Route113_GlassWorkshop_EventScript_NotEnoughAsh
# 53 "data/maps/Route113_GlassWorkshop/scripts.pory"
	message Route113_GlassWorkshop_Text_WhichGlassItemWoudYouLike
# 54 "data/maps/Route113_GlassWorkshop/scripts.pory"
	waitmessage
# 55 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_ChooseGlassItem
# 56 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 57 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 58 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_SootSackNotInBag:: @ 826ED9D
# 59 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_HaventGotYourSootSack, MSGBOX_DEFAULT
# 60 "data/maps/Route113_GlassWorkshop/scripts.pory"
	release
# 61 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 62 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 63 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_ChooseGlassItem:: @ 826EDA7
# 64 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 0
# 65 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_GLASS_WORKSHOP_VENDOR
# 66 "data/maps/Route113_GlassWorkshop/scripts.pory"
	special ShowScrollableMultichoice
# 67 "data/maps/Route113_GlassWorkshop/scripts.pory"
	waitstate
# 68 "data/maps/Route113_GlassWorkshop/scripts.pory"
	switch VAR_RESULT
# 69 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 0, Route113_GlassWorkshop_EventScript_BlueFlute
# 70 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 1, Route113_GlassWorkshop_EventScript_YellowFlute
# 71 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 2, Route113_GlassWorkshop_EventScript_RedFlute
# 72 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 3, Route113_GlassWorkshop_EventScript_WhiteFlute
# 73 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 4, Route113_GlassWorkshop_EventScript_BlackFlute
# 74 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 5, Route113_GlassWorkshop_EventScript_PrettyChair
# 75 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 6, Route113_GlassWorkshop_EventScript_PrettyDesk
# 76 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 7, Route113_GlassWorkshop_EventScript_CancelGlassItemSelect
# 77 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case MULTI_B_PRESSED, Route113_GlassWorkshop_EventScript_CancelGlassItemSelect
# 78 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 79 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 80 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_BlueFlute:: @ 826EE1E
# 81 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_BLUE_FLUTE
# 82 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname 0, VAR_0x8008
# 83 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x800A, BLUE_FLUTE_PRICE
# 84 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_ASH_GATHER_COUNT, BLUE_FLUTE_PRICE
# 85 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_lt Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
# 86 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
# 87 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_RESULT, NO
# 88 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq Route113_GlassWorkshop_EventScript_ChooseDifferentItem
# 89 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 10
# 90 "data/maps/Route113_GlassWorkshop/scripts.pory"
	subvar VAR_ASH_GATHER_COUNT, BLUE_FLUTE_PRICE
# 91 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
# 92 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 93 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 94 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_YellowFlute:: @ 826EE5A
# 95 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_YELLOW_FLUTE
# 96 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname 0, VAR_0x8008
# 97 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x800A, YELLOW_FLUTE_PRICE
# 98 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_ASH_GATHER_COUNT, YELLOW_FLUTE_PRICE
# 99 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_lt Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
# 100 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
# 101 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_RESULT, NO
# 102 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq Route113_GlassWorkshop_EventScript_ChooseDifferentItem
# 103 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 11
# 104 "data/maps/Route113_GlassWorkshop/scripts.pory"
	subvar VAR_ASH_GATHER_COUNT, YELLOW_FLUTE_PRICE
# 105 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
# 106 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 107 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 108 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_RedFlute:: @ 826EE96
# 109 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_RED_FLUTE
# 110 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname 0, VAR_0x8008
# 111 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x800A, RED_FLUTE_PRICE
# 112 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_ASH_GATHER_COUNT, RED_FLUTE_PRICE
# 113 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_lt Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
# 114 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
# 115 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_RESULT, NO
# 116 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq Route113_GlassWorkshop_EventScript_ChooseDifferentItem
# 117 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 12
# 118 "data/maps/Route113_GlassWorkshop/scripts.pory"
	subvar VAR_ASH_GATHER_COUNT, RED_FLUTE_PRICE
# 119 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
# 120 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 121 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 122 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_WhiteFlute:: @ 826EED2
# 123 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_WHITE_FLUTE
# 124 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname 0, VAR_0x8008
# 125 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x800A, WHITE_FLUTE_PRICE
# 126 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_ASH_GATHER_COUNT, WHITE_FLUTE_PRICE
# 127 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_lt Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
# 128 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
# 129 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_RESULT, NO
# 130 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq Route113_GlassWorkshop_EventScript_ChooseDifferentItem
# 131 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 13
# 132 "data/maps/Route113_GlassWorkshop/scripts.pory"
	subvar VAR_ASH_GATHER_COUNT, WHITE_FLUTE_PRICE
# 133 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
# 134 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 135 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 136 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_BlackFlute:: @ 826EF0E
# 137 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_BLACK_FLUTE
# 138 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname 0, VAR_0x8008
# 139 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x800A, BLACK_FLUTE_PRICE
# 140 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_ASH_GATHER_COUNT, BLACK_FLUTE_PRICE
# 141 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_lt Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
# 142 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
# 143 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_RESULT, NO
# 144 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq Route113_GlassWorkshop_EventScript_ChooseDifferentItem
# 145 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 14
# 146 "data/maps/Route113_GlassWorkshop/scripts.pory"
	subvar VAR_ASH_GATHER_COUNT, BLACK_FLUTE_PRICE
# 147 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
# 148 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 149 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 150 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_PrettyChair:: @ 826EF4A
# 151 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 1
# 152 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, DECOR_PRETTY_CHAIR
# 153 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferdecorationname 0, VAR_0x8008
# 154 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x800A, PRETTY_CHAIR_PRICE
# 155 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_ASH_GATHER_COUNT, PRETTY_CHAIR_PRICE
# 156 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_lt Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
# 157 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
# 158 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_RESULT, NO
# 159 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq Route113_GlassWorkshop_EventScript_ChooseDifferentItem
# 160 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 15
# 161 "data/maps/Route113_GlassWorkshop/scripts.pory"
	subvar VAR_ASH_GATHER_COUNT, PRETTY_CHAIR_PRICE
# 162 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
# 163 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 164 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 165 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_PrettyDesk:: @ 826EF8B
# 166 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 1
# 167 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, DECOR_PRETTY_DESK
# 168 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferdecorationname 0, VAR_0x8008
# 169 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x800A, PRETTY_DESK_PRICE
# 170 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_ASH_GATHER_COUNT, PRETTY_DESK_PRICE
# 171 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_lt Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
# 172 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
# 173 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_RESULT, NO
# 174 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq Route113_GlassWorkshop_EventScript_ChooseDifferentItem
# 175 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 16
# 176 "data/maps/Route113_GlassWorkshop/scripts.pory"
	subvar VAR_ASH_GATHER_COUNT, PRETTY_DESK_PRICE
# 177 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
# 178 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 179 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 180 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_CancelGlassItemSelect:: @ 826EFCC
# 181 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_AllThatAshButDontWantAnything, MSGBOX_DEFAULT
# 182 "data/maps/Route113_GlassWorkshop/scripts.pory"
	release
# 183 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 184 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 185 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_NotEnoughAsh:: @ 826EFD6
# 186 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x800A, LOWEST_ASH_PRICE
# 187 "data/maps/Route113_GlassWorkshop/scripts.pory"
	subvar VAR_0x800A, VAR_ASH_GATHER_COUNT
# 188 "data/maps/Route113_GlassWorkshop/scripts.pory"
	buffernumberstring 0, VAR_0x800A
# 189 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_NotEnoughAshNeedX, MSGBOX_DEFAULT
# 190 "data/maps/Route113_GlassWorkshop/scripts.pory"
	release
# 191 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 192 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 193 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_NotEnoughAshForItem:: @ 826EFEE
# 194 "data/maps/Route113_GlassWorkshop/scripts.pory"
	subvar VAR_0x800A, VAR_ASH_GATHER_COUNT
# 195 "data/maps/Route113_GlassWorkshop/scripts.pory"
	buffernumberstring 1, VAR_0x800A
# 196 "data/maps/Route113_GlassWorkshop/scripts.pory"
	message Route113_GlassWorkshop_Text_NotEnoughAshToMakeItem
# 197 "data/maps/Route113_GlassWorkshop/scripts.pory"
	waitmessage
# 198 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_ChooseGlassItem
# 199 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 200 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 201 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_ChooseDifferentItem:: @ 826F003
# 202 "data/maps/Route113_GlassWorkshop/scripts.pory"
	message Route113_GlassWorkshop_Text_WhichWouldYouLike
# 203 "data/maps/Route113_GlassWorkshop/scripts.pory"
	waitmessage
# 204 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_ChooseGlassItem
# 205 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 206 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 207 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_MakeGlassItem:: @ 826F00F
# 208 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IllMakeItemForYou, MSGBOX_DEFAULT
# 209 "data/maps/Route113_GlassWorkshop/scripts.pory"
	closemessage
# 210 "data/maps/Route113_GlassWorkshop/scripts.pory"
	fadescreen FADE_TO_BLACK
# 211 "data/maps/Route113_GlassWorkshop/scripts.pory"
	playse SE_SELECT
# 212 "data/maps/Route113_GlassWorkshop/scripts.pory"
	delay 30
# 213 "data/maps/Route113_GlassWorkshop/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 214 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IveFinishedGlassItem, MSGBOX_DEFAULT
# 215 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_0x8009, 0
# 216 "data/maps/Route113_GlassWorkshop/scripts.pory"
	call_if_eq Route113_GlassWorkshop_EventScript_GiveGlassFlute
# 217 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_0x8009, 1
# 218 "data/maps/Route113_GlassWorkshop/scripts.pory"
	call_if_eq Route113_GlassWorkshop_EventScript_GiveGlassDecor
# 219 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 2
# 220 "data/maps/Route113_GlassWorkshop/scripts.pory"
	release
# 221 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 222 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 223 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GiveGlassFlute:: @ 826F047
# 224 "data/maps/Route113_GlassWorkshop/scripts.pory"
	giveitem VAR_0x8008
# 225 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_RESULT, FALSE
# 226 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq Route113_GlassWorkshop_EventScript_NoRoomForFlute
# 227 "data/maps/Route113_GlassWorkshop/scripts.pory"
	return
# 228 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 229 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GiveGlassDecor:: @ 826F05F
# 230 "data/maps/Route113_GlassWorkshop/scripts.pory"
	givedecoration VAR_0x8008
# 231 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_RESULT, FALSE
# 232 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto_if_eq Route113_GlassWorkshop_EventScript_NoRoomForDecor
# 233 "data/maps/Route113_GlassWorkshop/scripts.pory"
	return
# 234 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 235 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_NoRoomForFlute:: @ 826F072
# 236 "data/maps/Route113_GlassWorkshop/scripts.pory"
	call Common_EventScript_BagIsFull
# 237 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_NoRoomInBag, MSGBOX_DEFAULT
# 238 "data/maps/Route113_GlassWorkshop/scripts.pory"
	release
# 239 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 240 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 241 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_NoRoomForDecor:: @ 826F081
# 242 "data/maps/Route113_GlassWorkshop/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 243 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_NoRoomInPC, MSGBOX_DEFAULT
# 244 "data/maps/Route113_GlassWorkshop/scripts.pory"
	release
# 245 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 246 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 247 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GiveItemAfterNoRoom:: @ 826F090
# 248 "data/maps/Route113_GlassWorkshop/scripts.pory"
	switch VAR_GLASS_WORKSHOP_STATE
# 249 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 10, Route113_GlassWorkshop_EventScript_GiveBlueFlute
# 250 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 11, Route113_GlassWorkshop_EventScript_GiveYellowFlute
# 251 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 12, Route113_GlassWorkshop_EventScript_GiveRedFlute
# 252 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 13, Route113_GlassWorkshop_EventScript_GiveWhiteFlute
# 253 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 14, Route113_GlassWorkshop_EventScript_GiveBlackFlute
# 254 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 15, Route113_GlassWorkshop_EventScript_GivePrettyChair
# 255 "data/maps/Route113_GlassWorkshop/scripts.pory"
	case 16, Route113_GlassWorkshop_EventScript_GivePrettyDesk
# 256 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 257 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 258 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GiveBlueFlute:: @ 826F0E3
# 259 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 0
# 260 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_BLUE_FLUTE
# 261 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname 0, VAR_0x8008
# 262 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
# 263 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 264 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 265 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GiveYellowFlute:: @ 826F0F7
# 266 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 0
# 267 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_YELLOW_FLUTE
# 268 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname 0, VAR_0x8008
# 269 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
# 270 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 271 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 272 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GiveRedFlute:: @ 826F10B
# 273 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 0
# 274 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_RED_FLUTE
# 275 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname 0, VAR_0x8008
# 276 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
# 277 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 278 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 279 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GiveWhiteFlute:: @ 826F11F
# 280 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 0
# 281 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_WHITE_FLUTE
# 282 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname 0, VAR_0x8008
# 283 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
# 284 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 285 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 286 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GiveBlackFlute:: @ 826F133
# 287 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 0
# 288 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, ITEM_BLACK_FLUTE
# 289 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferitemname 0, VAR_0x8008
# 290 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
# 291 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 292 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 293 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GivePrettyChair:: @ 826F147
# 294 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 1
# 295 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, DECOR_PRETTY_CHAIR
# 296 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferdecorationname 0, DECOR_PRETTY_CHAIR
# 297 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
# 298 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 299 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 300 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_GivePrettyDesk:: @ 826F15B
# 301 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8009, 1
# 302 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_0x8008, DECOR_PRETTY_DESK
# 303 "data/maps/Route113_GlassWorkshop/scripts.pory"
	bufferdecorationname 0, DECOR_PRETTY_DESK
# 304 "data/maps/Route113_GlassWorkshop/scripts.pory"
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
# 305 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 306 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 307 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_TryGiveItemAgain:: @ 826F16F
# 308 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_IveFinishedGlassItem, MSGBOX_DEFAULT
# 309 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_0x8009, 0
# 310 "data/maps/Route113_GlassWorkshop/scripts.pory"
	call_if_eq Route113_GlassWorkshop_EventScript_GiveGlassFlute
# 311 "data/maps/Route113_GlassWorkshop/scripts.pory"
	compare VAR_0x8009, 1
# 312 "data/maps/Route113_GlassWorkshop/scripts.pory"
	call_if_eq Route113_GlassWorkshop_EventScript_GiveGlassDecor
# 313 "data/maps/Route113_GlassWorkshop/scripts.pory"
	setvar VAR_GLASS_WORKSHOP_STATE, 2
# 314 "data/maps/Route113_GlassWorkshop/scripts.pory"
	release
# 315 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 316 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 317 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_EventScript_NinjaBoy:: @ 826F194
# 318 "data/maps/Route113_GlassWorkshop/scripts.pory"
	msgbox Route113_GlassWorkshop_Text_FunToBlowGlassFlute, MSGBOX_NPC
# 319 "data/maps/Route113_GlassWorkshop/scripts.pory"
	end
# 320 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 321 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_GoCollectAshWithThis: @ 826F19D
# 322 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "This area is covered in volcanic ash,\n"
# 323 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "huff-puff!\p"
# 324 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "I'm specially gifted, huff-puff.\p"
# 325 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "I make glass out of volcanic ash\n"
# 326 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "and make items, huff-puff.\p"
# 327 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Go collect ashes with this, huff-puff.$"
# 328 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 329 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_ExplainSootSack: @ 826F252
# 330 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Just take that Soot Sack and walk\n"
# 331 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "through piles of ash, huff-puff.\p"
# 332 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "And it will fill up with the volcanic ash,\n"
# 333 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "huff-puff.\p"
# 334 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Once you think you've collected a good\n"
# 335 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "amount, come see me, huff-puff.$"
# 336 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 337 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_LetsSeeCollectedAshes: @ 826F312
# 338 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Have you collected ashes, huff-puff?\n"
# 339 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Let me see, huff-puff.$"
# 340 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 341 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_NotEnoughAshNeedX: @ 826F34E
# 342 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Hmmm…\n"
# 343 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "There's not enough ash here, huff-puff.\l"
# 344 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "I can't make glass with this, huff-puff.\p"
# 345 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Let's see… {STR_VAR_1} is the number of steps\n"
# 346 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "you'll need to walk for me to make you\l"
# 347 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "a Blue Flute, huff-puff.$"
# 348 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 349 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_WhichGlassItemWoudYouLike: @ 826F40A
# 350 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Oh!\n"
# 351 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "You've got a lot of ashes, huff-puff!\p"
# 352 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "I'll make you a glass item, huff-puff!\n"
# 353 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Which one would you like, huff-puff?$"
# 354 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 355 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_IsThatTheItemForYou: @ 826F480
# 356 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "A {STR_VAR_1}, huff-puff?\n"
# 357 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Is that the one for you, huff-puff?$"
# 358 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 359 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_WhichWouldYouLike: @ 826F4B5
# 360 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Which one would you like, huff-puff?$"
# 361 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 362 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_IllMakeItemForYou: @ 826F4DA
# 363 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "A {STR_VAR_1} it is, then, huff-puff!\p"
# 364 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Okay! I'll make it for you, huff-puff.\n"
# 365 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Just wait a little while, huff-puff.$"
# 366 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 367 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_NotEnoughAshToMakeItem: @ 826F543
# 368 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "A {STR_VAR_1}, huff-puff?\p"
# 369 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "There's not enough ash here to make\n"
# 370 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "that, though, huff-puff.\p"
# 371 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Let's see… {STR_VAR_2} is the number of steps\n"
# 372 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "you'll need to walk through volcanic ash\l"
# 373 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "for me to make that item, huff-puff.\p"
# 374 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Which item would you rather have me\n"
# 375 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "make instead, huff-puff?$"
# 376 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 377 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_AllThatAshButDontWantAnything: @ 826F641
# 378 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "You've collected all that ash, but you\n"
# 379 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "don't want anything, huff-puff?$"
# 380 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 381 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_IveFinishedGlassItem: @ 826F688
# 382 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Ah, I've finished your {STR_VAR_1}.\n"
# 383 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Take it, huff-puff.$"
# 384 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 385 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_NoRoomInBag: @ 826F6B7
# 386 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Oh?\n"
# 387 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "You've no room in your Bag, huff-puff.\p"
# 388 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "I'll hold on to it, so come back later,\n"
# 389 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "huff-puff.$"
# 390 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 391 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_NoRoomInPC: @ 826F715
# 392 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Oh?\n"
# 393 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "You've no room in your PC, huff-puff?\p"
# 394 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "I'll hold on to it, so come back later,\n"
# 395 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "huff-puff.$"
# 396 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 397 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_HaventGotYourSootSack: @ 826F772
# 398 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Hah? You haven't got your Soot Sack\n"
# 399 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "with you, huff-puff.\p"
# 400 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "You have to keep it with you to collect\n"
# 401 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "volcanic ash, huff-puff.$"
# 402 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 403 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_Text_FunToBlowGlassFlute: @ 826F7EC
# 404 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "It's fun to blow a glass flute while\n"
# 405 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "my boss is talking.\p"
# 406 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Huff-huff! Puff-puff!$"
