#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_arena.h"
#include "battle_pyramid.h"
#include "battle_util.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_setup.h"
#include "data.h"
#include "party_menu.h"
#include "pokemon.h"
#include "international_string_util.h"
#include "item.h"
#include "rtc.h"
#include "util.h"
#include "battle_scripts.h"
#include "random.h"
#include "text.h"
#include "safari_zone.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "trig.h"
#include "window.h"
#include "battle_message.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "event_data.h"
#include "link.h"
#include "malloc.h"
#include "berry.h"
#include "pokedex.h"
#include "mail.h"
#include "field_weather.h"
#include "constants/abilities.h"
#include "constants/battle_anim.h"
#include "constants/battle_config.h"
#include "constants/battle_frontier.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_string_ids.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/weather.h"
#include "mgba_printf/mgba.h"
#include "mgba_printf/mini_printf.h"

/*
NOTE: The data and functions in this file up until (but not including) sSoundMovesTable
are actually part of battle_main.c. They needed to be moved to this file in order to
match the ROM; this is also why sSoundMovesTable's declaration is in the middle of
functions instead of at the top of the file with the other declarations.
*/

static bool32 TryRemoveScreens(u8 battler);
static bool32 IsUnnerveAbilityOnOpposingSide(u8 battlerId);
static bool8 DoesMoveBoostStats(u16 move);

extern const u8 *const gBattleScriptsForMoveEffects[];
extern const u8 *const gBattlescriptsForBallThrow[];
extern const u8 *const gBattlescriptsForRunningByItem[];
extern const u8 *const gBattlescriptsForUsingItem[];
extern const u8 *const gBattlescriptsForSafariActions[];

static const u8 sPkblToEscapeFactor[][3] = {
    {
        [B_MSG_MON_CURIOUS]    = 0,
        [B_MSG_MON_ENTHRALLED] = 0,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 3,
        [B_MSG_MON_ENTHRALLED] = 5,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 2,
        [B_MSG_MON_ENTHRALLED] = 3,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 1,
        [B_MSG_MON_ENTHRALLED] = 2,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 1,
        [B_MSG_MON_ENTHRALLED] = 1,
        [B_MSG_MON_IGNORED]    = 0
    }
};
static const u8 sGoNearCounterToCatchFactor[] = {4, 3, 2, 1};
static const u8 sGoNearCounterToEscapeFactor[] = {4, 4, 4, 4};

static const u16 sSkillSwapBannedAbilities[] =
{
    ABILITY_WONDER_GUARD,
};

static const u16 sRolePlayBannedAbilities[] =
{
    ABILITY_TRACE,
    ABILITY_WONDER_GUARD,
    ABILITY_POWER_OF_ALCHEMY,
    ABILITY_RECEIVER,
};

static const u16 sEntrainmentTargetSimpleBeamBannedAbilities[] =
{
    ABILITY_TRUANT,
};

static const u16 sTwoStrikeMoves[] =
{
    MOVE_DOUBLE_IRON_BASH,
    MOVE_TWINEEDLE,
};

u8 CalcBeatUpPower(void)
{
    struct Pokemon *party;
    u8 basePower;
    u16 species;

    if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    // Party slot is set in the battle script for Beat Up
    species = GetMonData(&party[gBattleCommunication[0] - 1], MON_DATA_SPECIES);
    basePower = (gBaseStats[species].baseAttack / 10) + 5;

    return basePower;
}

bool32 IsAffectedByFollowMe(u32 battlerAtk, u32 defSide, u32 move)
{
    u32 ability = GetBattlerAbility(battlerAtk);

    if (gSideTimers[defSide].followmeTimer == 0
        || gBattleMons[gSideTimers[defSide].followmeTarget].hp == 0
        || gBattleMoves[move].effect == EFFECT_SNIPE_SHOT
        || ability == ABILITY_PROPELLER_TAIL || ability == ABILITY_STALWART)
        return FALSE;

    if (gSideTimers[defSide].followmePowder && !IsAffectedByPowder(battlerAtk, ability, GetBattlerHoldEffect(battlerAtk, TRUE)))
        return FALSE;

    return TRUE;
}

// Returns the target field of a move, modified by ability
u8 GetBattleMoveTargetFlags(u16 moveId, u16 ability)
{
    if ((BATTLER_HAS_ABILITY_FAST(gActiveBattler, ABILITY_ARTILLERY, ability)) 
         && (gBattleMoves[moveId].flags & FLAG_MEGA_LAUNCHER_BOOST)
         && gBattleMoves[moveId].target == MOVE_TARGET_SELECTED)
        return MOVE_TARGET_BOTH;
    else if ((BATTLER_HAS_ABILITY_FAST(gActiveBattler, ABILITY_SWEEPING_EDGE, ability) || BATTLER_HAS_ABILITY_FAST(gActiveBattler, ABILITY_SWEEPING_EDGE_PLUS, ability)) 
         && (gBattleMoves[moveId].flags & FLAG_KEEN_EDGE_BOOST)
         && gBattleMoves[moveId].target == MOVE_TARGET_SELECTED)
        return MOVE_TARGET_BOTH;
    else if ((BATTLER_HAS_ABILITY(ability, ABILITY_AMPLIFIER) || BATTLER_HAS_ABILITY(ability, ABILITY_BASS_BOOSTED))
         && (gBattleMoves[moveId].flags & FLAG_SOUND)
         && gBattleMoves[moveId].target == MOVE_TARGET_SELECTED)
        return MOVE_TARGET_BOTH;
    else if (gBattleMoves[moveId].effect == EFFECT_EXPANDING_FORCE && GetCurrentTerrain() == STATUS_FIELD_PSYCHIC_TERRAIN)
        return MOVE_TARGET_BOTH;
    return gBattleMoves[moveId].target;
}

u8 GetBattlerBattleMoveTargetFlags(u16 moveId, u8 battler)
{
    u16 ability = gBattleMons[battler].ability;
    if ((BATTLER_HAS_ABILITY_FAST(battler, ABILITY_ARTILLERY, ability)) 
         && (gBattleMoves[moveId].flags & FLAG_MEGA_LAUNCHER_BOOST)
         && gBattleMoves[moveId].target == MOVE_TARGET_SELECTED)
        return MOVE_TARGET_BOTH;
    else if ((BATTLER_HAS_ABILITY_FAST(battler, ABILITY_SWEEPING_EDGE, ability) || BATTLER_HAS_ABILITY_FAST(battler, ABILITY_SWEEPING_EDGE_PLUS, ability)) 
         && (gBattleMoves[moveId].flags & FLAG_KEEN_EDGE_BOOST)
         && gBattleMoves[moveId].target == MOVE_TARGET_SELECTED)
        return MOVE_TARGET_BOTH;
    else if ((BATTLER_HAS_ABILITY(ability, ABILITY_AMPLIFIER) || BATTLER_HAS_ABILITY(ability, ABILITY_BASS_BOOSTED))
         && (gBattleMoves[moveId].flags & FLAG_SOUND)
         && gBattleMoves[moveId].target == MOVE_TARGET_SELECTED)
        return MOVE_TARGET_BOTH;
    else if (gBattleMoves[moveId].effect == EFFECT_EXPANDING_FORCE && GetCurrentTerrain() == STATUS_FIELD_PSYCHIC_TERRAIN)
        return MOVE_TARGET_BOTH;
    return gBattleMoves[moveId].target;
}

// Functions
void HandleAction_UseMove(void)
{
    u32 i, side, moveType, var = 4;

    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    if (gBattleStruct->field_91 & gBitTable[gBattlerAttacker] || !IsBattlerAlive(gBattlerAttacker))
    {
        gCurrentActionFuncId = B_ACTION_FINISHED;
        return;
    }

    gIsCriticalHit = FALSE;
    gBattleStruct->atkCancellerTracker = 0;
    gMoveResultFlags = 0;
    gMultiHitCounter = 0;
    gBattleScripting.savedDmg = 0;
    gBattleCommunication[6] = 0;
    gBattleScripting.savedMoveEffect = 0;
    gCurrMovePos = gChosenMovePos = *(gBattleStruct->chosenMovePositions + gBattlerAttacker);

    // choose move
    if (gProtectStructs[gBattlerAttacker].noValidMoves)
    {
        gProtectStructs[gBattlerAttacker].noValidMoves = FALSE;
        gCurrentMove = gChosenMove = MOVE_STRUGGLE;
        gHitMarker |= HITMARKER_NO_PPDEDUCT;
        *(gBattleStruct->moveTarget + gBattlerAttacker) = GetMoveTarget(MOVE_STRUGGLE, 0);
    }
    else if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS || gBattleMons[gBattlerAttacker].status2 & STATUS2_RECHARGE)
    {
        gCurrentMove = gChosenMove = gLockedMoves[gBattlerAttacker];
    }
    // encore forces you to use the same move
    else if (gDisableStructs[gBattlerAttacker].encoredMove != MOVE_NONE
          && gDisableStructs[gBattlerAttacker].encoredMove == gBattleMons[gBattlerAttacker].moves[gDisableStructs[gBattlerAttacker].encoredMovePos])
    {
        gCurrentMove = gChosenMove = gDisableStructs[gBattlerAttacker].encoredMove;
        gCurrMovePos = gChosenMovePos = gDisableStructs[gBattlerAttacker].encoredMovePos;
        *(gBattleStruct->moveTarget + gBattlerAttacker) = GetMoveTarget(gCurrentMove, 0);
    }
    // check if the encored move wasn't overwritten
    else if (gDisableStructs[gBattlerAttacker].encoredMove != MOVE_NONE
          && gDisableStructs[gBattlerAttacker].encoredMove != gBattleMons[gBattlerAttacker].moves[gDisableStructs[gBattlerAttacker].encoredMovePos])
    {
        gCurrMovePos = gChosenMovePos = gDisableStructs[gBattlerAttacker].encoredMovePos;
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
        gDisableStructs[gBattlerAttacker].encoredMove = MOVE_NONE;
        gDisableStructs[gBattlerAttacker].encoredMovePos = 0;
        gDisableStructs[gBattlerAttacker].encoreTimer = 0;
        *(gBattleStruct->moveTarget + gBattlerAttacker) = GetMoveTarget(gCurrentMove, 0);
    }
    else if (gBattleMons[gBattlerAttacker].moves[gCurrMovePos] != gChosenMoveByBattler[gBattlerAttacker])
    {
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
        *(gBattleStruct->moveTarget + gBattlerAttacker) = GetMoveTarget(gCurrentMove, 0);
    }
    else
    {
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
    }

    if (gBattleMons[gBattlerAttacker].hp != 0)
    {
        if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
            gBattleResults.lastUsedMovePlayer = gCurrentMove;
        else
            gBattleResults.lastUsedMoveOpponent = gCurrentMove;
    }

    // Set dynamic move type.
    SetTypeBeforeUsingMove(gChosenMove, gBattlerAttacker);
    GET_MOVE_TYPE(gChosenMove, moveType);

    // choose target
    side = GetBattlerSide(gBattlerAttacker) ^ BIT_SIDE;
    if (IsAffectedByFollowMe(gBattlerAttacker, side, gCurrentMove)
        && GetBattlerBattleMoveTargetFlags(gCurrentMove, gBattlerAttacker) == MOVE_TARGET_SELECTED
        && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gSideTimers[side].followmeTarget))
    {
        gBattlerTarget = gSideTimers[side].followmeTarget;
    }
    else if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
           && gSideTimers[side].followmeTimer == 0
           && (gBattleMoves[gCurrentMove].power != 0 || GetBattlerBattleMoveTargetFlags(gCurrentMove, gBattlerAttacker) != MOVE_TARGET_USER)
           && ((GetBattlerAbility(*(gBattleStruct->moveTarget + gBattlerAttacker)) != ABILITY_LIGHTNING_ROD && !BattlerHasInnate(*(gBattleStruct->moveTarget + gBattlerAttacker), ABILITY_LIGHTNING_ROD) && moveType == TYPE_ELECTRIC)
            || (GetBattlerAbility(*(gBattleStruct->moveTarget + gBattlerAttacker)) != ABILITY_STORM_DRAIN   && !BattlerHasInnate(*(gBattleStruct->moveTarget + gBattlerAttacker), ABILITY_STORM_DRAIN) && moveType == TYPE_WATER)))
    {
        side = GetBattlerSide(gBattlerAttacker);
        for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
        {
            if (side != GetBattlerSide(gActiveBattler)
                && *(gBattleStruct->moveTarget + gBattlerAttacker) != gActiveBattler
                && (((GetBattlerAbility(gActiveBattler) == ABILITY_LIGHTNING_ROD || BattlerHasInnate(gActiveBattler, ABILITY_LIGHTNING_ROD)) && moveType == TYPE_ELECTRIC)
                 || ((GetBattlerAbility(gActiveBattler) == ABILITY_STORM_DRAIN   || BattlerHasInnate(gActiveBattler, ABILITY_STORM_DRAIN))   && moveType == TYPE_WATER))
                && GetBattlerTurnOrderNum(gActiveBattler) < var
                && gBattleMoves[gCurrentMove].effect != EFFECT_SNIPE_SHOT
                && (GetBattlerAbility(gBattlerAttacker) != ABILITY_PROPELLER_TAIL
                 || GetBattlerAbility(gBattlerAttacker) != ABILITY_STALWART))
            {
                var = GetBattlerTurnOrderNum(gActiveBattler);
            }
        }
        if (var == 4)
        {
            if (GetBattlerBattleMoveTargetFlags(gChosenMove, gBattlerAttacker) & MOVE_TARGET_RANDOM)
            {
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                {
                    if (Random() & 1)
                        gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
                    else
                        gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
                }
                else
                {
                    if (Random() & 1)
                        gBattlerTarget = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
                    else
                        gBattlerTarget = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
                }
            }
            else if (GetBattlerBattleMoveTargetFlags(gChosenMove, gBattlerAttacker) & MOVE_TARGET_FOES_AND_ALLY)
            {
                for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount; gBattlerTarget++)
                {
                    if (gBattlerTarget == gBattlerAttacker)
                        continue;
                    if (IsBattlerAlive(gBattlerTarget))
                        break;
                }
            }
            else
            {
                gBattlerTarget = *(gBattleStruct->moveTarget + gBattlerAttacker);
            }

            if (!IsBattlerAlive(gBattlerTarget))
            {
                if (GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget))
                {
                    gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerTarget) ^ BIT_FLANK);
                }
                else
                {
                    gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerAttacker) ^ BIT_SIDE);
                    if (!IsBattlerAlive(gBattlerTarget))
                        gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerTarget) ^ BIT_FLANK);
                }
            }
        }
        else
        {
            gActiveBattler = gBattlerByTurnOrder[var];
            RecordAbilityBattle(gActiveBattler, gBattleMons[gActiveBattler].ability);
            if (GetBattlerAbility(gActiveBattler) == ABILITY_LIGHTNING_ROD    || BattlerHasInnate(gActiveBattler, ABILITY_LIGHTNING_ROD)) 
                gSpecialStatuses[gActiveBattler].lightningRodRedirected = TRUE;
            else if (GetBattlerAbility(gActiveBattler) == ABILITY_STORM_DRAIN || BattlerHasInnate(gActiveBattler, ABILITY_STORM_DRAIN))
                gSpecialStatuses[gActiveBattler].stormDrainRedirected = TRUE;
            gBattlerTarget = gActiveBattler;
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
          && GetBattlerBattleMoveTargetFlags(gChosenMove, gBattlerAttacker) & MOVE_TARGET_RANDOM)
    {
        if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
        {
            if (Random() & 1)
                gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            else
                gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
        }
        else
        {
            if (Random() & 1)
                gBattlerTarget = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
            else
                gBattlerTarget = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
        }

        if (gAbsentBattlerFlags & gBitTable[gBattlerTarget]
            && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget))
        {
            gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerTarget) ^ BIT_FLANK);
        }
    }
    else if (GetBattlerBattleMoveTargetFlags(gChosenMove, gBattlerAttacker) == MOVE_TARGET_ALLY)
    {
        if (IsBattlerAlive(BATTLE_PARTNER(gBattlerAttacker)))
            gBattlerTarget = BATTLE_PARTNER(gBattlerAttacker);
        else
            gBattlerTarget = gBattlerAttacker;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
          && GetBattlerBattleMoveTargetFlags(gChosenMove, gBattlerAttacker) == MOVE_TARGET_FOES_AND_ALLY)
    {
        for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount; gBattlerTarget++)
        {
            if (gBattlerTarget == gBattlerAttacker)
                continue;
            if (IsBattlerAlive(gBattlerTarget))
                break;
        }
    }
    else
    {
        gBattlerTarget = *(gBattleStruct->moveTarget + gBattlerAttacker);
        if (!IsBattlerAlive(gBattlerTarget))
        {
            if (GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget))
            {
                gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerTarget) ^ BIT_FLANK);
            }
            else
            {
                gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerAttacker) ^ BIT_SIDE);
                if (!IsBattlerAlive(gBattlerTarget))
                    gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerTarget) ^ BIT_FLANK);
            }
        }
    }

    if (gBattleTypeFlags & BATTLE_TYPE_PALACE && gProtectStructs[gBattlerAttacker].palaceUnableToUseMove)
    {
        // Battle Palace, select battle script for failure to use move
        if (gBattleMons[gBattlerAttacker].hp == 0)
        {
            gCurrentActionFuncId = B_ACTION_FINISHED;
            return;
        }
        else if (gPalaceSelectionBattleScripts[gBattlerAttacker] != NULL)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_INCAPABLE_OF_POWER;
            gBattlescriptCurrInstr = gPalaceSelectionBattleScripts[gBattlerAttacker];
            gPalaceSelectionBattleScripts[gBattlerAttacker] = NULL;
        }
        else
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_INCAPABLE_OF_POWER;
            gBattlescriptCurrInstr = BattleScript_MoveUsedLoafingAround;
        }
    }
    else
    {
        gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
    }

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        BattleArena_AddMindPoints(gBattlerAttacker);

    // Record HP of each battler
    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
        gBattleStruct->hpBefore[i] = gBattleMons[i].hp;

    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_Switch(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gActionSelectionCursor[gBattlerAttacker] = 0;
    gMoveSelectionCursor[gBattlerAttacker] = 0;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, *(gBattleStruct->battlerPartyIndexes + gBattlerAttacker))
    
    gBattleScripting.battler = gBattlerAttacker;
    gBattlescriptCurrInstr = BattleScript_ActionSwitch;
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;

    if (gBattleResults.playerSwitchesCounter < 255)
        gBattleResults.playerSwitchesCounter++;

    UndoFormChange(gBattlerPartyIndexes[gBattlerAttacker], GetBattlerSide(gBattlerAttacker), TRUE);
}

void HandleAction_UseItem(void)
{
    gBattlerAttacker = gBattlerTarget = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    ClearFuryCutterDestinyBondGrudge(gBattlerAttacker);

    gLastUsedItem = gBattleResources->bufferB[gBattlerAttacker][1] | (gBattleResources->bufferB[gBattlerAttacker][2] << 8);

    if (gLastUsedItem <= LAST_BALL_INDEX) // is ball
    {
        gBattlescriptCurrInstr = gBattlescriptsForBallThrow[gLastUsedItem];
    }
    else if (gLastUsedItem == ITEM_POKE_DOLL || gLastUsedItem == ITEM_FLUFFY_TAIL)
    {
        gBattlescriptCurrInstr = gBattlescriptsForRunningByItem[0];
    }
    else if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
    {
        gBattlescriptCurrInstr = gBattlescriptsForUsingItem[0];
    }
    else
    {
        gBattleScripting.battler = gBattlerAttacker;

        switch (*(gBattleStruct->AI_itemType + (gBattlerAttacker >> 1)))
        {
        case AI_ITEM_FULL_RESTORE:
        case AI_ITEM_HEAL_HP:
            break;
        case AI_ITEM_CURE_CONDITION:
            gBattleCommunication[MULTISTRING_CHOOSER] = AI_HEAL_CONFUSION;
            if (*(gBattleStruct->AI_itemFlags + gBattlerAttacker / 2) & (1 << AI_HEAL_CONFUSION))
            {
                if (*(gBattleStruct->AI_itemFlags + gBattlerAttacker / 2) & 0x3E)
                    gBattleCommunication[MULTISTRING_CHOOSER] = AI_HEAL_SLEEP;
            }
            else
            {
                // Check for other statuses, stopping at first (shouldn't be more than one)
                while (!(*(gBattleStruct->AI_itemFlags + gBattlerAttacker / 2) & 1))
                {
                    *(gBattleStruct->AI_itemFlags + gBattlerAttacker / 2) >>= 1;
                    gBattleCommunication[MULTISTRING_CHOOSER]++;
                    // MULTISTRING_CHOOSER will be either AI_HEAL_PARALYSIS, AI_HEAL_FREEZE,
                    // AI_HEAL_BURN, AI_HEAL_POISON, or AI_HEAL_SLEEP
                }
            }
            break;
        case AI_ITEM_X_STAT:
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_ROSE_ITEM;
            if (*(gBattleStruct->AI_itemFlags + (gBattlerAttacker >> 1)) & (1 << AI_DIRE_HIT))
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_USED_DIRE_HIT;
            }
            else
            {
                PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_ATK)
                PREPARE_STRING_BUFFER(gBattleTextBuff2, CHAR_X)

                while (!((*(gBattleStruct->AI_itemFlags + (gBattlerAttacker >> 1))) & 1))
                {
                    *(gBattleStruct->AI_itemFlags + gBattlerAttacker / 2) >>= 1;
                    gBattleTextBuff1[2]++;
                }

                gBattleScripting.animArg1 = gBattleTextBuff1[2] + 14;
                gBattleScripting.animArg2 = 0;
            }
            break;
        case AI_ITEM_GUARD_SPEC:
            // It seems probable that at some point there was a special message for
            // an AI trainer using Guard Spec in a double battle.
            // There isn't now however, and the assignment to 2 below goes out of
            // bounds for gMistUsedStringIds and instead prints "{mon} is getting pumped"
            // from the next table, gFocusEnergyUsedStringIds.
            // In any case this isn't an issue in the retail version, as no trainers
            // are ever given any Guard Spec to use.
#ifndef UBFIX
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MIST_FAILED + 1;
            else
#endif
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SET_MIST;
            break;
        }

        gBattlescriptCurrInstr = gBattlescriptsForUsingItem[*(gBattleStruct->AI_itemType + gBattlerAttacker / 2)];
    }
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

bool8 TryRunFromBattle(u8 battler)
{
    bool8 effect = FALSE;
    u8 holdEffect;
    u8 pyramidMultiplier;
    u8 speedVar;

    if (gBattleMons[battler].item == ITEM_ENIGMA_BERRY)
        holdEffect = gEnigmaBerries[battler].holdEffect;
    else
        holdEffect = ItemId_GetHoldEffect(gBattleMons[battler].item);

    gPotentialItemEffectBattler = battler;

    if (holdEffect == HOLD_EFFECT_CAN_ALWAYS_RUN)
    {
        gLastUsedItem = gBattleMons[battler].item;
        gProtectStructs[battler].fleeFlag = 1;
        effect++;
    }
    #if B_GHOSTS_ESCAPE >= GEN_6
    else if (IS_BATTLER_OF_TYPE(battler, TYPE_GHOST))
    {
        effect++;
    }
    #endif
    else if (GetBattlerAbility(battler) == ABILITY_RUN_AWAY)
    {
        if (InBattlePyramid())
        {
            gBattleStruct->runTries++;
            pyramidMultiplier = GetPyramidRunMultiplier();
            speedVar = (gBattleMons[battler].speed * pyramidMultiplier) / (gBattleMons[BATTLE_OPPOSITE(battler)].speed) + (gBattleStruct->runTries * 30);
            if (speedVar > (Random() & 0xFF))
            {
                gLastUsedAbility = ABILITY_RUN_AWAY;
                gProtectStructs[battler].fleeFlag = 2;
                effect++;
            }
        }
        else
        {
            gLastUsedAbility = ABILITY_RUN_AWAY;
            gProtectStructs[battler].fleeFlag = 2;
            effect++;
        }
    }
    else if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_TRAINER_HILL) && gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        effect++;
    }
    else
    {
        u8 runningFromBattler = BATTLE_OPPOSITE(battler);
        if (!IsBattlerAlive(runningFromBattler))
            runningFromBattler |= BIT_FLANK;

        if (InBattlePyramid())
        {
            pyramidMultiplier = GetPyramidRunMultiplier();
            speedVar = (gBattleMons[battler].speed * pyramidMultiplier) / (gBattleMons[runningFromBattler].speed) + (gBattleStruct->runTries * 30);
            if (speedVar > (Random() & 0xFF))
                effect++;
        }
        #ifdef DEBUG_BUILD
        else // Debug roms can always run
        {
            effect++;
        }
        #else
        else if (gBattleMons[battler].speed < gBattleMons[runningFromBattler].speed)
        {
            speedVar = (gBattleMons[battler].speed * 128) / (gBattleMons[runningFromBattler].speed) + (gBattleStruct->runTries * 30);
            if (speedVar > (Random() & 0xFF))
                effect++;
        }
        else // same speed or faster
        {
            effect++;
        }
        #endif

        gBattleStruct->runTries++;
    }

    if (effect)
    {
        gCurrentTurnActionNumber = gBattlersCount;
        gBattleOutcome = B_OUTCOME_RAN;
    }

    return effect;
}

void HandleAction_Run(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
    {
        gCurrentTurnActionNumber = gBattlersCount;

        for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
        {
            if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
            {
                if (gChosenActionByBattler[gActiveBattler] == B_ACTION_RUN)
                    gBattleOutcome |= B_OUTCOME_LOST;
            }
            else
            {
                if (gChosenActionByBattler[gActiveBattler] == B_ACTION_RUN)
                    gBattleOutcome |= B_OUTCOME_WON;
            }
        }

        gBattleOutcome |= B_OUTCOME_LINK_BATTLE_RAN;
        gSaveBlock2Ptr->frontier.disableRecordBattle = TRUE;
    }
    else
    {
        if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
        {
            if (!TryRunFromBattle(gBattlerAttacker)) // failed to run away
            {
                ClearFuryCutterDestinyBondGrudge(gBattlerAttacker);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CANT_ESCAPE_2;
                gBattlescriptCurrInstr = BattleScript_PrintFailedToRunString;
                gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
            }
        }
        else
        {
            if (!CanBattlerEscape(gBattlerAttacker))
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ATTACKER_CANT_ESCAPE;
                gBattlescriptCurrInstr = BattleScript_PrintFailedToRunString;
                gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
            }
            else
            {
                gCurrentTurnActionNumber = gBattlersCount;
                gBattleOutcome = B_OUTCOME_MON_FLED;
            }
        }
    }
}

void HandleAction_WatchesCarefully(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[0];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_SafariZoneBallThrow(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gNumSafariBalls--;
    gLastUsedItem = ITEM_SAFARI_BALL;
    gBattlescriptCurrInstr = gBattlescriptsForBallThrow[ITEM_SAFARI_BALL];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_ThrowBall(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gLastUsedItem = gLastThrownBall;
    RemoveBagItem(gLastUsedItem, 1);
    gBattlescriptCurrInstr = BattleScript_BallThrow;
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_ThrowPokeblock(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattleCommunication[MULTISTRING_CHOOSER] = gBattleResources->bufferB[gBattlerAttacker][1] - 1;
    gLastUsedItem = gBattleResources->bufferB[gBattlerAttacker][2];

    if (gBattleResults.pokeblockThrows < 0xFF)
        gBattleResults.pokeblockThrows++;
    if (gBattleStruct->safariPkblThrowCounter < 3)
        gBattleStruct->safariPkblThrowCounter++;
    if (gBattleStruct->safariEscapeFactor > 1)
    {
        // BUG: safariEscapeFactor can become 0 below. This causes the pokeblock throw glitch.
        #ifdef BUGFIX
        if (gBattleStruct->safariEscapeFactor <= sPkblToEscapeFactor[gBattleStruct->safariPkblThrowCounter][gBattleCommunication[MULTISTRING_CHOOSER]])
        #else
        if (gBattleStruct->safariEscapeFactor < sPkblToEscapeFactor[gBattleStruct->safariPkblThrowCounter][gBattleCommunication[MULTISTRING_CHOOSER]])
        #endif
            gBattleStruct->safariEscapeFactor = 1;
        else
            gBattleStruct->safariEscapeFactor -= sPkblToEscapeFactor[gBattleStruct->safariPkblThrowCounter][gBattleCommunication[MULTISTRING_CHOOSER]];
    }

    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[2];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_GoNear(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;

    gBattleStruct->safariCatchFactor += sGoNearCounterToCatchFactor[gBattleStruct->safariGoNearCounter];
    if (gBattleStruct->safariCatchFactor > 20)
        gBattleStruct->safariCatchFactor = 20;

    gBattleStruct->safariEscapeFactor += sGoNearCounterToEscapeFactor[gBattleStruct->safariGoNearCounter];
    if (gBattleStruct->safariEscapeFactor > 20)
        gBattleStruct->safariEscapeFactor = 20;

    if (gBattleStruct->safariGoNearCounter < 3)
    {
        gBattleStruct->safariGoNearCounter++;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CREPT_CLOSER;
    }
    else
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CANT_GET_CLOSER;
    }
    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[1];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_SafariZoneRun(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    PlaySE(SE_FLEE);
    gCurrentTurnActionNumber = gBattlersCount;
    gBattleOutcome = B_OUTCOME_RAN;
}

void HandleAction_WallyBallThrow(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, gBattlerPartyIndexes[gBattlerAttacker])

    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[3];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
    gActionsByTurnOrder[1] = B_ACTION_FINISHED;
}

void HandleAction_TryFinish(void)
{
    if (!HandleFaintedMonActions())
    {
        gBattleStruct->faintedActionsState = 0;
        gCurrentActionFuncId = B_ACTION_FINISHED;
    }
}

void HandleAction_NothingIsFainted(void)
{
    RecalculateMoveOrder(++gCurrentTurnActionNumber + (gAfterYouBattlers ? gAfterYouBattlers-- : 0), gBattlersCount - (gQuashedBattlers ? gQuashedBattlers-- : 0));
    gCurrentActionFuncId = gActionsByTurnOrder[gCurrentTurnActionNumber];
    gHitMarker &= ~(HITMARKER_DESTINYBOND | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_ATTACKSTRING_PRINTED
                    | HITMARKER_NO_PPDEDUCT | HITMARKER_IGNORE_SAFEGUARD | HITMARKER_PASSIVE_DAMAGE
                    | HITMARKER_OBEYS | HITMARKER_x10 | HITMARKER_SYNCHRONISE_EFFECT
                    | HITMARKER_CHARGING | HITMARKER_x4000000 | HITMARKER_IGNORE_DISGUISE);
}

void HandleAction_ActionFinished(void)
{
    *(gBattleStruct->monToSwitchIntoId + gBattlerByTurnOrder[gCurrentTurnActionNumber]) = 6;
    RecalculateMoveOrder(++gCurrentTurnActionNumber + (gAfterYouBattlers ? gAfterYouBattlers-- : 0), gBattlersCount - (gQuashedBattlers ? gQuashedBattlers-- : 0));
    gCurrentActionFuncId = gActionsByTurnOrder[gCurrentTurnActionNumber];
    SpecialStatusesClear();
    gHitMarker &= ~(HITMARKER_DESTINYBOND | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_ATTACKSTRING_PRINTED
                    | HITMARKER_NO_PPDEDUCT | HITMARKER_IGNORE_SAFEGUARD | HITMARKER_PASSIVE_DAMAGE
                    | HITMARKER_OBEYS | HITMARKER_x10 | HITMARKER_SYNCHRONISE_EFFECT
                    | HITMARKER_CHARGING | HITMARKER_x4000000 | HITMARKER_IGNORE_DISGUISE);

    gCurrentMove = 0;
    gBattleMoveDamage = 0;
    gMoveResultFlags = 0;
    gBattleScripting.animTurn = 0;
    gBattleScripting.animTargetsHit = 0;
    gLastLandedMoves[gBattlerAttacker] = 0;
    gLastHitByType[gBattlerAttacker] = 0;
    gProtectStructs[gBattlerAttacker].extraMoveUsed = 0;
    gBattleStruct->dynamicMoveType = 0;
    gBattleScripting.moveendState = 0;
    gBattleScripting.moveendState = 0;
    gBattleCommunication[3] = 0;
    gBattleCommunication[4] = 0;
    gBattleScripting.multihitMoveEffect = 0;
    gBattleResources->battleScriptsStack->size = 0;
}

// rom const data

static const u8 sAbilitiesAffectedByMoldBreaker[ABILITIES_COUNT] =
{
    [ABILITY_BATTLE_ARMOR] = 1,
    [ABILITY_CLEAR_BODY] = 1,
    [ABILITY_DAMP] = 1,
    [ABILITY_DRY_SKIN] = 1,
    [ABILITY_FILTER] = 1,
    [ABILITY_FLASH_FIRE] = 1,
    [ABILITY_FLOWER_GIFT] = 1,
    [ABILITY_HEATPROOF] = 1,
    [ABILITY_HYPER_CUTTER] = 1,
    [ABILITY_IMMUNITY] = 1,
    [ABILITY_INNER_FOCUS] = 1,
    [ABILITY_INSOMNIA] = 1,
    [ABILITY_KEEN_EYE] = 1,
    [ABILITY_LEAF_GUARD] = 1,
    [ABILITY_LEVITATE] = 1,
    [ABILITY_LIGHTNING_ROD] = 1,
    [ABILITY_LIMBER] = 1,
    [ABILITY_MAGMA_ARMOR] = 1,
    [ABILITY_MARVEL_SCALE] = 1,
    [ABILITY_MOTOR_DRIVE] = 1,
    [ABILITY_OBLIVIOUS] = 1,
    [ABILITY_OWN_TEMPO] = 1,
    [ABILITY_SAND_VEIL] = 1,
    [ABILITY_SHELL_ARMOR] = 1,
    [ABILITY_SHIELD_DUST] = 1,
    [ABILITY_SNOW_CLOAK] = 1,
    [ABILITY_SOLID_ROCK] = 1,
    [ABILITY_SOUNDPROOF] = 1,
    [ABILITY_STICKY_HOLD] = 1,
    [ABILITY_STORM_DRAIN] = 1,
    [ABILITY_STURDY] = 1,
    [ABILITY_SUCTION_CUPS] = 1,
    [ABILITY_TANGLED_FEET] = 1,
    [ABILITY_THICK_FAT] = 1,
    [ABILITY_UNAWARE] = 1,
    [ABILITY_VITAL_SPIRIT] = 1,
    [ABILITY_VOLT_ABSORB] = 1,
    [ABILITY_WATER_ABSORB] = 1,
    [ABILITY_WATER_VEIL] = 1,
    [ABILITY_WHITE_SMOKE] = 1,
    [ABILITY_WONDER_GUARD] = 1,
    [ABILITY_BIG_PECKS] = 1,
    [ABILITY_CONTRARY] = 1,
    [ABILITY_FRIEND_GUARD] = 1,
    [ABILITY_HEAVY_METAL] = 1,
    [ABILITY_LIGHT_METAL] = 1,
    [ABILITY_MAGIC_BOUNCE] = 1,
    [ABILITY_MULTISCALE] = 1,
    [ABILITY_SAP_SIPPER] = 1,
    [ABILITY_TELEPATHY] = 1,
    [ABILITY_WONDER_SKIN] = 1,
    [ABILITY_AROMA_VEIL] = 1,
    [ABILITY_BULLETPROOF] = 1,
    [ABILITY_FLOWER_VEIL] = 1,
    [ABILITY_FUR_COAT] = 1,
    [ABILITY_OVERCOAT] = 1,
    [ABILITY_SWEET_VEIL] = 1,
    [ABILITY_DAZZLING] = 1,
    [ABILITY_DISGUISE] = 1,
    [ABILITY_FLUFFY] = 1,
    [ABILITY_QUEENLY_MAJESTY] = 1,
    [ABILITY_WATER_BUBBLE] = 1,
    [ABILITY_MIRROR_ARMOR] = 1,
    [ABILITY_PUNK_ROCK] = 1,
    [ABILITY_ICE_SCALES] = 1,
    [ABILITY_ICE_FACE] = 1,

    // New abilities
    [ABILITY_DUNE_TERROR] = 1,
    [ABILITY_GIFTED_MIND] = 1,
    [ABILITY_HYDRO_CIRCUIT] = 1,
    [ABILITY_DESERT_CLOAK] = 1,
    [ABILITY_ARCTIC_FUR] = 1,
    [ABILITY_BIG_LEAVES] = 1,
    [ABILITY_POISON_ABSORB] = 1,
    [ABILITY_SEAWEED] = 1,
    [ABILITY_RAW_WOOD] = 1,
    [ABILITY_BAD_LUCK] = 1,
    [ABILITY_JUGGERNAUT] = 1,
    [ABILITY_MOUNTAINEER] = 1,
    [ABILITY_DRAGONFLY] = 1,
    [ABILITY_LIQUIFIED] = 1,
    [ABILITY_FOSSILIZED] = 1,
    [ABILITY_LEAD_COAT] = 1,
    [ABILITY_CHRISTMAS_SPIRIT] = 1,
    [ABILITY_AERODYNAMICS] = 1,
    [ABILITY_WATER_COMPACTION] = 1,
    [ABILITY_GRASS_PELT] = 1,
    [ABILITY_PRIMAL_ARMOR] = 1,
    [ABILITY_WEATHER_CONTROL] = 1,
    [ABILITY_ICE_DEW] = 1,
    [ABILITY_WELL_BAKED_BODY] = 1,
    [ABILITY_EVAPORATE] = 1,
    [ABILITY_RADIANCE] = 1,
    [ABILITY_JUNGLES_GUARD] = 1,
    [ABILITY_EARTH_EATER] = 1,
    [ABILITY_SAND_GUARD] = 1,
    [ABILITY_WIND_RIDER] = 1,
    [ABILITY_ENLIGHTENED] = 1,
    [ABILITY_BASS_BOOSTED] = 1,
    [ABILITY_CHROME_COAT] = 1,
    [ABILITY_PURIFYING_SALT] = 1,
    [ABILITY_LEAF_GUARD_CLONE] = 1,
    [ABILITY_GOOD_AS_GOLD] = 1,
    [ABILITY_THERMAL_EXCHANGE] = 1,
    [ABILITY_NOISE_CANCEL] = 1,
    // Intentionally not included: 
    //   Color Change
    //   Prismatic Fur
    //   Cheating Death
    //   Delta Stream
};

static const u8 sHoldEffectToType[][2] =
{
    {HOLD_EFFECT_BUG_POWER, TYPE_BUG},
    {HOLD_EFFECT_STEEL_POWER, TYPE_STEEL},
    {HOLD_EFFECT_GROUND_POWER, TYPE_GROUND},
    {HOLD_EFFECT_ROCK_POWER, TYPE_ROCK},
    {HOLD_EFFECT_GRASS_POWER, TYPE_GRASS},
    {HOLD_EFFECT_DARK_POWER, TYPE_DARK},
    {HOLD_EFFECT_FIGHTING_POWER, TYPE_FIGHTING},
    {HOLD_EFFECT_ELECTRIC_POWER, TYPE_ELECTRIC},
    {HOLD_EFFECT_WATER_POWER, TYPE_WATER},
    {HOLD_EFFECT_FLYING_POWER, TYPE_FLYING},
    {HOLD_EFFECT_POISON_POWER, TYPE_POISON},
    {HOLD_EFFECT_ICE_POWER, TYPE_ICE},
    {HOLD_EFFECT_GHOST_POWER, TYPE_GHOST},
    {HOLD_EFFECT_PSYCHIC_POWER, TYPE_PSYCHIC},
    {HOLD_EFFECT_FIRE_POWER, TYPE_FIRE},
    {HOLD_EFFECT_DRAGON_POWER, TYPE_DRAGON},
    {HOLD_EFFECT_NORMAL_POWER, TYPE_NORMAL},
    {HOLD_EFFECT_FAIRY_POWER, TYPE_FAIRY},
};

// percent in UQ_4_12 format
static const u16 sPercentToModifier[] =
{
    UQ_4_12(0.00), // 0
    UQ_4_12(0.01), // 1
    UQ_4_12(0.02), // 2
    UQ_4_12(0.03), // 3
    UQ_4_12(0.04), // 4
    UQ_4_12(0.05), // 5
    UQ_4_12(0.06), // 6
    UQ_4_12(0.07), // 7
    UQ_4_12(0.08), // 8
    UQ_4_12(0.09), // 9
    UQ_4_12(0.10), // 10
    UQ_4_12(0.11), // 11
    UQ_4_12(0.12), // 12
    UQ_4_12(0.13), // 13
    UQ_4_12(0.14), // 14
    UQ_4_12(0.15), // 15
    UQ_4_12(0.16), // 16
    UQ_4_12(0.17), // 17
    UQ_4_12(0.18), // 18
    UQ_4_12(0.19), // 19
    UQ_4_12(0.20), // 20
    UQ_4_12(0.21), // 21
    UQ_4_12(0.22), // 22
    UQ_4_12(0.23), // 23
    UQ_4_12(0.24), // 24
    UQ_4_12(0.25), // 25
    UQ_4_12(0.26), // 26
    UQ_4_12(0.27), // 27
    UQ_4_12(0.28), // 28
    UQ_4_12(0.29), // 29
    UQ_4_12(0.30), // 30
    UQ_4_12(0.31), // 31
    UQ_4_12(0.32), // 32
    UQ_4_12(0.33), // 33
    UQ_4_12(0.34), // 34
    UQ_4_12(0.35), // 35
    UQ_4_12(0.36), // 36
    UQ_4_12(0.37), // 37
    UQ_4_12(0.38), // 38
    UQ_4_12(0.39), // 39
    UQ_4_12(0.40), // 40
    UQ_4_12(0.41), // 41
    UQ_4_12(0.42), // 42
    UQ_4_12(0.43), // 43
    UQ_4_12(0.44), // 44
    UQ_4_12(0.45), // 45
    UQ_4_12(0.46), // 46
    UQ_4_12(0.47), // 47
    UQ_4_12(0.48), // 48
    UQ_4_12(0.49), // 49
    UQ_4_12(0.50), // 50
    UQ_4_12(0.51), // 51
    UQ_4_12(0.52), // 52
    UQ_4_12(0.53), // 53
    UQ_4_12(0.54), // 54
    UQ_4_12(0.55), // 55
    UQ_4_12(0.56), // 56
    UQ_4_12(0.57), // 57
    UQ_4_12(0.58), // 58
    UQ_4_12(0.59), // 59
    UQ_4_12(0.60), // 60
    UQ_4_12(0.61), // 61
    UQ_4_12(0.62), // 62
    UQ_4_12(0.63), // 63
    UQ_4_12(0.64), // 64
    UQ_4_12(0.65), // 65
    UQ_4_12(0.66), // 66
    UQ_4_12(0.67), // 67
    UQ_4_12(0.68), // 68
    UQ_4_12(0.69), // 69
    UQ_4_12(0.70), // 70
    UQ_4_12(0.71), // 71
    UQ_4_12(0.72), // 72
    UQ_4_12(0.73), // 73
    UQ_4_12(0.74), // 74
    UQ_4_12(0.75), // 75
    UQ_4_12(0.76), // 76
    UQ_4_12(0.77), // 77
    UQ_4_12(0.78), // 78
    UQ_4_12(0.79), // 79
    UQ_4_12(0.80), // 80
    UQ_4_12(0.81), // 81
    UQ_4_12(0.82), // 82
    UQ_4_12(0.83), // 83
    UQ_4_12(0.84), // 84
    UQ_4_12(0.85), // 85
    UQ_4_12(0.86), // 86
    UQ_4_12(0.87), // 87
    UQ_4_12(0.88), // 88
    UQ_4_12(0.89), // 89
    UQ_4_12(0.90), // 90
    UQ_4_12(0.91), // 91
    UQ_4_12(0.92), // 92
    UQ_4_12(0.93), // 93
    UQ_4_12(0.94), // 94
    UQ_4_12(0.95), // 95
    UQ_4_12(0.96), // 96
    UQ_4_12(0.97), // 97
    UQ_4_12(0.98), // 98
    UQ_4_12(0.99), // 99
    UQ_4_12(1.00), // 100
};

#define X UQ_4_12

static const u16 sTypeEffectivenessTable[NUMBER_OF_MON_TYPES][NUMBER_OF_MON_TYPES] =
{
//   normal  fight   flying  poison  ground  rock    bug     ghost   steel   mystery fire    water   grass  electric psychic ice     dragon  dark    fairy
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(0.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0)}, // normal
    {X(2.0), X(1.0), X(0.5), X(0.5), X(1.0), X(2.0), X(0.5), X(0.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(2.0), X(1.0), X(2.0), X(0.5)}, // fight
    {X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(0.5), X(2.0), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(2.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0)}, // flying
    {X(1.0), X(1.0), X(1.0), X(0.5), X(0.5), X(0.5), X(1.0), X(0.5), X(0.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0)}, // poison
    {X(1.0), X(1.0), X(0.0), X(2.0), X(1.0), X(2.0), X(0.5), X(1.0), X(2.0), X(1.0), X(2.0), X(1.0), X(0.5), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0)}, // ground
    {X(1.0), X(0.5), X(2.0), X(1.0), X(0.5), X(1.0), X(2.0), X(1.0), X(0.5), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0)}, // rock
    {X(1.0), X(0.5), X(0.5), X(0.5), X(1.0), X(1.0), X(1.0), X(0.5), X(0.5), X(1.0), X(0.5), X(1.0), X(2.0), X(1.0), X(2.0), X(1.0), X(1.0), X(2.0), X(0.5)}, // bug
    #if B_STEEL_RESISTANCES >= GEN_6
    {X(0.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(0.5), X(1.0)}, // ghost
    #else
    {X(0.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(0.5), X(1.0)}, // ghost
    #endif
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(0.5), X(1.0), X(0.5), X(0.5), X(1.0), X(0.5), X(1.0), X(2.0), X(1.0), X(1.0), X(2.0)}, // steel
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0)}, // mystery
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(2.0), X(1.0), X(2.0), X(1.0), X(0.5), X(0.5), X(2.0), X(1.0), X(1.0), X(2.0), X(0.5), X(1.0), X(1.0)}, // fire
    {X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(0.5), X(0.5), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0)}, // water
    {X(1.0), X(1.0), X(0.5), X(0.5), X(2.0), X(2.0), X(0.5), X(1.0), X(0.5), X(1.0), X(0.5), X(2.0), X(0.5), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0)}, // grass
    {X(1.0), X(1.0), X(2.0), X(1.0), X(0.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(0.5), X(0.5), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0)}, // electric
    {X(1.0), X(2.0), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(0.0), X(1.0)}, // psychic
    {X(1.0), X(1.0), X(2.0), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(0.5), X(0.5), X(2.0), X(1.0), X(1.0), X(0.5), X(2.0), X(1.0), X(1.0)}, // ice
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(0.0)}, // dragon
    #if B_STEEL_RESISTANCES >= GEN_6
    {X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(0.5), X(0.5)}, // dark
    #else
    {X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(0.5), X(0.5)}, // dark
    #endif
    {X(1.0), X(2.0), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(2.0), X(1.0)}, // fairy
};

static const u16 sInverseTypeEffectivenessTable[NUMBER_OF_MON_TYPES][NUMBER_OF_MON_TYPES] =
{
//   normal  fight   flying  poison  ground  rock    bug     ghost   steel   mystery fire    water   grass  electric psychic ice     dragon  dark    fairy
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(2.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0)}, // normal
    {X(0.5), X(1.0), X(2.0), X(2.0), X(1.0), X(0.5), X(2.0), X(2.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(0.5), X(1.0), X(0.5), X(2.0)}, // fight
    {X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(2.0), X(0.5), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(0.5), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0)}, // flying
    {X(1.0), X(1.0), X(1.0), X(2.0), X(2.0), X(2.0), X(1.0), X(2.0), X(2.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5)}, // poison
    {X(1.0), X(1.0), X(2.0), X(0.5), X(1.0), X(0.5), X(2.0), X(1.0), X(0.5), X(1.0), X(0.5), X(1.0), X(2.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0)}, // ground
    {X(1.0), X(2.0), X(0.5), X(1.0), X(2.0), X(1.0), X(0.5), X(1.0), X(2.0), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0)}, // rock
    {X(1.0), X(2.0), X(2.0), X(2.0), X(1.0), X(1.0), X(1.0), X(2.0), X(2.0), X(1.0), X(2.0), X(1.0), X(0.5), X(1.0), X(0.5), X(1.0), X(1.0), X(0.5), X(2.0)}, // bug
    #if B_STEEL_RESISTANCES >= GEN_6
    {X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(2.0), X(1.0)}, // ghost
    #else
    {X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(2.0), X(1.0)}, // ghost
    #endif
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(2.0), X(1.0), X(2.0), X(2.0), X(1.0), X(2.0), X(1.0), X(0.5), X(1.0), X(1.0), X(0.5)}, // steel
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0)}, // mystery
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(0.5), X(1.0), X(0.5), X(1.0), X(2.0), X(2.0), X(0.5), X(1.0), X(1.0), X(0.5), X(2.0), X(1.0), X(1.0)}, // fire
    {X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(2.0), X(2.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0)}, // water
    {X(1.0), X(1.0), X(2.0), X(2.0), X(0.5), X(0.5), X(2.0), X(1.0), X(2.0), X(1.0), X(2.0), X(0.5), X(2.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0)}, // grass
    {X(1.0), X(1.0), X(0.5), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(2.0), X(2.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0)}, // electric
    {X(1.0), X(0.5), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(2.0), X(1.0)}, // psychic
    {X(1.0), X(1.0), X(0.5), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(2.0), X(2.0), X(0.5), X(1.0), X(1.0), X(2.0), X(0.5), X(1.0), X(1.0)}, // ice
    {X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(2.0)}, // dragon
    #if B_STEEL_RESISTANCES >= GEN_6
    {X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(2.0), X(2.0)}, // dark
    #else
    {X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(1.0), X(1.0), X(2.0), X(2.0)}, // dark
    #endif
    {X(1.0), X(0.5), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(2.0), X(1.0), X(2.0), X(1.0), X(1.0), X(1.0), X(1.0), X(1.0), X(0.5), X(0.5), X(1.0)}, // fairy
};

#undef X

// code
u8 GetBattlerForBattleScript(u8 caseId)
{
    u8 ret = 0;
    switch (caseId)
    {
    case BS_TARGET:
        ret = gBattlerTarget;
        break;
    case BS_ATTACKER:
        ret = gBattlerAttacker;
        break;
    case BS_EFFECT_BATTLER:
        ret = gEffectBattler;
        break;
    case BS_BATTLER_0:
        ret = 0;
        break;
    case BS_SCRIPTING:
        ret = gBattleScripting.battler;
        break;
    case BS_FAINTED:
        ret = gBattlerFainted;
        break;
    case 5:
        ret = gBattlerFainted;
        break;
    case 4:
    case 6:
    case 8:
    case 9:
    case BS_PLAYER1:
        ret = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        break;
    case BS_OPPONENT1:
        ret = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        break;
    case BS_PLAYER2:
        ret = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
        break;
    case BS_OPPONENT2:
        ret = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
        break;
    case BS_ABILITY_BATTLER:
        ret = gBattlerAbility;
        break;
    case BS_ABILITY_PARTNER:
        ret = BATTLE_PARTNER(gBattlerAbility);
        break;
    case BS_TARGET_PARTNER:
        ret = BATTLE_PARTNER(gBattlerTarget);
        break;
    case BS_ATTACKER_PARTNER:
        ret = BATTLE_PARTNER(gBattlerAttacker);
        break;
    }
    return ret;
}

void MarkAllBattlersForControllerExec(void) // unused
{
    int i;

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        for (i = 0; i < gBattlersCount; i++)
            gBattleControllerExecFlags |= gBitTable[i] << (32 - MAX_BATTLERS_COUNT);
    }
    else
    {
        for (i = 0; i < gBattlersCount; i++)
            gBattleControllerExecFlags |= gBitTable[i];
    }
}

bool32 IsBattlerMarkedForControllerExec(u8 battlerId)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        return (gBattleControllerExecFlags & (gBitTable[battlerId] << 0x1C)) != 0;
    else
        return (gBattleControllerExecFlags & (gBitTable[battlerId])) != 0;
}

void MarkBattlerForControllerExec(u8 battlerId)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        gBattleControllerExecFlags |= gBitTable[battlerId] << (32 - MAX_BATTLERS_COUNT);
    else
        gBattleControllerExecFlags |= gBitTable[battlerId];
}

void MarkBattlerReceivedLinkData(u8 battlerId)
{
    s32 i;

    for (i = 0; i < GetLinkPlayerCount(); i++)
        gBattleControllerExecFlags |= gBitTable[battlerId] << (i << 2);

    gBattleControllerExecFlags &= ~(0x10000000 << battlerId);
}

void CancelMultiTurnMoves(u8 battler)
{
    gBattleMons[battler].status2 &= ~(STATUS2_MULTIPLETURNS);
    gBattleMons[battler].status2 &= ~(STATUS2_LOCK_CONFUSE);
    gBattleMons[battler].status2 &= ~(STATUS2_UPROAR);
    gBattleMons[battler].status2 &= ~(STATUS2_BIDE);

    gStatuses3[battler] &= ~(STATUS3_SEMI_INVULNERABLE);

    gDisableStructs[battler].rolloutTimer = 0;
    gDisableStructs[battler].furyCutterCounter = 0;
}

bool8 WasUnableToUseMove(u8 battler)
{
    if (gProtectStructs[battler].prlzImmobility
        || gProtectStructs[battler].usedImprisonedMove
        || gProtectStructs[battler].loveImmobility
        || gProtectStructs[battler].usedDisabledMove
        || gProtectStructs[battler].usedTauntedMove
        || gProtectStructs[battler].usedGravityPreventedMove
        || gProtectStructs[battler].usedHealBlockedMove
        || gProtectStructs[battler].flag2Unknown
        || gProtectStructs[battler].flinchImmobility
        || gProtectStructs[battler].confusionSelfDmg
        || gProtectStructs[battler].powderSelfDmg
        || gProtectStructs[battler].usedThroatChopPreventedMove)
        return TRUE;
    else
        return FALSE;
}

void PrepareStringBattle(u16 stringId, u8 battler)
{
    bool8 hasContrary = BATTLER_HAS_ABILITY(battler, ABILITY_CONTRARY);
    bool8 targetHasContrary = BATTLER_HAS_ABILITY(gBattlerTarget, ABILITY_CONTRARY);

    //Overwrite
    if(VarGet(VAR_TEMP_BATTLE_STRING_OVERWRITE_1) != 0){
        stringId = VarGet(VAR_TEMP_BATTLE_STRING_OVERWRITE_1);
        VarSet(VAR_TEMP_BATTLE_STRING_OVERWRITE_1, 0);
    }
    else if(VarGet(VAR_TEMP_BATTLE_STRING_OVERWRITE_2) != 0){
        stringId = VarGet(VAR_TEMP_BATTLE_STRING_OVERWRITE_2);
        VarSet(VAR_TEMP_BATTLE_STRING_OVERWRITE_2, 0);
    }
    else if(VarGet(VAR_TEMP_BATTLE_STRING_OVERWRITE_3) != 0){
        stringId = VarGet(VAR_TEMP_BATTLE_STRING_OVERWRITE_3);
        VarSet(VAR_TEMP_BATTLE_STRING_OVERWRITE_3, 0);
    }
    else if(VarGet(VAR_TEMP_BATTLE_STRING_OVERWRITE_4) != 0){
        stringId = VarGet(VAR_TEMP_BATTLE_STRING_OVERWRITE_4);
        VarSet(VAR_TEMP_BATTLE_STRING_OVERWRITE_4, 0);
    }

    // Support for Contrary ability.
    // If a move attempted to raise stat - print "won't increase".
    // If a move attempted to lower stat - print "won't decrease".
    if (stringId == STRINGID_STATSWONTDECREASE && !(gBattleScripting.statChanger & STAT_BUFF_NEGATIVE))
        stringId = STRINGID_STATSWONTINCREASE;
    else if (stringId == STRINGID_STATSWONTINCREASE && gBattleScripting.statChanger & STAT_BUFF_NEGATIVE)
        stringId = STRINGID_STATSWONTDECREASE;
    else if (stringId == STRINGID_STATSWONTDECREASE2 && hasContrary)
        stringId = STRINGID_STATSWONTINCREASE2;
    else if (stringId == STRINGID_STATSWONTINCREASE2 && hasContrary)
        stringId = STRINGID_STATSWONTDECREASE2;
    else if (stringId == STRINGID_PKMNCUTSSTATWITHINTIMIDATECLONE && (targetHasContrary || BATTLER_HAS_ABILITY(gBattlerTarget, ABILITY_GUARD_DOG)))
        stringId = STRINGID_PKMNRAISESSTATWITHINTIMIDATECLONE;
    else if (stringId == STRINGID_PKMNCUTSSTATWITHINTIMIDATECLONE2 && (targetHasContrary || BATTLER_HAS_ABILITY(gBattlerTarget, ABILITY_GUARD_DOG)))
        stringId = STRINGID_PKMNRAISESSTATWITHINTIMIDATECLONE2;
    else if (stringId == STRINGID_PKMNCUTSSTATWITHINTIMIDATECLONE3 && (targetHasContrary || BATTLER_HAS_ABILITY(gBattlerTarget, ABILITY_GUARD_DOG)))
        stringId = STRINGID_PKMNRAISESSTATWITHINTIMIDATECLONE3;
    else if((stringId == STRINGID_DEFENDERSSTATFELL) &&
            (GetBattlerAbility(gBattlerTarget) == ABILITY_KINGS_WRATH                 || BattlerHasInnate(gBattlerTarget, ABILITY_KINGS_WRATH) || 
             GetBattlerAbility(BATTLE_PARTNER(gBattlerTarget)) == ABILITY_KINGS_WRATH || BattlerHasInnate(BATTLE_PARTNER(gBattlerTarget), ABILITY_KINGS_WRATH)) &&
             gSpecialStatuses[gBattlerTarget].changedStatsBattlerId != BATTLE_PARTNER(gBattlerTarget) &&
             gSpecialStatuses[gBattlerTarget].changedStatsBattlerId != gBattlerTarget){
            
            //Overwrites the Popout
			gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_KINGS_WRATH;
            //Overwrites where it's written
            if(GetBattlerAbility(BATTLE_PARTNER(gBattlerTarget)) == ABILITY_KINGS_WRATH || BattlerHasInnate(BATTLE_PARTNER(gBattlerTarget), ABILITY_KINGS_WRATH)){
                gBattleScripting.battlerPopupOverwrite = BATTLE_PARTNER(gBattlerTarget);
                gBattlerAbility = BATTLE_PARTNER(gBattlerTarget);
            }
            else
                gBattlerAbility = gBattlerTarget;

            ChangeStatBuffs(gBattlerAbility, StatBuffValue(1), STAT_ATK, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
            ChangeStatBuffs(gBattlerAbility, StatBuffValue(1), STAT_DEF, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
            
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_KingsWrathActivated;
    }
    else if((stringId == STRINGID_DEFENDERSSTATFELL) &&
            (GetBattlerAbility(gBattlerTarget) == ABILITY_QUEENS_MOURNING                 || BattlerHasInnate(gBattlerTarget, ABILITY_QUEENS_MOURNING) || 
             GetBattlerAbility(BATTLE_PARTNER(gBattlerTarget)) == ABILITY_QUEENS_MOURNING || BattlerHasInnate(BATTLE_PARTNER(gBattlerTarget), ABILITY_QUEENS_MOURNING)) &&
             gSpecialStatuses[gBattlerTarget].changedStatsBattlerId != BATTLE_PARTNER(gBattlerTarget) &&
             gSpecialStatuses[gBattlerTarget].changedStatsBattlerId != gBattlerTarget){
            
            //Overwrites the Popout
			gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_QUEENS_MOURNING;
            //Overwrites where it's written
            if(GetBattlerAbility(BATTLE_PARTNER(gBattlerTarget)) == ABILITY_QUEENS_MOURNING || BattlerHasInnate(BATTLE_PARTNER(gBattlerTarget), ABILITY_QUEENS_MOURNING)){
                gBattleScripting.battlerPopupOverwrite = BATTLE_PARTNER(gBattlerTarget);
                gBattlerAbility = BATTLE_PARTNER(gBattlerTarget);
            }
            else
                gBattlerAbility = gBattlerTarget;

            ChangeStatBuffs(gBattlerAbility, StatBuffValue(1), STAT_SPATK, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
            ChangeStatBuffs(gBattlerAbility, StatBuffValue(1), STAT_SPDEF, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
            
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_QueensMourningActivated;
    }
    else if (stringId == STRINGID_DEFENDERSSTATFELL && BATTLER_HAS_ABILITY(gBattlerTarget, ABILITY_DEFIANT))
    {
        gBattlerAbility = gBattlerTarget;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_DefiantActivates;
    }
    else if (stringId == STRINGID_DEFENDERSSTATFELL && BATTLER_HAS_ABILITY(gBattlerTarget, ABILITY_COMPETITIVE))
    {
        gBattlerAbility = gBattlerTarget;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_CompetitiveActivates;
    }
    else if (stringId == STRINGID_DEFENDERSSTATFELL && BATTLER_HAS_ABILITY(gBattlerTarget, ABILITY_FORT_KNOX))
    {
        gBattlerAbility = gBattlerTarget;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_FortKnoxActivates;
    }
    else if (stringId == STRINGID_DEFENDERSSTATFELL && BATTLER_HAS_ABILITY(gBattlerTarget, ABILITY_RUN_AWAY))
    {
        gBattlerAbility = gBattlerTarget;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_RunAwayActivates;
    }
    
    gActiveBattler = battler;
    BtlController_EmitPrintString(0, stringId);
    MarkBattlerForControllerExec(gActiveBattler);
}

void ResetSentPokesToOpponentValue(void)
{
    s32 i;
    u32 bits = 0;

    gSentPokesToOpponent[0] = 0;
    gSentPokesToOpponent[1] = 0;

    for (i = 0; i < gBattlersCount; i += 2)
        bits |= gBitTable[gBattlerPartyIndexes[i]];

    for (i = 1; i < gBattlersCount; i += 2)
        gSentPokesToOpponent[(i & BIT_FLANK) >> 1] = bits;
}

void OpponentSwitchInResetSentPokesToOpponentValue(u8 battler)
{
    s32 i = 0;
    u32 bits = 0;

    if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        u8 flank = ((battler & BIT_FLANK) >> 1);
        gSentPokesToOpponent[flank] = 0;

        for (i = 0; i < gBattlersCount; i += 2)
        {
            if (!(gAbsentBattlerFlags & gBitTable[i]))
                bits |= gBitTable[gBattlerPartyIndexes[i]];
        }

        gSentPokesToOpponent[flank] = bits;
    }
}

void UpdateSentPokesToOpponentValue(u8 battler)
{
    if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        OpponentSwitchInResetSentPokesToOpponentValue(battler);
    }
    else
    {
        s32 i;
        for (i = 1; i < gBattlersCount; i++)
            gSentPokesToOpponent[(i & BIT_FLANK) >> 1] |= gBitTable[gBattlerPartyIndexes[battler]];
    }
}

void BattleScriptPush(const u8 *bsPtr)
{
    struct SavedStackData savedStackData = 
        {
            .abilityOverride = gBattleScripting.abilityPopupOverwrite,
        };
    gBattleResources->battleScriptsStack->savedStackData[gBattleResources->battleScriptsStack->size] = savedStackData;
    gBattleResources->battleScriptsStack->ptr[gBattleResources->battleScriptsStack->size++] = bsPtr;
}

void BattleScriptPushCursor(void)
{
    struct SavedStackData savedStackData = 
        {
            .abilityOverride = gBattleScripting.abilityPopupOverwrite,
        };
    gBattleResources->battleScriptsStack->savedStackData[gBattleResources->battleScriptsStack->size] = savedStackData;
    gBattleResources->battleScriptsStack->ptr[gBattleResources->battleScriptsStack->size++] = gBattlescriptCurrInstr;
}

void BattleScriptPop(void)
{
    gBattlescriptCurrInstr = gBattleResources->battleScriptsStack->ptr[--gBattleResources->battleScriptsStack->size];
    if (gBattleResources->battleScriptsStack->size > 0)
    {
        struct SavedStackData *data = &gBattleResources->battleScriptsStack->savedStackData[gBattleResources->battleScriptsStack->size - 1];
        // Abilities typically get overwritten and then stored, so they will generally be one position ahead
        gBattleScripting.abilityPopupOverwrite = data->abilityOverride;
    }
}

bool32 IsGravityPreventingMove(u32 move)
{
    if (!IsGravityActive())
        return FALSE;

    switch (move)
    {
    case MOVE_BOUNCE:
    case MOVE_FLY:
    case MOVE_FLYING_PRESS:
    case MOVE_HIGH_JUMP_KICK:
    case MOVE_JUMP_KICK:
    case MOVE_MAGNET_RISE:
    case MOVE_SKY_DROP:
    case MOVE_SPLASH:
    case MOVE_TELEKINESIS:
    case MOVE_FLOATY_FALL:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsHealBlockPreventingMove(u8 battler, u32 move)
{
    if (!(gStatuses3[battler] & STATUS3_HEAL_BLOCK) && !IsAbilityOnOpposingSide(battler, ABILITY_PERMANENCE))
        return FALSE;
    
    switch (gBattleMoves[move].effect)
    {
    case EFFECT_MORNING_SUN:
    case EFFECT_MOONLIGHT:
    case EFFECT_RESTORE_HP:
    case EFFECT_REST:
    case EFFECT_ROOST:
    case EFFECT_WISH:
    case EFFECT_HEALING_WISH:
    case EFFECT_REVIVAL_BLESSING:
        return TRUE;
    default:
        return FALSE;
    }
}

static bool32 IsBelchPreventingMove(u32 battler, u32 move)
{
    if (gBattleMoves[move].effect != EFFECT_BELCH)
        return FALSE;

    return !(gBattleStruct->ateBerry[battler & BIT_SIDE] & gBitTable[gBattlerPartyIndexes[battler]]);
}

u8 TrySetCantSelectMoveBattleScript(void)
{
    u32 limitations = 0;
    u8 moveId = gBattleResources->bufferB[gActiveBattler][2] & ~(RET_MEGA_EVOLUTION);
    u32 move = gBattleMons[gActiveBattler].moves[moveId];
    u32 holdEffect = GetBattlerHoldEffect(gActiveBattler, TRUE);
    u16 *choicedMove = &gBattleStruct->choicedMove[gActiveBattler];

    if (gDisableStructs[gActiveBattler].disabledMove == move && move != MOVE_NONE)
    {
        gBattleScripting.battler = gActiveBattler;
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingDisabledMoveInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingDisabledMove;
            limitations++;
        }
    }

    if (move == gLastMoves[gActiveBattler] && move != MOVE_STRUGGLE && (gBattleMons[gActiveBattler].status2 & STATUS2_TORMENT))
    {
        CancelMultiTurnMoves(gActiveBattler);
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingTormentedMoveInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingTormentedMove;
            limitations++;
        }
    }

    if (gDisableStructs[gActiveBattler].tauntTimer != 0 && gBattleMoves[move].power == 0)
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveTauntInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveTaunt;
            limitations++;
        }
    }

    if (gDisableStructs[gActiveBattler].throatChopTimer != 0 && gBattleMoves[move].flags & FLAG_SOUND)
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveThroatChopInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveThroatChop;
            limitations++;
        }
    }

    if (GetImprisonedMovesCount(gActiveBattler, move))
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingImprisonedMoveInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingImprisonedMove;
            limitations++;
        }
    }

    if (IsGravityPreventingMove(move))
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveGravityInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveGravity;
            limitations++;
        }
    }

    if (IsHealBlockPreventingMove(gActiveBattler, move))
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveHealBlockInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveHealBlock;
            limitations++;
        }
    }

    if (IsBelchPreventingMove(gActiveBattler, move))
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedBelchInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedBelch;
            limitations++;
        }
    }
    
    if (move == MOVE_STUFF_CHEEKS && ItemId_GetPocket(gBattleMons[gActiveBattler].item) != POCKET_BERRIES)
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedBelchInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = 1;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedStuffCheeks;
            limitations++;
        }
    }

    //Sleep Clause
    if(IsSleepClauseDisablingMove(gActiveBattler, move)){
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = 1;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingSleepClauseNotAllowed;
            limitations++;
        }
    }

    gPotentialItemEffectBattler = gActiveBattler;
    if (HOLD_EFFECT_CHOICE(holdEffect) && *choicedMove != 0 && *choicedMove != 0xFFFF && *choicedMove != move)
    {
        gCurrentMove = *choicedMove;
        gLastUsedItem = gBattleMons[gActiveBattler].item;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveChoiceItem;
            limitations++;
        }
    }
    else if (holdEffect == HOLD_EFFECT_ASSAULT_VEST && IS_MOVE_STATUS(move) && move != MOVE_ME_FIRST)
    {
        gCurrentMove = move;
        gLastUsedItem = gBattleMons[gActiveBattler].item;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveAssaultVest;
            limitations++;
        }
    }
    //Sage Power and Gorilla Tactics
    if ((BATTLER_HAS_ABILITY(gActiveBattler, ABILITY_SAGE_POWER)      ||
         BATTLER_HAS_ABILITY(gActiveBattler, ABILITY_GORILLA_TACTICS) ||
         BATTLER_HAS_ABILITY(gActiveBattler, ABILITY_DISCIPLINE))     &&
		*choicedMove != 0      &&
        *choicedMove != 0xFFFF && 
        *choicedMove != move)
    {
        gCurrentMove = *choicedMove;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = 1;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveGorillaTactics;//To Change
            limitations++;
        }
    }

    if (gBattleMons[gActiveBattler].pp[moveId] == 0)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingMoveWithNoPP;
            limitations++;
        }
    }

    if (moveId == gLastChosenMove[gActiveBattler] && gBattleMoves[moveId].effect == EFFECT_EVERY_OTHER_TURN)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CANTSELECTTWICE;
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedGeneric;
            limitations++;
        }
    }

    return limitations;
}

u8 CheckMoveLimitations(u8 battlerId, u8 unusableMoves, u8 check)
{
    u8 holdEffect = GetBattlerHoldEffect(battlerId, TRUE);
    u16 *choicedMove = &gBattleStruct->choicedMove[battlerId];
    s32 i;

    gPotentialItemEffectBattler = battlerId;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[battlerId].moves[i] == 0 && check & MOVE_LIMITATION_ZEROMOVE)
            unusableMoves |= gBitTable[i];
        else if (gBattleMons[battlerId].pp[i] == 0 && check & MOVE_LIMITATION_PP)
            unusableMoves |= gBitTable[i];
        else if (gBattleMons[battlerId].moves[i] == gDisableStructs[battlerId].disabledMove && check & MOVE_LIMITATION_DISABLED)
            unusableMoves |= gBitTable[i];
        else if (gBattleMons[battlerId].moves[i] == gLastMoves[battlerId] && check & MOVE_LIMITATION_TORMENTED && gBattleMons[battlerId].status2 & STATUS2_TORMENT)
            unusableMoves |= gBitTable[i];
        else if (gDisableStructs[battlerId].tauntTimer && check & MOVE_LIMITATION_TAUNT && gBattleMoves[gBattleMons[battlerId].moves[i]].power == 0)
            unusableMoves |= gBitTable[i];
        else if (GetImprisonedMovesCount(battlerId, gBattleMons[battlerId].moves[i]) && check & MOVE_LIMITATION_IMPRISON)
            unusableMoves |= gBitTable[i];
        else if (gDisableStructs[battlerId].encoreTimer && gDisableStructs[battlerId].encoredMove != gBattleMons[battlerId].moves[i])
            unusableMoves |= gBitTable[i];
        else if (HOLD_EFFECT_CHOICE(holdEffect) && *choicedMove != 0 && *choicedMove != 0xFFFF && *choicedMove != gBattleMons[battlerId].moves[i])
            unusableMoves |= gBitTable[i];
        else if (holdEffect == HOLD_EFFECT_ASSAULT_VEST && IS_MOVE_STATUS(gBattleMons[battlerId].moves[i]) && gBattleMons[battlerId].moves[i] != MOVE_ME_FIRST)
            unusableMoves |= gBitTable[i];
        else if (IsGravityPreventingMove(gBattleMons[battlerId].moves[i]))
            unusableMoves |= gBitTable[i];
        else if (IsHealBlockPreventingMove(battlerId, gBattleMons[battlerId].moves[i]))
            unusableMoves |= gBitTable[i];
        else if (IsBelchPreventingMove(battlerId, gBattleMons[battlerId].moves[i]))
            unusableMoves |= gBitTable[i];
        else if (gDisableStructs[battlerId].throatChopTimer && gBattleMoves[gBattleMons[battlerId].moves[i]].flags & FLAG_SOUND)
            unusableMoves |= gBitTable[i];
        else if (gBattleMons[battlerId].moves[i] == MOVE_STUFF_CHEEKS && ItemId_GetPocket(gBattleMons[gActiveBattler].item) != POCKET_BERRIES)
            unusableMoves |= gBitTable[i];
        else if (BATTLER_HAS_ABILITY(battlerId, ABILITY_DISCIPLINE) && *choicedMove != 0 && *choicedMove != 0xFFFF && *choicedMove != gBattleMons[battlerId].moves[i])
            unusableMoves |= gBitTable[i];
        else if (IsSleepClauseDisablingMove(battlerId, gBattleMons[battlerId].moves[i])){
            unusableMoves |= gBitTable[i];
        }
        else if ((BATTLER_HAS_ABILITY(battlerId, ABILITY_GORILLA_TACTICS) ||
                  BATTLER_HAS_ABILITY(battlerId, ABILITY_SAGE_POWER))
			&& *choicedMove != 0 && *choicedMove != 0xFFFF && *choicedMove != gBattleMons[battlerId].moves[i])
            unusableMoves |= gBitTable[i];
    }
    return unusableMoves;
}

bool8 AreAllMovesUnusable(void)
{
    u8 unusable;
    unusable = CheckMoveLimitations(gActiveBattler, 0, 0xFF);

    if (unusable == 0xF) // All moves are unusable.
    {
        gProtectStructs[gActiveBattler].noValidMoves = TRUE;
        gSelectionBattleScripts[gActiveBattler] = BattleScript_NoMovesLeft;
    }
    else
    {
        gProtectStructs[gActiveBattler].noValidMoves = FALSE;
    }

    return (unusable == 0xF);
}

u8 GetImprisonedMovesCount(u8 battlerId, u16 move)
{
    s32 i;
    u8 imprisonedMoves = 0;
    u8 battlerSide = GetBattlerSide(battlerId);

    for (i = 0; i < gBattlersCount; i++)
    {
        if (battlerSide != GetBattlerSide(i) && gStatuses3[i] & STATUS3_IMPRISONED_OTHERS)
        {
            s32 j;
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (move == gBattleMons[i].moves[j])
                    break;
            }
            if (j < MAX_MON_MOVES)
                imprisonedMoves++;
        }
    }

    return imprisonedMoves;
}

void RestoreBattlerOriginalTypes(u8 battlerId)
{
    gBattleMons[battlerId].type1 = gBaseStats[gBattleMons[battlerId].species].type1;
    gBattleMons[battlerId].type2 = gBaseStats[gBattleMons[battlerId].species].type2;
}

void TryToApplyMimicry(u8 battlerId, bool8 various)
{
    u32 moveType, move;

    GET_MOVE_TYPE(move, moveType);
    switch (gFieldStatuses)
    {
    case STATUS_FIELD_ELECTRIC_TERRAIN:
        moveType = TYPE_ELECTRIC;
        break;
    case STATUS_FIELD_MISTY_TERRAIN:
        moveType = TYPE_FAIRY;
        break;
    case STATUS_FIELD_GRASSY_TERRAIN:
        moveType = TYPE_GRASS;
        break;
    case STATUS_FIELD_PSYCHIC_TERRAIN:
        moveType = TYPE_PSYCHIC;
        break;
    default:
        moveType = 0;
        break;
    }

    if (moveType != 0 && !IS_BATTLER_OF_TYPE(battlerId, moveType))
    {
        SET_BATTLER_TYPE(battlerId, moveType);
        PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, battlerId, gBattlerPartyIndexes[battlerId])
        PREPARE_TYPE_BUFFER(gBattleTextBuff2, moveType);
        if (!various)
            BattleScriptPushCursorAndCallback(BattleScript_MimicryActivatesEnd3);
    }
}

void TryToRevertMimicry(void)
{
    s32 i;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (GetBattlerAbility(i) == ABILITY_MIMICRY)
            RestoreBattlerOriginalTypes(i);
    }
}

enum
{
    ENDTURN_ORDER,
    ENDTURN_REFLECT,
    ENDTURN_LIGHT_SCREEN,
    ENDTURN_AURORA_VEIL,
    ENDTURN_MIST,
    ENDTURN_LUCKY_CHANT,
    ENDTURN_SAFEGUARD,
    ENDTURN_TAILWIND,
    ENDTURN_WISH,
    ENDTURN_RAIN,
    ENDTURN_SANDSTORM,
    ENDTURN_SUN,
    ENDTURN_HAIL,
    ENDTURN_GRAVITY,
    ENDTURN_WATER_SPORT,
    ENDTURN_MUD_SPORT,
    ENDTURN_TRICK_ROOM,
    ENDTURN_WONDER_ROOM,
    ENDTURN_MAGIC_ROOM,
    ENDTURN_ELECTRIC_TERRAIN,
    ENDTURN_MISTY_TERRAIN,
    ENDTURN_GRASSY_TERRAIN,
    ENDTURN_PSYCHIC_TERRAIN,
    ENDTURN_ION_DELUGE,
    ENDTURN_FAIRY_LOCK,
    ENDTURN_RETALIATE,
    ENDTURN_RAINBOW,
    ENDTURN_SEA_OF_FIRE,
    ENDTURN_SWAMP,
    ENDTURN_FIELD_COUNT,
};

u8 DoFieldEndTurnEffects(void)
{
    u8 effect = 0;

    for (gBattlerAttacker = 0; gBattlerAttacker < gBattlersCount && gAbsentBattlerFlags & gBitTable[gBattlerAttacker]; gBattlerAttacker++)
    {
    }
    for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount && gAbsentBattlerFlags & gBitTable[gBattlerTarget]; gBattlerTarget++)
    {
    }

    do
    {
        s32 i;
        u8 side;

        switch (gBattleStruct->turnCountersTracker)
        {
        case ENDTURN_ORDER:
            for (i = 0; i < gBattlersCount; i++)
            {
                gBattlerByTurnOrder[i] = i;
            }
            for (i = 0; i < gBattlersCount - 1; i++)
            {
                s32 j;
                for (j = i + 1; j < gBattlersCount; j++)
                {
                    if (GetWhoStrikesFirst(gBattlerByTurnOrder[i], gBattlerByTurnOrder[j], 0))
                        SwapTurnOrder(i, j);
                }
            }

            gBattleStruct->turnCountersTracker++;
            gBattleStruct->turnSideTracker = 0;
            // fall through
        case ENDTURN_REFLECT:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gActiveBattler = gBattlerAttacker = gSideTimers[side].reflectBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_REFLECT)
                {
                    if (--gSideTimers[side].reflectTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_REFLECT;
                        BattleScriptExecute(BattleScript_SideStatusWoreOff);
                        PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_REFLECT);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (effect == 0)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_LIGHT_SCREEN:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gActiveBattler = gBattlerAttacker = gSideTimers[side].lightscreenBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_LIGHTSCREEN)
                {
                    if (--gSideTimers[side].lightscreenTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_LIGHTSCREEN;
                        BattleScriptExecute(BattleScript_SideStatusWoreOff);
                        gBattleCommunication[MULTISTRING_CHOOSER] = side;
                        PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_LIGHT_SCREEN);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_AURORA_VEIL:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gActiveBattler = gBattlerAttacker = side;
                //Aurora Veil
                if (gSideStatuses[side] & SIDE_STATUS_AURORA_VEIL)
                {
                    if (--gSideTimers[side].auroraVeilTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_AURORA_VEIL;
                        BattleScriptExecute(BattleScript_SideStatusWoreOff);
                        gBattleCommunication[MULTISTRING_CHOOSER] = side;
                        PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_AURORA_VEIL);
                        effect++;
                    }
                }
                //Spider Web
                if (gSideStatuses[side] & SIDE_STATUS_STICKY_WEB)
                {
                    if (--gSideTimers[side].spiderWebTimer == 1)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_STICKY_WEB;
                        BattleScriptExecute(BattleScript_SideStatusWoreOff);
                        gBattleCommunication[MULTISTRING_CHOOSER] = side;
                        PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_SPIDER_WEB);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_MIST:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gActiveBattler = gBattlerAttacker = gSideTimers[side].mistBattlerId;
                if (gSideTimers[side].mistTimer != 0
                 && --gSideTimers[side].mistTimer == 0)
                {
                    gSideStatuses[side] &= ~SIDE_STATUS_MIST;
                    BattleScriptExecute(BattleScript_SideStatusWoreOff);
                    gBattleCommunication[MULTISTRING_CHOOSER] = side;
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_MIST);
                    effect++;
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_SAFEGUARD:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gActiveBattler = gBattlerAttacker = gSideTimers[side].safeguardBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_SAFEGUARD)
                {
                    if (--gSideTimers[side].safeguardTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_SAFEGUARD;
                        BattleScriptExecute(BattleScript_SafeguardEnds);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_LUCKY_CHANT:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gActiveBattler = gBattlerAttacker = gSideTimers[side].luckyChantBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_LUCKY_CHANT)
                {
                    if (--gSideTimers[side].luckyChantTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_LUCKY_CHANT;
                        BattleScriptExecute(BattleScript_LuckyChantEnds);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_TAILWIND:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gActiveBattler = gBattlerAttacker = gSideTimers[side].tailwindBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_TAILWIND)
                {
                    if (--gSideTimers[side].tailwindTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_TAILWIND;
                        BattleScriptExecute(BattleScript_TailwindEnds);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_WISH:
            while (gBattleStruct->turnSideTracker < gBattlersCount)
            {
                gActiveBattler = gBattlerByTurnOrder[gBattleStruct->turnSideTracker];
                if (gWishFutureKnock.wishCounter[gActiveBattler] != 0
                 && --gWishFutureKnock.wishCounter[gActiveBattler] == 0
                 && gBattleMons[gActiveBattler].hp != 0)
                {
                    gBattlerTarget = gActiveBattler;
                    BattleScriptExecute(BattleScript_WishComesTrue);
                    effect++;
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
            }
            break;
        case ENDTURN_RAIN:
            if (gBattleWeather & WEATHER_RAIN_ANY)
            {
                if (!(gBattleWeather & WEATHER_RAIN_PERMANENT)
                 && !(gBattleWeather & WEATHER_RAIN_PRIMAL))
                {
                    if (--gWishFutureKnock.weatherDuration == 0)
                    {
                        gBattleWeather &= ~WEATHER_RAIN_TEMPORARY;
                        gBattleWeather &= ~WEATHER_RAIN_DOWNPOUR;
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_RAIN_STOPPED;
                    }
                    else if (gBattleWeather & WEATHER_RAIN_DOWNPOUR)
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DOWNPOUR_CONTINUES;
                    else
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_RAIN_CONTINUES;
                }
                else if (gBattleWeather & WEATHER_RAIN_DOWNPOUR)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DOWNPOUR_CONTINUES;
                }
                else
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_RAIN_CONTINUES;
                }

                BattleScriptExecute(BattleScript_RainContinuesOrEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_SANDSTORM:
            if (gBattleWeather & WEATHER_SANDSTORM_ANY)
            {
                if (!(gBattleWeather & WEATHER_SANDSTORM_PERMANENT) && --gWishFutureKnock.weatherDuration == 0)
                {
                    gBattleWeather &= ~WEATHER_SANDSTORM_TEMPORARY;
                    gBattlescriptCurrInstr = BattleScript_SandStormHailEnds;
                }
                else
                {
                    gBattlescriptCurrInstr = BattleScript_DamagingWeatherContinues;
                }

                gBattleScripting.animArg1 = B_ANIM_SANDSTORM_CONTINUES;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SANDSTORM;
                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_SUN:
            if (gBattleWeather & WEATHER_SUN_ANY)
            {
                if (!(gBattleWeather & WEATHER_SUN_PERMANENT)
                 && !(gBattleWeather & WEATHER_SUN_PRIMAL)
                 && --gWishFutureKnock.weatherDuration == 0)
                {
                    gBattleWeather &= ~WEATHER_SUN_TEMPORARY;
                    gBattlescriptCurrInstr = BattleScript_SunlightFaded;
                }
                else
                {
                    gBattlescriptCurrInstr = BattleScript_SunlightContinues;
                }

                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_HAIL:
            if (gBattleWeather & WEATHER_HAIL_ANY)
            {
                if (!(gBattleWeather & WEATHER_HAIL_PERMANENT) && --gWishFutureKnock.weatherDuration == 0)
                {
                    gBattleWeather &= ~WEATHER_HAIL_TEMPORARY;
                    gBattlescriptCurrInstr = BattleScript_SandStormHailEnds;
                }
                else
                {
                    gBattlescriptCurrInstr = BattleScript_DamagingWeatherContinues;
                }

                gBattleScripting.animArg1 = B_ANIM_HAIL_CONTINUES;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_HAIL;
                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_TRICK_ROOM:
            if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM && --gFieldTimers.trickRoomTimer == 0)
            {
                gFieldStatuses &= ~(STATUS_FIELD_TRICK_ROOM);
                BattleScriptExecute(BattleScript_TrickRoomEnds);
                effect++;
            }

            if (gFieldStatuses & STATUS_FIELD_INVERSE_ROOM && --gFieldTimers.inverseRoomTimer == 0)
            {
                gFieldStatuses &= ~(STATUS_FIELD_INVERSE_ROOM);
                BattleScriptExecute(BattleScript_InverseRoomEnds);
                effect++;
            }

            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_WONDER_ROOM:
            if (gFieldStatuses & STATUS_FIELD_WONDER_ROOM && --gFieldTimers.wonderRoomTimer == 0)
            {
                gFieldStatuses &= ~(STATUS_FIELD_WONDER_ROOM);
                BattleScriptExecute(BattleScript_WonderRoomEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_MAGIC_ROOM:
            if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM && --gFieldTimers.magicRoomTimer == 0)
            {
                gFieldStatuses &= ~(STATUS_FIELD_MAGIC_ROOM);
                BattleScriptExecute(BattleScript_MagicRoomEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_ELECTRIC_TERRAIN:
            if (gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN
              && (!(gFieldStatuses & STATUS_FIELD_TERRAIN_PERMANENT) && --gFieldTimers.terrainTimer == 0))
            {
                gFieldStatuses &= ~(STATUS_FIELD_ELECTRIC_TERRAIN | STATUS_FIELD_TERRAIN_PERMANENT);
                TryToRevertMimicry();
                BattleScriptExecute(BattleScript_ElectricTerrainEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_MISTY_TERRAIN:
            if (gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN
              && (!(gFieldStatuses & STATUS_FIELD_TERRAIN_PERMANENT) && --gFieldTimers.terrainTimer == 0))
            {
                gFieldStatuses &= ~(STATUS_FIELD_MISTY_TERRAIN);
                TryToRevertMimicry();
                BattleScriptExecute(BattleScript_MistyTerrainEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_GRASSY_TERRAIN:
            if (gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN)
            {
                if (!(gFieldStatuses & STATUS_FIELD_TERRAIN_PERMANENT)
                  && (gFieldTimers.terrainTimer == 0 || --gFieldTimers.terrainTimer == 0))
                {
                    gFieldStatuses &= ~(STATUS_FIELD_GRASSY_TERRAIN);
                    TryToRevertMimicry();
                }
                BattleScriptExecute(BattleScript_GrassyTerrainHeals);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_PSYCHIC_TERRAIN:
            if (gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN
              && (!(gFieldStatuses & STATUS_FIELD_TERRAIN_PERMANENT) && --gFieldTimers.terrainTimer == 0))
            {
                gFieldStatuses &= ~(STATUS_FIELD_PSYCHIC_TERRAIN);
                TryToRevertMimicry();
                BattleScriptExecute(BattleScript_PsychicTerrainEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_WATER_SPORT:
            if (gFieldStatuses & STATUS_FIELD_WATERSPORT && --gFieldTimers.waterSportTimer == 0)
            {
                gFieldStatuses &= ~(STATUS_FIELD_WATERSPORT);
                BattleScriptExecute(BattleScript_WaterSportEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_MUD_SPORT:
            if (gFieldStatuses & STATUS_FIELD_MUDSPORT && --gFieldTimers.mudSportTimer == 0)
            {
                gFieldStatuses &= ~(STATUS_FIELD_MUDSPORT);
                BattleScriptExecute(BattleScript_MudSportEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_GRAVITY:
            if (gFieldStatuses & STATUS_FIELD_GRAVITY && --gFieldTimers.gravityTimer == 0)
            {
                gFieldStatuses &= ~(STATUS_FIELD_GRAVITY);
                BattleScriptExecute(BattleScript_GravityEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_ION_DELUGE:
            gFieldStatuses &= ~(STATUS_FIELD_ION_DELUGE);
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_FAIRY_LOCK:
            if (gFieldStatuses & STATUS_FIELD_FAIRY_LOCK && --gFieldTimers.fairyLockTimer == 0)
            {
                gFieldStatuses &= ~(STATUS_FIELD_FAIRY_LOCK);
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_RETALIATE:
            if (gSideTimers[B_SIDE_PLAYER].retaliateTimer > 0)
                gSideTimers[B_SIDE_PLAYER].retaliateTimer--;
            if (gSideTimers[B_SIDE_OPPONENT].retaliateTimer > 0)
                gSideTimers[B_SIDE_OPPONENT].retaliateTimer--;
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_RAINBOW:
            while (gBattleStruct->turnSideTracker < 2)
            {
                u8 side = gBattleStruct->turnSideTracker;
                if (gSideTimers[side].rainbowTimer)
                {
                    for (gBattlerAttacker = 0; gBattlerAttacker < gBattlersCount; gBattlerAttacker++)
                    {
                        if (GetBattlerSide(gBattlerAttacker) == side)
                            break;
                    }

                    if (gSideTimers[side].rainbowTimer > 0 && --gSideTimers[side].rainbowTimer == 0)
                    {
                        BattleScriptExecute(BattleScript_RainbowDisappeared);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_SEA_OF_FIRE:
            while (gBattleStruct->turnSideTracker < 2)
            {
                u8 side = gBattleStruct->turnSideTracker;

                if (gSideTimers[side].fireSeaTimer)
                {
                    for (gBattlerAttacker = 0; gBattlerAttacker < gBattlersCount; gBattlerAttacker++)
                    {
                        if (GetBattlerSide(gBattlerAttacker) == side)
                            break;
                    }

                    if (gSideTimers[side].fireSeaTimer > 0 && --gSideTimers[side].fireSeaTimer == 0)
                    {
                        BattleScriptExecute(BattleScript_TheSeaOfFireDisappeared);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_SWAMP:
            while (gBattleStruct->turnSideTracker < 2)
            {
                u8 side = gBattleStruct->turnSideTracker;
                if (gSideTimers[side].swampTimer)
                {
                    for (gBattlerAttacker = 0; gBattlerAttacker < gBattlersCount; gBattlerAttacker++)
                    {
                        if (GetBattlerSide(gBattlerAttacker) == side)
                            break;
                    }

                    if (gSideTimers[side].swampTimer > 0 && --gSideTimers[side].swampTimer == 0)
                    {
                        BattleScriptExecute(BattleScript_TheSwampDisappeared);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_FIELD_COUNT:
            effect++;
            break;
        }
    } while (effect == 0);

    return (gBattleMainFunc != BattleTurnPassed);
}

enum
{
    ENDTURN_INGRAIN,
    ENDTURN_AQUA_RING,
    ENDTURN_ABILITIES,
    ENDTURN_ITEMS1,
    ENDTURN_LEECH_SEED,
    ENDTURN_POISON,
    ENDTURN_BAD_POISON,
    ENDTURN_BURN,
    ENDTURN_FROSTBITE,
    ENDTURN_BLEED,
    ENDTURN_NIGHTMARES,
    ENDTURN_CURSE,
    ENDTURN_SALT_CURE,
    ENDTURN_WRAP,
    ENDTURN_OCTOLOCK,
    ENDTURN_UPROAR,
    ENDTURN_THRASH,
    ENDTURN_FLINCH,
    ENDTURN_DISABLE,
    ENDTURN_ENCORE,
    ENDTURN_MAGNET_RISE,
    ENDTURN_TELEKINESIS,
    ENDTURN_HEALBLOCK,
    ENDTURN_EMBARGO,
    ENDTURN_LOCK_ON,
    ENDTURN_GHASTLY_ECHO,
    ENDTURN_COILED_UP,
    ENDTURN_LASER_FOCUS,
    ENDTURN_TAUNT,
    ENDTURN_YAWN,
    ENDTURN_ITEMS2,
    ENDTURN_ORBS,
    ENDTURN_ROOST,
    ENDTURN_ELECTRIFY,
    ENDTURN_POWDER,
    ENDTURN_THROAT_CHOP,
    ENDTURN_SLOW_START,
    ENDTURN_PLASMA_FISTS,
    ENDTURN_TOXIC_WASTE_DAMAGE,
    ENDTURN_SEA_OF_FIRE_DAMAGE,
    ENDTURN_BATTLER_COUNT,
};

// Ingrain, Leech Seed, Strength Sap and Aqua Ring
s32 GetDrainedBigRootHp(u32 battler, s32 hp)
{
    if (GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_BIG_ROOT)
        hp = (hp * 3) / 2; // Buff Big Root's additional healing from 30% to 50%

    if (BATTLER_HAS_ABILITY(battler, ABILITY_ABSORBANT))
        gBattleMoveDamage = (gBattleMoveDamage * 3) / 2; // Buff Absorbant additional healing from 30% to 50%

    if (hp == 0)
        hp = 1;

    return hp * -1;
}

#define BATTLER_HAS_MAGIC_GUARD(battlerId) (GetBattlerAbility(battlerId) == ABILITY_MAGIC_GUARD || GetBattlerAbility(battlerId) == ABILITY_IMPENETRABLE || BattlerHasInnate(battlerId, ABILITY_MAGIC_GUARD) || BattlerHasInnate(battlerId, ABILITY_IMPENETRABLE))

#define MAGIC_GUARD_CHECK \
if (ability == ABILITY_MAGIC_GUARD || ability == ABILITY_IMPENETRABLE || BattlerHasInnate(gActiveBattler, ABILITY_MAGIC_GUARD) || BattlerHasInnate(gActiveBattler, ABILITY_IMPENETRABLE)) \
{\
    RecordAbilityBattle(gActiveBattler, ability);\
    gBattleStruct->turnEffectsTracker++;\
            break;\
}


#define TOXIC_BOOST_CHECK \
if (BATTLER_HAS_ABILITY_FAST(gActiveBattler, ABILITY_TOXIC_BOOST, ability)) \
{\
    RecordAbilityBattle(gActiveBattler, ability);\
    gBattleStruct->turnEffectsTracker++;\
            break;\
}

#define FLARE_BOOST_CHECK \
if (BATTLER_HAS_ABILITY_FAST(gActiveBattler, ABILITY_FLARE_BOOST, ability)) \
{\
    RecordAbilityBattle(gActiveBattler, ability);\
    gBattleStruct->turnEffectsTracker++;\
            break;\
}



u8 DoBattlerEndTurnEffects(void)
{
    u32 ability, i, effect = 0;

    gHitMarker |= (HITMARKER_GRUDGE | HITMARKER_SKIP_DMG_TRACK);
    while (gBattleStruct->turnEffectsBattlerId < gBattlersCount && gBattleStruct->turnEffectsTracker <= ENDTURN_BATTLER_COUNT)
    {
        gActiveBattler = gBattlerAttacker = gBattlerByTurnOrder[gBattleStruct->turnEffectsBattlerId];
        if (gAbsentBattlerFlags & gBitTable[gActiveBattler])
        {
            gBattleStruct->turnEffectsBattlerId++;
            continue;
        }

        ability = GetBattlerAbility(gActiveBattler);
        switch (gBattleStruct->turnEffectsTracker)
        {
        case ENDTURN_INGRAIN:  // ingrain
            if ((gStatuses3[gActiveBattler] & STATUS3_ROOTED)
             && !BATTLER_MAX_HP(gActiveBattler)
             && !BATTLER_HEALING_BLOCKED(gActiveBattler)
             && gBattleMons[gActiveBattler].hp != 0)
            {
                gBattleMoveDamage = GetDrainedBigRootHp(gActiveBattler, gBattleMons[gActiveBattler].maxHP / 8);
                BattleScriptExecute(BattleScript_IngrainTurnHeal);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_AQUA_RING:  // aqua ring
            if ((gStatuses3[gActiveBattler] & STATUS3_AQUA_RING)
             && !BATTLER_MAX_HP(gActiveBattler)
             && !BATTLER_HEALING_BLOCKED(gActiveBattler)
             && gBattleMons[gActiveBattler].hp != 0)
            {
                gBattleMoveDamage = GetDrainedBigRootHp(gActiveBattler, gBattleMons[gActiveBattler].maxHP / 16);
                BattleScriptExecute(BattleScript_AquaRingHeal);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ABILITIES:  // end turn abilities
            if (AbilityBattleEffects(ABILITYEFFECT_ENDTURN, gActiveBattler, 0, 0, 0))
                effect++;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ITEMS1:  // item effects
            if (ItemBattleEffects(1, gActiveBattler, FALSE))
                effect++;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ITEMS2:  // item effects again
            if (ItemBattleEffects(1, gActiveBattler, TRUE))
                effect++;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ORBS:
            if (ItemBattleEffects(ITEMEFFECT_ORBS, gActiveBattler, FALSE))
                effect++;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_LEECH_SEED:  // leech seed
            if ((gStatuses3[gActiveBattler] & STATUS3_LEECHSEED)
             && gBattleMons[gStatuses3[gActiveBattler] & STATUS3_LEECHSEED_BATTLER].hp != 0
             && gBattleMons[gActiveBattler].hp != 0)
            {
                MAGIC_GUARD_CHECK;

                gBattlerTarget = gStatuses3[gActiveBattler] & STATUS3_LEECHSEED_BATTLER; // Notice gBattlerTarget is actually the HP receiver.
                gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 8;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                gBattleScripting.animArg1 = gBattlerTarget;
                gBattleScripting.animArg2 = gBattlerAttacker;
                BattleScriptExecute(BattleScript_LeechSeedTurnDrain);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_TOXIC_WASTE_DAMAGE:
            if ((IsAbilityOnField(ABILITY_TOXIC_SPILL)) && gBattleMons[gActiveBattler].hp != 0 && !IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_POISON))
            {
                MAGIC_GUARD_CHECK;
                if(ability != ABILITY_POISON_HEAL && !BattlerHasInnate(gActiveBattler, ABILITY_POISON_HEAL))
				    TOXIC_BOOST_CHECK;

                if (BATTLER_HAS_ABILITY_FAST(gActiveBattler, ABILITY_POISON_HEAL, ability))
                {
                    if (!BATTLER_MAX_HP(gActiveBattler) && !BATTLER_HEALING_BLOCKED(gActiveBattler))
                    {
                        gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 8;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                        gBattleMoveDamage *= -1;
                        BattleScriptExecute(BattleScript_PoisonHealActivates);
                        effect++;
                    }
                }
                else
                {
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptExecute(BattleScript_ToxicWasteTurnDmg);
                    effect++;
                }
            
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_POISON:  // poison
            if ((gBattleMons[gActiveBattler].status1 & STATUS1_POISON)
                && gBattleMons[gActiveBattler].hp != 0)
            {
                MAGIC_GUARD_CHECK;
                if(ability != ABILITY_POISON_HEAL && !BattlerHasInnate(gActiveBattler, ABILITY_POISON_HEAL))
				    TOXIC_BOOST_CHECK;

                if (BATTLER_HAS_ABILITY_FAST(gActiveBattler, ABILITY_POISON_HEAL, ability))
                {
                    if (!BATTLER_MAX_HP(gActiveBattler) && !BATTLER_HEALING_BLOCKED(gActiveBattler))
                    {
                        gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 8;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                        gBattleMoveDamage *= -1;
                        BattleScriptExecute(BattleScript_PoisonHealActivates);
                        effect++;
                    }
                }
                else
                {
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptExecute(BattleScript_PoisonTurnDmg);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_BAD_POISON:  // toxic poison
            if ((gBattleMons[gActiveBattler].status1 & STATUS1_TOXIC_POISON)
                && gBattleMons[gActiveBattler].hp != 0)
            {
                MAGIC_GUARD_CHECK;
                if(ability != ABILITY_POISON_HEAL && !BattlerHasInnate(gActiveBattler, ABILITY_POISON_HEAL))
				    TOXIC_BOOST_CHECK;

                if (BATTLER_HAS_ABILITY_FAST(gActiveBattler, ABILITY_POISON_HEAL, ability))
                {
                    if (!BATTLER_MAX_HP(gActiveBattler) && !BATTLER_HEALING_BLOCKED(gActiveBattler))
                    {
                        gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 8;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                        gBattleMoveDamage *= -1;
                        BattleScriptExecute(BattleScript_PoisonHealActivates);
                        effect++;
                    }
                }
                else
                {
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 16;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    if ((gBattleMons[gActiveBattler].status1 & STATUS1_TOXIC_COUNTER) != STATUS1_TOXIC_TURN(15)) // not 16 turns
                        gBattleMons[gActiveBattler].status1 += STATUS1_TOXIC_TURN(1);
                    gBattleMoveDamage *= (gBattleMons[gActiveBattler].status1 & STATUS1_TOXIC_COUNTER) >> 8;
                    BattleScriptExecute(BattleScript_PoisonTurnDmg);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_SEA_OF_FIRE_DAMAGE:
            if (IsBattlerAlive(gActiveBattler) && !IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_FIRE) && gSideTimers[GetBattlerSide(gActiveBattler)].fireSeaTimer)
            {
                MAGIC_GUARD_CHECK;
				FLARE_BOOST_CHECK;

                gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 8;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BtlController_EmitStatusAnimation(0, FALSE, STATUS1_BURN);
                MarkBattlerForControllerExec(gActiveBattler);
                BattleScriptExecute(BattleScript_HurtByTheSeaOfFire);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_BURN:  // burn
            if ((gBattleMons[gActiveBattler].status1 & STATUS1_BURN) && gBattleMons[gActiveBattler].hp != 0 &&
               ability != ABILITY_HEATPROOF &&
               !BattlerHasInnate(gActiveBattler, ABILITY_HEATPROOF))
            {
                MAGIC_GUARD_CHECK;
				FLARE_BOOST_CHECK;
			
                gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / (B_BURN_DAMAGE >= GEN_7 ? 16 : 8);
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptExecute(BattleScript_BurnTurnDmg);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_FROSTBITE:  // frostbite
            if ((gBattleMons[gActiveBattler].status1 & STATUS1_FROSTBITE)
                && gBattleMons[gActiveBattler].hp != 0)
            {
                MAGIC_GUARD_CHECK;
                #if B_BURN_DAMAGE >= GEN_7
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 16;
                #else
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 8;
                #endif
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptExecute(BattleScript_FrostbiteTurnDmg);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_BLEED: // bleed
            if ((gBattleMons[gActiveBattler].status1 & STATUS1_BLEED)
                && gBattleMons[gActiveBattler].hp != 0)
            {
                MAGIC_GUARD_CHECK;
                gBattleMoveDamage = BLEED_DAMAGE(gBattleMons[gActiveBattler].maxHP);
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptExecute(BattleScript_BleedTurnDmg);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_NIGHTMARES:  // spooky nightmares
            if ((gBattleMons[gActiveBattler].status2 & STATUS2_NIGHTMARE)
                && gBattleMons[gActiveBattler].hp != 0)
            {
                MAGIC_GUARD_CHECK;
                // R/S does not perform this sleep check, which causes the nightmare effect to
                // persist even after the affected Pokemon has been awakened by Shed Skin.
                if (gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP)
                {
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 4;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptExecute(BattleScript_NightmareTurnDmg);
                    effect++;
                }
                else
                {
                    gBattleMons[gActiveBattler].status2 &= ~STATUS2_NIGHTMARE;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_CURSE:  // curse
            if ((gBattleMons[gActiveBattler].status2 & STATUS2_CURSED)
                && gBattleMons[gActiveBattler].hp != 0)
            {
                MAGIC_GUARD_CHECK;
                gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 4;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptExecute(BattleScript_CurseTurnDmg);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_SALT_CURE:
            if (gStatuses4[gActiveBattler] & STATUS4_SALT_CURE && gBattleMons[gActiveBattler].hp != 0)
            {
                MAGIC_GUARD_CHECK;
                gBattleMoveDamage = (IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_WATER) || IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_WATER)) ?
                                        gBattleMons[gActiveBattler].maxHP / 4 : gBattleMons[gActiveBattler].maxHP / 8;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptExecute(BattleScript_CurseTurnDmg);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_WRAP:  // wrap
            if ((gBattleMons[gActiveBattler].status2 & STATUS2_WRAPPED) && gBattleMons[gActiveBattler].hp != 0)
            {
                if (--gDisableStructs[gActiveBattler].wrapTurns != 0)  // damaged by wrap
                {
                    MAGIC_GUARD_CHECK;

                    gBattleScripting.animArg1 = gBattleStruct->wrappedMove[gActiveBattler];
                    gBattleScripting.animArg2 = gBattleStruct->wrappedMove[gActiveBattler] >> 8;
                    if(gBattleMoves[gBattleStruct->wrappedMove[gActiveBattler]].effect == EFFECT_TRAP){
                        PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleStruct->wrappedMove[gActiveBattler]);
                    }
                    else{
                        gLastUsedAbility = ABILITY_GRIP_PINCER;
                        PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                    }
                    gBattlescriptCurrInstr = BattleScript_WrapTurnDmg;

                    if (BATTLER_HAS_ABILITY(gBattleStruct->wrappedBy[gActiveBattler], ABILITY_GRAPPLER))
                        gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / ((B_BINDING_DAMAGE >= GEN_6) ? 6 : 8);
                    else if (GetBattlerHoldEffect(gBattleStruct->wrappedBy[gActiveBattler], TRUE) == HOLD_EFFECT_BINDING_BAND)
                        gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / ((B_BINDING_DAMAGE >= GEN_6) ? 6 : 8);
                    else
                        gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / ((B_BINDING_DAMAGE >= GEN_6) ? 8 : 16);

                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                }
                else  // broke free
                {
                    gBattleMons[gActiveBattler].status2 &= ~(STATUS2_WRAPPED);
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleStruct->wrappedMove[gActiveBattler]);
                    gBattlescriptCurrInstr = BattleScript_WrapEnds;
                }
                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_OCTOLOCK:
            if (gDisableStructs[gActiveBattler].octolock 
             && !(GetBattlerAbility(gActiveBattler)    == ABILITY_CLEAR_BODY       || BattlerHasInnate(gActiveBattler, ABILITY_CLEAR_BODY)
                  || GetBattlerAbility(gActiveBattler) == ABILITY_FULL_METAL_BODY  || BattlerHasInnate(gActiveBattler, ABILITY_FULL_METAL_BODY)
                  || GetBattlerAbility(gActiveBattler) == ABILITY_WHITE_SMOKE      || BattlerHasInnate(gActiveBattler, ABILITY_WHITE_SMOKE)
                  || GetBattlerHoldEffect(gActiveBattler, TRUE) == HOLD_EFFECT_CLEAR_AMULET))
            {
                gBattlerTarget = gActiveBattler;
                BattleScriptExecute(BattleScript_OctolockEndTurn);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_UPROAR:  // uproar
            if (gBattleMons[gActiveBattler].status2 & STATUS2_UPROAR)
            {
                for (gBattlerAttacker = 0; gBattlerAttacker < gBattlersCount; gBattlerAttacker++)
                {
                    if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP)
                     && !BATTLER_HAS_ABILITY(gBattlerAttacker, ABILITY_SOUNDPROOF)
                     && !IsAbilityOnSide(gBattlerAttacker, ABILITY_NOISE_CANCEL))
                    {
                        gBattleMons[gBattlerAttacker].status1 &= ~(STATUS1_SLEEP);
                        gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_NIGHTMARE);
                        BattleScriptExecute(BattleScript_MonWokeUpInUproar);
                        gActiveBattler = gBattlerAttacker;
                        BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
                        MarkBattlerForControllerExec(gActiveBattler);
                        break;
                    }
                }
                if (gBattlerAttacker != gBattlersCount)
                {
                    effect = 2;  // a pokemon was awaken
                    break;
                }
                else
                {
                    gBattlerAttacker = gActiveBattler;
                    gBattleMons[gActiveBattler].status2 -= STATUS2_UPROAR_TURN(1);  // uproar timer goes down
                    if (WasUnableToUseMove(gActiveBattler))
                    {
                        CancelMultiTurnMoves(gActiveBattler);
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_UPROAR_ENDS;
                    }
                    else if (gBattleMons[gActiveBattler].status2 & STATUS2_UPROAR)
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_UPROAR_CONTINUES;
                        gBattleMons[gActiveBattler].status2 |= STATUS2_MULTIPLETURNS;
                    }
                    else
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_UPROAR_ENDS;
                        CancelMultiTurnMoves(gActiveBattler);
                    }
                    BattleScriptExecute(BattleScript_PrintUproarOverTurns);
                    effect = 1;
                }
            }
            if (effect != 2)
                gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_THRASH:  // thrash
            if (gBattleMons[gActiveBattler].status2 & STATUS2_LOCK_CONFUSE)
            {
                gBattleMons[gActiveBattler].status2 -= STATUS2_LOCK_CONFUSE_TURN(1);
                if (WasUnableToUseMove(gActiveBattler))
                    CancelMultiTurnMoves(gActiveBattler);
                else if (!(gBattleMons[gActiveBattler].status2 & STATUS2_LOCK_CONFUSE)
                 && (gBattleMons[gActiveBattler].status2 & STATUS2_MULTIPLETURNS))
                {
                    gBattleMons[gActiveBattler].status2 &= ~(STATUS2_MULTIPLETURNS);
                    if (!(gBattleMons[gActiveBattler].status2 & STATUS2_CONFUSION))
                    {
                        gBattleScripting.moveEffect = MOVE_EFFECT_CONFUSION | MOVE_EFFECT_AFFECTS_USER;
                        SetMoveEffect(TRUE, 0);
                        if (gBattleMons[gActiveBattler].status2 & STATUS2_CONFUSION)
                            BattleScriptExecute(BattleScript_ThrashConfuses);
                        effect++;
                    }
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_FLINCH:  // reset flinch
            gBattleMons[gActiveBattler].status2 &= ~(STATUS2_FLINCHED);
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_DISABLE:  // disable
            if (gDisableStructs[gActiveBattler].disableTimer != 0)
            {
                for (i = 0; i < MAX_MON_MOVES; i++)
                {
                    if (gDisableStructs[gActiveBattler].disabledMove == gBattleMons[gActiveBattler].moves[i])
                        break;
                }
                if (i == MAX_MON_MOVES)  // pokemon does not have the disabled move anymore
                {
                    gDisableStructs[gActiveBattler].disabledMove = 0;
                    gDisableStructs[gActiveBattler].disableTimer = 0;
                }
                else if (--gDisableStructs[gActiveBattler].disableTimer == 0)  // disable ends
                {
                    gDisableStructs[gActiveBattler].disabledMove = 0;
                    BattleScriptExecute(BattleScript_DisabledNoMore);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ENCORE:  // encore
            if (gDisableStructs[gActiveBattler].encoreTimer != 0)
            {
                if (gBattleMons[gActiveBattler].moves[gDisableStructs[gActiveBattler].encoredMovePos] != gDisableStructs[gActiveBattler].encoredMove)  // pokemon does not have the encored move anymore
                {
                    gDisableStructs[gActiveBattler].encoredMove = 0;
                    gDisableStructs[gActiveBattler].encoreTimer = 0;
                }
                else if (--gDisableStructs[gActiveBattler].encoreTimer == 0
                 || gBattleMons[gActiveBattler].pp[gDisableStructs[gActiveBattler].encoredMovePos] == 0)
                {
                    gDisableStructs[gActiveBattler].encoredMove = 0;
                    gDisableStructs[gActiveBattler].encoreTimer = 0;
                    BattleScriptExecute(BattleScript_EncoredNoMore);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_LOCK_ON:  // lock-on decrement
            if (gStatuses3[gActiveBattler] & STATUS3_ALWAYS_HITS)
                gStatuses3[gActiveBattler] -= STATUS3_ALWAYS_HITS_TURN(1);
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_GHASTLY_ECHO:
            if (gDisableStructs[gActiveBattler].ghastlyEchoTimer && --gDisableStructs[gActiveBattler].ghastlyEchoTimer == 0)
                gStatuses4[gActiveBattler] &= ~STATUS4_GHASTLY_ECHO;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_COILED_UP:
            if((gStatuses4[gActiveBattler] & STATUS4_COILED) && (gBattleMoves[gLastMoves[gActiveBattler]].flags & FLAG_STRONG_JAW_BOOST))
                gStatuses4[gActiveBattler] &= ~(STATUS4_COILED);
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_TAUNT:  // taunt
            if (gDisableStructs[gActiveBattler].tauntTimer && --gDisableStructs[gActiveBattler].tauntTimer == 0)
            {
                BattleScriptExecute(BattleScript_BufferEndTurn);
                PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_TAUNT);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_YAWN:  // yawn
            if (gStatuses3[gActiveBattler] & STATUS3_YAWN)
            {
                gStatuses3[gActiveBattler] -= STATUS3_YAWN_TURN(1);
                if (!(gStatuses3[gActiveBattler] & STATUS3_YAWN) 
                 && !(gBattleMons[gActiveBattler].status1 & STATUS1_ANY)
                 && !BATTLER_HAS_ABILITY(gActiveBattler, ABILITY_VITAL_SPIRIT)
                 && !BATTLER_HAS_ABILITY(gActiveBattler, ABILITY_INSOMNIA)
				 && !UproarWakeUpCheck(gActiveBattler)
                 && !IsLeafGuardProtected(gActiveBattler))
                {
                    CancelMultiTurnMoves(gActiveBattler);
                    gEffectBattler = gActiveBattler;
                    if (IsBattlerTerrainAffected(gActiveBattler, STATUS_FIELD_ELECTRIC_TERRAIN))
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAINPREVENTS_ELECTRIC;
                        BattleScriptExecute(BattleScript_TerrainPreventsEnd2);
                    }
                    else if (IsBattlerTerrainAffected(gActiveBattler, STATUS_FIELD_MISTY_TERRAIN))
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAINPREVENTS_MISTY;
                        BattleScriptExecute(BattleScript_TerrainPreventsEnd2);
                    }
                    else
                    {
                        gBattleMons[gActiveBattler].status1 |= (Random() & 3) + 2;
                        BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
                        MarkBattlerForControllerExec(gActiveBattler);
                        BattleScriptExecute(BattleScript_YawnMakesAsleep);
                    }
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_LASER_FOCUS:
            if (gStatuses3[gActiveBattler] & STATUS3_LASER_FOCUS)
            {
                if (gDisableStructs[gActiveBattler].laserFocusTimer == 0 || --gDisableStructs[gActiveBattler].laserFocusTimer == 0)
                    gStatuses3[gActiveBattler] &= ~(STATUS3_LASER_FOCUS);
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_EMBARGO:
            if (gStatuses3[gActiveBattler] & STATUS3_EMBARGO)
            {
                if (gDisableStructs[gActiveBattler].embargoTimer == 0 || --gDisableStructs[gActiveBattler].embargoTimer == 0)
                {
                    gStatuses3[gActiveBattler] &= ~(STATUS3_EMBARGO);
                    BattleScriptExecute(BattleScript_EmbargoEndTurn);
                    effect++;
                }
            }

            gDisableStructs[gActiveBattler].substituteDestroyedThisTurn = FALSE;

            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_MAGNET_RISE:
            if (gStatuses3[gActiveBattler] & STATUS3_MAGNET_RISE)
            {
                if (gDisableStructs[gActiveBattler].magnetRiseTimer == 0 || --gDisableStructs[gActiveBattler].magnetRiseTimer == 0)
                {
                    gStatuses3[gActiveBattler] &= ~(STATUS3_MAGNET_RISE);
                    BattleScriptExecute(BattleScript_BufferEndTurn);
                    PREPARE_STRING_BUFFER(gBattleTextBuff1, STRINGID_ELECTROMAGNETISM);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_TELEKINESIS:
            if (gStatuses3[gActiveBattler] & STATUS3_TELEKINESIS)
            {
                if (gDisableStructs[gActiveBattler].telekinesisTimer == 0 || --gDisableStructs[gActiveBattler].telekinesisTimer == 0)
                {
                    gStatuses3[gActiveBattler] &= ~(STATUS3_TELEKINESIS);
                    BattleScriptExecute(BattleScript_TelekinesisEndTurn);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_HEALBLOCK:
            if (gStatuses3[gActiveBattler] & STATUS3_HEAL_BLOCK)
            {
                if (gDisableStructs[gActiveBattler].healBlockTimer == 0 || --gDisableStructs[gActiveBattler].healBlockTimer == 0)
                {
                    gStatuses3[gActiveBattler] &= ~(STATUS3_HEAL_BLOCK);
                    BattleScriptExecute(BattleScript_BufferEndTurn);
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_HEAL_BLOCK);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ROOST: // Return flying type.
            if (gBattleResources->flags->flags[gActiveBattler] & RESOURCE_FLAG_ROOST)
            {
                gBattleResources->flags->flags[gActiveBattler] &= ~(RESOURCE_FLAG_ROOST);
                gBattleMons[gActiveBattler].type1 = gBattleStruct->roostTypes[gActiveBattler][0];
                gBattleMons[gActiveBattler].type2 = gBattleStruct->roostTypes[gActiveBattler][1];
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ELECTRIFY:
            gStatuses4[gActiveBattler] &= ~(STATUS4_ELECTRIFIED);
            gBattleStruct->turnEffectsTracker++;
        case ENDTURN_POWDER:
            gBattleMons[gActiveBattler].status2 &= ~(STATUS2_POWDER);
            gBattleStruct->turnEffectsTracker++;
        case ENDTURN_THROAT_CHOP:
            if (gDisableStructs[gActiveBattler].throatChopTimer && --gDisableStructs[gActiveBattler].throatChopTimer == 0)
            {
                BattleScriptExecute(BattleScript_ThroatChopEndTurn);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_SLOW_START:
            if(gDisableStructs[gActiveBattler].slowStartTimer){
                gDisableStructs[gActiveBattler].slowStartTimer--;

                if (gDisableStructs[gActiveBattler].slowStartTimer == 0
                && (BATTLER_HAS_ABILITY_FAST(gActiveBattler, ABILITY_SLOW_START, ability)))
                {
                    BattleScriptExecute(BattleScript_SlowStartEnds);
                    effect++;
                }
                else if (gDisableStructs[gActiveBattler].slowStartTimer == 0
                    && (BATTLER_HAS_ABILITY_FAST(gActiveBattler, ABILITY_LETHARGY, ability)))
                {
                    BattleScriptExecute(BattleScript_LethargyEnds);
                    effect++;
                }
            }
            
            if (BATTLER_HAS_ABILITY(gActiveBattler, ABILITY_DISCIPLINE)          &&
                !BATTLER_HAS_ABILITY(gActiveBattler, ABILITY_GORILLA_TACTICS)    &&
                !BATTLER_HAS_ABILITY(gActiveBattler, ABILITY_SAGE_POWER)         &&
                !HOLD_EFFECT_CHOICE(GetBattlerHoldEffect(gActiveBattler, FALSE)) &&
                gDisableStructs[gActiveBattler].disciplineCounter)
            {
                gDisableStructs[gActiveBattler].disciplineCounter--;
                if (gDisableStructs[gActiveBattler].disciplineCounter == 0)
                {
                    gBattleStruct->choicedMove[gActiveBattler] = MOVE_NONE;
                    BattleScriptExecute(BattleScript_DisciplineLockEnds);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;

            break;
        case ENDTURN_PLASMA_FISTS:
            for (i = 0; i < gBattlersCount; i++)
                gStatuses4[i] &= ~(STATUS4_PLASMA_FISTS);
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_BATTLER_COUNT:  // done
            gLastChosenMove[gActiveBattler] = gChosenMove;
            gBattleStruct->turnEffectsTracker = 0;
            gBattleStruct->turnEffectsBattlerId++;
            break;
        }

        if (effect != 0)
            return effect;

    }
    gHitMarker &= ~(HITMARKER_GRUDGE | HITMARKER_SKIP_DMG_TRACK);
    return 0;
}

bool8 HandleWishPerishSongOnTurnEnd(void)
{
    gHitMarker |= (HITMARKER_GRUDGE | HITMARKER_SKIP_DMG_TRACK);

    switch (gBattleStruct->wishPerishSongState)
    {
    case 0:
        while (gBattleStruct->wishPerishSongBattlerId < gBattlersCount)
        {
            gActiveBattler = gBattleStruct->wishPerishSongBattlerId;
            if (gAbsentBattlerFlags & gBitTable[gActiveBattler])
            {
                gBattleStruct->wishPerishSongBattlerId++;
                continue;
            }

            gBattleStruct->wishPerishSongBattlerId++;
            if (gWishFutureKnock.futureSightCounter[gActiveBattler] != 0
             && --gWishFutureKnock.futureSightCounter[gActiveBattler] == 0
             && gBattleMons[gActiveBattler].hp != 0)
            {
                if (gWishFutureKnock.futureSightMove[gActiveBattler] == MOVE_FUTURE_SIGHT)
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FUTURE_SIGHT;
                else
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DOOM_DESIRE;

                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gWishFutureKnock.futureSightMove[gActiveBattler]);

                gBattlerTarget = gActiveBattler;
                gBattlerAttacker = gWishFutureKnock.futureSightAttacker[gActiveBattler];
                gSpecialStatuses[gBattlerTarget].dmg = 0xFFFF;
                gCurrentMove = gWishFutureKnock.futureSightMove[gActiveBattler];
                SetTypeBeforeUsingMove(gCurrentMove, gActiveBattler);
                BattleScriptExecute(BattleScript_MonTookFutureAttack);

                if (gWishFutureKnock.futureSightCounter[gActiveBattler] == 0
                 && gWishFutureKnock.futureSightCounter[gActiveBattler ^ BIT_FLANK] == 0)
                {
                    gSideStatuses[GET_BATTLER_SIDE(gBattlerTarget)] &= ~(SIDE_STATUS_FUTUREATTACK);
                }
                return TRUE;
            }
        }
        gBattleStruct->wishPerishSongState = 1;
        gBattleStruct->wishPerishSongBattlerId = 0;
        // fall through
    case 1:
        while (gBattleStruct->wishPerishSongBattlerId < gBattlersCount)
        {
            gActiveBattler = gBattlerAttacker = gBattlerByTurnOrder[gBattleStruct->wishPerishSongBattlerId];
            if (gAbsentBattlerFlags & gBitTable[gActiveBattler])
            {
                gBattleStruct->wishPerishSongBattlerId++;
                continue;
            }
            gBattleStruct->wishPerishSongBattlerId++;
            if (gStatuses3[gActiveBattler] & STATUS3_PERISH_SONG)
            {
                PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff1, 1, gDisableStructs[gActiveBattler].perishSongTimer);
                if (gDisableStructs[gActiveBattler].perishSongTimer == 0)
                {
                    gStatuses3[gActiveBattler] &= ~STATUS3_PERISH_SONG;
                    gBattleMoveDamage = gBattleMons[gActiveBattler].hp;
                    gBattlescriptCurrInstr = BattleScript_PerishSongTakesLife;
                }
                else
                {
                    gDisableStructs[gActiveBattler].perishSongTimer--;
                    gBattlescriptCurrInstr = BattleScript_PerishSongCountGoesDown;
                }
                BattleScriptExecute(gBattlescriptCurrInstr);
                return TRUE;
            }
        }
        // Hm...
        {
            u8 *state = &gBattleStruct->wishPerishSongState;
            *state = 2;
            gBattleStruct->wishPerishSongBattlerId = 0;
        }
        // fall through
    case 2:
        if ((gBattleTypeFlags & BATTLE_TYPE_ARENA)
         && gBattleStruct->arenaTurnCounter == 2
         && gBattleMons[0].hp != 0 && gBattleMons[1].hp != 0)
        {
            s32 i;

            for (i = 0; i < 2; i++)
                CancelMultiTurnMoves(i);

            gBattlescriptCurrInstr = BattleScript_ArenaDoJudgment;
            BattleScriptExecute(BattleScript_ArenaDoJudgment);
            gBattleStruct->wishPerishSongState++;
            return TRUE;
        }
        break;
    }

    gHitMarker &= ~(HITMARKER_GRUDGE | HITMARKER_SKIP_DMG_TRACK);

    return FALSE;
}

#define FAINTED_ACTIONS_MAX_CASE 7

bool8 HandleFaintedMonActions(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
        return FALSE;
    do
    {
        s32 i;
        switch (gBattleStruct->faintedActionsState)
        {
        case 0:
            gBattleStruct->faintedActionsBattlerId = 0;
            gBattleStruct->faintedActionsState++;
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gAbsentBattlerFlags & gBitTable[i] && !HasNoMonsToSwitch(i, PARTY_SIZE, PARTY_SIZE))
                    gAbsentBattlerFlags &= ~(gBitTable[i]);
            }
            // fall through
        case 1:
            do
            {
                gBattlerFainted = gBattlerTarget = gBattleStruct->faintedActionsBattlerId;
                if (gBattleMons[gBattleStruct->faintedActionsBattlerId].hp == 0
                 && !(gBattleStruct->givenExpMons & gBitTable[gBattlerPartyIndexes[gBattleStruct->faintedActionsBattlerId]])
                 && !(gAbsentBattlerFlags & gBitTable[gBattleStruct->faintedActionsBattlerId]))
                {
                    BattleScriptExecute(BattleScript_GiveExp);
                    gBattleStruct->faintedActionsState = 2;
                    return TRUE;
                }
            } while (++gBattleStruct->faintedActionsBattlerId != gBattlersCount);
            gBattleStruct->faintedActionsState = 3;
            break;
        case 2:
            OpponentSwitchInResetSentPokesToOpponentValue(gBattlerFainted);
            if (++gBattleStruct->faintedActionsBattlerId == gBattlersCount)
                gBattleStruct->faintedActionsState = 3;
            else
                gBattleStruct->faintedActionsState = 1;

            // Don't switch mons until all pokemon performed their actions or the battle's over.
            if (gBattleOutcome == 0
                && !NoAliveMonsForEitherParty()
                && gCurrentTurnActionNumber != gBattlersCount)
            {
                gAbsentBattlerFlags |= gBitTable[gBattlerFainted];
                return FALSE;
            }
            break;
        case 3:
            // Don't switch mons until all pokemon performed their actions or the battle's over.
            if (gBattleOutcome == 0
                && !NoAliveMonsForEitherParty()
                && gCurrentTurnActionNumber != gBattlersCount)
            {
                return FALSE;
            }
            gBattleStruct->faintedActionsBattlerId = 0;
            gBattleStruct->faintedActionsState++;
            // fall through
        case 4:
            do
            {
                gBattlerFainted = gBattlerTarget = gBattleStruct->faintedActionsBattlerId;
                if (gBattleMons[gBattleStruct->faintedActionsBattlerId].hp == 0
                 && !(gAbsentBattlerFlags & gBitTable[gBattleStruct->faintedActionsBattlerId]))
                {
                    BattleScriptExecute(BattleScript_HandleFaintedMon);
                    gBattleStruct->faintedActionsState = 5;
                    return TRUE;
                }
            } while (++gBattleStruct->faintedActionsBattlerId != gBattlersCount);
            gBattleStruct->faintedActionsState = 6;
            break;
        case 5:
            if (++gBattleStruct->faintedActionsBattlerId == gBattlersCount)
                gBattleStruct->faintedActionsState = 6;
            else
                gBattleStruct->faintedActionsState = 4;
            break;
        case 6:
            if (ItemBattleEffects(1, 0, TRUE))
                return TRUE;
            gBattleStruct->faintedActionsState++;
            break;
        case FAINTED_ACTIONS_MAX_CASE:
            break;
        }
    } while (gBattleStruct->faintedActionsState != FAINTED_ACTIONS_MAX_CASE);
    return FALSE;
}

void TryClearRageAndFuryCutter(void)
{
    s32 i;
    for (i = 0; i < gBattlersCount; i++)
    {
        if ((gBattleMons[i].status2 & STATUS2_RAGE) && gChosenMoveByBattler[i] != MOVE_RAGE)
            gBattleMons[i].status2 &= ~(STATUS2_RAGE);
        if (gDisableStructs[i].furyCutterCounter != 0 && gChosenMoveByBattler[i] != MOVE_FURY_CUTTER)
            gDisableStructs[i].furyCutterCounter = 0;
    }
}

enum
{
    CANCELLER_FLAGS,
    CANCELLER_ASLEEP,
    CANCELLER_FROZEN,
    CANCELLER_TRUANT,
    CANCELLER_RECHARGE,
    CANCELLER_FLINCH,
    CANCELLER_DISABLED,
    CANCELLER_GRAVITY,
    CANCELLER_HEAL_BLOCKED,
    CANCELLER_TAUNTED,
    CANCELLER_IMPRISONED,
    CANCELLER_CONFUSED,
    CANCELLER_PARALYSED,
    CANCELLER_BIDE,
    CANCELLER_THAW,
    CANCELLER_POWDER_MOVE,
    CANCELLER_POWDER_STATUS,
    CANCELLER_THROAT_CHOP,
    CANCELLER_MULTIHIT_MOVES,
    CANCELLER_END,
    CANCELLER_PSYCHIC_TERRAIN,
    CANCELLER_END2,
};

u8 AtkCanceller_UnableToUseMove(void)
{
    u8 effect = 0;
    s32 *bideDmg = &gBattleScripting.bideDmg;
    do
    {
        switch (gBattleStruct->atkCancellerTracker)
        {
        case CANCELLER_FLAGS: // flags clear
            gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_DESTINY_BOND);
            gStatuses3[gBattlerAttacker] &= ~(STATUS3_GRUDGE);
            gBattleScripting.tripleKickPower = 0;
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_ASLEEP: // check being asleep
            if (gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP)
            {
                if (UproarWakeUpCheck(gBattlerAttacker))
                {
                    gBattleMons[gBattlerAttacker].status1 &= ~(STATUS1_SLEEP);
                    gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_NIGHTMARE);
                    BattleScriptPushCursor();
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WOKE_UP_UPROAR;
                    gBattlescriptCurrInstr = BattleScript_MoveUsedWokeUp;
                    effect = 2;
                }
                else
                {
                    u8 toSub;
                    if (BATTLER_HAS_ABILITY(gBattlerAttacker, ABILITY_EARLY_BIRD))
                        toSub = 2;
                    else
                        toSub = 1;

                    if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP) < toSub)
                        gBattleMons[gBattlerAttacker].status1 &= ~(STATUS1_SLEEP);
                    else
                        gBattleMons[gBattlerAttacker].status1 -= toSub;

                    if (gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP)
                    {
                        if (gChosenMove != MOVE_SNORE && gChosenMove != MOVE_SLEEP_TALK)
                        {
                            gBattlescriptCurrInstr = BattleScript_MoveUsedIsAsleep;
                            gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                            effect = 2;
                        }
                    }
                    else
                    {
                        gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_NIGHTMARE);
                        BattleScriptPushCursor();
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WOKE_UP;
                        gBattlescriptCurrInstr = BattleScript_MoveUsedWokeUp;
                        effect = 2;
                    }
                }
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_FROZEN: // check being frozen
            if (gBattleMons[gBattlerAttacker].status1 & STATUS1_FREEZE && !(gBattleMoves[gCurrentMove].flags & FLAG_THAW_USER))
            {
                if (Random() % 5)
                {
                    gBattlescriptCurrInstr = BattleScript_MoveUsedIsFrozen;
                    gHitMarker |= HITMARKER_NO_ATTACKSTRING;
                }
                else // unfreeze
                {
                    gBattleMons[gBattlerAttacker].status1 &= ~(STATUS1_FREEZE);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveUsedUnfroze;
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DEFROSTED;
                }
                effect = 2;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_TRUANT: // truant
            if (GetBattlerAbility(gBattlerAttacker) == ABILITY_TRUANT && gDisableStructs[gBattlerAttacker].truantCounter)
            {
                CancelMultiTurnMoves(gBattlerAttacker);
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_LOAFING;
                gBattlerAbility = gBattlerAttacker;
                gBattlescriptCurrInstr = BattleScript_TruantLoafingAround;
                gMoveResultFlags |= MOVE_RESULT_MISSED;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_RECHARGE: // recharge
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_RECHARGE)
            {
                gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_RECHARGE);
                gDisableStructs[gBattlerAttacker].rechargeTimer = 0;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedMustRecharge;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_FLINCH: // flinch
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_FLINCHED)
            {
                gProtectStructs[gBattlerAttacker].flinchImmobility = TRUE;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedFlinched;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_DISABLED: // disabled move
            if (gDisableStructs[gBattlerAttacker].disabledMove == gCurrentMove && gDisableStructs[gBattlerAttacker].disabledMove != 0)
            {
                gProtectStructs[gBattlerAttacker].usedDisabledMove = TRUE;
                gBattleScripting.battler = gBattlerAttacker;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsDisabled;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_HEAL_BLOCKED:
            if (IsHealBlockPreventingMove(gBattlerAttacker, gCurrentMove))
            {
                gProtectStructs[gBattlerAttacker].usedHealBlockedMove = TRUE;
                gBattleScripting.battler = gBattlerAttacker;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedHealBlockPrevents;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_GRAVITY:
            if (gFieldStatuses & STATUS_FIELD_GRAVITY && IsGravityPreventingMove(gCurrentMove))
            {
                gProtectStructs[gBattlerAttacker].usedGravityPreventedMove = TRUE;
                gBattleScripting.battler = gBattlerAttacker;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedGravityPrevents;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_TAUNTED: // taunt
            if (gDisableStructs[gBattlerAttacker].tauntTimer && gBattleMoves[gCurrentMove].power == 0)
            {
                gProtectStructs[gBattlerAttacker].usedTauntedMove = TRUE;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsTaunted;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_IMPRISONED: // imprisoned
            if (GetImprisonedMovesCount(gBattlerAttacker, gCurrentMove))
            {
                gProtectStructs[gBattlerAttacker].usedImprisonedMove = TRUE;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsImprisoned;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_CONFUSED: // confusion
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_CONFUSION)
            {
                gBattleMons[gBattlerAttacker].status2 -= STATUS2_CONFUSION_TURN(1);
                if (gBattleMons[gBattlerAttacker].status2 & STATUS2_CONFUSION)
                {
                    if (Random() % ((B_CONFUSION_SELF_DMG_CHANCE >= GEN_7) ? 3 : 2) == 0) // confusion dmg
                    {
                        u8 moveType = TYPE_MYSTERY;
                        gBattleCommunication[MULTISTRING_CHOOSER] = TRUE;
                        gBattlerTarget = gBattlerAttacker;
                        gBattleMoveDamage = CalculateMoveDamage(MOVE_NONE, gBattlerAttacker, gBattlerAttacker, &moveType, IsAbilityOnSide(BATTLE_OPPOSITE(gBattlerAttacker), ABILITY_COSMIC_DAZE) ? 80 : 40, FALSE, FALSE, TRUE);
                        gProtectStructs[gBattlerAttacker].confusionSelfDmg = TRUE;
                        gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                    }
                    else
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = FALSE;
                        BattleScriptPushCursor();
                    }
                    gBattlescriptCurrInstr = BattleScript_MoveUsedIsConfused;
                }
                else // snapped out of confusion
                {
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveUsedIsConfusedNoMore;
                }
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_PARALYSED: // paralysis
            if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_PARALYSIS) && (Random() % 4) == 0)
            {
                gProtectStructs[gBattlerAttacker].prlzImmobility = TRUE;
                // This is removed in Emerald for some reason
                //CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsParalyzed;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_BIDE: // bide
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_BIDE)
            {
                gBattleMons[gBattlerAttacker].status2 -= STATUS2_BIDE_TURN(1);
                if (gBattleMons[gBattlerAttacker].status2 & STATUS2_BIDE)
                {
                    gBattlescriptCurrInstr = BattleScript_BideStoringEnergy;
                }
                else
                {
                    // This is removed in Emerald for some reason
                    //gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_MULTIPLETURNS);
                    if (gTakenDmg[gBattlerAttacker])
                    {
                        gCurrentMove = MOVE_BIDE;
                        *bideDmg = gTakenDmg[gBattlerAttacker] * 2;
                        gBattlerTarget = gTakenDmgByBattler[gBattlerAttacker];
                        if (gAbsentBattlerFlags & gBitTable[gBattlerTarget])
                            gBattlerTarget = GetMoveTarget(MOVE_BIDE, 1);
                        gBattlescriptCurrInstr = BattleScript_BideAttack;
                    }
                    else
                    {
                        gBattlescriptCurrInstr = BattleScript_BideNoEnergyToAttack;
                    }
                }
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_THAW: // move thawing
            if (gBattleMons[gBattlerAttacker].status1 & STATUS1_FREEZE)
            {
                if (!(gBattleMoves[gCurrentMove].effect == EFFECT_BURN_UP && !IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_FIRE)))
                {
                    gBattleMons[gBattlerAttacker].status1 &= ~(STATUS1_FREEZE);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveUsedUnfroze;
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DEFROSTED_BY_MOVE;
                }
                effect = 2;
            }
            if (gBattleMons[gBattlerAttacker].status1 & STATUS1_FROSTBITE && (gBattleMoves[gCurrentMove].flags & FLAG_THAW_USER))
            {
                if (!(gBattleMoves[gCurrentMove].effect == EFFECT_BURN_UP && !IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_FIRE)))
                {
                    gBattleMons[gBattlerAttacker].status1 &= ~STATUS1_FROSTBITE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveUsedUnfrostbite;
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FROSTBITE_HEALED_BY_MOVE;
                }
                effect = 2;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_POWDER_MOVE:
            if ((gBattleMoves[gCurrentMove].flags & FLAG_POWDER) && (gBattlerAttacker != gBattlerTarget) && !IsMyceliumMightActive(gBattlerAttacker)) // Rage Powder targets the user
            {
                if ((B_POWDER_GRASS >= GEN_6 && IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_GRASS))
                    || GetBattlerAbility(gBattlerTarget) == ABILITY_OVERCOAT
					|| BattlerHasInnate(gBattlerTarget, ABILITY_OVERCOAT))
                {
                    gBattlerAbility = gBattlerTarget;
                    effect = 1;
                }
                else if (GetBattlerHoldEffect(gBattlerTarget, TRUE) == HOLD_EFFECT_SAFETY_GOGGLES)
                {
                    RecordItemEffectBattle(gBattlerTarget, HOLD_EFFECT_SAFETY_GOGGLES);
                    gLastUsedItem = gBattleMons[gBattlerTarget].item;
                    effect = 1;
                }

                if (effect)
                    gBattlescriptCurrInstr = BattleScript_PowderMoveNoEffect;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_POWDER_STATUS:
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_POWDER)
            {
                u32 moveType;
                GET_MOVE_TYPE(gCurrentMove, moveType);
                if (moveType == TYPE_FIRE)
                {
                    gProtectStructs[gBattlerAttacker].powderSelfDmg = TRUE;
                    gBattleMoveDamage = BATTLER_HAS_MAGIC_GUARD(gBattlerAttacker) ? 0 : (gBattleMons[gBattlerAttacker].maxHP / 4);
                    gBattlescriptCurrInstr = BattleScript_MoveUsedPowder;
                    effect = 1;
                }
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_THROAT_CHOP:
            if (gDisableStructs[gBattlerAttacker].throatChopTimer && gBattleMoves[gCurrentMove].flags & FLAG_SOUND)
            {
                gProtectStructs[gBattlerAttacker].usedThroatChopPreventedMove = TRUE;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsThroatChopPrevented;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_MULTIHIT_MOVES:
        {
            if (gBattleMoves[gCurrentMove].effect == EFFECT_MULTI_HIT)
            {
                u16 ability = gBattleMons[gBattlerAttacker].ability;

                if (ability == ABILITY_SKILL_LINK || 
                    BattlerHasInnate(gBattlerAttacker, ABILITY_SKILL_LINK))
                {
                    gMultiHitCounter = 5;
                }
                else if (ability == ABILITY_KUNOICHI_BLADE || 
                    BattlerHasInnate(gBattlerAttacker, ABILITY_KUNOICHI_BLADE))
                {
                    gMultiHitCounter = 5;
                } 
                else if (ability == ABILITY_BATTLE_BOND
                && gCurrentMove == MOVE_WATER_SHURIKEN
                && gBattleMons[gBattlerAttacker].species == SPECIES_GRENINJA_ASH)
                {
                    gMultiHitCounter = 3;
                }
                else
                {
                    if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_LOADED_DICE)
                    {
                        gMultiHitCounter = 4 + (Random() % 2);
                    }
                    else
                    {
                        // 2 and 3 hits: 33.3%
                        // 4 and 5 hits: 16.7%
                        gMultiHitCounter = Random() % 4;
                        if (gMultiHitCounter > 2)
                        {
                            gMultiHitCounter = (Random() % 3);
                            if (gMultiHitCounter < 2)
                                gMultiHitCounter = 2;
                            else
                                gMultiHitCounter = 3;
                        }
                        else
                            gMultiHitCounter += 3;
                    }
                }

                PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
            }
            else if (IsTwoStrikesMove(gCurrentMove))
            {
                gMultiHitCounter = 2;
				PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
            }
            else if (gBattleMoves[gCurrentMove].effect == EFFECT_DOUBLE_HIT)
            {
                gMultiHitCounter = gBattleMoves[gCurrentMove].argument ? gBattleMoves[gCurrentMove].argument : 2;
				PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
            }
            else if (gBattleMoves[gCurrentMove].effect == EFFECT_TRIPLE_KICK)
            {
                gMultiHitCounter = 3;
				PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
            }
            else if (gBattleMoves[gCurrentMove].effect == EFFECT_TEN_HITS)
            {
                gMultiHitCounter = 10;
				PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
            }
            #if B_BEAT_UP_DMG >= GEN_5
            else if (gBattleMoves[gCurrentMove].effect == EFFECT_BEAT_UP)
            {
                struct Pokemon* party;
                int i;

                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    party = gPlayerParty;
                else
                    party = gEnemyParty;
                
                for (i = 0; i < PARTY_SIZE; i++)
				{
					if (GetMonData(&party[i], MON_DATA_HP)
					&& GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE
					&& !GetMonData(&party[i], MON_DATA_IS_EGG)
					&& !GetMonData(&party[i], MON_DATA_STATUS))
						gMultiHitCounter++;
				}

				gBattleCommunication[0] = 0; // For later
				PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
            }
            #endif
            gBattleStruct->atkCancellerTracker++;
            break;
        }
        case CANCELLER_END:
            break;
        }

    } while (gBattleStruct->atkCancellerTracker != CANCELLER_END && gBattleStruct->atkCancellerTracker != CANCELLER_END2 && effect == 0);

    if (effect == 2)
    {
        gActiveBattler = gBattlerAttacker;
        BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
        MarkBattlerForControllerExec(gActiveBattler);
    }
    return effect;
}

// After Protean Activation.
u8 AtkCanceller_UnableToUseMove2(void)
{
    u8 effect = 0;

    do
    {
        switch (gBattleStruct->atkCancellerTracker)
        {
        case CANCELLER_END:
            gBattleStruct->atkCancellerTracker++;
        case CANCELLER_PSYCHIC_TERRAIN:
            if (GetCurrentTerrain() == STATUS_FIELD_PSYCHIC_TERRAIN
                && IsBattlerGrounded(gBattlerTarget)
                && GetChosenMovePriority(gBattlerAttacker, gBattlerTarget) > 0
                && gBattleMoves[gCurrentMove].target == MOVE_TARGET_SELECTED
                && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget))
            {
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedPsychicTerrainPrevents;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_END2:
            break;
        }

    } while (gBattleStruct->atkCancellerTracker != CANCELLER_END2 && effect == 0);

    return effect;
}

bool8 HasNoMonsToSwitch(u8 battler, u8 partyIdBattlerOn1, u8 partyIdBattlerOn2)
{
    struct Pokemon *party;
    u8 id1, id2;
    s32 i;

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        return FALSE;

    if (BATTLE_TWO_VS_ONE_OPPONENT && GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        id2 = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        id1 = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
        party = gEnemyParty;

        if (partyIdBattlerOn1 == PARTY_SIZE)
            partyIdBattlerOn1 = gBattlerPartyIndexes[id2];
        if (partyIdBattlerOn2 == PARTY_SIZE)
            partyIdBattlerOn2 = gBattlerPartyIndexes[id1];

        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&party[i], MON_DATA_HP) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG
             && i != partyIdBattlerOn1 && i != partyIdBattlerOn2
             && i != *(gBattleStruct->monToSwitchIntoId + id2) && i != id1[gBattleStruct->monToSwitchIntoId])
                break;
        }
        return (i == PARTY_SIZE);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        if (GetBattlerSide(battler) == B_SIDE_PLAYER)
            party = gPlayerParty;
        else
            party = gEnemyParty;

        id1 = ((battler & BIT_FLANK) / 2);
        for (i = id1 * 3; i < id1 * 3 + 3; i++)
        {
            if (GetMonData(&party[i], MON_DATA_HP) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG)
                break;
        }
        return (i == id1 * 3 + 3);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
        {
            if (GetBattlerSide(battler) == B_SIDE_PLAYER)
            {
                party = gPlayerParty;
                id2 = GetBattlerMultiplayerId(battler);
                id1 = GetLinkTrainerFlankId(id2);
            }
            else
            {
                party = gEnemyParty;
                if (battler == 1)
                    id1 = 0;
                else
                    id1 = 1;
            }
        }
        else
        {
            id2 = GetBattlerMultiplayerId(battler);

            if (GetBattlerSide(battler) == B_SIDE_PLAYER)
                party = gPlayerParty;
            else
                party = gEnemyParty;

            id1 = GetLinkTrainerFlankId(id2);
        }

        for (i = id1 * 3; i < id1 * 3 + 3; i++)
        {
            if (GetMonData(&party[i], MON_DATA_HP) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG)
                break;
        }
        return (i == id1 * 3 + 3);
    }
    else if ((gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) && GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        party = gEnemyParty;

        if (battler == 1)
            id1 = 0;
        else
            id1 = 3;

        for (i = id1; i < id1 + 3; i++)
        {
            if (GetMonData(&party[i], MON_DATA_HP) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG)
                break;
        }
        return (i == id1 + 3);
    }
    else
    {
        if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
        {
            id2 = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            id1 = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
            party = gEnemyParty;
        }
        else
        {
            id2 = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
            id1 = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
            party = gPlayerParty;
        }

        if (partyIdBattlerOn1 == PARTY_SIZE)
            partyIdBattlerOn1 = gBattlerPartyIndexes[id2];
        if (partyIdBattlerOn2 == PARTY_SIZE)
            partyIdBattlerOn2 = gBattlerPartyIndexes[id1];

        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&party[i], MON_DATA_HP) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG
             && i != partyIdBattlerOn1 && i != partyIdBattlerOn2
             && i != *(gBattleStruct->monToSwitchIntoId + id2) && i != id1[gBattleStruct->monToSwitchIntoId])
                break;
        }
        return (i == PARTY_SIZE);
    }
}

static const u16 sWeatherFlagsInfo[][3] =
{
    [ENUM_WEATHER_RAIN]         = {WEATHER_RAIN_TEMPORARY,      WEATHER_RAIN_PERMANENT,      HOLD_EFFECT_DAMP_ROCK},
    [ENUM_WEATHER_RAIN_PRIMAL]  = {WEATHER_RAIN_PRIMAL,         WEATHER_RAIN_PRIMAL,         HOLD_EFFECT_DAMP_ROCK},
    [ENUM_WEATHER_SUN]          = {WEATHER_SUN_TEMPORARY,       WEATHER_SUN_PERMANENT,       HOLD_EFFECT_HEAT_ROCK},
    [ENUM_WEATHER_SUN_PRIMAL]   = {WEATHER_SUN_PRIMAL,          WEATHER_SUN_PRIMAL,          HOLD_EFFECT_HEAT_ROCK},
    [ENUM_WEATHER_SANDSTORM]    = {WEATHER_SANDSTORM_TEMPORARY, WEATHER_SANDSTORM_PERMANENT, HOLD_EFFECT_SMOOTH_ROCK},
    [ENUM_WEATHER_HAIL]         = {WEATHER_HAIL_TEMPORARY,      WEATHER_HAIL_PERMANENT,      HOLD_EFFECT_ICY_ROCK},
    [ENUM_WEATHER_STRONG_WINDS] = {WEATHER_STRONG_WINDS,        WEATHER_STRONG_WINDS,        HOLD_EFFECT_NONE},
};

bool32 TryChangeBattleWeather(u8 battler, u32 weatherEnumId, bool32 viaAbility)
{
    if ((gBattleWeather & WEATHER_PRIMAL_ANY)
        && !BATTLER_HAS_ABILITY(battler, ABILITY_DESOLATE_LAND)
        && !BATTLER_HAS_ABILITY(battler, ABILITY_PRIMORDIAL_SEA)
        && !BATTLER_HAS_ABILITY(battler, ABILITY_DELTA_STREAM))
    {
        return FALSE;
    }
    else if (viaAbility && B_ABILITY_WEATHER <= GEN_5
        && !(gBattleWeather & sWeatherFlagsInfo[weatherEnumId][1]))
    {
        gBattleWeather = (sWeatherFlagsInfo[weatherEnumId][0] | sWeatherFlagsInfo[weatherEnumId][1]);
        return TRUE;
    }
    else if (!(gBattleWeather & (sWeatherFlagsInfo[weatherEnumId][0] | sWeatherFlagsInfo[weatherEnumId][1])))
    {
        gBattleWeather = (sWeatherFlagsInfo[weatherEnumId][0]);
        if (GetBattlerHoldEffect(battler, TRUE) == sWeatherFlagsInfo[weatherEnumId][2])
            gWishFutureKnock.weatherDuration = WEATHER_DURATION_EXTENDED;
        else
            gWishFutureKnock.weatherDuration = WEATHER_DURATION;

        return TRUE;
    }

    return FALSE;
}

static bool32 TryChangeBattleTerrain(u32 battler, u32 statusFlag, u8 *timer)
{
    if (!(gFieldStatuses & statusFlag))
    {
        gFieldStatuses &= ~(STATUS_FIELD_MISTY_TERRAIN | STATUS_FIELD_GRASSY_TERRAIN | STATUS_FIELD_ELECTRIC_TERRAIN | STATUS_FIELD_PSYCHIC_TERRAIN);
        gFieldStatuses |= statusFlag;

        if (GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_TERRAIN_EXTENDER)
            *timer = TERRAIN_DURATION_EXTENDED;
        else
            *timer = TERRAIN_DURATION;

        gBattlerAttacker = gBattleScripting.battler = battler;
        return TRUE;
    }

    return FALSE;
}

bool32 ShouldChangeFormHpBased(u32 battler)
{
    // Ability,     form >, form <=, hp divided
    static const u16 forms[][4] =
    {
        {ABILITY_SHIELDS_DOWN, SPECIES_MINIOR,               SPECIES_MINIOR_CORE_RED,              2},
        {ABILITY_SHIELDS_DOWN, SPECIES_MINIOR_METEOR_BLUE,   SPECIES_MINIOR_CORE_BLUE,             2},
        {ABILITY_SHIELDS_DOWN, SPECIES_MINIOR_METEOR_GREEN,  SPECIES_MINIOR_CORE_GREEN,            2},
        {ABILITY_SHIELDS_DOWN, SPECIES_MINIOR_METEOR_INDIGO, SPECIES_MINIOR_CORE_INDIGO,           2},
        {ABILITY_SHIELDS_DOWN, SPECIES_MINIOR_METEOR_ORANGE, SPECIES_MINIOR_CORE_ORANGE,           2},
        {ABILITY_SHIELDS_DOWN, SPECIES_MINIOR_METEOR_VIOLET, SPECIES_MINIOR_CORE_VIOLET,           2},
        {ABILITY_SHIELDS_DOWN, SPECIES_MINIOR_METEOR_YELLOW, SPECIES_MINIOR_CORE_YELLOW,           2},
        {ABILITY_SCHOOLING,    SPECIES_WISHIWASHI_SCHOOL,    SPECIES_WISHIWASHI,                   4},
        {ABILITY_GULP_MISSILE, SPECIES_CRAMORANT,            SPECIES_CRAMORANT_GORGING,            2},
        {ABILITY_GULP_MISSILE, SPECIES_CRAMORANT,            SPECIES_CRAMORANT_GULPING,            1},
    };
    u32 i;

    for (i = 0; i < ARRAY_COUNT(forms); i++)
    {
        if (GetBattlerAbility(battler) == forms[i][0] || BattlerHasInnate(battler, forms[i][0]))
        {
            if (gBattleMons[battler].species == forms[i][2]
                && gBattleMons[battler].hp > gBattleMons[battler].maxHP / forms[i][3])
            {
                UpdateAbilityStateIndicesForNewSpecies(gActiveBattler, forms[i][1]);
                gBattleMons[battler].species = forms[i][1];
                return TRUE;
            }
            if (gBattleMons[battler].species == forms[i][1]
                && gBattleMons[battler].hp <= gBattleMons[battler].maxHP / forms[i][3])
            {
                UpdateAbilityStateIndicesForNewSpecies(gActiveBattler, forms[i][2]);
                gBattleMons[battler].species = forms[i][2];
                return TRUE;
            }
        }
    }

    //Darmanitan
    if (gBattleMons[battler].species == SPECIES_DARMANITAN && 
	    (BATTLER_HAS_ABILITY(battler, ABILITY_ZEN_MODE)) &&
		gBattleMons[battler].hp != 0){
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_ZEN_MODE;
            gBattlerAttacker = battler;
            UpdateAbilityStateIndicesForNewSpecies(gActiveBattler, SPECIES_DARMANITAN_ZEN_MODE);
            gBattleMons[battler].species = SPECIES_DARMANITAN_ZEN_MODE;
			return TRUE;
	}

    //Darmanitan Galarian
    if (gBattleMons[battler].species == SPECIES_DARMANITAN_GALARIAN && 
	    (BATTLER_HAS_ABILITY(battler, ABILITY_ZEN_MODE)) &&
		gBattleMons[battler].hp != 0){
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_ZEN_MODE;
            gBattlerAttacker = battler;
            UpdateAbilityStateIndicesForNewSpecies(gActiveBattler, SPECIES_DARMANITAN_ZEN_MODE_GALARIAN);
            gBattleMons[battler].species = SPECIES_DARMANITAN_ZEN_MODE_GALARIAN;
			return TRUE;
	}

    //Castform
    if ((gBattleMons[battler].species == SPECIES_CASTFORM       ||
         gBattleMons[battler].species == SPECIES_CASTFORM_RAINY ||
         gBattleMons[battler].species == SPECIES_CASTFORM_SUNNY ||
         gBattleMons[battler].species == SPECIES_CASTFORM_SANDY ||
         gBattleMons[battler].species == SPECIES_CASTFORM_SNOWY) && 
	    BATTLER_HAS_ABILITY(battler, ABILITY_FORECAST) &&
		gBattleMons[battler].hp != 0){
		if (gBattleWeather & (WEATHER_RAIN_ANY) && gBattleMons[battler].species != SPECIES_CASTFORM_RAINY)
        {
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_FORECAST;
            gBattlerAttacker = battler;
            UpdateAbilityStateIndicesForNewSpecies(gActiveBattler, SPECIES_CASTFORM_RAINY);
            gBattleMons[battler].species = SPECIES_CASTFORM_RAINY;
			return TRUE;
        }
        else if (gBattleWeather & (WEATHER_SUN_ANY) && gBattleMons[battler].species != SPECIES_CASTFORM_SUNNY)
        {
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_FORECAST;
            gBattlerAttacker = battler;
            UpdateAbilityStateIndicesForNewSpecies(gActiveBattler, SPECIES_CASTFORM_SUNNY);
            gBattleMons[battler].species = SPECIES_CASTFORM_SUNNY;
			return TRUE;
        }
		else if (gBattleWeather & (WEATHER_HAIL_ANY) && gBattleMons[battler].species != SPECIES_CASTFORM_SNOWY)
        {
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_FORECAST;
            gBattlerAttacker = battler;
            UpdateAbilityStateIndicesForNewSpecies(gActiveBattler, SPECIES_CASTFORM_SNOWY);
            gBattleMons[battler].species = SPECIES_CASTFORM_SNOWY;
			return TRUE;
        }
		else if (gBattleWeather & (WEATHER_SANDSTORM_ANY) && gBattleMons[battler].species != SPECIES_CASTFORM_SANDY)
        {
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_FORECAST;
            gBattlerAttacker = battler;
            UpdateAbilityStateIndicesForNewSpecies(gActiveBattler, SPECIES_CASTFORM_SANDY);
            gBattleMons[battler].species = SPECIES_CASTFORM_SANDY;
			return TRUE;
        }else if(!(gBattleWeather & (WEATHER_ANY)) && gBattleMons[battler].species != SPECIES_CASTFORM){
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_FORECAST;
            gBattlerAttacker = battler;
            UpdateAbilityStateIndicesForNewSpecies(gActiveBattler, SPECIES_CASTFORM);
            gBattleMons[battler].species = SPECIES_CASTFORM;
			return TRUE;
        }
        else{
			return FALSE;
        }
	}

    //Cherrim
    if (gBattleMons[battler].species == SPECIES_CHERRIM && 
	          BATTLER_HAS_ABILITY(battler, ABILITY_FLOWER_GIFT) &&
		      gBattleMons[battler].hp != 0){
			if (gBattleWeather & (WEATHER_SUN_ANY))
        {
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_FLOWER_GIFT;
            gBattlerAttacker = battler;
            UpdateAbilityStateIndicesForNewSpecies(gActiveBattler, SPECIES_CHERRIM_SUNSHINE);
            gBattleMons[battler].species = SPECIES_CHERRIM_SUNSHINE;
			return TRUE;
		}
	}
    else if(gBattleMons[battler].species == SPECIES_CHERRIM_SUNSHINE &&
	          BATTLER_HAS_ABILITY(battler, ABILITY_FLOWER_GIFT) &&
		      gBattleMons[battler].hp != 0){
			if (!(gBattleWeather & (WEATHER_SUN_ANY)))
        {
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_FLOWER_GIFT;
            gBattlerAttacker = battler;
            UpdateAbilityStateIndicesForNewSpecies(gActiveBattler, SPECIES_CHERRIM);
            gBattleMons[battler].species = SPECIES_CHERRIM;
			return TRUE;
		}
	}

    if (gBattleMons[battler].species == SPECIES_PALAFIN && 
	          BATTLER_HAS_ABILITY(battler, ABILITY_ZERO_TO_HERO) &&
		      gBattleMons[battler].hp != 0 &&
		      GetSingleUseAbilityCounter(battler, ABILITY_ZERO_TO_HERO)){
        {
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_ZERO_TO_HERO;
            gBattlerAttacker = battler;
            UpdateAbilityStateIndicesForNewSpecies(gActiveBattler, SPECIES_PALAFIN_HERO);
            gBattleMons[battler].species = SPECIES_PALAFIN_HERO;
			return TRUE;
		}
	}

    return FALSE;
}

static u8 ForewarnChooseMove(u32 battler)
{
    struct Forewarn {
        u8 battlerId;
        u8 power;
        u16 moveId;
    };
    u32 i, j, bestId, count;
    struct Forewarn *data = malloc(sizeof(struct Forewarn) * MAX_BATTLERS_COUNT * MAX_MON_MOVES);

    // Put all moves
    for (count = 0, i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (IsBattlerAlive(i) && GetBattlerSide(i) != GetBattlerSide(battler))
        {
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (gBattleMons[i].moves[j] == MOVE_NONE)
                    continue;
                data[count].moveId = gBattleMons[i].moves[j];
                data[count].battlerId = i;
                switch (gBattleMoves[data[count].moveId].effect)
                {
                case EFFECT_OHKO:
                    data[count].power = 150;
                    break;
                case EFFECT_COUNTER:
                case EFFECT_MIRROR_COAT:
                case EFFECT_METAL_BURST:
                    data[count].power = 120;
                    break;
                default:
                    if (gBattleMoves[data[count].moveId].power == 1)
                        data[count].power = 80;
                    else
                        data[count].power = gBattleMoves[data[count].moveId].power;
                    break;
                }
                count++;
            }
        }
    }

    for (bestId = 0, i = 1; i < count; i++)
    {
        if (data[i].power > data[bestId].power)
            bestId = i;
        else if (data[i].power == data[bestId].power && Random() & 1)
            bestId = i;
    }

    gBattlerTarget = data[bestId].battlerId;
    PREPARE_MOVE_BUFFER(gBattleTextBuff1, data[bestId].moveId)
    RecordKnownMove(gBattlerTarget, data[bestId].moveId);

    free(data);
}

bool32 TryPrimalReversion(u8 battlerId)
{
    if (GetBattlerHoldEffect(battlerId, FALSE) == HOLD_EFFECT_PRIMAL_ORB
     && GetPrimalReversionSpecies(gBattleMons[battlerId].species, gBattleMons[battlerId].item) != SPECIES_NONE)
    {
        gBattlerAttacker = battlerId;
        BattleScriptExecute(BattleScript_PrimalReversion);
        return TRUE;
    }
    return FALSE;
}

bool8 CheckAndSetSwitchInAbility(u8 battlerId, u16 ability)
{
    switch (BattlerHasInnateOrAbility(battlerId, ability))
    {
        case BATTLER_INNATE:
            if(!gBattlerState[battlerId].switchInAbilityDone[GetBattlerInnateNum(battlerId, ability) + 1]){
                gBattlerState[battlerId].switchInAbilityDone[GetBattlerInnateNum(battlerId, ability) + 1] = TRUE;
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ability;
                gBattlerAttacker = battlerId;
                return TRUE;
            }
            return FALSE;
        case BATTLER_ABILITY:
            if(!gBattlerState[battlerId].switchInAbilityDone[0]){
                gBattlerState[battlerId].switchInAbilityDone[0] = TRUE;
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ability;
                gBattlerAttacker = battlerId;
                return TRUE;
            }
            return FALSE;
        default:
            return FALSE;
    }
}

s8 GetSingleUseAbilityCounter(u8 battler, u16 ability) {
    
    switch (BattlerHasInnateOrAbility(battler, ability))
    {
        case BATTLER_INNATE:
            return gBattleStruct->singleuseability[gBattlerPartyIndexes[battler]][GetBattlerInnateNum(battler, ability) + 1][GetBattlerSide(battler)];
        case BATTLER_ABILITY:
            return gBattleStruct->singleuseability[gBattlerPartyIndexes[battler]][0][GetBattlerSide(battler)];
        default:
            return -1;
    }
}

void SetSingleUseAbilityCounter(u8 battler, u16 ability, u8 value) {
    
    switch (BattlerHasInnateOrAbility(battler, ability))
    {
        case BATTLER_INNATE:
            gBattleStruct->singleuseability[gBattlerPartyIndexes[battler]][GetBattlerInnateNum(battler, ability) + 1][GetBattlerSide(battler)] = value;
            return;
        case BATTLER_ABILITY:
            gBattleStruct->singleuseability[gBattlerPartyIndexes[battler]][0][GetBattlerSide(battler)] = value;
            return;
        default:
            return;
    }
}

void IncrementSingleUseAbilityCounter(u8 battler, u16 ability, u8 value) {
    SetSingleUseAbilityCounter(battler, ability, GetSingleUseAbilityCounter(battler, ability) + value);
}

union AbilityStates GetAbilityStateAs(u8 battler, u16 ability)
{
    return (union AbilityStates) { .intValue = GetAbilityState(battler, ability) };
}

u32 GetAbilityState(u8 battler, u16 ability) {
    
    switch (BattlerHasInnateOrAbility(battler, ability))
    {
        case BATTLER_INNATE:
            return gBattlerState[battler].abilityState[GetBattlerInnateNum(battler, ability) + 1];
        case BATTLER_ABILITY:
            return gBattlerState[battler].abilityState[0];
        default:
            return 0;
    }
}

void SetAbilityStateAs(u8 battler, u16 ability, union AbilityStates value)
{
    SetAbilityState(battler, ability, value.intValue);
}

void SetAbilityState(u8 battler, u16 ability, u32 value) {
    
    switch (BattlerHasInnateOrAbility(battler, ability))
    {
        case BATTLER_INNATE:
            gBattlerState[battler].abilityState[GetBattlerInnateNum(battler, ability) + 1] = value;
            return;
        case BATTLER_ABILITY:
            gBattlerState[battler].abilityState[0] = value;
            return;
        default:
            return;
    }
}

void IncrementAbilityState(u8 battler, u16 ability, u32 value) {
    SetAbilityState(battler, ability, GetAbilityState(battler, ability) + value);
}

static bool8 UseEntryMove(u8 battler, u16 ability, u8 *effect, u16 extraMove, u8 movePower, u8 moveEffectPercentChance, u8 extraMoveSecondaryEffect) {
    bool8 hasTarget      = FALSE;
    u8 i;
    u8 opposingBattler = BATTLE_OPPOSITE(battler);
    
    if (!CheckAndSetSwitchInAbility(battler, ability)) return FALSE;

    //Checks Target
    for (i = 0; i < 2; opposingBattler ^= BIT_FLANK, i++)
    {
        if (IsBattlerAlive(opposingBattler) && gBattleMons[opposingBattler].hp != 1)
        {
            gBattlerTarget = opposingBattler;
            hasTarget = TRUE;
            break;
        }
    }

    //This is the stuff that has to be changed for each ability
    if(hasTarget && CanUseExtraMove(battler, gBattlerTarget)){
        gTempMove = gCurrentMove;
        gCurrentMove = extraMove;
        gMultiHitCounter = 0;
        gProtectStructs[battler].extraMoveUsed = TRUE;

        //Move Effect
        VarSet(VAR_EXTRA_MOVE_DAMAGE,     movePower);
        VarSet(VAR_TEMP_MOVEEFECT_CHANCE, moveEffectPercentChance);
        VarSet(VAR_TEMP_MOVEEFFECT,       extraMoveSecondaryEffect);

        gBattleScripting.replaceEndWithEnd3++;
        BattleScriptPushCursorAndCallback(BattleScript_AttackerUsedAnExtraMoveOnSwitchIn);
        (*effect)++;
        return TRUE;
    }

    return FALSE;
}

static u8 CheckAndSetOncePerTurnAbility(u8 battler, u16 ability)
{
    u8 index;

    switch (BattlerHasInnateOrAbility(battler, ability))
    {
        case BATTLER_INNATE:
            index = GetBattlerInnateNum(battler, ability) + 1;
            break;
        
        case BATTLER_ABILITY:
            index = 0;
            break;
        
        default:
            return;
    }

    if (!gSpecialStatuses[battler].turnAbilityTriggers[index])
    {
        gSpecialStatuses[battler].turnAbilityTriggers[index]++;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static u16 UseAttackerFollowUpMove(u8 battler, u16 ability, u16 extraMove, u8 movePower, u8 moveEffectPercentChance, u8 extraMoveSecondaryEffect)
{
    gTempMove = gCurrentMove;
    gCurrentMove = extraMove;
    VarSet(VAR_EXTRA_MOVE_DAMAGE, movePower);
    gProtectStructs[battler].extraMoveUsed = TRUE;

    //Move Effect
    VarSet(VAR_TEMP_MOVEEFECT_CHANCE, moveEffectPercentChance);
    VarSet(VAR_TEMP_MOVEEFFECT, extraMoveSecondaryEffect);

    gBattleScripting.abilityPopupOverwrite = ability;

    SetTypeBeforeUsingMove(extraMove, battler);

    return extraMove;
}

static void AbilityHealMonStatus(u8 *effect, u8 battler, u16 ability) {
    if (!(gBattleMons[battler].status1 & STATUS1_ANY)) return;

    if (gBattleMons[battler].status1 & (STATUS1_POISON | STATUS1_TOXIC_POISON))
        StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
    if (gBattleMons[battler].status1 & STATUS1_SLEEP)
        StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
    if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
        StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
    if (gBattleMons[battler].status1 & STATUS1_BURN)
        StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
    if (gBattleMons[battler].status1 & (STATUS1_FREEZE | STATUS1_FROSTBITE))
        StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);
    if (gBattleMons[battler].status1 & STATUS1_BLEED)
        StringCopy(gBattleTextBuff1, gStatusConditionString_BleedJpn);

    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ability;
    gBattleMons[battler].status1 = 0;
    gBattleMons[battler].status2 &= ~(STATUS2_NIGHTMARE);
    gBattleScripting.battler = gActiveBattler = battler;
    BattleScriptPushCursorAndCallback(BattleScript_ShedSkinActivates);
    BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battler].status1);
    MarkBattlerForControllerExec(gActiveBattler);
    (*effect)++;
}

static bool8 CanMoveHaveExtraFlinchChance(u16 move)
{
    switch (gBattleMoves[move].effect)
    {
        case EFFECT_FLINCH_HIT:
        case EFFECT_FAKE_OUT:
        case EFFECT_FLINCH_STATUS:
        case EFFECT_FLINCH_RECOIL_25:
        case EFFECT_FLINCH_RECOIL_50:
        case EFFECT_FLINCH_MINIMIZE_HIT:
        case EFFECT_FLING:
        case EFFECT_SECRET_POWER:
        case EFFECT_SNORE:
        case EFFECT_TWISTER:
            return gBattleMoves[move].secondaryEffectChance > 0;
            
        case EFFECT_TRIPLE_ARROWS:
            return FALSE;

        default:
            return TRUE;
    }
    return TRUE;
}

u8 DidMoveHit()
{
    return !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
        && TARGET_TURN_DAMAGED
		&& !gProtectStructs[gBattlerAttacker].confusionSelfDmg;
			 
}

u8 ShouldApplyOnHitAffect(u8 applyTo)
{
    return DidMoveHit() && IsBattlerAlive(applyTo);
}

bool8 UseIntimidateClone(u8 battler, u16 abilityToCheck)
{
    u8 numAbility, numStats, statToLower, i, target;
    bool8 canLowerStat = FALSE;
    for(numAbility = 0; i < NUM_INTIMIDATE_CLONES; i++){
        if(gIntimidateCloneData[numAbility].ability == abilityToCheck)
            break;
    }

    if (numAbility >= NUM_INTIMIDATE_CLONES) return FALSE;
    
    numStats = gIntimidateCloneData[numAbility].numStatsLowered;

    for(i = 0; i < numStats; i++){
        statToLower = gIntimidateCloneData[numAbility].statsLowered[i];
        target = BATTLE_OPPOSITE(battler);
        //Target 1
        if(!IsBattlerImmuneToLowerStatsFromIntimidateClone(target, statToLower, abilityToCheck)){
            canLowerStat = TRUE;
            break;
        }

        //Target 2
        if(IsDoubleBattle()){
            target = BATTLE_PARTNER(target);
            if(!IsBattlerImmuneToLowerStatsFromIntimidateClone(target, statToLower, abilityToCheck)){
                canLowerStat = TRUE;
                break;
            }
        }
    }

    if(canLowerStat){ //Ability effect can be triggered
        BattleScriptPushCursorAndCallback(BattleScript_IntimidateActivatedNew);
        return TRUE;
    }

    return FALSE;
}

u8 AbilityBattleEffects(u8 caseID, u8 battler, u16 ability, u8 special, u16 moveArg)
{
    u8 effect = 0;
    u32 speciesAtk, speciesDef;
    u32 pidAtk, pidDef;
    u32 moveType, move;
    u32 i, j;
    u16 trainerNum;
    bool8 abilityEffect = FALSE;
    u8 opponent;
    u16 effectTargetFlag;

    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
        return 0;

    if (gBattlerAttacker >= gBattlersCount)
        gBattlerAttacker = battler;

    speciesAtk = gBattleMons[gBattlerAttacker].species;
    pidAtk = gBattleMons[gBattlerAttacker].personality;

    speciesDef = gBattleMons[gBattlerTarget].species;
    pidDef = gBattleMons[gBattlerTarget].personality;

    if (special)
        gLastUsedAbility = special;
    else {
        gLastUsedAbility = GetBattlerAbility(battler);
        abilityEffect = TRUE;
    }

    if (moveArg)
        move = moveArg;
    else
        move = gCurrentMove;

    GET_MOVE_TYPE(move, moveType);

    switch (caseID)
    {
    case ABILITYEFFECT_SWITCH_IN_TERRAIN:
        if (VarGet(VAR_TERRAIN) & STATUS_FIELD_TERRAIN_ANY)
        {
            u16 terrainFlags = VarGet(VAR_TERRAIN) & STATUS_FIELD_TERRAIN_ANY;    // only works for status flag (1 << 15)
            gFieldStatuses = terrainFlags | STATUS_FIELD_TERRAIN_PERMANENT; // terrain is permanent
            switch (VarGet(VAR_TERRAIN) & STATUS_FIELD_TERRAIN_ANY)
            {
            case STATUS_FIELD_ELECTRIC_TERRAIN:
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAINBECOMESELECTRIC;
                break;
            case STATUS_FIELD_MISTY_TERRAIN:
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAINBECOMESMISTY;
                break;
            case STATUS_FIELD_GRASSY_TERRAIN:
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAINBECOMESGRASSY;
                break;
            case STATUS_FIELD_PSYCHIC_TERRAIN:
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAINBECOMESPSYCHIC;
                break;
            }

            BattleScriptPushCursorAndCallback(BattleScript_OverworldTerrain);
            effect++;
        }
        #if B_THUNDERSTORM_TERRAIN == TRUE
        else if (GetCurrentWeather() == WEATHER_RAIN_THUNDERSTORM && !(gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN))
        {
            // overworld weather started rain, so just do electric terrain anim
            gFieldStatuses = (STATUS_FIELD_ELECTRIC_TERRAIN | STATUS_FIELD_TERRAIN_PERMANENT);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAINBECOMESELECTRIC;
            BattleScriptPushCursorAndCallback(BattleScript_OverworldTerrain);
            effect++;
        }
        #endif
        break;
    case ABILITYEFFECT_SWITCH_IN_WEATHER:
        if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        {
            switch (GetCurrentWeather())
            {
            case WEATHER_RAIN:
            case WEATHER_RAIN_THUNDERSTORM:
            case WEATHER_DOWNPOUR:
                if (!(gBattleWeather & WEATHER_RAIN_ANY))
                {
                    gBattleWeather = (WEATHER_RAIN_TEMPORARY | WEATHER_RAIN_PERMANENT);
                    gBattleScripting.animArg1 = B_ANIM_RAIN_CONTINUES;
                    effect++;
                }
                break;
            case WEATHER_SANDSTORM:
                if (!(gBattleWeather & WEATHER_SANDSTORM_ANY))
                {
                    gBattleWeather = (WEATHER_SANDSTORM_PERMANENT | WEATHER_SANDSTORM_TEMPORARY);
                    gBattleScripting.animArg1 = B_ANIM_SANDSTORM_CONTINUES;
                    effect++;
                }
                break;
            case WEATHER_DROUGHT:
                if (!(gBattleWeather & WEATHER_SUN_ANY))
                {
                    gBattleWeather = (WEATHER_SUN_PERMANENT | WEATHER_SUN_TEMPORARY);
                    gBattleScripting.animArg1 = B_ANIM_SUN_CONTINUES;
                    effect++;
                }
                break;
            }
        }
        if (effect)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = GetCurrentWeather();
            BattleScriptPushCursorAndCallback(BattleScript_OverworldWeatherStarts);
        }
        break;
    case ABILITYEFFECT_ON_SWITCHIN: // 0
        gBattleScripting.battler = battler;

        if (CheckAndSetSwitchInAbility(battler, ABILITY_ANTICIPATION))
        {
            u32 side = GetBattlerSide(battler);

            for (i = 0; i < MAX_BATTLERS_COUNT; i++)
            {
                if (IsBattlerAlive(i) && side != GetBattlerSide(i))
                {
                    for (j = 0; j < MAX_MON_MOVES; j++)
                    {
                        move = gBattleMons[i].moves[j];
                        GET_MOVE_TYPE(move, moveType);
                        if (CalcTypeEffectivenessMultiplier(move, moveType, i, battler, FALSE) >= UQ_4_12(2.0))
                        {
                            effect++;
                            break;
                        }
                    }
                }
            }

            if (effect)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_ANTICIPATION;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
            }
        }

        if (CheckAndSetSwitchInAbility(battler, ABILITY_DARK_AURA))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_DARKAURA;
            BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
            effect++;
        }

        if (CheckAndSetSwitchInAbility(battler, ABILITY_FAIRY_AURA))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_FAIRYAURA;
            BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
            effect++;
        }
        
        if (CheckAndSetSwitchInAbility(battler, ABILITY_PIXIE_POWER))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_FAIRYAURA;
            BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
            effect++;
        }
        
        if (CheckAndSetSwitchInAbility(battler, ABILITY_AURA_BREAK))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_AURABREAK;
            BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
            effect++;
        }

        if (BATTLER_HAS_ABILITY(battler, ABILITY_IMPOSTER)
            && IsBattlerAlive(BATTLE_OPPOSITE(battler))
            && !(gBattleMons[BATTLE_OPPOSITE(battler)].status2 & (STATUS2_TRANSFORMED | STATUS2_SUBSTITUTE))
            && !(gBattleMons[battler].status2 & STATUS2_TRANSFORMED)
            && !(gBattleStruct->illusion[BATTLE_OPPOSITE(battler)].on)
            && !(gStatuses3[BATTLE_OPPOSITE(battler)] & STATUS3_SEMI_INVULNERABLE))
        {
            gBattlerTarget = BATTLE_OPPOSITE(battler);
            BattleScriptPushCursorAndCallback(BattleScript_ImposterActivates);
            effect++;
        }
        
        if (CheckAndSetSwitchInAbility(battler, ABILITY_COMATOSE))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_COMATOSE;
            BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
            effect++;
        }
        
        if (GetBattlerAbility(battler) == ABILITY_TRACE && !(gSpecialStatuses[battler].traced))
        {
            gBattleResources->flags->flags[battler] |= RESOURCE_FLAG_TRACED;
            gSpecialStatuses[battler].traced = TRUE;
        }

		if (BATTLER_HAS_ABILITY(battler, ABILITY_ZEN_MODE) && ShouldChangeFormHpBased(battler))
        {
            BattleScriptPushCursorAndCallback(BattleScript_AttackerFormChangeEnd3);
            effect++;
        }

        if ((BATTLER_HAS_ABILITY(battler, ABILITY_SCHOOLING) && gBattleMons[battler].level >= 20)
            || BATTLER_HAS_ABILITY(battler, ABILITY_SHIELDS_DOWN)
            || BATTLER_HAS_ABILITY(battler, ABILITY_FORECAST)
            || BATTLER_HAS_ABILITY(battler, ABILITY_FLOWER_GIFT))
        {
            if (ShouldChangeFormHpBased(battler))
            {
                BattleScriptPushCursorAndCallback(BattleScript_AttackerFormChangeEnd3);
                effect++;
            }
        }

        if (BATTLER_HAS_ABILITY(battler, ABILITY_MIMICRY))
        {
            if (gBattleMons[battler].hp != 0 && gFieldStatuses & STATUS_FIELD_TERRAIN_ANY)
            {
                TryToApplyMimicry(battler, FALSE);
                effect++;
            }
        }
        
        if (CheckAndSetSwitchInAbility(battler, ABILITY_AS_ONE_ICE_RIDER) || CheckAndSetSwitchInAbility(battler, ABILITY_AS_ONE_SHADOW_RIDER))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_ASONE;
            BattleScriptPushCursorAndCallback(BattleScript_ActivateAsOne);
            effect++;
        }

        if (CheckAndSetSwitchInAbility(battler, ABILITY_CROWNED_KING))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_CROWNEDKING;
            BattleScriptPushCursorAndCallback(BattleScript_ActivateAsOne);
            effect++;
        }
        
        if (CheckAndSetSwitchInAbility(battler, ABILITY_CURIOUS_MEDICINE) && IsDoubleBattle()
            && IsBattlerAlive(BATTLE_PARTNER(battler)) && TryResetBattlerStatChanges(BATTLE_PARTNER(battler)))
        {
            u32 i;
            gEffectBattler = BATTLE_PARTNER(battler);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_CURIOUS_MEDICINE;
            BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
            effect++;
        }
		
        if (CheckAndSetSwitchInAbility(battler, ABILITY_FRISK))
        {
            BattleScriptPushCursorAndCallback(BattleScript_FriskActivates); // Try activate
            effect++;
        }

        // Weather Abilities --------------------------------------------------------------------------------------------------
        // Drizzle and Seaborne
        if(CheckAndSetSwitchInAbility(battler, ABILITY_DRIZZLE) || CheckAndSetSwitchInAbility(battler, ABILITY_SEABORNE)){
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_RAIN, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_DrizzleActivates);
                effect++;
            }
            else if (gBattleWeather & B_WEATHER_PRIMAL_ANY && WEATHER_HAS_EFFECT)
            {
                BattleScriptPushCursorAndCallback(BattleScript_BlockedByPrimalWeatherEnd3);
                effect++;
            }
        }
        
        // Sand Stream
        if(CheckAndSetSwitchInAbility(battler, ABILITY_SAND_STREAM)){
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_SANDSTORM, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_SandstreamActivates);
                effect++;
            }
            else if (gBattleWeather & B_WEATHER_PRIMAL_ANY && WEATHER_HAS_EFFECT)
            {
                BattleScriptPushCursorAndCallback(BattleScript_BlockedByPrimalWeatherEnd3);
                effect++;
            }
        }

        // Drought
        if(CheckAndSetSwitchInAbility(battler, ABILITY_DROUGHT) || CheckAndSetSwitchInAbility(battler, ABILITY_ORICHALCUM_PULSE)){
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_SUN, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_DroughtActivates);
                effect++;
            }
            else if (gBattleWeather & B_WEATHER_PRIMAL_ANY && WEATHER_HAS_EFFECT)
            {
                BattleScriptPushCursorAndCallback(BattleScript_BlockedByPrimalWeatherEnd3);
                effect++;
            }
        }

        // Snow Warning
        if(CheckAndSetSwitchInAbility(battler, ABILITY_SNOW_WARNING)){
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_HAIL, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_SnowWarningActivates);
                effect++;
            }
            else if (gBattleWeather & B_WEATHER_PRIMAL_ANY && WEATHER_HAS_EFFECT)
            {
                BattleScriptPushCursorAndCallback(BattleScript_BlockedByPrimalWeatherEnd3);
                effect++;
            }
        }

        // Desolate Land
        if(CheckAndSetSwitchInAbility(battler, ABILITY_DESOLATE_LAND)){
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_SUN_PRIMAL, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_DesolateLandActivates);
                effect++;
            }
        }
        
        // Primordial Sea
        if(CheckAndSetSwitchInAbility(battler, ABILITY_PRIMORDIAL_SEA)){
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_RAIN_PRIMAL, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_PrimordialSeaActivates);
                effect++;
            }
        }
        
        // Delta Stream
        if(CheckAndSetSwitchInAbility(battler, ABILITY_DELTA_STREAM)){
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_STRONG_WINDS, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_DeltaStreamActivates);
                effect++;
            }
        }
        // Terrain Abilities --------------------------------------------------------------------------------------------------
        // Electric Surge
        if(CheckAndSetSwitchInAbility(battler, ABILITY_ELECTRIC_SURGE) || CheckAndSetSwitchInAbility(battler, ABILITY_HADRON_ENGINE)){
            if(TryChangeBattleTerrain(battler, STATUS_FIELD_ELECTRIC_TERRAIN, &gFieldTimers.terrainTimer)){
                BattleScriptPushCursorAndCallback(BattleScript_ElectricSurgeActivates);
                effect++;
            }
        }

        // Grassy Surge
        if(CheckAndSetSwitchInAbility(battler, ABILITY_GRASSY_SURGE)){
            if(TryChangeBattleTerrain(battler, STATUS_FIELD_GRASSY_TERRAIN, &gFieldTimers.terrainTimer)){
                BattleScriptPushCursorAndCallback(BattleScript_GrassySurgeActivates);
                effect++;
            }
        }
            
        // Misty Surge
        if(CheckAndSetSwitchInAbility(battler, ABILITY_MISTY_SURGE)){
            if(TryChangeBattleTerrain(battler, STATUS_FIELD_MISTY_TERRAIN, &gFieldTimers.terrainTimer)){
                BattleScriptPushCursorAndCallback(BattleScript_MistySurgeActivates);
                effect++;
            }
        }

        // Psychic Surge
        if(CheckAndSetSwitchInAbility(battler, ABILITY_PSYCHIC_SURGE)){
            if(TryChangeBattleTerrain(battler, STATUS_FIELD_PSYCHIC_TERRAIN, &gFieldTimers.terrainTimer)){
                BattleScriptPushCursorAndCallback(BattleScript_PsychicSurgeActivates);
                effect++;
            }
        }

        // Innates on Switch
        // Screen Cleaner
        if(CheckAndSetSwitchInAbility(battler, ABILITY_SCREEN_CLEANER)){
            if (TryRemoveScreens(battler))
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_SCREENCLEANER;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
        }
        
        if(CheckAndSetSwitchInAbility(battler, ABILITY_UNNERVE)){
            BattleScriptPushCursorAndCallback(BattleScript_ActivateUnnerve);
            effect++;
        }
        
        // Download
        if(CheckAndSetSwitchInAbility(battler, ABILITY_DOWNLOAD)){
            u32 statId, opposingBattler;
            u32 opposingDef = 0, opposingSpDef = 0;

            opposingBattler = BATTLE_OPPOSITE(battler);
            for (i = 0; i < 2; opposingBattler ^= BIT_FLANK, i++)
            {
                if (IsBattlerAlive(opposingBattler))
                {
                    opposingDef += gBattleMons[opposingBattler].defense
                                * gStatStageRatios[gBattleMons[opposingBattler].statStages[STAT_DEF]][0]
                                / gStatStageRatios[gBattleMons[opposingBattler].statStages[STAT_DEF]][1];
                    opposingSpDef += gBattleMons[opposingBattler].spDefense
                                * gStatStageRatios[gBattleMons[opposingBattler].statStages[STAT_SPDEF]][0]
                                / gStatStageRatios[gBattleMons[opposingBattler].statStages[STAT_SPDEF]][1];
                }
            }

            if (opposingDef < opposingSpDef)
                statId = STAT_ATK;
            else
                statId = STAT_SPATK;

            if (CompareStat(battler, statId, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                s8 result = ChangeStatBuffs(battler, StatBuffValue(1), statId, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
                if (result)
                {
                    SetStatChanger(statId, 1);
                    PREPARE_STAT_BUFFER(gBattleTextBuff1, statId);
                    BattleScriptPushCursorAndCallback(BattleScript_AttackerAbilityStatRaiseEnd3);
                    effect++;
                }
            }
        }
        
        // Lets Roll
        if(CheckAndSetSwitchInAbility(battler, ABILITY_LETS_ROLL)){
            SET_STATCHANGER(STAT_DEF, 1, FALSE);
            gBattleMons[battler].status2 = STATUS2_DEFENSE_CURL;
            BattleScriptPushCursorAndCallback(BattleScript_BattlerInnateStatRaiseOnSwitchIn);
            effect++;
        }
        
        // Slow Start
        if(CheckAndSetSwitchInAbility(battler, ABILITY_SLOW_START)){
            gDisableStructs[battler].slowStartTimer = 5;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_SLOWSTART;
            BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
            effect++;
        }

        // Lethargy
        if(CheckAndSetSwitchInAbility(battler, ABILITY_LETHARGY)){
            TryResetBattlerStatChanges(battler);
            gDisableStructs[battler].slowStartTimer = 5;
            BattleScriptPushCursorAndCallback(BattleScript_LethargyEnters);
            effect++;
        }
        
        // Majestic Moth
        if(CheckAndSetSwitchInAbility(battler, ABILITY_MAJESTIC_MOTH)){
            u8 statId = GetHighestStatId(battler, TRUE);

            if (CompareStat(battler, statId, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                s8 result = ChangeStatBuffs(battler, StatBuffValue(1), statId, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
                if (result)
                {
                    SetStatChanger(statId, 1);
                    gBattlerAttacker = battler;
                    PREPARE_STAT_BUFFER(gBattleTextBuff1, statId);
                    BattleScriptPushCursorAndCallback(BattleScript_AttackerAbilityStatRaiseEnd3);
                    effect++;
                }
            }
        }
        
        // Sea Guardian
        if(CheckAndSetSwitchInAbility(battler, ABILITY_SEA_GUARDIAN)){
            if (IsBattlerWeatherAffected(battler, WEATHER_RAIN_ANY))
            {
                u8 statId = GetHighestStatId(battler, TRUE);

                if (CompareStat(battler, statId, MAX_STAT_STAGE, CMP_LESS_THAN))
                {
                    s8 result = ChangeStatBuffs(battler, StatBuffValue(1), statId, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
                    if (result)
                    {
                        SetStatChanger(statId, 1);
                        gBattlerAttacker = battler;
                        PREPARE_STAT_BUFFER(gBattleTextBuff1, statId);
                        BattleScriptPushCursorAndCallback(BattleScript_AttackerAbilityStatRaiseEnd3);
                        effect++;
                    }
                }
            }
        }

        // Sun Worship
        if(CheckAndSetSwitchInAbility(battler, ABILITY_SUN_WORSHIP)){
            if (IsBattlerWeatherAffected(battler, WEATHER_SUN_ANY))
            {
                u8 statId = GetHighestStatId(battler, TRUE);

                if (CompareStat(battler, statId, MAX_STAT_STAGE, CMP_LESS_THAN))
                {
                    s8 result = ChangeStatBuffs(battler, StatBuffValue(1), statId, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
                    if (result)
                    {
                        SetStatChanger(statId, 1);
                        gBattlerAttacker = battler;
                        PREPARE_STAT_BUFFER(gBattleTextBuff1, statId);
                        BattleScriptPushCursorAndCallback(BattleScript_AttackerAbilityStatRaiseEnd3);
                        effect++;
                    }
                }
            }
        }

        //Toxic Spill
        if (CheckAndSetSwitchInAbility(battler, ABILITY_TOXIC_SPILL))
        {
            BattleScriptPushCursorAndCallback(BattleScript_BattlerAnnouncedToxicSpill);
            effect++;
        }

        //Cheating Death
        if(CheckAndSetSwitchInAbility(battler, ABILITY_CHEATING_DEATH))
        {
            u8 uses = 2 - GetSingleUseAbilityCounter(battler, ABILITY_CHEATING_DEATH);
            if(uses > 0) {
                if(uses == 1)
                    BattleScriptPushCursorAndCallback(BattleScript_BattlerHasASingleNoDamageHit);
                else{
                    ConvertIntToDecimalStringN(gBattleTextBuff4, uses, STR_CONV_MODE_LEFT_ALIGN, 2);
                    BattleScriptPushCursorAndCallback(BattleScript_BattlerHasNoDamageHits);
                }
                effect++;
            }
        }

        // Gallantry
        if(CheckAndSetSwitchInAbility(battler, ABILITY_GALLANTRY))
        {
            s8 uses = 1 - GetSingleUseAbilityCounter(battler, ABILITY_GALLANTRY);
            if(uses > 0) {
                BattleScriptPushCursorAndCallback(BattleScript_BattlerHasASingleNoDamageHit);
                effect++;
            }
        }

        // Coward
        if(BATTLER_HAS_ABILITY(battler, ABILITY_COWARD)){
            bool8 activateAbilty = FALSE;
            u16 abilityToCheck = ABILITY_COWARD; //For easier copypaste

            if (CheckAndSetSwitchInAbility(battler, abilityToCheck)) {
                if (!GetSingleUseAbilityCounter(battler, abilityToCheck)) {
                    SetSingleUseAbilityCounter(battler, abilityToCheck, TRUE);
                    activateAbilty = TRUE;
                }
            }

            //This is the stuff that has to be changed for each ability
            if(activateAbilty){
                gDisableStructs[battler].protectedThisTurn = TRUE;
                BattleScriptPushCursorAndCallback(BattleScript_BattlerIsProtectedForThisTurn);
                effect++;
            }
        }

        // Atlas
        if(CheckAndSetSwitchInAbility(battler, ABILITY_ATLAS)){
            if(!(gFieldStatuses & STATUS_FIELD_GRAVITY)){
                gFieldTimers.gravityTimer = GRAVITY_DURATION_EXTENDED;
                gFieldStatuses |= STATUS_FIELD_GRAVITY;
                BattleScriptPushCursorAndCallback(BattleScript_AtlasStarts);
                effect++;
            }
        }

        // Gravity Well
        if(CheckAndSetSwitchInAbility(battler, ABILITY_GRAVITY_WELL)) {
            if(!(gFieldStatuses & STATUS_FIELD_GRAVITY)){
                gFieldTimers.gravityTimer = GRAVITY_DURATION;
                gFieldStatuses |= STATUS_FIELD_GRAVITY;
                BattleScriptPushCursorAndCallback(BattleScript_GravityStarts);
                effect++;
            }
        }

        // Pickup
        if(CheckAndSetSwitchInAbility(battler, ABILITY_PICKUP)){
            if((gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_HAZARDS_ANY)){
                gSideStatuses[GetBattlerSide(gActiveBattler)] &= ~(SIDE_STATUS_STEALTH_ROCK | SIDE_STATUS_TOXIC_SPIKES | SIDE_STATUS_SPIKES | SIDE_STATUS_STICKY_WEB);
                BattleScriptPushCursorAndCallback(BattleScript_PickUpActivate);
                effect++;
            }
        }

        // Forewarn
        if(CheckAndSetSwitchInAbility(battler, ABILITY_FOREWARN)){
            bool8 hasTarget      = FALSE;
            u8 opposingBattler = BATTLE_OPPOSITE(battler);

            //Checks Target
            for (i = 0; i < 2; opposingBattler ^= BIT_FLANK, i++)
            {
                if (IsBattlerAlive(opposingBattler) && gWishFutureKnock.futureSightCounter[opposingBattler] == 0)
                {
                    gBattlerTarget = opposingBattler;
                    hasTarget = TRUE;
                    break;
                }
            }

            //This is the stuff that has to be changed for each ability
            if(hasTarget){
                u16 extraMove = MOVE_FUTURE_SIGHT; //The Extra Move to be used
                u8 movePower = 50; //The Move power, leave at 0 if you want it to be the same as the normal move
                u8 turns = 3; //The amount of turns the move will last

                gBattlerAttacker = battler;

                gSideStatuses[GET_BATTLER_SIDE(gBattlerTarget)] |= SIDE_STATUS_FUTUREATTACK;
                gWishFutureKnock.futureSightMove[gBattlerTarget] = extraMove;
                gWishFutureKnock.futureSightPower[gBattlerTarget] = movePower;
                gWishFutureKnock.futureSightAttacker[gBattlerTarget] = gBattlerAttacker;
                gWishFutureKnock.futureSightCounter[gBattlerTarget] = turns;

                BattleScriptPushCursorAndCallback(BattleScript_ForewarnReworkActivates);
                effect++;
            }
        }

        // Low Blow
        UseEntryMove(battler, ABILITY_LOW_BLOW, &effect, MOVE_FEINT_ATTACK, 0, 0, 0);

        // Cheap Tactics
        UseEntryMove(battler, ABILITY_CHEAP_TACTICS, &effect, MOVE_SCRATCH, 0, 0, 0);
        
        // Dust Cloud
        UseEntryMove(battler, ABILITY_DUST_CLOUD, &effect, MOVE_SAND_ATTACK, 0, 0, 0);

        // Trickster
        UseEntryMove(battler, ABILITY_TRICKSTER, &effect, MOVE_DISABLE, 0, 0, 0);

        // Suppress
        UseEntryMove(battler, ABILITY_SUPPRESS, &effect, MOVE_TORMENT, 0, 0, 0);

        // Doombringer
        UseEntryMove(battler, ABILITY_DOOMBRINGER, &effect, MOVE_DOOM_DESIRE, 0, 0, 0);

        // Change of Heart
        UseEntryMove(battler, ABILITY_CHANGE_OF_HEART, &effect, MOVE_HEART_SWAP, 0, 0, 0);

        // Telekinetic
        UseEntryMove(battler, ABILITY_TELEKINETIC, &effect, MOVE_TELEKINESIS, 0, 0, 0);

        // Powder Burst
        UseEntryMove(battler, ABILITY_POWDER_BURST, &effect, MOVE_POWDER, 0, 0, 0);

        // Monster Mash
        UseEntryMove(battler, ABILITY_MONSTER_MASH, &effect, MOVE_TRICK_OR_TREAT, 0, 0, 0);

        // Phantom Thief
        UseEntryMove(battler, ABILITY_PHANTOM_THIEF, &effect, MOVE_SPECTRAL_THIEF, 40, 0, 0);

        // Web Spinner
        UseEntryMove(battler, ABILITY_WEB_SPINNER, &effect, MOVE_STRING_SHOT, 0, 0, 0);

        // Wishmaker
        if (BATTLER_HAS_ABILITY(battler, ABILITY_WISHMAKER)) {
            u8 counter = GetSingleUseAbilityCounter(battler, ABILITY_WISHMAKER) + 1;
            if (counter <= 3) {
                if (UseEntryMove(battler, ABILITY_WISHMAKER, &effect, MOVE_WISH, 0, 0, 0))
                    SetSingleUseAbilityCounter(battler, ABILITY_WISHMAKER, counter);
            }
        }

        // Generator
        if(CheckAndSetSwitchInAbility(battler, ABILITY_GENERATOR)){
            BattleScriptPushCursorAndCallback(BattleScript_GeneratorActivates);
            effect++;
        }

        if(CheckAndSetSwitchInAbility(battler, ABILITY_SOOTHING_AROMA)){
            bool8 anyStatus = FALSE;
            struct Pokemon *party;

            if (GetBattlerSide(battler) == B_SIDE_PLAYER)
                party = gPlayerParty;
            else
                party = gEnemyParty;
                
            for (i = 0; i < PARTY_SIZE; i++) {
                u32 status1 = GetMonData(&party[i], MON_DATA_STATUS);
                if (status1 & STATUS1_ANY) {
                    anyStatus = TRUE;
                    break;
                }
            }

            if (anyStatus) {
                BattleScriptPushCursorAndCallback(BattleScript_EffectSoothingAroma);
                effect++;
            }
        }

        // Intimidate
        if(CheckAndSetSwitchInAbility(battler, ABILITY_INTIMIDATE)){
            effect += UseIntimidateClone(battler, ABILITY_INTIMIDATE);
        }
        
        // Scare
        if(CheckAndSetSwitchInAbility(battler, ABILITY_SCARE)){
            effect += UseIntimidateClone(battler, ABILITY_SCARE);
        }
        
        // Fearmonger
        if(CheckAndSetSwitchInAbility(battler, ABILITY_FEARMONGER) || CheckAndSetSwitchInAbility(battler, ABILITY_YUKI_ONNA)){
            effect += UseIntimidateClone(battler, ABILITY_FEARMONGER);
        }
        
        // Monkey Business
        if(CheckAndSetSwitchInAbility(battler, ABILITY_MONKEY_BUSINESS)){
            effect += UseIntimidateClone(battler, ABILITY_MONKEY_BUSINESS);
        }
        
        // Monkey Business
        if(CheckAndSetSwitchInAbility(battler, ABILITY_MALICIOUS)){
            effect += UseIntimidateClone(battler, ABILITY_MALICIOUS);
        }
        
        // Water Veil
        if(CheckAndSetSwitchInAbility(battler, ABILITY_WATER_VEIL)){
            if (!(gStatuses3[battler] & STATUS3_AQUA_RING))
            {
                gStatuses3[battler] |= STATUS3_AQUA_RING;
                BattleScriptPushCursorAndCallback(BattleScript_BattlerEnvelopedItselfInAVeil);
                effect++;
            }
        }
        
        // Aquatic
        if(CheckAndSetOncePerTurnAbility(battler, ABILITY_AQUATIC)){
            if (!IS_BATTLER_OF_TYPE(battler, TYPE_WATER))
            {
                gBattleMons[battler].type3 = TYPE_WATER;
                PREPARE_TYPE_BUFFER(gBattleTextBuff2, gBattleMons[battler].type3);
                BattleScriptPushCursorAndCallback(BattleScript_BattlerAddedTheType);
                effect++;
            }
        }
        
        // Grounded
        if(CheckAndSetSwitchInAbility(battler, ABILITY_GROUNDED)){
            if (!IS_BATTLER_OF_TYPE(battler, TYPE_GROUND))
            {
                gBattleMons[battler].type3 = TYPE_GROUND;
                PREPARE_TYPE_BUFFER(gBattleTextBuff2, gBattleMons[battler].type3);
                BattleScriptPushCursorAndCallback(BattleScript_BattlerAddedTheType);
                effect++;
            }
        }

        // Fairy Tale
        if(CheckAndSetSwitchInAbility(battler, ABILITY_FAIRY_TALE)){
            if (!IS_BATTLER_OF_TYPE(battler, TYPE_FAIRY))
            {
                gBattleMons[battler].type3 = TYPE_FAIRY;
                PREPARE_TYPE_BUFFER(gBattleTextBuff2, gBattleMons[battler].type3);
                BattleScriptPushCursorAndCallback(BattleScript_BattlerAddedTheType);
                effect++;
            }
        }
        
        // Ice Age
        if(CheckAndSetSwitchInAbility(battler, ABILITY_ICE_AGE)){
            if (!IS_BATTLER_OF_TYPE(battler, TYPE_ICE))
            {
                gBattleMons[battler].type3 = TYPE_ICE;
                PREPARE_TYPE_BUFFER(gBattleTextBuff2, gBattleMons[battler].type3);
                BattleScriptPushCursorAndCallback(BattleScript_BattlerAddedTheType);
                effect++;
            }
        }
        
        // Half Drake
        if(CheckAndSetSwitchInAbility(battler, ABILITY_HALF_DRAKE)){
            if (!IS_BATTLER_OF_TYPE(battler, TYPE_DRAGON))
            {
                gBattleMons[battler].type3 = TYPE_DRAGON;
                PREPARE_TYPE_BUFFER(gBattleTextBuff2, gBattleMons[battler].type3);
                BattleScriptPushCursorAndCallback(BattleScript_BattlerAddedTheType);
                effect++;
            }
        }
        
        // Metallic
        if(CheckAndSetSwitchInAbility(battler, ABILITY_METALLIC)){
            if (!IS_BATTLER_OF_TYPE(battler, TYPE_STEEL))
            {
                gBattleMons[battler].type3 = TYPE_STEEL;
                PREPARE_TYPE_BUFFER(gBattleTextBuff2, gBattleMons[battler].type3);
                BattleScriptPushCursorAndCallback(BattleScript_BattlerAddedTheType);
                effect++;
            }
        }
        
        // Dragonfly
        if(CheckAndSetSwitchInAbility(battler, ABILITY_DRAGONFLY)){
            if (!IS_BATTLER_OF_TYPE(battler, TYPE_DRAGON))
            {
                gBattleMons[battler].type3 = TYPE_DRAGON;
                PREPARE_TYPE_BUFFER(gBattleTextBuff2, gBattleMons[battler].type3);
                BattleScriptPushCursorAndCallback(BattleScript_BattlerAddedTheType);
                effect++;
            }
        }
        
        // Teravolt
        if(CheckAndSetSwitchInAbility(battler, ABILITY_TERAVOLT)){
            if (!IS_BATTLER_OF_TYPE(battler, TYPE_ELECTRIC))
            {
                gBattleMons[battler].type3 = TYPE_ELECTRIC;
                PREPARE_TYPE_BUFFER(gBattleTextBuff2, gBattleMons[battler].type3);
                BattleScriptPushCursorAndCallback(BattleScript_BattlerAddedTheType);
                effect++;
            }
        }
        
        // Turboblaze
        if(CheckAndSetSwitchInAbility(battler, ABILITY_TURBOBLAZE)){
            if (!IS_BATTLER_OF_TYPE(battler, TYPE_FIRE)) 
            {
                gBattleMons[battler].type3 = TYPE_FIRE;
                PREPARE_TYPE_BUFFER(gBattleTextBuff2, gBattleMons[battler].type3);
                BattleScriptPushCursorAndCallback(BattleScript_BattlerAddedTheType);
                effect++;
            }
        }
        
        // Coiled Up
        if(CheckAndSetSwitchInAbility(battler, ABILITY_COIL_UP)){
            if (!(gStatuses4[battler] & STATUS4_COILED))
            {
                gStatuses4[battler] |= STATUS4_COILED;
                BattleScriptPushCursorAndCallback(BattleScript_BattlerCoiledUp); // Try activate
                effect++;
            }
        }
        
        // Air Blower
        if(CheckAndSetSwitchInAbility(battler, ABILITY_AIR_BLOWER) &&
        !(gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_TAILWIND)){
            gSideStatuses[GetBattlerSide(battler)] |= SIDE_STATUS_TAILWIND;
            gSideTimers[GetBattlerSide(battler)].tailwindBattlerId = gBattlerAttacker;
            gSideTimers[GetBattlerSide(battler)].tailwindTimer = 3;
            BattleScriptPushCursorAndCallback(BattleScript_AirBlowerActivated);
            effect++;
        }

        // Pastel Veil Rework
        if(CheckAndSetSwitchInAbility(battler, ABILITY_PASTEL_VEIL) &&
        !(gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SAFEGUARD)){
            gSideStatuses[GetBattlerSide(battler)] |= SIDE_STATUS_SAFEGUARD;
            gSideTimers[GetBattlerSide(battler)].safeguardBattlerId = gBattlerAttacker;
            gSideTimers[GetBattlerSide(battler)].safeguardTimer = 5;
            BattleScriptPushCursorAndCallback(BattleScript_PastelVeilActivated);
            effect++;
        }

        // Phantom
        if(CheckAndSetSwitchInAbility(battler, ABILITY_PHANTOM)){
            gBattleMons[battler].type3 = TYPE_GHOST;
            PREPARE_TYPE_BUFFER(gBattleTextBuff2, gBattleMons[battler].type3);
            BattleScriptPushCursorAndCallback(BattleScript_BattlerAddedTheType);
            effect++;
        }
        
        // North Wind
        if(CheckAndSetSwitchInAbility(battler, ABILITY_NORTH_WIND)){
            if (!(gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_AURORA_VEIL))
            {
                gSideStatuses[GetBattlerSide(battler)] |= SIDE_STATUS_AURORA_VEIL;
                if (GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_LIGHT_CLAY)
                    gSideTimers[GET_BATTLER_SIDE(battler)].auroraVeilTimer = 5;
                else
                    gSideTimers[GET_BATTLER_SIDE(battler)].auroraVeilTimer = 3;
                BattleScriptPushCursorAndCallback(BattleScript_NorthWindActivated);
                effect++;
            }
        }

        // Spider Lair 
        if(CheckAndSetOncePerTurnAbility(battler, ABILITY_SPIDER_LAIR)){
            if (!(gSideStatuses[BATTLE_OPPOSITE(battler)] & SIDE_STATUS_STICKY_WEB))
            {
                gSideStatuses[BATTLE_OPPOSITE(battler)] |= SIDE_STATUS_STICKY_WEB;
                gSideTimers[BATTLE_OPPOSITE(battler)].spiderWebTimer = 6; // 5 - 1 for the ability
                BattleScriptPushCursorAndCallback(BattleScript_SpiderLairActivated);
                effect++;
            }
        }
        
        // Intrepid Sword
        if(CheckAndSetSwitchInAbility(battler, ABILITY_INTREPID_SWORD)){
            SET_STATCHANGER(STAT_ATK, 1, FALSE);
            BattleScriptPushCursorAndCallback(BattleScript_BattlerAbilityStatRaiseOnSwitchIn);
            effect++;
        }

        if (CheckAndSetSwitchInAbility(battler, ABILITY_CROWNED_SWORD))
        {
            SET_STATCHANGER(STAT_ATK, 1, FALSE);
            BattleScriptPushCursorAndCallback(BattleScript_BattlerAbilityStatRaiseOnSwitchIn);
            effect++;
        }

        if (CheckAndSetSwitchInAbility(battler, ABILITY_CROWNED_SHIELD))
        {
            SET_STATCHANGER(STAT_DEF, 1, FALSE);
            BattleScriptPushCursorAndCallback(BattleScript_BattlerAbilityStatRaiseOnSwitchIn);
            effect++;
        }
        
        // Dauntless Shield
        if(CheckAndSetSwitchInAbility(battler, ABILITY_DAUNTLESS_SHIELD)){
            SET_STATCHANGER(STAT_DEF, 1, FALSE);
            BattleScriptPushCursorAndCallback(BattleScript_BattlerAbilityStatRaiseOnSwitchIn);
            effect++;
        }
        
        // Pressure
        if(CheckAndSetSwitchInAbility(battler, ABILITY_PRESSURE)){
            u8 i;
            u8 loweredStats;
            for (i = 0; i < gBattlersCount; i++)
            {
                if (i == battler) continue;
                if (!IsBattlerAlive(i)) continue;
                loweredStats |= TryResetBattlerStatBuffs(i);
            }

            if (loweredStats)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_PRESSURE;
                BattleScriptPushCursorAndCallback(BattleScript_PressureRemoveStats);
            }
            else
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_PRESSURE;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
            }
            effect++;
        }

        //Clueless
        if(CheckAndSetSwitchInAbility(battler, ABILITY_CLUELESS)){
            BattleScriptPushCursorAndCallback(BattleScript_AnnounceAirLockCloudNine);
            effect++;
        }
        
        //Air Lock
        if(CheckAndSetSwitchInAbility(battler, ABILITY_AIR_LOCK)){
            BattleScriptPushCursorAndCallback(BattleScript_AnnounceAirLockCloudNine);
            effect++;
        }

        //Cloud Nine
        if(CheckAndSetSwitchInAbility(battler, ABILITY_CLOUD_NINE)){
            BattleScriptPushCursorAndCallback(BattleScript_AnnounceAirLockCloudNine);
            effect++;
        }
        
        // Wind Rider
        if (CheckAndSetSwitchInAbility(battler, ABILITY_WIND_RIDER)) {
            if (gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_TAILWIND) {
                SET_STATCHANGER(GetHighestAttackingStatId(battler, TRUE), 1, FALSE);

                BattleScriptPushCursorAndCallback(BattleScript_BattlerAbilityStatRaiseOnSwitchIn);
                effect++;
            }
        }
        
        // Purifying Waters
        if(CheckAndSetSwitchInAbility(battler, ABILITY_PURIFYING_WATERS)){
            gStatuses3[battler] |= STATUS3_AQUA_RING;
            BattleScriptPushCursorAndCallback(BattleScript_BattlerEnvelopedItselfInAVeil);
            effect++;
        }

        if (CheckAndSetSwitchInAbility(battler, ABILITY_TWISTED_DIMENSION)) {
            if(!(gFieldStatuses & STATUS_FIELD_TRICK_ROOM)){
                //Enable Trick Room
                gFieldStatuses |= STATUS_FIELD_TRICK_ROOM;
                gFieldTimers.trickRoomTimer = TRICK_ROOM_DURATION_SHORT;
                BattleScriptPushCursorAndCallback(BattleScript_TwistedDimensionActivated);
                effect++;
            }
            else{
                //Removes Trick Room
                gFieldTimers.trickRoomTimer = 0;
                gFieldStatuses &= ~(STATUS_FIELD_TRICK_ROOM);
                BattleScriptPushCursorAndCallback(BattleScript_TwistedDimensionRemoved);
                effect++;
            }
        }

        //Inverse Room
        if(CheckAndSetSwitchInAbility(battler, ABILITY_INVERSE_ROOM)){
            if(!(gFieldStatuses & STATUS_FIELD_INVERSE_ROOM)){
                //Enable Trick Room
                gFieldStatuses |= STATUS_FIELD_INVERSE_ROOM;
                gFieldTimers.inverseRoomTimer = INVERSE_ROOM_DURATION_SHORT;
                BattleScriptPushCursorAndCallback(BattleScript_InversedRoomActivated);
                effect++;
            }
            else{
                //Removes Trick Room
                gFieldTimers.inverseRoomTimer = 0;
                gFieldStatuses &= ~(STATUS_FIELD_INVERSE_ROOM);
                BattleScriptPushCursorAndCallback(BattleScript_InverseRoomRemoved);
                effect++;
            }
        }

        //Permanence
        if (CheckAndSetSwitchInAbility(battler, ABILITY_PERMANENCE)) {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_PERMANENCE;
            BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
            effect++;
        }

        //Permanence
        if (CheckAndSetSwitchInAbility(battler, ABILITY_BLOCK_ON_ENTRY)) {
            u8 anyBlocked = FALSE;
            u8 opponent = BATTLE_OPPOSITE(battler);

            if (IsBattlerAlive(opponent) && !(gBattleMons[opponent].status2 & STATUS2_ESCAPE_PREVENTION)) {
                gBattleMons[opponent].status2 |= STATUS2_ESCAPE_PREVENTION;
                gDisableStructs[opponent].battlerPreventingEscape = battler;
                anyBlocked = TRUE;
            }

            opponent = BATTLE_PARTNER(opponent);
            if (IsBattlerAlive(opponent) && !(gBattleMons[opponent].status2 & STATUS2_ESCAPE_PREVENTION)) {
                gBattleMons[opponent].status2 |= STATUS2_ESCAPE_PREVENTION;
                gDisableStructs[opponent].battlerPreventingEscape = battler;
                anyBlocked = TRUE;
            }

            if (anyBlocked) {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_BLOCK_ON_ENTRY;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
        }

        //Supreme Overlord
        if (CheckAndSetSwitchInAbility(battler, ABILITY_SUPREME_OVERLORD))
        {
            if (gFaintedMonCount[GetBattlerSide(battler)])
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_SUPREME_OVERLORD;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
        }

        //Berserk DNA
        if (CheckAndSetSwitchInAbility(battler, ABILITY_BERSERK_DNA))
        {
            bool8 becameConfused = FALSE;
            if (CanBeConfused(battler)) {
                gBattleMons[battler].status2 |= STATUS2_CONFUSION;
                gBattleMons[battler].status2 |= STATUS2_CONFUSION_TURN(3);
                becameConfused = TRUE;
            }
            BattleScriptPushCursorAndCallback(becameConfused ? BattleScript_BerserkDNA : BattleScript_BerserkDNANoConfusion);
            
            effect++;
        }

        if (CheckAndSetSwitchInAbility(battler, ABILITY_PROTOSYNTHESIS))
        {
            if (IsBattlerWeatherAffected(battler, WEATHER_SUN_ANY))
            {
                struct ParadoxBoost boost = { .statId = GetHighestStatId(battler, TRUE), .source = PARADOX_WEATHER_ACTIVE };
                SetAbilityStateAs(battler, ABILITY_PROTOSYNTHESIS, (union AbilityStates) { .paradoxBoost = boost });
                PREPARE_STAT_BUFFER(gBattleTextBuff1, boost.statId);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PARADOX_BOOST_WEATHER;
                BattleScriptPushCursorAndCallback(BattleScript_ParadoxBoostActivates);
            }
        }

        if (CheckAndSetSwitchInAbility(battler, ABILITY_QUARK_DRIVE))
        {
            if (IsBattlerTerrainAffected(battler, STATUS_FIELD_ELECTRIC_TERRAIN))
            {
                struct ParadoxBoost boost = { .statId = GetHighestStatId(battler, TRUE), .source = ABILITY_QUARK_DRIVE };
                SetAbilityStateAs(battler, ABILITY_QUARK_DRIVE, (union AbilityStates) { .paradoxBoost = boost });
                PREPARE_STAT_BUFFER(gBattleTextBuff1, boost.statId);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PARADOX_BOOST_TERRAIN;
                BattleScriptPushCursorAndCallback(BattleScript_ParadoxBoostActivates);
            }
        }

        if (CheckAndSetSwitchInAbility(battler, ABILITY_FURNACE)){
            if ((gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_STEALTH_ROCK)
            && gSideTimers[GetBattlerSide(gActiveBattler)].stealthRockType == TYPE_ROCK
            && IsBattlerAlive(battler)
            && CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                ChangeStatBuffs(battler, StatBuffValue(2), STAT_SPEED, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
                SetStatChanger(STAT_SPEED, 2);
                PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_SPEED);
                BattleScriptPushCursorAndCallback(BattleScript_AttackerAbilityStatRaiseEnd3);
                effect++;
            }
        }

        // Costar
        if (CheckAndSetSwitchInAbility(battler, ABILITY_COSTAR) && IsBattlerAlive(BATTLE_PARTNER(battler)))
        {
            u8 i;
            bool8 anyChanged = FALSE;
            for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
            {
                if (gBattleMons[battler].statStages[i] != gBattleMons[BATTLE_PARTNER(battler)].statStages[i])
                {
                    gBattleMons[battler].statStages[i] = gBattleMons[BATTLE_PARTNER(battler)].statStages[i];
                    anyChanged = TRUE;
                }
            }

            if (anyChanged)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_COSTAR;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
        }

        //Mold Breaker
        if(CheckAndSetSwitchInAbility(battler, ABILITY_MOLD_BREAKER)){
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_MOLDBREAKER;
            BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
            effect++;
        }

        // Double spikes on entry
        if (CheckAndSetSwitchInAbility(battler, ABILITY_WATCH_YOUR_STEP))
        {
            u8 targetSide = GetBattlerSide(BATTLE_OPPOSITE(battler));
            if (gSideTimers[targetSide].spikesAmount < 3)
            {
                gSideTimers[targetSide].spikesAmount = min(gSideTimers[targetSide].spikesAmount + 2, 3);
                gSideStatuses[targetSide] |= SIDE_STATUS_SPIKES;
                BattleScriptPushCursorAndCallback(BattleScript_DoubleSpikesOnEntry);
                effect++;
            }
        }

        //Totem Boost
        if(FlagGet(FLAG_TOTEM_BATTLE) 
            && GetBattlerSide(battler) != B_SIDE_PLAYER 
            && gBattleResults.battleTurnCounter == 0
            && !(gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            && !gBattleMons[battler].wasalreadytotemboosted){
            FlagSet(FLAG_SMART_AI);
            
            gBattlerAttacker = battler;
            gBattleMons[battler].wasalreadytotemboosted = TRUE;

            gBattleMons[battler].statStages[STAT_ATK]     = gBattleMons[battler].statStages[STAT_ATK]     + VarGet(VAR_TOTEM_POKEMON_ATK_BOOST);
            gBattleMons[battler].statStages[STAT_DEF]     = gBattleMons[battler].statStages[STAT_DEF]     + VarGet(VAR_TOTEM_POKEMON_DEF_BOOST);
            gBattleMons[battler].statStages[STAT_SPATK]   = gBattleMons[battler].statStages[STAT_SPATK]   + VarGet(VAR_TOTEM_POKEMON_SP_ATK_BOOST);
            gBattleMons[battler].statStages[STAT_SPDEF]   = gBattleMons[battler].statStages[STAT_SPDEF]   + VarGet(VAR_TOTEM_POKEMON_SP_DEF_BOOST);
            gBattleMons[battler].statStages[STAT_SPEED]   = gBattleMons[battler].statStages[STAT_SPEED]   + VarGet(VAR_TOTEM_POKEMON_SPEED_BOOST);
            gBattleMons[battler].statStages[STAT_ACC]     = gBattleMons[battler].statStages[STAT_ACC]     + VarGet(VAR_TOTEM_POKEMON_ACCURACY_BOOST);
            gBattleMons[battler].statStages[STAT_EVASION] = gBattleMons[battler].statStages[STAT_EVASION] + VarGet(VAR_TOTEM_POKEMON_EVASION_BOOST);

            //Evasion
            /*if(VarGet(VAR_TOTEM_POKEMON_EVASION_BOOST) == 1){
                BattleScriptPushCursorAndCallback(BattleScript_TotemBoosted_Evasion);
                effect++;
            }
            else if(VarGet(VAR_TOTEM_POKEMON_EVASION_BOOST) == 2){
                BattleScriptPushCursorAndCallback(BattleScript_TotemBoosted_Evasion2);
                effect++;
            }

            //Accuracy
            if(VarGet(VAR_TOTEM_POKEMON_ACCURACY_BOOST) == 1){
                BattleScriptPushCursorAndCallback(BattleScript_TotemBoosted_Accuracy);
                effect++;
            }
            else if(VarGet(VAR_TOTEM_POKEMON_ACCURACY_BOOST) == 2){
                BattleScriptPushCursorAndCallback(BattleScript_TotemBoosted_Accuracy2);
                effect++;
            }

            //Speed
            if(VarGet(VAR_TOTEM_POKEMON_SPEED_BOOST) == 1){
                BattleScriptPushCursorAndCallback(BattleScript_TotemBoosted_Speed);
                effect++;
            }
            else if(VarGet(VAR_TOTEM_POKEMON_SPEED_BOOST) == 2){
                BattleScriptPushCursorAndCallback(BattleScript_TotemBoosted_Speed2);
                effect++;
            }

            //Special Defense
            if(VarGet(VAR_TOTEM_POKEMON_SP_DEF_BOOST) == 1){
                BattleScriptPushCursorAndCallback(BattleScript_TotemBoosted_SpecialDefense);
                effect++;
            }
            else if(VarGet(VAR_TOTEM_POKEMON_SP_DEF_BOOST) == 2){
                BattleScriptPushCursorAndCallback(BattleScript_TotemBoosted_SpecialDefense2);
                effect++;
            }

            //Special Attack
            if(VarGet(VAR_TOTEM_POKEMON_SP_ATK_BOOST) == 1){
                BattleScriptPushCursorAndCallback(BattleScript_TotemBoosted_SpecialAttack);
                effect++;
            }
            else if(VarGet(VAR_TOTEM_POKEMON_SP_ATK_BOOST) == 2){
                BattleScriptPushCursorAndCallback(BattleScript_TotemBoosted_SpecialAttack2);
                effect++;
            }

            //Defense
            if(VarGet(VAR_TOTEM_POKEMON_DEF_BOOST) == 1){
                BattleScriptPushCursorAndCallback(BattleScript_TotemBoosted_Defense);
                effect++;
            }
            else if(VarGet(VAR_TOTEM_POKEMON_DEF_BOOST) == 2){
                BattleScriptPushCursorAndCallback(BattleScript_TotemBoosted_Defense2);
                effect++;
            }

            //Attack
            if(VarGet(VAR_TOTEM_POKEMON_ATK_BOOST) == 1){
                BattleScriptPushCursorAndCallback(BattleScript_TotemBoosted_Attack);
                effect++;
            }
            else if(VarGet(VAR_TOTEM_POKEMON_ATK_BOOST) == 2){
                BattleScriptPushCursorAndCallback(BattleScript_TotemBoosted_Attack2);
                effect++;
            }*/

            SET_STATCHANGER(STAT_ATK, 1, FALSE); //Just for the animation
            switch(VarGet(VAR_TOTEM_MESSAGE)){
                case TOTEM_FIGHT_HAXORUS:
                    BattleScriptPushCursorAndCallback(BattleScript_HaxorusTotemBoostActivated);
                break;
                default:
                    BattleScriptPushCursorAndCallback(BattleScript_WildTotemBoostActivated);
                break;
            }
            effect++;

            VarSet(VAR_TOTEM_POKEMON_ATK_BOOST,      0);
            VarSet(VAR_TOTEM_POKEMON_DEF_BOOST,      0);
            VarSet(VAR_TOTEM_POKEMON_SP_ATK_BOOST,   0);
            VarSet(VAR_TOTEM_POKEMON_SP_DEF_BOOST,   0);
            VarSet(VAR_TOTEM_POKEMON_SPEED_BOOST,    0);
            VarSet(VAR_TOTEM_POKEMON_ACCURACY_BOOST, 0);
            VarSet(VAR_TOTEM_POKEMON_EVASION_BOOST,  0);
            VarSet(VAR_TOTEM_MESSAGE,                0);
        }
        //abilityEffect End
        break;
    case ABILITYEFFECT_ENDTURN: // 1
        if (gBattleMons[battler].hp != 0)
        {
            gBattlerAttacker = battler;
            switch (gLastUsedAbility)
            {
            case ABILITY_DRY_SKIN:
                if (IsBattlerWeatherAffected(battler, WEATHER_SUN_ANY) && !BATTLER_HAS_MAGIC_GUARD(battler))
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_DRY_SKIN;
                    BattleScriptPushCursorAndCallback(BattleScript_SolarPowerActivates);
                    gBattleMoveDamage = gBattleMons[battler].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    effect++;
                }
				else if(IsBattlerWeatherAffected(battler, WEATHER_RAIN_ANY)
                 && !BATTLER_MAX_HP(battler)
                 && !BATTLER_HEALING_BLOCKED(battler))
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_DRY_SKIN;
                    BattleScriptPushCursorAndCallback(BattleScript_RainDishActivates);
                    gBattleMoveDamage = gBattleMons[battler].maxHP / (gLastUsedAbility == ABILITY_RAIN_DISH ? 8 : 8); // was 16 : 8
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                    effect++;
                }
                break;
            // Dry Skin works similarly to Rain Dish in Rain
            case ABILITY_RAIN_DISH:
                if (IsBattlerWeatherAffected(battler, WEATHER_RAIN_ANY)
                 && !BATTLER_MAX_HP(battler)
                 && !BATTLER_HEALING_BLOCKED(battler))
                {
                    BattleScriptPushCursorAndCallback(BattleScript_RainDishActivates);
                    gBattleMoveDamage = gBattleMons[battler].maxHP / (gLastUsedAbility == ABILITY_RAIN_DISH ? 8 : 8); // was 16 : 8
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                    effect++;
                }
                break;
            case ABILITY_HYDRATION:
                if (IsBattlerWeatherAffected(battler, WEATHER_RAIN_ANY))
                {
                    AbilityHealMonStatus(&effect, gActiveBattler, ABILITY_HYDRATION);
                }
                break;
            case ABILITY_SHED_SKIN:
                if ((Random() % 100) < 30)
                {
                    AbilityHealMonStatus(&effect, gActiveBattler, ABILITY_SHED_SKIN);
                }
                break;
            case ABILITY_SPEED_BOOST:
                if (CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN) && gDisableStructs[battler].isFirstTurn != 2)
                {
                    ChangeStatBuffs(battler, StatBuffValue(1), STAT_SPEED, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_SPEED_BOOST;
                    gBattlerAttacker = battler;
                    gBattleScripting.animArg1 = 14 + STAT_SPEED;
                    gBattleScripting.animArg2 = 0;
                    BattleScriptPushCursorAndCallback(BattleScript_SpeedBoostActivates);
                    gBattleScripting.battler = battler;
                    effect++;
                }
                break;
            case ABILITY_MOODY:
                if (gDisableStructs[battler].isFirstTurn != 2)
                {
                    u32 validToRaise = 0, validToLower = 0;
                    u32 statsNum = (B_MOODY_ACC_EVASION != GEN_8) ? NUM_BATTLE_STATS : NUM_STATS;

                    for (i = STAT_ATK; i < statsNum; i++)
                    {
                        if (CompareStat(battler, i, MIN_STAT_STAGE, CMP_GREATER_THAN))
                            validToLower |= gBitTable[i];
                        if (CompareStat(battler, i, MAX_STAT_STAGE, CMP_LESS_THAN))
                            validToRaise |= gBitTable[i];
                    }

                    if (validToLower != 0 || validToRaise != 0) // Can lower one stat, or can raise one stat
                    {
                        gBattleScripting.statChanger = gBattleScripting.savedStatChanger = 0; // for raising and lowering stat respectively
                        if (validToRaise != 0) // Find stat to raise
                        {
                            do
                            {
                                i = (Random() % statsNum) + STAT_ATK;
                            } while (!(validToRaise & gBitTable[i]));
                            SET_STATCHANGER(i, 2, FALSE);
                            validToLower &= ~(gBitTable[i]); // Can't lower the same stat as raising.
                        }
                        if (validToLower != 0) // Find stat to lower
                        {
                            do
                            {
                                i = (Random() % statsNum) + STAT_ATK;
                            } while (!(validToLower & gBitTable[i]));
                            SET_STATCHANGER2(gBattleScripting.savedStatChanger, i, 1, TRUE);
                        }
                        BattleScriptPushCursorAndCallback(BattleScript_MoodyActivates);
                        effect++;
                    }
                }
                break;
            case ABILITY_TRUANT:
                gDisableStructs[gBattlerAttacker].truantCounter ^= 1;
                break;
            case ABILITY_SWEET_DREAMS:
                if (!BATTLER_MAX_HP(gActiveBattler) && !BATTLER_HEALING_BLOCKED(gActiveBattler) && ((gBattleMons[battler].status1 & STATUS1_SLEEP) || BattlerHasInnate(battler, ABILITY_COMATOSE)  || GetBattlerAbility(battler) == ABILITY_COMATOSE))
                {
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                    BattleScriptExecute(BattleScript_SweetDreamsActivates);
                    effect++;
                }
                break;
            case ABILITY_SCHOOLING:
                if (gBattleMons[battler].level < 20)
                    break;
            case ABILITY_FORECAST:
            case ABILITY_FLOWER_GIFT:
                if ((effect = ShouldChangeFormHpBased(battler)))
                    BattleScriptPushCursorAndCallback(BattleScript_AttackerFormChangeEnd3);
                break;
            case ABILITY_POWER_CONSTRUCT:
                if ((gBattleMons[battler].species == SPECIES_ZYGARDE || gBattleMons[battler].species == SPECIES_ZYGARDE_10)
                    && gBattleMons[battler].hp <= gBattleMons[battler].maxHP / 2)
                {
                    gBattleStruct->changedSpecies[gBattlerPartyIndexes[battler]] = gBattleMons[battler].species;
                    UpdateAbilityStateIndicesForNewSpecies(gActiveBattler, SPECIES_ZYGARDE_COMPLETE);
                    gBattleMons[battler].species = SPECIES_ZYGARDE_COMPLETE;
                    BattleScriptPushCursorAndCallback(BattleScript_AttackerFormChangeEnd3);
                    effect++;
                }
                break;
            case ABILITY_BALL_FETCH:
                if (gBattleMons[battler].item == ITEM_NONE
                    && gBattleResults.catchAttempts[gLastUsedBall - ITEM_ULTRA_BALL] >= 1
                    && !gHasFetchedBall)
                {
                    gBattleScripting.battler = battler;
                    BtlController_EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gLastUsedBall);
                    MarkBattlerForControllerExec(battler);
                    gHasFetchedBall = TRUE;
                    gLastUsedItem = gLastUsedBall;
                    BattleScriptPushCursorAndCallback(BattleScript_BallFetch);
                    effect++;
                }
                break;
            case ABILITY_HUNGER_SWITCH:
                if (!(gBattleMons[battler].status2 & STATUS2_TRANSFORMED))
                {
                    if (gBattleMons[battler].species == SPECIES_MORPEKO)
                    {
                        UpdateAbilityStateIndicesForNewSpecies(gActiveBattler, SPECIES_MORPEKO_HANGRY);
                        gBattleMons[battler].species = SPECIES_MORPEKO_HANGRY;
                        BattleScriptPushCursorAndCallback(BattleScript_AttackerFormChangeEnd3NoPopup);
                    }
                    else if (gBattleMons[battler].species == SPECIES_MORPEKO_HANGRY)
                    {
                        UpdateAbilityStateIndicesForNewSpecies(gActiveBattler, SPECIES_MORPEKO);
                        gBattleMons[battler].species = SPECIES_MORPEKO;
                        BattleScriptPushCursorAndCallback(BattleScript_AttackerFormChangeEnd3NoPopup);
                    }
                    effect++;
                }
                break;
            }
			
			
			// End Turn Innates
			
			/***********************************/
			// Dry Skin
            if(BattlerHasInnate(gActiveBattler, ABILITY_DRY_SKIN)){
                if (IsBattlerWeatherAffected(battler, WEATHER_SUN_ANY) && !BATTLER_HAS_MAGIC_GUARD(battler))
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_DRY_SKIN;
                    BattleScriptPushCursorAndCallback(BattleScript_SolarPowerActivates);
                    gBattleMoveDamage = gBattleMons[battler].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    effect++;
                }
				else if(IsBattlerWeatherAffected(battler, WEATHER_RAIN_ANY)
                 && !BATTLER_MAX_HP(battler)
                 && !BATTLER_HEALING_BLOCKED(battler))
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_DRY_SKIN;
                    BattleScriptPushCursorAndCallback(BattleScript_RainDishActivates);
                    gBattleMoveDamage = gBattleMons[battler].maxHP / (gLastUsedAbility == ABILITY_RAIN_DISH ? 8 : 8); // was 16 : 8
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                    effect++;
                }
            }

			// Hydration
            if(BattlerHasInnate(gActiveBattler, ABILITY_HYDRATION)){
                if (IsBattlerWeatherAffected(battler, WEATHER_RAIN_ANY))
                {
                    AbilityHealMonStatus(&effect, gActiveBattler, ABILITY_HYDRATION);
                }
            }

			// Purifying Waters
            if(BattlerHasInnate(gActiveBattler, ABILITY_PURIFYING_WATERS)){
                if (IsBattlerWeatherAffected(battler, WEATHER_RAIN_ANY))
                {
                    AbilityHealMonStatus(&effect, gActiveBattler, ABILITY_PURIFYING_WATERS);
                }
            }
			
			// Shed Skin
            if(BattlerHasInnate(gActiveBattler, ABILITY_SHED_SKIN)){
                if ((Random() % 100) < 30)
                {
                    AbilityHealMonStatus(&effect, gActiveBattler, ABILITY_SHED_SKIN);
                }
			}
			
			// Speed Boost
            if(BattlerHasInnate(gActiveBattler, ABILITY_SPEED_BOOST)){
                if (CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN) && gDisableStructs[battler].isFirstTurn != 2)
                {
                    ChangeStatBuffs(battler, StatBuffValue(1), STAT_SPEED, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_SPEED_BOOST;
                    gBattlerAttacker = battler;
                    gBattleScripting.animArg1 = 14 + STAT_SPEED;
                    gBattleScripting.animArg2 = 0;
                    BattleScriptPushCursorAndCallback(BattleScript_SpeedBoostActivates);
                    gBattleScripting.battler = battler;
                    effect++;
                }
            }
			
			// Moody
            if(BattlerHasInnate(gActiveBattler, ABILITY_MOODY)){
                if (gDisableStructs[battler].isFirstTurn != 2)
                {
                    u32 validToRaise = 0, validToLower = 0;
                    u32 statsNum = (B_MOODY_ACC_EVASION != GEN_8) ? NUM_BATTLE_STATS : NUM_STATS;
                    gBattleScripting.abilityPopupOverwrite = ABILITY_MOODY;
			        gLastUsedAbility = ABILITY_MOODY;

                    for (i = STAT_ATK; i < statsNum; i++)
                    {
                        if (CompareStat(battler, i, MIN_STAT_STAGE, CMP_GREATER_THAN))
                            validToLower |= gBitTable[i];
                        if (CompareStat(battler, i, MAX_STAT_STAGE, CMP_LESS_THAN))
                            validToRaise |= gBitTable[i];
                    }

                    if (validToLower != 0 || validToRaise != 0) // Can lower one stat, or can raise one stat
                    {
                        gBattleScripting.statChanger = gBattleScripting.savedStatChanger = 0; // for raising and lowering stat respectively
                        if (validToRaise != 0) // Find stat to raise
                        {
                            do
                            {
                                i = (Random() % statsNum) + STAT_ATK;
                            } while (!(validToRaise & gBitTable[i]));
                            SET_STATCHANGER(i, 2, FALSE);
                            validToLower &= ~(gBitTable[i]); // Can't lower the same stat as raising.
                        }
                        if (validToLower != 0) // Find stat to lower
                        {
                            do
                            {
                                i = (Random() % statsNum) + STAT_ATK;
                            } while (!(validToLower & gBitTable[i]));
                            SET_STATCHANGER2(gBattleScripting.savedStatChanger, i, 1, TRUE);
                        }
                        BattleScriptPushCursorAndCallback(BattleScript_MoodyActivates);
                        effect++;
                    }
                }
            }
			
			// Truant
            if(BattlerHasInnate(gActiveBattler, ABILITY_TRUANT)){
                gDisableStructs[gBattlerAttacker].truantCounter ^= 1;
            }
			
			// Bad Dreams
            if(BATTLER_HAS_ABILITY(gActiveBattler, ABILITY_BAD_DREAMS)){
                if(BattlerHasInnate(gActiveBattler, ABILITY_BAD_DREAMS))
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_BAD_DREAMS;
                
                BattleScriptPushCursorAndCallback(BattleScript_BadDreamsActivates);
                effect++;
            }
			
			// Sweet Dreams
            if(BattlerHasInnate(gActiveBattler, ABILITY_SWEET_DREAMS)){
                if (!BATTLER_MAX_HP(gActiveBattler) && !BATTLER_HEALING_BLOCKED(gActiveBattler) && ((gBattleMons[battler].status1 & STATUS1_SLEEP) || BattlerHasInnate(battler, ABILITY_COMATOSE)  || GetBattlerAbility(battler) == ABILITY_COMATOSE))
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_SWEET_DREAMS;
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                    BattleScriptPushCursorAndCallback(BattleScript_SweetDreamsActivates);
                    effect++;
                }
			}
			
			// Sweet Dreams
            if(BATTLER_HAS_ABILITY(gActiveBattler, ABILITY_PEACEFUL_SLUMBER)){
                if (!BATTLER_MAX_HP(gActiveBattler) && !BATTLER_HEALING_BLOCKED(gActiveBattler) && ((gBattleMons[battler].status1 & STATUS1_SLEEP) || BattlerHasInnate(battler, ABILITY_COMATOSE)  || GetBattlerAbility(battler) == ABILITY_COMATOSE))
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_PEACEFUL_SLUMBER;
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                    BattleScriptPushCursorAndCallback(BattleScript_SweetDreamsActivates);
                    effect++;
                }
			}
			
			// Healer
			if(BATTLER_HAS_ABILITY(gActiveBattler, ABILITY_HEALER) && (Random() % 100) < 30) {
                if (IsBattlerAlive(BATTLE_PARTNER(gActiveBattler)) && gBattleMons[BATTLE_PARTNER(gActiveBattler)].status1 & STATUS1_ANY)                    
                {
                    gBattleScripting.abilityPopupOverwrite = ABILITY_HEALER;
                    gEffectBattler = gActiveBattler;
                    gBattleScripting.battler = BATTLE_PARTNER(gActiveBattler);
                    BattleScriptPushCursorAndCallback(BattleScript_HealerActivates);
                    effect++;
                }
                else if (IsBattlerAlive(gActiveBattler) && gBattleMons[gActiveBattler].status1 & STATUS1_ANY)                    
                {
                    AbilityHealMonStatus(&effect, gActiveBattler, ABILITY_HEALER);
                }
			}
			
			// Schooling
            if(BattlerHasInnate(gActiveBattler, ABILITY_SCHOOLING)){
                if (gBattleMons[battler].level >= 20){
					if ((effect = ShouldChangeFormHpBased(battler)))
                    BattleScriptPushCursorAndCallback(BattleScript_AttackerFormChangeEnd3);
				}
            }
		
			// Shields Down
            if(BATTLER_HAS_ABILITY(gActiveBattler, ABILITY_SHIELDS_DOWN)){
				if ((effect = ShouldChangeFormHpBased(battler))){
                    if(BattlerHasInnate(gActiveBattler, ABILITY_SHIELDS_DOWN))
                        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_SHIELDS_DOWN;
                    BattleScriptPushCursorAndCallback(BattleScript_AttackerFormChangeEnd3);
                }
			}

            // Harvest
            if(BATTLER_HAS_ABILITY(battler, ABILITY_HARVEST)){
                bool8 activateAbilty = FALSE;
                u16 abilityToCheck = ABILITY_HARVEST; //For easier copypaste

                if ((IsBattlerWeatherAffected(battler, WEATHER_SUN_ANY) || Random() % 2 == 0)
                 && gBattleMons[battler].item == ITEM_NONE
                 && gBattleStruct->changedItems[battler] == ITEM_NONE   // Will not inherit an item
                 && ItemId_GetPocket(GetUsedHeldItem(battler)) == POCKET_BERRIES)
                    activateAbilty = TRUE;

                //This is the stuff that has to be changed for each ability
                if(activateAbilty){
                    if(BattlerHasInnateOrAbility(battler, abilityToCheck) == BATTLER_INNATE)
                        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = abilityToCheck;

                    gBattlerAttacker = battler;
                    BattleScriptPushCursorAndCallback(BattleScript_HarvestActivates);
                    effect++;
                }
            }

            // Big Leaves
            if(BATTLER_HAS_ABILITY(battler, ABILITY_BIG_LEAVES)){
                bool8 activateAbilty = FALSE;
                u16 abilityToCheck = ABILITY_BIG_LEAVES; //For easier copypaste

                if ((IsBattlerWeatherAffected(battler, WEATHER_SUN_ANY) || Random() % 2 == 0)
                 && gBattleMons[battler].item == ITEM_NONE
                 && gBattleStruct->changedItems[battler] == ITEM_NONE   // Will not inherit an item
                 && ItemId_GetPocket(GetUsedHeldItem(battler)) == POCKET_BERRIES)
                    activateAbilty = TRUE;

                //This is the stuff that has to be changed for each ability
                if(activateAbilty && !BATTLER_HAS_ABILITY(battler, ABILITY_HARVEST)){
                    if(BattlerHasInnateOrAbility(battler, abilityToCheck) == BATTLER_INNATE)
                        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = abilityToCheck;
                    gBattlerAttacker = battler;
                    BattleScriptPushCursorAndCallback(BattleScript_HarvestActivates);
                    effect++;
                }
            }

            // Self Sufficient
            if(BATTLER_HAS_ABILITY(battler, ABILITY_SELF_SUFFICIENT)){
                bool8 activateAbilty = FALSE;
                u16 abilityToCheck = ABILITY_SELF_SUFFICIENT; //For easier copypaste

                if(BattlerHasInnateOrAbility(battler, abilityToCheck) == BATTLER_INNATE)
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = abilityToCheck;
                
                if(!BATTLER_MAX_HP(battler) && 
                   !BATTLER_HEALING_BLOCKED(gActiveBattler) && 
                   gDisableStructs[battler].isFirstTurn != 2)
                    activateAbilty = TRUE;

                //This is the stuff that has to be changed for each ability
                if(activateAbilty){
				    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 16;
					if (gBattleMoveDamage == 0)
						gBattleMoveDamage = 1;
					gBattleMoveDamage *= -1;
					BattleScriptPushCursorAndCallback(BattleScript_SelfSufficientActivates);
					effect++;
                }
            }

            // Self Sufficient
            if(BATTLER_HAS_ABILITY(battler, ABILITY_CELESTIAL_BLESSING)){
                if(!BATTLER_MAX_HP(battler) && 
                   !BATTLER_HEALING_BLOCKED(gActiveBattler) && 
                   gDisableStructs[battler].isFirstTurn != 2 &&
                   IsBattlerTerrainAffected(battler, STATUS_FIELD_MISTY_TERRAIN))
                {
                    u16 abilityToCheck = ABILITY_CELESTIAL_BLESSING; //For easier copypaste

                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_CELESTIAL_BLESSING;
                    
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 12;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                    BattleScriptPushCursorAndCallback(BattleScript_SelfSufficientActivates);
                    effect++;
                }
            }

            if (BATTLER_HAS_ABILITY(battler, ABILITY_CUD_CHEW))
            {
                u32 itemId = GetAbilityState(battler, ABILITY_CUD_CHEW);
                if (itemId & CUD_CHEW_CURRENT_TURN)
                {
                    SetAbilityState(battler, ABILITY_CUD_CHEW, itemId & ~CUD_CHEW_CURRENT_TURN);
                }
                else
                {
                    // attacker temporarily gains their item
                    gBattleStruct->changedItems[battler] = gBattleMons[battler].item;
                    gBattleMons[battler].item = itemId;
                    gBattleScripting.abilityPopupOverwrite = ABILITY_CUD_CHEW;
                    gBattlerAttacker = battler;
                    
                    BattleScriptPushCursorAndCallback(BattleScript_CudChew);
                    effect++;

                }
            }

            // Peaceful Slumber
            if(BATTLER_HAS_ABILITY(battler, ABILITY_PEACEFUL_SLUMBER)){
                bool8 activateAbilty = FALSE;
                u16 abilityToCheck = ABILITY_PEACEFUL_SLUMBER; //For easier copypaste

                if(BattlerHasInnateOrAbility(battler, abilityToCheck) == BATTLER_INNATE)
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = abilityToCheck;
                
                if(!BATTLER_MAX_HP(battler) && 
                   !BATTLER_HEALING_BLOCKED(gActiveBattler) && 
                   gDisableStructs[battler].isFirstTurn != 2)
                    activateAbilty = TRUE;

                //This is the stuff that has to be changed for each ability
                if(activateAbilty){
				    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 16;
					if (gBattleMoveDamage == 0)
						gBattleMoveDamage = 1;
					gBattleMoveDamage *= -1;
					BattleScriptPushCursorAndCallback(BattleScript_SelfSufficientActivates);
					effect++;
                }
            }

            // Self Repair
            if(BATTLER_HAS_ABILITY(battler, ABILITY_SELF_REPAIR)){
                bool8 activateAbilty = FALSE;
                u16 abilityToCheck = ABILITY_SELF_REPAIR; //For easier copypaste

                if(BattlerHasInnateOrAbility(battler, abilityToCheck) == BATTLER_INNATE)
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = abilityToCheck;
                
                if(!BATTLER_MAX_HP(battler) && 
                   !BATTLER_HEALING_BLOCKED(gActiveBattler) && 
                   gDisableStructs[battler].isFirstTurn != 2)
                    activateAbilty = TRUE;

                //This is the stuff that has to be changed for each ability
                if(activateAbilty){
				    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 16;
					if (gBattleMoveDamage == 0)
						gBattleMoveDamage = 1;
					gBattleMoveDamage *= -1;
					BattleScriptPushCursorAndCallback(BattleScript_SelfSufficientActivates);
					effect++;
                }
            }
			
			// Rain Dish
			if(BattlerHasInnate(gActiveBattler, ABILITY_RAIN_DISH)){
				if (IsBattlerWeatherAffected(battler, WEATHER_RAIN_ANY)
                 && !BATTLER_MAX_HP(battler)
                 && !BATTLER_HEALING_BLOCKED(battler))
                {
                    BattleScriptPushCursorAndCallback(BattleScript_RainDishActivates);
                    gBattleMoveDamage = gBattleMons[battler].maxHP / 8; // was 16 : 8
				    gBattleScripting.abilityPopupOverwrite = ABILITY_RAIN_DISH;
				    gLastUsedAbility = ABILITY_RAIN_DISH;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                    effect++;
                }
			}

            if (BATTLER_HAS_ABILITY(gActiveBattler, ABILITY_BLOOD_PRICE)) {
                if (gBattleMoves[move].split != SPLIT_STATUS
                    && !BATTLER_HAS_MAGIC_GUARD(gActiveBattler)
                    && !gProtectStructs[gActiveBattler].confusionSelfDmg)
                {
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 10;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;

                    gBattlerAttacker = gActiveBattler;
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_BLOOD_PRICE;
                    
                    BattleScriptPushCursorAndCallback(BattleScript_AbilitySelfDamage);
                    effect++;
                }
            }
        }
        break;
    case ABILITYEFFECT_MOVES_BLOCK: // 2
        if (BATTLER_HAS_ABILITY(battler, ABILITY_SOUNDPROOF)
            && !(gBattleMoves[move].target & MOVE_TARGET_USER)
			&& gBattleMoves[move].flags & FLAG_SOUND)
        {
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_SOUNDPROOF;
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)
                gHitMarker |= HITMARKER_NO_PPDEDUCT;
            gBattlescriptCurrInstr = BattleScript_SoundproofProtected;
            effect = 1;
        }
        else if (IsAbilityOnSide(battler, ABILITY_NOISE_CANCEL)
            && !(gBattleMoves[move].target & MOVE_TARGET_USER)
			&& gBattleMoves[move].flags & FLAG_SOUND)
        {
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_NOISE_CANCEL;
            if (!BATTLER_HAS_ABILITY(battler, ABILITY_NOISE_CANCEL)) {
                gBattleScripting.battlerPopupOverwrite = BATTLE_PARTNER(battler);
            }

            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)
                gHitMarker |= HITMARKER_NO_PPDEDUCT;
            gBattlescriptCurrInstr = BattleScript_SoundproofProtected;
            effect = 1;
        }
        else if (BATTLER_HAS_ABILITY(battler, ABILITY_WEATHER_CONTROL)
            && !(gBattleMoves[move].target & MOVE_TARGET_USER)
			&& gBattleMoves[move].flags & FLAG_WEATHER_BASED)
        {
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_WEATHER_CONTROL;
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)
                gHitMarker |= HITMARKER_NO_PPDEDUCT;
            gBattlescriptCurrInstr = BattleScript_SoundproofProtected;
            effect = 1;
        }
        else if (BATTLER_HAS_ABILITY(battler, ABILITY_DELTA_STREAM)
            && !(gBattleMoves[move].target & MOVE_TARGET_USER)
			&& gBattleMoves[move].flags & FLAG_WEATHER_BASED)
        {
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_DELTA_STREAM;
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)
                gHitMarker |= HITMARKER_NO_PPDEDUCT;
            gBattlescriptCurrInstr = BattleScript_SoundproofProtected;
            effect = 1;
        }
        else if ((GetBattlerAbility(battler) == ABILITY_BULLETPROOF || BattlerHasInnate(battler, ABILITY_BULLETPROOF))
			&& gBattleMoves[move].flags & FLAG_BALLISTIC)
        {
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_BULLETPROOF;
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)
                gHitMarker |= HITMARKER_NO_PPDEDUCT;
            gBattlescriptCurrInstr = BattleScript_SoundproofProtected;
            effect = 1;
        }
        else if (IsAbilityOnField(ABILITY_RADIANCE) && moveType == TYPE_DARK)
        {
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_RADIANCE;
            gBattleScripting.battlerPopupOverwrite = IsAbilityOnField(ABILITY_RADIANCE);
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)
                gHitMarker |= HITMARKER_NO_PPDEDUCT;
            gBattlescriptCurrInstr = BattleScript_RadianceProtected;
            effect = 1;
        }
        //Queenly Majesty
        else if(IsAbilityOnSide(battler, ABILITY_QUEENLY_MAJESTY)
            && GetChosenMovePriority(gBattlerAttacker, battler) > 0
            && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(battler)
            && !(move == MOVE_SCRATCH && BattlerHasInnateOrAbility(gBattlerAttacker, ABILITY_CHEAP_TACTICS))
            )
        {
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_QUEENLY_MAJESTY;
            if (!BATTLER_HAS_ABILITY(battler, ABILITY_QUEENLY_MAJESTY)) {
                gBattleScripting.battlerPopupOverwrite = BATTLE_PARTNER(battler);
            }

            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS){
                gHitMarker |= HITMARKER_NO_PPDEDUCT;
                gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_MULTIPLETURNS);
            }

            if (gStatuses3[gBattlerAttacker] & STATUS3_SEMI_INVULNERABLE)
                gStatuses3[gBattlerAttacker] &= ~(STATUS3_SEMI_INVULNERABLE);

            gBattlescriptCurrInstr = BattleScript_DazzlingProtected;
            effect = 1;
        }
        //Dazzling
        else if(IsAbilityOnSide(battler, ABILITY_DAZZLING)
            && GetChosenMovePriority(gBattlerAttacker, battler) > 0
            && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(battler))
        {
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_DAZZLING;
            if (!BATTLER_HAS_ABILITY(battler, ABILITY_DAZZLING)) {
                gBattleScripting.battlerPopupOverwrite = BATTLE_PARTNER(battler);
            }

             if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS){
                gHitMarker |= HITMARKER_NO_PPDEDUCT;
                gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_MULTIPLETURNS);
            }

            if (gStatuses3[gBattlerAttacker] & STATUS3_SEMI_INVULNERABLE)
                gStatuses3[gBattlerAttacker] &= ~(STATUS3_SEMI_INVULNERABLE);

            gBattlescriptCurrInstr = BattleScript_DazzlingProtected;
            effect = 1;
        }
        //Armor Tail
        else if (IsAbilityOnSide(battler, ABILITY_ARMOR_TAIL)
            && GetChosenMovePriority(gBattlerAttacker, battler) > 0
            && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(battler))
        {
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_ARMOR_TAIL;
            if (!BATTLER_HAS_ABILITY(battler, ABILITY_ARMOR_TAIL)) {
                gBattleScripting.battlerPopupOverwrite = BATTLE_PARTNER(battler);
            }

            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS){
                gHitMarker |= HITMARKER_NO_PPDEDUCT;
                gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_MULTIPLETURNS);
            }

            if (gStatuses3[gBattlerAttacker] & STATUS3_SEMI_INVULNERABLE)
                gStatuses3[gBattlerAttacker] &= ~(STATUS3_SEMI_INVULNERABLE);

            gBattlescriptCurrInstr = BattleScript_DazzlingProtected;
            effect = 1;
        }
        //Sand Guard
        else if(BATTLER_HAS_ABILITY(battler, ABILITY_SAND_GUARD)
            && gBattleWeather & B_WEATHER_SANDSTORM && WEATHER_HAS_EFFECT
            && GetChosenMovePriority(gBattlerAttacker, battler) > 0)
        {
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_SAND_GUARD;

            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS){
                gHitMarker |= HITMARKER_NO_PPDEDUCT;
                gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_MULTIPLETURNS);
            }

            if (gStatuses3[gBattlerAttacker] & STATUS3_SEMI_INVULNERABLE)
                gStatuses3[gBattlerAttacker] &= ~(STATUS3_SEMI_INVULNERABLE);

            gBattlescriptCurrInstr = BattleScript_DazzlingProtected;
            effect = 1;
        }
        else if (BlocksPrankster(move, gBattlerAttacker, gBattlerTarget, TRUE)
          && !(IS_MOVE_STATUS(move) && BATTLER_HAS_ABILITY(gBattlerTarget, ABILITY_MAGIC_BOUNCE)))
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE) || !(gBattleMoves[move].target & (MOVE_TARGET_BOTH | MOVE_TARGET_FOES_AND_ALLY)))
                CancelMultiTurnMoves(gBattlerAttacker); // Don't cancel moves that can hit two targets bc one target might not be protected
            gBattleScripting.battler = gBattlerAbility = gBattlerTarget;
            gBattlescriptCurrInstr = BattleScript_DarkTypePreventsPrankster;
            effect = 1;
        }
        else if (BATTLER_HAS_ABILITY(battler, ABILITY_GOOD_AS_GOLD)
            && battler != gBattlerAttacker
            && IS_MOVE_STATUS(move))
        {
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_GOOD_AS_GOLD;
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)
                gHitMarker |= HITMARKER_NO_PPDEDUCT;
            gBattlescriptCurrInstr = BattleScript_SoundproofProtected;
            effect = 1;
        }
        
        break;
    case ABILITYEFFECT_ABSORBING: // 3
        if (move != MOVE_NONE)
        {
            u8 statId;
            switch (gLastUsedAbility)
            {
            case ABILITY_VOLT_ABSORB:
                if (moveType == TYPE_ELECTRIC)
                    effect = 1;
                break;
			case ABILITY_POISON_ABSORB:
                if (moveType == TYPE_POISON)
                    effect = 1;
                break;
            case ABILITY_WATER_ABSORB:
            case ABILITY_DRY_SKIN:
                if (moveType == TYPE_WATER)
                    effect = 1;
                break;
            case ABILITY_MOTOR_DRIVE:
                if (moveType == TYPE_ELECTRIC)
                    effect = 2, statId = STAT_SPEED;
                break;
			case ABILITY_AERODYNAMICS:
                if (moveType == TYPE_FLYING)
                    effect = 2, statId = STAT_SPEED;
                break;
            case ABILITY_LIGHTNING_ROD:
                if (moveType == TYPE_ELECTRIC){
                    effect = 2;
                    statId = GetHighestAttackingStatId(battler, TRUE);
				}
                break;
            case ABILITY_STORM_DRAIN:
                if (moveType == TYPE_WATER){
                    effect = 2;
                    statId = GetHighestAttackingStatId(battler, TRUE);
				}
                break;
            case ABILITY_SAP_SIPPER:
                if (moveType == TYPE_GRASS){
                    effect = 2;
                    statId = GetHighestAttackingStatId(battler, TRUE);
				}
                break;
            case ABILITY_ICE_DEW:
                if (moveType == TYPE_ICE){
                    effect = 2;
                    statId = GetHighestAttackingStatId(battler, TRUE);
				}
                break;
            case ABILITY_FLASH_FIRE:
                if (moveType == TYPE_FIRE && !((gBattleMons[battler].status1 & STATUS1_FREEZE) && B_FLASH_FIRE_FROZEN <= GEN_4))
                {
                    if (!(gBattleResources->flags->flags[battler] & RESOURCE_FLAG_FLASH_FIRE))
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FLASH_FIRE_BOOST;
                        if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                            gBattlescriptCurrInstr = BattleScript_FlashFireBoost;
                        else
                            gBattlescriptCurrInstr = BattleScript_FlashFireBoost_PPLoss;

                        gBattleResources->flags->flags[battler] |= RESOURCE_FLAG_FLASH_FIRE;
                        effect = 3;
                        gMultiHitCounter = 0;
                    }
                    else
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FLASH_FIRE_NO_BOOST;
                        if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                            gBattlescriptCurrInstr = BattleScript_FlashFireBoost;
                        else
                            gBattlescriptCurrInstr = BattleScript_FlashFireBoost_PPLoss;

                        effect = 3;
                        gMultiHitCounter = 0;
                    }
                }
                break;
            }
			
			// Innates
			// Aerodynamics
			if(BattlerHasInnate(battler, ABILITY_AERODYNAMICS)){
				if (move != MOVE_NONE && moveType == TYPE_FLYING){
					effect = 2;
					statId = STAT_SPEED;
                    gBattleScripting.abilityPopupOverwrite = ABILITY_AERODYNAMICS;
				    gLastUsedAbility = ABILITY_AERODYNAMICS;
				}
			}
			
			// Volt Absorb
			if(BattlerHasInnate(battler, ABILITY_VOLT_ABSORB)){
				if (move != MOVE_NONE && moveType == TYPE_ELECTRIC){
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_VOLT_ABSORB;
                    effect = 1;
				}
			}

            // Earth Eater
			if(BATTLER_HAS_ABILITY(battler, ABILITY_EARTH_EATER)){
				if (move != MOVE_NONE && moveType == TYPE_GROUND){
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_EARTH_EATER;
                    effect = 1;
				}
			}
			
			// Water Absorb
			if(BattlerHasInnate(battler, ABILITY_WATER_ABSORB)){
				if (move != MOVE_NONE && moveType == TYPE_WATER){
                    effect = 1;
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_WATER_ABSORB;
				}
			}
			
			// Dry Skin
			if(BattlerHasInnate(battler, ABILITY_DRY_SKIN)){
				if (move != MOVE_NONE && moveType == TYPE_WATER){
                    effect = 1;
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_DRY_SKIN;
				}
			}
			
			// Poison Absorb
			if(BattlerHasInnate(battler, ABILITY_POISON_ABSORB)){
				if (move != MOVE_NONE && moveType == TYPE_POISON){
                    effect = 1;
                    gBattleScripting.abilityPopupOverwrite = ABILITY_POISON_ABSORB;
				    gLastUsedAbility = ABILITY_POISON_ABSORB;
				}
			}
			
			// Lighting Rod
			if(BattlerHasInnate(battler, ABILITY_LIGHTNING_ROD)){
				if (moveType == TYPE_ELECTRIC){
                    effect = 2;
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_LIGHTNING_ROD;
                    statId = GetHighestAttackingStatId(battler, TRUE);
				}
			}

            // Storm Drain
			if(BattlerHasInnate(battler, ABILITY_STORM_DRAIN)){
				if (moveType == TYPE_WATER){
                    effect = 2;
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_STORM_DRAIN;
                    statId = GetHighestAttackingStatId(battler, TRUE);
				}
			}
			
			// Flash Fire
			if(BattlerHasInnate(battler, ABILITY_FLASH_FIRE)){
                if (moveType == TYPE_FIRE && !((gBattleMons[battler].status1 & STATUS1_FREEZE) && B_FLASH_FIRE_FROZEN <= GEN_4))
                {
                    gBattleScripting.abilityPopupOverwrite = ABILITY_FLASH_FIRE;
				    gLastUsedAbility = ABILITY_FLASH_FIRE;

                    if (!(gBattleResources->flags->flags[battler] & RESOURCE_FLAG_FLASH_FIRE))
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FLASH_FIRE_BOOST;
                        if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                            gBattlescriptCurrInstr = BattleScript_FlashFireBoost;
                        else
                            gBattlescriptCurrInstr = BattleScript_FlashFireBoost_PPLoss;

                        gBattleResources->flags->flags[battler] |= RESOURCE_FLAG_FLASH_FIRE;
                        effect = 3;
                        gMultiHitCounter = 0;
                    }
                    else
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FLASH_FIRE_NO_BOOST;
                        if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                            gBattlescriptCurrInstr = BattleScript_FlashFireBoost;
                        else
                            gBattlescriptCurrInstr = BattleScript_FlashFireBoost_PPLoss;

                        effect = 3;
                        gMultiHitCounter = 0;
                    }
                }
			}

            // Sap Sipper
			if(BattlerHasInnate(battler, ABILITY_SAP_SIPPER)){
				if (moveType == TYPE_GRASS){
                    effect = 2;
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_SAP_SIPPER;
                    statId = GetHighestAttackingStatId(battler, TRUE);
				}
			}

            // Ice Dew
			if(BattlerHasInnate(battler, ABILITY_ICE_DEW)){
				if (moveType == TYPE_ICE){
                    effect = 2;
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_ICE_DEW;
                    statId = GetHighestAttackingStatId(battler, TRUE);
				}
			}
			
			//Motor Drive
			if(BattlerHasInnate(battler, ABILITY_MOTOR_DRIVE)){
                if (moveType == TYPE_ELECTRIC){
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_MOTOR_DRIVE;
                    effect = 2, statId = STAT_SPEED;
                }
			}

            if (BATTLER_HAS_ABILITY(battler, ABILITY_WIND_RIDER)){
                if (gBattleMoves[move].flags2 & FLAG_AIR_BASED){
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_WIND_RIDER;
                    effect = 2;
                    statId = GetHighestAttackingStatId(battler, TRUE);
                }
            }
			
			//Motor Drive
			if(BATTLER_HAS_ABILITY(battler, ABILITY_JUSTIFIED)){
                if (moveType == TYPE_DARK){
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_JUSTIFIED;
                    effect = 2;
                    statId = GetHighestAttackingStatId(battler, TRUE);
                }
			}

            if (effect == 1) // Drain Hp ability.
            {
                if (BATTLER_MAX_HP(battler) || BATTLER_HEALING_BLOCKED(battler))
                {
                    if ((gProtectStructs[gBattlerAttacker].notFirstStrike))
                        gBattlescriptCurrInstr = BattleScript_MonMadeMoveUseless;
                    else
                        gBattlescriptCurrInstr = BattleScript_MonMadeMoveUseless_PPLoss;
                }
                else
                {
                    if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                        gBattlescriptCurrInstr = BattleScript_MoveHPDrain;
                    else
                        gBattlescriptCurrInstr = BattleScript_MoveHPDrain_PPLoss;

                    gBattleMoveDamage = gBattleMons[battler].maxHP / 4;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                    gMultiHitCounter = 0;
                }
            }
            else if (effect == 2) // Boost Stat ability;
            {
                if (!CompareStat(battler, statId, MAX_STAT_STAGE, CMP_LESS_THAN))
                {
                    if ((gProtectStructs[gBattlerAttacker].notFirstStrike))
                        gBattlescriptCurrInstr = BattleScript_MonMadeMoveUseless;
                    else
                        gBattlescriptCurrInstr = BattleScript_MonMadeMoveUseless_PPLoss;
                }
                else
                {
                    if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                        gBattlescriptCurrInstr = BattleScript_MoveStatDrain;
                    else
                        gBattlescriptCurrInstr = BattleScript_MoveStatDrain_PPLoss;

                    SET_STATCHANGER(statId, 1, FALSE);
                    gMultiHitCounter = 0;
                    ChangeStatBuffs(battler, StatBuffValue(1), statId, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
                    PREPARE_STAT_BUFFER(gBattleTextBuff1, statId);
                }
            }
        }
        break;
    case ABILITYEFFECT_MOVE_END: // Think contact abilities.
        switch (gLastUsedAbility)
        {
        case ABILITY_WELL_BAKED_BODY:
            if(IsBattlerAlive(battler)
                && (moveType == TYPE_FIRE)
                && CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                SET_STATCHANGER(STAT_DEF, 2, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
            break;
        case ABILITY_EVAPORATE:
            if (IsBattlerAlive(battler)
             && (moveType == TYPE_WATER))
            {
                if(TryChangeBattleTerrain(battler, STATUS_FIELD_MISTY_TERRAIN, &gFieldTimers.terrainTimer)){
                        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_EVAPORATE;
                        BattleScriptPushCursorAndCallback(BattleScript_MistySurgeActivates);
                        effect++;
                }
            }
            break;
        case ABILITY_FURNACE:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && moveType == TYPE_ROCK
             && CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                SET_STATCHANGER(STAT_SPEED, 2, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
            break;
        case ABILITY_RATTLED:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && (moveType == TYPE_DARK || moveType == TYPE_BUG || moveType == TYPE_GHOST)
             && CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                SET_STATCHANGER(STAT_SPEED, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
            break;
        case ABILITY_WATER_COMPACTION:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && moveType == TYPE_WATER
             && CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                SET_STATCHANGER(STAT_DEF, 2, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_WaterCompactionActivated;
                effect++;
            }
            break;
        case ABILITY_INFLATABLE:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && (CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN) || CompareStat(battler, STAT_SPDEF, MAX_STAT_STAGE, CMP_LESS_THAN))
			 && (moveType == TYPE_FIRE || moveType == TYPE_FLYING))
            {
                ChangeStatBuffs(battler, StatBuffValue(1), STAT_DEF, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
                ChangeStatBuffs(battler, StatBuffValue(1), STAT_SPDEF, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
				
                gBattleScripting.animArg1 = 14 + STAT_DEF;
                gBattleScripting.animArg2 = 0;
                BattleScriptPushCursorAndCallback(BattleScript_InflatableActivates);
                gBattleScripting.battler = battler;
                effect++;
            }
            break;
		case ABILITY_STAMINA: // changed ability
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) // new effect
             && gIsCriticalHit
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                SET_STATCHANGER(STAT_DEF, MAX_STAT_STAGE - gBattleMons[battler].statStages[STAT_DEF], FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetsStatWasMaxedOut;
                effect++;
            }
			else if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) // old effect
             && move != MOVE_SUBSTITUTE
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                SET_STATCHANGER(STAT_DEF, 1, FALSE);
                BattleScriptPushCursor();
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_STAMINA;
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
            break;
        case ABILITY_EMERGENCY_EXIT: // Doesn't work consistently
        case ABILITY_WIMP_OUT:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
            // Had more than half of hp before, now has less
             && gBattleStruct->hpBefore[battler] > gBattleMons[battler].maxHP / 2
             && gBattleMons[battler].hp < gBattleMons[battler].maxHP / 2
             && (gMultiHitCounter == 0 || gMultiHitCounter == 1)
             && !(TestSheerForceFlag(gBattlerAttacker, gCurrentMove))
             && (CanBattlerSwitch(battler) || !(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
             && !(gBattleTypeFlags & BATTLE_TYPE_ARENA)
             && CountUsablePartyMons(battler) > 0)
            {
                gBattleResources->flags->flags[battler] |= RESOURCE_FLAG_EMERGENCY_EXIT;
                effect++;
            }
            break;
        case ABILITY_WEAK_ARMOR:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && IS_MOVE_PHYSICAL(gCurrentMove)
             && (CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN) // Don't activate if speed cannot be raised
               || CompareStat(battler, STAT_DEF, MIN_STAT_STAGE, CMP_GREATER_THAN))) // Don't activate if defense cannot be lowered
            {
                if (gBattleMoves[gCurrentMove].effect == EFFECT_HIT_ESCAPE && CanBattlerSwitch(gBattlerAttacker))
                    gProtectStructs[battler].disableEjectPack = TRUE;  // Set flag for target

                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_WeakArmorActivates;
                effect++;
            }
            break;
        case ABILITY_CURSED_BODY:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && gDisableStructs[gBattlerAttacker].disabledMove == MOVE_NONE
             && IsBattlerAlive(gBattlerAttacker)
             && gBattlerAttacker != gBattlerTarget
             && gBattleMoves[move].split != SPLIT_STATUS
             && gBattleMoves[move].target != MOVE_TARGET_USER
             && !IsAbilityOnSide(gBattlerAttacker, ABILITY_AROMA_VEIL)
             && gBattleMons[gBattlerAttacker].pp[gChosenMovePos] != 0
             && (Random() % 100) < 30)
            {
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_CURSED_BODY;
                gDisableStructs[gBattlerAttacker].disabledMove = gChosenMove;
                gDisableStructs[gBattlerAttacker].disableTimer = 4;
                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gChosenMove);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_CursedBodyActivates;
                effect++;
            }
            break;
        case ABILITY_MUMMY:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerAlive(gBattlerAttacker)
             && TARGET_TURN_DAMAGED
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
                if (!IsUnsuppressableAbility(gBattleMons[gBattlerAttacker].ability))
                {
                    if (DoesBattlerHaveAbilityShield(gBattlerAttacker)) break;
                    UpdateAbilityStateIndicesForNewAbility(gBattlerAttacker, ABILITY_MUMMY);
                    gLastUsedAbility = gBattleMons[gBattlerAttacker].ability = ABILITY_MUMMY;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MummyActivates;
                    effect++;
                    break;
                }
            }
            break;
        case ABILITY_LINGERING_AROMA:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerAlive(gBattlerAttacker)
             && TARGET_TURN_DAMAGED
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
                if (!IsUnsuppressableAbility(gBattleMons[gBattlerAttacker].ability))
                {
                    if (DoesBattlerHaveAbilityShield(gBattlerAttacker)) break;
                    UpdateAbilityStateIndicesForNewAbility(gBattlerAttacker, ABILITY_LINGERING_AROMA);
                    gLastUsedAbility = gBattleMons[gBattlerAttacker].ability = ABILITY_LINGERING_AROMA;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MummyActivates;
                    effect++;
                    break;
                }
            }
            break;
        case ABILITY_WANDERING_SPIRIT:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerAlive(gBattlerAttacker)
             && TARGET_TURN_DAMAGED
             && (gBattleMoves[move].flags & FLAG_MAKES_CONTACT))
            {
                if (!IsUnsuppressableAbility(gBattleMons[gBattlerAttacker].ability))
                {
                    if (DoesBattlerHaveAbilityShield(gBattlerAttacker)) break;
                    if (DoesBattlerHaveAbilityShield(gBattlerTarget)) break;
                    gLastUsedAbility = gBattleMons[gBattlerAttacker].ability;
                    UpdateAbilityStateIndicesForNewAbility(gBattlerAttacker, ABILITY_WANDERING_SPIRIT);
                    UpdateAbilityStateIndicesForNewAbility(gBattlerTarget, gLastUsedAbility);
                    gBattleMons[gBattlerAttacker].ability = gBattleMons[gBattlerTarget].ability;
                    gBattleMons[gBattlerTarget].ability = gLastUsedAbility;
                    RecordAbilityBattle(gBattlerAttacker, gBattleMons[gBattlerAttacker].ability);
                    RecordAbilityBattle(gBattlerTarget, gBattleMons[gBattlerTarget].ability);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_WanderingSpiritActivates;
                    effect++;
                    break;
                }
            }
            break;
        case ABILITY_ANGER_POINT:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gIsCriticalHit
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                SET_STATCHANGER(STAT_ATK, MAX_STAT_STAGE - gBattleMons[battler].statStages[STAT_ATK], FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetsStatWasMaxedOut;
                effect++;
            }
			else if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && IS_MOVE_PHYSICAL(gCurrentMove)
             && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
				ChangeStatBuffs(battler, StatBuffValue(1), STAT_ATK, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
                gBattleScripting.animArg1 = 14 + STAT_ATK;
                gBattleScripting.animArg2 = 0;
                BattleScriptPushCursorAndCallback(BattleScript_AngerPointsLightBoostActivates);
                effect++;
            }
            break;
        case ABILITY_GOOEY:
        case ABILITY_TANGLING_HAIR:
        case ABILITY_SUPER_HOT_GOO:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && (CompareStat(gBattlerAttacker, STAT_SPEED, MIN_STAT_STAGE, CMP_GREATER_THAN) || 
			     GetBattlerAbility(gBattlerAttacker) == ABILITY_MIRROR_ARMOR || 
				 BattlerHasInnate(gBattlerAttacker, ABILITY_MIRROR_ARMOR))
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
                SET_STATCHANGER(STAT_SPEED, 1, TRUE);
                gBattleScripting.moveEffect = MOVE_EFFECT_SPD_MINUS_1;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_GooeyActivates;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
            break;
        case ABILITY_ROUGH_SKIN:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && !BATTLER_HAS_MAGIC_GUARD(gBattlerAttacker)
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
                #if B_ROUGH_SKIN_DMG >= GEN_4
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 8;
                #else
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 16;
                #endif
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_RoughSkinActivates;
                effect++;
            }
            break;
        case ABILITY_IRON_BARBS:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && !BATTLER_HAS_MAGIC_GUARD(gBattlerAttacker)
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
                #if B_ROUGH_SKIN_DMG >= GEN_4
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 8;
                #else
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 16;
                #endif
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_IronBarbsActivates;
                effect++;
            }
            break;
        case ABILITY_SOUL_LINKER:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
              && gBattleMons[gBattlerTarget].hp != 0
              && gBattleMons[gBattlerAttacker].hp != 0
              && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
              && move != MOVE_PAIN_SPLIT
              && gBattleMons[gBattlerAttacker].ability != ABILITY_SOUL_LINKER
              && !BattlerHasInnate(gBattlerAttacker, ABILITY_SOUL_LINKER)
              && gBattlerAttacker != gBattlerTarget
              //&& gBattleMoves[move].effect != EFFECT_ABSORB 
              && TARGET_TURN_DAMAGED)
            {
                //Defender
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AttackerSoulLinker;
                effect++;
            }
            break;
        case ABILITY_AFTERMATH:
            if (!IsAbilityOnField(ABILITY_DAMP)
             && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp == 0
             && IsBattlerAlive(gBattlerAttacker)
             && IsMoveMakingContact(move, gBattlerAttacker)
             && !BATTLER_HAS_MAGIC_GUARD(gBattlerAttacker))
            {
                gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 4;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AftermathDmg;
                effect++;
            }
            break;
		case ABILITY_HAUNTED_SPIRIT:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp == 0
		     && !IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GHOST)
             && IsBattlerAlive(gBattlerAttacker)
			 && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_CURSED)
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_HAUNTED_SPIRIT;
				gBattleMons[gBattlerAttacker].status2 |= STATUS2_CURSED;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_HauntedSpiritActivated;
                effect++;
            }
            break;
        case ABILITY_INNARDS_OUT:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp == 0
             && IsBattlerAlive(gBattlerAttacker)
             && !BATTLER_HAS_MAGIC_GUARD(gBattlerAttacker))
            {
                gBattleMoveDamage = gSpecialStatuses[gBattlerTarget].dmg;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AftermathDmg;
                effect++;
            }
            break;
        case ABILITY_PRIM_AND_PROPER:
        case ABILITY_CUTE_CHARM:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && IsMoveMakingContact(move, gBattlerAttacker)
             && TARGET_TURN_DAMAGED
             && gBattleMons[gBattlerTarget].hp != 0
             && (Random() % 100) < 30
             && GetBattlerAbility(gBattlerAttacker) != ABILITY_OBLIVIOUS
			 && !BattlerHasInnate(gBattlerAttacker, ABILITY_OBLIVIOUS)
             && !IsAbilityOnSide(gBattlerAttacker, ABILITY_AROMA_VEIL)
             && GetGenderFromSpeciesAndPersonality(speciesAtk, pidAtk) != GetGenderFromSpeciesAndPersonality(speciesDef, pidDef)
             && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_INFATUATION)
             && GetGenderFromSpeciesAndPersonality(speciesAtk, pidAtk) != MON_GENDERLESS
             && GetGenderFromSpeciesAndPersonality(speciesDef, pidDef) != MON_GENDERLESS)
            {
                gBattleMons[gBattlerAttacker].status2 |= STATUS2_INFATUATED_WITH(gBattlerTarget);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_CuteCharmActivates;
                effect++;
            }
            break;
        case ABILITY_ILLUSION:
            if (gBattleStruct->illusion[gBattlerTarget].on && !gBattleStruct->illusion[gBattlerTarget].broken && TARGET_TURN_DAMAGED)
            {
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_IllusionOff;
                effect++;
            }
            break;
        case ABILITY_COTTON_DOWN:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && IsBattlerAlive(gBattlerAttacker)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && gBattlerAttacker != gBattlerTarget
             && TARGET_TURN_DAMAGED)
            {
                gEffectBattler = gBattlerTarget;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_CottonDownActivates;
                effect++;
            }
            break;
        case ABILITY_STEAM_ENGINE:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN)
             && (moveType == TYPE_FIRE || moveType == TYPE_WATER))
            {
                SET_STATCHANGER(STAT_SPEED, 6, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
            break;
        case ABILITY_SAND_SPIT:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && !(gBattleWeather & B_WEATHER_SANDSTORM && WEATHER_HAS_EFFECT))
            {
                if (gBattleWeather & B_WEATHER_PRIMAL_ANY && WEATHER_HAS_EFFECT)
                {
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BlockedByPrimalWeatherRet;
                    effect++;
                }
                else if (TryChangeBattleWeather(battler, ENUM_WEATHER_SANDSTORM, TRUE))
                {
                    gBattleScripting.battler = gActiveBattler = battler;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_SandSpitActivates;
                    effect++;
                }
            }
            break;
        case ABILITY_PERISH_BODY:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && IsMoveMakingContact(move, gBattlerAttacker)
             && !(gStatuses3[gBattlerAttacker] & STATUS3_PERISH_SONG))
            {
                if (!(gStatuses3[battler] & STATUS3_PERISH_SONG))
                {
                    gStatuses3[battler] |= STATUS3_PERISH_SONG;
                    gDisableStructs[battler].perishSongTimer = 3;
                    gDisableStructs[battler].perishSongTimerStartValue = 3;
                }
                gStatuses3[gBattlerAttacker] |= STATUS3_PERISH_SONG;
                gDisableStructs[gBattlerAttacker].perishSongTimer = 3;
                gDisableStructs[gBattlerAttacker].perishSongTimerStartValue = 3;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_PerishBodyActivates;
                effect++;
            }
            break;
        case ABILITY_GULP_MISSILE:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler))
            {
                if (gBattleMons[gBattlerTarget].species == SPECIES_CRAMORANT_GORGING)
                {
                    gBattleStruct->changedSpecies[gBattlerPartyIndexes[gBattlerTarget]] = gBattleMons[gBattlerTarget].species;
                    UpdateAbilityStateIndicesForNewSpecies(gActiveBattler, SPECIES_CRAMORANT);
                    gBattleMons[gBattlerTarget].species = SPECIES_CRAMORANT;
                    if (!BATTLER_HAS_MAGIC_GUARD(gBattlerAttacker))
                    {
                        gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 4;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                    }
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_GulpMissileGorging;
                    effect++;
                }
                else if (gBattleMons[gBattlerTarget].species == SPECIES_CRAMORANT_GULPING)
                {
                    gBattleStruct->changedSpecies[gBattlerPartyIndexes[gBattlerTarget]] = gBattleMons[gBattlerTarget].species;
                    UpdateAbilityStateIndicesForNewSpecies(gActiveBattler, SPECIES_CRAMORANT);
                    gBattleMons[gBattlerTarget].species = SPECIES_CRAMORANT;
                    if (!BATTLER_HAS_MAGIC_GUARD(gBattlerAttacker))
                    {
                        gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 4;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                    }
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_GulpMissileGulping;
                    effect++;
                }
            }
            break;
        }
		
		// Thermal Exchange
        if(BATTLER_HAS_ABILITY(battler, ABILITY_THERMAL_EXCHANGE)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && moveType == TYPE_FIRE
             && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_THERMAL_EXCHANGE;
                SET_STATCHANGER(STAT_ATK, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
        }

        //Furnace
        if(BattlerHasInnate(battler, ABILITY_FURNACE)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && moveType == TYPE_ROCK
             && CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_FURNACE;
                SET_STATCHANGER(STAT_SPEED, 2, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
        }
        //Well Baked Body
        if(BattlerHasInnate(battler, ABILITY_WELL_BAKED_BODY)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && moveType == TYPE_FIRE
             && CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_WELL_BAKED_BODY;
                SET_STATCHANGER(STAT_DEF, 2, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
        }


        //Furnace
        if(BATTLER_HAS_ABILITY(battler, ABILITY_FURNACE)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && moveType == TYPE_ROCK
             && CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_FURNACE;
                SET_STATCHANGER(STAT_SPEED, 2, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
        }

        //Evaporate
        if(BATTLER_HAS_ABILITY(battler, ABILITY_EVAPORATE)){
            if (IsBattlerAlive(battler)
             && (moveType == TYPE_WATER))
            {
                if(TryChangeBattleTerrain(battler, STATUS_FIELD_MISTY_TERRAIN, &gFieldTimers.terrainTimer)){
                        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_EVAPORATE;
                        BattleScriptPushCursorAndCallback(BattleScript_MistySurgeActivates);
                        effect++;
                }
            }
        }

        //Well Baked Body
        if(BATTLER_HAS_ABILITY(battler, ABILITY_WELL_BAKED_BODY)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && moveType == TYPE_FIRE
             && CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_WELL_BAKED_BODY;
                SET_STATCHANGER(STAT_DEF, 2, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
        }

        // Innates
        // Loose Rocks
        if (BATTLER_HAS_ABILITY(battler, ABILITY_LOOSE_ROCKS)) {
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0 
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && IsMoveMakingContact(move, gBattlerAttacker)
             && !(gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_STEALTH_ROCK)) {
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_LOOSE_ROCKS;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_DefenderSetsStealthRock;
                effect++;
            }
        }

        //Furnace
        if(BATTLER_HAS_ABILITY(battler, ABILITY_WIND_POWER)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && gBattleMoves[move].flags2 & FLAG_AIR_BASED
             && !(gStatuses3[gBattlerTarget] & STATUS3_CHARGED_UP))
            {
                gStatuses3[gBattlerTarget] |= STATUS3_CHARGED_UP; 
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_WIND_POWER;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_ElectromorphosisActivates;
                effect++;
            }
        }

        // Electromorphosis
        if (BATTLER_HAS_ABILITY(battler, ABILITY_ELECTROMORPHOSIS)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0 
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && !(gStatuses3[gBattlerTarget] & STATUS3_CHARGED_UP)){
                gStatuses3[gBattlerTarget] |= STATUS3_CHARGED_UP; 
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_ELECTROMORPHOSIS;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_ElectromorphosisActivates;
                effect++;
            }
        }

        //Rough Skin
        if(BattlerHasInnate(battler, ABILITY_ROUGH_SKIN)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && !BATTLER_HAS_MAGIC_GUARD(gBattlerAttacker)
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
                gBattleScripting.abilityPopupOverwrite = ABILITY_ROUGH_SKIN;
				gLastUsedAbility = ABILITY_ROUGH_SKIN;

                #if B_ROUGH_SKIN_DMG >= GEN_4
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 8;
                #else
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 16;
                #endif
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_RoughSkinActivates;
                effect++;
            }
        }

        //Iron Barbs
        if(BattlerHasInnate(battler, ABILITY_IRON_BARBS)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && !BATTLER_HAS_MAGIC_GUARD(gBattlerAttacker)
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
                gBattleScripting.abilityPopupOverwrite = ABILITY_IRON_BARBS;
				gLastUsedAbility = ABILITY_IRON_BARBS;

                #if B_ROUGH_SKIN_DMG >= GEN_4
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 8;
                #else
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 16;
                #endif
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_IronBarbsActivates;
                effect++;
            }
        }

        //Iron Barbs
        if(BATTLER_HAS_ABILITY(battler, ABILITY_DOUBLE_IRON_BARBS)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && !BATTLER_HAS_MAGIC_GUARD(gBattlerAttacker)
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_DOUBLE_IRON_BARBS;

                gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 6;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_IronBarbsActivates;
                effect++;
            }
        }

		// Rattled
        if(BattlerHasInnate(battler, ABILITY_RATTLED)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && (moveType == TYPE_DARK || moveType == TYPE_BUG || moveType == TYPE_GHOST)
             && CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_RATTLED;
                SET_STATCHANGER(STAT_SPEED, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
        }
        
        // Cursed Body
		if(BattlerHasInnate(battler, ABILITY_CURSED_BODY)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && gDisableStructs[gBattlerAttacker].disabledMove == MOVE_NONE
             && IsBattlerAlive(gBattlerAttacker)
             && gBattlerAttacker != gBattlerTarget
             && gBattleMoves[move].split != SPLIT_STATUS
             && gBattleMoves[move].target != MOVE_TARGET_USER
             && !IsAbilityOnSide(gBattlerAttacker, ABILITY_AROMA_VEIL)
             && gBattleMons[gBattlerAttacker].pp[gChosenMovePos] != 0
             && (Random() % 100) < 30)
            {
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_CURSED_BODY;
                gDisableStructs[gBattlerAttacker].disabledMove = gChosenMove;
                gDisableStructs[gBattlerAttacker].disableTimer = 4;
                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gChosenMove);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_CursedBodyActivates;
                effect++;
            }
        }
        
        // Cursed Body
		if(BATTLER_HAS_ABILITY(battler, ABILITY_SPITEFUL)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && move != MOVE_STRUGGLE
             && IsBattlerAlive(gBattlerAttacker)
             && gBattlerAttacker != gBattlerTarget
             && IsMoveMakingContact(move, gBattlerAttacker)
             && gBattleMons[gBattlerAttacker].pp[gChosenMovePos] != 0)
            {
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_SPITEFUL;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilitySpiteful;
                effect++;
            }
        }
		
		// Soul Linker Defender
		if(BattlerHasInnate(battler, ABILITY_SOUL_LINKER)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
              && gBattleMons[gBattlerTarget].hp != 0
              && gBattleMons[gBattlerAttacker].hp != 0
              && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
              && move != MOVE_PAIN_SPLIT
              && gBattleMons[gBattlerAttacker].ability != ABILITY_SOUL_LINKER
              && !BattlerHasInnate(gBattlerAttacker, ABILITY_SOUL_LINKER)
              && gBattlerAttacker != gBattlerTarget
              //&& gBattleMoves[move].effect != EFFECT_ABSORB 
              && TARGET_TURN_DAMAGED)
            {
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_SOUL_LINKER;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AttackerSoulLinker;
                effect++;
            }
        }
		
		// Cotton Down
		if(BattlerHasInnate(battler, ABILITY_COTTON_DOWN)){
			if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && IsBattlerAlive(gBattlerAttacker)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && gBattlerAttacker != gBattlerTarget
             && TARGET_TURN_DAMAGED)
            {
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_COTTON_DOWN;
                gEffectBattler = gBattlerTarget;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_CottonDownActivates;
                effect++;
            }
		}
			
		// Steam Engine
		if(BattlerHasInnate(battler, ABILITY_STEAM_ENGINE)){
			if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN)
             && (moveType == TYPE_FIRE || moveType == TYPE_WATER))
            {
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_STEAM_ENGINE;
                SET_STATCHANGER(STAT_SPEED, 6, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
		}
		
		// Sand Spit
		if(BattlerHasInnate(battler, ABILITY_SAND_SPIT)){
			if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && !(gBattleWeather & B_WEATHER_SANDSTORM && WEATHER_HAS_EFFECT))
            {
                if (gBattleWeather & B_WEATHER_PRIMAL_ANY && WEATHER_HAS_EFFECT)
                {
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BlockedByPrimalWeatherRet;
                    effect++;
                }
                else if (TryChangeBattleWeather(battler, ENUM_WEATHER_SANDSTORM, TRUE))
                {
                    gBattleScripting.battler = gActiveBattler = battler;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_SandSpitActivates;
                    effect++;
                }
			}
		}
		
		// Cryo Proficiency
		if(BATTLER_HAS_ABILITY(battler, ABILITY_CRYO_PROFICIENCY)){
			if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && !(gBattleWeather & WEATHER_HAIL_ANY && WEATHER_HAS_EFFECT))
            {
                if (gBattleWeather & B_WEATHER_PRIMAL_ANY && WEATHER_HAS_EFFECT)
                {
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BlockedByPrimalWeatherRet;
                    effect++;
                }
                else if (TryChangeBattleWeather(battler, ENUM_WEATHER_HAIL, TRUE))
                {
                    gBattleScripting.battler = gActiveBattler = battler;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_CryoProficiencyActivates;
                    effect++;
                }
			}
		}
		
		// Perish Body
		if(BattlerHasInnate(battler, ABILITY_PERISH_BODY)){
			if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && IsMoveMakingContact(move, gBattlerAttacker)
             && !(gStatuses3[gBattlerAttacker] & STATUS3_PERISH_SONG))
            {
                if (!(gStatuses3[battler] & STATUS3_PERISH_SONG))
                {
                    gStatuses3[battler] |= STATUS3_PERISH_SONG;
                    gDisableStructs[battler].perishSongTimer = 3;
                    gDisableStructs[battler].perishSongTimerStartValue = 3;
                }
                gStatuses3[gBattlerAttacker] |= STATUS3_PERISH_SONG;
                gDisableStructs[gBattlerAttacker].perishSongTimer = 3;
                gDisableStructs[gBattlerAttacker].perishSongTimerStartValue = 3;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_PerishBodyActivates;
                effect++;
            }
		}
		
		// Aftermath
		if(BattlerHasInnate(battler, ABILITY_AFTERMATH)){
            if (!IsAbilityOnField(ABILITY_DAMP)
             && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp == 0
             && IsBattlerAlive(gBattlerAttacker)
             && IsMoveMakingContact(move, gBattlerAttacker)
             && !BATTLER_HAS_MAGIC_GUARD(gBattlerAttacker))
            {
                gBattleScripting.abilityPopupOverwrite = ABILITY_AFTERMATH;
				gLastUsedAbility = ABILITY_AFTERMATH;
                gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 4;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AftermathDmg;
                effect++;
            }
        }
		
		// Guilt Trip
		if(BATTLER_HAS_ABILITY(battler, ABILITY_GUILT_TRIP)){
            if (ShouldApplyOnHitAffect(gBattlerAttacker)
                && (CompareStat(gBattlerAttacker, STAT_ATK, MIN_STAT_STAGE, CMP_GREATER_THAN)
                    || CompareStat(gBattlerAttacker, STAT_SPATK, MIN_STAT_STAGE, CMP_GREATER_THAN)))
            {
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_GUILT_TRIP;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_GuiltTrip;
                effect++;
            }
        }

        if (BATTLER_HAS_ABILITY(battler, ABILITY_ILL_WILL))
        {
            u8 moveIndex = gBattleStruct->chosenMovePositions[gBattlerAttacker];
            if (ShouldApplyOnHitAffect(gBattlerAttacker)
                && !IsBattlerAlive(battler)
                && gBattleMons[gBattlerAttacker].pp[moveIndex]
                && gCurrentMove != MOVE_STRUGGLE)
            {
                gBattleMons[gBattlerAttacker].pp[moveIndex] = 0;
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_ILL_WILL;
                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleMons[gBattlerAttacker].moves[moveIndex])
                BtlController_EmitSetMonData(0, moveIndex + REQUEST_PPMOVE1_BATTLE, 0, 1, &gBattleMons[gActiveBattler].pp[moveIndex]);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_IllWillTakesPp;
                effect++;
            }
        }
		
		// Innards Out
		if(BattlerHasInnate(battler, ABILITY_INNARDS_OUT)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp == 0
             && IsBattlerAlive(gBattlerAttacker)
             && !BATTLER_HAS_MAGIC_GUARD(gBattlerAttacker))
            {
                gBattleMoveDamage = gSpecialStatuses[gBattlerTarget].dmg;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AftermathDmg;
                effect++;
            }
		}
		
		// Effect Spore
		if(BATTLER_HAS_ABILITY(battler, ABILITY_EFFECT_SPORE)){
            EFFECT_SPORE:
            if (!IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GRASS)
             && GetBattlerAbility(gBattlerAttacker) != ABILITY_OVERCOAT
			 && !BattlerHasInnate(gBattlerAttacker, ABILITY_OVERCOAT)
             && GetBattlerAbility(gBattlerAttacker) != ABILITY_EFFECT_SPORE
             && !BattlerHasInnate(gBattlerAttacker, ABILITY_EFFECT_SPORE)
             && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_SAFETY_GOGGLES)
            {
                i = Random() % 3;
                if (i == 0){
                    //Poison Damage
                    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                    && gBattleMons[gBattlerAttacker].hp != 0
                    && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
                    && TARGET_TURN_DAMAGED
                    && CanBePoisoned(gBattlerAttacker, gBattlerTarget)
                    && IsMoveMakingContact(move, gBattlerAttacker)
                    && (Random() % 100) < 30)
                    {
                        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_EFFECT_SPORE;
                        gBattleScripting.moveEffect = MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_POISON;
                        PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                        gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                        effect++;
                    }
                }
                else if (i == 1){
                    //Paralyze
                    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                    && gBattleMons[gBattlerAttacker].hp != 0
                    && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
                    && TARGET_TURN_DAMAGED
                    && CanBeParalyzed(gBattlerAttacker, gBattlerTarget)
                    && IsMoveMakingContact(move, gBattlerAttacker)
                    && (Random() % 100) < 30)
                    {
                        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_EFFECT_SPORE;
                        gBattleScripting.moveEffect = MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_PARALYSIS;
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                        gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                        effect++;
                    }
                }
                else{
                    // Sleep
                    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                    && gBattleMons[gBattlerAttacker].hp != 0
                    && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
                    && TARGET_TURN_DAMAGED
                    && CanSleep(gBattlerAttacker)
                    && IsMoveMakingContact(move, gBattlerAttacker)
                    && !IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GRASS)
                    && (Random() % 100) < 30)
                    {
                        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_EFFECT_SPORE;
                        gBattleScripting.moveEffect = MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_SLEEP;
                        PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                        gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                        effect++;
                    }
                }
            }
        }
		
		// Inflatable
		if(BattlerHasInnate(battler, ABILITY_INFLATABLE)){
			if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
			 && TARGET_TURN_DAMAGED
			 && IsBattlerAlive(battler)
			 && (CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN) || CompareStat(battler, STAT_SPDEF, MAX_STAT_STAGE, CMP_LESS_THAN))
			 && (moveType == TYPE_FIRE || moveType == TYPE_FLYING))
			{
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_INFLATABLE;
				
				ChangeStatBuffs(battler, StatBuffValue(1), STAT_DEF, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
                ChangeStatBuffs(battler, StatBuffValue(1), STAT_SPDEF, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
				
				gBattleScripting.animArg1 = 14 + STAT_DEF;
				gBattleScripting.animArg2 = 0;
				BattleScriptPushCursorAndCallback(BattleScript_InflatableActivates);
				gBattleScripting.battler = battler;
				effect++;
			}
		}

        
		// Water Compaction
		if(BattlerHasInnate(battler, ABILITY_WATER_COMPACTION)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && moveType == TYPE_WATER
             && CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_WATER_COMPACTION;
                SET_STATCHANGER(STAT_DEF, 2, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_WaterCompactionActivated;
                effect++;
            }
        }
		
		//Haunted Spirit
		if(BATTLER_HAS_ABILITY(battler, ABILITY_VENGEFUL_SPIRIT)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp == 0
		     && !IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GHOST)
             && IsBattlerAlive(gBattlerAttacker)
			 && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_CURSED)
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_VENGEFUL_SPIRIT;
				gBattleMons[gBattlerAttacker].status2 |= STATUS2_CURSED;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_HauntedSpiritActivated;
                effect++;
            }
		}
		
		//Haunted Spirit
		if(BattlerHasInnate(battler, ABILITY_HAUNTED_SPIRIT)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp == 0
		     && !IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GHOST)
             && IsBattlerAlive(gBattlerAttacker)
			 && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_CURSED)
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_HAUNTED_SPIRIT;
				gBattleMons[gBattlerAttacker].status2 |= STATUS2_CURSED;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_HauntedSpiritActivated;
                effect++;
            }
		}
		
		//Magical Dust
		if(BATTLER_HAS_ABILITY(battler, ABILITY_MAGICAL_DUST)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && IsMoveMakingContact(move, gBattlerAttacker)
             && TARGET_TURN_DAMAGED
			 && !IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_PSYCHIC))
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_MAGICAL_DUST;
				gBattleMons[gBattlerAttacker].type3 = TYPE_PSYCHIC;
				PREPARE_TYPE_BUFFER(gBattleTextBuff1, gBattleMons[gBattlerAttacker].type3);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AttackerBecameTheType;
				effect++;
            }
		}
		
		//Damp
		if(BATTLER_HAS_ABILITY(battler, ABILITY_DAMP)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && IsMoveMakingContact(move, gBattlerAttacker)
             && TARGET_TURN_DAMAGED
			 && !IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_WATER))
            {
                u8 newtype = TYPE_WATER;
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_DAMP;
				gBattleMons[gBattlerAttacker].type1 = newtype;
				gBattleMons[gBattlerAttacker].type2 = newtype;
				gBattleMons[gBattlerAttacker].type3 = TYPE_MYSTERY;
				PREPARE_TYPE_BUFFER(gBattleTextBuff1, newtype);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AttackerBecameTheTypeFull;
				effect++;
            }
		}
		
		// Stamina
		if(BattlerHasInnate(battler, ABILITY_STAMINA)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) // new effect
             && gIsCriticalHit
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_STAMINA;
                SET_STATCHANGER(STAT_DEF, MAX_STAT_STAGE - gBattleMons[battler].statStages[STAT_DEF], FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetsStatWasMaxedOut;
                effect++;
            }
			else if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) // old effect
             && move != MOVE_SUBSTITUTE
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_STAMINA;
                SET_STATCHANGER(STAT_DEF, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
		}
		
		// Crowned Shield
		if(BATTLER_HAS_ABILITY(battler, ABILITY_CROWNED_SHIELD)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) // new effect
             && gIsCriticalHit
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_CROWNED_SHIELD;
                SET_STATCHANGER(STAT_DEF, MAX_STAT_STAGE - gBattleMons[battler].statStages[STAT_DEF], FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetsStatWasMaxedOut;
                effect++;
            }
			else if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) // old effect
             && move != MOVE_SUBSTITUTE
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_CROWNED_SHIELD;
                SET_STATCHANGER(STAT_DEF, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
		}
		
		// Fortitude
		if(BATTLER_HAS_ABILITY(battler, ABILITY_FORTITUDE)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) // new effect
             && gIsCriticalHit
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_SPDEF, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_FORTITUDE;
                SET_STATCHANGER(STAT_SPDEF, MAX_STAT_STAGE - gBattleMons[battler].statStages[STAT_SPDEF], FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetsStatWasMaxedOut;
                effect++;
            }
			else if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) // old effect
             && move != MOVE_SUBSTITUTE
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_SPDEF, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_FORTITUDE;
                SET_STATCHANGER(STAT_SPDEF, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
		}
		
		// Anger Point
		if(BattlerHasInnate(battler, ABILITY_ANGER_POINT)){
			if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gIsCriticalHit
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_ANGER_POINT;
                SET_STATCHANGER(STAT_ATK, MAX_STAT_STAGE - gBattleMons[battler].statStages[STAT_ATK], FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetsStatWasMaxedOut;
                effect++;
            }
			else if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && IS_MOVE_PHYSICAL(gCurrentMove)
             && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
			{
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_ANGER_POINT;
				PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
				BattleScriptPushCursor();
				ChangeStatBuffs(battler, StatBuffValue(1), STAT_ATK, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
				gBattleScripting.animArg1 = 14 + STAT_ATK;
				gBattleScripting.animArg2 = 0;
				BattleScriptPushCursorAndCallback(BattleScript_AngerPointsLightBoostActivates);
				effect++;
			}
		}
		
		// Crowned Sword
		if(BATTLER_HAS_ABILITY(battler, ABILITY_CROWNED_SWORD)){
			if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gIsCriticalHit
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_CROWNED_SWORD;
                SET_STATCHANGER(STAT_ATK, MAX_STAT_STAGE - gBattleMons[battler].statStages[STAT_ATK], FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetsStatWasMaxedOut;
                effect++;
            }
			else if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && IS_MOVE_SPECIAL(gCurrentMove)
             && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
			{
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_CROWNED_SWORD;
				PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
				BattleScriptPushCursor();
				ChangeStatBuffs(battler, StatBuffValue(1), STAT_ATK, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
				gBattleScripting.animArg1 = 14 + STAT_ATK;
				gBattleScripting.animArg2 = 0;
				BattleScriptPushCursorAndCallback(BattleScript_AngerPointsLightBoostActivates);
				effect++;
			}
		}
		
		// Tipping Point
		if(BATTLER_HAS_ABILITY(battler, ABILITY_TIPPING_POINT)){
			if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gIsCriticalHit
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_TIPPING_POINT;
                SET_STATCHANGER(STAT_SPATK, MAX_STAT_STAGE - gBattleMons[battler].statStages[STAT_SPATK], FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetsStatWasMaxedOut;
                effect++;
            }
			else if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && IS_MOVE_SPECIAL(gCurrentMove)
             && CompareStat(battler, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN))
			{
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_TIPPING_POINT;
				PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
				BattleScriptPushCursor();
				ChangeStatBuffs(battler, StatBuffValue(1), STAT_SPATK, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
				gBattleScripting.animArg1 = 14 + STAT_SPATK;
				gBattleScripting.animArg2 = 0;
				BattleScriptPushCursorAndCallback(BattleScript_AngerPointsLightBoostActivates);
				effect++;
			}
		}

		// Static (Defender)

        if (BATTLER_HAS_ABILITY(battler, ABILITY_BERSERK) || BATTLER_HAS_ABILITY(battler, ABILITY_BERSERKER_RAGE)) {
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
            // Had more than half of hp before, now has less
             && gBattleStruct->hpBefore[battler] > gBattleMons[battler].maxHP / 2
             && gBattleMons[battler].hp < gBattleMons[battler].maxHP / 2
             && (gMultiHitCounter == 0 || gMultiHitCounter == 1)
             && !(TestSheerForceFlag(gBattlerAttacker, gCurrentMove))
             && CompareStat(battler, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = BATTLER_HAS_ABILITY(battler, ABILITY_BERSERK) ? ABILITY_BERSERK : ABILITY_BERSERKER_RAGE;
                SET_STATCHANGER(STAT_SPATK, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseOnMoveEnd;
                effect++;
            }
        }

        if (BATTLER_HAS_ABILITY(battler, ABILITY_ANGER_SHELL)) {
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
            // Had more than half of hp before, now has less
             && gBattleStruct->hpBefore[battler] > gBattleMons[battler].maxHP / 2
             && gBattleMons[battler].hp < gBattleMons[battler].maxHP / 2
             && (gMultiHitCounter == 0 || gMultiHitCounter == 1)
             && !(TestSheerForceFlag(gBattlerAttacker, gCurrentMove))
             && CompareStat(battler, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_ANGER_SHELL;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AngerShell;
                effect++;
            }
        }

        //Itchy Defense
        if(BATTLER_HAS_ABILITY(battler, ABILITY_ITCHY_DEFENSE)){
            bool8 activateAbilty = FALSE;
            u16 abilityToCheck = ABILITY_ITCHY_DEFENSE; //For easier copypaste
            //Target and Attacker are swapped because this is the defender's ability
            //battler = attacker, gBattlerAttacker = defender

            //Checks if the ability is triggered
            if(!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
            && gBattleMons[gBattlerAttacker].hp != 0
            && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
            && IsMoveMakingContact(move, battler)
            && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_WRAPPED)
            && battler != gBattlerAttacker
            && TARGET_TURN_DAMAGED)
            {
                u16 extraMove = MOVE_INFESTATION;
                gBattleMons[gBattlerAttacker].status2 |= STATUS2_WRAPPED;
                if (GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_GRIP_CLAW)
                    gDisableStructs[gBattlerAttacker].wrapTurns = (B_BINDING_TURNS >= GEN_5) ? 7 : 5;
                else
                    gDisableStructs[gBattlerAttacker].wrapTurns = (B_BINDING_TURNS >= GEN_5) ? ((Random() % 2) + 4) : ((Random() % 4) + 2);
                gBattleStruct->wrappedMove[gBattlerAttacker] = extraMove;
                gBattleStruct->wrappedBy[gBattlerAttacker] = battler;
                    
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AttackerBecameInfested;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
        }

        //Atomic Burst
        if(BATTLER_HAS_ABILITY(battler, ABILITY_ATOMIC_BURST)){
            bool8 activateAbilty = FALSE;
            u16 abilityToCheck = ABILITY_ATOMIC_BURST; //For easier copypaste
            //Target and Attacker are swapped because this is the defender's ability
            //battler = attacker, gBattlerAttacker = defender

            //Checks if the ability is triggered
            if(!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)       &&
                !gRetaliationInProgress                          &&
                CanUseExtraMove(battler, gBattlerAttacker)       && //gBattlerAttacer is the target in this instance
                (gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE) &&
                TARGET_TURN_DAMAGED){
                activateAbilty = TRUE;
            }

            //This is the stuff that has to be changed for each ability
            if(activateAbilty){
                u16 extraMove = MOVE_HYPER_BEAM;  //The Extra Move to be used
                u8 movePower = 50;                //The Move power, leave at 0 if you want it to be the same as the normal move
                u8 moveEffectPercentChance  = 0;  //The percent chance of the move effect happening
                u8 extraMoveSecondaryEffect = 0;  //Leave at 0 to remove it's secondary effect
                gTempMove = gCurrentMove;
                gCurrentMove = extraMove;
                gProtectStructs[battler].extraMoveUsed = TRUE;

                //Move Effect
                VarSet(VAR_EXTRA_MOVE_DAMAGE,     movePower);
                VarSet(VAR_TEMP_MOVEEFECT_CHANCE, moveEffectPercentChance);
                VarSet(VAR_TEMP_MOVEEFFECT,       extraMoveSecondaryEffect);

                //If the ability is an innate overwrite the popout
                if(BattlerHasInnate(battler, abilityToCheck))
                    gBattleScripting.abilityPopupOverwrite = abilityToCheck;

                BattleScriptPushCursorAndCallback(BattleScript_DefenderUsedAnExtraMove);
                effect++;
            }
        }

        //Cold Rebound
        if(BATTLER_HAS_ABILITY(battler, ABILITY_COLD_REBOUND)){
            bool8 activateAbilty = FALSE;
            u16 abilityToCheck = ABILITY_COLD_REBOUND; //For easier copypaste
            //Target and Attacker are swapped because this is the defender's ability
            //battler = attacker, gBattlerAttacker = defender

            //Checks if the ability is triggered
            if(!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)  &&
                !gRetaliationInProgress                     &&
                CanUseExtraMove(battler, gBattlerAttacker)  && //gBattlerAttacer is the target in this instance
                IsMoveMakingContact(move, gBattlerAttacker) &&
                TARGET_TURN_DAMAGED){
                activateAbilty = TRUE;
            }

            //This is the stuff that has to be changed for each ability
            if(activateAbilty){
                u16 extraMove = MOVE_ICY_WIND;     //The Extra Move to be used
                u8 movePower = 0;                  //The Move power, leave at 0 if you want it to be the same as the normal move
                u8 moveEffectPercentChance  = 100; //The percent chance of the move effect happening
                u8 extraMoveSecondaryEffect = MOVE_EFFECT_SPD_MINUS_1; //Leave at 0 to remove it's secondary effect
                gTempMove = gCurrentMove;
                gCurrentMove = extraMove;
                gProtectStructs[battler].extraMoveUsed = TRUE;

                //Move Effect
                VarSet(VAR_EXTRA_MOVE_DAMAGE,     movePower);
                VarSet(VAR_TEMP_MOVEEFECT_CHANCE, moveEffectPercentChance);
                VarSet(VAR_TEMP_MOVEEFFECT,       extraMoveSecondaryEffect);

                //If the ability is an innate overwrite the popout
                if(BattlerHasInnate(battler, abilityToCheck))
                    gBattleScripting.abilityPopupOverwrite = abilityToCheck;

                BattleScriptPushCursorAndCallback(BattleScript_DefenderUsedAnExtraMove);
                effect++;
            }
        }

        //Parry
        if(BATTLER_HAS_ABILITY(battler, ABILITY_PARRY)){
            bool8 activateAbilty = FALSE;
            u16 abilityToCheck = ABILITY_PARRY; //For easier copypaste
            //Target and Attacker are swapped because this is the defender's ability
            //battler = attacker, gBattlerAttacker = defender

            //Checks if the ability is triggered
            if(!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)  &&
                !gRetaliationInProgress                     &&
                CanUseExtraMove(battler, gBattlerAttacker)  && //gBattlerAttacer is the target in this instance
                IsMoveMakingContact(move, gBattlerAttacker) &&
                TARGET_TURN_DAMAGED){
                activateAbilty = TRUE;
            }

            //This is the stuff that has to be changed for each ability
            if(activateAbilty){
                u16 extraMove = MOVE_MACH_PUNCH;  //The Extra Move to be used
                u8 movePower = 0;                 //The Move power, leave at 0 if you want it to be the same as the normal move
                u8 moveEffectPercentChance  = 0;  //The percent chance of the move effect happening
                u8 extraMoveSecondaryEffect = 0;  //Leave at 0 to remove it's secondary effect
                gTempMove = gCurrentMove;
                gCurrentMove = extraMove;
                gProtectStructs[battler].extraMoveUsed = TRUE;

                //Move Effect
                VarSet(VAR_EXTRA_MOVE_DAMAGE,     movePower);
                VarSet(VAR_TEMP_MOVEEFECT_CHANCE, moveEffectPercentChance);
                VarSet(VAR_TEMP_MOVEEFFECT,       extraMoveSecondaryEffect);

                //If the ability is an innate overwrite the popout
                if(BattlerHasInnate(battler, abilityToCheck))
                    gBattleScripting.abilityPopupOverwrite = abilityToCheck;

                BattleScriptPushCursorAndCallback(BattleScript_DefenderUsedAnExtraMove);
                effect++;
            }
        }

        //Parry
        if(BATTLER_HAS_ABILITY(battler, ABILITY_SNAP_TRAP_WHEN_HIT)){
            bool8 activateAbilty = FALSE;
            u16 abilityToCheck = ABILITY_SNAP_TRAP_WHEN_HIT; //For easier copypaste
            //Target and Attacker are swapped because this is the defender's ability
            //battler = attacker, gBattlerAttacker = defender

            //Checks if the ability is triggered
            if(!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)  &&
                !gRetaliationInProgress                     &&
                CanUseExtraMove(battler, gBattlerAttacker)  && //gBattlerAttacer is the target in this instance
                IsMoveMakingContact(move, gBattlerAttacker) &&
                TARGET_TURN_DAMAGED){
                activateAbilty = TRUE;
            }

            //This is the stuff that has to be changed for each ability
            if(activateAbilty){
                u16 extraMove = MOVE_SNAP_TRAP;  //The Extra Move to be used
                u8 movePower = 50;                 //The Move power, leave at 0 if you want it to be the same as the normal move
                u8 moveEffectPercentChance  = 0;  //The percent chance of the move effect happening
                u8 extraMoveSecondaryEffect = 0;  //Leave at 0 to remove it's secondary effect
                gTempMove = gCurrentMove;
                gCurrentMove = extraMove;
                gProtectStructs[battler].extraMoveUsed = TRUE;

                //Move Effect
                VarSet(VAR_EXTRA_MOVE_DAMAGE,     movePower);
                VarSet(VAR_TEMP_MOVEEFECT_CHANCE, moveEffectPercentChance);
                VarSet(VAR_TEMP_MOVEEFFECT,       extraMoveSecondaryEffect);

                //If the ability is an innate overwrite the popout
                if(BattlerHasInnate(battler, abilityToCheck))
                    gBattleScripting.abilityPopupOverwrite = abilityToCheck;

                BattleScriptPushCursorAndCallback(BattleScript_DefenderUsedAnExtraMove);
                effect++;
            }
        }

        //Scrapyard
        if(BATTLER_HAS_ABILITY(battler, ABILITY_SCRAPYARD)){
            if(!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
			 && IsMoveMakingContact(move, gBattlerAttacker)
             && gSideTimers[GetBattlerSide(gBattlerAttacker)].spikesAmount < 3){
				BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_DefenderSetsSpikeLayer_Scrapyard;
                effect++;
            }
        }

        //Loose Quills
        if(BATTLER_HAS_ABILITY(battler, ABILITY_LOOSE_QUILLS)){
            if(!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
			 && IsMoveMakingContact(move, gBattlerAttacker)
             && gSideTimers[GetBattlerSide(gBattlerAttacker)].spikesAmount < 3){
				BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_DefenderSetsSpikeLayer_Scrapyard;
                effect++;
            }
        }

        //Toxic Debris
        if(BATTLER_HAS_ABILITY(battler, ABILITY_TOXIC_DEBRIS)){
            if(!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
			 && IsMoveMakingContact(move, gBattlerAttacker)
             && gSideTimers[GetBattlerSide(gBattlerAttacker)].toxicSpikesAmount < 2){
				BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_DefenderSetsToxicSpikeLayer;
                effect++;
            }
        }

        // Spike Armor
        if(BATTLER_HAS_ABILITY(battler, ABILITY_VOODOO_POWER)){
            if(!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
			 && (IS_MOVE_SPECIAL(move) || gBattleMoves[move].flags2 & FLAG_HITS_SPDEF)
             && gBattleMoves[move].effect != EFFECT_PSYSHOCK
             && CanBleed(gBattlerAttacker)
             && (Random() % 100) < 30){
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_VOODOO_POWER;
                gBattleScripting.moveEffect = MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_BLEED;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
        }

        // Seed Sower
        if(BATTLER_HAS_ABILITY(battler, ABILITY_SEED_SOWER)){
            if(!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED) {
				BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SeedSower;
                effect++;
            }
        }
		
		//Cute Charm
		if(BattlerHasInnate(battler, ABILITY_CUTE_CHARM) || BattlerHasInnate(battler, ABILITY_PRIM_AND_PROPER)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && IsMoveMakingContact(move, gBattlerAttacker)
             && TARGET_TURN_DAMAGED
             && gBattleMons[gBattlerTarget].hp != 0
             && (Random() % 100) < 30
             && GetBattlerAbility(gBattlerAttacker) != ABILITY_OBLIVIOUS
			 && !BattlerHasInnate(gBattlerAttacker, ABILITY_OBLIVIOUS)
             && !IsAbilityOnSide(gBattlerAttacker, ABILITY_AROMA_VEIL)
             && GetGenderFromSpeciesAndPersonality(speciesAtk, pidAtk) != GetGenderFromSpeciesAndPersonality(speciesDef, pidDef)
             && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_INFATUATION)
             && GetGenderFromSpeciesAndPersonality(speciesAtk, pidAtk) != MON_GENDERLESS
             && GetGenderFromSpeciesAndPersonality(speciesDef, pidDef) != MON_GENDERLESS)
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = BattlerHasInnate(battler, ABILITY_CUTE_CHARM) ? ABILITY_CUTE_CHARM : ABILITY_PRIM_AND_PROPER;
                gBattleMons[gBattlerAttacker].status2 |= STATUS2_INFATUATED_WITH(gBattlerTarget);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_CuteCharmActivates;
                effect++;
            }
		}
		
		//Pure Love
		if(BattlerHasInnate(battler, ABILITY_PURE_LOVE)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && IsMoveMakingContact(move, gBattlerAttacker)
             && TARGET_TURN_DAMAGED
             && gBattleMons[gBattlerTarget].hp != 0
             && (Random() % 100) < 30
             && GetBattlerAbility(gBattlerAttacker) != ABILITY_OBLIVIOUS
			 && !BattlerHasInnate(gBattlerAttacker, ABILITY_OBLIVIOUS)
             && !IsAbilityOnSide(gBattlerAttacker, ABILITY_AROMA_VEIL)
             && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_INFATUATION))
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_PURE_LOVE;
                gBattleMons[gBattlerAttacker].status2 |= STATUS2_INFATUATED_WITH(gBattlerTarget);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_CuteCharmActivates;
                effect++;
            }
		}
		
		//Gooey, Tangling Hair & Super Hot Goo
		if(BattlerHasInnate(battler, ABILITY_GOOEY) || 
           BattlerHasInnate(battler, ABILITY_TANGLING_HAIR) || 
           BattlerHasInnate(battler, ABILITY_SUPER_HOT_GOO)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && (CompareStat(gBattlerAttacker, STAT_SPEED, MIN_STAT_STAGE, CMP_GREATER_THAN) || 
			     GetBattlerAbility(gBattlerAttacker) == ABILITY_MIRROR_ARMOR ||
				 BattlerHasInnate(gBattlerAttacker, ABILITY_MIRROR_ARMOR))
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
				if(BattlerHasInnate(battler, ABILITY_GOOEY)){
					gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_GOOEY;
				}
                else if(BattlerHasInnate(battler, ABILITY_SUPER_HOT_GOO)){
					gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_SUPER_HOT_GOO;
				}
				else{
					gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_TANGLING_HAIR;
				}
				
                SET_STATCHANGER(STAT_SPEED, 1, TRUE);
                gBattleScripting.moveEffect = MOVE_EFFECT_SPD_MINUS_1;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_GooeyActivates;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
		}
		
		//Weak Armor
		if(BattlerHasInnate(battler, ABILITY_WEAK_ARMOR)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
             && IsBattlerAlive(battler)
             && IS_MOVE_PHYSICAL(gCurrentMove)
             && (CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN) // Don't activate if speed cannot be raised
               || CompareStat(battler, STAT_DEF, MIN_STAT_STAGE, CMP_GREATER_THAN))) // Don't activate if defense cannot be lowered
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_WEAK_ARMOR;
                if (gBattleMoves[gCurrentMove].effect == EFFECT_HIT_ESCAPE && CanBattlerSwitch(gBattlerAttacker))
                    gProtectStructs[battler].disableEjectPack = TRUE;  // Set flag for target

                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_WeakArmorActivates;
                effect++;
            }
		}

        for(i = 0; i < MAX_BATTLERS_COUNT; i++){
            // Retribution Blow
            if(BATTLER_HAS_ABILITY(i, ABILITY_RETRIBUTION_BLOW)){
                if (IsBattlerAlive(i)
                && DoesMoveBoostStats(gCurrentMove)
                && !gRetaliationInProgress
                && !gProtectStructs[i].extraMoveUsed
                && !(gBattleMons[i].status1 & STATUS1_SLEEP)
                && gBattlerAttacker != i
                && (!IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GHOST) || BATTLER_HAS_ABILITY(i, ABILITY_SCRAPPY))
                && GET_BATTLER_SIDE(gBattlerAttacker) != GET_BATTLER_SIDE(i))
                {
                    u16 extraMove = MOVE_HYPER_BEAM;  //The Extra Move to be used
                    u8 movePower = 0;                 //The Move power, leave at 0 if you want it to be the same as the normal move
                    u8 moveEffectPercentChance  = 0;  //The secondary effect is removed here
                    u8 extraMoveSecondaryEffect = 0;  //Leave at 0 to remove it's secondary effect
                    gTempMove = gCurrentMove;
                    gCurrentMove = extraMove;
                    VarSet(VAR_EXTRA_MOVE_DAMAGE, movePower);
                    gProtectStructs[battler].extraMoveUsed = TRUE;

                    //Move Effect
                    VarSet(VAR_TEMP_MOVEEFECT_CHANCE, moveEffectPercentChance);
                    VarSet(VAR_TEMP_MOVEEFFECT, extraMoveSecondaryEffect);

                    gBattlerTarget = battler = i;
                    gProtectStructs[i].extraMoveUsed = TRUE;
                    gBattleScripting.abilityPopupOverwrite = ABILITY_RETRIBUTION_BLOW;
                    BattleScriptPushCursorAndCallback(BattleScript_DefenderUsedAnExtraMove);
                    effect++;
                }
            }
        }
		
        break;
    case ABILITYEFFECT_MOVE_END_ATTACKER: // Same as above, but for attacker
        switch (gLastUsedAbility)
        {
		// Growing Tooth
		case ABILITY_GROWING_TOOTH:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
			 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
			 && (gBattleMoves[move].flags & FLAG_STRONG_JAW_BOOST)
             && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
				SET_STATCHANGER(STAT_ATK, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AttackBoostActivates;
                effect++;
            }
            break;
        // Hardened Sheath
		case ABILITY_HARDENED_SHEATH:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && TARGET_TURN_DAMAGED
			 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
			 && (gBattleMoves[move].flags2 & FLAG_HORN_BASED)
             && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
				ChangeStatBuffs(battler, StatBuffValue(1), STAT_ATK, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
                gBattleScripting.animArg1 = 14 + STAT_ATK;
                gBattleScripting.animArg2 = 0;
                BattleScriptPushCursorAndCallback(BattleScript_AttackBoostActivates);
                gBattleScripting.battler = battler;
                effect++;
            }
            break;
        case ABILITY_SPECTRAL_SHROUD:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && CanBePoisoned(gBattlerAttacker, gBattlerTarget)
             && IsMoveMakingContact(move, gBattlerAttacker)
             && TARGET_TURN_DAMAGED // Need to actually hit the target
             && (Random() % 100) < 30)
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_TOXIC;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
            break;
        case ABILITY_SOLENOGLYPHS:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && CanBePoisoned(gBattlerAttacker, gBattlerTarget)
             && TARGET_TURN_DAMAGED // Need to actually hit the target
			 && (gBattleMoves[move].flags & FLAG_STRONG_JAW_BOOST)//Biting Moves
             && (Random() % 2) == 0)
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_TOXIC;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
            break;
        case ABILITY_SHOCKING_JAWS:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && CanBePoisoned(gBattlerAttacker, gBattlerTarget)
             && TARGET_TURN_DAMAGED // Need to actually hit the target
			 && (gBattleMoves[move].flags & FLAG_STRONG_JAW_BOOST)//Biting Moves
             && (Random() % 2) == 0)
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
            break;
		/*case ABILITY_ROUGH_SKIN:
        case ABILITY_IRON_BARBS:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
                #if B_ROUGH_SKIN_DMG >= GEN_4
                    gBattleMoveDamage = gBattleMons[gBattlerTarget].maxHP / 8;
                #else
                    gBattleMoveDamage = gBattleMons[gBattlerTarget].maxHP / 16;
                #endif
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AttackerRoughSkinActivates;
                effect++;
            }
            break;*/
        case ABILITY_SOUL_LINKER:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
              && gBattleMons[gBattlerTarget].hp != 0
              && gBattleMons[gBattlerAttacker].hp != 0
              && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
              && gBattleMons[gBattlerTarget].ability != ABILITY_SOUL_LINKER
              && !BattlerHasInnate(gBattlerTarget, ABILITY_SOUL_LINKER)
              && move != MOVE_PAIN_SPLIT
              && gBattlerAttacker != gBattlerTarget
              //&& gBattleMoves[move].effect != EFFECT_ABSORB 
              && TARGET_TURN_DAMAGED)
            {
                //Attacker
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AttackerSoulLinker;
                effect++;
            }
            break;
		case ABILITY_LOUD_BANG:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && CanBeConfused(gBattlerTarget)
             && TARGET_TURN_DAMAGED // Need to actually hit the target
			 && (gBattleMoves[move].flags & FLAG_SOUND)//Sound Based Move
             && (Random() % 100) < 50)
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_CONFUSION;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
            break;
        case ABILITY_GULP_MISSILE:
            if (((gCurrentMove == MOVE_SURF && TARGET_TURN_DAMAGED) || gStatuses3[gBattlerAttacker] & STATUS3_UNDERWATER)
             && (effect = ShouldChangeFormHpBased(gBattlerAttacker)))
            {
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AttackerFormChange;
                effect++;
            }
            break;
        }
		
        
		// Innates
		// Soul Linker Attacker
		if (BattlerHasInnate(battler, ABILITY_SOUL_LINKER)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
              && gBattleMons[gBattlerTarget].hp != 0
              && gBattleMons[gBattlerAttacker].hp != 0
              && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
              && gBattleMons[gBattlerTarget].ability != ABILITY_SOUL_LINKER
              && !BattlerHasInnate(gBattlerTarget, ABILITY_SOUL_LINKER)
              && move != MOVE_PAIN_SPLIT
              && gBattlerAttacker != gBattlerTarget
              //&& gBattleMoves[move].effect != EFFECT_ABSORB 
              && TARGET_TURN_DAMAGED)
            {
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AttackerSoulLinker;
                effect++;
            }
		}

        // Hydro Circuit
	    if(BATTLER_HAS_ABILITY(battler, ABILITY_HYDRO_CIRCUIT)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && !BATTLER_MAX_HP(gBattlerAttacker) 
             && !BATTLER_HEALING_BLOCKED(gBattlerAttacker)
             && IsBattlerAlive(gBattlerAttacker)
             && gBattleMoves[move].type == TYPE_WATER
             && TARGET_TURN_DAMAGED) // Need to actually hit the target
            {
                //Attacker
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_HYDRO_CIRCUIT;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_HydroCircuitAbsorbEffectActivated;
                effect++;
            }
        }

        // Hydro Circuit
	    if(BATTLER_HAS_ABILITY(battler, ABILITY_PURE_LOVE)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && !BATTLER_MAX_HP(gBattlerAttacker) 
             && !BATTLER_HEALING_BLOCKED(gBattlerAttacker)
             && IsBattlerAlive(gBattlerAttacker)
             && gBattleMons[gBattlerTarget].status2 & STATUS2_INFATUATION
             && TARGET_TURN_DAMAGED) // Need to actually hit the target
            {
                //Attacker
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_PURE_LOVE;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_HydroCircuitAbsorbEffectActivated;
                effect++;
            }
        }
		
		// Growing Tooth
		if (BattlerHasInnate(battler, ABILITY_GROWING_TOOTH)){
			if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
				 && TARGET_TURN_DAMAGED
				 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
				 && (gBattleMoves[move].flags & FLAG_STRONG_JAW_BOOST)
				 && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
				{
					gBattleScripting.abilityPopupOverwrite = ABILITY_GROWING_TOOTH;
					gLastUsedAbility = ABILITY_GROWING_TOOTH;
					PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
					BattleScriptPushCursor();
					ChangeStatBuffs(battler, StatBuffValue(1), STAT_ATK, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
					gBattleScripting.animArg1 = 14 + STAT_ATK;
					gBattleScripting.animArg2 = 0;
					BattleScriptPushCursorAndCallback(BattleScript_AttackBoostActivates);
					gBattleScripting.battler = battler;
					effect++;
				}
		}

        //Spinning Top
        if(BATTLER_HAS_ABILITY(battler, ABILITY_SPINNING_TOP)){
            bool8 activateAbilty = FALSE;
            u16 abilityToCheck = ABILITY_SPINNING_TOP; //For easier copypaste

            //Checks if the ability is triggered
            if(DidMoveHit() && gBattleMoves[move].type == TYPE_FIGHTING)
                activateAbilty = CheckAndSetOncePerTurnAbility(battler, ABILITY_SPINNING_TOP);

            //This is the stuff that has to be changed for each ability
            if(activateAbilty){
                //Remove Hazards
				if(gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_HAZARDS_ANY){
                    //If the ability is an innate overwrite the popout
                    if(BattlerHasInnate(battler, abilityToCheck))
                        gBattleScripting.abilityPopupOverwrite = abilityToCheck;
                    gSideStatuses[GetBattlerSide(battler)] &= ~(SIDE_STATUS_STEALTH_ROCK | SIDE_STATUS_TOXIC_SPIKES | SIDE_STATUS_SPIKES_DAMAGED | SIDE_STATUS_STICKY_WEB);
                    BattleScriptPushCursorAndCallback(BattleScript_PickUpActivate);
                    gBattleScripting.battler = battler;
                    effect++;
                }
                //Boosts Speed
                if(CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN)){
                    //If the ability is an innate overwrite the popout
                    if(BattlerHasInnate(battler, abilityToCheck))
                        gBattleScripting.abilityPopupOverwrite = abilityToCheck;
                    ChangeStatBuffs(battler, StatBuffValue(1), STAT_SPEED, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
                    gBattleScripting.animArg1 = 14 + STAT_SPEED;
                    gBattleScripting.animArg2 = 0;
                    BattleScriptPushCursorAndCallback(BattleScript_SpeedBoostActivates);
                    gBattleScripting.battler = battler;
                    effect++;
                }
            }
        }

        // Hardened Sheath
		if (BattlerHasInnate(battler, ABILITY_HARDENED_SHEATH)){
			if (DidMoveHit() && (gBattleMoves[move].flags2 & FLAG_HORN_BASED)
				 && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
				{
					gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_HARDENED_SHEATH;
					PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
					BattleScriptPushCursor();
					ChangeStatBuffs(battler, StatBuffValue(1), STAT_ATK, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
					gBattleScripting.animArg1 = 14 + STAT_ATK;
					gBattleScripting.animArg2 = 0;
					BattleScriptPushCursorAndCallback(BattleScript_AttackBoostActivates);
					gBattleScripting.battler = battler;
					effect++;
				}
		}
		// Loud Bang
		if (BattlerHasInnate(battler, ABILITY_LOUD_BANG)){
			if (ShouldApplyOnHitAffect(gBattlerTarget)
				 && CanBeConfused(gBattlerTarget)
				 && (gBattleMoves[move].flags & FLAG_SOUND)//Sound Based Move
				 && (Random() % 100) < 50)
				{
					gBattleScripting.abilityPopupOverwrite = ABILITY_LOUD_BANG;
					gLastUsedAbility = ABILITY_LOUD_BANG;
					gBattleScripting.moveEffect = MOVE_EFFECT_CONFUSION;
					PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
					BattleScriptPushCursor();
					gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
					gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
					effect++;
				}
		}
		/*/Iron Barbs/ Rough Skin
		if (BattlerHasInnate(battler, ABILITY_ROUGH_SKIN) ||
			BattlerHasInnate(battler, ABILITY_IRON_BARBS)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && TARGET_TURN_DAMAGED
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
				if(BattlerHasInnate(battler, ABILITY_ROUGH_SKIN)){
					gBattleScripting.abilityPopupOverwrite = ABILITY_ROUGH_SKIN;
					gLastUsedAbility = ABILITY_ROUGH_SKIN;
				}
				else{
					gBattleScripting.abilityPopupOverwrite = ABILITY_IRON_BARBS;
					gLastUsedAbility = ABILITY_IRON_BARBS;
				}
					
                gBattleMoveDamage = gBattleMons[gBattlerTarget].maxHP / 8;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AttackerRoughSkinActivates;
                effect++;
            }
		}*/
		
		//Electric Burst
		if (BATTLER_HAS_ABILITY(battler, ABILITY_ELECTRIC_BURST)){
			if (DidMoveHit()
			 && gBattleMoves[move].type == TYPE_ELECTRIC //Electric Type Moves
             && gBattleMons[gBattlerAttacker].hp > 1
             && !BATTLER_HAS_MAGIC_GUARD(gBattlerAttacker))
            {
                if(BattlerHasInnate(battler, ABILITY_ELECTRIC_BURST))
                    gLastUsedAbility = gBattleScripting.abilityPopupOverwrite = ABILITY_ELECTRIC_BURST;
                gBattleMoveDamage = gSpecialStatuses[gBattlerTarget].dmg / 10;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                else if(gBattleMoveDamage >= gBattleMons[gBattlerAttacker].hp) //Make it unable to faint the user to avoid crashes
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].hp - 1;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_UserGetsReckoilDamaged;
                effect++;
            }
		}

        // Infernal Rage
		if (BATTLER_HAS_ABILITY(battler, ABILITY_INFERNAL_RAGE)){
			if (DidMoveHit()
			 && gBattleMoves[move].type == TYPE_FIRE //Fire Type Moves
             && gBattleMons[gBattlerAttacker].hp > 1
             && !BATTLER_HAS_MAGIC_GUARD(gBattlerAttacker))
            {
                if(BattlerHasInnate(battler, ABILITY_INFERNAL_RAGE))
                    gLastUsedAbility = gBattleScripting.abilityPopupOverwrite = ABILITY_INFERNAL_RAGE;
                gBattleMoveDamage = gSpecialStatuses[gBattlerTarget].dmg / 10;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                else if(gBattleMoveDamage >= gBattleMons[gBattlerAttacker].hp) //Make it unable to faint the user to avoid crashes
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].hp - 1;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_UserGetsReckoilDamaged;
                effect++;
            }
		}

        //Archmage
        if(BATTLER_HAS_ABILITY(battler, ABILITY_ARCHMAGE)){
            bool8 activateAbilty = FALSE;
            u16 abilityToCheck = ABILITY_ARCHMAGE; //For easier copypaste

            //Checks if the ability is triggered
            if(DidMoveHit() && gBattleMoves[move].split != SPLIT_STATUS && (Random() % 100) < 30){
                activateAbilty = TRUE;
            }

            //This is the stuff that has to be changed for each ability
            if(activateAbilty){
                //If the ability is an innate overwrite the popout
                switch(gBattleMoves[move].type){
                    case TYPE_POISON: // 30% chance to badly poison.
                        if(IsBattlerAlive(gBattlerTarget) && CanBePoisoned(gBattlerAttacker, gBattlerTarget)){
                            if(BattlerHasInnate(battler, abilityToCheck))
                                gBattleScripting.abilityPopupOverwrite = abilityToCheck;
                            gBattleScripting.moveEffect = MOVE_EFFECT_TOXIC;
                            gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                            gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                            effect++;
                        }
                    break;
                    case TYPE_ICE: // 30% chance to inflict frostbite.
                        if(IsBattlerAlive(gBattlerTarget) && CanGetFrostbite(gBattlerTarget)){
                            if(BattlerHasInnate(battler, abilityToCheck))
                                gBattleScripting.abilityPopupOverwrite = abilityToCheck;
                            gBattleScripting.moveEffect = MOVE_EFFECT_FROSTBITE;
                            gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                            gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                            effect++;
                        }
                    break;
                    case TYPE_WATER: // 30% chance to confuse.
                        if(IsBattlerAlive(gBattlerTarget) && CanBeConfused(gBattlerTarget)){
                            if(BattlerHasInnate(battler, abilityToCheck))
                                gBattleScripting.abilityPopupOverwrite = abilityToCheck;
                            gBattleScripting.moveEffect = MOVE_EFFECT_CONFUSION;
                            gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                            gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                            effect++;
                        }
                    break;
                    case TYPE_FIRE: // 30% chance to burn.
                        if(IsBattlerAlive(gBattlerTarget) && CanBeBurned(gBattlerTarget)){
                            if(BattlerHasInnate(battler, abilityToCheck))
                                gBattleScripting.abilityPopupOverwrite = abilityToCheck;
                            gBattleScripting.moveEffect = MOVE_EFFECT_BURN;
                            gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                            gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                            effect++;
                        }
                    break;
                    case TYPE_ELECTRIC: // 30% chance to set up Electric Terrain.
                        if(TryChangeBattleTerrain(battler, STATUS_FIELD_ELECTRIC_TERRAIN, &gFieldTimers.terrainTimer)){
                            if(BattlerHasInnate(battler, abilityToCheck))
                                gBattleScripting.abilityPopupOverwrite = abilityToCheck;
                            gBattlescriptCurrInstr = BattleScript_Archmage_Effect_Type_Electric;
                            gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                            effect++;
                        }
                    break;
                    case TYPE_PSYCHIC: // 30% chance to set up Psychic Terrain.
                        if(TryChangeBattleTerrain(battler, STATUS_FIELD_PSYCHIC_TERRAIN, &gFieldTimers.terrainTimer)){
                            if(BattlerHasInnate(battler, abilityToCheck))
                                gBattleScripting.abilityPopupOverwrite = abilityToCheck;
                            gBattlescriptCurrInstr = BattleScript_Archmage_Effect_Type_Psychic;
                            gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                            effect++;
                        }
                    break;
                    case TYPE_FAIRY: // 30% chance to set up Misty Terrain.
                        if(TryChangeBattleTerrain(battler, STATUS_FIELD_MISTY_TERRAIN, &gFieldTimers.terrainTimer)){
                            if(BattlerHasInnate(battler, abilityToCheck))
                                gBattleScripting.abilityPopupOverwrite = abilityToCheck;
                            gBattlescriptCurrInstr = BattleScript_Archmage_Effect_Type_Fairy;
                            gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                            effect++;
                        }
                    break;
                    case TYPE_GRASS: // 30% chance to set up Grassy Terrain.
                        if(TryChangeBattleTerrain(battler, STATUS_FIELD_GRASSY_TERRAIN, &gFieldTimers.terrainTimer)){
                            if(BattlerHasInnate(battler, abilityToCheck))
                                gBattleScripting.abilityPopupOverwrite = abilityToCheck;
                            gBattlescriptCurrInstr = BattleScript_Archmage_Effect_Type_Grass;
                            gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                            effect++;
                        }
                    break;
                    case TYPE_NORMAL: // 30% chance to encore.
                    if (gDisableStructs[gBattlerTarget].encoreTimer == 0
                        && !IsAbilityOnSide(gBattlerTarget, ABILITY_AROMA_VEIL)
                        && !BATTLER_HAS_ABILITY(gBattlerTarget, ABILITY_OBLIVIOUS))
                    {
                        u8 i;
                        for (i = 0; i < MAX_MON_MOVES; i++)
                        {
                            if (gBattleMons[gBattlerTarget].moves[i] == gLastMoves[gBattlerTarget])
                                break;
                        }

                        if (gLastMoves[gBattlerTarget] == MOVE_STRUGGLE
                            || gLastMoves[gBattlerTarget] == MOVE_ENCORE
                            || gLastMoves[gBattlerTarget] == MOVE_MIRROR_MOVE)
                        {
                            i = 4;
                        }

                        if (gDisableStructs[gBattlerTarget].encoredMove == 0
                            && i != 4 && gBattleMons[gBattlerTarget].pp[i] != 0)
                        {
                            if(BattlerHasInnate(battler, abilityToCheck))
                                gBattleScripting.abilityPopupOverwrite = abilityToCheck;
                            
                            gDisableStructs[gBattlerTarget].encoredMove = gBattleMons[gBattlerTarget].moves[i];
                            gDisableStructs[gBattlerTarget].encoredMovePos = i;
                            gDisableStructs[gBattlerTarget].encoreTimer = 3;
                            gDisableStructs[gBattlerTarget].encoreTimerStartValue = gDisableStructs[gBattlerTarget].encoreTimer;

                            gBattlescriptCurrInstr = BattleScript_Archmage_Effect_Type_Normal;
                            gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                            effect++;
                        }
                    }
                    break;
                    case TYPE_ROCK: // 30% chance to set up Stealth Rock.
                        if(!(gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_STEALTH_ROCK)){
                            if(BattlerHasInnate(battler, abilityToCheck))
                                gBattleScripting.abilityPopupOverwrite = abilityToCheck;
                            gSideStatuses[GetBattlerSide(gBattlerTarget)] |= (SIDE_STATUS_STEALTH_ROCK);
                            gSideTimers[GetBattlerSide(gBattlerTarget)].stealthRockType= TYPE_ROCK;
                            gBattlescriptCurrInstr = BattleScript_Archmage_Effect_Type_Rock;
                            gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                            effect++;
                        }
                    break;
                    case TYPE_GHOST: // 30% chance to disable.
                    if (gDisableStructs[gBattlerTarget].disabledMove == 0)
                    {
                        if (IsBattlerAlive(gBattlerTarget) && CanBeDisabled(gBattlerTarget)){
                            if(BattlerHasInnate(battler, abilityToCheck))
                                gBattleScripting.abilityPopupOverwrite = abilityToCheck;
                            gBattleScripting.moveEffect = MOVE_EFFECT_DISABLE;
                            gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                            gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                            effect++;
                        }
                    }
                    break;
                    case TYPE_DARK: // 30% chance to inflict bleed.
                        if(IsBattlerAlive(gBattlerTarget) && CanBleed(gBattlerTarget)){
                            if(BattlerHasInnate(battler, abilityToCheck))
                                gBattleScripting.abilityPopupOverwrite = abilityToCheck;
                            gBattleScripting.moveEffect = MOVE_EFFECT_BLEED;
                            gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                            gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                            effect++;
                        }
                    break;
                    case TYPE_FIGHTING: // 30% chance to boost the users Special Attack by 1.
                    {
                        if(CompareStat(battler, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN)){
                            if(BattlerHasInnate(battler, abilityToCheck))
                                gBattleScripting.abilityPopupOverwrite = abilityToCheck;

                            gBattleScripting.moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1 | MOVE_EFFECT_AFFECTS_USER;
                            gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                            gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                            effect++;
                        }
                    }  
                    break;
                    case TYPE_FLYING: // 30% chance to raise the users Speed by 1.
                        if(CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN)){
                            if(BattlerHasInnate(battler, abilityToCheck))
                                gBattleScripting.abilityPopupOverwrite = abilityToCheck;

                            gBattleScripting.moveEffect = MOVE_EFFECT_SPD_PLUS_1 | MOVE_EFFECT_AFFECTS_USER;
                            gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                            gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                            effect++;
                        }
                    break;
                    case TYPE_BUG: // 30% chance to set Sticky Web.

                    break;
                    case TYPE_DRAGON: // 30% chance to lower the opponents attack by 1.
                        if(IsBattlerAlive(gBattlerTarget) && CompareStat(gBattlerTarget, STAT_ATK, MIN_STAT_STAGE, CMP_GREATER_THAN)){
                            if(BattlerHasInnate(battler, abilityToCheck))
                                gBattleScripting.abilityPopupOverwrite = abilityToCheck;

                            gBattleScripting.moveEffect = MOVE_EFFECT_ATK_MINUS_1;
                            gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                            gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                            effect++;
                        }
                    break;
                    case TYPE_GROUND: // 30% chance to trap.
                        if(!(gBattleMons[gBattlerTarget].status2 & STATUS2_ESCAPE_PREVENTION)){
                            if(BattlerHasInnate(battler, abilityToCheck))
                                gBattleScripting.abilityPopupOverwrite = abilityToCheck;

                            gBattleScripting.moveEffect = MOVE_EFFECT_PREVENT_ESCAPE;
                            gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                            gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                            effect++;
                        }
                    break;
                    case TYPE_STEEL: // 30% chance to increase the user's defense.
                        if(CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN)){
                            if(BattlerHasInnate(battler, abilityToCheck))
                                gBattleScripting.abilityPopupOverwrite = abilityToCheck;

                            gBattleScripting.moveEffect = MOVE_EFFECT_DEF_PLUS_1 | MOVE_EFFECT_AFFECTS_USER;
                            gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                            gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                            effect++;
                        }
                    break;
                }
            }
        }

		//Solenoglyphs
		if (BattlerHasInnate(battler, ABILITY_SOLENOGLYPHS)) {
		    if (ShouldApplyOnHitAffect(gBattlerTarget)
             && CanBePoisoned(gBattlerAttacker, gBattlerTarget)
			 && (gBattleMoves[move].flags & FLAG_STRONG_JAW_BOOST)//Biting Moves
             && (Random() % 2) == 0)
            {
				gBattleScripting.abilityPopupOverwrite = ABILITY_SOLENOGLYPHS;
				gLastUsedAbility = ABILITY_SOLENOGLYPHS;
                gBattleScripting.moveEffect = MOVE_EFFECT_TOXIC;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
        }

		//Flaming Jaws
		if (BATTLER_HAS_ABILITY(battler, ABILITY_FLAMING_JAWS)){
			if (ShouldApplyOnHitAffect(gBattlerTarget)
             && CanBeBurned(gBattlerTarget)
			 && (gBattleMoves[move].flags & FLAG_STRONG_JAW_BOOST)//Biting Moves
             && (Random() % 2) == 0)
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_FLAMING_JAWS;
                gBattleScripting.moveEffect = MOVE_EFFECT_BURN;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
        }

        if (BATTLER_HAS_ABILITY(battler, ABILITY_NOISE_CANCEL))
        {
            if (ShouldApplyOnHitAffect(gBattlerTarget)
             && CanBeDisabled(gBattlerTarget)
			 && (gBattleMoves[move].flags & FLAG_SOUND)
             && (Random() % 100) < 20) {
                gBattleScripting.abilityPopupOverwrite = ABILITY_NOISE_CANCEL;
                gBattleScripting.moveEffect = MOVE_EFFECT_DISABLE;
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
        }

        //Fearmonger Paralyze Chance
		if(BATTLER_HAS_ABILITY(battler, ABILITY_FEARMONGER)){
            if (ShouldApplyOnHitAffect(gBattlerTarget)
             && CanBeParalyzed(gBattlerAttacker, gBattlerTarget)
             && IsMoveMakingContact(move, gBattlerAttacker) //Does it need to be a contact move?
             && (Random() % 10) == 0)
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_FEARMONGER;
                gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
        }

        // Yuki Onna Charm Chance
		if(BATTLER_HAS_ABILITY(battler, ABILITY_YUKI_ONNA)){
            if (ShouldApplyOnHitAffect(gBattlerTarget)
             && gBattleMons[gBattlerAttacker].hp != 0
             && (Random() % 10) == 0
             && !BATTLER_HAS_ABILITY(gBattlerTarget, ABILITY_OBLIVIOUS)
             && !IsAbilityOnSide(gBattlerTarget, ABILITY_AROMA_VEIL)
             && GetGenderFromSpeciesAndPersonality(speciesAtk, pidAtk) != GetGenderFromSpeciesAndPersonality(speciesDef, pidDef)
             && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_INFATUATION)
             && GetGenderFromSpeciesAndPersonality(speciesAtk, pidAtk) != MON_GENDERLESS
             && GetGenderFromSpeciesAndPersonality(speciesDef, pidDef) != MON_GENDERLESS)
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_YUKI_ONNA;
                gBattleScripting.moveEffect = MOVE_EFFECT_ATTRACT;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
        }

        //Shocking Jaws
		if (BattlerHasInnate(battler, ABILITY_SHOCKING_JAWS)){
			if (ShouldApplyOnHitAffect(gBattlerTarget)
             && CanBePoisoned(gBattlerAttacker, gBattlerTarget)
			 && (gBattleMoves[move].flags & FLAG_STRONG_JAW_BOOST)//Biting Moves
             && (Random() % 2) == 0)
            {
				gBattleScripting.abilityPopupOverwrite = ABILITY_SHOCKING_JAWS;
				gLastUsedAbility = ABILITY_SHOCKING_JAWS;
                gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
        }

        //Molten Blades
		if (BATTLER_HAS_ABILITY(battler, ABILITY_MOLTEN_BLADES)){
			if (ShouldApplyOnHitAffect(gBattlerTarget)
             && CanBeBurned(gBattlerTarget)
			 && (gBattleMoves[move].flags & FLAG_KEEN_EDGE_BOOST) //Keen Edge
             && (Random() % 100) < 20)
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_MOLTEN_BLADES;
                gBattleScripting.moveEffect = MOVE_EFFECT_BURN;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
        }

        //Molten Blades
		if (BATTLER_HAS_ABILITY(battler, ABILITY_DEAD_POWER)){
			if (ShouldApplyOnHitAffect(gBattlerTarget)
             && !(gBattleMons[gBattlerTarget].status2 & STATUS2_CURSED)
             && IsMoveMakingContact(move, battler)
             && (Random() % 100) < 20)
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_DEAD_POWER;
                gBattleScripting.moveEffect = MOVE_EFFECT_CURSE;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
        }

		// Spectral Shroud
        if (BattlerHasInnate(battler, ABILITY_SPECTRAL_SHROUD)){
            u8 moveType;

            GET_MOVE_TYPE(move, moveType);

            if (ShouldApplyOnHitAffect(gBattlerTarget)
             && CanBePoisoned(gBattlerAttacker, gBattlerTarget)
             && gBattleStruct->ateBoost[battler]
             && moveType == TYPE_GHOST
             && (Random() % 100) < 30)
            {
				gBattleScripting.abilityPopupOverwrite = ABILITY_SPECTRAL_SHROUD;
				gLastUsedAbility = ABILITY_SPECTRAL_SHROUD;
                gBattleScripting.moveEffect = MOVE_EFFECT_TOXIC;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
		}

		// Damp (Attacker)
		if (BATTLER_HAS_ABILITY(battler, ABILITY_DAMP)){
            if (ShouldApplyOnHitAffect(gBattlerTarget)
             && IsMoveMakingContact(move, gBattlerAttacker)
             && !IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_WATER))
            {
                u8 newtype = TYPE_WATER;
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_DAMP;
				gBattleMons[gBattlerTarget].type1 = newtype;
				gBattleMons[gBattlerTarget].type2 = newtype;
				gBattleMons[gBattlerTarget].type3 = TYPE_MYSTERY;
				PREPARE_TYPE_BUFFER(gBattleTextBuff1, newtype);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_DefenderBecameTheTypeFull;
				effect++;
            }
		}

        if(BATTLER_HAS_ABILITY(battler, ABILITY_ANGELS_WRATH)){
            bool8 effectActivated = FALSE;

            switch(move){
                case MOVE_TACKLE:
                    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                    && gBattleMons[gBattlerTarget].hp != 0
                    && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
                    && gDisableStructs[gBattlerTarget].encoreTimer  == 0
                    && gDisableStructs[gBattlerTarget].disableTimer == 0
                    && TARGET_TURN_DAMAGED)
                    {
                        gDisableStructs[gBattlerTarget].encoreTimer = 2;
                        gDisableStructs[gBattlerTarget].encoredMove = gBattleMons[gBattlerTarget].moves[0];

                        gDisableStructs[gBattlerTarget].disableTimer = gDisableStructs[gBattlerTarget].disableTimerStartValue = 2;
                        gDisableStructs[gBattlerTarget].disabledMove = gBattleMons[gBattlerTarget].moves[0];
                        
				        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_ANGELS_WRATH;
                        PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                        BattleScriptPushCursorAndCallback(BattleScript_AngelsWrath_Effect_Tackle);
                        effect++;
                    }
                break;
                case MOVE_STRING_SHOT:
                    if (!gProtectStructs[gBattlerAttacker].confusionSelfDmg)
                    {
                        if(!(gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_STEALTH_ROCK) ||
                           !(gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_TOXIC_SPIKES) ||
                           !(gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_SPIKES) ||
                           !(gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_STICKY_WEB))
                                effectActivated = TRUE;

                        if(effectActivated){
                            gSideStatuses[GetBattlerSide(gBattlerTarget)] |= (SIDE_STATUS_STEALTH_ROCK);
                            gSideTimers[GetBattlerSide(gBattlerTarget)].stealthRockType = TYPE_ROCK;
                            gSideStatuses[GetBattlerSide(gBattlerTarget)] |= (SIDE_STATUS_TOXIC_SPIKES);
                            gSideStatuses[GetBattlerSide(gBattlerTarget)] |= (SIDE_STATUS_SPIKES);
                            gSideStatuses[GetBattlerSide(gBattlerTarget)] |= (SIDE_STATUS_STICKY_WEB);

                            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_ANGELS_WRATH;
                            PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                            BattleScriptPushCursorAndCallback(BattleScript_AngelsWrath_Effect_String_Shot);
                            effect++;
                        }
                    }
                break;
                case MOVE_HARDEN:
                    if (!gProtectStructs[gBattlerAttacker].confusionSelfDmg)
                    {
                        for(i = 1; i < NUM_STATS; i++){
                            if(gBattleMons[battler].statStages[i] < MAX_STAT_STAGE && i != STAT_DEF){
                                ChangeStatBuffs(battler, StatBuffValue(1), i, MOVE_EFFECT_AFFECTS_USER | STAT_BUFF_DONT_SET_BUFFERS, NULL);
                                effectActivated = TRUE;
                            }
                        }

                        if(effectActivated){
                            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_ANGELS_WRATH;
                            PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                            BattleScriptPushCursorAndCallback(BattleScript_AngelsWrath_Effect_Harden);
                            effect++;
                        }
                    }
                break;
                case MOVE_IRON_DEFENSE:
                    if (!gProtectStructs[gBattlerAttacker].confusionSelfDmg)
                    {
                        gProtectStructs[gBattlerAttacker].angelsWrathProtected = TRUE;
				        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_ANGELS_WRATH;
                        PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                        BattleScriptPushCursorAndCallback(BattleScript_AngelsWrath_Effect_Iron_Defense);
                        effect++;
                    }
                break;
                case MOVE_ELECTROWEB:
                    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                    && gBattleMons[gBattlerTarget].hp != 0
                    && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
                    && (gBattleMons[gBattlerTarget].statStages[STAT_SPEED] != 0
                    || !(gBattleMons[gBattlerTarget].status2 & STATUS2_ESCAPE_PREVENTION))
                    && TARGET_TURN_DAMAGED)
                    {
                        gBattleMons[gBattlerTarget].statStages[STAT_SPEED] = 0;
                        gBattleMons[gBattlerTarget].status2 |= (STATUS2_ESCAPE_PREVENTION);
				        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_ANGELS_WRATH;
                        PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                        BattleScriptPushCursorAndCallback(BattleScript_AngelsWrath_Effect_Electroweb);
                        effect++;
                    }
                break;
                case MOVE_BUG_BITE:
                    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                    && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
                    && TARGET_TURN_DAMAGED)
                    {
                        if(CanBattlerGetOrLoseItem(gBattlerTarget, gBattleMons[gBattlerTarget].item) && gBattleMons[gBattlerTarget].hp != 0){
                            gBattleMons[gBattlerTarget].item = ITEM_NONE;
                            BattleScriptPushCursorAndCallback(BattleScript_AngelsWrath_Effect_Bug_Bite);
                            effect++;
                        }

                        if(!BATTLER_MAX_HP(gBattlerAttacker)){
                            BattleScriptPushCursorAndCallback(BattleScript_AngelsWrath_Effect_Bug_Bite_2);
                            effect++;
                        }
                    }
                break;
            }
        }

        // Elemental Charge
		if (BATTLER_HAS_ABILITY(battler, ABILITY_ELEMENTAL_CHARGE)){ //this macro convines both ability and innate check
            //Paralysis
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && CanBeParalyzed(gBattlerAttacker, gBattlerTarget)
             && gBattleMoves[move].type == TYPE_ELECTRIC
             && TARGET_TURN_DAMAGED  // Need to actually hit the target
             && (Random() % 5) == 0) //20% chance
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_ELEMENTAL_CHARGE;
                gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
            //Burn
            else if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && CanBeBurned(gBattlerTarget)
             && gBattleMoves[move].type == TYPE_FIRE
             && TARGET_TURN_DAMAGED // Need to actually hit the target
             && (Random() % 5) == 0) //20% chance
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_ELEMENTAL_CHARGE;
                gBattleScripting.moveEffect = MOVE_EFFECT_BURN;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
            //Frostbite
            else if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && CanBeFrozen(gBattlerTarget)
             && gBattleMoves[move].type == TYPE_ICE
             && TARGET_TURN_DAMAGED // Need to actually hit the target
             && (Random() % 5) == 0) //20% chance
            {
				gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_ELEMENTAL_CHARGE;
                gBattleScripting.moveEffect = MOVE_EFFECT_FROSTBITE;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
		}
	
		// Stench
		if (BATTLER_HAS_ABILITY(battler, ABILITY_STENCH)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[battler].confusionSelfDmg
             && (Random() % 100) < 10
             && !IS_MOVE_STATUS(move)
             && TARGET_TURN_DAMAGED
             && CanMoveHaveExtraFlinchChance(move))
            {
                gLastUsedAbility = gBattleScripting.abilityPopupOverwrite = ABILITY_STENCH;
                gBattleScripting.moveEffect = MOVE_EFFECT_FLINCH;
                BattleScriptPushCursor();
                SetMoveEffect(FALSE, 0);
                BattleScriptPop();
                effect++;
            }
		}
	
		// Stench
		if (BATTLER_HAS_ABILITY(battler, ABILITY_HAUNTING_FRENZY)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[battler].confusionSelfDmg
             && (Random() % 100) < 20
             && !IS_MOVE_STATUS(move)
             && TARGET_TURN_DAMAGED
             && !(gBattleMons[gBattlerTarget].status2 & STATUS2_FLINCHED)
             && CanMoveHaveExtraFlinchChance(move))
            {
                gLastUsedAbility = gBattleScripting.abilityPopupOverwrite = ABILITY_HAUNTING_FRENZY;
                gBattleScripting.moveEffect = MOVE_EFFECT_FLINCH;
                BattleScriptPushCursor();
                SetMoveEffect(FALSE, 0);
                BattleScriptPop();
                effect++;
            }
		}

		// Absorbant
		if (BATTLER_HAS_ABILITY(battler, ABILITY_ABSORBANT)){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && !IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_GRASS)
             && TARGET_TURN_DAMAGED // Need to actually hit the target
             && !(gStatuses3[gBattlerTarget] & STATUS3_LEECHSEED)
             && ((gBattleMoves[move].effect == EFFECT_ABSORB      && TARGET_TURN_DAMAGED) || 
                 (gBattleMoves[move].effect == EFFECT_DREAM_EATER && TARGET_TURN_DAMAGED) ||
                 (gBattleMoves[move].effect == EFFECT_STRENGTH_SAP)))
            {
                gStatuses3[gBattlerTarget] |= gBattlerAttacker;
                gStatuses3[gBattlerTarget] |= STATUS3_LEECHSEED;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
				BattleScriptPushCursorAndCallback(BattleScript_AbsorbantActivated);
                effect++;
            }
		}

        // Fungal Infection
        if (BattlerHasInnate(battler, ABILITY_FUNGAL_INFECTION) || GetBattlerAbility(battler) == ABILITY_FUNGAL_INFECTION){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && !IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_GRASS)
             && IsMoveMakingContact(move, gBattlerAttacker)
             && TARGET_TURN_DAMAGED // Need to actually hit the target
             && !(gStatuses3[gBattlerTarget] & STATUS3_LEECHSEED))
            {
                gStatuses3[gBattlerTarget] |= gBattlerAttacker;
                gStatuses3[gBattlerTarget] |= STATUS3_LEECHSEED;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
				BattleScriptPushCursorAndCallback(BattleScript_FungalInfectionActivates);
                effect++;
            }
        }

        //Grip Pincer
        if (BattlerHasInnate(battler, ABILITY_GRIP_PINCER) || GetBattlerAbility(battler) == ABILITY_GRIP_PINCER){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                && gBattleMons[gBattlerTarget].hp != 0
                && !gProtectStructs[battler].confusionSelfDmg
                && IsMoveMakingContact(move, battler)
                && !(gBattleMons[gBattlerTarget].status2 & STATUS2_WRAPPED)
                && battler != gBattlerTarget
                && TARGET_TURN_DAMAGED // Need to actually hit the target
                && (Random() % 2) == 0)
                {
                    gBattleMons[gBattlerTarget].status2 |= STATUS2_WRAPPED;
                    if (GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_GRIP_CLAW)
                        gDisableStructs[gBattlerTarget].wrapTurns = (B_BINDING_TURNS >= GEN_5) ? 7 : 5;
                    else
                        gDisableStructs[gBattlerTarget].wrapTurns = (B_BINDING_TURNS >= GEN_5) ? ((Random() % 2) + 4) : ((Random() % 4) + 2);

                    gBattleStruct->wrappedMove[gBattlerTarget] = gCurrentMove;
                    gBattleStruct->wrappedBy[gBattlerTarget] = battler;
                    BattleScriptPushCursorAndCallback(BattleScript_GripPincerActivated);
                    effect++;
                }
        }

        //this move needs this to have 2 effects at once
        if(move == MOVE_SMITE){
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && CanBeParalyzed(gBattlerAttacker, gBattlerTarget)
             && IsMoveMakingContact(move, gBattlerAttacker)
             && TARGET_TURN_DAMAGED
             && (Random() % 5) == 0)
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_MoveSecondStatusEffect;
                effect++;
            }
		}
		
        break;
    case ABILITYEFFECT_MOVE_END_OTHER: // Abilities that activate on *another* battler's moveend: Dancer, Soul-Heart, Receiver, Symbiosis
        // Dancer
        if(GetBattlerAbility(battler) == ABILITY_DANCER || BattlerHasInnate(battler, ABILITY_DANCER)){
            if (IsBattlerAlive(battler)
             && (gBattleMoves[gCurrentMove].flags & FLAG_DANCE)
             && !gSpecialStatuses[battler].dancerUsedMove
             && gBattlerAttacker != battler)
            {
                // Set bit and save Dancer mon's original target
                gSpecialStatuses[battler].dancerUsedMove = TRUE;
                gSpecialStatuses[battler].dancerOriginalTarget = *(gBattleStruct->moveTarget + battler) | 0x4;
                gBattleStruct->atkCancellerTracker = 0;
                gBattlerAttacker = gBattlerAbility = battler;
                gCalledMove = gCurrentMove;

                // Set the target to the original target of the mon that first used a Dance move
                gBattlerTarget = gBattleScripting.savedBattler & 0x3;

                // Make sure that the target isn't an ally - if it is, target the original user
                if (GetBattlerSide(gBattlerTarget) == GetBattlerSide(gBattlerAttacker))
                    gBattlerTarget = (gBattleScripting.savedBattler & 0xF0) >> 4;
                gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
                BattleScriptExecute(BattleScript_DancerActivates);
                effect++;
            }
        }
        
        break;
    case ABILITYEFFECT_IMMUNITY: // 5
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            switch (GetBattlerAbility(battler))
            {
            case ABILITY_IMMUNITY:
                if (gBattleMons[battler].status1 & (STATUS1_POISON | STATUS1_TOXIC_POISON | STATUS1_TOXIC_COUNTER))
                {
                    StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
                    effect = 1;
                }
                break;
            case ABILITY_OWN_TEMPO:
            case ABILITY_DISCIPLINE:
                if (gBattleMons[battler].status2 & STATUS2_CONFUSION)
                {
                    StringCopy(gBattleTextBuff1, gStatusConditionString_ConfusionJpn);
                    effect = 2;
                }
                break;
            case ABILITY_LIMBER:
                if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
                {
                    StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
                    effect = 1;
                }
                break;
            case ABILITY_INSOMNIA:
            case ABILITY_VITAL_SPIRIT:
                if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                {
                    gBattleMons[battler].status2 &= ~(STATUS2_NIGHTMARE);
                    StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                    effect = 1;
                }
                break;
            case ABILITY_PURIFYING_WATERS:
            case ABILITY_WATER_VEIL:
            case ABILITY_WATER_BUBBLE:
                if (gBattleMons[battler].status1 & STATUS1_BURN)
                {
                    StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                    effect = 1;
                }
                break;
            case ABILITY_MAGMA_ARMOR:
                if (gBattleMons[battler].status1 & (STATUS1_FREEZE | STATUS1_FROSTBITE))
                {
                    StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);
                    effect = 1;
                }
                break;
            case ABILITY_OBLIVIOUS:
                if (gBattleMons[battler].status2 & STATUS2_INFATUATION)
                    effect = 3;
                else if (gDisableStructs[battler].tauntTimer != 0)
                    effect = 4;
                break;
            }

            //Innates
            //Purifying Salt
            if (BATTLER_HAS_ABILITY(battler, ABILITY_PURIFYING_SALT))
            {
                if (gBattleMons[battler].status1 & STATUS1_ANY)
                {
                    u32 status1 = gBattleMons[battler].status1;
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_PURIFYING_SALT;
                    if (status1 & (STATUS1_POISON | STATUS1_TOXIC_POISON)) StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
                    else if (status1 & STATUS1_BLEED) StringCopy(gBattleTextBuff1, gStatusConditionString_BleedJpn);
                    else if (status1 & STATUS1_BURN) StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                    else if (status1 & STATUS1_FROSTBITE) StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);
                    else if (status1 & STATUS1_SLEEP) StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                    else StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
                    effect = 1;
                }
            }

            //Immunity
            if(BattlerHasInnate(battler, ABILITY_IMMUNITY)){
                if (gBattleMons[battler].status1 & (STATUS1_POISON | STATUS1_TOXIC_POISON | STATUS1_TOXIC_COUNTER))
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_IMMUNITY;
                    StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
                    effect = 1;
                }
            }

            //Own Tempo
            if(BattlerHasInnate(battler, ABILITY_OWN_TEMPO)){
                if (gBattleMons[battler].status2 & STATUS2_CONFUSION)
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_OWN_TEMPO;
                    StringCopy(gBattleTextBuff1, gStatusConditionString_ConfusionJpn);
                    effect = 2;
                }
            }

            //Discipline
            if(BattlerHasInnate(battler, ABILITY_DISCIPLINE)){
                if (gBattleMons[battler].status2 & STATUS2_CONFUSION)
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_DISCIPLINE;
                    StringCopy(gBattleTextBuff1, gStatusConditionString_ConfusionJpn);
                    effect = 2;
                }
            }

            //Limber
            if(BattlerHasInnate(battler, ABILITY_LIMBER)){
                if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_LIMBER;
                    StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
                    effect = 1;
                }
            }

            //Insomnia
            if(BattlerHasInnate(battler, ABILITY_INSOMNIA)){
                if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_INSOMNIA;
                    gBattleMons[battler].status2 &= ~(STATUS2_NIGHTMARE);
                    StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                    effect = 1;
                }
            }

            //Vital Spirit
            if(BattlerHasInnate(battler, ABILITY_VITAL_SPIRIT)){
                if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_VITAL_SPIRIT;
                    gBattleMons[battler].status2 &= ~(STATUS2_NIGHTMARE);
                    StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                    effect = 1;
                }
            }

            //Water Veil
            if(BattlerHasInnate(battler, ABILITY_WATER_VEIL)){
                if (gBattleMons[battler].status1 & STATUS1_BURN)
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_WATER_VEIL;
                    StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                    effect = 1;
                }
            }

            //Purifying Waters
            if(BATTLER_HAS_ABILITY(battler, ABILITY_PURIFYING_WATERS)){
                if (gBattleMons[battler].status1 & STATUS1_BURN)
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_PURIFYING_WATERS;
                    StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                    effect = 1;
                }
            }

            //Water Bubble
            if(BattlerHasInnate(battler, ABILITY_WATER_BUBBLE)){
                if (gBattleMons[battler].status1 & STATUS1_BURN)
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_WATER_BUBBLE;
                    StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                    effect = 1;
                }
            }

            //Magma Armor
            if(BattlerHasInnate(battler, ABILITY_MAGMA_ARMOR)){
                if (gBattleMons[battler].status1 & (STATUS1_FREEZE | STATUS1_FROSTBITE))
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_MAGMA_ARMOR;
                    StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);
                    effect = 1;
                }
            }

            //Oblivious
            if(BattlerHasInnate(battler, ABILITY_OBLIVIOUS)){
                if (gBattleMons[battler].status2 & STATUS2_INFATUATION){
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_OBLIVIOUS;
                    effect = 3;
                }
                else if (gDisableStructs[battler].tauntTimer != 0){
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_OBLIVIOUS;
                    effect = 4;
                }
            }

            if (effect)
            {
                switch (effect)
                {
                case 1: // status cleared
                    gBattleMons[battler].status1 = 0;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_AbilityCuredStatus;
                    break;
                case 2: // get rid of confusion
                    gBattleMons[battler].status2 &= ~(STATUS2_CONFUSION);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_AbilityCuredStatus;
                    break;
                case 3: // get rid of infatuation
                    gBattleMons[battler].status2 &= ~(STATUS2_INFATUATION);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BattlerGotOverItsInfatuation;
                    break;
                case 4: // get rid of taunt
                    gDisableStructs[battler].tauntTimer = 0;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BattlerShookOffTaunt;
                    break;
                }

                gBattleScripting.battler = gActiveBattler = gBattlerAbility = battler;
                BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
                MarkBattlerForControllerExec(gActiveBattler);
                return effect;
            }
			
			//Vital Spirit & Insomnia
			if(BattlerHasInnate(battler, ABILITY_INSOMNIA) || 
               BattlerHasInnate(battler, ABILITY_VITAL_SPIRIT)){
                if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                {
                    gBattleMons[battler].status2 &= ~(STATUS2_NIGHTMARE);
                    StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                    effect = 1;
                }
			}
			
			//Oblivious
			if(BattlerHasInnate(battler, ABILITY_OBLIVIOUS)){
                if (gBattleMons[battler].status2 & STATUS2_INFATUATION)
                    effect = 3;
                else if (gDisableStructs[battler].tauntTimer != 0)
                    effect = 4;
			}
			
			// Water Veil & Water Bubble
			if(BattlerHasInnate(battler, ABILITY_WATER_VEIL) || 
               BattlerHasInnate(battler, ABILITY_WATER_BUBBLE) || 
               BattlerHasInnate(battler, ABILITY_PURIFYING_WATERS)){
                if (gBattleMons[battler].status1 & STATUS1_BURN)
                {
                    StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                    effect = 1;
                }
			}
			
        }
        break;
    case ABILITYEFFECT_FORECAST: // 6
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            if (BATTLER_HAS_ABILITY(battler, ABILITY_FORECAST) || BATTLER_HAS_ABILITY(battler, ABILITY_FLOWER_GIFT) || BATTLER_HAS_ABILITY(battler, ABILITY_ZERO_TO_HERO))
            {
                if (ShouldChangeFormHpBased(battler))
                {
                    BattleScriptPushCursorAndCallback(BattleScript_AttackerFormChangeEnd3);
                    return effect;
                }
            }
        }
        break;
    case ABILITYEFFECT_SYNCHRONIZE:
        if (gLastUsedAbility == ABILITY_SYNCHRONIZE && (gHitMarker & HITMARKER_SYNCHRONISE_EFFECT))
        {
            gHitMarker &= ~(HITMARKER_SYNCHRONISE_EFFECT);

            if (!(gBattleMons[gBattlerAttacker].status1 & STATUS1_ANY))
            {
                gBattleStruct->synchronizeMoveEffect &= ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                #if B_SYNCHRONIZE_TOXIC < GEN_5
                    if (gBattleStruct->synchronizeMoveEffect == MOVE_EFFECT_TOXIC)
                        gBattleStruct->synchronizeMoveEffect = MOVE_EFFECT_POISON;
                #endif

                gBattleScripting.moveEffect = gBattleStruct->synchronizeMoveEffect + MOVE_EFFECT_AFFECTS_USER;
                gBattleScripting.battler = gBattlerAbility = gBattlerTarget;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, ABILITY_SYNCHRONIZE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SynchronizeActivates;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
        }
        break;
    case ABILITYEFFECT_ATK_SYNCHRONIZE: // 8
        if (gLastUsedAbility == ABILITY_SYNCHRONIZE && (gHitMarker & HITMARKER_SYNCHRONISE_EFFECT))
        {
            gHitMarker &= ~(HITMARKER_SYNCHRONISE_EFFECT);

            if (!(gBattleMons[gBattlerTarget].status1 & STATUS1_ANY))
            {
                gBattleStruct->synchronizeMoveEffect &= ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                if (gBattleStruct->synchronizeMoveEffect == MOVE_EFFECT_TOXIC)
                    gBattleStruct->synchronizeMoveEffect = MOVE_EFFECT_POISON;

                gBattleScripting.moveEffect = gBattleStruct->synchronizeMoveEffect;
                gBattleScripting.battler = gBattlerAbility = gBattlerAttacker;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, ABILITY_SYNCHRONIZE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SynchronizeActivates;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
        }
        break;
    case ABILITYEFFECT_TRACE1:
    case ABILITYEFFECT_TRACE2:
        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattleMons[i].ability == ABILITY_TRACE && (gBattleResources->flags->flags[i] & RESOURCE_FLAG_TRACED))
            {
                u8 side = (GetBattlerPosition(i) ^ BIT_SIDE) & BIT_SIDE; // side of the opposing pokemon
                u8 target1 = GetBattlerAtPosition(side);
                u8 target2 = GetBattlerAtPosition(side + BIT_FLANK);

                if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                {
                    if (!IsRolePlayBannedAbility(gBattleMons[target1].ability) && gBattleMons[target1].hp != 0
                     && !IsRolePlayBannedAbility(gBattleMons[target2].ability) && gBattleMons[target2].hp != 0)
                        gActiveBattler = GetBattlerAtPosition(((Random() & 1) * 2) | side), effect++;
                    else if (!IsRolePlayBannedAbility(gBattleMons[target1].ability) && gBattleMons[target1].hp != 0)
                        gActiveBattler = target1, effect++;
                    else if (!IsRolePlayBannedAbility(gBattleMons[target2].ability) && gBattleMons[target2].hp != 0)
                        gActiveBattler = target2, effect++;
                }
                else
                {
                    if (!IsRolePlayBannedAbility(gBattleMons[target1].ability) && gBattleMons[target1].hp != 0)
                        gActiveBattler = target1, effect++;
                }

                if (effect)
                {
                    if (caseID == ABILITYEFFECT_TRACE1)
                    {
                        BattleScriptPushCursorAndCallback(BattleScript_TraceActivatesEnd3);
                    }
                    else
                    {
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_TraceActivates;
                    }
                    gBattleResources->flags->flags[i] &= ~(RESOURCE_FLAG_TRACED);
                    gBattleStruct->tracedAbility[i] = gLastUsedAbility = gBattleMons[gActiveBattler].ability;
                    battler = gBattlerAbility = gBattleScripting.battler = i;

                    PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gActiveBattler, gBattlerPartyIndexes[gActiveBattler])
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff2, gLastUsedAbility)
                    break;
                }
            }
        }
        break;
    case ABILITYEFFECT_NEUTRALIZINGGAS:
        // Prints message only. separate from ABILITYEFFECT_ON_SWITCHIN bc activates before entry hazards
        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattleMons[i].ability == ABILITY_NEUTRALIZING_GAS && !(gBattleResources->flags->flags[i] & RESOURCE_FLAG_NEUTRALIZING_GAS))
            {
                gBattleResources->flags->flags[i] |= RESOURCE_FLAG_NEUTRALIZING_GAS;
                gBattlerAbility = i;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_NEUTRALIZING_GAS;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            
            if (effect)
                break;
        }
        break;
    case ABILITYEFFECT_AFTER_RECOIL:
        //Nosferatu
        if(BATTLER_HAS_ABILITY(battler, ABILITY_NOSFERATU)){
            bool8 activateAbilty = FALSE;
            u16 abilityToCheck = ABILITY_NOSFERATU; //For easier copypaste

            //Checks if the ability is triggered
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerAlive(gBattlerAttacker)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && !BATTLER_HEALING_BLOCKED(gBattlerAttacker)
             && IsMoveMakingContact(move, gBattlerAttacker)
             && !BATTLER_MAX_HP(gBattlerAttacker) 
             && TARGET_TURN_DAMAGED){
                activateAbilty = TRUE;
            }

            //This is the stuff that has to be changed for each ability
            if(activateAbilty){
                if(BattlerHasInnate(battler, abilityToCheck))
                    gBattleScripting.abilityPopupOverwrite = abilityToCheck;

                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_NosferatuActivated;
                effect++;
            }
        }
        break;
    case ABILITYEFFECT_COPY_STATS:
        if (gBattleStruct->statStageCheckState == STAT_STAGE_CHECK_NEEDED)
        {
            u8 i, statId, j;
            bool8 found = FALSE;
            for (i = 0; i < MAX_BATTLERS_COUNT; i++)
            {
                if (BATTLER_HAS_ABILITY(i, ABILITY_EGOIST))
                {
                    bool8 foundForBattler = FALSE;
                    for (statId = STAT_ATK; statId < NUM_NATURE_STATS; statId++)
                    {
                        u8 change = 0;
                        for (j = 0; j < MAX_BATTLERS_COUNT; j++)
                        {
                            if (GetBattlerSide(i) == GetBattlerSide(j)) continue;
                            if (gBattleStruct->statChangesToCheck[j][statId - 1] > 0)
                            {
                                found = foundForBattler = TRUE;
                                SetAbilityStateAs(i, ABILITY_EGOIST, (union AbilityStates) { .statCopyState = (struct StatCopyState) { .inProgress = TRUE } });
                            }
                        }
                        if (foundForBattler) break;
                    }
                }
            }

            battler = IsAbilityOnField(ABILITY_SHARING_IS_CARING) - 1;
            if ((s8)battler > 0)
            {
                found = TRUE;
                SetAbilityStateAs(i, ABILITY_SHARING_IS_CARING, (union AbilityStates) { .statCopyState = (struct StatCopyState) { .inProgress = TRUE } });
            }

            if (found)
            {
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_PerformCopyStatEffects;
                effect++;
            }
            else
            {
                memset(gBattleStruct->statChangesToCheck, 0, sizeof(gBattleStruct->statChangesToCheck));
                gBattleStruct->statStageCheckState = STAT_STAGE_CHECK_NOT_NEEDED;
            }
        }
        break;
        case ABILITYEFFECT_ATTACKER_FOLLOWUP_MOVE:
            #define CHECK_ABILITY(ability) (BATTLER_HAS_ABILITY(battler, ability) && CheckAndSetOncePerTurnAbility(battler, ability))

            //Weather Cast
            if(CHECK_ABILITY(ABILITY_FORECAST)){
                switch (move) {
                    case MOVE_SUNNY_DAY:
                    case MOVE_RAIN_DANCE:
                    case MOVE_SANDSTORM:
                    case MOVE_HAIL:
                        gBattlerTarget = GetMoveTarget(MOVE_WEATHER_BALL, 0);
                        if (!CanUseExtraMove(gBattlerAttacker, gBattlerTarget)) break;
                        return UseAttackerFollowUpMove(battler, ABILITY_FORECAST, MOVE_WEATHER_BALL, 0, 0, 0);
                }
            }

            if (!CanUseExtraMove(gBattlerAttacker, gBattlerTarget)) break;

            //Volcano Rage
            if(CHECK_ABILITY(ABILITY_VOLCANO_RAGE)){

                if(!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) &&
                    (GetTypeBeforeUsingMove(move, battler) == TYPE_FIRE)){
                    return UseAttackerFollowUpMove(battler, ABILITY_VOLCANO_RAGE, MOVE_ERUPTION, 50, 0, 0);
                }
            }

            //Frost Burn
            if(CHECK_ABILITY(ABILITY_FROST_BURN)){

                if(!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) &&
                    (GetTypeBeforeUsingMove(move, battler) == TYPE_FIRE)){
                    return UseAttackerFollowUpMove(battler, ABILITY_FROST_BURN, MOVE_ICE_BEAM, 40, 0, 0);
                }
            }

            //Pryo Shells
            if(CHECK_ABILITY(ABILITY_PYRO_SHELLS)){

                //Checks if the ability is triggered
                if(!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) &&
                    (gBattleMoves[move].flags & FLAG_MEGA_LAUNCHER_BOOST)){
                    return UseAttackerFollowUpMove(battler, ABILITY_PYRO_SHELLS, MOVE_OUTBURST, 50, 0, 0);
                }
            }

            //Thundercall
            if(CHECK_ABILITY(ABILITY_THUNDERCALL)){

                //Checks if the ability is triggered
                if(!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) &&
                    (GetTypeBeforeUsingMove(move, battler) == TYPE_ELECTRIC)){
                    return UseAttackerFollowUpMove(battler, ABILITY_THUNDERCALL, MOVE_SMITE, 20, 0, 0);
                }
            }

            //Aftershock
            if(CHECK_ABILITY(ABILITY_AFTERSHOCK)){

                //Checks if the ability is triggered
                if(!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) &&
                    gBattleMoves[move].power){
                    return UseAttackerFollowUpMove(battler, ABILITY_AFTERSHOCK, MOVE_MAGNITUDE, 65, 0, 0);
                }
            }

            //High Tide
            if(CHECK_ABILITY(ABILITY_HIGH_TIDE)){

                //Checks if the ability is triggered
                if(!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) &&
                    (GetTypeBeforeUsingMove(move, battler) == TYPE_WATER)){
                    return UseAttackerFollowUpMove(battler, ABILITY_HIGH_TIDE, MOVE_SURF, 50, 0, 0);
                }
            }

            //Two Step
            if(CHECK_ABILITY(ABILITY_TWO_STEP)){

                //Checks if the ability is triggered
                if(!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) &&
                    gBattleMoves[move].flags & FLAG_DANCE) {
                    return UseAttackerFollowUpMove(battler, ABILITY_TWO_STEP, MOVE_REVELATION_DANCE, 50, 0, 0);
                }
            }
            #undef CHECK_ABILITY
        break;
        case ABILITYEFFECT_MOVE_END_EITHER:
            opponent = battler == gBattlerAttacker ? gBattlerTarget : gBattlerAttacker;
            effectTargetFlag = opponent == gBattlerAttacker ? MOVE_EFFECT_AFFECTS_USER : 0;

            if(BATTLER_HAS_ABILITY(battler, ABILITY_STATIC)){
                if (ShouldApplyOnHitAffect(opponent)
                && CanBeParalyzed(battler, opponent)
                && IsMoveMakingContact(move, gBattlerAttacker)
                && (Random() % 100) < 30)
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_STATIC;
                    gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS | effectTargetFlag;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                    gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                    effect++;
                }
            }
            
            // Flame Body
            if(BATTLER_HAS_ABILITY(battler, ABILITY_FLAME_BODY)){
                if (ShouldApplyOnHitAffect(opponent)
                && CanBeBurned(gBattlerAttacker)
                && IsMoveMakingContact(move, gBattlerAttacker)
                && (Random() % 100) < 30)
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_FLAME_BODY;
                    gBattleScripting.moveEffect = MOVE_EFFECT_BURN | effectTargetFlag;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                    gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                    effect++;
                }
            }
            
            // Super Hot Goo
            if(BATTLER_HAS_ABILITY(battler, ABILITY_SUPER_HOT_GOO)){
                if (ShouldApplyOnHitAffect(opponent)
                && CanBeBurned(gBattlerAttacker)
                && IsMoveMakingContact(move, gBattlerAttacker)
                && (Random() % 100) < 30)
                {
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_SUPER_HOT_GOO;
                    gBattleScripting.moveEffect = MOVE_EFFECT_BURN | effectTargetFlag;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                    gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                    effect++;
                }
            }

            // Poison Point
            if(BATTLER_HAS_ABILITY(battler, ABILITY_POISON_POINT)){
                if (ShouldApplyOnHitAffect(opponent)
                    && CanBePoisoned(battler, opponent)
                    && IsMoveMakingContact(move, gBattlerAttacker)
                    && (Random() % 100) < 30)
                    {
                        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_POISON_POINT;
                        gBattleScripting.moveEffect = MOVE_EFFECT_POISON | effectTargetFlag;
                        PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                        gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                        effect++;
                    }
            }

            // Poison Touch
            if(BATTLER_HAS_ABILITY(battler, ABILITY_POISON_TOUCH)){
                if (ShouldApplyOnHitAffect(opponent)
                    && CanBePoisoned(battler, opponent)
                    && IsMoveMakingContact(move, gBattlerAttacker)
                    && (Random() % 100) < 30)
                    {
                        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_POISON_TOUCH;
                        gBattleScripting.moveEffect = MOVE_EFFECT_POISON | effectTargetFlag;
                        PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                        gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                        effect++;
                    }
            }

            // Freezing Point
            if(BATTLER_HAS_ABILITY(battler, ABILITY_FREEZING_POINT)){
                if (ShouldApplyOnHitAffect(opponent)
                    && CanGetFrostbite(opponent)
                    && IsMoveMakingContact(move, gBattlerAttacker)
                    && (Random() % 100) < 30)
                    {
                        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_FREEZING_POINT;
                        gBattleScripting.moveEffect = MOVE_EFFECT_FROSTBITE | effectTargetFlag;
                        PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                        gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                        effect++;
                    }
            }

            // Cryo Proficiency
            if(BATTLER_HAS_ABILITY(battler, ABILITY_CRYO_PROFICIENCY)){
                if (ShouldApplyOnHitAffect(opponent)
                    && CanGetFrostbite(opponent)
                    && IsMoveMakingContact(move, gBattlerAttacker)
                    && (Random() % 100) < 30)
                    {
                        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_CRYO_PROFICIENCY;
                        gBattleScripting.moveEffect = MOVE_EFFECT_FROSTBITE | effectTargetFlag;
                        PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                        gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                        effect++;
                    }
            }
            
            // Spike Armor
            if(BATTLER_HAS_ABILITY(battler, ABILITY_SPIKE_ARMOR)){
                if(ShouldApplyOnHitAffect(opponent)
                && IsMoveMakingContact(move, gBattlerAttacker)
                && CanBleed(opponent)
                && (Random() % 100) < 30){
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_SPIKE_ARMOR;
                    gBattleScripting.moveEffect = MOVE_EFFECT_BLEED | effectTargetFlag;
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                    gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                    effect++;
                }
            }
        break;
    }

    if (effect && gLastUsedAbility != 0xFF)
        RecordAbilityBattle(battler, gLastUsedAbility);
    if (effect && caseID <= ABILITYEFFECT_MOVE_END)
        gBattlerAbility = battler;

    return effect;
}

bool32 IsUnsuppressableAbility(u32 ability)
{
    switch (ability)
    {
    case ABILITY_MULTITYPE:
    case ABILITY_ZEN_MODE:
    case ABILITY_STANCE_CHANGE:
    case ABILITY_POWER_CONSTRUCT:
    case ABILITY_SCHOOLING:
    case ABILITY_RKS_SYSTEM:
    case ABILITY_ZERO_TO_HERO:
    case ABILITY_SHIELDS_DOWN:
    case ABILITY_COMATOSE:
    case ABILITY_DISGUISE:
    case ABILITY_GULP_MISSILE:
    case ABILITY_ICE_FACE:
    case ABILITY_AS_ONE_ICE_RIDER:
    case ABILITY_AS_ONE_SHADOW_RIDER:
    case ABILITY_CROWNED_KING:
    case ABILITY_EJECT_PACK_ABILITY:
    case ABILITY_CHEATING_DEATH:
    case ABILITY_GALLANTRY:
    case ABILITY_WISHMAKER:
    case ABILITY_CLUELESS:
    case ABILITY_BATTLE_BOND:
    case ABILITY_NEUTRALIZING_GAS:
    case ABILITY_HUNGER_SWITCH:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsNeutralizingGasOnField(void)
{
    u32 i;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (IsBattlerAlive(i) && gBattleMons[i].ability == ABILITY_NEUTRALIZING_GAS && !(gStatuses3[i] & STATUS3_GASTRO_ACID))
            return TRUE;
    }

    return FALSE;
}

u32 GetBattlerAbility(u8 battlerId)
{
    if (!DoesBattlerHaveAbilityShield(battlerId))
    {
        if (BattlerAbilityIsSuppressed(battlerId)) return ABILITY_NONE;
    }
    
    return GetBattlerAbilityWithoutRemoval(battlerId);
}

bool8 BattlerAbilityIsSuppressed(u8 battlerId)
{
    if(BattlerAbilityWasRemoved(battlerId, gBattleMons[battlerId].ability))
        return TRUE;
    
    if (BattlerIgnoresAbility(gBattlerAttacker, battlerId, gBattleMons[battlerId].ability))
        return TRUE;

    return FALSE;
}

u32 GetBattlerAbilityWithoutRemoval(u8 battlerId)
{
    return gBattleMons[battlerId].ability;
}

bool8 BattlerIgnoresAbility(u8 sBattlerAttacker, u8 sBattlerTarget, u16 ability)
{
    u16 abilityAtk  = gBattleMons[sBattlerAttacker].ability;
    u16 species     = gBattleMons[sBattlerAttacker].species;
    u16 level       = gBattleMons[sBattlerAttacker].level;
    u32 personality = gBattleMons[sBattlerAttacker].personality;
    bool8 isEnemyMon = GetBattlerSide(sBattlerAttacker) == B_SIDE_OPPONENT;

    //Don't ignore own ability
    if (sBattlerAttacker == sBattlerTarget)
        return FALSE;

    //Check that the battler is currently attacking the target
    if(gBattlerByTurnOrder[gCurrentTurnActionNumber] != sBattlerAttacker                ||
        gActionsByTurnOrder[gBattlerByTurnOrder[sBattlerAttacker]] != B_ACTION_USE_MOVE ||
        gCurrentTurnActionNumber >= gBattlersCount)
        return FALSE;

    //Ability is unaffected by Mold Breaker
    if(sAbilitiesAffectedByMoldBreaker[ability] == 0)
        return FALSE;

    //Move ignores target ability regardless if it has Mold Breaker
    if(gBattleMoves[gCurrentMove].flags & FLAG_TARGET_ABILITY_IGNORED &&
       GetBattlerSide(sBattlerAttacker) != GetBattlerSide(sBattlerTarget))
        return TRUE;
    
    //Attacker Ability is suppressed so it can't ignore target ability
    if((gStatuses3[sBattlerAttacker] & STATUS3_GASTRO_ACID) ||
        GetBattlerSide(sBattlerAttacker) == GetBattlerSide(sBattlerTarget))
        return FALSE;

    //Check if the attacker has any Mold Breaker Variant
    switch(abilityAtk){
        case ABILITY_MOLD_BREAKER:
        case ABILITY_TERAVOLT:
        case ABILITY_TURBOBLAZE:
            return TRUE;
            break;
        default:
            if(SpeciesHasInnate(species, ABILITY_MOLD_BREAKER, level, personality, isEnemyMon, isEnemyMon) ||
               SpeciesHasInnate(species, ABILITY_TERAVOLT,     level, personality, isEnemyMon, isEnemyMon) ||
               SpeciesHasInnate(species, ABILITY_TURBOBLAZE,   level, personality, isEnemyMon, isEnemyMon))
            return TRUE;
        break;
    }
    
    return FALSE;
}

bool8 BattlerAbilityWasRemoved(u8 battlerId, u32 ability)
{
    if ((gStatuses3[battlerId] & STATUS3_GASTRO_ACID) ||
       (IsNeutralizingGasOnField() && !IsUnsuppressableAbility(ability)))
        return TRUE;
    else
        return FALSE;
}

u32 IsAbilityOnSide(u32 battlerId, u32 ability)
{
    if (IsBattlerAlive(battlerId) && GetBattlerAbility(battlerId) == ability)
        return battlerId + 1;
	else if (IsBattlerAlive(battlerId) && BattlerHasInnate(battlerId, ability))
        return battlerId + 1;
    else if (IsBattlerAlive(BATTLE_PARTNER(battlerId)) && GetBattlerAbility(BATTLE_PARTNER(battlerId)) == ability)
        return BATTLE_PARTNER(battlerId) + 1;
	else if (IsBattlerAlive(BATTLE_PARTNER(battlerId)) && BattlerHasInnate(BATTLE_PARTNER(battlerId), ability))
        return BATTLE_PARTNER(battlerId) + 1;
    else
        return 0;
}

u32 IsAbilityOnOpposingSide(u32 battlerId, u32 ability)
{
    return IsAbilityOnSide(BATTLE_OPPOSITE(battlerId), ability);
}

u32 IsAbilityOnField(u32 ability)
{
    u32 i;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (IsBattlerAlive(i) && (GetBattlerAbility(i) == ability || 
            BattlerHasInnate(i, ability)))
            return i + 1;
    }

    return 0;
}

u32 IsAbilityOnFieldExcept(u32 battlerId, u32 ability)
{
    u32 i;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (i != battlerId && IsBattlerAlive(i) && (GetBattlerAbility(i) == ability || 
            BattlerHasInnate(i, ability)))
            return i + 1;
    }

    return 0;
}

u32 IsAbilityPreventingEscape(u32 battlerId)
{
    u32 id;
    if(ItemId_GetHoldEffect(gBattleMons[battlerId].item) == HOLD_EFFECT_SHED_SHELL)
        return 0;
    #if B_GHOSTS_ESCAPE >= GEN_6
        if (IS_BATTLER_OF_TYPE(battlerId, TYPE_GHOST))
            return 0;
    #endif
    #if B_SHADOW_TAG_ESCAPE >= GEN_4
        if ((id = IsAbilityOnOpposingSide(battlerId, ABILITY_SHADOW_TAG)) && GetBattlerAbility(battlerId) != ABILITY_SHADOW_TAG)
    #else
        if (id = IsAbilityOnOpposingSide(battlerId, ABILITY_SHADOW_TAG))
    #endif
        return id;
    if ((id = IsAbilityOnOpposingSide(battlerId, ABILITY_ARENA_TRAP)) && IsBattlerGrounded(battlerId))
        return id;
    if ((id = IsAbilityOnOpposingSide(battlerId, ABILITY_MAGNET_PULL)) && IS_BATTLER_OF_TYPE(battlerId, TYPE_STEEL))
        return id;

    return 0;
}

bool32 CanBattlerEscape(u32 battlerId) // no ability check
{
    if (GetBattlerHoldEffect(battlerId, TRUE) == HOLD_EFFECT_SHED_SHELL)
        return TRUE;
    else if ((B_GHOSTS_ESCAPE >= GEN_6 && !IS_BATTLER_OF_TYPE(battlerId, TYPE_GHOST)) && gBattleMons[battlerId].status2 & (STATUS2_ESCAPE_PREVENTION | STATUS2_WRAPPED))
        return FALSE;
    else if (gStatuses3[battlerId] & STATUS3_ROOTED)
        return FALSE;
    else if (gFieldStatuses & STATUS_FIELD_FAIRY_LOCK)
        return FALSE;
    else
        return TRUE;
}

void BattleScriptExecute(const u8 *BS_ptr)
{
    gBattlescriptCurrInstr = BS_ptr;
    gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size++] = gBattleMainFunc;
    gBattleMainFunc = RunBattleScriptCommands_PopCallbacksStack;
    gCurrentActionFuncId = 0;
}

void BattleScriptPushCursorAndCallback(const u8 *BS_ptr)
{
    BattleScriptPushCursor();
    gBattlescriptCurrInstr = BS_ptr;
    gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size++] = gBattleMainFunc;
    gBattleMainFunc = RunBattleScriptCommands;
}

enum
{
    ITEM_NO_EFFECT, // 0
    ITEM_STATUS_CHANGE, // 1
    ITEM_EFFECT_OTHER, // 2
    ITEM_PP_CHANGE, // 3
    ITEM_HP_CHANGE, // 4
    ITEM_STATS_CHANGE, // 5
};

bool32 IsBattlerTerrainAffected(u8 battlerId, u32 terrainFlag)
{
    if(!TERRAIN_HAS_EFFECT)
        return FALSE;
    else if (!(gFieldStatuses & terrainFlag))
        return FALSE;
    else if (gStatuses3[battlerId] & STATUS3_SEMI_INVULNERABLE)
        return FALSE;
    
    return IsBattlerGrounded(battlerId);
}

bool8 IsSleepDisabled(u8 battlerId){
    //Sleep Clause
    struct Pokemon *party;
    u8 asleepmons = 0;
    u8 i;

    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if ((GetMonData(&party[i], MON_DATA_STATUS) & (STATUS1_SLEEP)) &&   
            GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG  &&
            GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE)
            asleepmons++;
    }

    if(asleepmons != 0)
        return TRUE;
    else
        return FALSE;
}

bool8 IsSleepClauseDisablingMove(u8 battlerId, u16 move)
{
    u32 target = BATTLE_OPPOSITE(battlerId);
    u16 moveEffect = gBattleMoves[move].effect;
    bool8 isSleepingMove = FALSE;
    u16 partnerchosenmove = gChosenMoveByBattler[BATTLE_PARTNER(battlerId)];
    bool8 IsDoubleBattle = FALSE;
    bool8 partnerChoseSleepMove = FALSE;

    if(gSaveBlock2Ptr->gameDifficulty == DIFFICULTY_EASY) //Sleep Clause is disabled in easy mode
        return FALSE;

    if((gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        IsDoubleBattle = TRUE;

    if(!IsBattlerAlive(BATTLE_PARTNER(battlerId)) || !IsDoubleBattle)
        partnerchosenmove = MOVE_NONE;

    switch(moveEffect){
        case EFFECT_SLEEP:
        case EFFECT_YAWN:
            isSleepingMove = TRUE;
        break;
        default:
            return FALSE;
        break;
    }

    if(IsDoubleBattle){
        switch(gBattleMoves[partnerchosenmove].effect){
            case EFFECT_SLEEP:
            case EFFECT_YAWN:
                partnerChoseSleepMove = TRUE;
            break;
        }
    }

    if(partnerChoseSleepMove && isSleepingMove && IsDoubleBattle) //To speed up things
        return TRUE;
    else if(IsSleepDisabled(target) && isSleepingMove)
        return TRUE;
    else
        return FALSE;
}

bool8 CanBeDisabled(u8 battlerId)
{
    if (gDisableStructs[battlerId].disabledMove
        || IsAbilityOnSide(battlerId, ABILITY_AROMA_VEIL))
        return FALSE;
    return TRUE;
}

bool32 CanSleep(u8 battlerId)
{
    u16 ability = GetBattlerAbility(battlerId);

    if (gBattleMons[battlerId].status1 & !STATUS1_ANY && IsMyceliumMightActive(gBattlerAttacker))
        return TRUE;

    if (BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_INSOMNIA, ability)
      || BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_VITAL_SPIRIT, ability)
      || gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_SAFEGUARD
      || gBattleMons[battlerId].status1 & STATUS1_ANY
      || IsAbilityOnSide(battlerId, ABILITY_SWEET_VEIL)
      || IsAbilityStatusProtected(battlerId)
      || IsBattlerTerrainAffected(battlerId, STATUS_FIELD_ELECTRIC_TERRAIN | STATUS_FIELD_MISTY_TERRAIN))
        return FALSE;
    return TRUE;
}

bool32 CanBePoisoned(u8 battlerAttacker, u8 battlerTarget)
{
    u16 ability = GetBattlerAbility(battlerTarget);

    if (gBattleMons[battlerTarget].status1 & !STATUS1_ANY && IsMyceliumMightActive(battlerAttacker))
        return TRUE;
        
    if (!(CanPoisonType(battlerAttacker, battlerTarget))
     || gSideStatuses[GetBattlerSide(battlerTarget)] & SIDE_STATUS_SAFEGUARD
     || gBattleMons[battlerTarget].status1 & STATUS1_ANY
     || BATTLER_HAS_ABILITY_FAST(battlerTarget, ABILITY_IMMUNITY, ability)
     || gBattleMons[battlerTarget].status1 & STATUS1_ANY
     || IsAbilityStatusProtected(battlerTarget)
     || IsBattlerTerrainAffected(battlerTarget, STATUS_FIELD_MISTY_TERRAIN))
        return FALSE;
    return TRUE;
}

bool32 CanBeBurned(u8 battlerId)
{
    u16 ability = GetBattlerAbility(battlerId);

    if (gBattleMons[battlerId].status1 & !STATUS1_ANY && IsMyceliumMightActive(gBattlerAttacker))
        return TRUE;

    if (IS_BATTLER_OF_TYPE(battlerId, TYPE_FIRE)
      || gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_SAFEGUARD
      || gBattleMons[battlerId].status1 & STATUS1_ANY
      || BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_WATER_VEIL, ability)
      || BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_PURIFYING_WATERS, ability)
      || BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_WATER_BUBBLE, ability)
      || BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_THERMAL_EXCHANGE, ability)
      || IsAbilityStatusProtected(battlerId)
      || IsBattlerTerrainAffected(battlerId, STATUS_FIELD_MISTY_TERRAIN))
        return FALSE;
    return TRUE;
}

bool32 CanBeParalyzed(u8 battlerAttacker, u8 battlerTarget)
{
    u16 ability = GetBattlerAbility(battlerTarget);

    if (gBattleMons[battlerTarget].status1 & !STATUS1_ANY && IsMyceliumMightActive(battlerAttacker))
        return TRUE;

    if ((!CanParalyzeType(battlerAttacker, battlerTarget))
      || gSideStatuses[GetBattlerSide(battlerTarget)] & SIDE_STATUS_SAFEGUARD
      || BATTLER_HAS_ABILITY_FAST(battlerTarget, ABILITY_LIMBER, ability)
      || BATTLER_HAS_ABILITY_FAST(battlerTarget, ABILITY_JUGGERNAUT, ability)
      || gBattleMons[battlerTarget].status1 & STATUS1_ANY
      || IsAbilityStatusProtected(battlerTarget)
      || IsBattlerTerrainAffected(battlerTarget, STATUS_FIELD_MISTY_TERRAIN))
        return FALSE;
    return TRUE;
}

bool32 CanBeFrozen(u8 battlerId)
{
    u16 ability = GetBattlerAbility(battlerId);
    if (IS_BATTLER_OF_TYPE(battlerId, TYPE_ICE)
      || IsBattlerWeatherAffected(battlerId, WEATHER_SUN_ANY)
      || gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_SAFEGUARD
      || BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_MAGMA_ARMOR, battlerId)
      || gBattleMons[battlerId].status1 & STATUS1_ANY
      || IsAbilityStatusProtected(battlerId)
      || IsBattlerTerrainAffected(battlerId, STATUS_FIELD_MISTY_TERRAIN))
        return FALSE;
    return TRUE;
}

bool32 CanGetFrostbite(u8 battlerId)
{
    if (gBattleMons[battlerId].status1 & !STATUS1_ANY && IsMyceliumMightActive(gBattlerAttacker))
        return TRUE;

    if (IS_BATTLER_OF_TYPE(battlerId, TYPE_ICE)
      || gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_SAFEGUARD
      || gBattleMons[battlerId].status1 & STATUS1_ANY
      || IsAbilityStatusProtected(battlerId)
      || IsBattlerTerrainAffected(battlerId, STATUS_FIELD_MISTY_TERRAIN))
        return FALSE;
    return TRUE;
}

bool32 CanBleed(u8 battlerId)
{
    if (gBattleMons[battlerId].status1 & !STATUS1_ANY && IsMyceliumMightActive(gBattlerAttacker))
        return TRUE;

    if (IS_BATTLER_OF_TYPE(battlerId, TYPE_ROCK)
        || IS_BATTLER_OF_TYPE(battlerId, TYPE_GHOST)
        || gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_SAFEGUARD
        || gBattleMons[battlerId].status1 & STATUS1_ANY
        || IsAbilityStatusProtected(battlerId)
        || IsBattlerTerrainAffected(battlerId, STATUS_FIELD_MISTY_TERRAIN))
        return FALSE;
    return TRUE;
}

bool32 CanBeConfused(u8 battlerId)
{
    if (gBattleMons[battlerId].status2 & !STATUS2_CONFUSION && IsMyceliumMightActive(gBattlerAttacker))
        return TRUE;

    if (BATTLER_HAS_ABILITY(gEffectBattler, ABILITY_OWN_TEMPO)
      || BATTLER_HAS_ABILITY(gEffectBattler, ABILITY_DISCIPLINE)
      || gBattleMons[gEffectBattler].status2 & STATUS2_CONFUSION
      || IsBattlerTerrainAffected(battlerId, STATUS_FIELD_MISTY_TERRAIN))
        return FALSE;
    return TRUE;
}

// second argument is 1/X of current hp compared to max hp
bool32 HasEnoughHpToEatBerry(u32 battlerId, u32 hpFraction, u32 itemId)
{
    bool32 isBerry = (ItemId_GetPocket(itemId) == POCKET_BERRIES);

    if (gBattleMons[battlerId].hp == 0)
        return FALSE;
    if (gBattleScripting.overrideBerryRequirements)
        return TRUE;
    // Unnerve prevents consumption of opponents' berries.
    if (isBerry && IsUnnerveAbilityOnOpposingSide(battlerId))
        return FALSE;
    if (gBattleMons[battlerId].hp <= gBattleMons[battlerId].maxHP / hpFraction)
        return TRUE;

    if (hpFraction <= 4 && (GetBattlerAbility(battlerId) == ABILITY_GLUTTONY || BattlerHasInnate(battlerId, ABILITY_GLUTTONY)) && isBerry
         && gBattleMons[battlerId].hp <= gBattleMons[battlerId].maxHP / 2)
    {
        RecordAbilityBattle(battlerId, ABILITY_GLUTTONY);
        return TRUE;
    }

    return FALSE;
}

static u8 HealConfuseBerry(u32 battlerId, u32 itemId, u8 flavorId, bool32 end2)
{
    if (HasEnoughHpToEatBerry(battlerId, 4, itemId))
    {
        PREPARE_FLAVOR_BUFFER(gBattleTextBuff1, flavorId);

        gBattleMoveDamage = gBattleMons[battlerId].maxHP / GetBattlerHoldEffectParam(battlerId);
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;

        if (BATTLER_HAS_ABILITY(battlerId, ABILITY_RIPEN))
        {
            gBattleMoveDamage *= 2;
            gBattlerAbility = battlerId;
        }
        gBattleScripting.battler = battlerId;
        if (end2)
        {
            if (GetFlavorRelationByNature(gBattleMons[battlerId].nature, flavorId) < 0)
                BattleScriptExecute(BattleScript_BerryConfuseHealEnd2);
            else
                BattleScriptExecute(BattleScript_ItemHealHP_RemoveItemEnd2);
        }
        else
        {
            BattleScriptPushCursor();
            if (GetFlavorRelationByNature(gBattleMons[battlerId].nature, flavorId) < 0)
                gBattlescriptCurrInstr = BattleScript_BerryConfuseHealRet;
            else
                gBattlescriptCurrInstr = BattleScript_ItemHealHP_RemoveItemRet;
        }

        return ITEM_HP_CHANGE;
    }
    return 0;
}

static u8 StatRaiseBerry(u32 battlerId, u32 itemId, u32 statId, bool32 end2)
{
    if (CompareStat(battlerId, statId, MAX_STAT_STAGE, CMP_LESS_THAN) && HasEnoughHpToEatBerry(battlerId, GetBattlerHoldEffectParam(battlerId), itemId))
    {
        BufferStatChange(battlerId, statId, STRINGID_STATROSE);
        gEffectBattler = battlerId;
        if (BATTLER_HAS_ABILITY(battlerId, ABILITY_RIPEN))
            SET_STATCHANGER(statId, 2, FALSE);
        else
            SET_STATCHANGER(statId, 1, FALSE);

        gBattleScripting.animArg1 = 14 + statId;
        gBattleScripting.animArg2 = 0;

        if (end2)
        {
            BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
        }
        else
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryStatRaiseRet;
        }
        return ITEM_STATS_CHANGE;
    }
    return 0;
}

static u8 RandomStatRaiseBerry(u32 battlerId, u32 itemId, bool32 end2)
{
    s32 i;
    u16 stringId;

    for (i = 0; i < 5; i++)
    {
        if (CompareStat(battlerId, STAT_ATK + i, MAX_STAT_STAGE, CMP_LESS_THAN))
            break;
    }
    if (i != 5 && HasEnoughHpToEatBerry(battlerId, GetBattlerHoldEffectParam(battlerId), itemId))
    {
        do
        {
            i = Random() % 5;
        } while (!CompareStat(battlerId, STAT_ATK + i, MAX_STAT_STAGE, CMP_LESS_THAN));

        PREPARE_STAT_BUFFER(gBattleTextBuff1, i + 1);
        stringId = (BATTLER_HAS_ABILITY(battlerId, ABILITY_CONTRARY)) ? STRINGID_STATFELL : STRINGID_STATROSE;
        gBattleTextBuff2[0] = B_BUFF_PLACEHOLDER_BEGIN;
        gBattleTextBuff2[1] = B_BUFF_STRING;
        gBattleTextBuff2[2] = STRINGID_STATSHARPLY;
        gBattleTextBuff2[3] = STRINGID_STATSHARPLY >> 8;
        gBattleTextBuff2[4] = B_BUFF_STRING;
        gBattleTextBuff2[5] = stringId;
        gBattleTextBuff2[6] = stringId >> 8;
        gBattleTextBuff2[7] = EOS;
        gEffectBattler = battlerId;
        if (BATTLER_HAS_ABILITY(battlerId, ABILITY_RIPEN))
            SET_STATCHANGER(i + 1, 4, FALSE);
        else
            SET_STATCHANGER(i + 1, 2, FALSE);

        gBattleScripting.animArg1 = 0x21 + i + 6;
        gBattleScripting.animArg2 = 0;
        if (end2)
        {
            BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
        }
        else
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryStatRaiseRet;
        }
        
        return ITEM_STATS_CHANGE;
    }
    return 0;
}

static u8 TrySetMicleBerry(u32 battlerId, u32 itemId, bool32 end2)
{
    if (HasEnoughHpToEatBerry(battlerId, 4, itemId))
    {
        gProtectStructs[battlerId].usedMicleBerry = TRUE;  // battler's next attack has increased accuracy

        if (end2)
        {
            BattleScriptExecute(BattleScript_MicleBerryActivateEnd2);
        }
        else
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_MicleBerryActivateRet;
        }
        return ITEM_EFFECT_OTHER;
    }
    return 0;
}

static u8 DamagedStatBoostBerryEffect(u8 battlerId, u8 statId, u8 split)
{
    if (IsBattlerAlive(battlerId)
     && TARGET_TURN_DAMAGED
     && CompareStat(battlerId, statId, MAX_STAT_STAGE, CMP_LESS_THAN)
     && !DoesSubstituteBlockMove(gBattlerAttacker, battlerId, gCurrentMove)
     && GetBattleMoveSplit(gCurrentMove) == split)
    {
        BufferStatChange(battlerId, statId, STRINGID_STATROSE);

        gEffectBattler = battlerId;
        if (BATTLER_HAS_ABILITY(battlerId, ABILITY_RIPEN))
            SET_STATCHANGER(statId, 2, FALSE);
        else
            SET_STATCHANGER(statId, 1, FALSE);

        gBattleScripting.animArg1 = 14 + statId;
        gBattleScripting.animArg2 = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_BerryStatRaiseRet;
        return ITEM_STATS_CHANGE;
    }
    return 0;
}

u8 TryHandleSeed(u8 battler, u32 terrainFlag, u8 statId, u16 itemId, bool32 execute)
{
    if (gFieldStatuses & terrainFlag && CompareStat(battler, statId, MAX_STAT_STAGE, CMP_LESS_THAN))
    {
        BufferStatChange(battler, statId, STRINGID_STATROSE);
        gLastUsedItem = itemId; // For surge abilities
        gEffectBattler = gBattleScripting.battler = battler;
        SET_STATCHANGER(statId, 1, FALSE);
        gBattleScripting.animArg1 = 0xE + statId;
        gBattleScripting.animArg2 = 0;
        if (execute)
        {
            BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
        }
        else
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryStatRaiseRet;
        }
        return ITEM_STATS_CHANGE;
    }
    return 0;
}

static u8 ItemHealHp(u32 battlerId, u32 itemId, bool32 end2, bool32 percentHeal)
{
    if (HasEnoughHpToEatBerry(battlerId, 2, itemId)
      && !(gBattleScripting.overrideBerryRequirements && gBattleMons[battlerId].hp == gBattleMons[battlerId].maxHP))
    {
        if (percentHeal)
            gBattleMoveDamage = (gBattleMons[battlerId].maxHP * GetBattlerHoldEffectParam(battlerId) / 100) * -1;
        else
            gBattleMoveDamage = GetBattlerHoldEffectParam(battlerId) * -1;

        // check ripen
        if (ItemId_GetPocket(itemId) == POCKET_BERRIES && BATTLER_HAS_ABILITY(battlerId, ABILITY_RIPEN))
            gBattleMoveDamage *= 2;

        gBattlerAbility = battlerId;    // in SWSH, berry juice shows ability pop up but has no effect. This is mimicked here
        if (end2)
        {
            BattleScriptExecute(BattleScript_ItemHealHP_RemoveItemEnd2);
        }
        else
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_ItemHealHP_RemoveItemRet;
        }
        return ITEM_HP_CHANGE;
    }
    return 0;
}

static bool32 UnnerveOn(u32 battlerId, u32 itemId)
{
    if (ItemId_GetPocket(itemId) == POCKET_BERRIES && IsUnnerveAbilityOnOpposingSide(battlerId))
        return TRUE;
    return FALSE;
}

static bool32 GetMentalHerbEffect(u8 battlerId)
{
    bool32 ret = FALSE;
    
    // Check infatuation
    if (gBattleMons[battlerId].status2 & STATUS2_INFATUATION)
    {
        gBattleMons[battlerId].status2 &= ~(STATUS2_INFATUATION);
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_INFATUATION;  // STRINGID_TARGETGOTOVERINFATUATION
        StringCopy(gBattleTextBuff1, gStatusConditionString_LoveJpn);
        ret = TRUE;
    }
    #if B_MENTAL_HERB >= GEN_5
        // Check taunt
        if (gDisableStructs[battlerId].tauntTimer != 0)
        {
            gDisableStructs[battlerId].tauntTimer = gDisableStructs[battlerId].tauntTimer2 = 0;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_TAUNT;
            PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_TAUNT);
            ret = TRUE;
        }
        // Check encore
        if (gDisableStructs[battlerId].encoreTimer != 0)
        {
            gDisableStructs[battlerId].encoredMove = 0;
            gDisableStructs[battlerId].encoreTimerStartValue = gDisableStructs[battlerId].encoreTimer = 0;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_ENCORE;   // STRINGID_PKMNENCOREENDED
            ret = TRUE;
        }
        // Check torment
        if (gBattleMons[battlerId].status2 & STATUS2_TORMENT)
        {
            gBattleMons[battlerId].status2 &= ~(STATUS2_TORMENT);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_TORMENT;
            ret = TRUE;
        }
        // Check heal block
        if (gStatuses3[battlerId] & STATUS3_HEAL_BLOCK)
        {
            gStatuses3[battlerId] &= ~(STATUS3_HEAL_BLOCK);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_HEALBLOCK;
            ret = TRUE;
        }
        // Check disable
        if (gDisableStructs[battlerId].disableTimer != 0)
        {
            gDisableStructs[battlerId].disableTimer = gDisableStructs[battlerId].disableTimerStartValue = 0;
            gDisableStructs[battlerId].disabledMove = 0;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_DISABLE;
            ret = TRUE;
        }
    #endif
    return ret;
}

u8 ItemBattleEffects(u8 caseID, u8 battlerId, bool8 moveTurn)
{
    int i = 0, moveType;
    u8 effect = ITEM_NO_EFFECT;
    u8 changedPP = 0;
    u8 battlerHoldEffect, atkHoldEffect;
    u8 atkHoldEffectParam;
    u16 atkItem;

    gLastUsedItem = gBattleMons[battlerId].item;
    battlerHoldEffect = GetBattlerHoldEffect(battlerId, TRUE);

    atkItem = gBattleMons[gBattlerAttacker].item;
    atkHoldEffect = GetBattlerHoldEffect(gBattlerAttacker, TRUE);
    atkHoldEffectParam = GetBattlerHoldEffectParam(gBattlerAttacker);

    switch (caseID)
    {
    case ITEMEFFECT_ON_SWITCH_IN:
        if (!gSpecialStatuses[battlerId].switchInItemDone)
        {
            switch (battlerHoldEffect)
            {
            case HOLD_EFFECT_DOUBLE_PRIZE:
                if (GetBattlerSide(battlerId) == B_SIDE_PLAYER && !gBattleStruct->moneyMultiplierItem)
                {
                    gBattleStruct->moneyMultiplier *= 2;
                    gBattleStruct->moneyMultiplierItem = 1;
                }
                break;
            case HOLD_EFFECT_RESTORE_STATS:
                for (i = 0; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[battlerId].statStages[i] < DEFAULT_STAT_STAGE)
                    {
                        gBattleMons[battlerId].statStages[i] = DEFAULT_STAT_STAGE;
                        effect = ITEM_STATS_CHANGE;
                    }
                }
                if (effect)
                {
                    gBattleScripting.battler = battlerId;
                    gPotentialItemEffectBattler = battlerId;
                    gActiveBattler = gBattlerAttacker = battlerId;
                    BattleScriptExecute(BattleScript_WhiteHerbEnd2);
                }
                break;
            case HOLD_EFFECT_CONFUSE_SPICY:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_SPICY, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_DRY:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_DRY, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_SWEET:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_SWEET, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_BITTER:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_BITTER, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_SOUR:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_SOUR, TRUE);
                break;
            case HOLD_EFFECT_ATTACK_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_ATK, TRUE);
                break;
            case HOLD_EFFECT_DEFENSE_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_DEF, TRUE);
                break;
            case HOLD_EFFECT_SPEED_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_SPEED, TRUE);
                break;
            case HOLD_EFFECT_SP_ATTACK_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_SPATK, TRUE);
                break;
            case HOLD_EFFECT_SP_DEFENSE_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_SPDEF, TRUE);
                break;
            case HOLD_EFFECT_CRITICAL_UP:
                if (B_BERRIES_INSTANT >= GEN_4 && !(gBattleMons[battlerId].status2 & STATUS2_FOCUS_ENERGY) && HasEnoughHpToEatBerry(battlerId, GetBattlerHoldEffectParam(battlerId), gLastUsedItem))
                {
                    gBattleMons[battlerId].status2 |= STATUS2_FOCUS_ENERGY;
                    BattleScriptExecute(BattleScript_BerryFocusEnergyEnd2);
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_RANDOM_STAT_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = RandomStatRaiseBerry(battlerId, gLastUsedItem, TRUE);
                break;
            case HOLD_EFFECT_CURE_PAR:
                if (B_BERRIES_INSTANT >= GEN_4 && gBattleMons[battlerId].status1 & STATUS1_PARALYSIS && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_PARALYSIS);
                    BattleScriptExecute(BattleScript_BerryCurePrlzEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_PSN:
                if (B_BERRIES_INSTANT >= GEN_4 && gBattleMons[battlerId].status1 & STATUS1_PSN_ANY && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_PSN_ANY | STATUS1_TOXIC_COUNTER);
                    BattleScriptExecute(BattleScript_BerryCurePsnEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_BRN:
                if (B_BERRIES_INSTANT >= GEN_4 && gBattleMons[battlerId].status1 & STATUS1_BURN && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_BURN);
                    BattleScriptExecute(BattleScript_BerryCureBrnEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_FRZ:
                if (B_BERRIES_INSTANT >= GEN_4 && gBattleMons[battlerId].status1 & STATUS1_FREEZE && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_FREEZE);
                    BattleScriptExecute(BattleScript_BerryCureFrzEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                if (gBattleMons[battlerId].status1 & STATUS1_FROSTBITE && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~STATUS1_FROSTBITE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureFsbRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_SLP:
                if (B_BERRIES_INSTANT >= GEN_4 && gBattleMons[battlerId].status1 & STATUS1_SLEEP && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_SLEEP);
                    gBattleMons[battlerId].status2 &= ~(STATUS2_NIGHTMARE);
                    BattleScriptExecute(BattleScript_BerryCureSlpEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_STATUS:
                if (B_BERRIES_INSTANT >= GEN_4 && (gBattleMons[battlerId].status1 & STATUS1_ANY || gBattleMons[battlerId].status2 & STATUS2_CONFUSION) && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    i = 0;
                    if (gBattleMons[battlerId].status1 & STATUS1_PSN_ANY)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_SLEEP)
                    {
                        gBattleMons[battlerId].status2 &= ~(STATUS2_NIGHTMARE);
                        StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_PARALYSIS)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_BURN)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_FREEZE || gBattleMons[battlerId].status1 & STATUS1_FROSTBITE)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status2 & STATUS2_CONFUSION)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ConfusionJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_BLEED)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_BleedJpn);
                        i++;
                    }
                    if (!(i > 1))
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_PROBLEM;
                    else
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_NORMALIZED_STATUS;
                    gBattleMons[battlerId].status1 = 0;
                    gBattleMons[battlerId].status2 &= ~(STATUS2_CONFUSION);
                    BattleScriptExecute(BattleScript_BerryCureChosenStatusEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_RESTORE_HP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = ItemHealHp(battlerId, gLastUsedItem, TRUE, FALSE);
                break;
            case HOLD_EFFECT_RESTORE_PCT_HP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = ItemHealHp(battlerId, gLastUsedItem, TRUE, TRUE);
                break;
            case HOLD_EFFECT_AIR_BALLOON:
                effect = ITEM_EFFECT_OTHER;
                gBattleScripting.battler = battlerId;
                BattleScriptPushCursorAndCallback(BattleScript_AirBaloonMsgIn);
                RecordItemEffectBattle(battlerId, HOLD_EFFECT_AIR_BALLOON);
                break;
            case HOLD_EFFECT_ROOM_SERVICE:
                if (TryRoomService(battlerId))
                {
                    BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
                    effect = ITEM_STATS_CHANGE;
                }
                break;
            case HOLD_EFFECT_SEEDS:
                switch (GetBattlerHoldEffectParam(battlerId))
                {
                case HOLD_EFFECT_PARAM_ELECTRIC_TERRAIN:
                    effect = TryHandleSeed(battlerId, STATUS_FIELD_ELECTRIC_TERRAIN, STAT_DEF, gLastUsedItem, TRUE);
                    break;
                case HOLD_EFFECT_PARAM_GRASSY_TERRAIN:
                    effect = TryHandleSeed(battlerId, STATUS_FIELD_GRASSY_TERRAIN, STAT_DEF, gLastUsedItem, TRUE);
                    break;
                case HOLD_EFFECT_PARAM_MISTY_TERRAIN:
                    effect = TryHandleSeed(battlerId, STATUS_FIELD_MISTY_TERRAIN, STAT_SPDEF, gLastUsedItem, TRUE);
                    break;
                case HOLD_EFFECT_PARAM_PSYCHIC_TERRAIN:
                    effect = TryHandleSeed(battlerId, STATUS_FIELD_PSYCHIC_TERRAIN, STAT_SPDEF, gLastUsedItem, TRUE);
                    break;
                }
                break;
            case HOLD_EFFECT_EJECT_PACK:
                if (gProtectStructs[battlerId].statFell
                 && gProtectStructs[battlerId].disableEjectPack == 0
                 && !(gCurrentMove == MOVE_PARTING_SHOT && CanBattlerSwitch(gBattlerAttacker))) // Does not activate if attacker used Parting Shot and can switch out
                {
                    gProtectStructs[battlerId].statFell = FALSE;
                    gActiveBattler = gBattleScripting.battler = battlerId;
                    effect = ITEM_STATS_CHANGE;
                    if (moveTurn)
                    {
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_EjectPackActivate_Ret;
                    }
                    else
                    {
                        BattleScriptExecute(BattleScript_EjectPackActivate_End2);
                    }
                }
                break;
            }
            
            if (effect)
            {
                gSpecialStatuses[battlerId].switchInItemDone = TRUE;
                gActiveBattler = gBattlerAttacker = gPotentialItemEffectBattler = gBattleScripting.battler = battlerId;
                switch (effect)
                {
                case ITEM_STATUS_CHANGE:
                    BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battlerId].status1);
                    MarkBattlerForControllerExec(gActiveBattler);
                    break;
                case ITEM_PP_CHANGE:
                    if (!(gBattleMons[battlerId].status2 & STATUS2_TRANSFORMED) && !(gDisableStructs[battlerId].mimickedMoves & gBitTable[i]))
                        gBattleMons[battlerId].pp[i] = changedPP;
                    break;
                }
            }
        }
        break;
    case 1:
        if (gBattleMons[battlerId].hp)
        {
            switch (battlerHoldEffect)
            {
            case HOLD_EFFECT_RESTORE_HP:
                if (!moveTurn)
                    effect = ItemHealHp(battlerId, gLastUsedItem, TRUE, FALSE);
                break;
            case HOLD_EFFECT_RESTORE_PCT_HP:
                if (!moveTurn)
                    effect = ItemHealHp(battlerId, gLastUsedItem, TRUE, TRUE);
                break;
            case HOLD_EFFECT_RESTORE_PP:
                if (!moveTurn)
                {
                    struct Pokemon *mon;
                    u8 ppBonuses;
                    u16 move;

                    mon = GetBattlerPartyData(battlerId);
                    for (i = 0; i < MAX_MON_MOVES; i++)
                    {
                        move = GetMonData(mon, MON_DATA_MOVE1 + i);
                        changedPP = GetMonData(mon, MON_DATA_PP1 + i);
                        ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
                        if (move && changedPP == 0)
                            break;
                    }
                    if (i != MAX_MON_MOVES)
                    {
                        u8 maxPP = CalculatePPWithBonus(move, ppBonuses, i);
                        u8 ppRestored = GetBattlerHoldEffectParam(battlerId);

                        if (BATTLER_HAS_ABILITY(battlerId, ABILITY_RIPEN))
                        {
                            ppRestored *= 2;
                            gBattlerAbility = battlerId;
                        }
                        if (changedPP + ppRestored > maxPP)
                            changedPP = maxPP;
                        else
                            changedPP = changedPP + ppRestored;

                        PREPARE_MOVE_BUFFER(gBattleTextBuff1, move);

                        BattleScriptExecute(BattleScript_BerryPPHealEnd2);
                        BtlController_EmitSetMonData(0, i + REQUEST_PPMOVE1_BATTLE, 0, 1, &changedPP);
                        MarkBattlerForControllerExec(gActiveBattler);
                        effect = ITEM_PP_CHANGE;
                    }
                }
                break;
            case HOLD_EFFECT_RESTORE_STATS:
                for (i = 0; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[battlerId].statStages[i] < DEFAULT_STAT_STAGE)
                    {
                        gBattleMons[battlerId].statStages[i] = DEFAULT_STAT_STAGE;
                        effect = ITEM_STATS_CHANGE;
                    }
                }
                if (effect)
                {
                    gBattleScripting.battler = battlerId;
                    gPotentialItemEffectBattler = battlerId;
                    gActiveBattler = gBattlerAttacker = battlerId;
                    BattleScriptExecute(BattleScript_WhiteHerbEnd2);
                }
                break;
            case HOLD_EFFECT_BLACK_SLUDGE:
                if (IS_BATTLER_OF_TYPE(battlerId, TYPE_POISON))
                {
                    goto LEFTOVERS;
                }
                else if (!BATTLER_HAS_MAGIC_GUARD(battlerId) &&
						 !moveTurn)
                {
                    gBattleMoveDamage = gBattleMons[battlerId].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptExecute(BattleScript_ItemHurtEnd2);
                    effect = ITEM_HP_CHANGE;
                    RecordItemEffectBattle(battlerId, battlerHoldEffect);
                    PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
                }
                break;
            case HOLD_EFFECT_LEFTOVERS:
            LEFTOVERS:
                if (gBattleMons[battlerId].hp < gBattleMons[battlerId].maxHP && !moveTurn)
                {
                    gBattleMoveDamage = gBattleMons[battlerId].maxHP / 16;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                    BattleScriptExecute(BattleScript_ItemHealHP_End2);
                    effect = ITEM_HP_CHANGE;
                    RecordItemEffectBattle(battlerId, battlerHoldEffect);
                }
                break;
            case HOLD_EFFECT_CONFUSE_SPICY:
                if (!moveTurn)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_SPICY, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_DRY:
                if (!moveTurn)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_DRY, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_SWEET:
                if (!moveTurn)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_SWEET, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_BITTER:
                if (!moveTurn)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_BITTER, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_SOUR:
                if (!moveTurn)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_SOUR, TRUE);
                break;
            case HOLD_EFFECT_ATTACK_UP:
                if (!moveTurn)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_ATK, TRUE);
                break;
            case HOLD_EFFECT_DEFENSE_UP:
                if (!moveTurn)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_DEF, TRUE);
                break;
            case HOLD_EFFECT_SPEED_UP:
                if (!moveTurn)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_SPEED, TRUE);
                break;
            case HOLD_EFFECT_SP_ATTACK_UP:
                if (!moveTurn)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_SPATK, TRUE);
                break;
            case HOLD_EFFECT_SP_DEFENSE_UP:
                if (!moveTurn)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_SPDEF, TRUE);
                break;
            case HOLD_EFFECT_CRITICAL_UP:
                if (!moveTurn && !(gBattleMons[battlerId].status2 & STATUS2_FOCUS_ENERGY) && HasEnoughHpToEatBerry(battlerId, GetBattlerHoldEffectParam(battlerId), gLastUsedItem))
                {
                    gBattleMons[battlerId].status2 |= STATUS2_FOCUS_ENERGY;
                    BattleScriptExecute(BattleScript_BerryFocusEnergyEnd2);
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_RANDOM_STAT_UP:
                if (!moveTurn)
                    effect = RandomStatRaiseBerry(battlerId, gLastUsedItem, TRUE);
                break;
            case HOLD_EFFECT_CURE_PAR:
                if (gBattleMons[battlerId].status1 & STATUS1_PARALYSIS && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_PARALYSIS);
                    BattleScriptExecute(BattleScript_BerryCurePrlzEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_PSN:
                if (gBattleMons[battlerId].status1 & STATUS1_PSN_ANY && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_PSN_ANY | STATUS1_TOXIC_COUNTER);
                    BattleScriptExecute(BattleScript_BerryCurePsnEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_BRN:
                if (gBattleMons[battlerId].status1 & STATUS1_BURN && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_BURN);
                    BattleScriptExecute(BattleScript_BerryCureBrnEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_FRZ:
                if (gBattleMons[battlerId].status1 & STATUS1_FREEZE && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_FREEZE);
                    BattleScriptExecute(BattleScript_BerryCureFrzEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                if (gBattleMons[battlerId].status1 & STATUS1_FROSTBITE && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~STATUS1_FROSTBITE;
                    BattleScriptExecute(BattleScript_BerryCureFsbEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_SLP:
                if (gBattleMons[battlerId].status1 & STATUS1_SLEEP && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_SLEEP);
                    gBattleMons[battlerId].status2 &= ~(STATUS2_NIGHTMARE);
                    BattleScriptExecute(BattleScript_BerryCureSlpEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_CONFUSION:
                if (gBattleMons[battlerId].status2 & STATUS2_CONFUSION && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status2 &= ~(STATUS2_CONFUSION);
                    BattleScriptExecute(BattleScript_BerryCureConfusionEnd2);
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_CURE_STATUS:
                if ((gBattleMons[battlerId].status1 & STATUS1_ANY || gBattleMons[battlerId].status2 & STATUS2_CONFUSION) && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    i = 0;
                    if (gBattleMons[battlerId].status1 & STATUS1_PSN_ANY)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_SLEEP)
                    {
                        gBattleMons[battlerId].status2 &= ~(STATUS2_NIGHTMARE);
                        StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_PARALYSIS)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_BURN)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_FREEZE || gBattleMons[battlerId].status1 & STATUS1_FROSTBITE)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status2 & STATUS2_CONFUSION)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ConfusionJpn);
                        i++;
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_BLEED)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_BleedJpn);
                        i++;
                    }
                    if (!(i > 1))
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_PROBLEM;
                    else
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_NORMALIZED_STATUS;
                    gBattleMons[battlerId].status1 = 0;
                    gBattleMons[battlerId].status2 &= ~(STATUS2_CONFUSION);
                    BattleScriptExecute(BattleScript_BerryCureChosenStatusEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_MENTAL_HERB:
                if (GetMentalHerbEffect(battlerId))
                {
                    gBattleScripting.savedBattler = gBattlerAttacker;
                    gBattlerAttacker = battlerId;
                    BattleScriptExecute(BattleScript_MentalHerbCureEnd2);
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_MICLE_BERRY:
                if (!moveTurn)
                    effect = TrySetMicleBerry(battlerId, gLastUsedItem, TRUE);
                break;
            }

            if (effect)
            {
                gActiveBattler = gBattlerAttacker = gPotentialItemEffectBattler = gBattleScripting.battler = battlerId;
                switch (effect)
                {
                case ITEM_STATUS_CHANGE:
                    BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battlerId].status1);
                    MarkBattlerForControllerExec(gActiveBattler);
                    break;
                case ITEM_PP_CHANGE:
                    if (!(gBattleMons[battlerId].status2 & STATUS2_TRANSFORMED) && !(gDisableStructs[battlerId].mimickedMoves & gBitTable[i]))
                        gBattleMons[battlerId].pp[i] = changedPP;
                    break;
                }
            }
        }
        break;
    case ITEMEFFECT_BATTLER_MOVE_END:
        goto DO_ITEMEFFECT_MOVE_END;    // this hurts a bit to do, but is an easy solution
    case ITEMEFFECT_MOVE_END:
        for (battlerId = 0; battlerId < gBattlersCount; battlerId++)
        {
            gLastUsedItem = gBattleMons[battlerId].item;
            battlerHoldEffect = GetBattlerHoldEffect(battlerId, TRUE);
        DO_ITEMEFFECT_MOVE_END:
            switch (battlerHoldEffect)
            {
            case HOLD_EFFECT_MICLE_BERRY:
                if (B_HP_BERRIES >= GEN_4)
                    effect = TrySetMicleBerry(battlerId, gLastUsedItem, FALSE);
                break;
            case HOLD_EFFECT_RESTORE_HP:
                if (B_HP_BERRIES >= GEN_4)
                    effect = ItemHealHp(battlerId, gLastUsedItem, FALSE, FALSE);
                break;
            case HOLD_EFFECT_RESTORE_PCT_HP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = ItemHealHp(battlerId, gLastUsedItem, FALSE, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_SPICY:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_SPICY, FALSE);
                break;
            case HOLD_EFFECT_CONFUSE_DRY:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_DRY, FALSE);
                break;
            case HOLD_EFFECT_CONFUSE_SWEET:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_SWEET, FALSE);
                break;
            case HOLD_EFFECT_CONFUSE_BITTER:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_BITTER, FALSE);
                break;
            case HOLD_EFFECT_CONFUSE_SOUR:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battlerId, gLastUsedItem, FLAVOR_SOUR, FALSE);
                break;
            case HOLD_EFFECT_ATTACK_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_ATK, FALSE);
                break;
            case HOLD_EFFECT_DEFENSE_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_DEF, FALSE);
                break;
            case HOLD_EFFECT_SPEED_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_SPEED, FALSE);
                break;
            case HOLD_EFFECT_SP_ATTACK_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_SPATK, FALSE);
                break;
            case HOLD_EFFECT_SP_DEFENSE_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battlerId, gLastUsedItem, STAT_SPDEF, FALSE);
                break;
            case HOLD_EFFECT_RANDOM_STAT_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = RandomStatRaiseBerry(battlerId, gLastUsedItem, FALSE);
                break;
            case HOLD_EFFECT_CURE_PAR:
                if (gBattleMons[battlerId].status1 & STATUS1_PARALYSIS && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_PARALYSIS);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureParRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_PSN:
                if (gBattleMons[battlerId].status1 & STATUS1_PSN_ANY && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_PSN_ANY | STATUS1_TOXIC_COUNTER);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCurePsnRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_BRN:
                if (gBattleMons[battlerId].status1 & STATUS1_BURN && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_BURN);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureBrnRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_FRZ:
                if (gBattleMons[battlerId].status1 & STATUS1_FREEZE && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_FREEZE);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureFrzRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_SLP:
                if (gBattleMons[battlerId].status1 & STATUS1_SLEEP && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status1 &= ~(STATUS1_SLEEP);
                    gBattleMons[battlerId].status2 &= ~(STATUS2_NIGHTMARE);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureSlpRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_CONFUSION:
                if (gBattleMons[battlerId].status2 & STATUS2_CONFUSION && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    gBattleMons[battlerId].status2 &= ~(STATUS2_CONFUSION);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureConfusionRet;
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_MENTAL_HERB:
                if (GetMentalHerbEffect(battlerId))
                {
                    gBattleScripting.savedBattler = gBattlerAttacker;
                    gBattlerAttacker = battlerId;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MentalHerbCureRet;
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_CURE_STATUS:
                if ((gBattleMons[battlerId].status1 & STATUS1_ANY || gBattleMons[battlerId].status2 & STATUS2_CONFUSION) && !UnnerveOn(battlerId, gLastUsedItem))
                {
                    if (gBattleMons[battlerId].status1 & STATUS1_PSN_ANY)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_SLEEP)
                    {
                        gBattleMons[battlerId].status2 &= ~(STATUS2_NIGHTMARE);
                        StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_PARALYSIS)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_BURN)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_FREEZE || gBattleMons[battlerId].status1 & STATUS1_FROSTBITE)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);
                    }
                    if (gBattleMons[battlerId].status2 & STATUS2_CONFUSION)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ConfusionJpn);
                    }
                    if (gBattleMons[battlerId].status1 & STATUS1_BLEED)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_BleedJpn);
                    }
                    gBattleMons[battlerId].status1 = 0;
                    gBattleMons[battlerId].status2 &= ~(STATUS2_CONFUSION);
                    BattleScriptPushCursor();
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_PROBLEM;
                    gBattlescriptCurrInstr = BattleScript_BerryCureChosenStatusRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_RESTORE_STATS:
                for (i = 0; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[battlerId].statStages[i] < DEFAULT_STAT_STAGE)
                    {
                        gBattleMons[battlerId].statStages[i] = DEFAULT_STAT_STAGE;
                        effect = ITEM_STATS_CHANGE;
                    }
                }
                if (effect)
                {
                    gBattleScripting.battler = battlerId;
                    gPotentialItemEffectBattler = battlerId;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_WhiteHerbRet;
                    return effect;
                }
                break;
            }

            if (effect)
            {
                gActiveBattler = gPotentialItemEffectBattler = gBattleScripting.battler = battlerId;
                if (effect == ITEM_STATUS_CHANGE)
                {
                    BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
                break;
            }
        }
        break;
case ITEMEFFECT_KINGSROCK:
        // Occur on each hit of a multi-strike move
        switch (atkHoldEffect)
        {
        case HOLD_EFFECT_FLINCH:
            #if B_SERENE_GRACE_BOOST >= GEN_5
                if (GetBattlerAbility(gBattlerAttacker) == ABILITY_SERENE_GRACE || BattlerHasInnate(gBattlerAttacker, ABILITY_SERENE_GRACE))
                {
                    atkHoldEffectParam *= 2;
                    atkHoldEffectParam = min(100, atkHoldEffectParam);
                }
                if (gSideTimers[GetBattlerSide(gBattlerAttacker)].rainbowTimer)
                {
                    atkHoldEffectParam *= 2;
                    atkHoldEffectParam = min(100, atkHoldEffectParam);
                }
            #endif
            if (gBattleMoveDamage != 0  // Need to have done damage
                && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                && TARGET_TURN_DAMAGED
                && (Random() % 100) < atkHoldEffectParam
                && gBattleMoves[gCurrentMove].flags & FLAG_KINGS_ROCK_AFFECTED
                && gBattleMons[gBattlerTarget].hp)
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_FLINCH;
                BattleScriptPushCursor();
                SetMoveEffect(FALSE, 0);
                BattleScriptPop();
            }
            break;
        case HOLD_EFFECT_BLUNDER_POLICY:
            if (gBattleStruct->blunderPolicy
             && gBattleMons[gBattlerAttacker].hp != 0
             && CompareStat(gBattlerAttacker, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                gBattleStruct->blunderPolicy = FALSE;
                gLastUsedItem = atkItem;
                gBattleScripting.statChanger = SET_STATCHANGER(STAT_SPEED, 2, FALSE);
                effect = ITEM_STATS_CHANGE;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AttackerItemStatRaise;
            }
            break;
        }
        break;
    case ITEMEFFECT_LIFEORB_SHELLBELL:
        // Occur after the final hit of a multi-strike move
        switch (atkHoldEffect)
        {
        case HOLD_EFFECT_SHELL_BELL:
            if (gSpecialStatuses[gBattlerAttacker].damagedMons
                && !(TestSheerForceFlag(gBattlerAttacker, gCurrentMove))
                && gBattlerAttacker != gBattlerTarget
                && gSpecialStatuses[gBattlerTarget].dmg != 0
                && gBattleMons[gBattlerAttacker].hp != gBattleMons[gBattlerAttacker].maxHP
                && gBattleMons[gBattlerAttacker].hp != 0)
            {
                gLastUsedItem = atkItem;
                gPotentialItemEffectBattler = gBattlerAttacker;
                gBattleScripting.battler = gBattlerAttacker;
                gBattleMoveDamage = (gSpecialStatuses[gBattlerTarget].dmg / 4) * -1;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = -1;
                gSpecialStatuses[gBattlerTarget].dmg = 0;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_ItemHealHP_Ret;
                effect = ITEM_HP_CHANGE;
            }
            break;
        case HOLD_EFFECT_LIFE_ORB:
            if (gSpecialStatuses[gBattlerAttacker].damagedMons
                && !(TestSheerForceFlag(gBattlerAttacker, gCurrentMove))
                && !BATTLER_HAS_MAGIC_GUARD(gBattlerAttacker)
				&& !(BattlerHasInnate(gBattlerAttacker, ABILITY_SHEER_FORCE)    && (gBattleMoves[gCurrentMove].flags & FLAG_SHEER_FORCE_BOOST))
                && !(GetBattlerAbility(gBattlerAttacker) == ABILITY_SHEER_FORCE && (gBattleMoves[gCurrentMove].flags & FLAG_SHEER_FORCE_BOOST))
                && gBattlerAttacker != gBattlerTarget
                && gBattleMons[gBattlerAttacker].hp != 0)
            {
                gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 10;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                effect = ITEM_HP_CHANGE;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_ItemHurtRet;
                gLastUsedItem = gBattleMons[gBattlerAttacker].item;
            }
            break;
        case HOLD_EFFECT_THROAT_SPRAY:  // Does NOT need to be a damaging move
            if (gProtectStructs[gBattlerAttacker].targetAffected
             && gBattleMons[gBattlerAttacker].hp != 0
             && gBattleMoves[gCurrentMove].flags & FLAG_SOUND
             && CompareStat(gBattlerAttacker, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN)
             && !NoAliveMonsForEitherParty())   // Don't activate if battle will end
            {
                gLastUsedItem = atkItem;
                gBattleScripting.battler = gBattlerAttacker;
                gBattleScripting.statChanger = SET_STATCHANGER(STAT_SPATK, 1, FALSE);
                effect = ITEM_STATS_CHANGE;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AttackerItemStatRaise;
            }
            break;
        }
        break;
    case ITEMEFFECT_TARGET:
        if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
        {
            GET_MOVE_TYPE(gCurrentMove, moveType);
            switch (battlerHoldEffect)
            {
            case HOLD_EFFECT_AIR_BALLOON:
                if (TARGET_TURN_DAMAGED)
                {
                    effect = ITEM_EFFECT_OTHER;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_AirBaloonMsgPop;
                }
                break;
            case HOLD_EFFECT_ROCKY_HELMET:
                if (TARGET_TURN_DAMAGED
                    && IsMoveMakingContact(gCurrentMove, gBattlerAttacker)
                    && IsBattlerAlive(gBattlerAttacker)
					&& !BATTLER_HAS_MAGIC_GUARD(gBattlerAttacker))
                {
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 6;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    effect = ITEM_HP_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_RockyHelmetActivates;
                    PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
                    RecordItemEffectBattle(battlerId, HOLD_EFFECT_ROCKY_HELMET);
                }
                break;
            case HOLD_EFFECT_WEAKNESS_POLICY:
                if (IsBattlerAlive(battlerId)
                    && TARGET_TURN_DAMAGED
                    && gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_WeaknessPolicy;
                }
                break;
            case HOLD_EFFECT_SNOWBALL:
                if (IsBattlerAlive(battlerId)
                    && TARGET_TURN_DAMAGED
                    && moveType == TYPE_ICE)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_TargetItemStatRaise;
                    gBattleScripting.statChanger = SET_STATCHANGER(STAT_ATK, 1, FALSE);
                }
                break;
            case HOLD_EFFECT_LUMINOUS_MOSS:
                if (IsBattlerAlive(battlerId)
                    && TARGET_TURN_DAMAGED
                    && moveType == TYPE_WATER)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_TargetItemStatRaise;
                    gBattleScripting.statChanger = SET_STATCHANGER(STAT_SPDEF, 1, FALSE);
                }
                break;
            case HOLD_EFFECT_CELL_BATTERY:
                if (IsBattlerAlive(battlerId)
                    && TARGET_TURN_DAMAGED
                    && moveType == TYPE_ELECTRIC)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_TargetItemStatRaise;
                    gBattleScripting.statChanger = SET_STATCHANGER(STAT_ATK, 1, FALSE);
                }
                break;
            case HOLD_EFFECT_ABSORB_BULB:
                if (IsBattlerAlive(battlerId)
                    && TARGET_TURN_DAMAGED
                    && moveType == TYPE_WATER)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_TargetItemStatRaise;
                    gBattleScripting.statChanger = SET_STATCHANGER(STAT_SPATK, 1, FALSE);
                }
                break;
            case HOLD_EFFECT_JABOCA_BERRY:  // consume and damage attacker if used physical move
                if (IsBattlerAlive(battlerId)
                 && TARGET_TURN_DAMAGED
                 && !DoesSubstituteBlockMove(gBattlerAttacker, battlerId, gCurrentMove)
                 && IS_MOVE_PHYSICAL(gCurrentMove)
                 && !BATTLER_HAS_MAGIC_GUARD(gBattlerAttacker))
                {
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    if (BATTLER_HAS_ABILITY(battlerId, ABILITY_RIPEN))
                        gBattleMoveDamage *= 2;

                    effect = ITEM_HP_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_JabocaRowapBerryActivates;
                    PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
                    RecordItemEffectBattle(battlerId, HOLD_EFFECT_ROCKY_HELMET);
                }
                break;
            case HOLD_EFFECT_ROWAP_BERRY:  // consume and damage attacker if used special move
                if (IsBattlerAlive(battlerId)
                 && TARGET_TURN_DAMAGED
                 && !DoesSubstituteBlockMove(gBattlerAttacker, battlerId, gCurrentMove)
                 && IS_MOVE_SPECIAL(gCurrentMove)
                 && !BATTLER_HAS_MAGIC_GUARD(gBattlerAttacker))
                {
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    if (BATTLER_HAS_ABILITY(battlerId, ABILITY_RIPEN))
                        gBattleMoveDamage *= 2;

                    effect = ITEM_HP_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_JabocaRowapBerryActivates;
                    PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
                    RecordItemEffectBattle(battlerId, HOLD_EFFECT_ROCKY_HELMET);
                }
                break;
            case HOLD_EFFECT_KEE_BERRY:  // consume and boost defense if used physical move
                effect = DamagedStatBoostBerryEffect(battlerId, STAT_DEF, SPLIT_PHYSICAL);
                break;
            case HOLD_EFFECT_MARANGA_BERRY:  // consume and boost sp. defense if used special move
                effect = DamagedStatBoostBerryEffect(battlerId, STAT_SPDEF, SPLIT_SPECIAL);
                break;
            case HOLD_EFFECT_STICKY_BARB:
                if (TARGET_TURN_DAMAGED
                  && (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
                  && IsMoveMakingContact(gCurrentMove, gBattlerAttacker)
                  && !DoesSubstituteBlockMove(gBattlerAttacker, battlerId, gCurrentMove)
                  && IsBattlerAlive(gBattlerAttacker)
                  && CanStealItem(gBattlerAttacker, gBattlerTarget, gBattleMons[gBattlerTarget].item)
                  && gBattleMons[gBattlerAttacker].item == ITEM_NONE)
                {
                    // No sticky hold checks.
                    gEffectBattler = battlerId; // gEffectBattler = target
                    StealTargetItem(gBattlerAttacker, gBattlerTarget);  // Attacker takes target's barb
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_StickyBarbTransfer;
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            }
        }
        break;
    case ITEMEFFECT_ORBS:
        switch (battlerHoldEffect)
        {
        case HOLD_EFFECT_TOXIC_ORB:
            if (!gBattleMons[battlerId].status1
                && CanPoisonType(battlerId, battlerId)
                && GetBattlerAbility(battlerId) != ABILITY_IMMUNITY
                && GetBattlerAbility(battlerId) != ABILITY_COMATOSE
                && IsBattlerAlive(battlerId))
            {
                effect = ITEM_STATUS_CHANGE;
                gBattleMons[battlerId].status1 = STATUS1_TOXIC_POISON;
                BattleScriptExecute(BattleScript_ToxicOrb);
                RecordItemEffectBattle(battlerId, battlerHoldEffect);
            }
            break;
        case HOLD_EFFECT_FLAME_ORB:
            if (!gBattleMons[battlerId].status1
                && !IS_BATTLER_OF_TYPE(battlerId, TYPE_FIRE)
                && GetBattlerAbility(battlerId) != ABILITY_WATER_VEIL
				&& !BattlerHasInnate(battlerId, ABILITY_WATER_VEIL)
                && GetBattlerAbility(battlerId) != ABILITY_PURIFYING_WATERS
				&& !BattlerHasInnate(battlerId, ABILITY_PURIFYING_WATERS)
                && GetBattlerAbility(battlerId) != ABILITY_WATER_BUBBLE
				&& !BattlerHasInnate(battlerId, ABILITY_WATER_BUBBLE)
                && GetBattlerAbility(battlerId) != ABILITY_COMATOSE
				&& !BattlerHasInnate(battlerId, ABILITY_COMATOSE)
                && IsBattlerAlive(battlerId))
            {
                effect = ITEM_STATUS_CHANGE;
                gBattleMons[battlerId].status1 = STATUS1_BURN;
                BattleScriptExecute(BattleScript_FlameOrb);
                RecordItemEffectBattle(battlerId, battlerHoldEffect);
            }
            break;
        case HOLD_EFFECT_STICKY_BARB:   // Not an orb per se, but similar effect, and needs to NOT activate with pickpocket
            if (!BATTLER_HAS_MAGIC_GUARD(battlerId))
            {
                gBattleMoveDamage = gBattleMons[battlerId].maxHP / 8;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptExecute(BattleScript_ItemHurtEnd2);
                effect = ITEM_HP_CHANGE;
                RecordItemEffectBattle(battlerId, battlerHoldEffect);
                PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
            }
            break;
        }

        if (effect == ITEM_STATUS_CHANGE)
        {
            gActiveBattler = battlerId;
            BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battlerId].status1);
            MarkBattlerForControllerExec(gActiveBattler);
        }
        break;
    }

    // Berry was successfully used on a Pokemon.
    if (effect && (gLastUsedItem >= FIRST_BERRY_INDEX && gLastUsedItem <= LAST_BERRY_INDEX))
        gBattleStruct->ateBerry[battlerId & BIT_SIDE] |= gBitTable[gBattlerPartyIndexes[battlerId]];

    return effect;
}

void ClearFuryCutterDestinyBondGrudge(u8 battlerId)
{
    gDisableStructs[battlerId].furyCutterCounter = 0;
    gBattleMons[battlerId].status2 &= ~(STATUS2_DESTINY_BOND);
    gStatuses3[battlerId] &= ~(STATUS3_GRUDGE);
}

void HandleAction_RunBattleScript(void) // identical to RunBattleScriptCommands
{
    if (gBattleControllerExecFlags == 0)
        gBattleScriptingCommandsTable[*gBattlescriptCurrInstr]();
}

u32 SetRandomTarget(u32 battlerId)
{
    u32 target;
    static const u8 targets[2][2] =
    {
        [B_SIDE_PLAYER] = {B_POSITION_OPPONENT_LEFT, B_POSITION_OPPONENT_RIGHT},
        [B_SIDE_OPPONENT] = {B_POSITION_PLAYER_LEFT, B_POSITION_PLAYER_RIGHT},
    };

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        target = GetBattlerAtPosition(targets[GetBattlerSide(battlerId)][Random() % 2]);
        if (!IsBattlerAlive(target))
            target ^= BIT_FLANK;
    }
    else
    {
        target = GetBattlerAtPosition(targets[GetBattlerSide(battlerId)][0]);
    }

    return target;
}

u32 GetMoveTarget(u16 move, u8 setTarget)
{
    u8 targetBattler = 0;
    u32 i, moveTarget, side;

    if (setTarget)
        moveTarget = setTarget - 1;
    else
        moveTarget = GetBattlerBattleMoveTargetFlags(move, gBattlerAttacker);
    
    // Special cases
    if (move == MOVE_CURSE && !IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GHOST))
        moveTarget = MOVE_TARGET_USER;
    
    switch (moveTarget)
    {
    case MOVE_TARGET_SELECTED:
        side = GetBattlerSide(gBattlerAttacker) ^ BIT_SIDE;
        if (IsAffectedByFollowMe(gBattlerAttacker, side, move))
        {
            targetBattler = gSideTimers[side].followmeTarget;
        }
        else
        {
            targetBattler = SetRandomTarget(gBattlerAttacker);
            if (gBattleMoves[move].type == TYPE_ELECTRIC
                && IsAbilityOnOpposingSide(gBattlerAttacker, ABILITY_LIGHTNING_ROD)
                && !BATTLER_HAS_ABILITY(targetBattler, ABILITY_LIGHTNING_ROD))
            {
                targetBattler ^= BIT_FLANK;
                RecordAbilityBattle(targetBattler, gBattleMons[targetBattler].ability);
                gSpecialStatuses[targetBattler].lightningRodRedirected = TRUE;
            }
            else if (gBattleMoves[move].type == TYPE_WATER
                && IsAbilityOnOpposingSide(gBattlerAttacker, ABILITY_STORM_DRAIN)
                && !BATTLER_HAS_ABILITY(targetBattler, ABILITY_STORM_DRAIN))
            {
                targetBattler ^= BIT_FLANK;
                RecordAbilityBattle(targetBattler, gBattleMons[targetBattler].ability);
                gSpecialStatuses[targetBattler].stormDrainRedirected = TRUE;
            }
        }
        break;
    case MOVE_TARGET_DEPENDS:
    case MOVE_TARGET_BOTH:
    case MOVE_TARGET_FOES_AND_ALLY:
    case MOVE_TARGET_OPPONENTS_FIELD:
        targetBattler = GetBattlerAtPosition((GetBattlerPosition(gBattlerAttacker) & BIT_SIDE) ^ BIT_SIDE);
        if (!IsBattlerAlive(targetBattler))
            targetBattler ^= BIT_FLANK;
        break;
    case MOVE_TARGET_RANDOM:
        side = GetBattlerSide(gBattlerAttacker) ^ BIT_SIDE;
        if (IsAffectedByFollowMe(gBattlerAttacker, side, move))
            targetBattler = gSideTimers[side].followmeTarget;
        else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && moveTarget & MOVE_TARGET_RANDOM)
            targetBattler = SetRandomTarget(gBattlerAttacker);
        else
            targetBattler = GetBattlerAtPosition((GetBattlerPosition(gBattlerAttacker) & BIT_SIDE) ^ BIT_SIDE);
        break;
    case MOVE_TARGET_USER_OR_SELECTED:
    case MOVE_TARGET_USER:
    default:
        targetBattler = gBattlerAttacker;
        break;
    case MOVE_TARGET_ALLY:
        if (IsBattlerAlive(BATTLE_PARTNER(gBattlerAttacker)))
            targetBattler = BATTLE_PARTNER(gBattlerAttacker);
        else
            targetBattler = gBattlerAttacker;
        break;
    }

    *(gBattleStruct->moveTarget + gBattlerAttacker) = targetBattler;

    return targetBattler;
}

static bool32 IsMonEventLegal(u8 battlerId)
{
    if (GetBattlerSide(battlerId) == B_SIDE_OPPONENT)
        return TRUE;
    if (GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES, NULL) != SPECIES_DEOXYS
        && GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES, NULL) != SPECIES_MEW)
            return TRUE;
    return GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_EVENT_LEGAL, NULL);
}

u8 IsMonDisobedient(void)
{
    s32 rnd;
    s32 calc;
    u8 obedienceLevel = 0;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
        return 0;
    if (GetBattlerSide(gBattlerAttacker) == B_SIDE_OPPONENT)
        return 0;

    if (IsMonEventLegal(gBattlerAttacker)) // only false if illegal Mew or Deoxys
    {
        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBattlerPosition(gBattlerAttacker) == 2)
            return 0;
        if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
            return 0;
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            return 0;
        if (!IsOtherTrainer(gBattleMons[gBattlerAttacker].otId, gBattleMons[gBattlerAttacker].otName))
            return 0;
        if (FlagGet(FLAG_BADGE08_GET))
            return 0;

        obedienceLevel = 25;

        if (FlagGet(FLAG_BADGE02_GET))
            obedienceLevel = 40;
        if (FlagGet(FLAG_BADGE03_GET))
            obedienceLevel = 50;
        if (FlagGet(FLAG_BADGE04_GET))
            obedienceLevel = 60;
        if (FlagGet(FLAG_BADGE05_GET))
            obedienceLevel = 70;
        if (FlagGet(FLAG_BADGE06_GET))
            obedienceLevel = 80;
        if (FlagGet(FLAG_BADGE07_GET))
            obedienceLevel = 90;
    }

    //if (gBattleMons[gBattlerAttacker].level <= obedienceLevel)
        return 0;
    rnd = (Random() & 255);
    calc = (gBattleMons[gBattlerAttacker].level + obedienceLevel) * rnd >> 8;
    if (calc < obedienceLevel)
        return 0;

    // is not obedient
    if (gCurrentMove == MOVE_RAGE)
        gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_RAGE);
    if (gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP && (gCurrentMove == MOVE_SNORE || gCurrentMove == MOVE_SLEEP_TALK))
    {
        gBattlescriptCurrInstr = BattleScript_IgnoresWhileAsleep;
        return 1;
    }

    rnd = (Random() & 255);
    calc = (gBattleMons[gBattlerAttacker].level + obedienceLevel) * rnd >> 8;
    if (calc < obedienceLevel)
    {
        calc = CheckMoveLimitations(gBattlerAttacker, gBitTable[gCurrMovePos], 0xFF);
        if (calc == 0xF) // all moves cannot be used
        {
            // Randomly select, then print a disobedient string
            // B_MSG_LOAFING, B_MSG_WONT_OBEY, B_MSG_TURNED_AWAY, or B_MSG_PRETEND_NOT_NOTICE
            gBattleCommunication[MULTISTRING_CHOOSER] = Random() & (NUM_LOAF_STRINGS - 1);
            gBattlescriptCurrInstr = BattleScript_MoveUsedLoafingAround;
            return 1;
        }
        else // use a random move
        {
            do
            {
                gCurrMovePos = gChosenMovePos = Random() & (MAX_MON_MOVES - 1);
            } while (gBitTable[gCurrMovePos] & calc);

            gCalledMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
            gBattlescriptCurrInstr = BattleScript_IgnoresAndUsesRandomMove;
            gBattlerTarget = GetMoveTarget(gCalledMove, 0);
            gHitMarker |= HITMARKER_x200000;
            return 2;
        }
    }
    else
    {
        obedienceLevel = gBattleMons[gBattlerAttacker].level - obedienceLevel;

        calc = (Random() & 255);
        if (calc < obedienceLevel && CanSleep(gBattlerAttacker))
        {
            // try putting asleep
            int i;
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gBattleMons[i].status2 & STATUS2_UPROAR)
                    break;
            }
            if (i == gBattlersCount)
            {
                gBattlescriptCurrInstr = BattleScript_IgnoresAndFallsAsleep;
                return 1;
            }
        }
        calc -= obedienceLevel;
        if (calc < obedienceLevel)
        {
            u8 moveType = TYPE_MYSTERY;
            gBattleMoveDamage = CalculateMoveDamage(MOVE_NONE, gBattlerAttacker, gBattlerAttacker, &moveType, 40, FALSE, FALSE, TRUE);
            gBattlerTarget = gBattlerAttacker;
            gBattlescriptCurrInstr = BattleScript_IgnoresAndHitsItself;
            gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
            return 2;
        }
        else
        {
            // Randomly select, then print a disobedient string
            // B_MSG_LOAFING, B_MSG_WONT_OBEY, B_MSG_TURNED_AWAY, or B_MSG_PRETEND_NOT_NOTICE
            gBattleCommunication[MULTISTRING_CHOOSER] = Random() & (NUM_LOAF_STRINGS - 1);
            gBattlescriptCurrInstr = BattleScript_MoveUsedLoafingAround;
            return 1;
        }
    }
}

u32 GetBattlerHoldEffect(u8 battlerId, bool32 checkNegating)
{
    if (checkNegating)
    {
        if (gStatuses3[battlerId] & STATUS3_EMBARGO)
            return HOLD_EFFECT_NONE;
        if (isMagicRoomActive())
            return HOLD_EFFECT_NONE;
        if (GetBattlerAbility(battlerId) == ABILITY_KLUTZ)
            return HOLD_EFFECT_NONE;
    }

    gPotentialItemEffectBattler = battlerId;

    if (B_ENABLE_DEBUG && gBattleStruct->debugHoldEffects[battlerId] != 0 && gBattleMons[battlerId].item)
        return gBattleStruct->debugHoldEffects[battlerId];
    else if (gBattleMons[battlerId].item == ITEM_ENIGMA_BERRY)
        return gEnigmaBerries[battlerId].holdEffect;
    else
        return ItemId_GetHoldEffect(gBattleMons[battlerId].item);
}

bool8 DoesBattlerHaveAbilityShield(u8 battlerId)
{
    u8 i;
    if (GetBattlerHoldEffect(battlerId, FALSE) != HOLD_EFFECT_ABILITY_SHIELD) return FALSE;
    if (gStatuses3[battlerId] & STATUS3_EMBARGO) return FALSE;
    if (!(gFieldStatuses & STATUS_FIELD_MAGIC_ROOM)) return TRUE;
    for (i = 0; i < gBattlersCount; i++)
    {
        if (GetBattlerAbilityWithoutRemoval(i) == ABILITY_CLUELESS) return TRUE;
        if (BattlerHasInnateWithoutRemoval(i, ABILITY_CLUELESS)) return TRUE;
    }
    return FALSE;
}

u32 GetBattlerHoldEffectParam(u8 battlerId)
{
    if (gBattleMons[battlerId].item == ITEM_ENIGMA_BERRY)
        return gEnigmaBerries[battlerId].holdEffectParam;
    else
        return ItemId_GetHoldEffectParam(gBattleMons[battlerId].item);
}

bool32 IsMoveMakingContact(u16 move, u8 battlerAtk)
{
    if (!(gBattleMoves[move].flags & FLAG_MAKES_CONTACT))
    {
        if (gBattleMoves[move].effect == EFFECT_SHELL_SIDE_ARM && gSwapDamageCategory)
            return TRUE;
        else
            return FALSE;
    }
    else if (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_LONG_REACH))
    {
        return FALSE;
    }
    else if (GetBattlerHoldEffect(battlerAtk, TRUE) == HOLD_EFFECT_PROTECTIVE_PADS)
    {
        return FALSE;
    }
    else if (GetBattlerHoldEffect(battlerAtk, TRUE) == HOLD_EFFECT_PUNCHING_GLOVE && IS_IRON_FIST(battlerAtk, move))
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

bool32 IsBattlerProtected(u8 battlerId, u16 move)
{
    // Decorate bypasses protect and detect, but not crafty shield
    if (move == MOVE_DECORATE)
    {
        if (gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_CRAFTY_SHIELD)
            return TRUE;
        else if (gProtectStructs[battlerId].protected)
            return FALSE;
    }

    // Protective Pads doesn't stop Unseen Fist from bypassing Protect effects, so IsMoveMakingContact() isn't used here.
    // This means extra logic is needed to handle Shell Side Arm.
    if (GetBattlerAbility(gBattlerAttacker) == ABILITY_UNSEEN_FIST
        && (gBattleMoves[move].flags & FLAG_MAKES_CONTACT || (gBattleMoves[move].effect == EFFECT_SHELL_SIDE_ARM && gSwapDamageCategory)))
        return FALSE;
    else if (!(gBattleMoves[move].flags & FLAG_PROTECT_AFFECTED))
        return FALSE;
    else if (gBattleMoves[move].effect == MOVE_EFFECT_FEINT)
        return FALSE;
    else if (gProtectStructs[battlerId].protected)
        return TRUE;
    else if (gDisableStructs[battlerId].protectedThisTurn && gProtectStructs[gBattlerAttacker].extraMoveUsed != TRUE)
        return TRUE;
    else if (gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_WIDE_GUARD
             && GetBattlerBattleMoveTargetFlags(move, battlerId) & (MOVE_TARGET_BOTH | MOVE_TARGET_FOES_AND_ALLY))
        return TRUE;
    else if (gProtectStructs[battlerId].banefulBunkered)
        return TRUE;
    else if (gProtectStructs[battlerId].obstructed && !IS_MOVE_STATUS(move))
        return TRUE;
    else if (gProtectStructs[battlerId].spikyShielded)
        return TRUE;
    else if (gProtectStructs[battlerId].kingsShielded && gBattleMoves[move].power != 0)
        return TRUE;
    else if (gProtectStructs[battlerId].angelsWrathProtected && gBattleMoves[move].power != 0)
        return TRUE;
    else if (gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_QUICK_GUARD
             && GetChosenMovePriority(gBattlerAttacker, battlerId) > 0)
        return TRUE;
    else if (gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_CRAFTY_SHIELD
      && IS_MOVE_STATUS(move))
        return TRUE;
    else if (gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_MAT_BLOCK
      && !IS_MOVE_STATUS(move))
        return TRUE;
    else
        return FALSE;
}


bool32 IsBattlerGrounded(u8 battlerId)
{
    if (GetBattlerHoldEffect(battlerId, TRUE) == HOLD_EFFECT_IRON_BALL)
        return TRUE;
    else if (IsGravityActive())
        return TRUE;
    else if (gStatuses3[battlerId] & STATUS3_ROOTED)
        return TRUE;
    else if (gStatuses3[battlerId] & STATUS3_SMACKED_DOWN)
        return TRUE;

    else if (gStatuses3[battlerId] & STATUS3_TELEKINESIS)
        return FALSE;
    else if (gStatuses3[battlerId] & STATUS3_MAGNET_RISE)
        return FALSE;
    else if (GetBattlerHoldEffect(battlerId, TRUE) == HOLD_EFFECT_AIR_BALLOON)
        return FALSE;
    else if (BATTLER_HAS_ABILITY(battlerId, ABILITY_LEVITATE))
        return FALSE;
	else if (BATTLER_HAS_ABILITY(battlerId, ABILITY_DRAGONFLY)) //Dragonfly
        return FALSE;
    else if (IS_BATTLER_OF_TYPE(battlerId, TYPE_FLYING))
        return FALSE;
    else
        return TRUE;
}

bool32 IsBattlerAlive(u8 battlerId)
{
    if (gBattleMons[battlerId].hp == 0)
        return FALSE;
    else if (battlerId >= gBattlersCount)
        return FALSE;
    else if (gAbsentBattlerFlags & gBitTable[battlerId])
        return FALSE;
    else
        return TRUE;
}

u8 GetBattleMonMoveSlot(struct BattlePokemon *battleMon, u16 move)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        if (battleMon->moves[i] == move)
            break;
    }
    return i;
}

u32 GetBattlerWeight(u8 battlerId)
{
    u32 i;
    u32 weight = GetPokedexHeightWeight(SpeciesToNationalPokedexNum(gBattleMons[battlerId].species), 1);
    u32 ability = GetBattlerAbility(battlerId);
    u32 holdEffect = GetBattlerHoldEffect(battlerId, TRUE);

    if (BATTLER_HAS_ABILITY(battlerId, ABILITY_HEAVY_METAL))
        weight *= 2;
	
    if (BATTLER_HAS_ABILITY(battlerId, ABILITY_LIGHT_METAL))
        weight /= 2;
	
	if (BATTLER_HAS_ABILITY(battlerId, ABILITY_LEAD_COAT))
        weight *= 3;
	
	if (BATTLER_HAS_ABILITY(battlerId, ABILITY_CHROME_COAT))
        weight *= 3;

    if (holdEffect == HOLD_EFFECT_FLOAT_STONE)
        weight /= 2;

    for (i = 0; i < gDisableStructs[battlerId].autotomizeCount; i++)
    {
        if (weight > 1000)
        {
            weight -= 1000;
        }
        else if (weight <= 1000)
        {
            weight = 1;
            break;
        }
    }

    if (weight == 0)
        weight = 1;

    return weight;
}

u32 CountBattlerStatIncreases(u8 battlerId, bool32 countEvasionAcc)
{
    u32 i;
    u32 count = 0;

    for (i = 0; i < NUM_BATTLE_STATS; i++)
    {
        if ((i == STAT_ACC || i == STAT_EVASION) && !countEvasionAcc)
            continue;
        if (gBattleMons[battlerId].statStages[i] > DEFAULT_STAT_STAGE) // Stat is increased.
            count += gBattleMons[battlerId].statStages[i] - DEFAULT_STAT_STAGE;
    }

    return count;
}

u32 GetMoveTargetCount(u16 move, u8 battlerAtk, u8 battlerDef)
{
    switch (GetBattlerBattleMoveTargetFlags(move, battlerAtk))
    {
    case MOVE_TARGET_BOTH:
        return IsBattlerAlive(battlerDef)
             + IsBattlerAlive(BATTLE_PARTNER(battlerDef));
    case MOVE_TARGET_FOES_AND_ALLY:
        return IsBattlerAlive(battlerDef)
             + IsBattlerAlive(BATTLE_PARTNER(battlerDef))
             + IsBattlerAlive(BATTLE_PARTNER(battlerAtk));
    case MOVE_TARGET_OPPONENTS_FIELD:
        return 1;
    case MOVE_TARGET_DEPENDS:
    case MOVE_TARGET_SELECTED:
    case MOVE_TARGET_RANDOM:
    case MOVE_TARGET_USER_OR_SELECTED:
        return IsBattlerAlive(battlerDef);
    case MOVE_TARGET_USER:
        return IsBattlerAlive(battlerAtk);
    default:
        return 0;
    }
}

static void MulModifier(u16 *modifier, u16 val)
{
    *modifier = UQ_4_12_TO_INT((*modifier * val) + UQ_4_12_ROUND);
}

static u32 ApplyModifier(u16 modifier, u32 val)
{
    return UQ_4_12_TO_INT((modifier * val) + UQ_4_12_ROUND);
}

static const u8 sFlailHpScaleToPowerTable[] =
{
    1, 200,
    4, 150,
    9, 100,
    16, 80,
    32, 40,
    48, 20
};

// format: min. weight (hectograms), base power
static const u16 sWeightToDamageTable[] =
{
    100, 20,
    250, 40,
    500, 60,
    1000, 80,
    2000, 100,
    0xFFFF, 0xFFFF
};

static const u8 sSpeedDiffPowerTable[] = {40, 60, 80, 120, 150};
static const u8 sHeatCrashPowerTable[] = {40, 40, 60, 80, 100, 120};
static const u8 sTrumpCardPowerTable[] = {200, 80, 60, 50, 40};

const struct TypePower gNaturalGiftTable[] =
{
    [ITEM_TO_BERRY(ITEM_CHERI_BERRY)] = {TYPE_FIRE, 80},
    [ITEM_TO_BERRY(ITEM_CHESTO_BERRY)] = {TYPE_WATER, 80},
    [ITEM_TO_BERRY(ITEM_PECHA_BERRY)] = {TYPE_ELECTRIC, 80},
    [ITEM_TO_BERRY(ITEM_RAWST_BERRY)] = {TYPE_GRASS, 80},
    [ITEM_TO_BERRY(ITEM_ASPEAR_BERRY)] = {TYPE_ICE, 80},
    [ITEM_TO_BERRY(ITEM_LEPPA_BERRY)] = {TYPE_FIGHTING, 80},
    [ITEM_TO_BERRY(ITEM_ORAN_BERRY)] = {TYPE_POISON, 80},
    [ITEM_TO_BERRY(ITEM_PERSIM_BERRY)] = {TYPE_GROUND, 80},
    [ITEM_TO_BERRY(ITEM_LUM_BERRY)] = {TYPE_FLYING, 80},
    [ITEM_TO_BERRY(ITEM_SITRUS_BERRY)] = {TYPE_PSYCHIC, 80},
    [ITEM_TO_BERRY(ITEM_FIGY_BERRY)] = {TYPE_BUG, 80},
    [ITEM_TO_BERRY(ITEM_WIKI_BERRY)] = {TYPE_ROCK, 80},
    [ITEM_TO_BERRY(ITEM_MAGO_BERRY)] = {TYPE_GHOST, 80},
    [ITEM_TO_BERRY(ITEM_AGUAV_BERRY)] = {TYPE_DRAGON, 80},
    [ITEM_TO_BERRY(ITEM_IAPAPA_BERRY)] = {TYPE_DARK, 80},
    [ITEM_TO_BERRY(ITEM_RAZZ_BERRY)] = {TYPE_STEEL, 80},
    [ITEM_TO_BERRY(ITEM_OCCA_BERRY)] = {TYPE_FIRE, 80},
    [ITEM_TO_BERRY(ITEM_PASSHO_BERRY)] = {TYPE_WATER, 80},
    [ITEM_TO_BERRY(ITEM_WACAN_BERRY)] = {TYPE_ELECTRIC, 80},
    [ITEM_TO_BERRY(ITEM_RINDO_BERRY)] = {TYPE_GRASS, 80},
    [ITEM_TO_BERRY(ITEM_YACHE_BERRY)] = {TYPE_ICE, 80},
    [ITEM_TO_BERRY(ITEM_CHOPLE_BERRY)] = {TYPE_FIGHTING, 80},
    [ITEM_TO_BERRY(ITEM_KEBIA_BERRY)] = {TYPE_POISON, 80},
    [ITEM_TO_BERRY(ITEM_SHUCA_BERRY)] = {TYPE_GROUND, 80},
    [ITEM_TO_BERRY(ITEM_COBA_BERRY)] = {TYPE_FLYING, 80},
    [ITEM_TO_BERRY(ITEM_PAYAPA_BERRY)] = {TYPE_PSYCHIC, 80},
    [ITEM_TO_BERRY(ITEM_TANGA_BERRY)] = {TYPE_BUG, 80},
    [ITEM_TO_BERRY(ITEM_CHARTI_BERRY)] = {TYPE_ROCK, 80},
    [ITEM_TO_BERRY(ITEM_KASIB_BERRY)] = {TYPE_GHOST, 80},
    [ITEM_TO_BERRY(ITEM_HABAN_BERRY)] = {TYPE_DRAGON, 80},
    [ITEM_TO_BERRY(ITEM_COLBUR_BERRY)] = {TYPE_DARK, 80},
    [ITEM_TO_BERRY(ITEM_BABIRI_BERRY)] = {TYPE_STEEL, 80},
    [ITEM_TO_BERRY(ITEM_CHILAN_BERRY)] = {TYPE_NORMAL, 80},
    [ITEM_TO_BERRY(ITEM_ROSELI_BERRY)] = {TYPE_FAIRY, 80},
    [ITEM_TO_BERRY(ITEM_BLUK_BERRY)] = {TYPE_FIRE, 90},
    [ITEM_TO_BERRY(ITEM_NANAB_BERRY)] = {TYPE_WATER, 90},
    [ITEM_TO_BERRY(ITEM_WEPEAR_BERRY)] = {TYPE_ELECTRIC, 90},
    [ITEM_TO_BERRY(ITEM_PINAP_BERRY)] = {TYPE_GRASS, 90},
    [ITEM_TO_BERRY(ITEM_POMEG_BERRY)] = {TYPE_ICE, 90},
    [ITEM_TO_BERRY(ITEM_KELPSY_BERRY)] = {TYPE_FIGHTING, 90},
    [ITEM_TO_BERRY(ITEM_QUALOT_BERRY)] = {TYPE_POISON, 90},
    [ITEM_TO_BERRY(ITEM_HONDEW_BERRY)] = {TYPE_GROUND, 90},
    [ITEM_TO_BERRY(ITEM_GREPA_BERRY)] = {TYPE_FLYING, 90},
    [ITEM_TO_BERRY(ITEM_TAMATO_BERRY)] = {TYPE_PSYCHIC, 90},
    [ITEM_TO_BERRY(ITEM_CORNN_BERRY)] = {TYPE_BUG, 90},
    [ITEM_TO_BERRY(ITEM_MAGOST_BERRY)] = {TYPE_ROCK, 90},
    [ITEM_TO_BERRY(ITEM_RABUTA_BERRY)] = {TYPE_GHOST, 90},
    [ITEM_TO_BERRY(ITEM_NOMEL_BERRY)] = {TYPE_DRAGON, 90},
    [ITEM_TO_BERRY(ITEM_SPELON_BERRY)] = {TYPE_DARK, 90},
    [ITEM_TO_BERRY(ITEM_PAMTRE_BERRY)] = {TYPE_STEEL, 90},
    [ITEM_TO_BERRY(ITEM_WATMEL_BERRY)] = {TYPE_FIRE, 100},
    [ITEM_TO_BERRY(ITEM_DURIN_BERRY)] = {TYPE_WATER, 100},
    [ITEM_TO_BERRY(ITEM_BELUE_BERRY)] = {TYPE_ELECTRIC, 100},
    [ITEM_TO_BERRY(ITEM_LIECHI_BERRY)] = {TYPE_GRASS, 100},
    [ITEM_TO_BERRY(ITEM_GANLON_BERRY)] = {TYPE_ICE, 100},
    [ITEM_TO_BERRY(ITEM_SALAC_BERRY)] = {TYPE_FIGHTING, 100},
    [ITEM_TO_BERRY(ITEM_PETAYA_BERRY)] = {TYPE_POISON, 100},
    [ITEM_TO_BERRY(ITEM_APICOT_BERRY)] = {TYPE_GROUND, 100},
    [ITEM_TO_BERRY(ITEM_LANSAT_BERRY)] = {TYPE_FLYING, 100},
    [ITEM_TO_BERRY(ITEM_STARF_BERRY)] = {TYPE_PSYCHIC, 100},
    [ITEM_TO_BERRY(ITEM_ENIGMA_BERRY)] = {TYPE_BUG, 100},
    [ITEM_TO_BERRY(ITEM_MICLE_BERRY)] = {TYPE_ROCK, 100},
    [ITEM_TO_BERRY(ITEM_CUSTAP_BERRY)] = {TYPE_GHOST, 100},
    [ITEM_TO_BERRY(ITEM_JABOCA_BERRY)] = {TYPE_DRAGON, 100},
    [ITEM_TO_BERRY(ITEM_ROWAP_BERRY)] = {TYPE_DARK, 100},
    [ITEM_TO_BERRY(ITEM_KEE_BERRY)] = {TYPE_FAIRY, 100},
    [ITEM_TO_BERRY(ITEM_MARANGA_BERRY)] = {TYPE_DARK, 100},
};

static u16 CalcMoveBasePower(u16 move, u8 battlerAtk, u8 battlerDef)
{
    u32 i;
    u16 basePower = gBattleMoves[move].power;
    u32 weight, hpFraction, speed;

    if (gSpecialStatuses[battlerAtk].parentalBondTrigger == ABILITY_MINION_CONTROL
        && gSpecialStatuses[battlerAtk].parentalBondOn < gSpecialStatuses[battlerAtk].parentalBondInitialCount)
        return 10;

    switch (gBattleMoves[move].effect)
    {
    case EFFECT_PLEDGE:
        // todo
        break;
    case EFFECT_FLING:
        // todo: program Fling + Unburden interaction
        break;
    case EFFECT_ERUPTION:
        basePower = gBattleMons[battlerAtk].hp * basePower / gBattleMons[battlerAtk].maxHP;
        break;
    case EFFECT_RETURN:
        basePower = 10 * (gBattleMons[battlerAtk].friendship) / 25;
        break;
    case EFFECT_FRUSTRATION:
        basePower = 10 * (255 - gBattleMons[battlerAtk].friendship) / 25;
        break;
    case EFFECT_FURY_CUTTER:
        for (i = 1; i < gDisableStructs[battlerAtk].furyCutterCounter; i++)
            basePower *= 2;
        break;
    case EFFECT_ROLLOUT:
        for (i = 1; i < (5 - gDisableStructs[battlerAtk].rolloutTimer); i++)
            basePower *= 2;
        if (gBattleMons[battlerAtk].status2 & STATUS2_DEFENSE_CURL)
            basePower *= 2;
        break;
    case EFFECT_MAGNITUDE:
        basePower = gBattleStruct->magnitudeBasePower;
        break;
    case EFFECT_PRESENT:
        basePower = gBattleStruct->presentBasePower;
        break;
    case EFFECT_TRIPLE_KICK:
        basePower += gBattleScripting.tripleKickPower;
        break;
    case EFFECT_SPIT_UP:
        basePower = 100 * gDisableStructs[battlerAtk].stockpileCounter;
        break;
    case EFFECT_REVENGE:
        if ((gProtectStructs[battlerAtk].physicalDmg
                && gProtectStructs[battlerAtk].physicalBattlerId == battlerDef)
            || (gProtectStructs[battlerAtk].specialDmg
                && gProtectStructs[battlerAtk].specialBattlerId == battlerDef))
            basePower *= 2;
        break;
    case EFFECT_WEATHER_BALL:
        if (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_CHLOROPLAST) || BATTLER_HAS_ABILITY(battlerAtk, ABILITY_BIG_LEAVES))
            basePower *= 2;
        else if (gBattleWeather & B_WEATHER_ANY && WEATHER_HAS_EFFECT)
            basePower *= 2;
        break;
    case EFFECT_PURSUIT:
        if (gActionsByTurnOrder[GetBattlerTurnOrderNum(gBattlerTarget)] == B_ACTION_SWITCH)
            basePower *= 2;
        break;
    case EFFECT_NATURAL_GIFT:
        basePower = gNaturalGiftTable[ITEM_TO_BERRY(gBattleMons[battlerAtk].item)].power;
        break;
    case EFFECT_WAKE_UP_SLAP:
        if (gBattleMons[battlerDef].status1 & STATUS1_SLEEP || GetBattlerAbility(battlerDef) == ABILITY_COMATOSE)
            basePower *= 2;
        break;
    case EFFECT_SMELLINGSALT:
        if (gBattleMons[battlerDef].status1 & STATUS1_PARALYSIS)
            basePower *= 2;
        break;
    case EFFECT_WRING_OUT:
        basePower = 120 * gBattleMons[battlerDef].hp / gBattleMons[battlerDef].maxHP;
        break;
    case EFFECT_HEX:
    case EFFECT_INFERNAL_PARADE:
        if (gBattleMons[battlerDef].status1 & STATUS1_ANY || GetBattlerAbility(battlerDef) == ABILITY_COMATOSE)
            basePower *= 2;
        break;
    case EFFECT_ASSURANCE:
        if (gProtectStructs[battlerDef].physicalDmg != 0 || gProtectStructs[battlerDef].specialDmg != 0 || gProtectStructs[battlerDef].confusionSelfDmg)
            basePower *= 2;
        break;
    case EFFECT_TRUMP_CARD:
        i = GetBattleMonMoveSlot(&gBattleMons[battlerAtk], move);
        if (i != 4)
        {
            if (gBattleMons[battlerAtk].pp[i] >= ARRAY_COUNT(sTrumpCardPowerTable))
                basePower = sTrumpCardPowerTable[ARRAY_COUNT(sTrumpCardPowerTable) - 1];
            else
                basePower = sTrumpCardPowerTable[gBattleMons[battlerAtk].pp[i]];
        }
        break;
    case EFFECT_ACROBATICS:
        if (gBattleMons[battlerAtk].item == ITEM_NONE
            // Edge case, because removal of items happens after damage calculation.
            || (gSpecialStatuses[battlerAtk].gemBoost && GetBattlerHoldEffect(battlerAtk, FALSE) == HOLD_EFFECT_GEMS))
            basePower *= 2;
        break;
    case EFFECT_LOW_KICK:
        weight = GetBattlerWeight(battlerDef);
        for (i = 0; sWeightToDamageTable[i] != 0xFFFF; i += 2)
        {
            if (sWeightToDamageTable[i] > weight)
                break;
        }
        if (sWeightToDamageTable[i] != 0xFFFF)
            basePower = sWeightToDamageTable[i + 1];
        else
            basePower = 120;
        break;
    case EFFECT_HEAT_CRASH:
        weight = GetBattlerWeight(battlerAtk) / GetBattlerWeight(battlerDef);
        if (weight >= ARRAY_COUNT(sHeatCrashPowerTable))
            basePower = sHeatCrashPowerTable[ARRAY_COUNT(sHeatCrashPowerTable) - 1];
        else
            basePower = sHeatCrashPowerTable[weight];
        break;
    case EFFECT_PUNISHMENT:
        basePower = 60 + (CountBattlerStatIncreases(battlerDef, FALSE) * 20);
        if (basePower > 200)
            basePower = 200;
        break;
    case EFFECT_STORED_POWER:
        basePower += (CountBattlerStatIncreases(battlerAtk, TRUE) * 20);
        break;
    case EFFECT_ELECTRO_BALL:
        speed = GetBattlerTotalSpeedStat(battlerAtk, TOTAL_SPEED_FULL) / GetBattlerTotalSpeedStat(battlerDef, TOTAL_SPEED_FULL);
        if (speed >= ARRAY_COUNT(sSpeedDiffPowerTable))
            speed = ARRAY_COUNT(sSpeedDiffPowerTable) - 1;
        basePower = sSpeedDiffPowerTable[speed];
        break;
    case EFFECT_GYRO_BALL:
        basePower = ((25 * GetBattlerTotalSpeedStat(battlerDef, TOTAL_SPEED_FULL)) / GetBattlerTotalSpeedStat(battlerAtk, TOTAL_SPEED_FULL)) + 1;
        if (basePower > 150)
            basePower = 150;
        break;
    case EFFECT_ECHOED_VOICE:
        // gBattleStruct->sameMoveTurns incremented in ppreduce
        if (gBattleStruct->sameMoveTurns[battlerAtk] != 0)
        {
            basePower += (basePower * gBattleStruct->sameMoveTurns[battlerAtk]);
            if (basePower > 200)
                basePower = 200;
        }
        break;
    case EFFECT_PAYBACK:
        if (GetBattlerTurnOrderNum(battlerAtk) > GetBattlerTurnOrderNum(battlerDef)
            && (gDisableStructs[battlerDef].isFirstTurn != 2 || B_PAYBACK_SWITCH_BOOST < GEN_5))
            basePower *= 2;
        break;
    case EFFECT_BOLT_BEAK:
        if (GetBattlerTurnOrderNum(battlerAtk) < GetBattlerTurnOrderNum(battlerDef))
            basePower *= 2;
        break;
    case EFFECT_ROUND:
        if (gChosenMoveByBattler[BATTLE_PARTNER(battlerAtk)] == MOVE_ROUND && !(gAbsentBattlerFlags & gBitTable[BATTLE_PARTNER(battlerAtk)]))
            basePower *= 2;
        break;
    case EFFECT_FUSION_COMBO:
        if (gBattleMoves[gLastUsedMove].effect == EFFECT_FUSION_COMBO && move != gLastUsedMove)
            basePower *= 2;
        break;
    case EFFECT_LASH_OUT:
        if (gProtectStructs[battlerAtk].statFell)
            basePower *= 2;
        break;
    case EFFECT_EXPLOSION:
        if (move == MOVE_MISTY_EXPLOSION && GetCurrentTerrain() == STATUS_FIELD_MISTY_TERRAIN && IsBattlerGrounded(battlerAtk))
            MulModifier(&basePower, UQ_4_12(1.5));
        break;
    case EFFECT_DYNAMAX_DOUBLE_DMG:
        #ifdef B_DYNAMAX
        if (IsDynamaxed(battlerDef))
            basePower *= 2;
        #endif
        break;
    #if B_BEAT_UP_DMG >= GEN_5
    case EFFECT_BEAT_UP:
        basePower = CalcBeatUpPower();
        break;
    #endif
    case EFFECT_GRAV_APPLE:
        if (IsGravityActive())
            MulModifier(&basePower, UQ_4_12(1.5));
        break;
    case EFFECT_TERRAIN_PULSE:
        if ((gFieldStatuses & STATUS_FIELD_TERRAIN_ANY) && IsBattlerGrounded(gBattlerAttacker))
            basePower *= 2;
        break;
    case EFFECT_RISING_VOLTAGE:
        if (GetCurrentTerrain() == STATUS_FIELD_ELECTRIC_TERRAIN && IsBattlerGrounded(battlerDef))
            basePower *= 2;
        break;
    case EFFECT_EXPANDING_FORCE:
        if (GetCurrentTerrain() == STATUS_FIELD_PSYCHIC_TERRAIN)
            basePower = 120;
        break;
    case EFFECT_MISTY_TERRAIN_BOOST:
        if (GetCurrentTerrain() == STATUS_FIELD_MISTY_TERRAIN && IsBattlerGrounded(gBattlerAttacker))
            basePower = basePower * 13 / 10;
        break;
    case EFFECT_MISC_HIT:
        switch (gBattleMoves[move].argument)
        {
            case MISC_EFFECT_FAINTED_MON_BOOST:
                basePower += 10 * gFaintedMonCount[GetBattlerSide(gBattlerAttacker)];
                break;
            case MISC_EFFECT_ELECTRIC_TERRAIN_BOOST:
                if (IsBattlerTerrainAffected(gBattlerAttacker, STATUS_FIELD_ELECTRIC_TERRAIN))
                    basePower = basePower * 3 / 2;
                break;
            case MISC_EFFECT_TOOK_DAMAGE_BOOST:
                basePower += 20 * min(3, gBattleStruct->timesDamaged[gBattlerPartyIndexes[gBattlerAttacker]][GetBattlerSide(gBattlerAttacker)]);
                break;
        }
        break;
    }

    // move-specific base power changes
    switch (move)
    {
    case MOVE_WATER_SHURIKEN:
        if (gBattleMons[battlerAtk].species == SPECIES_GRENINJA_ASH)
            basePower = 20;
        break;
    }

    if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_ANGELS_WRATH)){
        switch(move){
        case MOVE_TACKLE:
            basePower = 100;
            break;
        case MOVE_POISON_STING:
            basePower = 120;
            break;
        case MOVE_ELECTROWEB:
            basePower = 155;
            break;
        case MOVE_BUG_BITE:
            basePower = 140;
            break;
        }
    }

    if (basePower == 0)
        basePower = 1;
    return basePower;
}

u32 CalcMoveBasePowerAfterModifiers(u16 move, u8 fixedPower, u8 battlerAtk, u8 battlerDef, u8 moveType, bool32 updateFlags)
{
    u32 i, ability;
    u32 holdEffectAtk, holdEffectParamAtk;
    u16 basePower = CalcMoveBasePower(move, battlerAtk, battlerDef);
    u16 actualPower = fixedPower ? fixedPower : basePower;
    u16 holdEffectModifier;
    u16 modifier = UQ_4_12(1.0);
    u32 atkSide = GET_BATTLER_SIDE(battlerAtk);
	u8 numsleepmons = 0;
	
	for (i = 0; i < gBattlersCount; i++)
    {
        if ((gBattleMons[i].status1 & STATUS1_SLEEP) && IsBattlerAlive(i))
            numsleepmons++;
    }
	
	// Attacker Abilities and Innates
	
	// Reckless
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_RECKLESS)){
		if (gBattleMoves[move].flags & FLAG_RECKLESS_BOOST)
           MulModifier(&modifier, UQ_4_12(1.2));
    }

    // Keen Edge
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_KEEN_EDGE)){
		if (gBattleMoves[move].flags & FLAG_KEEN_EDGE_BOOST)
           MulModifier(&modifier, UQ_4_12(1.3));
    }

    // Molten Blades
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_MOLTEN_BLADES)){
		if (gBattleMoves[move].flags & FLAG_KEEN_EDGE_BOOST)
           MulModifier(&modifier, UQ_4_12(1.3));
    }

    // Sweeping Edge Plus
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_SWEEPING_EDGE_PLUS)){
		if (gBattleMoves[move].flags & FLAG_KEEN_EDGE_BOOST)
           MulModifier(&modifier, UQ_4_12(1.3));
    }

    // Mystic Blades
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_MYSTIC_BLADES)){
		if (gBattleMoves[move].flags & FLAG_KEEN_EDGE_BOOST)
           MulModifier(&modifier, UQ_4_12(1.3));
    }

    // Mystic Blades
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_PONY_POWER)){
		if (gBattleMoves[move].flags & FLAG_KEEN_EDGE_BOOST)
           MulModifier(&modifier, UQ_4_12(1.3));
           MulModifier(&modifier, UQ_4_12(1.3));
    }
	
	// Iron Fist / Power Fists
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_IRON_FIST) && IS_IRON_FIST(battlerAtk, move))
        MulModifier(&modifier, UQ_4_12(1.3));
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_POWER_FISTS) && IS_IRON_FIST(battlerAtk, move))
        MulModifier(&modifier, UQ_4_12(1.3));
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_NIKA) && IS_IRON_FIST(battlerAtk, move))
        MulModifier(&modifier, UQ_4_12(1.3));

	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_MYTHICAL_ARROWS) && gBattleMoves[move].flags2 & FLAG_ARROW_BASED)
        MulModifier(&modifier, UQ_4_12(1.3));
	
	// Striker
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_STRIKER)){
		if (gBattleMoves[move].flags & FLAG_STRIKER_BOOST)
           MulModifier(&modifier, UQ_4_12(1.3));
    }

    //Combat Specialist 
    if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_COMBAT_SPECIALIST)){
		if (IS_IRON_FIST(battlerAtk, move))
           MulModifier(&modifier, UQ_4_12(1.3));
        if (gBattleMoves[move].flags & FLAG_STRIKER_BOOST)
           MulModifier(&modifier, UQ_4_12(1.3));
    }

	// Mighty Horn & Hunter's Horn
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_MIGHTY_HORN) || BATTLER_HAS_ABILITY(battlerAtk, ABILITY_HUNTERS_HORN)){
		if (gBattleMoves[move].flags2 & FLAG_HORN_BASED)
           MulModifier(&modifier, UQ_4_12(1.3));
    }
    
    // Super Slammer
    if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_SUPER_SLAMMER)){
		if (gBattleMoves[move].flags2 & FLAG_HAMMER_BASED)
           MulModifier(&modifier, UQ_4_12(1.3));
    }
    
    // Archer
    if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_ARCHER)){
		if (gBattleMoves[move].flags2 & FLAG_ARROW_BASED)
           MulModifier(&modifier, UQ_4_12(1.3));
    }
	
	// Field Explorer
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_FIELD_EXPLORER)){
		if (gBattleMoves[move].flags & FLAG_FIELD_BASED)
           MulModifier(&modifier, UQ_4_12(1.25));
    }

    // Giant Wings
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_GIANT_WINGS)){
        if (gBattleMoves[move].flags2 & FLAG_AIR_BASED)
           MulModifier(&modifier, UQ_4_12(1.25));
    }
	
	// Sheer Force
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_SHEER_FORCE)){
		if (gBattleMoves[move].flags & FLAG_SHEER_FORCE_BOOST)
           MulModifier(&modifier, UQ_4_12(1.3));
    }
	
	// Sand Force
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_SAND_FORCE)){
		if ((moveType == TYPE_STEEL || moveType == TYPE_ROCK || moveType == TYPE_GROUND)
            && gBattleWeather & B_WEATHER_SANDSTORM && WEATHER_HAS_EFFECT)
           MulModifier(&modifier, UQ_4_12(1.3));
    }
	
	// Analytic
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_ANALYTIC)){
		if (GetBattlerTurnOrderNum(battlerAtk) == gBattlersCount - 1 && move != MOVE_FUTURE_SIGHT && move != MOVE_DOOM_DESIRE)
           MulModifier(&modifier, UQ_4_12(1.3));
    }
	
	// Strong Jaw
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_STRONG_JAW) && (gBattleMoves[move].flags & FLAG_STRONG_JAW_BOOST))
        MulModifier(&modifier, UQ_4_12(1.5));
	
	// Devourer
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_DEVOURER) && (gBattleMoves[move].flags & FLAG_STRONG_JAW_BOOST))
        MulModifier(&modifier, UQ_4_12(1.5));
	
	// Mind Crush
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_MIND_CRUSH) && (gBattleMoves[move].flags & FLAG_STRONG_JAW_BOOST))
        MulModifier(&modifier, UQ_4_12(1.5));
	
	// Pixilate
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_PIXILATE) && moveType == TYPE_FAIRY && gBattleStruct->ateBoost[battlerAtk])
        MulModifier(&modifier, UQ_4_12(1.1));
    
    //Emanate
    if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_EMANATE) && moveType == TYPE_PSYCHIC && gBattleStruct->ateBoost[battlerAtk])
        MulModifier(&modifier, UQ_4_12(1.1));
    
    //Enlightened
    if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_ENLIGHTENED) && moveType == TYPE_PSYCHIC && gBattleStruct->ateBoost[battlerAtk])
        MulModifier(&modifier, UQ_4_12(1.1));

    // Pollinate
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_POLLINATE) && moveType == TYPE_BUG && gBattleStruct->ateBoost[battlerAtk])
        MulModifier(&modifier, UQ_4_12(1.1));

    // Draconize
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_DRACONIZE) && moveType == TYPE_DRAGON && gBattleStruct->ateBoost[battlerAtk])
        MulModifier(&modifier, UQ_4_12(1.1));
	
	// Galvanize
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_GALVANIZE) && moveType == TYPE_ELECTRIC && gBattleStruct->ateBoost[battlerAtk])
        MulModifier(&modifier, UQ_4_12(1.1));
	
	// Refrigerate
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_REFRIGERATE) && moveType == TYPE_ICE && gBattleStruct->ateBoost[battlerAtk])
        MulModifier(&modifier, UQ_4_12(1.1));
	
	// Refrigerator
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_REFRIGERATOR) && moveType == TYPE_ICE && gBattleStruct->ateBoost[battlerAtk])
        MulModifier(&modifier, UQ_4_12(1.1));
	
	// Aerilate
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_AERILATE) && moveType == TYPE_FLYING && gBattleStruct->ateBoost[battlerAtk])
        MulModifier(&modifier, UQ_4_12(1.1));
	
	// Fertilize
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_FERTILIZE) && moveType == TYPE_GRASS && gBattleStruct->ateBoost[battlerAtk])
        MulModifier(&modifier, UQ_4_12(1.1));
	
	// Normalize
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_NORMALIZE) && moveType == TYPE_NORMAL && gBattleStruct->ateBoost[battlerAtk])
        MulModifier(&modifier, UQ_4_12(1.1));
	
	// Sand Song
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_SAND_SONG) && moveType == TYPE_GROUND && gBattleMoves[move].flags & FLAG_SOUND && gBattleStruct->ateBoost[battlerAtk])
        MulModifier(&modifier, UQ_4_12(1.2));
	
	// Sand Song
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_BANSHEE) && moveType == TYPE_GHOST && gBattleMoves[move].flags & FLAG_SOUND && gBattleStruct->ateBoost[battlerAtk])
        MulModifier(&modifier, UQ_4_12(1.2));
	
	// Punk Rock
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_PUNK_ROCK) && (gBattleMoves[move].flags & FLAG_SOUND))
        MulModifier(&modifier, UQ_4_12(1.3));

    // Amplifier
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_AMPLIFIER) && (gBattleMoves[move].flags & FLAG_SOUND))
        MulModifier(&modifier, UQ_4_12(1.3));

    // Bass Boosted
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_BASS_BOOSTED) && (gBattleMoves[move].flags & FLAG_SOUND))
    {
        MulModifier(&modifier, UQ_4_12(1.3));
        MulModifier(&modifier, UQ_4_12(1.3));
    }
	
	// Steely Spirit
	if(IsAbilityOnSide(battlerAtk, ABILITY_STEELY_SPIRIT) && moveType == TYPE_STEEL)
        MulModifier(&modifier, UQ_4_12(1.3));
	
	// Airborne
	if(IsAbilityOnSide(battlerAtk, ABILITY_AIRBORNE) && moveType == TYPE_FLYING)
        MulModifier(&modifier, UQ_4_12(1.3));
	
	// Transistor
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_TRANSISTOR) && moveType == TYPE_ELECTRIC)
        MulModifier(&modifier, UQ_4_12(1.5));
	
	// Dragon's Maw
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_DRAGONS_MAW) && moveType == TYPE_DRAGON)
        MulModifier(&modifier, UQ_4_12(1.5));
	
	// Liquid Voice
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_LIQUID_VOICE) && (gBattleMoves[move].flags & FLAG_SOUND))
        MulModifier(&modifier, UQ_4_12(1.2));

	// Gorilla Tactics
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_GORILLA_TACTICS) && IS_MOVE_PHYSICAL(move))
        MulModifier(&modifier, UQ_4_12(1.5));

	// Sage Power
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_SAGE_POWER) && IS_MOVE_SPECIAL(move))
        MulModifier(&modifier, UQ_4_12(1.5));

    //Exploit Weakness
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_EXPLOIT_WEAKNESS) && (gBattleMons[battlerDef].status1 & STATUS1_ANY))
        MulModifier(&modifier, UQ_4_12(1.25));

	// Avenger
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_AVENGER) && gSideTimers[atkSide].retaliateTimer == 1)
        MulModifier(&modifier, UQ_4_12(1.5));

	// Immolate
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_IMMOLATE) && moveType == TYPE_FIRE && gBattleStruct->ateBoost[battlerAtk])
		MulModifier(&modifier, UQ_4_12(1.1));

    // Mineralize
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_MINERALIZE) && moveType == TYPE_ROCK && gBattleStruct->ateBoost[battlerAtk])
		MulModifier(&modifier, UQ_4_12(1.1));

    // Spectral Shroud
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_SPECTRAL_SHROUD) && moveType == TYPE_GHOST && gBattleStruct->ateBoost[battlerAtk])
		MulModifier(&modifier, UQ_4_12(1.1));

    // Spectralize
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_SPECTRALIZE) && moveType == TYPE_GHOST && gBattleStruct->ateBoost[battlerAtk])
		MulModifier(&modifier, UQ_4_12(1.1));

    // Solar Flare
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_SOLAR_FLARE) && moveType == TYPE_FIRE && gBattleStruct->ateBoost[battlerAtk])
		MulModifier(&modifier, UQ_4_12(1.1));

	// Crystallize
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_CRYSTALLIZE) && moveType == TYPE_ICE && gBattleStruct->ateBoost[battlerAtk])
		MulModifier(&modifier, UQ_4_12(1.1));

	// Fight Spirit
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_FIGHT_SPIRIT) && moveType == TYPE_FIGHTING && gBattleStruct->ateBoost[battlerAtk])
		MulModifier(&modifier, UQ_4_12(1.1));
	
	// Tectonize
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_TECTONIZE) && moveType == TYPE_GROUND && gBattleStruct->ateBoost[battlerAtk])
		MulModifier(&modifier, UQ_4_12(1.1));
	
	// Hydrate
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_HYDRATE) && moveType == TYPE_WATER && gBattleStruct->ateBoost[battlerAtk])
		MulModifier(&modifier, UQ_4_12(1.1));
	
	// Intoxicate
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_INTOXICATE) && moveType == TYPE_POISON && gBattleStruct->ateBoost[battlerAtk])
		MulModifier(&modifier, UQ_4_12(1.1));
	
	// Long Reach
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_LONG_REACH) && IS_MOVE_PHYSICAL(move) && !(gBattleMoves[move].flags & FLAG_MAKES_CONTACT))
        MulModifier(&modifier, UQ_4_12(1.2));
	
	// Tough Claws
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_TOUGH_CLAWS) && IsMoveMakingContact(move, battlerAtk))
        MulModifier(&modifier, UQ_4_12(1.3));
    
	// Big Pecks
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_BIG_PECKS) && IsMoveMakingContact(move, battlerAtk))
        MulModifier(&modifier, UQ_4_12(1.3));
	
	//Dream Catcher
    if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_DREAMCATCHER) && numsleepmons > 0) //It used to be depending on the number of sleeping mons, but the sleep clause made it useless
		MulModifier(&modifier, UQ_4_12(2.0));

	// Rivalry
    if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_RIVALRY)){
        if (GetGenderFromSpeciesAndPersonality(gBattleMons[battlerAtk].species, gBattleMons[battlerAtk].personality) != MON_GENDERLESS
            && GetGenderFromSpeciesAndPersonality(gBattleMons[battlerDef].species, gBattleMons[battlerDef].personality) != MON_GENDERLESS)
            {
                if (GetGenderFromSpeciesAndPersonality(gBattleMons[battlerAtk].species, gBattleMons[battlerAtk].personality)
                == GetGenderFromSpeciesAndPersonality(gBattleMons[battlerDef].species, gBattleMons[battlerDef].personality))
                MulModifier(&modifier, UQ_4_12(1.25));
            }
	}

    // Cosmic Daze
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_COSMIC_DAZE) && gBattleMons[battlerDef].status2 & STATUS2_CONFUSION)
        MulModifier(&modifier, UQ_4_12(2.0));
	
	// Dragonslayer
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_DRAGONSLAYER) && IS_BATTLER_OF_TYPE(battlerDef, TYPE_DRAGON)) // check if foe has Dragon-type
        MulModifier(&modifier, UQ_4_12(1.5));

    // Fae Hunter
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_FAE_HUNTER) && IS_BATTLER_OF_TYPE(battlerDef, TYPE_FAIRY)) // check if foe has Fairy-type
        MulModifier(&modifier, UQ_4_12(1.5));

    // Fae Hunter
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_MONSTER_HUNTER) && IS_BATTLER_OF_TYPE(battlerDef, TYPE_DARK)) // check if foe has Fairy-type
        MulModifier(&modifier, UQ_4_12(1.5));

    // Marine Apex
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_MARINE_APEX) && IS_BATTLER_OF_TYPE(battlerDef, TYPE_WATER)) // check if foe has Water-type
        MulModifier(&modifier, UQ_4_12(1.5));

    // Lumberjack
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_LUMBERJACK) && IS_BATTLER_OF_TYPE(battlerDef, TYPE_GRASS))
        MulModifier(&modifier, UQ_4_12(1.5));

    // Blood Price
    if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_BLOOD_PRICE))
        MulModifier(&modifier, UQ_4_12(1.3));
	
	//Toxic Boost
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_TOXIC_BOOST) && (gBattleMons[battlerAtk].status1 & STATUS1_PSN_ANY) && IS_MOVE_PHYSICAL(move))
        MulModifier(&modifier, UQ_4_12(1.5));
	
	//Flare Boost
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_FLARE_BOOST) && (gBattleMons[battlerAtk].status1 & STATUS1_BURN) && IS_MOVE_SPECIAL(move))
        MulModifier(&modifier, UQ_4_12(1.5));
	
	// Mega Launcher
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_MEGA_LAUNCHER) && (gBattleMoves[move].flags & FLAG_MEGA_LAUNCHER_BOOST))
        MulModifier(&modifier, UQ_4_12(1.5));

    // Iron Barrage
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_IRON_BARRAGE) && (gBattleMoves[move].flags & FLAG_MEGA_LAUNCHER_BOOST))
        MulModifier(&modifier, UQ_4_12(1.5));
	
	// Hustle
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_HUSTLE))
        MulModifier(&modifier, UQ_4_12(1.4));
	
	// Technician
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_TECHNICIAN) && basePower <= 60 )
        MulModifier(&modifier, UQ_4_12(1.5));

    // Kunoichi's Blade
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_KUNOICHI_BLADE) && basePower <= 60 )
        MulModifier(&modifier, UQ_4_12(1.5));
	
	// Water Bubble
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_WATER_BUBBLE) && moveType == TYPE_WATER)
        MulModifier(&modifier, UQ_4_12(2.0));

    // Hydro Circuit
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_HYDRO_CIRCUIT) && moveType == TYPE_ELECTRIC)
        MulModifier(&modifier, UQ_4_12(1.5));
	
    // Field Abilities
    if ((IsAbilityOnField(ABILITY_DARK_AURA) && moveType == TYPE_DARK)
        || (IsAbilityOnField(ABILITY_FAIRY_AURA) && moveType == TYPE_FAIRY)
        || (IsAbilityOnField(ABILITY_PIXIE_POWER) && moveType == TYPE_FAIRY))
    {
        if (IsAbilityOnField(ABILITY_AURA_BREAK))
            MulModifier(&modifier, UQ_4_12(0.75));
        else
            MulModifier(&modifier, UQ_4_12(1.33));
    }

    // Pretty Princess
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_PRETTY_PRINCESS)){
        if(!BATTLER_HAS_ABILITY(battlerAtk, ABILITY_UNAWARE) &&
           !BATTLER_HAS_ABILITY(battlerDef, ABILITY_UNAWARE) &&
           HasAnyLoweredStat(battlerDef))
            MulModifier(&modifier, UQ_4_12(1.5));
    }

    // Attacker Partner's Abilities
    if (IsBattlerAlive(BATTLE_PARTNER(battlerAtk)))
    {
		// Attacker Partner's Abilities and Innates
		
		// Battery
		if(BATTLER_HAS_ABILITY(BATTLE_PARTNER(battlerAtk), ABILITY_BATTERY)){
			if (IS_MOVE_SPECIAL(move))
                MulModifier(&modifier, UQ_4_12(1.3));
		}
		
		// Power Spot
		if(BATTLER_HAS_ABILITY(BATTLE_PARTNER(battlerAtk), ABILITY_POWER_SPOT)){
			MulModifier(&modifier, UQ_4_12(1.3));
		}
    }
	
	// Target's Abilities and Innates
	// Heatproof & Water Bubble
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_HEATPROOF)){
        if (moveType == TYPE_FIRE)
        {
            MulModifier(&modifier, UQ_4_12(0.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ability);
        }
	}

	// Water Bubble
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_WATER_BUBBLE)){
        if (moveType == TYPE_FIRE)
        {
            MulModifier(&modifier, UQ_4_12(0.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ability);
        }
	}
    
	// Well Baked Body
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_WELL_BAKED_BODY)){
        if (moveType == TYPE_FIRE)
        {
            MulModifier(&modifier, UQ_4_12(0.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ability);
        }
	}
	
    // Dry Skin
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_DRY_SKIN)){
		if (moveType == TYPE_FIRE)
            MulModifier(&modifier, UQ_4_12(1.25));
	}
	
	// Fluffy
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_FLUFFY)){
		if (IsMoveMakingContact(move, battlerAtk))
        {
            MulModifier(&modifier, UQ_4_12(0.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ability);
        }
		if (moveType == TYPE_FIRE)
            MulModifier(&modifier, UQ_4_12(2.0));
	}
	
	// Liquified
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_LIQUIFIED)){
		if (IsMoveMakingContact(move, battlerAtk))
        {
            MulModifier(&modifier, UQ_4_12(0.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ability);
        }
        if (moveType == TYPE_WATER)
            MulModifier(&modifier, UQ_4_12(2.0));
	}

	// Christmas Spirit
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_CHRISTMAS_SPIRIT)){
		if(WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_HAIL_ANY){
			MulModifier(&modifier, UQ_4_12(0.5));
		}
    }

    // Dune Terror
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_DUNE_TERROR)){
		if(WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SANDSTORM_ANY){
			MulModifier(&modifier, UQ_4_12(0.65));
		}
    }

	// Battle Armor
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_BATTLE_ARMOR))
		MulModifier(&modifier, UQ_4_12(0.8));

	// Shell Armor
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_SHELL_ARMOR))
		MulModifier(&modifier, UQ_4_12(0.8));

	// Lead Coat
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_LEAD_COAT) && IS_MOVE_PHYSICAL(move))
		MulModifier(&modifier, UQ_4_12(0.6));

	// Lead Coat
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_CHROME_COAT) && IS_MOVE_SPECIAL(move))
		MulModifier(&modifier, UQ_4_12(0.6));

    // Parry
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_PARRY))
		MulModifier(&modifier, UQ_4_12(0.8));

	// Fossilized
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_FOSSILIZED)){
		if (moveType == TYPE_ROCK)
            MulModifier(&modifier, UQ_4_12(0.5));
    }

	// Immunity
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_IMMUNITY)){
		if (moveType == TYPE_POISON)
            MulModifier(&modifier, UQ_4_12(0.8));
    }

    holdEffectAtk = GetBattlerHoldEffect(battlerAtk, TRUE);
    holdEffectParamAtk = GetBattlerHoldEffectParam(battlerAtk);
    if (holdEffectParamAtk > 100)
        holdEffectParamAtk = 100;

    holdEffectModifier = UQ_4_12(1.0) + sPercentToModifier[holdEffectParamAtk];

    // attacker's hold effect
    switch (holdEffectAtk)
    {
    case HOLD_EFFECT_MUSCLE_BAND:
        if (IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_WISE_GLASSES:
        if (IS_MOVE_SPECIAL(move))
            MulModifier(&modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_LUSTROUS_ORB:
        if (gBattleMons[battlerAtk].species == SPECIES_PALKIA && (moveType == TYPE_WATER || moveType == TYPE_DRAGON))
            MulModifier(&modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_ADAMANT_ORB:
        if (gBattleMons[battlerAtk].species == SPECIES_DIALGA && (moveType == TYPE_STEEL || moveType == TYPE_DRAGON))
            MulModifier(&modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_GRISEOUS_ORB:
        if (gBattleMons[battlerAtk].species == SPECIES_GIRATINA && (moveType == TYPE_GHOST || moveType == TYPE_DRAGON))
            MulModifier(&modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_SOUL_DEW:
        #if B_SOUL_DEW_BOOST >= GEN_7
        if ((gBattleMons[battlerAtk].species == SPECIES_LATIAS || gBattleMons[battlerAtk].species == SPECIES_LATIOS) && (moveType == TYPE_PSYCHIC || moveType == TYPE_DRAGON))
        #else
        if ((gBattleMons[battlerAtk].species == SPECIES_LATIAS || gBattleMons[battlerAtk].species == SPECIES_LATIOS) && !(gBattleTypeFlags & BATTLE_TYPE_FRONTIER) && IS_MOVE_SPECIAL(move))
        #endif
            MulModifier(&modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_GEMS:
        if (gSpecialStatuses[battlerAtk].gemBoost && gBattleMons[battlerAtk].item)
            MulModifier(&modifier, UQ_4_12(1.0) + sPercentToModifier[gSpecialStatuses[battlerAtk].gemParam]);
        break;
    case HOLD_EFFECT_BUG_POWER:
    case HOLD_EFFECT_STEEL_POWER:
    case HOLD_EFFECT_GROUND_POWER:
    case HOLD_EFFECT_ROCK_POWER:
    case HOLD_EFFECT_GRASS_POWER:
    case HOLD_EFFECT_DARK_POWER:
    case HOLD_EFFECT_FIGHTING_POWER:
    case HOLD_EFFECT_ELECTRIC_POWER:
    case HOLD_EFFECT_WATER_POWER:
    case HOLD_EFFECT_FLYING_POWER:
    case HOLD_EFFECT_POISON_POWER:
    case HOLD_EFFECT_ICE_POWER:
    case HOLD_EFFECT_GHOST_POWER:
    case HOLD_EFFECT_PSYCHIC_POWER:
    case HOLD_EFFECT_FIRE_POWER:
    case HOLD_EFFECT_DRAGON_POWER:
    case HOLD_EFFECT_NORMAL_POWER:
    case HOLD_EFFECT_FAIRY_POWER:
        for (i = 0; i < ARRAY_COUNT(sHoldEffectToType); i++)
        {
            if (holdEffectAtk == sHoldEffectToType[i][0])
            {
                if (moveType == sHoldEffectToType[i][1])
                    MulModifier(&modifier, holdEffectModifier);
                break;
            }
        }
        break;
    case HOLD_EFFECT_PLATE:
        if (moveType == ItemId_GetSecondaryId(gBattleMons[battlerAtk].item))
            MulModifier(&modifier, holdEffectModifier);
        break;
    }

    // move effect
    switch (gBattleMoves[move].effect)
    {
    case EFFECT_DOUBLE_DMG_IF_STATUS1:
        if (gBattleMons[battlerDef].status1 & (gBattleMoves[move].argument))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case EFFECT_FACADE:
        if (gBattleMons[battlerAtk].status1 & (STATUS1_BURN | STATUS1_PSN_ANY | STATUS1_PARALYSIS| STATUS1_FROSTBITE))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case EFFECT_BRINE:
        if (gBattleMons[battlerDef].hp <= (gBattleMons[battlerDef].maxHP / 2))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case EFFECT_VENOSHOCK:
        if (gBattleMons[battlerDef].status1 & STATUS1_PSN_ANY)
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case EFFECT_RETALIATE:
        if (gSideTimers[atkSide].retaliateTimer == 1)
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case EFFECT_SOLARBEAM:
        if (IsBattlerWeatherAffected(battlerAtk, (WEATHER_HAIL_ANY | WEATHER_SANDSTORM_ANY | WEATHER_RAIN_ANY))
            && !BattlerHasInnate(gBattlerAttacker, ABILITY_SOLAR_FLARE)
            && GetBattlerAbility(gBattlerAttacker) != ABILITY_SOLAR_FLARE
            && !BattlerHasInnate(gBattlerAttacker, ABILITY_BIG_LEAVES)
            && GetBattlerAbility(gBattlerAttacker) != ABILITY_BIG_LEAVES
			&& !BattlerHasInnate(gBattlerAttacker, ABILITY_CHLOROPLAST)
            && GetBattlerAbility(gBattlerAttacker) != ABILITY_CHLOROPLAST)
            MulModifier(&modifier, UQ_4_12(0.5));
        break;
    case EFFECT_STOMPING_TANTRUM:
        if (gBattleStruct->lastMoveFailed & gBitTable[battlerAtk])
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case EFFECT_BULLDOZE:
    case EFFECT_MAGNITUDE:
    case EFFECT_EARTHQUAKE:
        if (GetCurrentTerrain() == STATUS_FIELD_GRASSY_TERRAIN && !(gStatuses3[battlerDef] & STATUS3_SEMI_INVULNERABLE))
            MulModifier(&modifier, UQ_4_12(0.5));
        break;
    case EFFECT_KNOCK_OFF:
        #if B_KNOCK_OFF_DMG >= GEN_6
        if (gBattleMons[battlerDef].item != ITEM_NONE
            && CanBattlerGetOrLoseItem(battlerDef, gBattleMons[battlerDef].item))
            MulModifier(&modifier, UQ_4_12(1.5));
        #endif
        break;
    }

    // various effecs
    if (gProtectStructs[battlerAtk].helpingHand)
        MulModifier(&modifier, UQ_4_12(1.5));
    if (gStatuses4[battlerAtk] & STATUS4_GHASTLY_ECHO)
        MulModifier(&modifier, UQ_4_12(1.5));
    if (gStatuses3[battlerAtk] & STATUS3_CHARGED_UP && moveType == TYPE_ELECTRIC)
        MulModifier(&modifier, UQ_4_12(2.0));
    if (gStatuses3[battlerAtk] & STATUS3_ME_FIRST)
        MulModifier(&modifier, UQ_4_12(1.5));
    if (GetCurrentTerrain() == STATUS_FIELD_GRASSY_TERRAIN && moveType == TYPE_GRASS && IsBattlerGrounded(battlerAtk) && !(gStatuses3[battlerAtk] & STATUS3_SEMI_INVULNERABLE))
        MulModifier(&modifier, (B_TERRAIN_TYPE_BOOST >= GEN_8) ? UQ_4_12(1.3) : UQ_4_12(1.5));
    if (GetCurrentTerrain() == STATUS_FIELD_ELECTRIC_TERRAIN && moveType == TYPE_ELECTRIC && IsBattlerGrounded(battlerAtk) && !(gStatuses3[battlerAtk] & STATUS3_SEMI_INVULNERABLE))
        MulModifier(&modifier, (B_TERRAIN_TYPE_BOOST >= GEN_8) ? UQ_4_12(1.3) : UQ_4_12(1.5));
    if (GetCurrentTerrain() == STATUS_FIELD_PSYCHIC_TERRAIN && moveType == TYPE_PSYCHIC && IsBattlerGrounded(battlerAtk) && !(gStatuses3[battlerAtk] & STATUS3_SEMI_INVULNERABLE))
        MulModifier(&modifier, (B_TERRAIN_TYPE_BOOST >= GEN_8) ? UQ_4_12(1.3) : UQ_4_12(1.5));
    if (GetCurrentTerrain() == STATUS_FIELD_MISTY_TERRAIN && moveType == TYPE_FAIRY && IsBattlerGrounded(battlerAtk) && !(gStatuses3[battlerAtk] & STATUS3_SEMI_INVULNERABLE))
        MulModifier(&modifier, (B_TERRAIN_TYPE_BOOST >= GEN_8) ? UQ_4_12(1.3) : UQ_4_12(1.5));
	
    return ApplyModifier(modifier, actualPower);
}

u32 CalculateStat(u8 battler, u8 statEnum, u8 secondaryStat, u16 move, bool8 isAttack, bool8 isCrit, bool8 isUnaware, bool8 calculatingSecondary) {
    u32 statBase = 0;
    u8 statStage = gBattleMons[battler].statStages[statEnum];
    u32 extraStat = 0;

    #define RUIN_CHECK(ability) if (IsAbilityOnFieldExcept(battler, ability) && !BATTLER_HAS_ABILITY(battler, ability)) statBase = statBase * 3 / 4;

    switch (statEnum)
    {
        case STAT_HP:
            return 0;
        case STAT_ATK:
            statBase = gBattleMons[battler].attack;

            // Tablets of Ruin
            RUIN_CHECK(ABILITY_TABLETS_OF_RUIN)
                    
            // Huge Power
            if (BATTLER_HAS_ABILITY(battler, ABILITY_HUGE_POWER)) statBase *= 2;
                    
            // Pure Power
            if (BATTLER_HAS_ABILITY(battler, ABILITY_PURE_POWER)) statBase *= 2;

            // Dead Power
            if (BATTLER_HAS_ABILITY(battler, ABILITY_DEAD_POWER)) statBase = statBase * 3 / 2;
                    
            // Slow Start
            if (BATTLER_HAS_ABILITY(battler, ABILITY_SLOW_START)
                && gDisableStructs[battler].slowStartTimer != 0)
                    statBase /= 2;

            // Violent Rush
            if(BATTLER_HAS_ABILITY(battler, ABILITY_VIOLENT_RUSH)
                && gDisableStructs[battler].isFirstTurn)
                    statBase = statBase * 6 / 5;

            // Showdown Mode
            if(BATTLER_HAS_ABILITY(battler, ABILITY_SHOWDOWN_MODE)
                && gDisableStructs[battler].isFirstTurn)
                    statBase = statBase * 6 / 5;

            // Huge Power on First Turn
            if(BATTLER_HAS_ABILITY(battler, ABILITY_HUGE_POWER_FOR_ONE_TURN)
                && gDisableStructs[battler].isFirstTurn)
                    statBase *= 2;
                    
            // Hadron Engine
            if (BATTLER_HAS_ABILITY(battler, ABILITY_ORICHALCUM_PULSE)
                && IsBattlerWeatherAffected(battler, WEATHER_SUN_ANY))
                    statBase = statBase * 4 / 3;

            // Burn
            if ((gBattleMons[battler].status1 & STATUS1_BURN)
                && gBattleMoves[move].effect != EFFECT_FACADE
                && !BATTLER_HAS_ABILITY(battler, ABILITY_FLARE_BOOST)
                && !BATTLER_HAS_ABILITY(battler, ABILITY_HEATPROOF)
                && !BATTLER_HAS_ABILITY(battler, ABILITY_GUTS))
                    statBase /= 2;

            HANDLE_STAT_CALC_ATK_OR_SPATK:
            // Supreme Overlord
            if (BATTLER_HAS_ABILITY(battler, ABILITY_SUPREME_OVERLORD))
                statBase = statBase * (10 + max(5, gFaintedMonCount[GetBattlerSide(battler)])) / 10;
                    
            // Defeatist
            if (BATTLER_HAS_ABILITY(battler, ABILITY_DEFEATIST)
                && gBattleMons[battler].hp <= (gBattleMons[battler].maxHP / 3))
                    statBase /= 2;
            break;
        case STAT_SPATK:
            statBase = gBattleMons[battler].spAttack;

            // Tablets of Ruin
            RUIN_CHECK(ABILITY_VESSEL_OF_RUIN)
                    
            // Majestic Bird
	        if (BATTLER_HAS_ABILITY(battler, ABILITY_MAJESTIC_BIRD)) statBase = statBase * 3 / 2;
                    
            // Feline Prowess
            if (BATTLER_HAS_ABILITY(battler, ABILITY_FELINE_PROWESS)) statBase *= 2;

            // Special Violent Rush
            if(BATTLER_HAS_ABILITY(battler, ABILITY_SPECIAL_VIOLENT_RUSH)
                && gDisableStructs[battler].isFirstTurn)
                    statBase = statBase * 6 / 5;

            // Hadron Engine
            if (BATTLER_HAS_ABILITY(battler, ABILITY_HADRON_ENGINE)
                && IsBattlerTerrainAffected(battler, STATUS_FIELD_ELECTRIC_TERRAIN))
                    statBase = statBase * 4 / 3;
                    
            // Big Leaves/Solar Power
            if ((BATTLER_HAS_ABILITY(battler, ABILITY_BIG_LEAVES) || BATTLER_HAS_ABILITY(battler, ABILITY_SOLAR_POWER))
                && IsBattlerWeatherAffected(battler, WEATHER_SUN_ANY))
                    statBase = statBase * 3 / 2;
                
            // Frostbite
            if ((gBattleMons[battler].status1 & STATUS1_FROSTBITE)
                && gBattleMoves[move].effect != EFFECT_FACADE
                && !BATTLER_HAS_ABILITY(battler, ABILITY_DETERMINATION))
                    statBase /= 2;
            
            goto HANDLE_STAT_CALC_ATK_OR_SPATK;
            break;
        case STAT_DEF:
            if (isWonderRoomActive()) goto CALCULATE_STAT_SPDEF;
            CALCULATE_STAT_DEF:
            statBase = gBattleMons[battler].defense;

            // Tablets of Ruin
            RUIN_CHECK(ABILITY_SWORD_OF_RUIN)
                    
            // Marvel Scale
            if (BATTLER_HAS_ABILITY(battler, ABILITY_MARVEL_SCALE)
                && gBattleMons[battler].status1 & STATUS1_ANY)
                    statBase = statBase * 3 / 2;
                    
            // Grass Pelt
            if (BATTLER_HAS_ABILITY(battler, ABILITY_GRASS_PELT)
                && GetCurrentTerrain() == STATUS_FIELD_GRASSY_TERRAIN)
                    statBase = statBase * 3 / 2;
            
            // Sandstorm
            if (IS_BATTLER_OF_TYPE(battler, TYPE_ROCK)
                && gBattleWeather & B_WEATHER_SANDSTORM && WEATHER_HAS_EFFECT)
                    statBase = statBase * 3 / 2;
            break;
        case STAT_SPDEF:
            if (isWonderRoomActive()) goto CALCULATE_STAT_DEF;
            CALCULATE_STAT_SPDEF:
            statBase = gBattleMons[battler].spDefense;
            
            // Tablets of Ruin
            RUIN_CHECK(ABILITY_BEADS_OF_RUIN)

            // Flower Gift
            if (BATTLER_HAS_ABILITY(battler, ABILITY_FLOWER_GIFT)
                && gBattleMons[battler].species == SPECIES_CHERRIM
                && IsBattlerWeatherAffected(battler, WEATHER_SUN_ANY))
                    statBase = statBase * 3 / 2;
            if (BATTLER_HAS_ABILITY(BATTLE_PARTNER(battler), ABILITY_FLOWER_GIFT)
                && gBattleMons[BATTLE_PARTNER(battler)].species == SPECIES_CHERRIM
                && IsBattlerWeatherAffected(BATTLE_PARTNER(battler), WEATHER_SUN_ANY))
                    statBase = statBase * 3 / 2;
                    
            // Hail
            if (IS_BATTLER_OF_TYPE(battler, TYPE_ICE)
                && WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_HAIL_ANY)
                    statBase = statBase * 3 / 2;
            break;
        case STAT_SPEED:
            statBase = GetBattlerTotalSpeedStat(battler, calculatingSecondary ? TOTAL_SPEED_SECONDARY : TOTAL_SPEED_PRIMARY);
            break;
    }

    if (statEnum != STAT_SPEED && GetAbilityStateAs(battler, ABILITY_PROTOSYNTHESIS).paradoxBoost.statId == statEnum)
        statBase = statBase * 13 / 10;

    if (statEnum != STAT_SPEED && GetAbilityStateAs(battler, ABILITY_QUARK_DRIVE).paradoxBoost.statId == statEnum)
        statBase = statBase * 13 / 10;

    #undef RUIN_CHECK

    if (isUnaware) statStage = DEFAULT_STAT_STAGE;
    else if (isCrit && isAttack) statStage = max(statStage, DEFAULT_STAT_STAGE);
    else if (isCrit && !isAttack) statStage = min(statStage, DEFAULT_STAT_STAGE);
    
    if (!calculatingSecondary) {
        if (secondaryStat == statEnum && statEnum != STAT_SPEED) statBase = statBase * 6 / 5;
        else if (secondaryStat == statEnum && statEnum == STAT_SPEED) 
        {
            statBase *= gStatStageRatios[statStage][0];
            statBase /= gStatStageRatios[statStage][1];
            statBase += CalculateStat(battler, secondaryStat, 0, move, isAttack, isCrit, isUnaware, TRUE) / 5;
            return statBase;
        }
        else if (secondaryStat) statBase += CalculateStat(battler, secondaryStat, 0, move, isAttack, isCrit, isUnaware, TRUE) / 5;
    }

    statBase *= gStatStageRatios[statStage][0];
    statBase /= gStatStageRatios[statStage][1];
    
    return statBase;
}

static u32 CalcAttackStat(u16 move, u8 battlerAtk, u8 battlerDef, u8 moveType, bool32 isCrit, bool32 updateFlags)
{
    u8 atkStatToUse = 0;
    u8 secondaryAtkStatToUse = 0;
    u8 statBattler = battlerAtk;
    //Calculates Highest Attack Stat after stat boosts
    bool8 isUnaware = BATTLER_HAS_ABILITY(battlerDef, ABILITY_UNAWARE);
    u8 highestAttackStat = STAT_ATK;
    u32 atkStat;
    u16 modifier;

    if (gBattleMoves[move].effect == EFFECT_FOUL_PLAY)
    {
        statBattler = battlerDef;
    }
    else if (gBattleMoves[move].effect == EFFECT_BODY_PRESS)
    {
        isUnaware = BATTLER_HAS_ABILITY(battlerAtk, ABILITY_UNAWARE);
        atkStatToUse = STAT_DEF;
    }
    else {
        // Speed Force
        if (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_SPEED_FORCE) && gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
        {
            secondaryAtkStatToUse = STAT_SPEED;
        }
        // Speed Force
        if (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_SPECIAL_SPEED_FORCE) && IS_MOVE_SPECIAL(move))
        {
            secondaryAtkStatToUse = STAT_SPEED;
        }
        // Power Core
        else if (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_POWER_CORE))
        {
            secondaryAtkStatToUse = IS_MOVE_PHYSICAL(move) ? STAT_DEF : STAT_SPDEF;
        }
        else if (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_JUGGERNAUT) && gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
        {
            secondaryAtkStatToUse = STAT_DEF;
        }

	    // Equinox
        if (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_EQUINOX))
        {
            u32 atk = CalculateStat(battlerAtk, STAT_ATK, secondaryAtkStatToUse, move, TRUE, isCrit, isUnaware, FALSE);
            u32 spAtk = CalculateStat(battlerAtk, STAT_SPATK, secondaryAtkStatToUse, move, TRUE, isCrit, isUnaware, FALSE);
            atkStatToUse = atk > spAtk ? STAT_ATK : STAT_SPATK;
        }
        // Ancient Idol
        else if (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_ANCIENT_IDOL))
        {
            atkStatToUse = IS_MOVE_PHYSICAL(move) ? STAT_DEF : STAT_SPDEF;
        }
        else if (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_MOMENTUM) && gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
        {
            atkStatToUse = STAT_SPEED;
        }
        else if (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_MOMENTUM_PLUS) && !(gBattleMoves[move].flags & FLAG_MAKES_CONTACT))
        {
            atkStatToUse = STAT_SPEED;
        }
        else if (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_MIND_CRUSH) && gBattleMoves[move].flags & FLAG_STRONG_JAW_BOOST)
        {
            atkStatToUse = STAT_SPATK;
        }
        else
        {
            atkStatToUse = IS_MOVE_PHYSICAL(move) ? STAT_ATK : STAT_SPATK;
        }
    }

    atkStat = CalculateStat(statBattler, atkStatToUse, secondaryAtkStatToUse, move, TRUE, isCrit, isUnaware, FALSE);

    // apply attack stat modifiers
    modifier = UQ_4_12(1.0);

    // attacker's abilities
    switch (GetBattlerAbility(battlerAtk))
    {
    case ABILITY_FLASH_FIRE:
        if (moveType == TYPE_FIRE && gBattleResources->flags->flags[battlerAtk] & RESOURCE_FLAG_FLASH_FIRE)
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_SWARM:
        if (moveType == TYPE_BUG)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.5));
            else
                MulModifier(&modifier, UQ_4_12(1.2));
        }
        break;
    case ABILITY_TORRENT:
        if (moveType == TYPE_WATER)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.5));
            else
                MulModifier(&modifier, UQ_4_12(1.2));
        }
        break;
    case ABILITY_BLAZE:
        if (moveType == TYPE_FIRE)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.5));
            else
                MulModifier(&modifier, UQ_4_12(1.2));
        }
        break;
    case ABILITY_OVERGROW:
        if (moveType == TYPE_GRASS)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.5));
            else
                MulModifier(&modifier, UQ_4_12(1.2));
        }
        break;
    case ABILITY_VENGEANCE:
        if (moveType == TYPE_GHOST)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.5));
            else
                MulModifier(&modifier, UQ_4_12(1.2));
        }
        break;
    case ABILITY_PURGATORY:
        if (moveType == TYPE_GHOST)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.8));
            else
                MulModifier(&modifier, UQ_4_12(1.3));
        }
        break;
    case ABILITY_PLASMA_LAMP:
        if (moveType == TYPE_FIRE || moveType == TYPE_ELECTRIC){
            MulModifier(&modifier, UQ_4_12(1.2));
        }   
        break;
	case ABILITY_SHORT_CIRCUIT:
        if (moveType == TYPE_ELECTRIC)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.5));
            else
                MulModifier(&modifier, UQ_4_12(1.2));
        }
        break;
    case ABILITY_HELLBLAZE:
        if (moveType == TYPE_FIRE)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.8));
            else
                MulModifier(&modifier, UQ_4_12(1.3));
        }
        break;
    case ABILITY_RIPTIDE:
        if (moveType == TYPE_WATER)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.8));
            else
                MulModifier(&modifier, UQ_4_12(1.3));
        }
        break;
    case ABILITY_FOREST_RAGE:
        if (moveType == TYPE_GRASS)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.8));
            else
                MulModifier(&modifier, UQ_4_12(1.3));
        }
        break;
	case ABILITY_FLOCK:
        if (moveType == TYPE_FLYING)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.5));
            else
                MulModifier(&modifier, UQ_4_12(1.2));
        }
        break;
	case ABILITY_ANTARCTIC_BIRD:
        if (moveType == TYPE_FLYING || moveType == TYPE_ICE)
        {
            MulModifier(&modifier, UQ_4_12(1.3));
        }
        break;
	case ABILITY_AMPHIBIOUS:
        if (moveType == TYPE_WATER)
        {
            MulModifier(&modifier, UQ_4_12(1.5));
        }
        break;
	case ABILITY_ELECTROCYTES:
        if (moveType == TYPE_ELECTRIC)
        {
            MulModifier(&modifier, UQ_4_12(1.25));
        }
        break;
    case ABILITY_NOCTURNAL:
        if (moveType == TYPE_DARK)
        {
            MulModifier(&modifier, UQ_4_12(1.25));
        }
        break;
	case ABILITY_EARTHBOUND:
        if (moveType == TYPE_GROUND)
        {
            MulModifier(&modifier, UQ_4_12(1.25));
        }
        break;
    case ABILITY_DUNE_TERROR:
        if (moveType == TYPE_GROUND)
        {
            MulModifier(&modifier, UQ_4_12(1.2));
        }
        break;
	case ABILITY_ILLUSION:
        if (gBattleStruct->illusion[battlerAtk].on && !gBattleStruct->illusion[battlerAtk].broken)
        {
            MulModifier(&modifier, UQ_4_12(1.3));
        }
        break;
	case ABILITY_LEVITATE:
        if (moveType == TYPE_FLYING)
        {
            MulModifier(&modifier, UQ_4_12(1.25));
        }
        break;
		
	case ABILITY_PSYCHIC_MIND:
        if (moveType == TYPE_PSYCHIC)
        {
            MulModifier(&modifier, UQ_4_12(1.25));
        }
        break;
    case ABILITY_FOSSILIZED:
        if (moveType == TYPE_ROCK)
        {
            MulModifier(&modifier, UQ_4_12(1.2));
        }
        break;
    case ABILITY_RAW_WOOD:
        if (moveType == TYPE_GRASS)
        {
            MulModifier(&modifier, UQ_4_12(1.2));
        }
        break;
    case ABILITY_PLUS:
    case ABILITY_MINUS:
        if (IsBattlerAlive(BATTLE_PARTNER(battlerAtk)))
        {
            u32 partnerAbility = GetBattlerAbility(BATTLE_PARTNER(battlerAtk));
            if (partnerAbility == ABILITY_PLUS || partnerAbility == ABILITY_MINUS)
                MulModifier(&modifier, UQ_4_12(2.0));
        }
        break;
    case ABILITY_FLOWER_GIFT:
        if (gBattleMons[battlerAtk].species == SPECIES_CHERRIM && IsBattlerWeatherAffected(battlerAtk, WEATHER_SUN_ANY) && IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_STAKEOUT:
        if (gDisableStructs[battlerDef].isFirstTurn == 2) // just switched in
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case ABILITY_WHITEOUT: // Boosts damage of Ice-type moves in hail
        if (moveType == TYPE_ICE && WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_HAIL_ANY)
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case ABILITY_GUTS:
        if (gBattleMons[battlerAtk].status1 & STATUS1_ANY && IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
	case ABILITY_SEAWEED:
		if (moveType == TYPE_GRASS && IS_BATTLER_OF_TYPE(battlerDef, TYPE_FIRE))
        {
            MulModifier(&modifier, UQ_4_12(2.0));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_SEAWEED);
        }
    }
	
	//Innates

	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_LETHARGY)){
        if(gDisableStructs[battlerAtk].slowStartTimer == 0 || gDisableStructs[battlerAtk].slowStartTimer == 1)
            MulModifier(&modifier, UQ_4_12(0.2));
        else if(gDisableStructs[battlerAtk].slowStartTimer == 2)
            MulModifier(&modifier, UQ_4_12(0.4));
        else if(gDisableStructs[battlerAtk].slowStartTimer == 3)
            MulModifier(&modifier, UQ_4_12(0.6));
        else if(gDisableStructs[battlerAtk].slowStartTimer == 4)
            MulModifier(&modifier, UQ_4_12(0.8));
    }

    //Infatuation
    if ((gBattleMons[battlerAtk].status2 & STATUS2_INFATUATION) && (gBattleMons[battlerAtk].status2 & STATUS2_INFATUATED_WITH(battlerDef)))   
        MulModifier(&modifier, UQ_4_12(0.5));
	
	// Plus & Minus
	if(BattlerHasInnate(BATTLE_PARTNER(battlerAtk), ABILITY_PLUS)
	|| BattlerHasInnate(BATTLE_PARTNER(battlerAtk), ABILITY_MINUS)){
        {
            u32 partnerAbility = GetBattlerAbility(BATTLE_PARTNER(battlerAtk));
            if (partnerAbility == ABILITY_PLUS 
			|| partnerAbility == ABILITY_MINUS 
			|| BattlerHasInnate(BATTLE_PARTNER(battlerAtk), ABILITY_PLUS)
			|| BattlerHasInnate(BATTLE_PARTNER(battlerAtk), ABILITY_MINUS)
			)
                MulModifier(&modifier, UQ_4_12(2.0));
        }
	}

    if (BATTLER_HAS_ABILITY(battlerDef, ABILITY_PURIFYING_SALT) && moveType == TYPE_GHOST) {
        MulModifier(&modifier, UQ_4_12(0.5));
    }
	
	// Stakeout
	if(BattlerHasInnate(battlerAtk, ABILITY_STAKEOUT)){
        if (gDisableStructs[battlerDef].isFirstTurn == 2) // just switched in
            MulModifier(&modifier, UQ_4_12(2.0));
    }
	
	// Whiteout
	if(BattlerHasInnate(battlerAtk, ABILITY_WHITEOUT)){
        if (moveType == TYPE_ICE && WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_HAIL_ANY)
            MulModifier(&modifier, UQ_4_12(1.5));
    }
	
	// Guts
	if(BattlerHasInnate(battlerAtk, ABILITY_GUTS)){
        if (gBattleMons[battlerAtk].status1 & STATUS1_ANY && IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, UQ_4_12(1.5));
    }
	
	// Guts
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_DETERMINATION)){
        if (gBattleMons[battlerAtk].status1 & STATUS1_ANY && IS_MOVE_SPECIAL(move))
            MulModifier(&modifier, UQ_4_12(1.5));
    }
	
	//Illusion
	if(BattlerHasInnate(battlerAtk, ABILITY_ILLUSION)){
		if (gBattleStruct->illusion[battlerAtk].on && !gBattleStruct->illusion[battlerAtk].broken)
        {
            MulModifier(&modifier, UQ_4_12(1.3));
        }
	}
	
	//Seaweed
	if(BattlerHasInnate(battlerAtk, ABILITY_SEAWEED)){
		if (moveType == TYPE_GRASS && IS_BATTLER_OF_TYPE(battlerDef, TYPE_FIRE))
        {
            MulModifier(&modifier, UQ_4_12(2.0));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_SEAWEED);
        }
	}

    // target's abilities
    switch (GetBattlerAbility(battlerDef))
    {
    case ABILITY_THICK_FAT:
        if (moveType == TYPE_FIRE || moveType == TYPE_ICE)
        {
            MulModifier(&modifier, UQ_4_12(0.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_THICK_FAT);
        }
        break;
    case ABILITY_NOCTURNAL:
        if (moveType == TYPE_DARK || moveType == TYPE_FAIRY)
        {
            MulModifier(&modifier, UQ_4_12(0.75));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_NOCTURNAL);
        }
        break;
	case ABILITY_MAGMA_ARMOR:
        if (moveType == TYPE_WATER || moveType == TYPE_ICE)
        {
            MulModifier(&modifier, UQ_4_12(0.7));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_MAGMA_ARMOR);
        }
        break;
	case ABILITY_OVERCOAT:
        if (IS_MOVE_SPECIAL(move))
            MulModifier(&modifier, UQ_4_12(0.8));
        break;
    case ABILITY_ICE_SCALES:
        if (IS_MOVE_SPECIAL(move))
            MulModifier(&modifier, UQ_4_12(0.5));
        break;
	case ABILITY_RAW_WOOD:
        if (moveType == TYPE_GRASS)
        {
            MulModifier(&modifier, UQ_4_12(0.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_RAW_WOOD);
        }
        break;
	case ABILITY_SEAWEED:
        if (moveType == TYPE_FIRE && IS_BATTLER_OF_TYPE(battlerDef, TYPE_GRASS))
        {
            MulModifier(&modifier, UQ_4_12(0.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_SEAWEED);
        }
        break;
    case ABILITY_WATER_COMPACTION:
        if (moveType == TYPE_WATER)
        {
            MulModifier(&modifier, UQ_4_12(0.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_WATER_COMPACTION);
        }
        break;
    }
	
	// Target's Innates
	// Thick Fat
	if(BattlerHasInnate(battlerDef, ABILITY_THICK_FAT)){
        if (moveType == TYPE_FIRE || moveType == TYPE_ICE)
        {
            MulModifier(&modifier, UQ_4_12(0.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_THICK_FAT);
        }
    }

    // Nocturnal
	if(BattlerHasInnate(battlerDef, ABILITY_NOCTURNAL)){
        if (moveType == TYPE_DARK || moveType == TYPE_FAIRY)
        {
            MulModifier(&modifier, UQ_4_12(0.75));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_NOCTURNAL);
        }
    }
	
	//Magma Armor
	if(BattlerHasInnate(battlerDef, ABILITY_MAGMA_ARMOR)){
		if (moveType == TYPE_WATER || moveType == TYPE_ICE)
        {
            MulModifier(&modifier, UQ_4_12(0.7));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_MAGMA_ARMOR);
        }
	}
	
	//Raw Wood
	if(BattlerHasInnate(battlerDef, ABILITY_RAW_WOOD)){
        if (moveType == TYPE_GRASS)
        {
            MulModifier(&modifier, UQ_4_12(0.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_RAW_WOOD);
        }
    }
	
	//Seaweed
	if(BattlerHasInnate(battlerDef, ABILITY_SEAWEED)){
        if (moveType == TYPE_FIRE && IS_BATTLER_OF_TYPE(battlerDef, TYPE_GRASS))
        {
            MulModifier(&modifier, UQ_4_12(0.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_SEAWEED);
        }
    }
	
	//Overcoat
	if(BattlerHasInnate(battlerDef, ABILITY_OVERCOAT)){
		if (IS_MOVE_SPECIAL(move))
            MulModifier(&modifier, UQ_4_12(0.8));
	}
	
	//Water Compaction
	if(BattlerHasInnate(battlerDef, ABILITY_WATER_COMPACTION)){
        if (moveType == TYPE_WATER)
        {
            MulModifier(&modifier, UQ_4_12(0.5));
            if (updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_WATER_COMPACTION);
        }
	}

    // ally's abilities
    if (IsBattlerAlive(BATTLE_PARTNER(battlerAtk)))
    {
        switch (GetBattlerAbility(BATTLE_PARTNER(battlerAtk)))
        {
        case ABILITY_FLOWER_GIFT:
            if (gBattleMons[BATTLE_PARTNER(battlerAtk)].species == SPECIES_CHERRIM && IsBattlerWeatherAffected(BATTLE_PARTNER(battlerAtk), WEATHER_SUN_ANY) && IS_MOVE_PHYSICAL(move))
                MulModifier(&modifier, UQ_4_12(1.5));
            break;
        }
    }

    // attacker's hold effect
    switch (GetBattlerHoldEffect(battlerAtk, TRUE))
    {
    case HOLD_EFFECT_THICK_CLUB:
        if ((GET_BASE_SPECIES_ID(gBattleMons[battlerAtk].species) == SPECIES_CUBONE
         || GET_BASE_SPECIES_ID(gBattleMons[battlerAtk].species) == SPECIES_MAROWAK)
         && IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_DEEP_SEA_TOOTH:
        if (gBattleMons[battlerAtk].species == SPECIES_CLAMPERL && IS_MOVE_SPECIAL(move))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_LIGHT_BALL:
        if (GET_BASE_SPECIES_ID(gBattleMons[battlerAtk].species) == SPECIES_PIKACHU)
            MulModifier(&modifier, UQ_4_12(2.0));
        if (GET_BASE_SPECIES_ID(gBattleMons[battlerAtk].species) == SPECIES_RAICHU)
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case HOLD_EFFECT_LEEK:
        if (GET_BASE_SPECIES_ID(gBattleMons[battlerAtk].species) == SPECIES_FARFETCHD
            && IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case HOLD_EFFECT_CHOICE_BAND:
        if (IS_MOVE_PHYSICAL(move))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case HOLD_EFFECT_CHOICE_SPECS:
        if (IS_MOVE_SPECIAL(move))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    }
	
	// Innates
	// Antarctic Bird
	if(BattlerHasInnate(battlerAtk, ABILITY_ANTARCTIC_BIRD)){
		if (moveType == TYPE_FLYING || moveType == TYPE_ICE)
        {
            MulModifier(&modifier, UQ_4_12(1.3));
        }
	}
	// Amphibious
	if(BattlerHasInnate(battlerAtk, ABILITY_AMPHIBIOUS)){
		if (moveType == TYPE_WATER)
        {
            MulModifier(&modifier, UQ_4_12(1.5));
        }
	}
	// Steelworker
	if(BattlerHasInnate(battlerAtk, ABILITY_STEELWORKER)){
		if (moveType == TYPE_STEEL)
        {
            MulModifier(&modifier, UQ_4_12(1.3));
        }
	}
	// Electrocytes
	if(BattlerHasInnate(battlerAtk, ABILITY_ELECTROCYTES)){
		if (moveType == TYPE_ELECTRIC)
        {
            MulModifier(&modifier, UQ_4_12(1.25));
        }
	}
    // Nocturnal
	if(BattlerHasInnate(battlerAtk, ABILITY_NOCTURNAL)){
		if (moveType == TYPE_DARK)
        {
            MulModifier(&modifier, UQ_4_12(1.25));
        }
	}
	// Earthbound
	if(BattlerHasInnate(battlerAtk, ABILITY_EARTHBOUND)){
		if (moveType == TYPE_GROUND)
        {
            MulModifier(&modifier, UQ_4_12(1.25));
        }
	}
    // Dune Terror
	if(BattlerHasInnate(battlerAtk, ABILITY_DUNE_TERROR)){
		if (moveType == TYPE_GROUND)
        {
            MulModifier(&modifier, UQ_4_12(1.2));
        }
	}
	// Levitate
	if(BattlerHasInnate(battlerAtk, ABILITY_LEVITATE)){
		if (moveType == TYPE_FLYING)
        {
            MulModifier(&modifier, UQ_4_12(1.5));
        }
	}
	// Psychic Mind
	if(BattlerHasInnate(battlerAtk, ABILITY_PSYCHIC_MIND)){
		if (moveType == TYPE_PSYCHIC)
        {
            MulModifier(&modifier, UQ_4_12(1.25));
        }
	}
    // Fossilized
	if(BattlerHasInnate(battlerAtk, ABILITY_FOSSILIZED)){
		if (moveType == TYPE_ROCK)
        {
            MulModifier(&modifier, UQ_4_12(1.2));
        }
	}
    // Raw Wood
	if(BattlerHasInnate(battlerAtk, ABILITY_RAW_WOOD)){
		if (moveType == TYPE_GRASS)
        {
            MulModifier(&modifier, UQ_4_12(1.2));
        }
	}
	// Swarm
	if(BattlerHasInnate(battlerAtk, ABILITY_SWARM)){
		if (moveType == TYPE_BUG)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.5));
            else
                MulModifier(&modifier, UQ_4_12(1.2));
		}
	}
	// Flash Fire
	if(BattlerHasInnate(battlerAtk, ABILITY_FLASH_FIRE)){
		if (moveType == TYPE_FIRE && gBattleResources->flags->flags[battlerAtk] & RESOURCE_FLAG_FLASH_FIRE)
            MulModifier(&modifier, UQ_4_12(1.5));
	}
	// Torrent
	if(BattlerHasInnate(battlerAtk, ABILITY_TORRENT)){
		if (moveType == TYPE_WATER)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.5));
            else
                MulModifier(&modifier, UQ_4_12(1.2));
        }
	}
	// Blaze
	if(BattlerHasInnate(battlerAtk, ABILITY_BLAZE)){
		if (moveType == TYPE_FIRE)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.5));
            else
                MulModifier(&modifier, UQ_4_12(1.2));
        }
	}
	// Overgrow 
	if(BattlerHasInnate(battlerAtk, ABILITY_OVERGROW)){
		if (moveType == TYPE_GRASS)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.5));
            else
                MulModifier(&modifier, UQ_4_12(1.2));
        }
	}
	// Fighter 
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_FIGHTER)){
		if (moveType == TYPE_FIGHTING)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.5));
            else
                MulModifier(&modifier, UQ_4_12(1.2));
        }
	}
	// Rocky Payload
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_ROCKY_PAYLOAD)){
		if (moveType == TYPE_ROCK)
        {
            MulModifier(&modifier, UQ_4_12(1.5));
        }
	}
	// Rocky Payload
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_COMBUSTION)){
		if (moveType == TYPE_FIRE)
        {
            MulModifier(&modifier, UQ_4_12(1.5));
        }
	}
	// Vengeance
	if(BattlerHasInnate(battlerAtk, ABILITY_VENGEANCE)){
		if (moveType == TYPE_GHOST)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.5));
            else
                MulModifier(&modifier, UQ_4_12(1.2));
        }
	}
	// Vengeance
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_VENGEANCE)){
		if (moveType == TYPE_GHOST)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.5));
            else
                MulModifier(&modifier, UQ_4_12(1.2));
        }
	}
    // Purgatory
	if(BattlerHasInnate(battlerAtk, ABILITY_PURGATORY)){
		if (moveType == TYPE_GHOST)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.8));
            else
                MulModifier(&modifier, UQ_4_12(1.3));
        }
	}
    // Plasma Lamp
	if(BattlerHasInnate(battlerAtk, ABILITY_PLASMA_LAMP)){
		if(moveType == TYPE_FIRE || moveType == TYPE_ELECTRIC) {
            MulModifier(&modifier, UQ_4_12(1.2));
        }        
	}
	// Short Circuit
	if(BattlerHasInnate(battlerAtk, ABILITY_SHORT_CIRCUIT)){
		if (moveType == TYPE_ELECTRIC)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.5));
            else
                MulModifier(&modifier, UQ_4_12(1.2));
        }
	}
    // Hellblaze
    if(BattlerHasInnate(battlerAtk, ABILITY_HELLBLAZE)){
        if (moveType == TYPE_FIRE)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.8));
            else
                MulModifier(&modifier, UQ_4_12(1.3));
        }
    }
    // Riptide
    if(BattlerHasInnate(battlerAtk, ABILITY_RIPTIDE)){
        if (moveType == TYPE_WATER)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.8));
            else
                MulModifier(&modifier, UQ_4_12(1.3));
        }
    }
    // Forest Rage
    if(BattlerHasInnate(battlerAtk, ABILITY_FOREST_RAGE)){
        if (moveType == TYPE_GRASS)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.8));
            else
                MulModifier(&modifier, UQ_4_12(1.3));
        }
    }
	// Flock
	if(BattlerHasInnate(battlerAtk, ABILITY_FLOCK)){
		if (moveType == TYPE_FLYING)
        {
            if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
                MulModifier(&modifier, UQ_4_12(1.5));
            else
                MulModifier(&modifier, UQ_4_12(1.2));
		}
	}
	// Electric Burst
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_ELECTRIC_BURST)){
        if (moveType == TYPE_ELECTRIC && gBattleMons[battlerAtk].hp > 1)
        {
            MulModifier(&modifier, UQ_4_12(1.35));
        }
	}
    // Infernal Rage
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_INFERNAL_RAGE)){
		if (moveType == TYPE_FIRE && gBattleMons[battlerAtk].hp > 1)
        {
            MulModifier(&modifier, UQ_4_12(1.35));
        }
	}
	
    return ApplyModifier(modifier, atkStat);
}

static bool32 CanEvolve(u32 species)
{
    u32 i;

    for (i = 0; i < EVOS_PER_MON; i++)
    {
        if (gEvolutionTable[species][i].method
         && gEvolutionTable[species][i].method != EVO_MEGA_EVOLUTION
         && gEvolutionTable[species][i].method != EVO_MOVE_MEGA_EVOLUTION
         && gEvolutionTable[species][i].method != EVO_PRIMAL_REVERSION)
            return TRUE;
    }
    return FALSE;
}

u8 CalculateBattlerLowestDefense(u8 battler){
    u8 defense = gBattleMons[battler].defense;
    u8 specialDefense = gBattleMons[battler].spDefense;

    if (defense < specialDefense)
        return STAT_DEF;
    else
        return STAT_SPDEF;
}

u8 CalculateBattlerHighestAttack(u8 battler){
    u8 attack = gBattleMons[battler].attack;
    u8 specialAttack = gBattleMons[battler].spAttack;

    if (attack > specialAttack)
        return STAT_ATK;
    else
        return STAT_SPATK;
}

static u32 CalcDefenseStat(u16 move, u8 battlerAtk, u8 battlerDef, u8 moveType, bool32 isCrit, bool32 updateFlags)
{
    u8 defStatToUse = 0;
    u32 defStat;
    u8 noPositiveStatStages = isCrit || (gBattleMons[battlerDef].status2 & STATUS2_WRAPPED && BATTLER_HAS_ABILITY(battlerAtk, ABILITY_GRIP_PINCER));
    u8 isUnaware = BATTLER_HAS_ABILITY(battlerAtk, ABILITY_UNAWARE);
    u16 modifier;

    if ((gBattleMoves[move].effect == EFFECT_PSYSHOCK || IS_MOVE_PHYSICAL(move) || (gBattleMoves[move].flags2 & FLAG_HITS_PHYSICAL_DEF)) && !(gBattleMoves[move].flags2 & FLAG_HITS_SPDEF)) // uses defense stat instead of sp.def
    {
        defStatToUse = STAT_DEF;
    }
    else // is special
    {
        defStatToUse = STAT_SPDEF;
    }

    if (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_POWER_FISTS) && IS_IRON_FIST(battlerAtk, move))
    {
        defStatToUse = STAT_SPDEF;
    }

    if (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_MYTHICAL_ARROWS) && gBattleMoves[move].flags2 & FLAG_ARROW_BASED)
    {
        defStatToUse = STAT_SPDEF;
    }

    if (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_MYSTIC_BLADES) && gBattleMoves[move].flags & FLAG_KEEN_EDGE_BOOST) 
    {
        defStatToUse = STAT_SPDEF;
    }

    if (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_PONY_POWER) && gBattleMoves[move].flags & FLAG_KEEN_EDGE_BOOST) 
    {
        defStatToUse = STAT_SPDEF;
    }

    if ((gBattleMons[battlerAtk].ability == ABILITY_ROUNDHOUSE || 
        BattlerHasInnate(battlerAtk, ABILITY_ROUNDHOUSE)) && 
        gBattleMoves[move].flags & FLAG_STRIKER_BOOST) 
    {
        u32 def = CalculateStat(battlerDef, STAT_DEF, 0, move, FALSE, noPositiveStatStages, isUnaware, FALSE);
        u32 spDef = CalculateStat(battlerDef, STAT_SPDEF, 0, move, FALSE, noPositiveStatStages, isUnaware, FALSE);
        defStat = min(def, spDef);
        defStatToUse = defStat == def ? STAT_DEF : STAT_SPDEF;
    }
    else {
        defStat = CalculateStat(battlerDef, defStatToUse, 0, move, FALSE, noPositiveStatStages, isUnaware, FALSE);
    }

    // apply defense stat modifiers
    modifier = UQ_4_12(1.0);
	
	// Punk Rock
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_PUNK_ROCK)){
        if (gBattleMoves[move].flags & FLAG_SOUND)
            MulModifier(&modifier, UQ_4_12(2.0));
    }
	// Punk Rock
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_PUNK_ROCK)){
        if (gBattleMoves[move].flags & FLAG_SOUND)
            MulModifier(&modifier, UQ_4_12(2.0));
    }

    // target's hold effects
    switch (GetBattlerHoldEffect(battlerDef, TRUE))
    {
    case HOLD_EFFECT_DEEP_SEA_SCALE:
        if (gBattleMons[battlerDef].species == SPECIES_CLAMPERL && defStatToUse == STAT_SPDEF)
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_METAL_POWDER:
        if (gBattleMons[battlerDef].species == SPECIES_DITTO && defStatToUse == STAT_DEF && !(gBattleMons[battlerDef].status2 & STATUS2_TRANSFORMED))
            MulModifier(&modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_EVIOLITE:
        if (CanEvolve(gBattleMons[battlerDef].species))
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
    case HOLD_EFFECT_ASSAULT_VEST:
        if (defStatToUse == STAT_SPDEF)
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
#if B_SOUL_DEW_BOOST <= GEN_6
    case HOLD_EFFECT_SOUL_DEW:
        if ((gBattleMons[battlerDef].species == SPECIES_LATIAS || gBattleMons[battlerDef].species == SPECIES_LATIOS)
         && !(gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
         && defStatToUse == STAT_SPDEF)
            MulModifier(&modifier, UQ_4_12(1.5));
        break;
#endif
    }

    return ApplyModifier(modifier, defStat);
}

u32 CalcFinalDmg(u32 dmg, u16 move, u8 battlerAtk, u8 battlerDef, u8 moveType, u16 typeEffectivenessModifier, bool32 isCrit, bool32 updateFlags)
{
    u32 percentBoost;
    u32 abilityAtk = GetBattlerAbility(battlerAtk);
    u32 abilityDef = GetBattlerAbility(battlerDef);
    u32 defSide = GET_BATTLER_SIDE(battlerDef);
    u16 finalModifier = UQ_4_12(1.0);
    u16 itemDef = gBattleMons[battlerDef].item;

    // check multiple targets in double battle
    if (GetMoveTargetCount(move, battlerAtk, battlerDef) >= 2)
        MulModifier(&finalModifier, UQ_4_12(0.75));

    // take type effectiveness
    MulModifier(&finalModifier, typeEffectivenessModifier);

    // check crit
    if (isCrit)
    {
        if (gBattleMoves[move].effect == EFFECT_MISC_HIT && gBattleMoves[move].argument == MISC_EFFECT_INCREASED_CRIT_DAMAGE)
        {
            dmg = ApplyModifier(UQ_4_12(2.0), dmg);
        }
        else
        {
            dmg = ApplyModifier(UQ_4_12(1.5), dmg);
        }
    }

    #define CHECK_WEATHER_DOUBLE_BOOST(boost, drop) (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_WEATHER_DOUBLE_BOOST) ? UQ_4_12(boost) : UQ_4_12(drop))

    // check sunny/rain weather
    if (IsBattlerWeatherAffected(battlerAtk, WEATHER_RAIN_PERMANENT))
    {
        if (gBattleMoves[move].effect == EFFECT_WEATHER_BOOST)
            dmg = ApplyModifier(UQ_4_12(1.2), dmg);
        else if (moveType == TYPE_FIRE)
            dmg = ApplyModifier(CHECK_WEATHER_DOUBLE_BOOST(1.2, 0.5), dmg);
        else if (moveType == TYPE_WATER)
            dmg = ApplyModifier(UQ_4_12(1.2), dmg);
    }
    else if (IsBattlerWeatherAffected(battlerAtk, WEATHER_RAIN_TEMPORARY))
    {
        if (gBattleMoves[move].effect == EFFECT_WEATHER_BOOST)
            dmg = ApplyModifier(UQ_4_12(1.5), dmg);
        else if (moveType == TYPE_FIRE)
            dmg = ApplyModifier(CHECK_WEATHER_DOUBLE_BOOST(1.5, 0.5), dmg);
        else if (moveType == TYPE_WATER)
            dmg = ApplyModifier(UQ_4_12(1.5), dmg);
    }
    else if (IsBattlerWeatherAffected(battlerAtk, WEATHER_SUN_PERMANENT))
    {
        if (gBattleMoves[move].effect == EFFECT_WEATHER_BOOST)
            dmg = ApplyModifier(UQ_4_12(1.2), dmg);
        else if (moveType == TYPE_FIRE)
            dmg = ApplyModifier(UQ_4_12(1.2), dmg);
        else if (moveType == TYPE_WATER && !BATTLER_HAS_ABILITY(battlerAtk, ABILITY_NIKA))
            dmg = ApplyModifier(CHECK_WEATHER_DOUBLE_BOOST(1.2, 0.5), dmg);
    }
    else if (IsBattlerWeatherAffected(battlerAtk, WEATHER_SUN_TEMPORARY))
    {
        if (gBattleMoves[move].effect == EFFECT_WEATHER_BOOST)
            dmg = ApplyModifier(UQ_4_12(1.5), dmg);
        else if (moveType == TYPE_FIRE)
            dmg = ApplyModifier(UQ_4_12(1.5), dmg);
        else if (moveType == TYPE_WATER && !BATTLER_HAS_ABILITY(battlerAtk, ABILITY_NIKA))
            dmg = ApplyModifier(CHECK_WEATHER_DOUBLE_BOOST(1.5, 0.5), dmg);
    }

    #undef CHECK_WEATHER_DOUBLE_BOOST

    // check stab
    if ((IS_BATTLER_OF_TYPE(battlerAtk, moveType) && move != MOVE_STRUGGLE) || 
	     BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_MYSTIC_POWER, abilityAtk) ||
	     BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_ARCANE_FORCE, abilityAtk) ||
         (abilityAtk == ABILITY_LUNAR_ECLIPSE && (moveType == TYPE_FAIRY || moveType == TYPE_DARK)) || (BattlerHasInnate(battlerAtk, ABILITY_LUNAR_ECLIPSE) && (moveType == TYPE_FAIRY || moveType == TYPE_DARK)) ||
         (abilityAtk == ABILITY_MOON_SPIRIT && (moveType == TYPE_FAIRY || moveType == TYPE_DARK)) || (BattlerHasInnate(battlerAtk, ABILITY_MOON_SPIRIT) && (moveType == TYPE_FAIRY || moveType == TYPE_DARK)) ||
         (abilityAtk == ABILITY_SOLAR_FLARE && moveType == TYPE_FIRE) || (BattlerHasInnate(battlerAtk, ABILITY_SOLAR_FLARE) && moveType == TYPE_FIRE) ||
		 (abilityAtk == ABILITY_AURORA_BOREALIS && moveType == TYPE_ICE) || (BattlerHasInnate(battlerAtk, ABILITY_AURORA_BOREALIS) && moveType == TYPE_ICE))
    {
        if (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_ADAPTABILITY, abilityAtk))
            MulModifier(&finalModifier, UQ_4_12(2.0));
        else
            MulModifier(&finalModifier, UQ_4_12(1.5));
    }

    // reflect, light screen, aurora veil
    if (((gSideStatuses[defSide] & SIDE_STATUS_REFLECT && IS_MOVE_PHYSICAL(move))
            || (gSideStatuses[defSide] & SIDE_STATUS_LIGHTSCREEN && IS_MOVE_SPECIAL(move))
            || (gSideStatuses[defSide] & SIDE_STATUS_AURORA_VEIL))
        && abilityAtk != ABILITY_INFILTRATOR
		&& !BattlerHasInnate(battlerAtk, ABILITY_INFILTRATOR)
        && abilityAtk != ABILITY_MARINE_APEX
		&& !BattlerHasInnate(battlerAtk, ABILITY_MARINE_APEX)
        && !(isCrit)
        && !gProtectStructs[gBattlerAttacker].confusionSelfDmg)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            MulModifier(&finalModifier, UQ_4_12(0.66));
        else
            MulModifier(&finalModifier, UQ_4_12(0.5));
    }
    
    switch (gSpecialStatuses[gBattlerAttacker].parentalBondTrigger) {
        case ABILITY_HYPER_AGGRESSIVE:
        case ABILITY_PARENTAL_BOND:
            if (gSpecialStatuses[gBattlerAttacker].parentalBondOn == 1)
                MulModifier(&finalModifier, UQ_4_12(0.25));
            break;
        case ABILITY_MULTI_HEADED:
            if(gBaseStats[gBattleMons[gBattlerAttacker].species].flags & F_TWO_HEADED){
                if (gSpecialStatuses[gBattlerAttacker].parentalBondOn == 1)
                    MulModifier(&finalModifier, UQ_4_12(0.25));
            } else {
                if(gSpecialStatuses[gBattlerAttacker].parentalBondOn == 2)
                    MulModifier(&finalModifier, UQ_4_12(0.2));
                else if(gSpecialStatuses[gBattlerAttacker].parentalBondOn == 1)
                    MulModifier(&finalModifier, UQ_4_12(0.15));
            }
            break;
        case ABILITY_PRIMAL_MAW:
        case ABILITY_DEVOURER:
        case ABILITY_RAGING_BOXER:
            if (gSpecialStatuses[gBattlerAttacker].parentalBondOn == 1)
                MulModifier(&finalModifier, UQ_4_12(0.5));
            break;
        case ABILITY_DUAL_WIELD:
        case ABILITY_RAGING_MOTH:
		    MulModifier(&finalModifier, UQ_4_12(0.75));
            break;
    }

    // attacker's abilities
    switch (abilityAtk)
    {
    case ABILITY_TINTED_LENS:
        if (typeEffectivenessModifier <= UQ_4_12(0.5))
            MulModifier(&finalModifier, UQ_4_12(2.0));
        break;
    case ABILITY_BONE_ZONE:
        if (typeEffectivenessModifier <= UQ_4_12(0.5) && (gBattleMoves[move].flags & FLAG_BONE_BASED))
            MulModifier(&finalModifier, UQ_4_12(2.0));
        break;
    case ABILITY_SNIPER:
        if (isCrit)
            MulModifier(&finalModifier, UQ_4_12(1.5));
        break;
    case ABILITY_NEUROFORCE:
        if (typeEffectivenessModifier >= UQ_4_12(2.0))
            MulModifier(&finalModifier, UQ_4_12(1.25));
        break;
	case ABILITY_FATAL_PRECISION:
        if (typeEffectivenessModifier >= UQ_4_12(2.0))
            MulModifier(&finalModifier, UQ_4_12(1.2));
        break;
    }
	
	
	// Innates
	// Sniper
	if(BattlerHasInnate(battlerAtk, ABILITY_SNIPER)){
        if (isCrit)
            MulModifier(&finalModifier, UQ_4_12(1.5));
    }
    
	// Neuroforce
	if(BattlerHasInnate(battlerAtk, ABILITY_NEUROFORCE)){
        if (typeEffectivenessModifier >= UQ_4_12(2.0))
            MulModifier(&finalModifier, UQ_4_12(1.25));
	}
    
	// Neuroforce
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_WINGED_KING)){
        if (typeEffectivenessModifier >= UQ_4_12(2.0))
            MulModifier(&finalModifier, UQ_4_12(1.25));
	}
    
	// Neuroforce
	if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_IRON_SERPENT)){
        if (typeEffectivenessModifier >= UQ_4_12(2.0))
            MulModifier(&finalModifier, UQ_4_12(1.25));
	}
    
	// Arcane Force
	if(BattlerHasInnate(battlerAtk, ABILITY_ARCANE_FORCE)){
        if (typeEffectivenessModifier >= UQ_4_12(2.0))
            MulModifier(&finalModifier, UQ_4_12(1.1));
	}
	
	// Fatal Precision
	if(BattlerHasInnate(battlerAtk, ABILITY_FATAL_PRECISION)){
		if (typeEffectivenessModifier >= UQ_4_12(2.0))
            MulModifier(&finalModifier, UQ_4_12(1.2));
    }
	// Tinted Lens
	if(BattlerHasInnate(battlerAtk, ABILITY_TINTED_LENS)){
		if (typeEffectivenessModifier <= UQ_4_12(0.5))
            MulModifier(&finalModifier, UQ_4_12(2.0));
    }
	
	// Bone Zone
	if(BattlerHasInnate(battlerAtk, ABILITY_BONE_ZONE)){
        if (typeEffectivenessModifier <= UQ_4_12(0.5) && (gBattleMoves[move].flags & FLAG_BONE_BASED))
            MulModifier(&finalModifier, UQ_4_12(2.0));
	}

    // target's abilities
    switch (abilityDef)
    {
    case ABILITY_MULTISCALE:
    case ABILITY_SHADOW_SHIELD:
        if (BATTLER_MAX_HP(battlerDef))
            MulModifier(&finalModifier, UQ_4_12(0.5));
        break;
    case ABILITY_FILTER:
    case ABILITY_SOLID_ROCK:
    case ABILITY_PRISM_ARMOR:
	case ABILITY_PERMAFROST:
        if (typeEffectivenessModifier >= UQ_4_12(2.0))
            MulModifier(&finalModifier, UQ_4_12(0.65));
        break;
	case ABILITY_PRIMAL_ARMOR:
        if (typeEffectivenessModifier >= UQ_4_12(2.0))
            MulModifier(&finalModifier, UQ_4_12(0.5));
        break;
    case ABILITY_ICE_SCALES:
        if (IS_MOVE_SPECIAL(move))
            MulModifier(&finalModifier, UQ_4_12(0.50));
        break;
    case ABILITY_PRISM_SCALES:
        if (IS_MOVE_SPECIAL(move))
            MulModifier(&finalModifier, UQ_4_12(0.70));
        break;
    case ABILITY_ARCTIC_FUR:
            MulModifier(&finalModifier, UQ_4_12(0.65));
        break;
    case ABILITY_PRISMATIC_FUR:
            MulModifier(&finalModifier, UQ_4_12(0.5));
        break;
    }
	
	
	// Innates
	
	// Permafrost
	if(BattlerHasInnate(battlerDef, ABILITY_PERMAFROST)){
		if (typeEffectivenessModifier >= UQ_4_12(2.0))
            MulModifier(&finalModifier, UQ_4_12(0.75));
    }
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_PERMAFROST_CLONE)){
		if (typeEffectivenessModifier >= UQ_4_12(2.0))
            MulModifier(&finalModifier, UQ_4_12(0.75));
    }
	// Prism Scales
	if(BattlerHasInnate(battlerDef, ABILITY_PRISM_SCALES)){
		if (IS_MOVE_SPECIAL(move))
            MulModifier(&finalModifier, UQ_4_12(0.70));
    }
    // Arctic Fur
	if(BattlerHasInnate(battlerDef, ABILITY_ARCTIC_FUR)){
            MulModifier(&finalModifier, UQ_4_12(0.65));
    }
    // Prismatic Fur
	if(BattlerHasInnate(battlerDef, ABILITY_PRISMATIC_FUR)){
            MulModifier(&finalModifier, UQ_4_12(0.5));
    }
	// Multiscale and Shadow Shield
	if(BattlerHasInnate(battlerDef, ABILITY_MULTISCALE) || 
	   BattlerHasInnate(battlerDef, ABILITY_SHADOW_SHIELD)){
		if (BATTLER_MAX_HP(battlerDef))
            MulModifier(&finalModifier, UQ_4_12(0.5));
    }
	// Filter, Solid Rock and Prism Armor
	if(BattlerHasInnate(battlerDef, ABILITY_FILTER)  ||
	BattlerHasInnate(battlerDef, ABILITY_SOLID_ROCK) ||
	BattlerHasInnate(battlerDef, ABILITY_PRISM_ARMOR)){
		if (typeEffectivenessModifier >= UQ_4_12(2.0))
            MulModifier(&finalModifier, UQ_4_12(0.65));
    }
	// Primal Armor
	if(BattlerHasInnate(battlerDef, ABILITY_PRIMAL_ARMOR)){
		if (typeEffectivenessModifier >= UQ_4_12(2.0))
            MulModifier(&finalModifier, UQ_4_12(0.5));
    }
	// Ice Scales
	if(BattlerHasInnate(battlerDef, ABILITY_ICE_SCALES)){
		if (IS_MOVE_SPECIAL(move))
            MulModifier(&finalModifier, UQ_4_12(0.50));
    }
	// Fur Coat
	if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_FUR_COAT)){
		if (IS_MOVE_PHYSICAL(move))
            MulModifier(&finalModifier, UQ_4_12(0.50));
    }
    // Sand Guard
    if (BATTLER_HAS_ABILITY(battlerDef, ABILITY_SAND_GUARD) 
        && gBattleWeather & B_WEATHER_SANDSTORM && WEATHER_HAS_EFFECT
        && IS_MOVE_SPECIAL(move))
            MulModifier(&finalModifier, UQ_4_12(0.50));
	
    // target's ally's abilities
    if (IsBattlerAlive(BATTLE_PARTNER(battlerDef)))
    {
        switch (GetBattlerAbility(BATTLE_PARTNER(battlerDef)))
        {
        case ABILITY_FRIEND_GUARD:
            MulModifier(&finalModifier, UQ_4_12(0.5)); // was 0.75
            break;
        }
    }

    // attacker's hold effect
    switch (GetBattlerHoldEffect(battlerAtk, TRUE))
    {
    case HOLD_EFFECT_METRONOME:
        percentBoost = min((gBattleStruct->sameMoveTurns[battlerAtk] * GetBattlerHoldEffectParam(battlerAtk)), 100);
        MulModifier(&finalModifier, UQ_4_12(1.0) + sPercentToModifier[percentBoost]);
        break;
    case HOLD_EFFECT_EXPERT_BELT:
        if (typeEffectivenessModifier >= UQ_4_12(2.0))
            MulModifier(&finalModifier, UQ_4_12(1.2));
        break;
    case HOLD_EFFECT_LIFE_ORB:
        MulModifier(&finalModifier, UQ_4_12(1.3));
        break;
    case HOLD_EFFECT_PUNCHING_GLOVE:
        if (IS_IRON_FIST(battlerAtk, move))
            MulModifier(&finalModifier, UQ_4_12(1.1));
        break;
    }

    // target's hold effect
    switch (GetBattlerHoldEffect(battlerDef, TRUE))
    {
    // berries reducing dmg
    case HOLD_EFFECT_RESIST_BERRY:
        if (moveType == GetBattlerHoldEffectParam(battlerDef)
            && (moveType == TYPE_NORMAL || typeEffectivenessModifier >= UQ_4_12(2.0))
            && !UnnerveOn(battlerDef, itemDef))
        {
            if (BATTLER_HAS_ABILITY(battlerDef, ABILITY_RIPEN))
                MulModifier(&finalModifier, UQ_4_12(0.25));
            else
                MulModifier(&finalModifier, UQ_4_12(0.5));
            if (updateFlags)
                gSpecialStatuses[battlerDef].berryReduced = TRUE;
        }
        break;
    }

    if (gProtectStructs[battlerDef].glaiveRush)
        MulModifier(&finalModifier, UQ_4_12(2.0));

    if (gBattleMoves[move].flags & FLAG_DMG_UNDERGROUND && gStatuses3[battlerDef] & STATUS3_UNDERGROUND)
        MulModifier(&finalModifier, UQ_4_12(2.0));
    if (gBattleMoves[move].flags & FLAG_DMG_UNDERWATER  && gStatuses3[battlerDef] & STATUS3_UNDERWATER)
        MulModifier(&finalModifier, UQ_4_12(2.0));
    if (gBattleMoves[move].flags & FLAG_DMG_2X_IN_AIR   && gStatuses3[battlerDef] & STATUS3_ON_AIR)
        MulModifier(&finalModifier, UQ_4_12(2.0));

    if (typeEffectivenessModifier >= UQ_4_12(2.0) && gBattleMoves[move].effect == EFFECT_MISC_HIT && gBattleMoves[move].argument == MISC_EFFECT_SUPEREFFECTIVE_BOOST)
    {
        MulModifier(&finalModifier, UQ_4_12(4.0/3.0));
    }

    dmg = ApplyModifier(finalModifier, dmg);
    if (dmg == 0)
        dmg = 1;

    return dmg;
}

s32 DoMoveDamageCalcInternal(u16 move, u8 battlerAtk, u8 battlerDef, u8 moveType, s32 fixedBasePower,
                            bool32 isCrit, bool32 updateFlags, u16 typeEffectivenessModifier)
{
    s32 dmg;

    // Don't calculate damage if the move has no effect on target.
    if (typeEffectivenessModifier == UQ_4_12(0))
        return -1;

    gBattleMovePower = CalcMoveBasePowerAfterModifiers(move, fixedBasePower, battlerAtk, battlerDef, moveType, updateFlags);

    // long dmg basic formula
    dmg = ((gBattleMons[battlerAtk].level * 2) / 5) + 2;
    dmg *= gBattleMovePower;
    dmg *= CalcAttackStat(move, battlerAtk, battlerDef, moveType, isCrit, updateFlags);
    dmg /= CalcDefenseStat(move, battlerAtk, battlerDef, moveType, isCrit, updateFlags);
    dmg = (dmg / 50) + 2;

    // Calculate final modifiers.
    dmg = CalcFinalDmg(dmg, move, battlerAtk, battlerDef, moveType, typeEffectivenessModifier, isCrit, updateFlags);

    return dmg;
}

static s32 DoMoveDamageCalc(u16 move, u8 battlerAtk, u8 battlerDef, u8* moveType, s32 fixedBasePower,
                            bool32 isCrit, bool32 randomFactor, bool32 updateFlags, u16* typeEffectivenessModifier)
{
    s32 dmg;
    *typeEffectivenessModifier = CalcTypeEffectivenessMultiplier(move, *moveType, battlerAtk, battlerDef, updateFlags);
    dmg = DoMoveDamageCalcInternal(move, battlerAtk, battlerDef, *moveType, fixedBasePower, isCrit, updateFlags, *typeEffectivenessModifier);

    if (gBattleMoves[move].type2 && gBattleMoves[move].type2 != *moveType && gBattleMoves[move].type2 != TYPE_MYSTERY)
    {
        u8 type2 = gBattleMoves[move].type2;
        u16 typeEffectivenessModifier2 = CalcTypeEffectivenessMultiplier(move, type2, battlerAtk, battlerDef, updateFlags);
        s32 dmg2 = DoMoveDamageCalcInternal(move, battlerAtk, battlerDef, type2, fixedBasePower, isCrit, updateFlags, typeEffectivenessModifier2);

        if (dmg2 > dmg)
        {
            *typeEffectivenessModifier = typeEffectivenessModifier2;
            dmg = dmg2;
            *moveType = type2;
        }
    }

    if (dmg < 0) return 0;

    // Add a random factor.
    if (randomFactor)
    {
        s32 roll = BATTLER_HAS_ABILITY(battlerDef, ABILITY_BAD_LUCK) ? 15 : Random() % 16;
        dmg *= 100 - roll;
        dmg /= 100;
    }

    if (dmg == 0)
        dmg = 1;

    return dmg;
}

s32 DoMoveDamageCalcBattleMenu(u16 move, u8 battlerAtk, u8 battlerDef, u8* moveType, bool32 isCrit, u8 randomFactor)
{
    u16 typeEffectivenessModifier;
    s32 dmg = DoMoveDamageCalc(move, battlerAtk, battlerDef, moveType, 0, isCrit, FALSE, FALSE, &typeEffectivenessModifier);

    if (BATTLER_HAS_ABILITY(battlerDef, ABILITY_BAD_LUCK)) randomFactor = 16;

    // Add a random factor.
    dmg *= 100 - randomFactor;
    dmg /= 100;

    if (dmg == 0)
        dmg = 1;

    return dmg;
}

s32 CalculateMoveDamage(u16 move, u8 battlerAtk, u8 battlerDef, u8* moveType, s32 fixedBasePower, bool32 isCrit, bool32 randomFactor, bool32 updateFlags)
{
    u16 typeEffectiveness;
    return DoMoveDamageCalc(move, battlerAtk, battlerDef, moveType, fixedBasePower, isCrit, randomFactor,
                            updateFlags, &typeEffectiveness);
}

// for AI - get move damage and effectiveness with one function call
s32 CalculateMoveDamageAndEffectiveness(u16 move, u8 battlerAtk, u8 battlerDef, u8* moveType, u16 *typeEffectivenessModifier)
{
    return DoMoveDamageCalc(move, battlerAtk, battlerDef, moveType, 0, FALSE, FALSE, FALSE, typeEffectivenessModifier);
}

void MulByTypeEffectiveness(u16 *modifier, u16 move, u8 moveType, u8 battlerDef, u8 defType, u8 battlerAtk, bool32 recordAbilities)
{
    u16 mod = GetTypeModifier(moveType, defType);

    if (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_NORMALIZE) && moveType == TYPE_NORMAL && mod != UQ_4_12(0.0))
    {
        mod = UQ_4_12(1.0);
    }
    else if (mod == UQ_4_12(0.0) && GetBattlerHoldEffect(battlerDef, TRUE) == HOLD_EFFECT_RING_TARGET)
    {
        mod = UQ_4_12(1.0);
        if (recordAbilities)
            RecordItemEffectBattle(battlerDef, HOLD_EFFECT_RING_TARGET);
    }
    else if ((moveType == TYPE_FIGHTING || moveType == TYPE_NORMAL) && defType == TYPE_GHOST && gBattleMons[battlerDef].status2 & STATUS2_FORESIGHT && mod == UQ_4_12(0.0))
    {
        mod = UQ_4_12(1.0);
    }
    else if ((moveType == TYPE_FIGHTING || moveType == TYPE_NORMAL) && defType == TYPE_GHOST && (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_SCRAPPY) || BATTLER_HAS_ABILITY(battlerAtk, ABILITY_MINDS_EYE)) && mod == UQ_4_12(0.0))
    {
        mod = UQ_4_12(1.0);
        if (recordAbilities)
            RecordAbilityBattle(battlerAtk, ABILITY_SCRAPPY);
    }
    else if (moveType == TYPE_GHOST && defType == TYPE_NORMAL && BATTLER_HAS_ABILITY(battlerAtk, ABILITY_PHANTOM_PAIN))
    {   
        mod = UQ_4_12(1.0);
        if (recordAbilities)
            RecordAbilityBattle(battlerAtk, ABILITY_PHANTOM_PAIN);
    }
	else if (mod == UQ_4_12(0.0) && moveType == TYPE_ELECTRIC && defType == TYPE_GROUND && BATTLER_HAS_ABILITY(battlerAtk, ABILITY_GROUND_SHOCK))
    {
		mod = UQ_4_12(0.5);
        if (recordAbilities)
            RecordAbilityBattle(battlerAtk, ABILITY_GROUND_SHOCK);
    }
	else if (moveType == TYPE_ELECTRIC && defType == TYPE_ELECTRIC && BATTLER_HAS_ABILITY(battlerAtk, ABILITY_OVERCHARGE))
    {
		//Has Innate Effect here too
        mod = UQ_4_12(2.0); // super-effective
        if (recordAbilities)
            RecordAbilityBattle(battlerAtk, ABILITY_OVERCHARGE);
    }
	// Molten Down
	else if (moveType == TYPE_FIRE && defType == TYPE_ROCK && BATTLER_HAS_ABILITY(battlerAtk, ABILITY_MOLTEN_DOWN))
    {
		//Has Innate Effect here too
        mod = UQ_4_12(2.0); // super-effective
        if (recordAbilities)
            RecordAbilityBattle(battlerAtk, ABILITY_MOLTEN_DOWN);
    }
    // Magma Eater
    else if (moveType == TYPE_FIRE && defType == TYPE_ROCK && BATTLER_HAS_ABILITY(battlerAtk, ABILITY_MAGMA_EATER))
    {
		//Has Innate Effect here too
        mod = UQ_4_12(2.0); // super-effective
        if (recordAbilities)
            RecordAbilityBattle(battlerAtk, ABILITY_MAGMA_EATER);
    }
	else if (moveType == TYPE_POISON && defType == TYPE_STEEL && BATTLER_HAS_ABILITY(battlerAtk, ABILITY_CORROSION))
    {
		//Has Innate Effect here too
        mod = UQ_4_12(2.0); // super-effective
        if (recordAbilities)
            RecordAbilityBattle(battlerAtk, ABILITY_CORROSION);
    }
	else if (move == MOVE_POISON_STING && defType == TYPE_STEEL && BATTLER_HAS_ABILITY(battlerAtk, ABILITY_ANGELS_WRATH))
    {
		//Has Innate Effect here too
        mod = UQ_4_12(2.0); // super-effective
    }
	else if (move == MOVE_ELECTROWEB && defType == TYPE_GROUND && BATTLER_HAS_ABILITY(battlerAtk, ABILITY_ANGELS_WRATH))
    {
		//Has Innate Effect here too
        mod = UQ_4_12(2.0); // super-effective
    }
	else if (mod == UQ_4_12(0.0) && moveType == TYPE_DRAGON && defType == TYPE_FAIRY && BATTLER_HAS_ABILITY(battlerAtk, ABILITY_OVERWHELM))
    {
		//Has Innate Effect here too
        mod = UQ_4_12(1.0);
        if (recordAbilities)
            RecordAbilityBattle(battlerAtk, ABILITY_OVERWHELM);
    }

    if (moveType == TYPE_PSYCHIC && defType == TYPE_DARK && gStatuses3[battlerDef] & STATUS3_MIRACLE_EYED && mod == UQ_4_12(0.0))
        mod = UQ_4_12(1.0);
    if(gBattleMoves[move].effect == EFFECT_IGNORE_TYPE_IMMUNITY && defType == gBattleMoves[move].argument && mod == UQ_4_12(0.0))
        mod = UQ_4_12(1.0);
    if(gBattleMoves[move].effect == EFFECT_SE_AGAINST_TYPE_HIT && defType == gBattleMoves[move].argument)
        mod = UQ_4_12(2.0); // super-effective
    if (gBattleMoves[move].effect == EFFECT_FREEZE_DRY && defType == TYPE_WATER)
        mod = UQ_4_12(2.0); // super-effective
    if (gBattleMoves[move].effect == EFFECT_EXCALIBUR && defType == TYPE_DRAGON)
        mod = UQ_4_12(2.0); // super-effective
    if (gBattleMoves[move].effect == EFFECT_ACID && defType == TYPE_STEEL)
        mod = UQ_4_12(2.0);
    if (gBattleMoves[move].effect == EFFECT_SLUDGE && defType == TYPE_WATER)
        mod = UQ_4_12(2.0);
    if (gBattleMoves[move].effect == EFFECT_POISON_GAS && defType == TYPE_FLYING)
        mod = UQ_4_12(2.0);
    if (move == MOVE_GIGATON_HAMMER && defType == TYPE_STEEL)
        mod = UQ_4_12(2.0);
    if (moveType == TYPE_GROUND && defType == TYPE_FLYING && IsBattlerGrounded(battlerDef) && mod == UQ_4_12(0.0))
        mod = UQ_4_12(1.0);
    if (moveType == TYPE_FIRE && gDisableStructs[battlerDef].tarShot)
        mod = UQ_4_12(2.0); // super-effective

    // B_WEATHER_STRONG_WINDS weakens Super Effective moves against Flying-type Pokémon
    if (gBattleWeather & B_WEATHER_STRONG_WINDS && WEATHER_HAS_EFFECT)
    {
        if (defType == TYPE_FLYING && mod >= UQ_4_12(2.0))
            mod = UQ_4_12(1.0);
    }

    MulModifier(modifier, mod);
}

static void TryNoticeIllusionInTypeEffectiveness(u32 move, u32 moveType, u32 battlerAtk, u32 battlerDef, u16 resultingModifier, u32 illusionSpecies)
{
    // Check if the type effectiveness would've been different if the pokemon really had the types as the disguise.
    u16 presumedModifier = UQ_4_12(1.0);
    MulByTypeEffectiveness(&presumedModifier, move, moveType, battlerDef, gBaseStats[illusionSpecies].type1, battlerAtk, FALSE);
    if (gBaseStats[illusionSpecies].type2 != gBaseStats[illusionSpecies].type1)
        MulByTypeEffectiveness(&presumedModifier, move, moveType, battlerDef, gBaseStats[illusionSpecies].type2, battlerAtk, FALSE);

    if (presumedModifier != resultingModifier)
        RecordAbilityBattle(battlerDef, ABILITY_ILLUSION);
}

static void UpdateMoveResultFlags(u16 modifier)
{
    if (modifier == UQ_4_12(0.0))
    {
        gMoveResultFlags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
        gMoveResultFlags &= ~(MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_SUPER_EFFECTIVE);
    }
    else if (modifier == UQ_4_12(1.0))
    {
        gMoveResultFlags &= ~(MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_DOESNT_AFFECT_FOE);
    }
    else if (modifier > UQ_4_12(1.0))
    {
        gMoveResultFlags |= MOVE_RESULT_SUPER_EFFECTIVE;
        gMoveResultFlags &= ~(MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_DOESNT_AFFECT_FOE);
    }
    else //if (modifier < UQ_4_12(1.0))
    {
        gMoveResultFlags |= MOVE_RESULT_NOT_VERY_EFFECTIVE;
        gMoveResultFlags &= ~(MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_DOESNT_AFFECT_FOE);
    }
}

static u16 CalcTypeEffectivenessMultiplierInternal(u16 move, u8 moveType, u8 battlerAtk, u8 battlerDef, bool32 recordAbilities, u16 modifier)
{
    u32 illusionSpecies;
    u16 modifier1, modifier2, modifier3, modifierInitial;
    u8 currentAttackBattler = gBattlerAttacker;
    u16 immunityAbility = 0;
    gBattlerAttacker = battlerAtk;
    modifierInitial = modifier;
    modifier1 = modifier2 = modifier3 = UQ_4_12(1.0);
    MulByTypeEffectiveness(&modifier1, move, moveType, battlerDef, gBattleMons[battlerDef].type1, battlerAtk, recordAbilities);
    if (gBattleMons[battlerDef].type2 != gBattleMons[battlerDef].type1)
        MulByTypeEffectiveness(&modifier2, move, moveType, battlerDef, gBattleMons[battlerDef].type2, battlerAtk, recordAbilities);
    if (gBattleMons[battlerDef].type3 != TYPE_MYSTERY && gBattleMons[battlerDef].type3 != gBattleMons[battlerDef].type2
        && gBattleMons[battlerDef].type3 != gBattleMons[battlerDef].type1)
        MulByTypeEffectiveness(&modifier3, move, moveType, battlerDef, gBattleMons[battlerDef].type3, battlerAtk, recordAbilities);

    MulModifier(&modifier, modifier1);
    MulModifier(&modifier, modifier2);
    MulModifier(&modifier, modifier3);

    if (recordAbilities && (illusionSpecies = GetIllusionMonSpecies(battlerDef)))
        TryNoticeIllusionInTypeEffectiveness(move, moveType, battlerAtk, battlerDef, modifier, illusionSpecies);

    if (moveType == TYPE_GROUND && !IsBattlerGrounded(battlerDef) &&
       !(gBattleMoves[move].flags & FLAG_DMG_UNGROUNDED_IGNORE_TYPE_IF_FLYING)) // Moves that ignore ground immunity
    {
        if(BATTLER_HAS_ABILITY(battlerDef, ABILITY_LEVITATE) || BATTLER_HAS_ABILITY(battlerDef, ABILITY_DRAGONFLY)){ //Defender has Levitate as Ability
            modifier = UQ_4_12(0.0);
            immunityAbility = BATTLER_HAS_ABILITY(battlerDef, ABILITY_LEVITATE) ? ABILITY_LEVITATE : ABILITY_DRAGONFLY;
        }
        else // Everything Else
        {
            modifier = UQ_4_12(0.0);
        }
    }
    else if (BATTLER_HAS_ABILITY(battlerDef, ABILITY_MOUNTAINEER) && moveType == TYPE_ROCK)
    {
        modifier = UQ_4_12(0.0);
        immunityAbility = ABILITY_MOUNTAINEER;
    }
    else if (BATTLER_HAS_ABILITY(battlerDef, ABILITY_GIFTED_MIND) && (moveType == TYPE_DARK || moveType == TYPE_GHOST || moveType == TYPE_BUG))
    {
        modifier = UQ_4_12(0.0);
        immunityAbility = ABILITY_GIFTED_MIND;
    }
    else if (BATTLER_HAS_ABILITY(battlerDef, ABILITY_EVAPORATE) && moveType == TYPE_WATER)
    {
        modifier = UQ_4_12(0.0);
        immunityAbility = ABILITY_EVAPORATE;
    }

    if(BATTLER_HAS_ABILITY(battlerAtk, ABILITY_BONE_ZONE) && gBattleMoves[move].flags & FLAG_BONE_BASED && modifier < UQ_4_12(1.0)){
        modifier = UQ_4_12(1.0);
        if (modifier1) MulModifier(&modifier, modifier1);
        if (modifier2) MulModifier(&modifier, modifier2);
        if (modifier3) MulModifier(&modifier, modifier3);
        if (modifier < UQ_4_12(1.0)) MulModifier(&modifier, UQ_4_12(2.0));
    }

    // Thousand Arrows ignores type modifiers for flying mons
    if (!IsBattlerGrounded(battlerDef) && (gBattleMoves[move].flags & FLAG_DMG_UNGROUNDED_IGNORE_TYPE_IF_FLYING)
        && IS_BATTLER_OF_TYPE(battlerDef, TYPE_FLYING))
    {
        modifier = UQ_4_12(1.0);
    }

    // Thousand Arrows ignores type modifiers for flying mons
    if (!IsBattlerGrounded(battlerDef) && (gBattleMoves[move].flags & FLAG_DMG_UNGROUNDED_IGNORE_TYPE_IF_FLYING)
        && IS_BATTLER_OF_TYPE(battlerDef, TYPE_FLYING) && modifier == UQ_4_12(0))
    {
        modifier = UQ_4_12(1.0);
    }

    if (BATTLER_HAS_ABILITY(battlerDef, ABILITY_WONDER_GUARD) && modifier <= UQ_4_12(1.0) && gBattleMoves[move].power)
    {
        modifier = UQ_4_12(0.0);
        immunityAbility = ABILITY_WONDER_GUARD;
    }
    else if (GetBattlerAbility(battlerDef) == ABILITY_TELEPATHY && battlerDef == BATTLE_PARTNER(battlerAtk) && gBattleMoves[move].power)
    {
        modifier = UQ_4_12(0.0);
        immunityAbility = ABILITY_TELEPATHY;
    }

    
    if (recordAbilities && immunityAbility && !modifier)
    {
        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = immunityAbility;
        gMoveResultFlags |= (MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE);
        gLastLandedMoves[battlerDef] = 0;
        gBattleCommunication[MISS_TYPE] = B_MSG_AVOIDED_DMG;
        RecordAbilityBattle(battlerDef, immunityAbility);
    }

    gBattlerAttacker = currentAttackBattler;

    return modifier;
}

u16 CalcTypeEffectivenessMultiplier(u16 move, u8 moveType, u8 battlerAtk, u8 battlerDef, bool32 recordAbilities)
{
    u16 modifier = UQ_4_12(1.0);

    if (move != MOVE_STRUGGLE && moveType != TYPE_MYSTERY)
    {
        modifier = CalcTypeEffectivenessMultiplierInternal(move, moveType, battlerAtk, battlerDef, recordAbilities, modifier);
    }

    if (recordAbilities)
        UpdateMoveResultFlags(modifier);
    return modifier;
}

u16 CalcPartyMonTypeEffectivenessMultiplier(u16 move, u16 speciesDef, u16 abilityDef, u8 battlerDef)
{
    u16 modifier = UQ_4_12(1.0);
    u8 moveType = gBattleMoves[move].type;

    if (move != MOVE_STRUGGLE && moveType != TYPE_MYSTERY)
    {
        MulByTypeEffectiveness(&modifier, move, moveType, 0, gBaseStats[speciesDef].type1, 0, FALSE);
        if (gBaseStats[speciesDef].type2 != gBaseStats[speciesDef].type1)
            MulByTypeEffectiveness(&modifier, move, moveType, 0, gBaseStats[speciesDef].type2, 0, FALSE);

        if (moveType == TYPE_GROUND && (BATTLER_HAS_ABILITY_FAST(battlerDef, ABILITY_LEVITATE, abilityDef)) && !(gFieldStatuses & STATUS_FIELD_GRAVITY))
            modifier = UQ_4_12(0.0);
		if (moveType == TYPE_ROCK && (BATTLER_HAS_ABILITY_FAST(battlerDef, ABILITY_MOUNTAINEER, abilityDef) || BATTLER_HAS_ABILITY_FAST(battlerDef, ABILITY_FURNACE, abilityDef)))
            modifier = UQ_4_12(0.0);
		if ((moveType == TYPE_DARK || moveType == TYPE_GHOST || moveType == TYPE_BUG) && 
            (BATTLER_HAS_ABILITY_FAST(battlerDef, ABILITY_GIFTED_MIND, abilityDef))) 
            modifier = UQ_4_12(0.0);
        if (abilityDef == ABILITY_WONDER_GUARD && modifier <= UQ_4_12(1.0) && gBattleMoves[move].power)
            modifier = UQ_4_12(0.0);
    }

    UpdateMoveResultFlags(modifier);
    return modifier;
}

u16 GetTypeModifier(u8 atkType, u8 defType)
{
    if(IsInverseRoomActive()){
        if (B_FLAG_INVERSE_BATTLE != 0 && FlagGet(B_FLAG_INVERSE_BATTLE))
            return sTypeEffectivenessTable[atkType][defType];
        else
            return sInverseTypeEffectivenessTable[atkType][defType];
    }
    else{
        if (B_FLAG_INVERSE_BATTLE != 0 && FlagGet(B_FLAG_INVERSE_BATTLE))
            return sInverseTypeEffectivenessTable[atkType][defType];
        else
            return sTypeEffectivenessTable[atkType][defType];
    }
}

s32 GetStealthHazardDamage(u8 hazardType, u8 battlerId)
{
    u8 type1 = gBattleMons[battlerId].type1;
    u8 type2 = gBattleMons[battlerId].type2;
    u8 type3 = gBattleMons[battlerId].type3;
    u32 maxHp = gBattleMons[battlerId].maxHP;
    s32 dmg = 0;
    u16 modifier = UQ_4_12(1.0);

    MulModifier(&modifier, GetTypeModifier(hazardType, type1));
    if (type2 != type1)
        MulModifier(&modifier, GetTypeModifier(hazardType, type2));
    if (type3 != TYPE_MYSTERY && type3 != type1 && type3 != type2)
        MulModifier(&modifier, GetTypeModifier(hazardType, type3));

    switch (modifier)
    {
    case UQ_4_12(0.0):
        dmg = 0;
        break;
    case UQ_4_12(0.25):
        dmg = maxHp / 32;
        if (dmg == 0)
            dmg = 1;
        break;
    case UQ_4_12(0.5):
        dmg = maxHp / 16;
        if (dmg == 0)
            dmg = 1;
        break;
    case UQ_4_12(1.0):
        dmg = maxHp / 8;
        if (dmg == 0)
            dmg = 1;
        break;
    case UQ_4_12(2.0):
        dmg = maxHp / 4;
        if (dmg == 0)
            dmg = 1;
        break;
    case UQ_4_12(4.0):
        dmg = maxHp / 2;
        if (dmg == 0)
            dmg = 1;
        break;
    }

    return dmg;
}

bool32 IsPartnerMonFromSameTrainer(u8 battlerId)
{
    if (GetBattlerSide(battlerId) == B_SIDE_OPPONENT && gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        return FALSE;
    else if (GetBattlerSide(battlerId) == B_SIDE_PLAYER && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        return FALSE;
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        return FALSE;
    else
        return TRUE;
}

u16 GetMegaEvolutionSpecies(u16 preEvoSpecies, u16 heldItemId)
{
    u32 i;

    for (i = 0; i < EVOS_PER_MON; i++)
    {
        if (gEvolutionTable[preEvoSpecies][i].method == EVO_MEGA_EVOLUTION
         && gEvolutionTable[preEvoSpecies][i].param == heldItemId)
            return gEvolutionTable[preEvoSpecies][i].targetSpecies;
    }
    return SPECIES_NONE;
}


u16 GetPrimalReversionSpecies(u16 preEvoSpecies, u16 heldItemId)
{
    u32 i;

    for (i = 0; i < EVOS_PER_MON; i++)
    {
        if (gEvolutionTable[preEvoSpecies][i].method == EVO_PRIMAL_REVERSION
         && gEvolutionTable[preEvoSpecies][i].param == heldItemId)
            return gEvolutionTable[preEvoSpecies][i].targetSpecies;
    }
    return SPECIES_NONE;
}

u16 GetWishMegaEvolutionSpecies(u16 preEvoSpecies, u16 moveId1, u16 moveId2, u16 moveId3, u16 moveId4)
{
    u32 i, par;

    for (i = 0; i < EVOS_PER_MON; i++)
    {
        if (gEvolutionTable[preEvoSpecies][i].method == EVO_MOVE_MEGA_EVOLUTION)
        {
            par = gEvolutionTable[preEvoSpecies][i].param;
            if (par == moveId1 || par == moveId2 || par == moveId3 || par == moveId4)
                return gEvolutionTable[preEvoSpecies][i].targetSpecies;
        }
    }
    return SPECIES_NONE;
}

bool32 CanMegaEvolve(u8 battlerId)
{
    u32 itemId, holdEffect, species;
    struct Pokemon *mon;
    u8 battlerPosition = GetBattlerPosition(battlerId);
    u8 partnerPosition = GetBattlerPosition(BATTLE_PARTNER(battlerId));
    u8 step = 0;
    struct MegaEvolutionData *mega = &(((struct ChooseMoveStruct*)(&gBattleResources->bufferA[gActiveBattler][4]))->mega);

    // Check if Player has a Mega Ring and the appropriate flag is set
    if ((GetBattlerPosition(battlerId) == B_POSITION_PLAYER_LEFT || (!(gBattleTypeFlags & BATTLE_TYPE_MULTI) && GetBattlerPosition(battlerId) == B_POSITION_PLAYER_RIGHT))
     && (!CheckBagHasItem(ITEM_MEGA_BRACELET, 1) || !FlagGet(FLAG_SYS_RECEIVED_KEYSTONE)))
    {
        if(GetBattlerSide(battlerId) == B_SIDE_PLAYER)
            return FALSE;
    }

    // Gets mon data.
    if (GetBattlerSide(battlerId) == B_SIDE_OPPONENT)
        mon = &gEnemyParty[gBattlerPartyIndexes[battlerId]];
    else
        mon = &gPlayerParty[gBattlerPartyIndexes[battlerId]];

    species = GetMonData(mon, MON_DATA_SPECIES);
    itemId  = GetMonData(mon, MON_DATA_HELD_ITEM);

    // Check if trainer already mega evolved a pokemon.
    if (mega->alreadyEvolved[battlerPosition] &&
        ItemId_GetHoldEffect(itemId) != HOLD_EFFECT_PRIMAL_ORB && 
        GetBattlerSide(battlerId) == B_SIDE_PLAYER) //There can be a lot of primal mons per battle, it's only checked with the player
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        if (IsPartnerMonFromSameTrainer(battlerId)
            && ItemId_GetHoldEffect(itemId) != HOLD_EFFECT_PRIMAL_ORB //There can be a lot of primal mons per battle
            && (mega->alreadyEvolved[partnerPosition] || (mega->toEvolve & gBitTable[BATTLE_PARTNER(battlerId)]))
            )
            return FALSE;
    }

    // Check if there is an entry in the evolution table for regular Mega Evolution.
    if (GetMegaEvolutionSpecies(species, itemId) != SPECIES_NONE)
    {
        if (B_ENABLE_DEBUG && gBattleStruct->debugHoldEffects[battlerId])
            holdEffect = gBattleStruct->debugHoldEffects[battlerId];
        else if (itemId == ITEM_ENIGMA_BERRY)
            holdEffect = gEnigmaBerries[battlerId].holdEffect;
        else
            holdEffect = ItemId_GetHoldEffect(itemId);

        gBattleStruct->mega.isWishMegaEvo = FALSE;
        gBattleStruct->mega.isPrimalReversion = FALSE;
        return TRUE;
    }

    // Check if there is an entry in the evolution table for regular Primal Reversion.
    if (GetPrimalReversionSpecies(species, itemId) != SPECIES_NONE)
    {
        if (B_ENABLE_DEBUG && gBattleStruct->debugHoldEffects[battlerId])
            holdEffect = gBattleStruct->debugHoldEffects[battlerId];
        else if (itemId == ITEM_ENIGMA_BERRY)
            holdEffect = gEnigmaBerries[battlerId].holdEffect;
        else
            holdEffect = ItemId_GetHoldEffect(itemId);

        gBattleStruct->mega.isWishMegaEvo = FALSE;
        gBattleStruct->mega.isPrimalReversion = TRUE;
        return TRUE;
    }

    // Check if there is an entry in the evolution table for Wish Mega Evolution.
    if (GetWishMegaEvolutionSpecies(species, GetMonData(mon, MON_DATA_MOVE1), GetMonData(mon, MON_DATA_MOVE2), GetMonData(mon, MON_DATA_MOVE3), GetMonData(mon, MON_DATA_MOVE4)))
    {
        gBattleStruct->mega.isWishMegaEvo = TRUE;
        return TRUE;
    }

    // No checks passed, the mon CAN'T mega evolve.
    return FALSE;
}

void UndoMegaEvolution(u32 monId)
{
    u16 species = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES);
    u16 baseSpecies = GET_BASE_SPECIES_ID(GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES));
    bool8 multibattle = VarGet(VAR_0x8004) == SPECIAL_BATTLE_MULTI;

    switch(species){
        case SPECIES_ABOMASNOW_MEGA:
        case SPECIES_ABSOL_MEGA:
        case SPECIES_AERODACTYL_MEGA:
        case SPECIES_AGGRON_MEGA:
        case SPECIES_ALAKAZAM_MEGA:
        case SPECIES_ALTARIA_MEGA:
        case SPECIES_AMPHAROS_MEGA:
        case SPECIES_AUDINO_MEGA:
        case SPECIES_BANETTE_MEGA:
        case SPECIES_BEEDRILL_MEGA:
        case SPECIES_BLASTOISE_MEGA:
        case SPECIES_BLAZIKEN_MEGA:
        case SPECIES_CAMERUPT_MEGA:
        case SPECIES_CHARIZARD_MEGA_X:
        case SPECIES_CHARIZARD_MEGA_Y:
        case SPECIES_DIANCIE_MEGA:
        case SPECIES_GALLADE_MEGA:
        case SPECIES_GARCHOMP_MEGA:
        case SPECIES_GARDEVOIR_MEGA:
        case SPECIES_GENGAR_MEGA:
        case SPECIES_GLALIE_MEGA:
        case SPECIES_GYARADOS_MEGA:
        case SPECIES_HERACROSS_MEGA:
        case SPECIES_HOUNDOOM_MEGA:
        case SPECIES_KANGASKHAN_MEGA:
        case SPECIES_LATIAS_MEGA:
        case SPECIES_LATIOS_MEGA:
        case SPECIES_LOPUNNY_MEGA:
        case SPECIES_LUCARIO_MEGA:
        case SPECIES_MANECTRIC_MEGA:
        case SPECIES_MAWILE_MEGA:
        case SPECIES_MEDICHAM_MEGA:
        case SPECIES_METAGROSS_MEGA:
        case SPECIES_MEWTWO_MEGA_X:
        case SPECIES_MEWTWO_MEGA_Y:
        case SPECIES_PIDGEOT_MEGA:
        case SPECIES_PINSIR_MEGA:
        case SPECIES_SABLEYE_MEGA:
        case SPECIES_SALAMENCE_MEGA:
        case SPECIES_SCEPTILE_MEGA:
        case SPECIES_SCIZOR_MEGA:
        case SPECIES_SHARPEDO_MEGA:
        case SPECIES_SLOWBRO_MEGA:
        case SPECIES_STEELIX_MEGA:
        case SPECIES_SWAMPERT_MEGA:
        case SPECIES_TYRANITAR_MEGA:
        case SPECIES_VENUSAUR_MEGA:
        case SPECIES_MILOTIC_MEGA:
        case SPECIES_GROUDON_PRIMAL:
        case SPECIES_KYOGRE_PRIMAL:
        case SPECIES_FLYGON_MEGA:
        case SPECIES_BUTTERFREE_MEGA:
        case SPECIES_LAPRAS_MEGA:
        case SPECIES_MACHAMP_MEGA:
        case SPECIES_KINGLER_MEGA:
        case SPECIES_KINGDRA_MEGA:
        case SPECIES_DEWGONG_MEGA:
        case SPECIES_HITMONCHAN_MEGA:
        case SPECIES_HITMONLEE_MEGA:
        case SPECIES_HITMONTOP_MEGA:
        case SPECIES_CROBAT_MEGA:
        case SPECIES_SKARMORY_MEGA:
        case SPECIES_BRUXISH_MEGA:
        case SPECIES_TORTERRA_MEGA:
        case SPECIES_INFERNAPE_MEGA:
        case SPECIES_EMPOLEON_MEGA:
        case SPECIES_SHUCKLE_MEGA:
        case SPECIES_RELICANTH_MEGA:
        case SPECIES_QUAGSIRE_MEGA:
        case SPECIES_JELLICENT_MEGA:
        case SPECIES_TOUCANNON_MEGA:
        case SPECIES_DRAGONITE_MEGA:
        case SPECIES_BRELOOM_MEGA:
        case SPECIES_SLAKING_MEGA:
        case SPECIES_CASCOON_PRIMAL:
        case SPECIES_RAYQUAZA_MEGA:
        case SPECIES_FERALIGATR_MEGA_X:
        case SPECIES_FERALIGATR_MEGA_Y:
        case SPECIES_GRANBULL_MEGA:
        case SPECIES_GYARADOS_MEGA_Y:
        case SPECIES_HAXORUS_MEGA:
        case SPECIES_KINGDRA_MEGA_Y:
        case SPECIES_LUXRAY_MEGA:
        case SPECIES_NIDOKING_MEGA:
        case SPECIES_NIDOQUEEN_MEGA:
        case SPECIES_SANDSLASH_MEGA:
        case SPECIES_TYPHLOSION_MEGA:
        case SPECIES_MEGANIUM_MEGA:
        case SPECIES_KROOKODILE_MEGA:
        case SPECIES_MAGNEZONE_MEGA:
        case SPECIES_SHEDINJA_MEGA:
        case SPECIES_SWALOT_MEGA:
        case SPECIES_LANTURN_MEGA:
        case SPECIES_LAPRAS_MEGA_X:
        case SPECIES_SLOWKING_MEGA:
            SetMonData(&gPlayerParty[monId], MON_DATA_SPECIES, &baseSpecies);
        break;
    }

    if (gBattleStruct->mega.evolvedPartyIds[B_SIDE_PLAYER] & gBitTable[monId])
    {
        gBattleStruct->mega.evolvedPartyIds[B_SIDE_PLAYER] &= ~(gBitTable[monId]);
        if(multibattle && gBattleStruct->mega.playerEvolvedSpecies == SPECIES_NONE) //This fixes a problem with multis and mega evolutions
            SetMonData(&gPlayerParty[monId], MON_DATA_SPECIES, &baseSpecies);
        else
            SetMonData(&gPlayerParty[monId], MON_DATA_SPECIES, &gBattleStruct->mega.playerEvolvedSpecies);
        
        CalculateMonStats(&gPlayerParty[monId]);
    }
    else if (gBattleStruct->mega.primalRevertedPartyIds[B_SIDE_PLAYER] & gBitTable[monId])
    {
        gBattleStruct->mega.primalRevertedPartyIds[B_SIDE_PLAYER] &= ~(gBitTable[monId]);
        SetMonData(&gPlayerParty[monId], MON_DATA_SPECIES, &baseSpecies);
        CalculateMonStats(&gPlayerParty[monId]);
    }
    // While not exactly a mega evolution, Zygarde follows the same rules.
    else if (GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES, NULL) == SPECIES_ZYGARDE_COMPLETE)
    {
        SetMonData(&gPlayerParty[monId], MON_DATA_SPECIES, &gBattleStruct->changedSpecies[monId]);
        gBattleStruct->changedSpecies[monId] = 0;
        CalculateMonStats(&gPlayerParty[monId]);
    }
}

void DoBurmyFormChange(u32 monId)
{
    u16 newSpecies, currSpecies;
    struct Pokemon *party = gPlayerParty;

    currSpecies = GetMonData(&party[monId], MON_DATA_SPECIES, NULL);

    if ((GET_BASE_SPECIES_ID(currSpecies) == SPECIES_BURMY) 
        && (gBattleStruct->appearedInBattle & gBitTable[monId]) // Burmy appeared in battle
        && GetMonData(&party[monId], MON_DATA_HP, NULL) != 0) // Burmy isn't fainted
    {
        switch (gBattleTerrain)
        {  
            case BATTLE_TERRAIN_GRASS:
            case BATTLE_TERRAIN_LONG_GRASS:
            case BATTLE_TERRAIN_POND:
            case BATTLE_TERRAIN_MOUNTAIN:
            case BATTLE_TERRAIN_PLAIN:
                newSpecies = SPECIES_BURMY;
                break;
            case BATTLE_TERRAIN_CAVE:
            case BATTLE_TERRAIN_SAND:
                newSpecies = SPECIES_BURMY_SANDY_CLOAK;
                break;
            case BATTLE_TERRAIN_BUILDING:
                newSpecies = SPECIES_BURMY_TRASH_CLOAK;
                break;
            default: // Don't change form if last battle was water-related
                newSpecies = SPECIES_NONE;
                break;
        }

        if (newSpecies != SPECIES_NONE)
        {
            SetMonData(&party[monId], MON_DATA_SPECIES, &newSpecies);
            CalculateMonStats(&party[monId]);
        }
    }
}

void UndoFormChange(u32 monId, u32 side, bool32 isSwitchingOut)
// || gBattleMons[battlerDef].status2 & STATUS2_TRANSFORMED check for transformed mon before reverting
{
    u32 i, currSpecies;
    struct Pokemon *party = (side == B_SIDE_PLAYER) ? gPlayerParty : gEnemyParty;
    static const u16 species[][3] =
    {
        // Changed Form ID                      Default Form ID               Should change on switch
        {SPECIES_MIMIKYU_BUSTED,                SPECIES_MIMIKYU,              FALSE},
        {SPECIES_GRENINJA_ASH,                  SPECIES_GRENINJA_BATTLE_BOND, FALSE},
        {SPECIES_MELOETTA_PIROUETTE,            SPECIES_MELOETTA,             FALSE},
        {SPECIES_AEGISLASH_BLADE,               SPECIES_AEGISLASH,            TRUE},
        {SPECIES_AEGISLASH_BLADE_REDUX,         SPECIES_AEGISLASH_REDUX,      TRUE},
        {SPECIES_DARMANITAN_ZEN_MODE,           SPECIES_DARMANITAN,           TRUE},
        {SPECIES_MINIOR,                        SPECIES_MINIOR_CORE_RED,      TRUE},
        {SPECIES_MINIOR_METEOR_BLUE,            SPECIES_MINIOR_CORE_BLUE,     TRUE},
        {SPECIES_MINIOR_METEOR_GREEN,           SPECIES_MINIOR_CORE_GREEN,    TRUE},
        {SPECIES_MINIOR_METEOR_INDIGO,          SPECIES_MINIOR_CORE_INDIGO,   TRUE},
        {SPECIES_MINIOR_METEOR_ORANGE,          SPECIES_MINIOR_CORE_ORANGE,   TRUE},
        {SPECIES_MINIOR_METEOR_VIOLET,          SPECIES_MINIOR_CORE_VIOLET,   TRUE},
        {SPECIES_MINIOR_METEOR_YELLOW,          SPECIES_MINIOR_CORE_YELLOW,   TRUE},
        {SPECIES_WISHIWASHI_SCHOOL,             SPECIES_WISHIWASHI,           TRUE},
        {SPECIES_CRAMORANT_GORGING,             SPECIES_CRAMORANT,            TRUE},
        {SPECIES_CRAMORANT_GULPING,             SPECIES_CRAMORANT,            TRUE},
        {SPECIES_MORPEKO_HANGRY,                SPECIES_MORPEKO,              TRUE},
        {SPECIES_CASTFORM_RAINY,                SPECIES_CASTFORM,             TRUE},
        {SPECIES_CASTFORM_SNOWY,                SPECIES_CASTFORM,             TRUE},
        {SPECIES_CASTFORM_SUNNY,                SPECIES_CASTFORM,             TRUE},
        {SPECIES_CASTFORM_SANDY,                SPECIES_CASTFORM,             TRUE},
        {SPECIES_DARMANITAN_ZEN_MODE_GALARIAN,  SPECIES_DARMANITAN_GALARIAN,  TRUE},
    };

    currSpecies = GetMonData(&party[monId], MON_DATA_SPECIES, NULL);
    for (i = 0; i < ARRAY_COUNT(species); i++)
    {
        if (currSpecies == species[i][0] && (!isSwitchingOut || species[i][2] == TRUE))
        {
            SetMonData(&party[monId], MON_DATA_SPECIES, &species[i][1]);
            CalculateMonStats(&party[monId]);
            break;
        }
    }
}

bool32 DoBattlersShareType(u32 battler1, u32 battler2)
{
    s32 i;
    u8 types1[3] = {gBattleMons[battler1].type1, gBattleMons[battler1].type2, gBattleMons[battler1].type3};
    u8 types2[3] = {gBattleMons[battler2].type1, gBattleMons[battler2].type2, gBattleMons[battler2].type3};

    if (types1[2] == TYPE_MYSTERY)
        types1[2] = types1[0];
    if (types2[2] == TYPE_MYSTERY)
        types2[2] = types2[0];

    for (i = 0; i < 3; i++)
    {
        if (types1[i] == types2[0] || types1[i] == types2[1] || types1[i] == types2[2])
            return TRUE;
    }

    return FALSE;
}

bool32 CanBattlerGetOrLoseItem(u8 battlerId, u16 itemId)
{
    u16 species = gBattleMons[battlerId].species;
    u16 holdEffect = ItemId_GetHoldEffect(itemId);
    
    // Mail can be stolen now
    if (itemId == ITEM_ENIGMA_BERRY)
        return FALSE;
    else if (GET_BASE_SPECIES_ID(species) == SPECIES_KYOGRE && itemId == ITEM_BLUE_ORB) // includes primal
        return FALSE;
    else if (GET_BASE_SPECIES_ID(species) == SPECIES_GROUDON && itemId == ITEM_RED_ORB) // includes primal
        return FALSE;
    // Mega stone cannot be lost if pokemon's base species can mega evolve with it.
    else if (holdEffect == HOLD_EFFECT_MEGA_STONE)
        return FALSE;
    else if (GET_BASE_SPECIES_ID(species) == SPECIES_GIRATINA && itemId == ITEM_GRISEOUS_ORB)
        return FALSE;
    else if (GET_BASE_SPECIES_ID(species) == SPECIES_GENESECT && holdEffect == HOLD_EFFECT_DRIVE)
        return FALSE;
    else if (GET_BASE_SPECIES_ID(species) == SPECIES_SILVALLY && holdEffect == HOLD_EFFECT_MEMORY)
        return FALSE;
    else if (GET_BASE_SPECIES_ID(species) == SPECIES_ARCEUS && holdEffect == HOLD_EFFECT_PLATE)
        return FALSE;
#ifdef HOLD_EFFECT_Z_CRYSTAL
    else if (holdEffect == HOLD_EFFECT_Z_CRYSTAL)
        return FALSE;
#endif
    else
        return TRUE;
}

u32 GetIllusionMonSpecies(u32 battlerId)
{
    struct Pokemon *illusionMon = GetIllusionMonPtr(battlerId);
    if (illusionMon != NULL)
        return GetMonData(illusionMon, MON_DATA_SPECIES);
    return SPECIES_NONE;
}

struct Pokemon *GetIllusionMonPtr(u32 battlerId)
{
    if (gBattleStruct->illusion[battlerId].broken)
        return NULL;
    if (!gBattleStruct->illusion[battlerId].set)
    {
        if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
            SetIllusionMon(&gPlayerParty[gBattlerPartyIndexes[battlerId]], battlerId);
        else
            SetIllusionMon(&gEnemyParty[gBattlerPartyIndexes[battlerId]], battlerId);
    }
    if (!gBattleStruct->illusion[battlerId].on)
        return NULL;

    return gBattleStruct->illusion[battlerId].mon;
}

void ClearIllusionMon(u32 battlerId)
{
    memset(&gBattleStruct->illusion[battlerId], 0, sizeof(gBattleStruct->illusion[battlerId]));
}

bool32 SetIllusionMon(struct Pokemon *mon, u32 battlerId)
{
    struct Pokemon *party, *partnerMon;
    s32 i, id;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u32 personality = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u16 ability = RandomizeAbility(GetMonAbility(mon), species, personality);
    bool8 isEnemyMon = GetBattlerSide(battlerId) == B_SIDE_OPPONENT;

    gBattleStruct->illusion[battlerId].set = 1;
    if (ability != ABILITY_ILLUSION && !MonHasInnate(mon, ABILITY_ILLUSION, isEnemyMon))
        return FALSE;

    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (IsBattlerAlive(BATTLE_PARTNER(battlerId)))
        partnerMon = &party[gBattlerPartyIndexes[BATTLE_PARTNER(battlerId)]];
    else
        partnerMon = mon;

    // Find last alive non-egg pokemon.
    for (i = PARTY_SIZE - 1; i >= 0; i--)
    {
        id = i;
        if (GetMonData(&party[id], MON_DATA_SANITY_HAS_SPECIES)
            && GetMonData(&party[id], MON_DATA_HP)
            && !GetMonData(&party[id], MON_DATA_IS_EGG)
            && &party[id] != mon
            && &party[id] != partnerMon)
        {
            gBattleStruct->illusion[battlerId].on = 1;
            gBattleStruct->illusion[battlerId].broken = 0;
            gBattleStruct->illusion[battlerId].partyId = id;
            gBattleStruct->illusion[battlerId].mon = &party[id];
            return TRUE;
        }
    }

    return FALSE;
}

bool8 ShouldGetStatBadgeBoost(u16 badgeFlag, u8 battlerId)
{
    if (B_BADGE_BOOST != GEN_3)
        return FALSE;
    else if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_FRONTIER))
        return FALSE;
    else if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
        return FALSE;
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && gTrainerBattleOpponent_A == TRAINER_SECRET_BASE)
        return FALSE;
    else if (FlagGet(badgeFlag))
        return TRUE;
    else
        return FALSE;
}

u8 GetBattleMoveSplit(u32 moveId)
{
    if (gSwapDamageCategory) // Photon Geyser, Shell Side Arm, Light That Burns the Sky
        return SPLIT_PHYSICAL;
    else if (IS_MOVE_STATUS(moveId) || B_PHYSICAL_SPECIAL_SPLIT >= GEN_4)
        return gBattleMoves[moveId].split;
    else if (gBattleMoves[moveId].type < TYPE_MYSTERY)
        return SPLIT_PHYSICAL;
    else
        return SPLIT_SPECIAL;
}

static bool32 TryRemoveScreens(u8 battler)
{
    bool32 removed = FALSE;
    u8 battlerSide = GetBattlerSide(battler);
    u8 enemySide = GetBattlerSide(BATTLE_OPPOSITE(battler));

    // try to remove from battler's side
    if (gSideStatuses[battlerSide] & (SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL))
    {
        gSideStatuses[battlerSide] &= ~(SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL);
        gSideTimers[battlerSide].reflectTimer = 0;
        gSideTimers[battlerSide].lightscreenTimer = 0;
        gSideTimers[battlerSide].auroraVeilTimer = 0;
        removed = TRUE;
    }

    // try to remove from battler opponent's side
    if (gSideStatuses[enemySide] & (SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL))
    {
        gSideStatuses[enemySide] &= ~(SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL);
        gSideTimers[enemySide].reflectTimer = 0;
        gSideTimers[enemySide].lightscreenTimer = 0;
        gSideTimers[enemySide].auroraVeilTimer = 0;
        removed = TRUE;
    }

    return removed;
}

static bool32 IsUnnerveAbilityOnOpposingSide(u8 battlerId)
{
    if (IsAbilityOnOpposingSide(battlerId, ABILITY_UNNERVE)
      || IsAbilityOnOpposingSide(battlerId, ABILITY_AS_ONE_ICE_RIDER)
      || IsAbilityOnOpposingSide(battlerId, ABILITY_AS_ONE_SHADOW_RIDER)
      || IsAbilityOnOpposingSide(battlerId, ABILITY_CROWNED_KING))
        return TRUE;
    return FALSE;
}

bool32 TestMoveFlags(u16 move, u32 flag)
{
    if (gBattleMoves[move].flags & flag)
        return TRUE;
    return FALSE;
}

struct Pokemon *GetBattlerPartyData(u8 battlerId)
{
    struct Pokemon *mon;
    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        mon = &gPlayerParty[gBattlerPartyIndexes[battlerId]];
    else
        mon = &gEnemyParty[gBattlerPartyIndexes[battlerId]];
    return mon;
}

//Make sure the input bank is any bank on the specific mon's side
bool32 CanFling(u8 battlerId)
{
    u16 item = gBattleMons[battlerId].item;
    u16 itemEffect = ItemId_GetHoldEffect(item);

    if (item == ITEM_NONE
      || GetBattlerAbility(battlerId) == ABILITY_KLUTZ
      || isMagicRoomActive()
      || gDisableStructs[battlerId].embargoTimer != 0
      || !CanBattlerGetOrLoseItem(battlerId, item)
      //|| itemEffect == HOLD_EFFECT_PRIMAL_ORB
      || itemEffect == HOLD_EFFECT_GEMS
      #ifdef ITEM_ABILITY_CAPSULE
      || item == ITEM_ABILITY_CAPSULE
      #endif
      || (ItemId_GetPocket(item) == POCKET_BERRIES && IsAbilityOnSide(battlerId, ABILITY_UNNERVE))
      || GetPocketByItemId(item) == POCKET_POKE_BALLS)
        return FALSE;

    return TRUE;
}

// ability checks
bool32 IsRolePlayBannedAbilityAtk(u16 ability)
{
    u32 i;
    if (IsUnsuppressableAbility(ability)) return TRUE;
    return FALSE;
}

bool32 IsRolePlayBannedAbility(u16 ability)
{
    u32 i;
    if (!ability) return TRUE;
    if (IsUnsuppressableAbility(ability)) return TRUE;
    for (i = 0; i < ARRAY_COUNT(sRolePlayBannedAbilities); i++)
    {
        if (ability == sRolePlayBannedAbilities[i])
            return TRUE;
    }
    return FALSE;
}

bool32 IsWorrySeedBannedAbility(u16 ability)
{
    u32 i;
    if (IsUnsuppressableAbility(ability)) return TRUE;
    return FALSE;
}

bool32 IsGastroAcidBannedAbility(u16 ability)
{
    u32 i;
    if (IsUnsuppressableAbility(ability)) return TRUE;
    return FALSE;
}

bool32 IsEntrainmentBannedAbilityAttacker(u16 ability)
{
    u32 i;
    if (IsUnsuppressableAbility(ability)) return TRUE;
    for (i = 0; i < ARRAY_COUNT(sSkillSwapBannedAbilities); i++)
    {
        if (ability == sSkillSwapBannedAbilities[i])
            return TRUE;
    }
    return FALSE;
}

bool32 IsEntrainmentTargetOrSimpleBeamBannedAbility(u16 ability)
{
    u32 i;
    if (IsUnsuppressableAbility(ability)) return TRUE;
    for (i = 0; i < ARRAY_COUNT(sEntrainmentTargetSimpleBeamBannedAbilities); i++)
    {
        if (ability == sEntrainmentTargetSimpleBeamBannedAbilities[i])
            return TRUE;
    }
    return FALSE;
}

// Sort an array of battlers by speed
// Useful for effects like pickpocket, eject button, red card, dancer
void SortBattlersBySpeed(u8 *battlers, bool8 slowToFast)
{
    int i, j, currSpeed, currBattler;
    u16 speeds[4] = {0};
    
    for (i = 0; i < gBattlersCount; i++)
        speeds[i] = GetBattlerTotalSpeedStat(battlers[i], TOTAL_SPEED_FULL);

    for (i = 1; i < gBattlersCount; i++)
    {
        currBattler = battlers[i];
        currSpeed = speeds[i];
        j = i - 1;

        if (slowToFast)
        {
            while (j >= 0 && speeds[j] > currSpeed)
            {
                battlers[j + 1] = battlers[j];
                speeds[j + 1] = speeds[j];
                j = j - 1;
            }
        }
        else
        {
            while (j >= 0 && speeds[j] < currSpeed)
            {
                battlers[j + 1] = battlers[j];
                speeds[j + 1] = speeds[j];
                j = j - 1;
            }
        }

        battlers[j + 1] = currBattler;
        speeds[j + 1] = currSpeed;
    }
}

void TryRestoreStolenItems(void)
{
    u32 i;
    u16 stolenItem = ITEM_NONE;
    
    if (B_RESTORE_ALL_ITEMS)
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (gBattleStruct->itemStolen[i].originalItem != ITEM_NONE
                && GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, NULL) != gBattleStruct->itemStolen[i].originalItem)
            {
                stolenItem = gBattleStruct->itemStolen[i].originalItem;
                SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &stolenItem);
            }
        }
    }
    else
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (gBattleStruct->itemStolen[i].stolen)
            {
                stolenItem = gBattleStruct->itemStolen[i].originalItem;
                if (stolenItem != ITEM_NONE && ItemId_GetPocket(stolenItem) != POCKET_BERRIES)
                    SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &stolenItem);  // Restore stolen non-berry items
            }
        }
    }
}

bool32 CanStealItem(u8 battlerStealing, u8 battlerItem, u16 item)
{
    u8 stealerSide = GetBattlerSide(battlerStealing);
    
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
        return FALSE;
    
    // Check if the battler trying to steal should be able to
    if (stealerSide == B_SIDE_OPPONENT
        && !(gBattleTypeFlags &
             (BATTLE_TYPE_EREADER_TRAINER
              | BATTLE_TYPE_FRONTIER
              | BATTLE_TYPE_LINK
              | BATTLE_TYPE_RECORDED_LINK
              | BATTLE_TYPE_SECRET_BASE
              #if B_TRAINERS_KNOCK_OFF_ITEMS
              | BATTLE_TYPE_TRAINER
              #endif
              )))
    {
        return FALSE;
    }
    else if (!(gBattleTypeFlags &
          (BATTLE_TYPE_EREADER_TRAINER
           | BATTLE_TYPE_FRONTIER
           | BATTLE_TYPE_LINK
           | BATTLE_TYPE_RECORDED_LINK
           | BATTLE_TYPE_SECRET_BASE))
        && (gWishFutureKnock.knockedOffMons[stealerSide] & gBitTable[gBattlerPartyIndexes[battlerStealing]]))
    {
        return FALSE;
    }
    
    if (!CanBattlerGetOrLoseItem(battlerItem, item)      // Battler with item cannot have it stolen
      ||!CanBattlerGetOrLoseItem(battlerStealing, item)) // Stealer cannot take the item
        return FALSE;
    
    return TRUE;
}

void TrySaveExchangedItem(u8 battlerId, u16 stolenItem)
{
    // Because BtlController_EmitSetMonData does SetMonData, we need to save the stolen item only if it matches the battler's original
    // So, if the player steals an item during battle and has it stolen from it, it will not end the battle with it (naturally)
    #if B_TRAINERS_KNOCK_OFF_ITEMS == TRUE
    // If regular trainer battle and mon's original item matches what is being stolen, save it to be restored at end of battle
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER
      && !(gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
      && GetBattlerSide(battlerId) == B_SIDE_PLAYER
      && stolenItem == gBattleStruct->itemStolen[gBattlerPartyIndexes[battlerId]].originalItem)
        gBattleStruct->itemStolen[gBattlerPartyIndexes[battlerId]].stolen = TRUE;
    #endif
}

bool32 IsBattlerAffectedByHazards(u8 battlerId, bool32 toxicSpikes)
{
    bool32 ret = TRUE;
    u32 holdEffect = GetBattlerHoldEffect(gActiveBattler, TRUE);
    if (toxicSpikes && 
		holdEffect == HOLD_EFFECT_HEAVY_DUTY_BOOTS &&
		!IS_BATTLER_OF_TYPE(battlerId, TYPE_POISON))
    {
        ret = FALSE;
        RecordItemEffectBattle(battlerId, holdEffect);
    }
    else if (holdEffect == HOLD_EFFECT_HEAVY_DUTY_BOOTS)
    {
        ret = FALSE;
        RecordItemEffectBattle(battlerId, holdEffect);
    }
	else if (GetBattlerAbility(gActiveBattler) == ABILITY_SHIELD_DUST ||
		BattlerHasInnate(gActiveBattler, ABILITY_SHIELD_DUST))
    {
        ret = FALSE;
    }
	else if ((GetBattlerAbility(gActiveBattler) == ABILITY_MOUNTAINEER ||
		BattlerHasInnate(gActiveBattler, ABILITY_MOUNTAINEER)) && !toxicSpikes)
    {
        ret = FALSE;
    }
    else if ((GetBattlerAbility(gActiveBattler) == ABILITY_FURNACE ||
		BattlerHasInnate(gActiveBattler, ABILITY_FURNACE)) && !toxicSpikes)
    {
        ret = FALSE;
    }
    return ret;
}

bool32 TestSheerForceFlag(u8 battler, u16 move)
{
    if ((GetBattlerAbility(battler) == ABILITY_SHEER_FORCE || BattlerHasInnate(battler, ABILITY_SHEER_FORCE)) && 
         gBattleMoves[move].flags & FLAG_SHEER_FORCE_BOOST)
        return TRUE;
    else
        return FALSE;
}

// This function is the body of "jumpifstat", but can be used dynamically in a function
bool32 CompareStat(u8 battlerId, u8 statId, u8 cmpTo, u8 cmpKind)
{
    bool8 ret = FALSE;
    u8 statValue = gBattleMons[battlerId].statStages[statId];
    
    // Because this command is used as a way of checking if a stat can be lowered/raised,
    // we need to do some modification at run-time.
    if (GetBattlerAbility(battlerId) == ABILITY_CONTRARY || BattlerHasInnate(battlerId, ABILITY_CONTRARY))
    {
        if (cmpKind == CMP_GREATER_THAN)
            cmpKind = CMP_LESS_THAN;
        else if (cmpKind == CMP_LESS_THAN)
            cmpKind = CMP_GREATER_THAN;

        if (cmpTo == MIN_STAT_STAGE)
            cmpTo = MAX_STAT_STAGE;
        else if (cmpTo == MAX_STAT_STAGE)
            cmpTo = MIN_STAT_STAGE;
    }

    switch (cmpKind)
    {
    case CMP_EQUAL:
        if (statValue == cmpTo)
            ret = TRUE;
        break;
    case CMP_NOT_EQUAL:
        if (statValue != cmpTo)
            ret = TRUE;
        break;
    case CMP_GREATER_THAN:
        if (statValue > cmpTo)
            ret = TRUE;
        break;
    case CMP_LESS_THAN:
        if (statValue < cmpTo)
            ret = TRUE;
        break;
    case CMP_COMMON_BITS:
        if (statValue & cmpTo)
            ret = TRUE;
        break;
    case CMP_NO_COMMON_BITS:
        if (!(statValue & cmpTo))
            ret = TRUE;
        break;
    }
    
    return ret;
}

void BufferStatChange(u8 battlerId, u8 statId, u8 stringId)
{
    bool8 hasContrary = FALSE;
    
    if(GetBattlerAbility(battlerId) == ABILITY_CONTRARY || BattlerHasInnate(battlerId, ABILITY_CONTRARY))
        hasContrary = TRUE;

    PREPARE_STAT_BUFFER(gBattleTextBuff1, statId);
    if (stringId == STRINGID_STATFELL)
    {
        if (hasContrary)
            PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_STATROSE)
        else
            PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_STATFELL)
    }
    else if (stringId == STRINGID_STATROSE)
    {
        if (hasContrary)
            PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_STATFELL)
        else
            PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_STATROSE)
    }
    else
    {
        PREPARE_STRING_BUFFER(gBattleTextBuff2, stringId)
    }
}

bool32 TryRoomService(u8 battlerId)
{
    if (IsTrickRoomActive() && CompareStat(battlerId, STAT_SPEED, MIN_STAT_STAGE, CMP_GREATER_THAN))
    {
        BufferStatChange(battlerId, STAT_SPEED, STRINGID_STATFELL);
        gEffectBattler = gBattleScripting.battler = battlerId;
        SET_STATCHANGER(STAT_SPEED, 1, TRUE);
        gBattleScripting.animArg1 = 0xE + STAT_SPEED;
        gBattleScripting.animArg2 = 0;
        gLastUsedItem = gBattleMons[battlerId].item;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

// Move Checks
bool8 IsTwoStrikesMove(u16 move)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sTwoStrikeMoves); i++)
    {
        if (move == sTwoStrikeMoves[i])
            return TRUE;
    }
    return FALSE;
}

bool32 BlocksPrankster(u16 move, u8 battlerPrankster, u8 battlerDef, bool32 checkTarget)
{
    #if B_PRANKSTER_DARK_TYPES >= GEN_7
    if (!gProtectStructs[battlerPrankster].pranksterElevated)
        return FALSE;
    if (GetBattlerSide(battlerPrankster) == GetBattlerSide(battlerDef))
        return FALSE;
    if (checkTarget && (gBattleMoves[move].target & (MOVE_TARGET_OPPONENTS_FIELD | MOVE_TARGET_DEPENDS)))
        return FALSE;
    if (!IS_BATTLER_OF_TYPE(battlerDef, TYPE_DARK))
        return FALSE;
    if (gStatuses3[battlerDef] & STATUS3_SEMI_INVULNERABLE)
        return FALSE;
    
    return TRUE;
    #endif
    return FALSE;
}

u16 GetUsedHeldItem(u8 battler)
{
    return gBattleStruct->usedHeldItems[gBattlerPartyIndexes[battler]][GetBattlerSide(battler)];
}

bool32 IsBattlerWeatherAffected(u8 battlerId, u32 weatherFlags)
{
    if (gBattleWeather & weatherFlags && WEATHER_HAS_EFFECT)
    {
        // given weather is active -> check if its sun, rain against utility umbrella ( since only 1 weather can be active at once)
        if (gBattleWeather & (WEATHER_SUN_ANY | WEATHER_RAIN_ANY) && GetBattlerHoldEffect(battlerId, TRUE) == HOLD_EFFECT_UTILITY_UMBRELLA)
            return FALSE; // utility umbrella blocks sun, rain effects
    
        return TRUE;
    }
    return FALSE;
}

bool32 DoesBattlerIgnoreAbilityorInnateChecks(u8 battler)
{
    u16 ability = gBattleMons[battler].ability;

    if( ability == ABILITY_MOLD_BREAKER                 ||
        ability == ABILITY_TERAVOLT                     ||
        ability == ABILITY_TURBOBLAZE                   ||
        BattlerHasInnate(battler, ABILITY_MOLD_BREAKER) || 
        BattlerHasInnate(battler, ABILITY_TERAVOLT)     || 
        BattlerHasInnate(battler, ABILITY_TURBOBLAZE))
        return TRUE;

    return FALSE;
}

static bool8 DoesMoveBoostStats(u16 move){
    switch(gBattleMoves[move].effect){
        //Multiple Stats Up
        case EFFECT_CALM_MIND:
        //Attack
        case EFFECT_ATTACK_UP:
        case EFFECT_ATTACK_UP_2:
        case EFFECT_HOWL:
        //Defense
        case EFFECT_DEFENSE_UP:
        case EFFECT_DEFENSE_UP_2: 
        //Special Attack
        case EFFECT_SPECIAL_ATTACK_UP:
        case EFFECT_SPECIAL_ATTACK_UP_2:
        case EFFECT_SPECIAL_ATTACK_UP_3:
		//Special Defense
		case EFFECT_SPECIAL_DEFENSE_UP_2:
		//Speed
		case EFFECT_SPEED_UP_HIT:
		case EFFECT_SPEED_UP_2:
	    //Accuracy
		//case EFFECT_ACCURACY_UP:
            return TRUE;
        break;
        case EFFECT_ATTACK_UP_HIT:
		case EFFECT_SPECIAL_DEFENSE_UP:
        case EFFECT_SP_ATTACK_UP_HIT:
        case EFFECT_DEFENSE_UP_HIT:
        case EFFECT_ALL_STATS_UP_HIT:
            if(gBattleMoves[move].secondaryEffectChance == 100 || (gBattleScripting.moveEffect & MOVE_EFFECT_CERTAIN) || FlagGet(FLAG_LAST_MOVE_SECONDARY_EFFECT_ACTIVATED))
                return TRUE;
        break;
    }
    return FALSE;
}

bool8 HasAnyLoweredStat(u8 battler){
    u8 i;
    for(i = STAT_ATK; i < NUM_BATTLE_STATS; i++){
        if(CompareStat(battler, i, DEFAULT_STAT_STAGE, CMP_LESS_THAN))
            return TRUE;
    }
    return FALSE;
}

s32 GetCurrentTerrain(void)
{
    if(!TERRAIN_HAS_EFFECT)
        return 0;
    else if(gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN)
        return STATUS_FIELD_MISTY_TERRAIN;
    else if(gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN)
        return STATUS_FIELD_PSYCHIC_TERRAIN;
    else if(gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN)
        return STATUS_FIELD_ELECTRIC_TERRAIN;
    else if(gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN)
        return STATUS_FIELD_GRASSY_TERRAIN;
    else
        return 0;
}

u8 BattlerHasInnateOrAbility(u8 battler, u16 ability){
    if(BattlerHasInnate(battler, ability))
        return BATTLER_INNATE;
    else if(GetBattlerAbility(battler) == ability)
        return BATTLER_ABILITY;
    else
        return BATTLER_NONE;
}

bool8 IsTrickRoomActive(void){
    if(IsAbilityOnField(ABILITY_CLUELESS))
        return FALSE;
    else if(gFieldStatuses & STATUS_FIELD_TRICK_ROOM)
        return TRUE;
    else
        return FALSE;
}

bool8 IsInverseRoomActive(void){
    if(IsAbilityOnField(ABILITY_CLUELESS))
        return FALSE;
    else if(gFieldStatuses & STATUS_FIELD_INVERSE_ROOM)
        return TRUE;
    else
        return FALSE;
}

bool8 IsGravityActive(void){
    if(IsAbilityOnField(ABILITY_CLUELESS))
        return FALSE;
    else if(gFieldStatuses & STATUS_FIELD_GRAVITY)
        return TRUE;
    else
        return FALSE;
}

bool8 isMagicRoomActive(void){
    if(IsAbilityOnField(ABILITY_CLUELESS))
        return FALSE;
    else if(gFieldStatuses & STATUS_FIELD_MAGIC_ROOM)
        return TRUE;
    else
        return FALSE;
}

bool8 isWonderRoomActive(void){
    if(IsAbilityOnField(ABILITY_CLUELESS))
        return FALSE;
    else if(gFieldStatuses & STATUS_FIELD_WONDER_ROOM)
        return TRUE;
    else
        return FALSE;
}

bool8 CanUseExtraMove(u8 sBattlerAttacker, u8 sBattlerTarget){
    if(IsBattlerAlive(sBattlerAttacker)                         &&
       IsBattlerAlive(sBattlerTarget)                           &&
       !gProtectStructs[sBattlerAttacker].confusionSelfDmg      &&
       !gProtectStructs[sBattlerAttacker].extraMoveUsed         &&
       !gProtectStructs[sBattlerAttacker].flinchImmobility      &&
       !gProtectStructs[sBattlerAttacker].powderSelfDmg         &&
       !(gBattleMons[sBattlerAttacker].status1 & STATUS1_SLEEP) &&
       !(gBattleMons[sBattlerAttacker].status1 & STATUS1_FREEZE))
        return TRUE;
    else
        return FALSE;
}

u8 GetHighestStatId(u8 battlerId, u8 includeStatStages)
{
    u8 i;
    u8 highestId = STAT_ATK;
    u32 highestStat = 0;

    for (i = STAT_ATK; i < NUM_STATS; i++)
    {
        u16 statVal = *(&gBattleMons[battlerId].attack + (i - 1));
        if (includeStatStages)
        {
            statVal = statVal * gStatStageRatios[gBattleMons[battlerId].statStages[i]][0] / gStatStageRatios[gBattleMons[battlerId].statStages[i]][1];
        }
        if (statVal > highestStat)
        {
            highestStat = statVal;
            highestId = i;
        }
    }
    return highestId;
}

u8 GetHighestAttackingStatId(u8 battlerId, u8 includeStatStages)
{
    u8 i;
    u8 highestId = STAT_ATK;
    u32 highestStat = 0;

    for (i = STAT_ATK; i > STAT_SPATK; i += STAT_SPATK - STAT_ATK)
    {
        u16 statVal = *(&gBattleMons[battlerId].attack + (i - 1));
        if (includeStatStages)
        {
            statVal = statVal * gStatStageRatios[gBattleMons[battlerId].statStages[i]][0] / gStatStageRatios[gBattleMons[battlerId].statStages[i]][1];
        }
        if (statVal > highestStat)
        {
            highestStat = statVal;
            highestId = i;
        }
    }
    return highestId;
}

u8 GetHighestDefendingStatId(u8 battlerId, u8 includeStatStages)
{
    u8 i;
    u8 highestId = STAT_DEF;
    u32 highestStat = 0;

    for (i = STAT_DEF; i > STAT_SPDEF; i += STAT_SPDEF - STAT_DEF)
    {
        u16 statVal = *(&gBattleMons[battlerId].attack + (i - 1));
        if (includeStatStages)
        {
            statVal = statVal * gStatStageRatios[gBattleMons[battlerId].statStages[i]][0] / gStatStageRatios[gBattleMons[battlerId].statStages[i]][1];
        }
        if (statVal > highestStat)
        {
            highestStat = statVal;
            highestId = i;
        }
    }
    return highestId;
}

u8 TranslateStatId(u8 statId, u8 battlerId)
{
    if ((statId & STAT_HIGHEST_ATTACKING) == STAT_HIGHEST_ATTACKING) return GetHighestAttackingStatId(battlerId, statId & STAT_USE_STAT_BOOSTS_IN_CALC);
    if ((statId & STAT_HIGHEST_DEFENDING) == STAT_HIGHEST_DEFENDING) return GetHighestDefendingStatId(battlerId, statId & STAT_USE_STAT_BOOSTS_IN_CALC);
    if ((statId & STAT_HIGHEST_TOTAL) == STAT_HIGHEST_TOTAL) return GetHighestStatId(battlerId, statId & STAT_USE_STAT_BOOSTS_IN_CALC);
    return statId;
}

bool32 IsAlly(u32 battlerAtk, u32 battlerDef)
{
    return (GetBattlerSide(battlerAtk) == GetBattlerSide(battlerDef));
}

u16 GetInnateInSlot(u16 species, u8 position, u32 personality, u8 isPlayer)
{
    return isPlayer ? RandomizeInnate(gBaseStats[species].innates[position], species, personality) : gBaseStats[species].innates[position];
}

void UpdateAbilityStateIndicesForNewSpecies(u8 battler, u16 newSpecies)
{
    u32 personality = gBattleMons[battler].personality;
    bool8 isPlayer = GetBattlerSide(battler) == B_SIDE_PLAYER;
    u16 newAbilities[] = { 
        gBaseStats[newSpecies].abilities[gBattleMons[battler].abilityNum],
        GetInnateInSlot(newSpecies, 0, personality, isPlayer),
        GetInnateInSlot(newSpecies, 1, personality, isPlayer),
        GetInnateInSlot(newSpecies, 2, personality, isPlayer),
        };
    UpdateAbilityStateIndices(battler, newAbilities);
}

void UpdateAbilityStateIndicesForNewAbility(u8 battler, u16 newAbility)
{
    u16 species = gBattleMons[battler].species;
    u32 personality = gBattleMons[battler].personality;
    bool8 isPlayer = GetBattlerSide(battler) == B_SIDE_PLAYER;
    u16 newAbilities[] = { 
        newAbility,
        GetInnateInSlot(species, 0, personality, isPlayer),
        GetInnateInSlot(species, 1, personality, isPlayer),
        GetInnateInSlot(species, 2, personality, isPlayer),
        };
    UpdateAbilityStateIndices(battler, newAbilities);
}

void UpdateAbilityStateIndices(u8 battler, u16 newAbilities[])
{
    u8 i, j;
    u8 switchInAbilityDone[NUM_INNATE_PER_SPECIES + 1] = {0};
    u8 turnAbilityTriggers[NUM_INNATE_PER_SPECIES + 1] = {0};
    u32 abilityState[NUM_INNATE_PER_SPECIES + 1] = {0};
    u16 species = gBattleMons[battler].species;
    u32 personality = gBattleMons[battler].personality;
    bool8 isPlayer = GetBattlerSide(battler) == B_SIDE_PLAYER;
    u16 oldAbilities[] = { 
        gBattleMons[battler].ability,
        GetInnateInSlot(species, 0, personality, isPlayer),
        GetInnateInSlot(species, 1, personality, isPlayer),
        GetInnateInSlot(species, 2, personality, isPlayer),
        };

    for (i = 0; i < NUM_INNATE_PER_SPECIES + 1; i++)
    {
        for (j = 0; j < NUM_INNATE_PER_SPECIES + 1; j++)
        {
            if (newAbilities[i] == oldAbilities[j])
            {
                break;
            }
        }
        if (j >= NUM_INNATE_PER_SPECIES + 1) continue;
        switchInAbilityDone[i] = gBattlerState[battler].switchInAbilityDone[i];
        turnAbilityTriggers[i] = gSpecialStatuses[battler].turnAbilityTriggers[i];
        abilityState[i] = gBattlerState[battler].abilityState[i];
    }

    memcpy(&gBattlerState[battler].switchInAbilityDone, &switchInAbilityDone, sizeof(gBattlerState[battler].switchInAbilityDone));
    memcpy(&gSpecialStatuses[battler].turnAbilityTriggers, &turnAbilityTriggers, sizeof(gSpecialStatuses[battler].turnAbilityTriggers));
    memcpy(&gBattlerState[battler].abilityState, &abilityState, sizeof(gBattlerState[battler].abilityState));
}
