# 1 "data/maps/SSTidalRooms/scripts.pory"

# 2 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_MapScripts:: @ 823C9F1
# 3 "data/maps/SSTidalRooms/scripts.pory"
	.byte 0
# 4 "data/maps/SSTidalRooms/scripts.pory"

# 5 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_SnatchGiver:: @ 823C9F2
# 6 "data/maps/SSTidalRooms/scripts.pory"
	lock
# 7 "data/maps/SSTidalRooms/scripts.pory"
	faceplayer
# 8 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
# 9 "data/maps/SSTidalRooms/scripts.pory"
	release
# 10 "data/maps/SSTidalRooms/scripts.pory"
	end
# 11 "data/maps/SSTidalRooms/scripts.pory"

# 12 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_ExplainSnatch:: @ 823CA29
# 13 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
# 14 "data/maps/SSTidalRooms/scripts.pory"
	release
# 15 "data/maps/SSTidalRooms/scripts.pory"
	end
# 16 "data/maps/SSTidalRooms/scripts.pory"

# 17 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_Bed:: @ 823CA33
# 18 "data/maps/SSTidalRooms/scripts.pory"
	lockall
# 19 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
# 20 "data/maps/SSTidalRooms/scripts.pory"
	closemessage
# 21 "data/maps/SSTidalRooms/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 22 "data/maps/SSTidalRooms/scripts.pory"
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
# 23 "data/maps/SSTidalRooms/scripts.pory"
	releaseall
# 24 "data/maps/SSTidalRooms/scripts.pory"
	end
# 25 "data/maps/SSTidalRooms/scripts.pory"

# 26 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_Colton:: @ 823CA49
# 27 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
# 28 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
# 29 "data/maps/SSTidalRooms/scripts.pory"
	end
# 30 "data/maps/SSTidalRooms/scripts.pory"

# 31 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_Micah:: @ 823CA60
# 32 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
# 33 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
# 34 "data/maps/SSTidalRooms/scripts.pory"
	end
# 35 "data/maps/SSTidalRooms/scripts.pory"

# 36 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_Thomas:: @ 823CA77
# 37 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
# 38 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
# 39 "data/maps/SSTidalRooms/scripts.pory"
	end
# 40 "data/maps/SSTidalRooms/scripts.pory"

# 41 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_Jed:: @ 823CA8E
# 42 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
# 43 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
# 44 "data/maps/SSTidalRooms/scripts.pory"
	end
# 45 "data/maps/SSTidalRooms/scripts.pory"

# 46 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_Lea:: @ 823CAA9
# 47 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
# 48 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
# 49 "data/maps/SSTidalRooms/scripts.pory"
	end
# 50 "data/maps/SSTidalRooms/scripts.pory"

# 51 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_Garret:: @ 823CAC4
# 52 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
# 53 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
# 54 "data/maps/SSTidalRooms/scripts.pory"
	end
# 55 "data/maps/SSTidalRooms/scripts.pory"

# 56 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_EventScript_Naomi:: @ 823CADB
# 57 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
# 58 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
# 59 "data/maps/SSTidalRooms/scripts.pory"
	end
# 60 "data/maps/SSTidalRooms/scripts.pory"

# 61 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_TakeRestOnBed: @ 823CAF2
# 62 "data/maps/SSTidalRooms/scripts.pory"
	.string "There's a bed…\n"
# 63 "data/maps/SSTidalRooms/scripts.pory"
	.string "Let's take a rest.$"
# 64 "data/maps/SSTidalRooms/scripts.pory"

# 65 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_ColtonIntro: @ 823CB14
# 66 "data/maps/SSTidalRooms/scripts.pory"
	.string "I often sail to Lilycove City.\p"
# 67 "data/maps/SSTidalRooms/scripts.pory"
	.string "I enjoy attending Contests,\n"
# 68 "data/maps/SSTidalRooms/scripts.pory"
	.string "you see.$"
# 69 "data/maps/SSTidalRooms/scripts.pory"

# 70 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_ColtonDefeat: @ 823CB58
# 71 "data/maps/SSTidalRooms/scripts.pory"
	.string "That was an enjoyable match!$"
# 72 "data/maps/SSTidalRooms/scripts.pory"

# 73 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_ColtonPostBattle: @ 823CB75
# 74 "data/maps/SSTidalRooms/scripts.pory"
	.string "I get so excited imagining what kinds\n"
# 75 "data/maps/SSTidalRooms/scripts.pory"
	.string "of Pokémon I'll get to see in the next\l"
# 76 "data/maps/SSTidalRooms/scripts.pory"
	.string "Contest. The anticipation of it thrills!$"
# 77 "data/maps/SSTidalRooms/scripts.pory"

# 78 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_MicahIntro: @ 823CBEB
# 79 "data/maps/SSTidalRooms/scripts.pory"
	.string "Are your friends strong?$"
# 80 "data/maps/SSTidalRooms/scripts.pory"

# 81 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_MicahDefeat: @ 823CC04
# 82 "data/maps/SSTidalRooms/scripts.pory"
	.string "Your friends are, indeed, strong.$"
# 83 "data/maps/SSTidalRooms/scripts.pory"

# 84 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_MicahPostBattle: @ 823CC26
# 85 "data/maps/SSTidalRooms/scripts.pory"
	.string "Friends need not be human.\n"
# 86 "data/maps/SSTidalRooms/scripts.pory"
	.string "For me, Pokémon are treasured friends!$"
# 87 "data/maps/SSTidalRooms/scripts.pory"

# 88 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_ThomasIntro: @ 823CC68
# 89 "data/maps/SSTidalRooms/scripts.pory"
	.string "Child…\n"
# 90 "data/maps/SSTidalRooms/scripts.pory"
	.string "Did you knock on the door?$"
# 91 "data/maps/SSTidalRooms/scripts.pory"

# 92 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_ThomasDefeat: @ 823CC8A
# 93 "data/maps/SSTidalRooms/scripts.pory"
	.string "A loss is to be accepted without haste\n"
# 94 "data/maps/SSTidalRooms/scripts.pory"
	.string "or panic.$"
# 95 "data/maps/SSTidalRooms/scripts.pory"

# 96 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_ThomasPostBattle: @ 823CCBB
# 97 "data/maps/SSTidalRooms/scripts.pory"
	.string "To be never ruffled in any situation is\n"
# 98 "data/maps/SSTidalRooms/scripts.pory"
	.string "the GENTLEMAN's code of conduct.$"
# 99 "data/maps/SSTidalRooms/scripts.pory"

# 100 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_JedIntro: @ 823CD04
# 101 "data/maps/SSTidalRooms/scripts.pory"
	.string "Jed: I feel a little shy about this, but…\n"
# 102 "data/maps/SSTidalRooms/scripts.pory"
	.string "We'll show you our lovey-dovey power!$"
# 103 "data/maps/SSTidalRooms/scripts.pory"

# 104 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_JedDefeat: @ 823CD54
# 105 "data/maps/SSTidalRooms/scripts.pory"
	.string "Jed: Sigh…$"
# 106 "data/maps/SSTidalRooms/scripts.pory"

# 107 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_JedPostBattle: @ 823CD5F
# 108 "data/maps/SSTidalRooms/scripts.pory"
	.string "Jed: It's the first time that our lovey-\n"
# 109 "data/maps/SSTidalRooms/scripts.pory"
	.string "dovey power couldn't prevail!\l"
# 110 "data/maps/SSTidalRooms/scripts.pory"
	.string "You must be an awesome Trainer!$"
# 111 "data/maps/SSTidalRooms/scripts.pory"

# 112 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_JedNotEnoughMons: @ 823CDC6
# 113 "data/maps/SSTidalRooms/scripts.pory"
	.string "Jed: You only have one Pokémon?\n"
# 114 "data/maps/SSTidalRooms/scripts.pory"
	.string "Isn't that just too lonesome?$"
# 115 "data/maps/SSTidalRooms/scripts.pory"

# 116 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_LeaIntro: @ 823CE04
# 117 "data/maps/SSTidalRooms/scripts.pory"
	.string "Lea: I feel a little silly, but…\n"
# 118 "data/maps/SSTidalRooms/scripts.pory"
	.string "We'll show you our lovey-dovey power!$"
# 119 "data/maps/SSTidalRooms/scripts.pory"

# 120 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_LeaDefeat: @ 823CE4B
# 121 "data/maps/SSTidalRooms/scripts.pory"
	.string "Lea: Oh, boo!$"
# 122 "data/maps/SSTidalRooms/scripts.pory"

# 123 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_LeaPostBattle: @ 823CE59
# 124 "data/maps/SSTidalRooms/scripts.pory"
	.string "Lea: I can't believe it!\n"
# 125 "data/maps/SSTidalRooms/scripts.pory"
	.string "Our lovey-dovey power failed…\l"
# 126 "data/maps/SSTidalRooms/scripts.pory"
	.string "You must be an awesome Trainer!$"
# 127 "data/maps/SSTidalRooms/scripts.pory"

# 128 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_LeaNotEnoughMons: @ 823CEB0
# 129 "data/maps/SSTidalRooms/scripts.pory"
	.string "Lea: I wanted to battle…\n"
# 130 "data/maps/SSTidalRooms/scripts.pory"
	.string "But you don't even have two Pokémon…$"
# 131 "data/maps/SSTidalRooms/scripts.pory"

# 132 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_GarretIntro: @ 823CEEE
# 133 "data/maps/SSTidalRooms/scripts.pory"
	.string "Ah, you've come just in time.\p"
# 134 "data/maps/SSTidalRooms/scripts.pory"
	.string "I'm bored, you see.\n"
# 135 "data/maps/SSTidalRooms/scripts.pory"
	.string "You may entertain me.$"
# 136 "data/maps/SSTidalRooms/scripts.pory"

# 137 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_GarretDefeat: @ 823CF36
# 138 "data/maps/SSTidalRooms/scripts.pory"
	.string "…That will do.$"
# 139 "data/maps/SSTidalRooms/scripts.pory"

# 140 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_GarretPostBattle: @ 823CF45
# 141 "data/maps/SSTidalRooms/scripts.pory"
	.string "Perhaps I shall get Father to acquire\n"
# 142 "data/maps/SSTidalRooms/scripts.pory"
	.string "a yacht for me.\l"
# 143 "data/maps/SSTidalRooms/scripts.pory"
	.string "A yacht for me and Pokémon!$"
# 144 "data/maps/SSTidalRooms/scripts.pory"

# 145 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_NaomiIntro: @ 823CF97
# 146 "data/maps/SSTidalRooms/scripts.pory"
	.string "Oh, you're such an adorable Trainer.\n"
# 147 "data/maps/SSTidalRooms/scripts.pory"
	.string "Would you like to have tea?\l"
# 148 "data/maps/SSTidalRooms/scripts.pory"
	.string "Or would you rather battle?$"
# 149 "data/maps/SSTidalRooms/scripts.pory"

# 150 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_NaomiDefeat: @ 823CFF4
# 151 "data/maps/SSTidalRooms/scripts.pory"
	.string "I see.\n"
# 152 "data/maps/SSTidalRooms/scripts.pory"
	.string "You're the active sort.$"
# 153 "data/maps/SSTidalRooms/scripts.pory"

# 154 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_NaomiPostBattle: @ 823D013
# 155 "data/maps/SSTidalRooms/scripts.pory"
	.string "A world cruise on a luxury liner has its\n"
# 156 "data/maps/SSTidalRooms/scripts.pory"
	.string "charms, I must say…\p"
# 157 "data/maps/SSTidalRooms/scripts.pory"
	.string "But, I will admit there is an appealing\n"
# 158 "data/maps/SSTidalRooms/scripts.pory"
	.string "side to touring Hoenn by ferry.$"
# 159 "data/maps/SSTidalRooms/scripts.pory"

# 160 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_NotSuspiciousTakeThis: @ 823D098
# 161 "data/maps/SSTidalRooms/scripts.pory"
	.string "Uh… Hi! I… I'm not acting suspicious!\n"
# 162 "data/maps/SSTidalRooms/scripts.pory"
	.string "Uh… You can have this! For free!\p"
# 163 "data/maps/SSTidalRooms/scripts.pory"
	.string "It… Honestly, I didn't Snatch it from\n"
# 164 "data/maps/SSTidalRooms/scripts.pory"
	.string "someone! I'd never do such a thing!\l"
# 165 "data/maps/SSTidalRooms/scripts.pory"
	.string "It's clean! You can use it!$"
# 166 "data/maps/SSTidalRooms/scripts.pory"

# 167 "data/maps/SSTidalRooms/scripts.pory"
SSTidalRooms_Text_ExplainSnatch: @ 823D145
# 168 "data/maps/SSTidalRooms/scripts.pory"
	.string "Snatch steals the beneficial effects\n"
# 169 "data/maps/SSTidalRooms/scripts.pory"
	.string "of certain moves before they can be\l"
# 170 "data/maps/SSTidalRooms/scripts.pory"
	.string "used by a foe or ally.$"
