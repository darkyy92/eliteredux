# 1 "data/maps/MossdeepCity_House1/scripts.pory"

# 2 "data/maps/MossdeepCity_House1/scripts.pory"
.set LOCALID_CYNTHIA, 1
# 3 "data/maps/MossdeepCity_House1/scripts.pory"

# 4 "data/maps/MossdeepCity_House1/scripts.pory"
@ VAR_CYNTHIA_STATE
# 5 "data/maps/MossdeepCity_House1/scripts.pory"
@ 0: Unmet
# 6 "data/maps/MossdeepCity_House1/scripts.pory"
@ 1: Defeated for the first time
# 7 "data/maps/MossdeepCity_House1/scripts.pory"

# 8 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_MapScripts::
# 9 "data/maps/MossdeepCity_House1/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_House1_MapScripts_OnFrame
# 10 "data/maps/MossdeepCity_House1/scripts.pory"
	.byte 0
# 11 "data/maps/MossdeepCity_House1/scripts.pory"

# 12 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_MapScripts_OnFrame:
# 13 "data/maps/MossdeepCity_House1/scripts.pory"
	map_script_2 VAR_CYNTHIA_STATE, 1, MossdeepCity_House1_EventScript_CynthiaBattle
# 14 "data/maps/MossdeepCity_House1/scripts.pory"
	.2byte 0
# 15 "data/maps/MossdeepCity_House1/scripts.pory"

# 16 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_EventScript_CynthiaBattle::
# 17 "data/maps/MossdeepCity_House1/scripts.pory"
	lockall
# 18 "data/maps/MossdeepCity_House1/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, MossdeepCity_House1_EventScript_End
# 19 "data/maps/MossdeepCity_House1/scripts.pory"
	goto_if_set FLAG_HIDE_MOSSDEEP_CYNTHIA, MossdeepCity_House1_EventScript_End
# 20 "data/maps/MossdeepCity_House1/scripts.pory"
	delay 40
# 21 "data/maps/MossdeepCity_House1/scripts.pory"
	playse SE_PIN
# 22 "data/maps/MossdeepCity_House1/scripts.pory"
	applymovement LOCALID_CYNTHIA, Common_Movement_ExclamationMark
# 23 "data/maps/MossdeepCity_House1/scripts.pory"
	waitmovement 0
# 24 "data/maps/MossdeepCity_House1/scripts.pory"
	applymovement LOCALID_CYNTHIA, Common_Movement_Delay48
# 25 "data/maps/MossdeepCity_House1/scripts.pory"
	waitmovement 0
# 26 "data/maps/MossdeepCity_House1/scripts.pory"
	playbgm DP_SEQ_EYE_CHAMP, FALSE
# 27 "data/maps/MossdeepCity_House1/scripts.pory"
	applymovement LOCALID_CYNTHIA, Common_Movement_WalkInPlaceFastestDown
# 28 "data/maps/MossdeepCity_House1/scripts.pory"
	waitmovement 0
# 29 "data/maps/MossdeepCity_House1/scripts.pory"
	msgbox MossdeepCity_House1_Text_WhatsThis, MSGBOX_YESNO
# 30 "data/maps/MossdeepCity_House1/scripts.pory"
	compare VAR_RESULT, NO
# 31 "data/maps/MossdeepCity_House1/scripts.pory"
	call_if_eq MossdeepCity_House1_EventScript_CynthiaHeal
# 32 "data/maps/MossdeepCity_House1/scripts.pory"
	msgbox MossdeepCity_House1_Text_BeforeISendOut, MSGBOX_DEFAULT
# 33 "data/maps/MossdeepCity_House1/scripts.pory"
	closemessage
# 34 "data/maps/MossdeepCity_House1/scripts.pory"
	trainerbattle_no_intro TRAINER_CYNTHIA_1, MossdeepCity_House1_Text_CynthiaDefeat
# 35 "data/maps/MossdeepCity_House1/scripts.pory"
	msgbox MossdeepCity_House1_Text_BeyondExpectation, MSGBOX_DEFAULT
# 36 "data/maps/MossdeepCity_House1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
# 37 "data/maps/MossdeepCity_House1/scripts.pory"
	waitmovement 0
# 38 "data/maps/MossdeepCity_House1/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 39 "data/maps/MossdeepCity_House1/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 40 "data/maps/MossdeepCity_House1/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 41 "data/maps/MossdeepCity_House1/scripts.pory"
	setflag FLAG_DAILY_REMATCH_CYNTHIA
# 42 "data/maps/MossdeepCity_House1/scripts.pory"
	setvar VAR_CYNTHIA_STATE, 2
# 43 "data/maps/MossdeepCity_House1/scripts.pory"
	releaseall
# 44 "data/maps/MossdeepCity_House1/scripts.pory"
	end
# 45 "data/maps/MossdeepCity_House1/scripts.pory"

# 46 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_EventScript_CynthiaHeal::
# 47 "data/maps/MossdeepCity_House1/scripts.pory"
	msgbox MossdeepCity_House1_Text_LetMeHealYourPokemon, MSGBOX_DEFAULT
# 48 "data/maps/MossdeepCity_House1/scripts.pory"
	playfanfare MUS_HEAL
# 49 "data/maps/MossdeepCity_House1/scripts.pory"
	waitfanfare
# 50 "data/maps/MossdeepCity_House1/scripts.pory"
	special HealPlayerParty
# 51 "data/maps/MossdeepCity_House1/scripts.pory"
	return
# 52 "data/maps/MossdeepCity_House1/scripts.pory"

# 53 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_EventScript_Cynthia::
# 54 "data/maps/MossdeepCity_House1/scripts.pory"
	lockall
# 55 "data/maps/MossdeepCity_House1/scripts.pory"
	faceplayer
# 56 "data/maps/MossdeepCity_House1/scripts.pory"
	goto_if_unset FLAG_DAILY_REMATCH_CYNTHIA, MossdeepCity_House1_EventScript_CynthiaRematch
# 57 "data/maps/MossdeepCity_House1/scripts.pory"
	msgbox MossdeepCity_House1_Text_AfterBattle, MSGBOX_DEFAULT
# 58 "data/maps/MossdeepCity_House1/scripts.pory"
	releaseall
# 59 "data/maps/MossdeepCity_House1/scripts.pory"
	end
# 60 "data/maps/MossdeepCity_House1/scripts.pory"

# 61 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_EventScript_CynthiaRematch::
# 62 "data/maps/MossdeepCity_House1/scripts.pory"
	msgbox MossdeepCity_House1_Text_BeforeRematch, MSGBOX_YESNO
# 63 "data/maps/MossdeepCity_House1/scripts.pory"
	compare VAR_RESULT, YES
# 64 "data/maps/MossdeepCity_House1/scripts.pory"
	goto_if_eq MossdeepCity_House1_EventScript_CynthiaStartRematch
# 65 "data/maps/MossdeepCity_House1/scripts.pory"
	releaseall
# 66 "data/maps/MossdeepCity_House1/scripts.pory"
	end
# 67 "data/maps/MossdeepCity_House1/scripts.pory"

# 68 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_EventScript_CynthiaStartRematch::
# 69 "data/maps/MossdeepCity_House1/scripts.pory"
	msgbox MossdeepCity_House1_Text_NoHoldsBarred, MSGBOX_DEFAULT
# 70 "data/maps/MossdeepCity_House1/scripts.pory"
	random 1
# 71 "data/maps/MossdeepCity_House1/scripts.pory"
	compare VAR_RESULT, 1
# 72 "data/maps/MossdeepCity_House1/scripts.pory"
	goto_if_eq MossdeepCity_House1_EventScript_CynthiaTeam1
# 73 "data/maps/MossdeepCity_House1/scripts.pory"
	trainerbattle_no_intro TRAINER_CYNTHIA_2, MossdeepCity_House1_Text_CynthiaDefeat
# 74 "data/maps/MossdeepCity_House1/scripts.pory"
	setflag FLAG_DAILY_REMATCH_CYNTHIA
# 75 "data/maps/MossdeepCity_House1/scripts.pory"
	releaseall
# 76 "data/maps/MossdeepCity_House1/scripts.pory"
	end
# 77 "data/maps/MossdeepCity_House1/scripts.pory"

# 78 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_EventScript_CynthiaTeam1::
# 79 "data/maps/MossdeepCity_House1/scripts.pory"
	trainerbattle_no_intro TRAINER_CYNTHIA_1, MossdeepCity_House1_Text_CynthiaDefeat
# 80 "data/maps/MossdeepCity_House1/scripts.pory"
	setflag FLAG_DAILY_REMATCH_CYNTHIA
# 81 "data/maps/MossdeepCity_House1/scripts.pory"
	releaseall
# 82 "data/maps/MossdeepCity_House1/scripts.pory"
	end
# 83 "data/maps/MossdeepCity_House1/scripts.pory"

# 84 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_EventScript_End::
# 85 "data/maps/MossdeepCity_House1/scripts.pory"
	releaseall
# 86 "data/maps/MossdeepCity_House1/scripts.pory"
	end
# 87 "data/maps/MossdeepCity_House1/scripts.pory"

# 88 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_Text_WhatsThis:
# 89 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "What's this?\p"
# 90 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Oh, you're {PLAYER}, aren't you?\n"
# 91 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Hoenn's newest Champion!\p"
# 92 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "I'm Cynthia. I'm a Pokémon Trainer,\n"
# 93 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "too, like you.\p"
# 94 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "I have an insatiable curiosity for\n"
# 95 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "researching Pokémon myths.\p"
# 96 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Have you heard of Navel Rock?\p"
# 97 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "It's said that two Legendary Pokémon\n"
# 98 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "await a special trainer there.\p"
# 99 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "You can get there by taking a\n"
# 100 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Mystic Ticket to the ferry captain.\p"
# 101 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "I was going to go myself, but…\n"
# 102 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Strangely, I get the feeling that you\l"
# 103 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "should go instead.\p"
# 104 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Of course, there's only one way to\n"
# 105 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "decide - with a Pokémon battle!\p"
# 106 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Would you care to be my opponent?$"
# 107 "data/maps/MossdeepCity_House1/scripts.pory"

# 108 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_Text_LetMeHealYourPokemon:
# 109 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Oh? I see. Allow me to me heal your\n"
# 110 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Pokémon first.$"
# 111 "data/maps/MossdeepCity_House1/scripts.pory"

# 112 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_Text_BeforeISendOut:
# 113 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Before I send out my Pokémon, my heart\n"
# 114 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "always begins to race…\p"
# 115 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Interesting…\p"
# 116 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "My Pokémon in their Poké Balls are\n"
# 117 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "radiating a happy feeling.\p"
# 118 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Are you the reason?$"
# 119 "data/maps/MossdeepCity_House1/scripts.pory"

# 120 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_Text_CynthiaDefeat:
# 121 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "My heart is pounding so hard because I\n"
# 122 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "had such a heated battle with you.\p" 
# 123 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "You are a really great Trainer!$"
# 124 "data/maps/MossdeepCity_House1/scripts.pory"

# 125 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_Text_BeyondExpectation:
# 126 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "That was beyond my expectation!\n"
# 127 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "What an exceptional battle!\p"
# 128 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "I think it's clear you should have\n"
# 129 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "the Mystic Ticket.\p"
# 130 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Go on, take it!$"
# 131 "data/maps/MossdeepCity_House1/scripts.pory"

# 132 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_Text_AfterBattle:
# 133 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Cynthia: You're a great Trainer, and\n"
# 134 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "it would make me happy to see you\l"
# 135 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "again sometime.$"
# 136 "data/maps/MossdeepCity_House1/scripts.pory"

# 137 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_Text_BeforeRematch:
# 138 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Cynthia: How terrific to see you again!\p"
# 139 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "I've got to tell you… \n"
# 140 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "My Pokémon are excited to battle yours.\p"
# 141 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Would you care to be my opponent?$"
# 142 "data/maps/MossdeepCity_House1/scripts.pory"

# 143 "data/maps/MossdeepCity_House1/scripts.pory"
MossdeepCity_House1_Text_NoHoldsBarred:
# 144 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "This will be such fun!\n" 
# 145 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "No holds barred!$"
