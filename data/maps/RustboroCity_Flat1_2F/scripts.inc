# 1 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 2 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
.set LOCALID_WALDAS_DAD, 6
# 3 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 4 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_MapScripts:: @ 8215139
# 5 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.byte 0
# 6 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 7 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldasDad:: @ 821513A
# 8 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	lock
# 9 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	faceplayer
# 10 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	specialvar VAR_RESULT, TryBufferWaldaPhrase
# 11 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	compare VAR_RESULT, FALSE
# 12 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
# 13 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	compare VAR_RESULT, TRUE
# 14 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase
# 15 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 16 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_GivePhrase:: @ 8215157
# 17 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	special DoWaldaNamingScreen
# 18 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	waitstate
# 19 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	compare VAR_0x8004, 1
# 20 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
# 21 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	compare VAR_0x8004, 2
# 22 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
# 23 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
# 24 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	compare VAR_RESULT, TRUE
# 25 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
# 26 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	compare VAR_RESULT, FALSE
# 27 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
# 28 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 29 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 30 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase:: @ 821518D
# 31 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
# 32 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	compare VAR_RESULT, NO
# 33 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
# 34 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
# 35 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase
# 36 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 37 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase:: @ 82151AD
# 38 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
# 39 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	compare VAR_RESULT, NO
# 40 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
# 41 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
# 42 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase
# 43 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 44 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase:: @ 82151CD
# 45 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
# 46 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	release
# 47 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 48 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 49 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_CancelGivePhrase:: @ 82151D7
# 50 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
# 51 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	release
# 52 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 53 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 54 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase:: @ 82151E1
# 55 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
# 56 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
# 57 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
# 58 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	release
# 59 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 60 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 61 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase:: @ 82151F8
# 62 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
# 63 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
# 64 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
# 65 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
# 66 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	waitmovement 0
# 67 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
# 68 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	release
# 69 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 70 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 71 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase:: @ 8215221
# 72 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
# 73 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
# 74 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
# 75 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	release
# 76 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 77 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 78 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda:: @ 8215238
# 79 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
# 80 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	return
# 81 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 82 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldasMom:: @ 821523D
# 83 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
# 84 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 85 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 86 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_PokeDoll:: @ 8215246
# 87 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
# 88 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 89 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 90 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard: @ 821524F
# 91 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, it's so hard every day…\p"
# 92 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "What's hard?\n"
# 93 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "You need to ask?\p"
# 94 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "It's trying to figure out what to\n"
# 95 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "make for meals every day.\p"
# 96 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "It really isn't easy coming up with\n"
# 97 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "meals every day.$"
# 98 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 99 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase: @ 82152FA
# 100 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, hello!\n"
# 101 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Welcome to the Pepper household.\p"
# 102 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "I have a question for you.\n"
# 103 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Have you ever baby-sat?\p"
# 104 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "You see, I'm a new father, so raising\n"
# 105 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "a child is all new to me.\p"
# 106 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "And I have a problem. My daughter\n"
# 107 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Walda doesn't laugh enough.\p"
# 108 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "I think she'd laugh for me if I told\n"
# 109 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "her something funny.\p"
# 110 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Do you know of a funny word or\n"
# 111 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "phrase you can tell me?$"
# 112 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 113 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase: @ 8215448
# 114 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "I've been saying “{STR_VAR_1}”\n"
# 115 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "to amuse her lately.\p"
# 116 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Do you know of a better word or\n"
# 117 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "a phrase that might work?$"
# 118 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 119 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion: @ 82154AD
# 120 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, that's wonderful.\n"
# 121 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "So, let's hear it, your suggestion.$"
# 122 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 123 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_OhIsThatRight: @ 82154E7
# 124 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, is that right?\p"
# 125 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Well, if you come up with a good\n"
# 126 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "suggestion, I'm all ears.$"
# 127 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 128 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_LetsGiveItATry2: @ 8215535
# 129 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Ah, I see.\n"
# 130 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Well, let's give it a try, shall we?$"
# 131 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 132 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_OhShesLaughing: @ 8215565
# 133 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "{STR_VAR_1}.\n"
# 134 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 135 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, yes! She's laughing!\n"
# 136 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, I am as delighted as she!$"
# 137 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 138 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_LetsGiveItATry: @ 82155A4
# 139 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Ah, I see.\n"
# 140 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Well, let's give it a try, shall we?$"
# 141 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 142 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll: @ 82155D4
# 143 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "{STR_VAR_1}.\n"
# 144 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 145 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Hmmm… She's not smiling at all.\n"
# 146 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Maybe Walda is one serious child…$"
# 147 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 148 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase: @ 821561E
# 149 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, so you don't know any good words.\n"
# 150 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "I'd better think for myself, then.\p"
# 151 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Hmm…\n"
# 152 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "How about “{STR_VAR_1}”?\l"
# 153 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Let's see if that will work.$"
# 154 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 155 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2: @ 8215699
# 156 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "{STR_VAR_1}.\n"
# 157 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 158 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Hmmm… She's not smiling at all.\n"
# 159 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Maybe Walda is one serious child…$"
# 160 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 161 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_OhYouDontKnowAny: @ 82156E3
# 162 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, so you don't know any good words.\n"
# 163 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "I guess I'll try to amuse her with\l"
# 164 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "the saying I used before.\p"
# 165 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Anyways, if you have a good suggestion,\n"
# 166 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "don't hesitate in telling me, okay?$"
# 167 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 168 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper: @ 8215792
# 169 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Thank you!\p"
# 170 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Thanks to you, my darling Walda\n"
# 171 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "laughed for me!\p"
# 172 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Actually, I may not look all that\n"
# 173 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "special, but I'm one of Devon\l"
# 174 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Corporation's top researchers.\p"
# 175 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "So, how about I do something in return\n"
# 176 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "for you?\p"
# 177 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "I know, I'll add some new wallpaper\n"
# 178 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "patterns for the Boxes in the PC\l"
# 179 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Pokémon Storage System.\p"
# 180 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "In the wallpaper pattern menu,\n"
# 181 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "select “Friends.”\p"
# 182 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "That will give you access to the new\n"
# 183 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "wallpaper patterns.$"
# 184 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 185 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll: @ 8215923
# 186 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "It's a Pokémon plush Doll!$"
