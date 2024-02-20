EventScript_PkmnCenterNurseHasVial::
    giveBattleItems
    call EventScript_PkmnCenterNurse_HealPkmn
	release
    end

EventScript_PkmnCenterNurse_Goodbye::
    message gText_WeHopeToSeeYouAgain
    return

@ VAR_0x8004 is 1 when player has Gold Card; jumps are identical
    EventScript_PkmnCenterNurse_HealPkmn::
    copyvar VAR_POKE_VIAL_CHARGES, VAR_POKE_VIAL_MAX_CHARGES @ refill Poke Vial
    incrementgamestat GAME_STAT_USED_POKECENTER
    call EventScript_PkmnCenterNurse_TakeAndHealPkmn
    goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
    end

EventScript_PkmnCenterNurse_IllTakeYourPkmn::
    message gText_IllTakeYourPkmn
    return

EventScript_PkmnCenterNurse_IllTakeYourPkmn2::
    message gText_IllTakeYourPkmn2
    return

EventScript_PkmnCenterNurse_TakeAndHealPkmn::
    applymovement VAR_0x800B, Common_Movement_FaceLeft
    waitmovement 0
    dofieldeffect FLDEFF_POKECENTER_HEAL
    waitfieldeffect FLDEFF_POKECENTER_HEAL
    applymovement VAR_0x800B, Common_Movement_FaceDown
    waitmovement 0
    special HealPlayerParty
    return

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom::
    specialvar VAR_RESULT, PlayerNotAtTrainerHillEntrance
    compare VAR_RESULT, 0
    goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn
    specialvar VAR_RESULT, BufferUnionRoomPlayerName
    copyvar VAR_0x8008, VAR_RESULT
    compare VAR_0x8008, 0
    goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn
    compare VAR_0x8008, 1
    goto_if_eq EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
    end

@ VAR_0x8004 is 1 when player has Gold Card
EventScript_PkmnCenterNurse_ReturnPkmn::
    applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
    waitmovement 0
    return

EventScript_PkmnCenterNurse_ReturnPkmn2::
    message gText_ThankYouForWaiting
    waitmessage
    applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
    waitmovement 0
    message gText_WeHopeToSeeYouAgain2
    return

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom::
    goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_ReturnPkmn
    msgbox gText_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
    setflag FLAG_NURSE_UNION_ROOM_REMINDER
    message CableClub_Text_PlayerIsWaiting
    waitmessage
    applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
    waitmovement 0
    message gText_WeHopeToSeeYouAgain
    return

EventScript_PkmnCenterNurse_CheckPokerus::
    specialvar VAR_RESULT, IsPokerusInParty
    compare VAR_RESULT, TRUE
    goto_if_eq EventScript_PkmnCenterNurse_ExplainPokerus
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
    end

EventScript_PkmnCenterNurse_ExplainPokerus::
    message gText_PokerusExplanation
    setflag FLAG_POKERUS_EXPLAINED
    return

EventScript_PkmnCenterNurse_GoldCard::
    goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, EventScript_PkmnCenterNurse_AskForUsual
    setflag FLAG_NURSE_MENTIONS_GOLD_CARD
    msgbox gText_WelcomeCutShort, MSGBOX_DEFAULT
    playse SE_PIN
    applymovement VAR_0x800B, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement VAR_0x800B, Common_Movement_Delay48
    waitmovement 0
    msgbox gText_NoticesGoldCard, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq EventScript_PkmnCenterNurse_GoldCardHealPkmn
    message gText_WeHopeToSeeYouAgain2
    return

EventScript_PkmnCenterNurse_AskForUsual::
    msgbox gText_YouWantTheUsual, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq EventScript_PkmnCenterNurse_GoldCardHealPkmn
    message gText_WeHopeToSeeYouAgain2
    return

EventScript_PkmnCenterNurse_GoldCardHealPkmn::
    setvar VAR_0x8004, 1
    goto EventScript_PkmnCenterNurse_HealPkmn
    end

Movement_PkmnCenterNurse_Bow:
    nurse_joy_bow
    delay_4
    step_end

.macro check_and_add item:req, quantity:req
	checkitem \item, \quantity
	compare VAR_RESULT, TRUE
	call_if_ne check_and_add_\@_result
	goto check_and_add_\@_end
check_and_add_\@_result:
	additem \item, \quantity
	return
check_and_add_\@_end:
.endm

Give_all_TMHMs:
	check_and_add ITEM_TM01_FOCUS_PUNCH, 1
	check_and_add ITEM_TM02_DRAGON_CLAW, 1
	check_and_add ITEM_TM03_WATER_PULSE, 1
	check_and_add ITEM_TM04_CALM_MIND, 1
	check_and_add ITEM_TM05_ROAR, 1
	check_and_add ITEM_TM06_TOXIC, 1
	check_and_add ITEM_TM07_HAIL, 1
	check_and_add ITEM_TM08_BULK_UP, 1
	check_and_add ITEM_TM09_BULLET_SEED, 1
	check_and_add ITEM_TM10_HIDDEN_POWER, 1
	check_and_add ITEM_TM11_SUNNY_DAY, 1
	check_and_add ITEM_TM12_TAUNT, 1
	check_and_add ITEM_TM13_ICE_BEAM, 1
	check_and_add ITEM_TM14_BLIZZARD, 1
	check_and_add ITEM_TM15_HYPER_BEAM, 1
	check_and_add ITEM_TM16_LIGHT_SCREEN, 1
	check_and_add ITEM_TM17_PROTECT, 1
	check_and_add ITEM_TM18_RAIN_DANCE, 1
	check_and_add ITEM_TM19_GIGA_DRAIN, 1
	check_and_add ITEM_TM20_SAFEGUARD, 1
	check_and_add ITEM_TM21_FRUSTRATION, 1
	check_and_add ITEM_TM22_SOLARBEAM, 1
	check_and_add ITEM_TM23_IRON_TAIL, 1
	check_and_add ITEM_TM24_THUNDERBOLT, 1
	check_and_add ITEM_TM26_EARTHQUAKE, 1
	check_and_add ITEM_TM27_RETURN, 1
	check_and_add ITEM_TM28_DIG, 1
	check_and_add ITEM_TM29_PSYCHIC, 1
	check_and_add ITEM_TM30_SHADOW_BALL, 1
	check_and_add ITEM_TM31_BRICK_BREAK, 1
	check_and_add ITEM_TM32_DOUBLE_TEAM, 1
	check_and_add ITEM_TM33_REFLECT, 1
	check_and_add ITEM_TM34_SLUDGE_WAVE, 1
	check_and_add ITEM_TM35_FLAMETHROWER, 1
	check_and_add ITEM_TM36_SLUDGE_BOMB, 1
	check_and_add ITEM_TM37_SANDSTORM, 1
	check_and_add ITEM_TM38_FIRE_BLAST, 1
	check_and_add ITEM_TM39_ROCK_TOMB, 1
	check_and_add ITEM_TM40_AERIAL_ACE, 1
	check_and_add ITEM_TM41_TORMENT, 1
	check_and_add ITEM_TM42_FACADE, 1
	check_and_add ITEM_TM43_SECRET_POWER, 1
	check_and_add ITEM_TM44_REST, 1
	check_and_add ITEM_TM45_ATTRACT, 1
	check_and_add ITEM_TM46_THIEF, 1
	check_and_add ITEM_TM47_STEEL_WING, 1
	check_and_add ITEM_TM48_SKILL_SWAP, 1
	check_and_add ITEM_TM49_SLEEP_TALK, 1
	check_and_add ITEM_TM50_OVERHEAT, 1
	check_and_add ITEM_TM51_ROOST, 1
	check_and_add ITEM_TM52_FOCUS_BLAST, 1
	check_and_add ITEM_TM53_ENERGY_BALL, 1
	check_and_add ITEM_TM54_PSYSHOCK, 1
	check_and_add ITEM_TM55_SCALD, 1
	check_and_add ITEM_TM56_LEECH_LIFE, 1
	check_and_add ITEM_TM57_CHARGE_BEAM, 1
	check_and_add ITEM_TM58_ENDURE, 1
	check_and_add ITEM_TM59_DRAGON_PULSE, 1
	check_and_add ITEM_TM60_DRAIN_PUNCH, 1
	check_and_add ITEM_TM61_WILL_O_WISP, 1
	check_and_add ITEM_TM62_ACROBATICS, 1
	check_and_add ITEM_TM63_ROCK_SLIDE, 1
	check_and_add ITEM_TM64_EXPLOSION, 1
	check_and_add ITEM_TM65_SHADOW_CLAW, 1
	check_and_add ITEM_TM66_PAYBACK, 1
	check_and_add ITEM_TM67_RECYCLE, 1
	check_and_add ITEM_TM68_GIGA_IMPACT, 1
	check_and_add ITEM_TM69_ROCK_POLISH, 1
	check_and_add ITEM_TM70_AURORA_VEIL, 1
	check_and_add ITEM_TM71_STONE_EDGE, 1
	check_and_add ITEM_TM72_VOLT_SWITCH, 1
	check_and_add ITEM_TM73_THUNDER_WAVE, 1
	check_and_add ITEM_TM74_GYRO_BALL, 1
	check_and_add ITEM_TM75_SWORDS_DANCE, 1
	check_and_add ITEM_TM76_STEALTH_ROCK, 1
	check_and_add ITEM_TM77_STRUGGLE_BUG, 1
	check_and_add ITEM_TM78_BULLDOZE, 1
	check_and_add ITEM_TM79_FREEZE_DRY, 1
	check_and_add ITEM_TM80_VENOSHOCK, 1
	check_and_add ITEM_TM81_X_SCISSOR, 1
	check_and_add ITEM_TM82_DRAGON_TAIL, 1
	check_and_add ITEM_TM83_FLAME_CHARGE, 1
	check_and_add ITEM_TM84_POISON_JAB, 1
	check_and_add ITEM_TM85_DREAM_EATER, 1
	check_and_add ITEM_TM86_GRASS_KNOT, 1
	check_and_add ITEM_TM87_SMACK_DOWN, 1
	check_and_add ITEM_TM88_LOW_SWEEP, 1
	check_and_add ITEM_TM89_U_TURN, 1
	check_and_add ITEM_TM90_SUBSTITUTE, 1
	check_and_add ITEM_TM91_FLASH_CANNON, 1
	check_and_add ITEM_TM92_TRICK_ROOM, 1
	check_and_add ITEM_TM93_WILD_CHARGE, 1
	check_and_add ITEM_TM94_SUCKER_PUNCH, 1
	check_and_add ITEM_TM95_SNARL, 1
	check_and_add ITEM_TM96_AVALANCHE, 1
	check_and_add ITEM_TM97_DARK_PULSE, 1
	check_and_add ITEM_TM98_FALSE_SWIPE, 1
	check_and_add ITEM_TM99_DAZZLING_GLEAM, 1
	check_and_add ITEM_TM100_CURSE, 1
	check_and_add ITEM_HM01_CUT, 1
	check_and_add ITEM_HM02_FLY, 1
	check_and_add ITEM_HM03_SURF, 1
	check_and_add ITEM_HM04_STRENGTH, 1
	check_and_add ITEM_HM05_FLASH, 1
	check_and_add ITEM_HM06_ROCK_SMASH, 1
	check_and_add ITEM_HM07_WATERFALL, 1
	check_and_add ITEM_HM08_DIVE, 1
	return

