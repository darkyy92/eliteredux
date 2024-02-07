# 1 "data/maps/Route109/scripts.pory"

# 2 "data/maps/Route109/scripts.pory"
@ NOTE: Route 109's sail to Dewford script references local IDs from Dewford's map. 
# 3 "data/maps/Route109/scripts.pory"
@  These are labeled in DewfordTown/scripts.inc
# 4 "data/maps/Route109/scripts.pory"

# 5 "data/maps/Route109/scripts.pory"
Route109_MapScripts::
# 6 "data/maps/Route109/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_OnTransition
# 7 "data/maps/Route109/scripts.pory"
	.byte 0
# 8 "data/maps/Route109/scripts.pory"

# 9 "data/maps/Route109/scripts.pory"
Route109_OnTransition:
# 10 "data/maps/Route109/scripts.pory"
	setflag FLAG_VISITED_SLATEPORT_CITY
# 11 "data/maps/Route109/scripts.pory"
	end
# 12 "data/maps/Route109/scripts.pory"

# 13 "data/maps/Route109/scripts.pory"
Route109_EventScript_StartDepartForDewford:: @ 81EE760
# 14 "data/maps/Route109/scripts.pory"
	call EventScript_BackupMrBrineyLocation
# 15 "data/maps/Route109/scripts.pory"
	setobjectpriority LOCALID_BRINEY_R109, MAP_ROUTE109, 0
# 16 "data/maps/Route109/scripts.pory"
	setobjectpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE109, 0
# 17 "data/maps/Route109/scripts.pory"
	applymovement LOCALID_BRINEY_R109, Route109_Movement_BrineyEnterBoat
# 18 "data/maps/Route109/scripts.pory"
	waitmovement 0
# 19 "data/maps/Route109/scripts.pory"
	removeobject LOCALID_BRINEY_R109
# 20 "data/maps/Route109/scripts.pory"
	switch VAR_FACING
# 21 "data/maps/Route109/scripts.pory"
	case DIR_SOUTH, Route109_EventScript_EnterBoatSouth
# 22 "data/maps/Route109/scripts.pory"
	case DIR_WEST, Route109_EventScript_EnterBoatWest
# 23 "data/maps/Route109/scripts.pory"
	case DIR_EAST, Route109_EventScript_EnterBoatEast
# 24 "data/maps/Route109/scripts.pory"
	end
# 25 "data/maps/Route109/scripts.pory"

# 26 "data/maps/Route109/scripts.pory"
Route109_EventScript_EnterBoatSouth:: @ 81EE7A5
# 27 "data/maps/Route109/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route109_Movement_PlayerEnterBoatSouth
# 28 "data/maps/Route109/scripts.pory"
	waitmovement 0
# 29 "data/maps/Route109/scripts.pory"
	goto Route109_EventScript_DoSailToDewford
# 30 "data/maps/Route109/scripts.pory"
	end
# 31 "data/maps/Route109/scripts.pory"

# 32 "data/maps/Route109/scripts.pory"
Route109_EventScript_EnterBoatEast:: @ 81EE7B5
# 33 "data/maps/Route109/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route109_Movement_PlayerEnterBoatEast
# 34 "data/maps/Route109/scripts.pory"
	waitmovement 0
# 35 "data/maps/Route109/scripts.pory"
	goto Route109_EventScript_DoSailToDewford
# 36 "data/maps/Route109/scripts.pory"
	end
# 37 "data/maps/Route109/scripts.pory"

# 38 "data/maps/Route109/scripts.pory"
Route109_EventScript_EnterBoatWest:: @ 81EE7C5
# 39 "data/maps/Route109/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route109_Movement_PlayerEnterBoatWest
# 40 "data/maps/Route109/scripts.pory"
	waitmovement 0
# 41 "data/maps/Route109/scripts.pory"
	goto Route109_EventScript_DoSailToDewford
# 42 "data/maps/Route109/scripts.pory"
	end
# 43 "data/maps/Route109/scripts.pory"

# 44 "data/maps/Route109/scripts.pory"
Route109_EventScript_DoSailToDewford:: @ 81EE7D5
# 45 "data/maps/Route109/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE109
# 46 "data/maps/Route109/scripts.pory"
	call Common_EventScript_PlayBrineysBoatMusic
# 47 "data/maps/Route109/scripts.pory"
	applymovement LOCALID_BOAT_R109, Route109_Movement_SailToDewford
# 48 "data/maps/Route109/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route109_Movement_SailToDewford
# 49 "data/maps/Route109/scripts.pory"
	waitmovement 0
# 50 "data/maps/Route109/scripts.pory"
	delay 50
# 51 "data/maps/Route109/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 52 "data/maps/Route109/scripts.pory"
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
# 53 "data/maps/Route109/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route109_Movement_PlayerExitBoat
# 54 "data/maps/Route109/scripts.pory"
	waitmovement 0
# 55 "data/maps/Route109/scripts.pory"
	addobject LOCALID_BOAT_DEWFORD
# 56 "data/maps/Route109/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
# 57 "data/maps/Route109/scripts.pory"
	setobjectxyperm LOCALID_BRINEY_DEWFORD, 12, 8
# 58 "data/maps/Route109/scripts.pory"
	addobject LOCALID_BRINEY_DEWFORD
# 59 "data/maps/Route109/scripts.pory"
	setobjectpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
# 60 "data/maps/Route109/scripts.pory"
	applymovement LOCALID_BRINEY_DEWFORD, Route109_Movement_BrineyExitBoat
# 61 "data/maps/Route109/scripts.pory"
	waitmovement 0
# 62 "data/maps/Route109/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
# 63 "data/maps/Route109/scripts.pory"
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
# 64 "data/maps/Route109/scripts.pory"
	hideobjectat LOCALID_BOAT_R109, MAP_ROUTE109
# 65 "data/maps/Route109/scripts.pory"
	msgbox DewfordTown_Text_BrineyLandedInDewford, MSGBOX_DEFAULT
# 66 "data/maps/Route109/scripts.pory"
	closemessage
# 67 "data/maps/Route109/scripts.pory"
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
# 68 "data/maps/Route109/scripts.pory"
	resetobjectpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE109
# 69 "data/maps/Route109/scripts.pory"
	resetobjectpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN
# 70 "data/maps/Route109/scripts.pory"
	copyobjectxytoperm LOCALID_BRINEY_DEWFORD
# 71 "data/maps/Route109/scripts.pory"
	release
# 72 "data/maps/Route109/scripts.pory"
	end
# 73 "data/maps/Route109/scripts.pory"

# 74 "data/maps/Route109/scripts.pory"
Route109_Movement_SailToDewford: @ 81EE84F
# 75 "data/maps/Route109/scripts.pory"
	walk_in_place_fastest_down
# 76 "data/maps/Route109/scripts.pory"
	walk_down
# 77 "data/maps/Route109/scripts.pory"
	walk_down
# 78 "data/maps/Route109/scripts.pory"
	walk_fast_down
# 79 "data/maps/Route109/scripts.pory"
	walk_fast_down
# 80 "data/maps/Route109/scripts.pory"
	walk_fastest_down
# 81 "data/maps/Route109/scripts.pory"
	walk_fastest_down
# 82 "data/maps/Route109/scripts.pory"
	walk_fastest_down
# 83 "data/maps/Route109/scripts.pory"
	walk_fastest_down
# 84 "data/maps/Route109/scripts.pory"
	walk_fastest_down
# 85 "data/maps/Route109/scripts.pory"
	walk_fastest_down
# 86 "data/maps/Route109/scripts.pory"
	walk_fastest_down
# 87 "data/maps/Route109/scripts.pory"
	walk_fastest_down
# 88 "data/maps/Route109/scripts.pory"
	walk_fastest_down
# 89 "data/maps/Route109/scripts.pory"
	walk_fastest_down
# 90 "data/maps/Route109/scripts.pory"
	walk_fastest_down
# 91 "data/maps/Route109/scripts.pory"
	walk_fastest_down
# 92 "data/maps/Route109/scripts.pory"
	walk_fastest_down
# 93 "data/maps/Route109/scripts.pory"
	walk_fastest_down
# 94 "data/maps/Route109/scripts.pory"
	walk_fastest_down
# 95 "data/maps/Route109/scripts.pory"
	walk_fastest_down
# 96 "data/maps/Route109/scripts.pory"
	walk_fast_down
# 97 "data/maps/Route109/scripts.pory"
	walk_fast_down
# 98 "data/maps/Route109/scripts.pory"
	walk_fast_left
# 99 "data/maps/Route109/scripts.pory"
	walk_fast_left
# 100 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 101 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 102 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 103 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 104 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 105 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 106 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 107 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 108 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 109 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 110 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 111 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 112 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 113 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 114 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 115 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 116 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 117 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 118 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 119 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 120 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 121 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 122 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 123 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 124 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 125 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 126 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 127 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 128 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 129 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 130 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 131 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 132 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 133 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 134 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 135 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 136 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 137 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 138 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 139 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 140 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 141 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 142 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 143 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 144 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 145 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 146 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 147 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 148 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 149 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 150 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 151 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 152 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 153 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 154 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 155 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 156 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 157 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 158 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 159 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 160 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 161 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 162 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 163 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 164 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 165 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 166 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 167 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 168 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 169 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 170 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 171 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 172 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 173 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 174 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 175 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 176 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 177 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 178 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 179 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 180 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 181 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 182 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 183 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 184 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 185 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 186 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 187 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 188 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 189 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 190 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 191 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 192 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 193 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 194 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 195 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 196 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 197 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 198 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 199 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 200 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 201 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 202 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 203 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 204 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 205 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 206 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 207 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 208 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 209 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 210 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 211 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 212 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 213 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 214 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 215 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 216 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 217 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 218 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 219 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 220 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 221 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 222 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 223 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 224 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 225 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 226 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 227 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 228 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 229 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 230 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 231 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 232 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 233 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 234 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 235 "data/maps/Route109/scripts.pory"
	walk_fastest_left
# 236 "data/maps/Route109/scripts.pory"
	walk_fast_left
# 237 "data/maps/Route109/scripts.pory"
	walk_fast_left
# 238 "data/maps/Route109/scripts.pory"
	walk_fast_left
# 239 "data/maps/Route109/scripts.pory"
	walk_fast_left
# 240 "data/maps/Route109/scripts.pory"
	walk_fast_left
# 241 "data/maps/Route109/scripts.pory"
	walk_fast_left
# 242 "data/maps/Route109/scripts.pory"
	walk_fast_left
# 243 "data/maps/Route109/scripts.pory"
	walk_fast_left
# 244 "data/maps/Route109/scripts.pory"
	walk_fast_left
# 245 "data/maps/Route109/scripts.pory"
	walk_left
# 246 "data/maps/Route109/scripts.pory"
	walk_left
# 247 "data/maps/Route109/scripts.pory"
	walk_in_place_fastest_down
# 248 "data/maps/Route109/scripts.pory"
	step_end
# 249 "data/maps/Route109/scripts.pory"

# 250 "data/maps/Route109/scripts.pory"
Route109_Movement_PlayerEnterBoatSouth: @ 81EE8FD
# 251 "data/maps/Route109/scripts.pory"
	walk_down
# 252 "data/maps/Route109/scripts.pory"
	walk_down
# 253 "data/maps/Route109/scripts.pory"
	step_end
# 254 "data/maps/Route109/scripts.pory"

# 255 "data/maps/Route109/scripts.pory"
Route109_Movement_PlayerExitBoat: @ 81EE900
# 256 "data/maps/Route109/scripts.pory"
	walk_down
# 257 "data/maps/Route109/scripts.pory"
	walk_down
# 258 "data/maps/Route109/scripts.pory"
	walk_left
# 259 "data/maps/Route109/scripts.pory"
	walk_in_place_fastest_right
# 260 "data/maps/Route109/scripts.pory"
	step_end
# 261 "data/maps/Route109/scripts.pory"

# 262 "data/maps/Route109/scripts.pory"
Route109_Movement_PlayerEnterBoatEast: @ 81EE905
# 263 "data/maps/Route109/scripts.pory"
	walk_right
# 264 "data/maps/Route109/scripts.pory"
	walk_down
# 265 "data/maps/Route109/scripts.pory"
	step_end
# 266 "data/maps/Route109/scripts.pory"

# 267 "data/maps/Route109/scripts.pory"
Route109_Movement_PlayerEnterBoatWest: @ 81EE908
# 268 "data/maps/Route109/scripts.pory"
	walk_left
# 269 "data/maps/Route109/scripts.pory"
	walk_down
# 270 "data/maps/Route109/scripts.pory"
	step_end
# 271 "data/maps/Route109/scripts.pory"

# 272 "data/maps/Route109/scripts.pory"
Route109_Movement_BrineyEnterBoat: @ 81EE90B
# 273 "data/maps/Route109/scripts.pory"
	walk_down
# 274 "data/maps/Route109/scripts.pory"
	step_end
# 275 "data/maps/Route109/scripts.pory"

# 276 "data/maps/Route109/scripts.pory"
Route109_Movement_BrineyExitBoat: @ 81EE90D
# 277 "data/maps/Route109/scripts.pory"
	walk_down
# 278 "data/maps/Route109/scripts.pory"
	walk_in_place_fastest_left
# 279 "data/maps/Route109/scripts.pory"
	step_end
# 280 "data/maps/Route109/scripts.pory"

# 281 "data/maps/Route109/scripts.pory"
Route109_EventScript_MrBriney:: @ 81EE910
# 282 "data/maps/Route109/scripts.pory"
	lock
# 283 "data/maps/Route109/scripts.pory"
	faceplayer
# 284 "data/maps/Route109/scripts.pory"
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route109_EventScript_HaveNotDeliveredDevonGood
# 285 "data/maps/Route109/scripts.pory"
	goto Route109_EventScript_DeliveredDevonGoods
# 286 "data/maps/Route109/scripts.pory"
	end
# 287 "data/maps/Route109/scripts.pory"

# 288 "data/maps/Route109/scripts.pory"
Route109_EventScript_HaveNotDeliveredDevonGood:: @ 81EE921
# 289 "data/maps/Route109/scripts.pory"
	message Route109_Text_BrineySailToDewfordQuestion
# 290 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_BrineySailToDewfordQuestion, MSGBOX_YESNO
# 291 "data/maps/Route109/scripts.pory"
	compare VAR_RESULT, NO
# 292 "data/maps/Route109/scripts.pory"
	goto_if_eq Route109_EventScript_StayHere
# 293 "data/maps/Route109/scripts.pory"
	goto Route109_EventScript_SailToDewford
# 294 "data/maps/Route109/scripts.pory"
	end
# 295 "data/maps/Route109/scripts.pory"

# 296 "data/maps/Route109/scripts.pory"
Route109_EventScript_DeliveredDevonGoods:: @ 81EE93F
# 297 "data/maps/Route109/scripts.pory"
	message Route109_Text_BrineyWhereAreWeBound
# 298 "data/maps/Route109/scripts.pory"
	waitmessage
# 299 "data/maps/Route109/scripts.pory"
	multichoicedefault 21, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
# 300 "data/maps/Route109/scripts.pory"
	switch VAR_RESULT
# 301 "data/maps/Route109/scripts.pory"
	case 0, Route109_EventScript_SailToDewford
# 302 "data/maps/Route109/scripts.pory"
	case 1, Route109_EventScript_ChoseNotToSail
# 303 "data/maps/Route109/scripts.pory"
	case MULTI_B_PRESSED, Route109_EventScript_ChoseNotToSail
# 304 "data/maps/Route109/scripts.pory"
	end
# 305 "data/maps/Route109/scripts.pory"

# 306 "data/maps/Route109/scripts.pory"
Route109_EventScript_SailToDewford:: @ 81EE972
# 307 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_BrineyDewfordItIs, MSGBOX_DEFAULT
# 308 "data/maps/Route109/scripts.pory"
	closemessage
# 309 "data/maps/Route109/scripts.pory"
	goto Route109_EventScript_StartDepartForDewford
# 310 "data/maps/Route109/scripts.pory"
	end
# 311 "data/maps/Route109/scripts.pory"

# 312 "data/maps/Route109/scripts.pory"
Route109_EventScript_StayHere:: @ 81EE981
# 313 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_BrineyDeliverDevonGoods, MSGBOX_DEFAULT
# 314 "data/maps/Route109/scripts.pory"
	release
# 315 "data/maps/Route109/scripts.pory"
	end
# 316 "data/maps/Route109/scripts.pory"

# 317 "data/maps/Route109/scripts.pory"
Route109_EventScript_ChoseNotToSail:: @ 81EE98B
# 318 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_BrineyTellMeWhenYouNeedToSail, MSGBOX_DEFAULT
# 319 "data/maps/Route109/scripts.pory"
	release
# 320 "data/maps/Route109/scripts.pory"
	end
# 321 "data/maps/Route109/scripts.pory"

# 322 "data/maps/Route109/scripts.pory"
Route109_EventScript_SeashoreHouseGirl:: @ 81EE995
# 323 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_ChillAtMyPapasSpot, MSGBOX_NPC
# 324 "data/maps/Route109/scripts.pory"
	end
# 325 "data/maps/Route109/scripts.pory"

# 326 "data/maps/Route109/scripts.pory"
Route109_EventScript_SandCastleBoy:: @ 81EE99E
# 327 "data/maps/Route109/scripts.pory"
	lock
# 328 "data/maps/Route109/scripts.pory"
	faceplayer
# 329 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_SandCastleTakingLongTime, MSGBOX_DEFAULT
# 330 "data/maps/Route109/scripts.pory"
	closemessage
# 331 "data/maps/Route109/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 332 "data/maps/Route109/scripts.pory"
	waitmovement 0
# 333 "data/maps/Route109/scripts.pory"
	release
# 334 "data/maps/Route109/scripts.pory"
	end
# 335 "data/maps/Route109/scripts.pory"

# 336 "data/maps/Route109/scripts.pory"
Route109_EventScript_SoftSandGirl:: @ 81EE9B5
# 337 "data/maps/Route109/scripts.pory"
	lock
# 338 "data/maps/Route109/scripts.pory"
	faceplayer
# 339 "data/maps/Route109/scripts.pory"
	special GetPlayerBigGuyGirlString
# 340 "data/maps/Route109/scripts.pory"
	goto_if_set FLAG_RECEIVED_SOFT_SAND, Route109_EventScript_AlreadyReceivedSoftSand
# 341 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_YouCanHaveThis, MSGBOX_DEFAULT
# 342 "data/maps/Route109/scripts.pory"
	giveitem ITEM_SOFT_SAND
# 343 "data/maps/Route109/scripts.pory"
	compare VAR_RESULT, 0
# 344 "data/maps/Route109/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 345 "data/maps/Route109/scripts.pory"
	closemessage
# 346 "data/maps/Route109/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 347 "data/maps/Route109/scripts.pory"
	waitmovement 0
# 348 "data/maps/Route109/scripts.pory"
	setflag FLAG_RECEIVED_SOFT_SAND
# 349 "data/maps/Route109/scripts.pory"
	release
# 350 "data/maps/Route109/scripts.pory"
	end
# 351 "data/maps/Route109/scripts.pory"

# 352 "data/maps/Route109/scripts.pory"
Route109_EventScript_AlreadyReceivedSoftSand:: @ 81EE9F2
# 353 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_WereGoingToMakeBigCastle, MSGBOX_DEFAULT
# 354 "data/maps/Route109/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 355 "data/maps/Route109/scripts.pory"
	waitmovement 0
# 356 "data/maps/Route109/scripts.pory"
	release
# 357 "data/maps/Route109/scripts.pory"
	end
# 358 "data/maps/Route109/scripts.pory"

# 359 "data/maps/Route109/scripts.pory"
Route109_EventScript_Woman:: @ 81EEA06
# 360 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_LittleKidsDartAround, MSGBOX_NPC
# 361 "data/maps/Route109/scripts.pory"
	end
# 362 "data/maps/Route109/scripts.pory"

# 363 "data/maps/Route109/scripts.pory"
Route109_EventScript_OldMan:: @ 81EEA0F
# 364 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_ZigzagoonPicksUpLitter, MSGBOX_NPC
# 365 "data/maps/Route109/scripts.pory"
	end
# 366 "data/maps/Route109/scripts.pory"

# 367 "data/maps/Route109/scripts.pory"
Route109_EventScript_Zigzagoon:: @ 81EEA18
# 368 "data/maps/Route109/scripts.pory"
	lock
# 369 "data/maps/Route109/scripts.pory"
	faceplayer
# 370 "data/maps/Route109/scripts.pory"
	waitse
# 371 "data/maps/Route109/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, 0
# 372 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_ZigzagoonCry, MSGBOX_DEFAULT
# 373 "data/maps/Route109/scripts.pory"
	waitmoncry
# 374 "data/maps/Route109/scripts.pory"
	release
# 375 "data/maps/Route109/scripts.pory"
	end
# 376 "data/maps/Route109/scripts.pory"

# 377 "data/maps/Route109/scripts.pory"
Route_109_EventScript_SandMound::
# 378 "data/maps/Route109/scripts.pory"
	lockall
# 379 "data/maps/Route109/scripts.pory"
	faceplayer
# 380 "data/maps/Route109/scripts.pory"
	special RockSmashWildEncounter
# 381 "data/maps/Route109/scripts.pory"
	delay 0x60
# 382 "data/maps/Route109/scripts.pory"
	removeobject 25
# 383 "data/maps/Route109/scripts.pory"
	releaseall
# 384 "data/maps/Route109/scripts.pory"
	end
# 385 "data/maps/Route109/scripts.pory"

# 386 "data/maps/Route109/scripts.pory"
Route_109_EventScript_SandMound1::
# 387 "data/maps/Route109/scripts.pory"
	lockall
# 388 "data/maps/Route109/scripts.pory"
	faceplayer
# 389 "data/maps/Route109/scripts.pory"
	special RockSmashWildEncounter
# 390 "data/maps/Route109/scripts.pory"
	delay 0x60
# 391 "data/maps/Route109/scripts.pory"
	removeobject 26
# 392 "data/maps/Route109/scripts.pory"
	releaseall
# 393 "data/maps/Route109/scripts.pory"
	end
# 394 "data/maps/Route109/scripts.pory"

# 395 "data/maps/Route109/scripts.pory"
Route_109_EventScript_SandMound2::
# 396 "data/maps/Route109/scripts.pory"
	lockall
# 397 "data/maps/Route109/scripts.pory"
	faceplayer
# 398 "data/maps/Route109/scripts.pory"
	special RockSmashWildEncounter
# 399 "data/maps/Route109/scripts.pory"
	delay 0x60
# 400 "data/maps/Route109/scripts.pory"
	removeobject 27
# 401 "data/maps/Route109/scripts.pory"
	releaseall
# 402 "data/maps/Route109/scripts.pory"
	end
# 403 "data/maps/Route109/scripts.pory"

# 404 "data/maps/Route109/scripts.pory"
Route109_EventScript_SeashoreHouseSign:: @ 81EEA2B
# 405 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_SeashoreHouseSign, MSGBOX_SIGN
# 406 "data/maps/Route109/scripts.pory"
	end
# 407 "data/maps/Route109/scripts.pory"

# 408 "data/maps/Route109/scripts.pory"
Route109_EventScript_TrainerTipsSign:: @ 81EEA34
# 409 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_TrainerTipsSign, MSGBOX_SIGN
# 410 "data/maps/Route109/scripts.pory"
	end
# 411 "data/maps/Route109/scripts.pory"

# 412 "data/maps/Route109/scripts.pory"
Route109_EventScript_David:: @ 81EEA3D
# 413 "data/maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_DAVID, Route109_Text_DavidIntro, Route109_Text_DavidDefeated
# 414 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_DavidPostBattle, MSGBOX_AUTOCLOSE
# 415 "data/maps/Route109/scripts.pory"
	end
# 416 "data/maps/Route109/scripts.pory"

# 417 "data/maps/Route109/scripts.pory"
Route109_EventScript_Alice:: @ 81EEA54
# 418 "data/maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_ALICE, Route109_Text_AliceIntro, Route109_Text_AliceDefeated
# 419 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_AlicePostBattle, MSGBOX_AUTOCLOSE
# 420 "data/maps/Route109/scripts.pory"
	end
# 421 "data/maps/Route109/scripts.pory"

# 422 "data/maps/Route109/scripts.pory"
Route109_EventScript_Huey:: @ 81EEA6B
# 423 "data/maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_HUEY, Route109_Text_HueyIntro, Route109_Text_HueyDefeated
# 424 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_HueyPostBattle, MSGBOX_AUTOCLOSE
# 425 "data/maps/Route109/scripts.pory"
	end
# 426 "data/maps/Route109/scripts.pory"

# 427 "data/maps/Route109/scripts.pory"
Route109_EventScript_Edmond:: @ 81EEA82
# 428 "data/maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_EDMOND, Route109_Text_EdmondIntro, Route109_Text_EdmondDefeated
# 429 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_EdmondPostBattle, MSGBOX_AUTOCLOSE
# 430 "data/maps/Route109/scripts.pory"
	end
# 431 "data/maps/Route109/scripts.pory"

# 432 "data/maps/Route109/scripts.pory"
Route109_EventScript_Ricky:: @ 81EEA99
# 433 "data/maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_RICKY_1, Route109_Text_RickyIntro, Route109_Text_RickyDefeated, Route109_EventScript_RickyRegisterMatchCallAfterBattle
# 434 "data/maps/Route109/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 435 "data/maps/Route109/scripts.pory"
	compare VAR_RESULT, TRUE
# 436 "data/maps/Route109/scripts.pory"
	goto_if_eq Route109_EventScript_RickyRematch
# 437 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_RickyPostBattle, MSGBOX_DEFAULT
# 438 "data/maps/Route109/scripts.pory"
	release
# 439 "data/maps/Route109/scripts.pory"
	end
# 440 "data/maps/Route109/scripts.pory"

# 441 "data/maps/Route109/scripts.pory"
Route109_EventScript_RickyRegisterMatchCallAfterBattle:: @ 81EEAC5
# 442 "data/maps/Route109/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 443 "data/maps/Route109/scripts.pory"
	waitmovement 0
# 444 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_RickyRegister, MSGBOX_DEFAULT
# 445 "data/maps/Route109/scripts.pory"
	register_matchcall TRAINER_RICKY_1
# 446 "data/maps/Route109/scripts.pory"
	release
# 447 "data/maps/Route109/scripts.pory"
	end
# 448 "data/maps/Route109/scripts.pory"

# 449 "data/maps/Route109/scripts.pory"
Route109_EventScript_RickyRematch:: @ 81EEAE4
# 450 "data/maps/Route109/scripts.pory"
	trainerbattle_rematch TRAINER_RICKY_1, Route109_Text_RickyRematchIntro, Route109_Text_RickyRematchDefeated
# 451 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_RickyRematchPostBattle, MSGBOX_AUTOCLOSE
# 452 "data/maps/Route109/scripts.pory"
	end
# 453 "data/maps/Route109/scripts.pory"

# 454 "data/maps/Route109/scripts.pory"
Route109_EventScript_Lola:: @ 81EEAFB
# 455 "data/maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_LOLA_1, Route109_Text_LolaIntro, Route109_Text_LolaDefeated, Route109_EventScript_LolaRegisterMatchCallAfterBattle
# 456 "data/maps/Route109/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 457 "data/maps/Route109/scripts.pory"
	compare VAR_RESULT, TRUE
# 458 "data/maps/Route109/scripts.pory"
	goto_if_eq Route109_EventScript_LolaRematch
# 459 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_LolaPostBattle, MSGBOX_DEFAULT
# 460 "data/maps/Route109/scripts.pory"
	release
# 461 "data/maps/Route109/scripts.pory"
	end
# 462 "data/maps/Route109/scripts.pory"

# 463 "data/maps/Route109/scripts.pory"
Route109_EventScript_LolaRegisterMatchCallAfterBattle:: @ 81EEB27
# 464 "data/maps/Route109/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 465 "data/maps/Route109/scripts.pory"
	waitmovement 0
# 466 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_LolaRegister, MSGBOX_DEFAULT
# 467 "data/maps/Route109/scripts.pory"
	register_matchcall TRAINER_LOLA_1
# 468 "data/maps/Route109/scripts.pory"
	release
# 469 "data/maps/Route109/scripts.pory"
	end
# 470 "data/maps/Route109/scripts.pory"

# 471 "data/maps/Route109/scripts.pory"
Route109_EventScript_LolaRematch:: @ 81EEB46
# 472 "data/maps/Route109/scripts.pory"
	trainerbattle_rematch TRAINER_LOLA_1, Route109_Text_LolaRematchIntro, Route109_Text_LolaRematchDefeated
# 473 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_LolaRematchPostBattle, MSGBOX_AUTOCLOSE
# 474 "data/maps/Route109/scripts.pory"
	end
# 475 "data/maps/Route109/scripts.pory"

# 476 "data/maps/Route109/scripts.pory"
Route109_EventScript_Austina:: @ 81EEB5D
# 477 "data/maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_AUSTINA, Route109_Text_AustinaIntro, Route109_Text_AustinaDefeated
# 478 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_AustinaPostBattle, MSGBOX_AUTOCLOSE
# 479 "data/maps/Route109/scripts.pory"
	end
# 480 "data/maps/Route109/scripts.pory"

# 481 "data/maps/Route109/scripts.pory"
Route109_EventScript_Gwen:: @ 81EEB74
# 482 "data/maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_GWEN, Route109_Text_GwenIntro, Route109_Text_GwenDefeated
# 483 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_GwenPostBattle, MSGBOX_AUTOCLOSE
# 484 "data/maps/Route109/scripts.pory"
	end
# 485 "data/maps/Route109/scripts.pory"

# 486 "data/maps/Route109/scripts.pory"
Route109_EventScript_Carter:: @ 81EEB8B
# 487 "data/maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_CARTER, Route109_Text_CarterIntro, Route109_Text_CarterDefeated
# 488 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_CarterPostBattle, MSGBOX_AUTOCLOSE
# 489 "data/maps/Route109/scripts.pory"
	end
# 490 "data/maps/Route109/scripts.pory"

# 491 "data/maps/Route109/scripts.pory"
Route109_EventScript_Paul:: @ 81EEBA2
# 492 "data/maps/Route109/scripts.pory"
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route109_Text_PaulIntro, Route109_Text_PaulDefeated, Route109_Text_PaulNotEnoughPokemon
# 493 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_PaulPostBattle, MSGBOX_AUTOCLOSE
# 494 "data/maps/Route109/scripts.pory"
	end
# 495 "data/maps/Route109/scripts.pory"

# 496 "data/maps/Route109/scripts.pory"
Route109_EventScript_Mel:: @ 81EEBBD
# 497 "data/maps/Route109/scripts.pory"
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route109_Text_MelIntro, Route109_Text_MelDefeated, Route109_Text_MelNotEnoughPokemon
# 498 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_MelPostBattle, MSGBOX_AUTOCLOSE
# 499 "data/maps/Route109/scripts.pory"
	end
# 500 "data/maps/Route109/scripts.pory"

# 501 "data/maps/Route109/scripts.pory"
Route109_EventScript_Chandler:: @ 81EEBD8
# 502 "data/maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_CHANDLER, Route109_Text_ChandlerIntro, Route109_Text_ChandlerDefeated
# 503 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_ChandlerPostBattle, MSGBOX_AUTOCLOSE
# 504 "data/maps/Route109/scripts.pory"
	end
# 505 "data/maps/Route109/scripts.pory"

# 506 "data/maps/Route109/scripts.pory"
Route109_EventScript_Hailey:: @ 81EEBEF
# 507 "data/maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_HAILEY, Route109_Text_HaileyIntro, Route109_Text_HaileyDefeated
# 508 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_HaileyPostBattle, MSGBOX_AUTOCLOSE
# 509 "data/maps/Route109/scripts.pory"
	end
# 510 "data/maps/Route109/scripts.pory"

# 511 "data/maps/Route109/scripts.pory"
Route109_EventScript_Elijah:: @ 81EEC06
# 512 "data/maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_ELIJAH, Route109_Text_ElijahIntro, Route109_Text_ElijahDefeated
# 513 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_ElijahPostBattle, MSGBOX_AUTOCLOSE
# 514 "data/maps/Route109/scripts.pory"
	end
# 515 "data/maps/Route109/scripts.pory"

# 516 "data/maps/Route109/scripts.pory"
DewfordTown_Text_BrineyLandedInSlateportDeliverGoods: @ 81EEC1D
# 517 "data/maps/Route109/scripts.pory"
	.string "Mr. Briney: Ahoy!\n"
# 518 "data/maps/Route109/scripts.pory"
	.string "We've made land in Slateport!\p"
# 519 "data/maps/Route109/scripts.pory"
	.string "I suppose you're going to visit Capt.\n"
# 520 "data/maps/Route109/scripts.pory"
	.string "Stern and deliver the Devon Parts?$"
# 521 "data/maps/Route109/scripts.pory"

# 522 "data/maps/Route109/scripts.pory"
Route109_Text_BrineySailToDewfordQuestion: @ 81EEC96
# 523 "data/maps/Route109/scripts.pory"
	.string "Mr. Briney: I thought you're supposed\n"
# 524 "data/maps/Route109/scripts.pory"
	.string "to deliver the Devon Parts.\p"
# 525 "data/maps/Route109/scripts.pory"
	.string "Would you like to sail back to\n"
# 526 "data/maps/Route109/scripts.pory"
	.string "Dewford, then?$"
# 527 "data/maps/Route109/scripts.pory"

# 528 "data/maps/Route109/scripts.pory"
Route109_Text_BrineyDewfordItIs: @ 81EED06
# 529 "data/maps/Route109/scripts.pory"
	.string "Mr. Briney: Dewford it is, then!\p"
# 530 "data/maps/Route109/scripts.pory"
	.string "Anchors aweigh!\n"
# 531 "data/maps/Route109/scripts.pory"
	.string "Peeko, we're setting sail, my darling!$"
# 532 "data/maps/Route109/scripts.pory"

# 533 "data/maps/Route109/scripts.pory"
Route109_Text_BrineyDeliverDevonGoods: @ 81EED5E
# 534 "data/maps/Route109/scripts.pory"
	.string "Mr. Briney: Then you go on and deliver\n"
# 535 "data/maps/Route109/scripts.pory"
	.string "the Devon Parts. I'll be waiting.$"
# 536 "data/maps/Route109/scripts.pory"

# 537 "data/maps/Route109/scripts.pory"
DewfordTown_Text_BrineyLandedInSlateport: @ 81EEDA7
# 538 "data/maps/Route109/scripts.pory"
	.string "Mr. Briney: Ahoy! We've made land in\n"
# 539 "data/maps/Route109/scripts.pory"
	.string "Slateport!\p"
# 540 "data/maps/Route109/scripts.pory"
	.string "You just go on and tell me whenever\n"
# 541 "data/maps/Route109/scripts.pory"
	.string "you want to set sail again!$"
# 542 "data/maps/Route109/scripts.pory"

# 543 "data/maps/Route109/scripts.pory"
Route109_Text_BrineyWhereAreWeBound: @ 81EEE17
# 544 "data/maps/Route109/scripts.pory"
	.string "Mr. Briney: Ahoy!\n"
# 545 "data/maps/Route109/scripts.pory"
	.string "For you, I'll go out to sea anytime!\p"
# 546 "data/maps/Route109/scripts.pory"
	.string "Now, my friend, where are we bound?$"
# 547 "data/maps/Route109/scripts.pory"

# 548 "data/maps/Route109/scripts.pory"
Route109_Text_BrineyTellMeWhenYouNeedToSail: @ 81EEE72
# 549 "data/maps/Route109/scripts.pory"
	.string "Mr. Briney: You just tell me whenever\n"
# 550 "data/maps/Route109/scripts.pory"
	.string "you need to set sail again!$"
# 551 "data/maps/Route109/scripts.pory"

# 552 "data/maps/Route109/scripts.pory"
Route109_Text_ChillAtMyPapasSpot: @ 81EEEB4
# 553 "data/maps/Route109/scripts.pory"
	.string "Yo, Trainers!\n"
# 554 "data/maps/Route109/scripts.pory"
	.string "Whether you're hot to trot,\l"
# 555 "data/maps/Route109/scripts.pory"
	.string "or cool cat not,\l"
# 556 "data/maps/Route109/scripts.pory"
	.string "chill at my papa's spot!$"
# 557 "data/maps/Route109/scripts.pory"

# 558 "data/maps/Route109/scripts.pory"
Route109_Text_LittleKidsDartAround: @ 81EEF08
# 559 "data/maps/Route109/scripts.pory"
	.string "Little kids can dart around so quickly…\p"
# 560 "data/maps/Route109/scripts.pory"
	.string "You don't dare take your eyes off them\n"
# 561 "data/maps/Route109/scripts.pory"
	.string "for an instant. It's very taxing.\p"
# 562 "data/maps/Route109/scripts.pory"
	.string "Mine are with my Pokémon, so they\n"
# 563 "data/maps/Route109/scripts.pory"
	.string "should be okay, but…$"
# 564 "data/maps/Route109/scripts.pory"

# 565 "data/maps/Route109/scripts.pory"
Route109_Text_SandCastleTakingLongTime: @ 81EEFB0
# 566 "data/maps/Route109/scripts.pory"
	.string "Our sand castle's taking a long time\n"
# 567 "data/maps/Route109/scripts.pory"
	.string "to make.$"
# 568 "data/maps/Route109/scripts.pory"

# 569 "data/maps/Route109/scripts.pory"
Route109_Text_YouCanHaveThis: @ 81EEFDE
# 570 "data/maps/Route109/scripts.pory"
	.string "You can have this!$"
# 571 "data/maps/Route109/scripts.pory"

# 572 "data/maps/Route109/scripts.pory"
Route109_Text_WereGoingToMakeBigCastle: @ 81EEFF1
# 573 "data/maps/Route109/scripts.pory"
	.string "We're going to get all the sand from\n"
# 574 "data/maps/Route109/scripts.pory"
	.string "the beach and make a big castle!\p"
# 575 "data/maps/Route109/scripts.pory"
	.string "And then we're going to be a king and\n"
# 576 "data/maps/Route109/scripts.pory"
	.string "queen.\p"
# 577 "data/maps/Route109/scripts.pory"
	.string "We'll let you be a servant.$"
# 578 "data/maps/Route109/scripts.pory"

# 579 "data/maps/Route109/scripts.pory"
Route109_Text_ZigzagoonPicksUpLitter: @ 81EF080
# 580 "data/maps/Route109/scripts.pory"
	.string "The water around these parts is clean.\p"
# 581 "data/maps/Route109/scripts.pory"
	.string "But, I get my Zigzagoon to pick up\n"
# 582 "data/maps/Route109/scripts.pory"
	.string "litter from the shoreline at times.\p"
# 583 "data/maps/Route109/scripts.pory"
	.string "Dirty water becomes rain and joins our\n"
# 584 "data/maps/Route109/scripts.pory"
	.string "rivers, which we drink from…\p"
# 585 "data/maps/Route109/scripts.pory"
	.string "If we pollute the sea, it all comes\n"
# 586 "data/maps/Route109/scripts.pory"
	.string "back to haunt us eventually.$"
# 587 "data/maps/Route109/scripts.pory"

# 588 "data/maps/Route109/scripts.pory"
Route109_Text_ZigzagoonCry: @ 81EF173
# 589 "data/maps/Route109/scripts.pory"
	.string "Zigzagoon: Guguu?$"
# 590 "data/maps/Route109/scripts.pory"

# 591 "data/maps/Route109/scripts.pory"
Route109_Text_SeashoreHouseSign: @ 81EF185
# 592 "data/maps/Route109/scripts.pory"
	.string "Seashore House\p"
# 593 "data/maps/Route109/scripts.pory"
	.string "“May hot battles rage on hot sands!\n"
# 594 "data/maps/Route109/scripts.pory"
	.string "The place for hot Trainers!”$"
# 595 "data/maps/Route109/scripts.pory"

# 596 "data/maps/Route109/scripts.pory"
Route109_Text_TrainerTipsSign: @ 81EF1D5
# 597 "data/maps/Route109/scripts.pory"
	.string "Trainer Tips\p"
# 598 "data/maps/Route109/scripts.pory"
	.string "Pokémon at the same level may not\n"
# 599 "data/maps/Route109/scripts.pory"
	.string "always have identical stats.\p"
# 600 "data/maps/Route109/scripts.pory"
	.string "Pokémon raised by Trainers are said\n"
# 601 "data/maps/Route109/scripts.pory"
	.string "to grow stronger than wild Pokémon.$"

Route109_Beach_EventScript_Gen8_NPC::
# 604 "data/maps/Route109/scripts.pory"
	lock
# 605 "data/maps/Route109/scripts.pory"
	faceplayer
# 606 "data/maps/Route109/scripts.pory"
	checktrainerflag TRAINER_HUEY
	goto_if 1, Route109_Beach_EventScript_Gen8_NPC_5
Route109_Beach_EventScript_Gen8_NPC_3:
# 621 "data/maps/Route109/scripts.pory"
	msgbox Route109_Beach_EventScript_Gen8_NPC_Text_2
Route109_Beach_EventScript_Gen8_NPC_1:
# 623 "data/maps/Route109/scripts.pory"
	release
	end

Route109_Beach_EventScript_Gen8_NPC_2:
# 613 "data/maps/Route109/scripts.pory"
	msgbox Route109_Beach_EventScript_Gen8_NPC_Text_0
# 614 "data/maps/Route109/scripts.pory"
	givemon SPECIES_YAMASK_GALARIAN, 10, ITEM_NONE
# 615 "data/maps/Route109/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 616 "data/maps/Route109/scripts.pory"
	message Route109_Beach_EventScript_Gen8_NPC_Text_1
# 617 "data/maps/Route109/scripts.pory"
	waitfanfare
	goto Route109_Beach_EventScript_Gen8_NPC_1

Route109_Beach_EventScript_Gen8_NPC_4:
# 608 "data/maps/Route109/scripts.pory"
	checktrainerflag TRAINER_LOLA_1
	goto_if 1, Route109_Beach_EventScript_Gen8_NPC_9
	goto Route109_Beach_EventScript_Gen8_NPC_3

Route109_Beach_EventScript_Gen8_NPC_5:
# 607 "data/maps/Route109/scripts.pory"
	checktrainerflag TRAINER_RICKY_1
	goto_if 1, Route109_Beach_EventScript_Gen8_NPC_4
	goto Route109_Beach_EventScript_Gen8_NPC_3

Route109_Beach_EventScript_Gen8_NPC_8:
# 610 "data/maps/Route109/scripts.pory"
	checktrainerflag TRAINER_HAILEY
	goto_if 1, Route109_Beach_EventScript_Gen8_NPC_12
	goto Route109_Beach_EventScript_Gen8_NPC_3

Route109_Beach_EventScript_Gen8_NPC_9:
# 609 "data/maps/Route109/scripts.pory"
	checktrainerflag TRAINER_CHANDLER
	goto_if 1, Route109_Beach_EventScript_Gen8_NPC_8
	goto Route109_Beach_EventScript_Gen8_NPC_3

Route109_Beach_EventScript_Gen8_NPC_12:
# 611 "data/maps/Route109/scripts.pory"
	checktrainerflag TRAINER_EDMOND
	goto_if 1, Route109_Beach_EventScript_Gen8_NPC_2
	goto Route109_Beach_EventScript_Gen8_NPC_3


Route109_EventScript_LegendaryNPC::
# 628 "data/maps/Route109/scripts.pory"
	lock
# 629 "data/maps/Route109/scripts.pory"
	faceplayer
# 630 "data/maps/Route109/scripts.pory"
	msgbox Route109_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 632 "data/maps/Route109/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route109_EventScript_LegendaryNPC_2
# 654 "data/maps/Route109/scripts.pory"
	msgbox Route109_EventScript_LegendaryNPC_Text_4, MSGBOX_NPC
Route109_EventScript_LegendaryNPC_1:
# 656 "data/maps/Route109/scripts.pory"
	release
	end

Route109_EventScript_LegendaryNPC_2:
# 633 "data/maps/Route109/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route109_EventScript_LegendaryNPC_5
# 640 "data/maps/Route109/scripts.pory"
	checktrainerflag TRAINER_HUEY
	goto_if 1, Route109_EventScript_LegendaryNPC_11
Route109_EventScript_LegendaryNPC_9:
# 649 "data/maps/Route109/scripts.pory"
	msgbox Route109_EventScript_LegendaryNPC_Text_3
	goto Route109_EventScript_LegendaryNPC_1

Route109_EventScript_LegendaryNPC_5:
# 634 "data/maps/Route109/scripts.pory"
	msgbox Route109_EventScript_LegendaryNPC_Text_1
	goto Route109_EventScript_LegendaryNPC_1

Route109_EventScript_LegendaryNPC_8:
# 646 "data/maps/Route109/scripts.pory"
	msgbox Route109_EventScript_LegendaryNPC_Text_2
	goto Route109_EventScript_LegendaryNPC_1

Route109_EventScript_LegendaryNPC_10:
# 642 "data/maps/Route109/scripts.pory"
	checktrainerflag TRAINER_LOLA_1
	goto_if 1, Route109_EventScript_LegendaryNPC_15
	goto Route109_EventScript_LegendaryNPC_9

Route109_EventScript_LegendaryNPC_11:
# 641 "data/maps/Route109/scripts.pory"
	checktrainerflag TRAINER_RICKY_1
	goto_if 1, Route109_EventScript_LegendaryNPC_10
	goto Route109_EventScript_LegendaryNPC_9

Route109_EventScript_LegendaryNPC_14:
# 644 "data/maps/Route109/scripts.pory"
	checktrainerflag TRAINER_HAILEY
	goto_if 1, Route109_EventScript_LegendaryNPC_18
	goto Route109_EventScript_LegendaryNPC_9

Route109_EventScript_LegendaryNPC_15:
# 643 "data/maps/Route109/scripts.pory"
	checktrainerflag TRAINER_CHANDLER
	goto_if 1, Route109_EventScript_LegendaryNPC_14
	goto Route109_EventScript_LegendaryNPC_9

Route109_EventScript_LegendaryNPC_18:
# 645 "data/maps/Route109/scripts.pory"
	checktrainerflag TRAINER_EDMOND
	goto_if 1, Route109_EventScript_LegendaryNPC_8
	goto Route109_EventScript_LegendaryNPC_9


Route109_Beach_EventScript_Gen8_NPC_Text_0:
# 613 "data/maps/Route109/scripts.pory"
	.string "Yes, you are the one...$"

Route109_Beach_EventScript_Gen8_NPC_Text_1:
# 616 "data/maps/Route109/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Galarian Yamask{COLOR DARK_GRAY} as a\n"
	.string "gift for defeating every trainer at\l"
	.string "this beach!$"

Route109_Beach_EventScript_Gen8_NPC_Text_2:
# 621 "data/maps/Route109/scripts.pory"
	.string "I'm seeking a soul hungry for battle and\n"
	.string "wanderlust, but you don't seem ready\l"
	.string "yet...$"

Route109_EventScript_LegendaryNPC_Text_0:
# 630 "data/maps/Route109/scripts.pory"
	.string "Sage: Are you one of those trainers\n"
	.string "looking for legendary Pokémon?\p"
	.string "I possess some intel you might find\n"
	.string "useful.$"

Route109_EventScript_LegendaryNPC_Text_1:
# 634 "data/maps/Route109/scripts.pory"
	.string "This might look like an ordinary beach,\n"
	.string "with its golden sands and gentle waves\l"
	.string "lapping against the shore.\p"
	.string "However, hidden within the depths of\n"
	.string "this seemingly tranquil landscape lies a\l"
	.string "Pokémon of immense power: the\l"
	.string "enigmatic Hoopa.\p"
	.string "We don't yet know why they chose these\n"
	.string "golden dunes as their home. Perhaps he\l"
	.string "preferred being left alone rather than\l"
	.string "having company.\p"
	.string "Should you want to meet them, become\n"
	.string "champion, then come back to me.$"

Route109_EventScript_LegendaryNPC_Text_2:
# 646 "data/maps/Route109/scripts.pory"
	.string "I hope you can excuse the strict\n"
	.string "conditions I imposed upon you, but one\l"
	.string "must not underestimate Hoopa, as their\l"
	.string "true form is one of immense power and\l"
	.string "destructive capabilities. You are\l"
	.string "definitely worthy of managing such\l"
	.string "powers. I updated your DexNav to\l"
	.string "include Hoopa's location: may an\l"
	.string "unbreakable bond be forged between\l"
	.string "you two!$"

Route109_EventScript_LegendaryNPC_Text_3:
# 649 "data/maps/Route109/scripts.pory"
	.string "Congratulations on becoming champion.\n"
	.string "If you want to meet Hoopa, I'd first\l"
	.string "advise you to finish your job and\l"
	.string "defeat every remaining trainer on this\l"
	.string "beach. We'll talk about Hoopa once\l"
	.string "you've done that.$"

Route109_EventScript_LegendaryNPC_Text_4:
# 654 "data/maps/Route109/scripts.pory"
	.string "I'll be sticking here if you ever change\n"
	.string "your mind.$"
