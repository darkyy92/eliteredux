# 1 "data/maps/UnionRoom/scripts.pory"

# 2 "data/maps/UnionRoom/scripts.pory"
.set LOCALID_UR_PLAYER_4, 2
# 3 "data/maps/UnionRoom/scripts.pory"
.set LOCALID_UR_PLAYER_8, 3
# 4 "data/maps/UnionRoom/scripts.pory"
.set LOCALID_UR_PLAYER_7, 4
# 5 "data/maps/UnionRoom/scripts.pory"
.set LOCALID_UR_PLAYER_6, 5
# 6 "data/maps/UnionRoom/scripts.pory"
.set LOCALID_UR_PLAYER_5, 6
# 7 "data/maps/UnionRoom/scripts.pory"
.set LOCALID_UR_PLAYER_3, 7
# 8 "data/maps/UnionRoom/scripts.pory"
.set LOCALID_UR_PLAYER_2, 8
# 9 "data/maps/UnionRoom/scripts.pory"
.set LOCALID_UR_PLAYER_1, 9
# 10 "data/maps/UnionRoom/scripts.pory"

# 11 "data/maps/UnionRoom/scripts.pory"
UnionRoom_MapScripts:: @ 823D1A6
# 12 "data/maps/UnionRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, UnionRoom_OnResume
# 13 "data/maps/UnionRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, UnionRoom_OnTransition
# 14 "data/maps/UnionRoom/scripts.pory"
	.byte 0
# 15 "data/maps/UnionRoom/scripts.pory"

# 16 "data/maps/UnionRoom/scripts.pory"
UnionRoom_OnResume: @ 823D1B1
# 17 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_1
# 18 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_2
# 19 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_3
# 20 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_4
# 21 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_5
# 22 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_6
# 23 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_7
# 24 "data/maps/UnionRoom/scripts.pory"
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_8
# 25 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UR_PLAYER_1
# 26 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UR_PLAYER_2
# 27 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UR_PLAYER_3
# 28 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UR_PLAYER_4
# 29 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UR_PLAYER_5
# 30 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UR_PLAYER_6
# 31 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UR_PLAYER_7
# 32 "data/maps/UnionRoom/scripts.pory"
	removeobject LOCALID_UR_PLAYER_8
# 33 "data/maps/UnionRoom/scripts.pory"
	special RunUnionRoom
# 34 "data/maps/UnionRoom/scripts.pory"
	end
# 35 "data/maps/UnionRoom/scripts.pory"

# 36 "data/maps/UnionRoom/scripts.pory"
UnionRoom_OnTransition: @ 823D1E5
# 37 "data/maps/UnionRoom/scripts.pory"
	end
# 38 "data/maps/UnionRoom/scripts.pory"

# 39 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player1:: @ 823D1E6
# 40 "data/maps/UnionRoom/scripts.pory"
	lock
# 41 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 42 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_1
# 43 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 44 "data/maps/UnionRoom/scripts.pory"
	release
# 45 "data/maps/UnionRoom/scripts.pory"
	end
# 46 "data/maps/UnionRoom/scripts.pory"

# 47 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player2:: @ 823D1F0
# 48 "data/maps/UnionRoom/scripts.pory"
	lock
# 49 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 50 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_2
# 51 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 52 "data/maps/UnionRoom/scripts.pory"
	release
# 53 "data/maps/UnionRoom/scripts.pory"
	end
# 54 "data/maps/UnionRoom/scripts.pory"

# 55 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player3:: @ 823D1FA
# 56 "data/maps/UnionRoom/scripts.pory"
	lock
# 57 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 58 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_3
# 59 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 60 "data/maps/UnionRoom/scripts.pory"
	release
# 61 "data/maps/UnionRoom/scripts.pory"
	end
# 62 "data/maps/UnionRoom/scripts.pory"

# 63 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player4:: @ 823D204
# 64 "data/maps/UnionRoom/scripts.pory"
	lock
# 65 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 66 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_4
# 67 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 68 "data/maps/UnionRoom/scripts.pory"
	release
# 69 "data/maps/UnionRoom/scripts.pory"
	end
# 70 "data/maps/UnionRoom/scripts.pory"

# 71 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player5:: @ 823D20E
# 72 "data/maps/UnionRoom/scripts.pory"
	lock
# 73 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 74 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_5
# 75 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 76 "data/maps/UnionRoom/scripts.pory"
	release
# 77 "data/maps/UnionRoom/scripts.pory"
	end
# 78 "data/maps/UnionRoom/scripts.pory"

# 79 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player6:: @ 823D218
# 80 "data/maps/UnionRoom/scripts.pory"
	lock
# 81 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 82 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_6
# 83 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 84 "data/maps/UnionRoom/scripts.pory"
	release
# 85 "data/maps/UnionRoom/scripts.pory"
	end
# 86 "data/maps/UnionRoom/scripts.pory"

# 87 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player7:: @ 823D222
# 88 "data/maps/UnionRoom/scripts.pory"
	lock
# 89 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 90 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_7
# 91 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 92 "data/maps/UnionRoom/scripts.pory"
	release
# 93 "data/maps/UnionRoom/scripts.pory"
	end
# 94 "data/maps/UnionRoom/scripts.pory"

# 95 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Player8:: @ 823D22C
# 96 "data/maps/UnionRoom/scripts.pory"
	lock
# 97 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 98 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_PLAYER_8
# 99 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 100 "data/maps/UnionRoom/scripts.pory"
	release
# 101 "data/maps/UnionRoom/scripts.pory"
	end
# 102 "data/maps/UnionRoom/scripts.pory"

# 103 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Attendant:: @ 823D236
# 104 "data/maps/UnionRoom/scripts.pory"
	lock
# 105 "data/maps/UnionRoom/scripts.pory"
	faceplayer
# 106 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_ATTENDANT
# 107 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 108 "data/maps/UnionRoom/scripts.pory"
	release
# 109 "data/maps/UnionRoom/scripts.pory"
	end
# 110 "data/maps/UnionRoom/scripts.pory"

# 111 "data/maps/UnionRoom/scripts.pory"
UnionRoom_EventScript_Unused:: @ 823D240
# 112 "data/maps/UnionRoom/scripts.pory"
	lockall
# 113 "data/maps/UnionRoom/scripts.pory"
	setvar VAR_RESULT, UR_INTERACT_UNUSED
# 114 "data/maps/UnionRoom/scripts.pory"
	waitstate
# 115 "data/maps/UnionRoom/scripts.pory"
	releaseall
# 116 "data/maps/UnionRoom/scripts.pory"
	end
