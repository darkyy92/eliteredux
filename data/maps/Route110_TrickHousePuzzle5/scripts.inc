# 1 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 2 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
.set LOCALID_MECHADOLL_1, 1
# 3 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
.set LOCALID_MECHADOLL_2, 2
# 4 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
.set LOCALID_MECHADOLL_3, 3
# 5 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
.set LOCALID_MECHADOLL_4, 4
# 6 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
.set LOCALID_MECHADOLL_5, 5
# 7 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 8 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_MapScripts:: @ 826CAF0
# 9 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle5_OnTransition
# 10 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.byte 0
# 11 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 12 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_OnTransition: @ 826CAF6
# 13 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_1, 0
# 14 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_2, 0
# 15 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_3, 0
# 16 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_4, 0
# 17 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_5, 0
# 18 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_8, 0
# 19 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 20 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 21 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Scroll:: @ 826CB15
# 22 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 23 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_5_STATE, 0
# 24 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle5_EventScript_FoundScroll
# 25 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 26 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 27 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 28 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_FoundScroll:: @ 826CB27
# 29 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_5_STATE, 1
# 30 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 31 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 32 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 33 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1:: @ 826CB32
# 34 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 35 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Common_Movement_FacePlayer
# 36 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 37 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_1, 1
# 38 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
# 39 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 40 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
# 41 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 42 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 43 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2:: @ 826CB53
# 44 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 45 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Common_Movement_FacePlayer
# 46 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 47 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_2, 1
# 48 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
# 49 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 50 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 51 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 52 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 53 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3:: @ 826CB74
# 54 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 55 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Common_Movement_FacePlayer
# 56 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 57 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_3, 1
# 58 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
# 59 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 60 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
# 61 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 62 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 63 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4:: @ 826CB95
# 64 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 65 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Common_Movement_FacePlayer
# 66 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 67 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_4, 1
# 68 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
# 69 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 70 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 71 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 72 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 73 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5:: @ 826CBB6
# 74 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 75 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Common_Movement_FacePlayer
# 76 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 77 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_5, 1
# 78 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
# 79 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 80 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll5Activate
# 81 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 82 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 83 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger0:: @ 826CBD7
# 84 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 85 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 86 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
# 87 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 88 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 89 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger1:: @ 826CBE3
# 90 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 91 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 1
# 92 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
# 93 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 94 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 95 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger2:: @ 826CBEF
# 96 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 97 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 2
# 98 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
# 99 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 100 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 101 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger3:: @ 826CBFB
# 102 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 103 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 3
# 104 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
# 105 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 106 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 107 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger4:: @ 826CC07
# 108 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 109 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 4
# 110 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate
# 111 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 112 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 113 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger0:: @ 826CC13
# 114 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 115 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 116 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 117 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 118 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 119 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger1:: @ 826CC1F
# 120 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 121 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 1
# 122 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 123 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 124 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 125 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger2:: @ 826CC2B
# 126 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 127 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 2
# 128 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 129 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 130 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 131 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger3:: @ 826CC37
# 132 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 133 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 3
# 134 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 135 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 136 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 137 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger4:: @ 826CC43
# 138 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 139 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 4
# 140 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 141 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 142 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 143 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger5:: @ 826CC4F
# 144 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 145 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 5
# 146 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate
# 147 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 148 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 149 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger0:: @ 826CC5B
# 150 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 151 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 152 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
# 153 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 154 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 155 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger1:: @ 826CC67
# 156 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 157 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 1
# 158 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
# 159 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 160 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 161 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger2:: @ 826CC73
# 162 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 163 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 2
# 164 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
# 165 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 166 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 167 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger3:: @ 826CC7F
# 168 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 169 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 3
# 170 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
# 171 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 172 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 173 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger4:: @ 826CC8B
# 174 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 175 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 4
# 176 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate
# 177 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 178 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 179 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger0:: @ 826CC97
# 180 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 181 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 182 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 183 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 184 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 185 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger1:: @ 826CCA3
# 186 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 187 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 1
# 188 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 189 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 190 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 191 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger2:: @ 826CCAF
# 192 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 193 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 2
# 194 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 195 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 196 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 197 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger3:: @ 826CCBB
# 198 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 199 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 3
# 200 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 201 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 202 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 203 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger4:: @ 826CCC7
# 204 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 205 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 4
# 206 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 207 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 208 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 209 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
@ Unused
# 210 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger5:: @ 826CCD3
# 211 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 212 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 5
# 213 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate
# 214 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 215 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 216 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5Trigger0:: @ 826CCDF
# 217 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	lockall
# 218 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_9, 0
# 219 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_Mechadoll5Activate
# 220 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 221 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 222 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Activate:: @ 826CCEB
# 223 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_1, 1
# 224 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_1
# 225 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_PIN
# 226 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Common_Movement_ExclamationMark
# 227 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 228 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Common_Movement_Delay48
# 229 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 230 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_9, 1
# 231 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1
# 232 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_9, 2
# 233 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2
# 234 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_9, 3
# 235 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3
# 236 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_9, 4
# 237 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4
# 238 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Intro, MSGBOX_DEFAULT
# 239 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	random 3
# 240 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 241 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz1
# 242 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz2
# 243 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz3
# 244 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 245 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 246 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Activate:: @ 826CD6A
# 247 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_2, 1
# 248 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_2
# 249 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_PIN
# 250 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Common_Movement_ExclamationMark
# 251 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 252 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Common_Movement_Delay48
# 253 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 254 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_9, 1
# 255 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight1
# 256 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_9, 2
# 257 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight2
# 258 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_9, 3
# 259 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight3
# 260 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_9, 4
# 261 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight4
# 262 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_9, 5
# 263 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight5
# 264 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Intro, MSGBOX_DEFAULT
# 265 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	random 3
# 266 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 267 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz1
# 268 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz2
# 269 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz3
# 270 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 271 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 272 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Activate:: @ 826CDF4
# 273 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_3, 1
# 274 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_3
# 275 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_PIN
# 276 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Common_Movement_ExclamationMark
# 277 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 278 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Common_Movement_Delay48
# 279 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 280 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_9, 1
# 281 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1
# 282 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_9, 2
# 283 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2
# 284 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_9, 3
# 285 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3
# 286 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_9, 4
# 287 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4
# 288 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Intro, MSGBOX_DEFAULT
# 289 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	random 3
# 290 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 291 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz1
# 292 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz2
# 293 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz3
# 294 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 295 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 296 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Activate:: @ 826CE73
# 297 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_4, 1
# 298 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_4
# 299 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_PIN
# 300 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Common_Movement_ExclamationMark
# 301 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 302 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Common_Movement_Delay48
# 303 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 304 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_9, 1
# 305 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1
# 306 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_9, 2
# 307 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2
# 308 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_9, 3
# 309 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3
# 310 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_9, 4
# 311 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4
# 312 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Intro, MSGBOX_DEFAULT
# 313 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	random 3
# 314 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 315 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz1
# 316 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz2
# 317 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz3
# 318 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 319 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 320 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5Activate:: @ 826CEF2
# 321 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_5, 1
# 322 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	setvar VAR_TEMP_8, LOCALID_MECHADOLL_5
# 323 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_PIN
# 324 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Common_Movement_ExclamationMark
# 325 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 326 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Common_Movement_Delay48
# 327 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 328 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Intro, MSGBOX_DEFAULT
# 329 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	random 3
# 330 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 331 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz1
# 332 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz2
# 333 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz3
# 334 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 335 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 336 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz1:: @ 826CF45
# 337 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz1, MSGBOX_DEFAULT
# 338 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL1_Q1, TRUE
# 339 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 340 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 341 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 342 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 343 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 344 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz2:: @ 826CF68
# 345 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz2, MSGBOX_DEFAULT
# 346 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL1_Q2, TRUE
# 347 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 348 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 349 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 350 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 351 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 352 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1Quiz3:: @ 826CF8B
# 353 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz3, MSGBOX_DEFAULT
# 354 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL1_Q3, TRUE
# 355 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 356 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 357 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 358 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 359 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 360 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz1:: @ 826CFAE
# 361 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz1, MSGBOX_DEFAULT
# 362 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL2_Q1, TRUE
# 363 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 364 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 365 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 366 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 367 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 368 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz2:: @ 826CFD1
# 369 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz2, MSGBOX_DEFAULT
# 370 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL2_Q2, TRUE
# 371 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 372 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 373 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 374 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 375 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 376 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2Quiz3:: @ 826CFF4
# 377 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz3, MSGBOX_DEFAULT
# 378 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL2_Q3, TRUE
# 379 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 380 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 381 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 382 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 383 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 384 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz1:: @ 826D017
# 385 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz1, MSGBOX_DEFAULT
# 386 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL3_Q1, TRUE
# 387 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 388 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 389 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 390 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 391 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 392 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz2:: @ 826D03A
# 393 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz2, MSGBOX_DEFAULT
# 394 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL3_Q2, TRUE
# 395 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 396 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 397 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 398 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 399 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 400 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3Quiz3:: @ 826D05D
# 401 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz3, MSGBOX_DEFAULT
# 402 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL3_Q3, TRUE
# 403 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 404 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 405 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 406 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 407 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 408 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz1:: @ 826D080
# 409 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz1, MSGBOX_DEFAULT
# 410 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL4_Q1, TRUE
# 411 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 412 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 413 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 414 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 415 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 416 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz2:: @ 826D0A3
# 417 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz2, MSGBOX_DEFAULT
# 418 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL4_Q2, TRUE
# 419 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 420 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 421 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 422 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 423 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 424 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4Quiz3:: @ 826D0C6
# 425 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz3, MSGBOX_DEFAULT
# 426 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL4_Q3, TRUE
# 427 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 428 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 429 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 430 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 431 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 432 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz1:: @ 826D0E9
# 433 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz1, MSGBOX_DEFAULT
# 434 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL5_Q1, TRUE
# 435 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 436 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 1, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 437 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 438 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 439 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 440 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz2:: @ 826D10C
# 441 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz2, MSGBOX_DEFAULT
# 442 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL5_Q2, TRUE
# 443 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 444 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 0, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 445 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 446 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 447 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 448 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5Quiz3:: @ 826D12F
# 449 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz3, MSGBOX_DEFAULT
# 450 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	multichoice 0, 0, MULTI_MECHADOLL5_Q3, TRUE
# 451 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	switch VAR_RESULT
# 452 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	case 2, Route110_TrickHousePuzzle5_EventScript_CorrectAnswer
# 453 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer
# 454 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 455 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 456 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_IncorrectAnswer:: @ 826D152
# 457 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitse
# 458 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_FAILURE
# 459 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_DisappointmentError, MSGBOX_DEFAULT
# 460 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_MechadollShake
# 461 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_MechadollShake
# 462 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_MechadollShake
# 463 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_MechadollShake
# 464 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_MechadollShake
# 465 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_Wahahahaha, MSGBOX_DEFAULT
# 466 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 467 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_WaitForNextChallenge, MSGBOX_DEFAULT
# 468 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	closemessage
# 469 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE5, 255, 0, 21
# 470 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitstate
# 471 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	releaseall
# 472 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 473 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 474 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_CorrectAnswer:: @ 826D1A0
# 475 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitse
# 476 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	playse SE_SUCCESS
# 477 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	goto Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough
# 478 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 479 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 480 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_CorrectGoThrough:: @ 826D1AA
# 481 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_CorrectGoThrough, MSGBOX_DEFAULT
# 482 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	releaseall
# 483 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	end
# 484 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 485 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
@ Absurd redundancy in movement scripts that could be resolved by using VAR_TEMP_8 for applymovement instead
# 486 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
@ Many of the below movement scripts arent even used, see below
# 487 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
@   Mechadoll 2 is the only mechadoll to walk right, all the other WalkRight scripts are unused
# 488 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
@   Mechadoll 5 never walks, all the Mechadoll5Walk scripts are unused
# 489 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
@   No mechadoll walks left 5 paces, all the WalkLeft5 scripts are unused
# 490 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft1:: @ 826D1B4
# 491 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
# 492 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft1
# 493 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
# 494 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft1
# 495 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
# 496 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft1
# 497 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
# 498 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft1
# 499 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
# 500 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft1
# 501 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 502 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 503 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft2:: @ 826D1EC
# 504 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
# 505 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft2
# 506 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
# 507 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft2
# 508 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
# 509 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft2
# 510 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
# 511 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft2
# 512 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
# 513 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft2
# 514 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 515 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 516 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft3:: @ 826D224
# 517 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
# 518 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft3
# 519 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
# 520 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft3
# 521 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
# 522 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft3
# 523 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
# 524 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft3
# 525 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
# 526 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft3
# 527 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 528 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 529 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft4:: @ 826D25C
# 530 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
# 531 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft4
# 532 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
# 533 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft4
# 534 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
# 535 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft4
# 536 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
# 537 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft4
# 538 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
# 539 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft4
# 540 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 541 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 542 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkLeft5:: @ 826D294
# 543 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
# 544 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft5
# 545 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
# 546 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft5
# 547 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
# 548 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft5
# 549 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
# 550 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft5
# 551 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
# 552 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft5
# 553 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 554 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 555 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight1:: @ 826D2CC
# 556 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
# 557 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight1
# 558 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
# 559 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight1
# 560 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
# 561 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight1
# 562 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
# 563 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight1
# 564 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
# 565 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight1
# 566 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 567 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 568 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight2:: @ 826D304
# 569 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
# 570 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight2
# 571 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
# 572 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight2
# 573 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
# 574 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight2
# 575 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
# 576 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight2
# 577 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
# 578 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight2
# 579 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 580 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 581 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight3:: @ 826D33C
# 582 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
# 583 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight3
# 584 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
# 585 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight3
# 586 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
# 587 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight3
# 588 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
# 589 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight3
# 590 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
# 591 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight3
# 592 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 593 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 594 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight4:: @ 826D374
# 595 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
# 596 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight4
# 597 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
# 598 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight4
# 599 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
# 600 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight4
# 601 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
# 602 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight4
# 603 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
# 604 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight4
# 605 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 606 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 607 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_MechadollWalkRight5:: @ 826D3AC
# 608 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_1
# 609 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight5
# 610 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_2
# 611 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight5
# 612 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_3
# 613 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight5
# 614 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_4
# 615 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight5
# 616 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	compare VAR_TEMP_8, LOCALID_MECHADOLL_5
# 617 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight5
# 618 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 619 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 620 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft1:: @ 826D3E4
# 621 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft1
# 622 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 623 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 624 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 625 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft1:: @ 826D3EF
# 626 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft1
# 627 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 628 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 629 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 630 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft1:: @ 826D3FA
# 631 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft1
# 632 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 633 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 634 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 635 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft1:: @ 826D405
# 636 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft1
# 637 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 638 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 639 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 640 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft1:: @ 826D410
# 641 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft1
# 642 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 643 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 644 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 645 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft2:: @ 826D41B
# 646 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft2
# 647 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 648 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 649 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 650 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft2:: @ 826D426
# 651 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft2
# 652 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 653 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 654 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 655 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft2:: @ 826D431
# 656 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft2
# 657 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 658 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 659 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 660 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft2:: @ 826D43C
# 661 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft2
# 662 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 663 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 664 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 665 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft2:: @ 826D447
# 666 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft2
# 667 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 668 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 669 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 670 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft3:: @ 826D452
# 671 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft3
# 672 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 673 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 674 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 675 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft3:: @ 826D45D
# 676 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft3
# 677 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 678 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 679 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 680 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft3:: @ 826D468
# 681 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft3
# 682 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 683 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 684 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 685 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft3:: @ 826D473
# 686 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft3
# 687 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 688 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 689 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 690 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft3:: @ 826D47E
# 691 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft3
# 692 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 693 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 694 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 695 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft4:: @ 826D489
# 696 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft4
# 697 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 698 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 699 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 700 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft4:: @ 826D494
# 701 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft4
# 702 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 703 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 704 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 705 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft4:: @ 826D49F
# 706 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft4
# 707 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 708 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 709 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 710 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft4:: @ 826D4AA
# 711 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft4
# 712 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 713 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 714 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 715 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft4:: @ 826D4B5
# 716 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft4
# 717 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 718 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 719 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 720 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkLeft5:: @ 826D4C0
# 721 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkLeft5
# 722 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 723 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 724 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 725 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkLeft5:: @ 826D4CB
# 726 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkLeft5
# 727 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 728 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 729 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 730 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkLeft5:: @ 826D4D6
# 731 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkLeft5
# 732 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 733 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 734 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 735 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkLeft5:: @ 826D4E1
# 736 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkLeft5
# 737 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 738 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 739 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 740 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkLeft5:: @ 826D4EC
# 741 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkLeft5
# 742 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 743 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 744 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 745 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight1:: @ 826D4F7
# 746 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight1
# 747 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 748 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 749 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 750 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight1:: @ 826D502
# 751 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight1
# 752 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 753 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 754 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 755 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight1:: @ 826D50D
# 756 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight1
# 757 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 758 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 759 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 760 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight1:: @ 826D518
# 761 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight1
# 762 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 763 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 764 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 765 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight1:: @ 826D523
# 766 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight1
# 767 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 768 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 769 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 770 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight2:: @ 826D52E
# 771 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight2
# 772 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 773 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 774 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 775 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight2:: @ 826D539
# 776 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight2
# 777 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 778 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 779 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 780 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight2:: @ 826D544
# 781 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight2
# 782 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 783 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 784 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 785 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight2:: @ 826D54F
# 786 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight2
# 787 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 788 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 789 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 790 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight2:: @ 826D55A
# 791 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight2
# 792 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 793 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 794 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 795 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight3:: @ 826D565
# 796 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight3
# 797 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 798 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 799 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 800 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight3:: @ 826D570
# 801 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight3
# 802 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 803 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 804 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 805 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight3:: @ 826D57B
# 806 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight3
# 807 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 808 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 809 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 810 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight3:: @ 826D586
# 811 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight3
# 812 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 813 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 814 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 815 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight3:: @ 826D591
# 816 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight3
# 817 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 818 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 819 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 820 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight4:: @ 826D59C
# 821 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight4
# 822 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 823 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 824 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 825 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight4:: @ 826D5A7
# 826 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight4
# 827 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 828 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 829 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 830 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight4:: @ 826D5B2
# 831 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight4
# 832 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 833 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 834 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 835 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight4:: @ 826D5BD
# 836 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight4
# 837 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 838 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 839 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 840 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight4:: @ 826D5C8
# 841 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight4
# 842 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 843 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 844 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 845 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll1WalkRight5:: @ 826D5D3
# 846 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_1, Route110_TrickHousePuzzle5_Movement_WalkRight5
# 847 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 848 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 849 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 850 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll2WalkRight5:: @ 826D5DE
# 851 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_2, Route110_TrickHousePuzzle5_Movement_WalkRight5
# 852 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 853 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 854 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 855 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll3WalkRight5:: @ 826D5E9
# 856 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_3, Route110_TrickHousePuzzle5_Movement_WalkRight5
# 857 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 858 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 859 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 860 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll4WalkRight5:: @ 826D5F4
# 861 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_4, Route110_TrickHousePuzzle5_Movement_WalkRight5
# 862 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 863 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 864 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 865 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Mechadoll5WalkRight5:: @ 826D5FF
# 866 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	applymovement LOCALID_MECHADOLL_5, Route110_TrickHousePuzzle5_Movement_WalkRight5
# 867 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	waitmovement 0
# 868 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	return
# 869 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 870 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkLeft1: @ 826D60A
# 871 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 872 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 873 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 874 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkLeft2: @ 826D60C
# 875 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 876 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 877 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 878 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 879 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkLeft3: @ 826D60F
# 880 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 881 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 882 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 883 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 884 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 885 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkLeft4: @ 826D613
# 886 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 887 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 888 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 889 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 890 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 891 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 892 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkLeft5: @ 826D618
# 893 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 894 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 895 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 896 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 897 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_left
# 898 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 899 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 900 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkRight1: @ 826D61E
# 901 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 902 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 903 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 904 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkRight2: @ 826D620
# 905 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 906 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 907 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 908 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 909 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkRight3: @ 826D623
# 910 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 911 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 912 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 913 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 914 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 915 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkRight4: @ 826D627
# 916 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 917 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 918 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 919 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 920 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 921 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 922 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_WalkRight5: @ 826D62C
# 923 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 924 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 925 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 926 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 927 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	walk_right
# 928 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 929 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 930 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Movement_MechadollShake: @ 826D632
# 931 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 932 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 933 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 934 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 935 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 936 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 937 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 938 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 939 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 940 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 941 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 942 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 943 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 944 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 945 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 946 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 947 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 948 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 949 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 950 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 951 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 952 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 953 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 954 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 955 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 956 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 957 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 958 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 959 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 960 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 961 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 962 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 963 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 964 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 965 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 966 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 967 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 968 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 969 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 970 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 971 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_left
# 972 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 973 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_right
# 974 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	delay_2
# 975 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	face_down
# 976 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	step_end
# 977 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 978 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_WroteSecretCodeLockOpened: @ 826D660
# 979 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 980 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "on the door.\p"
# 981 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "“Trick Master is a genius.”\n"
# 982 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "… … … … … … … …\p"
# 983 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "The lock clicked open!$"
# 984 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 985 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll1Intro: @ 826D6CE
# 986 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CLICKETY-CLACK…\n"
# 987 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 1 AM I!\p"
# 988 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "IF YOU ANSWER QUIZZES CORRECTLY,\n"
# 989 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "THEN YOU WILL GO TO MECHADOLL 5.\l"
# 990 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "THEN YOU CAN OBTAIN THE SECRET CODE.$"
# 991 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 992 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz1: @ 826D757
# 993 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 1 QUIZ.\p"
# 994 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "One of these Pokémon is not found\n"
# 995 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "on Route 110. Which one is it?$"
# 996 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 997 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz2: @ 826D7AA
# 998 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 1 QUIZ.\p"
# 999 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "One of these Pokémon is not of the\n"
# 1000 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Water type. Which one is it?$"
# 1001 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1002 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll1Quiz3: @ 826D7FC
# 1003 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 1 QUIZ.\p"
# 1004 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "One of these Pokémon does not use\n"
# 1005 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Leech Life. Which one is it?$"
# 1006 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1007 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_CorrectGoThrough: @ 826D84D
# 1008 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CONGRATULATIONS. CORRECT YOU ARE.\n"
# 1009 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "GO THROUGH. PLEASE.$"
# 1010 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1011 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_DisappointmentError: @ 826D883
# 1012 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "BZZZT. DISAPPOINTMENT.\n"
# 1013 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "ERROR.$"
# 1014 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1015 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Wahahahaha: @ 826D8A1
# 1016 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "WAHAHAHAHA! WAHAHAHAHA!\n"
# 1017 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CLICKETY-CLACK!$"
# 1018 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1019 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_WaitForNextChallenge: @ 826D8C9
# 1020 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "YOUR NEXT CHALLENGE WE WAIT FOR.$"
# 1021 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1022 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll2Intro: @ 826D8EA
# 1023 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CLICKETY-CLACK…\n"
# 1024 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 2 AM I!\p"
# 1025 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 1'S QUIZ DIFFICULTY LEVEL\n"
# 1026 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "IS SET TOO LOW.$"
# 1027 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1028 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz1: @ 826D940
# 1029 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 2 QUIZ.\p"
# 1030 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Which of these Pokémon did Wally\n"
# 1031 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "borrow from your father?$"
# 1032 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1033 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz2: @ 826D98C
# 1034 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 2 QUIZ.\p"
# 1035 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Which of these Pokémon was chasing\n"
# 1036 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Prof. Birch?$"
# 1037 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1038 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll2Quiz3: @ 826D9CE
# 1039 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 2 QUIZ.\p"
# 1040 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Which of these Pokémon did Team Aqua\n"
# 1041 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "use in Petalburg Forest?$"
# 1042 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1043 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll3Intro: @ 826DA1E
# 1044 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CLICKETY-CLACK…\n"
# 1045 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 3 AM I!\p"
# 1046 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MATTERS OF MONEY ARE MY SOLE FOCUS.$"
# 1047 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1048 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz1: @ 826DA64
# 1049 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 3 QUIZ.\p"
# 1050 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Which costs more?\n"
# 1051 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Three Harbor Mails or one Burn Heal?$"
# 1052 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1053 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz2: @ 826DAAD
# 1054 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 3 QUIZ.\p"
# 1055 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Sell one Great Ball and buy\n"
# 1056 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "one Potion. How much money remains?$"
# 1057 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1058 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll3Quiz3: @ 826DAFF
# 1059 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 3 QUIZ.\p"
# 1060 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Do one Repel and Soda Pop cost\n"
# 1061 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "more than one Super Potion?$"
# 1062 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1063 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll4Intro: @ 826DB4C
# 1064 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CLICKETY-CLACK…\n"
# 1065 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 4 THAT IS ME!\p"
# 1066 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MY QUIZ IS AN OBJECT OF BEAUTY.$"
# 1067 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1068 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz1: @ 826DB94
# 1069 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 4 QUIZ.\p"
# 1070 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "In Seashore House, were there more men\n"
# 1071 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "or women?$"
# 1072 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1073 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz2: @ 826DBD7
# 1074 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 4 QUIZ.\p"
# 1075 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "In Lavaridge Town, were there more\n"
# 1076 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "elderly men or elderly women?$"
# 1077 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1078 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll4Quiz3: @ 826DC2A
# 1079 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 4 QUIZ.\p"
# 1080 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "In the Trainer's School, how many\n"
# 1081 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "girl students were there?$"
# 1082 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1083 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll5Intro: @ 826DC78
# 1084 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "CLICKETY-CLACK…\n"
# 1085 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 5 AM I!\p"
# 1086 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "THE MASTER'S BEST AND PROUDEST\n"
# 1087 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "ACHIEVEMENT AM I.$"
# 1088 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1089 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz1: @ 826DCCB
# 1090 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 5 QUIZ.\p"
# 1091 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "In Slateport's Pokémon Fan Club,\n"
# 1092 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "how many Pokémon were there?$"
# 1093 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1094 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz2: @ 826DD1B
# 1095 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 5 QUIZ.\p"
# 1096 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "In Fortree City, how many\n"
# 1097 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "tree houses were there?$"
# 1098 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"

# 1099 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
Route110_TrickHousePuzzle5_Text_Mechadoll5Quiz3: @ 826DD5F
# 1100 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "MECHADOLL 5 QUIZ.\p"
# 1101 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "On the Cycling Road, how many\n"
# 1102 "data/maps/Route110_TrickHousePuzzle5/scripts.pory"
	.string "Triathletes were there?$"
