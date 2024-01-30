# 1 "data/maps/PetalburgWoods/scripts.pory"

# 2 "data/maps/PetalburgWoods/scripts.pory"
.set LOCALID_GRUNT, 3
# 3 "data/maps/PetalburgWoods/scripts.pory"
.set LOCALID_DEVON_EMPLOYEE, 4
# 4 "data/maps/PetalburgWoods/scripts.pory"

# 5 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_MapScripts:: @ 822DFD6
# 6 "data/maps/PetalburgWoods/scripts.pory"
	.byte 0
# 7 "data/maps/PetalburgWoods/scripts.pory"

# 8 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherLeft:: @ 822DFD7
# 9 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 10 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 11 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
# 12 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 13 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 14 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 15 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 16 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 17 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 18 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 19 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 20 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
# 21 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 22 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestUp
# 23 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 24 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 25 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 26 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
# 27 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 28 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 29 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 30 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
# 31 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 32 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 33 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
# 34 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 35 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 36 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 37 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
# 38 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
# 39 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 40 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
# 41 "data/maps/PetalburgWoods/scripts.pory"
	end
# 42 "data/maps/PetalburgWoods/scripts.pory"

# 43 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherRight:: @ 822E079
# 44 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 45 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 46 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
# 47 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 48 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 49 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 50 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 51 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 52 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 53 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 54 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 55 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 56 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 57 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
# 58 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 59 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestUp
# 60 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 61 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 62 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 63 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
# 64 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 65 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 66 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 67 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 68 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 69 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
# 70 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 71 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 72 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 73 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
# 74 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
# 75 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 76 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
# 77 "data/maps/PetalburgWoods/scripts.pory"
	end
# 78 "data/maps/PetalburgWoods/scripts.pory"

# 79 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherIntro:: @ 822E124
# 80 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
# 81 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 82 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
# 83 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 84 "data/maps/PetalburgWoods/scripts.pory"
	return
# 85 "data/maps/PetalburgWoods/scripts.pory"

# 86 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherPostBattle::
# 87 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
# 88 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 89 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
# 90 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 91 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_GRUNT
# 92 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
# 93 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 94 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
# 95 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_EXP_SHARE
# 96 "data/maps/PetalburgWoods/scripts.pory"
	compare VAR_RESULT, FALSE
# 97 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq PetalburgWoods_EventScript_BagFull
# 98 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
# 99 "data/maps/PetalburgWoods/scripts.pory"
	end
# 100 "data/maps/PetalburgWoods/scripts.pory"

# 101 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_BagFull:: @ 822E17D
# 102 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 103 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
# 104 "data/maps/PetalburgWoods/scripts.pory"
	end
# 105 "data/maps/PetalburgWoods/scripts.pory"

# 106 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherFinish:: @ 822E18B
# 107 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
# 108 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
# 109 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 110 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
# 111 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 112 "data/maps/PetalburgWoods/scripts.pory"
	return
# 113 "data/maps/PetalburgWoods/scripts.pory"

# 114 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RemoveDevonResearcher:: @ 822E1A7
# 115 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_DEVON_EMPLOYEE
# 116 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_PETALBURG_WOODS_STATE, 1
# 117 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
# 118 "data/maps/PetalburgWoods/scripts.pory"
	end
# 119 "data/maps/PetalburgWoods/scripts.pory"

# 120 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherLookAround: @ 822E1B1
# 121 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 122 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 123 "data/maps/PetalburgWoods/scripts.pory"
	delay_4
# 124 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 125 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 126 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 127 "data/maps/PetalburgWoods/scripts.pory"
	face_left
# 128 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 129 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 130 "data/maps/PetalburgWoods/scripts.pory"
	face_down
# 131 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 132 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 133 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 134 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 135 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 136 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 137 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 138 "data/maps/PetalburgWoods/scripts.pory"

# 139 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitLeft: @ 822E1C2
# 140 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 141 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 142 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 143 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 144 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 145 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 146 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 147 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 148 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 149 "data/maps/PetalburgWoods/scripts.pory"

# 150 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft: @ 822E1CB
# 151 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 152 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 153 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 154 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 155 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 156 "data/maps/PetalburgWoods/scripts.pory"

# 157 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerRight: @ 822E1D0
# 158 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 159 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 160 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 161 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 162 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 163 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_fastest_right
# 164 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 165 "data/maps/PetalburgWoods/scripts.pory"

# 166 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitRight: @ 822E1D7
# 167 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 168 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 169 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 170 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 171 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 172 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 173 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 174 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 175 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 176 "data/maps/PetalburgWoods/scripts.pory"

# 177 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_WatchResearcherLeave: @ 822E1E0
# 178 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 179 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 180 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_fastest_up
# 181 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 182 "data/maps/PetalburgWoods/scripts.pory"

# 183 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft: @ 822E1E4
# 184 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 185 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 186 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 187 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 188 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_fastest_up
# 189 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 190 "data/maps/PetalburgWoods/scripts.pory"

# 191 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight: @ 822E1EA
# 192 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 193 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 194 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_fastest_up
# 195 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 196 "data/maps/PetalburgWoods/scripts.pory"

# 197 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherStartExit: @ 822E1EE
# 198 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_fastest_down
# 199 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 200 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 201 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 202 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 203 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 204 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 205 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 206 "data/maps/PetalburgWoods/scripts.pory"

# 207 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherLeft: @ 822E1F6
# 208 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 209 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 210 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 211 "data/maps/PetalburgWoods/scripts.pory"

# 212 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaBackOff: @ 822E1F9
# 213 "data/maps/PetalburgWoods/scripts.pory"
	lock_facing_direction
# 214 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 215 "data/maps/PetalburgWoods/scripts.pory"
	unlock_facing_direction
# 216 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 217 "data/maps/PetalburgWoods/scripts.pory"

# 218 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaRunAway: @ 822E1FD
# 219 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 220 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 221 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 222 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 223 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 224 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 225 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 226 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 227 "data/maps/PetalburgWoods/scripts.pory"

# 228 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherRight: @ 822E205
# 229 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 230 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 231 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 232 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 233 "data/maps/PetalburgWoods/scripts.pory"

# 234 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaEntrance: @ 822E209
# 235 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 236 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 237 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 238 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 239 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 240 "data/maps/PetalburgWoods/scripts.pory"

# 241 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachPlayer: @ 822E20E
# 242 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 243 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 244 "data/maps/PetalburgWoods/scripts.pory"

# 245 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy1:: @ 822E210
# 246 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
# 247 "data/maps/PetalburgWoods/scripts.pory"
	end
# 248 "data/maps/PetalburgWoods/scripts.pory"

# 249 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy2:: @ 822E219
# 250 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
# 251 "data/maps/PetalburgWoods/scripts.pory"
	end
# 252 "data/maps/PetalburgWoods/scripts.pory"

# 253 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Girl:: @ 822E222
# 254 "data/maps/PetalburgWoods/scripts.pory"
	lock
# 255 "data/maps/PetalburgWoods/scripts.pory"
	faceplayer
# 256 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
# 257 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
# 258 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 259 "data/maps/PetalburgWoods/scripts.pory"
	compare VAR_RESULT, FALSE
# 260 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 261 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_RECEIVED_MIRACLE_SEED
# 262 "data/maps/PetalburgWoods/scripts.pory"
	release
# 263 "data/maps/PetalburgWoods/scripts.pory"
	end
# 264 "data/maps/PetalburgWoods/scripts.pory"

# 265 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_ExplainMiracleSeed:: @ 822E251
# 266 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
# 267 "data/maps/PetalburgWoods/scripts.pory"
	release
# 268 "data/maps/PetalburgWoods/scripts.pory"
	end
# 269 "data/maps/PetalburgWoods/scripts.pory"

# 270 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign1:: @ 822E25B
# 271 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
# 272 "data/maps/PetalburgWoods/scripts.pory"
	end
# 273 "data/maps/PetalburgWoods/scripts.pory"

# 274 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign2:: @ 822E264
# 275 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
# 276 "data/maps/PetalburgWoods/scripts.pory"
	end
# 277 "data/maps/PetalburgWoods/scripts.pory"

# 278 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Lyle:: @ 822E26D
# 279 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
# 280 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
# 281 "data/maps/PetalburgWoods/scripts.pory"
	end
# 282 "data/maps/PetalburgWoods/scripts.pory"

# 283 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_James:: @ 822E284
# 284 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
# 285 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 286 "data/maps/PetalburgWoods/scripts.pory"
	compare VAR_RESULT, TRUE
# 287 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq PetalburgWoods_EventScript_JamesRematch
# 288 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_0x8004, TRAINER_JAMES_1
# 289 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 290 "data/maps/PetalburgWoods/scripts.pory"
	compare VAR_RESULT, FALSE
# 291 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq PetalburgWoods_EventScript_TryRegisterJames2
# 292 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 293 "data/maps/PetalburgWoods/scripts.pory"
	release
# 294 "data/maps/PetalburgWoods/scripts.pory"
	end
# 295 "data/maps/PetalburgWoods/scripts.pory"

# 296 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames:: @ 822E2C5
# 297 "data/maps/PetalburgWoods/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 298 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 299 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
# 300 "data/maps/PetalburgWoods/scripts.pory"
	release
# 301 "data/maps/PetalburgWoods/scripts.pory"
	end
# 302 "data/maps/PetalburgWoods/scripts.pory"

# 303 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames:: @ 822E2D6
# 304 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
# 305 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 306 "data/maps/PetalburgWoods/scripts.pory"
	release
# 307 "data/maps/PetalburgWoods/scripts.pory"
	end
# 308 "data/maps/PetalburgWoods/scripts.pory"

# 309 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames2:: @ 822E2EF
# 310 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
# 311 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 312 "data/maps/PetalburgWoods/scripts.pory"
	release
# 313 "data/maps/PetalburgWoods/scripts.pory"
	end
# 314 "data/maps/PetalburgWoods/scripts.pory"

# 315 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames2:: @ 822E302
# 316 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
# 317 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 318 "data/maps/PetalburgWoods/scripts.pory"
	release
# 319 "data/maps/PetalburgWoods/scripts.pory"
	end
# 320 "data/maps/PetalburgWoods/scripts.pory"

# 321 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_JamesRematch:: @ 822E31B
# 322 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
# 323 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
# 324 "data/maps/PetalburgWoods/scripts.pory"
	end
# 325 "data/maps/PetalburgWoods/scripts.pory"

# 326 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NotAOneToBeFound: @ 822E332
# 327 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hmmm…\n"
# 328 "data/maps/PetalburgWoods/scripts.pory"
	.string "Not a one to be found…$"
# 329 "data/maps/PetalburgWoods/scripts.pory"

# 330 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HaveYouSeenShroomish: @ 822E34F
# 331 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hello, have you seen any Pokémon\n"
# 332 "data/maps/PetalburgWoods/scripts.pory"
	.string "called Shroomish around here?\p"
# 333 "data/maps/PetalburgWoods/scripts.pory"
	.string "I really love that Pokémon.$"
# 334 "data/maps/PetalburgWoods/scripts.pory"

# 335 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWasGoingToAmbushYou: @ 822E3AA
# 336 "data/maps/PetalburgWoods/scripts.pory"
	.string "I was going to ambush you, but you\n"
# 337 "data/maps/PetalburgWoods/scripts.pory"
	.string "had to dawdle in Petalburg Woods\l"
# 338 "data/maps/PetalburgWoods/scripts.pory"
	.string "forever, didn't you?\p"
# 339 "data/maps/PetalburgWoods/scripts.pory"
	.string "I got sick of waiting, so here I am!$"
# 340 "data/maps/PetalburgWoods/scripts.pory"

# 341 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HandOverThosePapers: @ 822E428
# 342 "data/maps/PetalburgWoods/scripts.pory"
	.string "You! Devon Researcher!\p"
# 343 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hand over those papers!$"
# 344 "data/maps/PetalburgWoods/scripts.pory"

# 345 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouHaveToHelpMe: @ 822E457
# 346 "data/maps/PetalburgWoods/scripts.pory"
	.string "Aiyeeeh!\p"
# 347 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're a Pokémon Trainer, aren't you?\n"
# 348 "data/maps/PetalburgWoods/scripts.pory"
	.string "You've got to help me, please!$"
# 349 "data/maps/PetalburgWoods/scripts.pory"

# 350 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NoOneCrossesTeamAqua: @ 822E4A5
# 351 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hunh? What do you think you're doing?\n"
# 352 "data/maps/PetalburgWoods/scripts.pory"
	.string "What, you're going to protect him?\p"
# 353 "data/maps/PetalburgWoods/scripts.pory"
	.string "No one who crosses Team Aqua\n"
# 354 "data/maps/PetalburgWoods/scripts.pory"
	.string "gets any mercy, not even a kid!\p"
# 355 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me!$"
# 356 "data/maps/PetalburgWoods/scripts.pory"

# 357 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureKiddingMe: @ 822E542
# 358 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're kidding me! You're tough!$"
# 359 "data/maps/PetalburgWoods/scripts.pory"

# 360 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouveGotSomeNerve: @ 822E563
# 361 "data/maps/PetalburgWoods/scripts.pory"
	.string "Grrr… You've got some nerve\n"
# 362 "data/maps/PetalburgWoods/scripts.pory"
	.string "meddling with Team Aqua!\l"
# 363 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me again!\p"
# 364 "data/maps/PetalburgWoods/scripts.pory"
	.string "I wish I could say that, but I'm out of\n"
# 365 "data/maps/PetalburgWoods/scripts.pory"
	.string "Pokémon…\p"
# 366 "data/maps/PetalburgWoods/scripts.pory"
	.string "And, hey, we of Team Aqua are also\n"
# 367 "data/maps/PetalburgWoods/scripts.pory"
	.string "after something in Rustboro.\p"
# 368 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll let you go today!$"
# 369 "data/maps/PetalburgWoods/scripts.pory"

# 370 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ThatWasAwfullyClose: @ 822E63D
# 371 "data/maps/PetalburgWoods/scripts.pory"
	.string "Whew…\n"
# 372 "data/maps/PetalburgWoods/scripts.pory"
	.string "That was awfully close!\p"
# 373 "data/maps/PetalburgWoods/scripts.pory"
	.string "Thanks to you, he didn't rob me of\n"
# 374 "data/maps/PetalburgWoods/scripts.pory"
	.string "these important papers.\p"
# 375 "data/maps/PetalburgWoods/scripts.pory"
	.string "I know, I'll give you an Exp. Share\n"
# 376 "data/maps/PetalburgWoods/scripts.pory"
	.string "as my thanks!$"
# 377 "data/maps/PetalburgWoods/scripts.pory"

# 378 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
# 379 "data/maps/PetalburgWoods/scripts.pory"
	.string "A Pokémon holding that Exp. Share\n"
# 380 "data/maps/PetalburgWoods/scripts.pory"
	.string "will get 100% of the Exp. points from\l"
# 381 "data/maps/PetalburgWoods/scripts.pory"
	.string "battle, even if it didn't participate.\p"
# 382 "data/maps/PetalburgWoods/scripts.pory"
	.string "Normally they'd only get a quarter of\n"
# 383 "data/maps/PetalburgWoods/scripts.pory"
	.string "the Exp. points, so it's quite useful\l"
# 384 "data/maps/PetalburgWoods/scripts.pory"
	.string "for raising weak Pokémon!\p"
# 385 "data/maps/PetalburgWoods/scripts.pory"
	.string "Didn't that Team Aqua thug say\n"
# 386 "data/maps/PetalburgWoods/scripts.pory"
	.string "they were after something in\l"
# 387 "data/maps/PetalburgWoods/scripts.pory"
	.string "Rustboro, too?$"
# 388 "data/maps/PetalburgWoods/scripts.pory"

# 389 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICantBeWastingTime: @ 822E712
# 390 "data/maps/PetalburgWoods/scripts.pory"
	.string "Uh-oh! It's a crisis!\n"
# 391 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be wasting time!$"
# 392 "data/maps/PetalburgWoods/scripts.pory"

# 393 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureLoadedWithItems: @ 822E741
# 394 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're loaded with items.\n"
# 395 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't give you this Exp. Share.$"
# 396 "data/maps/PetalburgWoods/scripts.pory"

# 397 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_GoBugPokemonTeam: @ 822E77D
# 398 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a whole bunch of Pokémon!\p"
# 399 "data/maps/PetalburgWoods/scripts.pory"
	.string "Go, go, go!\n"
# 400 "data/maps/PetalburgWoods/scripts.pory"
	.string "My Bug Pokémon team!$"
# 401 "data/maps/PetalburgWoods/scripts.pory"

# 402 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICouldntWin: @ 822E7C1
# 403 "data/maps/PetalburgWoods/scripts.pory"
	.string "I have all these Pokémon,\n"
# 404 "data/maps/PetalburgWoods/scripts.pory"
	.string "but I couldn't win…$"
# 405 "data/maps/PetalburgWoods/scripts.pory"

# 406 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ImOutOfPokeBalls: @ 822E7EF
# 407 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a bunch of Pokémon.\n"
# 408 "data/maps/PetalburgWoods/scripts.pory"
	.string "Now I'm out of Poké Balls.$"
# 409 "data/maps/PetalburgWoods/scripts.pory"

# 410 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_InstantlyPopularWithBugPokemon: @ 822E827
# 411 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you take Bug Pokémon to school,\n"
# 412 "data/maps/PetalburgWoods/scripts.pory"
	.string "you get to be instantly popular!$"
# 413 "data/maps/PetalburgWoods/scripts.pory"

# 414 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfILose: @ 822E86B
# 415 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 416 "data/maps/PetalburgWoods/scripts.pory"

# 417 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_PeopleRespectYou: @ 822E889
# 418 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you have a big BUG Pokémon,\n"
# 419 "data/maps/PetalburgWoods/scripts.pory"
	.string "people respect you for it.$"
# 420 "data/maps/PetalburgWoods/scripts.pory"

# 421 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch1: @ 822E8C3
# 422 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG\n"
# 423 "data/maps/PetalburgWoods/scripts.pory"
	.string "Pokémon grow up!\p"
# 424 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my PokéNav!$"
# 425 "data/maps/PetalburgWoods/scripts.pory"

# 426 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch2: @ 822E914
# 427 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG \n"
# 428 "data/maps/PetalburgWoods/scripts.pory"
	.string "Pokémon grow up!\p"
# 429 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my PokéNav!$"
# 430 "data/maps/PetalburgWoods/scripts.pory"

# 431 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MyPokemonHaveGrown: @ 822E966
# 432 "data/maps/PetalburgWoods/scripts.pory"
	.string "My Bug Pokémon have grown.\n"
# 433 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll be popular again.$"
# 434 "data/maps/PetalburgWoods/scripts.pory"

# 435 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfLose: @ 822E998
# 436 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 437 "data/maps/PetalburgWoods/scripts.pory"

# 438 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IveBeenTrainingHard: @ 822E9B6
# 439 "data/maps/PetalburgWoods/scripts.pory"
	.string "You get to be popular if you have\n"
# 440 "data/maps/PetalburgWoods/scripts.pory"
	.string "strong Pokémon, right?\l"
# 441 "data/maps/PetalburgWoods/scripts.pory"
	.string "So, I've been training hard.$"
# 442 "data/maps/PetalburgWoods/scripts.pory"

# 443 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_StayOutOfTallGrass: @ 822EA0C
# 444 "data/maps/PetalburgWoods/scripts.pory"
	.string "Yo, there!\n"
# 445 "data/maps/PetalburgWoods/scripts.pory"
	.string "Your Pokémon doing okay?\p"
# 446 "data/maps/PetalburgWoods/scripts.pory"
	.string "If your Pokémon are weak and you want\n"
# 447 "data/maps/PetalburgWoods/scripts.pory"
	.string "to avoid battles, you should stay out\l"
# 448 "data/maps/PetalburgWoods/scripts.pory"
	.string "of tall grass.$"
# 449 "data/maps/PetalburgWoods/scripts.pory"

# 450 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HiddenItemsExplanation: @ 822EA8B
# 451 "data/maps/PetalburgWoods/scripts.pory"
	.string "Sometimes, there are things on the\n"
# 452 "data/maps/PetalburgWoods/scripts.pory"
	.string "ground even if you can't see them.\p"
# 453 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's why I always check where I'm\n"
# 454 "data/maps/PetalburgWoods/scripts.pory"
	.string "walking.$"
# 455 "data/maps/PetalburgWoods/scripts.pory"

# 456 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TryUsingThisItem: @ 822EAFE
# 457 "data/maps/PetalburgWoods/scripts.pory"
	.string "Oh, neat!\n"
# 458 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's the Badge from Rustboro Gym!\p"
# 459 "data/maps/PetalburgWoods/scripts.pory"
	.string "You must be a Trainer.\n"
# 460 "data/maps/PetalburgWoods/scripts.pory"
	.string "You should try using this item.$"
# 461 "data/maps/PetalburgWoods/scripts.pory"

# 462 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MiracleSeedExplanation: @ 822EB63
# 463 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's a Miracle Seed.\n"
# 464 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a Pokémon holds that item, its\l"
# 465 "data/maps/PetalburgWoods/scripts.pory"
	.string "Grass-type moves become stronger.\p"
# 466 "data/maps/PetalburgWoods/scripts.pory"
	.string "Besides Miracle Seed, I think there are\n"
# 467 "data/maps/PetalburgWoods/scripts.pory"
	.string "other convenient items for Pokémon\l"
# 468 "data/maps/PetalburgWoods/scripts.pory"
	.string "to hold.$"
# 469 "data/maps/PetalburgWoods/scripts.pory"

# 470 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsExperience: @ 822EC10
# 471 "data/maps/PetalburgWoods/scripts.pory"
	.string "Elite Redux Trainer Tips\p"
# 472 "data/maps/PetalburgWoods/scripts.pory"
	.string "You can easily level up your\n"
# 473 "data/maps/PetalburgWoods/scripts.pory"
	.string "Pokémon with the new Candy Box.\p"
# 474 "data/maps/PetalburgWoods/scripts.pory"
	.string "There is no need to grind anymore.$"
# 475 "data/maps/PetalburgWoods/scripts.pory"

# 476 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsPP: @ 822ED07
# 477 "data/maps/PetalburgWoods/scripts.pory"
	.string "Elite Redux Trainer Tips\p"
# 478 "data/maps/PetalburgWoods/scripts.pory"
	.string "In addition to Hit Points (HP), Pokémon\n"
# 479 "data/maps/PetalburgWoods/scripts.pory"
	.string "have Power Points (PP) that are used to\l"
# 480 "data/maps/PetalburgWoods/scripts.pory"
	.string "make moves during battle.\p"
# 481 "data/maps/PetalburgWoods/scripts.pory"
	.string "Thanks to Auto-Heal, you don't have to\n"
# 482 "data/maps/PetalburgWoods/scripts.pory"
	.string "go to a Pokémon Center anymore.$"

PetalburgWoods_EventScript_Gen8_NPC::
# 486 "data/maps/PetalburgWoods/scripts.pory"
	lock
# 487 "data/maps/PetalburgWoods/scripts.pory"
	faceplayer
# 488 "data/maps/PetalburgWoods/scripts.pory"
	checktrainerflag TRAINER_JAMES_1
	goto_if 1, PetalburgWoods_EventScript_Gen8_NPC_4
PetalburgWoods_EventScript_Gen8_NPC_3:
# 499 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_EventScript_Gen8_NPC_Text_3
PetalburgWoods_EventScript_Gen8_NPC_1:
# 501 "data/maps/PetalburgWoods/scripts.pory"
	release
	end

PetalburgWoods_EventScript_Gen8_NPC_2:
# 491 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_EventScript_Gen8_NPC_Text_0
# 492 "data/maps/PetalburgWoods/scripts.pory"
	givemon SPECIES_SIZZLIPEDE, 10, ITEM_NONE
# 493 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_EventScript_Gen8_NPC_Text_1
# 494 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_EventScript_Gen8_NPC_Text_2
	goto PetalburgWoods_EventScript_Gen8_NPC_1

PetalburgWoods_EventScript_Gen8_NPC_4:
# 489 "data/maps/PetalburgWoods/scripts.pory"
	checktrainerflag TRAINER_LYLE
	goto_if 1, PetalburgWoods_EventScript_Gen8_NPC_2
	goto PetalburgWoods_EventScript_Gen8_NPC_3


PetalburgWoods_EventScript_Gen8_NPC_Text_0:
# 491 "data/maps/PetalburgWoods/scripts.pory"
	.string "Good job, every Venipede in a thousand\n"
	.string "mile radius will fear you now!$"

PetalburgWoods_EventScript_Gen8_NPC_Text_1:
# 493 "data/maps/PetalburgWoods/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Sizzlipede{COLOR DARK_GRAY} as a gift\n"
	.string "for defeating every trainer here!$"

PetalburgWoods_EventScript_Gen8_NPC_Text_2:
# 494 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come back if you want more!$"

PetalburgWoods_EventScript_Gen8_NPC_Text_3:
# 499 "data/maps/PetalburgWoods/scripts.pory"
	.string "In Galar, wild Venipede and Sizzlipede\n"
	.string "fight in a constant struggle for\l"
	.string "supremacy. Will you join me on the side\l"
	.string "of the latter? Defeat every trainer\l"
	.string "here, and I'll give you a Sizzlipede!$"
