# 1 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 2 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
.set LOCALID_FOSSIL_SCIENTIST, 5
# 3 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 4 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_MapScripts:: @ 8211857
# 5 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_OnTransition
# 6 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.byte 0
# 7 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 8 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_OnTransition: @ 821185D
# 9 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
# 10 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 11 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 12 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 13 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_SetFossilReady:: @ 8211869
# 14 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
# 15 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 16 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 17 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist:: @ 821186F
# 18 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 19 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 20 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
# 21 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 22 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon, MSGBOX_DEFAULT
# 23 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 24 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 25 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 26 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_BallScientist:: @ 8211886
# 27 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 28 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 29 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
# 30 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 31 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls
# 32 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls, MSGBOX_DEFAULT
# 33 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 34 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 35 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 36 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls:: @ 82118A6
# 37 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls, MSGBOX_DEFAULT
# 38 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 39 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 40 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 41 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_PokenavScientist:: @ 82118B0
# 42 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 43 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 44 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
# 45 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 46 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_HasPokenav
# 47 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_IMadePokenav, MSGBOX_DEFAULT
# 48 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 49 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 50 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 51 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_HasPokenav:: @ 82118D0
# 52 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav, MSGBOX_DEFAULT
# 53 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 54 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 55 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 56 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist:: @ 82118DA
# 57 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 58 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 59 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
# 60 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 61 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams, MSGBOX_DEFAULT
# 62 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 63 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 64 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 65 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FossilScientist:: @ 82118F1
# 66 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 67 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 68 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_FOSSIL_RESURRECTION_STATE, 2
# 69 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FossilMonReady
# 70 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
# 71 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_StillRegenerating
# 72 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
# 73 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	specialvar VAR_RESULT, DoesPlayerHaveFossil
# 74 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, TRUE
# 75 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoticeFossil
# 76 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 77 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 78 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	
# 79 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_NoticeFossil::
# 80 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 81 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playse SE_PIN
# 82 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
# 83 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 84 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
# 85 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 86 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
# 87 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NO
# 88 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
# 89 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilsPickOne, MSGBOX_DEFAULT
# 90 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 91 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	special Bag_ChooseItem
# 92 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitstate
# 93 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	specialvar VAR_RESULT, IsItemFossil
# 94 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, FALSE
# 95 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ThatsNotAFossil
# 96 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	special FossilToSpecies
# 97 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname 0, VAR_ITEM_ID
# 98 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 99 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem VAR_ITEM_ID
# 100 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
# 101 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	copyvar VAR_WHICH_FOSSIL_REVIVED, VAR_ITEM_ID
# 102 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 103 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 104 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 105 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil:: @ 82119EF
# 106 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_DEFAULT
# 107 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 108 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 109 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 110 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_StillRegenerating:: @ 82119F9
# 111 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
# 112 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 113 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 114 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 115 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ThatsNotAFossil::
# 116 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_ThatsNotAFossil, MSGBOX_DEFAULT
# 117 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 118 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 119 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 120 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
@ VAR_0x8006 is Pokemon species to restore
# 121 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
@ VAR_0x8008 is the fossil that was chosen for restoration
# 122 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FossilMonReady::
# 123 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	copyvar VAR_0x8008, VAR_WHICH_FOSSIL_REVIVED
# 124 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	special FossilToSpecies
# 125 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname 1, VAR_0x8006
# 126 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 127 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_0x8006
# 128 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	special GetStaticEncounterLevel
# 129 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon VAR_0x8006, VAR_0x800A, ITEM_NONE
# 130 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, 0
# 131 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilParty
# 132 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, 1
# 133 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilPC
# 134 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 135 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 136 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 137 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilParty:: @ 8211A6E
# 138 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedFossilFanfare
# 139 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 140 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NO
# 141 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FinishReceivingFossil
# 142 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 143 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 144 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingFossil
# 145 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 146 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 147 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilPC:: @ 8211A96
# 148 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedFossilFanfare
# 149 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 150 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NO
# 151 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_TransferFossilToPC
# 152 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 153 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_TransferFossilToPC
# 154 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 155 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 156 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TransferFossilToPC:: @ 8211AB9
# 157 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 158 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingFossil
# 159 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 160 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 161 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceivedFossilFanfare:: @ 8211AC4
# 162 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname 1, VAR_0x8006
# 163 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 164 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
# 165 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 166 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitfanfare
# 167 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname 0, VAR_0x8006
# 168 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 169 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 170 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FinishReceivingFossil:: @ 8211AD7
# 171 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 172 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 173 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 174 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 175 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 176 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist:: @ 8211BCF
# 177 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 178 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 179 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
# 180 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 181 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RUSTBORO_CITY_STATE, 7
# 182 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_ge RustboroCity_DevonCorp_2F_EventScript_WorkOnNext
# 183 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature, MSGBOX_DEFAULT
# 184 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 185 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 186 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 187 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_WorkOnNext:: @ 8211BF1
# 188 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
# 189 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 190 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 191 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 192 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon: @ 8211BFB
# 193 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "We're developing a device for talking\n"
# 194 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "with Pokémon.\p"
# 195 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But we haven't had much success…$"
# 196 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 197 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls: @ 8211C50
# 198 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm developing new kinds of\n"
# 199 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Poké Balls…\p"
# 200 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But I haven't made much headway…$"
# 201 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 202 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls: @ 8211C99
# 203 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "We finally made new kinds of\n"
# 204 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Poké Balls!\p"
# 205 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The Repeat Ball makes it easier to\n"
# 206 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "catch Pokémon you've caught before.\p"
# 207 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The Timer Ball gets better at catching\n"
# 208 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Pokémon the longer a battle runs.\p"
# 209 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Both are proudly developed by\n"
# 210 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the Devon Corporation.\p"
# 211 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Please give them a try!$"
# 212 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 213 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_IMadePokenav: @ 8211D9F
# 214 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I made the PokéNav!\p"
# 215 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "As an engineer, I feel blessed to have\n"
# 216 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "made something so great!$"
# 217 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 218 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav: @ 8211DF3
# 219 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, wow!\n"
# 220 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "That's a PokéNav!\p"
# 221 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "It came about as a result of our\n"
# 222 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "President's desire to learn about\l"
# 223 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the feelings of Pokémon.\p"
# 224 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like me to describe its\n"
# 225 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "features in detail?\p"
# 226 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "No, no. I think you'll find out just by\n"
# 227 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "trying the PokéNav out.$"
# 228 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 229 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams: @ 8211EE0
# 230 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm trying to develop a device that\n"
# 231 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "visually reproduces the dreams of\l"
# 232 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Pokémon…\p"
# 233 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it's not going well.$"
# 234 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 235 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils: @ 8211F48
# 236 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I've been trying to develop a device\n"
# 237 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "that resurrects Pokémon from fossils…\p"
# 238 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "And, it's working!$"
# 239 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 240 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife: @ 8211FA6
# 241 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Wait! That thing you have there…\n"
# 242 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Is that a Pokémon fossil?\p"
# 243 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like to bring that Pokémon\n"
# 244 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "back to life?\p"
# 245 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I can with my newly developed\n"
# 246 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Fossil Regenerator.$"
# 247 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 248 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_OhIsThatSo: @ 8212046
# 249 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, is that so?\p"
# 250 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Devon's technological expertise\n"
# 251 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "is outstanding, I tell you.$"
# 252 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 253 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_FossilsPickOne: @ 8212092
# 254 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Which fossil would you like to\n"
# 255 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "regenerate?$"
# 256 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 257 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher: @ 8212153
# 258 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Excellent!\n"
# 259 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Let's do this right away.\p"
# 260 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{PLAYER} handed the {STR_VAR_1} to\n"
# 261 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the Devon Researcher.$"
# 262 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 263 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime: @ 82121A2
# 264 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The Fossil Regenerator, which I made,\n"
# 265 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "is incredible.\p"
# 266 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it has one drawback--it takes\n"
# 267 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "a long time to work.\p"
# 268 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "So, uh… How about you go for a stroll\n"
# 269 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "and look around for a while?$"
# 270 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 271 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife: @ 8212251
# 272 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Thanks for waiting!\p"
# 273 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Your fossilized Pokémon has been\n"
# 274 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "brought back to life!\p"
# 275 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The fossil was an ancient Pokémon.\n"
# 276 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{STR_VAR_2}, it was!$"
# 277 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 278 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher: @ 82122CB
# 279 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{PLAYER} received {STR_VAR_2} from\n"
# 280 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the Devon Researcher.$"
# 281 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 282 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
@ Unused
# 283 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_TooManyPokemon: @ 82122F5
# 284 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Uh-oh, you've got too many Pokémon.\n"
# 285 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "You have no room for this one.$"
# 286 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 287 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature: @ 8212338
# 288 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm trying to develop a new feature\n"
# 289 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "for the PokéNav…\p"
# 290 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it's not going well.$"
# 291 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 292 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext: @ 8212386
# 293 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Well, now what shall I work on\n"
# 294 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "developing next?\p"
# 295 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Our company allows us to make our\n"
# 296 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "inspirations into reality.\p"
# 297 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "One couldn't ask for a better\n"
# 298 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "environment as an engineer.$"
# 299 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 300 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_ThatsNotAFossil:
# 301 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Come now, that's not a fossil!$"
