@ gSpecialvar_0x8008: HM move being used
@ gSpecialvar_0x8009: if 0, use player's mon. Otherwise, use Gym Leader's mon

@ Interact with cuttable tree
EventScript_CutTree:: @ 82906BB
	lockall
	goto_if_unset FLAG_BADGE01_GET, EventScript_CheckTreeCantCut
	checkpartymove MOVE_CUT
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_AnorithCut
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick 0, VAR_RESULT
	buffermovename 1, MOVE_CUT
	msgbox Text_WantToCut, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelCut
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

EventScript_AnorithCut::
	compare VAR_RUSTBORO_CITY_STATE, 9
	goto_if_lt EventScript_CheckTreeCantCut
	setvar VAR_0x8004, SPECIES_ANORITH
	setvar VAR_0x8008, MOVE_CUT
	setvar VAR_0x8009, 1
	bufferspeciesname 0, VAR_0x8004	
	buffermovename 1, VAR_0x8008
	msgbox Text_AnorithToCut, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelCut
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

@ Use cut from party menu
EventScript_UseCut:: @ 8290705
	lockall
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

EventScript_CutTreeDown:: @ 8290710
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	random 3
	switch VAR_RESULT
	case 0, EventScript_CutTreeEncounter
	case 1, EventScript_CutTreeItem
	case 2, EventScript_CancelCut
	releaseall
	end

EventScript_CutTreeEncounter::
	compare VAR_REPEL_STEP_COUNT, 0
	goto_if_gt EventScript_CancelCut
	special RockSmashWildEncounter
	compare VAR_RESULT, 0
	goto_if_eq EventScript_CancelCut
	waitstate
	releaseall
	end

EventScript_CutTreeItem::
	random 14
	switch VAR_RESULT
	case 0, EventScript_CutTreeMiracleSeed
	case 1, EventScript_CutTreeCharcoal
	case 2, EventScript_CutTreeMentalHerb
	case 3, EventScript_CutTreePowerHerb
	case 4, EventScript_CutTreeWhiteHerb
	case 5, EventScript_CutTreeRevivalHerb
	case 6, EventScript_CutTreeEnergyRoot
	case 7, EventScript_CutTreeTerrainSeed
	case 8, EventScript_CutTreeTinyMushroom
	case 9, EventScript_CutTreeBigMushroom
	case 10, EventScript_CutTreeTypeBerry
	case 11, EventScript_CutTreeEVBerry
	case 12, EventScript_CutTreeStick
	case 13, EventScript_CutTreeBigRoot
	releaseall
	end

EventScript_CutTreeMiracleSeed::
	finditem ITEM_MIRACLE_SEED
	releaseall
	end

EventScript_CutTreeCharcoal::
	finditem ITEM_CHARCOAL
	releaseall
	end

EventScript_CutTreeMentalHerb::
	finditem ITEM_MENTAL_HERB
	releaseall
	end
	
EventScript_CutTreePowerHerb::
	finditem ITEM_POWER_HERB
	releaseall
	end
	
EventScript_CutTreeWhiteHerb::
	finditem ITEM_WHITE_HERB
	releaseall
	end
	
EventScript_CutTreeRevivalHerb::
	finditem ITEM_REVIVAL_HERB
	releaseall
	end
	
EventScript_CutTreeEnergyRoot::
	finditem ITEM_ENERGY_ROOT
	releaseall
	end
	
EventScript_CutTreeTerrainSeed::
	random 4
	addvar VAR_RESULT, ITEM_ELECTRIC_SEED
	finditem VAR_RESULT
	releaseall
	end
	
EventScript_CutTreeTinyMushroom::
	finditem ITEM_TINY_MUSHROOM
	releaseall
	end
	
EventScript_CutTreeBigMushroom::
	finditem ITEM_BIG_MUSHROOM
	releaseall
	end
	
EventScript_CutTreeTypeBerry::
	random 18
	addvar VAR_RESULT, ITEM_OCCA_BERRY
	finditem VAR_RESULT
	releaseall
	end

EventScript_CutTreeEVBerry::
	random 6
	addvar VAR_RESULT, ITEM_POMEG_BERRY
	finditem VAR_RESULT
	releaseall
	end

EventScript_CutTreeStick::
	finditem ITEM_LEEK
	releaseall
	end

EventScript_CutTreeBigRoot::
	finditem ITEM_BIG_ROOT
	releaseall
	end

Movement_CutTreeDown: @ 829071F
	cut_tree
	step_end

EventScript_CheckTreeCantCut:: @ 8290721
	msgbox Text_CantCut, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelCut:: @ 829072B
	closemessage
	releaseall
	end

Text_WantToCut: @ 829072E
	.string "This tree looks like it can be Cut down!\n"
	.string "Would you like to Cut it?$"

Text_AnorithToCut:
	.string "This tree looks like it can be Cut down!\n"
	.string "Call Roxanne's Anorith to Cut it?$"

Text_MonUsedFieldMove: @ 8290771
	.string "{STR_VAR_1} used {STR_VAR_2}!$"

Text_CantCut: @ 829077D
	.string "This tree looks like it can be\n"
	.string "Cut down!$"

@ Interact with smashable rock
EventScript_RockSmash:: @ 82907A6
	lockall
	goto_if_unset FLAG_BADGE03_GET, EventScript_CantSmashRock
	checkpartymove MOVE_ROCK_SMASH
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_RaichuSmash
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick 0, VAR_RESULT
	buffermovename 1, MOVE_ROCK_SMASH
	msgbox Text_WantToSmash, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelSmash
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

EventScript_RaichuSmash::
	setvar VAR_0x8004, SPECIES_RAICHU_ALOLAN
	setvar VAR_0x8008, MOVE_ROCK_SMASH
	setvar VAR_0x8009, 1
	bufferspeciesname 0, VAR_0x8004	
	buffermovename 1, VAR_0x8008
	msgbox Text_RaichuSmash, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelSmash
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

@ Use rock smash from party menu
EventScript_UseRockSmash:: @ 82907F0
	lockall
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

EventScript_SmashRock::
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_EndSmash
	random 10
	switch VAR_RESULT
	case 0, EventScript_RockSmashFossil
	compare VAR_REPEL_STEP_COUNT, 0
	goto_if_gt EventScript_EndSmash
	special RockSmashWildEncounter
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_EndSmash
	waitstate
	releaseall
	end

EventScript_RockSmashPearl::
	finditem ITEM_PEARL
	releaseall
	end

EventScript_RockSmashBigPearl::
	finditem ITEM_BIG_PEARL
	releaseall
	end

EventScript_RockSmashEther::
	finditem ITEM_ETHER
	releaseall
	end
	
EventScript_RockSmashMaxEther::
	finditem ITEM_MAX_ETHER
	releaseall
	end
	
EventScript_RockSmashSoftSand::
	finditem ITEM_SOFT_SAND
	releaseall
	end
	
EventScript_RockSmashHardStone::
	finditem ITEM_HARD_STONE
	releaseall
	end
	
EventScript_RockSmashRevive::
	finditem ITEM_REVIVE
	releaseall
	end
	
EventScript_RockSmashMaxRevive::
	finditem ITEM_MAX_REVIVE
	releaseall
	end
	
EventScript_RockSmashStarPiece::
	finditem ITEM_STAR_PIECE
	releaseall
	end
	
EventScript_RockSmashGem::
	random 19
	addvar VAR_RESULT, ITEM_BUG_GEM
	finditem VAR_RESULT
	releaseall
	end
	
EventScript_RockSmashFossil::
	random 12
	compare VAR_RESULT, 11
	goto_if_eq EventScript_RockSmashOldAmber
	addvar VAR_RESULT, ITEM_ARMOR_FOSSIL
	finditem VAR_RESULT
	releaseall
	end

EventScript_RockSmashBottleCap::
	finditem ITEM_BOTTLE_CAP
	releaseall
	end

EventScript_RockSmashOldAmber::
	finditem ITEM_OLD_AMBER
	releaseall
	end

EventScript_EndSmash::
	releaseall
	end

Movement_SmashRock::
	rock_smash_break
	step_end

EventScript_CantSmashRock:: @ 829082D
	msgbox Text_CantSmash, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelSmash:: @ 8290837
	closemessage
	releaseall
	end

Text_WantToSmash: @ 829083A
	.string "This rock appears to be breakable.\n"
	.string "Would you like to use Rock Smash?$"

Text_RaichuSmash:
	.string "This rock appears to be breakable.\n"
	.string "Call Wattson's Raichu to smash it?$"

Text_CantSmash: @ 829087F
	.string "It's a rugged rock, but a Pokémon\n"
	.string "may be able to smash it.$"

EventScript_StrengthBoulder:: @ 82908BA
	lockall
	goto_if_unset FLAG_BADGE04_GET, EventScript_CantStrength
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
	checkpartymove MOVE_STRENGTH
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_ArcanineStrength
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToStrength, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelStrength
	closemessage
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_ArcanineStrength::
	setvar VAR_0x8004, SPECIES_ARCANINE
	setvar VAR_0x8008, MOVE_STRENGTH
	setvar VAR_0x8009, 1
	msgbox Text_ArcanineStrength, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelStrength
	closemessage
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateArcanineStrength
	end

EventScript_UseStrength:: @ 82908FD
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_ActivateStrength:: @ 8290908
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_ActivateArcanineStrength::
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_ArcanineUsedStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CantStrength:: @ 8290915
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder:: @ 829091F
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelStrength:: @ 8290929
	closemessage
	releaseall
	end

Text_WantToStrength: @ 829092C
	.string "It's a big boulder, but a Pokémon\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to use Strength?$"

Text_ArcanineStrength: @ 829092C
	.string "It's a big boulder, but a Pokémon\n"
	.string "may be able to push it aside.\p"
	.string "Call Flannery's Arcanine to push it?$"

Text_MonUsedStrength: @ 829098C
	.string "{STR_VAR_1} used Strength!\p"
	.string "{STR_VAR_1}'s Strength made it\n"
	.string "possible to move boulders around!$"

Text_ArcanineUsedStrength:
	.string "Arcanine used Strength!\p"
	.string "Arcanine 's Strength made it\n"
	.string "possible to move boulders around!$"

Text_CantStrength: @ 82909D6
	.string "It's a big boulder, but a Pokémon\n"
	.string "may be able to push it aside.$"

Text_StrengthActivated: @ 8290A16
	.string "Strength made it possible to move\n"
	.string "boulders around.$"

EventScript_UseWaterfall:: @ 8290A49
	lockall
	goto_if_unset FLAG_BADGE08_GET, EventScript_CannotUseWaterfall
	checkpartymove MOVE_WATERFALL
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_KabutopsWaterfall
	bufferpartymonnick 0, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_EndWaterfall
	msgbox Text_MonUsedWaterfall, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_WATERFALL
	goto EventScript_EndWaterfall

EventScript_CannotUseWaterfall:: @ 8290A83
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT
	releaseall
	end

EventScript_KabutopsWaterfall::
	setvar VAR_0x8004, SPECIES_KABUTOPS
	setvar VAR_0x8008, MOVE_WATERFALL
	setvar VAR_0x8009, 1
	bufferspeciesname 0, VAR_0x8004	
	buffermovename 1, VAR_0x8008
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_KabutopsWaterfall, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_EndWaterfall
	msgbox Text_MonUsedWaterfall, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_WATERFALL
	goto EventScript_EndWaterfall

EventScript_EndWaterfall:: @ 8290A8C
	releaseall
	end

Text_CantWaterfall: @ 8290A8E
	.string "A wall of water is crashing down with\n"
	.string "a mighty roar.$"

Text_WantToWaterfall: @ 8290AC3
	.string "It's a large waterfall.\n"
	.string "Would you like to use Waterfall?$"

Text_KabutopsWaterfall:
	.string "It's a large waterfall.\n"
	.string "Call Juan's Kabutops to climb it?$"

Text_MonUsedWaterfall: @ 8290AFC
	.string "{STR_VAR_1} used Waterfall.$"

EventScript_UseDive:: @ 8290B0F
	lockall
	goto_if_unset FLAG_BADGE07_GET, EventScript_CantDive
	checkpartymove MOVE_DIVE
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_SlowbroDive
	bufferpartymonnick 0, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToDive, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_EndDive
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_SlowbroDive::
	setvar VAR_0x8004, SPECIES_SLOWBRO
	setvar VAR_0x8008, MOVE_DIVE
	setvar VAR_0x8009, 1
	bufferspeciesname 0, VAR_0x8004	
	buffermovename 1, VAR_0x8008
	msgbox Text_SlowbroDive, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_EndDive
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_CantDive:: @ 8290B4E
	msgbox Text_CantDive, MSGBOX_DEFAULT
	releaseall
	end

EventScript_EndDive:: @ 8290B58
	releaseall
	end

EventScript_UseDiveUnderwater:: @ 8290B5A
	lockall
	checkpartymove MOVE_DIVE
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_SlowbroSurface
	bufferpartymonnick 0, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToSurface, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_EndSurface
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_SlowbroSurface::
	setvar VAR_0x8004, SPECIES_SLOWBRO
	setvar VAR_0x8008, MOVE_DIVE
	setvar VAR_0x8009, 1
	bufferspeciesname 0, VAR_0x8004
	buffermovename 1, VAR_0x8008
	msgbox Text_WantToSurface, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_EndSurface
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_EndSurface:: @ 8290BA8
	releaseall
	end

Text_CantDive: @ 8290BAA
	.string "The sea is deep here. A Pokémon\n"
	.string "may be able to go underwater.$"

Text_WantToDive: @ 8290BE8
	.string "The sea is deep here.\n"
	.string "Would you like to use Dive?$"

Text_SlowbroDive:
	.string "The sea is deep here.\n"
	.string "Call Tate & Liza's Slowbro to Dive?$"

Text_MonUsedDive: @ 8290C1A
	.string "{STR_VAR_1} used Dive.$"

Text_CantSurface: @ 8290C28
	.string "Light is filtering down from above.\n"
	.string "A Pokémon may be able to surface.$"

Text_WantToSurface: @ 8290C6E
	.string "Light is filtering down from above.\n"
	.string "Would you like to use Dive?$"

EventScript_FailSweetScent:: @ 8290CAE
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end

Text_FailSweetScent: @ 8290CB7
	.string "Looks like there's nothing here…$"
    
    
EventScript_DisableAutoRun::
    msgbox AutoRunDisabled MSGBOX_SIGN
    end
AutoRunDisabled:
    .string "Auto Run {COLOR RED}Disabled{COLOR DARK_GRAY}.$"
    
EventScript_EnableAutoRun::
    msgbox AutoRunEnabled MSGBOX_SIGN
    end
AutoRunEnabled:
    .string "Auto Run {COLOR GREEN}Enabled{COLOR DARK_GRAY}.$"
