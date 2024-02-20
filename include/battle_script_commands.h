#ifndef GUARD_BATTLE_SCRIPT_COMMANDS_H
#define GUARD_BATTLE_SCRIPT_COMMANDS_H

#include "constants/pokemon.h"

#define WINDOW_CLEAR            0x1
#define WINDOW_x80              0x80

struct StatFractions
{
    u8 dividend;
    u8 divisor;
};

//Intimidate Clone Data
enum{
    I_CLONE_INTIMIDATE,
    I_CLONE_SCARE,
    I_CLONE_FEARMONGER,
    I_CLONE_MONKEY_BUSSINESS,
    I_CLONE_MALICIOUS,
    NUM_INTIMIDATE_CLONES
};

struct IntimidateCloneData
{
    u16 ability;
    u8 numStatsLowered; //1 - 3
    u8 statsLowered[3]; //atk, def, speed
    bool8 targetBoth;
};

void CheckForBadEggs(void);
s32 CalcCritChanceStage(u8 battlerAtk, u8 battlerDef, u32 move, bool32 recordAbility);
s8 GetInverseCritChance(u8 battlerAtk, u8 battlerDef, u32 move);
u32 GetTotalAccuracy(u32 battlerAtk, u32 battlerDef, u32 move);
u8 GetBattlerTurnOrderNum(u8 battlerId);
bool32 NoAliveMonsForEitherParty(void);
void SetMoveEffect(bool32 primary, u32 certain);
bool32 CanBattlerSwitch(u32 battlerId);
void BattleDestroyYesNoCursorAt(u8 cursorPosition);
void BattleCreateYesNoCursorAt(u8 cursorPosition);
void BufferMoveToLearnIntoBattleTextBuff2(void);
void HandleBattleWindow(u8 xStart, u8 yStart, u8 xEnd, u8 yEnd, u8 flags);
bool8 UproarWakeUpCheck(u8 battlerId);
bool32 DoesSubstituteBlockMove(u8 battlerAtk, u8 battlerDef, u32 move);
bool32 DoesDisguiseBlockMove(u8 battlerAtk, u8 battlerDef, u32 move);
s8 RemainingNoDamageHits(u8 battler);
u16 GetNoDamageAbility(u8 battler);
bool32 CanPoisonType(u8 battlerAttacker, u8 battlerTarget);
bool32 CanParalyzeType(u8 battlerAttacker, u8 battlerTarget);
bool32 CanUseLastResort(u8 battlerId);
u32 IsFlowerVeilProtected(u32 battler);
u32 IsLeafGuardProtected(u32 battler);
bool32 IsShieldsDownProtected(u32 battler);
u32 IsAbilityStatusProtected(u32 battler);
bool32 TryResetBattlerStatChanges(u8 battler);
bool32 TryResetBattlerStatBuffs(u8 battler);
bool32 CanCamouflage(u8 battlerId);
u16 GetNaturePowerMove(void);
u16 GetSecretPowerMoveEffect(void);
void StealTargetItem(u8 battlerStealer, u8 battlerItem);
void RemoveItem(u8 battler);
u8 GetCatchingBattler(void);
u32 IsDesertCloakProtected(u32 battler);
u8 getStatToLowerFromIntimidateClone(u16 ability, u8 num);
bool8 IsBattlerImmuneToLowerStatsFromIntimidateClone(u8 battler, u8 stat, u16 ability);
void SetStatChanger(u8 statId, s8 change);
u8 StatBuffValue(s8 change);
s8 ChangeStatBuffsImplicit(s8 statValue, u32 statId, u32 flags, const u8 *BS_ptr);
s8 ChangeStatBuffs(u8 battler, s8 statValue, u32 statId, u32 flags, const u8 *BS_ptr);
u8 GetFirstFaintedPartyIndex(u8 battler);

extern void (* const gBattleScriptingCommandsTable[])(void);
extern const u8 gBattlePalaceNatureToMoveGroupLikelihood[NUM_NATURES][4];
extern const struct StatFractions gAccuracyStageRatios[];

#endif // GUARD_BATTLE_SCRIPT_COMMANDS_H
