#ifndef GUARD_BATTLE_UTIL_H
#define GUARD_BATTLE_UTIL_H

#define MOVE_LIMITATION_ZEROMOVE                (1 << 0)
#define MOVE_LIMITATION_PP                      (1 << 1)
#define MOVE_LIMITATION_DISABLED                (1 << 2)
#define MOVE_LIMITATION_TORMENTED               (1 << 3)
#define MOVE_LIMITATION_TAUNT                   (1 << 4)
#define MOVE_LIMITATION_IMPRISON                (1 << 5)

#define ABILITYEFFECT_ON_SWITCHIN                0
#define ABILITYEFFECT_ENDTURN                    1
#define ABILITYEFFECT_MOVES_BLOCK                2
#define ABILITYEFFECT_ABSORBING                  3
#define ABILITYEFFECT_MOVE_END_ATTACKER          4
#define ABILITYEFFECT_MOVE_END                   5
#define ABILITYEFFECT_IMMUNITY                   6
#define ABILITYEFFECT_FORECAST                   7
#define ABILITYEFFECT_SYNCHRONIZE                8
#define ABILITYEFFECT_ATK_SYNCHRONIZE            9
#define ABILITYEFFECT_INTIMIDATE1                10
#define ABILITYEFFECT_INTIMIDATE2                11
#define ABILITYEFFECT_TRACE1                     12
#define ABILITYEFFECT_TRACE2                     13
#define ABILITYEFFECT_MOVE_END_OTHER             14
#define ABILITYEFFECT_NEUTRALIZINGGAS            15
#define ABILITYEFFECT_AFTER_RECOIL               16
#define ABILITYEFFECT_COPY_STATS                 17
#define ABILITYEFFECT_ATTACKER_FOLLOWUP_MOVE     18
#define ABILITYEFFECT_MOVE_END_EITHER            19
// Special cases
#define ABILITYEFFECT_SWITCH_IN_TERRAIN          0xFE
#define ABILITYEFFECT_SWITCH_IN_WEATHER          0xFF

#define ITEMEFFECT_ON_SWITCH_IN                 0x0
#define ITEMEFFECT_MOVE_END                     0x3
#define ITEMEFFECT_KINGSROCK                    0x4
#define ITEMEFFECT_TARGET                       0x5
#define ITEMEFFECT_ORBS                         0x6
#define ITEMEFFECT_LIFEORB_SHELLBELL            0x7
#define ITEMEFFECT_BATTLER_MOVE_END             0x8 // move end effects for just the battler, not whole field

#define WEATHER_HAS_EFFECT ((!IsAbilityOnField(ABILITY_CLOUD_NINE) && !IsAbilityOnField(ABILITY_AIR_LOCK) && !IsAbilityOnField(ABILITY_CLUELESS)))
#define TERRAIN_HAS_EFFECT (!IsAbilityOnField(ABILITY_CLUELESS))
#define ROOM_HAS_EFFECT    (!IsAbilityOnField(ABILITY_CLUELESS))

#define BATTLER_NONE       0
#define BATTLER_ABILITY    1
#define BATTLER_INNATE     2

#define WEATHER_DURATION                8
#define WEATHER_DURATION_EXTENDED       12
#define TERRAIN_DURATION                8
#define TERRAIN_DURATION_EXTENDED       12
#define GRAVITY_DURATION                5
#define GRAVITY_DURATION_EXTENDED       8
#define TRICK_ROOM_DURATION             5
#define TRICK_ROOM_DURATION_SHORT       3
#define WONDER_ROOM_DURATION            5
#define MAGIC_ROOM_DURATION             5
#define INVERSE_ROOM_DURATION           5
#define INVERSE_ROOM_DURATION_SHORT     3

#define IS_WHOLE_SIDE_ALIVE(battler)((IsBattlerAlive(battler) && IsBattlerAlive(BATTLE_PARTNER(battler))))
#define BATTLER_HAS_ABILITY(battlerId, ability) (IsBattlerAlive(battlerId) && BattlerHasAbility(battlerId, gBattlerAttacker, ability))
#define BATTLER_HAS_ABILITY_FAST(battlerId, abilityToCheck, battlerAbility) ((battlerAbility == abilityToCheck || BattlerHasInnate(battlerId, abilityToCheck))) //Useful to make calculations faster

#define BATTLER_HEALING_BLOCKED(battlerId) (gStatuses3[battlerId] & STATUS3_HEAL_BLOCK || gBattleMons[battlerId].status1 & STATUS1_BLEED || IsAbilityOnOpposingSide(battlerId, ABILITY_PERMANENCE))

enum MiscMoveEffects
{
    MISC_EFFECT_SUPEREFFECTIVE_BOOST = 1,
    MISC_EFFECT_FAINTED_MON_BOOST,
    MISC_EFFECT_ELECTRIC_TERRAIN_BOOST,
    MISC_EFFECT_TOOK_DAMAGE_BOOST,
    MISC_EFFECT_INCREASED_CRIT_DAMAGE,
};

// for Natural Gift and Fling
struct TypePower
{
    u8 type;
    u8 power;
    u16 effect;
};

typedef enum
{
    PARADOX_BOOST_NOT_ACTIVE = 0,
    PARADOX_BOOSTER_ENERGY = 1,
    PARADOX_WEATHER_ACTIVE = 2,
} ParadoxBoostSource;

struct ParadoxBoost
{
    ParadoxBoostSource source:2;
    u8 statId:3;
};

struct StatCopyState
{
    bool8 inProgress:1;
    u8 battler:2;
    u8 stat:3;
    bool8 announced:1;
};

union AbilityStates
{
    struct ParadoxBoost paradoxBoost;
    struct StatCopyState statCopyState;
    u32 intValue;
};

#define CUD_CHEW_CURRENT_TURN (1 << 15)

#define IS_IRON_FIST(attacker, moveToCheck) (gBattleMoves[moveToCheck].flags & FLAG_IRON_FIST_BOOST || (BATTLER_HAS_ABILITY(attacker, ABILITY_BRAWLING_WYVERN) && IS_MOVE_TYPE(moveToCheck, TYPE_DRAGON)))

extern const struct TypePower gNaturalGiftTable[];

s32 CountUsablePartyMons(u8 battlerId);
void HandleAction_ThrowBall(void);
bool32 IsAffectedByFollowMe(u32 battlerAtk, u32 defSide, u32 move);
void HandleAction_UseMove(void);
void HandleAction_Switch(void);
void HandleAction_UseItem(void);
void HandleAction_Run(void);
void HandleAction_WatchesCarefully(void);
void HandleAction_SafariZoneBallThrow(void);
void HandleAction_ThrowPokeblock(void);
void HandleAction_GoNear(void);
bool8 CanUseExtraMove(u8 sBattlerAttacker, u8 sBattlerTarget);
void HandleAction_SafariZoneRun(void);
void HandleAction_WallyBallThrow(void);
void HandleAction_TryFinish(void);
void HandleAction_NothingIsFainted(void);
void HandleAction_ActionFinished(void);
u8 GetBattlerForBattleScript(u8 caseId);
bool8 IsSleepDisabled(u8 battlerId);
bool8 IsSleepClauseDisablingMove(u8 battlerId, u16 move);
void MarkAllBattlersForControllerExec(void); // unused
bool32 IsBattlerMarkedForControllerExec(u8 battlerId);
void MarkBattlerForControllerExec(u8 battlerId);
void MarkBattlerReceivedLinkData(u8 arg0);
void CancelMultiTurnMoves(u8 battlerId);
bool8 WasUnableToUseMove(u8 battlerId);
void PrepareStringBattle(u16 stringId, u8 battlerId);
void ResetSentPokesToOpponentValue(void);
void OpponentSwitchInResetSentPokesToOpponentValue(u8 battlerId);
void UpdateSentPokesToOpponentValue(u8 battlerId);
void BattleScriptPush(const u8* bsPtr);
void BattleScriptPushCursor(void);
void BattleScriptPop(void);
u8 TrySetCantSelectMoveBattleScript(void);
u8 CheckMoveLimitations(u8 battlerId, u8 unusableMoves, u8 check);
bool8 AreAllMovesUnusable(void);
u8 GetImprisonedMovesCount(u8 battlerId, u16 move);
u8 DoFieldEndTurnEffects(void);
s32 GetDrainedBigRootHp(u32 battler, s32 hp);
u8 DoBattlerEndTurnEffects(void);
bool8 HandleWishPerishSongOnTurnEnd(void);
bool8 HandleFaintedMonActions(void);
void TryClearRageAndFuryCutter(void);
u8 AtkCanceller_UnableToUseMove(void);
u8 AtkCanceller_UnableToUseMove2(void);
bool8 HasNoMonsToSwitch(u8 battlerId, u8 r1, u8 r2);
bool32 TryChangeBattleWeather(u8 battler, u32 weatherEnumId, bool32 viaAbility);
u8 AbilityBattleEffects(u8 caseID, u8 battlerId, u16 ability, u8 special, u16 moveArg);
u32 GetBattlerAbility(u8 battlerId);
bool8 BattlerAbilityIsSuppressed(u8 battlerId, u8 attacker);
u32 GetBattlerAbilityWithoutRemoval(u8 battlerId);
bool8 BattlerIgnoresAbility(u8 sBattlerAttacker, u8 sBattlerTarget, u16 ability);
bool8 BattlerAbilityWasRemoved(u8 battlerId, u32 ability);
u32 IsAbilityOnSide(u32 battlerId, u32 ability);
u32 IsAbilityOnOpposingSide(u32 battlerId, u32 ability);
u32 IsAbilityOnField(u32 ability);
u32 IsAbilityOnFieldExcept(u32 battlerId, u32 ability);
u32 IsAbilityPreventingEscape(u32 battlerId);
bool32 IsBattlerProtected(u8 battlerId, u16 move);
bool32 CanBattlerEscape(u32 battlerId); // no ability check
void BattleScriptExecute(const u8* BS_ptr);
void BattleScriptPushCursorAndCallback(const u8* BS_ptr);
u8 ItemBattleEffects(u8 caseID, u8 battlerId, bool8 moveTurn);
void ClearFuryCutterDestinyBondGrudge(u8 battlerId);
void HandleAction_RunBattleScript(void);
u32 SetRandomTarget(u32 battlerId);
u32 GetMoveTarget(u16 move, u8 setTarget);
u8 IsMonDisobedient(void);
u32 GetBattlerHoldEffect(u8 battlerId, bool32 checkNegating);
u32 GetBattlerHoldEffectParam(u8 battlerId);
bool32 IsMoveMakingContact(u16 move, u8 battlerAtk);
bool32 IsBattlerGrounded(u8 battlerId);
bool32 IsBattlerAlive(u8 battlerId);
u8 GetBattleMonMoveSlot(struct BattlePokemon *battleMon, u16 move);
u32 GetBattlerWeight(u8 battlerId);
s32 CalculateMoveDamage(u16 move, u8 battlerAtk, u8 battlerDef, u8* moveType, s32 fixedBasePower, bool32 isCrit, bool32 randomFactor, bool32 updateFlags);
s32 CalculateMoveDamageAndEffectiveness(u16 move, u8 battlerAtk, u8 battlerDef, u8* moveType, u16 *typeEffectivenessModifier);
u32 CalcMoveBasePowerAfterModifiers(u16 move, u8 fixedPower, u8 battlerAtk, u8 battlerDef, u8 moveType, bool32 updateFlags);
u16 CalcTypeEffectivenessMultiplier(u16 move, u8 moveType, u8 battlerAtk, u8 battlerDef, bool32 recordAbilities);
u16 CalcPartyMonTypeEffectivenessMultiplier(u16 move, u16 speciesDef, u16 abilityDef, u8 leveldef);
u16 GetTypeModifier(u8 atkType, u8 defType);
s32 GetStealthHazardDamage(u8 hazardType, u8 battlerId);
u16 GetMegaEvolutionSpecies(u16 preEvoSpecies, u16 heldItemId);
u16 GetPrimalReversionSpecies(u16 preEvoSpecies, u16 heldItemId);
u16 GetWishMegaEvolutionSpecies(u16 preEvoSpecies, u16 moveId1, u16 moveId2, u16 moveId3, u16 moveId4);
bool32 CanMegaEvolve(u8 battlerId);
void UndoMegaEvolution(u32 monId);
void UndoFormChange(u32 monId, u32 side, bool32 isSwitchingOut);
bool32 DoBattlersShareType(u32 battler1, u32 battler2);
bool32 CanBattlerGetOrLoseItem(u8 battlerId, u16 itemId);
struct Pokemon *GetIllusionMonPtr(u32 battlerId);
void ClearIllusionMon(u32 battlerId);
bool32 SetIllusionMon(struct Pokemon *mon, u32 battlerId);
u8 GetBattleMoveSplit(u32 moveId);
bool32 TestMoveFlags(u16 move, u32 flag);
struct Pokemon *GetBattlerPartyData(u8 battlerId);
bool32 CanFling(u8 battlerId);
bool32 IsTelekinesisBannedSpecies(u16 species);
bool32 IsHealBlockPreventingMove(u8 battler, u32 move);
bool32 HasEnoughHpToEatBerry(u32 battlerId, u32 hpFraction, u32 itemId);
void SortBattlersBySpeed(u8 *battlers, bool8 slowToFast);
bool32 TestSheerForceFlag(u8 battler, u16 move);
void TryRestoreStolenItems(void);
bool32 CanStealItem(u8 battlerStealing, u8 battlerItem, u16 item);
void TrySaveExchangedItem(u8 battlerId, u16 stolenItem);
bool32 IsPartnerMonFromSameTrainer(u8 battlerId);
u8 TryHandleSeed(u8 battler, u32 terrainFlag, u8 statId, u16 itemId, bool32 execute);
bool32 IsBattlerAffectedByHazards(u8 battlerId, bool32 toxicSpikes);
void SortBattlersBySpeed(u8 *battlers, bool8 slowToFast);
bool32 CompareStat(u8 battlerId, u8 statId, u8 cmpTo, u8 cmpKind);
bool32 TryRoomService(u8 battlerId);
void BufferStatChange(u8 battlerId, u8 statId, u8 stringId);
void DoBurmyFormChange(u32 monId);
bool32 BlocksPrankster(u16 move, u8 battlerPrankster, u8 battlerDef, bool32 checkTarget);
u16 GetUsedHeldItem(u8 battler);
bool32 IsBattlerWeatherAffected(u8 battlerId, u32 weatherFlags);
void TryToApplyMimicry(u8 battlerId, bool8 various);
void TryToRevertMimicry(void);
void RestoreBattlerOriginalTypes(u8 battlerId);
bool8 IsMoveAffectedByParentalBond(u16 move, u8 battlerId);
u8 GetBattleMoveTargetFlags(u16 moveId, u16 ability);
u8 GetBattlerBattleMoveTargetFlags(u16 moveId, u8 battler);
bool32 ShouldChangeFormHpBased(u32 battler);
u32 CountBattlerStatIncreases(u8 battlerId, bool32 countEvasionAcc);
bool32 DoesBattlerIgnoreAbilityorInnateChecks(u8 battler);
s32 GetCurrentTerrain(void);
u8 BattlerHasInnateOrAbility(u8 battler, u16 ability);
bool8 IsTrickRoomActive(void);
bool8 IsInverseRoomActive(void);
bool8 IsGravityActive(void);
bool8 isMagicRoomActive(void);
bool8 isWonderRoomActive(void);
bool32 TryPrimalReversion(u8 battlerId);
bool8 HasAnyLoweredStat(u8 battler);
u32 CalculateStat(u8 battler, u8 statEnum, u8 secondaryStat, u16 move, bool8 isAttack, bool8 isCrit, bool8 isUnaware, bool8 calculatingSecondary);
bool8 CheckAndSetSwitchInAbility(u8 battlerId, u16 ability);
s8 GetSingleUseAbilityCounter(u8 battler, u16 ability);
void SetSingleUseAbilityCounter(u8 battler, u16 ability, u8 value);
void IncrementSingleUseAbilityCounter(u8 battler, u16 ability, u8 value);
u32 GetAbilityState(u8 battler, u16 ability);
void SetAbilityState(u8 battler, u16 ability, u32 value);
union AbilityStates GetAbilityStateAs(u8 battler, u16 ability);
void SetAbilityStateAs(u8 battler, u16 ability, union AbilityStates value);
void IncrementAbilityState(u8 battler, u16 ability, u32 value);
u8 GetHighestStatId(u8 battlerId, u8 includeStatStages);
u8 GetHighestAttackingStatId(u8 battlerId, u8 includeStatStages);
u8 GetHighestDefendingStatId(u8 battlerId, u8 includeStatStages);
u8 TranslateStatId(u8 statId, u8 battlerId);
bool32 IsAlly(u32 battlerAtk, u32 battlerDef);
void UpdateAbilityStateIndices(u8 battler, u16 newAbilities[]);
void UpdateAbilityStateIndicesForNewAbility(u8 battler, u16 newAbility);
void UpdateAbilityStateIndicesForNewSpecies(u8 battler, u16 newSpecies);
bool32 IsUnsuppressableAbility(u32 ability);
bool8 CanBeDisabled(u8 battlerId);
bool8 DoesBattlerHaveAbilityShield(u8 battlerId);
u16 IsSoundproof(u8 battlerId);
bool8 BattlerHasAbility(u8 battlerId, u8 attacker, u16 ability);

// Ability checks
bool32 IsRolePlayBannedAbilityAtk(u16 ability);
bool32 IsRolePlayBannedAbility(u16 ability);
bool32 IsWorrySeedBannedAbility(u16 ability);
bool32 IsGastroAcidBannedAbility(u16 ability);
bool32 IsEntrainmentBannedAbilityAttacker(u16 ability);
bool32 IsEntrainmentTargetOrSimpleBeamBannedAbility(u16 ability);

bool32 CanSleep(u8 battlerId);
bool32 CanBePoisoned(u8 battlerAttacker, u8 battlerTarget);
bool32 CanBeBurned(u8 battlerId);
bool32 CanBeParalyzed(u8 battlerAttacker, u8 battlerTarget);
bool32 CanBeFrozen(u8 battlerId);
bool32 CanGetFrostbite(u8 battlerId);
bool32 CanBeConfused(u8 battlerId);
bool32 CanBleed(u8 battlerId);
bool32 IsBattlerTerrainAffected(u8 battlerId, u32 terrainFlag);

// Move checks
bool8 IsTwoStrikesMove(u16 move);

u32 CalcFinalDmg(u32 dmg, u16 move, u8 battlerAtk, u8 battlerDef, u8 moveType, u16 typeEffectivenessModifier, bool32 isCrit, bool32 updateFlags);
void MulByTypeEffectiveness(u16 *modifier, u16 move, u8 moveType, u8 battlerDef, u8 defType, u8 battlerAtk, bool32 recordAbilities);

u32 GetIllusionMonSpecies(u32 battlerId);
s32 DoMoveDamageCalcBattleMenu(u16 move, u8 battlerAtk, u8 battlerDef, u8* moveType, bool32 isCrit, u8 randomFactor);
#endif // GUARD_BATTLE_UTIL_H
