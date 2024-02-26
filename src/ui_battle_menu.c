#include "global.h"
#include "ui_battle_menu.h"
#include "strings.h"
#include "bg.h"
#include "battle.h"
#include "battle_main.h"
#include "battle_util.h"
#include "battle_script_commands.h"
#include "battle_anim.h"
#include "battle_ai_main.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_icon.h"
#include "item_use.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "overworld.h"
#include "util.h"
#include "event_data.h"
#include "constants/abilities.h"
#include "constants/species.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "mgba_printf/mgba.h"
#include "mgba_printf/mini_printf.h"
#include "trig.h"

//==========DEFINES==========//
enum
{
    SPRITE_ARR_ID_FIELD_ICON,
    SPRITE_ARR_ID_SELECTOR,
    SPRITE_ARR_ID_MON_ICON_1,
    SPRITE_ARR_ID_MON_ICON_2,
    SPRITE_ARR_ID_MON_ICON_3,
    SPRITE_ARR_ID_MON_ICON_4,
    SPRITE_ARR_ID_STATUS,
    //SPRITE_ARR_ID_TYPE_1,
    //SPRITE_ARR_ID_TYPE_2,
    //SPRITE_ARR_ID_TYPE_3,
    SPRITE_ARR_HELD_ITEM,
    SPRITE_ARR_ID_MON_ICON_1_SPEED,
    SPRITE_ARR_ID_MON_ICON_2_SPEED,
    SPRITE_ARR_ID_MON_ICON_3_SPEED,
    SPRITE_ARR_ID_MON_ICON_4_SPEED,
    SPRITE_ARR_ID_MON_ICON_1_PARTY_PLAYER,
    SPRITE_ARR_ID_MON_ICON_2_PARTY_PLAYER,
    SPRITE_ARR_ID_MON_ICON_3_PARTY_PLAYER,
    SPRITE_ARR_ID_MON_ICON_4_PARTY_PLAYER,
    SPRITE_ARR_ID_MON_ICON_5_PARTY_PLAYER,
    SPRITE_ARR_ID_MON_ICON_6_PARTY_PLAYER,
    SPRITE_ARR_ID_MON_ICON_1_PARTY_ENEMY,
    SPRITE_ARR_ID_MON_ICON_2_PARTY_ENEMY,
    SPRITE_ARR_ID_MON_ICON_3_PARTY_ENEMY,
    SPRITE_ARR_ID_MON_ICON_4_PARTY_ENEMY,
    SPRITE_ARR_ID_MON_ICON_5_PARTY_ENEMY,
    SPRITE_ARR_ID_MON_ICON_6_PARTY_ENEMY,
    NUM_SPRITES,
};

enum
{
    FIELD_INFO_WEATHER,
    FIELD_INFO_TERRAIN,
    FIELD_INFO_INVERSE_ROOM,
    FIELD_INFO_TRICK_ROOM,
    FIELD_INFO_GRAVITY,
    FIELD_INFO_WONDER_ROOM,
    FIELD_INFO_MAGIC_ROOM,
    FIELD_INFO_FAIRY_LOCK,
    FIELD_INFO_MUD_SPORT,
    FIELD_INFO_WATER_SPORT,
    FIELD_INFO_ION_DELUGE,
    NUM_FIELD_INFO,
};

enum
{
    SIDE_INFO_AURORA_VEIL,
    SIDE_INFO_REFLECT,
    SIDE_INFO_LIGHT_SCREEN,
    SIDE_INFO_TAILWIND,
    SIDE_INFO_SPIKES,
    SIDE_INFO_TOXIC_SPIKES,
    SIDE_INFO_STEALTH_ROCK,
    SIDE_INFO_CREEPING_THORNS,
    SIDE_INFO_STICKY_WEB,
    SIDE_INFO_SAFEGUARD,
    SIDE_INFO_MIST,
    SIDE_INFO_RAINBOW,
    SIDE_INFO_SEA_OF_FIRE,
    SIDE_INFO_SWAMP,
    NUM_SIDE_INFO,
};

enum
{
    //Status 1
    STATUS_INFO_PRIMARY,
    //Status 2
    STATUS_INFO_CONFUSION,
    STATUS_INFO_FUTURE_SIGHT,
    //STATUS_INFO_FLINCHED,
    STATUS_INFO_UPROAR,
    STATUS_INFO_BIDE,
    STATUS_INFO_INFUATION,
    STATUS_INFO_FOCUS_ENERGY,
    STATUS_INFO_TRANSFORMED,
    STATUS_INFO_ESCAPE_PREVENTION,
    STATUS_INFO_CURSED,
    STATUS_INFO_FORESIGHT,
    STATUS_INFO_DEFENSE_CURL,
    STATUS_INFO_TORMENT,
    //Status 3
    STATUS_INFO_LEECHSEED,
    STATUS_INFO_PERISH_SONG,
    STATUS_INFO_MINIMIZED,
    STATUS_INFO_CHARGED_UP,
    STATUS_INFO_ROOTED,
    STATUS_INFO_YAWN,
    STATUS_INFO_GRUDGE,
    STATUS_INFO_CANT_CRIT,
    STATUS_INFO_GASTRO_ACID,
    STATUS_INFO_EMBARGO,
    STATUS_INFO_SMACKED_DOWN,
    STATUS_INFO_MIRACLE_EYED,
    STATUS_INFO_HEAL_BLOCKED,
    STATUS_INFO_AQUA_RING,
    STATUS_INFO_MAGNET_RISE,
    STATUS_INFO_SEMI_INVULNERABLE,
    //STATUS_INFO_UNDERGROUND,
    //STATUS_INFO_UNDERWATER,
    //STATUS_INFO_PHANTOM,FORCE,
    //STATUS_INFO_ON_AIR,
    STATUS_INFO_ELECTRIFIED,
    STATUS_INFO_PLASMA_FIST,
    STATUS_INFO_COILED,
    STATUS_INFO_PROTOSYNTHESIS,
    STATUS_INFO_QUARK_DRIVE,
    NUM_STATUS_INFO,
};

#define MAX_TARGETS 2

//252+ SpA Abomasnow Blizzard vs. 168 HP / 0 SpD Abomasnow: 178-211 (49 - 58.1%) -- 97.7% chance to 2HKO
struct DamageCalculation
{
    bool8 calculated;
    //Damage
    s32 minDamage;
    u8  minDamagePercentage;
    s32 maxDamage;
    u8  maxDamagePercentage;
    //KO
    u8  hits2KO;
    s32 chance2KO;
    //NatureStuff
    u8  attackerNatureUp;
    u8  attackerNatureDown;
    u8  targetNatureUp;
    u8  targetNatureDown;
    //u8 *DamageCalculationText;
    u8 targetEvs[NUM_STATS];
    u8 battlerEvs[NUM_STATS];
    bool8 noDamage;
};

struct MenuResources
{
    MainCallback savedCallback;     // determines callback to run when we exit. e.g. where do we want to go after closing the menu
    u8 gfxLoadState;
    u8 battlerId;
    u8 modeId;
    u8 tabId;
    u8 fieldTabId;
    u8 tabModeId;
    u8 moveModeId;
    u8 dmgCalculatorTarget;
    u8 spriteIds[NUM_SPRITES];
    u8 fieldInfo[NUM_FIELD_INFO];
    u8 currentFieldInfo;
    u8 numFields;
    u8 SideInfoPlayer[NUM_SIDE_INFO];
    u8 currentSideInfoPlayer;
    u8 numSideInfoPlayer;
    u8 SideInfoEnemy[NUM_SIDE_INFO];
    u8 currentSideInfoEnemy;
    u8 speedModeId;
    u8 numSideInfoEnemy;
    u8 BattlerStatus[NUM_STATUS_INFO][MAX_BATTLERS_COUNT];
    u8 CurrentStatusInfo[MAX_BATTLERS_COUNT];
    u8 numStatusInfo[MAX_BATTLERS_COUNT];
    struct DamageCalculation damageCalculation[MAX_BATTLERS_COUNT][MAX_TARGETS * 2][MAX_MON_MOVES];
};

enum WindowIds
{
    WINDOW_1,
};

enum battler_TabIds
{
    TAB_STATS,
    TAB_ABILITIES,
    TAB_MOVES,
    TAB_DAMAGE_CALCULATOR,
    TAB_STATUS,
    NUM_TABS,
};

enum field_TabsIds
{
    TAB_PARTY,
    TAB_FIELD,
    TAB_SPEED,
    TAB_PLAYER_SIDE,
    TAB_ENEMY_SIDE,
    NUM_FIELD_TABS,
};

enum menu_colors
{
    MENU_COLOR_BLUE,
    MENU_COLOR_RED,
    MENU_COLOR_YELLOW,
    MENU_COLOR_GREEN,
    NUM_COLORS,
};

enum modes
{
    MODE_BATTLER2,
    MODE_BATTLER0,
    MODE_FIELD,
    MODE_BATTLER1,
    MODE_BATTLER3,
    NUM_MODES
};

enum move_modes
{
    MOVE_MODE_NORMAL,
    MOVE_MODE_DESCRIPTION,
    //MOVE_MODE_DAMAGE_CALCULATOR,
    MOVE_MODE_AFFECTED_1,
    MOVE_MODE_AFFECTED_2,
    NUM_MOVE_MODES
};

//==========EWRAM==========//
static EWRAM_DATA struct MenuResources *sMenuDataPtr = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

//==========STATIC=DEFINES==========//
static void Battle_Menu_RunSetup(void);
static bool8 Menu_DoGfxSetup(void);
static bool8 Menu_InitBgs(void);
static void Menu_FadeAndBail(void);
static bool8 Menu_LoadGraphics(void);
static void Menu_InitWindows(void);
static void PrintToWindow(u8 windowId, u8 colorIdx);
static void PrintPartyTab(void);
static void PrintFieldTab(void);
static void PrintSpeedTab(void);
static void PrintSideTab(u8 side);
static void PrintStatsTab(void);
static void PrintAbilityTab(void);
static void PrintStatusTab(void);
static void PrintDamageCalulatorTab(void);
static void PrintDamageCalculation(u8 battler, u8 target, u8 moveidx);
static void Task_MenuWaitFadeIn(u8 taskId);
static void Task_MenuMain(u8 taskId);
static void PrintMoveInfo(u16 move, u8 x, u8 y, u8 moveIdx);

static u8 ShowSpeciesIcon(u8 num);
static u8 ShowSpeciesIconSpeed(u8 battler, u8 x, u8 y);
static void FreeEveryPartyMonIconSprite(void);
static void FreePartySpeciesIconSprite(u8 num, bool8 isEnemyMon);
static u8 ShowSpeciesIconParty(u8 num, bool8 isEnemyParty, u8 x, u8 y);
static void FreeEveryMonIconSprite(void);
static void FreeSpeciesIconSprite(u8 battler);
static void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible);
static void SetMonTypeIcons(void);
static void SetTypeIconSpritePosAndPal(u8 typeId, u8 x, u8 y, u8 spriteArrayId);
static void CreateSetStatusSprite(void);
static u8 DestroyBattleMenuSprite(u8 spriteArrayId);
static void setBattler(void);
static void LoadTilemapFromMode(void);
static void PrintPage(void);

static void ShowFieldIcon(void);
static void CreateSelectorSprite(void);
static void FreeItemIconSprite(void);
void FreeFieldSprite(void);
void FreeSelectorSprite(void);
static void CalculateDamage(u8 battler, u8 target, u8 moveIndex);

//==========CONST=DATA==========//
static const struct BgTemplate sMenuBgTemplates[] =
{
    {
        .bg = 0,    // windows, etc
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    }, 
    {
        .bg = 1,    // this bg loads the UI tilemap
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 2
    },
    {
        .bg = 2,    // this bg loads the UI tilemap
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .priority = 0
    }
};

static const struct WindowTemplate sMenuWindowTemplates[] = 
{
    [WINDOW_1] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 0,   // position from left (per 8 pixels)
        .tilemapTop = 0,    // position from top (per 8 pixels)
        .width = 30,        // width (per 8 pixels)
        .height = 20,       // height (per 8 pixels)
        .paletteNum = 0,    // palette index to use for text
        .baseBlock = 1,     // tile start in VRAM
    },
};

static const u32 sMenuTiles[]      = INCBIN_U32("graphics/ui_menus/battle_menu/tiles.4bpp.lz");
static const u8 sStatDownArrow[]   = INCBIN_U8("graphics/ui_menus/battle_menu/stat_down_arrow.4bpp");
static const u8 sStatUpArrow[]     = INCBIN_U8("graphics/ui_menus/battle_menu/stat_up_arrow.4bpp");
static const u8 sCheck[]           = INCBIN_U8("graphics/ui_menus/battle_menu/check.4bpp");

//Palettes
static const u16 sMenuPalette[]        = INCBIN_U16("graphics/ui_menus/battle_menu/palette.gbapal");
static const u16 sMenuPalette_Blue[]   = INCBIN_U16("graphics/ui_menus/battle_menu/palette_blue.gbapal");
static const u16 sMenuPalette_Yellow[] = INCBIN_U16("graphics/ui_menus/battle_menu/palette_yellow.gbapal");
static const u16 sMenuPalette_Green[]  = INCBIN_U16("graphics/ui_menus/battle_menu/palette_green.gbapal");
static const u16 sMenuPalette_Red[]    = INCBIN_U16("graphics/ui_menus/battle_menu/palette_red.gbapal");

//Battler Tabs
static const u32 sMenu_Tilemap_Singles_Battler_Status[]     = INCBIN_U32("graphics/ui_menus/battle_menu/titlemap_singles_battler_status.bin.lz");
static const u32 sMenu_Tilemap_Doubles_Battler_Status[]     = INCBIN_U32("graphics/ui_menus/battle_menu/titlemap_doubles_battler_status.bin.lz");
//
static const u32 sMenu_Tilemap_Singles_Battler_Abilities[]  = INCBIN_U32("graphics/ui_menus/battle_menu/titlemap_singles_battler_abilities.bin.lz");
static const u32 sMenu_Tilemap_Doubles_Battler_Abilities[]  = INCBIN_U32("graphics/ui_menus/battle_menu/titlemap_doubles_battler_abilities.bin.lz");
//Field Tabs
static const u32 sMenu_Tilemap_Singles_Field[]              = INCBIN_U32("graphics/ui_menus/battle_menu/titlemap_singles_field.bin.lz");
static const u32 sMenu_Tilemap_Doubles_Field[]              = INCBIN_U32("graphics/ui_menus/battle_menu/titlemap_doubles_field.bin.lz");
static const u32 sMenu_Tilemap_Party_Info[]                 = INCBIN_U32("graphics/ui_menus/battle_menu/tilemap_field_party.bin.lz");
//
static const u32 sMenu_Tilemap_Singles_Speed[]              = INCBIN_U32("graphics/ui_menus/battle_menu/titlemap_singles_field_speed.bin.lz");
static const u32 sMenu_Tilemap_Doubles_Speed[]              = INCBIN_U32("graphics/ui_menus/battle_menu/titlemap_doubles_field_speed.bin.lz");

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};
static const u8 sMenuWindowFontColors[][3] = 
{
    [FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT,  3,  2},
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT,  1,  3},
    [FONT_RED]    = {TEXT_COLOR_TRANSPARENT,  14, 2},
    [FONT_BLUE]   = {TEXT_COLOR_TRANSPARENT,  13, 2},
};

//==========FUNCTIONS==========//
// UI loader template
void Task_OpenBattleMenuFromStartMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        UI_Battle_Menu_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

static void Task_CalculateDamage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 i, j , k;

    for(i = 0; i < MAX_BATTLERS_COUNT; i++){
        for(j = 0; j < MAX_TARGETS * 2; j++){
            for(k = 0; k < MAX_MON_MOVES; k++){
                if(IsBattlerAlive(i) && 
                   IsBattlerAlive(j) && 
                   GetBattlerSide(i) != GetBattlerSide(j) &&
                   gBattleMons[i].moves[k] != MOVE_NONE   &&
                   gBattleMoves[gBattleMons[i].moves[k]].split != SPLIT_STATUS){
                    CalculateDamage(i, j, k);
                }
            }
        }
    }
    DestroyTask(taskId);
}

// This is our main initialization function if you want to call the menu from elsewhere
void UI_Battle_Menu_Init(MainCallback callback)
{
    u8 i, j;
    bool8 isExtraInfoShown;

    if ((sMenuDataPtr = AllocZeroed(sizeof(struct MenuResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    // initialize stuff
    sMenuDataPtr->gfxLoadState          = 0;
    sMenuDataPtr->moveModeId            = 0;
    sMenuDataPtr->tabModeId             = 0;
    sMenuDataPtr->tabId                 = 0;
    sMenuDataPtr->fieldTabId            = 0;
    sMenuDataPtr->dmgCalculatorTarget   = 0;

    sMenuDataPtr->currentFieldInfo      = 0;
    sMenuDataPtr->numFields             = 0;

    sMenuDataPtr->currentSideInfoPlayer = 0;
    sMenuDataPtr->numSideInfoPlayer     = 0;

    sMenuDataPtr->currentSideInfoEnemy  = 0;
    sMenuDataPtr->numSideInfoEnemy      = 0;

    sMenuDataPtr->numStatusInfo[B_POSITION_PLAYER_LEFT]    = 0;
    sMenuDataPtr->numStatusInfo[B_POSITION_OPPONENT_LEFT]  = 0;
    sMenuDataPtr->numStatusInfo[B_POSITION_PLAYER_RIGHT]   = 0;
    sMenuDataPtr->numStatusInfo[B_POSITION_OPPONENT_RIGHT] = 0;

    if(IsDoubleBattle())
        sMenuDataPtr->modeId = MODE_BATTLER2;
    else
        sMenuDataPtr->modeId = MODE_BATTLER0;
    setBattler();
    for(i = 0; i < NUM_SPRITES; i++)
        sMenuDataPtr->spriteIds[i] = SPRITE_NONE;
    sMenuDataPtr->savedCallback = callback;

    for(i = 0; i < NUM_FIELD_INFO; i++)
        sMenuDataPtr->fieldInfo[i] = NUM_FIELD_INFO;

    //Field Info
    for(i = 0; i < NUM_FIELD_INFO; i++){
        isExtraInfoShown = FALSE;
        switch(i){
            case FIELD_INFO_WEATHER:
                if((gBattleWeather & WEATHER_ANY))
                    isExtraInfoShown = TRUE;
            break;
            case FIELD_INFO_TERRAIN:
                if(gFieldStatuses & STATUS_FIELD_TERRAIN_ANY)
                    isExtraInfoShown = TRUE;
            break;
            case FIELD_INFO_INVERSE_ROOM:
                if(gFieldStatuses & STATUS_FIELD_INVERSE_ROOM)
                    isExtraInfoShown = TRUE;
            break;
            case FIELD_INFO_TRICK_ROOM:
                if(gFieldStatuses & STATUS_FIELD_TRICK_ROOM)
                    isExtraInfoShown = TRUE;
            break;
            case FIELD_INFO_GRAVITY:
                if((gFieldStatuses & STATUS_FIELD_GRAVITY))
                    isExtraInfoShown = TRUE;
            break;
            case FIELD_INFO_WONDER_ROOM:
                if(gFieldStatuses & STATUS_FIELD_WONDER_ROOM)
                    isExtraInfoShown = TRUE;
            break;
            case FIELD_INFO_MAGIC_ROOM:
                if(gFieldStatuses & STATUS_FIELD_MAGIC_ROOM)
                    isExtraInfoShown = TRUE;
            break;
            case FIELD_INFO_FAIRY_LOCK:
                if(gFieldStatuses & STATUS_FIELD_FAIRY_LOCK)
                    isExtraInfoShown = TRUE;
            break;
            case FIELD_INFO_MUD_SPORT:
                if(gFieldStatuses & STATUS_FIELD_MUDSPORT)
                    isExtraInfoShown = TRUE;
            break;
            case FIELD_INFO_WATER_SPORT:
                if(gFieldStatuses & STATUS_FIELD_WATERSPORT)
                    isExtraInfoShown = TRUE;
            break;
            case FIELD_INFO_ION_DELUGE:
                if(gFieldStatuses & STATUS_FIELD_ION_DELUGE)
                    isExtraInfoShown = TRUE;
            break;
        }

        if(isExtraInfoShown){
            sMenuDataPtr->fieldInfo[sMenuDataPtr->numFields] = i;
            sMenuDataPtr->numFields++;
        }
    }

    //Player Side Info
    for(i = 0; i < NUM_SIDE_INFO; i++){
        isExtraInfoShown = FALSE;
        switch(i){
            case SIDE_INFO_AURORA_VEIL:
                if(gSideStatuses[B_SIDE_PLAYER] & SIDE_STATUS_AURORA_VEIL)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_REFLECT:
                if(gSideStatuses[B_SIDE_PLAYER] & SIDE_STATUS_REFLECT)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_LIGHT_SCREEN:
                if(gSideStatuses[B_SIDE_PLAYER] & SIDE_STATUS_LIGHTSCREEN)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_TAILWIND:
                if(gSideStatuses[B_SIDE_PLAYER] & SIDE_STATUS_TAILWIND)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_SPIKES:
                if(gSideStatuses[B_SIDE_PLAYER] & SIDE_STATUS_SPIKES)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_TOXIC_SPIKES:
                if(gSideStatuses[B_SIDE_PLAYER] & SIDE_STATUS_TOXIC_SPIKES)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_STEALTH_ROCK:
                if(gSideStatuses[B_SIDE_PLAYER] & SIDE_STATUS_STEALTH_ROCK && gSideTimers[B_SIDE_PLAYER].stealthRockType == TYPE_ROCK)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_CREEPING_THORNS:
                if(gSideStatuses[B_SIDE_PLAYER] & SIDE_STATUS_STEALTH_ROCK && gSideTimers[B_SIDE_PLAYER].stealthRockType == TYPE_GRASS)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_STICKY_WEB:
                if(gSideStatuses[B_SIDE_PLAYER] & SIDE_STATUS_STICKY_WEB)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_SAFEGUARD:
                if(gSideStatuses[B_SIDE_PLAYER] & SIDE_STATUS_SAFEGUARD)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_MIST:
                if(gSideStatuses[B_SIDE_PLAYER] & SIDE_STATUS_MIST)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_RAINBOW:
                if(gSideTimers[B_SIDE_PLAYER].rainbowTimer)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_SEA_OF_FIRE:
                if(gSideTimers[B_SIDE_PLAYER].fireSeaTimer)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_SWAMP:
                if(gSideTimers[B_SIDE_PLAYER].swampTimer)
                    isExtraInfoShown = TRUE;
            break;
        }

        if(isExtraInfoShown){
            sMenuDataPtr->SideInfoPlayer[sMenuDataPtr->numSideInfoPlayer] = i;
            sMenuDataPtr->numSideInfoPlayer++;
        }
    }

    //Enemy Side Info
    for(i = 0; i < NUM_SIDE_INFO; i++){
        isExtraInfoShown = FALSE;
        switch(i){
            case SIDE_INFO_AURORA_VEIL:
                if(gSideStatuses[B_SIDE_OPPONENT] & SIDE_STATUS_AURORA_VEIL)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_REFLECT:
                if(gSideStatuses[B_SIDE_OPPONENT] & SIDE_STATUS_REFLECT)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_LIGHT_SCREEN:
                if(gSideStatuses[B_SIDE_OPPONENT] & SIDE_STATUS_LIGHTSCREEN)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_TAILWIND:
                if(gSideStatuses[B_SIDE_OPPONENT] & SIDE_STATUS_TAILWIND)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_SPIKES:
                if(gSideStatuses[B_SIDE_OPPONENT] & SIDE_STATUS_SPIKES)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_TOXIC_SPIKES:
                if(gSideStatuses[B_SIDE_OPPONENT] & SIDE_STATUS_TOXIC_SPIKES)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_STEALTH_ROCK:
                if(gSideStatuses[B_SIDE_OPPONENT] & SIDE_STATUS_STEALTH_ROCK && gSideTimers[B_SIDE_OPPONENT].stealthRockType == TYPE_ROCK)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_CREEPING_THORNS:
                if(gSideStatuses[B_SIDE_OPPONENT] & SIDE_STATUS_STEALTH_ROCK && gSideTimers[B_SIDE_OPPONENT].stealthRockType == TYPE_GRASS)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_STICKY_WEB:
                if(gSideStatuses[B_SIDE_OPPONENT] & SIDE_STATUS_STICKY_WEB)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_SAFEGUARD:
                if(gSideStatuses[B_SIDE_OPPONENT] & SIDE_STATUS_SAFEGUARD)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_MIST:
                if(gSideStatuses[B_SIDE_OPPONENT] & SIDE_STATUS_MIST)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_RAINBOW:
                if(gSideTimers[B_SIDE_OPPONENT].rainbowTimer)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_SEA_OF_FIRE:
                if(gSideTimers[B_SIDE_OPPONENT].fireSeaTimer)
                    isExtraInfoShown = TRUE;
            break;
            case SIDE_INFO_SWAMP:
                if(gSideTimers[B_SIDE_OPPONENT].swampTimer)
                    isExtraInfoShown = TRUE;
            break;
        }

        if(isExtraInfoShown){
            sMenuDataPtr->SideInfoEnemy[sMenuDataPtr->numSideInfoEnemy] = i;
            sMenuDataPtr->numSideInfoEnemy++;
        }
    }

    //Battler Status Info
    for(i = 0; i < NUM_STATUS_INFO; i++){
        for(j = 0; j < MAX_BATTLERS_COUNT; j++){
            isExtraInfoShown = FALSE;
            switch(i){
                case STATUS_INFO_PRIMARY:
                    if(gBattleMons[j].status1 & STATUS1_ANY)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_CONFUSION:
                    if(gBattleMons[j].status2 & STATUS2_CONFUSION)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_FUTURE_SIGHT:
                    if(gWishFutureKnock.futureSightCounter[j] != 0)
                        isExtraInfoShown = TRUE;
                case STATUS_INFO_UPROAR:
                    if(gBattleMons[j].status2 & STATUS2_UPROAR)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_BIDE:
                    if(gBattleMons[j].status2 & STATUS2_BIDE)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_INFUATION:
                    if(gBattleMons[j].status2 & STATUS2_INFATUATION)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_FOCUS_ENERGY:
                    if(gBattleMons[j].status2 & STATUS2_FOCUS_ENERGY)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_TRANSFORMED:
                    if(gBattleMons[j].status2 & STATUS2_TRANSFORMED)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_ESCAPE_PREVENTION:
                    if(gBattleMons[j].status2 & STATUS2_ESCAPE_PREVENTION)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_CURSED:
                    if(gBattleMons[j].status2 & STATUS2_CURSED)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_FORESIGHT:
                    if(gBattleMons[j].status2 & STATUS2_FORESIGHT)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_DEFENSE_CURL:
                    if(gBattleMons[j].status2 & STATUS2_DEFENSE_CURL)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_TORMENT:
                    if(gBattleMons[j].status2 & STATUS2_TORMENT)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_LEECHSEED:
                    if(gStatuses3[j] & STATUS3_LEECHSEED)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_PERISH_SONG:
                    if(gStatuses3[j] & STATUS3_PERISH_SONG)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_MINIMIZED:
                    if(gStatuses3[j] & STATUS3_MINIMIZED)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_CHARGED_UP:
                    if(gStatuses3[j] & STATUS3_CHARGED_UP)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_ROOTED:
                    if(gStatuses3[j] & STATUS3_ROOTED)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_YAWN:
                    if(gStatuses3[j] & STATUS3_YAWN)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_GRUDGE:
                    if(gStatuses3[j] & STATUS3_GRUDGE)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_CANT_CRIT:
                    if(gStatuses3[j] & STATUS3_CANT_SCORE_A_CRIT)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_GASTRO_ACID:
                    if(gStatuses3[j] & STATUS3_GASTRO_ACID)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_EMBARGO:
                    if(gStatuses3[j] & STATUS3_EMBARGO)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_SMACKED_DOWN:
                    if(gStatuses3[j] & STATUS3_SMACKED_DOWN)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_MIRACLE_EYED:
                    if(gStatuses3[j] & STATUS3_MIRACLE_EYED)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_HEAL_BLOCKED:
                    if(gStatuses3[j] & STATUS3_HEAL_BLOCK)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_AQUA_RING:
                    if(gStatuses3[j] & STATUS3_AQUA_RING)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_MAGNET_RISE:
                    if(gStatuses3[j] & STATUS3_MAGNET_RISE)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_SEMI_INVULNERABLE:
                    if(gStatuses3[j] & STATUS3_SEMI_INVULNERABLE)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_ELECTRIFIED:
                    if(gStatuses4[j] & STATUS4_ELECTRIFIED)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_PLASMA_FIST:
                    if(gStatuses4[j] & STATUS4_PLASMA_FISTS)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_COILED:
                    if(gStatuses4[j] & STATUS4_COILED)
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_PROTOSYNTHESIS:
                    if (GetAbilityState(j, ABILITY_PROTOSYNTHESIS))
                        isExtraInfoShown = TRUE;
                break;
                case STATUS_INFO_QUARK_DRIVE:
                    if (GetAbilityState(j, ABILITY_QUARK_DRIVE))
                        isExtraInfoShown = TRUE;
                break;
            }

            if(isExtraInfoShown && IsBattlerAlive(j)){
                sMenuDataPtr->BattlerStatus[sMenuDataPtr->numStatusInfo[j]][j] = i;
                sMenuDataPtr->numStatusInfo[j]++;
            }
        }
    }

    SetMainCallback2(Battle_Menu_RunSetup);
}

static void Battle_Menu_RunSetup(void)
{
    while (1)
    {
        if (Menu_DoGfxSetup() == TRUE)
            break;
    }
}

static void Menu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Menu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

#define POKEMON_ICON_X   (1 * 8)  + (2 * 8)

#define POKEMON_ICON_1_Y (4 * 8)  + (2 * 8)
#define POKEMON_ICON_2_Y (12 * 8) + (2 * 8)
#define POKEMON_ICON_3_Y (0 * 8)  + (2 * 8)
#define POKEMON_ICON_4_Y (16 * 8) + (2 * 8)

static bool8 Menu_DoGfxSetup(void)
{
    u8 taskId;
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (Menu_InitBgs())
        {
            sMenuDataPtr->gfxLoadState = 0;
            gMain.state++;
        }
        else
        {
            Menu_FadeAndBail();
            return TRUE;
        }
        break;
    case 3:
        if (Menu_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 4:
        LoadMessageBoxAndBorderGfx();
        Menu_InitWindows();
        gMain.state++;
        break;
    case 5:
        taskId = CreateTask(Task_MenuWaitFadeIn, 0);
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        //Start 
        ShowSpeciesIcon(0);
        ShowSpeciesIcon(1);
        if(IsDoubleBattle()){
            ShowSpeciesIcon(2);
            ShowSpeciesIcon(3);
        }
        PrintStatsTab();
        //CreateTask(Task_CalculateDamage, 1);
        CreateSelectorSprite();
        ShowFieldIcon();
        gMain.state++;
        break;
    default:
        SetVBlankCallback(Menu_VBlankCB);
        SetMainCallback2(Menu_MainCB);
        return TRUE;
    }
    return FALSE;
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void Menu_FreeResources(void)
{
    try_free(sMenuDataPtr);
    try_free(sBg1TilemapBuffer);
    FreeAllWindowBuffers();
}

void LoadTilemapFromMode(void)
{
    try_free(sBg1TilemapBuffer);
    sBg1TilemapBuffer == NULL;

    sBg1TilemapBuffer = Alloc(0x800);

    memset(sBg1TilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sMenuBgTemplates, NELEMS(sMenuBgTemplates));
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);

    //ResetTempTileDataBuffers();
    //DecompressAndCopyTileDataToVram(1, sMenuTiles, 0, 0, 0);
    //FreeTempTileDataBuffersIfPossible();

    if(sMenuDataPtr->modeId != MODE_FIELD){
        switch(sMenuDataPtr->tabId){
            case TAB_STATS:
                if(IsDoubleBattle())
                    LZDecompressWram(sMenu_Tilemap_Doubles_Battler_Status, sBg1TilemapBuffer);
                else
                    LZDecompressWram(sMenu_Tilemap_Singles_Battler_Status, sBg1TilemapBuffer);
            break;
            case TAB_ABILITIES:
            case TAB_MOVES:
            case TAB_DAMAGE_CALCULATOR:
                if(IsDoubleBattle())
                    LZDecompressWram(sMenu_Tilemap_Doubles_Battler_Abilities, sBg1TilemapBuffer);
                else
                    LZDecompressWram(sMenu_Tilemap_Singles_Battler_Abilities, sBg1TilemapBuffer);
            break;
            default:
                if(IsDoubleBattle())
                    LZDecompressWram(sMenu_Tilemap_Doubles_Field, sBg1TilemapBuffer);
                else
                    LZDecompressWram(sMenu_Tilemap_Singles_Field, sBg1TilemapBuffer);
            break;
        }
    }
    else{
        switch(sMenuDataPtr->fieldTabId){
            case TAB_PARTY:
                LZDecompressWram(sMenu_Tilemap_Party_Info, sBg1TilemapBuffer);
            break;
            case TAB_FIELD:
            case TAB_PLAYER_SIDE:
            case TAB_ENEMY_SIDE:
                if(IsDoubleBattle())
                    LZDecompressWram(sMenu_Tilemap_Doubles_Field, sBg1TilemapBuffer);
                else
                    LZDecompressWram(sMenu_Tilemap_Singles_Field, sBg1TilemapBuffer);
            break;
            case TAB_SPEED:
                if(IsDoubleBattle())
                    LZDecompressWram(sMenu_Tilemap_Doubles_Speed, sBg1TilemapBuffer);
                else
                    LZDecompressWram(sMenu_Tilemap_Singles_Speed, sBg1TilemapBuffer);
            break;
        }
    }
}

static void Task_MenuWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeFieldSprite();
        FreeSelectorSprite();
        FreeItemIconSprite();
        SetMainCallback2(sMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}

static void Menu_FadeAndBail(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_MenuWaitFadeAndBail, 0);
    SetVBlankCallback(Menu_VBlankCB);
    SetMainCallback2(Menu_MainCB);
}

static bool8 Menu_InitBgs(void)
{
    ResetAllBgsCoordinates();
    sBg1TilemapBuffer = Alloc(0x800);
    if (sBg1TilemapBuffer == NULL)
        return FALSE;

    memset(sBg1TilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sMenuBgTemplates, NELEMS(sMenuBgTemplates));
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    return TRUE;
}

static bool8 Menu_LoadGraphics(void)
{
    switch (sMenuDataPtr->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sMenuTiles, 0, 0, 0);
        sMenuDataPtr->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            if(IsDoubleBattle())
                LZDecompressWram(sMenu_Tilemap_Doubles_Battler_Status, sBg1TilemapBuffer);
            else
                LZDecompressWram(sMenu_Tilemap_Singles_Battler_Status, sBg1TilemapBuffer);
            sMenuDataPtr->gfxLoadState++;
        }
        break;
    case 2:
        LoadPalette(sMenuPalette, 0, 32);
        sMenuDataPtr->gfxLoadState++;
        break;
    default:
        sMenuDataPtr->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void Menu_InitWindows(void)
{
    u32 i;

    InitWindows(sMenuWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);

    //First Window
    FillWindowPixelBuffer(WINDOW_1, 0);
    LoadUserWindowBorderGfx(WINDOW_1, 720, 14 * 16);
    PutWindowTilemap(WINDOW_1);
    CopyWindowToVram(WINDOW_1, 3);

    ScheduleBgCopyTilemapToVram(2);
}

static const u8 sText_MyMenu[] = _("HP: {STR_VAR_1}/{STR_VAR_2}");
static const u8 sText_HP[] = _("{STR_VAR_1}/{STR_VAR_2}");
static const u8 sText_PP[] = _("PP: {STR_VAR_1}/{STR_VAR_2}");

static const u8 sText_Ability[] = _("Ability:");
static const u8 sText_Innate[]  = _("Innate:");
static const u8 sText_Held_Item[] = _("Held Item:\n{STR_VAR_1}");
static const u8 sText_None[]  = _("None");
static const u8 sYourOpponentPokemonData[] = _("Your Opponent Pokémon Battle Data");
static const u8 sYourPokemonData[] = _("Your Pokémon Battle Data");

static const u8 sText_StatHP[]         = _("HP");
static const u8 sText_Attack[]         = _("Atk");
static const u8 sText_Defense[]        = _("Def");
static const u8 sText_SpecialAttack[]  = _("SpA");
static const u8 sText_SpecialDefense[] = _("SpD");
static const u8 sText_Speed[]          = _("Spd");
static const u8 sText_Accuracy[]       = _("Acc");
static const u8 sText_Evasion[]        = _("Eva");
static const u8 sText_Critical[]       = _("Crt");

static u8 statorder[NUM_BATTLE_STATS] = {
    STAT_HP,
    STAT_ATK,
    STAT_DEF,
    STAT_SPATK,
    STAT_SPDEF,
    STAT_SPEED,
    STAT_ACC,
    STAT_EVASION,
};

#define PAL_UI_SPRITES        14
#define PAL_FIELD_ICON        15

#define TAG_ITEM_ICON         4133
#define TAG_BATTLER_SPEED     4134
#define TAG_ICON_PARTY_PLAYER 4135
#define TAG_ICON_PARTY_ENEMY  TAG_ICON_PARTY_PLAYER + PARTY_SIZE

static const u32 gBattleFieldIconForest_Gfx[] = INCBIN_U32("graphics/ui_menus/battle_menu/fields/forest.4bpp.lz");
static const u16 gBattleFieldIconForest_Pal[] = INCBIN_U16("graphics/ui_menus/battle_menu/fields/forest.gbapal");

static const struct SpritePalette sBattleMenuFieldIconSpritePalette_Forest[] = {gBattleFieldIconForest_Pal, PAL_FIELD_ICON};

//Field Icon
void FreeFieldSprite(void)
{
    u8 *spriteId = &sMenuDataPtr->spriteIds[SPRITE_ARR_ID_FIELD_ICON];
    if (*spriteId != SPRITE_NONE)
    {
        FreeSpriteTilesByTag(SPRITE_ARR_ID_FIELD_ICON);
        FreeSpritePaletteByTag(SPRITE_ARR_ID_FIELD_ICON);
        FreeSpriteOamMatrix(&gSprites[*spriteId]);
        DestroySprite(&gSprites[*spriteId]);
        *spriteId = SPRITE_NONE;
        sMenuDataPtr->spriteIds[SPRITE_ARR_ID_FIELD_ICON] = SPRITE_NONE;
    }
}

static void ShowFieldIcon(void)
{
    u8 spriteId;
    u8 SpriteTag = SPRITE_ARR_ID_FIELD_ICON;
    struct CompressedSpriteSheet sSpriteSheet_FieldIcon = {gBattleFieldIconForest_Gfx, 0x0800, SpriteTag};
    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

    TempSpriteTemplate.tileTag = SpriteTag;
    TempSpriteTemplate.callback = SpriteCallbackDummy;

    LoadCompressedSpriteSheet(&sSpriteSheet_FieldIcon);
    LoadSpritePalette(sBattleMenuFieldIconSpritePalette_Forest);
    TempSpriteTemplate.paletteTag = PAL_FIELD_ICON;
    spriteId = CreateSprite(&TempSpriteTemplate, 4, 68, 0);
    sMenuDataPtr->spriteIds[SPRITE_ARR_ID_FIELD_ICON] = spriteId;

    gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_FIELD_ICON]].oam.shape = SPRITE_SHAPE(64x32);
    gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_FIELD_ICON]].oam.size = SPRITE_SIZE(64x32);
    gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_FIELD_ICON]].oam.priority = 1;
}

static void SpriteCB_Selector(struct Sprite *sprite)
{
    u8 val = sprite->data[0];
    sprite->y2 = (gSineTable[val] / 128) + ((sMenuDataPtr->modeId * 4) * 8);
    sprite->data[0] += 8;
}

static const u32 gBattleSelector_Gfx[] = INCBIN_U32("graphics/ui_menus/battle_menu/fields/selector.4bpp.lz");
static const u16 gBattleSelector_Pal[] = INCBIN_U16("graphics/ui_menus/battle_menu/fields/selector.gbapal");

static const struct SpritePalette sBattleMenuSelectorSpritePalette[] = {gBattleSelector_Pal, PAL_UI_SPRITES};
//Selector
void FreeSelectorSprite(void)
{
    u8 *spriteId = &sMenuDataPtr->spriteIds[SPRITE_ARR_ID_SELECTOR];
    if (*spriteId != SPRITE_NONE)
    {
        FreeSpriteTilesByTag(SPRITE_ARR_ID_SELECTOR);
        FreeSpritePaletteByTag(SPRITE_ARR_ID_SELECTOR);
        FreeSpriteOamMatrix(&gSprites[*spriteId]);
        DestroySprite(&gSprites[*spriteId]);
        *spriteId = SPRITE_NONE;
        sMenuDataPtr->spriteIds[SPRITE_ARR_ID_SELECTOR] = SPRITE_NONE;
    }
}

static void CreateSelectorSprite(void)
{
    u8 spriteId;
    u8 SpriteTag = SPRITE_ARR_ID_SELECTOR;
    struct CompressedSpriteSheet sSpriteSheet_Selector = {gBattleSelector_Gfx, 0x0801, SpriteTag};
    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

    TempSpriteTemplate.tileTag = SpriteTag;
    TempSpriteTemplate.callback = SpriteCB_Selector;

    LoadCompressedSpriteSheet(&sSpriteSheet_Selector);
    LoadSpritePalette(sBattleMenuSelectorSpritePalette);
    TempSpriteTemplate.paletteTag = PAL_UI_SPRITES;
    spriteId = CreateSprite(&TempSpriteTemplate, 4, 4, 0);
    sMenuDataPtr->spriteIds[SPRITE_ARR_ID_SELECTOR] = spriteId;

    gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_SELECTOR]].oam.shape = SPRITE_SHAPE(64x32);
    gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_SELECTOR]].oam.size = SPRITE_SIZE(64x32);
    gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_SELECTOR]].oam.priority = 0;
}

static void ShowItemIcon(u16 itemId, u8 x, u8 y)
{
    u8 itemSpriteId;
    u8 *spriteId = &sMenuDataPtr->spriteIds[SPRITE_ARR_HELD_ITEM];

    if (*spriteId == SPRITE_NONE && itemId != ITEM_NONE)
    {
        FreeSpriteTilesByTag(TAG_ITEM_ICON - 1);
        FreeSpritePaletteByTag(TAG_ITEM_ICON - 1);
        itemSpriteId = AddItemIconSprite(TAG_ITEM_ICON, TAG_ITEM_ICON, itemId);
        sMenuDataPtr->spriteIds[SPRITE_ARR_HELD_ITEM] = itemSpriteId;
        
        if (itemSpriteId != MAX_SPRITES)
        {
            *spriteId = itemSpriteId;
            gSprites[itemSpriteId].x2 = x;
            gSprites[itemSpriteId].y2 = y;
        }
    }
}

static void FreeItemIconSprite(void)
{
    u8 *spriteId = &sMenuDataPtr->spriteIds[SPRITE_ARR_HELD_ITEM];
    if (*spriteId != SPRITE_NONE)
    {
        FreeSpriteTilesByTag(TAG_ITEM_ICON);
        FreeSpritePaletteByTag(TAG_ITEM_ICON);
        FreeSpriteOamMatrix(&gSprites[*spriteId]);
        DestroySprite(&gSprites[*spriteId]);
        *spriteId = SPRITE_NONE;
        sMenuDataPtr->spriteIds[SPRITE_ARR_HELD_ITEM] = SPRITE_NONE;
    }
}
const u8 sText_Title_Nothing[]    = _("");

const u8 sText_Title_Battler_Stats[]     = _("Pokémon Stats");
const u8 sText_Title_Battler_Ability[]   = _("Abilities Info");
const u8 sText_Title_Battler_Moves[]     = _("Moves Info");
const u8 sText_Title_Battler_Status[]    = _("Pokémon Status");
const u8 sText_Title_Battler_Damage[]    = _("Damage Calculator");
const u8 sText_Title_Field_Party[]       = _("Party Info");
const u8 sText_Title_Field_Stats[]       = _("Field Info");
const u8 sText_Title_Enemy_Side[]        = _("Enemy Side Info");
const u8 sText_Title_Player_Side[]       = _("Player Side Info");
const u8 sText_Title_Speed_Order[]       = _("Speed Order");
const u8 sText_Title_FieldControllers[]  = _("{A_BUTTON}Scroll {DPAD_UPDOWN}Switch {DPAD_LEFTRIGHT}Page");
const u8 sText_Title_FieldControllers2[] = _("{A_BUTTON}Scroll {DPAD_UPDOWN}Switch");
const u8 sText_Title_Controllers[]       = _("{DPAD_UPDOWN}Switch {DPAD_LEFTRIGHT}Page");

const u8 sText_Title_Type_One[]     = _("Type:\n{STR_VAR_1}");
const u8 sText_Title_Type_Two[]     = _("Types:\n{STR_VAR_1}/ {STR_VAR_2}");
const u8 sText_Title_Type_Three[]   = _("Types:\n{STR_VAR_1}/ {STR_VAR_2}/ {STR_VAR_3}");

const u8 sText_Title_Nature[]        = _("Nature: {STR_VAR_1}\n({STR_VAR_2}+ {STR_VAR_3}-)");
const u8 sText_Title_Nature_NoStat[] = _("Nature:\n{STR_VAR_1}");

const u8 sText_Title_Held_Item[]    = _("Held Item: {STR_VAR_1}");
const u8 gText_NewLevelSymbol[] = _("{LV}{STR_VAR_1}");
#define SPACE_BETWEEN_TYPES (5 * 8)

static void PrintStatsTab(){
    u8 i, j;
    u8 x, y, x2, y2;
    u8 windowId = WINDOW_1;
    u8 colorIdx = FONT_BLACK;
    u16 species = gBattleMons[sMenuDataPtr->battlerId].species;
    u16 innate1 = gBaseStats[species].innates[0];
    u16 innate2 = gBaseStats[species].innates[1];
    u16 innate3 = gBaseStats[species].innates[2];
    u32 personality = gBattleMons[sMenuDataPtr->battlerId].personality;
    u8 gender = GetGenderFromSpeciesAndPersonality(gBattleMons[sMenuDataPtr->battlerId].species, gBattleMons[sMenuDataPtr->battlerId].personality);
    u8 statStage;
    bool8 statStageUp = FALSE;
    bool8 isEnemyMon = GetBattlerSide(sMenuDataPtr->battlerId) == B_SIDE_OPPONENT;
    u8 numtypes = 1;
    struct Pokemon *party, *targetParty;
    u8 nature;
    const s8 *natureMod;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    //Title
    x  = 9;
    y  = 0;
    x2 = 0;
    y2 = -4;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Battler_Stats);
    x  = 19;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Controllers);

    //Pokemon Name
    x  = 9;
    y  = 4;
    x2 = 0;
    y2 = -4;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gSpeciesNames[species]);
    //Pokemon Gender
    x = x + 8;
    switch(gender){
        case MON_MALE:
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLUE], 0xFF, gText_MaleSymbol);
            break;
        case MON_FEMALE:
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_RED], 0xFF, gText_FemaleSymbol);
            break;
    }
    //Pokemon Level
    x++;
    ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].level, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_NewLevelSymbol);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    //Pokemon Types
    y++;
    x = 9;
    StringCopy(gStringVar1, gTypeNames[gBattleMons[sMenuDataPtr->battlerId].type1]);
    //Check if there is a second type
    if(gBattleMons[sMenuDataPtr->battlerId].type1 != gBattleMons[sMenuDataPtr->battlerId].type2){
        numtypes++;
        StringCopy(gStringVar2, gTypeNames[gBattleMons[sMenuDataPtr->battlerId].type2]);
    }
    //Check if there is a third type
    if(gBattleMons[sMenuDataPtr->battlerId].type3 != TYPE_MYSTERY && 
       gBattleMons[sMenuDataPtr->battlerId].type3 != gBattleMons[sMenuDataPtr->battlerId].type1 &&
       gBattleMons[sMenuDataPtr->battlerId].type3 != gBattleMons[sMenuDataPtr->battlerId].type2){
        numtypes++;
        if(numtypes == 2)
            StringCopy(gStringVar2, gTypeNames[gBattleMons[sMenuDataPtr->battlerId].type3]);
        else
            StringCopy(gStringVar3, gTypeNames[gBattleMons[sMenuDataPtr->battlerId].type3]);
    }   

    switch(numtypes){
        case 1:
            StringExpandPlaceholders(gStringVar4, sText_Title_Type_One);
        break;
        case 2:
            StringExpandPlaceholders(gStringVar4, sText_Title_Type_Two);
        break;
        case 3:
            StringExpandPlaceholders(gStringVar4, sText_Title_Type_Three);
        break;
    }
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);

    //Held Item
    y = y +2;
    if(gBattleMons[sMenuDataPtr->battlerId].item != ITEM_NONE)
        CopyItemName(gBattleMons[sMenuDataPtr->battlerId].item, gStringVar1);
    else
        StringCopy(gStringVar1, sText_None);
    StringExpandPlaceholders(gStringVar4, sText_Title_Held_Item);
    //StringCopy(gStringVar1, ItemId_GetDescription(gBattleMons[sMenuDataPtr->battlerId].item));
    StringExpandPlaceholders(gStringVar4, sText_Title_Held_Item);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);

    //Item Icon
    x  = 26 + 1;
    x2 = 4;
    y  = 4  + 3;
    ShowItemIcon(gBattleMons[sMenuDataPtr->battlerId].item, (x * 8) + x2, (y * 8) + y2);
    x2 = 0;

    //Stat Drops & Ups
    x = 9;
    y = 9;
    //Attack
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Attack);
    y++;
    //Defense
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Defense);
    y++;
    //Special Attack
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_SpecialAttack);
    y++;
    //Special Defense
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_SpecialDefense);
    y++;
    //Speed
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Speed);
    y = y + 2;
    //Accuracy
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Accuracy);
    //Evasion
    y++;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Evasion);
    //Critical
    y++;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Critical);
    
    x = 11;
    y = 9;
    for(i = 0; i < NUM_BATTLE_STATS - 1; i++){
        
        statStage = gBattleMons[sMenuDataPtr->battlerId].statStages[statorder[i + 1]];//HP is not taken into account
        if(statStage != DEFAULT_STAT_STAGE){
            if(statStage > DEFAULT_STAT_STAGE){
                statStageUp = TRUE;
                statStage = statStage - DEFAULT_STAT_STAGE;
            }
            else{
                statStageUp = FALSE;
                statStage = DEFAULT_STAT_STAGE - statStage;
            }

            for(j = 0; j < statStage; j++){
                if(statStageUp)
                    BlitBitmapToWindow(windowId, sStatUpArrow, ((x + j) * 8) + x2, (y * 8), 8, 8);
                else
                    BlitBitmapToWindow(windowId, sStatDownArrow, ((x + j) * 8) + x2, (y * 8), 8, 8);

            }
        }
        if(statorder[i + 1] == STAT_SPEED)
            y = y + 2;
        else
            y++;
    }

    //Stat names
    x  = 20;
    y  = 9;
    //HP
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_StatHP);
    ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].hp, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, gBattleMons[sMenuDataPtr->battlerId].maxHP, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, sText_HP);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    y++;
    //Attack
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Attack);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].attack, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    y++;
    //Defense
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Defense);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].defense, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    y++;
    //Special Attack
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_SpecialAttack);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].spAttack, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    y++;
    //Special Defense
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_SpecialDefense);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].spDefense, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    y++;
    //Speed
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Speed);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].speed, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);

    //Nature
    x = 20;
    y = 16;
    if (GetBattlerSide(sMenuDataPtr->battlerId) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;
    
    nature = GetMonData(&party[gBattlerPartyIndexes[sMenuDataPtr->battlerId]], MON_DATA_NATURE, NULL);

    CopyNatureName(nature);
    if(nature == NATURE_HARDY || nature == NATURE_DOCILE || nature == NATURE_SERIOUS || nature == NATURE_BASHFUL || nature == NATURE_QUIRKY){
        //No Stat Up or Down
        StringExpandPlaceholders(gStringVar4, sText_Title_Nature_NoStat);
    }
    else{
        natureMod = gNatureStatTable[nature];
        for(i = 0; i < NUM_NATURE_STATS; i++){
            if (natureMod[i] > 0){
                //Nature Up
                switch(i + 1){
                    case STAT_ATK:
                        StringCopy(gStringVar2, sText_Attack);
                    break;
                    case STAT_DEF:
                        StringCopy(gStringVar2, sText_Defense);
                    break;
                    case STAT_SPATK:
                        StringCopy(gStringVar2, sText_SpecialAttack);
                    break;
                    case STAT_SPDEF:
                        StringCopy(gStringVar2, sText_SpecialDefense);
                    break;
                    case STAT_SPEED:
                        StringCopy(gStringVar2, sText_Speed);
                    break;
                }
            }
            else if (natureMod[i] < 0){
                //Nature Down
                switch(i + 1){
                    case STAT_ATK:
                        StringCopy(gStringVar3, sText_Attack);
                    break;
                    case STAT_DEF:
                        StringCopy(gStringVar3, sText_Defense);
                    break;
                    case STAT_SPATK:
                        StringCopy(gStringVar3, sText_SpecialAttack);
                    break;
                    case STAT_SPDEF:
                        StringCopy(gStringVar3, sText_SpecialDefense);
                    break;
                    case STAT_SPEED:
                        StringCopy(gStringVar3, sText_Speed);
                    break;
                }
            }
        }
        StringExpandPlaceholders(gStringVar4, sText_Title_Nature);
    }
    
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}


const u8 sText_PrintAbilityTab_Ability[] = _("Ability");
const u8 sText_PrintAbilityTab_Innate[] = _("Innate");
#define SPACE_BETWEEN_ABILITY_AND_NAME (8 * 8)
#define SPACE_BETWEEN_ABILITIES 3
static void PrintAbilityTab(){
    u8 i, j;
    u8 x, y, x2, y2;
    u8 windowId = WINDOW_1;
    u8 colorIdx = FONT_BLACK;
    u16 species = gBattleMons[sMenuDataPtr->battlerId].species;
    u16 innate1 = gBaseStats[species].innates[0];
    u16 innate2 = gBaseStats[species].innates[1];
    u16 innate3 = gBaseStats[species].innates[2];
    u16 ability = gBattleMons[sMenuDataPtr->battlerId].ability;
    u32 personality = gBattleMons[sMenuDataPtr->battlerId].personality;
    u8 gender = GetGenderFromSpeciesAndPersonality(gBattleMons[sMenuDataPtr->battlerId].species, gBattleMons[sMenuDataPtr->battlerId].personality);
    u8 statStage;
    bool8 statStageUp = FALSE;
    bool8 isEnemyMon = GetBattlerSide(sMenuDataPtr->battlerId) == B_SIDE_OPPONENT;

    if(!isEnemyMon){ //Enemy Mons have disabled randomized innates/abilies 
        innate1 = RandomizeInnate(gBaseStats[species].innates[0], species, personality);
        innate2 = RandomizeInnate(gBaseStats[species].innates[1], species, personality);
        innate3 = RandomizeInnate(gBaseStats[species].innates[2], species, personality);
    }

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    //Title
    x  = 9;
    y  = 0;
    x2 = 0;
    y2 = 0;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Battler_Ability);
    x  = 19;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Controllers);

    // Main Ability
    x  = 9;
    y  = 3;
    x2 = 0;
    y2 = -4;
    //Title
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_PrintAbilityTab_Ability);
	// Name ---------------------------------------------------------------------------------------------------
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gAbilityNames[ability]);
	// Description ---------------------------------------------------------------------------------------------------
    y++;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2 + 4, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gAbilityDescriptionPointers[ability]);

    // Innate 1
    y = y + SPACE_BETWEEN_ABILITIES;
    //Title
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_PrintAbilityTab_Innate);
    // Name ---------------------------------------------------------------------------------------------------
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gAbilityNames[innate1]);
    // Description ---------------------------------------------------------------------------------------------------
    y++;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2 + 4, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gAbilityDescriptionPointers[innate1]);
    
    // Innate 2
    y = y + SPACE_BETWEEN_ABILITIES;
    //Title
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_PrintAbilityTab_Innate);
    // Name ---------------------------------------------------------------------------------------------------
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gAbilityNames[innate2]);
    // Description ---------------------------------------------------------------------------------------------------
    y++;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2 + 4, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gAbilityDescriptionPointers[innate2]);
       
    // Innate 3
    y = y + SPACE_BETWEEN_ABILITIES;
    //Title
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_PrintAbilityTab_Innate);
    // Name ---------------------------------------------------------------------------------------------------
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gAbilityNames[innate3]);
    // Description ---------------------------------------------------------------------------------------------------
    y++;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2 + 4, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gAbilityDescriptionPointers[innate3]);

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}


const u8 gText_CurrentPP[]         = _("PP: {STR_VAR_1}/{STR_VAR_2}");
const u8 gText_MoveInfo_Power[]    = _("Power: {STR_VAR_1}");
const u8 gText_MoveInfo_Accuracy[] = _("Accuracy: {STR_VAR_1}");
const u8 gText_MoveInfo_Priority[] = _("Priority: {STR_VAR_1}");
const u8 gText_MoveInfo_Split[]    = _("Split: {STR_VAR_1}");
const u8 gText_MoveInfo_STAB[]     = _("STAB: {STR_VAR_1}");

const u8 gText_Split_Physical[] = _("Physical");
const u8 gText_Split_Special[]  = _("Special");
const u8 gText_Split_Status[]   = _("Status");

const u8 gText_MoveInfo_Target1[] = _("Target 1: {STR_VAR_1}");
const u8 gText_MoveInfo_Target2[] = _("Target 2: {STR_VAR_1}");

const u8 gText_MoveInfo_Damage[] = _("Damage");

const u8 gText_Target_Nothing[]   = _("---");
const u8 sText_Title_Controllers_Move[]      = _("{DPAD_UPDOWN}Switch {DPAD_LEFTRIGHT}Page {A_BUTTON}Mode");
#define SPACE_BETWEEN_MOVES 4
#define SPACE_BETWEEN_DAMAGE (4 * 8)
#define MIN_MOVE_DAMAGE 4
#define ENABLE_DAMAGE_CALCULATION FALSE
static void PrintMoveTab(void){
    u8 i, j;
    u8 x, y, x2, y2;
    u8 windowId = WINDOW_1;
    u8 colorIdx = FONT_BLACK;
    u16 species = gBattleMons[sMenuDataPtr->battlerId].species;
    u16 move1   = gBattleMons[sMenuDataPtr->battlerId].moves[0];
    u16 move2   = gBattleMons[sMenuDataPtr->battlerId].moves[1];
    u16 move3   = gBattleMons[sMenuDataPtr->battlerId].moves[2];
    u16 move4   = gBattleMons[sMenuDataPtr->battlerId].moves[3];
    u16 ability = gBattleMons[sMenuDataPtr->battlerId].ability;
    u16 gBattleMoveDamage;
    u8 target = 1;
    u32 personality = gBattleMons[sMenuDataPtr->battlerId].personality;
    u8 gender = GetGenderFromSpeciesAndPersonality(gBattleMons[sMenuDataPtr->battlerId].species, gBattleMons[sMenuDataPtr->battlerId].personality);
    u8 statStage;
    bool8 statStageUp = FALSE;
    bool8 isEnemyMon = GetBattlerSide(sMenuDataPtr->battlerId) == B_SIDE_OPPONENT;
    u8 mode = sMenuDataPtr->moveModeId;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    
    //Title
    x  = 9;
    y  = 0;
    x2 = 0;
    y2 = 0;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Battler_Moves);
    x  = 16;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Controllers_Move);

    // First Move
    x  = 9;
    y  = 3;
	PrintMoveInfo(move1, x, y, 0);

    // Second Move
    y = y + SPACE_BETWEEN_MOVES;
	PrintMoveInfo(move2, x, y, 1);

    // Third Move
    y = y + SPACE_BETWEEN_MOVES;
	PrintMoveInfo(move3, x, y, 2);

    // Fourth Move
    y = y + SPACE_BETWEEN_MOVES;
	PrintMoveInfo(move4, x, y, 3);

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

const u8 gText_Makes_Contact_True[]        = _("Makes contact");
const u8 gText_Makes_Contact_False[]       = _("Does not make contact");
const u8 gText_Protect_Affected_True[]     = _("Affected by Protect");
const u8 gText_Protect_Affected_False[]    = _("Not affected by Protect");
const u8 gText_Magic_Coat_Affected_True[]  = _("Affected by Magic Coat");
const u8 gText_Magic_Coat_Affected_False[] = _("Not affected by Magic Coat");
const u8 gText_Snatch_Affected_True[]      = _("Affected by Snatch");
const u8 gText_Snatch_Affected_False[]     = _("Not affected by Snatch");
const u8 gText_Mirror_Move_Affected_True[] = _("Affected by Mirror Move");
const u8 gText_Mirror_Move_Affected_False[]= _("Not affected by Mirror Move");
const u8 gText_Kings_Rock_Affected_True[]  = _("Affected by King's Rock");
const u8 gText_Kings_Rock_Affected_False[] = _("Not affected by King's Rock");

const u8 gText_Boost_True[]          = _("True");
const u8 gText_Boost_False[]         = _("False");

const u8 gText_Move_Type_TwoTypedMoves[] = _("{STR_VAR_1}/{STR_VAR_2}");

static void MulModifier(u16 *modifier, u16 val)
{
	*modifier = UQ_4_12_TO_INT((*modifier * val) + UQ_4_12_ROUND);
}

static void PrintMoveInfo(u16 move, u8 x, u8 y, u8 moveIdx){
    u8 i, j;
    u8 windowId = WINDOW_1;
    u8 colorIdx = FONT_BLACK;
    u16 species = gBattleMons[sMenuDataPtr->battlerId].species;
    u16 ability = gBattleMons[sMenuDataPtr->battlerId].ability;
    u16 gBattleMoveDamage;
    bool8 isEnemyMon = GetBattlerSide(sMenuDataPtr->battlerId) == B_SIDE_OPPONENT;
    u8 mode = sMenuDataPtr->moveModeId;
    u8 x2 = 0;
    u8 y2 = -4;
    u8 target = BATTLE_OPPOSITE(sMenuDataPtr->battlerId);
    u32 movePower = gBattleMoves[move].power;
    u32 moveAccuracy = GetTotalAccuracy(sMenuDataPtr->battlerId, target, move);
    u8 moveType  = gBattleMoves[move].type;
    u8 moveType2 = TYPE_MYSTERY;
    bool32 updateFlags = FALSE;
    bool8 isStatusMove = gBattleMoves[move].split == SPLIT_STATUS;
    bool8 isStab = FALSE;
    struct Pokemon *party;

    //Party
    if (!isEnemyMon)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    //Sets move type depending on the mon ability/stats
    SetTypeBeforeUsingMove(move, sMenuDataPtr->battlerId);
    GET_MOVE_TYPE(move, moveType);

    //Sets move power depending on the mon ability/stats
    movePower = CalcMoveBasePowerAfterModifiers(move, 0, sMenuDataPtr->battlerId, target, moveType, FALSE);

    moveType2 = gBattleMoves[move].type2;
    if (moveType2)
    {
        u32 movePower2 = CalcMoveBasePowerAfterModifiers(move, 0, sMenuDataPtr->battlerId, target, moveType2, FALSE);
        if (movePower2 > movePower)
        {
            moveType = moveType2;
            movePower = movePower2;
        }
    }

    //Check Stab
    if(IS_BATTLER_OF_TYPE(sMenuDataPtr->battlerId, moveType) && !isStatusMove)
        isStab = TRUE;
    
    //Move Name
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gMoveNamesLong[move]);
    //Type
    if(gBattleMoves[move].type2 == TYPE_MYSTERY || gBattleMoves[move].type2 == TYPE_NORMAL)
        StringCopy(gStringVar4, gTypeNames[moveType]);
    else{
        StringCopy(gStringVar1, gTypeNames[moveType]);
        StringCopy(gStringVar2, gTypeNames[gBattleMoves[move].type2]);
        StringExpandPlaceholders(gStringVar4, gText_Move_Type_TwoTypedMoves);
    }
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 1) * 8) + SPACE_BETWEEN_ABILITY_AND_NAME + 16, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);
    y++;

    //Stab Boost
    if(isStab)
        movePower = movePower * 1.5;
    
    switch(mode){
        case MOVE_MODE_NORMAL:
            // Move Power ---------------------------------------------------------------------------------------------------
            if(!isStatusMove)
                ConvertIntToDecimalStringN(gStringVar1, movePower, STR_CONV_MODE_LEFT_ALIGN, 3);
            else
                StringCopy(gStringVar1, gText_Target_Nothing);
            StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Power);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
            // Move Accuracy
            if(moveAccuracy != 0)
                ConvertIntToDecimalStringN(gStringVar1, moveAccuracy, STR_CONV_MODE_LEFT_ALIGN, 3);
            else
                StringCopy(gStringVar1, gText_Target_Nothing);
            StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Accuracy);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
            y++;
            // Move Priority ---------------------------------------------------------------------------------------------------
            if(gBattleMoves[move].priority >= 0)
                ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move].priority, STR_CONV_MODE_LEFT_ALIGN, 3);
            else
                ConvertIntToDecimalStringN(gStringVar1, 0, STR_CONV_MODE_LEFT_ALIGN, 3);
            StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Priority);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
            // Move Split
            switch(gBattleMoves[move].split){
                case SPLIT_PHYSICAL:
                    StringCopy(gStringVar1, gText_Split_Physical);
                break;
                case SPLIT_SPECIAL:
                    StringCopy(gStringVar1, gText_Split_Special);
                break;
                case SPLIT_STATUS:
                default:
                    StringCopy(gStringVar1, gText_Split_Status);
                break;
            }
            StringExpandPlaceholders(gStringVar4, gText_MoveInfo_Split);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
            y++;
            //PP
            ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].pp[moveIdx],  STR_CONV_MODE_LEFT_ALIGN, 2); //Current PP
            ConvertIntToDecimalStringN(gStringVar2, CalculatePPWithBonus(move, GetMonData(&party[gBattlerPartyIndexes[sMenuDataPtr->battlerId]], MON_DATA_PP_BONUSES, NULL), moveIdx), STR_CONV_MODE_LEFT_ALIGN, 2); //Max PP
            StringExpandPlaceholders(gStringVar4, gText_CurrentPP);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
            //Stab
            if(!isStatusMove){ //No stab boost for status moves
                if(isStab)
                    StringCopy(gStringVar1, gText_Boost_True);
                else
                    StringCopy(gStringVar1, gText_Boost_False);
                StringExpandPlaceholders(gStringVar4, gText_MoveInfo_STAB);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + SPACE_BETWEEN_ABILITY_AND_NAME, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
            }
        break;
        case MOVE_MODE_DESCRIPTION:
            y2 = y2 + 4;
            StringCopy(gStringVar4, gMoveDescriptionPointers[move - 1]);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        break;
        /*case MOVE_MODE_DAMAGE_CALCULATOR:
            if(gBattleMoves[move].split == SPLIT_STATUS || movePower == 0){
                StringCopy(gStringVar4, gText_Target_Nothing);
            }
            else{
                PrintDamageCalculation(sMenuDataPtr->battlerId, target, move);
            }
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        break;*/
        case MOVE_MODE_AFFECTED_1:
            //Makes Contact
            if(gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
                StringCopy(gStringVar4, gText_Makes_Contact_True);
            else
                StringCopy(gStringVar4, gText_Makes_Contact_False);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
            
            //Protect Affected 
            y++;
            if(gBattleMoves[move].flags & FLAG_PROTECT_AFFECTED)
                StringCopy(gStringVar4, gText_Protect_Affected_True);
            else
                StringCopy(gStringVar4, gText_Protect_Affected_False);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
            //Magic Coat Affected
            y++;
            if(gBattleMoves[move].flags & FLAG_MAGIC_COAT_AFFECTED)
                StringCopy(gStringVar4, gText_Magic_Coat_Affected_True);
            else
                StringCopy(gStringVar4, gText_Magic_Coat_Affected_False);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        break;
        case MOVE_MODE_AFFECTED_2:
            //Snatch Affected
            if(gBattleMoves[move].flags & FLAG_SNATCH_AFFECTED)
                StringCopy(gStringVar4, gText_Snatch_Affected_True);
            else
                StringCopy(gStringVar4, gText_Snatch_Affected_False);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
            
            //Mirror Move Affected
            y++;
            if(gBattleMoves[move].flags & FLAG_PROTECT_AFFECTED)
                StringCopy(gStringVar4, gText_Mirror_Move_Affected_True);
            else
                StringCopy(gStringVar4, gText_Mirror_Move_Affected_False);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
            //King's Rock Affected
            y++;
            if(gBattleMoves[move].flags & FLAG_MAGIC_COAT_AFFECTED)
                StringCopy(gStringVar4, gText_Kings_Rock_Affected_True);
            else
                StringCopy(gStringVar4, gText_Kings_Rock_Affected_False);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        break;
    }
}

//Misc
const u8 sText_Title_Field_Turns_Left[]                   = _("Turns Left:");
const u8 sText_Title_Field_Turns[]                        = _("Turns:");
const u8 sText_Title_Field_Layers[]                       = _("Layers:");
const u8 sText_Title_Field_Nature_Power[]                 = _("Nature Power:");
const u8 sText_Title_Field_Secret_Power[]                 = _("Secret Power:");
const u8 sText_Title_Field_Paralysis[]                    = _("Causes Paralysis");
const u8 sText_Title_Field_Active[]                       = _("Active");
const u8 sText_Title_Field_Not_Active[]                   = _("Not Active");
const u8 sText_Title_Field_None[]                         = _("None");
//Primary Status
const u8 sText_Title_Status_Paralysis[]                    = _("Paralyzed");
const u8 sText_Title_Status_Paralysis_Description[]        = _("Reduces the speed of this Pokémon\n"
                                                               "by 50% and has a 25% risk of losing\n"
                                                               "their turn due to full paralysis.");
const u8 sText_Title_Status_Burn[]                         = _("Burned");
const u8 sText_Title_Status_Burn_Description[]             = _("Reduces the Physical Attack of this\n"
                                                               "Pokémon by 50% and will take 1/16 of\n"
                                                               "its max HP at the end of each turn.");
const u8 sText_Title_Status_Sleep[]                        = _("Asleep");
const u8 sText_Title_Status_Sleep_Description[]            = _("Prevents this Pokémon from making\n"
                                                               "a move, it is vulnerable to Dream\n"
                                                               "Eater, Nightmare, and Bad Dreams.");
const u8 sText_Title_Status_Frostbite[]                    = _("Frostbiten");
const u8 sText_Title_Status_Frostbite_Description[]        = _("Reduces the Special Attack of this\n"
                                                               "Pokémon by 50% and will take 1/16 of\n"
                                                               "its max HP at the end of each turn.");
const u8 sText_Title_Status_Freeze[]                       = _("Frozen");
const u8 sText_Title_Status_Freeze_Description[]           = _("Causes this pokemon to be unable to\n"
                                                               "move for some turns, can be thwated\n"
                                                               "if hit by some Fire-type moves.");
const u8 sText_Title_Status_Poison[]                       = _("Poisoned");
const u8 sText_Title_Status_Poison_Description[]           = _("Takes 1/8 of its max HP every turn,\n"
                                                               "takes double damage from Hex and\n"
                                                               "Venoshock.");
const u8 sText_Title_Status_Bad_Poison[]                   = _("Badly Poisoned");
const u8 sText_Title_Status_Bad_Poison_Description[]       = _("Takes 1/16 of its max HP on the first,\n"
                                                               "turn, after which damage increases by\n"
                                                               "1/16 each time it takes poison damage.");
const u8 sText_Title_Status_Bleed[]                        = _("Bleeding");
const u8 sText_Title_Status_Bleed_Description[]            = _("Prevents this pokemon from healing\n"
                                                               "and will take 6% of its HP as damage.\n"
                                                               "Cured by healing moves.");

//Secondary Status
const u8 sText_Title_Status_Confusion[]                    = _("Confused");
const u8 sText_Title_Status_Confusion_Description[]        = _("Has a 33% chance to damage itself,\n"
                                                               "damage is calculated as if it were a\n"
                                                               "physical typeless move with a 40 BP.");
const u8 sText_Title_Status_IncomingAttack[]               = _("Incoming Attack");
const u8 sText_Title_Status_IncomingAttack_Description[]   = _("Will be hit by {STR_VAR_1}'s\n"
                                                               "{STR_VAR_2} with a power of {STR_VAR_3}\n"
                                                               "in some turns.");
const u8 sText_Title_Status_Uproar[]                       = _("Causing an Uproar");
const u8 sText_Title_Status_Uproar_Description[]           = _("Will use Uproar for some turns,\n"
                                                               "nobody can fall asleep while this\n"
                                                               "is happening with some exceptions.");
const u8 sText_Title_Status_Bide[]                         = _("Bide");
const u8 sText_Title_Status_Bide_Description[]             = _("Will be unable to attack,\n"
                                                               "will do double the damage equal to\n"
                                                               "twice the damage it receives.");
const u8 sText_Title_Status_Infuation[]                    = _("Infuated with {STR_VAR_1}");
const u8 sText_Title_Status_Infuation_Description[]        = _("Reduces the dmg done to the target\n"
                                                               "of it's infuation, it will end\n"
                                                               "when any of the two gets switched.");
const u8 sText_Title_Status_Focus_Energy[]                 = _("Focus Energy");
const u8 sText_Title_Status_Focus_Energy_Description[]     = _("Increases the user critical hit rate\n"
                                                               "by two stages, this effect can be\n"
                                                               "transferred by Baton Pass.");
const u8 sText_Title_Status_Transformed[]                  = _("Transformed into {STR_VAR_1}");
const u8 sText_Title_Status_Transformed_Description[]      = _("Became an exact copy of a targeted\n"
                                                               "Pokémon, has less PP and some\n"
                                                               "specific abilities may not work.");
const u8 sText_Title_Status_Escape_Prevention[]             = _("Can't Escape");
const u8 sText_Title_Status_Escape_Prevention_Description[] = _("This Pokémon can't escape or switch,\n"
                                                                "it can be only removed from battle\n"
                                                                "if the battle ends or it faints.");
const u8 sText_Title_Status_Cursed[]                       = _("Cursed");
const u8 sText_Title_Status_Cursed_Description[]           = _("Loses 1/4 of it's maximum HP at the\n"
                                                               "end of each turn, the curse will\n"
                                                               "remain until the Pokémon leaves.");
const u8 sText_Title_Status_Foresight[]                    = _("Foresighted");
const u8 sText_Title_Status_Foresight_Description[]        = _("Enables to be hit by Normal or\n"
                                                               "Fighting-type moves if it's a\n"
                                                               "Ghost-type, ignores evasiveness.");
const u8 sText_Title_Status_Defense_Curl[]                 = _("Defense Curl");
const u8 sText_Title_Status_Defense_Curl_Description[]     = _("Doubles the power of the user's\n"
                                                               "Rollout and Ice Ball as long as\n"
                                                               "the user remains in battle.");
const u8 sText_Title_Status_Torment[]                      = _("Tormented");
const u8 sText_Title_Status_Torment_Description[]          = _("Is prevented from using the same\n"
                                                               "move twice in a row, the effect\n"
                                                               "lasts until the Pokémon leaves.");
const u8 sText_Title_Status_Leech_Seed_Target[]             = _("Seeded by {STR_VAR_1}");
const u8 sText_Title_Status_Leech_Seed_Target_Description[] = _("Some of it's HP get's stolen\n"
                                                                "every turn, the effect lasts\n"
                                                                "until the Pokémon leaves.");
const u8 sText_Title_Status_Leech_Seed_User[]              = _("Seeded {STR_VAR_1}");
const u8 sText_Title_Status_Leech_Seed_User_Description[]  = _("Receives some HP from a target\n"
                                                               "every turn, the effect lasts\n"
                                                               "until the Pokémon leaves.");
const u8 sText_Title_Status_Perish_Song[]                  = _("Perishing");
const u8 sText_Title_Status_Perish_Song_Description[]      = _("The perish count decreases by 1\n"
                                                               "at the end of each turn, when\n"
                                                               "it reaches 0, it will faint.");
const u8 sText_Title_Status_Minimize[]                     = _("Minimized");
const u8 sText_Title_Status_Minimize_Description[]         = _("Specific moves will have their\n"
                                                               "damage doubled and will bypass\n"
                                                               "accuracy and evassion checks.");
const u8 sText_Title_Status_Charge[]                       = _("Charged Up");
const u8 sText_Title_Status_Charge_Description[]           = _("The user's next Electric-type\n"
                                                               "move will deal twice the usual\n"
                                                               "amount of damage.");
const u8 sText_Title_Status_Rooted[]                       = _("Rooted");
const u8 sText_Title_Status_Rooted_Description[]           = _("It will restore 1/16 of it's max\n"
                                                               "HP at the end of every turn, it is\n"
                                                               "unable to escape or switch out.");
const u8 sText_Title_Status_Yawn[]                         = _("Drowsy");
const u8 sText_Title_Status_Yawn_Description[]             = _("This Pokémon will fall asleep at\n"
                                                               "the end of the next turn if there\n"
                                                               "isn't anything preventing it.");
const u8 sText_Title_Status_Grudge[]                       = _("Grudge");
const u8 sText_Title_Status_Grudge_Description[]           = _("If the user faints as the direct\n"
                                                               "result of an attack, the move\n"
                                                               "that caused it lose all its PP.");
const u8 sText_Title_Status_Cant_Crit[]                    = _("Can't land a Critical Hit");
const u8 sText_Title_Status_Cant_Crit_Description[]        = _("This Pokémon will be unable to\n"
                                                               "land any critical hit, it will\n"
                                                               "last until the Pokémon leaves.");
const u8 sText_Title_Status_Gastro_Acid[]                  = _("Ability Suppressed");
const u8 sText_Title_Status_Gastro_Acid_Description[]      = _("The Ability and Innates for\n"
                                                               "this Pokémon are Disabled, it\n"
                                                               "lasts until the Pokémon leaves.");
const u8 sText_Title_Status_Embargo[]                      = _("Held Effect Negated");
const u8 sText_Title_Status_Embargo_Description[]          = _("This Pokémon will be unable to\n"
                                                               "use it's held item for some\n"
                                                               "turns.");
const u8 sText_Title_Status_Smack_Down[]                   = _("Grounded");
const u8 sText_Title_Status_Smack_Down_Description[]       = _("Ground moves will hit this\n"
                                                               "Pokémon regardless of type,\n"
                                                               "ability, status or item.");
const u8 sText_Title_Status_Miracle_Eye[]                  = _("Miracle Eyed");
const u8 sText_Title_Status_Miracle_Eye_Description[]      = _("It will be hit ignoring evasion\n"
                                                               "changes, If it has the Dark-type\n"
                                                               "it can be hit by Psychic moves.");
const u8 sText_Title_Status_Heal_Block[]                   = _("Can't be Healed");
const u8 sText_Title_Status_Heal_Block_Description[]       = _("This Pokémon will be unable to\n"
                                                               "be healed by any means, it will\n"
                                                               "last some turns.");
const u8 sText_Title_Status_Aqua_Ring[]                    = _("Aqua Ring");
const u8 sText_Title_Status_Aqua_Ring_Description[]        = _("This Pokémon will be healed\n"
                                                               "by 1/16 of its maximum HP\n"
                                                               "at the end of every turn.");
const u8 sText_Title_Status_Magnet_Rise[]                  = _("Magnet Rise");
const u8 sText_Title_Status_Magnet_Rise_Description[]      = _("This Pokémon can't be hit by\n"
                                                               "Ground-type moves, it will\n"
                                                               "last some turns.");
const u8 sText_Title_Status_Semi_Invulnerable[]             = _("Semi Invlunerable");
const u8 sText_Title_Status_Semi_Invulnerable_Description[] = _("This Pokémon will avoid the\n"
                                                                "majory of attacks for one turn,\n"
                                                                "it can be hit by specific moves.");
const u8 sText_Title_Status_Electrified[]                   = _("Electrified");
const u8 sText_Title_Status_Electrified_Description[]       = _("This Pokémon moves will become\n"
                                                                "Electric-type for this turn.");
const u8 sText_Title_Status_Plasma_Fist[]                   = _("Plasma Fisted");
const u8 sText_Title_Status_Plasma_Fist_Description[]       = _("This Pokémon Normal-type moves\n"
                                                                "will become Electric-type for\n"
                                                                "this turn.");
const u8 sText_Title_Status_Coiled_Up[]                     = _("Coiled Up");
const u8 sText_Title_Status_Coiled_Up_Description[]         = _("The next biting move used by\n"
                                                                "this Pokémon will have an\n"
                                                                "increased priority.");
const u8 sText_Title_Status_Quark_Drive[]                   = _("Quark Drive");
const u8 sText_Title_Status_Protosynthesis[]                = _("Protosynthesis");
const u8 sText_Title_Status_Paradox_Boost_Description[]     = _("This Pokémon's highest stat\n"
                                                                "is boosted by 30%. If speed\n"
                                                                "+50% instead.");

#define SPACE_BETWEEN_LINES_FIELD ((6 * 8) + 4)
#define MAX_DESCRIPTION_LINES 3
#define LINES_BETWEEN_STUFF 1

#define SHOW_SLEEPING_TURNS FALSE

static void PrintStatusTab(void){
    u8 i, j;
    u8 x, y, x2, y2;
    u8 windowId = WINDOW_1;
    u8 colorIdx = FONT_BLACK;
    u16 species = gBattleMons[sMenuDataPtr->battlerId].species;
    u16 move1   = gBattleMons[sMenuDataPtr->battlerId].moves[0];
    u16 move2   = gBattleMons[sMenuDataPtr->battlerId].moves[1];
    u16 move3   = gBattleMons[sMenuDataPtr->battlerId].moves[2];
    u16 move4   = gBattleMons[sMenuDataPtr->battlerId].moves[3];
    u16 ability = gBattleMons[sMenuDataPtr->battlerId].ability;
    u16 gBattleMoveDamage;
    u8 target = 1;
    u32 personality = gBattleMons[sMenuDataPtr->battlerId].personality;
    u8 gender = GetGenderFromSpeciesAndPersonality(gBattleMons[sMenuDataPtr->battlerId].species, gBattleMons[sMenuDataPtr->battlerId].personality);
    u8 statStage;
    bool8 statStageUp = FALSE;
    bool8 isEnemyMon = GetBattlerSide(sMenuDataPtr->battlerId) == B_SIDE_OPPONENT;
    u8 maxLines = 3;
    bool8 printedInfo = FALSE;
    u8 turnsLeft = 0;
    u8 currentStatus = 0;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    //Title
    x  = 9;
    y  = 0;
    x2 = 0;
    y2 = 0;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Battler_Status);
    x  = 19;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Controllers);

    // Weather
    x  = 9;
    y  = 3;
    x2 = 0;
    y2 = -4;

    if(sMenuDataPtr->numStatusInfo[sMenuDataPtr->battlerId] < maxLines)
        maxLines = sMenuDataPtr->numStatusInfo[sMenuDataPtr->battlerId];

    for(i = 0; i < maxLines; i++){
        printedInfo = FALSE;
        currentStatus = (i + sMenuDataPtr->CurrentStatusInfo[sMenuDataPtr->battlerId]) % sMenuDataPtr->numStatusInfo[sMenuDataPtr->battlerId];
        j = sMenuDataPtr->BattlerStatus[currentStatus][sMenuDataPtr->battlerId];

        switch(j){
            case STATUS_INFO_PRIMARY:
                printedInfo = TRUE;
                if(gBattleMons[sMenuDataPtr->battlerId].status1 & STATUS1_SLEEP){
                    //Sleep
                    StringCopy(gStringVar1, sText_Title_Status_Sleep);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                    //Turns Left
                    if(SHOW_SLEEPING_TURNS){
                        StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                        turnsLeft = gBattleMons[sMenuDataPtr->battlerId].status1;
                        ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                    }
                    //Description
                    StringCopy(gStringVar1, sText_Title_Status_Sleep_Description);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                }
                else if(gBattleMons[sMenuDataPtr->battlerId].status1 & STATUS1_POISON){
                    //Poison
                    StringCopy(gStringVar1, sText_Title_Status_Poison);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                    
                    //Description
                    StringCopy(gStringVar1, sText_Title_Status_Poison_Description);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                }
                else if(gBattleMons[sMenuDataPtr->battlerId].status1 & STATUS1_BURN){
                    //Burn
                    StringCopy(gStringVar1, sText_Title_Status_Burn);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                    
                    //Description
                    StringCopy(gStringVar1, sText_Title_Status_Burn_Description);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                }
                else if(gBattleMons[sMenuDataPtr->battlerId].status1 & STATUS1_FREEZE){
                    //Freeze - Unused rn
                    StringCopy(gStringVar1, sText_Title_Status_Freeze);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                    //Description
                    StringCopy(gStringVar1, sText_Title_Status_Freeze_Description);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                }
                else if(gBattleMons[sMenuDataPtr->battlerId].status1 & STATUS1_PARALYSIS){
                    //Paralysis
                    StringCopy(gStringVar1, sText_Title_Status_Paralysis);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                    //Description
                    StringCopy(gStringVar1, sText_Title_Status_Paralysis_Description);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                }
                else if(gBattleMons[sMenuDataPtr->battlerId].status1 & STATUS1_TOXIC_POISON){
                    //Toxic Poison
                    StringCopy(gStringVar1, sText_Title_Status_Bad_Poison);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                    //Turns
                    StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                    turnsLeft = gBattleMons[sMenuDataPtr->battlerId].status1 - STATUS1_TOXIC_COUNTER;
                    ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                    //Description
                    StringCopy(gStringVar1, sText_Title_Status_Bad_Poison_Description);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                    //STATUS1_TOXIC_COUNTER
                }
                else if(gBattleMons[sMenuDataPtr->battlerId].status1 & STATUS1_FROSTBITE){
                    //Paralysis
                    StringCopy(gStringVar1, sText_Title_Status_Frostbite);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                    //Description
                    StringCopy(gStringVar1, sText_Title_Status_Frostbite_Description);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                }
                else if(gBattleMons[sMenuDataPtr->battlerId].status1 & STATUS1_BLEED){
                    //Bleed
                    StringCopy(gStringVar1, sText_Title_Status_Bleed);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                    //Description
                    StringCopy(gStringVar1, sText_Title_Status_Bleed_Description);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                }
                else{
                    printedInfo = FALSE;
                }
            break;
            case STATUS_INFO_CONFUSION:
                StringCopy(gStringVar1, sText_Title_Status_Confusion);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                /*StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gBattleMons[sMenuDataPtr->battlerId].status2 - STATUS2_CONFUSION;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);*/
                
                //Description
                StringCopy(gStringVar1, sText_Title_Status_Confusion_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_FUTURE_SIGHT:
                StringCopy(gStringVar1, sText_Title_Status_IncomingAttack);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gWishFutureKnock.futureSightCounter[sMenuDataPtr->battlerId];
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, gSpeciesNames[gBattleMons[gWishFutureKnock.futureSightAttacker[sMenuDataPtr->battlerId]].species]);
                StringCopy(gStringVar2, gMoveNames[gWishFutureKnock.futureSightMove[sMenuDataPtr->battlerId]]);
                ConvertIntToDecimalStringN(gStringVar3, gWishFutureKnock.futureSightPower[sMenuDataPtr->battlerId], STR_CONV_MODE_LEFT_ALIGN, 4);
                StringExpandPlaceholders(gStringVar4, sText_Title_Status_IncomingAttack_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar4);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_UPROAR:
                StringCopy(gStringVar1, sText_Title_Status_Uproar);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                /*//Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gBattleMons[sMenuDataPtr->battlerId].status2 - STATUS2_UPROAR;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);*/
                
                //Description
                StringCopy(gStringVar1, sText_Title_Status_Uproar_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_BIDE:
                StringCopy(gStringVar1, sText_Title_Status_Bide);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gBattleMons[sMenuDataPtr->battlerId].status2 - STATUS2_BIDE;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Status_Bide_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_INFUATION:{
                u8 infuatedWith = 0;
                u16 species = SPECIES_NONE;

                for(i = 0; i < gBattlersCount; i++){
                    if ((gBattleMons[sMenuDataPtr->battlerId].status2 & STATUS2_INFATUATION) && 
                        (gBattleMons[sMenuDataPtr->battlerId].status2 & STATUS2_INFATUATED_WITH(i)) &&
                        i != sMenuDataPtr->battlerId){
                            infuatedWith = i;
                            species = gBattleMons[infuatedWith].species;
                            break;
                        }
                }

                StringCopy(gStringVar1, gSpeciesNames[species]);
                StringExpandPlaceholders(gStringVar4, sText_Title_Status_Infuation);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Infuation_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            }
            break;
            case STATUS_INFO_FOCUS_ENERGY:
                StringCopy(gStringVar1, sText_Title_Status_Focus_Energy);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Focus_Energy_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_TRANSFORMED:
            {
                u16 species = gBattleMons[sMenuDataPtr->battlerId].species;
                
                StringCopy(gStringVar1, gSpeciesNames[species]);
                StringExpandPlaceholders(gStringVar4, sText_Title_Status_Transformed);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);
                //Description
                StringCopy(gStringVar1, sText_Title_Status_Transformed_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            }
            break;
            case STATUS_INFO_ESCAPE_PREVENTION:
                StringCopy(gStringVar1, sText_Title_Status_Escape_Prevention);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Escape_Prevention_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_CURSED:
                StringCopy(gStringVar1, sText_Title_Status_Cursed);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Status_Cursed_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_FORESIGHT:
                StringCopy(gStringVar1, sText_Title_Status_Foresight);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Status_Foresight_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_DEFENSE_CURL:
                StringCopy(gStringVar1, sText_Title_Status_Defense_Curl);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Status_Defense_Curl_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_TORMENT:
                StringCopy(gStringVar1, sText_Title_Status_Torment);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Status_Torment_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_LEECHSEED:{
                u8 seedUser = gStatuses3[sMenuDataPtr->battlerId] & STATUS3_LEECHSEED_BATTLER;
                u16 species  = gBattleMons[seedUser].species;

                StringCopy(gStringVar1, gSpeciesNames[species]);
                StringExpandPlaceholders(gStringVar4, sText_Title_Status_Leech_Seed_Target);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Leech_Seed_Target_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            }
            break;
            case STATUS_INFO_PERISH_SONG:
                StringCopy(gStringVar1, sText_Title_Status_Perish_Song);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gVolatileStructs[sMenuDataPtr->battlerId].perishSongTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Perish_Song_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_MINIMIZED:
                StringCopy(gStringVar1, sText_Title_Status_Minimize);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Minimize_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_CHARGED_UP:
                StringCopy(gStringVar1, sText_Title_Status_Charge);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gVolatileStructs[sMenuDataPtr->battlerId].perishSongTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Charge_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_ROOTED:
                StringCopy(gStringVar1, sText_Title_Status_Rooted);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Rooted_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_YAWN:
                StringCopy(gStringVar1, sText_Title_Status_Yawn);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = 1 + (gStatuses3[sMenuDataPtr->battlerId] & STATUS3_YAWN_TURN(0));
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Yawn_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_GRUDGE:
                StringCopy(gStringVar1, sText_Title_Status_Grudge);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Grudge_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_CANT_CRIT:
                StringCopy(gStringVar1, sText_Title_Status_Cant_Crit);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Cant_Crit_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_GASTRO_ACID:
                StringCopy(gStringVar1, sText_Title_Status_Gastro_Acid);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Gastro_Acid_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_EMBARGO:
                StringCopy(gStringVar1, sText_Title_Status_Embargo);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gVolatileStructs[sMenuDataPtr->battlerId].embargoTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Embargo_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_SMACKED_DOWN:
                StringCopy(gStringVar1, sText_Title_Status_Smack_Down);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Smack_Down_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_MIRACLE_EYED:
                StringCopy(gStringVar1, sText_Title_Status_Miracle_Eye);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Miracle_Eye_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_HEAL_BLOCKED:
                StringCopy(gStringVar1, sText_Title_Status_Heal_Block);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Heal_Block_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_AQUA_RING:
                StringCopy(gStringVar1, sText_Title_Status_Aqua_Ring);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Aqua_Ring_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_MAGNET_RISE:
                StringCopy(gStringVar1, sText_Title_Status_Magnet_Rise);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gVolatileStructs[sMenuDataPtr->battlerId].magnetRiseTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Magnet_Rise_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_SEMI_INVULNERABLE:
                StringCopy(gStringVar1, sText_Title_Status_Semi_Invulnerable);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Semi_Invulnerable_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_ELECTRIFIED:
                StringCopy(gStringVar1, sText_Title_Status_Electrified);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Status_Electrified_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_PLASMA_FIST:
                StringCopy(gStringVar1, sText_Title_Status_Plasma_Fist);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Status_Plasma_Fist_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_COILED:
                StringCopy(gStringVar1, sText_Title_Status_Coiled_Up);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Status_Coiled_Up_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_PROTOSYNTHESIS:
                StringCopy(gStringVar1, sText_Title_Status_Protosynthesis);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Status_Paradox_Boost_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
            case STATUS_INFO_QUARK_DRIVE:
                StringCopy(gStringVar1, sText_Title_Status_Quark_Drive);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Status_Paradox_Boost_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                printedInfo = TRUE;
            break;
        }
        if(printedInfo)
            y = y + MAX_DESCRIPTION_LINES + 2;
    }

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

static void PrintDamageCalulatorTab(void){
    u8 i, j;
    u8 x, y, x2, y2;
    u8 windowId = WINDOW_1;
    u8 colorIdx = FONT_BLACK;
    u16 species = gBattleMons[sMenuDataPtr->battlerId].species;
    u16 moves[MAX_MON_MOVES] = {gBattleMons[sMenuDataPtr->battlerId].moves[0], 
                                gBattleMons[sMenuDataPtr->battlerId].moves[1],
                                gBattleMons[sMenuDataPtr->battlerId].moves[2], 
                                gBattleMons[sMenuDataPtr->battlerId].moves[3]};
    u16 ability = gBattleMons[sMenuDataPtr->battlerId].ability;
    u16 gBattleMoveDamage;
    u32 personality = gBattleMons[sMenuDataPtr->battlerId].personality;
    u8 gender = GetGenderFromSpeciesAndPersonality(gBattleMons[sMenuDataPtr->battlerId].species, gBattleMons[sMenuDataPtr->battlerId].personality);
    u8 statStage;
    bool8 statStageUp = FALSE;
    bool8 isEnemyMon = GetBattlerSide(sMenuDataPtr->battlerId) == B_SIDE_OPPONENT;
    u16 move;
    u8 target = BATTLE_OPPOSITE(sMenuDataPtr->battlerId);
    
    if(sMenuDataPtr->dmgCalculatorTarget != 0 && IsDoubleBattle())
        target = BATTLE_OPPOSITE(BATTLE_PARTNER(sMenuDataPtr->battlerId));

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    //Title
    x  = 9;
    y  = 0;
    x2 = 0;
    y2 = 0;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Battler_Damage);
    x  = 20;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Controllers);

    // First Move
    x  = 9;
    y  = 3;
    x2 = 0;
    y2 = -4;
    for(i = 0; i < MAX_MON_MOVES; i++){
        //Move Name
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gMoveNamesLong[moves[i]]);

        // Move Damage ---------------------------------------------------------------------------------------------------
        y++;
        if(gBattleMoves[moves[i]].split == SPLIT_STATUS || gBattleMoves[moves[i]].power <= 2){
            StringCopy(gStringVar4, gText_Target_Nothing);
        }
        else{
            PrintDamageCalculation(sMenuDataPtr->battlerId, target, i);
        }
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
        y = y + 3;
    }

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

#define HP_EV_INDEX    0
#define ATK_EV_INDEX   1
#define DEF_EV_INDEX   2
#define SPEED_EV_INDEX 3
#define SPATK_EV_INDEX 4
#define SPDEF_EV_INDEX 5

const u8 gText_SmogonDamageCalculator_FirstPartText_SpecialDefense[]              = _("{STR_VAR_1} SpA {STR_VAR_2} {STR_VAR_3} vs.");
const u8 gText_SmogonDamageCalculator_FirstPartText_SpecialDefense_NatureUp[]     = _("{STR_VAR_1} SpA+ {STR_VAR_2} {STR_VAR_3} vs.");
const u8 gText_SmogonDamageCalculator_FirstPartText_SpecialDefense_NatureDown[]   = _("{STR_VAR_1} SpA- {STR_VAR_2} {STR_VAR_3} vs.");
const u8 gText_SmogonDamageCalculator_FirstPartText_PhysicalDefense[]             = _("{STR_VAR_1} Atk {STR_VAR_2} {STR_VAR_3} vs.");
const u8 gText_SmogonDamageCalculator_FirstPartText_PhysicalDefense_NatureUp[]    = _("{STR_VAR_1} Atk+ {STR_VAR_2} {STR_VAR_3} vs.");
const u8 gText_SmogonDamageCalculator_FirstPartText_PhysicalDefense_NatureDown[]  = _("{STR_VAR_1} Atk- {STR_VAR_2} {STR_VAR_3} vs.");
//{STR_VAR_1}+ = Special Attack EV, {STR_VAR_2} = Pokemon Name, {STR_VAR_3} = Move Name
const u8 gText_SmogonDamageCalculator_SecondPartText_SpecialDefense[]             = _("{STR_VAR_1}\n{STR_VAR_2} HP/ {STR_VAR_3} SpD");
const u8 gText_SmogonDamageCalculator_SecondPartText_SpecialDefense_NatureUp[]    = _("{STR_VAR_1}\n{STR_VAR_2} HP/ {STR_VAR_3} SpD+");
const u8 gText_SmogonDamageCalculator_SecondPartText_SpecialDefense_NatureDown[]  = _("{STR_VAR_1}\n{STR_VAR_2} HP/ {STR_VAR_3} SpD-");
const u8 gText_SmogonDamageCalculator_SecondPartText_PhysicalDefense[]            = _("{STR_VAR_1}\n{STR_VAR_2} HP/ {STR_VAR_3} Def");
const u8 gText_SmogonDamageCalculator_SecondPartText_PhysicalDefense_NatureUp[]   = _("{STR_VAR_1}\n{STR_VAR_2} HP/ {STR_VAR_3} Def+");
const u8 gText_SmogonDamageCalculator_SecondPartText_PhysicalDefense_NatureDown[] = _("{STR_VAR_1}\n{STR_VAR_2} HP/ {STR_VAR_3} Def-");
//{STR_VAR_1} = First Part {STR_VAR_2} = HP EV, {STR_VAR_3} = Special Defense EV
const u8 gText_SmogonDamageCalculator_ThirdPart[] = _("{STR_VAR_1} {STR_VAR_2}: {STR_VAR_3}");
//{STR_VAR_1} = Second Part {STR_VAR_2} = Target Name, {STR_VAR_3} = Min Damage
const u8 gText_SmogonDamageCalculator_FourthPart[] = _("{STR_VAR_1}-{STR_VAR_2}\n({STR_VAR_3} - ");
//{STR_VAR_1} = Third Part {STR_VAR_2} = Max Damage, {STR_VAR_3} = Min Percent
const u8 gText_SmogonDamageCalculator_FifthPart[] = _("{STR_VAR_1} {STR_VAR_2}%) -- {STR_VAR_3}% chance to");
const u8 gText_SmogonDamageCalculator_FifthPart_Guaranteed[] = _("{STR_VAR_1} {STR_VAR_2}%) -- Guaranteed");
//{STR_VAR_1} = Foruth Part {STR_VAR_2} = Max Percent, {STR_VAR_3} = Chance
const u8 gText_SmogonDamageCalculator_SixthPart[] = _("{STR_VAR_1} {STR_VAR_2}HKO");
const u8 gText_SmogonDamageCalculator_SixthPart_OHKO[] = _("{STR_VAR_1} OHKO");
//{STR_VAR_1} = Fifth Part {STR_VAR_2} = 2HKO or 3HKO

#define MAX_DAMAGE_FACTOR 0
#define MIN_DAMAGE_FACTOR 16
#define MAX_PERCENT 100
#define MAX_PERCENT_2 10000

static void CalculateDamage(u8 battler, u8 target, u8 moveIndex){
    u32 minDamage, maxDamage, midDamage, tempdamage;
    s32 dmg, critDmg, critChance, tempchance, minHits2KOChance;
    u32 hits2KO, hits2KOmin, percentage;
    u8 chance, moveType;
    u8 natureAtk, natureDef;
    u8 statUpAtk, statUpDef;
    u8 statDownAtk, statDownDef;
    u8 i, j;
    struct Pokemon *party, *targetParty;
    u16 targetCurrentHp = gBattleMons[target].hp;
    bool8 isCrit = FALSE;
    u16 move = gBattleMons[battler].moves[moveIndex];
    const s8 *natureMod;
    
    if(sMenuDataPtr->damageCalculation[battler][target][moveIndex].calculated)
        return;

    sMenuDataPtr->damageCalculation[battler][target][moveIndex].calculated = TRUE;

    //Sets move type depending on the mon ability/stats
    SetTypeBeforeUsingMove(move, battler);
    GET_MOVE_TYPE(move, moveType);

    //Max and Min Damage
    sMenuDataPtr->damageCalculation[battler][target][moveIndex].minDamage = minDamage = DoMoveDamageCalcBattleMenu(move, battler, target, &moveType, FALSE, MIN_DAMAGE_FACTOR);
    sMenuDataPtr->damageCalculation[battler][target][moveIndex].maxDamage = maxDamage = DoMoveDamageCalcBattleMenu(move, battler, target, &moveType, FALSE, MAX_DAMAGE_FACTOR);

    if(!IsBattlerAlive(battler) || 
       !IsBattlerAlive(target)  || 
       gBattleMoves[move].split == SPLIT_STATUS || 
       gBattleMoves[move].power <= 2            || 
       sMenuDataPtr->damageCalculation[battler][target][moveIndex].maxDamage == 0){
        sMenuDataPtr->damageCalculation[battler][target][moveIndex].noDamage = TRUE;
        return;
    }

    // Min Damage Percentage
    percentage = (minDamage * MAX_PERCENT_2) / targetCurrentHp; 
    percentage = (percentage / MAX_PERCENT);
    if(percentage >= MAX_PERCENT)
        percentage = MAX_PERCENT;
    sMenuDataPtr->damageCalculation[battler][target][moveIndex].minDamagePercentage = percentage;

    // Max Damage Percentage
    percentage = (maxDamage * MAX_PERCENT_2)/ targetCurrentHp; 
    percentage = (percentage / MAX_PERCENT);
    if(percentage > MAX_PERCENT)
        percentage = MAX_PERCENT;
    sMenuDataPtr->damageCalculation[battler][target][moveIndex].maxDamagePercentage = percentage;
    
    //Chances To KO
    sMenuDataPtr->damageCalculation[battler][target][moveIndex].hits2KO = (targetCurrentHp / sMenuDataPtr->damageCalculation[battler][target][moveIndex].maxDamage);

    for(i = 0; i < MIN_DAMAGE_FACTOR; i++){
        tempdamage = DoMoveDamageCalcBattleMenu(move, battler, target, &moveType, FALSE, MIN_DAMAGE_FACTOR - i);
        tempchance = (targetCurrentHp / tempdamage);

        if(tempchance == hits2KO){
            percentage = (MIN_DAMAGE_FACTOR - i);
            break;
        }
    }

    minHits2KOChance = (percentage * (MAX_PERCENT_2 / MIN_DAMAGE_FACTOR));
    sMenuDataPtr->damageCalculation[battler][target][moveIndex].chance2KO = minHits2KOChance / MAX_PERCENT;

    //Nature Stuff
    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (GetBattlerSide(target) == B_SIDE_PLAYER)
        targetParty = gPlayerParty;
    else
        targetParty = gEnemyParty;

    natureAtk = GetMonData(&party[gBattlerPartyIndexes[battler]], MON_DATA_NATURE, NULL);
    natureDef = GetMonData(&targetParty[gBattlerPartyIndexes[target]], MON_DATA_NATURE, NULL);

    //Attacker
    if(natureAtk == NATURE_HARDY || natureAtk == NATURE_DOCILE || natureAtk == NATURE_SERIOUS || natureAtk == NATURE_BASHFUL || natureAtk == NATURE_QUIRKY){
        sMenuDataPtr->damageCalculation[battler][target][moveIndex].attackerNatureUp   = NUM_NATURE_STATS;
        sMenuDataPtr->damageCalculation[battler][target][moveIndex].attackerNatureDown = NUM_NATURE_STATS;
    }
    else{
        natureMod = gNatureStatTable[natureAtk];
        for(i = 0; i < NUM_NATURE_STATS; i++){
            if (natureMod[i] > 0)
                sMenuDataPtr->damageCalculation[battler][target][moveIndex].attackerNatureUp   = i + 1; //Nature Up
            else if (natureMod[i] < 0)
                sMenuDataPtr->damageCalculation[battler][target][moveIndex].attackerNatureDown = i + 1; //Nature Down
        }
    }

    //Target
    if(natureDef == NATURE_HARDY || natureDef == NATURE_DOCILE || natureDef == NATURE_SERIOUS || natureDef == NATURE_BASHFUL || natureDef == NATURE_QUIRKY){
        sMenuDataPtr->damageCalculation[battler][target][moveIndex].targetNatureUp   = NUM_NATURE_STATS;
        sMenuDataPtr->damageCalculation[battler][target][moveIndex].targetNatureDown = NUM_NATURE_STATS;
    }
    else{
        natureMod = gNatureStatTable[natureDef];
        for(i = 0; i < NUM_NATURE_STATS; i++){
            if (natureMod[i] > 0)
                sMenuDataPtr->damageCalculation[battler][target][moveIndex].targetNatureUp = i + 1; //Nature Up
            else if (natureMod[i] < 0)
                sMenuDataPtr->damageCalculation[battler][target][moveIndex].targetNatureDown = i + 1; //Nature Down
        }
    }

    //Evs
    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (GetBattlerSide(target) == B_SIDE_PLAYER)
        targetParty = gPlayerParty;
    else
        targetParty = gEnemyParty;

    for(i = 0 ; i < NUM_STATS; i++){
        sMenuDataPtr->damageCalculation[battler][target][moveIndex].battlerEvs[i] = GetMonData(&party[gBattlerPartyIndexes[battler]],      MON_DATA_HP_EV + i, NULL);
        sMenuDataPtr->damageCalculation[battler][target][moveIndex].targetEvs[i]  = GetMonData(&targetParty[gBattlerPartyIndexes[target]], MON_DATA_HP_EV + i, NULL);
    }
}

static void PrintDamageCalculation(u8 battler, u8 target, u8 moveIdx){
    u32 minDamage, maxDamage, midDamage, tempdamage;
    s32 dmg, critDmg, critChance, tempchance;
    double minHits2KOChance;
    u16 hits2KO, hits2KOmin, percentage;
    u8 chance, moveType;
    u8 natureAtk, natureDef;
    u8 statUpAtk, statUpDef;
    u8 statDownAtk, statDownDef;
    u8 i, j;
    u16 targetCurrentHp = gBattleMons[target].hp;
    bool8 isCrit = FALSE;
    u16 typeEffectivenessModifier;
    const s8 *natureMod;
    u16 move = gBattleMons[battler].moves[moveIdx];
    struct DamageCalculation *damageCalculation;
    u8 *DamageCalculationText;

    //Sets move type depending on the mon ability/stats
    SetTypeBeforeUsingMove(move, battler);
    GET_MOVE_TYPE(move, moveType);
    
    typeEffectivenessModifier = CalcTypeEffectivenessMultiplier(move, moveType, battler, target, FALSE);

    if (sMenuDataPtr->damageCalculation[battler][target][moveIdx].noDamage){
        StringCopy(gStringVar4, gText_Target_Nothing);
        return;
    }

    CalculateDamage(battler, target, moveIdx);
    damageCalculation = &sMenuDataPtr->damageCalculation[battler][target][moveIdx];

    //252+ SpA Abomasnow Blizzard vs. 168 HP / 0 SpD Abomasnow: 178-211 (49 - 58.1%) -- 97.7% chance to 2HKO

    //Damage Calculation
    minDamage = damageCalculation->minDamage;
    maxDamage = damageCalculation->maxDamage;

    //First Part
    StringCopy(gStringVar2, gSpeciesNames[gBattleMons[battler].species]);
    StringCopy(gStringVar3, gMoveNames[move]);
    if(gBattleMoves[move].split == SPLIT_SPECIAL){
        ConvertIntToDecimalStringN(gStringVar1, damageCalculation->battlerEvs[SPATK_EV_INDEX], STR_CONV_MODE_LEFT_ALIGN, 3);
        if(damageCalculation->attackerNatureDown == STAT_SPATK)
            StringExpandPlaceholders(gStringVar4, gText_SmogonDamageCalculator_FirstPartText_SpecialDefense_NatureDown);
        else if(damageCalculation->attackerNatureUp == STAT_SPATK)
            StringExpandPlaceholders(gStringVar4, gText_SmogonDamageCalculator_FirstPartText_SpecialDefense_NatureUp);
        else
            StringExpandPlaceholders(gStringVar4, gText_SmogonDamageCalculator_FirstPartText_SpecialDefense);
    }
    else{
        ConvertIntToDecimalStringN(gStringVar1, damageCalculation->battlerEvs[ATK_EV_INDEX], STR_CONV_MODE_LEFT_ALIGN, 3);
        if(damageCalculation->attackerNatureDown == STAT_ATK)
            StringExpandPlaceholders(gStringVar4, gText_SmogonDamageCalculator_FirstPartText_PhysicalDefense_NatureDown);
        else if(damageCalculation->attackerNatureUp == STAT_ATK)
            StringExpandPlaceholders(gStringVar4, gText_SmogonDamageCalculator_FirstPartText_PhysicalDefense_NatureUp);
        else
            StringExpandPlaceholders(gStringVar4, gText_SmogonDamageCalculator_FirstPartText_PhysicalDefense);
    }

    //Second Part
    StringCopy(gStringVar1, gStringVar4);
    ConvertIntToDecimalStringN(gStringVar2, damageCalculation->targetEvs[HP_EV_INDEX], STR_CONV_MODE_LEFT_ALIGN, 3);
    if(gBattleMoves[move].split == SPLIT_SPECIAL){
        ConvertIntToDecimalStringN(gStringVar3, damageCalculation->targetEvs[SPDEF_EV_INDEX], STR_CONV_MODE_LEFT_ALIGN, 3);
        if(damageCalculation->targetNatureDown == STAT_SPDEF)
            StringExpandPlaceholders(gStringVar4, gText_SmogonDamageCalculator_SecondPartText_SpecialDefense_NatureDown);
        else if(damageCalculation->targetNatureUp == STAT_SPDEF)
            StringExpandPlaceholders(gStringVar4, gText_SmogonDamageCalculator_SecondPartText_SpecialDefense_NatureUp);
        else
            StringExpandPlaceholders(gStringVar4, gText_SmogonDamageCalculator_SecondPartText_SpecialDefense);
    }
    else{
        ConvertIntToDecimalStringN(gStringVar3, damageCalculation->targetEvs[DEF_EV_INDEX], STR_CONV_MODE_LEFT_ALIGN, 3);
        if(damageCalculation->targetNatureDown == STAT_DEF)
            StringExpandPlaceholders(gStringVar4, gText_SmogonDamageCalculator_SecondPartText_PhysicalDefense_NatureDown);
        else if(damageCalculation->targetNatureUp == STAT_DEF)
            StringExpandPlaceholders(gStringVar4, gText_SmogonDamageCalculator_SecondPartText_PhysicalDefense_NatureUp);
        else
            StringExpandPlaceholders(gStringVar4, gText_SmogonDamageCalculator_SecondPartText_PhysicalDefense);
    }
        
    //Third Part
    StringCopy(gStringVar1, gStringVar4);
    StringCopy(gStringVar2, gSpeciesNames[gBattleMons[target].species]);
    ConvertIntToDecimalStringN(gStringVar3, minDamage, STR_CONV_MODE_LEFT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_SmogonDamageCalculator_ThirdPart);

    //Fourth Part gText_SmogonDamageCalculator_FourthPart
    StringCopy(gStringVar1, gStringVar4);
    ConvertIntToDecimalStringN(gStringVar2, maxDamage, STR_CONV_MODE_LEFT_ALIGN, 4);
    ConvertIntToDecimalStringN(gStringVar3, damageCalculation->minDamagePercentage, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_SmogonDamageCalculator_FourthPart);

    //Fifth Part 
    StringCopy(gStringVar1, gStringVar4);
    ConvertIntToDecimalStringN(gStringVar2, damageCalculation->maxDamagePercentage, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, damageCalculation->chance2KO, STR_CONV_MODE_LEFT_ALIGN, 3);
    if(damageCalculation->chance2KO >= 100)
        StringExpandPlaceholders(gStringVar4, gText_SmogonDamageCalculator_FifthPart_Guaranteed);
    else
        StringExpandPlaceholders(gStringVar4, gText_SmogonDamageCalculator_FifthPart);

    //Sixth Part
    StringCopy(gStringVar1, gStringVar4);
    if(damageCalculation->hits2KO > 0){
        ConvertIntToDecimalStringN(gStringVar2, (damageCalculation->hits2KO + 1), STR_CONV_MODE_LEFT_ALIGN, 3);
        StringExpandPlaceholders(gStringVar4, gText_SmogonDamageCalculator_SixthPart);
    }
    else
        StringExpandPlaceholders(gStringVar4, gText_SmogonDamageCalculator_SixthPart_OHKO);
}

#define NUM_PARTY_ICONS_SHOWN  6
#define PARTY_POKEMON_ICON_X   (11 * 8) + 4
#define PARTY_POKEMON_ICON_Y   (4 * 8)
#define PARTY_POKEMON_ICON_Y_2 (4 * 8) + (10 * 8)
#define PARTY_POKEMON_SPACE_X  (7 * 8)
#define PARTY_POKEMON_SPACE_Y  (3 * 8)

static void PrintPartyTab(){
    u8 i, j;
    u8 x, y, x2, y2;
    u8 windowId = WINDOW_1;
    u8 colorIdx = FONT_BLACK;
    u8 turnsLeft = 5;
    bool8 printedInfo = FALSE;
    u8 maxLines = 3;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    //Title
    x  = 9;
    y  = 0;
    x2 = 0;
    y2 = -4;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Field_Party);
    x  = 15;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_FieldControllers);

    //Player Mon Icons
    for(i = 0; i < NUM_PARTY_ICONS_SHOWN; i++){
        ShowSpeciesIconParty(i, FALSE, PARTY_POKEMON_ICON_X + ((i % 3) * PARTY_POKEMON_SPACE_X), PARTY_POKEMON_ICON_Y + ((i / 3) * PARTY_POKEMON_SPACE_Y));
    }

    //Enemy Mon Icons
    for(i = 0; i < NUM_PARTY_ICONS_SHOWN; i++){
        ShowSpeciesIconParty(i, TRUE, PARTY_POKEMON_ICON_X + ((i % 3) * PARTY_POKEMON_SPACE_X), PARTY_POKEMON_ICON_Y_2 + ((i / 3)  * PARTY_POKEMON_SPACE_Y));
    }
    
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

//Weathers
const u8 sText_Title_Field_Weather[]                      = _("Weather: {STR_VAR_1}");
const u8 sText_Title_Field_Weather_Rain[]                 = _("Rain");
const u8 sText_Title_Field_Weather_Sun[]                  = _("Sun");
const u8 sText_Title_Field_Weather_Sandstorm[]            = _("Sandstorm");
const u8 sText_Title_Field_Weather_Hail[]                 = _("Hail");
const u8 sText_Title_Field_Weather_Snow[]                 = _("Snow");
const u8 sText_Title_Field_Weather_Strong_Winds[]         = _("Strong Winds");
const u8 sText_Title_Field_Weather_Rain_Primal[]          = _("Primal Rain");
const u8 sText_Title_Field_Weather_Sun_Primal[]           = _("Primal Sun");

const u8 sText_Title_Field_Weather_Description_Rain[]         = _("Strengthens Water-type moves by\n"
                                                                  "50% while weakening Fire-type\n"
                                                                  "moves by 50%.");
const u8 sText_Title_Field_Weather_Description_Sun[]          = _("Strengthens the power of Fire-type\n"
                                                                  "moves by 50% and weakens Water-type\n"
                                                                  "moves by 50%.");
const u8 sText_Title_Field_Weather_Description_Sandstorm[]    = _("Any Pokémon that is not Rock, Ground\n"
                                                                  "or Steel-type will be damaged for\n"
                                                                  "1/16 of its maximum HP each turn.");
const u8 sText_Title_Field_Weather_Description_Hail[]         = _("Any Pokémon that is not Ice-type\n"
                                                                  "will be damaged each turn, Pokémon\n"
                                                                  "are twice as likely to get frostbite.");
const u8 sText_Title_Field_Weather_Description_Strong_Winds[] = _("Causes Electric, Ice, and Rock-type\n"
                                                                  "moves to deal neutral damage to \n"
                                                                  "Flying-type Pokémon.");
const u8 sText_Title_Field_Weather_Description_Primal_Rain[]  = _("Boosts the power of Water-type\n"
                                                                  "moves and protects Pokémon from\n"
                                                                  "Fire-type moves.");
const u8 sText_Title_Field_Weather_Description_Primal_Sun[]  = _("Boosts the power of Fire-type\n"
                                                                 "moves and protects Pokémon from\n"
                                                                 "Water-type moves.");
//Terrains
const u8 sText_Title_Field_Terrain[]                      = _("{STR_VAR_1} Terrain");
const u8 sText_Title_Field_Terrain_Electric[]             = _("Electric");
const u8 sText_Title_Field_Terrain_Psychic[]              = _("Psychic");
const u8 sText_Title_Field_Terrain_Misty[]                = _("Misty");
const u8 sText_Title_Field_Terrain_Grassy[]               = _("Grassy");

const u8 sText_Title_Field_Terrain_Description_Electric[]    = _("Pokémon on the ground won't fall\n"
                                                                 "asleep. The power of Electric-type\n"
                                                                 "moves is boosted.");
const u8 sText_Title_Field_Terrain_Description_Psychic[]     = _("Pokémon on the ground won't be hit\n"
                                                                "by priority moves. The power of\n"
                                                                "Psychic-type moves is boosted.");
const u8 sText_Title_Field_Terrain_Description_Misty[]       = _("Pokémon on the ground won't get any\n"
                                                                 "status conditions, Damage from Dragon\n"
                                                                 "type moves is halved.");
const u8 sText_Title_Field_Terrain_Description_Grassy[]      = _("Increases the power of Grass-type\n"
                                                                 "moves, Restores 1/16 HP to all\n"
                                                                 "Pokémon on the ground each turn.");
//Rooms
const u8 sText_Title_Field_Trick_Room[]                      = _("Trick Room");
const u8 sText_Title_Field_Room_Description_Trick[]          = _("The move order is reversed, slower\n"
                                                                 "Pokémon will attack before faster\n"
                                                                 "Pokémon.");
const u8 sText_Title_Field_Wonder_Room[]                     = _("Wonder Room:");
const u8 sText_Title_Field_Room_Description_Wonder[]          = _("Swaps the Defense and Sp.Defense\n"
                                                                  "of all Pokémon, but stat changes\n"
                                                                  "remain on their respective stat.");
const u8 sText_Title_Field_Magic_Room[]                      = _("Magic Room:");
const u8 sText_Title_Field_Room_Description_Magic[]          = _("Suppresses the effect of all items\n"
                                                                 "held by the Pokémon on the field.");
const u8 sText_Title_Field_Gravity[]                         = _("Gravity");
const u8 sText_Title_Field_Gravity_Description   []         = _("The accuracy of all moves is\n"
                                                                "multiplied by 1.67, all Pokémon on\n"
                                                                "the field to become grounded.");
const u8 sText_Title_Field_Inverse_Room[]                   = _("Inverse Room:");
const u8 sText_Title_Field_Inverse_Description[]            = _("The type effectiveness are inversed.\n"
                                                                "Any type that would be resistant or\n"
                                                                "immune to another type is now weak.");
//Other
const u8 sText_Title_Field_Fairy_Lock[]                      = _("Fairy Lock");
const u8 sText_Title_Field_Fairy_Lock_Description[]          = _("Prevents all Pokémon(except Ghost\n"
                                                                 "types) from switching out or\n"
                                                                 "fleeing during their next turn.");
const u8 sText_Title_Field_Mud_Sport[]                       = _("Mud Sport");
const u8 sText_Title_Field_Mud_Sport_Description[]           = _("Reduces the base power of\n"
                                                                 "Electric-type moves by 67%\n"
                                                                 "on both sides.");
const u8 sText_Title_Field_Water_Sport[]                     = _("Water Sport");
const u8 sText_Title_Field_Water_Sport_Description[]         = _("Reduces the base power of\n"
                                                                 "Fire-type moves by 67%\n"
                                                                 "on both sides.");
const u8 sText_Title_Field_Ion_Deluge[]                     = _("Ion Deluge");
const u8 sText_Title_Field_Ion_Deluge_Description[]         = _("Causes all the Normal-type moves to\n"
                                                                "become Electric-type instad,\n"
                                                                "including status moves.");
static void PrintFieldTab(void)
{
    u8 i, j;
    u8 x, y, x2, y2;
    u8 windowId = WINDOW_1;
    u8 colorIdx = FONT_BLACK;
    u8 turnsLeft = 5;
    bool8 printedInfo = FALSE;
    u8 maxLines = 3;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    //Title
    x  = 9;
    y  = 0;
    x2 = 0;
    y2 = -4;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Field_Stats);
    x  = 15;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_FieldControllers);

    // Weather
    x  = 9;
    y  = 3;
    x2 = 0;
    y2 = -4;

    if(sMenuDataPtr->numFields < maxLines)
        maxLines = sMenuDataPtr->numFields;
    
    for(i = 0; i < maxLines; i++){
        printedInfo = FALSE;
        //switch(sMenuDataPtr->fieldInfo[(i ) % NUM_FIELD_INFO]){
        switch(sMenuDataPtr->fieldInfo[(i + sMenuDataPtr->currentFieldInfo) % sMenuDataPtr->numFields]){
            case FIELD_INFO_WEATHER:
                //Title
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Field_Weather);
                if((gBattleWeather & WEATHER_RAIN_ANY) && !(gBattleWeather & WEATHER_RAIN_PRIMAL))
                    StringCopy(gStringVar1, sText_Title_Field_Weather_Rain);
                else if((gBattleWeather & WEATHER_SUN_ANY) && !(gBattleWeather & WEATHER_SUN_PRIMAL))
                    StringCopy(gStringVar1, sText_Title_Field_Weather_Sun);
                else if((gBattleWeather & WEATHER_SANDSTORM_ANY))
                    StringCopy(gStringVar1, sText_Title_Field_Weather_Sandstorm);
                else if((gBattleWeather & WEATHER_HAIL_ANY))
                    StringCopy(gStringVar1, sText_Title_Field_Weather_Hail);
                else if((gBattleWeather & WEATHER_STRONG_WINDS))
                    StringCopy(gStringVar1, sText_Title_Field_Weather_Strong_Winds);
                else if((gBattleWeather & WEATHER_RAIN_PRIMAL))
                    StringCopy(gStringVar1, sText_Title_Field_Weather_Rain_Primal);
                else if((gBattleWeather & WEATHER_SUN_PRIMAL))
                    StringCopy(gStringVar1, sText_Title_Field_Weather_Sun_Primal);
                else
                    StringCopy(gStringVar1, sText_Title_Field_None);

                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + SPACE_BETWEEN_LINES_FIELD, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
            
                if((gBattleWeather & WEATHER_ANY)){
                    //Turns Left
                    if(!(gBattleWeather & WEATHER_RAIN_PRIMAL) && !(gBattleWeather & WEATHER_SUN_PRIMAL)){
                        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Field_Turns_Left);
                        ConvertIntToDecimalStringN(gStringVar1, gWishFutureKnock.weatherDuration, STR_CONV_MODE_LEFT_ALIGN, 4);
                        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                    }

                    //Weather Description
                    if((gBattleWeather & WEATHER_STRONG_WINDS))
                        StringCopy(gStringVar1, sText_Title_Field_Weather_Description_Strong_Winds);
                    else if((gBattleWeather & WEATHER_RAIN_PRIMAL))
                        StringCopy(gStringVar1, sText_Title_Field_Weather_Description_Primal_Rain);
                    else if((gBattleWeather & WEATHER_SUN_PRIMAL))
                        StringCopy(gStringVar1, sText_Title_Field_Weather_Description_Primal_Sun);
                    else if((gBattleWeather & WEATHER_RAIN_ANY))
                        StringCopy(gStringVar1, sText_Title_Field_Weather_Description_Rain);
                    else if((gBattleWeather & WEATHER_SUN_ANY))
                        StringCopy(gStringVar1, sText_Title_Field_Weather_Description_Sun);
                    else if((gBattleWeather & WEATHER_SANDSTORM_ANY))
                        StringCopy(gStringVar1, sText_Title_Field_Weather_Description_Sandstorm);
                    else if((gBattleWeather & WEATHER_HAIL_ANY))
                        StringCopy(gStringVar1, sText_Title_Field_Weather_Description_Hail);
                    
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                }

                printedInfo = TRUE;
            break;
            case FIELD_INFO_TERRAIN:
                //Terrain
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Field_Terrain);
                if(gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN)
                    StringCopy(gStringVar1, sText_Title_Field_Terrain_Electric);
                else if(gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN)
                    StringCopy(gStringVar1, sText_Title_Field_Terrain_Grassy);
                else if(gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN)
                    StringCopy(gStringVar1, sText_Title_Field_Terrain_Misty);
                else if(gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN)
                    StringCopy(gStringVar1, sText_Title_Field_Terrain_Psychic);
                else
                    StringCopy(gStringVar1, sText_Title_Field_None);

                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + SPACE_BETWEEN_LINES_FIELD, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                //Turns Left
                if(gFieldStatuses & STATUS_FIELD_TERRAIN_ANY){
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Field_Turns_Left);
                    ConvertIntToDecimalStringN(gStringVar1, gFieldTimers.terrainTimer, STR_CONV_MODE_LEFT_ALIGN, 4);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                    //Terrain Description
                    if((gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN))
                        StringCopy(gStringVar1, sText_Title_Field_Terrain_Description_Electric);
                    else if((gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN))
                        StringCopy(gStringVar1, sText_Title_Field_Terrain_Description_Grassy);
                    else if((gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN))
                        StringCopy(gStringVar1, sText_Title_Field_Terrain_Description_Misty);
                    else if((gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN))
                        StringCopy(gStringVar1, sText_Title_Field_Terrain_Description_Psychic);

                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);
                }

                printedInfo = TRUE;
            break;
            case FIELD_INFO_INVERSE_ROOM:
                StringCopy(gStringVar1, sText_Title_Field_Inverse_Room);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gFieldTimers.inverseRoomTimer ;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Field_Inverse_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case FIELD_INFO_GRAVITY:
                StringCopy(gStringVar1, sText_Title_Field_Gravity);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gFieldTimers.gravityTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Field_Gravity_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case FIELD_INFO_TRICK_ROOM:
                StringCopy(gStringVar1, sText_Title_Field_Trick_Room);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gFieldTimers.trickRoomTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Field_Room_Description_Trick);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case FIELD_INFO_WONDER_ROOM:
                StringCopy(gStringVar1, sText_Title_Field_Wonder_Room);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gFieldTimers.wonderRoomTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Field_Room_Description_Wonder);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case FIELD_INFO_MAGIC_ROOM:
                StringCopy(gStringVar1, sText_Title_Field_Magic_Room);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gFieldTimers.magicRoomTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Field_Room_Description_Magic);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case FIELD_INFO_FAIRY_LOCK:
                StringCopy(gStringVar1, sText_Title_Field_Fairy_Lock);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gFieldTimers.fairyLockTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Field_Fairy_Lock_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case FIELD_INFO_MUD_SPORT:
                StringCopy(gStringVar1, sText_Title_Field_Mud_Sport);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gFieldTimers.mudSportTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Field_Mud_Sport_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case FIELD_INFO_WATER_SPORT:
                StringCopy(gStringVar1, sText_Title_Field_Water_Sport);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gFieldTimers.waterSportTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Field_Water_Sport_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case FIELD_INFO_ION_DELUGE:
                StringCopy(gStringVar1, sText_Title_Field_Ion_Deluge);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                /*StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gFieldTimers.magicRoomTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);*/
                
                //Description
                StringCopy(gStringVar1, sText_Title_Field_Ion_Deluge_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
        }
        if(printedInfo)
            y = y + MAX_DESCRIPTION_LINES + 2;
    }

    /*//Nature Power
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Field_Nature_Power);
    StringCopy(gStringVar1, gMoveNamesLong[MOVE_THUNDERBOLT]);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 1.5), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

    //Secret Power
    y++;
    StringCopy(gStringVar1, sText_Title_Field_Secret_Power);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
    StringCopy(gStringVar1, sText_Title_Field_Paralysis);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 1.5), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
    */

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

const u8 sText_Title_Side_Aurora_Veil[]                    = _("Auora Veil");
const u8 sText_Title_Side_Aurora_Veil_Description[]        = _("Reduces the damage done to the user\n"
                                                               "by physical and special moves by\n"
                                                               "50%.");
const u8 sText_Title_Side_Reflect[]                        = _("Reflect");
const u8 sText_Title_Side_Reflect_Description[]            = _("Reduces the damage done to the user\n"
                                                               "by physical moves by 50% can be\n"
                                                               "be lifted by moves like Haze.");
const u8 sText_Title_Side_Light_Screen[]                   = _("Light Screen");
const u8 sText_Title_Side_Light_Screen_Description[]       = _("Reduces the damage done to the user\n"
                                                               "by special moves by 50% can be\n"
                                                               "be lifted by moves like Defog.");
const u8 sText_Title_Side_Tailwind[]                       = _("Tailwind");
const u8 sText_Title_Side_Tailwind_Description[]           = _("Doubles the Speed stat of the user\n"
                                                               "and all the other Pokémon in the\n"
                                                               "user side.");
const u8 sText_Title_Side_Spikes[]                         = _("Spikes");
const u8 sText_Title_Side_Spikes_1_Description[]           = _("Pokémon who switch into the field\n"
                                                               "take a 12.5% of their maximum\n"
                                                               "HP in damage.");
const u8 sText_Title_Side_Spikes_2_Description[]           = _("Pokémon who switch into the field\n"
                                                               "take a 16.67% of their maximum\n"
                                                               "HP in damage.");
const u8 sText_Title_Side_Spikes_3_Description[]           = _("Pokémon who switch into the field\n"
                                                               "take a 25% of their maximum HP in\n"
                                                               "damage.");
const u8 sText_Title_Side_Toxic_Spikes[]                   = _("Toxic Spikes");
const u8 sText_Title_Side_Toxic_Spikes_1_Description[]     = _("Pokémon who switch into the field\n"
                                                               "acquire the poison status ailment");
const u8 sText_Title_Side_Toxic_Spikes_2_Description[]     = _("Pokémon who switch into the field\n"
                                                               "become badly poisoned");
const u8 sText_Title_Side_Stealth_Rock[]                   = _("Stealth Rock");
const u8 sText_Title_Side_Stealth_Rock_Description[]       = _("Pokémon who switch in receive dmg,\n"
                                                               "the amount varies depending by the\n"
                                                               "effectiveness of Rock against it.");
const u8 sText_Title_Side_Creeping_Thorns[]                = _("Creeping Thorns");
const u8 sText_Title_Side_Creeping_Thorns_Description[]    = _("Pokémon who switch in receive dmg,\n"
                                                               "the amount varies depending by the\n"
                                                               "effectiveness of Grass against it.");
const u8 sText_Title_Side_Sticky_Web[]                     = _("Sticky Web");
const u8 sText_Title_Side_Sticky_Web_Description[]         = _("Pokémon who switch into the field\n"
                                                               "get their Speed stat lowered by\n"
                                                               "one.");
const u8 sText_Title_Side_Safeguard[]                      = _("Safeguard");
const u8 sText_Title_Side_Safeguard_Description[]          = _("A protective field that prevents\n"
                                                               "status problems like poison,\n"
                                                               "paralysis, burn and sleep.");
const u8 sText_Title_Side_Mist[]                           = _("Safeguard");
const u8 sText_Title_Side_Mist_Description[]               = _("A white mist that prevents any\n"
                                                               "Pokémon on this side from having\n"
                                                               "any of it's stat lowered.");
const u8 sText_Title_Side_Rainbow[]                           = _("Rainbow");
const u8 sText_Title_Side_Rainbow_Description[]               = _("A splendid rainbow boosts the\n"
                                                               "chance of secondary effects for\n"
                                                               "all Pokémon on this side.");
const u8 sText_Title_Side_FireSea[]                           = _("Sea of Fire");
const u8 sText_Title_Side_FireSea_Description[]               = _("A sea of fire damages non-Fire\n"
                                                               "Pokémon on this side for 12.5%\n"
                                                               "of their maximum HP each turn.");
const u8 sText_Title_Side_Swamp[]                           = _("Swamp");
const u8 sText_Title_Side_Swamp_Description[]               = _("A deep swamp reduces the speed\n"
                                                               "stat of Pokémon on this side\n"
                                                               "by 75%.");

static void PrintSideTab(u8 side){
    u8 i, j;
    u8 x, y, x2, y2;
    u8 windowId = WINDOW_1;
    u8 colorIdx = FONT_BLACK;
    u8 turnsLeft = 5;
    bool8 printedInfo = FALSE;
    u8 maxLines = 3;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    //Title
    x  = 9;
    y  = 0;
    x2 = 0;
    y2 = -4;
    switch(side){
        case B_SIDE_PLAYER:
            AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Player_Side);
        break;
        case B_SIDE_OPPONENT:
            AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Enemy_Side);
        break;
    }
    x  = 19;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_FieldControllers2);

    // Weather
    x  = 9;
    y  = 3;
    x2 = 0;
    y2 = -4;

    switch(side){
        case B_SIDE_PLAYER:
            if(sMenuDataPtr->numSideInfoPlayer < maxLines)
                maxLines = sMenuDataPtr->numSideInfoPlayer;
            //sMenuDataPtr->currentSideInfoPlayer
        break;
        case B_SIDE_OPPONENT:
            if(sMenuDataPtr->numSideInfoEnemy < maxLines)
                maxLines = sMenuDataPtr->numSideInfoEnemy;
            //sMenuDataPtr->currentSideInfoEnemy
        break;
    }

    for(i = 0; i < maxLines; i++){
        printedInfo = FALSE;

        if(side == B_SIDE_PLAYER){
            j = sMenuDataPtr->SideInfoPlayer[(i + sMenuDataPtr->currentSideInfoPlayer) % sMenuDataPtr->numSideInfoPlayer];
        }
        else{
            j = sMenuDataPtr->SideInfoEnemy[(i + sMenuDataPtr->currentSideInfoEnemy) % sMenuDataPtr->numSideInfoEnemy];
        }

        switch(j){
            case SIDE_INFO_AURORA_VEIL:
                StringCopy(gStringVar1, sText_Title_Side_Aurora_Veil);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gSideTimers[GetBattlerSide(side)].auroraVeilTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Side_Aurora_Veil_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case SIDE_INFO_REFLECT:
                StringCopy(gStringVar1, sText_Title_Side_Reflect);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gSideTimers[GetBattlerSide(side)].reflectTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Side_Reflect_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case SIDE_INFO_LIGHT_SCREEN:
                StringCopy(gStringVar1, sText_Title_Side_Light_Screen);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gSideTimers[GetBattlerSide(side)].lightscreenTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Side_Light_Screen_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case SIDE_INFO_TAILWIND:
                StringCopy(gStringVar1, sText_Title_Side_Tailwind);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gSideTimers[GetBattlerSide(side)].tailwindTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Side_Tailwind_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case SIDE_INFO_SPIKES:
                StringCopy(gStringVar1, sText_Title_Side_Spikes);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Layers
                StringCopy(gStringVar1, sText_Title_Field_Layers);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gSideTimers[GetBattlerSide(side)].spikesAmount;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                if(turnsLeft == 1)
                    StringCopy(gStringVar1, sText_Title_Side_Spikes_1_Description);
                else if(turnsLeft == 2)
                    StringCopy(gStringVar1, sText_Title_Side_Spikes_2_Description);
                else
                    StringCopy(gStringVar1, sText_Title_Side_Spikes_3_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case SIDE_INFO_TOXIC_SPIKES:
                StringCopy(gStringVar1, sText_Title_Side_Toxic_Spikes);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Layers
                StringCopy(gStringVar1, sText_Title_Field_Layers);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gSideTimers[GetBattlerSide(side)].toxicSpikesAmount;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                if(turnsLeft == 1)
                    StringCopy(gStringVar1, sText_Title_Side_Toxic_Spikes_1_Description);
                else
                    StringCopy(gStringVar1, sText_Title_Side_Toxic_Spikes_2_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case SIDE_INFO_STEALTH_ROCK:
                StringCopy(gStringVar1, sText_Title_Side_Stealth_Rock);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Side_Stealth_Rock_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case SIDE_INFO_CREEPING_THORNS:
                StringCopy(gStringVar1, sText_Title_Side_Creeping_Thorns);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Side_Creeping_Thorns_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case SIDE_INFO_STICKY_WEB:
                StringCopy(gStringVar1, sText_Title_Side_Sticky_Web);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Description
                StringCopy(gStringVar1, sText_Title_Side_Sticky_Web_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case SIDE_INFO_SAFEGUARD:
                StringCopy(gStringVar1, sText_Title_Side_Safeguard);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gSideTimers[GetBattlerSide(side)].safeguardTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Side_Safeguard_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case SIDE_INFO_MIST:
                StringCopy(gStringVar1, sText_Title_Side_Mist);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gSideTimers[GetBattlerSide(side)].mistTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Side_Mist_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case SIDE_INFO_RAINBOW:
                StringCopy(gStringVar1, sText_Title_Side_Rainbow);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gSideTimers[GetBattlerSide(side)].rainbowTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Side_Rainbow_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case SIDE_INFO_SEA_OF_FIRE:
                StringCopy(gStringVar1, sText_Title_Side_FireSea);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gSideTimers[GetBattlerSide(side)].fireSeaTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Side_FireSea_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
            case SIDE_INFO_SWAMP:
                StringCopy(gStringVar1, sText_Title_Side_Swamp);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

                //Turns Left
                StringCopy(gStringVar1, sText_Title_Field_Turns_Left);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 2), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                turnsLeft = gSideTimers[GetBattlerSide(side)].swampTimer;
                ConvertIntToDecimalStringN(gStringVar1, turnsLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2 + (SPACE_BETWEEN_LINES_FIELD * 3), (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
                
                //Description
                StringCopy(gStringVar1, sText_Title_Side_Swamp_Description);
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, ((y + 1) * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

                printedInfo = TRUE;
            break;
        }

        if(printedInfo)
            y = y + MAX_DESCRIPTION_LINES + 2;
    }

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

//gText_MoveInfo_Priority
const u8 gText_SpeedInfo_CanKOThisTurn[] = _("Can KO {STR_VAR_1} this turn:\n{STR_VAR_2}");
#define SPEED_POKEMON_ICON_X (9 * 8) + 4
#define SPEED_POKEMON_ICON_Y (6 * 8) + 1
#define SPEED_POKEMON_SPACE  (8 * 8)

const u8 gText_BattlerLevelString[] = _("{LV}{STR_VAR_1}");
const u8 gText_PrintSpeedTabStats[] = _("Total Speed: {STR_VAR_1}");

#define MAX_SPEED_MONS_SHOWN 2

static void PrintSpeedTab(void)
{
    //Single Battle Only
    u16 targetCurrentHp, move, moveDamage, species, targetSpecies;
    u8 i, j, target, x, y, x2, y2;
    u8 windowId = WINDOW_1;
    u8 colorIdx = FONT_BLACK;
    u8 sBattlerByTurnOrder[gBattlersCount];
    u8 firstMon = sMenuDataPtr->speedModeId;
    u8 battlertoCheck = 0;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    //Calculate Order
    for (i = 0; i < gBattlersCount; i++)
        sBattlerByTurnOrder[i] = i;

    for (i = 0; i < gBattlersCount - 1; i++)
    {
        for (j = i + 1; j < gBattlersCount; j++)
        {
            if (GetWhoStrikesFirst(sBattlerByTurnOrder[i], sBattlerByTurnOrder[j], TRUE) != 0)
            {
                u8 temp = sBattlerByTurnOrder[i];
                sBattlerByTurnOrder[i] = sBattlerByTurnOrder[j];
                sBattlerByTurnOrder[j] = temp;
            }
        }
    }

    //Mon Icon
    for(i = 0; i < MAX_SPEED_MONS_SHOWN; i++){
        battlertoCheck = sBattlerByTurnOrder[firstMon + i];
        if(IsBattlerAlive(battlertoCheck)){
            ShowSpeciesIconSpeed(battlertoCheck, SPEED_POKEMON_ICON_X, SPEED_POKEMON_ICON_Y + (i * SPEED_POKEMON_SPACE));
        }
    }

    //Title
    x  = 9;
    y  = 0;
    x2 = 0;
    y2 = -4;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Speed_Order);
    x  = 19;
    AddTextPrinterParameterized4(windowId, FONT_SMALL, (x * 8), (y * 8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Controllers);

    //Speed Order
    x  = 13;
    y  = 4;
    x2 = 0;
    y2 = -4;

    for(i = 0; i < MAX_SPEED_MONS_SHOWN; i++){
        battlertoCheck = sBattlerByTurnOrder[firstMon + i];
        if(IsBattlerAlive(battlertoCheck)){
            u8 gender = GetGenderFromSpeciesAndPersonality(gBattleMons[battlertoCheck].species, gBattleMons[battlertoCheck].personality);
            u16 speed = GetBattlerTotalSpeedStat(battlertoCheck, TOTAL_SPEED_FULL);
            species = gBattleMons[battlertoCheck].species;
            target = BATTLE_OPPOSITE(battlertoCheck);
            targetCurrentHp = gBattleMons[target].hp;
            
            //Species Name
            StringCopy(gStringVar1, gSpeciesNames[species]);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
            x = x + 8;

            //Level
            ConvertIntToDecimalStringN(gStringVar1, gBattleMons[battlertoCheck].level, STR_CONV_MODE_LEFT_ALIGN, 3);
            StringExpandPlaceholders(gStringVar4, gText_BattlerLevelString);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
            x = x + 4;

            switch(gender){
                case MON_MALE:
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLUE], 0xFF, gText_MaleSymbol);
                    break;
                case MON_FEMALE:
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_RED], 0xFF, gText_FemaleSymbol);
                    break;
            }
            x = 13;
            y++;
            //Total Stats 9 x 8
            ConvertIntToDecimalStringN(gStringVar1, speed, STR_CONV_MODE_LEFT_ALIGN, 3);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (8 * 8) + 4, (10 * 8) - 4 + (SPEED_POKEMON_SPACE * i), 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
            y = y + 2;

            //Move Names
            for(j = 0; j < MAX_MON_MOVES; j++){
                move = gBattleMons[battlertoCheck].moves[j];
                if(move != MOVE_NONE){
                    StringCopy(gStringVar1, gMoveNames[move]);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
                    x = x + 9;
                    //Priority
                    ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move].priority, STR_CONV_MODE_LEFT_ALIGN, 3);
                    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
                    x = x + 3;
                    x2 = 4;
                    //Can KO - Todo: Check calculation
                    if(gBattleMoves[move].split != SPLIT_STATUS && gBattleMoves[move].power > 0){
                        u8 moveType = gBattleMoves[move].type;
                        SetTypeBeforeUsingMove(move, battlertoCheck);
                        GET_MOVE_TYPE(move, moveType);
                        moveDamage = CalculateMoveDamage(move, battlertoCheck, target, &moveType, 0, FALSE, FALSE, FALSE);
                        if(targetCurrentHp <= moveDamage)
                            BlitBitmapToWindow(windowId, sCheck, (x * 8) + x2, (y * 8), 8, 8);
                    }
                    x = x - 12;
                    x2 = 0;
                    y++;
                }
            }
            y++;
        }
    }

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

static void PrintToWindow(u8 windowId, u8 colorIdx)
{
    const u8 *str = sText_MyMenu;
    u8 i, j;
    u8 x, y, x2, y2;
    u16 species = gBattleMons[sMenuDataPtr->battlerId].species;
    u16 innate1 = gBaseStats[species].innates[0];
    u16 innate2 = gBaseStats[species].innates[1];
    u16 innate3 = gBaseStats[species].innates[2];
    u32 personality = gBattleMons[sMenuDataPtr->battlerId].personality;
    u8 gender = GetGenderFromSpeciesAndPersonality(gBattleMons[sMenuDataPtr->battlerId].species, gBattleMons[sMenuDataPtr->battlerId].personality);
    u8 statStage;
    bool8 statStageUp = FALSE;
    bool8 isEnemyMon = GetBattlerSide(sMenuDataPtr->battlerId) == B_SIDE_OPPONENT;
    u8 move = MOVE_NONE;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    if(!isEnemyMon){ //Enemy Mons have disabled randomized innates/abilies 
        innate1 = RandomizeInnate(gBaseStats[species].innates[0], species, personality);
        innate2 = RandomizeInnate(gBaseStats[species].innates[1], species, personality);
        innate3 = RandomizeInnate(gBaseStats[species].innates[2], species, personality);
    }

    //Title
    x  = 7;
    y  = 2;
    x2 = 0;
    y2 = -4;
    if(isEnemyMon)
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sYourOpponentPokemonData);
    else
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sYourPokemonData);

    //Pokemon Name
    y++;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gSpeciesNames[species]);
    //Pokemon HP
    y++;
    ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].hp, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, gBattleMons[sMenuDataPtr->battlerId].maxHP, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, sText_HP);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
    //Pokemon Gender
    x = 2;
    y = 6;
    switch(gender){
        case MON_MALE:
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLUE], 0xFF, gText_MaleSymbol);
            break;
        case MON_FEMALE:
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[FONT_RED], 0xFF, gText_FemaleSymbol);
            break;
    }

    //Pokemon Level
    x++;
    ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].level, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_NewLevelSymbol);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);

    //Held Item
    x  = 22;
    y  = 3;
    if (gBattleMons[sMenuDataPtr->battlerId].item == ITEM_NONE)
        StringCopy(gStringVar1, sText_None);
    else
        StringCopy(gStringVar1, ItemId_GetName(gBattleMons[sMenuDataPtr->battlerId].item));
    StringExpandPlaceholders(gStringVar4, sText_Held_Item);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);

    //Stats
    x  = 3;
    y  = 7;
    //Attack
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Attack);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].attack, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    y++;
    //Defense
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Defense);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].defense, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    y++;
    //Special Attack
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_SpecialAttack);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].spAttack, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    y++;
    //Special Defense
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_SpecialDefense);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].spDefense, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);
    y++;
    //Speed
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Speed);
	ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].speed, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 3) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar1);

    //Accuracy
    y = y + 2;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Accuracy);
    //Evasion
    y++;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Evasion);

    //Abilitites
    x = 15;
    y = 7;
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Ability);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 5) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gAbilityNames[gBattleMons[sMenuDataPtr->battlerId].ability]);
    y++;
    //Innate 1
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Innate);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 5) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gAbilityNames[innate1]);
    y++;
    //Innate 2
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Innate);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 5) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gAbilityNames[innate2]);
    y++;
    //Innate 3
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Innate);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 5) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gAbilityNames[innate3]);

    //Moves
    y = y+2;
    for(i = 0; i < MAX_MON_MOVES; i++){
        move = gBattleMons[sMenuDataPtr->battlerId].moves[i];
        if(move != MOVE_NONE){
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, (x * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gMoveNames[move]);
            //Current PP
            ConvertIntToDecimalStringN(gStringVar1, gBattleMons[sMenuDataPtr->battlerId].pp[i], STR_CONV_MODE_LEFT_ALIGN, 3); //Current PP
            ConvertIntToDecimalStringN(gStringVar2, gBattleMoves[move].pp, STR_CONV_MODE_LEFT_ALIGN, 3); //Max PP, ToFix
            StringExpandPlaceholders(gStringVar4, sText_PP);
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, ((x + 8) * 8) + x2, (y * 8) + y2, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gStringVar4);
            y++;
        }
    }

    //Stat Drops & Ups
    x = 8;
    y = 7;
    for(i = 0; i < NUM_BATTLE_STATS - 1; i++){
        
        statStage = gBattleMons[sMenuDataPtr->battlerId].statStages[statorder[i + 1]];//HP is not taken into account
        if(statStage != DEFAULT_STAT_STAGE){
            if(statStage > DEFAULT_STAT_STAGE){
                statStageUp = TRUE;
                statStage = statStage - DEFAULT_STAT_STAGE;
            }
            else{
                statStageUp = FALSE;
                statStage = DEFAULT_STAT_STAGE - statStage;
            }

            for(j = 0; j < statStage; j++){
                if(statStageUp)
                    BlitBitmapToWindow(windowId, sStatUpArrow, ((x + j) * 8) + x2, (y * 8), 8, 8);
                else
                    BlitBitmapToWindow(windowId, sStatDownArrow, ((x + j) * 8) + x2, (y * 8), 8, 8);

            }
        }
        if(statorder[i + 1] == STAT_SPEED)
            y = y + 2;
        else
            y++;
    }
    
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

static void Task_MenuWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_MenuMain;
}

static void Task_MenuTurnOff(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}
//Status

static const union AnimCmd sSpriteAnim_StatusPoison[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusParalyzed[] = {
    ANIMCMD_FRAME(4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusSleep[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusFrozen[] = {
    ANIMCMD_FRAME(12, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusBurn[] = {
    ANIMCMD_FRAME(16, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusPokerus[] = {
    ANIMCMD_FRAME(20, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusFaint[] = {
    ANIMCMD_FRAME(24, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusFrostbite[] = {
    ANIMCMD_FRAME(28, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusBleed[] = {
    ANIMCMD_FRAME(32, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd *const sSpriteAnimTable_StatusCondition[] = {
    sSpriteAnim_StatusPoison,
    sSpriteAnim_StatusParalyzed,
    sSpriteAnim_StatusSleep,
    sSpriteAnim_StatusFrozen,
    sSpriteAnim_StatusBurn,
    sSpriteAnim_StatusPokerus,
    sSpriteAnim_StatusFaint,
    sSpriteAnim_StatusFrostbite,
    sSpriteAnim_StatusBleed,
};
static const struct OamData sOamData_StatusCondition =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};
#define TAG_MON_STATUS      30001
static const struct SpriteTemplate sSpriteTemplate_StatusCondition =
{
    .tileTag = TAG_MON_STATUS,
    .paletteTag = TAG_MON_STATUS,
    .oam = &sOamData_StatusCondition,
    .anims = sSpriteAnimTable_StatusCondition,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

#define STATUS_ICON_X (7 * 8)
#define STATUS_ICON_Y (5 * 8)
static void CreateSetStatusSprite(void)
{
    u8 *spriteId = &sMenuDataPtr->spriteIds[SPRITE_ARR_ID_STATUS];
    u8 statusAnim;

    if (*spriteId == SPRITE_NONE)
        *spriteId = CreateSprite(&sSpriteTemplate_StatusCondition, STATUS_ICON_X, STATUS_ICON_Y, 0);

    //statusAnim = gBattleMons[sMenuDataPtr->battlerId].status1;
    statusAnim = sMenuDataPtr->battlerId;
    if (statusAnim != 0)
    {
        StartSpriteAnim(&gSprites[*spriteId], statusAnim - 1);
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, FALSE);
    }
    else
    {
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
    }
}

static u8 DestroyBattleMenuSprite(u8 spriteArrayId)
{
    struct Sprite *sprite = &gSprites[sMenuDataPtr->spriteIds[spriteArrayId]];
    sMenuDataPtr->spriteIds[spriteArrayId] = SPRITE_NONE;
    DestroySpriteAndFreeResources(sprite);
}

static u8 ShowSpeciesIcon(u8 num)
{
	u16 species     = gBattleMons[num].species;
    u16 personality = gBattleMons[num].personality;
	LoadMonIconPalette(species);

    switch(num){
        case 0:
            sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1] = CreateMonIcon(species, SpriteCallbackDummy, POKEMON_ICON_X, POKEMON_ICON_1_Y, 0, personality);
                    
            gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1]].invisible = FALSE;
            return sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1];
        break;
        case 1:
            sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_2] = CreateMonIcon(species, SpriteCallbackDummy, POKEMON_ICON_X, POKEMON_ICON_2_Y, 0, personality);
                    
            gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_2]].invisible = FALSE;
            return sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_2];
        break;
        case 2:
            if(IsDoubleBattle()){
                sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_3] = CreateMonIcon(species, SpriteCallbackDummy, POKEMON_ICON_X, POKEMON_ICON_3_Y, 0, personality);
                        
                gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_3]].invisible = FALSE;
            }
            return sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_3];
        break;
        case 3:
            if(IsDoubleBattle()){
                sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_4] = CreateMonIcon(species, SpriteCallbackDummy, POKEMON_ICON_X, POKEMON_ICON_4_Y, 0, personality);
                        
                gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_4]].invisible = FALSE;
            }
            return sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_4];
        break;
    }
}

static void FreeEveryMonIconSprite(void)
{
    u8 i;
    for (i = 0; i < gBattlersCount; i++)
        FreeSpeciesIconSprite(i);
}

static void FreeSpeciesIconSprite(u8 battler)
{
    u8 *spriteId = &sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1_SPEED + battler];
    if (*spriteId != SPRITE_NONE)
    {
        FreeSpriteTilesByTag(TAG_BATTLER_SPEED   + battler - 1);
        FreeSpritePaletteByTag(TAG_BATTLER_SPEED + battler - 1);
        FreeSpriteOamMatrix(&gSprites[*spriteId]);
        DestroySprite(&gSprites[*spriteId]);
        *spriteId = SPRITE_NONE;
        sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1_SPEED + battler] = SPRITE_NONE;
    }
}

static u8 ShowSpeciesIconSpeed(u8 battler, u8 x, u8 y)
{
	u16 species     = gBattleMons[battler].species;
    u32 personality = gBattleMons[battler].personality;
	LoadMonIconPalette(species);

    switch(battler){
        case 0:
            sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1_SPEED] = CreateMonIcon(species, SpriteCallbackDummy, x, y, 0, personality);
                    
            gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1_SPEED]].invisible = FALSE;
            return sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1_SPEED];
        break;
        case 1:
            sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_2_SPEED] = CreateMonIcon(species, SpriteCallbackDummy, x, y, 0, personality);
                    
            gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_2_SPEED]].invisible = FALSE;
            return sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_2_SPEED];
        break;
        case 2:
            if(IsDoubleBattle()){
                sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_3_SPEED] = CreateMonIcon(species, SpriteCallbackDummy, x, y, 0, personality);
                        
                gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_3_SPEED]].invisible = FALSE;
            }
            return sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_3_SPEED];
        break;
        case 3:
            if(IsDoubleBattle()){
                sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_4_SPEED] = CreateMonIcon(species, SpriteCallbackDummy, x, y, 0, personality);
                        
                gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_4_SPEED]].invisible = FALSE;
            }
            return sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_4_SPEED];
        break;
    }
}

static u8 ShowSpeciesIconParty(u8 num, bool8 isEnemyParty, u8 x, u8 y)
{
    struct Pokemon *party = NULL;
	u16 species;
    u32 personality;

    if(isEnemyParty)
        party = gEnemyParty;
    else
        party = gPlayerParty;

    species     = GetMonData(&party[num], MON_DATA_SPECIES, NULL);
    personality = GetMonData(&party[num], MON_DATA_PERSONALITY, NULL);

	LoadMonIconPalette(species);

    if(species == SPECIES_NONE)
        return 0;

    if(isEnemyParty){
        sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1_PARTY_ENEMY + num] = CreateMonIcon(species, SpriteCallbackDummy, x, y, 0, personality);
                    
        gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1_PARTY_PLAYER]].invisible = FALSE;
        return sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1_PARTY_PLAYER];
    }
    else{
        sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1_PARTY_PLAYER + num] = CreateMonIcon(species, SpriteCallbackDummy, x, y, 0, personality);
                    
        gSprites[sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1_PARTY_PLAYER + num]].invisible = FALSE;
        return sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1_PARTY_PLAYER + num];
    }

}

static void FreeEveryPartyMonIconSprite(void)
{
    u8 i;
    for (i = 0; i < PARTY_SIZE; i++)
        FreePartySpeciesIconSprite(i, FALSE);

    for (i = 0; i < PARTY_SIZE; i++)
        FreePartySpeciesIconSprite(i, TRUE);
}

static void FreePartySpeciesIconSprite(u8 num, bool8 isEnemyMon)
{
    u8 *spriteId;

    if(isEnemyMon)
        spriteId = &sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1_PARTY_ENEMY + num];
    else
        spriteId = &sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1_PARTY_PLAYER + num];

    if (*spriteId != SPRITE_NONE)
    {
        FreeSpriteTilesByTag(TAG_ICON_PARTY_PLAYER   + num - 1);
        FreeSpritePaletteByTag(TAG_ICON_PARTY_PLAYER + num - 1);
        FreeSpriteOamMatrix(&gSprites[*spriteId]);
        DestroySprite(&gSprites[*spriteId]);
        *spriteId = SPRITE_NONE;

        if(isEnemyMon)
            sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1_PARTY_ENEMY + num] = SPRITE_NONE;
        else
            sMenuDataPtr->spriteIds[SPRITE_ARR_ID_MON_ICON_1_PARTY_PLAYER + num] = SPRITE_NONE;
    }
}

// different from pokemon_summary_screen
#define TYPE_ICON_PAL_NUM_0     13
#define TYPE_ICON_PAL_NUM_1     14
#define TYPE_ICON_PAL_NUM_2     15
static const u8 sMoveTypeToOamPaletteNum[NUMBER_OF_MON_TYPES] =
{
    [TYPE_NORMAL] = TYPE_ICON_PAL_NUM_0,
    [TYPE_FIGHTING] = TYPE_ICON_PAL_NUM_0,
    [TYPE_FLYING] = TYPE_ICON_PAL_NUM_1,
    [TYPE_POISON] = TYPE_ICON_PAL_NUM_1,
    [TYPE_GROUND] = TYPE_ICON_PAL_NUM_0,
    [TYPE_ROCK] = TYPE_ICON_PAL_NUM_0,
    [TYPE_BUG] = TYPE_ICON_PAL_NUM_2,
    [TYPE_GHOST] = TYPE_ICON_PAL_NUM_1,
    [TYPE_STEEL] = TYPE_ICON_PAL_NUM_0,
    [TYPE_MYSTERY] = TYPE_ICON_PAL_NUM_2,
    [TYPE_FIRE] = TYPE_ICON_PAL_NUM_0,
    [TYPE_WATER] = TYPE_ICON_PAL_NUM_1,
    [TYPE_GRASS] = TYPE_ICON_PAL_NUM_2,
    [TYPE_ELECTRIC] = TYPE_ICON_PAL_NUM_0,
    [TYPE_PSYCHIC] = TYPE_ICON_PAL_NUM_1,
    [TYPE_ICE] = TYPE_ICON_PAL_NUM_1,
    [TYPE_DRAGON] = TYPE_ICON_PAL_NUM_2,
    [TYPE_DARK] = TYPE_ICON_PAL_NUM_0,
    [TYPE_FAIRY] = TYPE_ICON_PAL_NUM_1,
};

static void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible)
{
    gSprites[sMenuDataPtr->spriteIds[spriteArrayId]].invisible = invisible;
}

static void SetTypeIconSpritePosAndPal(u8 typeId, u8 x, u8 y, u8 spriteArrayId)
{
    struct Sprite *sprite = &gSprites[sMenuDataPtr->spriteIds[spriteArrayId]];
    StartSpriteAnim(sprite, typeId);
    sprite->oam.paletteNum = sMoveTypeToOamPaletteNum[typeId];
    sprite->x = x + 16;
    sprite->y = y + 8;
    SetSpriteInvisibility(spriteArrayId, FALSE);
}
/*
#define TYPE_ICON_Y (5 * 8)
#define TYPE_ICON_1_X (7 * 8)
#define TYPE_ICON_2_X TYPE_ICON_1_X + (4 * 8)
#define TYPE_ICON_3_X TYPE_ICON_2_X + (4 * 8)
static void SetMonTypeIcons(void)
{
    u8 type1 = gBattleMons[sMenuDataPtr->battlerId].type1;
    u8 type2 = gBattleMons[sMenuDataPtr->battlerId].type2;
    u8 type3 = gBattleMons[sMenuDataPtr->battlerId].type3;

    if (type1 != type2)
    {
        SetTypeIconSpritePosAndPal(type1, TYPE_ICON_1_X, TYPE_ICON_Y, SPRITE_ARR_ID_TYPE_1);
        SetTypeIconSpritePosAndPal(type2, TYPE_ICON_2_X, TYPE_ICON_Y, SPRITE_ARR_ID_TYPE_2);
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE_2, FALSE);
    }
    else
    {
        SetTypeIconSpritePosAndPal(type1, TYPE_ICON_1_X, TYPE_ICON_Y, SPRITE_ARR_ID_TYPE_1);
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE_2, TRUE);
    }
}*/

static u8 tabColors[NUM_TABS] = {
    [TAB_STATS]             = MENU_COLOR_BLUE,
    [TAB_ABILITIES]         = MENU_COLOR_RED,
    [TAB_MOVES]             = MENU_COLOR_GREEN,
    [TAB_STATUS]            = MENU_COLOR_YELLOW,
    [TAB_DAMAGE_CALCULATOR] = MENU_COLOR_RED,
};

static u8 tabColorsField[NUM_FIELD_TABS + 2] = {
    [TAB_PARTY]             = MENU_COLOR_YELLOW,
    [TAB_FIELD]             = MENU_COLOR_GREEN,
    [TAB_SPEED]             = MENU_COLOR_BLUE,
    [TAB_PLAYER_SIDE]       = MENU_COLOR_RED,
    [TAB_ENEMY_SIDE]        = MENU_COLOR_YELLOW,
};

static void setBattler(void){
    switch(sMenuDataPtr->modeId){
        case MODE_BATTLER0:
            sMenuDataPtr->battlerId = 0;
        break;
        case MODE_BATTLER1:
            sMenuDataPtr->battlerId = 1;
        break;
        case MODE_BATTLER2:
            sMenuDataPtr->battlerId = 2;
        break;
        case MODE_BATTLER3:
            sMenuDataPtr->battlerId = 3;
        break;
        case MODE_FIELD:
            sMenuDataPtr->battlerId = 0;
        break;
    }
}

static void LoadTabPalette(void){
    if(sMenuDataPtr->modeId == MODE_FIELD){
        switch(tabColorsField[sMenuDataPtr->fieldTabId]){
            case MENU_COLOR_BLUE:
                LoadPalette(sMenuPalette_Blue, 0, 32);
            break;
            case MENU_COLOR_YELLOW:
                LoadPalette(sMenuPalette_Yellow, 0, 32);
            break;
            case MENU_COLOR_RED:
                LoadPalette(sMenuPalette_Red, 0, 32);
            break;
            case MENU_COLOR_GREEN:
                LoadPalette(sMenuPalette_Green, 0, 32);
            break;
            default:
                LoadPalette(sMenuPalette, 0, 32);
            break;
        }
    }
    else{
        switch(tabColors[sMenuDataPtr->tabId]){
            case MENU_COLOR_BLUE:
                LoadPalette(sMenuPalette_Blue, 0, 32);
            break;
            case MENU_COLOR_YELLOW:
                LoadPalette(sMenuPalette_Yellow, 0, 32);
            break;
            case MENU_COLOR_RED:
                LoadPalette(sMenuPalette_Red, 0, 32);
            break;
            case MENU_COLOR_GREEN:
                LoadPalette(sMenuPalette_Green, 0, 32);
            break;
            default:
                LoadPalette(sMenuPalette, 0, 32);
            break;
        }
    }
}

static void PrintPage(void){
    LoadTilemapFromMode();
    LoadTabPalette();
    FreeItemIconSprite();
    FreeEveryMonIconSprite();
    FreeEveryPartyMonIconSprite();
    if(sMenuDataPtr->modeId != MODE_FIELD)
        switch(sMenuDataPtr->tabId){
            case TAB_STATS:
                PrintStatsTab();
            break;
            case TAB_ABILITIES:
                PrintAbilityTab();
            break;
            case TAB_MOVES:
                PrintMoveTab();
            break;
            case TAB_STATUS:
                PrintStatusTab();
            break;
            case TAB_DAMAGE_CALCULATOR:
                PrintDamageCalulatorTab();
            break;
            default:
                PrintStatsTab();
            break;
        }
    else{
        switch(sMenuDataPtr->fieldTabId){
            case TAB_PARTY:
                PrintPartyTab();
            break;
            case TAB_FIELD:
                PrintFieldTab();
            break;
            case TAB_SPEED:
                PrintSpeedTab();
            break;
            case TAB_PLAYER_SIDE:
                PrintSideTab(B_SIDE_PLAYER);
            break;
            case TAB_ENEMY_SIDE:
                PrintSideTab(B_SIDE_OPPONENT);
            break;
        }
    }
}

/* This is the meat of the UI. This is where you wait for player inputs and can branch to other tasks accordingly */
static void Task_MenuMain(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_MenuTurnOff;
    }

    if (JOY_NEW(A_BUTTON))
    {
        if(sMenuDataPtr->modeId != MODE_FIELD){
            switch(sMenuDataPtr->tabId){
                case TAB_MOVES:
                    if(sMenuDataPtr->moveModeId != NUM_MOVE_MODES - 1)
                        sMenuDataPtr->moveModeId++;
                    else
                        sMenuDataPtr->moveModeId = 0;
                    PrintMoveTab();
                break;
                case TAB_DAMAGE_CALCULATOR:
                    if(IsDoubleBattle()){
                        if(sMenuDataPtr->dmgCalculatorTarget != MAX_TARGETS - 1)
                            sMenuDataPtr->dmgCalculatorTarget++;
                        else
                            sMenuDataPtr->dmgCalculatorTarget = 0;
                        PrintDamageCalulatorTab();
                    }
                break;
                case TAB_STATUS:
                    sMenuDataPtr->CurrentStatusInfo[sMenuDataPtr->battlerId] = (sMenuDataPtr->CurrentStatusInfo[sMenuDataPtr->battlerId] + 1) % sMenuDataPtr->numStatusInfo[sMenuDataPtr->battlerId];
                    PrintStatusTab();
                break;
                default:
                    PlaySE(SE_PC_OFF);
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                    gTasks[taskId].func = Task_MenuTurnOff;
                break;
            }

        }
        else{
            switch(sMenuDataPtr->fieldTabId){
                case TAB_PARTY:
                    PrintPartyTab();
                case TAB_FIELD:
                    sMenuDataPtr->currentFieldInfo = (sMenuDataPtr->currentFieldInfo + 1) % sMenuDataPtr->numFields;
                    PrintFieldTab();
                break;
                case TAB_PLAYER_SIDE:
                    sMenuDataPtr->currentSideInfoPlayer = (sMenuDataPtr->currentSideInfoPlayer + 1) % sMenuDataPtr->numSideInfoPlayer;
                    PrintSideTab(B_SIDE_PLAYER);
                break;
                case TAB_ENEMY_SIDE:
                    sMenuDataPtr->currentSideInfoEnemy = (sMenuDataPtr->currentSideInfoEnemy + 1) % sMenuDataPtr->numSideInfoEnemy;
                    PrintSideTab(B_SIDE_OPPONENT);
                break;
                case TAB_SPEED:
                    //Scrolling since we only have 2 spaces, will be changed in the future, lacks ability to change targets
                    if(IsDoubleBattle()){
                        if(sMenuDataPtr->speedModeId != gBattlersCount - 2)
                            sMenuDataPtr->speedModeId++;
                        else
                            sMenuDataPtr->speedModeId = 0;
                        FreeEveryMonIconSprite();
                        PrintSpeedTab();
                    }
                    else{
                        PlaySE(SE_PC_OFF);
                        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                        gTasks[taskId].func = Task_MenuTurnOff;
                    }
                break;
                default:
                    PlaySE(SE_PC_OFF);
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                    gTasks[taskId].func = Task_MenuTurnOff;
                break;
            }
        }
    }

    if (JOY_NEW(DPAD_DOWN)){
        if(IsDoubleBattle()){
            if(sMenuDataPtr->modeId != NUM_MODES - 1)
                sMenuDataPtr->modeId++;
            else
                sMenuDataPtr->modeId = 0;
        }
        else{
            if(sMenuDataPtr->modeId != MODE_BATTLER1)
                sMenuDataPtr->modeId++;
            else
                sMenuDataPtr->modeId = MODE_BATTLER0;
        }
        setBattler();
        PrintPage();
    }

    if (JOY_NEW(DPAD_UP)){
        if(IsDoubleBattle()){
            if(sMenuDataPtr->modeId != 0)
                sMenuDataPtr->modeId--;
            else
                sMenuDataPtr->modeId = NUM_MODES - 1;
        }
        else{
            if(sMenuDataPtr->modeId != MODE_BATTLER0)
                sMenuDataPtr->modeId--;
            else
                sMenuDataPtr->modeId = MODE_BATTLER1;
        }
        setBattler();
        PrintPage();
    }

    if (JOY_NEW(DPAD_LEFT)){
        switch(sMenuDataPtr->modeId){
            case MODE_FIELD:
                if(sMenuDataPtr->fieldTabId != 0)
                    sMenuDataPtr->fieldTabId--;
                else
                    sMenuDataPtr->fieldTabId = NUM_FIELD_TABS - 1;
                PrintPage();
            break;
            default: //Battlers
                if(sMenuDataPtr->tabId != 0)
                    sMenuDataPtr->tabId--;
                else
                    sMenuDataPtr->tabId = NUM_TABS - 1;
                setBattler();
                PrintPage();
            break;
        }
    }

    if (JOY_NEW(DPAD_RIGHT)){
        switch(sMenuDataPtr->modeId){
            case MODE_FIELD:
                if(sMenuDataPtr->fieldTabId != NUM_FIELD_TABS - 1)
                    sMenuDataPtr->fieldTabId++;
                else
                    sMenuDataPtr->fieldTabId = 0;
                PrintPage();
            break;
            default: //Battlers
                if(sMenuDataPtr->tabId != NUM_TABS - 1)
                    sMenuDataPtr->tabId++;
                else
                    sMenuDataPtr->tabId = 0;
                setBattler();
                PrintPage();
            break;
        }
    }
}