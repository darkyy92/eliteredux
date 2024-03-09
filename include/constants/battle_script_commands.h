#ifndef GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H
#define GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H

// Battle Scripting and BattleCommunication addresses
#define sPAINSPLIT_HP                gBattleScripting
#define sBIDE_DMG                    sPAINSPLIT_HP + 4
#define sMULTIHIT_STRING             sBIDE_DMG + 4
#define sEXP_CATCH                   sMULTIHIT_STRING + 6
#define sTWOTURN_STRINGID            sEXP_CATCH + 1
#define sB_ANIM_ARG1                 sTWOTURN_STRINGID + 1
#define sB_ANIM_ARG2                 sB_ANIM_ARG1 + 1
#define sMOVEEND_STATE               sB_ANIM_ARG2 + 1
#define sSAVED_STAT_CHANGER          sMOVEEND_STATE + 1
#define sSHIFT_SWITCHED              sSAVED_STAT_CHANGER + 1
#define sBATTLER                     sSHIFT_SWITCHED + 1
#define sB_ANIM_TURN                 sBATTLER + 1
#define sB_ANIM_TARGETS_HIT          sB_ANIM_TURN + 1
#define sSTATCHANGER                 sB_ANIM_TARGETS_HIT + 1
#define sSTAT_ANIM_PLAYED            sSTATCHANGER + 1
#define sGIVEEXP_STATE               sSTAT_ANIM_PLAYED + 1
#define sBATTLE_STYLE                sGIVEEXP_STATE + 1
#define sLVLBOX_STATE                sBATTLE_STYLE + 1
#define sLEARNMOVE_STATE             sLVLBOX_STATE + 1
#define sSAVED_BATTLER               sLEARNMOVE_STATE + 1
#define sRESHOW_MAIN_STATE           sSAVED_BATTLER + 1
#define sRESHOW_HELPER_STATE         sRESHOW_MAIN_STATE + 1
#define sLEVEL_UP_HP                 sRESHOW_HELPER_STATE + 1
#define sWINDOWS_TYPE                sLEVEL_UP_HP + 1
#define sMULTIPLAYER_ID              sWINDOWS_TYPE + 1
#define sSPECIAL_TRAINER_BATTLE_TYPE sMULTIPLAYER_ID + 1
#define sMON_CAUGHT                  sSPECIAL_TRAINER_BATTLE_TYPE + 1
#define sSAVED_MOVE_EFFECT           sMON_CAUGHT + 1
#define sMOVE_EFFECT                 sSAVED_MOVE_EFFECT + 2
#define sMULTIHIT_EFFECT             sMOVE_EFFECT + 2
#define sILLUSION_NICK_HACK          sMULTIHIT_EFFECT + 2
#define sFIXED_ABILITY_POPUP         sILLUSION_NICK_HACK + 1
#define sABILITY_OVERWRITE           sFIXED_ABILITY_POPUP + 1
#define sSWITCH_IN_BATTLER_OVERWRITE sABILITY_OVERWRITE + 2
#define sSWITCH_CASE                 sSWITCH_IN_BATTLER_OVERWRITE + 1
#define sBERRY_OVERRIDE              sSWITCH_CASE + 1
#define sBATTLER_OVERRIDE            sBERRY_OVERRIDE + 1
#define sEFFECT_CHANCE               sBATTLER_OVERRIDE + 2 // Missing forceFalseSwipeEffect

#define cMULTISTRING_CHOOSER         gBattleCommunication + 5
#define cMISS_TYPE                   gBattleCommunication + 6

// Battle Script defines for getting the wanted battler
#define BS_TARGET                   0
#define BS_ATTACKER                 1
#define BS_EFFECT_BATTLER           2
#define BS_FAINTED                  3
#define BS_ATTACKER_WITH_PARTNER    4 // for Cmd_updatestatusicon
#define BS_FAINTED_LINK_MULTIPLE_1  5 // for openpartyscreen
#define BS_FAINTED_LINK_MULTIPLE_2  6 // for openpartyscreen
#define BS_BATTLER_0                7
#define BS_ATTACKER_SIDE            8 // for Cmd_jumpifability
#define BS_TARGET_SIDE              9 // for Cmd_jumpifability
#define BS_SCRIPTING                10
#define BS_PLAYER1                  11
#define BS_OPPONENT1                12
#define BS_PLAYER2                  13
#define BS_OPPONENT2                14
#define BS_ABILITY_BATTLER          15
#define BS_ABILITY_PARTNER          16
#define BS_TARGET_PARTNER           17
#define BS_ATTACKER_PARTNER         18
#define BS_CHOOSE_FAINTED_MON       19
#define BS_STACK_1                  20
#define BS_STACK_2                  21
#define BS_STACK_3                  22
#define BS_STACK_4                  23

// Cmd_accuracycheck
#define NO_ACC_CALC_CHECK_LOCK_ON 0xFFFF
#define ACC_CURR_MOVE 0

// compare operands
#define CMP_EQUAL               0
#define CMP_NOT_EQUAL           1
#define CMP_GREATER_THAN        2
#define CMP_LESS_THAN           3
#define CMP_COMMON_BITS         4
#define CMP_NO_COMMON_BITS      5

// Cmd_various
#define VARIOUS_CANCEL_MULTI_TURN_MOVES         0
#define VARIOUS_SET_MAGIC_COAT_TARGET           1
#define VARIOUS_IS_RUNNING_IMPOSSIBLE           2
#define VARIOUS_GET_MOVE_TARGET                 3
#define VARIOUS_GET_BATTLER_FAINTED             4
#define VARIOUS_RESET_INTIMIDATE_TRACE_BITS     5
#define VARIOUS_UPDATE_CHOICE_MOVE_ON_LVL_UP    6
#define VARIOUS_PALACE_FLAVOR_TEXT              8
#define VARIOUS_ARENA_JUDGMENT_WINDOW           9
#define VARIOUS_ARENA_OPPONENT_MON_LOST         10
#define VARIOUS_ARENA_PLAYER_MON_LOST           11
#define VARIOUS_ARENA_BOTH_MONS_LOST            12
#define VARIOUS_EMIT_YESNOBOX                   13
#define VARIOUS_ARENA_JUDGMENT_STRING           16
#define VARIOUS_ARENA_WAIT_STRING               17
#define VARIOUS_WAIT_CRY                        18
#define VARIOUS_RETURN_OPPONENT_MON1            19
#define VARIOUS_RETURN_OPPONENT_MON2            20
#define VARIOUS_VOLUME_DOWN                     21
#define VARIOUS_VOLUME_UP                       22
#define VARIOUS_SET_ALREADY_STATUS_MOVE_ATTEMPT 23
#define VARIOUS_SET_TELEPORT_OUTCOME            25
#define VARIOUS_PLAY_TRAINER_DEFEATED_MUSIC     26
#define VARIOUS_STAT_TEXT_BUFFER                27
#define VARIOUS_SWITCHIN_ABILITIES              28
#define VARIOUS_SAVE_TARGET                     29
#define VARIOUS_RESTORE_TARGET                  30
#define VARIOUS_INSTANT_HP_DROP                 31
#define VARIOUS_CLEAR_STATUS                    32
#define VARIOUS_RESTORE_PP                      33
#define VARIOUS_TRY_ACTIVATE_MOXIE              34
#define VARIOUS_TRY_ACTIVATE_FELL_STINGER       35
#define VARIOUS_PLAY_MOVE_ANIMATION             36
#define VARIOUS_SET_LUCKY_CHANT                 37
#define VARIOUS_SUCKER_PUNCH_CHECK              38
#define VARIOUS_SET_SIMPLE_BEAM                 39
#define VARIOUS_TRY_ENTRAINMENT                 40
#define VARIOUS_SET_LAST_USED_ABILITY           41
#define VARIOUS_TRY_HEAL_PULSE                  42
#define VARIOUS_TRY_QUASH                       43
#define VARIOUS_INVERT_STAT_STAGES              44
#define VARIOUS_SET_TERRAIN                     45
#define VARIOUS_TRY_ME_FIRST                    46
#define VARIOUS_JUMP_IF_BATTLE_END              47
#define VARIOUS_TRY_ELECTRIFY                   48
#define VARIOUS_TRY_REFLECT_TYPE                49
#define VARIOUS_TRY_SOAK                        50
#define VARIOUS_HANDLE_MEGA_EVO                 51
#define VARIOUS_TRY_LAST_RESORT                 52
#define VARIOUS_ARGUMENT_STATUS_EFFECT          53
#define VARIOUS_TRY_HIT_SWITCH_TARGET           54
#define VARIOUS_TRY_AUTOTOMIZE                  55
#define VARIOUS_TRY_COPYCAT                     56
#define VARIOUS_ABILITY_POPUP                   57
#define VARIOUS_DEFOG                           58
#define VARIOUS_JUMP_IF_TARGET_ALLY             59
#define VARIOUS_TRY_SYNCHRONOISE                60
#define VARIOUS_PSYCHO_SHIFT                    61
#define VARIOUS_CURE_STATUS                     62
#define VARIOUS_POWER_TRICK                     63
#define VARIOUS_AFTER_YOU                       64
#define VARIOUS_BESTOW                          65
#define VARIOUS_ARGUMENT_TO_MOVE_EFFECT         66
#define VARIOUS_JUMP_IF_NOT_GROUNDED            67
#define VARIOUS_HANDLE_TRAINER_SLIDE_MSG        68
#define VARIOUS_TRY_TRAINER_SLIDE_MSG_FIRST_OFF 69
#define VARIOUS_TRY_TRAINER_SLIDE_MSG_LAST_ON   70
#define VARIOUS_SET_AURORA_VEIL                 71
#define VARIOUS_TRY_THIRD_TYPE                  72
#define VARIOUS_ACUPRESSURE                     73
#define VARIOUS_SET_POWDER                      74
#define VARIOUS_SPECTRAL_THIEF                  75
#define VARIOUS_GRAVITY_ON_AIRBORNE_MONS        76
#define VARIOUS_CHECK_IF_GRASSY_TERRAIN_HEALS   77
#define VARIOUS_JUMP_IF_ROAR_FAILS              78
#define VARIOUS_TRY_INSTRUCT                    79
#define VARIOUS_JUMP_IF_NOT_BERRY               80
#define VARIOUS_TRACE_ABILITY                   81
#define VARIOUS_UPDATE_NICK                     82
#define VARIOUS_TRY_ILLUSION_OFF                83
#define VARIOUS_SET_SPRITEIGNORE0HP             84
#define VARIOUS_HANDLE_FORM_CHANGE              85
#define VARIOUS_GET_STAT_VALUE                  86
#define VARIOUS_JUMP_IF_FULL_HP                 87
#define VARIOUS_LOSE_TYPE                       88
#define VARIOUS_TRY_ACTIVATE_SOULHEART          89
#define VARIOUS_TRY_ACTIVATE_RECEIVER           90
#define VARIOUS_TRY_ACTIVATE_BEAST_BOOST        91
#define VARIOUS_TRY_FRISK                       92
#define VARIOUS_JUMP_IF_SHIELDS_DOWN_PROTECTED  93
#define VARIOUS_TRY_FAIRY_LOCK                  94
#define VARIOUS_JUMP_IF_NO_ALLY                 95
#define VARIOUS_POISON_TYPE_IMMUNITY            96
#define VARIOUS_JUMP_IF_NO_HOLD_EFFECT          97
#define VARIOUS_INFATUATE_WITH_BATTLER          98
#define VARIOUS_SET_LAST_USED_ITEM              99
#define VARIOUS_PARALYZE_TYPE_IMMUNITY          100
#define VARIOUS_JUMP_IF_ABSENT                  101
#define VARIOUS_DESTROY_ABILITY_POPUP           102
#define VARIOUS_TOTEM_BOOST                     103
#define VARIOUS_TRY_ACTIVATE_GRIM_NEIGH         104
#define VARIOUS_MOVEEND_ITEM_EFFECTS            105
#define VARIOUS_TERRAIN_SEED                    106
#define VARIOUS_MAKE_INVISIBLE                  107
#define VARIOUS_ROOM_SERVICE                    108
#define VARIOUS_JUMP_IF_TERRAIN_AFFECTED        109
#define VARIOUS_EERIE_SPELL_PP_REDUCE           110
#define VARIOUS_JUMP_IF_TEAM_HEALTHY            111
#define VARIOUS_TRY_HEAL_PERCENT_HP             112
#define VARIOUS_REMOVE_TERRAIN                  113
#define VARIOUS_JUMP_IF_PRANKSTER_BLOCKED       114
#define VARIOUS_TRY_TO_CLEAR_PRIMAL_WEATHER     115
#define VARIOUS_GET_ROTOTILLER_TARGETS          116
#define VARIOUS_JUMP_IF_NOT_ROTOTILLER_AFFECTED 117
#define VARIOUS_TRY_ACTIVATE_BATTLE_BOND        118
#define VARIOUS_CONSUME_BERRY                   119
#define VARIOUS_JUMP_IF_CANT_REVERT_TO_PRIMAL   120
#define VARIOUS_HANDLE_PRIMAL_REVERSION         121
#define VARIOUS_APPLY_PLASMA_FISTS              122
#define VARIOUS_JUMP_IF_SPECIES                 123
#define VARIOUS_UPDATE_ABILITY_POPUP            124
#define VARIOUS_JUMP_IF_WEATHER_AFFECTED        125
#define VARIOUS_JUMP_IF_LEAF_GUARD_PROTECTED    126
#define VARIOUS_SET_ATTACKER_STICKY_WEB_USER    127
#define VARIOUS_TRY_TO_APPLY_MIMICRY            128
#define VARIOUS_PHOTON_GEYSER_CHECK             129
#define VARIOUS_SHELL_SIDE_ARM_CHECK            130
#define VARIOUS_TRY_NO_RETREAT                  131
#define VARIOUS_TRY_TAR_SHOT                    132
#define VARIOUS_CAN_TAR_SHOT_WORK               133
#define VARIOUS_CHECK_POLTERGEIST               134
#define VARIOUS_SET_OCTOLOCK                    135
#define VARIOUS_CUT_1_3_HP_RAISE_STATS          136
#define VARIOUS_TRY_END_NEUTRALIZING_GAS        137
#define VARIOUS_TRY_ACTIVATE_RAMPAGE            138
#define VARIOUS_TRY_ACTIVATE_SOUL_EATER         139
#define VARIOUS_SET_BEAK_BLAST                  140
#define VARIOUS_CAN_TELEPORT                    141
#define VARIOUS_GET_BATTLER_SIDE                142
#define VARIOUS_SET_WEATHER_GRAPHICS            143
#define VARIOUS_TRY_ACTIVATE_JAWS_OF_CARNAGE    144
#define VARIOUS_RAISE_HIGHEST_ATTACKING_STAT    145
#define VARIOUS_TRY_ACTIVATE_SUPER_STRAIN       146
#define VARIOUS_SET_DYNAMIC_TYPE                147
#define VARIOUS_GOTO_ACTUAL_MOVE                148
#define VARIOUS_INCREASE_TRIPLE_KICK_DAMAGE     149
#define VARIOUS_HANDLE_WEATHER_CHANGE           150
#define VARIOUS_HANDLE_TERRAIN_CHANGE           151
#define VARIOUS_GET_BATTLER                     152
#define VARIOUS_DO_COPY_STAT_CHANGE             153
#define VARIOUS_TRY_LOSE_PERCENT_HP             154
#define VARIOUS_SWAP_SIDE_EFFECTS               155
#define VARIOUS_GHASTLY_ECHO                    156
#define VARIOUS_TRY_REVIVAL_BLESSING            157
#define VARIOUS_REMOVE_WEATHER                  158
#define VARIOUS_COPY_ABILITY                    159
#define VARIOUS_TRY_FLING                       160
#define VARIOUS_JUMP_IF_STATUS_4                161
#define VARIOUS_RESTORE_TURN_BATTLERS           162
#define VARIOUS_WRITE_STACK_BATTLER             163
#define VARIOUS_RESTORE_STACK_STATE             164

// Cmd_manipulatedamage
#define DMG_CHANGE_SIGN            0
#define DMG_RECOIL_FROM_MISS       1
#define DMG_DOUBLED                2
#define DMG_1_8_TARGET_HP          3
#define DMG_FULL_ATTACKER_HP       4
#define DMG_CURR_ATTACKER_HP       5
#define DMG_BIG_ROOT               6
#define DMG_1_2_ATTACKER_HP        7
#define DMG_RECOIL_FROM_IMMUNE     8  // Used to calculate recoil for the Gen 4 version of Jump Kick
#define DMG_1_4_TARGET_HP          9
#define DMG_TO_HP_FROM_ABILITY     10
#define DMG_TO_HP_FROM_MOVE        11

// Cmd_jumpifcantswitch
#define SWITCH_IGNORE_ESCAPE_PREVENTION   (1 << 7)

// Cmd_statbuffchange
#define STAT_BUFF_ALLOW_PTR                 (1 << 0)   // If set, allow use of jumpptr. Set in every use of statbuffchange
#define STAT_BUFF_NOT_PROTECT_AFFECTED      (1 << 5)
#define STAT_BUFF_UPDATE_MOVE_EFFECT        (1 << 6)
#define STAT_BUFF_DONT_SET_BUFFERS          (1 << 7)

// stat change flags for Cmd_playstatchangeanimation
#define STAT_CHANGE_NEGATIVE             (1 << 0)
#define STAT_CHANGE_BY_TWO               (1 << 1)
#define STAT_CHANGE_MULTIPLE_STATS       (1 << 2)
#define STAT_CHANGE_CANT_PREVENT         (1 << 3)

// stat flags for Cmd_playstatchangeanimation
#define BIT_HP                      (1 << 0)
#define BIT_ATK                     (1 << 1)
#define BIT_DEF                     (1 << 2)
#define BIT_SPEED                   (1 << 3)
#define BIT_SPATK                   (1 << 4)
#define BIT_SPDEF                   (1 << 5)
#define BIT_ACC                     (1 << 6)
#define BIT_EVASION                 (1 << 7)

#define PARTY_SCREEN_OPTIONAL (1 << 7) // Flag for first argument to openpartyscreen

// cases for Cmd_moveend
#define MOVEEND_SUM_DAMAGE                        0
#define MOVEEND_PROTECT_LIKE_EFFECT               1
#define MOVEEND_RAGE                              2
#define MOVEEND_SYNCHRONIZE_TARGET                3
#define MOVEEND_DANCER                            4
#define MOVEEND_ABILITIES                         5
#define MOVEEND_ABILITIES_ATTACKER                6
#define MOVEEND_STATUS_IMMUNITY_ABILITIES         7
#define MOVEEND_SYNCHRONIZE_ATTACKER              8
#define MOVEEND_CHOICE_MOVE                       9
#define MOVEEND_ATTACKER_INVISIBLE                10
#define MOVEEND_ATTACKER_VISIBLE                  11
#define MOVEEND_TARGET_VISIBLE                    12
#define MOVEEND_ITEM_EFFECTS_TARGET               13
#define MOVEEND_ITEM_EFFECTS_ALL                  14
#define MOVEEND_KINGSROCK                         15
#define MOVEEND_SUBSTITUTE                        16
#define MOVEEND_UPDATE_LAST_MOVES                 17
#define MOVEEND_MIRROR_MOVE                       18
#define MOVEEND_NEXT_TARGET                       19    // Everything up until here is handled for each strike of a multi-hit move
#define MOVEEND_MULTIHIT_MOVE                     20
#define MOVEEND_MOVE_EFFECTS2                     21
#define MOVEEND_RECOIL                            22
#define MOVEEND_CHARGE                            23
#define MOVEEND_ATTACKER_FOLLOWUP_MOVE            24
#define MOVEEND_ABILITIES_AFTER_RECOIL            25
#define MOVEEND_EJECT_BUTTON                      26
#define MOVEEND_RED_CARD                          27
#define MOVEEND_EJECT_PACK                        28
#define MOVEEND_LIFEORB_SHELLBELL                 29
#define MOVEEND_CHANGED_ITEMS                     30
#define MOVEEND_DEFROST                           31
#define MOVEEND_PICKPOCKET                        32
#define MOVEEND_EMERGENCY_EXIT                    33
#define MOVEEND_CLEAR_BITS                        34
#define MOVEEND_COUNT                             35

// switch cases
#define B_SWITCH_NORMAL     0
#define B_SWITCH_HIT        1   // dragon tail, circle throw
#define B_SWITCH_RED_CARD   2

#endif // GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H
