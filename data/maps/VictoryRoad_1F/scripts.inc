.set LOCALID_WALLY_ENTRANCE, 4

VictoryRoad_1F_MapScripts:: @ 8235D7A
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition: @ 8235D80
	compare VAR_VICTORY_ROAD_1F_STATE, 1
	call_if_eq VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	compare VAR_VICTORY_ROAD_1F_STATE, 2
	call_if_eq VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1:: @ 8235D97
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 2, 24
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2:: @ 8235DA3
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 3, 24
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1:: @ 8235DAF
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2:: @ 8235DC8
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle:: @ 8235DE1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_WALLY_ENTRANCE
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1: @ 8235E15
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2: @ 8235E21
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally:: @ 8235E2C
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered 
VictoryRoad_1F_EventScript_ExitWally:: @ 8235E35
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally:: @ 8235E5C
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar:: @ 8235E73
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert:: @ 8235E8A
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope:: @ 8235EA1
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy:: @ 8235EB8
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn:: @ 8235ECF
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore: @ 8235EE6
	.string "Wally: Hi! {PLAYER}!\p"
	.string "I bet you're surprised to see me here!\p"
	.string "I made it all the way here, and it's\n"
	.string "all thanks to you!\p"
	.string "{PLAYER}, losing to you that time\n"
	.string "made me stronger!\p"
	.string "But I'm not going to lose anymore!\p"
	.string "I'm going to win! For the Pokémon who\n"
	.string "gave me courage and strength!\p"
	.string "Okay… Here I come!$"

VictoryRoad_1F_Text_WallyEntranceDefeat: @ 8235FFC
	.string "Wow!\n"
	.string "{PLAYER}, you are strong, after all!$"

VictoryRoad_1F_Text_WallyPostEntranceBattle: @ 8236020
	.string "Wally: I couldn't beat you today,\n"
	.string "{PLAYER}, but one of these days, I'll\l"
	.string "catch up to you!$"

VictoryRoad_1F_Text_WallyIntro: @ 8236073
	.string "Wally: Hi! {PLAYER}!\p"
	.string "I've gotten stronger since that last\n"
	.string "time! I wanted to show you, {PLAYER}!\p"
	.string "Okay… Here I come!$"

VictoryRoad_1F_Text_WallyDefeat: @ 82360DA
	.string "Wow!\n"
	.string "{PLAYER}, you are strong, after all!$"

VictoryRoad_1F_Text_WallyPostBattle: @ 82360FE
	.string "Wally: I couldn't beat you this time,\n"
	.string "too… But one of these days, {PLAYER},\l"
	.string "I'm going to catch up to you…\p"
	.string "And challenge the Pokémon League!$"

VictoryRoad_1F_Text_EdgarIntro: @ 8236184
	.string "I've made it this far a couple times,\n"
	.string "but the last stretch is so long…$"

VictoryRoad_1F_Text_EdgarDefeat: @ 82361CB
	.string "My dream ends here again…$"

VictoryRoad_1F_Text_EdgarPostBattle: @ 82361E5
	.string "You've made it this far. Keep the\n"
	.string "momentum going and become the\l"
	.string "Champion! If anyone can, it's you!$"

VictoryRoad_1F_Text_AlbertIntro: @ 8236248
	.string "I didn't come all this way to lose now.\n"
	.string "That possibility doesn't exist!$"

VictoryRoad_1F_Text_AlbertDefeat: @ 8236290
	.string "Impossible…\n"
	.string "I lost?$"

VictoryRoad_1F_Text_AlbertPostBattle: @ 82362A4
	.string "I lost here…\p"
	.string "That means I lack the qualifications\n"
	.string "to become the Champion…$"

VictoryRoad_1F_Text_HopeIntro: @ 82362EE
	.string "This seemingly infinite and harsh road\n"
	.string "lives up to its name of Victory.$"

VictoryRoad_1F_Text_HopeDefeat: @ 8236336
	.string "Your battle style is fantastic…$"

VictoryRoad_1F_Text_HopePostBattle: @ 8236356
	.string "You seem to have the potential for\n"
	.string "becoming the Champion.$"

VictoryRoad_1F_Text_QuincyIntro: @ 8236390
	.string "What is the Victory Road?\n"
	.string "I'll tell you if you win!$"

VictoryRoad_1F_Text_QuincyDefeat: @ 82363C4
	.string "Okay!\n"
	.string "Well done!$"

VictoryRoad_1F_Text_QuincyPostBattle: @ 82363D5
	.string "Getting through here safely--that's\n"
	.string "the final test for any Trainer aiming\l"
	.string "to become the Pokémon Champion.\p"
	.string "That's why it's called the Victory\n"
	.string "Road.$"

VictoryRoad_1F_Text_KatelynnIntro: @ 8236468
	.string "I have nothing to say to anyone\n"
	.string "that's come this far. Come on!$"

VictoryRoad_1F_Text_KatelynnDefeat: @ 82364A7
	.string "This is a disgrace…$"

VictoryRoad_1F_Text_KatelynnPostBattle: @ 82364BB
	.string "Humph, go right on ahead.\n"
	.string "See if I care.$"

VictoryRoad_1F_EventScript_LegendaryNPC::
	lock
	faceplayer
	msgbox VictoryRoad_1F_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq VictoryRoad_1F_EventScript_LegendaryNPC_2
	msgbox VictoryRoad_1F_EventScript_LegendaryNPC_Text_4
VictoryRoad_1F_EventScript_LegendaryNPC_1:
	release
	end

VictoryRoad_1F_EventScript_LegendaryNPC_2:
	goto_if_unset FLAG_SYS_GAME_CLEAR, VictoryRoad_1F_EventScript_LegendaryNPC_5
	checktrainerflag TRAINER_WALLY_VR_1
	goto_if 1, VictoryRoad_1F_EventScript_LegendaryNPC_11
VictoryRoad_1F_EventScript_LegendaryNPC_9:
	msgbox VictoryRoad_1F_EventScript_LegendaryNPC_Text_3
	goto VictoryRoad_1F_EventScript_LegendaryNPC_1

VictoryRoad_1F_EventScript_LegendaryNPC_5:
	msgbox VictoryRoad_1F_EventScript_LegendaryNPC_Text_1
	goto VictoryRoad_1F_EventScript_LegendaryNPC_1

VictoryRoad_1F_EventScript_LegendaryNPC_8:
	msgbox VictoryRoad_1F_EventScript_LegendaryNPC_Text_2
	goto VictoryRoad_1F_EventScript_LegendaryNPC_1

VictoryRoad_1F_EventScript_LegendaryNPC_10:
	checktrainerflag TRAINER_ALBERT
	goto_if 1, VictoryRoad_1F_EventScript_LegendaryNPC_15
	goto VictoryRoad_1F_EventScript_LegendaryNPC_9

VictoryRoad_1F_EventScript_LegendaryNPC_11:
	checktrainerflag TRAINER_EDGAR
	goto_if 1, VictoryRoad_1F_EventScript_LegendaryNPC_10
	goto VictoryRoad_1F_EventScript_LegendaryNPC_9

VictoryRoad_1F_EventScript_LegendaryNPC_14:
	checktrainerflag TRAINER_QUINCY
	goto_if 1, VictoryRoad_1F_EventScript_LegendaryNPC_18
	goto VictoryRoad_1F_EventScript_LegendaryNPC_9

VictoryRoad_1F_EventScript_LegendaryNPC_15:
	checktrainerflag TRAINER_HOPE
	goto_if 1, VictoryRoad_1F_EventScript_LegendaryNPC_14
	goto VictoryRoad_1F_EventScript_LegendaryNPC_9

VictoryRoad_1F_EventScript_LegendaryNPC_18:
	checktrainerflag TRAINER_KATELYNN
	goto_if 1, VictoryRoad_1F_EventScript_LegendaryNPC_8
	goto VictoryRoad_1F_EventScript_LegendaryNPC_9


VictoryRoad_1F_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_E4, VictoryRoad_1F_EventScript_Calvin_Text_0, VictoryRoad_1F_EventScript_Calvin_Text_1
	msgbox VictoryRoad_1F_EventScript_Calvin_Text_2, MSGBOX_NPC
	settrainerflag TRAINER_CALVIN_E4
	release
	end


VictoryRoad_1F_EventScript_LegendaryNPC_Text_0:
	.string "Sage intern: Why did I choose to get an\n"
	.string "internship at the Academy of Pokémon\l"
	.string "sages? I could've become an\l"
	.string "investment banker like my brother, or\l"
	.string "an insurance lawyer like my sister...\l"
	.string "but no! I chose an academic\l"
	.string "profession, and now I'm stuck here for\l"
	.string "FREE all day long!\p"
	.string "Oh, sorry I didn't notice you... wait, I\n"
	.string "forgot my script... did I have any?\l"
	.string "Whatever. Just choose yes in the\l"
	.string "message box. Please. They didn't code a\l"
	.string "response for 'no' and the game's gonna\l"
	.string "crash.$"

VictoryRoad_1F_EventScript_LegendaryNPC_Text_1:
	.string "My colleagues might have bombarded you\n"
	.string "with information about their route's\l"
	.string "legendaries, but I'm different!\p"
	.string "Those residing in this dank cave... just\n"
	.string "happened to randomly like it, so they\l"
	.string "stayed. I tried asking my colleagues\l"
	.string "about it, but they ignored my emails...\l"
	.string "shame on them!\p"
	.string "Two are poisonous dragons, one's a\n"
	.string "football player, and they've got\l"
	.string "nothing to do with each other!\p"
	.string "You seem like a smart fella, so no\n"
	.string "beating around the bush this time:\l"
	.string "become champion, beat every trainer,\l"
	.string "talk to me, use your DexNav, and\l"
	.string "pronto! Three legendaries for you!$"

VictoryRoad_1F_EventScript_LegendaryNPC_Text_2:
	.string "Poipole, Naganadel and Zeraora... done,\n"
	.string "your DexNav should show their location\l"
	.string "now. Good luck champ, let's leave this\l"
	.string "place!$"

VictoryRoad_1F_EventScript_LegendaryNPC_Text_3:
	.string "Hey lad! Congrats on becoming champion,\n"
	.string "but as you might have guessed, your\l"
	.string "work's not done! It's not my fault tho!\l"
	.string "Rules say so (I despise them too!)! So\l"
	.string "beat every trainer, then come back\l"
	.string "here so we can leave this cave behind\l"
	.string "us, ok?$"

VictoryRoad_1F_EventScript_LegendaryNPC_Text_4:
	.string "ERROR AT ADDRESS 0X0009B1F\p"
	.string "CORRUPTION WARNING ADDRESS\n"
	.string "0X0009DA32\p"
	.string "SAV\l"
	.string "ING DAT\p"
	.string "A DO N OT TURN Y\p"
	.string "o\p"
	.string "u\p"
	.string "r\p"
	.string "\p"
	.string "SAVE DATA S++++++UC\p"
	.string "0x000E34F ESFULLY DEL\p"
	.string "ETED\p"
	.string "Come on. Did I really fool you. Admit it.\n"
	.string "I did, if only for a split second. You're\l"
	.string "lucky I can't change music through\l"
	.string "Poryscript... that would've been funny.\l"
	.string "Jokes aside, you have to explain to me\l"
	.string "why you clicked 'no' when I EXPLICITLY\l"
	.string "told you it would crash the game. Come\l"
	.string "on. You're an adult! Why would you crash\l"
	.string "the game and make all the NPC's here\l"
	.string "suffer? That's sick of you!\p"
	.string "Imagine if I came into your house and\n"
	.string "broke all the windows because you put\l"
	.string "up a sing saying 'please don't break my\l"
	.string "windows!'. I imagine you'd be pissed\l"
	.string "off. I would be too! But you did anyway.\p"
	.string "Imagine if you were a streamer playing\n"
	.string "the hack and this message stalled out\l"
	.string "your 'ultra hardcore no restarts no\l"
	.string "breathing blind deaf colourblind no\l"
	.string "hands no setup no terrain no weather\l"
	.string "bridge-wed-egg-soul locke run.\p"
	.string "Would you keep mashing A hoping this\n"
	.string "dialogue ends? Or would you rather\l"
	.string "reload the save and just answer 'YES'\l"
	.string "to my question?\p"
	.string "There's a concept in economics called\n"
	.string "'sunk cost'. Yes, it's releveant.\l"
	.string "Basically, sunk costs are those which\l"
	.string "have already been incurred and which\l"
	.string "are unrecoverable. The time you spent\l"
	.string "reading this is a sunk cost, for\l"
	.string "example.\p"
	.string "Now, would it make sense for you to end\n"
	.string "this dialogue now by reloading your\l"
	.string "save, and stop incurring sunk costs, or\l"
	.string "would it be better to keep on reading?\p"
	.string "That's an interesting question, and it\n"
	.string "all depends on when you last saved, if\l"
	.string "you're enjoying this dialogue, your\l"
	.string "attention level, the amount of speedup\l"
	.string "your emulator is playing at, et cetera.\p"
	.string "(un)fortunately for you, my heated SPA\n"
	.string "has reached 37 degrees Celsius, so it's\l"
	.string "time for me to take a hot bath. I would\l"
	.string "keep on talking otherwise.. Consider\l"
	.string "yourself lucky, kid! - Luca$"

VictoryRoad_1F_EventScript_Calvin_Text_0:
	.string "Hehe! I'm almost at the Pokémon League.\n"
	.string "Some say I'm not ready. Look at me now,\l"
	.string "I'm Calvin, and I'm a wall before the\l"
	.string "League! Ready for a real challenge?$"

VictoryRoad_1F_EventScript_Calvin_Text_1:
	.string "Whoa, you're tough!$"

VictoryRoad_1F_EventScript_Calvin_Text_2:
	.string "Hey, give the E4 a run for their money,\n"
	.string "will ya? Good luck!$"
