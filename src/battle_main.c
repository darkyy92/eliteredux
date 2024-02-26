#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "battle_arena.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_main.h"
#include "battle_message.h"
#include "battle_pyramid.h"
#include "battle_scripts.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_util.h"
#include "berry.h"
#include "bg.h"
#include "data.h"
#include "debug.h"
#include "decompress.h"
#include "dexnav.h"
#include "dma3.h"
#include "event_data.h"
#include "evolution_scene.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "link_rfu.h"
#include "load_save.h"
#include "main.h"
#include "malloc.h"
#include "m4a.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "rtc.h"
#include "recorded_battle.h"
#include "roamer.h"
#include "safari_zone.h"
#include "scanline_effect.h"
#include "script_pokemon_util.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "trig.h"
#include "tv.h"
#include "util.h"
#include "wild_encounter.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/battle_config.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_string_ids.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/opponents.h"
#include "constants/spreads.h"
#include "cable_club.h"
#include "mgba_printf/mgba.h"
#include "mgba_printf/mini_printf.h"

extern struct MusicPlayerInfo gMPlayInfo_SE1;
extern struct MusicPlayerInfo gMPlayInfo_SE2;

extern const struct BgTemplate gBattleBgTemplates[];
extern const struct WindowTemplate *const gBattleWindowTemplates[];

// this file's functions
static void CB2_InitBattleInternal(void);
static void CB2_PreInitMultiBattle(void);
static void CB2_PreInitIngamePlayerPartnerBattle(void);
static void CB2_HandleStartMultiPartnerBattle(void);
static void CB2_HandleStartMultiBattle(void);
static void CB2_HandleStartBattle(void);
static void TryCorrectShedinjaLanguage(struct Pokemon *mon);
static u8 CreateNPCTrainerParty(struct Pokemon *party, u16 trainerNum, bool8 firstTrainer);
static void BattleMainCB1(void);
static void sub_8038538(struct Sprite *sprite);
static void CB2_EndLinkBattle(void);
static void EndLinkBattleInSteps(void);
static void sub_80392A8(void);
static void sub_803937C(void);
static void sub_803939C(void);
static void SpriteCb_MoveWildMonToRight(struct Sprite *sprite);
static void SpriteCb_WildMonShowHealthbox(struct Sprite *sprite);
static void SpriteCb_WildMonAnimate(struct Sprite *sprite);
static void sub_80398D0(struct Sprite *sprite);
static void SpriteCB_AnimFaintOpponent(struct Sprite *sprite);
static void SpriteCb_BlinkVisible(struct Sprite *sprite);
static void SpriteCallbackDummy_3(struct Sprite *sprite);
static void SpriteCB_BattleSpriteSlideLeft(struct Sprite *sprite);
static void TurnValuesCleanUp(bool8 var0);
static void SpriteCB_BounceEffect(struct Sprite *sprite);
static void BattleStartClearSetData(void);
static void DoBattleIntro(void);
static void TryDoEventsBeforeFirstTurn(void);
static void HandleTurnActionSelectionState(void);
static void RunTurnActionsFunctions(void);
static void SetActionsAndBattlersTurnOrder(void);
static void sub_803CDF8(void);
static bool8 AllAtActionConfirmed(void);
static void TryChangeTurnOrder(void);
static void CheckFocusPunch_ClearVarsBeforeTurnStarts(void);
static void CheckMegaEvolutionBeforeTurn(void);
static void CheckQuickClaw_CustapBerryActivation(void);
static void FreeResetData_ReturnToOvOrDoEvolutions(void);
static void ReturnFromBattleToOverworld(void);
static void TryEvolvePokemon(void);
static void WaitForEvoSceneToFinish(void);
static void HandleEndTurn_ContinueBattle(void);
static void HandleEndTurn_BattleWon(void);
static void HandleEndTurn_BattleLost(void);
static void HandleEndTurn_RanFromBattle(void);
static void HandleEndTurn_MonFled(void);
static void HandleEndTurn_FinishBattle(void);
static u8 getRole(u16 species);

// EWRAM vars
EWRAM_DATA u16 gBattle_BG0_X = 0;
EWRAM_DATA u16 gBattle_BG0_Y = 0;
EWRAM_DATA u16 gBattle_BG1_X = 0;
EWRAM_DATA u16 gBattle_BG1_Y = 0;
EWRAM_DATA u16 gBattle_BG2_X = 0;
EWRAM_DATA u16 gBattle_BG2_Y = 0;
EWRAM_DATA u16 gBattle_BG3_X = 0;
EWRAM_DATA u16 gBattle_BG3_Y = 0;
EWRAM_DATA u16 gBattle_WIN0H = 0;
EWRAM_DATA u16 gBattle_WIN0V = 0;
EWRAM_DATA u16 gBattle_WIN1H = 0;
EWRAM_DATA u16 gBattle_WIN1V = 0;
EWRAM_DATA u8 gDisplayedStringBattle[400] = {0};
EWRAM_DATA u8 gBattleTextBuff1[TEXT_BUFF_ARRAY_COUNT] = {0};
EWRAM_DATA u8 gBattleTextBuff2[TEXT_BUFF_ARRAY_COUNT] = {0};
EWRAM_DATA u8 gBattleTextBuff3[TEXT_BUFF_ARRAY_COUNT] = {0};
EWRAM_DATA u8 gBattleTextBuff4[TEXT_BUFF_ARRAY_COUNT] = {0};
EWRAM_DATA u32 gBattleTypeFlags = 0;
EWRAM_DATA u8 gBattleTerrain = 0;
EWRAM_DATA u32 gUnusedFirstBattleVar1 = 0; // Never read
EWRAM_DATA struct UnknownPokemonStruct4 gMultiPartnerParty[MULTI_PARTY_SIZE] = {0};
EWRAM_DATA static struct UnknownPokemonStruct4* sMultiPartnerPartyBuffer = NULL;
EWRAM_DATA u8 *gUnknown_0202305C = NULL;
EWRAM_DATA u8 *gUnknown_02023060 = NULL;
EWRAM_DATA u8 gActiveBattler = 0;
EWRAM_DATA u32 gBattleControllerExecFlags = 0;
EWRAM_DATA u8 gBattlersCount = 0;
EWRAM_DATA u16 gBattlerPartyIndexes[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gQuashedBattlers = 0;
EWRAM_DATA u8 gAfterYouBattlers = 0;
EWRAM_DATA u8 gBattlerPositions[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gActionsByTurnOrder[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gBattlerByTurnOrder[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gCurrentTurnActionNumber = 0;
EWRAM_DATA u8 gCurrentActionFuncId = 0;
EWRAM_DATA struct BattlePokemon gBattleMons[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gBattlerSpriteIds[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gCurrMovePos = 0;
EWRAM_DATA u8 gChosenMovePos = 0;
EWRAM_DATA u16 gCurrentMove = 0;
EWRAM_DATA u16 gTempMove = 0;
EWRAM_DATA u16 gChosenMove = 0;
EWRAM_DATA u16 gCalledMove = 0;
EWRAM_DATA s32 gBattleMoveDamage = 0;
EWRAM_DATA s32 gHpDealt = 0;
EWRAM_DATA s32 gTakenDmg[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastUsedItem = 0;
EWRAM_DATA u16 gLastUsedAbility = 0;
EWRAM_DATA u8 gBattlerAttacker = 0;
EWRAM_DATA u8 gBattlerTarget = 0;
EWRAM_DATA u8 gBattlerFainted = 0;
EWRAM_DATA u8 gEffectBattler = 0;
EWRAM_DATA u8 gPotentialItemEffectBattler = 0;
EWRAM_DATA u8 gAbsentBattlerFlags = 0;
EWRAM_DATA u8 gIsCriticalHit = FALSE;
EWRAM_DATA bool8 gRetaliationInProgress = FALSE;
EWRAM_DATA const u8 *gBattlescriptCurrInstr = NULL;
EWRAM_DATA u8 gChosenActionByBattler[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA const u8 *gSelectionBattleScripts[MAX_BATTLERS_COUNT] = {NULL};
EWRAM_DATA const u8 *gPalaceSelectionBattleScripts[MAX_BATTLERS_COUNT] = {NULL};
EWRAM_DATA u16 gLastPrintedMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastChosenMove[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastLandedMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastHitByType[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastResultingMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLockedMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastUsedMove = 0;
EWRAM_DATA u8 gLastHitBy[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gChosenMoveByBattler[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gMoveResultFlags = 0;
EWRAM_DATA u32 gHitMarker = 0;
EWRAM_DATA u8 gTakenDmgByBattler[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gUnusedFirstBattleVar2 = 0; // Never read
EWRAM_DATA u32 gSideStatuses[2] = {0};
EWRAM_DATA u8 gFaintedMonCount[2] = {0};
EWRAM_DATA struct SideTimer gSideTimers[2] = {0};
EWRAM_DATA u32 gStatuses3[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u32 gStatuses4[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA struct VolatileStruct gVolatileStructs[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gPauseCounterBattle = 0;
EWRAM_DATA u16 gPaydayMoney = 0;
EWRAM_DATA u16 gRandomTurnNumber = 0;
EWRAM_DATA u8 gBattleCommunication[BATTLE_COMMUNICATION_ENTRIES_COUNT] = {0};
EWRAM_DATA u8 gBattleOutcome = 0;
EWRAM_DATA struct RoundStruct gRoundStructs[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA struct TurnStruct gTurnStructs[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gBattleWeather = 0;
EWRAM_DATA struct WishFutureKnock gWishFutureKnock = {0};
EWRAM_DATA u16 gIntroSlideFlags = 0;
EWRAM_DATA u8 gSentPokesToOpponent[2] = {0};
EWRAM_DATA u16 gExpShareExp = 0;
EWRAM_DATA struct BattleEnigmaBerry gEnigmaBerries[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA struct BattleScripting gBattleScripting = {0};
EWRAM_DATA struct BattleScripting gSavedBattleScripting = {0};
EWRAM_DATA struct BattleStruct *gBattleStruct = NULL;
EWRAM_DATA u8 *gLinkBattleSendBuffer = NULL;
EWRAM_DATA u8 *gLinkBattleRecvBuffer = NULL;
EWRAM_DATA struct BattleResources *gBattleResources = NULL;
EWRAM_DATA u8 gActionSelectionCursor[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gMoveSelectionCursor[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gBattlerStatusSummaryTaskId[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gBattlerInMenuId = 0;
EWRAM_DATA bool8 gDoingBattleAnim = FALSE;
EWRAM_DATA u32 gTransformedPersonalities[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gPlayerDpadHoldFrames = 0;
EWRAM_DATA struct BattleSpriteData *gBattleSpritesDataPtr = NULL;
EWRAM_DATA struct MonSpritesGfx *gMonSpritesGfxPtr = NULL;
EWRAM_DATA struct BattleHealthboxInfo *gBattleControllerOpponentHealthboxData = NULL; // Never read
EWRAM_DATA struct BattleHealthboxInfo *gBattleControllerOpponentFlankHealthboxData = NULL; // Never read
EWRAM_DATA u16 gBattleMovePower = 0;
EWRAM_DATA u16 gMoveToLearn = 0;
EWRAM_DATA u8 gBattleMonForms[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u32 gFieldStatuses = 0;
EWRAM_DATA struct FieldTimer gFieldTimers = {0};
EWRAM_DATA u8 gBattlerAbility = 0;
EWRAM_DATA u16 gPartnerSpriteId = 0;
EWRAM_DATA struct TotemBoost gTotemBoosts[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA bool8 gHasFetchedBall = FALSE;
EWRAM_DATA u8 gLastUsedBall = 0;
EWRAM_DATA u16 gLastThrownBall = 0;
EWRAM_DATA u8 gMaxPartyLevel = 1;
EWRAM_DATA bool8 gSwapDamageCategory = FALSE; // Photon Geyser, Shell Side Arm, Light That Burns the Sky

// IWRAM common vars
void (*gPreBattleCallback1)(void);
void (*gBattleMainFunc)(void);
struct BattleResults gBattleResults;
u8 gLeveledUpInBattle;
void (*gBattlerControllerFuncs[MAX_BATTLERS_COUNT])(void);
u8 gHealthboxSpriteIds[MAX_BATTLERS_COUNT];
u8 gMultiUsePlayerCursor;
u8 gNumberOfMovesToChoose;
u8 gBattleControllerData[MAX_BATTLERS_COUNT]; // Used by the battle controllers to store misc sprite/task IDs for each battler

// rom const data
static const struct ScanlineEffectParams sIntroScanlineParams16Bit =
{
    (void *)REG_ADDR_BG3HOFS, SCANLINE_EFFECT_DMACNT_16BIT, 1
};

// unused
static const struct ScanlineEffectParams sIntroScanlineParams32Bit =
{
    (void *)REG_ADDR_BG3HOFS, SCANLINE_EFFECT_DMACNT_32BIT, 1
};

const struct SpriteTemplate gUnknown_0831AC88 =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8038528,
};

static const u8 sText_ShedinjaJpnName[] = _("ヌケニン"); // Nukenin

const struct OamData gOamData_BattleSpriteOpponentSide =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

const struct OamData gOamData_BattleSpritePlayerSide =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 2,
    .affineParam = 0,
};

static const s8 gUnknown_0831ACE0[] ={-32, -16, -16, -32, -32, 0, 0, 0};

const u8 gTypeNames[NUMBER_OF_MON_TYPES][TYPE_NAME_LENGTH + 1] =
{
    [TYPE_NORMAL] = _("Normal"),
    [TYPE_FIGHTING] = _("Fight"),
    [TYPE_FLYING] = _("Flying"),
    [TYPE_POISON] = _("Poison"),
    [TYPE_GROUND] = _("Ground"),
    [TYPE_ROCK] = _("Rock"),
    [TYPE_BUG] = _("Bug"),
    [TYPE_GHOST] = _("Ghost"),
    [TYPE_STEEL] = _("Steel"),
    [TYPE_MYSTERY] = _("???"),
    [TYPE_FIRE] = _("Fire"),
    [TYPE_WATER] = _("Water"),
    [TYPE_GRASS] = _("Grass"),
    [TYPE_ELECTRIC] = _("Electr"),
    [TYPE_PSYCHIC] = _("Psychc"),
    [TYPE_ICE] = _("Ice"),
    [TYPE_DRAGON] = _("Dragon"),
    [TYPE_DARK] = _("Dark"),
    [TYPE_FAIRY] = _("Fairy"),
};

// This is a factor in how much money you get for beating a trainer.
const struct TrainerMoney gTrainerMoneyTable[] =
{
    {TRAINER_CLASS_PKMN_TRAINER_1, 50},
    {TRAINER_CLASS_TEAM_AQUA, 5},
    {TRAINER_CLASS_AQUA_ADMIN, 10},
    {TRAINER_CLASS_AQUA_LEADER, 20},
    {TRAINER_CLASS_AROMA_LADY, 10},
    {TRAINER_CLASS_RUIN_MANIAC, 15},
    {TRAINER_CLASS_INTERVIEWER, 12},
    {TRAINER_CLASS_TUBER_F, 1},
    {TRAINER_CLASS_TUBER_M, 1},
    {TRAINER_CLASS_SIS_AND_BRO, 3},
    {TRAINER_CLASS_COOLTRAINER, 12},
    {TRAINER_CLASS_HEX_MANIAC, 6},
    {TRAINER_CLASS_LADY, 50},
    {TRAINER_CLASS_BEAUTY, 20},
    {TRAINER_CLASS_RICH_BOY, 50},
    {TRAINER_CLASS_POKEMANIAC, 15},
    {TRAINER_CLASS_SWIMMER_M, 2},
    {TRAINER_CLASS_BLACK_BELT, 8},
    {TRAINER_CLASS_GUITARIST, 8},
    {TRAINER_CLASS_KINDLER, 8},
    {TRAINER_CLASS_CAMPER, 4},
    {TRAINER_CLASS_OLD_COUPLE, 10},
    {TRAINER_CLASS_BUG_MANIAC, 15},
    {TRAINER_CLASS_PSYCHIC, 6},
    {TRAINER_CLASS_GENTLEMAN, 20},
    {TRAINER_CLASS_ELITE_FOUR, 25},
    {TRAINER_CLASS_LEADER, 25},
    {TRAINER_CLASS_SCHOOL_KID, 5},
    {TRAINER_CLASS_SR_AND_JR, 4},
    {TRAINER_CLASS_POKEFAN, 20},
    {TRAINER_CLASS_EXPERT, 10},
    {TRAINER_CLASS_YOUNGSTER, 4},
    {TRAINER_CLASS_CHAMPION, 50},
    {TRAINER_CLASS_FISHERMAN, 10},
    {TRAINER_CLASS_TRIATHLETE, 10},
    {TRAINER_CLASS_DRAGON_TAMER, 12},
    {TRAINER_CLASS_BIRD_KEEPER, 8},
    {TRAINER_CLASS_NINJA_BOY, 3},
    {TRAINER_CLASS_BATTLE_GIRL, 6},
    {TRAINER_CLASS_PARASOL_LADY, 10},
    {TRAINER_CLASS_SWIMMER_F, 2},
    {TRAINER_CLASS_PICNICKER, 4},
    {TRAINER_CLASS_TWINS, 3},
    {TRAINER_CLASS_SAILOR, 8},
    {TRAINER_CLASS_COLLECTOR, 15},
    {TRAINER_CLASS_PKMN_TRAINER_3, 15},
    {TRAINER_CLASS_PKMN_BREEDER, 10},
    {TRAINER_CLASS_PKMN_RANGER, 12},
    {TRAINER_CLASS_TEAM_MAGMA, 5},
    {TRAINER_CLASS_MAGMA_ADMIN, 10},
    {TRAINER_CLASS_MAGMA_LEADER, 20},
    {TRAINER_CLASS_LASS, 4},
    {TRAINER_CLASS_BUG_CATCHER, 4},
    {TRAINER_CLASS_HIKER, 10},
    {TRAINER_CLASS_YOUNG_COUPLE, 8},
    {TRAINER_CLASS_WINSTRATE, 10},
    {TRAINER_CLASS_MAGIKARP_GUY, 20},
    {TRAINER_CLASS_PKMN_TRAINER_4, 30},
    {TRAINER_CLASS_PKMN_TRAINER_5, 50},
    {TRAINER_CLASS_BUFFEL, 45},
    {TRAINER_CLASS_JOHTO_CHAMP, 50},
    {0xFF, 5},
};

// Determines which Poke Ball type is used by each trainer class
const struct TrainerBall gTrainerBallTable[] =
{
    {TRAINER_CLASS_PKMN_TRAINER_1, ITEM_ULTRA_BALL},
    {TRAINER_CLASS_TEAM_AQUA, ITEM_NET_BALL},
    {TRAINER_CLASS_AQUA_ADMIN, ITEM_NET_BALL},
    {TRAINER_CLASS_AQUA_LEADER, ITEM_MASTER_BALL},
    {TRAINER_CLASS_AROMA_LADY, ITEM_FRIEND_BALL},
    {TRAINER_CLASS_RUIN_MANIAC, ITEM_DUSK_BALL},
    {TRAINER_CLASS_INTERVIEWER, ITEM_REPEAT_BALL},
    {TRAINER_CLASS_TUBER_F, ITEM_DIVE_BALL},
    {TRAINER_CLASS_TUBER_M, ITEM_DIVE_BALL},
    {TRAINER_CLASS_SIS_AND_BRO, ITEM_POKE_BALL},
    {TRAINER_CLASS_COOLTRAINER, ITEM_ULTRA_BALL},
    {TRAINER_CLASS_HEX_MANIAC, ITEM_DUSK_BALL},
    {TRAINER_CLASS_LADY, ITEM_LUXURY_BALL},
    {TRAINER_CLASS_BEAUTY, ITEM_LOVE_BALL},
    {TRAINER_CLASS_RICH_BOY, ITEM_LUXURY_BALL},
    {TRAINER_CLASS_POKEMANIAC, ITEM_MOON_BALL},
    {TRAINER_CLASS_SWIMMER_M, ITEM_DIVE_BALL},
    {TRAINER_CLASS_BLACK_BELT, ITEM_HEAVY_BALL},
    {TRAINER_CLASS_GUITARIST, ITEM_FAST_BALL},
    {TRAINER_CLASS_KINDLER, ITEM_POKE_BALL},
    {TRAINER_CLASS_CAMPER, ITEM_NEST_BALL},
    {TRAINER_CLASS_OLD_COUPLE, ITEM_TIMER_BALL},
    {TRAINER_CLASS_BUG_MANIAC, ITEM_NET_BALL},
    {TRAINER_CLASS_PSYCHIC, ITEM_DREAM_BALL},
    {TRAINER_CLASS_GENTLEMAN, ITEM_LUXURY_BALL},
    {TRAINER_CLASS_ELITE_FOUR, ITEM_ULTRA_BALL},
    {TRAINER_CLASS_LEADER, ITEM_ULTRA_BALL},
    {TRAINER_CLASS_SCHOOL_KID, ITEM_POKE_BALL},
    {TRAINER_CLASS_SR_AND_JR, ITEM_POKE_BALL},
    {TRAINER_CLASS_POKEFAN, ITEM_POKE_BALL},
    {TRAINER_CLASS_EXPERT, ITEM_ULTRA_BALL},
    {TRAINER_CLASS_YOUNGSTER, ITEM_POKE_BALL},
    {TRAINER_CLASS_CHAMPION, ITEM_CHERISH_BALL},
    {TRAINER_CLASS_FISHERMAN, ITEM_LURE_BALL},
    {TRAINER_CLASS_TRIATHLETE, ITEM_FAST_BALL},
    {TRAINER_CLASS_DRAGON_TAMER, ITEM_ULTRA_BALL},
    {TRAINER_CLASS_BIRD_KEEPER, ITEM_QUICK_BALL},
    {TRAINER_CLASS_NINJA_BOY, ITEM_QUICK_BALL},
    {TRAINER_CLASS_BATTLE_GIRL, ITEM_HEAVY_BALL},
    {TRAINER_CLASS_PARASOL_LADY, ITEM_POKE_BALL},
    {TRAINER_CLASS_SWIMMER_F, ITEM_DIVE_BALL},
    {TRAINER_CLASS_PICNICKER, ITEM_FRIEND_BALL},
    {TRAINER_CLASS_TWINS, ITEM_POKE_BALL},
    {TRAINER_CLASS_SAILOR, ITEM_DIVE_BALL},
    {TRAINER_CLASS_COLLECTOR, ITEM_REPEAT_BALL},
    {TRAINER_CLASS_PKMN_TRAINER_3, ITEM_PREMIER_BALL},
    {TRAINER_CLASS_PKMN_BREEDER, ITEM_FRIEND_BALL},
    {TRAINER_CLASS_PKMN_RANGER, ITEM_SAFARI_BALL},
    {TRAINER_CLASS_TEAM_MAGMA, ITEM_NEST_BALL},
    {TRAINER_CLASS_MAGMA_ADMIN, ITEM_NEST_BALL},
    {TRAINER_CLASS_MAGMA_LEADER, ITEM_MASTER_BALL},
    {TRAINER_CLASS_LASS, ITEM_POKE_BALL},
    {TRAINER_CLASS_BUG_CATCHER, ITEM_NET_BALL},
    {TRAINER_CLASS_HIKER, ITEM_HEAVY_BALL},
    {TRAINER_CLASS_YOUNG_COUPLE, ITEM_LOVE_BALL},
    {TRAINER_CLASS_WINSTRATE, ITEM_GREAT_BALL},
    {TRAINER_CLASS_PKMN_TRAINER_2, ITEM_HEAVY_BALL},
    {TRAINER_CLASS_MAGIKARP_GUY, ITEM_LOVE_BALL},
    {TRAINER_CLASS_PKMN_TRAINER_4, ITEM_CHERISH_BALL},
    {TRAINER_CLASS_PKMN_TRAINER_5, ITEM_HEAVY_BALL},
    {TRAINER_CLASS_BUFFEL, ITEM_CHERISH_BALL},
    {TRAINER_CLASS_JOHTO_CHAMP, ITEM_ULTRA_BALL},
    {0xFF, ITEM_POKE_BALL},
};

#include "data/text/abilities.h"

static void (* const sTurnActionsFuncsTable[])(void) =
{
    [B_ACTION_USE_MOVE] = HandleAction_UseMove,
    [B_ACTION_USE_ITEM] = HandleAction_UseItem,
    [B_ACTION_SWITCH] = HandleAction_Switch,
    [B_ACTION_RUN] = HandleAction_Run,
    [B_ACTION_SAFARI_WATCH_CAREFULLY] = HandleAction_WatchesCarefully,
    [B_ACTION_SAFARI_BALL] = HandleAction_SafariZoneBallThrow,
    [B_ACTION_SAFARI_POKEBLOCK] = HandleAction_ThrowPokeblock,
    [B_ACTION_SAFARI_GO_NEAR] = HandleAction_GoNear,
    [B_ACTION_SAFARI_RUN] = HandleAction_SafariZoneRun,
    [B_ACTION_WALLY_THROW] = HandleAction_WallyBallThrow,
    [B_ACTION_EXEC_SCRIPT] = HandleAction_RunBattleScript,
    [B_ACTION_TRY_FINISH] = HandleAction_TryFinish,
    [B_ACTION_FINISHED] = HandleAction_ActionFinished,
    [B_ACTION_NOTHING_FAINTED] = HandleAction_NothingIsFainted,
    [B_ACTION_THROW_BALL] = HandleAction_ThrowBall,
};

static void (* const sEndTurnFuncsTable[])(void) =
{
    [0] = HandleEndTurn_ContinueBattle, //B_OUTCOME_NONE?
    [B_OUTCOME_WON] = HandleEndTurn_BattleWon,
    [B_OUTCOME_LOST] = HandleEndTurn_BattleLost,
    [B_OUTCOME_DREW] = HandleEndTurn_BattleLost,
    [B_OUTCOME_RAN] = HandleEndTurn_RanFromBattle,
    [B_OUTCOME_PLAYER_TELEPORTED] = HandleEndTurn_FinishBattle,
    [B_OUTCOME_MON_FLED] = HandleEndTurn_MonFled,
    [B_OUTCOME_CAUGHT] = HandleEndTurn_FinishBattle,
    [B_OUTCOME_NO_SAFARI_BALLS] = HandleEndTurn_FinishBattle,
    [B_OUTCOME_FORFEITED] = HandleEndTurn_FinishBattle,
    [B_OUTCOME_MON_TELEPORTED] = HandleEndTurn_FinishBattle,
};

const u8 gStatusConditionString_PoisonJpn[8] = _("どく$$$$$");
const u8 gStatusConditionString_SleepJpn[8] = _("ねむり$$$$");
const u8 gStatusConditionString_ParalysisJpn[8] = _("まひ$$$$$");
const u8 gStatusConditionString_BurnJpn[8] = _("やけど$$$$");
const u8 gStatusConditionString_IceJpn[8] = _("こおり$$$$");
const u8 gStatusConditionString_ConfusionJpn[8] = _("こんらん$$$");
const u8 gStatusConditionString_LoveJpn[8] = _("メロメロ$$$");
const u8 gStatusConditionString_BleedJpn[8] = _("わからん$$$");

const u8 * const gStatusConditionStringsTable[8][2] =
{
    {gStatusConditionString_PoisonJpn, gText_Poison},
    {gStatusConditionString_SleepJpn, gText_Sleep},
    {gStatusConditionString_ParalysisJpn, gText_Paralysis},
    {gStatusConditionString_BurnJpn, gText_Burn},
    {gStatusConditionString_IceJpn, gText_Ice},
    {gStatusConditionString_ConfusionJpn, gText_Confusion},
    {gStatusConditionString_LoveJpn, gText_Love},
    {gStatusConditionString_BleedJpn, gText_Bleed},
};

// code
void CB2_InitBattle(void)
{
    MoveSaveBlocks_ResetHeap();
    AllocateBattleResources();
    AllocateBattleSpritesData();
    AllocateMonSpritesGfx();
    RecordedBattle_ClearFrontierPassFlag();

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            CB2_InitBattleInternal();
        }
        else if (!(gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER))
        {
            HandleLinkBattleSetup();
            SetMainCallback2(CB2_PreInitMultiBattle);
        }
        else
        {
            SetMainCallback2(CB2_PreInitIngamePlayerPartnerBattle);
        }
        gBattleCommunication[MULTIUSE_STATE] = 0;
    }
    else
    {
        CB2_InitBattleInternal();
    }
}

static void CB2_InitBattleInternal(void)
{
    s32 i;

    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);

    CpuFill32(0, (void*)(VRAM), VRAM_SIZE);

    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuReg(REG_OFFSET_WIN0H, DISPLAY_WIDTH);
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(DISPLAY_HEIGHT / 2, DISPLAY_HEIGHT / 2 + 1));
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);

    gBattle_WIN0H = DISPLAY_WIDTH;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gPartnerTrainerId != TRAINER_STEVEN_PARTNER && gPartnerTrainerId < TRAINER_CUSTOM_PARTNER)
    {
        gBattle_WIN0V = DISPLAY_HEIGHT - 1;
        gBattle_WIN1H = DISPLAY_WIDTH;
        gBattle_WIN1V = 32;
    }
    else
    {
        gBattle_WIN0V = WIN_RANGE(DISPLAY_HEIGHT / 2, DISPLAY_HEIGHT / 2 + 1);
        ScanlineEffect_Clear();

        i = 0;
        while (i < 80)
        {
            gScanlineEffectRegBuffers[0][i] = 0xF0;
            gScanlineEffectRegBuffers[1][i] = 0xF0;
            i++;
        }

        while (i < 160)
        {
            gScanlineEffectRegBuffers[0][i] = 0xFF10;
            gScanlineEffectRegBuffers[1][i] = 0xFF10;
            i++;
        }

        ScanlineEffect_SetParams(sIntroScanlineParams16Bit);
    }

    ResetPaletteFade();
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    gBattle_BG2_Y = 0;
    gBattle_BG3_X = 0;
    gBattle_BG3_Y = 0;

	#if B_ENABLE_DEBUG == FALSE
		gBattleTerrain = BattleSetup_GetTerrainId();
	#else
    if (!gIsDebugBattle)
        gBattleTerrain = BattleSetup_GetTerrainId();
	#endif
    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        gBattleTerrain = BATTLE_TERRAIN_BUILDING;

    InitBattleBgsVideo();
    LoadBattleTextboxAndBackground();
    ResetSpriteData();
    ResetTasks();
    DrawBattleEntryBackground();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 4;
    SetVBlankCallback(VBlankCB_Battle);
    SetUpBattleVarsAndBirchZigzagoon();

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
        SetMainCallback2(CB2_HandleStartMultiPartnerBattle);
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        SetMainCallback2(CB2_HandleStartMultiPartnerBattle);
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        SetMainCallback2(CB2_HandleStartMultiBattle);
    else
        SetMainCallback2(CB2_HandleStartBattle);


	#if B_ENABLE_DEBUG == FALSE 
		if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED)))
		{
			CreateNPCTrainerParty(&gEnemyParty[0], gTrainerBattleOpponent_A, TRUE);
			if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && !BATTLE_TWO_VS_ONE_OPPONENT)
				CreateNPCTrainerParty(&gEnemyParty[3], gTrainerBattleOpponent_B, FALSE);
			SetWildMonHeldItem();
		}
	#else
		if (!gIsDebugBattle)
		{
			if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED)))
			{
				CreateNPCTrainerParty(&gEnemyParty[0], gTrainerBattleOpponent_A, TRUE);
				if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
					CreateNPCTrainerParty(&gEnemyParty[PARTY_SIZE / 2], gTrainerBattleOpponent_B, FALSE);
				SetWildMonHeldItem();
			}
		}
	#endif

    gMain.inBattle = TRUE;
    gSaveBlock2Ptr->frontier.disableRecordBattle = FALSE;

    for (i = 0; i < PARTY_SIZE; i++)
        AdjustFriendship(&gPlayerParty[i], FRIENDSHIP_EVENT_LEAGUE_BATTLE);

    gBattleCommunication[MULTIUSE_STATE] = 0;
}

#define BUFFER_PARTY_VS_SCREEN_STATUS(party, flags, i)              \
    for ((i) = 0; (i) < PARTY_SIZE; (i)++)                          \
    {                                                               \
        u16 species = GetMonData(&(party)[(i)], MON_DATA_SPECIES2); \
        u16 hp = GetMonData(&(party)[(i)], MON_DATA_HP);            \
        u32 status = GetMonData(&(party)[(i)], MON_DATA_STATUS);    \
                                                                    \
        if (species == SPECIES_NONE)                                \
            continue;                                               \
                                                                    \
        /* Is healthy mon? */                                       \
        if (species != SPECIES_EGG && hp != 0 && status == 0)       \
            (flags) |= 1 << (i) * 2;                                \
                                                                    \
        if (species == SPECIES_NONE) /* Redundant */                \
            continue;                                               \
                                                                    \
        /* Is Egg or statused? */                                   \
        if (hp != 0 && (species == SPECIES_EGG || status != 0))     \
            (flags) |= 2 << (i) * 2;                                \
                                                                    \
        if (species == SPECIES_NONE) /* Redundant */                \
            continue;                                               \
                                                                    \
        /* Is fainted? */                                           \
        if (species != SPECIES_EGG && hp == 0)                      \
            (flags) |= 3 << (i) * 2;                                \
    }

// For Vs Screen at link battle start
static void BufferPartyVsScreenHealth_AtStart(void)
{
    u16 flags = 0;
    s32 i;

    BUFFER_PARTY_VS_SCREEN_STATUS(gPlayerParty, flags, i);
    gBattleStruct->multiBuffer.linkBattlerHeader.vsScreenHealthFlagsLo = flags;
    *(&gBattleStruct->multiBuffer.linkBattlerHeader.vsScreenHealthFlagsHi) = flags >> 8;
    gBattleStruct->multiBuffer.linkBattlerHeader.vsScreenHealthFlagsHi |= FlagGet(FLAG_SYS_FRONTIER_PASS) << 7;
}

static void SetPlayerBerryDataInBattleStruct(void)
{
    s32 i;
    struct BattleStruct *battleStruct = gBattleStruct;
    struct BattleEnigmaBerry *battleBerry = &battleStruct->multiBuffer.linkBattlerHeader.battleEnigmaBerry;

    if (IsEnigmaBerryValid() == TRUE)
    {
        #ifndef FREE_ENIGMA_BERRY
        for (i = 0; i < BERRY_NAME_LENGTH; i++)
            battleBerry->name[i] = gSaveBlock1Ptr->enigmaBerry.berry.name[i];
        battleBerry->name[i] = EOS;

        for (i = 0; i < BERRY_ITEM_EFFECT_COUNT; i++)
            battleBerry->itemEffect[i] = gSaveBlock1Ptr->enigmaBerry.itemEffect[i];

        #ifndef FREE_ENIGMA_BERRY
        battleBerry->holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
        #else
        battleBerry->holdEffect = 0;
        #endif
        battleBerry->holdEffectParam = gSaveBlock1Ptr->enigmaBerry.holdEffectParam;
        #endif
    }
    else
    {
        const struct Berry *berryData = GetBerryInfo(ItemIdToBerryType(ITEM_ENIGMA_BERRY));

        for (i = 0; i < BERRY_NAME_LENGTH; i++)
            battleBerry->name[i] = berryData->name[i];
        battleBerry->name[i] = EOS;

        for (i = 0; i < BERRY_ITEM_EFFECT_COUNT; i++)
            battleBerry->itemEffect[i] = 0;

        battleBerry->holdEffect = HOLD_EFFECT_NONE;
        battleBerry->holdEffectParam = 0;
    }
}

static void SetAllPlayersBerryData(void)
{
    s32 i;
    s32 j;

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        if (IsEnigmaBerryValid() == TRUE)
        {
            #ifndef FREE_ENIGMA_BERRY
            for (i = 0; i < BERRY_NAME_LENGTH; i++)
            {
                gEnigmaBerries[0].name[i] = gSaveBlock1Ptr->enigmaBerry.berry.name[i];
                gEnigmaBerries[2].name[i] = gSaveBlock1Ptr->enigmaBerry.berry.name[i];
            }
            gEnigmaBerries[0].name[i] = EOS;
            gEnigmaBerries[2].name[i] = EOS;

            for (i = 0; i < BERRY_ITEM_EFFECT_COUNT; i++)
            {
                gEnigmaBerries[0].itemEffect[i] = gSaveBlock1Ptr->enigmaBerry.itemEffect[i];
                gEnigmaBerries[2].itemEffect[i] = gSaveBlock1Ptr->enigmaBerry.itemEffect[i];
            }

            gEnigmaBerries[0].holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
            gEnigmaBerries[2].holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
            gEnigmaBerries[0].holdEffectParam = gSaveBlock1Ptr->enigmaBerry.holdEffectParam;
            gEnigmaBerries[2].holdEffectParam = gSaveBlock1Ptr->enigmaBerry.holdEffectParam;
            #endif
        }
        else
        {
            const struct Berry *berryData = GetBerryInfo(ItemIdToBerryType(ITEM_ENIGMA_BERRY));

            for (i = 0; i < BERRY_NAME_LENGTH; i++)
            {
                gEnigmaBerries[0].name[i] = berryData->name[i];
                gEnigmaBerries[2].name[i] = berryData->name[i];
            }
            gEnigmaBerries[0].name[i] = EOS;
            gEnigmaBerries[2].name[i] = EOS;

            for (i = 0; i < BERRY_ITEM_EFFECT_COUNT; i++)
            {
                gEnigmaBerries[0].itemEffect[i] = 0;
                gEnigmaBerries[2].itemEffect[i] = 0;
            }

            gEnigmaBerries[0].holdEffect = 0;
            gEnigmaBerries[2].holdEffect = 0;
            gEnigmaBerries[0].holdEffectParam = 0;
            gEnigmaBerries[2].holdEffectParam = 0;
        }
    }
    else
    {
        s32 numPlayers;
        struct BattleEnigmaBerry *src;
        u8 battlerId;

        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
                numPlayers = 2;
            else
                numPlayers = 4;

            for (i = 0; i < numPlayers; i++)
            {
                src = (struct BattleEnigmaBerry *)(gBlockRecvBuffer[i] + 2);
                battlerId = gLinkPlayers[i].id;

                for (j = 0; j < BERRY_NAME_LENGTH; j++)
                    gEnigmaBerries[battlerId].name[j] = src->name[j];
                gEnigmaBerries[battlerId].name[j] = EOS;

                for (j = 0; j < BERRY_ITEM_EFFECT_COUNT; j++)
                    gEnigmaBerries[battlerId].itemEffect[j] = src->itemEffect[j];

                gEnigmaBerries[battlerId].holdEffect = src->holdEffect;
                gEnigmaBerries[battlerId].holdEffectParam = src->holdEffectParam;
            }
        }
        else
        {
            for (i = 0; i < 2; i++)
            {
                src = (struct BattleEnigmaBerry *)(gBlockRecvBuffer[i] + 2);

                for (j = 0; j < BERRY_NAME_LENGTH; j++)
                {
                    gEnigmaBerries[i].name[j] = src->name[j];
                    gEnigmaBerries[i + 2].name[j] = src->name[j];
                }
                gEnigmaBerries[i].name[j] = EOS;
                gEnigmaBerries[i + 2].name[j] = EOS;

                for (j = 0; j < BERRY_ITEM_EFFECT_COUNT; j++)
                {
                    gEnigmaBerries[i].itemEffect[j] = src->itemEffect[j];
                    gEnigmaBerries[i + 2].itemEffect[j] = src->itemEffect[j];
                }

                gEnigmaBerries[i].holdEffect = src->holdEffect;
                gEnigmaBerries[i + 2].holdEffect = src->holdEffect;
                gEnigmaBerries[i].holdEffectParam = src->holdEffectParam;
                gEnigmaBerries[i + 2].holdEffectParam = src->holdEffectParam;
            }
        }
    }
}

// This was inlined in Ruby/Sapphire
static void FindLinkBattleMaster(u8 numPlayers, u8 multiPlayerId)
{
    u8 found = 0;

    // If player 1 is playing the minimum version, player 1 is master.
    if (gBlockRecvBuffer[0][0] == 0x100)
    {
        if (multiPlayerId == 0)
            gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER;
        else
            gBattleTypeFlags |= BATTLE_TYPE_TRAINER;
        found++;
    }

    if (found == 0)
    {
        // If multiple different versions are being used, player 1 is master.
        s32 i;

        for (i = 0; i < numPlayers; i++)
        {
            if (gBlockRecvBuffer[0][0] != gBlockRecvBuffer[i][0])
                break;
        }

        if (i == numPlayers)
        {
            if (multiPlayerId == 0)
                gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER;
            else
                gBattleTypeFlags |= BATTLE_TYPE_TRAINER;
            found++;
        }

        if (found == 0)
        {
            // Lowest index player with the highest game version is master.
            for (i = 0; i < numPlayers; i++)
            {
                if (gBlockRecvBuffer[i][0] == 0x300 && i != multiPlayerId)
                {
                    if (i < multiPlayerId)
                        break;
                }
                if (gBlockRecvBuffer[i][0] > 0x300 && i != multiPlayerId)
                    break;
            }

            if (i == numPlayers)
                gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER;
            else
                gBattleTypeFlags |= BATTLE_TYPE_TRAINER;
        }
    }
}

static void CB2_HandleStartBattle(void)
{
    u8 playerMultiplayerId;
    u8 enemyMultiplayerId;

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();

    playerMultiplayerId = GetMultiplayerId();
    gBattleScripting.multiplayerId = playerMultiplayerId;
    enemyMultiplayerId = playerMultiplayerId ^ BIT_SIDE;
    if(!FlagGet(FLAG_SYS_DISABLE_AUTOHEAL))
        HealPlayerParty();

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            sub_805EF14();
            gBattleCommunication[MULTIUSE_STATE] = 1;
        }
        if (gWirelessCommType)
            LoadWirelessStatusIndicatorSpriteGfx();
        break;
    case 1:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (gReceivedRemoteLinkPlayers != 0)
            {
                if (IsLinkTaskFinished())
                {
                    // 0x300
                    *(&gBattleStruct->multiBuffer.linkBattlerHeader.versionSignatureLo) = 0;
                    *(&gBattleStruct->multiBuffer.linkBattlerHeader.versionSignatureHi) = 3;
                    BufferPartyVsScreenHealth_AtStart();
                    SetPlayerBerryDataInBattleStruct();

                    if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                    {
                        gLinkPlayers[0].id = 0;
                        gLinkPlayers[1].id = 1;
                    }

                    SendBlock(bitmask_all_link_players_but_self(), &gBattleStruct->multiBuffer.linkBattlerHeader, sizeof(gBattleStruct->multiBuffer.linkBattlerHeader));
                    gBattleCommunication[MULTIUSE_STATE] = 2;
                }
                if (gWirelessCommType)
                    CreateWirelessStatusIndicatorSprite(0, 0);
            }
        }
        else
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
                gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER;
            gBattleCommunication[MULTIUSE_STATE] = 15;
            SetAllPlayersBerryData();
        }
        break;
    case 2:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            u8 taskId;

            ResetBlockReceivedFlags();
            FindLinkBattleMaster(2, playerMultiplayerId);
            SetAllPlayersBerryData();
            taskId = CreateTask(InitLinkBattleVsScreen, 0);
            gTasks[taskId].data[1] = 0x10E;
            gTasks[taskId].data[2] = 0x5A;
            gTasks[taskId].data[5] = 0;
            gTasks[taskId].data[3] = gBattleStruct->multiBuffer.linkBattlerHeader.vsScreenHealthFlagsLo | (gBattleStruct->multiBuffer.linkBattlerHeader.vsScreenHealthFlagsHi << 8);
            gTasks[taskId].data[4] = gBlockRecvBuffer[enemyMultiplayerId][1];
            RecordedBattle_SetFrontierPassFlagFromHword(gBlockRecvBuffer[playerMultiplayerId][1]);
            RecordedBattle_SetFrontierPassFlagFromHword(gBlockRecvBuffer[enemyMultiplayerId][1]);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 3:
        if (IsLinkTaskFinished())
        {
            SendBlock(bitmask_all_link_players_but_self(), gPlayerParty, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 4:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            memcpy(gEnemyParty, gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 7:
        if (IsLinkTaskFinished())
        {
            SendBlock(bitmask_all_link_players_but_self(), gPlayerParty + 2, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 8:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            memcpy(gEnemyParty + 2, gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 11:
        if (IsLinkTaskFinished())
        {
            SendBlock(bitmask_all_link_players_but_self(), gPlayerParty + 4, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 12:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            memcpy(gEnemyParty + 4, gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon) * 2);
            TryCorrectShedinjaLanguage(&gEnemyParty[0]);
            TryCorrectShedinjaLanguage(&gEnemyParty[1]);
            TryCorrectShedinjaLanguage(&gEnemyParty[2]);
            TryCorrectShedinjaLanguage(&gEnemyParty[3]);
            TryCorrectShedinjaLanguage(&gEnemyParty[4]);
            TryCorrectShedinjaLanguage(&gEnemyParty[5]);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 15:
        InitBattleControllers();
        sub_8184E58();
        gBattleCommunication[SPRITES_INIT_STATE1] = 0;
        gBattleCommunication[SPRITES_INIT_STATE2] = 0;
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            s32 i;

            for (i = 0; i < 2 && (gLinkPlayers[i].version & 0xFF) == VERSION_EMERALD; i++);

            if (i == 2)
                gBattleCommunication[MULTIUSE_STATE] = 16;
            else
                gBattleCommunication[MULTIUSE_STATE] = 18;
        }
        else
        {
            gBattleCommunication[MULTIUSE_STATE] = 18;
        }
        break;
    case 16:
        if (IsLinkTaskFinished())
        {
            SendBlock(bitmask_all_link_players_but_self(), &gRecordedBattleRngSeed, sizeof(gRecordedBattleRngSeed));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 17:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (!(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER))
                memcpy(&gRecordedBattleRngSeed, gBlockRecvBuffer[enemyMultiplayerId], sizeof(gRecordedBattleRngSeed));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 18:
        if (BattleInitAllSprites(&gBattleCommunication[SPRITES_INIT_STATE1], &gBattleCommunication[SPRITES_INIT_STATE2]))
        {
            gPreBattleCallback1 = gMain.callback1;
            gMain.callback1 = BattleMainCB1;
            SetMainCallback2(BattleMainCB2);
            if (gBattleTypeFlags & BATTLE_TYPE_LINK)
            {
                gBattleTypeFlags |= BATTLE_TYPE_LINK_IN_BATTLE;
            }
        }
        break;
    case 5:
    case 9:
    case 13:
        gBattleCommunication[MULTIUSE_STATE]++;
        gBattleCommunication[1] = 1;
    case 6:
    case 10:
    case 14:
        if (--gBattleCommunication[1] == 0)
            gBattleCommunication[MULTIUSE_STATE]++;
        break;
    }
}

static void CB2_HandleStartMultiPartnerBattle(void)
{
    u8 playerMultiplayerId;
    u8 enemyMultiplayerId;

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();

    playerMultiplayerId = GetMultiplayerId();
    gBattleScripting.multiplayerId = playerMultiplayerId;
    enemyMultiplayerId = playerMultiplayerId ^ BIT_SIDE;

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            sub_805EF14();
            gBattleCommunication[MULTIUSE_STATE] = 1;
        }
        if (gWirelessCommType)
            LoadWirelessStatusIndicatorSpriteGfx();
        // fall through
    case 1:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (gReceivedRemoteLinkPlayers != 0)
            {
                u8 language;

                gLinkPlayers[0].id = 0;
                gLinkPlayers[1].id = 2;
                gLinkPlayers[2].id = 1;
                gLinkPlayers[3].id = 3;
                GetFrontierTrainerName(gLinkPlayers[2].name, gTrainerBattleOpponent_A);
                GetFrontierTrainerName(gLinkPlayers[3].name, gTrainerBattleOpponent_B);
                GetBattleTowerTrainerLanguage(&language, gTrainerBattleOpponent_A);
                gLinkPlayers[2].language = language;
                GetBattleTowerTrainerLanguage(&language, gTrainerBattleOpponent_B);
                gLinkPlayers[3].language = language;

                if (IsLinkTaskFinished())
                {
                    // 0x300
                    *(&gBattleStruct->multiBuffer.linkBattlerHeader.versionSignatureLo) = 0;
                    *(&gBattleStruct->multiBuffer.linkBattlerHeader.versionSignatureHi) = 3;
                    BufferPartyVsScreenHealth_AtStart();
                    SetPlayerBerryDataInBattleStruct();
                    SendBlock(bitmask_all_link_players_but_self(), &gBattleStruct->multiBuffer.linkBattlerHeader, sizeof(gBattleStruct->multiBuffer.linkBattlerHeader));
                    gBattleCommunication[MULTIUSE_STATE] = 2;
                }

                if (gWirelessCommType)
                    CreateWirelessStatusIndicatorSprite(0, 0);
            }
        }
        else
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
                gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER;
            gBattleCommunication[MULTIUSE_STATE] = 13;
            SetAllPlayersBerryData();
        }
        break;
    case 2:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            u8 taskId;

            ResetBlockReceivedFlags();
            FindLinkBattleMaster(2, playerMultiplayerId);
            SetAllPlayersBerryData();
            taskId = CreateTask(InitLinkBattleVsScreen, 0);
            gTasks[taskId].data[1] = 0x10E;
            gTasks[taskId].data[2] = 0x5A;
            gTasks[taskId].data[5] = 0;
            gTasks[taskId].data[3] = 0x145;
            gTasks[taskId].data[4] = 0x145;
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 3:
        if (IsLinkTaskFinished())
        {
            SendBlock(bitmask_all_link_players_but_self(), gPlayerParty, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 4:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (gLinkPlayers[playerMultiplayerId].id != 0)
            {
                memcpy(gPlayerParty, gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon) * 2);
                memcpy(gPlayerParty + MULTI_PARTY_SIZE, gBlockRecvBuffer[playerMultiplayerId], sizeof(struct Pokemon) * 2);
            }
            else
            {
                memcpy(gPlayerParty, gBlockRecvBuffer[playerMultiplayerId], sizeof(struct Pokemon) * 2);
                memcpy(gPlayerParty + MULTI_PARTY_SIZE, gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon) * 2);
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 5:
        if (IsLinkTaskFinished())
        {
            SendBlock(bitmask_all_link_players_but_self(), gPlayerParty + 2, sizeof(struct Pokemon));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 6:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (gLinkPlayers[playerMultiplayerId].id != 0)
            {
                memcpy(gPlayerParty + 2, gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon));
                memcpy(gPlayerParty + 5, gBlockRecvBuffer[playerMultiplayerId], sizeof(struct Pokemon));
            }
            else
            {
                memcpy(gPlayerParty + 2, gBlockRecvBuffer[playerMultiplayerId], sizeof(struct Pokemon));
                memcpy(gPlayerParty + 5, gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon));
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 7:
        if (IsLinkTaskFinished())
        {
            SendBlock(bitmask_all_link_players_but_self(), gEnemyParty, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 8:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (GetMultiplayerId() != 0)
            {
                memcpy(gEnemyParty, gBlockRecvBuffer[0], sizeof(struct Pokemon) * 2);
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 9:
        if (IsLinkTaskFinished())
        {
            SendBlock(bitmask_all_link_players_but_self(), gEnemyParty + 2, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 10:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (GetMultiplayerId() != 0)
            {
                memcpy(gEnemyParty + 2, gBlockRecvBuffer[0], sizeof(struct Pokemon) * 2);
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 11:
        if (IsLinkTaskFinished())
        {
            SendBlock(bitmask_all_link_players_but_self(), gEnemyParty + 4, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 12:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (GetMultiplayerId() != 0)
                memcpy(gEnemyParty + 4, gBlockRecvBuffer[0], sizeof(struct Pokemon) * 2);
            TryCorrectShedinjaLanguage(&gPlayerParty[0]);
            TryCorrectShedinjaLanguage(&gPlayerParty[1]);
            TryCorrectShedinjaLanguage(&gPlayerParty[2]);
            TryCorrectShedinjaLanguage(&gPlayerParty[3]);
            TryCorrectShedinjaLanguage(&gPlayerParty[4]);
            TryCorrectShedinjaLanguage(&gPlayerParty[5]);
            TryCorrectShedinjaLanguage(&gEnemyParty[0]);
            TryCorrectShedinjaLanguage(&gEnemyParty[1]);
            TryCorrectShedinjaLanguage(&gEnemyParty[2]);
            TryCorrectShedinjaLanguage(&gEnemyParty[3]);
            TryCorrectShedinjaLanguage(&gEnemyParty[4]);
            TryCorrectShedinjaLanguage(&gEnemyParty[5]);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 13:
        InitBattleControllers();
        sub_8184E58();
        gBattleCommunication[SPRITES_INIT_STATE1] = 0;
        gBattleCommunication[SPRITES_INIT_STATE2] = 0;
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            gBattleCommunication[MULTIUSE_STATE] = 14;
        }
        else
        {
            gBattleCommunication[MULTIUSE_STATE] = 16;
        }
        break;
    case 14:
        if (IsLinkTaskFinished())
        {
            SendBlock(bitmask_all_link_players_but_self(), &gRecordedBattleRngSeed, sizeof(gRecordedBattleRngSeed));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 15:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (!(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER))
                memcpy(&gRecordedBattleRngSeed, gBlockRecvBuffer[enemyMultiplayerId], sizeof(gRecordedBattleRngSeed));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 16:
        if (BattleInitAllSprites(&gBattleCommunication[SPRITES_INIT_STATE1], &gBattleCommunication[SPRITES_INIT_STATE2]))
        {
            TrySetLinkBattleTowerEnemyPartyLevel();
            gPreBattleCallback1 = gMain.callback1;
            gMain.callback1 = BattleMainCB1;
            SetMainCallback2(BattleMainCB2);
            if (gBattleTypeFlags & BATTLE_TYPE_LINK)
            {
                gBattleTypeFlags |= BATTLE_TYPE_LINK_IN_BATTLE;
            }
        }
        break;
    }
}

static void sub_80379F8(u8 arrayIdPlus)
{
    s32 i;

    for (i = 0; i < (int)ARRAY_COUNT(gMultiPartnerParty); i++)
    {
        gMultiPartnerParty[i].species     = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_SPECIES);
        gMultiPartnerParty[i].heldItem    = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_HELD_ITEM);
        GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_NICKNAME, gMultiPartnerParty[i].nickname);
        gMultiPartnerParty[i].level       = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_LEVEL);
        gMultiPartnerParty[i].hp          = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_HP);
        gMultiPartnerParty[i].maxhp       = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_MAX_HP);
        gMultiPartnerParty[i].status      = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_STATUS);
        gMultiPartnerParty[i].personality = GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_PERSONALITY);
        gMultiPartnerParty[i].gender      = GetMonGender(&gPlayerParty[arrayIdPlus + i]);
        StripExtCtrlCodes(gMultiPartnerParty[i].nickname);
        if (GetMonData(&gPlayerParty[arrayIdPlus + i], MON_DATA_LANGUAGE) != LANGUAGE_JAPANESE)
            PadNameString(gMultiPartnerParty[i].nickname, CHAR_SPACE);
    }
    memcpy(sMultiPartnerPartyBuffer, gMultiPartnerParty, sizeof(gMultiPartnerParty));
}

static void CB2_PreInitMultiBattle(void)
{
    s32 i;
    u8 playerMultiplierId;
    s32 numPlayers = 4;
    u8 r4 = 0xF;
    u32 *savedBattleTypeFlags;
    void (**savedCallback)(void);

    if (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
    {
        numPlayers = 2;
        r4 = 3;
    }

    playerMultiplierId = GetMultiplayerId();
    gBattleScripting.multiplayerId = playerMultiplierId;
    savedCallback = &gBattleStruct->savedCallback;
    savedBattleTypeFlags = &gBattleStruct->savedBattleTypeFlags;

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        if (gReceivedRemoteLinkPlayers != 0 && IsLinkTaskFinished())
        {
            sMultiPartnerPartyBuffer = Alloc(sizeof(struct UnknownPokemonStruct4) * ARRAY_COUNT(gMultiPartnerParty));
            sub_80379F8(0);
            SendBlock(bitmask_all_link_players_but_self(), sMultiPartnerPartyBuffer, sizeof(struct UnknownPokemonStruct4) * ARRAY_COUNT(gMultiPartnerParty));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 1:
        if ((GetBlockReceivedStatus() & r4) == r4)
        {
            ResetBlockReceivedFlags();
            for (i = 0; i < numPlayers; i++)
            {
                if (i == playerMultiplierId)
                    continue;

                if (numPlayers == MAX_LINK_PLAYERS)
                {
                    if ((!(gLinkPlayers[i].id & 1) && !(gLinkPlayers[playerMultiplierId].id & 1))
                        || (gLinkPlayers[i].id & 1 && gLinkPlayers[playerMultiplierId].id & 1))
                    {
                        memcpy(gMultiPartnerParty, gBlockRecvBuffer[i], sizeof(struct UnknownPokemonStruct4) * ARRAY_COUNT(gMultiPartnerParty));
                    }
                }
                else
                {
                    memcpy(gMultiPartnerParty, gBlockRecvBuffer[i], sizeof(struct UnknownPokemonStruct4) * ARRAY_COUNT(gMultiPartnerParty));
                }
            }
            gBattleCommunication[MULTIUSE_STATE]++;
            *savedCallback = gMain.savedCallback;
            *savedBattleTypeFlags = gBattleTypeFlags;
            gMain.savedCallback = CB2_PreInitMultiBattle;
            ShowPartyMenuToShowcaseMultiBattleParty();
        }
        break;
    case 2:
        if (IsLinkTaskFinished() && !gPaletteFade.active)
        {
            gBattleCommunication[MULTIUSE_STATE]++;
            if (gWirelessCommType)
                SetLinkStandbyCallback();
            else
                SetCloseLinkCallback();
        }
        break;
    case 3:
        if (gWirelessCommType)
        {
            if (IsLinkRfuTaskFinished())
            {
                gBattleTypeFlags = *savedBattleTypeFlags;
                gMain.savedCallback = *savedCallback;
                SetMainCallback2(CB2_InitBattleInternal);
                Free(sMultiPartnerPartyBuffer);
                sMultiPartnerPartyBuffer = NULL;
            }
        }
        else if (gReceivedRemoteLinkPlayers == 0)
        {
            gBattleTypeFlags = *savedBattleTypeFlags;
            gMain.savedCallback = *savedCallback;
            SetMainCallback2(CB2_InitBattleInternal);
            Free(sMultiPartnerPartyBuffer);
            sMultiPartnerPartyBuffer = NULL;
        }
        break;
    }
}

static void CB2_PreInitIngamePlayerPartnerBattle(void)
{
    u32 *savedBattleTypeFlags;
    void (**savedCallback)(void);

    savedCallback = &gBattleStruct->savedCallback;
    savedBattleTypeFlags = &gBattleStruct->savedBattleTypeFlags;

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        sMultiPartnerPartyBuffer = Alloc(sizeof(struct UnknownPokemonStruct4) * ARRAY_COUNT(gMultiPartnerParty));
        sub_80379F8(3);
        gBattleCommunication[MULTIUSE_STATE]++;
        *savedCallback = gMain.savedCallback;
        *savedBattleTypeFlags = gBattleTypeFlags;
        gMain.savedCallback = CB2_PreInitIngamePlayerPartnerBattle;
        ShowPartyMenuToShowcaseMultiBattleParty();
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            gBattleCommunication[MULTIUSE_STATE] = 2;
            gBattleTypeFlags = *savedBattleTypeFlags;
            gMain.savedCallback = *savedCallback;
            SetMainCallback2(CB2_InitBattleInternal);
            Free(sMultiPartnerPartyBuffer);
            sMultiPartnerPartyBuffer = NULL;
        }
        break;
    }
}

static void CB2_HandleStartMultiBattle(void)
{
    u8 playerMultiplayerId;
    s32 id;
    u8 var;

    playerMultiplayerId = GetMultiplayerId();
    gBattleScripting.multiplayerId = playerMultiplayerId;

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            sub_805EF14();
            gBattleCommunication[MULTIUSE_STATE] = 1;
        }
        if (gWirelessCommType)
            LoadWirelessStatusIndicatorSpriteGfx();
        break;
    case 1:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (gReceivedRemoteLinkPlayers != 0)
            {
                if (IsLinkTaskFinished())
                {
                    // 0x300
                    *(&gBattleStruct->multiBuffer.linkBattlerHeader.versionSignatureLo) = 0;
                    *(&gBattleStruct->multiBuffer.linkBattlerHeader.versionSignatureHi) = 3;
                    BufferPartyVsScreenHealth_AtStart();
                    SetPlayerBerryDataInBattleStruct();

                    SendBlock(bitmask_all_link_players_but_self(), &gBattleStruct->multiBuffer.linkBattlerHeader, sizeof(gBattleStruct->multiBuffer.linkBattlerHeader));
                    gBattleCommunication[MULTIUSE_STATE]++;
                }
                if (gWirelessCommType)
                    CreateWirelessStatusIndicatorSprite(0, 0);
            }
        }
        else
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
                gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER;
            gBattleCommunication[MULTIUSE_STATE] = 7;
            SetAllPlayersBerryData();
        }
        break;
    case 2:
        if ((GetBlockReceivedStatus() & 0xF) == 0xF)
        {
            ResetBlockReceivedFlags();
            FindLinkBattleMaster(4, playerMultiplayerId);
            SetAllPlayersBerryData();
            var = CreateTask(InitLinkBattleVsScreen, 0);
            gTasks[var].data[1] = 0x10E;
            gTasks[var].data[2] = 0x5A;
            gTasks[var].data[5] = 0;
            gTasks[var].data[3] = 0;
            gTasks[var].data[4] = 0;

            for (id = 0; id < MAX_LINK_PLAYERS; id++)
            {
                RecordedBattle_SetFrontierPassFlagFromHword(gBlockRecvBuffer[id][1]);
                switch (gLinkPlayers[id].id)
                {
                case 0:
                    gTasks[var].data[3] |= gBlockRecvBuffer[id][1] & 0x3F;
                    break;
                case 1:
                    gTasks[var].data[4] |= gBlockRecvBuffer[id][1] & 0x3F;
                    break;
                case 2:
                    gTasks[var].data[3] |= (gBlockRecvBuffer[id][1] & 0x3F) << 6;
                    break;
                case 3:
                    gTasks[var].data[4] |= (gBlockRecvBuffer[id][1] & 0x3F) << 6;
                    break;
                }
            }
            ZeroEnemyPartyMons();
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        else
            break;
        // fall through
    case 3:
        if (IsLinkTaskFinished())
        {
            SendBlock(bitmask_all_link_players_but_self(), gPlayerParty, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 4:
        if ((GetBlockReceivedStatus() & 0xF) == 0xF)
        {
            ResetBlockReceivedFlags();
            for (id = 0; id < MAX_LINK_PLAYERS; id++)
            {
                if (id == playerMultiplayerId)
                {
                    switch (gLinkPlayers[id].id)
                    {
                    case 0:
                    case 3:
                        memcpy(gPlayerParty, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                        break;
                    case 1:
                    case 2:
                        memcpy(gPlayerParty + MULTI_PARTY_SIZE, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                        break;
                    }
                }
                else
                {
                    if ((!(gLinkPlayers[id].id & 1) && !(gLinkPlayers[playerMultiplayerId].id & 1))
                     || ((gLinkPlayers[id].id & 1) && (gLinkPlayers[playerMultiplayerId].id & 1)))
                    {
                        switch (gLinkPlayers[id].id)
                        {
                        case 0:
                        case 3:
                            memcpy(gPlayerParty, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                            break;
                        case 1:
                        case 2:
                            memcpy(gPlayerParty + MULTI_PARTY_SIZE, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                            break;
                        }
                    }
                    else
                    {
                        switch (gLinkPlayers[id].id)
                        {
                        case 0:
                        case 3:
                            memcpy(gEnemyParty, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                            break;
                        case 1:
                        case 2:
                            memcpy(gEnemyParty + MULTI_PARTY_SIZE, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                            break;
                        }
                    }
                }
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 5:
        if (IsLinkTaskFinished())
        {
            SendBlock(bitmask_all_link_players_but_self(), gPlayerParty + 2, sizeof(struct Pokemon));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 6:
        if ((GetBlockReceivedStatus() & 0xF) == 0xF)
        {
            ResetBlockReceivedFlags();
            for (id = 0; id < MAX_LINK_PLAYERS; id++)
            {
                if (id == playerMultiplayerId)
                {
                    switch (gLinkPlayers[id].id)
                    {
                    case 0:
                    case 3:
                        memcpy(gPlayerParty + 2, gBlockRecvBuffer[id], sizeof(struct Pokemon));
                        break;
                    case 1:
                    case 2:
                        memcpy(gPlayerParty + 5, gBlockRecvBuffer[id], sizeof(struct Pokemon));
                        break;
                    }
                }
                else
                {
                    if ((!(gLinkPlayers[id].id & 1) && !(gLinkPlayers[playerMultiplayerId].id & 1))
                     || ((gLinkPlayers[id].id & 1) && (gLinkPlayers[playerMultiplayerId].id & 1)))
                    {
                        switch (gLinkPlayers[id].id)
                        {
                        case 0:
                        case 3:
                            memcpy(gPlayerParty + 2, gBlockRecvBuffer[id], sizeof(struct Pokemon));
                            break;
                        case 1:
                        case 2:
                            memcpy(gPlayerParty + 5, gBlockRecvBuffer[id], sizeof(struct Pokemon));
                            break;
                        }
                    }
                    else
                    {
                        switch (gLinkPlayers[id].id)
                        {
                        case 0:
                        case 3:
                            memcpy(gEnemyParty + 2, gBlockRecvBuffer[id], sizeof(struct Pokemon));
                            break;
                        case 1:
                        case 2:
                            memcpy(gEnemyParty + 5, gBlockRecvBuffer[id], sizeof(struct Pokemon));
                            break;
                        }
                    }
                }
            }
            TryCorrectShedinjaLanguage(&gPlayerParty[0]);
            TryCorrectShedinjaLanguage(&gPlayerParty[1]);
            TryCorrectShedinjaLanguage(&gPlayerParty[2]);
            TryCorrectShedinjaLanguage(&gPlayerParty[3]);
            TryCorrectShedinjaLanguage(&gPlayerParty[4]);
            TryCorrectShedinjaLanguage(&gPlayerParty[5]);

            TryCorrectShedinjaLanguage(&gEnemyParty[0]);
            TryCorrectShedinjaLanguage(&gEnemyParty[1]);
            TryCorrectShedinjaLanguage(&gEnemyParty[2]);
            TryCorrectShedinjaLanguage(&gEnemyParty[3]);
            TryCorrectShedinjaLanguage(&gEnemyParty[4]);
            TryCorrectShedinjaLanguage(&gEnemyParty[5]);

            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 7:
        InitBattleControllers();
        sub_8184E58();
        gBattleCommunication[SPRITES_INIT_STATE1] = 0;
        gBattleCommunication[SPRITES_INIT_STATE2] = 0;
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            for (id = 0; id < MAX_LINK_PLAYERS && (gLinkPlayers[id].version & 0xFF) == VERSION_EMERALD; id++);

            if (id == MAX_LINK_PLAYERS)
                gBattleCommunication[MULTIUSE_STATE] = 8;
            else
                gBattleCommunication[MULTIUSE_STATE] = 10;
        }
        else
        {
            gBattleCommunication[MULTIUSE_STATE] = 10;
        }
        break;
    case 8:
        if (IsLinkTaskFinished())
        {
            u32* ptr = gBattleStruct->multiBuffer.battleVideo;
            ptr[0] = gBattleTypeFlags;
            ptr[1] = gRecordedBattleRngSeed; // UB: overwrites berry data
            SendBlock(bitmask_all_link_players_but_self(), ptr, sizeof(gBattleStruct->multiBuffer.battleVideo));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 9:
        if ((GetBlockReceivedStatus() & 0xF) == 0xF)
        {
            ResetBlockReceivedFlags();
            for (var = 0; var < 4; var++)
            {
                u32 blockValue = gBlockRecvBuffer[var][0];
                if (blockValue & 4)
                {
                    memcpy(&gRecordedBattleRngSeed, &gBlockRecvBuffer[var][2], sizeof(gRecordedBattleRngSeed));
                    break;
                }
            }

            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 10:
        if (BattleInitAllSprites(&gBattleCommunication[SPRITES_INIT_STATE1], &gBattleCommunication[SPRITES_INIT_STATE2]))
        {
            gPreBattleCallback1 = gMain.callback1;
            gMain.callback1 = BattleMainCB1;
            SetMainCallback2(BattleMainCB2);
            if (gBattleTypeFlags & BATTLE_TYPE_LINK)
            {
                gTrainerBattleOpponent_A = TRAINER_LINK_OPPONENT;
                gBattleTypeFlags |= BATTLE_TYPE_LINK_IN_BATTLE;
            }
        }
        break;
    }
}

void BattleMainCB2(void)
{
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();

    if (JOY_HELD(B_BUTTON) && gBattleTypeFlags & BATTLE_TYPE_RECORDED && sub_8186450())
    {
        gSpecialVar_Result = gBattleOutcome = B_OUTCOME_PLAYER_TELEPORTED;
        ResetPaletteFadeControl();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        SetMainCallback2(CB2_QuitRecordedBattle);
    }
}

static void FreeRestoreBattleData(void)
{
    gMain.callback1 = gPreBattleCallback1;
    gScanlineEffect.state = 3;
    gMain.inBattle = 0;
    ZeroEnemyPartyMons();
    m4aSongNumStop(SE_LOW_HEALTH);
    FreeMonSpritesGfx();
    FreeBattleSpritesData();
    FreeBattleResources();
}

void CB2_QuitRecordedBattle(void)
{
    UpdatePaletteFade();
    if (!gPaletteFade.active)
    {
        m4aMPlayStop(&gMPlayInfo_SE1);
        m4aMPlayStop(&gMPlayInfo_SE2);
        FreeRestoreBattleData();
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
    }
}

void sub_8038528(struct Sprite* sprite)
{
    sprite->data[0] = 0;
    sprite->callback = sub_8038538;
}

static void sub_8038538(struct Sprite *sprite)
{
    u16 *arr = (u16*)(gDecompressionBuffer);

    switch (sprite->data[0])
    {
    case 0:
        sprite->data[0]++;
        sprite->data[1] = 0;
        sprite->data[2] = 0x281;
        sprite->data[3] = 0;
        sprite->data[4] = 1;
        // fall through
    case 1:
        sprite->data[4]--;
        if (sprite->data[4] == 0)
        {
            s32 i;
            s32 r2;
            s32 r0;

            sprite->data[4] = 2;
            r2 = sprite->data[1] + sprite->data[3] * 32;
            r0 = sprite->data[2] - sprite->data[3] * 32;
            for (i = 0; i < 29; i += 2)
            {
                arr[r2 + i] = 0x3D;
                arr[r0 + i] = 0x3D;
            }
            sprite->data[3]++;
            if (sprite->data[3] == 21)
            {
                sprite->data[0]++;
                sprite->data[1] = 32;
            }
        }
        break;
    case 2:
        sprite->data[1]--;
        if (sprite->data[1] == 20)
            SetMainCallback2(CB2_InitBattle);
        break;
    }
}

static u8 CreateNPCTrainerParty(struct Pokemon *party, u16 trainerNum, bool8 firstTrainer)
{
    u32 nameHash = 0;
    u32 personalityValue;
    u8 fixedIV;
    s32 i, j = 0;
    u8 monsCount;
    u8 level;
    u8 pp;
    u8 friendship;
    u8 difficultySetting = gSaveBlock2Ptr->gameDifficulty;
    u8 isDoubleBattle = gTrainers[trainerNum].doubleBattle;
	u8 DoubleReady = GetMonsStateToDoubles() == PLAYER_HAS_TWO_USABLE_MONS;
    u8 enemyPartySize = gTrainers[trainerNum].partySize;
        
    u16 move = 1;
    u16 species = 1;

    if(DoubleReady && (gSaveBlock2Ptr->doubleBattleMode == TRUE || gTrainers[trainerNum].doubleBattle)){
        // This is a copy from the code below to calculate the number of Pokemon per trainer
        // In doubles if you are on elite mode the game will try to use a Double Elite Party if there is no exclusive party it uses the 
        // Elite Single Party if there is Elite Single Party it will try to use Double Normal Party if there is no Normal Double Party it will try to
        // use the Signle Normal Party
        if(difficultySetting == DIFFICULTY_ELITE && gTrainers[trainerNum].partySizeInsaneDouble != 0)
            enemyPartySize = gTrainers[trainerNum].partySizeInsaneDouble;
        else if(difficultySetting == DIFFICULTY_ELITE && gTrainers[trainerNum].partySizeInsane != 0)
            enemyPartySize = gTrainers[trainerNum].partySizeInsane;
        else if(gTrainers[trainerNum].partySizeDouble != 0)
            enemyPartySize = gTrainers[trainerNum].partySizeDouble;
        else
            enemyPartySize = gTrainers[trainerNum].partySize;
        }
    else{
        // In singles if you are on elite mode the game will try to use an Elite Party if there is no exclusive party it uses the normal one
        if(difficultySetting == DIFFICULTY_ELITE && gTrainers[trainerNum].partySizeInsane != 0)
            enemyPartySize = gTrainers[trainerNum].partySizeInsane;
        else
            enemyPartySize = gTrainers[trainerNum].partySize;
    }

    //Double Battle Mode
    if(DoubleReady && enemyPartySize >= 2 && gSaveBlock2Ptr->doubleBattleMode == TRUE)
		isDoubleBattle = TRUE;
	else if(DoubleReady && enemyPartySize >= 2 && gTrainers[trainerNum].doubleBattle)
		isDoubleBattle = TRUE;
	else
		isDoubleBattle = FALSE;

    //Saves the last trainer you battled in case that you battle 2 different opponents at once
    VarSet(VAR_LAST_TRAINER_BATTLED_2, VarGet(VAR_LAST_TRAINER_BATTLED));
    //Then saves the current trainer to the last battled trainer
    VarSet(VAR_LAST_TRAINER_BATTLED, trainerNum);

    if (trainerNum == TRAINER_SECRET_BASE)
        return 0;

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && !(gBattleTypeFlags & (BATTLE_TYPE_FRONTIER
                                                                        | BATTLE_TYPE_EREADER_TRAINER
                                                                        | BATTLE_TYPE_TRAINER_HILL)))
    {
        if (firstTrainer == TRUE)
            ZeroEnemyPartyMons();

        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        {
            if (enemyPartySize > 3)
                monsCount = 3;
            else
                monsCount = enemyPartySize;
        }
        else
        {
            monsCount = enemyPartySize;
        }

        for (i = 0; i < monsCount; i++)
        {

            if (isDoubleBattle == TRUE)
                personalityValue = 0x80;
            else if (gTrainers[trainerNum].encounterMusic_gender & F_TRAINER_FEMALE)
                personalityValue = 0x78; // Use personality more likely to result in a female Pokémon
            else
                personalityValue = 0x88; // Use personality more likely to result in a male Pokémon

            for (j = 0; gTrainers[trainerNum].trainerName[j] != EOS; j++)
                nameHash += gTrainers[trainerNum].trainerName[j];

            switch (gTrainers[trainerNum].partyFlags)
            {
            case 0:
            {
                const struct TrainerMonNoItemDefaultMoves *partyData = gTrainers[trainerNum].party.NoItemDefaultMoves;

                for (j = 0; gSpeciesNames[partyData[i].species][j] != EOS; j++)
                    nameHash += gSpeciesNames[partyData[i].species][j];

                personalityValue += nameHash << 8;
                fixedIV = partyData[i].iv * MAX_PER_STAT_IVS / 255;
                CreateMon(&party[i], partyData[i].species, partyData[i].lvl, fixedIV, TRUE, personalityValue, OT_ID_RANDOM_NO_SHINY, 0);

                // Sets Pokemon Nature
                SetMonData(&party[i], MON_DATA_NATURE, &partyData[i].nature);

                //Sets EVs to fully customized spreads if difficulty is Hard or higher
                if (difficultySetting > DIFFICULTY_EASY)
                {
                    for (j = 0; j < NUM_STATS; j++)
                    {
                        switch(j){
                            case 0:
                                SetMonData(&party[i], MON_DATA_HP_EV, &partyData[i].evs[j]);
                            break;
                            case 1:
                                SetMonData(&party[i], MON_DATA_ATK_EV, &partyData[i].evs[j]);
                            break;
                            case 2:
                                SetMonData(&party[i], MON_DATA_DEF_EV, &partyData[i].evs[j]);
                            break;
                            case 3:
                                SetMonData(&party[i], MON_DATA_SPATK_EV, &partyData[i].evs[j]);
                            break;
                            case 4:
                                SetMonData(&party[i], MON_DATA_SPDEF_EV, &partyData[i].evs[j]);
                            break;
                            case 5:
                                SetMonData(&party[i], MON_DATA_SPEED_EV, &partyData[i].evs[j]);
                            break;
                        }
                    }
                }

                CalculateMonStats(&party[i]);

                break;
            }
            case F_TRAINER_PARTY_CUSTOM_MOVESET:
            {
                const struct TrainerMonNoItemCustomMoves *partyData = gTrainers[trainerNum].party.NoItemCustomMoves;

                for (j = 0; gSpeciesNames[partyData[i].species][j] != EOS; j++)
                    nameHash += gSpeciesNames[partyData[i].species][j];

                personalityValue += nameHash << 8;
                fixedIV = partyData[i].iv * MAX_PER_STAT_IVS / 255;
                CreateMon(&party[i], partyData[i].species, partyData[i].lvl, fixedIV, TRUE, personalityValue, OT_ID_RANDOM_NO_SHINY, 0);

                for (j = 0; j < MAX_MON_MOVES; j++)
                {
                    SetMonData(&party[i], MON_DATA_MOVE1 + j, &partyData[i].moves[j]);
                    pp = CalculatePPWithBonus(GetMonData(&party[i], MON_DATA_MOVE1 + j, NULL), GetMonData(&party[i], MON_DATA_PP_BONUSES, NULL), j);
                    SetMonData(&party[i], MON_DATA_PP1 + j, &pp);
                }

                // Sets Pokemon Nature
                SetMonData(&party[i], MON_DATA_NATURE, &partyData[i].nature);

                //Sets EVs to fully customized spreads if difficulty is Hard or higher
                if (difficultySetting > DIFFICULTY_EASY)
                {
                    for (j = 0; j < NUM_STATS; j++)
                    {
                        switch(j){
                            case 0:
                                SetMonData(&party[i], MON_DATA_HP_EV, &partyData[i].evs[j]);
                            break;
                            case 1:
                                SetMonData(&party[i], MON_DATA_ATK_EV, &partyData[i].evs[j]);
                            break;
                            case 2:
                                SetMonData(&party[i], MON_DATA_DEF_EV, &partyData[i].evs[j]);
                            break;
                            case 3:
                                SetMonData(&party[i], MON_DATA_SPATK_EV, &partyData[i].evs[j]);
                            break;
                            case 4:
                                SetMonData(&party[i], MON_DATA_SPDEF_EV, &partyData[i].evs[j]);
                            break;
                            case 5:
                                SetMonData(&party[i], MON_DATA_SPEED_EV, &partyData[i].evs[j]);
                            break;
                        }
                    }
                }

                CalculateMonStats(&party[i]);

                break;
            }
            case F_TRAINER_PARTY_HELD_ITEM:
            {
                const struct TrainerMonItemDefaultMoves *partyData = gTrainers[trainerNum].party.ItemDefaultMoves;

                for (j = 0; gSpeciesNames[partyData[i].species][j] != EOS; j++)
                    nameHash += gSpeciesNames[partyData[i].species][j];

                personalityValue += nameHash << 8;
                fixedIV = partyData[i].iv * MAX_PER_STAT_IVS / 255;
                CreateMon(&party[i], partyData[i].species, partyData[i].lvl, fixedIV, TRUE, personalityValue, OT_ID_RANDOM_NO_SHINY, 0);

                SetMonData(&party[i], MON_DATA_HELD_ITEM, &partyData[i].heldItem);

                // Sets Pokemon Nature
                SetMonData(&party[i], MON_DATA_NATURE, &partyData[i].nature);

                //Sets EVs to fully customized spreads if difficulty is Hard or higher
                if (difficultySetting > DIFFICULTY_EASY)
                {
                    for (j = 0; j < NUM_STATS; j++)
                    {
                        switch(j){
                            case 0:
                                SetMonData(&party[i], MON_DATA_HP_EV, &partyData[i].evs[j]);
                            break;
                            case 1:
                                SetMonData(&party[i], MON_DATA_ATK_EV, &partyData[i].evs[j]);
                            break;
                            case 2:
                                SetMonData(&party[i], MON_DATA_DEF_EV, &partyData[i].evs[j]);
                            break;
                            case 3:
                                SetMonData(&party[i], MON_DATA_SPATK_EV, &partyData[i].evs[j]);
                            break;
                            case 4:
                                SetMonData(&party[i], MON_DATA_SPDEF_EV, &partyData[i].evs[j]);
                            break;
                            case 5:
                                SetMonData(&party[i], MON_DATA_SPEED_EV, &partyData[i].evs[j]);
                            break;
                        }
                    }
                }

                CalculateMonStats(&party[i]);

                break;
            }
            case F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM:
            {
                const struct TrainerMonItemCustomMoves *partyData;
                u8 hpType;
                if(isDoubleBattle && gSaveBlock2Ptr->doubleBattleMode == TRUE){
                    // In doubles if you are on elite mode the game will try to use a Double Elite Party if there is no exclusive party it uses the 
                    // Elite Single Party if there is Elite Single Party it will try to use Double Normal Party if there is no Normal Double Party it will try to
                    // use the Signle Normal Party
                    if(difficultySetting == DIFFICULTY_ELITE && gTrainers[trainerNum].partyInsaneDouble.ItemCustomMoves != 0)
                        partyData = gTrainers[trainerNum].partyInsaneDouble.ItemCustomMoves;
                    else if(difficultySetting == DIFFICULTY_ELITE && gTrainers[trainerNum].partyInsane.ItemCustomMoves != 0)
                        partyData = gTrainers[trainerNum].partyInsane.ItemCustomMoves;
                    else if(gTrainers[trainerNum].partyDouble.ItemCustomMoves != 0)
                        partyData = gTrainers[trainerNum].partyDouble.ItemCustomMoves;
                    else
                        partyData = gTrainers[trainerNum].party.ItemCustomMoves;
                }
                else{
                    // In singles if you are on elite mode the game will try to use an Elite Party if there is no exclusive party it uses the normal one
                    if(difficultySetting == DIFFICULTY_ELITE && gTrainers[trainerNum].partyInsane.ItemCustomMoves != 0)
                        partyData = gTrainers[trainerNum].partyInsane.ItemCustomMoves;
                    else
                        partyData = gTrainers[trainerNum].party.ItemCustomMoves;
                }

                for (j = 0; gSpeciesNames[partyData[i].species][j] != EOS; j++)
                    nameHash += gSpeciesNames[partyData[i].species][j];

                personalityValue += nameHash << 8;

                level = GetHighestLevelInPlayerParty();
                if (level + partyData[i].lvl > 100)
                {
                    level = 100;
                }
                else if (level + partyData[i].lvl < 1)
                {
                    level = 1;
                }
                else
                {
                    level = level + partyData[i].lvl;
                }

                #ifdef DEBUG_BUILD
                if(FlagGet(FLAG_DEBUG_GODMODE))
                    level = 10;
                #endif

                if (trainerNum == TRAINER_OLDPLAYER)
                {
                    species = Random() % 500;
                    CreateMon(&party[i], species, level, 31, TRUE, personalityValue, OT_ID_RANDOM_NO_SHINY, 0);
                }
                else
                    CreateMon(&party[i], partyData[i].species, level, 31, TRUE, personalityValue, OT_ID_RANDOM_NO_SHINY, 0);

                // Sets Pokemon Nature
                SetMonData(&party[i], MON_DATA_NATURE, &partyData[i].nature);

                SetMonData(&party[i], MON_DATA_HELD_ITEM, &partyData[i].heldItem);

                SetMonData(&party[i], MON_DATA_SPEED_DOWN, &partyData[i].zeroSpeedIvs);

                SetMonData(&party[i], MON_DATA_IS_ALPHA, &partyData[i].isAlpha);
                
                if (partyData[i].hpType) {
                    SetMonData(&party[i], MON_DATA_HP_TYPE, &partyData[i].hpType);
                }
                else {
                    do {
                        hpType = Random() % NUMBER_OF_MON_TYPES;
                    } while (hpType == TYPE_MYSTERY);
                    
                    SetMonData(&party[i], MON_DATA_HP_TYPE, &hpType);
                }

                #ifdef DEBUG_BUILD
                if(FlagGet(FLAG_SYS_AUTOWIN))
                    SetTrainerFlag(trainerNum);
                #endif

                SetMonData(&party[i], MON_DATA_ABILITY_NUM, &partyData[i].ability);

                //Sets EVs to fully customized spreads if difficulty is Hard or higher
                if (difficultySetting > DIFFICULTY_EASY)
                {
                    for (j = 0; j < NUM_STATS; j++)
                    {
                        switch(j){
                            case 0:
                                SetMonData(&party[i], MON_DATA_HP_EV, &partyData[i].evs[j]);
                            break;
                            case 1:
                                SetMonData(&party[i], MON_DATA_ATK_EV, &partyData[i].evs[j]);
                            break;
                            case 2:
                                SetMonData(&party[i], MON_DATA_DEF_EV, &partyData[i].evs[j]);
                            break;
                            case 3:
                                SetMonData(&party[i], MON_DATA_SPATK_EV, &partyData[i].evs[j]);
                            break;
                            case 4:
                                SetMonData(&party[i], MON_DATA_SPDEF_EV, &partyData[i].evs[j]);
                            break;
                            case 5:
                                SetMonData(&party[i], MON_DATA_SPEED_EV, &partyData[i].evs[j]);
                            break;
                        }
                    }
                }

                CalculateMonStats(&party[i]); // called twice; fix in future

                if (trainerNum == TRAINER_OLDPLAYER)
                {
                    for (j = 0; j < MAX_MON_MOVES; j++)
                    {
                        move = selectMoves(species, j, GetMonData(&party[i], MON_DATA_ATK, NULL), GetMonData(&party[i], MON_DATA_SPATK, NULL));        
                        SetMonData(&party[i], MON_DATA_MOVE1 + j, &move);
                        pp = CalculatePPWithBonus(GetMonData(&party[i], MON_DATA_MOVE1 + j, NULL), GetMonData(&party[i], MON_DATA_PP_BONUSES, NULL), j);
                        SetMonData(&party[i], MON_DATA_PP1 + j, &pp);
                    }
                }
                else
                {
                    for (j = 0; j < MAX_MON_MOVES; j++)
                    {
                        SetMonData(&party[i], MON_DATA_MOVE1 + j, &partyData[i].moves[j]);
                        pp = CalculatePPWithBonus(GetMonData(&party[i], MON_DATA_MOVE1 + j, NULL), GetMonData(&party[i], MON_DATA_PP_BONUSES, NULL), j);
                        SetMonData(&party[i], MON_DATA_PP1 + j, &pp);
                    }
                }
                // Set max friendship if trainer mon knows Return /  Added Veevee Volley and Pika Papow to the list
                if (MonKnowsMove(&party[i], MOVE_RETURN) || MonKnowsMove(&party[i], MOVE_VEEVEE_VOLLEY) || MonKnowsMove(&party[i], MOVE_PIKA_PAPOW))
                {
                    friendship = MAX_FRIENDSHIP;
                    SetMonData(&party[i], MON_DATA_FRIENDSHIP, &friendship);
                }
                break;
            }
            }
            for (j = 0; gTrainerBallTable[j].classId != 0xFF; j++)
            {
                if (gTrainerBallTable[j].classId == gTrainers[trainerNum].trainerClass)
                    break;
            }
            SetMonData(&party[i], MON_DATA_POKEBALL, &gTrainerBallTable[j].Ball);
        }

        if(isDoubleBattle)
			gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
        else
            gBattleTypeFlags |= gTrainers[trainerNum].doubleBattle;
    }

    return enemyPartySize;
}

void VBlankCB_Battle(void)
{
    // Change gRngSeed every vblank unless the battle could be recorded.
    if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_FRONTIER | BATTLE_TYPE_RECORDED)))
        Random();

    SetGpuReg(REG_OFFSET_BG0HOFS, gBattle_BG0_X);
    SetGpuReg(REG_OFFSET_BG0VOFS, gBattle_BG0_Y);
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);
    SetGpuReg(REG_OFFSET_BG2HOFS, gBattle_BG2_X);
    SetGpuReg(REG_OFFSET_BG2VOFS, gBattle_BG2_Y);
    SetGpuReg(REG_OFFSET_BG3HOFS, gBattle_BG3_X);
    SetGpuReg(REG_OFFSET_BG3VOFS, gBattle_BG3_Y);
    SetGpuReg(REG_OFFSET_WIN0H, gBattle_WIN0H);
    SetGpuReg(REG_OFFSET_WIN0V, gBattle_WIN0V);
    SetGpuReg(REG_OFFSET_WIN1H, gBattle_WIN1H);
    SetGpuReg(REG_OFFSET_WIN1V, gBattle_WIN1V);
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ScanlineEffect_InitHBlankDmaTransfer();
}

void SpriteCB_VsLetterDummy(struct Sprite *sprite)
{

}

static void SpriteCB_VsLetter(struct Sprite *sprite)
{
    if (sprite->data[0] != 0)
        sprite->x = sprite->data[1] + ((sprite->data[2] & 0xFF00) >> 8);
    else
        sprite->x = sprite->data[1] - ((sprite->data[2] & 0xFF00) >> 8);

    sprite->data[2] += 0x180;

    if (sprite->affineAnimEnded)
    {
        FreeSpriteTilesByTag(ANIM_SPRITES_START);
        FreeSpritePaletteByTag(ANIM_SPRITES_START);
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}

void SpriteCB_VsLetterInit(struct Sprite *sprite)
{
    StartSpriteAffineAnim(sprite, 1);
    sprite->callback = SpriteCB_VsLetter;
    PlaySE(SE_MUGSHOT);
}

static void BufferPartyVsScreenHealth_AtEnd(u8 taskId)
{
    struct Pokemon *party1 = NULL;
    struct Pokemon *party2 = NULL;
    u8 multiplayerId = gBattleScripting.multiplayerId;
    u32 flags;
    s32 i;

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        switch (gLinkPlayers[multiplayerId].id)
        {
        case 0:
        case 2:
            party1 = gPlayerParty;
            party2 = gEnemyParty;
            break;
        case 1:
        case 3:
            party1 = gEnemyParty;
            party2 = gPlayerParty;
            break;
        }
    }
    else
    {
        party1 = gPlayerParty;
        party2 = gEnemyParty;
    }

    flags = 0;
    BUFFER_PARTY_VS_SCREEN_STATUS(party1, flags, i);
    gTasks[taskId].data[3] = flags;

    flags = 0;
    BUFFER_PARTY_VS_SCREEN_STATUS(party2, flags, i);
    gTasks[taskId].data[4] = flags;
}

void CB2_InitEndLinkBattle(void)
{
    s32 i;
    u8 taskId;

    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);
    gBattleTypeFlags &= ~(BATTLE_TYPE_LINK_IN_BATTLE);

    if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
    {
        SetMainCallback2(gMain.savedCallback);
        FreeBattleResources();
        FreeBattleSpritesData();
        FreeMonSpritesGfx();
    }
    else
    {
        CpuFill32(0, (void*)(VRAM), VRAM_SIZE);
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        SetGpuReg(REG_OFFSET_WIN0H, DISPLAY_WIDTH);
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(DISPLAY_HEIGHT / 2, DISPLAY_HEIGHT / 2 + 1));
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        gBattle_WIN0H = DISPLAY_WIDTH;
        gBattle_WIN0V = WIN_RANGE(DISPLAY_HEIGHT / 2, DISPLAY_HEIGHT / 2 + 1);
        ScanlineEffect_Clear();

        i = 0;
        while (i < 80)
        {
            gScanlineEffectRegBuffers[0][i] = 0xF0;
            gScanlineEffectRegBuffers[1][i] = 0xF0;
            i++;
        }

        while (i < 160)
        {
            gScanlineEffectRegBuffers[0][i] = 0xFF10;
            gScanlineEffectRegBuffers[1][i] = 0xFF10;
            i++;
        }

        ResetPaletteFade();

        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 0;
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        gBattle_BG2_X = 0;
        gBattle_BG2_Y = 0;
        gBattle_BG3_X = 0;
        gBattle_BG3_Y = 0;

        InitBattleBgsVideo();
        LoadCompressedPalette(gBattleTextboxPalette, 0, 64);
        LoadBattleMenuWindowGfx();
        ResetSpriteData();
        ResetTasks();
        DrawBattleEntryBackground();
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 4;
        SetVBlankCallback(VBlankCB_Battle);

        // Show end Vs screen with battle results
        taskId = CreateTask(InitLinkBattleVsScreen, 0);
        gTasks[taskId].data[1] = 0x10E;
        gTasks[taskId].data[2] = 0x5A;
        gTasks[taskId].data[5] = 1;
        BufferPartyVsScreenHealth_AtEnd(taskId);

        SetMainCallback2(CB2_EndLinkBattle);
        gBattleCommunication[MULTIUSE_STATE] = 0;
    }
}

static void CB2_EndLinkBattle(void)
{
    EndLinkBattleInSteps();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

static void EndLinkBattleInSteps(void)
{
    s32 i;

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        gBattleCommunication[1] = 0xFF;
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 1:
        if (--gBattleCommunication[1] == 0)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 2:
        if (!gPaletteFade.active)
        {
            u8 monsCount;

            gMain.anyLinkBattlerHasFrontierPass = RecordedBattle_GetFrontierPassFlag();

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                monsCount = 4;
            else
                monsCount = 2;

            for (i = 0; i < monsCount && (gLinkPlayers[i].version & 0xFF) == VERSION_EMERALD; i++);

            if (!gSaveBlock2Ptr->frontier.disableRecordBattle && i == monsCount)
            {
                if (FlagGet(FLAG_SYS_FRONTIER_PASS))
                {
                    FreeAllWindowBuffers();
                    SetMainCallback2(sub_80392A8);
                }
                else if (!gMain.anyLinkBattlerHasFrontierPass)
                {
                    SetMainCallback2(gMain.savedCallback);
                    FreeBattleResources();
                    FreeBattleSpritesData();
                    FreeMonSpritesGfx();
                }
                else if (gReceivedRemoteLinkPlayers == 0)
                {
                    CreateTask(Task_ReconnectWithLinkPlayers, 5);
                    gBattleCommunication[MULTIUSE_STATE]++;
                }
                else
                {
                    gBattleCommunication[MULTIUSE_STATE]++;
                }
            }
            else
            {
                SetMainCallback2(gMain.savedCallback);
                FreeBattleResources();
                FreeBattleSpritesData();
                FreeMonSpritesGfx();
            }
        }
        break;
    case 3:
        CpuFill32(0, (void*)(VRAM), VRAM_SIZE);

        for (i = 0; i < 2; i++)
            LoadChosenBattleElement(i);

        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 4:
        if (!gPaletteFade.active)
            gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 5:
        if (!FuncIsActiveTask(Task_ReconnectWithLinkPlayers))
            gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 6:
        if (IsLinkTaskFinished() == TRUE)
        {
            SetLinkStandbyCallback();
            BattlePutTextOnWindow(gText_LinkStandby3, 0);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 7:
        if (!IsTextPrinterActive(0))
        {
            if (IsLinkTaskFinished() == TRUE)
                gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 8:
        if (!gWirelessCommType)
            SetCloseLinkCallback();
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 9:
        if (!gMain.anyLinkBattlerHasFrontierPass || gWirelessCommType || gReceivedRemoteLinkPlayers != 1)
        {
            gMain.anyLinkBattlerHasFrontierPass = 0;
            SetMainCallback2(gMain.savedCallback);
            FreeBattleResources();
            FreeBattleSpritesData();
            FreeMonSpritesGfx();
        }
        break;
    }
}

u32 GetBattleBgTemplateData(u8 arrayId, u8 caseId)
{
    u32 ret = 0;

    switch (caseId)
    {
    case 0:
        ret = gBattleBgTemplates[arrayId].bg;
        break;
    case 1:
        ret = gBattleBgTemplates[arrayId].charBaseIndex;
        break;
    case 2:
        ret = gBattleBgTemplates[arrayId].mapBaseIndex;
        break;
    case 3:
        ret = gBattleBgTemplates[arrayId].screenSize;
        break;
    case 4:
        ret = gBattleBgTemplates[arrayId].paletteMode;
        break;
    case 5: // Only this case is used
        ret = gBattleBgTemplates[arrayId].priority;
        break;
    case 6:
        ret = gBattleBgTemplates[arrayId].baseTile;
        break;
    }

    return ret;
}

static void sub_80392A8(void)
{
    s32 i;

    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);
    CpuFill32(0, (void*)(VRAM), VRAM_SIZE);
    ResetPaletteFade();
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    gBattle_BG2_Y = 0;
    gBattle_BG3_X = 0;
    gBattle_BG3_Y = 0;
    InitBattleBgsVideo();
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    LoadBattleMenuWindowGfx();

    for (i = 0; i < 2; i++)
        LoadChosenBattleElement(i);

    ResetSpriteData();
    ResetTasks();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 4;
    SetVBlankCallback(VBlankCB_Battle);
    SetMainCallback2(sub_803937C);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
    gBattleCommunication[MULTIUSE_STATE] = 0;
}

static void sub_803937C(void)
{
    sub_803939C();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

static void sub_803939C(void)
{
    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 1:
        if (gMain.anyLinkBattlerHasFrontierPass && gReceivedRemoteLinkPlayers == 0)
            CreateTask(Task_ReconnectWithLinkPlayers, 5);
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 2:
        if (!FuncIsActiveTask(Task_ReconnectWithLinkPlayers))
            gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 3:
        if (!gPaletteFade.active)
        {
            BattlePutTextOnWindow(gText_RecordBattleToPass, 0);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 4:
        if (!IsTextPrinterActive(0))
        {
            HandleBattleWindow(0x18, 8, 0x1D, 0xD, 0);
            BattlePutTextOnWindow(gText_BattleYesNoChoice, 0xC);
            gBattleCommunication[CURSOR_POSITION] = 1;
            BattleCreateYesNoCursorAt(1);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 5:
        if (JOY_NEW(DPAD_UP))
        {
            if (gBattleCommunication[CURSOR_POSITION] != 0)
            {
                PlaySE(SE_SELECT);
                BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
                gBattleCommunication[CURSOR_POSITION] = 0;
                BattleCreateYesNoCursorAt(0);
            }
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (gBattleCommunication[CURSOR_POSITION] == 0)
            {
                PlaySE(SE_SELECT);
                BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
                gBattleCommunication[CURSOR_POSITION] = 1;
                BattleCreateYesNoCursorAt(1);
            }
        }
        else if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            if (gBattleCommunication[CURSOR_POSITION] == 0)
            {
                HandleBattleWindow(0x18, 8, 0x1D, 0xD, WINDOW_CLEAR);
                gBattleCommunication[1] = MoveRecordedBattleToSaveData();
                gBattleCommunication[MULTIUSE_STATE] = 10;
            }
            else
            {
                gBattleCommunication[MULTIUSE_STATE]++;
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 6:
        if (IsLinkTaskFinished() == TRUE)
        {
            HandleBattleWindow(0x18, 8, 0x1D, 0xD, WINDOW_CLEAR);
            if (gMain.anyLinkBattlerHasFrontierPass)
            {
                SetLinkStandbyCallback();
                BattlePutTextOnWindow(gText_LinkStandby3, 0);
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 8:
        if (--gBattleCommunication[1] == 0)
        {
            if (gMain.anyLinkBattlerHasFrontierPass && !gWirelessCommType)
                SetCloseLinkCallback();
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 9:
        if (!gMain.anyLinkBattlerHasFrontierPass || gWirelessCommType || gReceivedRemoteLinkPlayers != 1)
        {
            gMain.anyLinkBattlerHasFrontierPass = 0;
            if (!gPaletteFade.active)
            {
                SetMainCallback2(gMain.savedCallback);
                FreeBattleResources();
                FreeBattleSpritesData();
                FreeMonSpritesGfx();
            }
        }
        break;
    case 10:
        if (gBattleCommunication[1] == 1)
        {
            PlaySE(SE_SAVE);
            BattleStringExpandPlaceholdersToDisplayedString(gText_BattleRecordedOnPass);
            BattlePutTextOnWindow(gDisplayedStringBattle, 0);
            gBattleCommunication[1] = 0x80;
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        else
        {
            BattleStringExpandPlaceholdersToDisplayedString(BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved);
            BattlePutTextOnWindow(gDisplayedStringBattle, 0);
            gBattleCommunication[1] = 0x80;
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 11:
        if (IsLinkTaskFinished() == TRUE && !IsTextPrinterActive(0) && --gBattleCommunication[1] == 0)
        {
            if (gMain.anyLinkBattlerHasFrontierPass)
            {
                SetLinkStandbyCallback();
                BattlePutTextOnWindow(gText_LinkStandby3, 0);
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 12:
    case 7:
        if (!IsTextPrinterActive(0))
        {
            if (gMain.anyLinkBattlerHasFrontierPass)
            {
                if (IsLinkTaskFinished() == TRUE)
                {
                    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
                    gBattleCommunication[1] = 0x20;
                    gBattleCommunication[MULTIUSE_STATE] = 8;
                }

            }
            else
            {
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
                gBattleCommunication[1] = 0x20;
                gBattleCommunication[MULTIUSE_STATE] = 8;
            }
        }
        break;
    }
}

static void TryCorrectShedinjaLanguage(struct Pokemon *mon)
{
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u8 language = LANGUAGE_JAPANESE;

    if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_SHEDINJA
     && GetMonData(mon, MON_DATA_LANGUAGE) != language)
    {
        GetMonData(mon, MON_DATA_NICKNAME, nickname);
        if (StringCompareWithoutExtCtrlCodes(nickname, sText_ShedinjaJpnName) == 0)
            SetMonData(mon, MON_DATA_LANGUAGE, &language);
    }
}

u32 GetBattleWindowTemplatePixelWidth(u32 setId, u32 tableId)
{
    return gBattleWindowTemplates[setId][tableId].width * 8;
}

#define sBattler            data[0]
#define sSpeciesId          data[2]

void SpriteCb_WildMon(struct Sprite *sprite)
{
    sprite->callback = SpriteCb_MoveWildMonToRight;
    StartSpriteAnimIfDifferent(sprite, 0);
    if (WILD_DOUBLE_BATTLE)
        BeginNormalPaletteFade((0x10000 << sprite->sBattler) | (0x10000 << BATTLE_PARTNER(sprite->sBattler)), 0, 10, 10, RGB(8, 8, 8));
    else
        BeginNormalPaletteFade((0x10000 << sprite->sBattler), 0, 10, 10, RGB(8, 8, 8));
}

static void SpriteCb_MoveWildMonToRight(struct Sprite *sprite)
{
    if ((gIntroSlideFlags & 1) == 0)
    {
        sprite->x2 += 2;
        if (sprite->x2 == 0)
        {
            sprite->callback = SpriteCb_WildMonShowHealthbox;
        }
    }
}

static void SpriteCb_WildMonShowHealthbox(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        StartHealthboxSlideIn(sprite->sBattler);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[sprite->sBattler]);
        sprite->callback = SpriteCb_WildMonAnimate;
        StartSpriteAnimIfDifferent(sprite, 0);
        if (WILD_DOUBLE_BATTLE)
            BeginNormalPaletteFade((0x10000 << sprite->sBattler) | (0x10000 << BATTLE_PARTNER(sprite->sBattler)), 0, 10, 0, RGB(8, 8, 8));
        else
            BeginNormalPaletteFade((0x10000 << sprite->sBattler), 0, 10, 0, RGB(8, 8, 8));
    }
}

static void SpriteCb_WildMonAnimate(struct Sprite *sprite)
{
    if (!gPaletteFade.active)
    {
        BattleAnimateFrontSprite(sprite, sprite->sSpeciesId, FALSE, 1);
    }
}

void SpriteCallbackDummy_2(struct Sprite *sprite)
{

}

static void sub_80398D0(struct Sprite *sprite)
{
    sprite->data[4]--;
    if (sprite->data[4] == 0)
    {
        sprite->data[4] = 8;
        sprite->invisible ^= 1;
        sprite->data[3]--;
        if (sprite->data[3] == 0)
        {
            sprite->invisible = FALSE;
            sprite->callback = SpriteCallbackDummy_2;
            // sUnusedUnknownArray[0] = 0;
        }
    }
}

extern const struct MonCoords gMonFrontPicCoords[];
extern const struct MonCoords gCastformFrontSpriteCoords[];

void SpriteCB_FaintOpponentMon(struct Sprite *sprite)
{
    u8 battler = sprite->sBattler;
    u32 personality = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_PERSONALITY);
    u16 species;
    u8 yOffset;

    if (gBattleSpritesDataPtr->battlerData[battler].transformSpecies != 0)
        species = gBattleSpritesDataPtr->battlerData[battler].transformSpecies;
    else
        species = sprite->sSpeciesId;

    GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_PERSONALITY);  // Unused return value.

    if (species == SPECIES_UNOWN)
    {
        species = GetUnownSpeciesId(personality);
        yOffset = gMonFrontPicCoords[species].y_offset;
    }
    else if (species == SPECIES_CASTFORM)
    {
        yOffset = gCastformFrontSpriteCoords[gBattleMonForms[battler]].y_offset;
    }
    else if (species > NUM_SPECIES)
    {
        yOffset = gMonFrontPicCoords[SPECIES_NONE].y_offset;
    }
    else
    {
        yOffset = gMonFrontPicCoords[species].y_offset;
    }

    sprite->data[3] = 8 - yOffset / 8;
    sprite->data[4] = 1;
    sprite->callback = SpriteCB_AnimFaintOpponent;
}

static void SpriteCB_AnimFaintOpponent(struct Sprite *sprite)
{
    s32 i;

    if (--sprite->data[4] == 0)
    {
        sprite->data[4] = 2;
        sprite->y2 += 8; // Move the sprite down.
        if (--sprite->data[3] < 0)
        {
            FreeSpriteOamMatrix(sprite);
            DestroySprite(sprite);
        }
        else // Erase bottom part of the sprite to create a smooth illusion of mon falling down.
        {
            u8* dst = gMonSpritesGfxPtr->sprites.byte[GetBattlerPosition(sprite->sBattler)] + (gBattleMonForms[sprite->sBattler] << 11) + (sprite->data[3] << 8);

            for (i = 0; i < 0x100; i++)
                *(dst++) = 0;

            StartSpriteAnim(sprite, gBattleMonForms[sprite->sBattler]);
        }
    }
}

// Used when selecting a move, which can hit multiple targets, in double battles.
void SpriteCb_ShowAsMoveTarget(struct Sprite *sprite)
{
    sprite->data[3] = 8;
    sprite->data[4] = sprite->invisible;
    sprite->callback = SpriteCb_BlinkVisible;
}

static void SpriteCb_BlinkVisible(struct Sprite *sprite)
{
    if (--sprite->data[3] == 0)
    {
        sprite->invisible ^= 1;
        sprite->data[3] = 8;
    }
}

void SpriteCb_HideAsMoveTarget(struct Sprite *sprite)
{
    sprite->invisible = sprite->data[4];
    sprite->data[4] = FALSE;
    sprite->callback = SpriteCallbackDummy_2;
}

void SpriteCb_OpponentMonFromBall(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        if (!(gHitMarker & HITMARKER_NO_ANIMATIONS) || gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
        {
            if (HasTwoFramesAnimation(sprite->sSpeciesId))
                StartSpriteAnim(sprite, 1);
        }
        BattleAnimateFrontSprite(sprite, sprite->sSpeciesId, TRUE, 1);
    }
}

// This callback is frequently overwritten by SpriteCB_TrainerSlideIn
void SpriteCB_BattleSpriteStartSlideLeft(struct Sprite *sprite)
{
    sprite->callback = SpriteCB_BattleSpriteSlideLeft;
}

static void SpriteCB_BattleSpriteSlideLeft(struct Sprite *sprite)
{
    if (!(gIntroSlideFlags & 1))
    {
        sprite->x2 -= 2;
        if (sprite->x2 == 0)
        {
            sprite->callback = SpriteCallbackDummy_3;
            sprite->data[1] = 0;
        }
    }
}

// Unused
static void sub_80105DC(struct Sprite *sprite)
{
    sprite->callback = SpriteCallbackDummy_3;
}

static void SpriteCallbackDummy_3(struct Sprite *sprite)
{
}

#define sSpeedX data[1]
#define sSpeedY data[2]

void SpriteCB_FaintSlideAnim(struct Sprite *sprite)
{
    if (!(gIntroSlideFlags & 1))
    {
        sprite->x2 += sprite->sSpeedX;
        sprite->y2 += sprite->sSpeedY;
    }
}

#undef sSpeedX
#undef sSpeedY

#define sSinIndex           data[3]
#define sDelta              data[4]
#define sAmplitude          data[5]
#define sBouncerSpriteId    data[6]
#define sWhich              data[7]

void DoBounceEffect(u8 battler, u8 which, s8 delta, s8 amplitude)
{
    u8 invisibleSpriteId;
    u8 bouncerSpriteId;

    switch (which)
    {
    case BOUNCE_HEALTHBOX:
    default:
        if (gBattleSpritesDataPtr->healthBoxesData[battler].healthboxIsBouncing)
            return;
        break;
    case BOUNCE_MON:
        if (gBattleSpritesDataPtr->healthBoxesData[battler].battlerIsBouncing)
            return;
        break;
    }

    invisibleSpriteId = CreateInvisibleSpriteWithCallback(SpriteCB_BounceEffect);
    if (which == BOUNCE_HEALTHBOX)
    {
        bouncerSpriteId = gHealthboxSpriteIds[battler];
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxBounceSpriteId = invisibleSpriteId;
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxIsBouncing = 1;
        gSprites[invisibleSpriteId].sSinIndex = 128; // 0
    }
    else
    {
        bouncerSpriteId = gBattlerSpriteIds[battler];
        gBattleSpritesDataPtr->healthBoxesData[battler].battlerBounceSpriteId = invisibleSpriteId;
        gBattleSpritesDataPtr->healthBoxesData[battler].battlerIsBouncing = 1;
        gSprites[invisibleSpriteId].sSinIndex = 192; // -1
    }
    gSprites[invisibleSpriteId].sDelta = delta;
    gSprites[invisibleSpriteId].sAmplitude = amplitude;
    gSprites[invisibleSpriteId].sBouncerSpriteId = bouncerSpriteId;
    gSprites[invisibleSpriteId].sWhich = which;
    gSprites[invisibleSpriteId].sBattler = battler;
    gSprites[bouncerSpriteId].x2 = 0;
    gSprites[bouncerSpriteId].y2 = 0;
}

void EndBounceEffect(u8 battler, u8 which)
{
    u8 bouncerSpriteId;

    if (which == BOUNCE_HEALTHBOX)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].healthboxIsBouncing)
            return;

        bouncerSpriteId = gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].healthboxBounceSpriteId].sBouncerSpriteId;
        DestroySprite(&gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].healthboxBounceSpriteId]);
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxIsBouncing = 0;
    }
    else
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].battlerIsBouncing)
            return;

        bouncerSpriteId = gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].battlerBounceSpriteId].sBouncerSpriteId;
        DestroySprite(&gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].battlerBounceSpriteId]);
        gBattleSpritesDataPtr->healthBoxesData[battler].battlerIsBouncing = 0;
    }

    gSprites[bouncerSpriteId].x2 = 0;
    gSprites[bouncerSpriteId].y2 = 0;
}

static void SpriteCB_BounceEffect(struct Sprite *sprite)
{
    u8 bouncerSpriteId = sprite->sBouncerSpriteId;
    s32 index = sprite->sSinIndex;
    s32 y = Sin(index, sprite->sAmplitude) + sprite->sAmplitude;

    gSprites[bouncerSpriteId].y2 = y;
    sprite->sSinIndex = (sprite->sSinIndex + sprite->sDelta) & 0xFF;

    bouncerSpriteId = GetMegaIndicatorSpriteId(sprite->sBouncerSpriteId);
    if (sprite->sWhich == BOUNCE_HEALTHBOX && bouncerSpriteId != 0xFF)
        gSprites[bouncerSpriteId].y2 = y;
}

#undef sSinIndex
#undef sDelta
#undef sAmplitude
#undef sBouncerSpriteId
#undef sWhich

void SpriteCb_PlayerMonFromBall(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
        BattleAnimateBackSprite(sprite, sprite->sSpeciesId);
}

void sub_8039E60(struct Sprite *sprite)
{
    sub_8039E9C(sprite);
    if (sprite->animEnded)
        sprite->callback = SpriteCallbackDummy_3;
}

void SpriteCB_TrainerThrowObject(struct Sprite *sprite)
{
    StartSpriteAnim(sprite, 1);
    sprite->callback = sub_8039E60;
}

void sub_8039E9C(struct Sprite *sprite)
{
    if (sprite->animDelayCounter == 0)
        sprite->centerToCornerVecX = gUnknown_0831ACE0[sprite->animCmdIndex];
}

void BeginBattleIntroDummy(void)
{

}

void BeginBattleIntro(void)
{
    BattleStartClearSetData();
    gBattleCommunication[1] = 0;
    gBattleStruct->introState = 0;
    gBattleMainFunc = DoBattleIntro;
}

static void BattleMainCB1(void)
{
    gBattleMainFunc();

    for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
        gBattlerControllerFuncs[gActiveBattler]();
}

static void BattleStartClearSetData(void)
{
    s32 i;

    TurnValuesCleanUp(FALSE);
    TurnStructsClear();

    memset(&gVolatileStructs, 0, sizeof(gVolatileStructs));
    memset(&gFieldTimers, 0, sizeof(gFieldTimers));
    memset(&gSideStatuses, 0, sizeof(gSideStatuses));
    memset(&gFaintedMonCount, 0, sizeof(gFaintedMonCount));
    memset(&gSideTimers, 0, sizeof(gSideTimers));
    memset(&gWishFutureKnock, 0, sizeof(gWishFutureKnock));
    memset(&gBattleResults, 0, sizeof(gBattleResults));

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        gLastChosenMove[i] = 0;
        gStatuses3[i] = 0;
        gStatuses4[i] = 0;
        gVolatileStructs[i].isFirstTurn = 2;
        gVolatileStructs[i].hasBeenOnBattle = FALSE;
        gLastMoves[i] = 0;
        gLastLandedMoves[i] = 0;
        gLastHitByType[i] = 0;
        gLastResultingMoves[i] = 0;
        gLastHitBy[i] = 0xFF;
        gLockedMoves[i] = 0;
        gLastPrintedMoves[i] = 0;
        gBattleResources->flags->flags[i] = 0;
        gPalaceSelectionBattleScripts[i] = 0;
        gBattleStruct->lastTakenMove[i] = 0;
        gBattleStruct->choicedMove[i] = 0;
        gBattleStruct->changedItems[i] = 0;
        gBattleStruct->lastTakenMoveFrom[i][0] = 0;
        gBattleStruct->lastTakenMoveFrom[i][1] = 0;
        gBattleStruct->lastTakenMoveFrom[i][2] = 0;
        gBattleStruct->lastTakenMoveFrom[i][3] = 0;
        gBattleStruct->AI_monToSwitchIntoId[i] = PARTY_SIZE;
    }

    gLastUsedMove = 0;
    gFieldStatuses = 0;

    gHasFetchedBall = FALSE;
    gLastUsedBall = 0;

    gBattlerAttacker = 0;
    gBattlerTarget = 0;
    gBattleWeather = 0;
    gHitMarker = 0;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
    {
        if (!(gBattleTypeFlags & BATTLE_TYPE_LINK) && gSaveBlock2Ptr->optionsBattleSceneOff == TRUE)
            gHitMarker |= HITMARKER_NO_ANIMATIONS;
    }
    else if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK)) && GetBattleSceneInRecordedBattle())
    {
        gHitMarker |= HITMARKER_NO_ANIMATIONS;
    }

    gBattleScripting.battleStyle = gSaveBlock2Ptr->optionsBattleStyle;
    gBattleScripting.battlerPopupOverwrite = MAX_BATTLERS_COUNT;
    gBattleScripting.forceFalseSwipeEffect = 0;
    gBattleScripting.switchInBattlerOverwrite = MAX_BATTLERS_COUNT;
    gBattleScripting.expOnCatch = (B_EXP_CATCH >= GEN_6);
    gBattleScripting.monCaught = FALSE;

    gBattleOutcome = 0;
    gBattleControllerExecFlags = 0;
    gPaydayMoney = 0;
    gBattleResources->battleScriptsStack->size = 0;
    gBattleResources->battleCallbackStack->size = 0;
    gRetaliationInProgress = FALSE;

    for (i = 0; i < BATTLE_COMMUNICATION_ENTRIES_COUNT; i++)
        gBattleCommunication[i] = 0;

    gPauseCounterBattle = 0;
    gBattleMoveDamage = 0;
    gIntroSlideFlags = 0;
    gBattleScripting.animTurn = 0;
    gBattleScripting.animTargetsHit = 0;
    gLeveledUpInBattle = 0;
    gAbsentBattlerFlags = 0;
    gBattleStruct->runTries = 0;
    gBattleStruct->safariGoNearCounter = 0;
    gBattleStruct->safariPkblThrowCounter = 0;
    gBattleStruct->safariCatchFactor = gBaseStats[GetMonData(&gEnemyParty[0], MON_DATA_SPECIES)].catchRate * 100 / 1275;
    gBattleStruct->safariEscapeFactor = 3;
    gBattleStruct->wildVictorySong = 0;
    gBattleStruct->moneyMultiplier = 1;

    gBattleStruct->givenExpMons = 0;
    gBattleStruct->palaceFlags = 0;

    gRandomTurnNumber = Random();

    gBattleResults.shinyWildMon = IsMonShiny(&gEnemyParty[0]);

    gBattleStruct->arenaLostPlayerMons = 0;
    gBattleStruct->arenaLostOpponentMons = 0;

    gBattleStruct->mega.triggerSpriteId = 0xFF;
    
    gBattleStruct->stickyWebUser = 0xFF;
    gBattleStruct->appearedInBattle = 0;
    
    for (i = 0; i < PARTY_SIZE; i++)
    {
        gBattleStruct->usedHeldItems[i][0] = 0;
        gBattleStruct->usedHeldItems[i][1] = 0;
        gBattleStruct->itemStolen[i].originalItem = GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM);
    }

    gSwapDamageCategory = FALSE; // Photon Geyser, Shell Side Arm, Light That Burns the Sky
}

void SwitchInClearSetData(void)
{
    s32 i;
    struct VolatileStruct VolatileStructCopy = gVolatileStructs[gActiveBattler];

    ClearIllusionMon(gActiveBattler);
    if (gBattleMoves[gCurrentMove].effect != EFFECT_BATON_PASS)
    {
        for (i = 0; i < NUM_BATTLE_STATS; i++)
            gBattleMons[gActiveBattler].statStages[i] = DEFAULT_STAT_STAGE;
        for (i = 0; i < gBattlersCount; i++)
        {
            if ((gBattleMons[i].status2 & STATUS2_ESCAPE_PREVENTION) && gVolatileStructs[i].battlerPreventingEscape == gActiveBattler)
                gBattleMons[i].status2 &= ~STATUS2_ESCAPE_PREVENTION;
            if ((gStatuses3[i] & STATUS3_ALWAYS_HITS) && gVolatileStructs[i].battlerWithSureHit == gActiveBattler)
            {
                gStatuses3[i] &= ~STATUS3_ALWAYS_HITS;
                gVolatileStructs[i].battlerWithSureHit = 0;
            }
        }
    }
    if (gBattleMoves[gCurrentMove].effect == EFFECT_BATON_PASS)
    {
        gBattleMons[gActiveBattler].status2 &= (STATUS2_CONFUSION | STATUS2_FOCUS_ENERGY | STATUS2_SUBSTITUTE | STATUS2_ESCAPE_PREVENTION | STATUS2_CURSED);
        gStatuses3[gActiveBattler] &= (STATUS3_LEECHSEED_BATTLER | STATUS3_LEECHSEED | STATUS3_ALWAYS_HITS | STATUS3_PERISH_SONG | STATUS3_ROOTED
                                       | STATUS3_GASTRO_ACID | STATUS3_EMBARGO | STATUS3_TELEKINESIS | STATUS3_MAGNET_RISE | STATUS3_HEAL_BLOCK
                                       | STATUS3_AQUA_RING | STATUS3_POWER_TRICK);

        for (i = 0; i < gBattlersCount; i++)
        {
            if (GetBattlerSide(gActiveBattler) != GetBattlerSide(i)
             && (gStatuses3[i] & STATUS3_ALWAYS_HITS) != 0
             && (gVolatileStructs[i].battlerWithSureHit == gActiveBattler))
            {
                gStatuses3[i] &= ~(STATUS3_ALWAYS_HITS);
                gStatuses3[i] |= STATUS3_ALWAYS_HITS_TURN(2);
            }
        }
        if (gStatuses3[gActiveBattler] & STATUS3_POWER_TRICK)
            SWAP(gBattleMons[gActiveBattler].attack, gBattleMons[gActiveBattler].defense, i);
    }
    else
    {
        gBattleMons[gActiveBattler].status2 = 0;
        gStatuses3[gActiveBattler] = 0;
    }
    
    gStatuses4[gActiveBattler] = 0;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (gBattleMons[i].status2 & STATUS2_INFATUATED_WITH(gActiveBattler))
            gBattleMons[i].status2 &= ~(STATUS2_INFATUATED_WITH(gActiveBattler));
        if ((gBattleMons[i].status2 & STATUS2_WRAPPED) && *(gBattleStruct->wrappedBy + i) == gActiveBattler)
            gBattleMons[i].status2 &= ~(STATUS2_WRAPPED);
    }

    gActionSelectionCursor[gActiveBattler] = 0;
    gMoveSelectionCursor[gActiveBattler] = 0;

    memset(&gVolatileStructs[gActiveBattler], 0, sizeof(struct VolatileStruct));

    if (gBattleMoves[gCurrentMove].effect == EFFECT_BATON_PASS)
    {
        gVolatileStructs[gActiveBattler].substituteHP = VolatileStructCopy.substituteHP;
        gVolatileStructs[gActiveBattler].battlerWithSureHit = VolatileStructCopy.battlerWithSureHit;
        gVolatileStructs[gActiveBattler].perishSongTimer = VolatileStructCopy.perishSongTimer;
        gVolatileStructs[gActiveBattler].perishSongTimerStartValue = VolatileStructCopy.perishSongTimerStartValue;
        gVolatileStructs[gActiveBattler].battlerPreventingEscape = VolatileStructCopy.battlerPreventingEscape;
    }

    gMoveResultFlags = 0;
    gVolatileStructs[gActiveBattler].isFirstTurn = 2;
    gVolatileStructs[gActiveBattler].truantSwitchInHack = VolatileStructCopy.truantSwitchInHack;
    gLastMoves[gActiveBattler] = 0;
    gLastLandedMoves[gActiveBattler] = 0;
    gLastHitByType[gActiveBattler] = 0;
    gLastResultingMoves[gActiveBattler] = 0;
    gLastPrintedMoves[gActiveBattler] = 0;
    gLastHitBy[gActiveBattler] = 0xFF;
    gLastChosenMove[gActiveBattler] = 0;

    gBattleStruct->lastTakenMove[gActiveBattler] = 0;
    gBattleStruct->sameMoveTurns[gActiveBattler] = 0;
    gBattleStruct->lastTakenMoveFrom[gActiveBattler][0] = 0;
    gBattleStruct->lastTakenMoveFrom[gActiveBattler][1] = 0;
    gBattleStruct->lastTakenMoveFrom[gActiveBattler][2] = 0;
    gBattleStruct->lastTakenMoveFrom[gActiveBattler][3] = 0;
    gBattleStruct->lastMoveFailed &= ~(gBitTable[gActiveBattler]);
    gBattleStruct->palaceFlags &= ~(gBitTable[gActiveBattler]);
    
    if (gActiveBattler == gBattleStruct->stickyWebUser)
        gBattleStruct->stickyWebUser = 0xFF;    // Switched into sticky web user slot so reset it

    for (i = 0; i < gBattlersCount; i++)
    {
        if (i != gActiveBattler && GetBattlerSide(i) != GetBattlerSide(gActiveBattler))
            gBattleStruct->lastTakenMove[i] = 0;

        gBattleStruct->lastTakenMoveFrom[i][gActiveBattler] = 0;
    }

    gBattleStruct->choicedMove[gActiveBattler] = 0;
    gBattleResources->flags->flags[gActiveBattler] = 0;
    gCurrentMove = 0;
    gBattleStruct->arenaTurnCounter = 0xFF;
    
    // Reset damage to prevent things like red card activating if the switched-in mon is holding it
    gTurnStructs[gActiveBattler].physicalDmg = 0;
    gTurnStructs[gActiveBattler].specialDmg = 0;

    ClearBattlerMoveHistory(gActiveBattler);
    ClearBattlerAbilityHistory(gActiveBattler);
    ClearBattlerItemEffectHistory(gActiveBattler);
}

void FaintClearSetData(void)
{
    s32 i;

    for (i = 0; i < NUM_BATTLE_STATS; i++)
        gBattleMons[gActiveBattler].statStages[i] = DEFAULT_STAT_STAGE;

    gBattleMons[gActiveBattler].status2 = 0;
    gStatuses3[gActiveBattler] = 0;
    gStatuses4[gActiveBattler] = 0;

    for (i = 0; i < gBattlersCount; i++)
    {
        if ((gBattleMons[i].status2 & STATUS2_ESCAPE_PREVENTION) && gVolatileStructs[i].battlerPreventingEscape == gActiveBattler)
            gBattleMons[i].status2 &= ~STATUS2_ESCAPE_PREVENTION;
        if (gBattleMons[i].status2 & STATUS2_INFATUATED_WITH(gActiveBattler))
            gBattleMons[i].status2 &= ~(STATUS2_INFATUATED_WITH(gActiveBattler));
        if ((gBattleMons[i].status2 & STATUS2_WRAPPED) && *(gBattleStruct->wrappedBy + i) == gActiveBattler)
            gBattleMons[i].status2 &= ~(STATUS2_WRAPPED);
    }

    gActionSelectionCursor[gActiveBattler] = 0;
    gMoveSelectionCursor[gActiveBattler] = 0;

    memset(&gVolatileStructs[gActiveBattler], 0, sizeof(struct VolatileStruct));
    memset(&gRoundStructs[gActiveBattler], 0, sizeof(struct RoundStruct));

    gVolatileStructs[gActiveBattler].isFirstTurn = 2;

    gLastMoves[gActiveBattler] = 0;
    gLastLandedMoves[gActiveBattler] = 0;
    gLastHitByType[gActiveBattler] = 0;
    gLastResultingMoves[gActiveBattler] = 0;
    gLastPrintedMoves[gActiveBattler] = 0;
    gLastHitBy[gActiveBattler] = 0xFF;
    gLastChosenMove[gActiveBattler] = 0;

    gBattleStruct->choicedMove[gActiveBattler] = 0;
    gBattleStruct->sameMoveTurns[gActiveBattler] = 0;
    gBattleStruct->lastTakenMove[gActiveBattler] = 0;
    gBattleStruct->lastTakenMoveFrom[gActiveBattler][0] = 0;
    gBattleStruct->lastTakenMoveFrom[gActiveBattler][1] = 0;
    gBattleStruct->lastTakenMoveFrom[gActiveBattler][2] = 0;
    gBattleStruct->lastTakenMoveFrom[gActiveBattler][3] = 0;

    gBattleStruct->palaceFlags &= ~(gBitTable[gActiveBattler]);
    
    if (gActiveBattler == gBattleStruct->stickyWebUser)
        gBattleStruct->stickyWebUser = 0xFF;    // User of sticky web fainted, so reset the stored battler ID

    for (i = 0; i < gBattlersCount; i++)
    {
        if (i != gActiveBattler && GetBattlerSide(i) != GetBattlerSide(gActiveBattler))
            gBattleStruct->lastTakenMove[i] = 0;

        gBattleStruct->lastTakenMoveFrom[i][gActiveBattler] = 0;
    }

    gBattleResources->flags->flags[gActiveBattler] = 0;

    gBattleMons[gActiveBattler].type1 = gBaseStats[gBattleMons[gActiveBattler].species].type1;
    gBattleMons[gActiveBattler].type2 = gBaseStats[gBattleMons[gActiveBattler].species].type2;
    gBattleMons[gActiveBattler].type3 = TYPE_MYSTERY;

    ClearBattlerMoveHistory(gActiveBattler);
    ClearBattlerAbilityHistory(gActiveBattler);
    ClearBattlerItemEffectHistory(gActiveBattler);
    UndoFormChange(gBattlerPartyIndexes[gActiveBattler], GET_BATTLER_SIDE(gActiveBattler), FALSE);
    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        UndoMegaEvolution(gBattlerPartyIndexes[gActiveBattler]);
}

static void DoBattleIntro(void)
{
    s32 i;
    u8 *state = &gBattleStruct->introState;

    switch (*state)
    {
    case 0: // Get Data of all battlers.
        gActiveBattler = gBattleCommunication[1];
        BtlController_EmitGetMonData(0, REQUEST_ALL_BATTLE, 0);
        MarkBattlerForControllerExec(gActiveBattler);
        (*state)++;
        break;
    case 1: // Loop through all battlers.
        if (!gBattleControllerExecFlags)
        {
            if (++gBattleCommunication[1] == gBattlersCount)
                (*state)++;
            else
                *state = 0;
        }
        break;
    case 2: // Start graphical intro slide.
        if (!gBattleControllerExecFlags)
        {
            gActiveBattler = GetBattlerAtPosition(0);
            BtlController_EmitIntroSlide(0, gBattleTerrain);
            MarkBattlerForControllerExec(gActiveBattler);
            gBattleCommunication[0] = 0;
            gBattleCommunication[1] = 0;
            (*state)++;
        }
        break;
    case 3: // Wait for intro slide.
        if (!gBattleControllerExecFlags)
            (*state)++;
        break;
    case 4: // Copy battler data gotten in cases 0 and 1. Draw trainer/mon sprite.
        for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
        {
            if ((gBattleTypeFlags & BATTLE_TYPE_SAFARI) && GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
            {
                memset(&gBattleMons[gActiveBattler], 0, sizeof(struct BattlePokemon));
            }
            else
            {
                memcpy(&gBattleMons[gActiveBattler], &gBattleResources->bufferB[gActiveBattler][4], sizeof(struct BattlePokemon));
                gBattleMons[gActiveBattler].type1 = RandomizeType(gBaseStats[gBattleMons[gActiveBattler].species].type1, gBattleMons[gActiveBattler].species, gBattleMons[gActiveBattler].personality, TRUE);
                gBattleMons[gActiveBattler].type2 = RandomizeType(gBaseStats[gBattleMons[gActiveBattler].species].type2, gBattleMons[gActiveBattler].species, gBattleMons[gActiveBattler].personality, FALSE);
                gBattleMons[gActiveBattler].type3 = TYPE_MYSTERY;
                if(GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER) //Only the player has a randomized ability
                    gBattleMons[gActiveBattler].ability = RandomizeAbility(GetAbilityBySpecies(gBattleMons[gActiveBattler].species, gBattleMons[gActiveBattler].abilityNum), gBattleMons[gActiveBattler].species, gBattleMons[gActiveBattler].personality);
                else
                    gBattleMons[gActiveBattler].ability = GetAbilityBySpecies(gBattleMons[gActiveBattler].species, gBattleMons[gActiveBattler].abilityNum);

                gBattleMons[gActiveBattler].wasalreadytotemboosted = FALSE;
                
                gBattleStruct->hpOnSwitchout[GetBattlerSide(gActiveBattler)] = gBattleMons[gActiveBattler].hp;
                gBattleMons[gActiveBattler].status2 = 0;
                for (i = 0; i < NUM_BATTLE_STATS; i++)
                    gBattleMons[gActiveBattler].statStages[i] = 6;
            }

            // Draw sprite.
            switch (GetBattlerPosition(gActiveBattler))
            {
            case B_POSITION_PLAYER_LEFT: // player sprite
                BtlController_EmitDrawTrainerPic(0);
                MarkBattlerForControllerExec(gActiveBattler);
                break;
            case B_POSITION_OPPONENT_LEFT:
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER) // opponent 1 sprite
                {
                    BtlController_EmitDrawTrainerPic(0);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
                else // wild mon 1
                {
                    BtlController_EmitLoadMonSprite(0);
                    MarkBattlerForControllerExec(gActiveBattler);
                    gBattleResults.lastOpponentSpecies = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES, NULL);
                }
                break;
            case B_POSITION_PLAYER_RIGHT:
                if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER)) // partner sprite
                {
                    BtlController_EmitDrawTrainerPic(0);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
                break;
            case B_POSITION_OPPONENT_RIGHT:
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                {
                    if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS) && !BATTLE_TWO_VS_ONE_OPPONENT) // opponent 2 if exists
                    {
                        BtlController_EmitDrawTrainerPic(0);
                        MarkBattlerForControllerExec(gActiveBattler);
                    }
                }
                else // wild mon 2
                {
                    BtlController_EmitLoadMonSprite(0);
                    MarkBattlerForControllerExec(gActiveBattler);
                    gBattleResults.lastOpponentSpecies = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES, NULL);
                }
                break;
            }

            if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
                BattleArena_InitPoints();
        }

        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            (*state)++;
        }
        else // Skip party summary since it is a wild battle.
        {
            if (B_FAST_INTRO)
                *state = 7; // Don't wait for sprite, print message at the same time.
            else
                *state = 6; // Wait for sprite to load.
        }
        break;
    case 5: // draw party summary in trainer battles
        if (!gBattleControllerExecFlags)
        {
            struct HpAndStatus hpStatus[PARTY_SIZE];

            for (i = 0; i < PARTY_SIZE; i++)
            {
                if (GetMonData(&gEnemyParty[i], MON_DATA_SPECIES2) == SPECIES_NONE
                 || GetMonData(&gEnemyParty[i], MON_DATA_SPECIES2) == SPECIES_EGG)
                {
                    hpStatus[i].hp = 0xFFFF;
                    hpStatus[i].status = 0;
                }
                else
                {
                    hpStatus[i].hp = GetMonData(&gEnemyParty[i], MON_DATA_HP);
                    hpStatus[i].status = GetMonData(&gEnemyParty[i], MON_DATA_STATUS);
                }
            }

            gActiveBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            BtlController_EmitDrawPartyStatusSummary(0, hpStatus, 0x80);
            MarkBattlerForControllerExec(gActiveBattler);

            for (i = 0; i < PARTY_SIZE; i++)
            {
                if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2) == SPECIES_NONE
                 || GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2) == SPECIES_EGG)
                {
                    hpStatus[i].hp = 0xFFFF;
                    hpStatus[i].status = 0;
                }
                else
                {
                    hpStatus[i].hp = GetMonData(&gPlayerParty[i], MON_DATA_HP);
                    hpStatus[i].status = GetMonData(&gPlayerParty[i], MON_DATA_STATUS);
                }
            }

            gActiveBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
            BtlController_EmitDrawPartyStatusSummary(0, hpStatus, 0x80);
            MarkBattlerForControllerExec(gActiveBattler);

            (*state)++;
        }
        break;
    case 6: // wait for previous action to complete
        if (!gBattleControllerExecFlags)
            (*state)++;
        break;
    case 7: // print battle intro message
        if (!IsBattlerMarkedForControllerExec(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)))
        {
            PrepareStringBattle(STRINGID_INTROMSG, GetBattlerAtPosition(B_POSITION_PLAYER_LEFT));
            (*state)++;
        }
        break;
    case 8: // wait for intro message to be printed
        if (!IsBattlerMarkedForControllerExec(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)))
        {
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            {
                (*state)++;
            }
            else
            {
                if (B_FAST_INTRO)
                    *state = 15; // Wait for text to be printed.
                else
                    *state = 14; // Wait for text and sprite.
            }
        }
        break;
    case 9: // print opponent sends out
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && !(gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER))
            PrepareStringBattle(STRINGID_INTROSENDOUT, GetBattlerAtPosition(B_POSITION_PLAYER_LEFT));
        else
            PrepareStringBattle(STRINGID_INTROSENDOUT, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
        (*state)++;
        break;
    case 10: // wait for opponent sends out text
        if (!gBattleControllerExecFlags)
            (*state)++;
        break;
    case 11: // first opponent's mon send out animation
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && !(gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER))
            gActiveBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        else
            gActiveBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);

        BtlController_EmitIntroTrainerBallThrow(0);
        MarkBattlerForControllerExec(gActiveBattler);
        (*state)++;
        break;
    case 12: // nothing
        (*state)++;
    case 13: // second opponent's mon send out
        if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS) && !BATTLE_TWO_VS_ONE_OPPONENT)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && !(gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER))
                gActiveBattler = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
            else
                gActiveBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);

            BtlController_EmitIntroTrainerBallThrow(0);
            MarkBattlerForControllerExec(gActiveBattler);
        }
        if (B_FAST_INTRO && !(gBattleTypeFlags & (BATTLE_TYPE_RECORDED | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_RECORDED_IS_MASTER | BATTLE_TYPE_LINK)))
            *state = 15; // Print at the same time as trainer sends out second mon.
        else
            (*state)++;
        break;
    case 14: // wait for opponent 2 send out
        if (!gBattleControllerExecFlags)
            (*state)++;
        break;
    case 15: // wait for wild battle message
        if (!IsBattlerMarkedForControllerExec(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)))
            (*state)++;
        break;
    case 16: // print player sends out
        if (!(gBattleTypeFlags & BATTLE_TYPE_SAFARI))
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && !(gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER))
                gActiveBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            else
                gActiveBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);

            // A hack that makes fast intro work in trainer battles too.
            if (B_FAST_INTRO
                && gBattleTypeFlags & BATTLE_TYPE_TRAINER
                && !(gBattleTypeFlags & (BATTLE_TYPE_RECORDED | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_RECORDED_IS_MASTER | BATTLE_TYPE_LINK))
                && gSprites[gHealthboxSpriteIds[gActiveBattler ^ BIT_SIDE]].callback == SpriteCallbackDummy)
            {
                return;
            }

            PrepareStringBattle(STRINGID_INTROSENDOUT, gActiveBattler);
        }
        (*state)++;
        break;
    case 17: // wait for player send out message
        if (!(gBattleTypeFlags & BATTLE_TYPE_LINK && gBattleControllerExecFlags))
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && !(gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER))
                gActiveBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            else
                gActiveBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);

            if (!IsBattlerMarkedForControllerExec(gActiveBattler))
                (*state)++;
        }
        break;
    case 18: // player 1 send out
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && !(gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER))
            gActiveBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        else
            gActiveBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);

        BtlController_EmitIntroTrainerBallThrow(0);
        MarkBattlerForControllerExec(gActiveBattler);
        (*state)++;
        break;
    case 19: // player 2 send out
        if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && !(gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER))
                gActiveBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
            else
                gActiveBattler = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);

            BtlController_EmitIntroTrainerBallThrow(0);
            MarkBattlerForControllerExec(gActiveBattler);
        }
        (*state)++;
        break;
    case 20: // set dex and battle vars
        if (!gBattleControllerExecFlags)
        {
            for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
            {
                if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT
                 && !(gBattleTypeFlags & (BATTLE_TYPE_EREADER_TRAINER
                                          | BATTLE_TYPE_FRONTIER
                                          | BATTLE_TYPE_LINK
                                          | BATTLE_TYPE_RECORDED_LINK
                                          | BATTLE_TYPE_TRAINER_HILL)))
                {
                    HandleSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gActiveBattler].species), FLAG_SET_SEEN, gBattleMons[gActiveBattler].personality);
                }
            }

            gBattleStruct->switchInAbilitiesCounter = 0;
            gBattleStruct->switchInItemsCounter = 0;
            gBattleStruct->overworldWeatherDone = FALSE;

            gBattleMainFunc = TryDoEventsBeforeFirstTurn;
        }
        break;
    }
}

static void TryDoEventsBeforeFirstTurn(void)
{
    s32 i, j;

    if (gBattleControllerExecFlags)
        return;

    // Set invalid mons as absent(for example when starting a double battle with only one pokemon).
    if (!(gBattleTypeFlags & BATTLE_TYPE_SAFARI))
    {
        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattleMons[i].hp == 0 || gBattleMons[i].species == SPECIES_NONE)
                gAbsentBattlerFlags |= gBitTable[i];
        }
    }

    if (gBattleStruct->switchInAbilitiesCounter == 0)
    {
        for (i = 0; i < gBattlersCount; i++)
            gBattlerByTurnOrder[i] = i;
        for (i = 0; i < gBattlersCount - 1; i++)
        {
            for (j = i + 1; j < gBattlersCount; j++)
            {
                if (GetWhoStrikesFirst(gBattlerByTurnOrder[i], gBattlerByTurnOrder[j], TRUE) != 0)
                    SwapTurnOrder(i, j);
            }
        }
    }
    if (!gBattleStruct->overworldWeatherDone
        && AbilityBattleEffects(ABILITYEFFECT_SWITCH_IN_WEATHER, 0, 0, TRUE, 0) != 0)
    {
        gBattleStruct->overworldWeatherDone = TRUE;
        return;
    }

    if (!gBattleStruct->terrainDone && AbilityBattleEffects(ABILITYEFFECT_SWITCH_IN_TERRAIN, 0, 0, TRUE, 0) != 0)
    {
        gBattleStruct->terrainDone = TRUE;
        return;
    }

    // Totem boosts
    for (i = 0; i < gBattlersCount; i++)
    {
        if (gTotemBoosts[i].stats != 0)
        {
            gBattlerAttacker = i;
            BattleScriptExecute(BattleScript_TotemVar);
            return;
        }
    }
    memset(gTotemBoosts, 0, sizeof(gTotemBoosts));  // erase all totem boosts just to be safe

    // Check neutralizing gas
    if (AbilityBattleEffects(ABILITYEFFECT_NEUTRALIZINGGAS, 0, 0, 0, 0) != 0)
        return;
    
    // Check all switch in abilities happening from the fastest mon to slowest.
    while (gBattleStruct->switchInAbilitiesCounter < gBattlersCount)
    {
        gBattlerAttacker = gBattlerByTurnOrder[gBattleStruct->switchInAbilitiesCounter++];
        // Primal Reversion
        if (TryPrimalReversion(gBattlerAttacker))
            return;
        if (AbilityBattleEffects(ABILITYEFFECT_ON_SWITCHIN, gBattlerAttacker, 0, 0, 0) != 0)
            return;
    }
    if (AbilityBattleEffects(ABILITYEFFECT_TRACE1, 0, 0, 0, 0) != 0)
        return;
    // Check all switch in items having effect from the fastest mon to slowest.
    while (gBattleStruct->switchInItemsCounter < gBattlersCount)
    {
        if (ItemBattleEffects(ITEMEFFECT_ON_SWITCH_IN, gBattlerByTurnOrder[gBattleStruct->switchInItemsCounter++], FALSE))
            return;
    }

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        *(gBattleStruct->monToSwitchIntoId + i) = PARTY_SIZE;
        gChosenActionByBattler[i] = B_ACTION_NONE;
        gChosenMoveByBattler[i] = MOVE_NONE;
        // Record party slots of player's mons that appeared in battle
        if (!IsBattlerAIControlled(i))
            gBattleStruct->appearedInBattle |= gBitTable[gBattlerPartyIndexes[i]];
    }
    TurnValuesCleanUp(FALSE);
    TurnStructsClear();
    *(&gBattleStruct->field_91) = gAbsentBattlerFlags;
    BattlePutTextOnWindow(gText_EmptyString3, 0);
    gBattleMainFunc = HandleTurnActionSelectionState;
    ResetSentPokesToOpponentValue();

    for (i = 0; i < BATTLE_COMMUNICATION_ENTRIES_COUNT; i++)
        gBattleCommunication[i] = 0;

    for (i = 0; i < gBattlersCount; i++)
        gBattleMons[i].status2 &= ~(STATUS2_FLINCHED);

    *(&gBattleStruct->turnEffectsTracker) = 0;
    *(&gBattleStruct->turnEffectsBattlerId) = 0;
    *(&gBattleStruct->wishPerishSongState) = 0;
    *(&gBattleStruct->wishPerishSongBattlerId) = 0;
    gBattleScripting.moveendState = 0;
    gBattleStruct->faintedActionsState = 0;
    gBattleStruct->turnCountersTracker = 0;
    gMoveResultFlags = 0;

    gRandomTurnNumber = Random();

    GetAiLogicData(); // get assumed abilities, hold effects, etc of all battlers

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
    {
        StopCryAndClearCrySongs();
        BattleScriptExecute(BattleScript_ArenaTurnBeginning);
    }
}

static void HandleEndTurn_ContinueBattle(void)
{
    s32 i;

    if (gBattleControllerExecFlags == 0)
    {
        gBattleMainFunc = BattleTurnPassed;
        for (i = 0; i < BATTLE_COMMUNICATION_ENTRIES_COUNT; i++)
            gBattleCommunication[i] = 0;
        for (i = 0; i < gBattlersCount; i++)
        {
            gBattleMons[i].status2 &= ~(STATUS2_FLINCHED);
            if ((gBattleMons[i].status1 & STATUS1_SLEEP) && (gBattleMons[i].status2 & STATUS2_MULTIPLETURNS))
                CancelMultiTurnMoves(i);
        }
        gBattleStruct->turnEffectsTracker = 0;
        gBattleStruct->turnEffectsBattlerId = 0;
        gBattleStruct->wishPerishSongState = 0;
        gBattleStruct->wishPerishSongBattlerId = 0;
        gBattleStruct->turnCountersTracker = 0;
        gMoveResultFlags = 0;
    }
}

void BattleTurnPassed(void)
{
    s32 i;

    TurnValuesCleanUp(TRUE);
    if (gBattleOutcome == 0)
    {
        if (DoFieldEndTurnEffects())
            return;
        if (DoBattlerEndTurnEffects())
            return;
    }
    if (HandleFaintedMonActions())
        return;
    gBattleStruct->faintedActionsState = 0;
    if (HandleWishPerishSongOnTurnEnd())
        return;

    TurnValuesCleanUp(FALSE);
    gHitMarker &= ~(HITMARKER_NO_ATTACKSTRING);
    gHitMarker &= ~(HITMARKER_UNABLE_TO_USE_MOVE);
    gHitMarker &= ~(HITMARKER_x400000);
    gHitMarker &= ~(HITMARKER_PASSIVE_DAMAGE);
    gBattleScripting.animTurn = 0;
    gBattleScripting.animTargetsHit = 0;
    gBattleScripting.moveendState = 0;
    gBattleMoveDamage = 0;
    gMoveResultFlags = 0;
    gRetaliationInProgress = 0;

    for (i = 0; i < 5; i++)
        gBattleCommunication[i] = 0;

    if (gBattleOutcome != 0)
    {
        gCurrentActionFuncId = B_ACTION_FINISHED;
        gBattleMainFunc = RunTurnActionsFunctions;
        return;
    }

    if (gBattleResults.battleTurnCounter < 0xFF)
    {
        gBattleResults.battleTurnCounter++;
        gBattleStruct->arenaTurnCounter++;
    }

    for (i = 0; i < gBattlersCount; i++)
    {
        gChosenActionByBattler[i] = B_ACTION_NONE;
        gChosenMoveByBattler[i] = MOVE_NONE;
    }

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
        *(gBattleStruct->monToSwitchIntoId + i) = PARTY_SIZE;

    *(&gBattleStruct->field_91) = gAbsentBattlerFlags;
    BattlePutTextOnWindow(gText_EmptyString3, 0);
    GetAiLogicData(); // get assumed abilities, hold effects, etc of all battlers
    gBattleMainFunc = HandleTurnActionSelectionState;
    gRandomTurnNumber = Random();

    if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        BattleScriptExecute(BattleScript_PalacePrintFlavorText);
    else if (gBattleTypeFlags & BATTLE_TYPE_ARENA && gBattleStruct->arenaTurnCounter == 0)
        BattleScriptExecute(BattleScript_ArenaTurnBeginning);
    else if (ShouldDoTrainerSlide(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), gTrainerBattleOpponent_A, TRAINER_SLIDE_LAST_LOW_HP))
        BattleScriptExecute(BattleScript_TrainerSlideMsgEnd2);
}

u8 IsRunningFromBattleImpossible(void)
{
    u32 holdEffect, i;

    #ifdef DEBUG_BUILD
        return 0;
    #endif

    if (gBattleMons[gActiveBattler].item == ITEM_ENIGMA_BERRY)
        holdEffect = gEnigmaBerries[gActiveBattler].holdEffect;
    else
        holdEffect = ItemId_GetHoldEffect(gBattleMons[gActiveBattler].item);

    gPotentialItemEffectBattler = gActiveBattler;

    if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE) // Cannot ever run from saving Birch's battle.
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DONT_LEAVE_BIRCH;
        return 1;
    }
    if (GetBattlerPosition(gActiveBattler) == B_POSITION_PLAYER_RIGHT && WILD_DOUBLE_BATTLE
        && IsBattlerAlive(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT))) // The second pokemon cannot run from a double wild battle, unless it's the only alive mon.
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CANT_ESCAPE;
        return 1;
    }

    if (holdEffect == HOLD_EFFECT_CAN_ALWAYS_RUN)
        return 0;
    #if B_GHOSTS_ESCAPE >= GEN_6
        if (IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_GHOST))
            return 0;
    #endif
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        return 0;
    if (GetBattlerAbility(gActiveBattler) == ABILITY_RUN_AWAY)
        return 0;

    if ((i = IsAbilityPreventingEscape(gActiveBattler)))
    {
        gBattleScripting.battler = i - 1;
        gLastUsedAbility = gBattleMons[i - 1].ability;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PREVENTS_ESCAPE;
        return 2;
    }

    if (!CanBattlerEscape(gActiveBattler))
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CANT_ESCAPE;
        return 1;
    }
    return 0;
}

void SwitchPartyOrder(u8 battler)
{
    s32 i;
    u8 partyId1;
    u8 partyId2;

    // gBattleStruct->battlerPartyOrders[battler][i]

    for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        gBattlePartyCurrentOrder[i] = *(battler * 3 + i + (u8*)(gBattleStruct->battlerPartyOrders));

    partyId1 = GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[battler]);
    partyId2 = GetPartyIdFromBattlePartyId(*(gBattleStruct->monToSwitchIntoId + battler));
    SwitchPartyMonSlots(partyId1, partyId2);

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        {
            *(battler * 3 + i + (u8*)(gBattleStruct->battlerPartyOrders)) = gBattlePartyCurrentOrder[i];
            *(BATTLE_PARTNER(battler) * 3 + i + (u8*)(gBattleStruct->battlerPartyOrders)) = gBattlePartyCurrentOrder[i];
        }
    }
    else
    {
        for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        {
            *(battler * 3 + i + (u8*)(gBattleStruct->battlerPartyOrders)) = gBattlePartyCurrentOrder[i];
        }
    }
}

enum
{
    STATE_TURN_START_RECORD,
    STATE_BEFORE_ACTION_CHOSEN,
    STATE_WAIT_ACTION_CHOSEN,
    STATE_WAIT_ACTION_CASE_CHOSEN,
    STATE_WAIT_ACTION_CONFIRMED_STANDBY,
    STATE_WAIT_ACTION_CONFIRMED,
    STATE_SELECTION_SCRIPT,
    STATE_WAIT_SET_BEFORE_ACTION,
    STATE_SELECTION_SCRIPT_MAY_RUN
};

static void HandleTurnActionSelectionState(void)
{
    s32 i;

    gBattleCommunication[ACTIONS_CONFIRMED_COUNT] = 0;
    for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
    {
        u8 position = GetBattlerPosition(gActiveBattler);
        switch (gBattleCommunication[gActiveBattler])
        {
        case STATE_TURN_START_RECORD: // Recorded battle related action on start of every turn.
            RecordedBattle_CopyBattlerMoves();
            gBattleCommunication[gActiveBattler] = STATE_BEFORE_ACTION_CHOSEN;

            // Do AI score computations here so we can use them in AI_TrySwitchOrUseItem
            if ((gBattleTypeFlags & BATTLE_TYPE_HAS_AI || IsWildMonSmart()) && IsBattlerAIControlled(gActiveBattler)) {
                gBattleStruct->aiMoveOrAction[gActiveBattler] = ComputeBattleAiScores(gActiveBattler);
            }
            break;
        case STATE_BEFORE_ACTION_CHOSEN: // Choose an action.
            *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI
                || (position & BIT_FLANK) == B_FLANK_LEFT
                || gBattleStruct->field_91 & gBitTable[GetBattlerAtPosition(BATTLE_PARTNER(position))]
                || gBattleCommunication[GetBattlerAtPosition(BATTLE_PARTNER(position))] == STATE_WAIT_ACTION_CONFIRMED)
            {
                if (gBattleStruct->field_91 & gBitTable[gActiveBattler])
                {
                    gChosenActionByBattler[gActiveBattler] = B_ACTION_NOTHING_FAINTED;
                    if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
                        gBattleCommunication[gActiveBattler] = STATE_WAIT_ACTION_CONFIRMED;
                    else
                        gBattleCommunication[gActiveBattler] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                }
                else
                {
                    if (gBattleMons[gActiveBattler].status2 & STATUS2_MULTIPLETURNS
                        || gBattleMons[gActiveBattler].status2 & STATUS2_RECHARGE)
                    {
                        gChosenActionByBattler[gActiveBattler] = B_ACTION_USE_MOVE;
                        gBattleCommunication[gActiveBattler] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                    }
                    else if (WILD_DOUBLE_BATTLE
                             && position == B_POSITION_PLAYER_RIGHT
                             && (gBattleStruct->throwingPokeBall || gChosenActionByBattler[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)] == B_ACTION_RUN))
                    {
                        gBattleStruct->throwingPokeBall = FALSE;
                        gChosenActionByBattler[gActiveBattler] = B_ACTION_NOTHING_FAINTED; // Not fainted, but it cannot move, because of the throwing ball.
                        gBattleCommunication[gActiveBattler] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                    }
                    else
                    {
                        BtlController_EmitChooseAction(0, gChosenActionByBattler[0], gBattleResources->bufferB[0][1] | (gBattleResources->bufferB[0][2] << 8));
                        MarkBattlerForControllerExec(gActiveBattler);
                        gBattleCommunication[gActiveBattler]++;
                    }
                }
            }
            break;
        case STATE_WAIT_ACTION_CHOSEN: // Try to perform an action.
            if (!(gBattleControllerExecFlags & ((gBitTable[gActiveBattler]) | (0xF << 28) | (gBitTable[gActiveBattler] << 4) | (gBitTable[gActiveBattler] << 8) | (gBitTable[gActiveBattler] << 12))))
            {
                RecordedBattle_SetBattlerAction(gActiveBattler, gBattleResources->bufferB[gActiveBattler][1]);
                gChosenActionByBattler[gActiveBattler] = gBattleResources->bufferB[gActiveBattler][1];

                switch (gBattleResources->bufferB[gActiveBattler][1])
                {
                case B_ACTION_USE_MOVE:
                    if (AreAllMovesUnusable())
                    {
                        gBattleCommunication[gActiveBattler] = STATE_SELECTION_SCRIPT;
                        *(gBattleStruct->selectionScriptFinished + gActiveBattler) = FALSE;
                        *(gBattleStruct->stateIdAfterSelScript + gActiveBattler) = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                        *(gBattleStruct->moveTarget + gActiveBattler) = gBattleResources->bufferB[gActiveBattler][3];
                        return;
                    }
                    else if (gVolatileStructs[gActiveBattler].encoredMove != 0)
                    {
                        gChosenMoveByBattler[gActiveBattler] = gVolatileStructs[gActiveBattler].encoredMove;
                        *(gBattleStruct->chosenMovePositions + gActiveBattler) = gVolatileStructs[gActiveBattler].encoredMovePos;
                        gBattleCommunication[gActiveBattler] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                        return;
                    }
                    else
                    {
                        struct ChooseMoveStruct moveInfo;

                        moveInfo.mega = gBattleStruct->mega;
                        moveInfo.species = gBattleMons[gActiveBattler].species;
                        moveInfo.monType1 = gBattleMons[gActiveBattler].type1;
                        moveInfo.monType2 = gBattleMons[gActiveBattler].type2;
                        moveInfo.monType3 = gBattleMons[gActiveBattler].type3;

                        for (i = 0; i < MAX_MON_MOVES; i++)
                        {
                            moveInfo.moves[i] = gBattleMons[gActiveBattler].moves[i];
                            moveInfo.currentPp[i] = gBattleMons[gActiveBattler].pp[i];
                            moveInfo.maxPp[i] = CalculatePPWithBonus(
                                                            gBattleMons[gActiveBattler].moves[i],
                                                            gBattleMons[gActiveBattler].ppBonuses,
                                                            i);
                        }

                        BtlController_EmitChooseMove(0, (gBattleTypeFlags & BATTLE_TYPE_DOUBLE) != 0, FALSE, &moveInfo);
                        MarkBattlerForControllerExec(gActiveBattler);
                    }
                    break;
                case B_ACTION_USE_ITEM:
					#if B_ENABLE_DEBUG == TRUE
                    if (FlagGet(FLAG_SYS_NO_BAG_USE) || gBattleTypeFlags & (BATTLE_TYPE_LINK
                                            | BATTLE_TYPE_FRONTIER_NO_PYRAMID
                                            | BATTLE_TYPE_EREADER_TRAINER
                                            | BATTLE_TYPE_RECORDED_LINK))
                    {
                        RecordedBattle_ClearBattlerAction(gActiveBattler, 1);
                        gSelectionBattleScripts[gActiveBattler] = BattleScript_ActionSelectionItemsCantBeUsed;
                        gBattleCommunication[gActiveBattler] = STATE_SELECTION_SCRIPT;
                        *(gBattleStruct->selectionScriptFinished + gActiveBattler) = FALSE;
                        *(gBattleStruct->stateIdAfterSelScript + gActiveBattler) = STATE_BEFORE_ACTION_CHOSEN;
                        return;
                    }
					#endif
                    if (gBattleTypeFlags & (BATTLE_TYPE_LINK
                                            | BATTLE_TYPE_FRONTIER_NO_PYRAMID
                                            | BATTLE_TYPE_EREADER_TRAINER
                                            | BATTLE_TYPE_RECORDED_LINK)
                        || (gSaveBlock2Ptr->gameDifficulty == DIFFICULTY_EASY  && (gBattleTypeFlags & BATTLE_TYPE_TRAINER))
                        || (gSaveBlock2Ptr->gameDifficulty == DIFFICULTY_ELITE && (gBattleTypeFlags & BATTLE_TYPE_TRAINER))
                        || (gSaveBlock2Ptr->gameDifficulty == DIFFICULTY_ACE   && (gBattleTypeFlags & BATTLE_TYPE_TRAINER)))
                    {
                        RecordedBattle_ClearBattlerAction(gActiveBattler, 1);
                        gSelectionBattleScripts[gActiveBattler] = BattleScript_ActionSelectionItemsCantBeUsed;
                        gBattleCommunication[gActiveBattler] = STATE_SELECTION_SCRIPT;
                        *(gBattleStruct->selectionScriptFinished + gActiveBattler) = FALSE;
                        *(gBattleStruct->stateIdAfterSelScript + gActiveBattler) = STATE_BEFORE_ACTION_CHOSEN;
                        return;
                    }
                    else
                    {
                        BtlController_EmitChooseItem(0, gBattleStruct->battlerPartyOrders[gActiveBattler]);
                        MarkBattlerForControllerExec(gActiveBattler);
                    }
                    break;
                case B_ACTION_SWITCH:
                    *(gBattleStruct->battlerPartyIndexes + gActiveBattler) = gBattlerPartyIndexes[gActiveBattler];
                    if (gBattleTypeFlags & BATTLE_TYPE_ARENA
                        || !CanBattlerEscape(gActiveBattler))
                    {
                        BtlController_EmitChoosePokemon(0, PARTY_ACTION_CANT_SWITCH, PARTY_SIZE, ABILITY_NONE, gBattleStruct->battlerPartyOrders[gActiveBattler]);
                    }
                    else if ((i = IsAbilityPreventingEscape(gActiveBattler)))
                    {
                        BtlController_EmitChoosePokemon(0, ((i - 1) << 4) | PARTY_ACTION_ABILITY_PREVENTS, PARTY_SIZE, gBattleMons[i - 1].ability, gBattleStruct->battlerPartyOrders[gActiveBattler]);
                    }
                    else
                    {
                        if (gActiveBattler == 2 && gChosenActionByBattler[0] == B_ACTION_SWITCH)
                            BtlController_EmitChoosePokemon(0, PARTY_ACTION_CHOOSE_MON, *(gBattleStruct->monToSwitchIntoId + 0), ABILITY_NONE, gBattleStruct->battlerPartyOrders[gActiveBattler]);
                        else if (gActiveBattler == 3 && gChosenActionByBattler[1] == B_ACTION_SWITCH)
                            BtlController_EmitChoosePokemon(0, PARTY_ACTION_CHOOSE_MON, *(gBattleStruct->monToSwitchIntoId + 1), ABILITY_NONE, gBattleStruct->battlerPartyOrders[gActiveBattler]);
                        else
                            BtlController_EmitChoosePokemon(0, PARTY_ACTION_CHOOSE_MON, PARTY_SIZE, ABILITY_NONE, gBattleStruct->battlerPartyOrders[gActiveBattler]);
                    }
                    MarkBattlerForControllerExec(gActiveBattler);
                    break;
                case B_ACTION_SAFARI_BALL:
                    if (IsPlayerPartyAndPokemonStorageFull())
                    {
                        gSelectionBattleScripts[gActiveBattler] = BattleScript_PrintFullBox;
                        gBattleCommunication[gActiveBattler] = STATE_SELECTION_SCRIPT;
                        *(gBattleStruct->selectionScriptFinished + gActiveBattler) = FALSE;
                        *(gBattleStruct->stateIdAfterSelScript + gActiveBattler) = STATE_BEFORE_ACTION_CHOSEN;
                        return;
                    }
                    break;
                case B_ACTION_SAFARI_POKEBLOCK:
                    BtlController_EmitChooseItem(0, gBattleStruct->battlerPartyOrders[gActiveBattler]);
                    MarkBattlerForControllerExec(gActiveBattler);
                    break;
                case B_ACTION_CANCEL_PARTNER:
                    gBattleCommunication[gActiveBattler] = STATE_WAIT_SET_BEFORE_ACTION;
                    gBattleCommunication[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))] = STATE_BEFORE_ACTION_CHOSEN;
                    RecordedBattle_ClearBattlerAction(gActiveBattler, 1);
                    if (gBattleMons[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))].status2 & STATUS2_MULTIPLETURNS
                        || gBattleMons[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))].status2 & STATUS2_RECHARGE)
                    {
                        BtlController_EmitEndBounceEffect(0);
                        MarkBattlerForControllerExec(gActiveBattler);
                        return;
                    }
                    else if (gChosenActionByBattler[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))] == B_ACTION_SWITCH)
                    {
                        RecordedBattle_ClearBattlerAction(GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler))), 2);
                    }
                    else if (gChosenActionByBattler[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))] == B_ACTION_RUN)
                    {
                        RecordedBattle_ClearBattlerAction(GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler))), 1);
                    }
                    else if (gChosenActionByBattler[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))] == B_ACTION_USE_MOVE
                             && (gRoundStructs[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))].noValidMoves
                                || gVolatileStructs[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))].encoredMove))
                    {
                        RecordedBattle_ClearBattlerAction(GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler))), 1);
                    }
                    else if (gBattleTypeFlags & BATTLE_TYPE_PALACE
                             && gChosenActionByBattler[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))] == B_ACTION_USE_MOVE)
                    {
                        gRngValue = gBattlePalaceMoveSelectionRngValue;
                        RecordedBattle_ClearBattlerAction(GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler))), 1);
                    }
                    else
                    {
                        RecordedBattle_ClearBattlerAction(GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler))), 3);
                    }

                    gBattleStruct->mega.toEvolve &= ~(gBitTable[BATTLE_PARTNER(GetBattlerPosition(gActiveBattler))]);
                    BtlController_EmitEndBounceEffect(0);
                    MarkBattlerForControllerExec(gActiveBattler);
                    return;
                case B_ACTION_DEBUG:
                    #ifdef DEBUG_BUILD
                    BtlController_EmitDebugMenu(0);
                    MarkBattlerForControllerExec(gActiveBattler);
                    break;
                    #endif
                }
                
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER
                    && gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_TRAINER_HILL)
                    && gBattleResources->bufferB[gActiveBattler][1] == B_ACTION_RUN)
                {
                    gSelectionBattleScripts[gActiveBattler] = BattleScript_AskIfWantsToForfeitMatch;
                    gBattleCommunication[gActiveBattler] = STATE_SELECTION_SCRIPT_MAY_RUN;
                    *(gBattleStruct->selectionScriptFinished + gActiveBattler) = FALSE;
                    *(gBattleStruct->stateIdAfterSelScript + gActiveBattler) = STATE_BEFORE_ACTION_CHOSEN;
                    return;
                }
                #ifdef DEBUG_BUILD
                else if(FlagGet(FLAG_SYS_AUTOWIN)
                         && gBattleTypeFlags & BATTLE_TYPE_TRAINER
                         && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                         && gBattleResources->bufferB[gActiveBattler][1] == B_ACTION_RUN)
                {
                    gBattleCommunication[gActiveBattler]++;
                }
                #endif
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER
                         && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                         && gBattleResources->bufferB[gActiveBattler][1] == B_ACTION_RUN)
                {
                    gSelectionBattleScripts[gActiveBattler] = BattleScript_AskIfWantsToForfeitMatch;
                    gBattleCommunication[gActiveBattler] = STATE_SELECTION_SCRIPT_MAY_RUN;
                    *(gBattleStruct->selectionScriptFinished + gActiveBattler) = FALSE;
                    *(gBattleStruct->stateIdAfterSelScript + gActiveBattler) = STATE_BEFORE_ACTION_CHOSEN;
                    return;
                }
                
                if (IsRunningFromBattleImpossible() && gBattleResources->bufferB[gActiveBattler][1] == B_ACTION_RUN)
                {
                    gSelectionBattleScripts[gActiveBattler] = BattleScript_PrintCantEscapeFromBattle;
                    gBattleCommunication[gActiveBattler] = STATE_SELECTION_SCRIPT;
                    *(gBattleStruct->selectionScriptFinished + gActiveBattler) = FALSE;
                    *(gBattleStruct->stateIdAfterSelScript + gActiveBattler) = STATE_BEFORE_ACTION_CHOSEN;
                    return;
                }
                else
                {
                    gBattleCommunication[gActiveBattler]++;
                }
            }
            break;
        case STATE_WAIT_ACTION_CASE_CHOSEN:
            if (!(gBattleControllerExecFlags & ((gBitTable[gActiveBattler]) | (0xF << 28) | (gBitTable[gActiveBattler] << 4) | (gBitTable[gActiveBattler] << 8) | (gBitTable[gActiveBattler] << 12))))
            {
                switch (gChosenActionByBattler[gActiveBattler])
                {
                case B_ACTION_USE_MOVE:
                    switch (gBattleResources->bufferB[gActiveBattler][1])
                    {
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                    case 9:
                        gChosenActionByBattler[gActiveBattler] = gBattleResources->bufferB[gActiveBattler][1];
                        return;
                    case 15:
                        gChosenActionByBattler[gActiveBattler] = B_ACTION_SWITCH;
                        sub_803CDF8();
                        return;
                    default:
                        sub_818603C(2);
                        if ((gBattleResources->bufferB[gActiveBattler][2] | (gBattleResources->bufferB[gActiveBattler][3] << 8)) == 0xFFFF)
                        {
                            gBattleCommunication[gActiveBattler] = STATE_BEFORE_ACTION_CHOSEN;
                            RecordedBattle_ClearBattlerAction(gActiveBattler, 1);
                        }
                        else if (TrySetCantSelectMoveBattleScript())
                        {
                            RecordedBattle_ClearBattlerAction(gActiveBattler, 1);
                            gBattleCommunication[gActiveBattler] = STATE_SELECTION_SCRIPT;
                            *(gBattleStruct->selectionScriptFinished + gActiveBattler) = FALSE;
                            gBattleResources->bufferB[gActiveBattler][1] = B_ACTION_USE_MOVE;
                            *(gBattleStruct->stateIdAfterSelScript + gActiveBattler) = STATE_WAIT_ACTION_CHOSEN;
                            return;
                        }
                        else
                        {
                            if (!(gBattleTypeFlags & BATTLE_TYPE_PALACE))
                            {
                                RecordedBattle_SetBattlerAction(gActiveBattler, gBattleResources->bufferB[gActiveBattler][2]);
                                RecordedBattle_SetBattlerAction(gActiveBattler, gBattleResources->bufferB[gActiveBattler][3]);
                            }
                            *(gBattleStruct->chosenMovePositions + gActiveBattler) = gBattleResources->bufferB[gActiveBattler][2] & ~(RET_MEGA_EVOLUTION);
                            gChosenMoveByBattler[gActiveBattler] = gBattleMons[gActiveBattler].moves[*(gBattleStruct->chosenMovePositions + gActiveBattler)];
                            *(gBattleStruct->moveTarget + gActiveBattler) = gBattleResources->bufferB[gActiveBattler][3];
                            if (gBattleResources->bufferB[gActiveBattler][2] & RET_MEGA_EVOLUTION)
                                gBattleStruct->mega.toEvolve |= gBitTable[gActiveBattler];
                            gBattleCommunication[gActiveBattler]++;
                        }
                        break;
                    }
                    break;
                case B_ACTION_USE_ITEM:
                    if ((gBattleResources->bufferB[gActiveBattler][1] | (gBattleResources->bufferB[gActiveBattler][2] << 8)) == 0)
                    {
                        gBattleCommunication[gActiveBattler] = STATE_BEFORE_ACTION_CHOSEN;
                    }
                    else
                    {
                        gLastUsedItem = (gBattleResources->bufferB[gActiveBattler][1] | (gBattleResources->bufferB[gActiveBattler][2] << 8));
                        if (ItemId_GetPocket(gLastUsedItem) == POCKET_POKE_BALLS)
                            gBattleStruct->throwingPokeBall = TRUE;
                        gBattleCommunication[gActiveBattler]++;
                    }
                    break;
                case B_ACTION_SWITCH:
                    if (gBattleResources->bufferB[gActiveBattler][1] == PARTY_SIZE)
                    {
                        gBattleCommunication[gActiveBattler] = STATE_BEFORE_ACTION_CHOSEN;
                        RecordedBattle_ClearBattlerAction(gActiveBattler, 1);
                    }
                    else
                    {
                        sub_803CDF8();
                        gBattleCommunication[gActiveBattler]++;
                    }
                    break;
                case B_ACTION_RUN:
                    gHitMarker |= HITMARKER_RUN;
                    gBattleCommunication[gActiveBattler]++;
                    break;
                case B_ACTION_SAFARI_WATCH_CAREFULLY:
                    gBattleCommunication[gActiveBattler]++;
                    break;
                case B_ACTION_SAFARI_BALL:
                    gBattleCommunication[gActiveBattler]++;
                    break;
                case B_ACTION_THROW_BALL:
                    gBattleStruct->throwingPokeBall = TRUE;
                    gBattleCommunication[gActiveBattler]++;
                    break;
                case B_ACTION_SAFARI_POKEBLOCK:
                    if ((gBattleResources->bufferB[gActiveBattler][1] | (gBattleResources->bufferB[gActiveBattler][2] << 8)) != 0)
                    {
                        gBattleCommunication[gActiveBattler]++;
                    }
                    else
                    {
                        gBattleCommunication[gActiveBattler] = STATE_BEFORE_ACTION_CHOSEN;
                    }
                    break;
                case B_ACTION_SAFARI_GO_NEAR:
                    gBattleCommunication[gActiveBattler]++;
                    break;
                case B_ACTION_SAFARI_RUN:
                    gHitMarker |= HITMARKER_RUN;
                    gBattleCommunication[gActiveBattler]++;
                    break;
                case B_ACTION_WALLY_THROW:
                    gBattleCommunication[gActiveBattler]++;
                    break;
                case B_ACTION_DEBUG:
                    gBattleCommunication[gActiveBattler] = STATE_BEFORE_ACTION_CHOSEN;
                    break;
                }
            }
            break;
        case STATE_WAIT_ACTION_CONFIRMED_STANDBY:
            if (!(gBattleControllerExecFlags & ((gBitTable[gActiveBattler])
                                                | (0xF << 28)
                                                | (gBitTable[gActiveBattler] << 4)
                                                | (gBitTable[gActiveBattler] << 8)
                                                | (gBitTable[gActiveBattler] << 12))))
            {
                if (AllAtActionConfirmed())
                    i = TRUE;
                else
                    i = FALSE;

                if (((gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_DOUBLE)) != BATTLE_TYPE_DOUBLE)
                    || (position & BIT_FLANK) != B_FLANK_LEFT
                    || (*(&gBattleStruct->field_91) & gBitTable[GetBattlerAtPosition(position ^ BIT_FLANK)]))
                {
                    BtlController_EmitLinkStandbyMsg(0, 0, i);
                }
                else
                {
                    BtlController_EmitLinkStandbyMsg(0, 1, i);
                }
                MarkBattlerForControllerExec(gActiveBattler);
                gBattleCommunication[gActiveBattler]++;
            }
            break;
        case STATE_WAIT_ACTION_CONFIRMED:
            if (!(gBattleControllerExecFlags & ((gBitTable[gActiveBattler]) | (0xF << 28) | (gBitTable[gActiveBattler] << 4) | (gBitTable[gActiveBattler] << 8) | (gBitTable[gActiveBattler] << 12))))
            {
                gBattleCommunication[ACTIONS_CONFIRMED_COUNT]++;
            }
            break;
        case STATE_SELECTION_SCRIPT:
            if (*(gBattleStruct->selectionScriptFinished + gActiveBattler))
            {
                gBattleCommunication[gActiveBattler] = *(gBattleStruct->stateIdAfterSelScript + gActiveBattler);
            }
            else
            {
                gBattlerAttacker = gActiveBattler;
                gBattlescriptCurrInstr = gSelectionBattleScripts[gActiveBattler];
                if (!(gBattleControllerExecFlags & ((gBitTable[gActiveBattler]) | (0xF << 28) | (gBitTable[gActiveBattler] << 4) | (gBitTable[gActiveBattler] << 8) | (gBitTable[gActiveBattler] << 12))))
                {
                    gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
                }
                gSelectionBattleScripts[gActiveBattler] = gBattlescriptCurrInstr;
            }
            break;
        case STATE_WAIT_SET_BEFORE_ACTION:
            if (!(gBattleControllerExecFlags & ((gBitTable[gActiveBattler]) | (0xF << 28) | (gBitTable[gActiveBattler] << 4) | (gBitTable[gActiveBattler] << 8) | (gBitTable[gActiveBattler] << 12))))
            {
                gBattleCommunication[gActiveBattler] = STATE_BEFORE_ACTION_CHOSEN;
            }
            break;
        case STATE_SELECTION_SCRIPT_MAY_RUN:
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))){
                //Ran from in-game Trainer
                if (*(gBattleStruct->selectionScriptFinished + gActiveBattler))
                {
                    if (gBattleResources->bufferB[gActiveBattler][1] == B_ACTION_NOTHING_FAINTED)
                    {
                        u8 numWhiteOuts = 0 + VarGet(VAR_TIMES_WHITED_OUT);
                        numWhiteOuts++;
                        VarSet(VAR_TIMES_WHITED_OUT, numWhiteOuts);
                        
                        if(gActiveBattler == B_POSITION_PLAYER_LEFT){
                            gHitMarker |= HITMARKER_RUN;
                            gChosenActionByBattler[gActiveBattler] = B_ACTION_RUN;
                            gChosenActionByBattler[B_POSITION_PLAYER_RIGHT] = B_ACTION_RUN;
                            gBattleOutcome = B_OUTCOME_LOST;
                            gBattleCommunication[gActiveBattler] = STATE_WAIT_ACTION_CONFIRMED;
                            gBattleCommunication[B_POSITION_PLAYER_RIGHT] = STATE_WAIT_ACTION_CONFIRMED;
                        }
                        else{
                            gHitMarker |= HITMARKER_RUN;
                            gChosenActionByBattler[gActiveBattler] = B_ACTION_RUN;
                            gBattleOutcome = B_OUTCOME_LOST;
                            gBattleCommunication[gActiveBattler] = STATE_WAIT_ACTION_CONFIRMED;
                        }
                    }
                    else
                    {
                        RecordedBattle_ClearBattlerAction(gActiveBattler, 1);
                        gBattleCommunication[gActiveBattler] = *(gBattleStruct->stateIdAfterSelScript + gActiveBattler);
                    }
                }
                else
                {
                    gBattlerAttacker = gActiveBattler;
                    gBattlescriptCurrInstr = gSelectionBattleScripts[gActiveBattler];
                    if (!(gBattleControllerExecFlags & ((gBitTable[gActiveBattler]) | (0xF << 28) | (gBitTable[gActiveBattler] << 4) | (gBitTable[gActiveBattler] << 8) | (gBitTable[gActiveBattler] << 12))))
                    {
                        gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
                    }
                    gSelectionBattleScripts[gActiveBattler] = gBattlescriptCurrInstr;
                }
                break;
            }
            else{
                if (*(gBattleStruct->selectionScriptFinished + gActiveBattler))
                {
                    if (gBattleResources->bufferB[gActiveBattler][1] == B_ACTION_NOTHING_FAINTED)
                    {
                        gHitMarker |= HITMARKER_RUN;
                        gChosenActionByBattler[gActiveBattler] = B_ACTION_RUN;
                        gBattleCommunication[gActiveBattler] = STATE_WAIT_ACTION_CONFIRMED_STANDBY;
                    }
                    else
                    {
                        RecordedBattle_ClearBattlerAction(gActiveBattler, 1);
                        gBattleCommunication[gActiveBattler] = *(gBattleStruct->stateIdAfterSelScript + gActiveBattler);
                    }
                }
                else
                {
                    gBattlerAttacker = gActiveBattler;
                    gBattlescriptCurrInstr = gSelectionBattleScripts[gActiveBattler];
                    if (!(gBattleControllerExecFlags & ((gBitTable[gActiveBattler]) | (0xF << 28) | (gBitTable[gActiveBattler] << 4) | (gBitTable[gActiveBattler] << 8) | (gBitTable[gActiveBattler] << 12))))
                    {
                        gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
                    }
                    gSelectionBattleScripts[gActiveBattler] = gBattlescriptCurrInstr;
                }
                break;
            }
        }
    }

    // Check if everyone chose actions.
    if (gBattleCommunication[ACTIONS_CONFIRMED_COUNT] == gBattlersCount)
    {
        sub_818603C(1);
        
        if (WILD_DOUBLE_BATTLE && gBattleStruct->throwingPokeBall) {
            // if we choose to throw a ball with our second mon, skip the action of the first
            // (if we have chosen throw ball with first, second's is already skipped)
            gChosenActionByBattler[B_POSITION_PLAYER_LEFT] = B_ACTION_NOTHING_FAINTED;
        }
        
        gBattleMainFunc = SetActionsAndBattlersTurnOrder;

        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        {
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gChosenActionByBattler[i] == B_ACTION_SWITCH)
                    SwitchPartyOrderInGameMulti(i, *(gBattleStruct->monToSwitchIntoId + i));
            }
        }
    }
}

static bool8 AllAtActionConfirmed(void)
{
    s32 i, count;

    for (count = 0, i = 0; i < gBattlersCount; i++)
    {
        if (gBattleCommunication[i] == STATE_WAIT_ACTION_CONFIRMED)
            count++;
    }

    if (count + 1 == gBattlersCount)
        return TRUE;
    else
        return FALSE;
}

static void sub_803CDF8(void)
{
    *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = gBattleResources->bufferB[gActiveBattler][1];
    RecordedBattle_SetBattlerAction(gActiveBattler, gBattleResources->bufferB[gActiveBattler][1]);

    if (gBattleTypeFlags & BATTLE_TYPE_LINK && gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        *(gActiveBattler * 3 + (u8*)(gBattleStruct->battlerPartyOrders) + 0) &= 0xF;
        *(gActiveBattler * 3 + (u8*)(gBattleStruct->battlerPartyOrders) + 0) |= (gBattleResources->bufferB[gActiveBattler][2] & 0xF0);
        *(gActiveBattler * 3 + (u8*)(gBattleStruct->battlerPartyOrders) + 1) = gBattleResources->bufferB[gActiveBattler][3];

        *((gActiveBattler ^ BIT_FLANK) * 3 + (u8*)(gBattleStruct->battlerPartyOrders) + 0) &= (0xF0);
        *((gActiveBattler ^ BIT_FLANK) * 3 + (u8*)(gBattleStruct->battlerPartyOrders) + 0) |= (gBattleResources->bufferB[gActiveBattler][2] & 0xF0) >> 4;
        *((gActiveBattler ^ BIT_FLANK) * 3 + (u8*)(gBattleStruct->battlerPartyOrders) + 2) = gBattleResources->bufferB[gActiveBattler][3];
    }
}

void SwapTurnOrder(u8 id1, u8 id2)
{
    u32 temp;

    SWAP(gActionsByTurnOrder[id1], gActionsByTurnOrder[id2], temp);
    SWAP(gBattlerByTurnOrder[id1], gBattlerByTurnOrder[id2], temp);
}

u32 GetBattlerTotalSpeedStat(u8 battlerId, u8 calcType)
{
    u32 speed = gBattleMons[battlerId].speed;
    u32 ability = GetBattlerAbility(battlerId);
    u32 holdEffect = GetBattlerHoldEffect(battlerId, TRUE);

    // weather abilities
    if (WEATHER_HAS_EFFECT)
    {
        if (BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_SWIFT_SWIM, ability) && holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA && gBattleWeather & WEATHER_RAIN_ANY)
            speed = (speed * 150) / 100;

        if (BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_SEABORNE, ability) && holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA && gBattleWeather & WEATHER_RAIN_ANY)
            speed = (speed * 150) / 100;

        if (BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_CHLOROPHYLL, ability) && holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA && gBattleWeather & WEATHER_SUN_ANY)
            speed = (speed * 150) / 100;

        if (BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_BIG_LEAVES, ability) && holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA && gBattleWeather & WEATHER_SUN_ANY)
            speed = (speed * 150) / 100;

        if (BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_SAND_RUSH, ability) && gBattleWeather & WEATHER_SANDSTORM_ANY)
            speed = (speed * 150) / 100;

        if (BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_SLUSH_RUSH, ability) && gBattleWeather & WEATHER_HAIL_ANY)
            speed = (speed * 150) / 100;
    }
    
    if (GetAbilityStateAs(battlerId, ABILITY_PROTOSYNTHESIS).paradoxBoost.statId == STAT_SPEED)
        speed = speed * 3 / 2;
    
    if (GetAbilityStateAs(battlerId, ABILITY_QUARK_DRIVE).paradoxBoost.statId == STAT_SPEED)
        speed = speed * 3 / 2;

    // other abilities
    if (BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_QUICK_FEET, ability) && gBattleMons[battlerId].status1 & STATUS1_ANY)
        speed = (speed * 150) / 100;

    if (BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_SURGE_SURFER, ability) && GetCurrentTerrain() == STATUS_FIELD_ELECTRIC_TERRAIN)
        speed = (speed * 150) / 100;

    if (BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_SLOW_START, ability) && gVolatileStructs[battlerId].slowStartTimer != 0)
        speed /= 2;

    if (BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_VIOLENT_RUSH, ability) && gVolatileStructs[battlerId].isFirstTurn)
            speed = (speed * 150) / 100;

    if (BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_SPECIAL_VIOLENT_RUSH, ability) && gVolatileStructs[battlerId].isFirstTurn)
            speed = (speed * 150) / 100;

    if (BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_SHOWDOWN_MODE, ability) && gVolatileStructs[battlerId].isFirstTurn)
            speed = (speed * 150) / 100;
	
	if (BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_LEAD_COAT, ability))
        speed  = speed * 9 / 10;
	
	if (BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_CHROME_COAT, ability))
        speed  = speed * 9 / 10;

	if (BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_LIGHT_METAL, ability))
        speed = (speed * 130) / 100;
	
	/*if (BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_NOCTURNAL, ability) && !IsCurrentlyDay())
        speed *= 1.1;
    */

    if (gBattleResources->flags->flags[battlerId] & RESOURCE_FLAG_UNBURDEN)
        speed *= 2;

    // paralysis drop
    if (gBattleMons[battlerId].status1 & STATUS1_PARALYSIS && !BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_QUICK_FEET, ability))
        speed /= (B_PARALYSIS_SPEED >= GEN_7 ? 2 : 4);

    if (calcType == TOTAL_SPEED_PRIMARY) return speed;

    // various effects
    if (gSideStatuses[GET_BATTLER_SIDE(battlerId)] & SIDE_STATUS_TAILWIND)
        speed *= 2;

    if (gSideTimers[GET_BATTLER_SIDE2(battlerId)].swampTimer)
        speed /= 4;

    if (calcType == TOTAL_SPEED_SECONDARY) return speed;

    // item effects
    if (holdEffect == HOLD_EFFECT_MACHO_BRACE || holdEffect == HOLD_EFFECT_POWER_ITEM)
        speed /= 2;
    else if (holdEffect == HOLD_EFFECT_IRON_BALL)
        speed /= 2;
    else if (holdEffect == HOLD_EFFECT_CHOICE_SCARF)
        speed = (speed * 150) / 100;
    else if (holdEffect == HOLD_EFFECT_QUICK_POWDER && gBattleMons[battlerId].species == SPECIES_DITTO && !(gBattleMons[battlerId].status2 & STATUS2_TRANSFORMED))
        speed *= 2;

    // stat stages
    speed *= gStatStageRatios[gBattleMons[battlerId].statStages[STAT_SPEED]][0];
    speed /= gStatStageRatios[gBattleMons[battlerId].statStages[STAT_SPEED]][1];

    return speed;
}

u16 GetChosenMove(u32 battlerId)
{
    if (gRoundStructs[battlerId].noValidMoves)
        return MOVE_STRUGGLE;
    else
        return gBattleMons[battlerId].moves[*(gBattleStruct->chosenMovePositions + battlerId)];
}

u16 IsMyceliumMightActive(u32 battlerId)
{
    u16 ability = gBattleMons[battlerId].ability;

    if (BATTLER_HAS_ABILITY_FAST(battlerId, ABILITY_MYCELIUM_MIGHT, ability)) {
        const struct BattleMove *move = &gBattleMoves[GetChosenMove(battlerId)];
        return move->split == SPLIT_STATUS && move->target & !MOVE_TARGET_USER;
    }
    
    return FALSE;
}

s8 GetChosenMovePriority(u32 battlerId, u32 target)
{
    u16 move = GetChosenMove(battlerId);

    gRoundStructs[battlerId].pranksterElevated = 0;

    return GetMovePriority(battlerId, move, target);
}

s8 GetMovePriority(u32 battlerId, u16 move, u32 target)
{
    s8 priority;

    priority = gBattleMoves[move].priority;

    if(BATTLER_HAS_ABILITY(battlerId, ABILITY_OPPORTUNIST) && gBattleMons[target].hp <= gBattleMons[target].maxHP / 2)
        priority++;

    #define GALE_WINGS_CLONE(ability, type) if (BATTLER_HAS_ABILITY(battlerId, ability) \
                                                && GetTypeBeforeUsingMove(move, battlerId) == type \
                                                && (B_GALE_WINGS <= GEN_6 || BATTLER_MAX_HP(battlerId))) \
                                                    priority++;

    GALE_WINGS_CLONE(ABILITY_GALE_WINGS, TYPE_FLYING)
    GALE_WINGS_CLONE(ABILITY_FLAMING_SOUL, TYPE_FIRE)
    GALE_WINGS_CLONE(ABILITY_EARLY_GRAVE, TYPE_GHOST)
    GALE_WINGS_CLONE(ABILITY_FROZEN_SOUL, TYPE_ICE)
    GALE_WINGS_CLONE(ABILITY_VOLT_RUSH, TYPE_ELECTRIC)
    GALE_WINGS_CLONE(ABILITY_DARK_GALE_WINGS, TYPE_DARK)
    GALE_WINGS_CLONE(ABILITY_WATER_GALE_WINGS, TYPE_WATER)

    #undef GALE_WINGS_CLONE

    // Prankster
	if ((GetBattlerAbility(battlerId) == ABILITY_PRANKSTER || BattlerHasInnate(battlerId, ABILITY_PRANKSTER)) && IS_MOVE_STATUS(move))
    {
        gRoundStructs[battlerId].pranksterElevated = 1;
        priority++;
    }

    // Sighting System
	if (BATTLER_HAS_ABILITY(battlerId, ABILITY_SIGHTING_SYSTEM) && gBattleMoves[move].accuracy && gBattleMoves[move].accuracy <= 75)
    { 
        priority = priority - 3;
    }

    // Iron Barrage
	if (BATTLER_HAS_ABILITY(battlerId, ABILITY_IRON_BARRAGE) && gBattleMoves[move].accuracy && gBattleMoves[move].accuracy <= 75)
    { 
        priority = priority - 3;
    }
    
	if (gBattleMoves[move].effect == EFFECT_GRASSY_GLIDE && GetCurrentTerrain() == STATUS_FIELD_GRASSY_TERRAIN && IsBattlerGrounded(battlerId))
    {
        priority++;
    }
    
	if ((GetBattlerAbility(battlerId) == ABILITY_TRIAGE || BattlerHasInnate(battlerId, ABILITY_TRIAGE)))
    {
        switch (gBattleMoves[move].effect)
        {
        case EFFECT_RESTORE_HP:
        case EFFECT_REST:
        case EFFECT_MORNING_SUN:
        case EFFECT_MOONLIGHT:
        case EFFECT_SYNTHESIS:
        case EFFECT_HEAL_PULSE:
        case EFFECT_HEALING_WISH:
        case EFFECT_SWALLOW:
        case EFFECT_WISH:
        case EFFECT_SOFTBOILED:
        case EFFECT_ABSORB:
        case EFFECT_ROOST:
        case EFFECT_STRENGTH_SAP:
            priority += 3;
            break;
        }
    }
    
	if ((GetBattlerAbility(battlerId) == ABILITY_BLITZ_BOXER || BattlerHasInnate(battlerId, ABILITY_BLITZ_BOXER))
		&& IS_IRON_FIST(battlerId, move)
        && (B_GALE_WINGS <= GEN_6 || BATTLER_MAX_HP(battlerId)))
    {
        priority++;
    }

	if(BATTLER_HAS_ABILITY(battlerId, ABILITY_PERFECTIONIST) && 
       gBattleMoves[move].power <= 25 && 
       gBattleMoves[move].power > 0)
		priority++;

    if((gStatuses4[battlerId] & STATUS4_COILED) && (gBattleMoves[move].flags & FLAG_STRONG_JAW_BOOST)){
		priority++;
	}

    if (move == MOVE_RAZOR_WIND && (gSideStatuses[0] & SIDE_STATUS_TAILWIND || gSideStatuses[1] & SIDE_STATUS_TAILWIND))
        priority++;

    return priority;
}

#define MYCELIUM_MIGHT_AFFECTED(battler, move) (BATTLER_HAS_ABILITY(battler, ABILITY_MYCELIUM_MIGHT) && gBattleMoves[move].split == SPLIT_STATUS && gBattleMoves[move].target & !MOVE_TARGET_USER)

u8 GetWhoStrikesFirst(u8 battler1, u8 battler2, bool8 ignoreChosenMoves)
{
    u8 strikesFirst = 0;
    u32 speedBattler1 = 0, speedBattler2 = 0;
    u32 holdEffectBattler1 = 0, holdEffectBattler2 = 0;
    s8 priority1 = 0, priority2 = 0;

    // Battler 1
    speedBattler1 = GetBattlerTotalSpeedStat(battler1, TOTAL_SPEED_FULL);
    holdEffectBattler1 = GetBattlerHoldEffect(battler1, TRUE);

    // Quick Draw
    if (!ignoreChosenMoves && GetBattlerAbility(battler1) == ABILITY_QUICK_DRAW && !IS_MOVE_STATUS(gChosenMoveByBattler[battler1]) && Random() % 100 < 30)
        gRoundStructs[battler1].quickDraw = TRUE;
    
    // Quick Claw and Custap Berry
    if (!gRoundStructs[battler1].quickDraw
     && ((holdEffectBattler1 == HOLD_EFFECT_QUICK_CLAW && gRandomTurnNumber < (0xFFFF * GetBattlerHoldEffectParam(battler1)) / 100)
     || (!IsAbilityOnOpposingSide(battler1, ABILITY_UNNERVE)
      && holdEffectBattler1 == HOLD_EFFECT_CUSTAP_BERRY
      && HasEnoughHpToEatBerry(battler1, 4, gBattleMons[battler1].item))))
        gRoundStructs[battler1].usedCustapBerry = TRUE;

    // Battler 2
    speedBattler2 = GetBattlerTotalSpeedStat(battler2, TOTAL_SPEED_FULL);
    holdEffectBattler2 = GetBattlerHoldEffect(battler2, TRUE);
    // Quick Draw
    if (!ignoreChosenMoves && GetBattlerAbility(battler2) == ABILITY_QUICK_DRAW && !IS_MOVE_STATUS(gChosenMoveByBattler[battler2]) && Random() % 100 < 30)
        gRoundStructs[battler2].quickDraw = TRUE;
    // Quick Claw and Custap Berry
    if (!gRoundStructs[battler2].quickDraw
     && ((holdEffectBattler2 == HOLD_EFFECT_QUICK_CLAW && gRandomTurnNumber < (0xFFFF * GetBattlerHoldEffectParam(battler2)) / 100)
     || (!IsAbilityOnOpposingSide(battler2, ABILITY_UNNERVE)
      && holdEffectBattler2 == HOLD_EFFECT_CUSTAP_BERRY
      && HasEnoughHpToEatBerry(battler2, 4, gBattleMons[battler2].item))))
        gRoundStructs[battler2].usedCustapBerry = TRUE;

    if (!ignoreChosenMoves)
    {
        if (gChosenActionByBattler[battler1] == B_ACTION_USE_MOVE)
            priority1 = GetChosenMovePriority(battler1, battler2);
        if (gChosenActionByBattler[battler2] == B_ACTION_USE_MOVE)
            priority2 = GetChosenMovePriority(battler2, battler1);
    }

    if (priority1 == priority2)
    {
        u8 b1GoFirst = gRoundStructs[battler1].quickDraw + gRoundStructs[battler1].usedCustapBerry;
        u8 b2GoFirst = gRoundStructs[battler2].quickDraw + gRoundStructs[battler2].usedCustapBerry;
        u8 b1GoLast  = (holdEffectBattler1 == HOLD_EFFECT_LAGGING_TAIL)
                        + BATTLER_HAS_ABILITY(battler1, ABILITY_STALL)
                        + BATTLER_HAS_ABILITY(battler1, ABILITY_ATLAS)
                        + MYCELIUM_MIGHT_AFFECTED(battler1, GetChosenMove(battler1));
        u8 b2GoLast  = (holdEffectBattler2 == HOLD_EFFECT_LAGGING_TAIL)
                        + BATTLER_HAS_ABILITY(battler2, ABILITY_STALL)
                        + BATTLER_HAS_ABILITY(battler2, ABILITY_ATLAS)
                        + MYCELIUM_MIGHT_AFFECTED(battler2, GetChosenMove(battler2));

        if (b1GoFirst > b2GoFirst)
            strikesFirst = 0;
        else if (b1GoFirst < b2GoFirst)
            strikesFirst = 1;
        else if (b1GoLast > b2GoLast)
            strikesFirst = 1;
        else if (b1GoLast < b2GoLast)
            strikesFirst = 0;
        else
        {
            if (speedBattler1 == speedBattler2 && Random() & 1)
            {
                strikesFirst = 2; // same speeds, same priorities
            }
            else if (speedBattler1 < speedBattler2)
            {
                // battler2 has more speed
                if (IsTrickRoomActive())
                    strikesFirst = 0;
                else
                    strikesFirst = 1;
            }
            else
            {
                // battler1 has more speed
                if (IsTrickRoomActive())
                    strikesFirst = 1;
                else
                    strikesFirst = 0;
            }
        }
    }
    else if (priority1 < priority2)
    {
        strikesFirst = 1; // battler2's move has greater priority
    }
    else
    {
        strikesFirst = 0; // battler1's move has greater priority
    }

    return strikesFirst;
}

static void SetActionsAndBattlersTurnOrder(void)
{
    s32 turnOrderId = 0;
    s32 i, j;

    gAfterYouBattlers = gQuashedBattlers = 0;

    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
    {
        for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
        {
            gActionsByTurnOrder[turnOrderId] = gChosenActionByBattler[gActiveBattler];
            gBattlerByTurnOrder[turnOrderId] = gActiveBattler;
            turnOrderId++;
        }
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
            {
                if (gChosenActionByBattler[gActiveBattler] == B_ACTION_RUN)
                {
                    turnOrderId = 5;
                    break;
                }
            }
        }
        else
        {
            if (gChosenActionByBattler[0] == B_ACTION_RUN)
            {
                gActiveBattler = 0;
                turnOrderId = 5;
            }
            if (gChosenActionByBattler[2] == B_ACTION_RUN)
            {
                gActiveBattler = 2;
                turnOrderId = 5;
            }
        }

        if (turnOrderId == 5) // One of battlers wants to run.
        {
            gActionsByTurnOrder[0] = gChosenActionByBattler[gActiveBattler];
            gBattlerByTurnOrder[0] = gActiveBattler;
            turnOrderId = 1;
            for (i = 0; i < gBattlersCount; i++)
            {
                if (i != gActiveBattler)
                {
                    gActionsByTurnOrder[turnOrderId] = gChosenActionByBattler[i];
                    gBattlerByTurnOrder[turnOrderId] = i;
                    turnOrderId++;
                }
            }
            gBattleMainFunc = CheckMegaEvolutionBeforeTurn;
            gBattleStruct->mega.battlerId = 0;
            return;
        }
        else
        {
            for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
            {
                if (gChosenActionByBattler[gActiveBattler] == B_ACTION_USE_ITEM
                  || gChosenActionByBattler[gActiveBattler] == B_ACTION_SWITCH
                  || gChosenActionByBattler[gActiveBattler] == B_ACTION_THROW_BALL)
                {
                    gActionsByTurnOrder[turnOrderId] = gChosenActionByBattler[gActiveBattler];
                    gBattlerByTurnOrder[turnOrderId] = gActiveBattler;
                    turnOrderId++;
                }
            }
            for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
            {
                if (gChosenActionByBattler[gActiveBattler] != B_ACTION_USE_ITEM
                  && gChosenActionByBattler[gActiveBattler] != B_ACTION_SWITCH
                  && gChosenActionByBattler[gActiveBattler] != B_ACTION_THROW_BALL)
                {
                    gActionsByTurnOrder[turnOrderId] = gChosenActionByBattler[gActiveBattler];
                    gBattlerByTurnOrder[turnOrderId] = gActiveBattler;
                    turnOrderId++;
                }
            }
            for (i = 0; i < gBattlersCount - 1; i++)
            {
                for (j = i + 1; j < gBattlersCount; j++)
                {
                    u8 battler1 = gBattlerByTurnOrder[i];
                    u8 battler2 = gBattlerByTurnOrder[j];
                    if (gActionsByTurnOrder[i] != B_ACTION_USE_ITEM
                        && gActionsByTurnOrder[j] != B_ACTION_USE_ITEM
                        && gActionsByTurnOrder[i] != B_ACTION_SWITCH
                        && gActionsByTurnOrder[j] != B_ACTION_SWITCH
                        && gActionsByTurnOrder[i] != B_ACTION_THROW_BALL
                        && gActionsByTurnOrder[j] != B_ACTION_THROW_BALL)
                    {
                        if (GetWhoStrikesFirst(battler1, battler2, FALSE))
                            SwapTurnOrder(i, j);
                    }
                }
            }
        }
    }
    gBattleMainFunc = CheckMegaEvolutionBeforeTurn;
    gBattleStruct->mega.battlerId = 0;
}

static void TurnValuesCleanUp(bool8 var0)
{
    s32 i;

    for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
    {
        if (var0)
        {
            gVolatileStructs[gActiveBattler].protectedThisTurn = FALSE;
            gRoundStructs[gActiveBattler].protected = FALSE;
            gRoundStructs[gActiveBattler].spikyShielded = FALSE;
            gRoundStructs[gActiveBattler].kingsShielded = FALSE;
            gRoundStructs[gActiveBattler].banefulBunkered = FALSE;
            gRoundStructs[gActiveBattler].angelsWrathProtected = FALSE;
        }
        else
        {
            memset(&gRoundStructs[gActiveBattler], 0, sizeof(struct RoundStruct));

            if (gVolatileStructs[gActiveBattler].isFirstTurn)
                gVolatileStructs[gActiveBattler].isFirstTurn--;

            if (gVolatileStructs[gActiveBattler].rechargeTimer)
            {
                gVolatileStructs[gActiveBattler].rechargeTimer--;
                if (gVolatileStructs[gActiveBattler].rechargeTimer == 0)
                    gBattleMons[gActiveBattler].status2 &= ~(STATUS2_RECHARGE);
            }
        }

        if (gVolatileStructs[gActiveBattler].substituteHP == 0)
            gBattleMons[gActiveBattler].status2 &= ~(STATUS2_SUBSTITUTE);

        gTurnStructs[gActiveBattler].parentalBondOn = 0;
    }

    gSideStatuses[0] &= ~(SIDE_STATUS_QUICK_GUARD | SIDE_STATUS_WIDE_GUARD | SIDE_STATUS_CRAFTY_SHIELD | SIDE_STATUS_MAT_BLOCK);
    gSideStatuses[1] &= ~(SIDE_STATUS_QUICK_GUARD | SIDE_STATUS_WIDE_GUARD | SIDE_STATUS_CRAFTY_SHIELD | SIDE_STATUS_MAT_BLOCK);
    gSideTimers[0].followmeTimer = 0;
    gSideTimers[1].followmeTimer = 0;
}

void TurnStructsClear(void)
{
    memset(&gTurnStructs, 0, sizeof(gTurnStructs));
}

static void CheckMegaEvolutionBeforeTurn(void)
{
    if (!(gHitMarker & HITMARKER_RUN))
    {
        while (gBattleStruct->mega.battlerId < gBattlersCount)
        {
            gActiveBattler = gBattlerAttacker = gBattleStruct->mega.battlerId;
            gBattleStruct->mega.battlerId++;
            if (gBattleStruct->mega.toEvolve & gBitTable[gActiveBattler]
                && !(gRoundStructs[gActiveBattler].noValidMoves))
            {
                gBattleStruct->mega.toEvolve &= ~(gBitTable[gActiveBattler]);
                gLastUsedItem = gBattleMons[gActiveBattler].item;

                //Trainer Mega Evolution
                if((gBattleTypeFlags & BATTLE_TYPE_TRAINER) || GET_BATTLER_SIDE(gActiveBattler) == B_SIDE_PLAYER){
                    if (gBattleStruct->mega.isWishMegaEvo == TRUE)
                        BattleScriptExecute(BattleScript_WishMegaEvolution);
                    else
                        BattleScriptExecute(BattleScript_MegaEvolution);
                }
				else //Wild Mega Evolution
					BattleScriptExecute(BattleScript_WildTotemMegaEvolution);

                return;
            }
        }
    }

    #if B_MEGA_EVO_TURN_ORDER <= GEN_6
        gBattleMainFunc = CheckFocusPunch_ClearVarsBeforeTurnStarts;
        gBattleStruct->focusPunchBattlerId = 0;
    #else
        gBattleMainFunc = TryChangeTurnOrder; // This will just do nothing if no mon has mega evolved
    #endif  
}

// In gen7, priority and speed are recalculated during the turn in which a pokemon mega evolves
static void TryChangeTurnOrder(void)
{
    RecalculateMoveOrder(0, gBattlersCount);
    gBattleMainFunc = CheckFocusPunch_ClearVarsBeforeTurnStarts;
    gBattleStruct->focusPunchBattlerId = 0;
}

void RecalculateMoveOrder(u8 startingFrom, u8 processTo)
{
    s32 i, j;
    for (i = startingFrom; i < processTo - 1; i++)
    {
        if (gActionsByTurnOrder[i] != B_ACTION_USE_MOVE)
            continue;

        for (j = i + 1; j < processTo; j++)
        {
            if (gActionsByTurnOrder[j] != B_ACTION_USE_MOVE)
                continue;
            
            if (GetWhoStrikesFirst(gBattlerByTurnOrder[i], gBattlerByTurnOrder[j], FALSE))
                SwapTurnOrder(i, j);
        }
    }
}


static void CheckFocusPunch_ClearVarsBeforeTurnStarts(void)
{
    u32 i;

    if (!(gHitMarker & HITMARKER_RUN))
    {
        while (gBattleStruct->focusPunchBattlerId < gBattlersCount)
        {
            gActiveBattler = gBattlerAttacker = gBattleStruct->focusPunchBattlerId;
            gBattleStruct->focusPunchBattlerId++;
            if (!(gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP)
                && !(gVolatileStructs[gBattlerAttacker].truantCounter)
                && !(gRoundStructs[gActiveBattler].noValidMoves))
            {
                switch(gChosenMoveByBattler[gActiveBattler])
                {
                case MOVE_FOCUS_PUNCH:
                    BattleScriptExecute(BattleScript_FocusPunchSetUp);
                    return;
                break;
                /*case MOVE_BEAK_BLAST:
                    BattleScriptExecute(BattleScript_BeakBlastSetUp);
                    return;
                break;*/
                }
            }
        }
    }

    gBattleMainFunc = CheckQuickClaw_CustapBerryActivation;
    gBattleStruct->quickClawBattlerId = 0;
}

static void CheckQuickClaw_CustapBerryActivation(void)
{
    u32 i;

    if (!(gHitMarker & HITMARKER_RUN))
    {
        while (gBattleStruct->quickClawBattlerId < gBattlersCount)
        {
            gActiveBattler = gBattlerAttacker = gBattleStruct->quickClawBattlerId;
            gBattleStruct->quickClawBattlerId++;
            if (gChosenActionByBattler[gActiveBattler] == B_ACTION_USE_MOVE
             && gChosenMoveByBattler[gActiveBattler] != MOVE_FOCUS_PUNCH   // quick claw message doesn't need to activate here
             && (gRoundStructs[gActiveBattler].usedCustapBerry || gRoundStructs[gActiveBattler].quickDraw)
             && !(gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP)
             && !(gVolatileStructs[gBattlerAttacker].truantCounter)
             && !(gRoundStructs[gActiveBattler].noValidMoves))
            {
                if (gRoundStructs[gActiveBattler].usedCustapBerry)
                {
                    gRoundStructs[gActiveBattler].usedCustapBerry = FALSE;
                    gLastUsedItem = gBattleMons[gActiveBattler].item;
                    PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
                    if (GetBattlerHoldEffect(gActiveBattler, FALSE) == HOLD_EFFECT_CUSTAP_BERRY)
                    {
                        // don't record berry since its gone now
                        BattleScriptExecute(BattleScript_CustapBerryActivation);
                    }
                    else
                    {
                        RecordItemEffectBattle(gActiveBattler, GetBattlerHoldEffect(gActiveBattler, FALSE));
                        BattleScriptExecute(BattleScript_QuickClawActivation);
                    }
                }
                else if (gRoundStructs[gActiveBattler].quickDraw)
                {
                    if(gBattleMons[gActiveBattler].ability == ABILITY_QUICK_DRAW || 
                       BattlerHasInnate(gActiveBattler, ABILITY_QUICK_DRAW)){
                        gRoundStructs[gActiveBattler].quickDraw = FALSE;
                        gLastUsedAbility = gBattleScripting.abilityPopupOverwrite = ABILITY_QUICK_DRAW;
                        PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                        //gBattlerAbility = gActiveBattler;
                        RecordAbilityBattle(gActiveBattler, gLastUsedAbility);
                        BattleScriptExecute(BattleScript_QuickDrawActivation);
                    }
                    else{
                        BattleScriptExecute(BattleScript_QuickClawActivation);
                    }
                }
                return;
            }
        }
    }

    // setup stuff before turns/actions
    TryClearRageAndFuryCutter();
    gCurrentTurnActionNumber = 0;
    gCurrentActionFuncId = gActionsByTurnOrder[0];
    gBattleStruct->dynamicMoveType = 0;
    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        gBattleStruct->ateBoost[i] = FALSE;
        gTurnStructs[i].gemBoost = FALSE;
    }

    gBattleMainFunc = RunTurnActionsFunctions;
    gBattleCommunication[3] = 0;
    gBattleCommunication[4] = 0;
    gBattleScripting.multihitMoveEffect = 0;
    gBattleResources->battleScriptsStack->size = 0;
}

static void RunTurnActionsFunctions(void)
{
    if (gBattleOutcome != 0)
        gCurrentActionFuncId = B_ACTION_FINISHED;

    *(&gBattleStruct->savedTurnActionNumber) = gCurrentTurnActionNumber;
    sTurnActionsFuncsTable[gCurrentActionFuncId]();

    if (gCurrentTurnActionNumber >= gBattlersCount) // everyone did their actions, turn finished
    {
        gHitMarker &= ~(HITMARKER_PASSIVE_DAMAGE);
        gBattleMainFunc = sEndTurnFuncsTable[gBattleOutcome & 0x7F];
    }
    else
    {
        if (gBattleStruct->savedTurnActionNumber != gCurrentTurnActionNumber) // action turn has been done, clear hitmarker bits for another battlerId
        {
            gHitMarker &= ~(HITMARKER_NO_ATTACKSTRING);
            gHitMarker &= ~(HITMARKER_UNABLE_TO_USE_MOVE);
        }
    }
}

static void HandleEndTurn_BattleWon(void)
{
    gCurrentActionFuncId = 0;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
    {
        gSpecialVar_Result = gBattleOutcome;
        gBattleTextBuff1[0] = gBattleOutcome;
        gBattlerAttacker = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        gBattlescriptCurrInstr = BattleScript_LinkBattleWonOrLost;
        gBattleOutcome &= ~(B_OUTCOME_LINK_BATTLE_RAN);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER
            && gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_TRAINER_HILL | BATTLE_TYPE_EREADER_TRAINER))
    {
        BattleStopLowHpSound();
        gBattlescriptCurrInstr = BattleScript_FrontierTrainerBattleWon;

        if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
            PlayBGM(MUS_VICTORY_GYM_LEADER);
        else
            PlayBGM(MUS_VICTORY_TRAINER);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && !(gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        BattleStopLowHpSound();
        gBattlescriptCurrInstr = BattleScript_LocalTrainerBattleWon;

        switch (gTrainers[gTrainerBattleOpponent_A].trainerClass)
        {
        case TRAINER_CLASS_ELITE_FOUR:
        case TRAINER_CLASS_CHAMPION:
            PlayBGM(MUS_VICTORY_LEAGUE);
            break;
        case TRAINER_CLASS_TEAM_AQUA:
        case TRAINER_CLASS_TEAM_MAGMA:
        case TRAINER_CLASS_AQUA_ADMIN:
        case TRAINER_CLASS_AQUA_LEADER:
        case TRAINER_CLASS_MAGMA_ADMIN:
        case TRAINER_CLASS_MAGMA_LEADER:
            PlayBGM(MUS_VICTORY_AQUA_MAGMA);
            break;
        case TRAINER_CLASS_LEADER:
            PlayBGM(MUS_VICTORY_GYM_LEADER);
            break;
        case TRAINER_CLASS_PKMN_TRAINER_1:
            PlayBGM(DP_SEQ_WINCHAMP);
            break;
        default:
            PlayBGM(MUS_VICTORY_TRAINER);
            break;
        }
    }
    else
    {
        gBattlescriptCurrInstr = BattleScript_PayDayMoneyAndPickUpItems;
    }

    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

static void HandleEndTurn_BattleLost(void)
{
    gCurrentActionFuncId = 0;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
    {
        if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        {
            if (gBattleOutcome & B_OUTCOME_LINK_BATTLE_RAN)
            {
                gBattlescriptCurrInstr = BattleScript_PrintPlayerForfeitedLinkBattle;
                gBattleOutcome &= ~(B_OUTCOME_LINK_BATTLE_RAN);
                gSaveBlock2Ptr->frontier.disableRecordBattle = TRUE;
            }
            else
            {
                gBattlescriptCurrInstr = BattleScript_FrontierLinkBattleLost;
                gBattleOutcome &= ~(B_OUTCOME_LINK_BATTLE_RAN);
            }
        }
        else
        {
            gBattleTextBuff1[0] = gBattleOutcome;
            gBattlerAttacker = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
            gBattlescriptCurrInstr = BattleScript_LinkBattleWonOrLost;
            gBattleOutcome &= ~(B_OUTCOME_LINK_BATTLE_RAN);
        }
    }
    else
    {
        gBattlescriptCurrInstr = BattleScript_LocalBattleLost;
    }

    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

static void HandleEndTurn_RanFromBattle(void)
{
    gCurrentActionFuncId = 0;

    if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER && gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        gBattlescriptCurrInstr = BattleScript_PrintPlayerForfeited;
        gBattleOutcome = B_OUTCOME_FORFEITED;
        gSaveBlock2Ptr->frontier.disableRecordBattle = TRUE;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
    {
        gBattlescriptCurrInstr = BattleScript_PrintPlayerForfeited;
        gBattleOutcome = B_OUTCOME_FORFEITED;
    }
    else
    {
        switch (gRoundStructs[gBattlerAttacker].fleeFlag)
        {
        default:
            gBattlescriptCurrInstr = BattleScript_GotAwaySafely;
            break;
        case 1:
            gBattlescriptCurrInstr = BattleScript_SmokeBallEscape;
            break;
        case 2:
            gBattlescriptCurrInstr = BattleScript_RanAwayUsingMonAbility;
            break;
        }
    }

    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

static void HandleEndTurn_MonFled(void)
{
    gCurrentActionFuncId = 0;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, gBattlerPartyIndexes[gBattlerAttacker]);
    gBattlescriptCurrInstr = BattleScript_WildMonFled;

    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

static void HandleEndTurn_FinishBattle(void)
{
    u32 i;

    if (gCurrentActionFuncId == B_ACTION_TRY_FINISH || gCurrentActionFuncId == B_ACTION_FINISHED)
    {
        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                  | BATTLE_TYPE_RECORDED_LINK
                                  | BATTLE_TYPE_FIRST_BATTLE
                                  | BATTLE_TYPE_SAFARI
                                  | BATTLE_TYPE_EREADER_TRAINER
                                  | BATTLE_TYPE_WALLY_TUTORIAL
                                  | BATTLE_TYPE_FRONTIER)))
        {
            for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
            {
                if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
                {
                    if (gBattleResults.playerMon1Species == SPECIES_NONE)
                    {
                        gBattleResults.playerMon1Species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES, NULL);
                        GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_NICKNAME, gBattleResults.playerMon1Name);
                    }
                    else
                    {
                        gBattleResults.playerMon2Species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES, NULL);
                        GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_NICKNAME, gBattleResults.playerMon2Name);
                    }
                }
            }
            TryPutPokemonTodayOnAir();
        }

        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                  | BATTLE_TYPE_RECORDED_LINK
                                  | BATTLE_TYPE_TRAINER
                                  | BATTLE_TYPE_FIRST_BATTLE
                                  | BATTLE_TYPE_SAFARI
                                  | BATTLE_TYPE_FRONTIER
                                  | BATTLE_TYPE_EREADER_TRAINER
                                  | BATTLE_TYPE_WALLY_TUTORIAL))
            && gBattleResults.shinyWildMon)
        {
            TryPutBreakingNewsOnAir();
        }

        sub_8186444();
        BeginFastPaletteFade(3);
        FadeOutMapMusic(5);
        #if B_TRAINERS_KNOCK_OFF_ITEMS
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER || B_ALWAYS_RESTORE_ITEMS)
            TryRestoreStolenItems();
        #endif
        for (i = 0; i < PARTY_SIZE; i++)
        {
            UndoMegaEvolution(i);
            UndoFormChange(i, B_SIDE_PLAYER, FALSE);
            DoBurmyFormChange(i);
        }

		FlagClear(FLAG_SMART_AI);
		FlagClear(FLAG_TOTEM_BATTLE);

    #ifdef DEBUG_BUILD
        CheckForBadEggs();
    #endif

    #if B_RECALCULATE_STATS >= GEN_5
        // Recalculate the stats of every party member before the end
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2) != SPECIES_NONE
             && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2) != SPECIES_EGG)
            {
                CalculateMonStats(&gPlayerParty[i]);
            }
        }
    #endif
        gBattleMainFunc = FreeResetData_ReturnToOvOrDoEvolutions;
        gCB2_AfterEvolution = BattleMainCB2;
    }
    else
    {
        if (gBattleControllerExecFlags == 0)
            gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
    }
}

static void FreeResetData_ReturnToOvOrDoEvolutions(void)
{
    if (!gPaletteFade.active)
    {
		if (gDexnavBattle && (gBattleOutcome == B_OUTCOME_WON || gBattleOutcome == B_OUTCOME_CAUGHT))
            IncrementDexNavChain();
        else
            gSaveBlock1Ptr->dexNavChain = 0;
		
        gIsFishingEncounter = FALSE;
        gIsSurfingEncounter = FALSE;
        ResetSpriteData();
        if (gLeveledUpInBattle && (gBattleOutcome == B_OUTCOME_WON || gBattleOutcome == B_OUTCOME_CAUGHT))
        {
            gBattleMainFunc = TryEvolvePokemon;
        }
        else
        {
            gBattleMainFunc = ReturnFromBattleToOverworld;
            return;
        }
    }

    FreeAllWindowBuffers();
    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        FreeMonSpritesGfx();
        FreeBattleResources();
        FreeBattleSpritesData();
    }
}

static void TryEvolvePokemon(void)
{
    s32 i;

    while (gLeveledUpInBattle != 0)
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (gLeveledUpInBattle & gBitTable[i])
            {
                u16 species;
                u8 levelUpBits = gLeveledUpInBattle;

                levelUpBits &= ~(gBitTable[i]);
                gLeveledUpInBattle = levelUpBits;

                species = GetEvolutionTargetSpecies(&gPlayerParty[i], EVO_MODE_NORMAL, levelUpBits, SPECIES_NONE);
                if (species != SPECIES_NONE)
                {
                    FreeAllWindowBuffers();
                    gBattleMainFunc = WaitForEvoSceneToFinish;
                    EvolutionScene(&gPlayerParty[i], species, TRUE, i);
                    return;
                }
            }
        }
    }

    gBattleMainFunc = ReturnFromBattleToOverworld;
}

static void WaitForEvoSceneToFinish(void)
{
    if (gMain.callback2 == BattleMainCB2)
        gBattleMainFunc = TryEvolvePokemon;
}

static void ReturnFromBattleToOverworld(void)
{
    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        RandomlyGivePartyPokerus(gPlayerParty);
        PartySpreadPokerus(gPlayerParty);
    }

    if (gBattleTypeFlags & BATTLE_TYPE_LINK && gReceivedRemoteLinkPlayers != 0)
        return;

    gSpecialVar_Result = gBattleOutcome;
    gMain.inBattle = 0;
    gMain.callback1 = gPreBattleCallback1;

    if (gBattleTypeFlags & BATTLE_TYPE_ROAMER)
    {
        UpdateRoamerHPStatus(&gEnemyParty[0]);

#ifndef BUGFIX
        if ((gBattleOutcome & B_OUTCOME_WON) || gBattleOutcome == B_OUTCOME_CAUGHT)
#else
        if ((gBattleOutcome == B_OUTCOME_WON) || gBattleOutcome == B_OUTCOME_CAUGHT) // Bug: When Roar is used by roamer, gBattleOutcome is B_OUTCOME_PLAYER_TELEPORTED (5).
#endif                                                                               // & with B_OUTCOME_WON (1) will return TRUE and deactivates the roamer.
            SetRoamerInactive();
    }

    m4aSongNumStop(SE_LOW_HEALTH);
    SetMainCallback2(gMain.savedCallback);
}

void RunBattleScriptCommands_PopCallbacksStack(void)
{
    if (gCurrentActionFuncId == B_ACTION_TRY_FINISH || gCurrentActionFuncId == B_ACTION_FINISHED)
    {
        if (gBattleResources->battleCallbackStack->size != 0)
            gBattleResources->battleCallbackStack->size--;
        gBattleMainFunc = gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size];
    }
    else
    {
        if (gBattleControllerExecFlags == 0)
            gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
    }
}

void RunBattleScriptCommands(void)
{
    if (gBattleControllerExecFlags == 0)
        gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
}

#define HAS_ABILITY(abilityToCheck) (MonHasInnate(mon, abilityToCheck, disableRandomizer) || ability == abilityToCheck)
u8 GetMonMoveType(u16 move, struct Pokemon *mon, bool8 disableRandomizer){
    u32 moveType, ateType, attackerAbility, tempstuff;
    u16 item = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
    u16 holdEffect = ItemId_GetHoldEffect(item);
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    u8  abilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM, NULL);
    u16 ability = GetAbilityBySpecies(species, abilityNum);
    u8 type1 = gBaseStats[species].type1;
    u8 type2 = gBaseStats[species].type2;

    if(!disableRandomizer){
        ability =  RandomizeAbility(GetAbilityBySpecies(species, abilityNum), species, personality);
        type1 = RandomizeType(gBaseStats[species].type1, species, personality, TRUE);
        type2 = RandomizeType(gBaseStats[species].type2, species, personality, FALSE);
    }

    GET_MOVE_TYPE(move, moveType);

    if (move == MOVE_STRUGGLE)
        return TYPE_NORMAL;

    if (move == MOVE_RAGING_BULL)
    {
        switch (species)
        {
            case SPECIES_TAUROS_PALDEAN_COMBAT_BREED:
                return TYPE_FIGHTING;
            case SPECIES_TAUROS_PALDEAN_BLAZE_BREED:
                return TYPE_FIRE;
            case SPECIES_TAUROS_PALDEAN_AQUA_BREED:
                return TYPE_WATER;
        }
    }

    if (gBattleMoves[move].effect == EFFECT_HIDDEN_POWER)
    {
        return GetMonData(mon, MON_DATA_HP_TYPE, NULL);
    }
    else if (gBattleMoves[move].effect == EFFECT_CHANGE_TYPE_ON_ITEM)
    {
        if (holdEffect == gBattleMoves[move].argument)
            return ItemId_GetSecondaryId(item);
    }
    else if (gBattleMoves[move].effect == EFFECT_REVELATION_DANCE)
    {
        if (type1 != TYPE_MYSTERY)
            return type1;
        else if (type2 != TYPE_MYSTERY)
            return type2;
    }
    else if (gBattleMoves[move].effect == EFFECT_NATURAL_GIFT || gBattleMoves[move].effect == EFFECT_BERRY_SMASH)
    {
        if (ItemId_GetPocket(item) == POCKET_BERRIES)
            return gNaturalGiftTable[ITEM_TO_BERRY(item)].type;
    }
    //Sand Song
    if(HAS_ABILITY(ABILITY_SAND_SONG) && gBattleMoves[move].flags & FLAG_SOUND && moveType == TYPE_NORMAL){
        return TYPE_GROUND;
    }

    //Requiem
    if(HAS_ABILITY(ABILITY_BANSHEE) && gBattleMoves[move].flags & FLAG_SOUND && moveType == TYPE_NORMAL){
        return TYPE_GHOST;
    }

    if (gBattleMoves[move].type == TYPE_NORMAL
            && gBattleMoves[move].effect != EFFECT_HIDDEN_POWER
            && gBattleMoves[move].effect != EFFECT_WEATHER_BALL
            && gBattleMoves[move].effect != EFFECT_CHANGE_TYPE_ON_ITEM
            && gBattleMoves[move].effect != EFFECT_NATURAL_GIFT
            && gBattleMoves[move].effect != EFFECT_BERRY_SMASH
            && (   (HAS_ABILITY(ABILITY_PIXILATE)          && (ateType = TYPE_FAIRY))
                || (HAS_ABILITY(ABILITY_REFRIGERATE)       && (ateType = TYPE_ICE))
                || (HAS_ABILITY(ABILITY_REFRIGERATOR)      && (ateType = TYPE_ICE))
                || (HAS_ABILITY(ABILITY_AERILATE)          && (ateType = TYPE_FLYING))
		        || (HAS_ABILITY(ABILITY_IMMOLATE)          && (ateType = TYPE_FIRE))
			    || (HAS_ABILITY(ABILITY_SOLAR_FLARE)       && (ateType = TYPE_FIRE))
				|| (HAS_ABILITY(ABILITY_TECTONIZE)         && (ateType = TYPE_GROUND))
				|| (HAS_ABILITY(ABILITY_FIGHT_SPIRIT)      && (ateType = TYPE_FIGHTING))
                || (HAS_ABILITY(ABILITY_INTOXICATE)        && (ateType = TYPE_POISON))
                || (HAS_ABILITY(ABILITY_HYDRATE)           && (ateType = TYPE_WATER))
                || (HAS_ABILITY(ABILITY_GALVANIZE)         && (ateType = TYPE_ELECTRIC))
                || (HAS_ABILITY(ABILITY_POLLINATE)         && (ateType = TYPE_BUG))
				|| (HAS_ABILITY(ABILITY_SPECTRAL_SHROUD)   && (ateType = TYPE_GHOST))
				|| (HAS_ABILITY(ABILITY_SPECTRALIZE)       && (ateType = TYPE_GHOST))
                || (HAS_ABILITY(ABILITY_MINERALIZE)        && (ateType = TYPE_ROCK))
                || (HAS_ABILITY(ABILITY_DRACONIZE)         && (ateType = TYPE_DRAGON))
                || (HAS_ABILITY(ABILITY_EMANATE)           && (ateType = TYPE_PSYCHIC))
                || (HAS_ABILITY(ABILITY_ENLIGHTENED)       && (ateType = TYPE_PSYCHIC))
                || (HAS_ABILITY(ABILITY_FERTILIZE)         && (ateType = TYPE_GRASS))
                )
            ){
        return ateType;
    }

    else if (move == MOVE_AURA_WHEEL && species == SPECIES_MORPEKO_HANGRY)
        return TYPE_DARK;
	
	//Crystallize
	if(HAS_ABILITY(ABILITY_CRYSTALLIZE)){
		if(gBattleMoves[move].type == TYPE_ROCK)
			return TYPE_ICE;
	}
    //Normalize
    if(HAS_ABILITY(ABILITY_NORMALIZE)){
        if (gBattleMoves[move].type != TYPE_NORMAL
             && gBattleMoves[move].effect != EFFECT_HIDDEN_POWER
             && gBattleMoves[move].effect != EFFECT_WEATHER_BALL)
        return TYPE_NORMAL;
    }
    //Liquid Voice
    if(HAS_ABILITY(ABILITY_LIQUID_VOICE)){
        if (gBattleMoves[move].flags & FLAG_SOUND)
            return TYPE_WATER;
    }
	//Fight Spirit
	if(HAS_ABILITY(ABILITY_FIGHT_SPIRIT)){
		if(gBattleMoves[move].type == TYPE_NORMAL
             && gBattleMoves[move].effect != EFFECT_HIDDEN_POWER
             && gBattleMoves[move].effect != EFFECT_WEATHER_BALL
             && gBattleMoves[move].effect != EFFECT_CHANGE_TYPE_ON_ITEM
             && gBattleMoves[move].effect != EFFECT_NATURAL_GIFT
             && gBattleMoves[move].effect != EFFECT_BERRY_SMASH)
				return TYPE_FIGHTING;
	}

    return gBattleMoves[move].type;
}
#undef HAS_ABILITY

u8 GetTypeBeforeUsingMove(u16 move, u8 battlerAtk){
    u32 moveType, ateType, attackerAbility, tempstuff;
    u16 holdEffect = GetBattlerHoldEffect(battlerAtk, TRUE);

    if (move == MOVE_STRUGGLE)
        return TYPE_NORMAL;
    
    if (move == MOVE_RAGING_BULL)
    {
        switch (gBattleMons[battlerAtk].species)
        {
            case SPECIES_TAUROS_PALDEAN_COMBAT_BREED:
                return TYPE_FIGHTING;
            case SPECIES_TAUROS_PALDEAN_BLAZE_BREED:
                return TYPE_FIRE;
            case SPECIES_TAUROS_PALDEAN_AQUA_BREED:
                return TYPE_WATER;
        }
    }

    if (gBattleMoves[move].effect == EFFECT_WEATHER_BALL)
    {
        if (WEATHER_HAS_EFFECT)
        {
            if (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_CHLOROPLAST) || BATTLER_HAS_ABILITY(battlerAtk, ABILITY_BIG_LEAVES))
                return TYPE_FIRE;
            else if (gBattleWeather & WEATHER_RAIN_ANY && holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA)
                return TYPE_WATER;
            else if (gBattleWeather & WEATHER_SANDSTORM_ANY)
                return TYPE_ROCK;
            else if (gBattleWeather & WEATHER_SUN_ANY && holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA)
                return TYPE_FIRE;
            else if (gBattleWeather & WEATHER_HAIL_ANY)
                return TYPE_ICE;
            else
                return TYPE_NORMAL;
        }
    }
    else if (gBattleMoves[move].effect == EFFECT_HIDDEN_POWER)
    {
        return gBattleMons[gBattlerAttacker].hpType;
    }
    else if (gBattleMoves[move].effect == EFFECT_CHANGE_TYPE_ON_ITEM)
    {
        if (holdEffect == gBattleMoves[move].argument)
            return ItemId_GetSecondaryId(gBattleMons[battlerAtk].item);
    }
    else if (gBattleMoves[move].effect == EFFECT_REVELATION_DANCE)
    {
        if (gBattleMons[battlerAtk].type1 != TYPE_MYSTERY)
            return gBattleMons[battlerAtk].type1;
        else if (gBattleMons[battlerAtk].type2 != TYPE_MYSTERY)
            return gBattleMons[battlerAtk].type2;
        else if (gBattleMons[battlerAtk].type3 != TYPE_MYSTERY)
            return gBattleMons[battlerAtk].type3;
    }
    else if (gBattleMoves[move].effect == EFFECT_NATURAL_GIFT || gBattleMoves[move].effect == EFFECT_BERRY_SMASH)
    {
        if (ItemId_GetPocket(gBattleMons[battlerAtk].item) == POCKET_BERRIES)
            return gNaturalGiftTable[ITEM_TO_BERRY(gBattleMons[battlerAtk].item)].type;
    }
    else if (gBattleMoves[move].effect == EFFECT_TERRAIN_PULSE)
    {
        if (IsBattlerTerrainAffected(battlerAtk, STATUS_FIELD_TERRAIN_ANY))
        {
            if (GetCurrentTerrain() == STATUS_FIELD_ELECTRIC_TERRAIN)
                return TYPE_ELECTRIC;
            else if (GetCurrentTerrain() == STATUS_FIELD_GRASSY_TERRAIN)
                return TYPE_GRASS;
            else if (GetCurrentTerrain() == STATUS_FIELD_MISTY_TERRAIN)
                return TYPE_FAIRY;
            else if (GetCurrentTerrain() == STATUS_FIELD_PSYCHIC_TERRAIN)
                return TYPE_PSYCHIC;
            else //failsafe
                return TYPE_NORMAL;
        }
    }

    attackerAbility = GetBattlerAbility(battlerAtk);
    GET_MOVE_TYPE(move, moveType);

    if ((gFieldStatuses & STATUS_FIELD_ION_DELUGE && moveType == TYPE_NORMAL) || gStatuses4[battlerAtk] & STATUS4_ELECTRIFIED)
        return TYPE_ELECTRIC;
    else if (gBattleMoves[move].flags & FLAG_SOUND && moveType == TYPE_NORMAL && BATTLER_HAS_ABILITY(battlerAtk, ABILITY_SAND_SONG))
        return TYPE_GROUND;
    else if (gBattleMoves[move].flags & FLAG_SOUND && moveType == TYPE_NORMAL && BATTLER_HAS_ABILITY(battlerAtk, ABILITY_BANSHEE))
        return TYPE_GHOST;
    else if (gBattleMoves[move].type == TYPE_NORMAL
             && gBattleMoves[move].effect != EFFECT_HIDDEN_POWER
             && gBattleMoves[move].effect != EFFECT_WEATHER_BALL
             && gBattleMoves[move].effect != EFFECT_CHANGE_TYPE_ON_ITEM
             && gBattleMoves[move].effect != EFFECT_NATURAL_GIFT
             && gBattleMoves[move].effect != EFFECT_BERRY_SMASH
             && (   (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_PIXILATE, attackerAbility)        && (ateType = TYPE_FAIRY))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_REFRIGERATE, attackerAbility)     && (ateType = TYPE_ICE))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_REFRIGERATOR, attackerAbility)    && (ateType = TYPE_ICE))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_AERILATE, attackerAbility)        && (ateType = TYPE_FLYING))
				 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_IMMOLATE, attackerAbility)        && (ateType = TYPE_FIRE))
				 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_SOLAR_FLARE, attackerAbility)     && (ateType = TYPE_FIRE))
				 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_TECTONIZE, attackerAbility)       && (ateType = TYPE_GROUND))
				 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_FIGHT_SPIRIT, attackerAbility)    && (ateType = TYPE_FIGHTING))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_INTOXICATE, attackerAbility)      && (ateType = TYPE_POISON))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_HYDRATE, attackerAbility)         && (ateType = TYPE_WATER))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_GALVANIZE, attackerAbility)       && (ateType = TYPE_ELECTRIC))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_POLLINATE, attackerAbility)       && (ateType = TYPE_BUG))
				 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_SPECTRAL_SHROUD, attackerAbility) && (ateType = TYPE_GHOST))
				 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_SPECTRALIZE, attackerAbility)     && (ateType = TYPE_GHOST))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_MINERALIZE, attackerAbility)      && (ateType = TYPE_ROCK))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_DRACONIZE, attackerAbility)       && (ateType = TYPE_DRAGON))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_EMANATE, attackerAbility)         && (ateType = TYPE_PSYCHIC))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_ENLIGHTENED, attackerAbility)     && (ateType = TYPE_PSYCHIC))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_FERTILIZE, attackerAbility)       && (ateType = TYPE_GRASS))
                )
             )
        return ateType;
	else if(gBattleMoves[move].type == TYPE_ROCK && BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_CRYSTALLIZE, attackerAbility))
		return TYPE_ICE;
    else if (gBattleMoves[move].type != TYPE_NORMAL
             && gBattleMoves[move].effect != EFFECT_HIDDEN_POWER
             && gBattleMoves[move].effect != EFFECT_WEATHER_BALL
             && attackerAbility == ABILITY_NORMALIZE)
        return TYPE_NORMAL;
    else if (gBattleMoves[move].flags & FLAG_SOUND &&
             BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_LIQUID_VOICE, attackerAbility))
        return TYPE_WATER;
    else if (gStatuses4[battlerAtk] & STATUS4_PLASMA_FISTS && moveType == TYPE_NORMAL)
        return TYPE_ELECTRIC;
    else if (move == MOVE_AURA_WHEEL && gBattleMons[battlerAtk].species == SPECIES_MORPEKO_HANGRY)
        return TYPE_DARK;

    return gBattleMoves[move].type;
}

void SetTypeBeforeUsingMove(u16 move, u8 battlerAtk)
{
    u32 moveType, ateType, attackerAbility;
    u16 holdEffect = GetBattlerHoldEffect(battlerAtk, TRUE);


    gBattleStruct->dynamicMoveType = 0;
    gBattleStruct->ateBoost[battlerAtk] = 0;
    gTurnStructs[battlerAtk].gemBoost = FALSE;

    if (move == MOVE_RAGING_BULL)
    {
        switch (gBattleMons[battlerAtk].species)
        {
            case SPECIES_TAUROS_PALDEAN_COMBAT_BREED:
                gBattleStruct->dynamicMoveType = TYPE_FIGHTING | 0x80;
                break;
            case SPECIES_TAUROS_PALDEAN_BLAZE_BREED:
                gBattleStruct->dynamicMoveType = TYPE_FIRE | 0x80;
                break;
            case SPECIES_TAUROS_PALDEAN_AQUA_BREED:
                gBattleStruct->dynamicMoveType = TYPE_WATER | 0x80;
                break;
        }
    }

    if (gBattleMoves[move].effect == EFFECT_WEATHER_BALL)
    {
        if (WEATHER_HAS_EFFECT)
        {
            if (BATTLER_HAS_ABILITY(battlerAtk, ABILITY_CHLOROPLAST) || BATTLER_HAS_ABILITY(battlerAtk, ABILITY_BIG_LEAVES))
                gBattleStruct->dynamicMoveType = TYPE_FIRE | 0x80;
            else if (gBattleWeather & WEATHER_RAIN_ANY && holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA)
                gBattleStruct->dynamicMoveType = TYPE_WATER | 0x80;
            else if (gBattleWeather & WEATHER_SANDSTORM_ANY)
                gBattleStruct->dynamicMoveType = TYPE_ROCK | 0x80;
            else if (gBattleWeather & WEATHER_SUN_ANY && holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA)
                gBattleStruct->dynamicMoveType = TYPE_FIRE | 0x80;
            else if (gBattleWeather & WEATHER_HAIL_ANY)
                gBattleStruct->dynamicMoveType = TYPE_ICE | 0x80;
            else
                gBattleStruct->dynamicMoveType = TYPE_NORMAL | 0x80;
        }
    }
    else if (gBattleMoves[move].effect == EFFECT_HIDDEN_POWER)
    {
        gBattleStruct->dynamicMoveType = gBattleMons[battlerAtk].hpType | 0xC0;
    }
    else if (gBattleMoves[move].effect == EFFECT_CHANGE_TYPE_ON_ITEM)
    {
        if (holdEffect == gBattleMoves[move].argument)
            gBattleStruct->dynamicMoveType = ItemId_GetSecondaryId(gBattleMons[battlerAtk].item) | 0x80;
    }
    else if (gBattleMoves[move].effect == EFFECT_REVELATION_DANCE)
    {
        if (gBattleMons[battlerAtk].type1 != TYPE_MYSTERY)
            gBattleStruct->dynamicMoveType = gBattleMons[battlerAtk].type1 | 0x80;
        else if (gBattleMons[battlerAtk].type2 != TYPE_MYSTERY)
            gBattleStruct->dynamicMoveType = gBattleMons[battlerAtk].type2 | 0x80;
        else if (gBattleMons[battlerAtk].type3 != TYPE_MYSTERY)
            gBattleStruct->dynamicMoveType = gBattleMons[battlerAtk].type3 | 0x80;
    }
    else if (gBattleMoves[move].effect == EFFECT_NATURAL_GIFT || gBattleMoves[move].effect == EFFECT_BERRY_SMASH)
    {
        if (ItemId_GetPocket(gBattleMons[battlerAtk].item) == POCKET_BERRIES)
            gBattleStruct->dynamicMoveType = gNaturalGiftTable[ITEM_TO_BERRY(gBattleMons[battlerAtk].item)].type;
    }
    else if (gBattleMoves[move].effect == EFFECT_TERRAIN_PULSE)
    {
        if (IsBattlerTerrainAffected(battlerAtk, STATUS_FIELD_TERRAIN_ANY))
        {
            if (GetCurrentTerrain() == STATUS_FIELD_ELECTRIC_TERRAIN)
                gBattleStruct->dynamicMoveType = TYPE_ELECTRIC | 0x80;
            else if (GetCurrentTerrain() == STATUS_FIELD_GRASSY_TERRAIN)
                gBattleStruct->dynamicMoveType = TYPE_GRASS | 0x80;
            else if (GetCurrentTerrain() == STATUS_FIELD_MISTY_TERRAIN)
                gBattleStruct->dynamicMoveType = TYPE_FAIRY | 0x80;
            else if (GetCurrentTerrain() == STATUS_FIELD_PSYCHIC_TERRAIN)
                gBattleStruct->dynamicMoveType = TYPE_PSYCHIC | 0x80;
            else //failsafe
                gBattleStruct->dynamicMoveType = TYPE_NORMAL | 0x80;
        }
    }

    attackerAbility = GetBattlerAbility(battlerAtk);
    GET_MOVE_TYPE(move, moveType);
    if ((gFieldStatuses & STATUS_FIELD_ION_DELUGE && moveType == TYPE_NORMAL)
        || gStatuses4[battlerAtk] & STATUS4_ELECTRIFIED)
    {
        gBattleStruct->dynamicMoveType = 0x80 | TYPE_ELECTRIC;
    }
    else if (gBattleMoves[move].flags & FLAG_SOUND && gBattleMoves[move].type == TYPE_NORMAL && BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_SAND_SONG, attackerAbility))
    {
        gBattleStruct->dynamicMoveType = 0x80 | TYPE_GROUND;
        gBattleStruct->ateBoost[battlerAtk] = 1;
    }
    else if (gBattleMoves[move].flags & FLAG_SOUND && gBattleMoves[move].type == TYPE_NORMAL && BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_BANSHEE, attackerAbility))
    {
        gBattleStruct->dynamicMoveType = 0x80 | TYPE_GHOST;
        gBattleStruct->ateBoost[battlerAtk] = 1;
    }
    else if (gBattleMoves[move].type == TYPE_NORMAL
             && gBattleMoves[move].effect != EFFECT_HIDDEN_POWER
             && gBattleMoves[move].effect != EFFECT_WEATHER_BALL
             && gBattleMoves[move].effect != EFFECT_CHANGE_TYPE_ON_ITEM
             && gBattleMoves[move].effect != EFFECT_NATURAL_GIFT
             && gBattleMoves[move].effect != EFFECT_BERRY_SMASH
             && (   (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_PIXILATE, attackerAbility)            && (ateType = TYPE_FAIRY))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_REFRIGERATE, attackerAbility)         && (ateType = TYPE_ICE))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_REFRIGERATOR, attackerAbility)        && (ateType = TYPE_ICE))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_AERILATE, attackerAbility)            && (ateType = TYPE_FLYING))
				 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_IMMOLATE, attackerAbility)            && (ateType = TYPE_FIRE))
				 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_SOLAR_FLARE, attackerAbility)         && (ateType = TYPE_FIRE))
				 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_TECTONIZE, attackerAbility)           && (ateType = TYPE_GROUND))
				 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_FIGHT_SPIRIT, attackerAbility)        && (ateType = TYPE_FIGHTING))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_INTOXICATE, attackerAbility)          && (ateType = TYPE_POISON))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_HYDRATE, attackerAbility)             && (ateType = TYPE_WATER))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_GALVANIZE, attackerAbility)           && (ateType = TYPE_ELECTRIC))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_POLLINATE, attackerAbility)           && (ateType = TYPE_BUG))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_SPECTRAL_SHROUD, attackerAbility)     && (ateType = TYPE_GHOST))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_SPECTRALIZE, attackerAbility)         && (ateType = TYPE_GHOST))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_MINERALIZE, attackerAbility)          && (ateType = TYPE_ROCK))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_DRACONIZE, attackerAbility)           && (ateType = TYPE_DRAGON))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_EMANATE, attackerAbility)             && (ateType = TYPE_PSYCHIC))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_ENLIGHTENED, attackerAbility)         && (ateType = TYPE_PSYCHIC))
                 || (BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_FERTILIZE, attackerAbility)           && (ateType = TYPE_GRASS))
                )
             )
    {
        gBattleStruct->dynamicMoveType = 0x80 | ateType;
        gBattleStruct->ateBoost[battlerAtk] = 1;
    }
	else if(gBattleMoves[move].type == TYPE_ROCK && BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_CRYSTALLIZE, attackerAbility) && (ateType = TYPE_ICE)){
		ateType = TYPE_ICE;
		gBattleStruct->dynamicMoveType = 0x80 | ateType;
		gBattleStruct->ateBoost[battlerAtk] = 1;
	}
    else if (gBattleMoves[move].type != TYPE_NORMAL
             && gBattleMoves[move].effect != EFFECT_HIDDEN_POWER
             && gBattleMoves[move].effect != EFFECT_WEATHER_BALL
             && attackerAbility == ABILITY_NORMALIZE)
    {
        gBattleStruct->dynamicMoveType = 0x80 | TYPE_NORMAL;
        gBattleStruct->ateBoost[battlerAtk] = 1;
    }
    else if (gBattleMoves[move].flags & FLAG_SOUND &&
            BATTLER_HAS_ABILITY_FAST(battlerAtk, ABILITY_LIQUID_VOICE, attackerAbility))
    {
        gBattleStruct->dynamicMoveType = 0x80 | TYPE_WATER;
    }
    else if (gStatuses4[battlerAtk] & STATUS4_PLASMA_FISTS && moveType == TYPE_NORMAL)
    {
        gBattleStruct->dynamicMoveType = 0x80 | TYPE_ELECTRIC;
    }
    else if (move == MOVE_AURA_WHEEL && gBattleMons[battlerAtk].species == SPECIES_MORPEKO_HANGRY)
    {
        gBattleStruct->dynamicMoveType = 0x80 | TYPE_DARK;
    }

    // Check if a gem should activate.
    GET_MOVE_TYPE(move, moveType);
    if (holdEffect == HOLD_EFFECT_GEMS
        && moveType == ItemId_GetSecondaryId(gBattleMons[battlerAtk].item))
    {
        gTurnStructs[battlerAtk].gemParam = GetBattlerHoldEffectParam(battlerAtk);
        gTurnStructs[battlerAtk].gemBoost = TRUE;
    }
}

// special to set a field's totem boost(s)
// inputs:
//  var8000: battlerId
//  var8001 - var8007: stat changes
void SetTotemBoost(void)
{
    u8 battlerId = gSpecialVar_0x8000;
    u8 i;

    for (i = 0; i < (NUM_BATTLE_STATS - 1); i++)
    {
        if (*(&gSpecialVar_0x8001 + i))
        {
            gTotemBoosts[battlerId].stats |= (1 << i);
            gTotemBoosts[battlerId].statChanges[i] = *(&gSpecialVar_0x8001 + i);
            gTotemBoosts[battlerId].stats |= 0x80;  // used as a flag for the "totem flared to life" script
        }
    }
}


u16 selectMoves (u16 species, u8 i, u16 atk, u16 spAtk)
{    
    //generated by code
    static const u16 oldPlayerMoveTypeArrays[][3] = 
    {
        {0, 4, 15}, //(0)Type One: Normal, Type Two: Normal, Result: Normal, Ground, Ice - Score: 597
        {0, 1, 4}, //(1)Type One: Normal, Type Two: Fighting, Result: Normal, Fighting, Ground - Score: 564
        {0, 2, 4}, //(2)Type One: Normal, Type Two: Flying, Result: Normal, Flying, Ground - Score: 576
        {0, 3, 4}, //(3)Type One: Normal, Type Two: Poison, Result: Normal, Poison, Ground - Score: 533
        {0, 4, 15}, //(4)Type One: Normal, Type Two: Ground, Result: Normal, Ground, Ice - Score: 597
        {0, 4, 5}, //(5)Type One: Normal, Type Two: Rock, Result: Normal, Ground, Rock - Score: 588
        {0, 4, 6}, //(6)Type One: Normal, Type Two: Bug, Result: Normal, Ground, Bug - Score: 546
        {0, 4, 7}, //(7)Type One: Normal, Type Two: Ghost, Result: Normal, Ground, Ghost - Score: 533
        {0, 4, 8}, //(8)Type One: Normal, Type Two: Steel, Result: Normal, Ground, Steel - Score: 550
        {0, 0, 0}, //(9)Type One: Normal, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {0, 4, 10}, //(10)Type One: Normal, Type Two: Fire, Result: Normal, Ground, Fire - Score: 583
        {0, 10, 11}, //(11)Type One: Normal, Type Two: Water, Result: Normal, Fire, Water - Score: 529
        {0, 4, 12}, //(12)Type One: Normal, Type Two: Grass, Result: Normal, Ground, Grass - Score: 529
        {0, 4, 13}, //(13)Type One: Normal, Type Two: Electric, Result: Normal, Ground, Electric - Score: 536
        {0, 4, 14}, //(14)Type One: Normal, Type Two: Psychic, Result: Normal, Ground, Psychic - Score: 519
        {0, 4, 15}, //(15)Type One: Normal, Type Two: Ice, Result: Normal, Ground, Ice - Score: 597
        {0, 4, 16}, //(16)Type One: Normal, Type Two: Dragon, Result: Normal, Ground, Dragon - Score: 511
        {0, 0, 0}, //(17)Type One: Normal, Type Two: Dark, Result: Normal, Normal, Normal - Score: 0
        {0, 4, 18}, //(18)Type One: Normal, Type Two: Fairy, Result: Normal, Ground, Fairy - Score: 569
        {0, 1, 4}, //(19)Type One: Fighting, Type Two: Normal, Result: Normal, Fighting, Ground - Score: 564
        {1, 4, 15}, //(20)Type One: Fighting, Type Two: Fighting, Result: Fighting, Ground, Ice - Score: 661
        {1, 2, 4}, //(21)Type One: Fighting, Type Two: Flying, Result: Fighting, Flying, Ground - Score: 644
        {1, 3, 4}, //(22)Type One: Fighting, Type Two: Poison, Result: Fighting, Poison, Ground - Score: 605
        {1, 4, 15}, //(23)Type One: Fighting, Type Two: Ground, Result: Fighting, Ground, Ice - Score: 661
        {1, 4, 5}, //(24)Type One: Fighting, Type Two: Rock, Result: Fighting, Ground, Rock - Score: 656
        {1, 4, 6}, //(25)Type One: Fighting, Type Two: Bug, Result: Fighting, Ground, Bug - Score: 595
        {1, 4, 7}, //(26)Type One: Fighting, Type Two: Ghost, Result: Fighting, Ground, Ghost - Score: 612
        {1, 4, 8}, //(27)Type One: Fighting, Type Two: Steel, Result: Fighting, Ground, Steel - Score: 607
        {0, 0, 0}, //(28)Type One: Fighting, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {1, 4, 10}, //(29)Type One: Fighting, Type Two: Fire, Result: Fighting, Ground, Fire - Score: 639
        {1, 5, 11}, //(30)Type One: Fighting, Type Two: Water, Result: Fighting, Rock, Water - Score: 605
        {1, 5, 12}, //(31)Type One: Fighting, Type Two: Grass, Result: Fighting, Rock, Grass - Score: 604
        {1, 4, 13}, //(32)Type One: Fighting, Type Two: Electric, Result: Fighting, Ground, Electric - Score: 603
        {1, 5, 14}, //(33)Type One: Fighting, Type Two: Psychic, Result: Fighting, Rock, Psychic - Score: 608
        {1, 4, 15}, //(34)Type One: Fighting, Type Two: Ice, Result: Fighting, Ground, Ice - Score: 661
        {1, 4, 16}, //(35)Type One: Fighting, Type Two: Dragon, Result: Fighting, Ground, Dragon - Score: 582
        {1, 5, 17}, //(36)Type One: Fighting, Type Two: Dark, Result: Fighting, Rock, Dark - Score: 605
        {1, 4, 18}, //(37)Type One: Fighting, Type Two: Fairy, Result: Fighting, Ground, Fairy - Score: 624
        {0, 2, 4}, //(38)Type One: Flying, Type Two: Normal, Result: Normal, Flying, Ground - Score: 576
        {1, 2, 4}, //(39)Type One: Flying, Type Two: Fighting, Result: Fighting, Flying, Ground - Score: 644
        {2, 4, 15}, //(40)Type One: Flying, Type Two: Flying, Result: Flying, Ground, Ice - Score: 651
        {2, 3, 4}, //(41)Type One: Flying, Type Two: Poison, Result: Flying, Poison, Ground - Score: 597
        {2, 4, 15}, //(42)Type One: Flying, Type Two: Ground, Result: Flying, Ground, Ice - Score: 651
        {2, 4, 5}, //(43)Type One: Flying, Type Two: Rock, Result: Flying, Ground, Rock - Score: 646
        {2, 4, 6}, //(44)Type One: Flying, Type Two: Bug, Result: Flying, Ground, Bug - Score: 615
        {2, 4, 7}, //(45)Type One: Flying, Type Two: Ghost, Result: Flying, Ground, Ghost - Score: 610
        {2, 4, 8}, //(46)Type One: Flying, Type Two: Steel, Result: Flying, Ground, Steel - Score: 626
        {0, 0, 0}, //(47)Type One: Flying, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {2, 4, 10}, //(48)Type One: Flying, Type Two: Fire, Result: Flying, Ground, Fire - Score: 622
        {2, 4, 11}, //(49)Type One: Flying, Type Two: Water, Result: Flying, Ground, Water - Score: 607
        {2, 4, 12}, //(50)Type One: Flying, Type Two: Grass, Result: Flying, Ground, Grass - Score: 616
        {2, 4, 13}, //(51)Type One: Flying, Type Two: Electric, Result: Flying, Ground, Electric - Score: 618
        {2, 4, 14}, //(52)Type One: Flying, Type Two: Psychic, Result: Flying, Ground, Psychic - Score: 583
        {2, 4, 15}, //(53)Type One: Flying, Type Two: Ice, Result: Flying, Ground, Ice - Score: 651
        {2, 4, 16}, //(54)Type One: Flying, Type Two: Dragon, Result: Flying, Ground, Dragon - Score: 594
        {2, 4, 17}, //(55)Type One: Flying, Type Two: Dark, Result: Flying, Ground, Dark - Score: 610
        {2, 4, 18}, //(56)Type One: Flying, Type Two: Fairy, Result: Flying, Ground, Fairy - Score: 625
        {0, 3, 4}, //(57)Type One: Poison, Type Two: Normal, Result: Normal, Poison, Ground - Score: 533
        {1, 3, 4}, //(58)Type One: Poison, Type Two: Fighting, Result: Fighting, Poison, Ground - Score: 605
        {2, 3, 4}, //(59)Type One: Poison, Type Two: Flying, Result: Flying, Poison, Ground - Score: 597
        {3, 4, 5}, //(60)Type One: Poison, Type Two: Poison, Result: Poison, Ground, Rock - Score: 622
        {3, 4, 5}, //(61)Type One: Poison, Type Two: Ground, Result: Poison, Ground, Rock - Score: 622
        {3, 4, 5}, //(62)Type One: Poison, Type Two: Rock, Result: Poison, Ground, Rock - Score: 622
        {3, 4, 6}, //(63)Type One: Poison, Type Two: Bug, Result: Poison, Ground, Bug - Score: 575
        {3, 4, 7}, //(64)Type One: Poison, Type Two: Ghost, Result: Poison, Ground, Ghost - Score: 577
        {3, 4, 8}, //(65)Type One: Poison, Type Two: Steel, Result: Poison, Ground, Steel - Score: 577
        {0, 0, 0}, //(66)Type One: Poison, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {3, 4, 10}, //(67)Type One: Poison, Type Two: Fire, Result: Poison, Ground, Fire - Score: 608
        {3, 4, 11}, //(68)Type One: Poison, Type Two: Water, Result: Poison, Ground, Water - Score: 572
        {3, 4, 12}, //(69)Type One: Poison, Type Two: Grass, Result: Poison, Ground, Grass - Score: 575
        {3, 4, 13}, //(70)Type One: Poison, Type Two: Electric, Result: Poison, Ground, Electric - Score: 579
        {3, 4, 14}, //(71)Type One: Poison, Type Two: Psychic, Result: Poison, Ground, Psychic - Score: 563
        {3, 4, 15}, //(72)Type One: Poison, Type Two: Ice, Result: Poison, Ground, Ice - Score: 622
        {3, 4, 16}, //(73)Type One: Poison, Type Two: Dragon, Result: Poison, Ground, Dragon - Score: 557
        {3, 4, 17}, //(74)Type One: Poison, Type Two: Dark, Result: Poison, Ground, Dark - Score: 575
        {3, 4, 18}, //(75)Type One: Poison, Type Two: Fairy, Result: Poison, Ground, Fairy - Score: 604
        {0, 4, 15}, //(76)Type One: Ground, Type Two: Normal, Result: Normal, Ground, Ice - Score: 597
        {1, 4, 15}, //(77)Type One: Ground, Type Two: Fighting, Result: Fighting, Ground, Ice - Score: 661
        {2, 4, 15}, //(78)Type One: Ground, Type Two: Flying, Result: Flying, Ground, Ice - Score: 651
        {3, 4, 5}, //(79)Type One: Ground, Type Two: Poison, Result: Poison, Ground, Rock - Score: 622
        {4, 5, 15}, //(80)Type One: Ground, Type Two: Ground, Result: Ground, Rock, Ice - Score: 669
        {4, 5, 15}, //(81)Type One: Ground, Type Two: Rock, Result: Ground, Rock, Ice - Score: 669
        {4, 5, 6}, //(82)Type One: Ground, Type Two: Bug, Result: Ground, Rock, Bug - Score: 637
        {4, 7, 15}, //(83)Type One: Ground, Type Two: Ghost, Result: Ground, Ghost, Ice - Score: 625
        {4, 8, 15}, //(84)Type One: Ground, Type Two: Steel, Result: Ground, Steel, Ice - Score: 646
        {0, 0, 0}, //(85)Type One: Ground, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {4, 10, 15}, //(86)Type One: Ground, Type Two: Fire, Result: Ground, Fire, Ice - Score: 665
        {4, 5, 11}, //(87)Type One: Ground, Type Two: Water, Result: Ground, Rock, Water - Score: 614
        {4, 5, 12}, //(88)Type One: Ground, Type Two: Grass, Result: Ground, Rock, Grass - Score: 629
        {4, 10, 13}, //(89)Type One: Ground, Type Two: Electric, Result: Ground, Fire, Electric - Score: 626
        {4, 14, 15}, //(90)Type One: Ground, Type Two: Psychic, Result: Ground, Psychic, Ice - Score: 616
        {4, 5, 15}, //(91)Type One: Ground, Type Two: Ice, Result: Ground, Rock, Ice - Score: 669
        {4, 10, 16}, //(92)Type One: Ground, Type Two: Dragon, Result: Ground, Fire, Dragon - Score: 607
        {4, 15, 17}, //(93)Type One: Ground, Type Two: Dark, Result: Ground, Ice, Dark - Score: 621
        {4, 5, 18}, //(94)Type One: Ground, Type Two: Fairy, Result: Ground, Rock, Fairy - Score: 657
        {0, 4, 5}, //(95)Type One: Rock, Type Two: Normal, Result: Normal, Ground, Rock - Score: 588
        {1, 4, 5}, //(96)Type One: Rock, Type Two: Fighting, Result: Fighting, Ground, Rock - Score: 656
        {2, 4, 5}, //(97)Type One: Rock, Type Two: Flying, Result: Flying, Ground, Rock - Score: 646
        {3, 4, 5}, //(98)Type One: Rock, Type Two: Poison, Result: Poison, Ground, Rock - Score: 622
        {4, 5, 15}, //(99)Type One: Rock, Type Two: Ground, Result: Ground, Rock, Ice - Score: 669
        {4, 5, 15}, //(100)Type One: Rock, Type Two: Rock, Result: Ground, Rock, Ice - Score: 669
        {4, 5, 6}, //(101)Type One: Rock, Type Two: Bug, Result: Ground, Rock, Bug - Score: 637
        {4, 5, 7}, //(102)Type One: Rock, Type Two: Ghost, Result: Ground, Rock, Ghost - Score: 620
        {4, 5, 8}, //(103)Type One: Rock, Type Two: Steel, Result: Ground, Rock, Steel - Score: 623
        {0, 0, 0}, //(104)Type One: Rock, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {4, 5, 10}, //(105)Type One: Rock, Type Two: Fire, Result: Ground, Rock, Fire - Score: 641
        {4, 5, 11}, //(106)Type One: Rock, Type Two: Water, Result: Ground, Rock, Water - Score: 614
        {4, 5, 12}, //(107)Type One: Rock, Type Two: Grass, Result: Ground, Rock, Grass - Score: 629
        {4, 5, 13}, //(108)Type One: Rock, Type Two: Electric, Result: Ground, Rock, Electric - Score: 607
        {4, 5, 14}, //(109)Type One: Rock, Type Two: Psychic, Result: Ground, Rock, Psychic - Score: 615
        {4, 5, 15}, //(110)Type One: Rock, Type Two: Ice, Result: Ground, Rock, Ice - Score: 669
        {4, 5, 16}, //(111)Type One: Rock, Type Two: Dragon, Result: Ground, Rock, Dragon - Score: 605
        {4, 5, 17}, //(112)Type One: Rock, Type Two: Dark, Result: Ground, Rock, Dark - Score: 615
        {4, 5, 18}, //(113)Type One: Rock, Type Two: Fairy, Result: Ground, Rock, Fairy - Score: 657
        {0, 4, 6}, //(114)Type One: Bug, Type Two: Normal, Result: Normal, Ground, Bug - Score: 546
        {1, 4, 6}, //(115)Type One: Bug, Type Two: Fighting, Result: Fighting, Ground, Bug - Score: 595
        {2, 4, 6}, //(116)Type One: Bug, Type Two: Flying, Result: Flying, Ground, Bug - Score: 615
        {3, 4, 6}, //(117)Type One: Bug, Type Two: Poison, Result: Poison, Ground, Bug - Score: 575
        {4, 5, 6}, //(118)Type One: Bug, Type Two: Ground, Result: Ground, Rock, Bug - Score: 637
        {4, 5, 6}, //(119)Type One: Bug, Type Two: Rock, Result: Ground, Rock, Bug - Score: 637
        {4, 5, 6}, //(120)Type One: Bug, Type Two: Bug, Result: Ground, Rock, Bug - Score: 637
        {4, 6, 7}, //(121)Type One: Bug, Type Two: Ghost, Result: Ground, Bug, Ghost - Score: 580
        {4, 6, 8}, //(122)Type One: Bug, Type Two: Steel, Result: Ground, Bug, Steel - Score: 600
        {0, 0, 0}, //(123)Type One: Bug, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {4, 6, 10}, //(124)Type One: Bug, Type Two: Fire, Result: Ground, Bug, Fire - Score: 618
        {4, 6, 11}, //(125)Type One: Bug, Type Two: Water, Result: Ground, Bug, Water - Score: 579
        {4, 6, 12}, //(126)Type One: Bug, Type Two: Grass, Result: Ground, Bug, Grass - Score: 570
        {4, 6, 13}, //(127)Type One: Bug, Type Two: Electric, Result: Ground, Bug, Electric - Score: 593
        {4, 6, 14}, //(128)Type One: Bug, Type Two: Psychic, Result: Ground, Bug, Psychic - Score: 580
        {4, 6, 15}, //(129)Type One: Bug, Type Two: Ice, Result: Ground, Bug, Ice - Score: 633
        {4, 6, 16}, //(130)Type One: Bug, Type Two: Dragon, Result: Ground, Bug, Dragon - Score: 564
        {4, 6, 17}, //(131)Type One: Bug, Type Two: Dark, Result: Ground, Bug, Dark - Score: 571
        {4, 6, 18}, //(132)Type One: Bug, Type Two: Fairy, Result: Ground, Bug, Fairy - Score: 607
        {0, 4, 7}, //(133)Type One: Ghost, Type Two: Normal, Result: Normal, Ground, Ghost - Score: 533
        {1, 4, 7}, //(134)Type One: Ghost, Type Two: Fighting, Result: Fighting, Ground, Ghost - Score: 612
        {2, 4, 7}, //(135)Type One: Ghost, Type Two: Flying, Result: Flying, Ground, Ghost - Score: 610
        {3, 4, 7}, //(136)Type One: Ghost, Type Two: Poison, Result: Poison, Ground, Ghost - Score: 577
        {4, 7, 15}, //(137)Type One: Ghost, Type Two: Ground, Result: Ground, Ghost, Ice - Score: 625
        {4, 5, 7}, //(138)Type One: Ghost, Type Two: Rock, Result: Ground, Rock, Ghost - Score: 620
        {4, 6, 7}, //(139)Type One: Ghost, Type Two: Bug, Result: Ground, Bug, Ghost - Score: 580
        {4, 7, 15}, //(140)Type One: Ghost, Type Two: Ghost, Result: Ground, Ghost, Ice - Score: 625
        {4, 7, 8}, //(141)Type One: Ghost, Type Two: Steel, Result: Ground, Ghost, Steel - Score: 587
        {0, 0, 0}, //(142)Type One: Ghost, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {4, 7, 10}, //(143)Type One: Ghost, Type Two: Fire, Result: Ground, Ghost, Fire - Score: 616
        {1, 7, 11}, //(144)Type One: Ghost, Type Two: Water, Result: Fighting, Ghost, Water - Score: 571
        {4, 7, 12}, //(145)Type One: Ghost, Type Two: Grass, Result: Ground, Ghost, Grass - Score: 563
        {4, 7, 13}, //(146)Type One: Ghost, Type Two: Electric, Result: Ground, Ghost, Electric - Score: 571
        {1, 7, 14}, //(147)Type One: Ghost, Type Two: Psychic, Result: Fighting, Ghost, Psychic - Score: 573
        {4, 7, 15}, //(148)Type One: Ghost, Type Two: Ice, Result: Ground, Ghost, Ice - Score: 625
        {4, 7, 16}, //(149)Type One: Ghost, Type Two: Dragon, Result: Ground, Ghost, Dragon - Score: 552
        {4, 7, 17}, //(150)Type One: Ghost, Type Two: Dark, Result: Ground, Ghost, Dark - Score: 534
        {4, 7, 18}, //(151)Type One: Ghost, Type Two: Fairy, Result: Ground, Ghost, Fairy - Score: 606
        {0, 4, 8}, //(152)Type One: Steel, Type Two: Normal, Result: Normal, Ground, Steel - Score: 550
        {1, 4, 8}, //(153)Type One: Steel, Type Two: Fighting, Result: Fighting, Ground, Steel - Score: 607
        {2, 4, 8}, //(154)Type One: Steel, Type Two: Flying, Result: Flying, Ground, Steel - Score: 626
        {3, 4, 8}, //(155)Type One: Steel, Type Two: Poison, Result: Poison, Ground, Steel - Score: 577
        {4, 8, 15}, //(156)Type One: Steel, Type Two: Ground, Result: Ground, Steel, Ice - Score: 646
        {4, 5, 8}, //(157)Type One: Steel, Type Two: Rock, Result: Ground, Rock, Steel - Score: 623
        {4, 6, 8}, //(158)Type One: Steel, Type Two: Bug, Result: Ground, Bug, Steel - Score: 600
        {4, 7, 8}, //(159)Type One: Steel, Type Two: Ghost, Result: Ground, Ghost, Steel - Score: 587
        {4, 8, 15}, //(160)Type One: Steel, Type Two: Steel, Result: Ground, Steel, Ice - Score: 646
        {0, 0, 0}, //(161)Type One: Steel, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {4, 8, 10}, //(162)Type One: Steel, Type Two: Fire, Result: Ground, Steel, Fire - Score: 619
        {4, 8, 11}, //(163)Type One: Steel, Type Two: Water, Result: Ground, Steel, Water - Score: 575
        {4, 8, 12}, //(164)Type One: Steel, Type Two: Grass, Result: Ground, Steel, Grass - Score: 588
        {4, 8, 13}, //(165)Type One: Steel, Type Two: Electric, Result: Ground, Steel, Electric - Score: 593
        {4, 8, 14}, //(166)Type One: Steel, Type Two: Psychic, Result: Ground, Steel, Psychic - Score: 577
        {4, 8, 15}, //(167)Type One: Steel, Type Two: Ice, Result: Ground, Steel, Ice - Score: 646
        {4, 8, 16}, //(168)Type One: Steel, Type Two: Dragon, Result: Ground, Steel, Dragon - Score: 571
        {4, 8, 17}, //(169)Type One: Steel, Type Two: Dark, Result: Ground, Steel, Dark - Score: 587
        {4, 8, 18}, //(170)Type One: Steel, Type Two: Fairy, Result: Ground, Steel, Fairy - Score: 618
        {0, 0, 0}, //(171)Type One: 9, Type Two: Normal, Result: Normal, Normal, Normal - Score: 0
        {0, 0, 0}, //(172)Type One: 9, Type Two: Fighting, Result: Normal, Normal, Normal - Score: 0
        {0, 0, 0}, //(173)Type One: 9, Type Two: Flying, Result: Normal, Normal, Normal - Score: 0
        {0, 0, 0}, //(174)Type One: 9, Type Two: Poison, Result: Normal, Normal, Normal - Score: 0
        {0, 0, 0}, //(175)Type One: 9, Type Two: Ground, Result: Normal, Normal, Normal - Score: 0
        {0, 0, 0}, //(176)Type One: 9, Type Two: Rock, Result: Normal, Normal, Normal - Score: 0
        {0, 0, 0}, //(177)Type One: 9, Type Two: Bug, Result: Normal, Normal, Normal - Score: 0
        {0, 0, 0}, //(178)Type One: 9, Type Two: Ghost, Result: Normal, Normal, Normal - Score: 0
        {0, 0, 0}, //(179)Type One: 9, Type Two: Steel, Result: Normal, Normal, Normal - Score: 0
        {0, 0, 0}, //(180)Type One: 9, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {0, 0, 0}, //(181)Type One: 9, Type Two: Fire, Result: Normal, Normal, Normal - Score: 0
        {0, 0, 0}, //(182)Type One: 9, Type Two: Water, Result: Normal, Normal, Normal - Score: 0
        {0, 0, 0}, //(183)Type One: 9, Type Two: Grass, Result: Normal, Normal, Normal - Score: 0
        {0, 0, 0}, //(184)Type One: 9, Type Two: Electric, Result: Normal, Normal, Normal - Score: 0
        {0, 0, 0}, //(185)Type One: 9, Type Two: Psychic, Result: Normal, Normal, Normal - Score: 0
        {0, 0, 0}, //(186)Type One: 9, Type Two: Ice, Result: Normal, Normal, Normal - Score: 0
        {0, 0, 0}, //(187)Type One: 9, Type Two: Dragon, Result: Normal, Normal, Normal - Score: 0
        {0, 0, 0}, //(188)Type One: 9, Type Two: Dark, Result: Normal, Normal, Normal - Score: 0
        {0, 0, 0}, //(189)Type One: 9, Type Two: Fairy, Result: Normal, Normal, Normal - Score: 0
        {0, 4, 10}, //(190)Type One: Fire, Type Two: Normal, Result: Normal, Ground, Fire - Score: 583
        {1, 4, 10}, //(191)Type One: Fire, Type Two: Fighting, Result: Fighting, Ground, Fire - Score: 639
        {2, 4, 10}, //(192)Type One: Fire, Type Two: Flying, Result: Flying, Ground, Fire - Score: 622
        {3, 4, 10}, //(193)Type One: Fire, Type Two: Poison, Result: Poison, Ground, Fire - Score: 608
        {4, 10, 15}, //(194)Type One: Fire, Type Two: Ground, Result: Ground, Fire, Ice - Score: 665
        {4, 5, 10}, //(195)Type One: Fire, Type Two: Rock, Result: Ground, Rock, Fire - Score: 641
        {4, 6, 10}, //(196)Type One: Fire, Type Two: Bug, Result: Ground, Bug, Fire - Score: 618
        {4, 7, 10}, //(197)Type One: Fire, Type Two: Ghost, Result: Ground, Ghost, Fire - Score: 616
        {4, 8, 10}, //(198)Type One: Fire, Type Two: Steel, Result: Ground, Steel, Fire - Score: 619
        {0, 0, 0}, //(199)Type One: Fire, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {4, 10, 15}, //(200)Type One: Fire, Type Two: Fire, Result: Ground, Fire, Ice - Score: 665
        {4, 10, 11}, //(201)Type One: Fire, Type Two: Water, Result: Ground, Fire, Water - Score: 613
        {4, 10, 12}, //(202)Type One: Fire, Type Two: Grass, Result: Ground, Fire, Grass - Score: 624
        {4, 10, 13}, //(203)Type One: Fire, Type Two: Electric, Result: Ground, Fire, Electric - Score: 626
        {4, 10, 14}, //(204)Type One: Fire, Type Two: Psychic, Result: Ground, Fire, Psychic - Score: 605
        {4, 10, 15}, //(205)Type One: Fire, Type Two: Ice, Result: Ground, Fire, Ice - Score: 665
        {4, 10, 16}, //(206)Type One: Fire, Type Two: Dragon, Result: Ground, Fire, Dragon - Score: 607
        {4, 10, 17}, //(207)Type One: Fire, Type Two: Dark, Result: Ground, Fire, Dark - Score: 612
        {4, 10, 18}, //(208)Type One: Fire, Type Two: Fairy, Result: Ground, Fire, Fairy - Score: 652
        {0, 10, 11}, //(209)Type One: Water, Type Two: Normal, Result: Normal, Fire, Water - Score: 529
        {1, 5, 11}, //(210)Type One: Water, Type Two: Fighting, Result: Fighting, Rock, Water - Score: 605
        {2, 4, 11}, //(211)Type One: Water, Type Two: Flying, Result: Flying, Ground, Water - Score: 607
        {3, 4, 11}, //(212)Type One: Water, Type Two: Poison, Result: Poison, Ground, Water - Score: 572
        {4, 5, 11}, //(213)Type One: Water, Type Two: Ground, Result: Ground, Rock, Water - Score: 614
        {4, 5, 11}, //(214)Type One: Water, Type Two: Rock, Result: Ground, Rock, Water - Score: 614
        {4, 6, 11}, //(215)Type One: Water, Type Two: Bug, Result: Ground, Bug, Water - Score: 579
        {1, 7, 11}, //(216)Type One: Water, Type Two: Ghost, Result: Fighting, Ghost, Water - Score: 571
        {4, 8, 11}, //(217)Type One: Water, Type Two: Steel, Result: Ground, Steel, Water - Score: 575
        {0, 0, 0}, //(218)Type One: Water, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {4, 10, 11}, //(219)Type One: Water, Type Two: Fire, Result: Ground, Fire, Water - Score: 613
        {4, 5, 11}, //(220)Type One: Water, Type Two: Water, Result: Ground, Rock, Water - Score: 614
        {10, 11, 12}, //(221)Type One: Water, Type Two: Grass, Result: Fire, Water, Grass - Score: 551
        {10, 11, 13}, //(222)Type One: Water, Type Two: Electric, Result: Fire, Water, Electric - Score: 569
        {10, 11, 14}, //(223)Type One: Water, Type Two: Psychic, Result: Fire, Water, Psychic - Score: 563
        {4, 11, 15}, //(224)Type One: Water, Type Two: Ice, Result: Ground, Water, Ice - Score: 612
        {10, 11, 16}, //(225)Type One: Water, Type Two: Dragon, Result: Fire, Water, Dragon - Score: 560
        {1, 11, 17}, //(226)Type One: Water, Type Two: Dark, Result: Fighting, Water, Dark - Score: 564
        {10, 11, 18}, //(227)Type One: Water, Type Two: Fairy, Result: Fire, Water, Fairy - Score: 603
        {0, 4, 12}, //(228)Type One: Grass, Type Two: Normal, Result: Normal, Ground, Grass - Score: 529
        {1, 5, 12}, //(229)Type One: Grass, Type Two: Fighting, Result: Fighting, Rock, Grass - Score: 604
        {2, 4, 12}, //(230)Type One: Grass, Type Two: Flying, Result: Flying, Ground, Grass - Score: 616
        {3, 4, 12}, //(231)Type One: Grass, Type Two: Poison, Result: Poison, Ground, Grass - Score: 575
        {4, 5, 12}, //(232)Type One: Grass, Type Two: Ground, Result: Ground, Rock, Grass - Score: 629
        {4, 5, 12}, //(233)Type One: Grass, Type Two: Rock, Result: Ground, Rock, Grass - Score: 629
        {4, 6, 12}, //(234)Type One: Grass, Type Two: Bug, Result: Ground, Bug, Grass - Score: 570
        {4, 7, 12}, //(235)Type One: Grass, Type Two: Ghost, Result: Ground, Ghost, Grass - Score: 563
        {4, 8, 12}, //(236)Type One: Grass, Type Two: Steel, Result: Ground, Steel, Grass - Score: 588
        {0, 0, 0}, //(237)Type One: Grass, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {4, 10, 12}, //(238)Type One: Grass, Type Two: Fire, Result: Ground, Fire, Grass - Score: 624
        {10, 11, 12}, //(239)Type One: Grass, Type Two: Water, Result: Fire, Water, Grass - Score: 551
        {4, 5, 12}, //(240)Type One: Grass, Type Two: Grass, Result: Ground, Rock, Grass - Score: 629
        {4, 12, 13}, //(241)Type One: Grass, Type Two: Electric, Result: Ground, Grass, Electric - Score: 556
        {5, 12, 14}, //(242)Type One: Grass, Type Two: Psychic, Result: Rock, Grass, Psychic - Score: 555
        {4, 12, 15}, //(243)Type One: Grass, Type Two: Ice, Result: Ground, Grass, Ice - Score: 627
        {4, 12, 16}, //(244)Type One: Grass, Type Two: Dragon, Result: Ground, Grass, Dragon - Score: 552
        {4, 12, 17}, //(245)Type One: Grass, Type Two: Dark, Result: Ground, Grass, Dark - Score: 556
        {4, 12, 18}, //(246)Type One: Grass, Type Two: Fairy, Result: Ground, Grass, Fairy - Score: 603
        {0, 4, 13}, //(247)Type One: Electric, Type Two: Normal, Result: Normal, Ground, Electric - Score: 536
        {1, 4, 13}, //(248)Type One: Electric, Type Two: Fighting, Result: Fighting, Ground, Electric - Score: 603
        {2, 4, 13}, //(249)Type One: Electric, Type Two: Flying, Result: Flying, Ground, Electric - Score: 618
        {3, 4, 13}, //(250)Type One: Electric, Type Two: Poison, Result: Poison, Ground, Electric - Score: 579
        {4, 10, 13}, //(251)Type One: Electric, Type Two: Ground, Result: Ground, Fire, Electric - Score: 626
        {4, 5, 13}, //(252)Type One: Electric, Type Two: Rock, Result: Ground, Rock, Electric - Score: 607
        {4, 6, 13}, //(253)Type One: Electric, Type Two: Bug, Result: Ground, Bug, Electric - Score: 593
        {4, 7, 13}, //(254)Type One: Electric, Type Two: Ghost, Result: Ground, Ghost, Electric - Score: 571
        {4, 8, 13}, //(255)Type One: Electric, Type Two: Steel, Result: Ground, Steel, Electric - Score: 593
        {0, 0, 0}, //(256)Type One: Electric, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {4, 10, 13}, //(257)Type One: Electric, Type Two: Fire, Result: Ground, Fire, Electric - Score: 626
        {10, 11, 13}, //(258)Type One: Electric, Type Two: Water, Result: Fire, Water, Electric - Score: 569
        {4, 12, 13}, //(259)Type One: Electric, Type Two: Grass, Result: Ground, Grass, Electric - Score: 556
        {4, 10, 13}, //(260)Type One: Electric, Type Two: Electric, Result: Ground, Fire, Electric - Score: 626
        {4, 13, 14}, //(261)Type One: Electric, Type Two: Psychic, Result: Ground, Electric, Psychic - Score: 560
        {4, 13, 15}, //(262)Type One: Electric, Type Two: Ice, Result: Ground, Electric, Ice - Score: 626
        {4, 13, 16}, //(263)Type One: Electric, Type Two: Dragon, Result: Ground, Electric, Dragon - Score: 559
        {4, 13, 17}, //(264)Type One: Electric, Type Two: Dark, Result: Ground, Electric, Dark - Score: 566
        {4, 13, 18}, //(265)Type One: Electric, Type Two: Fairy, Result: Ground, Electric, Fairy - Score: 610
        {0, 4, 14}, //(266)Type One: Psychic, Type Two: Normal, Result: Normal, Ground, Psychic - Score: 519
        {1, 5, 14}, //(267)Type One: Psychic, Type Two: Fighting, Result: Fighting, Rock, Psychic - Score: 608
        {2, 4, 14}, //(268)Type One: Psychic, Type Two: Flying, Result: Flying, Ground, Psychic - Score: 583
        {3, 4, 14}, //(269)Type One: Psychic, Type Two: Poison, Result: Poison, Ground, Psychic - Score: 563
        {4, 14, 15}, //(270)Type One: Psychic, Type Two: Ground, Result: Ground, Psychic, Ice - Score: 616
        {4, 5, 14}, //(271)Type One: Psychic, Type Two: Rock, Result: Ground, Rock, Psychic - Score: 615
        {4, 6, 14}, //(272)Type One: Psychic, Type Two: Bug, Result: Ground, Bug, Psychic - Score: 580
        {1, 7, 14}, //(273)Type One: Psychic, Type Two: Ghost, Result: Fighting, Ghost, Psychic - Score: 573
        {4, 8, 14}, //(274)Type One: Psychic, Type Two: Steel, Result: Ground, Steel, Psychic - Score: 577
        {0, 0, 0}, //(275)Type One: Psychic, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {4, 10, 14}, //(276)Type One: Psychic, Type Two: Fire, Result: Ground, Fire, Psychic - Score: 605
        {10, 11, 14}, //(277)Type One: Psychic, Type Two: Water, Result: Fire, Water, Psychic - Score: 563
        {5, 12, 14}, //(278)Type One: Psychic, Type Two: Grass, Result: Rock, Grass, Psychic - Score: 555
        {4, 13, 14}, //(279)Type One: Psychic, Type Two: Electric, Result: Ground, Electric, Psychic - Score: 560
        {4, 14, 15}, //(280)Type One: Psychic, Type Two: Psychic, Result: Ground, Psychic, Ice - Score: 616
        {4, 14, 15}, //(281)Type One: Psychic, Type Two: Ice, Result: Ground, Psychic, Ice - Score: 616
        {4, 14, 16}, //(282)Type One: Psychic, Type Two: Dragon, Result: Ground, Psychic, Dragon - Score: 540
        {1, 14, 17}, //(283)Type One: Psychic, Type Two: Dark, Result: Fighting, Psychic, Dark - Score: 571
        {4, 14, 18}, //(284)Type One: Psychic, Type Two: Fairy, Result: Ground, Psychic, Fairy - Score: 579
        {0, 4, 15}, //(285)Type One: Ice, Type Two: Normal, Result: Normal, Ground, Ice - Score: 597
        {1, 4, 15}, //(286)Type One: Ice, Type Two: Fighting, Result: Fighting, Ground, Ice - Score: 661
        {2, 4, 15}, //(287)Type One: Ice, Type Two: Flying, Result: Flying, Ground, Ice - Score: 651
        {3, 4, 15}, //(288)Type One: Ice, Type Two: Poison, Result: Poison, Ground, Ice - Score: 622
        {4, 5, 15}, //(289)Type One: Ice, Type Two: Ground, Result: Ground, Rock, Ice - Score: 669
        {4, 5, 15}, //(290)Type One: Ice, Type Two: Rock, Result: Ground, Rock, Ice - Score: 669
        {4, 6, 15}, //(291)Type One: Ice, Type Two: Bug, Result: Ground, Bug, Ice - Score: 633
        {4, 7, 15}, //(292)Type One: Ice, Type Two: Ghost, Result: Ground, Ghost, Ice - Score: 625
        {4, 8, 15}, //(293)Type One: Ice, Type Two: Steel, Result: Ground, Steel, Ice - Score: 646
        {0, 0, 0}, //(294)Type One: Ice, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {4, 10, 15}, //(295)Type One: Ice, Type Two: Fire, Result: Ground, Fire, Ice - Score: 665
        {4, 11, 15}, //(296)Type One: Ice, Type Two: Water, Result: Ground, Water, Ice - Score: 612
        {4, 12, 15}, //(297)Type One: Ice, Type Two: Grass, Result: Ground, Grass, Ice - Score: 627
        {4, 13, 15}, //(298)Type One: Ice, Type Two: Electric, Result: Ground, Electric, Ice - Score: 626
        {4, 14, 15}, //(299)Type One: Ice, Type Two: Psychic, Result: Ground, Psychic, Ice - Score: 616
        {4, 5, 15}, //(300)Type One: Ice, Type Two: Ice, Result: Ground, Rock, Ice - Score: 669
        {4, 15, 16}, //(301)Type One: Ice, Type Two: Dragon, Result: Ground, Ice, Dragon - Score: 601
        {4, 15, 17}, //(302)Type One: Ice, Type Two: Dark, Result: Ground, Ice, Dark - Score: 621
        {4, 15, 18}, //(303)Type One: Ice, Type Two: Fairy, Result: Ground, Ice, Fairy - Score: 645
        {0, 4, 16}, //(304)Type One: Dragon, Type Two: Normal, Result: Normal, Ground, Dragon - Score: 511
        {1, 4, 16}, //(305)Type One: Dragon, Type Two: Fighting, Result: Fighting, Ground, Dragon - Score: 582
        {2, 4, 16}, //(306)Type One: Dragon, Type Two: Flying, Result: Flying, Ground, Dragon - Score: 594
        {3, 4, 16}, //(307)Type One: Dragon, Type Two: Poison, Result: Poison, Ground, Dragon - Score: 557
        {4, 10, 16}, //(308)Type One: Dragon, Type Two: Ground, Result: Ground, Fire, Dragon - Score: 607
        {4, 5, 16}, //(309)Type One: Dragon, Type Two: Rock, Result: Ground, Rock, Dragon - Score: 605
        {4, 6, 16}, //(310)Type One: Dragon, Type Two: Bug, Result: Ground, Bug, Dragon - Score: 564
        {4, 7, 16}, //(311)Type One: Dragon, Type Two: Ghost, Result: Ground, Ghost, Dragon - Score: 552
        {4, 8, 16}, //(312)Type One: Dragon, Type Two: Steel, Result: Ground, Steel, Dragon - Score: 571
        {0, 0, 0}, //(313)Type One: Dragon, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {4, 10, 16}, //(314)Type One: Dragon, Type Two: Fire, Result: Ground, Fire, Dragon - Score: 607
        {10, 11, 16}, //(315)Type One: Dragon, Type Two: Water, Result: Fire, Water, Dragon - Score: 560
        {4, 12, 16}, //(316)Type One: Dragon, Type Two: Grass, Result: Ground, Grass, Dragon - Score: 552
        {4, 13, 16}, //(317)Type One: Dragon, Type Two: Electric, Result: Ground, Electric, Dragon - Score: 559
        {4, 14, 16}, //(318)Type One: Dragon, Type Two: Psychic, Result: Ground, Psychic, Dragon - Score: 540
        {4, 15, 16}, //(319)Type One: Dragon, Type Two: Ice, Result: Ground, Ice, Dragon - Score: 601
        {4, 10, 16}, //(320)Type One: Dragon, Type Two: Dragon, Result: Ground, Fire, Dragon - Score: 607
        {4, 16, 17}, //(321)Type One: Dragon, Type Two: Dark, Result: Ground, Dragon, Dark - Score: 545
        {4, 16, 18}, //(322)Type One: Dragon, Type Two: Fairy, Result: Ground, Dragon, Fairy - Score: 569
        {0, 0, 0}, //(323)Type One: Dark, Type Two: Normal, Result: Normal, Normal, Normal - Score: 0
        {1, 5, 17}, //(324)Type One: Dark, Type Two: Fighting, Result: Fighting, Rock, Dark - Score: 605
        {2, 4, 17}, //(325)Type One: Dark, Type Two: Flying, Result: Flying, Ground, Dark - Score: 610
        {3, 4, 17}, //(326)Type One: Dark, Type Two: Poison, Result: Poison, Ground, Dark - Score: 575
        {4, 15, 17}, //(327)Type One: Dark, Type Two: Ground, Result: Ground, Ice, Dark - Score: 621
        {4, 5, 17}, //(328)Type One: Dark, Type Two: Rock, Result: Ground, Rock, Dark - Score: 615
        {4, 6, 17}, //(329)Type One: Dark, Type Two: Bug, Result: Ground, Bug, Dark - Score: 571
        {4, 7, 17}, //(330)Type One: Dark, Type Two: Ghost, Result: Ground, Ghost, Dark - Score: 534
        {4, 8, 17}, //(331)Type One: Dark, Type Two: Steel, Result: Ground, Steel, Dark - Score: 587
        {0, 0, 0}, //(332)Type One: Dark, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {4, 10, 17}, //(333)Type One: Dark, Type Two: Fire, Result: Ground, Fire, Dark - Score: 612
        {1, 11, 17}, //(334)Type One: Dark, Type Two: Water, Result: Fighting, Water, Dark - Score: 564
        {4, 12, 17}, //(335)Type One: Dark, Type Two: Grass, Result: Ground, Grass, Dark - Score: 556
        {4, 13, 17}, //(336)Type One: Dark, Type Two: Electric, Result: Ground, Electric, Dark - Score: 566
        {1, 14, 17}, //(337)Type One: Dark, Type Two: Psychic, Result: Fighting, Psychic, Dark - Score: 571
        {4, 15, 17}, //(338)Type One: Dark, Type Two: Ice, Result: Ground, Ice, Dark - Score: 621
        {4, 16, 17}, //(339)Type One: Dark, Type Two: Dragon, Result: Ground, Dragon, Dark - Score: 545
        {4, 15, 17}, //(340)Type One: Dark, Type Two: Dark, Result: Ground, Ice, Dark - Score: 621
        {4, 17, 18}, //(341)Type One: Dark, Type Two: Fairy, Result: Ground, Dark, Fairy - Score: 606
        {0, 4, 18}, //(342)Type One: Fairy, Type Two: Normal, Result: Normal, Ground, Fairy - Score: 569
        {1, 4, 18}, //(343)Type One: Fairy, Type Two: Fighting, Result: Fighting, Ground, Fairy - Score: 624
        {2, 4, 18}, //(344)Type One: Fairy, Type Two: Flying, Result: Flying, Ground, Fairy - Score: 625
        {3, 4, 18}, //(345)Type One: Fairy, Type Two: Poison, Result: Poison, Ground, Fairy - Score: 604
        {4, 5, 18}, //(346)Type One: Fairy, Type Two: Ground, Result: Ground, Rock, Fairy - Score: 657
        {4, 5, 18}, //(347)Type One: Fairy, Type Two: Rock, Result: Ground, Rock, Fairy - Score: 657
        {4, 6, 18}, //(348)Type One: Fairy, Type Two: Bug, Result: Ground, Bug, Fairy - Score: 607
        {4, 7, 18}, //(349)Type One: Fairy, Type Two: Ghost, Result: Ground, Ghost, Fairy - Score: 606
        {4, 8, 18}, //(350)Type One: Fairy, Type Two: Steel, Result: Ground, Steel, Fairy - Score: 618
        {0, 0, 0}, //(351)Type One: Fairy, Type Two: 9, Result: Normal, Normal, Normal - Score: 0
        {4, 10, 18}, //(352)Type One: Fairy, Type Two: Fire, Result: Ground, Fire, Fairy - Score: 652
        {10, 11, 18}, //(353)Type One: Fairy, Type Two: Water, Result: Fire, Water, Fairy - Score: 603
        {4, 12, 18}, //(354)Type One: Fairy, Type Two: Grass, Result: Ground, Grass, Fairy - Score: 603
        {4, 13, 18}, //(355)Type One: Fairy, Type Two: Electric, Result: Ground, Electric, Fairy - Score: 610
        {4, 14, 18}, //(356)Type One: Fairy, Type Two: Psychic, Result: Ground, Psychic, Fairy - Score: 579
        {4, 15, 18}, //(357)Type One: Fairy, Type Two: Ice, Result: Ground, Ice, Fairy - Score: 645
        {4, 16, 18}, //(358)Type One: Fairy, Type Two: Dragon, Result: Ground, Dragon, Fairy - Score: 569
        {4, 17, 18}, //(359)Type One: Fairy, Type Two: Dark, Result: Ground, Dark, Fairy - Score: 606
        {4, 5, 18} //(360)Type One: Fairy, Type Two: Fairy, Result: Ground, Rock, Fairy - Score: 657
    };
    
    static const u16 oldPlayerTypeMove [][2][3] = 
    {
        {//Normal
        {MOVE_MULTI_ATTACK, MOVE_HEAD_CHARGE, MOVE_BODY_SLAM},//Physical
        {MOVE_BOOMBURST, MOVE_JUDGMENT, MOVE_TRI_ATTACK},//Special
        },
        {//Fighting
        {MOVE_CLOSE_COMBAT, MOVE_FLYING_PRESS, MOVE_SACRED_SWORD},//Physical
        {MOVE_FOCUS_BLAST, MOVE_SECRET_SWORD, MOVE_AURA_SPHERE},//Special
        },
        {//Flying
        {MOVE_DRAGON_ASCENT, MOVE_BRAVE_BIRD, MOVE_DRILL_PECK},//Physical
        {MOVE_HURRICANE, MOVE_AEROBLAST, MOVE_OBLIVION_WING},//Special
        },
        {//Poison
        {MOVE_GUNK_SHOT, MOVE_POISON_JAB, MOVE_POISON_JAB},//Physical
        {MOVE_SLUDGE_WAVE, MOVE_SLUDGE_BOMB, MOVE_SLUDGE_BOMB},//Special
        },
        {//Ground
        {MOVE_EARTHQUAKE, MOVE_THOUSAND_ARROWS, MOVE_HIGH_HORSEPOWER},//Physical
        {MOVE_EARTH_POWER, MOVE_EARTH_POWER, MOVE_EARTH_POWER},//Special
        },
        {//Rock
        {MOVE_HEAD_SMASH, MOVE_STONE_EDGE, MOVE_DIAMOND_STORM},//Physical
        {MOVE_POWER_GEM, MOVE_POWER_GEM, MOVE_ANCIENT_POWER},//Special
        },
        {//Bug
        {MOVE_MEGAHORN, MOVE_ATTACK_ORDER, MOVE_X_SCISSOR},//Physical
        {MOVE_BUG_BUZZ, MOVE_BUG_BUZZ, MOVE_SIGNAL_BEAM},//Special
        },
        {//Ghost
        {MOVE_SPECTRAL_THIEF, MOVE_SHADOW_BONE, MOVE_SPIRIT_SHACKLE},//Physical
        {MOVE_MOONGEIST_BEAM, MOVE_SHADOW_BALL, MOVE_SHADOW_BALL},//Special
        },
        {//Steel
        {MOVE_IRON_TAIL, MOVE_IRON_HEAD, MOVE_METEOR_MASH},//Physical
        {MOVE_DOOM_DESIRE, MOVE_FLASH_CANNON, MOVE_FLASH_CANNON},//Special
        },
        {//9
        {MOVE_NONE, MOVE_NONE, MOVE_NONE},//Physical
        {MOVE_NONE, MOVE_NONE, MOVE_NONE},//Special
        },
        {//Fire
        {MOVE_FLARE_BLITZ, MOVE_SACRED_FIRE, MOVE_FIRE_LASH},//Physical
        {MOVE_BLUE_FLARE, MOVE_FUSION_FLARE, MOVE_FLAMETHROWER},//Special
        },
        {//Water
        {MOVE_CRABHAMMER, MOVE_LIQUIDATION, MOVE_FISHIOUS_REND},//Physical
        {MOVE_SURF, MOVE_STEAM_ERUPTION, MOVE_ORIGIN_PULSE},//Special
        },
        {//Grass
        {MOVE_WOOD_HAMMER, MOVE_POWER_WHIP, MOVE_LEAF_BLADE},//Physical
        {MOVE_SEED_FLARE, MOVE_ENERGY_BALL, MOVE_GIGA_DRAIN},//Special
        },
        {//Electric
        {MOVE_BOLT_STRIKE, MOVE_VOLT_TACKLE, MOVE_FUSION_BOLT},//Physical
        {MOVE_THUNDER, MOVE_THUNDERBOLT, MOVE_THUNDERBOLT},//Special
        },
        {//Psychic
        {MOVE_PSYCHIC_FANGS, MOVE_PSYCHIC_FANGS, MOVE_ZEN_HEADBUTT},//Physical
        {MOVE_PSYSTRIKE, MOVE_PSYCHIC, MOVE_PHOTON_GEYSER},//Special
        },
        {//Ice
        {MOVE_ICE_HAMMER, MOVE_ICE_HAMMER, MOVE_ICICLE_CRASH},//Physical
        {MOVE_BLIZZARD, MOVE_ICE_BEAM, MOVE_ICE_BEAM},//Special
        },
        {//Dragon
        {MOVE_DRAGON_RUSH, MOVE_DRAGON_HAMMER, MOVE_DRAGON_CLAW},//Physical
        {MOVE_CLANGING_SCALES, MOVE_SPACIAL_REND, MOVE_CORE_ENFORCER},//Special
        },
        {//Dark
        {MOVE_HYPERSPACE_HOLE, MOVE_DARKEST_LARIAT, MOVE_CRUNCH},//Physical
        {MOVE_NIGHT_DAZE, MOVE_NIGHT_DAZE, MOVE_DARK_PULSE},//Special
        },
        {//Fairy
        {MOVE_PLAY_ROUGH, MOVE_PLAY_ROUGH, MOVE_PLAY_ROUGH},//Physical
        {MOVE_LIGHT_OF_RUIN, MOVE_MOONBLAST, MOVE_MOONBLAST},//Special
        }
    };
    
    
    u8 type1 = gBaseStats[species].type1;
    u8 type2 = gBaseStats[species].type2;
    u16 moveTypeArraysID = (type1 * 19) + type2;
    u8 randomMove = Random() % 3;
    u8 role = getRole(species);
    u8 split = 0;
    u32 caster = 1;
    
    
    u8 type = 0;
    u16 randomValue = 0;
    u32 chanceValue = 0;
    
    if (i == MAX_MON_MOVES - 1)
    {
        if (type1 == TYPE_NORMAL || type2 == TYPE_NORMAL)
            return MOVE_EXTREME_SPEED;
        else if (type1 == TYPE_DARK || type2 == TYPE_DARK)
            return MOVE_SUCKER_PUNCH;
        else if (type1 == TYPE_BUG || type2 == TYPE_BUG)
            return MOVE_U_TURN ;
        else if (type1 == TYPE_ELECTRIC || type2 == TYPE_ELECTRIC)
            return MOVE_VOLT_SWITCH ;
        else if (type1 == TYPE_WATER || type2 == TYPE_WATER)
            if (atk > spAtk)
                return MOVE_AQUA_JET;
            else
                return MOVE_WATER_SHURIKEN;
        else if (type1 == TYPE_FIGHTING || type2 == TYPE_FIGHTING)
            if (atk > spAtk)
                return MOVE_MACH_PUNCH;
            else
                return MOVE_VACUUM_WAVE;
        else if (type1 == TYPE_STEEL || type2 == TYPE_STEEL)
            return MOVE_BULLET_PUNCH;
        else if (type1 == TYPE_ICE || type2 == TYPE_ICE)
            return MOVE_ICE_SHARD;
        else if (type1 == TYPE_ROCK || type2 == TYPE_ROCK)
            return MOVE_ACCELEROCK;
        else if (type1 == TYPE_GHOST || type2 == TYPE_GHOST)
            return MOVE_SHADOW_SNEAK;    
        else
            return MOVE_EXTREME_SPEED;
    }
    else
    {
        type = oldPlayerMoveTypeArrays[moveTypeArraysID][i];
        randomValue = Random() % 1000;
        chanceValue = (caster * 500 * atk * atk *atk) / (caster * spAtk * spAtk * spAtk);
        if (atk > spAtk)
        {
                    chanceValue = (caster * 500 * spAtk * spAtk *spAtk) / (caster * atk * atk * atk);
                    if ((atk * 3) > (spAtk * 4))
                        split = 0;
                    else if (randomValue < chanceValue)
                        split = 1;
                    else
                        split = 0;
            }
        else
        {
                    chanceValue = (caster * 500 * atk * atk *atk) / (caster * spAtk * spAtk * spAtk);
                    if ((spAtk * 3) > (atk * 4))
                        split = 1;
                    else if (randomValue < chanceValue)
                        split = 0;
                    else 
                        split = 1;
            }  
    }
    
    return oldPlayerTypeMove[type][split][randomMove];
}

static u8 getRole (u16 species)
{
    u16 max = 0;
    u16 atk = gBaseStats[species].baseAttack;
    u16 spAtk = gBaseStats[species].baseSpAttack;
    u16 def = gBaseStats[species].baseDefense;
    u16 spDef = gBaseStats[species].baseSpDefense;
    u16 HP = gBaseStats[species].baseHP;
        
    if (atk >= spAtk)
        max = atk;
    else
        max = spAtk;
    
    if ((max * 3) > ((def + spDef + HP) * 1))
        return 0;
    else
        return 1;    
};

bool32 IsWildMonSmart(void)
{
    return (B_SMART_WILD_AI_FLAG != 0 && FlagGet(B_SMART_WILD_AI_FLAG));
}
