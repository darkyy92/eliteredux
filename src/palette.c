#include "global.h"
#include "palette.h"
#include "util.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "task.h"
#include "constants/rgb.h"
#include "mgba_printf/mgba.h"
#include "mgba_printf/mini_printf.h"

enum
{
    NORMAL_FADE,
    FAST_FADE,
    HARDWARE_FADE,
};

// These are structs for some unused palette system.
// The full functionality of this system is unknown.

struct PaletteStructTemplate
{
    u16 uid;
    u16 *src;
    u16 pst_field_8_0:1;
    u16 pst_field_8_1:9;
    u16 size:5;
    u16 pst_field_9_7:1;
    u8 pst_field_A;
    u8 srcCount:5;
    u8 pst_field_B_5:3;
    u8 pst_field_C;
};

struct PaletteStruct
{
    const struct PaletteStructTemplate *base;
    u32 ps_field_4_0:1;
    u16 ps_field_4_1:1;
    u32 baseDestOffset:9;
    u16 destOffset:10;
    u16 srcIndex:7;
    u8 ps_field_8;
    u8 ps_field_9;
};

static void unused_sub_80A1CDC(struct PaletteStruct *, u32 *);
static void unused_sub_80A1E40(struct PaletteStruct *, u32 *);
static void unused_sub_80A1F00(struct PaletteStruct *);
static u8 GetPaletteNumByUid(u16);
static u8 UpdateNormalPaletteFade(void);
static void BeginFastPaletteFadeInternal(u8);
static u8 UpdateFastPaletteFade(void);
static u8 UpdateHardwarePaletteFade(void);
static void UpdateBlendRegisters(void);
static bool8 IsSoftwarePaletteFadeFinishing(void);
static void Task_BlendPalettesGradually(u8 taskId);

// palette buffers require alignment with agbcc because
// unaligned word reads are issued in BlendPalette otherwise
ALIGNED(4) EWRAM_DATA u16 gPlttBufferUnfaded[PLTT_BUFFER_SIZE] = {0};
ALIGNED(4) EWRAM_DATA u16 gPlttBufferFaded[PLTT_BUFFER_SIZE] = {0};
EWRAM_DATA struct PaletteStruct sPaletteStructs[0x10] = {0};
EWRAM_DATA struct PaletteFadeControl gPaletteFade = {0};
static EWRAM_DATA u32 sFiller = 0;
static EWRAM_DATA u32 sPlttBufferTransferPending = 0;
EWRAM_DATA u8 gPaletteDecompressionBuffer[PLTT_DECOMP_BUFFER_SIZE] = {0};

static const struct PaletteStructTemplate gDummyPaletteStructTemplate = {
    .uid = 0xFFFF,
    .pst_field_B_5 = 1
};

static const u8 sRoundedDownGrayscaleMap[] = {
     0,  0,  0,  0,  0,
     5,  5,  5,  5,  5,
    11, 11, 11, 11, 11,
    16, 16, 16, 16, 16,
    21, 21, 21, 21, 21,
    27, 27, 27, 27, 27,
    31, 31
};

void LoadCompressedPalette(const u32 *src, u16 offset, u16 size)
{
    LZDecompressWram(src, gPaletteDecompressionBuffer);
    CpuCopy16(gPaletteDecompressionBuffer, gPlttBufferUnfaded + offset, size);
    CpuCopy16(gPaletteDecompressionBuffer, gPlttBufferFaded + offset, size);
}

static const u16 sCosTable[] = {
    0x0400,
    0x03FF,
    0x03FF,
    0x03FF,
    0x03FE,
    0x03FE,
    0x03FD,
    0x03FC,
    0x03FB,
    0x03FA,
    0x03F9,
    0x03F8,
    0x03F6,
    0x03F5,
    0x03F3,
    0x03F1,
    0x03EF,
    0x03ED,
    0x03EB,
    0x03E8,
    0x03E6,
    0x03E3,
    0x03E0,
    0x03DD,
    0x03DA,
    0x03D7,
    0x03D4,
    0x03D1,
    0x03CD,
    0x03C9,
    0x03C6,
    0x03C2
};

static const u16 sSinTable[] = {
    0x0000,
    0x000B,
    0x0017,
    0x0022,
    0x002E,
    0x0039,
    0x0045,
    0x0050,
    0x005C,
    0x0067,
    0x0073,
    0x007E,
    0x0089,
    0x0095,
    0x00A0,
    0x00AC,
    0x00B7,
    0x00C2,
    0x00CE,
    0x00D9,
    0x00E4,
    0x00EF,
    0x00FB,
    0x0106,
    0x0111,
    0x011C,
    0x0127,
    0x0132,
    0x013D,
    0x0148,
    0x0153,
    0x015E
};

//Chosen to provide the most amount of precision without overflowing in our use case
typedef s32 fixed;
#define FIX_SHIFT 10

#define ONE        (fixed) (1  << FIX_SHIFT)
#define THREE      (fixed) (3  << FIX_SHIFT)
#define THIRTY_TWO (fixed) (32 << FIX_SHIFT)
#define ONE_HALF   (fixed) (1  << (FIX_SHIFT-1))
#define ONE_THIRD  (fixed) (0x155)
#define TWO_THIRDS (fixed) (0x2AA)
#define SQRT_1_3   (fixed) (0x24F)

///Multiply two fixed point values
static inline fixed FxMul(fixed fa, fixed fb) { return (fa*fb)>>FIX_SHIFT; }

///Take a fixed point value and round it, clamp to 0 or 31, then shift down to integer
static inline s32 RoundClampShift(fixed v) {
    v += ONE_HALF;
    if (v < 0)           return 0;
    if (v >= THIRTY_TWO) return 31;
    return v >> FIX_SHIFT;
}

/***
 * Performs a hue shift on the colors in a given palette. Index must be from 0 to 63.
 * Values 0-31 shift right, while values 32-63 shift left (but 32 is treated as 0, 33 as 1, etc.).
 ***/
#define ALPHA_RED_COLOR 31
void HueShiftMonPalette(u16* colors, u32 personality, bool8 isAlpha) {
    //Use third personality byte to determine color;
    //Limit the index to valid bounds
    u32 index = (personality >> 16) & (64-1);

    //sCosTable and sSinTable are two tables for precalculated cosine values, one after other, each with 32
    //elements of two bytes. The values are represented in fixed point, and the table doesn't go very far around the
    //circle (currently represent about +/-20 degrees).
    //The index into the table is treated a little strangely. an index of 0 corresponds to cos(0) and sin(0).
    //values of index after 32 are treated like -(index-32). for cosine, because cos(x) == cos(-x), I can just
    //chop off bits after the first 5 and index into the table. For sine, sin(-x) == -sin(x), so I flip the sign of the
    //value in the table at (index-32). This is all done to save space.
    fixed cosA = sCosTable[index & 31],
          sinA = index >= 32 ? -(fixed)(sSinTable[index-32]) : sSinTable[index];

    //The following code performs an approximate hue shift on each color in the palette, taken from this post on stack
    //overflow, optimized to work with this fixed point stuff: https://stackoverflow.com/a/8510751/963007
    fixed val1 = ONE_THIRD + FxMul(cosA, TWO_THIRDS);
    fixed val2 = FxMul(ONE - cosA, ONE_THIRD) - FxMul(SQRT_1_3, sinA);
    fixed val3 = FxMul(ONE - cosA, ONE_THIRD) + FxMul(SQRT_1_3, sinA);

    u8 i;
    u16 color;
    fixed r, g, b;
    s32 rx, gx, bx;

    for (i = 1; i < 16; i++) { //Skip past first color, which is transparency
        color = colors[i];

        //Unpack the color
        if (gSaveBlock2Ptr->individualColors){
            if(isAlpha)
                r = ALPHA_RED_COLOR << FIX_SHIFT;
            else
                r = (color & 0x1F) << FIX_SHIFT;
            color = color >> 5;
            g     = (color & 0x1F) << FIX_SHIFT;
            color = color >> 5;
            b     = (color & 0x1F) << FIX_SHIFT; 
        }
        else{
            if(isAlpha)
                r = ALPHA_RED_COLOR << FIX_SHIFT;
            else
                r = (color & 0x1F) << FIX_SHIFT;
            color = color >> 5;
            g     = (color & 0x1F) << FIX_SHIFT;
            color = color >> 5;
            b     = (color & 0x1F) << FIX_SHIFT; 
        }

        //Hue shift, clamping at the max component value (31)
        rx = RoundClampShift(FxMul(r, val1) + FxMul(g, val2) + FxMul(b, val3));
        gx = RoundClampShift(FxMul(r, val3) + FxMul(g, val1) + FxMul(b, val2));
        bx = RoundClampShift(FxMul(r, val2) + FxMul(g, val3) + FxMul(b, val1));

        //Pack the color
        colors[i] = rx | (gx << 5) | (bx << 10);
    }
}

void LoadHueShiftedMonPalette(const u32 *src, u16 offset, u16 size, u32 personality, bool8 isAlpha)
{
    LZDecompressWram(src, gPaletteDecompressionBuffer);

    HueShiftMonPalette((u16*) gPaletteDecompressionBuffer, personality, isAlpha);

    CpuCopy16(gPaletteDecompressionBuffer, gPlttBufferUnfaded + offset, size);
    CpuCopy16(gPaletteDecompressionBuffer, gPlttBufferFaded + offset, size);
}

void LoadPalette(const void *src, u16 offset, u16 size)
{
    CpuCopy16(src, gPlttBufferUnfaded + offset, size);
    CpuCopy16(src, gPlttBufferFaded + offset, size);
}

void FillPalette(u16 value, u16 offset, u16 size)
{
    CpuFill16(value, gPlttBufferUnfaded + offset, size);
    CpuFill16(value, gPlttBufferFaded + offset, size);
}

void TransferPlttBuffer(void)
{
    if (!gPaletteFade.bufferTransferDisabled)
    {
        void *src = gPlttBufferFaded;
        void *dest = (void *)PLTT;
        DmaCopy16(3, src, dest, PLTT_SIZE);
        sPlttBufferTransferPending = 0;
        if (gPaletteFade.mode == HARDWARE_FADE && gPaletteFade.active)
            UpdateBlendRegisters();
    }
}

u8 UpdatePaletteFade(void)
{
    u8 result;
    u8 dummy = 0;

    if (sPlttBufferTransferPending)
        return PALETTE_FADE_STATUS_LOADING;

    if (gPaletteFade.mode == NORMAL_FADE)
        result = UpdateNormalPaletteFade();
    else if (gPaletteFade.mode == FAST_FADE)
        result = UpdateFastPaletteFade();
    else
        result = UpdateHardwarePaletteFade();

    sPlttBufferTransferPending = gPaletteFade.multipurpose1 | dummy;

    return result;
}

void ResetPaletteFade(void)
{
    u8 i;

    for (i = 0; i < 16; i++)
        ResetPaletteStruct(i);

    ResetPaletteFadeControl();
}

void ReadPlttIntoBuffers(void)
{
    u16 i;
    u16 *pltt = (u16 *)PLTT;

    for (i = 0; i < PLTT_SIZE / 2; i++)
    {
        gPlttBufferUnfaded[i] = pltt[i];
        gPlttBufferFaded[i] = pltt[i];
    }
}

bool8 BeginNormalPaletteFade(u32 selectedPalettes, s8 delay, u8 startY, u8 targetY, u16 blendColor)
{
    u8 temp;
    u16 color = blendColor;

    if (gPaletteFade.active)
    {
        return FALSE;
    }
    else
    {
        gPaletteFade.deltaY = 2;

        if (delay < 0)
        {
            gPaletteFade.deltaY += (delay * -1);
            delay = 0;
        }

        gPaletteFade_selectedPalettes = selectedPalettes;
        gPaletteFade.delayCounter = delay;
        gPaletteFade_delay = delay;
        gPaletteFade.y = startY;
        gPaletteFade.targetY = targetY;
        gPaletteFade.blendColor = color;
        gPaletteFade.active = 1;
        gPaletteFade.mode = NORMAL_FADE;

        if (startY < targetY)
            gPaletteFade.yDec = 0;
        else
            gPaletteFade.yDec = 1;

        UpdatePaletteFade();

        temp = gPaletteFade.bufferTransferDisabled;
        gPaletteFade.bufferTransferDisabled = 0;
        CpuCopy32(gPlttBufferFaded, (void *)PLTT, PLTT_SIZE);
        sPlttBufferTransferPending = 0;
        if (gPaletteFade.mode == HARDWARE_FADE && gPaletteFade.active)
            UpdateBlendRegisters();
        gPaletteFade.bufferTransferDisabled = temp;
        return TRUE;
    }
}

bool8 unref_sub_80A1C1C(u32 a1, u8 a2, u8 a3, u8 a4, u16 a5)
{
    ReadPlttIntoBuffers();
    return BeginNormalPaletteFade(a1, a2, a3, a4, a5);
}

void unref_sub_80A1C64(u8 a1, u32 *a2)
{
    u8 i;

    for (i = 0; i < 16; i++)
    {
        struct PaletteStruct *palstruct = &sPaletteStructs[i];
        if (palstruct->ps_field_4_0)
        {
            if (palstruct->base->pst_field_8_0 == a1)
            {
                u8 val1 = palstruct->srcIndex;
                u8 val2 = palstruct->base->srcCount;
                if (val1 == val2)
                {
                    unused_sub_80A1F00(palstruct);
                    if (!palstruct->ps_field_4_0)
                        continue;
                }
                if (palstruct->ps_field_8 == 0)
                    unused_sub_80A1CDC(palstruct, a2);
                else
                    palstruct->ps_field_8--;

                unused_sub_80A1E40(palstruct, a2);
            }
        }
    }
}

static void unused_sub_80A1CDC(struct PaletteStruct *a1, u32 *a2)
{
    s32 srcIndex;
    s32 srcCount;
    u8 i = 0;
    u16 srcOffset = a1->srcIndex * a1->base->size;

    if (!a1->base->pst_field_8_0)
    {
        while (i < a1->base->size)
        {
            gPlttBufferUnfaded[a1->destOffset] = a1->base->src[srcOffset];
            gPlttBufferFaded[a1->destOffset] = a1->base->src[srcOffset];
            i++;
            a1->destOffset++;
            srcOffset++;
        }
    }
    else
    {
        while (i < a1->base->size)
        {
            gPlttBufferFaded[a1->destOffset] = a1->base->src[srcOffset];
            i++;
            a1->destOffset++;
            srcOffset++;
        }
    }

    a1->destOffset = a1->baseDestOffset;
    a1->ps_field_8 = a1->base->pst_field_A;
    a1->srcIndex++;

    srcIndex = a1->srcIndex;
    srcCount = a1->base->srcCount;

    if (srcIndex >= srcCount)
    {
        if (a1->ps_field_9)
            a1->ps_field_9--;
        a1->srcIndex = 0;
    }

    *a2 |= 1 << (a1->baseDestOffset >> 4);
}

static void unused_sub_80A1E40(struct PaletteStruct *a1, u32 *a2)
{
    if (gPaletteFade.active && ((1 << (a1->baseDestOffset >> 4)) & gPaletteFade_selectedPalettes))
    {
        if (!a1->base->pst_field_8_0)
        {
            if (gPaletteFade.delayCounter != gPaletteFade_delay)
            {
                BlendPalette(
                    a1->baseDestOffset,
                    a1->base->size,
                    gPaletteFade.y,
                    gPaletteFade.blendColor);
            }
        }
        else
        {
            if (!gPaletteFade.delayCounter)
            {
                if (a1->ps_field_8 != a1->base->pst_field_A)
                {
                    u32 srcOffset = a1->srcIndex * a1->base->size;
                    u8 i;

                    for (i = 0; i < a1->base->size; i++)
                        gPlttBufferFaded[a1->baseDestOffset + i] = a1->base->src[srcOffset + i];
                }
            }
        }
    }
}

static void unused_sub_80A1F00(struct PaletteStruct *a1)
{
    if (!a1->ps_field_9)
    {
        s32 val = a1->base->pst_field_B_5;

        if (!val)
        {
            a1->srcIndex = 0;
            a1->ps_field_8 = a1->base->pst_field_A;
            a1->ps_field_9 = a1->base->pst_field_C;
            a1->destOffset = a1->baseDestOffset;
        }
        else
        {
            if (val < 0)
                return;
            if (val > 2)
                return;
            ResetPaletteStructByUid(a1->base->uid);
        }
    }
    else
    {
        a1->ps_field_9--;
    }
}

void ResetPaletteStructByUid(u16 a1)
{
    u8 paletteNum = GetPaletteNumByUid(a1);
    if (paletteNum != 16)
        ResetPaletteStruct(paletteNum);
}

void ResetPaletteStruct(u8 paletteNum)
{
    sPaletteStructs[paletteNum].base = &gDummyPaletteStructTemplate;
    sPaletteStructs[paletteNum].ps_field_4_0 = 0;
    sPaletteStructs[paletteNum].baseDestOffset = 0;
    sPaletteStructs[paletteNum].destOffset = 0;
    sPaletteStructs[paletteNum].srcIndex = 0;
    sPaletteStructs[paletteNum].ps_field_4_1 = 0;
    sPaletteStructs[paletteNum].ps_field_8 = 0;
    sPaletteStructs[paletteNum].ps_field_9 = 0;
}

void ResetPaletteFadeControl(void)
{
    gPaletteFade.multipurpose1 = 0;
    gPaletteFade.multipurpose2 = 0;
    gPaletteFade.delayCounter = 0;
    gPaletteFade.y = 0;
    gPaletteFade.targetY = 0;
    gPaletteFade.blendColor = 0;
    gPaletteFade.active = 0;
    gPaletteFade.multipurpose2 = 0; // assign same value twice
    gPaletteFade.yDec = 0;
    gPaletteFade.bufferTransferDisabled = 0;
    gPaletteFade.shouldResetBlendRegisters = 0;
    gPaletteFade.hardwareFadeFinishing = 0;
    gPaletteFade.softwareFadeFinishing = 0;
    gPaletteFade.softwareFadeFinishingCounter = 0;
    gPaletteFade.objPaletteToggle = 0;
    gPaletteFade.deltaY = 2;
}

void unref_sub_80A2048(u16 uid)
{
    u8 paletteNum = GetPaletteNumByUid(uid);
    if (paletteNum != 16)
        sPaletteStructs[paletteNum].ps_field_4_1 = 1;
}

void unref_sub_80A2074(u16 uid)
{
    u8 paletteNum = GetPaletteNumByUid(uid);
    if (paletteNum != 16)
        sPaletteStructs[paletteNum].ps_field_4_1 = 0;
}

static u8 GetPaletteNumByUid(u16 uid)
{
    u8 i;

    for (i = 0; i < 16; i++)
        if (sPaletteStructs[i].base->uid == uid)
            return i;

    return 16;
}

static u8 UpdateNormalPaletteFade(void)
{
    u16 paletteOffset;
    u16 selectedPalettes;

    if (!gPaletteFade.active)
        return PALETTE_FADE_STATUS_DONE;

    if (IsSoftwarePaletteFadeFinishing())
    {
        return gPaletteFade.active ? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;
    }
    else
    {
        if (!gPaletteFade.objPaletteToggle)
        {
            if (gPaletteFade.delayCounter < gPaletteFade_delay)
            {
                gPaletteFade.delayCounter++;
                return 2;
            }
            gPaletteFade.delayCounter = 0;
        }

        paletteOffset = 0;

        if (!gPaletteFade.objPaletteToggle)
        {
            selectedPalettes = gPaletteFade_selectedPalettes;
        }
        else
        {
            selectedPalettes = gPaletteFade_selectedPalettes >> 16;
            paletteOffset = 256;
        }

        while (selectedPalettes)
        {
            if (selectedPalettes & 1)
                BlendPalette(
                    paletteOffset,
                    16,
                    gPaletteFade.y,
                    gPaletteFade.blendColor);
            selectedPalettes >>= 1;
            paletteOffset += 16;
        }

        gPaletteFade.objPaletteToggle ^= 1;

        if (!gPaletteFade.objPaletteToggle)
        {
            if (gPaletteFade.y == gPaletteFade.targetY)
            {
                gPaletteFade_selectedPalettes = 0;
                gPaletteFade.softwareFadeFinishing = 1;
            }
            else
            {
                s8 val;

                if (!gPaletteFade.yDec)
                {
                    val = gPaletteFade.y;
                    val += gPaletteFade.deltaY;
                    if (val > gPaletteFade.targetY)
                        val = gPaletteFade.targetY;
                    gPaletteFade.y = val;
                }
                else
                {
                    val = gPaletteFade.y;
                    val -= gPaletteFade.deltaY;
                    if (val < gPaletteFade.targetY)
                        val = gPaletteFade.targetY;
                    gPaletteFade.y = val;
                }
            }
        }

        // gPaletteFade.active cannot change since the last time it was checked. So this
        // is equivalent to `return PALETTE_FADE_STATUS_ACTIVE;`
        return gPaletteFade.active ? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;
    }
}

void InvertPlttBuffer(u32 selectedPalettes)
{
    u16 paletteOffset = 0;

    while (selectedPalettes)
    {
        if (selectedPalettes & 1)
        {
            u8 i;
            for (i = 0; i < 16; i++)
                gPlttBufferFaded[paletteOffset + i] = ~gPlttBufferFaded[paletteOffset + i];
        }
        selectedPalettes >>= 1;
        paletteOffset += 16;
    }
}

void TintPlttBuffer(u32 selectedPalettes, s8 r, s8 g, s8 b)
{
    u16 paletteOffset = 0;

    while (selectedPalettes)
    {
        if (selectedPalettes & 1)
        {
            u8 i;
            for (i = 0; i < 16; i++)
            {
                struct PlttData *data = (struct PlttData *)&gPlttBufferFaded[paletteOffset + i];
                data->r += r;
                data->g += g;
                data->b += b;
            }
        }
        selectedPalettes >>= 1;
        paletteOffset += 16;
    }
}

void UnfadePlttBuffer(u32 selectedPalettes)
{
    u16 paletteOffset = 0;

    while (selectedPalettes)
    {
        if (selectedPalettes & 1)
        {
            u8 i;
            for (i = 0; i < 16; i++)
                gPlttBufferFaded[paletteOffset + i] = gPlttBufferUnfaded[paletteOffset + i];
        }
        selectedPalettes >>= 1;
        paletteOffset += 16;
    }
}

void BeginFastPaletteFade(u8 submode)
{
    gPaletteFade.deltaY = 2;
    BeginFastPaletteFadeInternal(submode);
}

static void BeginFastPaletteFadeInternal(u8 submode)
{
    gPaletteFade.y = 31;
    gPaletteFade_submode = submode & 0x3F;
    gPaletteFade.active = 1;
    gPaletteFade.mode = FAST_FADE;

    if (submode == FAST_FADE_IN_FROM_BLACK)
        CpuFill16(RGB_BLACK, gPlttBufferFaded, PLTT_SIZE);

    if (submode == FAST_FADE_IN_FROM_WHITE)
        CpuFill16(RGB_WHITE, gPlttBufferFaded, PLTT_SIZE);

    UpdatePaletteFade();
}

static u8 UpdateFastPaletteFade(void)
{
    u16 i;
    u16 paletteOffsetStart;
    u16 paletteOffsetEnd;
    s8 r0;
    s8 g0;
    s8 b0;
    s8 r;
    s8 g;
    s8 b;

    if (!gPaletteFade.active)
        return PALETTE_FADE_STATUS_DONE;

    if (IsSoftwarePaletteFadeFinishing())
        return gPaletteFade.active ? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;
        

    if (gPaletteFade.objPaletteToggle)
    {
        paletteOffsetStart = 256;
        paletteOffsetEnd = 512;
    }
    else
    {
        paletteOffsetStart = 0;
        paletteOffsetEnd = 256;
    }

    switch (gPaletteFade_submode)
    {
    case FAST_FADE_IN_FROM_WHITE:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *unfaded;
            struct PlttData *faded;

            unfaded = (struct PlttData *)&gPlttBufferUnfaded[i];
            r0 = unfaded->r;
            g0 = unfaded->g;
            b0 = unfaded->b;

            faded = (struct PlttData *)&gPlttBufferFaded[i];
            r = faded->r - 2;
            g = faded->g - 2;
            b = faded->b - 2;

            if (r < r0)
                r = r0;
            if (g < g0)
                g = g0;
            if (b < b0)
                b = b0;

            gPlttBufferFaded[i] = RGB(r, g, b);
        }
        break;
    case FAST_FADE_OUT_TO_WHITE:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *data = (struct PlttData *)&gPlttBufferFaded[i];
            r = data->r + 2;
            g = data->g + 2;
            b = data->b + 2;

            if (r > 31)
                r = 31;
            if (g > 31)
                g = 31;
            if (b > 31)
                b = 31;

            gPlttBufferFaded[i] = RGB(r, g, b);
        }
        break;
    case FAST_FADE_IN_FROM_BLACK:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *unfaded;
            struct PlttData *faded;

            unfaded = (struct PlttData *)&gPlttBufferUnfaded[i];
            r0 = unfaded->r;
            g0 = unfaded->g;
            b0 = unfaded->b;

            faded = (struct PlttData *)&gPlttBufferFaded[i];
            r = faded->r + 2;
            g = faded->g + 2;
            b = faded->b + 2;

            if (r > r0)
                r = r0;
            if (g > g0)
                g = g0;
            if (b > b0)
                b = b0;

            gPlttBufferFaded[i] = RGB(r, g, b);
        }
        break;
    case FAST_FADE_OUT_TO_BLACK:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *data = (struct PlttData *)&gPlttBufferFaded[i];
            r = data->r - 2;
            g = data->g - 2;
            b = data->b - 2;

            if (r < 0)
                r = 0;
            if (g < 0)
                g = 0;
            if (b < 0)
                b = 0;

            gPlttBufferFaded[i] = RGB(r, g, b);
        }
    }

    gPaletteFade.objPaletteToggle ^= 1;

    if (gPaletteFade.objPaletteToggle)
        // gPaletteFade.active cannot change since the last time it was checked. So this
        // is equivalent to `return PALETTE_FADE_STATUS_ACTIVE;`
        return gPaletteFade.active ? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;

    if (gPaletteFade.y - gPaletteFade.deltaY < 0)
        gPaletteFade.y = 0;
    else
        gPaletteFade.y -= gPaletteFade.deltaY;

    if (gPaletteFade.y == 0)
    {
        switch (gPaletteFade_submode)
        {
        case FAST_FADE_IN_FROM_WHITE:
        case FAST_FADE_IN_FROM_BLACK:
            CpuCopy32(gPlttBufferUnfaded, gPlttBufferFaded, PLTT_SIZE);
            break;
        case FAST_FADE_OUT_TO_WHITE:
            CpuFill32(0xFFFFFFFF, gPlttBufferFaded, PLTT_SIZE);
            break;
        case FAST_FADE_OUT_TO_BLACK:
            CpuFill32(0x00000000, gPlttBufferFaded, PLTT_SIZE);
            break;
        }

        gPaletteFade.mode = NORMAL_FADE;
        gPaletteFade.softwareFadeFinishing = 1;
    }
    
    // gPaletteFade.active cannot change since the last time it was checked. So this
    // is equivalent to `return PALETTE_FADE_STATUS_ACTIVE;`
    return gPaletteFade.active ? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;
}

void BeginHardwarePaletteFade(u8 blendCnt, u8 delay, u8 y, u8 targetY, u8 shouldResetBlendRegisters)
{
    gPaletteFade_blendCnt = blendCnt;
    gPaletteFade.delayCounter = delay;
    gPaletteFade_delay = delay;
    gPaletteFade.y = y;
    gPaletteFade.targetY = targetY;
    gPaletteFade.active = 1;
    gPaletteFade.mode = HARDWARE_FADE;
    gPaletteFade.shouldResetBlendRegisters = shouldResetBlendRegisters & 1;
    gPaletteFade.hardwareFadeFinishing = 0;

    if (y < targetY)
        gPaletteFade.yDec = 0;
    else
        gPaletteFade.yDec = 1;
}

static u8 UpdateHardwarePaletteFade(void)
{
    if (!gPaletteFade.active)
        return PALETTE_FADE_STATUS_DONE;

    if (gPaletteFade.delayCounter < gPaletteFade_delay)
    {
        gPaletteFade.delayCounter++;
        return PALETTE_FADE_STATUS_DELAY;
    }

    gPaletteFade.delayCounter = 0;

    if (!gPaletteFade.yDec)
    {
        gPaletteFade.y++;
        if (gPaletteFade.y > gPaletteFade.targetY)
        {
            gPaletteFade.hardwareFadeFinishing++;
            gPaletteFade.y--;
        }
    }
    else
    {
        s32 y = gPaletteFade.y--;
        if (y - 1 < gPaletteFade.targetY)
        {
            gPaletteFade.hardwareFadeFinishing++;
            gPaletteFade.y++;
        }
    }

    if (gPaletteFade.hardwareFadeFinishing)
    {
        if (gPaletteFade.shouldResetBlendRegisters)
        {
            gPaletteFade_blendCnt = 0;
            gPaletteFade.y = 0;
        }
        gPaletteFade.shouldResetBlendRegisters = 0;
    }

    // gPaletteFade.active cannot change since the last time it was checked. So this
    // is equivalent to `return PALETTE_FADE_STATUS_ACTIVE;`
    return gPaletteFade.active ? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;
}

static void UpdateBlendRegisters(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, (u16)gPaletteFade_blendCnt);
    SetGpuReg(REG_OFFSET_BLDY, gPaletteFade.y);
    if (gPaletteFade.hardwareFadeFinishing)
    {
        gPaletteFade.hardwareFadeFinishing = 0;
        gPaletteFade.mode = 0;
        gPaletteFade_blendCnt = 0;
        gPaletteFade.y = 0;
        gPaletteFade.active = 0;
    }
}

static bool8 IsSoftwarePaletteFadeFinishing(void)
{
    if (gPaletteFade.softwareFadeFinishing)
    {
        if (gPaletteFade.softwareFadeFinishingCounter == 4)
        {
            gPaletteFade.active = 0;
            gPaletteFade.softwareFadeFinishing = 0;
            gPaletteFade.softwareFadeFinishingCounter = 0;
        }
        else
        {
            gPaletteFade.softwareFadeFinishingCounter++;
        }

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void BlendPalettes(u32 selectedPalettes, u8 coeff, u16 color)
{
    u16 paletteOffset;

    for (paletteOffset = 0; selectedPalettes; paletteOffset += 16)
    {
        if (selectedPalettes & 1)
            BlendPalette(paletteOffset, 16, coeff, color);
        selectedPalettes >>= 1;
    }
}

void BlendPalettesUnfaded(u32 selectedPalettes, u8 coeff, u16 color)
{
    void *src = gPlttBufferUnfaded;
    void *dest = gPlttBufferFaded;
    DmaCopy32(3, src, dest, PLTT_SIZE);
    BlendPalettes(selectedPalettes, coeff, color);
}

void TintPalette_GrayScale(u16 *palette, u16 count)
{
    s32 r, g, b, i;
    u32 gray;

    for (i = 0; i < count; i++)
    {
        r = GET_R(*palette);
        g = GET_G(*palette);
        b = GET_B(*palette);

        gray = (r * Q_8_8(0.3) + g * Q_8_8(0.59) + b * Q_8_8(0.1133)) >> 8;

        *palette++ = RGB2(gray, gray, gray);
    }
}

void TintPalette_GrayScale2(u16 *palette, u16 count)
{
    s32 r, g, b, i;
    u32 gray;

    for (i = 0; i < count; i++)
    {
        r = GET_R(*palette);
        g = GET_G(*palette);
        b = GET_B(*palette);

        gray = (r * Q_8_8(0.3) + g * Q_8_8(0.59) + b * Q_8_8(0.1133)) >> 8;

        if (gray > 31)
            gray = 31;

        gray = sRoundedDownGrayscaleMap[gray];

        *palette++ = RGB2(gray, gray, gray);
    }
}

void TintPalette_SepiaTone(u16 *palette, u16 count)
{
    s32 r, g, b, i;
    u32 gray;

    for (i = 0; i < count; i++)
    {
        r = GET_R(*palette);
        g = GET_G(*palette);
        b = GET_B(*palette);

        gray = (r * Q_8_8(0.3) + g * Q_8_8(0.59) + b * Q_8_8(0.1133)) >> 8;

        r = (u16)((Q_8_8(1.2) * gray)) >> 8;
        g = (u16)((Q_8_8(1.0) * gray)) >> 8;
        b = (u16)((Q_8_8(0.94) * gray)) >> 8;

        if (r > 31)
            r = 31;

        *palette++ = RGB2(r, g, b);
    }
}

void TintPalette_CustomTone(u16 *palette, u16 count, u16 rTone, u16 gTone, u16 bTone)
{
    s32 r, g, b, i;
    u32 gray;

    for (i = 0; i < count; i++)
    {
        r = GET_R(*palette);
        g = GET_G(*palette);
        b = GET_B(*palette);

        gray = (r * Q_8_8(0.3) + g * Q_8_8(0.59) + b * Q_8_8(0.1133)) >> 8;

        r = (u16)((rTone * gray)) >> 8;
        g = (u16)((gTone * gray)) >> 8;
        b = (u16)((bTone * gray)) >> 8;

        if (r > 31)
            r = 31;
        if (g > 31)
            g = 31;
        if (b > 31)
            b = 31;

        *palette++ = RGB2(r, g, b);
    }
}

#define tCoeff       data[0]
#define tCoeffTarget data[1]
#define tCoeffDelta  data[2]
#define tDelay       data[3]
#define tDelayTimer  data[4]
#define tPalettes    5 // data[5] and data[6], set/get via Set/GetWordTaskArg
#define tColor       data[7]
#define tId          data[8]

// Blend the selected palettes in a series of steps toward or away from the color.
// Only used by the Groudon/Kyogre fight scene to flash the screen for lightning
// One call is used to fade the bg from white, while another fades the duo from black
void BlendPalettesGradually(u32 selectedPalettes, s8 delay, u8 coeff, u8 coeffTarget, u16 color, u8 priority, u8 id)
{
    u8 taskId;

    taskId = CreateTask((void *)Task_BlendPalettesGradually, priority);
    gTasks[taskId].tCoeff = coeff;
    gTasks[taskId].tCoeffTarget = coeffTarget;

    if (delay >= 0)
    {
        gTasks[taskId].tDelay = delay;
        gTasks[taskId].tCoeffDelta = 1;
    }
    else
    {
        gTasks[taskId].tDelay = 0;
        gTasks[taskId].tCoeffDelta = -delay + 1;
    }

    if (coeffTarget < coeff)
        gTasks[taskId].tCoeffDelta *= -1;

    SetWordTaskArg(taskId, tPalettes, selectedPalettes);
    gTasks[taskId].tColor = color;
    gTasks[taskId].tId = id;
    gTasks[taskId].func(taskId);
}

// Unused
static bool32 IsBlendPalettesGraduallyTaskActive(u8 id)
{
    int i;

    for (i = 0; i < NUM_TASKS; i++)
        if ((gTasks[i].isActive == TRUE) 
            && (gTasks[i].func == Task_BlendPalettesGradually) 
            && (gTasks[i].tId == id))
            return TRUE;

    return FALSE;
}

// Unused
static void DestroyBlendPalettesGraduallyTask(void)
{
    u8 taskId;

    while (1)
    {
        taskId = FindTaskIdByFunc(Task_BlendPalettesGradually);
        if (taskId == TASK_NONE)
            break;
        DestroyTask(taskId);
    }
}

static void Task_BlendPalettesGradually(u8 taskId)
{
    u32 palettes;
    s16 *data;
    s16 target;

    data = gTasks[taskId].data;
    palettes = GetWordTaskArg(taskId, tPalettes);

    if (++tDelayTimer > tDelay)
    {
        tDelayTimer = 0;
        BlendPalettes(palettes, tCoeff, tColor);
        target = tCoeffTarget;
        if (tCoeff == target)
        {
            DestroyTask(taskId);
        }
        else
        {
            tCoeff += tCoeffDelta;
            if (tCoeffDelta >= 0)
            {
                if (tCoeff < target)
                    return;
            }
            else if (tCoeff > target)
            {
                return;
            }
            tCoeff = target;
        }
    }
}
