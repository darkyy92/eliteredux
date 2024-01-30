# 1 "data/maps/VerdanturfMeadow/scripts.pory"

# 2 "data/maps/VerdanturfMeadow/scripts.pory"
VerdanturfMeadow_MapScripts::
# 3 "data/maps/VerdanturfMeadow/scripts.pory"
	.byte 0
# 4 "data/maps/VerdanturfMeadow/scripts.pory"

# 5 "data/maps/VerdanturfMeadow/scripts.pory"
VerdanturfMeadow_EventScript_GiftMeganiumite::
# 6 "data/maps/VerdanturfMeadow/scripts.pory"
	lock
# 7 "data/maps/VerdanturfMeadow/scripts.pory"
	faceplayer
# 8 "data/maps/VerdanturfMeadow/scripts.pory"
	goto_if_set FLAG_RECEIVED_AUDINO, VerdanturfMeadow_EventScript_TakeCareOfAudino
# 9 "data/maps/VerdanturfMeadow/scripts.pory"
	msgbox VerdanturfMeadow_Text_PleaseTakePokemon, MSGBOX_DEFAULT
# 10 "data/maps/VerdanturfMeadow/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_AUDINO
# 11 "data/maps/VerdanturfMeadow/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 12 "data/maps/VerdanturfMeadow/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 13 "data/maps/VerdanturfMeadow/scripts.pory"
	givemon SPECIES_AUDINO, VAR_0x800A, ITEM_AUDINITE
# 14 "data/maps/VerdanturfMeadow/scripts.pory"
	compare VAR_RESULT, 0
# 15 "data/maps/VerdanturfMeadow/scripts.pory"
	goto_if_eq VerdanturfMeadow_EventScript_ReceiveAudinoParty
# 16 "data/maps/VerdanturfMeadow/scripts.pory"
	compare VAR_RESULT, 1
# 17 "data/maps/VerdanturfMeadow/scripts.pory"
	goto_if_eq VerdanturfMeadow_EventScript_ReceiveAudinoPC
# 18 "data/maps/VerdanturfMeadow/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 19 "data/maps/VerdanturfMeadow/scripts.pory"
	end
# 20 "data/maps/VerdanturfMeadow/scripts.pory"

# 21 "data/maps/VerdanturfMeadow/scripts.pory"
VerdanturfMeadow_EventScript_ReceiveAudinoParty::
# 22 "data/maps/VerdanturfMeadow/scripts.pory"
	call VerdanturfMeadow_EventScript_ReceivedAudinoFanfare
# 23 "data/maps/VerdanturfMeadow/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 24 "data/maps/VerdanturfMeadow/scripts.pory"
	compare VAR_RESULT, NO
# 25 "data/maps/VerdanturfMeadow/scripts.pory"
	goto_if_eq VerdanturfMeadow_EventScript_TakeCareOfAudino
# 26 "data/maps/VerdanturfMeadow/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 27 "data/maps/VerdanturfMeadow/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 28 "data/maps/VerdanturfMeadow/scripts.pory"
	goto VerdanturfMeadow_EventScript_TakeCareOfAudino
# 29 "data/maps/VerdanturfMeadow/scripts.pory"
	end
# 30 "data/maps/VerdanturfMeadow/scripts.pory"

# 31 "data/maps/VerdanturfMeadow/scripts.pory"
VerdanturfMeadow_EventScript_ReceiveAudinoPC::
# 32 "data/maps/VerdanturfMeadow/scripts.pory"
	call VerdanturfMeadow_EventScript_ReceivedAudinoFanfare
# 33 "data/maps/VerdanturfMeadow/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 34 "data/maps/VerdanturfMeadow/scripts.pory"
	compare VAR_RESULT, NO
# 35 "data/maps/VerdanturfMeadow/scripts.pory"
	goto_if_eq VerdanturfMeadow_EventScript_SendAudinoToPC
# 36 "data/maps/VerdanturfMeadow/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 37 "data/maps/VerdanturfMeadow/scripts.pory"
	goto VerdanturfMeadow_EventScript_SendAudinoToPC
# 38 "data/maps/VerdanturfMeadow/scripts.pory"
	end
# 39 "data/maps/VerdanturfMeadow/scripts.pory"

# 40 "data/maps/VerdanturfMeadow/scripts.pory"
VerdanturfMeadow_EventScript_SendAudinoToPC::
# 41 "data/maps/VerdanturfMeadow/scripts.pory"
	call Common_EventScript_TransferredToPC
# 42 "data/maps/VerdanturfMeadow/scripts.pory"
	goto VerdanturfMeadow_EventScript_TakeCareOfAudino
# 43 "data/maps/VerdanturfMeadow/scripts.pory"
	end
# 44 "data/maps/VerdanturfMeadow/scripts.pory"

# 45 "data/maps/VerdanturfMeadow/scripts.pory"
VerdanturfMeadow_EventScript_ReceivedAudinoFanfare::
# 46 "data/maps/VerdanturfMeadow/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 47 "data/maps/VerdanturfMeadow/scripts.pory"
	message VerdanturfMeadow_Text_PlayerReceivedAudino
# 48 "data/maps/VerdanturfMeadow/scripts.pory"
	waitmessage
# 49 "data/maps/VerdanturfMeadow/scripts.pory"
	waitfanfare
# 50 "data/maps/VerdanturfMeadow/scripts.pory"
	bufferspeciesname 0, SPECIES_AUDINO
# 51 "data/maps/VerdanturfMeadow/scripts.pory"
	return
# 52 "data/maps/VerdanturfMeadow/scripts.pory"

# 53 "data/maps/VerdanturfMeadow/scripts.pory"
VerdanturfMeadow_EventScript_TakeCareOfAudino::
# 54 "data/maps/VerdanturfMeadow/scripts.pory"
	msgbox VerdanturfMeadow_Text_TakeCareOfAudino, MSGBOX_DEFAULT
# 55 "data/maps/VerdanturfMeadow/scripts.pory"
	setflag FLAG_RECEIVED_AUDINO
# 56 "data/maps/VerdanturfMeadow/scripts.pory"
	release
# 57 "data/maps/VerdanturfMeadow/scripts.pory"
	end
# 58 "data/maps/VerdanturfMeadow/scripts.pory"

# 59 "data/maps/VerdanturfMeadow/scripts.pory"
VerdanturfMeadow_Text_PleaseTakePokemon:
# 60 "data/maps/VerdanturfMeadow/scripts.pory"
	.string "Do you know the Pokémon Audino?\p"
# 61 "data/maps/VerdanturfMeadow/scripts.pory"
	.string "I'm giving them away to promote\n"
# 62 "data/maps/VerdanturfMeadow/scripts.pory"
	.string "Audino welfare!\p"
# 63 "data/maps/VerdanturfMeadow/scripts.pory"
	.string "Some Trainers use Audino like punching\n"
# 64 "data/maps/VerdanturfMeadow/scripts.pory"
	.string "bags for their Pokémon, just to make\l"
# 65 "data/maps/VerdanturfMeadow/scripts.pory"
	.string "their team grow quickly.\p"
# 66 "data/maps/VerdanturfMeadow/scripts.pory"
	.string "This is not OK!\p"
# 67 "data/maps/VerdanturfMeadow/scripts.pory"
	.string "Please take this Audino to keep it safe\n"
# 68 "data/maps/VerdanturfMeadow/scripts.pory"
	.string "from EXP-mad Trainers!$"
# 69 "data/maps/VerdanturfMeadow/scripts.pory"

# 70 "data/maps/VerdanturfMeadow/scripts.pory"
VerdanturfMeadow_Text_PlayerReceivedAudino:
# 71 "data/maps/VerdanturfMeadow/scripts.pory"
	.string "{PLAYER} received Audino!$"
# 72 "data/maps/VerdanturfMeadow/scripts.pory"

# 73 "data/maps/VerdanturfMeadow/scripts.pory"
VerdanturfMeadow_Text_TakeCareOfAudino:
# 74 "data/maps/VerdanturfMeadow/scripts.pory"
	.string "Take good care of Audino!$"

VerdanturfMeadow_EventScript_Meganiumite_Battle::
# 78 "data/maps/VerdanturfMeadow/scripts.pory"
	lock
# 79 "data/maps/VerdanturfMeadow/scripts.pory"
	faceplayer
# 80 "data/maps/VerdanturfMeadow/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, VerdanturfMeadow_EventScript_Meganiumite_Battle_2
# 101 "data/maps/VerdanturfMeadow/scripts.pory"
	msgbox VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_6, MSGBOX_NPC
VerdanturfMeadow_EventScript_Meganiumite_Battle_1:
# 103 "data/maps/VerdanturfMeadow/scripts.pory"
	release
	end

VerdanturfMeadow_EventScript_Meganiumite_Battle_2:
# 82 "data/maps/VerdanturfMeadow/scripts.pory"
	checktrainerflag TRAINER_MEGANIUMITE_VERDANTURF_MEADOW
	goto_if 0, VerdanturfMeadow_EventScript_Meganiumite_Battle_5
# 97 "data/maps/VerdanturfMeadow/scripts.pory"
	msgbox VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_5, MSGBOX_NPC
	goto VerdanturfMeadow_EventScript_Meganiumite_Battle_1

VerdanturfMeadow_EventScript_Meganiumite_Battle_5:
# 83 "data/maps/VerdanturfMeadow/scripts.pory"
	msgbox VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_0, MSGBOX_YESNO
# 84 "data/maps/VerdanturfMeadow/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq VerdanturfMeadow_EventScript_Meganiumite_Battle_8
# 93 "data/maps/VerdanturfMeadow/scripts.pory"
	msgbox VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_4, MSGBOX_NPC
	goto VerdanturfMeadow_EventScript_Meganiumite_Battle_1

VerdanturfMeadow_EventScript_Meganiumite_Battle_8:
# 85 "data/maps/VerdanturfMeadow/scripts.pory"
	msgbox VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_1, MSGBOX_NPC
# 86 "data/maps/VerdanturfMeadow/scripts.pory"
	trainerbattle_no_intro TRAINER_MEGANIUMITE_VERDANTURF_MEADOW, VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_2
# 87 "data/maps/VerdanturfMeadow/scripts.pory"
	msgbox VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_3, MSGBOX_NPC
# 88 "data/maps/VerdanturfMeadow/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 89 "data/maps/VerdanturfMeadow/scripts.pory"
	giveitem ITEM_MEGANIUMITE, 1
# 90 "data/maps/VerdanturfMeadow/scripts.pory"
	waitmessage
	goto VerdanturfMeadow_EventScript_Meganiumite_Battle_1


VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_0:
# 83 "data/maps/VerdanturfMeadow/scripts.pory"
	.string "Ah, I see you've triumphed over Norman,\n"
	.string "quite the impressive feat at your age.\l"
	.string "How about we put your skills to the\l"
	.string "test in a friendly match? If you win,\l"
	.string "I'll reward you with this Meganiumite!$"

VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_1:
# 85 "data/maps/VerdanturfMeadow/scripts.pory"
	.string "Splendid, let's start!$"

VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_2:
# 86 "data/maps/VerdanturfMeadow/scripts.pory"
	.string "Your strength is truly awe-inspiring...$"

VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_3:
# 87 "data/maps/VerdanturfMeadow/scripts.pory"
	.string "You truly are strong. I hope to see your\n"
	.string "growth even further into the future.\l"
	.string "But for now, take this gift from me, and\l"
	.string "use it well.$"

VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_4:
# 93 "data/maps/VerdanturfMeadow/scripts.pory"
	.string "That's a bit disappointing. I hope you\n"
	.string "change your mind.$"

VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_5:
# 97 "data/maps/VerdanturfMeadow/scripts.pory"
	.string "I trust you'll find delight in the token\n"
	.string "I've bestowed upon you!$"

VerdanturfMeadow_EventScript_Meganiumite_Battle_Text_6:
# 101 "data/maps/VerdanturfMeadow/scripts.pory"
	.string "Greetings! Have you come to savor the\n"
	.string "fragrance of these blossoms? You\l"
	.string "strike me as someone with different\l"
	.string "interests. A Pokémon Trainer,\l"
	.string "perchance? Well, here's a proposition\l"
	.string "for you: how about dropping by after\l"
	.string "exploring Petalburg? I may just have a\l"
	.string "little something that piques your\l"
	.string "curiosity.$"
