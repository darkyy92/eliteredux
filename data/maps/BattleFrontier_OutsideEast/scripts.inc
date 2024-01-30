# 1 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 2 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
.set LOCALID_SUDOWOODO, 14
# 3 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 4 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_MapScripts:: @ 8242C04
# 5 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
# 6 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
# 7 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.byte 0
# 8 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 9 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_OnResume: @ 8242C0F
# 10 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
# 11 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 12 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 13 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo:: @ 8242C19
# 14 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 15 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
# 16 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	goto_if_ne Common_EventScript_NopReturn
# 17 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	removeobject VAR_LAST_TALKED
# 18 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	return
# 19 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 20 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_OnTransition: @ 8242C2D
# 21 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
# 22 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
# 23 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
# 24 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 25 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 26 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_ShowSudowoodo:: @ 8242C3F
# 27 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
# 28 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	return
# 29 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 30 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_BattleTowerSign:: @ 8242C43
# 31 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
# 32 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 33 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 34 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_BattlePalaceSign:: @ 8242C4C
# 35 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
# 36 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 37 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 38 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_BattleArenaSign:: @ 8242C55
# 39 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
# 40 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 41 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 42 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_BattlePyramidSign:: @ 8242C5E
# 43 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
# 44 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 45 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 46 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_NinjaBoy:: @ 8242C67
# 47 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
# 48 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 49 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 50 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Man1:: @ 8242C70
# 51 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
# 52 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 53 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 54 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Hiker:: @ 8242C79
# 55 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
# 56 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 57 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 58 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_HexManiac:: @ 8242C82
# 59 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
# 60 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 61 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 62 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_BlackBelt1:: @ 8242C8B
# 63 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
# 64 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 65 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 66 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Cook:: @ 8242C94
# 67 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 68 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
# 69 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 70 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 71 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 72 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Zigzagoon:: @ 8242C9F
# 73 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 74 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	faceplayer
# 75 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	waitse
# 76 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, 0
# 77 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
# 78 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	waitmoncry
# 79 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 80 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 81 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 82 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_RichBoy:: @ 8242CB2
# 83 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
# 84 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 85 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 86 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_ExpertF:: @ 8242CBB
# 87 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
# 88 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 89 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 90 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_TriathleteF:: @ 8242CC4
# 91 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
# 92 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 93 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 94 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Twin:: @ 8242CCD
# 95 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
# 96 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 97 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 98 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Man2:: @ 8242CD6
# 99 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 100 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
# 101 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 102 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 103 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 104 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_TriathleteM:: @ 8242CE1
# 105 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
# 106 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 107 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 108 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Sudowoodo:: @ 8242CEA
# 109 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 110 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	faceplayer
# 111 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	waitse
# 112 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	playse SE_SUDOWOODO_SHAKE
# 113 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
# 114 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	waitmovement 0
# 115 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 116 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 117 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 118 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_WaterSudowoodo:: @ 8242CFC
# 119 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 120 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	faceplayer
# 121 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	special DoWateringBerryTreeAnim
# 122 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	waitstate
# 123 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	waitse
# 124 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	playse SE_SUDOWOODO_SHAKE
# 125 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
# 126 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	waitmovement 0
# 127 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
# 128 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	closemessage
# 129 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	waitse
# 130 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	playmoncry SPECIES_SUDOWOODO, 2
# 131 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	delay 40
# 132 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	waitmoncry
# 133 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_SUDOWOODO
# 134 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 135 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 136 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	setwildbattle SPECIES_SUDOWOODO, VAR_0x800A, ITEM_PASSHO_BERRY
# 137 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 138 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	dowildbattle
# 139 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 140 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 141 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 142 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	goto_if_eq BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
# 143 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 144 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	goto_if_eq BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
# 145 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 146 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	goto_if_eq BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
# 147 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	setflag FLAG_DEFEATED_SUDOWOODO
# 148 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 149 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 150 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 151 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo:: @ 8242D60
# 152 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	setflag FLAG_DEFEATED_SUDOWOODO
# 153 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 154 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 155 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 156 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Movement_SudowoodoShake: @ 8242D69
# 157 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	face_right
# 158 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 159 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	face_down
# 160 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 161 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	face_left
# 162 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 163 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	face_down
# 164 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 165 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	face_right
# 166 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 167 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	face_down
# 168 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 169 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	face_left
# 170 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	delay_8
# 171 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	face_down
# 172 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	step_end
# 173 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 174 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Maniac1:: @ 8242D79
# 175 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
# 176 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 177 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 178 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Girl:: @ 8242D82
# 179 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
# 180 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 181 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 182 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_PsychicM:: @ 8242D8B
# 183 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
# 184 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 185 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 186 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Man3:: @ 8242D94
# 187 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
# 188 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 189 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 190 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Woman1:: @ 8242D9D
# 191 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
# 192 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 193 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 194 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Woman2:: @ 8242DA6
# 195 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
# 196 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 197 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 198 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_BlackBelt2:: @ 8242DAF
# 199 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
# 200 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 201 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 202 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Maniac2:: @ 8242DB8
# 203 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 204 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
# 205 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 206 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 207 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 208 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Woman3:: @ 8242DC3
# 209 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 210 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
# 211 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 212 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 213 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 214 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_RankingHallSign:: @ 8242DCE
# 215 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
# 216 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 217 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 218 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign:: @ 8242DD7
# 219 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
# 220 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 221 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 222 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Gentleman:: @ 8242DE0
# 223 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
# 224 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 225 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 226 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_OldWoman:: @ 8242DE9
# 227 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	lock
# 228 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	faceplayer
# 229 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
# 230 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
# 231 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 232 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 233 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 234 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone:: @ 8242DFE
# 235 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
# 236 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	release
# 237 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 238 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 239 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_EventScript_Camper:: @ 8242E08
# 240 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
# 241 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	end
# 242 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 243 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BattleTowerSign: @ 8242E11
# 244 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "This is the Battle Tower!\n"
# 245 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Keep the win streak as the toughest\l"
# 246 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Trainer!$"
# 247 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 248 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BattlePalaceSign: @ 8242E58
# 249 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "This is the BATTLE PALACE!\n"
# 250 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Keep your eyes on Pokémon battles!$"
# 251 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 252 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BattleArenaSign: @ 8242E96
# 253 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "This is the BATTLE ARENA!\n"
# 254 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Let the toughest teams gather!$"
# 255 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 256 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BattlePyramidSign: @ 8242ECF
# 257 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "This is the BATTLE PYRAMID!\n"
# 258 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Advance through the Battle Quest!$"
# 259 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 260 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_RankingHallSign: @ 8242F0D
# 261 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Battle Frontier RANKING HALL\n"
# 262 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Set your sights on new records!$"
# 263 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 264 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_ExchangeCornerSign: @ 8242F4A
# 265 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "BATTLE POINT EXCHANGE SERVICE CORNER\n"
# 266 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Exchange your Battle Points!$"
# 267 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 268 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial: @ 8242F8C
# 269 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Wow!\n"
# 270 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "It's huge!\p"
# 271 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "The Battle Tower feels special.\n"
# 272 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "It's different from the others.$"
# 273 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 274 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier: @ 8242FDC
# 275 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "My grand ambition is to conquer both\n"
# 276 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "the Battle Frontier and the Pokémon\l"
# 277 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "League.\p"
# 278 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "And if my dream comes true…\p"
# 279 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I… I'm going to ask MIMI next door\n"
# 280 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "if she will be friends with me!$"
# 281 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 282 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_PyramidTooHarsh: @ 824308C
# 283 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "The BATTLE PYRAMID's too harsh!\n"
# 284 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I just can't make it to the top!\p"
# 285 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Since I'm out of options, maybe I can\n"
# 286 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "climb the outside…$"
# 287 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 288 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_ThriveInDarkness: @ 8243106
# 289 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I thrive in darkness…\n"
# 290 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Yes… What is worthy of me?\l"
# 291 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "None other than the BATTLE PYRAMID…\p"
# 292 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "What say you to wandering in darkness\n"
# 293 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "and in utter and total desperation?$"
# 294 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 295 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam: @ 82431A5
# 296 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I didn't sleep for a week, but then\n"
# 297 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I put together the ultimate team!\p"
# 298 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I can't see myself losing, no joke.\n"
# 299 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "We're storming the BATTLE ARENA!$"
# 300 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 301 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_DidScottBringYouHere: @ 8243230
# 302 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Did SCOTT bring you here, too?\n"
# 303 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "What is it with that guy?\p"
# 304 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "It sounds like he really does know\n"
# 305 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "how to spot talented TRAINERS, but…\p"
# 306 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I've never seen him battling in person\n"
# 307 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "ever.$"
# 308 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 309 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BelieveInYouBuddy: @ 82432DD
# 310 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "ZIGG!\n"
# 311 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I believe in you, little buddy!\p"
# 312 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I'll make my little ZIGG any favorite\n"
# 313 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "tasty treats you like if you win!$"
# 314 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 315 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant: @ 824334B
# 316 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "ZIGZAGOON looks vacant…$"
# 317 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 318 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody: @ 8243363
# 319 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "People call me a busybody,\n"
# 320 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "but I can't help it.\p"
# 321 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Your hat's on crooked!\n"
# 322 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Oh, no, trash on the ground!\l"
# 323 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Oops, it's almost dinnertime!\p"
# 324 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I don't know if I can stand to just\n"
# 325 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "watch at the BATTLE PALACE…$"
# 326 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 327 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_OnceBeatGymLeader: @ 8243425
# 328 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I may not look that impressive now,\n"
# 329 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "but I once beat a Gym Leader.\p"
# 330 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Who knows, maybe I should give it\n"
# 331 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "another shot at glory.$"
# 332 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 333 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles: @ 82434A0
# 334 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I'm fast on my Bike, and that goes for\n"
# 335 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "the way I battle, too.\p"
# 336 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I win matches in the blink of\n"
# 337 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "an eye!$"
# 338 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 339 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon: @ 8243504
# 340 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I'm better than my daddy\n"
# 341 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "at Pokémon.$"
# 342 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 343 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy: @ 8243529
# 344 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Go on, my baby sweetie!\n"
# 345 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Go rack up some wins for Daddy!\p"
# 346 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "You're just like your mother,\n"
# 347 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "so you'll be dominating!$"
# 348 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 349 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena: @ 8243598
# 350 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "It wasn't easy getting here,\n"
# 351 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "but I'd heard about this knockout\l"
# 352 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "pretty girl at the BATTLE ARENA.\p"
# 353 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Instead of her, do you know what\n"
# 354 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I found?\p"
# 355 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "A whole teeming mob of sweaty,\n"
# 356 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "stinky, and primitive martial artists!$"
# 357 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 358 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere: @ 8243668
# 359 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I sometimes see this really important-\n"
# 360 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "looking old man going in there.\p"
# 361 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "He has these really awesome Pokémon.\n"
# 362 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "He seems really nice, though.$"
# 363 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 364 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid: @ 82436F2
# 365 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Do you know it?\n"
# 366 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "The legend of the BATTLE PYRAMID?\p"
# 367 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "When there comes a confident Trainer\n"
# 368 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "reaching for the golden pinnacle,\l"
# 369 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "there shall appear a man among men.\p"
# 370 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Don't know that legend?\n"
# 371 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Well, of course not!\l"
# 372 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I just made it up!\p"
# 373 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "What's it supposed to mean?\n"
# 374 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "That, my friend, I can't say!$"
# 375 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 376 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_GotWipedOut: @ 8243809
# 377 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Man! Oh man!\n"
# 378 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I've never lost once before!\p"
# 379 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "But I got wiped out with no saving\n"
# 380 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "grace at all!\p"
# 381 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "And then I'm told I don't have any\n"
# 382 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "talent?! Man!$"
# 383 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 384 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower: @ 8243895
# 385 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "This guy ran into a horribly tough\n"
# 386 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Trainer while he was on the BATTLE\l"
# 387 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "TOWER challenge.\p"
# 388 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Now look at him…\p"
# 389 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "You need to be cautious if you ever\n"
# 390 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "decide to go to the Battle Tower.$"
# 391 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 392 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll: @ 8243943
# 393 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Yes!\n"
# 394 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I've finally got enough Battle Points!\p"
# 395 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I guess I'll trade for another giant\n"
# 396 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "plush DOLL!$"
# 397 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 398 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere: @ 82439A0
# 399 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Oh, yeah, okay!\n"
# 400 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "So this is the RANKING HALL!\p"
# 401 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I'd like to go down in history as\n"
# 402 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "a super champ and have my name\l"
# 403 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "recorded here for posterity.$"
# 404 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 405 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou: @ 8243A2B
# 406 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "With you by my side, I can do anything.$"
# 407 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 408 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome: @ 8243A53
# 409 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Ooh, darling, you are so wonderful!\p"
# 410 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Ooh, I just can't wait anymore!\p"
# 411 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Let's go to a MULTI BATTLE ROOM\n"
# 412 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "right this instant!\p"
# 413 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "If we get together in the BATTLE SALON,\n"
# 414 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "the power of our love will overcome\l"
# 415 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "everyone we meet.\p"
# 416 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Why, before us, darling, everything\n"
# 417 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "will topple like dominoes!$"
# 418 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 419 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers: @ 8243B68
# 420 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "The Battle Frontier isn't exclusively\n"
# 421 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "for tough Trainers.\p"
# 422 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Many people with special abilities\n"
# 423 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "have been invited, it seems.\p"
# 424 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "That man SCOTT…\p"
# 425 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "He may have built this place to serve\n"
# 426 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "a bigger objective…$"
# 427 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 428 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle: @ 8243C2C
# 429 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Excuse me, young one.\n"
# 430 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Have you good eyesight?\p"
# 431 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "There is an odd tree past here, and to\n"
# 432 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "my tired eyes it seems to wiggle.$"
# 433 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 434 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere: @ 8243CA3
# 435 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Excuse me, young one.\n"
# 436 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "Have you a good memory?\p"
# 437 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I have this feeling there once was\n"
# 438 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "an odd tree past here.$"
# 439 "data/maps/BattleFrontier_OutsideEast/scripts.pory"

# 440 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
BattleFrontier_OutsideEast_Text_StickyMonWithLongTail: @ 8243D0B
# 441 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I…\n"
# 442 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "I saw it!\p"
# 443 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "There was a sticky sort of a Pokémon\n"
# 444 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "with a long tail up ahead!\p"
# 445 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "It was hiding under a boulder, and\n"
# 446 "data/maps/BattleFrontier_OutsideEast/scripts.pory"
	.string "it kept staring at me!$"
