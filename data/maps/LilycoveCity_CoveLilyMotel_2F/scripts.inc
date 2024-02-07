# 1 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 2 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_MapScripts:: @ 82186D2
# 3 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.byte 0
# 4 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 5 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner:: @ 82186D3
# 6 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	lock
# 7 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	faceplayer
# 8 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
# 9 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
# 10 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	specialvar VAR_RESULT, HasAllHoennMons
# 11 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
# 12 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
# 13 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 14 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 15 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 16 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex:: @ 82186F9
# 17 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
# 18 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	return
# 19 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 20 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare:: @ 8218702
# 21 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_TEMP_2
# 22 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 23 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitfanfare
# 24 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
# 25 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 26 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 27 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma:: @ 821870F
# 28 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
# 29 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 30 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 31 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	special Special_ShowDiploma
# 32 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitstate
# 33 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 34 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 35 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 36 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_SelfInsert::
# 37 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	lockall
# 38 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	faceplayer
# 39 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	//goto_if_set FLAG_DAILY_REMATCH_BUFFEL, LilycoveCity_CoveLilyMotel_2F_EventScript_BuffelDefeated
# 40 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImBuffel, MSGBOX_YESNO
# 41 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, NO
# 42 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SelfInsertNo
# 43 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	message LilycoveCity_CoveLilyMotel_2F_Text_SelfInsertBattle
# 44 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 45 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_BUFFEL, LilycoveCity_CoveLilyMotel_2F_Text_BuffelDefeat
# 46 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_BUFFEL
# 47 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_BuffelDefeated::
# 48 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ThanksAgain, MSGBOX_DEFAULT
# 49 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 50 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 51 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 52 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_SelfInsertNo::
# 53 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SelfInsertNo, MSGBOX_DEFAULT
# 54 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 55 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 56 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 57 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer:: @ 8218720
# 58 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
# 59 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 60 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 61 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist:: @ 8218729
# 62 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
# 63 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 64 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 65 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan:: @ 8218732
# 66 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
# 67 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 68 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 69 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Woman:: @ 821873B
# 70 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
# 71 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 72 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 73 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid:: @ 8218744
# 74 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
# 75 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 76 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 77 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Scott:: @ 821874D
# 78 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	lock
# 79 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	faceplayer
# 80 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
# 81 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
# 82 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 83 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
# 84 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 85 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 86 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 87 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott:: @ 821876A
# 88 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
# 89 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 90 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 91 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 92 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex: @ 8218774
# 93 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the Game Designer.\p"
# 94 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, is that right?\n"
# 95 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You're working on a Pokédex?\p"
# 96 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "It's tough trying to complete it,\n"
# 97 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "but don't give up.\p"
# 98 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "If you do complete it, please come\n"
# 99 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "show me.$"
# 100 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 101 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis: @ 821881C
# 102 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Wow! That's awesome!\n"
# 103 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Yep, it's totally awesome!\p"
# 104 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "This Pokédex is completely filled!\n"
# 105 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You really must love Pokémon!\p"
# 106 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm so impressed!\p"
# 107 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Let me give you something in\n"
# 108 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "recognition of your feat!$"
# 109 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 110 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer: @ 82188D6
# 111 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Me? You're talking to me?\n"
# 112 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the Programmer.\p"
# 113 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I wonder what the Slots are\n"
# 114 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "like here.$"
# 115 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 116 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist: @ 821892B
# 117 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the Graphic Artist! Aren't the\n"
# 118 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Pokémon of Hoenn interesting?$"
# 119 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 120 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute: @ 821896C
# 121 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "The girl Tubers, they're cute, hey?\n"
# 122 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "To battle against a cute Tuber…\p"
# 123 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Whoop, it's so awesome!\p"
# 124 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And the Twins! Aren't they cute?\n"
# 125 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "A 2-on-2 battle with Twins…\p"
# 126 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Whoop, it's unbearably fun!$"
# 127 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 128 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart: @ 8218A21
# 129 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "The sea breeze tickles my heart.\n"
# 130 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "It feels wonderful here!$"
# 131 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 132 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy: @ 8218A5B
# 133 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You never know when and where\n"
# 134 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "people will challenge you.\p"
# 135 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "That's why I never leave home without\n"
# 136 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "my Game Boy Advance.$"
# 137 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 138 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles: @ 8218ACF
# 139 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Scott: … … … … …\n"
# 140 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … … Zzz…\p"
# 141 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … … Huh?!\n"
# 142 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, sorry, sorry! I was snoozing!\p"
# 143 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I came to check out this Pokémon\n"
# 144 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Contest thing.\p"
# 145 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I have to admit, it does look quite\n"
# 146 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "entertaining, but…\p"
# 147 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Consider me a purist--I prefer\n"
# 148 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "battles and tough Trainers.\p"
# 149 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "But that's just me.\p"
# 150 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "{PLAYER}{KUN}, I hope you'll enjoy everything\n"
# 151 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "like the Gyms, Contests, Battle Tent,\l"
# 152 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "the whole works!$"
# 153 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 154 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy: @ 8218C33
# 155 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Scott: I think it does take strategy\n"
# 156 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "to win a Contest.\p"
# 157 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Devising Contest strategies is one way\n"
# 158 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "of becoming a better Trainer, I'd say.$"
# 159 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 160 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ImBuffel:
# 161 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Hey {PLAYER}!\p"
# 162 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm Buffel, the creator of the\n"
# 163 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "ROM base (Inclement Emerald).\p"
# 164 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Thanks for playing!\p"
# 165 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I hope you had fun on your journey,\n"
# 166 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "and didn't run in to too many bugs!\p"
# 167 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Now that you're the Champion, how about\n"
# 168 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "we have a friendly battle?\p"
# 169 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Don't worry - I haven't given myself\n"
# 170 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "any unfair advantages!\p"
# 171 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "So, are you ready?$"
# 172 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 173 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SelfInsertNo:
# 174 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Some other time, then?$"
# 175 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 176 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SelfInsertBattle:
# 177 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Great! let's see what you can do!$"
# 178 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 179 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_BuffelDefeat:
# 180 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Well done, {PLAYER}!$"
# 181 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 182 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ThanksAgain:
# 183 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Thanks again for playing!\p"
# 184 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "If you want a rematch, come back\n"
# 185 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "tomorrow!$"
