#include "global.h"
#include "frontier_util.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "berry.h"
#include "clock.h"
#include "coins.h"
#include "contest.h"
#include "contest_util.h"
#include "contest_painting.h"
#include "data.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "event_data.h"
#include "field_door.h"
#include "field_effect.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "field_message_box.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "field_tasks.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "item.h"
#include "lilycove_lady.h"
#include "main.h"
#include "menu.h"
#include "money.h"
#include "mystery_event_script.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "overworld.h"
#include "rotating_tile_puzzle.h"
#include "rtc.h"
#include "script.h"
#include "script_menu.h"
#include "script_movement.h"
#include "script_pokemon_util.h"
#include "shop.h"
#include "slot_machine.h"
#include "sound.h"
#include "string_util.h"
#include "text.h"
#include "text_window.h"
#include "trainer_see.h"
#include "tv.h"
#include "window.h"
#include "quests.h"
#include "constants/event_objects.h"
#include "constants/items.h"

typedef u16 (*SpecialFunc)(void);
typedef void (*NativeFunc)(void);

EWRAM_DATA const u8 *gRamScriptRetAddr = NULL;
static EWRAM_DATA u32 sAddressOffset = 0; // For relative addressing in vgoto etc., used by saved scripts (e.g. Mystery Event)
static EWRAM_DATA u16 sPauseCounter = 0;
static EWRAM_DATA u16 sMovingNpcId = 0;
static EWRAM_DATA u16 sMovingNpcMapBank = 0;
static EWRAM_DATA u16 sMovingNpcMapId = 0;
static EWRAM_DATA u16 sFieldEffectScriptId = 0;

static u8 gBrailleWindowId;
static bool8 gIsScriptedWildDouble;

extern const SpecialFunc gSpecials[];
extern const u8 *gStdScripts[];
extern const u8 *gStdScripts_End[];

static void CloseBrailleWindow(void);

// This is defined in here so the optimizer can't see its value when compiling
// script.c.
void * const gNullScriptPtr = NULL;

static const u8 sScriptConditionTable[6][3] =
{
//  <  =  >
    1, 0, 0, // <
    0, 1, 0, // =
    0, 0, 1, // >
    1, 1, 0, // <=
    0, 1, 1, // >=
    1, 0, 1, // !=
};

static u8 * const sScriptStringVars[] =
{
    gStringVar1,
    gStringVar2,
    gStringVar3,
    gExtraStringVar1,
    gExtraStringVar2,
    gExtraStringVar3,
};

bool8 ScrCmd_nop(struct ScriptContext *ctx)
{
    return FALSE;
}

bool8 ScrCmd_nop1(struct ScriptContext *ctx)
{
    return FALSE;
}

bool8 ScrCmd_end(struct ScriptContext *ctx)
{
    StopScript(ctx);
    return FALSE;
}

bool8 ScrCmd_gotonative(struct ScriptContext *ctx)
{
    bool8 (*addr)(void) = (bool8 (*)(void))ScriptReadWord(ctx);

    SetupNativeScript(ctx, addr);
    return TRUE;
}

bool8 ScrCmd_special(struct ScriptContext *ctx)
{
    u16 index = ScriptReadHalfword(ctx);

    gSpecials[index]();
    return FALSE;
}

bool8 ScrCmd_specialvar(struct ScriptContext *ctx)
{
    u16 *var = GetVarPointer(ScriptReadHalfword(ctx));

    *var = gSpecials[ScriptReadHalfword(ctx)]();
    return FALSE;
}

bool8 ScrCmd_callnative(struct ScriptContext *ctx)
{
    NativeFunc func = (NativeFunc)ScriptReadWord(ctx);

    func();
    return FALSE;
}

bool8 ScrCmd_waitstate(struct ScriptContext *ctx)
{
    ScriptContext1_Stop();
    return TRUE;
}

bool8 ScrCmd_goto(struct ScriptContext *ctx)
{
    const u8 *ptr = (const u8 *)ScriptReadWord(ctx);

    ScriptJump(ctx, ptr);
    return FALSE;
}

bool8 ScrCmd_return(struct ScriptContext *ctx)
{
    ScriptReturn(ctx);
    return FALSE;
}

bool8 ScrCmd_call(struct ScriptContext *ctx)
{
    const u8 *ptr = (const u8 *)ScriptReadWord(ctx);

    ScriptCall(ctx, ptr);
    return FALSE;
}

bool8 ScrCmd_goto_if(struct ScriptContext *ctx)
{
    u8 condition = ScriptReadByte(ctx);
    const u8 *ptr = (const u8 *)ScriptReadWord(ctx);

    if (sScriptConditionTable[condition][ctx->comparisonResult] == 1)
        ScriptJump(ctx, ptr);
    return FALSE;
}

bool8 ScrCmd_call_if(struct ScriptContext *ctx)
{
    u8 condition = ScriptReadByte(ctx);
    const u8 *ptr = (const u8 *)ScriptReadWord(ctx);

    if (sScriptConditionTable[condition][ctx->comparisonResult] == 1)
        ScriptCall(ctx, ptr);
    return FALSE;
}

bool8 ScrCmd_setvaddress(struct ScriptContext *ctx)
{
    u32 addr1 = (u32)ctx->scriptPtr - 1;
    u32 addr2 = ScriptReadWord(ctx);

    sAddressOffset = addr2 - addr1;
    return FALSE;
}

bool8 ScrCmd_vgoto(struct ScriptContext *ctx)
{
    u32 addr = ScriptReadWord(ctx);

    ScriptJump(ctx, (u8 *)(addr - sAddressOffset));
    return FALSE;
}

bool8 ScrCmd_vcall(struct ScriptContext *ctx)
{
    u32 addr = ScriptReadWord(ctx);

    ScriptCall(ctx, (u8 *)(addr - sAddressOffset));
    return FALSE;
}

bool8 ScrCmd_vgoto_if(struct ScriptContext *ctx)
{
    u8 condition = ScriptReadByte(ctx);
    const u8 *ptr = (const u8 *)(ScriptReadWord(ctx) - sAddressOffset);

    if (sScriptConditionTable[condition][ctx->comparisonResult] == 1)
        ScriptJump(ctx, ptr);
    return FALSE;
}

bool8 ScrCmd_vcall_if(struct ScriptContext *ctx)
{
    u8 condition = ScriptReadByte(ctx);
    const u8 *ptr = (const u8 *)(ScriptReadWord(ctx) - sAddressOffset);

    if (sScriptConditionTable[condition][ctx->comparisonResult] == 1)
        ScriptCall(ctx, ptr);
    return FALSE;
}

bool8 ScrCmd_gotostd(struct ScriptContext *ctx)
{
    u8 index = ScriptReadByte(ctx);
    const u8 **ptr = &gStdScripts[index];

    if (ptr < gStdScripts_End)
        ScriptJump(ctx, *ptr);
    return FALSE;
}

bool8 ScrCmd_callstd(struct ScriptContext *ctx)
{
    u8 index = ScriptReadByte(ctx);
    const u8 **ptr = &gStdScripts[index];

    if (ptr < gStdScripts_End)
        ScriptCall(ctx, *ptr);
    return FALSE;
}

bool8 ScrCmd_gotostd_if(struct ScriptContext *ctx)
{
    u8 condition = ScriptReadByte(ctx);
    u8 index = ScriptReadByte(ctx);

    if (sScriptConditionTable[condition][ctx->comparisonResult] == 1)
    {
        const u8 **ptr = &gStdScripts[index];
        if (ptr < gStdScripts_End)
            ScriptJump(ctx, *ptr);
    }
    return FALSE;
}

bool8 ScrCmd_callstd_if(struct ScriptContext *ctx)
{
    u8 condition = ScriptReadByte(ctx);
    u8 index = ScriptReadByte(ctx);

    if (sScriptConditionTable[condition][ctx->comparisonResult] == 1)
    {
        const u8 **ptr = &gStdScripts[index];
        if (ptr < gStdScripts_End)
            ScriptCall(ctx, *ptr);
    }
    return FALSE;
}

bool8 ScrCmd_returnram(struct ScriptContext *ctx)
{
    ScriptJump(ctx, gRamScriptRetAddr);
    return FALSE;
}

bool8 ScrCmd_killscript(struct ScriptContext *ctx)
{
    ClearRamScript();
    StopScript(ctx);
    return TRUE;
}

bool8 ScrCmd_setmysteryeventstatus(struct ScriptContext *ctx)
{
    u8 value = ScriptReadByte(ctx);

    SetMysteryEventScriptStatus(value);
    return FALSE;
}

bool8 ScrCmd_loadword(struct ScriptContext *ctx)
{
    u8 index = ScriptReadByte(ctx);

    ctx->data[index] = ScriptReadWord(ctx);
    return FALSE;
}

bool8 ScrCmd_loadbytefromaddr(struct ScriptContext *ctx)
{
    u8 index = ScriptReadByte(ctx);

    ctx->data[index] = *(const u8 *)ScriptReadWord(ctx);
    return FALSE;
}

bool8 ScrCmd_writebytetoaddr(struct ScriptContext *ctx)
{
    u8 value = ScriptReadByte(ctx);

    *(u8 *)ScriptReadWord(ctx) = value;
    return FALSE;
}

bool8 ScrCmd_loadbyte(struct ScriptContext *ctx)
{
    u8 index = ScriptReadByte(ctx);

    ctx->data[index] = ScriptReadByte(ctx);
    return FALSE;
}

bool8 ScrCmd_setptrbyte(struct ScriptContext *ctx)
{
    u8 index = ScriptReadByte(ctx);

    *(u8 *)ScriptReadWord(ctx) = ctx->data[index];
    return FALSE;
}

bool8 ScrCmd_copylocal(struct ScriptContext *ctx)
{
    u8 destIndex = ScriptReadByte(ctx);
    u8 srcIndex = ScriptReadByte(ctx);

    ctx->data[destIndex] = ctx->data[srcIndex];
    return FALSE;
}

bool8 ScrCmd_copybyte(struct ScriptContext *ctx)
{
    u8 *ptr = (u8 *)ScriptReadWord(ctx);
    *ptr = *(const u8 *)ScriptReadWord(ctx);
    return FALSE;
}

bool8 ScrCmd_setvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(ScriptReadHalfword(ctx));
    *ptr = ScriptReadHalfword(ctx);
    return FALSE;
}

bool8 ScrCmd_copyvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(ScriptReadHalfword(ctx));
    *ptr = *GetVarPointer(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 ScrCmd_setorcopyvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(ScriptReadHalfword(ctx));
    *ptr = VarGet(ScriptReadHalfword(ctx));
    return FALSE;
}

u8 Compare(u16 a, u16 b)
{
    if (a < b)
        return 0;
    if (a == b)
        return 1;
    return 2;
}

bool8 ScrCmd_compare_local_to_local(struct ScriptContext *ctx)
{
    const u8 value1 = ctx->data[ScriptReadByte(ctx)];
    const u8 value2 = ctx->data[ScriptReadByte(ctx)];

    ctx->comparisonResult = Compare(value1, value2);
    return FALSE;
}

bool8 ScrCmd_compare_local_to_value(struct ScriptContext *ctx)
{
    const u8 value1 = ctx->data[ScriptReadByte(ctx)];
    const u8 value2 = ScriptReadByte(ctx);

    ctx->comparisonResult = Compare(value1, value2);
    return FALSE;
}

bool8 ScrCmd_compare_local_to_addr(struct ScriptContext *ctx)
{
    const u8 value1 = ctx->data[ScriptReadByte(ctx)];
    const u8 value2 = *(const u8 *)ScriptReadWord(ctx);

    ctx->comparisonResult = Compare(value1, value2);
    return FALSE;
}

bool8 ScrCmd_compare_addr_to_local(struct ScriptContext *ctx)
{
    const u8 value1 = *(const u8 *)ScriptReadWord(ctx);
    const u8 value2 = ctx->data[ScriptReadByte(ctx)];

    ctx->comparisonResult = Compare(value1, value2);
    return FALSE;
}

bool8 ScrCmd_compare_addr_to_value(struct ScriptContext *ctx)
{
    const u8 value1 = *(const u8 *)ScriptReadWord(ctx);
    const u8 value2 = ScriptReadByte(ctx);

    ctx->comparisonResult = Compare(value1, value2);
    return FALSE;
}

bool8 ScrCmd_compare_addr_to_addr(struct ScriptContext *ctx)
{
    const u8 value1 = *(const u8 *)ScriptReadWord(ctx);
    const u8 value2 = *(const u8 *)ScriptReadWord(ctx);

    ctx->comparisonResult = Compare(value1, value2);
    return FALSE;
}

bool8 ScrCmd_compare_var_to_value(struct ScriptContext *ctx)
{
    const u16 value1 = *GetVarPointer(ScriptReadHalfword(ctx));
    const u16 value2 = ScriptReadHalfword(ctx);

    ctx->comparisonResult = Compare(value1, value2);
    return FALSE;
}

bool8 ScrCmd_compare_var_to_var(struct ScriptContext *ctx)
{
    const u16 *ptr1 = GetVarPointer(ScriptReadHalfword(ctx));
    const u16 *ptr2 = GetVarPointer(ScriptReadHalfword(ctx));

    ctx->comparisonResult = Compare(*ptr1, *ptr2);
    return FALSE;
}

// Note: addvar doesn't support adding from a variable in vanilla. If you were to 
// add a VarGet() to the above, make sure you change the `addvar VAR_*, -1`
// in the contest scripts to `subvar VAR_*, 1`, else contests will break.
bool8 ScrCmd_addvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(ScriptReadHalfword(ctx));
    *ptr += ScriptReadHalfword(ctx);
    return FALSE;
}

bool8 ScrCmd_subvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(ScriptReadHalfword(ctx));
    *ptr -= VarGet(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 ScrCmd_random(struct ScriptContext *ctx)
{
    u16 max = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = Random() % max;
    return FALSE;
}

bool8 ScrCmd_additem(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(ScriptReadHalfword(ctx));
    u32 quantity = VarGet(ScriptReadHalfword(ctx));

    if(AddBagItem(itemId, (u16)quantity)){
        gSpecialVar_Result = 1; //Bag
    }
    else if(AddPCItem(itemId, (u16)quantity)){
        gSpecialVar_Result = 2; //PC
    }
    else{
        gSpecialVar_Result = 0; //Failed
    }

    return FALSE;
}

bool8 ScrCmd_removeitem(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(ScriptReadHalfword(ctx));
    u32 quantity = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = RemoveBagItem(itemId, (u8)quantity);
    return FALSE;
}

bool8 ScrCmd_checkitemspace(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(ScriptReadHalfword(ctx));
    u32 quantity = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = CheckBagHasSpace(itemId, (u8)quantity);
    return FALSE;
}

bool8 ScrCmd_checkitem(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(ScriptReadHalfword(ctx));
    u32 quantity = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = CheckBagHasItem(itemId, (u16)quantity);
    return FALSE;
}

bool8 ScrCmd_checkitemtype(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = GetPocketByItemId(itemId);
    return FALSE;
}

bool8 ScrCmd_addpcitem(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(ScriptReadHalfword(ctx));
    u16 quantity = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = AddPCItem(itemId, quantity);
    return FALSE;
}

bool8 ScrCmd_checkpcitem(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(ScriptReadHalfword(ctx));
    u16 quantity = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = CheckPCHasItem(itemId, quantity);
    return FALSE;
}

bool8 ScrCmd_adddecoration(struct ScriptContext *ctx)
{
    u32 decorId = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = DecorationAdd(decorId);
    return FALSE;
}

bool8 ScrCmd_removedecoration(struct ScriptContext *ctx)
{
    u32 decorId = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = DecorationRemove(decorId);
    return FALSE;
}

bool8 ScrCmd_checkdecorspace(struct ScriptContext *ctx)
{
    u32 decorId = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = DecorationCheckSpace(decorId);
    return FALSE;
}

bool8 ScrCmd_checkdecor(struct ScriptContext *ctx)
{
    u32 decorId = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = CheckHasDecoration(decorId);
    return FALSE;
}

bool8 ScrCmd_setflag(struct ScriptContext *ctx)
{
    FlagSet(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 ScrCmd_clearflag(struct ScriptContext *ctx)
{
    FlagClear(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 ScrCmd_checkflag(struct ScriptContext *ctx)
{
    ctx->comparisonResult = FlagGet(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 ScrCmd_incrementgamestat(struct ScriptContext *ctx)
{
    IncrementGameStat(ScriptReadByte(ctx));
    return FALSE;
}

bool8 ScrCmd_animateflash(struct ScriptContext *ctx)
{
    AnimateFlash(ScriptReadByte(ctx));
    ScriptContext1_Stop();
    return TRUE;
}

bool8 ScrCmd_setflashradius(struct ScriptContext *ctx)
{
    u16 flashLevel = VarGet(ScriptReadHalfword(ctx));

    Overworld_SetFlashLevel(flashLevel);
    return FALSE;
}

static bool8 IsPaletteNotActive(void)
{
    if (!gPaletteFade.active)
        return TRUE;
    else
        return FALSE;
}

bool8 ScrCmd_fadescreen(struct ScriptContext *ctx)
{
    FadeScreen(ScriptReadByte(ctx), 0);
    SetupNativeScript(ctx, IsPaletteNotActive);
    return TRUE;
}

bool8 ScrCmd_fadescreenspeed(struct ScriptContext *ctx)
{
    u8 mode = ScriptReadByte(ctx);
    u8 speed = ScriptReadByte(ctx);

    FadeScreen(mode, speed);
    SetupNativeScript(ctx, IsPaletteNotActive);
    return TRUE;
}

bool8 ScrCmd_fadescreenswapbuffers(struct ScriptContext *ctx)
{
    u8 mode = ScriptReadByte(ctx);

    switch (mode)
    {
        case FADE_TO_BLACK:
        case FADE_TO_WHITE:   
        default:
            CpuCopy32(gPlttBufferUnfaded, gPaletteDecompressionBuffer, PLTT_DECOMP_BUFFER_SIZE);
            FadeScreen(mode, 0);
            break;
        case FADE_FROM_BLACK:
        case FADE_FROM_WHITE:
            CpuCopy32(gPaletteDecompressionBuffer, gPlttBufferUnfaded, PLTT_DECOMP_BUFFER_SIZE);
            FadeScreen(mode, 0);
            break;
    }

    SetupNativeScript(ctx, IsPaletteNotActive);
    return TRUE;
}

static bool8 RunPauseTimer(void)
{
    sPauseCounter--;

    if (sPauseCounter == 0)
        return TRUE;
    else
        return FALSE;
}

bool8 ScrCmd_delay(struct ScriptContext *ctx)
{
    sPauseCounter = ScriptReadHalfword(ctx);
    SetupNativeScript(ctx, RunPauseTimer);
    return TRUE;
}

bool8 ScrCmd_initclock(struct ScriptContext *ctx)
{
    u8 hour = VarGet(ScriptReadHalfword(ctx));
    u8 minute = VarGet(ScriptReadHalfword(ctx));

    RtcInitLocalTimeOffset(hour, minute);
    return FALSE;
}

bool8 ScrCmd_dotimebasedevents(struct ScriptContext *ctx)
{
    DoTimeBasedEvents();
    return FALSE;
}

bool8 ScrCmd_gettime(struct ScriptContext *ctx)
{
    RtcCalcLocalTime();
    gSpecialVar_0x8000 = gLocalTime.hours;
    gSpecialVar_0x8001 = gLocalTime.minutes;
    gSpecialVar_0x8002 = gLocalTime.seconds;
    return FALSE;
}

bool8 ScrCmd_setweather(struct ScriptContext *ctx)
{
    u16 weather = VarGet(ScriptReadHalfword(ctx));

    SetSav1Weather(weather);
    return FALSE;
}

bool8 ScrCmd_resetweather(struct ScriptContext *ctx)
{
    SetSav1WeatherFromCurrMapHeader();
    return FALSE;
}

bool8 ScrCmd_doweather(struct ScriptContext *ctx)
{
    DoCurrentWeather();
    return FALSE;
}

bool8 ScrCmd_setstepcallback(struct ScriptContext *ctx)
{
    ActivatePerStepCallback(ScriptReadByte(ctx));
    return FALSE;
}

bool8 ScrCmd_setmaplayoutindex(struct ScriptContext *ctx)
{
    u16 value = VarGet(ScriptReadHalfword(ctx));

    SetCurrentMapLayout(value);
    return FALSE;
}

bool8 ScrCmd_warp(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    DoWarp();
    ResetInitialPlayerAvatarState();
    return TRUE;
}

bool8 ScrCmd_warpsilent(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    DoDiveWarp();
    ResetInitialPlayerAvatarState();
    return TRUE;
}

bool8 ScrCmd_warpdoor(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    DoDoorWarp();
    ResetInitialPlayerAvatarState();
    return TRUE;
}

bool8 ScrCmd_warphole(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u16 x;
    u16 y;

    PlayerGetDestCoords(&x, &y);
    if (mapGroup == 0xFF && mapNum == 0xFF)
        SetWarpDestinationToFixedHoleWarp(x - 7, y - 7);
    else
        SetWarpDestination(mapGroup, mapNum, -1, x - 7, y - 7);
    DoFallWarp();
    ResetInitialPlayerAvatarState();
    return TRUE;
}

// RS mossdeep gym warp, unused in Emerald
bool8 ScrCmd_warpteleport(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    DoTeleportTileWarp();
    ResetInitialPlayerAvatarState();
    return TRUE;
}

bool8 ScrCmd_warpmossdeepgym(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    DoMossdeepGymWarp();
    ResetInitialPlayerAvatarState();
    return TRUE;
}

bool8 ScrCmd_setwarp(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    return FALSE;
}

bool8 ScrCmd_setdynamicwarp(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetDynamicWarpWithCoords(0, mapGroup, mapNum, warpId, x, y);
    return FALSE;
}

bool8 ScrCmd_setdivewarp(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetFixedDiveWarp(mapGroup, mapNum, warpId, x, y);
    return FALSE;
}

bool8 ScrCmd_setholewarp(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetFixedHoleWarp(mapGroup, mapNum, warpId, x, y);
    return FALSE;
}

bool8 ScrCmd_setescapewarp(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetEscapeWarp(mapGroup, mapNum, warpId, x, y);
    return FALSE;
}

bool8 ScrCmd_getplayerxy(struct ScriptContext *ctx)
{
    u16 *pX = GetVarPointer(ScriptReadHalfword(ctx));
    u16 *pY = GetVarPointer(ScriptReadHalfword(ctx));

    *pX = gSaveBlock1Ptr->pos.x;
    *pY = gSaveBlock1Ptr->pos.y;
    return FALSE;
}

bool8 ScrCmd_getpartysize(struct ScriptContext *ctx)
{
    gSpecialVar_Result = CalculatePlayerPartyCount();
    return FALSE;
}

bool8 ScrCmd_playse(struct ScriptContext *ctx)
{
    PlaySE(ScriptReadHalfword(ctx));
    return FALSE;
}

static bool8 WaitForSoundEffectFinish(void)
{
    if (!IsSEPlaying())
        return TRUE;
    else
        return FALSE;
}

bool8 ScrCmd_waitse(struct ScriptContext *ctx)
{
    SetupNativeScript(ctx, WaitForSoundEffectFinish);
    return TRUE;
}

bool8 ScrCmd_playfanfare(struct ScriptContext *ctx)
{
    PlayFanfare(ScriptReadHalfword(ctx));
    return FALSE;
}

static bool8 WaitForFanfareFinish(void)
{
    return IsFanfareTaskInactive();
}

bool8 ScrCmd_waitfanfare(struct ScriptContext *ctx)
{
    SetupNativeScript(ctx, WaitForFanfareFinish);
    return TRUE;
}

bool8 ScrCmd_playbgm(struct ScriptContext *ctx)
{
    u16 songId = ScriptReadHalfword(ctx);
    bool8 val = ScriptReadByte(ctx);

    if (val == TRUE)
        Overworld_SetSavedMusic(songId);
    PlayNewMapMusic(songId);
    return FALSE;
}

bool8 ScrCmd_savebgm(struct ScriptContext *ctx)
{
    Overworld_SetSavedMusic(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 ScrCmd_fadedefaultbgm(struct ScriptContext *ctx)
{
    Overworld_ChangeMusicToDefault();
    return FALSE;
}

bool8 ScrCmd_fadenewbgm(struct ScriptContext *ctx)
{
    Overworld_ChangeMusicTo(ScriptReadHalfword(ctx));
    return FALSE;
}

bool8 ScrCmd_fadeoutbgm(struct ScriptContext *ctx)
{
    u8 speed = ScriptReadByte(ctx);

    if (speed != 0)
        FadeOutBGMTemporarily(4 * speed);
    else
        FadeOutBGMTemporarily(4);
    SetupNativeScript(ctx, IsBGMPausedOrStopped);
    return TRUE;
}

bool8 ScrCmd_fadeinbgm(struct ScriptContext *ctx)
{
    u8 speed = ScriptReadByte(ctx);

    if (speed != 0)
        FadeInBGM(4 * speed);
    else
        FadeInBGM(4);
    return FALSE;
}

bool8 ScrCmd_applymovement(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    const void *movementScript = (const void *)ScriptReadWord(ctx);

    ScriptMovement_StartObjectMovementScript(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, movementScript);
    sMovingNpcId = localId;
    return FALSE;
}

bool8 ScrCmd_applymovement_at(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    const void *movementScript = (const void *)ScriptReadWord(ctx);
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);

    ScriptMovement_StartObjectMovementScript(localId, mapNum, mapGroup, movementScript);
    sMovingNpcId = localId;
    return FALSE;
}

static bool8 WaitForMovementFinish(void)
{
    return ScriptMovement_IsObjectMovementFinished(sMovingNpcId, sMovingNpcMapId, sMovingNpcMapBank);
}

bool8 ScrCmd_waitmovement(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));

    if (localId != 0)
        sMovingNpcId = localId;
    sMovingNpcMapBank = gSaveBlock1Ptr->location.mapGroup;
    sMovingNpcMapId = gSaveBlock1Ptr->location.mapNum;
    SetupNativeScript(ctx, WaitForMovementFinish);
    return TRUE;
}

bool8 ScrCmd_waitmovement_at(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    u8 mapBank;
    u8 mapId;

    if (localId != 0)
        sMovingNpcId = localId;
    mapBank = ScriptReadByte(ctx);
    mapId = ScriptReadByte(ctx);
    sMovingNpcMapBank = mapBank;
    sMovingNpcMapId = mapId;
    SetupNativeScript(ctx, WaitForMovementFinish);
    return TRUE;
}

bool8 ScrCmd_removeobject(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));

    RemoveObjectEventByLocalIdAndMap(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    return FALSE;
}

bool8 ScrCmd_removeobject_at(struct ScriptContext *ctx)
{
    u16 objectId = VarGet(ScriptReadHalfword(ctx));
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);

    RemoveObjectEventByLocalIdAndMap(objectId, mapNum, mapGroup);
    return FALSE;
}

bool8 ScrCmd_addobject(struct ScriptContext *ctx)
{
    u16 objectId = VarGet(ScriptReadHalfword(ctx));

    TrySpawnObjectEvent(objectId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    return FALSE;
}

bool8 ScrCmd_addobject_at(struct ScriptContext *ctx)
{
    u16 objectId = VarGet(ScriptReadHalfword(ctx));
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);

    TrySpawnObjectEvent(objectId, mapNum, mapGroup);
    return FALSE;
}

bool8 ScrCmd_setobjectxy(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    TryMoveObjectEventToMapCoords(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, x, y);
    return FALSE;
}

bool8 ScrCmd_setobjectxyperm(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    Overworld_SetObjEventTemplateCoords(localId, x, y);
    return FALSE;
}

bool8 ScrCmd_copyobjectxytoperm(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));

    TryOverrideObjectEventTemplateCoords(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    return FALSE;
}

bool8 ScrCmd_showobject_at(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);

    SetObjectInvisibility(localId, mapNum, mapGroup, FALSE);
    return FALSE;
}

bool8 ScrCmd_hideobject_at(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);

    SetObjectInvisibility(localId, mapNum, mapGroup, TRUE);
    return FALSE;
}

bool8 ScrCmd_setobjectpriority(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 priority = ScriptReadByte(ctx);

    SetObjectPriority(localId, mapNum, mapGroup, priority + 83);
    return FALSE;
}

bool8 ScrCmd_resetobjectpriority(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);

    ResetObjectPriority(localId, mapNum, mapGroup);
    return FALSE;
}

bool8 ScrCmd_faceplayer(struct ScriptContext *ctx)
{
    if (gObjectEvents[gSelectedObjectEvent].active)
    {
        ObjectEventFaceOppositeDirection(&gObjectEvents[gSelectedObjectEvent],
          GetPlayerFacingDirection());
    }
    return FALSE;
}

bool8 ScrCmd_turnobject(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    u8 direction = ScriptReadByte(ctx);

    ObjectEventTurnByLocalIdAndMap(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, direction);
    return FALSE;
}

bool8 ScrCmd_setobjectmovementtype(struct ScriptContext *ctx)
{
    u16 localId = VarGet(ScriptReadHalfword(ctx));
    u8 movementType = ScriptReadByte(ctx);

    Overworld_SetObjEventTemplateMovementType(localId, movementType);
    return FALSE;
}

bool8 ScrCmd_createvobject(struct ScriptContext *ctx)
{
    u16 graphicsId = ScriptReadHalfword(ctx);
    u8 objectEventId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u32 y = VarGet(ScriptReadHalfword(ctx));
    u8 elevation = ScriptReadByte(ctx);
    u8 direction = ScriptReadByte(ctx);

    CreateObjectSprite(graphicsId, objectEventId, x, y, elevation, direction);
    return FALSE;
}

bool8 ScrCmd_turnvobject(struct ScriptContext *ctx)
{
    u8 objectEventId = ScriptReadByte(ctx);
    u8 direction = ScriptReadByte(ctx);

    TurnObjectEventSprite(objectEventId, direction);
    return FALSE;
}

// lockall freezes all object events except the player immediately.
// The player is frozen after waiting for their current movement to finish.
bool8 ScrCmd_lockall(struct ScriptContext *ctx)
{
    if (IsUpdateLinkStateCBActive())
    {
        return FALSE;
    }
    else
    {
        FreezeObjects_WaitForPlayer();
        SetupNativeScript(ctx, IsFreezePlayerFinished);
        return TRUE;
    }
}

// lock freezes all object events except the player and the selected object immediately.
// The player and selected object are frozen after waiting for their current movement to finish.
bool8 ScrCmd_lock(struct ScriptContext *ctx)
{
    if (IsUpdateLinkStateCBActive())
    {
        return FALSE;
    }
    else
    {
        if (gObjectEvents[gSelectedObjectEvent].active)
        {
            FreezeObjects_WaitForPlayerAndSelected();
            SetupNativeScript(ctx, IsFreezeSelectedObjectAndPlayerFinished);
        }
        else
        {
            FreezeObjects_WaitForPlayer();
            SetupNativeScript(ctx, IsFreezePlayerFinished);
        }
        return TRUE;
    }
}

bool8 ScrCmd_releaseall(struct ScriptContext *ctx)
{
    u8 playerObjectId;

    HideFieldMessageBox();
    playerObjectId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
    ObjectEventClearHeldMovementIfFinished(&gObjectEvents[playerObjectId]);
    ScriptMovement_UnfreezeObjectEvents();
    UnfreezeObjectEvents();
    return FALSE;
}

bool8 ScrCmd_release(struct ScriptContext *ctx)
{
    u8 playerObjectId;

    HideFieldMessageBox();
    if (gObjectEvents[gSelectedObjectEvent].active)
        ObjectEventClearHeldMovementIfFinished(&gObjectEvents[gSelectedObjectEvent]);
    playerObjectId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
    ObjectEventClearHeldMovementIfFinished(&gObjectEvents[playerObjectId]);
    ScriptMovement_UnfreezeObjectEvents();
    UnfreezeObjectEvents();
    return FALSE;
}

bool8 ScrCmd_message(struct ScriptContext *ctx)
{
    const u8 *msg = (const u8 *)ScriptReadWord(ctx);

    if (msg == NULL)
        msg = (const u8 *)ctx->data[0];
    ShowFieldMessage(msg);
    return FALSE;
}

bool8 ScrCmd_pokenavcall(struct ScriptContext *ctx)
{
    const u8 *msg = (const u8 *)ScriptReadWord(ctx);

    if (msg == NULL)
        msg = (const u8 *)ctx->data[0];
    ShowPokenavFieldMessage(msg);
    return FALSE;
}

bool8 ScrCmd_messageautoscroll(struct ScriptContext *ctx)
{
    const u8 *msg = (const u8 *)ScriptReadWord(ctx);

    if (msg == NULL)
        msg = (const u8 *)ctx->data[0];
    gTextFlags.autoScroll = TRUE;
    gTextFlags.forceMidTextSpeed = TRUE;
    ShowFieldAutoScrollMessage(msg);
    return FALSE;
}

// Prints all at once. Skips waiting for player input. Only used by link contests
bool8 ScrCmd_messageinstant(struct ScriptContext *ctx)
{
    const u8 *msg = (const u8 *)ScriptReadWord(ctx);

    if (msg == NULL)
        msg = (const u8 *)ctx->data[0];
    LoadMessageBoxAndBorderGfx();
    DrawDialogueFrame(0, 1);
    AddTextPrinterParameterized(0, 1, msg, 0, 1, 0, 0);
    return FALSE;
}

bool8 ScrCmd_waitmessage(struct ScriptContext *ctx)
{
    SetupNativeScript(ctx, IsFieldMessageBoxHidden);
    return TRUE;
}

bool8 ScrCmd_closemessage(struct ScriptContext *ctx)
{
    HideFieldMessageBox();
    return FALSE;
}

static bool8 WaitForAorBPress(void)
{
    if (JOY_NEW(A_BUTTON))
        return TRUE;
    if (JOY_NEW(B_BUTTON))
        return TRUE;
    return FALSE;
}

bool8 ScrCmd_waitbuttonpress(struct ScriptContext *ctx)
{
    SetupNativeScript(ctx, WaitForAorBPress);
    return TRUE;
}

bool8 ScrCmd_yesnobox(struct ScriptContext *ctx)
{
    u8 left = ScriptReadByte(ctx);
    u8 top = ScriptReadByte(ctx);

    if (ScriptMenu_YesNo(left, top) == TRUE)
    {
        ScriptContext1_Stop();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 ScrCmd_multichoice(struct ScriptContext *ctx)
{
    u8 left = ScriptReadByte(ctx);
    u8 top = ScriptReadByte(ctx);
    u8 multichoiceId = ScriptReadByte(ctx);
    bool8 ignoreBPress = ScriptReadByte(ctx);

    if (ScriptMenu_Multichoice(left, top, multichoiceId, ignoreBPress) == TRUE)
    {
        ScriptContext1_Stop();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 ScrCmd_multichoicedefault(struct ScriptContext *ctx)
{
    u8 left = ScriptReadByte(ctx);
    u8 top = ScriptReadByte(ctx);
    u8 multichoiceId = ScriptReadByte(ctx);
    u8 defaultChoice = ScriptReadByte(ctx);
    bool8 ignoreBPress = ScriptReadByte(ctx);

    if (ScriptMenu_MultichoiceWithDefault(left, top, multichoiceId, ignoreBPress, defaultChoice) == TRUE)
    {
        ScriptContext1_Stop();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 ScrCmd_drawbox(struct ScriptContext *ctx)
{
    /*u8 left = ScriptReadByte(ctx);
    u8 top = ScriptReadByte(ctx);
    u8 right = ScriptReadByte(ctx);
    u8 bottom = ScriptReadByte(ctx);

    MenuDrawTextWindow(left, top, right, bottom);*/
    return FALSE;
}

bool8 ScrCmd_multichoicegrid(struct ScriptContext *ctx)
{
    u8 left = ScriptReadByte(ctx);
    u8 top = ScriptReadByte(ctx);
    u8 multichoiceId = ScriptReadByte(ctx);
    u8 numColumns = ScriptReadByte(ctx);
    bool8 ignoreBPress = ScriptReadByte(ctx);

    if (ScriptMenu_MultichoiceGrid(left, top, multichoiceId, ignoreBPress, numColumns) == TRUE)
    {
        ScriptContext1_Stop();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 ScrCmd_erasebox(struct ScriptContext *ctx)
{
    u8 left = ScriptReadByte(ctx);
    u8 top = ScriptReadByte(ctx);
    u8 right = ScriptReadByte(ctx);
    u8 bottom = ScriptReadByte(ctx);

    // Menu_EraseWindowRect(left, top, right, bottom);
    return FALSE;
}

bool8 ScrCmd_drawboxtext(struct ScriptContext *ctx)
{
    u8 left = ScriptReadByte(ctx);
    u8 top = ScriptReadByte(ctx);
    u8 multichoiceId = ScriptReadByte(ctx);
    bool8 ignoreBPress = ScriptReadByte(ctx);

    /*if (Multichoice(left, top, multichoiceId, ignoreBPress) == TRUE)
    {
        ScriptContext1_Stop();
        return TRUE;
    }*/
    return FALSE;
}

bool8 ScrCmd_showmonpic(struct ScriptContext *ctx)
{
    u16 species = VarGet(ScriptReadHalfword(ctx));
    u8 x = ScriptReadByte(ctx);
    u8 y = ScriptReadByte(ctx);

    ScriptMenu_ShowPokemonPic(species, x, y);
    return FALSE;
}

bool8 ScrCmd_hidemonpic(struct ScriptContext *ctx)
{
    bool8 (*func)(void) = ScriptMenu_GetPicboxWaitFunc();

    if (func == NULL)
        return FALSE;
    SetupNativeScript(ctx, func);
    return TRUE;
}

bool8 ScrCmd_showcontestpainting(struct ScriptContext *ctx)
{
    u8 contestWinnerId = ScriptReadByte(ctx);

    // Artist's painting is temporary and already has its data loaded
    if (contestWinnerId != CONTEST_WINNER_ARTIST)
        SetContestWinnerForPainting(contestWinnerId);

    ShowContestPainting();
    ScriptContext1_Stop();
    return TRUE;
}

bool8 ScrCmd_braillemessage(struct ScriptContext *ctx)
{
    u8 *ptr = (u8 *)ScriptReadWord(ctx);
    struct WindowTemplate winTemplate;
    s32 i;
    u8 width, height;
    u8 xWindow, yWindow, xText, yText;
    u8 temp;

    // + 6 for the 6 bytes at the start of a braille message (brailleformat macro)
    // In RS these bytes are used to position the text and window, but
    // in Emerald they are unused and position is calculated below instead
    StringExpandPlaceholders(gStringVar4, ptr + 6);

    width = GetStringWidth(6, gStringVar4, -1) / 8u;

    if (width > 28)
        width = 28;

    for (i = 0, height = 4; gStringVar4[i] != EOS;)
    {
        if (gStringVar4[i++] == CHAR_NEWLINE)
            height += 3;
    }

    if (height > 18)
        height = 18;

    temp = width + 2;
    xWindow = (30 - temp) / 2;

    temp = height + 2;
    yText = (20 - temp) / 2;

    xText = xWindow;
    xWindow += 1;

    yWindow = yText;
    yText += 2;

    xText = (xWindow - xText - 1) * 8 + 3;
    yText = (yText - yWindow - 1) * 8;

    winTemplate = CreateWindowTemplate(0, xWindow, yWindow + 1, width, height, 0xF, 0x1);
    gBrailleWindowId = AddWindow(&winTemplate);
    LoadUserWindowBorderGfx(gBrailleWindowId, 0x214, 0xE0);
    DrawStdWindowFrame(gBrailleWindowId, 0);
    PutWindowTilemap(gBrailleWindowId);
    FillWindowPixelBuffer(gBrailleWindowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(gBrailleWindowId, 6, gStringVar4, xText, yText, 0xFF, 0x0);
    CopyWindowToVram(gBrailleWindowId, 3);
    return FALSE;
}

bool8 ScrCmd_closebraillemessage(struct ScriptContext *ctx)
{
    CloseBrailleWindow();
    return FALSE;
}

bool8 ScrCmd_vmessage(struct ScriptContext *ctx)
{
    u32 msg = ScriptReadWord(ctx);

    ShowFieldMessage((u8 *)(msg - sAddressOffset));
    return FALSE;
}

bool8 ScrCmd_bufferspeciesname(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 species = VarGet(ScriptReadHalfword(ctx));

    StringCopy(sScriptStringVars[stringVarIndex], gSpeciesNames[species]);
    return FALSE;
}

bool8 ScrCmd_bufferleadmonspeciesname(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);

    u8 *dest = sScriptStringVars[stringVarIndex];
    u8 partyIndex = GetLeadMonIndex();
    u32 species = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPECIES, NULL);
    StringCopy(dest, gSpeciesNames[species]);
    return FALSE;
}

bool8 ScrCmd_bufferpartymonnick(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 partyIndex = VarGet(ScriptReadHalfword(ctx));

    GetMonData(&gPlayerParty[partyIndex], MON_DATA_NICKNAME, sScriptStringVars[stringVarIndex]);
    StringGetEnd10(sScriptStringVars[stringVarIndex]);
    return FALSE;
}

bool8 ScrCmd_bufferitemname(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 itemId = VarGet(ScriptReadHalfword(ctx));

    CopyItemName(itemId, sScriptStringVars[stringVarIndex]);
    return FALSE;
}

bool8 ScrCmd_bufferitemnameplural(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 itemId = VarGet(ScriptReadHalfword(ctx));
    u16 quantity = VarGet(ScriptReadHalfword(ctx));

    CopyItemNameHandlePlural(itemId, sScriptStringVars[stringVarIndex], quantity);
    return FALSE;
}

bool8 ScrCmd_bufferdecorationname(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 decorId = VarGet(ScriptReadHalfword(ctx));

    StringCopy(sScriptStringVars[stringVarIndex], gDecorations[decorId].name);
    return FALSE;
}

bool8 ScrCmd_buffermovename(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 moveId = VarGet(ScriptReadHalfword(ctx));

    StringCopy(sScriptStringVars[stringVarIndex], gMoveNamesLong[moveId]);
    return FALSE;
}

bool8 ScrCmd_buffernumberstring(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 num = VarGet(ScriptReadHalfword(ctx));
    u8 numDigits = CountDigits(num);

    ConvertIntToDecimalStringN(sScriptStringVars[stringVarIndex], num, STR_CONV_MODE_LEFT_ALIGN, numDigits);
    return FALSE;
}

bool8 ScrCmd_bufferstdstring(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 index = VarGet(ScriptReadHalfword(ctx));

    StringCopy(sScriptStringVars[stringVarIndex], gStdStrings[index]);
    return FALSE;
}

bool8 ScrCmd_buffercontesttype(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 index = VarGet(ScriptReadHalfword(ctx));

    BufferContestName(sScriptStringVars[stringVarIndex], index);
    return FALSE;
}

bool8 ScrCmd_bufferstring(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    const u8 *text = (u8 *)ScriptReadWord(ctx);

    StringCopy(sScriptStringVars[stringVarIndex], text);
    return FALSE;
}

bool8 ScrCmd_vloadword(struct ScriptContext *ctx)
{
    const u8 *ptr = (u8 *)(ScriptReadWord(ctx) - sAddressOffset);

    StringExpandPlaceholders(gStringVar4, ptr);
    return FALSE;
}

bool8 ScrCmd_vbufferstring(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u32 addr = ScriptReadWord(ctx);

    const u8 *src = (u8 *)(addr - sAddressOffset);
    u8 *dest = sScriptStringVars[stringVarIndex];
    StringCopy(dest, src);
    return FALSE;
}

bool8 ScrCmd_bufferboxname(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 boxId = VarGet(ScriptReadHalfword(ctx));

    StringCopy(sScriptStringVars[stringVarIndex], GetBoxNamePtr(boxId));
    return FALSE;
}

bool8 ScrCmd_givemon(struct ScriptContext *ctx)
{
    u16 species = VarGet(ScriptReadHalfword(ctx));
    u16 level = VarGet(ScriptReadHalfword(ctx));
    u16 item = VarGet(ScriptReadHalfword(ctx));
    u32 unkParam1 = ScriptReadWord(ctx);
    u32 unkParam2 = ScriptReadWord(ctx);
    u8 unkParam3 = ScriptReadByte(ctx);

    gSpecialVar_Result = ScriptGiveMon(species, level, item, unkParam1, unkParam2, unkParam3);
    return FALSE;
}

bool8 ScrCmd_giveegg(struct ScriptContext *ctx)
{
    u16 species = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = ScriptGiveEgg(species);
    return FALSE;
}

bool8 ScrCmd_setmonmove(struct ScriptContext *ctx)
{
    u8 partyIndex = ScriptReadByte(ctx);
    u8 slot = ScriptReadByte(ctx);
    u16 move = ScriptReadHalfword(ctx);

    ScriptSetMonMoveSlot(partyIndex, move, slot);
    return FALSE;
}

bool8 ScrCmd_checkpartymove(struct ScriptContext *ctx)
{
    u8 i;
    u16 moveId = ScriptReadHalfword(ctx);

    gSpecialVar_Result = PARTY_SIZE;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);
        if (!species)
            break;
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG) && MonKnowsMove(&gPlayerParty[i], moveId) == TRUE)
        {
            gSpecialVar_Result = i;
            gSpecialVar_0x8004 = species;
            break;
        }
    }
    return FALSE;
}

bool8 ScrCmd_addmoney(struct ScriptContext *ctx)
{
    u32 amount = ScriptReadWord(ctx);
    u8 ignore = ScriptReadByte(ctx);

    if (!ignore)
        AddMoney(&gSaveBlock1Ptr->money, amount);
    return FALSE;
}

bool8 ScrCmd_removemoney(struct ScriptContext *ctx)
{
    u32 amount = VarGet(ScriptReadWord(ctx));
    u8 ignore = ScriptReadByte(ctx);

    if (!ignore)
        RemoveMoney(&gSaveBlock1Ptr->money, amount);
    return FALSE;
}

bool8 ScrCmd_checkmoney(struct ScriptContext *ctx)
{
    u32 amount = VarGet(ScriptReadWord(ctx));
    u8 ignore = ScriptReadByte(ctx);

    if (!ignore)
        gSpecialVar_Result = IsEnoughMoney(&gSaveBlock1Ptr->money, amount);
    return FALSE;
}

bool8 ScrCmd_showmoneybox(struct ScriptContext *ctx)
{
    u8 x = ScriptReadByte(ctx);
    u8 y = ScriptReadByte(ctx);
    u8 ignore = ScriptReadByte(ctx);

    if (!ignore)
        DrawMoneyBox(GetMoney(&gSaveBlock1Ptr->money), x, y);
    return FALSE;
}

bool8 ScrCmd_hidemoneybox(struct ScriptContext *ctx)
{
    /*u8 x = ScriptReadByte(ctx);
    u8 y = ScriptReadByte(ctx);*/

    HideMoneyBox();
    return FALSE;
}

bool8 ScrCmd_updatemoneybox(struct ScriptContext *ctx)
{
    u8 x = ScriptReadByte(ctx);
    u8 y = ScriptReadByte(ctx);
    u8 ignore = ScriptReadByte(ctx);

    if (!ignore)
        ChangeAmountInMoneyBox(GetMoney(&gSaveBlock1Ptr->money));
    return FALSE;
}

bool8 ScrCmd_showcoinsbox(struct ScriptContext *ctx)
{
    u8 x = ScriptReadByte(ctx);
    u8 y = ScriptReadByte(ctx);

    ShowCoinsWindow(GetCoins(), x, y);
    return FALSE;
}

bool8 ScrCmd_hidecoinsbox(struct ScriptContext *ctx)
{
    u8 x = ScriptReadByte(ctx);
    u8 y = ScriptReadByte(ctx);

    HideCoinsWindow();
    return FALSE;
}

bool8 ScrCmd_updatecoinsbox(struct ScriptContext *ctx)
{
    u8 x = ScriptReadByte(ctx);
    u8 y = ScriptReadByte(ctx);

    PrintCoinsString(GetCoins());
    return FALSE;
}

bool8 ScrCmd_trainerbattle(struct ScriptContext *ctx)
{
    ctx->scriptPtr = BattleSetup_ConfigureTrainerBattle(ctx->scriptPtr);
    return FALSE;
}

bool8 ScrCmd_dotrainerbattle(struct ScriptContext *ctx)
{
    BattleSetup_StartTrainerBattle();
    return TRUE;
}

bool8 ScrCmd_gotopostbattlescript(struct ScriptContext *ctx)
{
    ctx->scriptPtr = BattleSetup_GetScriptAddrAfterBattle();
    return FALSE;
}

bool8 ScrCmd_gotobeatenscript(struct ScriptContext *ctx)
{
    ctx->scriptPtr = BattleSetup_GetTrainerPostBattleScript();
    return FALSE;
}

bool8 ScrCmd_checktrainerflag(struct ScriptContext *ctx)
{
    u16 index = VarGet(ScriptReadHalfword(ctx));

    ctx->comparisonResult = HasTrainerBeenFought(index);
    return FALSE;
}

bool8 ScrCmd_settrainerflag(struct ScriptContext *ctx)
{
    u16 index = VarGet(ScriptReadHalfword(ctx));

    SetTrainerFlag(index);
    return FALSE;
}

bool8 ScrCmd_cleartrainerflag(struct ScriptContext *ctx)
{
    u16 index = VarGet(ScriptReadHalfword(ctx));

    ClearTrainerFlag(index);
    return FALSE;
}

bool8 ScrCmd_setwildbattle(struct ScriptContext *ctx)
{
    u16 species = ScriptReadHalfword(ctx);
    u16 level = VarGet(ScriptReadHalfword(ctx));
    u16 item = ScriptReadHalfword(ctx);
    u16 species2 = ScriptReadHalfword(ctx);
    u16 level2 = VarGet(ScriptReadHalfword(ctx));
    u16 item2 = ScriptReadHalfword(ctx);

    if(species2 == SPECIES_NONE)
    {
        CreateScriptedWildMon(species, level, item);
        gIsScriptedWildDouble = FALSE;
    }
    else
    { 
        CreateScriptedDoubleWildMon(species, level, item, species2, level2, item2);
        gIsScriptedWildDouble = TRUE;
    }

    return FALSE;
}

bool8 ScrCmd_dowildbattle(struct ScriptContext *ctx)
{
    if(gIsScriptedWildDouble == FALSE)
    {
        BattleSetup_StartScriptedWildBattle();
        ScriptContext1_Stop();
    }
    else
    {
        BattleSetup_StartScriptedDoubleWildBattle();
        ScriptContext1_Stop();
    }

    return TRUE;
}

bool8 ScrCmd_pokemart(struct ScriptContext *ctx)
{
    const void *ptr = (void *)ScriptReadWord(ctx);

    CreatePokemartMenu(ptr);
    ScriptContext1_Stop();
    return TRUE;
}

bool8 ScrCmd_pokemartdecoration(struct ScriptContext *ctx)
{
    const void *ptr = (void *)ScriptReadWord(ctx);

    CreateDecorationShop1Menu(ptr);
    ScriptContext1_Stop();
    return TRUE;
}

// Changes clerk dialogue slightly from above. See MART_TYPE_DECOR2
bool8 ScrCmd_pokemartdecoration2(struct ScriptContext *ctx)
{
    const void *ptr = (void *)ScriptReadWord(ctx);

    CreateDecorationShop2Menu(ptr);
    ScriptContext1_Stop();
    return TRUE;
}

bool8 ScrCmd_playslotmachine(struct ScriptContext *ctx)
{
    u8 slotMachineIndex = VarGet(ScriptReadHalfword(ctx));

    PlaySlotMachine(slotMachineIndex, CB2_ReturnToFieldContinueScriptPlayMapMusic);
    ScriptContext1_Stop();
    return TRUE;
}

bool8 ScrCmd_setberrytree(struct ScriptContext *ctx)
{
    u8 treeId = ScriptReadByte(ctx);
    u8 berry = ScriptReadByte(ctx);
    u8 growthStage = ScriptReadByte(ctx);

    if (berry == 0)
        PlantBerryTree(treeId, 0, growthStage, FALSE);
    else
        PlantBerryTree(treeId, berry, growthStage, FALSE);
    return FALSE;
}

bool8 ScrCmd_getpricereduction(struct ScriptContext *ctx)
{
    u16 newsKind = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = GetPriceReduction(newsKind);
    return FALSE;
}

bool8 ScrCmd_choosecontestmon(struct ScriptContext *ctx)
{
    ChooseContestMon();
    ScriptContext1_Stop();
    return TRUE;
}


bool8 ScrCmd_startcontest(struct ScriptContext *ctx)
{
    StartContest();
    ScriptContext1_Stop();
    return TRUE;
}

bool8 ScrCmd_showcontestresults(struct ScriptContext *ctx)
{
    ShowContestResults();
    ScriptContext1_Stop();
    return TRUE;
}

bool8 ScrCmd_contestlinktransfer(struct ScriptContext *ctx)
{
    ContestLinkTransfer(gSpecialVar_ContestCategory);
    ScriptContext1_Stop();
    return TRUE;
}

bool8 ScrCmd_dofieldeffect(struct ScriptContext *ctx)
{
    u16 effectId = VarGet(ScriptReadHalfword(ctx));

    sFieldEffectScriptId = effectId;
    FieldEffectStart(sFieldEffectScriptId);
    return FALSE;
}

bool8 ScrCmd_setfieldeffectarg(struct ScriptContext *ctx)
{
    u8 argNum = ScriptReadByte(ctx);

    gFieldEffectArguments[argNum] = (s16)VarGet(ScriptReadHalfword(ctx));
    return FALSE;
}

static bool8 WaitForFieldEffectFinish(void)
{
    if (!FieldEffectActiveListContains(sFieldEffectScriptId))
        return TRUE;
    else
        return FALSE;
}

bool8 ScrCmd_waitfieldeffect(struct ScriptContext *ctx)
{
    sFieldEffectScriptId = VarGet(ScriptReadHalfword(ctx));
    SetupNativeScript(ctx, WaitForFieldEffectFinish);
    return TRUE;
}

bool8 ScrCmd_setrespawn(struct ScriptContext *ctx)
{
    u16 healLocationId = VarGet(ScriptReadHalfword(ctx));

    SetLastHealLocationWarp(healLocationId);
    return FALSE;
}

bool8 ScrCmd_checkplayergender(struct ScriptContext *ctx)
{
    gSpecialVar_Result = gSaveBlock2Ptr->playerGender;
    return FALSE;
}

bool8 ScrCmd_playmoncry(struct ScriptContext *ctx)
{
    u16 species = VarGet(ScriptReadHalfword(ctx));
    u16 mode = VarGet(ScriptReadHalfword(ctx));

    PlayCry5(species, mode);
    return FALSE;
}

bool8 ScrCmd_waitmoncry(struct ScriptContext *ctx)
{
    SetupNativeScript(ctx, IsCryFinished);
    return TRUE;
}

bool8 ScrCmd_setmetatile(struct ScriptContext *ctx)
{
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));
    u16 tileId = VarGet(ScriptReadHalfword(ctx));
    u16 isImpassable = VarGet(ScriptReadHalfword(ctx));

    x += 7;
    y += 7;
    if (!isImpassable)
        MapGridSetMetatileIdAt(x, y, tileId);
    else
        MapGridSetMetatileIdAt(x, y, tileId | METATILE_COLLISION_MASK);
    return FALSE;
}

bool8 ScrCmd_opendoor(struct ScriptContext *ctx)
{
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    x += 7;
    y += 7;
    PlaySE(GetDoorSoundEffect(x, y));
    FieldAnimateDoorOpen(x, y);
    return FALSE;
}

bool8 ScrCmd_closedoor(struct ScriptContext *ctx)
{
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    x += 7;
    y += 7;
    FieldAnimateDoorClose(x, y);
    return FALSE;
}

static bool8 IsDoorAnimationStopped(void)
{
    if (!FieldIsDoorAnimationRunning())
        return TRUE;
    else
        return FALSE;
}

bool8 ScrCmd_waitdooranim(struct ScriptContext *ctx)
{
    SetupNativeScript(ctx, IsDoorAnimationStopped);
    return TRUE;
}

bool8 ScrCmd_setdooropen(struct ScriptContext *ctx)
{
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    x += 7;
    y += 7;
    FieldSetDoorOpened(x, y);
    return FALSE;
}

bool8 ScrCmd_setdoorclosed(struct ScriptContext *ctx)
{
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    x += 7;
    y += 7;
    FieldSetDoorClosed(x, y);
    return FALSE;
}

// Below two are functions for elevators in RS, do nothing in Emerald
bool8 ScrCmd_addelevmenuitem(struct ScriptContext *ctx)
{
    u8 v3 = ScriptReadByte(ctx);
    u16 v5 = VarGet(ScriptReadHalfword(ctx));
    u16 v7 = VarGet(ScriptReadHalfword(ctx));
    u16 v9 = VarGet(ScriptReadHalfword(ctx));

    //ScriptAddElevatorMenuItem(v3, v5, v7, v9);
    return FALSE;
}

bool8 ScrCmd_showelevmenu(struct ScriptContext *ctx)
{
    /*ScriptShowElevatorMenu();
    ScriptContext1_Stop();
    return TRUE;*/
    return FALSE;
}

bool8 ScrCmd_checkcoins(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(ScriptReadHalfword(ctx));
    *ptr = GetCoins();
    return FALSE;
}

bool8 ScrCmd_addcoins(struct ScriptContext *ctx)
{
    u16 coins = VarGet(ScriptReadHalfword(ctx));

    if (AddCoins(coins) == TRUE)
        gSpecialVar_Result = FALSE;
    else
        gSpecialVar_Result = TRUE;
    return FALSE;
}

bool8 ScrCmd_removecoins(struct ScriptContext *ctx)
{
    u16 coins = VarGet(ScriptReadHalfword(ctx));

    if (RemoveCoins(coins) == TRUE)
        gSpecialVar_Result = FALSE;
    else
        gSpecialVar_Result = TRUE;
    return FALSE;
}

bool8 ScrCmd_moverotatingtileobjects(struct ScriptContext *ctx)
{
    u16 puzzleNumber = VarGet(ScriptReadHalfword(ctx));

    sMovingNpcId = MoveRotatingTileObjects(puzzleNumber);
    return FALSE;
}

bool8 ScrCmd_turnrotatingtileobjects(struct ScriptContext *ctx)
{
    TurnRotatingTileObjects();
    return FALSE;
}

bool8 ScrCmd_initrotatingtilepuzzle(struct ScriptContext *ctx)
{
    u16 isTrickHouse = VarGet(ScriptReadHalfword(ctx));

    InitRotatingTilePuzzle(isTrickHouse);
    return FALSE;
}

bool8 ScrCmd_freerotatingtilepuzzle(struct ScriptContext *ctx)
{
    FreeRotatingTilePuzzle();
    return FALSE;
}

bool8 ScrCmd_selectapproachingtrainer(struct ScriptContext *ctx)
{
    gSelectedObjectEvent = GetCurrentApproachingTrainerObjectEventId();
    return FALSE;
}

bool8 ScrCmd_lockfortrainer(struct ScriptContext *ctx)
{
    if (IsUpdateLinkStateCBActive())
    {
        return FALSE;
    }
    else
    {
        if (gObjectEvents[gSelectedObjectEvent].active)
        {
            FreezeForApproachingTrainers();
            SetupNativeScript(ctx, IsFreezeObjectAndPlayerFinished);
        }
        return TRUE;
    }
}

// This command will set a Pokémon's eventLegal bit; there is no similar command to clear it.
bool8 ScrCmd_setmoneventlegal(struct ScriptContext *ctx)
{
    bool8 isEventLegal = TRUE;
    u16 partyIndex = VarGet(ScriptReadHalfword(ctx));

    SetMonData(&gPlayerParty[partyIndex], MON_DATA_EVENT_LEGAL, &isEventLegal);
    return FALSE;
}

bool8 ScrCmd_checkmoneventlegal(struct ScriptContext *ctx)
{
    u16 partyIndex = VarGet(ScriptReadHalfword(ctx));

    gSpecialVar_Result = GetMonData(&gPlayerParty[partyIndex], MON_DATA_EVENT_LEGAL, NULL);
    return FALSE;
}

// TODO: Should be renamed. Name implies general usage, but its specifically for Wonder Card
// See GetSavedRamScriptIfValid, which is NULL if ValidateReceivedWonderCard returns FALSE
bool8 ScrCmd_gotoram(struct ScriptContext *ctx)
{
    const u8* script = GetSavedRamScriptIfValid();

    if (script)
    {
        gRamScriptRetAddr = ctx->scriptPtr;
        ScriptJump(ctx, script);
    }
    return FALSE;
}

// Unused
// For the warp used by the Aqua Hideout, see DoTeleportTileWarp
bool8 ScrCmd_warpspinenter(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    SetSpinStartFacingDir(GetPlayerFacingDirection());
    DoSpinEnterWarp();
    ResetInitialPlayerAvatarState();
    return TRUE;
}

bool8 ScrCmd_setmonmetlocation(struct ScriptContext *ctx)
{
    u16 partyIndex = VarGet(ScriptReadHalfword(ctx));
    u8 location = ScriptReadByte(ctx);

    if (partyIndex < PARTY_SIZE)
        SetMonData(&gPlayerParty[partyIndex], MON_DATA_MET_LOCATION, &location);
    return FALSE;
}

static void CloseBrailleWindow(void)
{
    ClearStdWindowAndFrame(gBrailleWindowId, 1);
    RemoveWindow(gBrailleWindowId);
}

bool8 ScrCmd_buffertrainerclassname(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 trainerClassId = VarGet(ScriptReadHalfword(ctx));

    StringCopy(sScriptStringVars[stringVarIndex], GetTrainerClassNameFromId(trainerClassId));
    return FALSE;
}

bool8 ScrCmd_buffertrainername(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u16 trainerClassId = VarGet(ScriptReadHalfword(ctx));

    StringCopy(sScriptStringVars[stringVarIndex], GetTrainerNameFromId(trainerClassId));
    return FALSE;
}

void SetMovingNpcId(u16 npcId)
{
    sMovingNpcId = npcId;
}

bool8 ScrCmd_warpsootopolislegend(struct ScriptContext *ctx)
{
    u8 mapGroup = ScriptReadByte(ctx);
    u8 mapNum = ScriptReadByte(ctx);
    u8 warpId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u16 y = VarGet(ScriptReadHalfword(ctx));

    SetWarpDestination(mapGroup, mapNum, warpId, x, y);
    DoSootopolisLegendWarp();
    ResetInitialPlayerAvatarState();
    return TRUE;
}

// Checks if player's party contains a certain species OR one of its forms that
// shares the same national dex number
bool8 ScrCmd_checkPartyHasSpecies(struct ScriptContext *ctx)
{
    u16 wantedSpecies = ScriptReadHalfword(ctx);
    u16 partySpecies;
    int i = 0;
    u8 partyCount = CalculatePlayerPartyCount();
    
    gSpecialVar_Result = FALSE;

    for (i = 0; i < partyCount; i++)
    {
        partySpecies = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);
        if (gSpeciesToNationalPokedexNum[partySpecies - 1] == wantedSpecies)
        {
            gSpecialVar_Result = TRUE;
        }
    }
    return FALSE;
}

// Checks if the species stored in gSpecialVar 0x8004 is a certain species OR one of its forms that
// shares the same national dex number
bool8 ScrCmd_isChosenMonSpecies(struct ScriptContext *ctx)
{
    u16 wantedSpecies = ScriptReadHalfword(ctx);
    u16 chosenSpecies = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPECIES2, NULL);

    gSpecialVar_Result = FALSE;
    if (gSpeciesToNationalPokedexNum[chosenSpecies - 1] == wantedSpecies)
    {
        gSpecialVar_Result = TRUE;
    }
    return FALSE;
}

//Multi choice
bool8 ScrCmd_multichoice2(struct ScriptContext *ctx){
    u8 x = ScriptReadByte(ctx);
    u8 y = ScriptReadByte(ctx);
    char* choices = (char*)ScriptReadWord(ctx);
    bool8 ignoreBPress = ScriptReadByte(ctx);
    u8 columns = ScriptReadByte(ctx);
    u8 defaultChoice = ScriptReadByte(ctx);
    if((u32)choices < 0x1000000){ //choices is a multichoiceId
        if(columns > 1)
            ScriptMenu_MultichoiceGrid(x, y, (u32)choices, ignoreBPress, columns);
        else
            ScriptMenu_MultichoiceWithDefault(x, y, (u32)choices, ignoreBPress, defaultChoice);
        ScriptContext1_Stop();
        return TRUE;
    }else{ //choices is a string
        struct MenuAction menuItems[16] = {NULL};
        u8 count = 0;
        while(count < ARRAY_COUNT(menuItems)){
		    int len = StringLength(choices);
		    if(!len) break;
		    menuItems[count++].text = choices;
		    choices += len + 1;
        }
        if(defaultChoice >= count)
            defaultChoice = 0;
        if (count > 0){
		    if(columns > 1)
			    ScriptMenu_MultichoiceGridCustom(x, y, defaultChoice, ignoreBPress, columns, menuItems, count);
		    else
			    DrawMultichoiceMenuCustom(x, y, 0, ignoreBPress, defaultChoice, menuItems, count);
            ScriptContext1_Stop();
            return TRUE;
	    }
    }
    return FALSE;
}

//Items given to you by Nurse Joy
static const u16 sBattleItemList[][2] =
{
    {ITEM_CANDY_BOX,         1},
    {ITEM_INFINITE_REPEL,    1},
    {ITEM_HONEY,            50},
    {ITEM_ESCAPE_ROPE,       1},
    {ITEM_EVIOLITE,         50},
    {ITEM_LEFTOVERS,        50},
    {ITEM_BLACK_SLUDGE,     50},
    {ITEM_FOCUS_SASH,       50},
    {ITEM_TOXIC_ORB,        50},
    {ITEM_FLAME_ORB,        50},
    {ITEM_FROST_ORB,        50},
    {ITEM_LIFE_ORB,         50},
    {ITEM_CHOICE_BAND,      50},
    {ITEM_CHOICE_SPECS,     50},
    {ITEM_CHOICE_SCARF,     50},
    {ITEM_ROCKY_HELMET,     50},
    {ITEM_ASSAULT_VEST,     50},
    {ITEM_PHYSICAL_VEST,    50},
    {ITEM_LIGHT_CLAY,       50},
    {ITEM_HEAVY_DUTY_BOOTS, 50},
    {ITEM_AIR_BALLOON,      50},
    {ITEM_WEAKNESS_POLICY,  50},
    {ITEM_WIDE_LENS,        50},
    {ITEM_DAMP_ROCK,        50},
    {ITEM_HEAT_ROCK,        50},
    {ITEM_ICY_ROCK,         50},
    {ITEM_SMOOTH_ROCK,      50},
    {ITEM_EXPERT_BELT,      50},
    {ITEM_SCOPE_LENS,       50},
    {ITEM_PROTECTIVE_PADS,  50},
    {ITEM_LIGHT_BALL,       50},
    {ITEM_SHELL_BELL,       50},
    {ITEM_SHED_SHELL,       50},
    {ITEM_LAGGING_TAIL,     50},
    {ITEM_TERRAIN_EXTENDER, 50},
    {ITEM_THROAT_SPRAY,     50},
    {ITEM_THICK_CLUB,       50},
    {ITEM_ADAMANT_ORB,       5},
    {ITEM_LUSTROUS_ORB,      5},
    {ITEM_GRISEOUS_ORB,      5},
    {ITEM_SOUL_DEW,          5},
    {ITEM_RED_ORB,           5},
    {ITEM_BLUE_ORB,          5},
    {ITEM_MIRACLE_SEED,     10},
    {ITEM_CHARCOAL,         10},
    {ITEM_LEEK,             10},
    {ITEM_BIG_ROOT,         50},
    {ITEM_MENTAL_HERB,      50},
    {ITEM_POWER_HERB,       50},
    {ITEM_WHITE_HERB,       50},
    {ITEM_MIRROR_HERB,      50},
    {ITEM_ELECTRIC_SEED,    50},
    {ITEM_PSYCHIC_SEED,     50},
    {ITEM_MISTY_SEED,       50},
    {ITEM_GRASSY_SEED,      50},
    {ITEM_BERRY_JUICE,      50},
    {ITEM_BRIGHT_POWDER,    50},
    {ITEM_HARD_STONE,       50},
    {ITEM_MYSTIC_WATER,     50},
    {ITEM_SILVER_POWDER,    50},
    {ITEM_POISON_BARB,      50},
    {ITEM_SOFT_SAND,        50},
    {ITEM_BLACK_BELT,       50},
    {ITEM_SILK_SCARF,       50},
    {ITEM_SHARP_BEAK,       50},
    {ITEM_NEVER_MELT_ICE,   50},
    {ITEM_TWISTED_SPOON,    50},
    {ITEM_MAGNET,           50},
    {ITEM_BLACK_GLASSES,    50},
    {ITEM_SPELL_TAG,        50},
    {ITEM_DRAGON_FANG,      50},
    {ITEM_MAGNET,           50},
    {ITEM_BINDING_BAND,     50},
    {ITEM_SAFETY_GOGGLES,   50},
    {ITEM_EJECT_BUTTON,     50},
    {ITEM_EJECT_PACK,       50},
    {ITEM_RED_CARD,         50},
    {ITEM_IRON_BALL,        50},
    {ITEM_IRON_PILL,        50},
    {ITEM_QUICK_CLAW,       50},
    {ITEM_MUSCLE_BAND,      50},
    {ITEM_WISE_GLASSES,     50},
    {ITEM_ABILITY_SHIELD,   50},
    {ITEM_CLEAR_AMULET,     50},
    {ITEM_PUNCHING_GLOVE,   50},
    {ITEM_COVERT_CLOAK,     50},
    {ITEM_LOADED_DICE,      50},
    {ITEM_BOOSTER_ENERGY,   50},
    //Pokeballs
    {ITEM_POKE_BALL,         1},
    {ITEM_MASTER_BALL,       1},
    {ITEM_ULTRA_BALL,        1},
    {ITEM_GREAT_BALL,        1},
    {ITEM_SAFARI_BALL,       1},
    {ITEM_NET_BALL,          1},
    {ITEM_DIVE_BALL,         1},
    {ITEM_NEST_BALL,         1},
    {ITEM_REPEAT_BALL,       1},
    {ITEM_TIMER_BALL,        1},
    {ITEM_LUXURY_BALL,       1},
    {ITEM_DUSK_BALL,         1},
    {ITEM_HEAL_BALL,         1},
    {ITEM_QUICK_BALL,        1},
    {ITEM_CHERISH_BALL,      1},
    {ITEM_FAST_BALL,         1},
    {ITEM_LEVEL_BALL,        1},
    {ITEM_LURE_BALL,         1},
    {ITEM_HEAVY_BALL,        1},
    {ITEM_LOVE_BALL,         1},
    {ITEM_FRIEND_BALL,       1},
    {ITEM_MOON_BALL,         1},
    {ITEM_SPORT_BALL,        1},
    {ITEM_PARK_BALL,         1},
    {ITEM_DREAM_BALL,        1},
    {ITEM_BEAST_BALL,        1},
    {ITEM_PREMIER_BALL,      1},
    //Type Gems
    {ITEM_BUG_GEM,          50},
    {ITEM_DARK_GEM,         50},
    {ITEM_DRAGON_GEM,       50},
    {ITEM_ELECTRIC_GEM,     50},
    {ITEM_FAIRY_GEM,        50},
    {ITEM_FIGHTING_GEM,     50},
    {ITEM_FIRE_GEM,         50},
    {ITEM_FLYING_GEM,       50},
    {ITEM_GHOST_GEM,        50},
    {ITEM_GRASS_GEM,        50},
    {ITEM_GROUND_GEM,       50},
    {ITEM_ICE_GEM,          50},
    {ITEM_NORMAL_GEM,       50},
    {ITEM_POISON_GEM,       50},
    {ITEM_PSYCHIC_GEM,      50},
    {ITEM_ROCK_GEM,         50},
    {ITEM_STEEL_GEM,        50},
    {ITEM_WATER_GEM,        50},
    //Mega Stones
    {ITEM_ABOMASITE,         1},
    {ITEM_ABSOLITE,          1},
    {ITEM_AERODACTYLITE,     1},
    {ITEM_AGGRONITE,         1},
    {ITEM_ALAKAZITE,         1},
    {ITEM_ALTARIANITE,       1},
    {ITEM_AMPHAROSITE,       1},
    {ITEM_AUDINITE,          1},
    {ITEM_BANETTITE,         1},
    {ITEM_BEEDRILLITE,       1},
    {ITEM_BLASTOISINITE,     1},
    {ITEM_BLAZIKENITE,       1},
    {ITEM_CAMERUPTITE,       1},
    {ITEM_CHARIZARDITE_X,    1},
    {ITEM_CHARIZARDITE_Y,    1},
    {ITEM_DIANCITE,          1},
    {ITEM_GALLADITE,         1},
    {ITEM_GARCHOMPITE,       1},
    {ITEM_GARDEVOIRITE,      1},
    {ITEM_GENGARITE,         1},
    {ITEM_GLALITITE,         1},
    {ITEM_GYARADOSITE,       1},
    {ITEM_HERACRONITE,       1},
    {ITEM_HOUNDOOMINITE,     1},
    {ITEM_KANGASKHANITE,     1},
    {ITEM_LATIASITE,         1},
    {ITEM_LATIOSITE,         1},
    {ITEM_LOPUNNITE,         1},
    {ITEM_LUCARIONITE,       1},
    {ITEM_MANECTITE,         1},
    {ITEM_MAWILITE,          1},
    {ITEM_MEDICHAMITE,       1},
    {ITEM_METAGROSSITE,      1},
    {ITEM_MEWTWONITE_X,      1},
    {ITEM_MEWTWONITE_Y,      1},
    {ITEM_PIDGEOTITE,        1},
    {ITEM_PINSIRITE,         1},
    {ITEM_SABLENITE,         1},
    {ITEM_SALAMENCITE,       1},
    {ITEM_SCEPTILITE,        1},
    {ITEM_SCIZORITE,         1},
    {ITEM_SHARPEDONITE,      1},
    {ITEM_SLOWBRONITE,       1},
    {ITEM_STEELIXITE,        1},
    {ITEM_SWAMPERTITE,       1},
    {ITEM_TYRANITARITE,      1},
    {ITEM_VENUSAURITE,       1},
    {ITEM_MILOTICITE,        1},
    {ITEM_FLYGONITE,         1},
    {ITEM_BUTTERFRENITE,     1},
    {ITEM_LAPRASITE_Y,         1},
    {ITEM_MACHAMPITE,        1},
    {ITEM_KINGLERITE,        1},
    {ITEM_KINGDRANITE,       1},
    {ITEM_SKARMORITE,      1},
    {ITEM_RELICANTHITE,      1},
    {ITEM_QUAGSIRENITE,      1},
    {ITEM_SWALOTITE,         1},
    {ITEM_LUXRAYNITE,        1},
    {ITEM_MAGNEZONITE,       1},
    //Berries
    {ITEM_AGUAV_BERRY,      50},
    {ITEM_APICOT_BERRY,     50},
    {ITEM_CUSTAP_BERRY,     50},
    {ITEM_FIGY_BERRY,       50},
    {ITEM_IAPAPA_BERRY,     50},
    {ITEM_LIECHI_BERRY,     50},
    {ITEM_PETAYA_BERRY,     50},
    {ITEM_SALAC_BERRY,      50},
    {ITEM_WIKI_BERRY,       50},
    {ITEM_CHERI_BERRY,      50},
    {ITEM_CHESTO_BERRY,     50},
    {ITEM_PECHA_BERRY,      50},
    {ITEM_RAWST_BERRY,      50},
    {ITEM_PERSIM_BERRY,     50},
    {ITEM_OCCA_BERRY,       50},
    {ITEM_PASSHO_BERRY,     50},
    {ITEM_WACAN_BERRY,      50},
    {ITEM_RINDO_BERRY,      50},
    {ITEM_YACHE_BERRY,      50},
    {ITEM_CHOPLE_BERRY,     50},
    {ITEM_KEBIA_BERRY,      50},
    {ITEM_SHUCA_BERRY,      50},
    {ITEM_COBA_BERRY,       50},
    {ITEM_PAYAPA_BERRY,     50},
    {ITEM_TANGA_BERRY,      50},
    {ITEM_CHARTI_BERRY,     50},
    {ITEM_KASIB_BERRY,      50},
    {ITEM_HABAN_BERRY,      50},
    {ITEM_COLBUR_BERRY,     50},
    {ITEM_BABIRI_BERRY,     50},
    {ITEM_CHILAN_BERRY,     50},
    {ITEM_ROSELI_BERRY,     50},
    {ITEM_SITRUS_BERRY,     50},
};

bool8 ScrCmd_giveBattleItems(struct ScriptContext *ctx)
{
    u8 i;
    //Battle Items
    for(i = 0; i < ARRAY_COUNT(sBattleItemList); i++){
        if(CheckBagHasItem(ITEM_MEGA_BRACELET, 1) && FlagGet(FLAG_SYS_RECEIVED_KEYSTONE)){
            //With Mega Stones
            if (!CheckBagHasItem(sBattleItemList[i][0], sBattleItemList[i][1])){
                AddBagItem(sBattleItemList[i][0], sBattleItemList[i][1]);
            } 
        }
        else{
            //Without Mega stones
            if (!CheckBagHasItem(sBattleItemList[i][0], sBattleItemList[i][1]) && ItemId_GetPocket(sBattleItemList[i][0]) != POCKET_MEGA_STONES){
                AddBagItem(sBattleItemList[i][0], sBattleItemList[i][1]);
            } 
        }
    }

    for(i = 0; i < NUM_TECHNICAL_MACHINES; i++){
        if (!CheckBagHasItem(ITEM_TM01_FOCUS_PUNCH + i, 1)){
            AddBagItem(ITEM_TM01_FOCUS_PUNCH + i, 1);
        } 
    }
    return TRUE;
}

bool8 ScrCmd_givecustommon(struct ScriptContext *ctx)
{
    u16 species = ScriptReadHalfword(ctx);
    u8 level = ScriptReadByte(ctx);
    u16 item = ScriptReadHalfword(ctx);
    u8 ball = ScriptReadByte(ctx);
    u8 nature = ScriptReadByte(ctx);
    u8 abilityNum = ScriptReadByte(ctx);
    u8 hpEv = ScriptReadByte(ctx);
    u8 atkEv = ScriptReadByte(ctx);
    u8 defEv = ScriptReadByte(ctx);
    u8 speedEv = ScriptReadByte(ctx);
    u8 spAtkEv = ScriptReadByte(ctx);
    u8 spDefEv = ScriptReadByte(ctx);
    u8 hpIv = ScriptReadByte(ctx);
    u8 atkIv = ScriptReadByte(ctx);
    u8 defIv = ScriptReadByte(ctx);
    u8 speedIv = ScriptReadByte(ctx);
    u8 spAtkIv = ScriptReadByte(ctx);
    u8 spDefIv = ScriptReadByte(ctx);
    u16 move1 = ScriptReadHalfword(ctx);
    u16 move2 = ScriptReadHalfword(ctx);
    u16 move3 = ScriptReadHalfword(ctx);
    u16 move4 = ScriptReadHalfword(ctx);
    bool8 isShiny = ScriptReadByte(ctx);

    u8 evs[NUM_STATS] = {hpEv, atkEv, defEv, speedEv, spAtkEv, spDefEv};
    u8 ivs[NUM_STATS] = {hpIv, atkIv, defIv, speedIv, spAtkIv, spDefIv};
    u16 moves[4] = {move1, move2, move3, move4};

    if(level == 0)
        level = GetHighestLevelInPlayerParty();

    gSpecialVar_Result = ScriptGiveCustomMon(species, level, item, ball, nature, abilityNum, evs, ivs, moves, isShiny);
    return FALSE;
}

bool8 ScrCmd_toggleSaveblock(struct ScriptContext *ctx)
{
    u16 flag  = ScriptReadHalfword(ctx);
    u16 value = ScriptReadHalfword(ctx);
    switch(flag){
        case SAVEBLOCK_RANDOMIZER:
            gSaveBlock2Ptr->encounterRandomizedMode = value;
        break;
        case SAVEBLOCK_INNATE_RANDOMIZER:
            gSaveBlock2Ptr->innaterandomizedMode = value;
        break;
        case SAVEBLOCK_DIFFICULTY:
            gSaveBlock2Ptr->gameDifficulty = value;
        break;
        case SAVEBLOCK_ENABLE_LEGENDARY:
            gSaveBlock2Ptr->encounterRandomizedLegendaryMode = value;
        break;
    }
    return TRUE;
}

bool8 ScrCmd_checkSaveblockValue(struct ScriptContext *ctx)
{
    u16 flag  = ScriptReadHalfword(ctx);
    switch(flag){
        case SAVEBLOCK_RANDOMIZER:
            gSpecialVar_Result = gSaveBlock2Ptr->encounterRandomizedMode;
        break;
        case SAVEBLOCK_INNATE_RANDOMIZER:
            gSpecialVar_Result = gSaveBlock2Ptr->innaterandomizedMode;
        break;
        case SAVEBLOCK_DIFFICULTY:
            gSpecialVar_Result = gSaveBlock2Ptr->gameDifficulty;
        break;
        case SAVEBLOCK_ENABLE_LEGENDARY:
            gSpecialVar_Result = gSaveBlock2Ptr->encounterRandomizedLegendaryMode;
        break;
    }
    return FALSE;
}

bool8 ScrCmd_checkpartyfortypeornumber(struct ScriptContext *ctx)
{
    u16 type  = ScriptReadHalfword(ctx);
    u16 number  = ScriptReadHalfword(ctx);
    u8 partySize = CalculatePlayerPartyCount();
    u8 i, type1, type2;
    u16 species;

    if(partySize != number && number != 0){
        gSpecialVar_Result = FALSE;
        return FALSE;
    }

    if(type != NUMBER_OF_MON_TYPES){
        for(i = 0; i < partySize; i++){
            species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);
            type1 = gBaseStats[species].type1;
            type2 = gBaseStats[species].type2;
            if(type1 != type && type2 != type){
                gSpecialVar_Result = FALSE;
                return FALSE;
            }
        }
    }

    gSpecialVar_Result = TRUE;
    return TRUE;
}

bool8 ScrCmd_setwildbattlewithcustommoves(struct ScriptContext *ctx)
{
    u16 species    = ScriptReadHalfword(ctx);
    u8  level      = ScriptReadByte(ctx);
    u16 item       = ScriptReadHalfword(ctx);
    u16 move1      = ScriptReadHalfword(ctx);
    u16 move2      = ScriptReadHalfword(ctx);
    u16 move3      = ScriptReadHalfword(ctx);
    u16 move4      = ScriptReadHalfword(ctx);
    u16 abilitynum = ScriptReadHalfword(ctx);
    u16 nature     = ScriptReadHalfword(ctx);
    u16 hp_evs     = ScriptReadHalfword(ctx);
    u16 atk_evs    = ScriptReadHalfword(ctx);
    u16 def_evs    = ScriptReadHalfword(ctx);
    u16 spa_evs    = ScriptReadHalfword(ctx);
    u16 spd_evs    = ScriptReadHalfword(ctx);
    u16 speed_evs  = ScriptReadHalfword(ctx);
    struct Pokemon *pkmn = &gEnemyParty[0];
    
    if(level == 0)
        level = GetHighestLevelInPlayerParty();

    CreateScriptedWildMon(species, level, item);

    if (move1 != MOVE_NONE) {
        SetMonMoveSlot(pkmn, move1, 0);
    }    
    if (move2 != MOVE_NONE) {
        SetMonMoveSlot(pkmn, move2, 1);
    }    
    if (move3 != MOVE_NONE) {
        SetMonMoveSlot(pkmn, move3, 2);
    }    
    if (move4 != MOVE_NONE) {
        SetMonMoveSlot(pkmn, move4, 3);
    }   
	if (abilitynum != 3) {
		SetMonData(pkmn, MON_DATA_ABILITY_NUM, &abilitynum);
    }      
	if (nature != 0) {
		SetMonData(pkmn, MON_DATA_NATURE, &nature);
    }
	
	SetMonData(pkmn, MON_DATA_HELD_ITEM, &item);
	SetMonData(pkmn, MON_DATA_HP_EV,     &hp_evs);
	SetMonData(pkmn, MON_DATA_ATK_EV,    &atk_evs);
	SetMonData(pkmn, MON_DATA_DEF_EV,    &def_evs);
	SetMonData(pkmn, MON_DATA_SPATK_EV,  &spa_evs);
	SetMonData(pkmn, MON_DATA_SPDEF_EV,  &spd_evs);
	SetMonData(pkmn, MON_DATA_SPEED_EV,  &speed_evs);
	
    return FALSE;
}

bool8 ScrCmd_questmenu(struct ScriptContext *ctx)
{
    u8 caseId = ScriptReadByte(ctx);
    u8 questId = VarGet(ScriptReadByte(ctx));

    switch (caseId)
    {
    case QUEST_MENU_OPEN:
    default:
        SetQuestMenuActive();
        BeginNormalPaletteFade(0xFFFFFFFF, 2, 16, 0, 0);
        QuestMenu_Init(0, CB2_ReturnToFieldContinueScriptPlayMapMusic);
        ScriptContext1_Stop();
        break;
    case QUEST_MENU_UNLOCK_QUEST:
        GetSetQuestFlag(questId, FLAG_SET_UNLOCKED);
        break;
    case QUEST_MENU_COMPLETE_QUEST:
        GetSetQuestFlag(questId, FLAG_SET_COMPLETED);
        break;
    case QUEST_MENU_SET_ACTIVE:
        SetActiveQuest(questId);
        break;
    case QUEST_MENU_RESET_ACTIVE:
        ResetActiveQuest();
        break;
    case QUEST_MENU_BUFFER_QUEST_NAME:
            CopyQuestName(gStringVar1, questId);
        break;
    case QUEST_MENU_GET_ACTIVE_QUEST:
        gSpecialVar_Result = GetActiveQuestIndex();
        break;
    case QUEST_MENU_CHECK_UNLOCKED:
        if (GetSetQuestFlag(questId, FLAG_GET_UNLOCKED))
            gSpecialVar_Result = TRUE;
        else
            gSpecialVar_Result = FALSE;
        break;
    case QUEST_MENU_CHECK_COMPLETE:
        if (GetSetQuestFlag(questId, FLAG_GET_COMPLETED))
            gSpecialVar_Result = TRUE;
        else
            gSpecialVar_Result = FALSE;
        break;
    }

    return TRUE;
}
