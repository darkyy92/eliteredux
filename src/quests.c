#include "global.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_icon.h"
#include "item_use.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "quests.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"

#define tCount          data[2]
#define tPageItems      data[4]
#define tItemPcParam    data[6]
#define tWindowId       data[10]
#define tListMenuTaskId data[11]

#define tState          data[0]
#define tXSpeed         data[1]
#define tYSpeed         data[2]
#define tWin0Left       data[3]
#define tWin0Right      data[4]
#define tWin0Top        data[5]
#define tWin0Bottom     data[6]
#define tBldCntBak      data[7]
#define tBldYBak        data[8]


struct QuestMenuResources
{
    /*0x00*/ MainCallback savedCallback;
    /*0x04*/ u8 moveModeOrigPos;
    /*0x05*/ u8 itemMenuIconSlot;
    /*0x06*/ u8 maxShowed;
    /*0x07*/ u8 nItems;
    /*0x08*/ u8 scrollIndicatorArrowPairId;
    /*0x0A*/ u16 withdrawQuantitySubmenuCursorPos;
    /*0x0C*/ s16 data[3];
}; /* size = 0x14 */

struct QuestMenuStaticResources
{
    /*0x00*/ MainCallback savedCallback;
    /*0x04*/ u16 scroll;
    /*0x06*/ u16 row;
    /*0x08*/ u8 initialized;
};  /* size = 0xC */

// RAM
EWRAM_DATA static struct QuestMenuResources *sStateDataPtr = NULL;
EWRAM_DATA static u8 *sBg1TilemapBuffer = NULL;
EWRAM_DATA static struct ListMenuItem *sListMenuItems = NULL;
EWRAM_DATA static struct QuestMenuStaticResources sListMenuState = {0};
EWRAM_DATA static u8 sSubmenuWindowIds[3] = {0};
EWRAM_DATA static u8 gUnknown_2039878[12] = {0};        // from pokefirered src/item_menu_icons.c

// This File's Functions
static void DebugQuestMenu(void);
static void QuestMenu_RunSetup(void);
static bool8 QuestMenu_DoGfxSetup(void);
static void QuestMenu_FadeAndBail(void);
static void Task_QuestMenuWaitFadeAndBail(u8 taskId);
static bool8 QuestMenu_InitBgs(void);
static bool8 QuestMenu_LoadGraphics(void);
static bool8 QuestMenu_AllocateResourcesForListMenu(void);
static void QuestMenu_BuildListMenuTemplate(void);
static void QuestMenu_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu * list);
static void QuestMenu_ItemPrintFunc(u8 windowId, u32 itemId, u8 y);
static void QuestMenu_PrintOrRemoveCursorAt(u8 y, u8 state);
static void QuestMenu_PrintHeader(void);
static void QuestMenu_PlaceTopMenuScrollIndicatorArrows(void);
static void QuestMenu_SetCursorPosition(void);
static void QuestMenu_FreeResources(void);
static void Task_QuestMenuTurnOff2(u8 taskId);
static void QuestMenu_InitItems(void);
static void QuestMenu_SetScrollPosition(void);
static void Task_QuestMenuMain(u8 taskId);
static void QuestMenu_InsertItemIntoNewSlot(u8 taskId, u32 pos);
static void Task_QuestMenuSubmenuInit(u8 taskId);
static void Task_QuestMenuSubmenuRun(u8 taskId);
static void Task_QuestMenuDetails(u8 taskId);
static void Task_QuestMenuReward(u8 taskId);
static void Task_QuestMenuBeginQuest(u8 taskId);
static void Task_QuestMenuEndQuest(u8 taskId);
static void QuestMenu_DisplaySubMenuMessage(u8 taskId);
static void Task_QuestMenuRefreshAfterAcknowledgement(u8 taskId);
static void Task_QuestMenuCleanUp(u8 taskId);
static void QuestMenu_WithdrawMultipleInitWindow(u16 slotId);
static void Task_QuestMenuCancel(u8 taskId);
static void QuestMenu_InitWindows(void);
static void QuestMenu_AddTextPrinterParameterized(u8 windowId, u8 fontId, const u8 * str, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorIdx);
static void QuestMenu_SetBorderStyleOnWindow(u8 windowId);
static u8 QuestMenu_GetOrCreateSubwindow(u8 idx);
static void QuestMenu_DestroySubwindow(u8 idx);
static void QuestMenu_SetInitializedFlag(u8 a0);
static bool8 IsActiveQuest(u8 questId);

// Data
// graphics
static const u32 sQuestMenuTiles[] = INCBIN_U32("graphics/quest_menu/menu.4bpp.lz");
static const u32 sQuestMenuBgPals[] = INCBIN_U32("graphics/quest_menu/menu_pal.gbapal.lz");
static const u32 sQuestMenuTilemap[] = INCBIN_U32("graphics/quest_menu/tilemap.bin.lz");
static const u16 sMainWindowPal[] = INCBIN_U16("graphics/quest_menu/main_window.gbapal");

// text window from firered
static const u16 sFR_StdFrame0[] = INCBIN_U16("graphics/text_window/fr_std0.4bpp");
//static const u16 sFR_StdFrame1[] = INCBIN_U16("graphics/text_window/fr_std1.4bpp");
static const u16 sFR_MessageBoxTiles[] = INCBIN_U16("graphics/text_window/fr_message_box.4bpp");

// strings
static const u8 sText_Empty[] = _("");
static const u8 sText_Quests[] = _("   Side\n Quests");
static const u8 sText_QuestMenu_Begin[] = _("Begin");
static const u8 sText_QuestMenu_End[] = _("End");
static const u8 sText_QuestMenu_Details[] = _("Details");
static const u8 sText_QuestMenu_Reward[] = _("Reward");
static const u8 sText_QuestMenu_Unk[] = _("{COLOR}{LIGHT_GRAY}?????????");
static const u8 sText_QuestMenu_Active[] = _("{COLOR}{GREEN}Active");
static const u8 sText_QuestMenu_Complete[] = _("{COLOR}{BLUE}Done");
static const u8 sText_QuestMenu_Exit[] = _("Exit the Quest Menu");
static const u8 sText_QuestMenu_SelectedQuest[] = _("Do what with\nthis quest?");
static const u8 sText_QuestMenu_DisplayDetails[] = _("POC: {STR_VAR_1}\nMap: {STR_VAR_2}");
static const u8 sText_QuestMenu_DisplayReward[] = _("Reward:\n{STR_VAR_1}");
static const u8 sText_QuestMenu_BeginQuest[] = _("Initiating Quest:\n{STR_VAR_1}");
static const u8 sText_QuestMenu_EndQuest[] = _("Cancelling Quest:\n{STR_VAR_1}");

static const struct SideQuest sSideQuests[SIDE_QUEST_COUNT] =
{
    [SIDE_QUEST_1] = 
    {
        .name       = _("Your First Badge"),
        .desc       = _("Get your first badge"),
        .poc        = _("No idea what this means"),
        .map        = _("Rustboro City"),
        .hint       = _("Roxanne"),
        .reward     = _("Nothing :D"),
        .difficulty = QUEST_DIFFICULTY_EASY,
        .type       = QUEST_TYPE_MAIN_STORY,
    },
    [SIDE_QUEST_2] = 
    {
        .name       = _("Side Quest Name"),
        .desc       = _("Description"),
        .poc        = _("POC"),
        .map        = _("Map"),
        .hint       = _("Hint"),
        .reward     = _("Reward"),
        .difficulty = QUEST_DIFFICULTY_EASY,
        .type       = QUEST_TYPE_MAIN_STORY,
    },
    [SIDE_QUEST_3] = 
    {
        .name       = _("Side Quest Name"),
        .desc       = _("Description"),
        .poc        = _("POC"),
        .map        = _("Map"),
        .hint       = _("Hint"),
        .reward     = _("Reward"),
        .difficulty = QUEST_DIFFICULTY_EASY,
        .type       = QUEST_TYPE_MAIN_STORY,
    },
    [SIDE_QUEST_4] = 
    {
        .name       = _("Side Quest Name"),
        .desc       = _("Description"),
        .poc        = _("POC"),
        .map        = _("Map"),
        .hint       = _("Hint"),
        .reward     = _("Reward"),
        .difficulty = QUEST_DIFFICULTY_EASY,
        .type       = QUEST_TYPE_MAIN_STORY,
    },
    [SIDE_QUEST_5] = 
    {
        .name       = _("Side Quest Name"),
        .desc       = _("Description"),
        .poc        = _("POC"),
        .map        = _("Map"),
        .hint       = _("Hint"),
        .reward     = _("Reward"),
        .difficulty = QUEST_DIFFICULTY_EASY,
        .type       = QUEST_TYPE_MAIN_STORY,
    },
    [SIDE_QUEST_6] = 
    {
        .name       = _("Side Quest Name"),
        .desc       = _("Description"),
        .poc        = _("POC"),
        .map        = _("Map"),
        .hint       = _("Hint"),
        .reward     = _("Reward"),
        .difficulty = QUEST_DIFFICULTY_EASY,
        .type       = QUEST_TYPE_MAIN_STORY,
    },
    [SIDE_QUEST_7] = 
    {
        .name       = _("Side Quest Name"),
        .desc       = _("Description"),
        .poc        = _("POC"),
        .map        = _("Map"),
        .hint       = _("Hint"),
        .reward     = _("Reward"),
        .difficulty = QUEST_DIFFICULTY_EASY,
        .type       = QUEST_TYPE_MAIN_STORY,
    },
    [SIDE_QUEST_8] = 
    {
        .name       = _("Side Quest Name"),
        .desc       = _("Description"),
        .poc        = _("POC"),
        .map        = _("Map"),
        .hint       = _("Hint"),
        .reward     = _("Reward"),
        .difficulty = QUEST_DIFFICULTY_EASY,
        .type       = QUEST_TYPE_MAIN_STORY,
    },
    [SIDE_QUEST_9] = 
    {
        .name       = _("Side Quest Name"),
        .desc       = _("Description"),
        .poc        = _("POC"),
        .map        = _("Map"),
        .hint       = _("Hint"),
        .reward     = _("Reward"),
        .difficulty = QUEST_DIFFICULTY_EASY,
        .type       = QUEST_TYPE_MAIN_STORY,
    },
    [SIDE_QUEST_10] = 
    {
        .name       = _("Side Quest Name"),
        .desc       = _("Description"),
        .poc        = _("POC"),
        .map        = _("Map"),
        .hint       = _("Hint"),
        .reward     = _("Reward"),
        .difficulty = QUEST_DIFFICULTY_EASY,
        .type       = QUEST_TYPE_MAIN_STORY,
    },
};

static const u16 sSideQuestDifficultyItemIds[] = 
{
	ITEM_POKE_BALL,
	ITEM_GREAT_BALL,
	ITEM_ULTRA_BALL,
	ITEM_MASTER_BALL,
};

// Selected an incomplete quest
static const struct MenuAction sQuestSubmenuOptions[] =
{
    {sText_QuestMenu_Begin,             {.void_u8 = Task_QuestMenuBeginQuest}},
    {sText_QuestMenu_Details,           {.void_u8 = Task_QuestMenuDetails}},
    {gText_Cancel,                      {.void_u8 = Task_QuestMenuCancel}},
};

// Selected the active quest
static const struct MenuAction sActiveQuestSubmenuOptions[] =
{
    {sText_QuestMenu_End,               {.void_u8 = Task_QuestMenuEndQuest}},
    {sText_QuestMenu_Details,           {.void_u8 = Task_QuestMenuDetails}},
    {gText_Cancel,                      {.void_u8 = Task_QuestMenuCancel}},
};

// completed quest selection
static const struct MenuAction sCompletedQuestSubmenuOptions[] =
{
    {sText_QuestMenu_Reward,            {.void_u8 = Task_QuestMenuReward}},
    {sText_QuestMenu_Details,           {.void_u8 = Task_QuestMenuDetails}},
    {gText_Cancel,                      {.void_u8 = Task_QuestMenuCancel}},
};

static const struct BgTemplate sQuestMenuBgTemplates[2] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 0
    }, 
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 1
    }
};

static const u8 sQuestMenuWindowFontColors[][3] = 
{
    {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GRAY},
    {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_DARK_GRAY,  TEXT_COLOR_LIGHT_GRAY},
    {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_LIGHT_GRAY, TEXT_COLOR_DARK_GRAY},
    {TEXT_COLOR_TRANSPARENT,  TEXT_DYNAMIC_COLOR_1,  TEXT_COLOR_DARK_GRAY}
};

static const struct WindowTemplate sQuestMenuHeaderWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 0x07,
        .tilemapTop = 0x01,
        .width = 0x13,
        .height = 0x0c,
        .paletteNum = 0x0f,
        .baseBlock = 0x02bf
    }, 
    {
        .bg = 0,
        .tilemapLeft = 0x05,
        .tilemapTop = 0x0e,
        .width = 0x19,
        .height = 0x06,
        .paletteNum = 0x0d,
        .baseBlock = 0x0229
    }, 
    {
        .bg = 0,
        .tilemapLeft = 0x01,
        .tilemapTop = 0x01,
        .width = 0x05,
        .height = 0x04,
        .paletteNum = 15,
        .baseBlock = 0x0215
    }, 
    {
        .bg = 0,
        .tilemapLeft = 0x18,
        .tilemapTop = 0x0f,
        .width = 0x05,
        .height = 0x04,
        .paletteNum = 15,
        .baseBlock = 0x0201
    }, 
    {   // submenu cursor selection window
        .bg = 0,
        .tilemapLeft = 0x16,
        .tilemapTop = 0xD,  //+2 for 4 options
        .width = 0x07,
        .height = 0x06,     //+2 for 4 options
        .paletteNum = 15,
        .baseBlock = 0x01d7
    }, 
    {
        .bg = 0,
        .tilemapLeft = 0x02,
        .tilemapTop = 0x0f,
        .width = 0x1a,
        .height = 0x04,
        .paletteNum = 0x0b,
        .baseBlock = 0x016f
    }, 
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sQuestMenuSubWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 0x06,
        .tilemapTop = 0x0f,
        .width = 0x0e,
        .height = 0x04,
        .paletteNum = 12,
        .baseBlock = 0x0137
    }, 
    {
        .bg = 0,
        .tilemapLeft = 0x06,
        .tilemapTop = 0x0f,
        .width = 0x10,
        .height = 0x04,
        .paletteNum = 12,
        .baseBlock = 0x0137
    }, 
    {
        .bg = 0,
        .tilemapLeft = 0x06,
        .tilemapTop = 0x0f,
        .width = 0x17,
        .height = 0x04,
        .paletteNum = 12,
        .baseBlock = 0x009b
    }
};

// Functions -> ported from pokefirered
void QuestMenu_Init(u8 a0, MainCallback callback)
{
    u8 i;

    if (a0 >= 2)
    {
        SetMainCallback2(callback);
        return;
    }
    
    if ((sStateDataPtr = Alloc(sizeof(struct QuestMenuResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    
    if (a0 != 1)
    {
        sListMenuState.savedCallback = callback;
        sListMenuState.scroll = sListMenuState.row = 0;
    }
    
    sStateDataPtr->moveModeOrigPos = 0xFF;
    sStateDataPtr->itemMenuIconSlot = 0;
    sStateDataPtr->scrollIndicatorArrowPairId = 0xFF;
    sStateDataPtr->savedCallback = 0;
    for (i = 0; i < 3; i++)
    {
        sStateDataPtr->data[i] = 0;
    }
    
    SetMainCallback2(QuestMenu_RunSetup);
}

static void QuestMenu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void QuestMenu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void QuestMenu_RunSetup(void)
{
    while (1)
    {
        if (QuestMenu_DoGfxSetup() == TRUE)
            break;
    }
}

// from pc_screen_effect
static void BeginPCScreenEffect(TaskFunc task, u16 a1, u16 a2, u16 priority)
{
    u8 taskId = CreateTask(task, priority);
    gTasks[taskId].data[0] = 0;
    if (a1 == 0)
        gTasks[taskId].data[1] = 16;
    else
        gTasks[taskId].data[1] = 0;
    
    if (a1 == 0)
        gTasks[taskId].data[2] = 20;
    else
        gTasks[taskId].data[2] = 0;
    
    gTasks[taskId].func(taskId);
}

/// from pc_screen_effect
static void Task_PCScreenEffect_TurnOn(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        task->tWin0Left = 120;
        task->tWin0Right = 120;
        task->tWin0Top = 80;
        task->tWin0Bottom = 81;
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->tWin0Left, task->tWin0Right));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWin0Top, task->tWin0Bottom));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        break;
    case 1:
        task->tBldCntBak = GetGpuReg(REG_OFFSET_BLDCNT);
        task->tBldYBak = GetGpuReg(REG_OFFSET_BLDY);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_EFFECT_LIGHTEN);
        SetGpuReg(REG_OFFSET_BLDY, 16);
        break;
    case 2:
        task->tWin0Left -= task->tXSpeed;
        task->tWin0Right += task->tXSpeed;
        if (task->tWin0Left <= 0 || task->tWin0Right >= DISPLAY_WIDTH)
        {
            task->tWin0Left = 0;
            task->tWin0Right = DISPLAY_WIDTH;
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_BLDCNT, task->tBldCntBak);
            BlendPalettes(0xFFFFFFFF, 0, RGB_BLACK);
            gPlttBufferFaded[0] = 0;
        }
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->tWin0Left, task->tWin0Right));
        if (task->tWin0Left)
            return;
        break;
    case 3:
        task->tWin0Top -= task->tYSpeed;
        task->tWin0Bottom += task->tYSpeed;
        if (task->tWin0Top <= 0 || task->tWin0Bottom >= DISPLAY_HEIGHT)
        {
            task->tWin0Top = 0;
            task->tWin0Bottom = DISPLAY_HEIGHT;
            ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        }
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWin0Top, task->tWin0Bottom));
        if (task->tWin0Top)
            return;
        break;
    default:
        SetGpuReg(REG_OFFSET_BLDCNT, task->tBldCntBak);
        DestroyTask(taskId);
        return;
    }
    ++task->tState;
}

// from pc_screen_effect
static void BeginPCScreenEffect_TurnOn(u16 a0, u16 a1, u16 a2)
{
    BeginPCScreenEffect(Task_PCScreenEffect_TurnOn, a0, a1, a2);
}

static bool8 QuestMenu_DoGfxSetup(void)
{
    u8 taskId;
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 3:
        ResetPaletteFade();
        gMain.state++;
        break;
    case 4:
        ResetSpriteData();
        gMain.state++;
        break;
    case 5:
        ResetItemMenuIconState();
        gMain.state++;
        break;
    case 6:
        ResetTasks();
        gMain.state++;
        break;
    case 7:
        if (QuestMenu_InitBgs())
        {
            sStateDataPtr->data[0] = 0;
            gMain.state++;
        }
        else
        {
            QuestMenu_FadeAndBail();
            return TRUE;
        }
        break;
    case 8:
        if (QuestMenu_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 9:
        QuestMenu_InitWindows();
        gMain.state++;
        break;
    case 10:
        QuestMenu_InitItems();
        QuestMenu_SetCursorPosition();
        QuestMenu_SetScrollPosition();
        gMain.state++;
        break;
    case 11:
        if (QuestMenu_AllocateResourcesForListMenu())
        {
            gMain.state++;
        }
        else
        {
            QuestMenu_FadeAndBail();
            return TRUE;
        }
        break;
    case 12:
        QuestMenu_BuildListMenuTemplate();
        gMain.state++;
        break;
    case 13:
        QuestMenu_PrintHeader();
        gMain.state++;
        break;
    case 14:
        //sub_80985E4();
        gMain.state++;
        break;
    case 15:
        taskId = CreateTask(Task_QuestMenuMain, 0);
        gTasks[taskId].data[0] = ListMenuInit(&gMultiuseListMenuTemplate, sListMenuState.scroll, sListMenuState.row);
        gMain.state++;
        break;
    case 16:
        QuestMenu_PlaceTopMenuScrollIndicatorArrows();
        gMain.state++;
        break;
    case 17:
        //HelpSystem_SetSomeVariable2(29);
        gMain.state++;
        break;
    case 18:
        if (sListMenuState.initialized == 1)
        {
            BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        }
        gMain.state++;
        break;
    case 19:
        if (sListMenuState.initialized == 1)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        }
        else
        {
            BeginPCScreenEffect_TurnOn(0, 0, 0);
            QuestMenu_SetInitializedFlag(1);
            PlaySE(SE_PC_LOGIN);
        }
        gMain.state++;
        break;
    case 20:
        //if ((u8)sub_80BF72C() != TRUE)
            //gMain.state++;
        gMain.state++;
        break;
    default:
        SetVBlankCallback(QuestMenu_VBlankCB);
        SetMainCallback2(QuestMenu_MainCB);
        return TRUE;
    }
    return FALSE;
}

static void QuestMenu_FadeAndBail(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_QuestMenuWaitFadeAndBail, 0);
    SetVBlankCallback(QuestMenu_VBlankCB);
    SetMainCallback2(QuestMenu_MainCB);
}

static void Task_QuestMenuWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sListMenuState.savedCallback);
        QuestMenu_FreeResources();
        DestroyTask(taskId);
    }
}

static bool8 QuestMenu_InitBgs(void)
{
    ResetAllBgsCoordinatesAndBgCntRegs();
    sBg1TilemapBuffer = Alloc(0x800);
    if (sBg1TilemapBuffer == NULL)
        return FALSE;
    
    memset(sBg1TilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sQuestMenuBgTemplates, NELEMS(sQuestMenuBgTemplates));
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    SetGpuReg(REG_OFFSET_BLDCNT , 0);
    ShowBg(0);
    ShowBg(1);
    return TRUE;
}

static bool8 QuestMenu_LoadGraphics(void)
{
    switch (sStateDataPtr->data[0])
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sQuestMenuTiles, 0, 0, 0);
        sStateDataPtr->data[0]++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sQuestMenuTilemap, sBg1TilemapBuffer);
            sStateDataPtr->data[0]++;
        }
        break;
    case 2:
        LoadCompressedPalette(sQuestMenuBgPals, 0x00, 0x60);
        sStateDataPtr->data[0]++;
        break;
    case 3:
        //LoadCompressedSpriteSheet(&gBagSwapSpriteSheet);
        sStateDataPtr->data[0]++;
        break;
    default:
        //LoadCompressedSpritePalette(&gBagSwapSpritePalette);
        sStateDataPtr->data[0] = 0;
        return TRUE;
    }
    return FALSE;
}

#define try_alloc(ptr__, size) ({ \
    void ** ptr = (void **)&(ptr__);             \
    *ptr = Alloc(size);                 \
    if (*ptr == NULL)                   \
    {                                   \
        QuestMenu_FreeResources();                  \
        QuestMenu_FadeAndBail();                  \
        return FALSE;                   \
    }                                   \
})

static bool8 QuestMenu_AllocateResourcesForListMenu(void)
{
    try_alloc(sListMenuItems, sizeof(struct ListMenuItem) * (SIDE_QUEST_COUNT + 1));
    //try_alloc(sUnusedStringAllocation, 14 * (PC_ITEMS_COUNT + 1));
    return TRUE;
}

static void QuestMenu_BuildListMenuTemplate(void)
{
    u16 i;

    for (i = 0; i < sStateDataPtr->nItems; i++)
    {
        #ifdef DEBUG_BUILD
            sListMenuItems[i].name = sSideQuests[i].name;
        #else
            if (gSaveBlock2Ptr->questStatus[i] >= QUEST_STATUS_UNLOCKED)
                sListMenuItems[i].name = sSideQuests[i].name;
            else
                sListMenuItems[i].name = sText_QuestMenu_Unk;
        #endif
        
        sListMenuItems[i].id = i;
    }
    sListMenuItems[i].name = gText_Cancel;
    sListMenuItems[i].id = LIST_CANCEL;

    gMultiuseListMenuTemplate.items = sListMenuItems;
    gMultiuseListMenuTemplate.totalItems = sStateDataPtr->nItems + 1;
    gMultiuseListMenuTemplate.windowId = 0;
    gMultiuseListMenuTemplate.header_X = 0;
    gMultiuseListMenuTemplate.item_X = 9;
    gMultiuseListMenuTemplate.cursor_X = 1;
    gMultiuseListMenuTemplate.lettersSpacing = 1;
    gMultiuseListMenuTemplate.itemVerticalPadding = 2;
    gMultiuseListMenuTemplate.upText_Y = 2;
    gMultiuseListMenuTemplate.maxShowed = sStateDataPtr->maxShowed;
    gMultiuseListMenuTemplate.fontId = 2;
    gMultiuseListMenuTemplate.cursorPal = 2;
    gMultiuseListMenuTemplate.fillValue = 0;
    gMultiuseListMenuTemplate.cursorShadowPal = 3;
    gMultiuseListMenuTemplate.moveCursorFunc = QuestMenu_MoveCursorFunc;
    gMultiuseListMenuTemplate.itemPrintFunc = QuestMenu_ItemPrintFunc;
    gMultiuseListMenuTemplate.scrollMultiple = 0;
    gMultiuseListMenuTemplate.cursorKind = 0;
}

void CreateItemMenuIcon(u16 itemId, u8 idx)
{
    u8 * ptr = &gUnknown_2039878[10];
    u8 spriteId;

    if (ptr[idx] == 0xFF)
    {
        FreeSpriteTilesByTag(102 + idx);
        FreeSpritePaletteByTag(102 + idx);
        spriteId = AddItemIconSprite(102 + idx, 102 + idx, itemId);
        if (spriteId != MAX_SPRITES)
        {
            ptr[idx] = spriteId;
            gSprites[spriteId].x2 = 24;
            gSprites[spriteId].y2 = 140;
        }
    }
}

void ResetItemMenuIconState(void)
{
    u16 i;

    for (i = 0; i < NELEMS(gUnknown_2039878); i++)
        gUnknown_2039878[i] = 0xFF;
}

void DestroyItemMenuIcon(u8 idx)
{
    u8 * ptr = &gUnknown_2039878[10];

    if (ptr[idx] != 0xFF)
    {
        DestroySpriteAndFreeResources(&gSprites[ptr[idx]]);
        ptr[idx] = 0xFF;
    }
}

static void QuestMenu_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu * list)
{
    u16 itemId;
    const u8 * desc;
    
    if (onInit != TRUE)
        PlaySE(SE_SELECT);

    if (sStateDataPtr->moveModeOrigPos == 0xFF)
    {
        DestroyItemMenuIcon(sStateDataPtr->itemMenuIconSlot ^ 1);
        if (itemIndex != LIST_CANCEL)
        {
            if (GetSetQuestFlag(itemIndex, FLAG_GET_UNLOCKED))
            {
                itemId = sSideQuestDifficultyItemIds[sSideQuests[itemIndex].difficulty];
                desc = sSideQuests[itemIndex].desc;
            }
            else
            {
                itemId = ITEM_NONE;
                desc = sText_QuestMenu_Unk;
            }
            
            CreateItemMenuIcon(itemId, sStateDataPtr->itemMenuIconSlot);
        }
        else
        {
            CreateItemMenuIcon(ITEM_NONE, sStateDataPtr->itemMenuIconSlot);
            desc = sText_QuestMenu_Exit;
        }
        
        sStateDataPtr->itemMenuIconSlot ^= 1;
        FillWindowPixelBuffer(1, 0);
        QuestMenu_AddTextPrinterParameterized(1, 2, desc, 0, 3, 2, 0, 0, 3);
    }
}

static void QuestMenu_ItemPrintFunc(u8 windowId, u32 itemId, u8 y)
{
    if (sStateDataPtr->moveModeOrigPos != 0xFF)
    {
        if (sStateDataPtr->moveModeOrigPos == (u8)itemId)
            QuestMenu_PrintOrRemoveCursorAt(y, 2);
        else
            QuestMenu_PrintOrRemoveCursorAt(y, 0xFF);
    }
    if (itemId != LIST_CANCEL)
    {
        if (GetSetQuestFlag(itemId, FLAG_GET_COMPLETED))
            StringCopy(gStringVar4, sText_QuestMenu_Complete);
        else if (IsActiveQuest(itemId))
            StringCopy(gStringVar4, sText_QuestMenu_Active);
        else
            StringCopy(gStringVar4, sText_Empty);
        
        QuestMenu_AddTextPrinterParameterized(windowId, 0, gStringVar4, 110, y, 0, 0, 0xFF, 1);
    }
}

static void QuestMenu_PrintOrRemoveCursor(u8 listMenuId, u8 colorIdx)
{
    QuestMenu_PrintOrRemoveCursorAt(ListMenuGetYCoordForPrintingArrowCursor(listMenuId), colorIdx);
}

static void QuestMenu_PrintOrRemoveCursorAt(u8 y, u8 colorIdx)
{
    if (colorIdx == 0xFF)
    {
        u8 maxWidth = GetFontAttribute(1, FONTATTR_MAX_LETTER_WIDTH);
        u8 maxHeight = GetFontAttribute(1, FONTATTR_MAX_LETTER_HEIGHT);
        FillWindowPixelRect(0, 0, 0, y, maxWidth, maxHeight);
    }
    else
    {
        QuestMenu_AddTextPrinterParameterized(0, 2, gText_SelectorArrow, 0, y, 0, 0, 0, colorIdx);
    }
}

static void QuestMenu_PrintHeader(void)
{
    QuestMenu_AddTextPrinterParameterized(2, 0, sText_Quests, 0, 1, 0, 1, 0, 0);
}

static void QuestMenu_PlaceTopMenuScrollIndicatorArrows(void)
{
    sStateDataPtr->scrollIndicatorArrowPairId = AddScrollIndicatorArrowPairParameterized(2, 128, 8, 104, sStateDataPtr->nItems - sStateDataPtr->maxShowed + 1, 110, 110, &sListMenuState.scroll);
}

static void QuestMenu_PlaceWithdrawQuantityScrollIndicatorArrows(void)
{
    sStateDataPtr->withdrawQuantitySubmenuCursorPos = 1;
    sStateDataPtr->scrollIndicatorArrowPairId = AddScrollIndicatorArrowPairParameterized(2, 212, 120, 152, 2, 110, 110, &sStateDataPtr->withdrawQuantitySubmenuCursorPos);
}

static void QuestMenu_RemoveScrollIndicatorArrowPair(void)
{
    if (sStateDataPtr->scrollIndicatorArrowPairId != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(sStateDataPtr->scrollIndicatorArrowPairId);
        sStateDataPtr->scrollIndicatorArrowPairId = 0xFF;
    }
}

static void QuestMenu_SetCursorPosition(void)
{
    if (sListMenuState.scroll != 0 && sListMenuState.scroll + sStateDataPtr->maxShowed > sStateDataPtr->nItems + 1)
        sListMenuState.scroll = (sStateDataPtr->nItems + 1) - sStateDataPtr->maxShowed;
    if (sListMenuState.scroll + sListMenuState.row >= sStateDataPtr->nItems + 1)
    {
        if (sStateDataPtr->nItems + 1 < 2)
            sListMenuState.row = 0;
        else
            sListMenuState.row = sStateDataPtr->nItems;
    }
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void QuestMenu_FreeResources(void)
{
    try_free(sStateDataPtr);
    try_free(sBg1TilemapBuffer);
    try_free(sListMenuItems);
    //try_free(sUnusedStringAllocation);
    FreeAllWindowBuffers();
}

// pc_screen_effect
static void Task_PCScreenEffect_TurnOff(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        gPlttBufferFaded[0] = 0;
        break;
    case 1:
        task->tWin0Left = 0;
        task->tWin0Right = DISPLAY_WIDTH;
        task->tWin0Top = 0;
        task->tWin0Bottom = DISPLAY_HEIGHT;
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->tWin0Left, task->tWin0Right));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWin0Top, task->tWin0Bottom));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        break;
    case 2:
        task->tWin0Top += task->tYSpeed;
        task->tWin0Bottom -= task->tYSpeed;
        if (task->tWin0Top >= 80 || task->tWin0Bottom <= 81)
        {
            task->tWin0Top = 80;
            task->tWin0Bottom = 81;
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_EFFECT_LIGHTEN);
            SetGpuReg(REG_OFFSET_BLDY, 16);
        }
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWin0Top, task->tWin0Bottom));
        if (task->tWin0Top != 80)
            return;
        break;
    case 3:
        task->tWin0Left += task->tXSpeed;
        task->tWin0Right -= task->tXSpeed;
        if (task->tWin0Left >= 120 || task->tWin0Right <= 120)
        {
            task->tWin0Left = 120;
            task->tWin0Right = 120;
            BlendPalettes(0xFFFFFFFF, 0x10, RGB_BLACK);
            gPlttBufferFaded[0] = 0;
        }
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->tWin0Left, task->tWin0Right));
        if (task->tWin0Left != 120)
            return;
        break;
    default:
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        DestroyTask(taskId);
        return;
    }
    ++task->tState;
}

// pc_screen_effect
static void BeginPCScreenEffect_TurnOff(u16 a0, u16 a1, u16 a2)
{
    BeginPCScreenEffect(Task_PCScreenEffect_TurnOff, a0, a1, a2);
}

static void Task_QuestMenuTurnOff1(u8 taskId)
{
    if (sListMenuState.initialized == 1)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    }
    else
    {
        BeginPCScreenEffect_TurnOff(0, 0, 0);
        PlaySE(SE_PC_OFF);
    }
    
    gTasks[taskId].func = Task_QuestMenuTurnOff2;
}

// pc_screen_effect
static bool8 IsPCScreenEffectRunning_TurnOff(void)
{
    return FuncIsActiveTask(Task_PCScreenEffect_TurnOff);
}

static void Task_QuestMenuTurnOff2(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    if (!gPaletteFade.active && !IsPCScreenEffectRunning_TurnOff())
    {
        DestroyListMenuTask(data[0], &sListMenuState.scroll, &sListMenuState.row);
        if (sStateDataPtr->savedCallback != NULL)
            SetMainCallback2(sStateDataPtr->savedCallback);
        else
            SetMainCallback2(sListMenuState.savedCallback);
        
        QuestMenu_RemoveScrollIndicatorArrowPair();
        QuestMenu_FreeResources();
        DestroyTask(taskId);
    }
}

static u8 QuestMenu_GetCursorPosition(void)
{
    return sListMenuState.scroll + sListMenuState.row;
}


static void QuestMenu_InitItems(void)
{
    sStateDataPtr->nItems = SIDE_QUEST_COUNT;
    sStateDataPtr->maxShowed = sStateDataPtr->nItems + 1 <= 6 ? sStateDataPtr->nItems + 1 : 6;
    //DebugQuestMenu();
}

static void QuestMenu_SetScrollPosition(void)
{
    u8 i;

    if (sListMenuState.row > 3)
    {
        for (i = 0; i <= sListMenuState.row - 3; sListMenuState.row--, sListMenuState.scroll++, i++)
        {
            if (sListMenuState.scroll + sStateDataPtr->maxShowed == sStateDataPtr->nItems + 1)
                break;
        }
    }
}

static void QuestMenu_SetMessageWindowPalette(int a0)
{
    SetBgTilemapPalette(1, 0, 14, 30, 6, a0 + 1);
    //SetBgTilemapPalette(1, 0, 14, 30, 6, 15);
    ScheduleBgCopyTilemapToVram(1);
}

static void QuestMenu_SetInitializedFlag(u8 a0)
{
    sListMenuState.initialized = a0;
}

static bool8 IsPCScreenEffectRunning_TurnOn(void)
{
    return FuncIsActiveTask(Task_PCScreenEffect_TurnOn);
}

static void Task_QuestMenuMain(u8 taskId)
{
    s16 * data = gTasks[taskId].data;
    u16 scroll;
    u16 row;
    s32 input;

    if (!gPaletteFade.active && !IsPCScreenEffectRunning_TurnOn())
    {
        /*
        if (JOY_NEW(SELECT_BUTTON))
        {
            ListMenuGetScrollAndRow(data[0], &scroll, &row);
            if (scroll + row != sStateDataPtr->nItems)
            {
                PlaySE(SE_SELECT);
                QuestMenu_MoveItemModeInit(taskId, scroll + row);
                return;
            }
        }
        */
        input = ListMenu_ProcessInput(data[0]);
        ListMenuGetScrollAndRow(data[0], &sListMenuState.scroll, &sListMenuState.row);
        switch (input)
        {
        case LIST_NOTHING_CHOSEN:
            break;
            
        case LIST_CANCEL:
            PlaySE(SE_SELECT);
            QuestMenu_SetInitializedFlag(0);
            gTasks[taskId].func = Task_QuestMenuTurnOff1;
            break;
            
        default:
            if (GetSetQuestFlag(input, FLAG_GET_UNLOCKED))
            {
                PlaySE(SE_SELECT);
                QuestMenu_SetMessageWindowPalette(1);
                QuestMenu_RemoveScrollIndicatorArrowPair();
                data[1] = input;
                //data[2] = QuestMenu_GetItemQuantityBySlotId(input);
                data[2] = 0;
                QuestMenu_PrintOrRemoveCursor(data[0], 2);            
                gTasks[taskId].func = Task_QuestMenuSubmenuInit;
            }
            else
            {
                PlaySE(SE_FAILURE);
            }
            break;
        }
    }
}

static void QuestMenu_ReturnFromSubmenu(u8 taskId)
{
    QuestMenu_SetMessageWindowPalette(0);
    QuestMenu_PlaceTopMenuScrollIndicatorArrows();
    gTasks[taskId].func = Task_QuestMenuMain;
}

// pokefirered item_menu_icon
static void sub_8098660(u8 flag)
{
    u8 i;
    u8 * ptr = &gUnknown_2039878[1];

    for (i = 0; i < 9; i++)
    {
        gSprites[ptr[i]].invisible = flag;
    }
}

// pokefirered item_menu_icon
static void sub_80986A8(s16 x, u16 y)
{
    u8 i;
    u8 * ptr = &gUnknown_2039878[1];

    for (i = 0; i < 9; i++)
    {
        gSprites[ptr[i]].x2 = x;
        gSprites[ptr[i]].y = y + 7;
    }
}

static void Task_QuestMenuSubmenuInit(u8 taskId)
{
    s16 * data = gTasks[taskId].data;
    u8 windowId;

    QuestMenu_SetBorderStyleOnWindow(4);    //for sub menu list items
    windowId = QuestMenu_GetOrCreateSubwindow(0);
    
    if (GetSetQuestFlag(data[1], FLAG_GET_COMPLETED))
    {
        // Completed
        PrintMenuActionTextsAtPos(4, 2, 8, 2, GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) + 2, NELEMS(sCompletedQuestSubmenuOptions), sCompletedQuestSubmenuOptions);
        InitMenuNormal(4, 2, 0, 2, GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) + 2, NELEMS(sCompletedQuestSubmenuOptions), 0);
    }
    else if (IsActiveQuest(QuestMenu_GetCursorPosition()))
    {
        // Active
        PrintMenuActionTextsAtPos(4, 2, 8, 2, GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) + 2, NELEMS(sActiveQuestSubmenuOptions), sActiveQuestSubmenuOptions);
        InitMenuNormal(4, 2, 0, 2, GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) + 2, NELEMS(sActiveQuestSubmenuOptions), 0);
    }
    else
    {
        // Unlocked
        PrintMenuActionTextsAtPos(4, 2, 8, 2, GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) + 2, NELEMS(sQuestSubmenuOptions), sQuestSubmenuOptions);
        InitMenuNormal(4, 2, 0, 2, GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) + 2, NELEMS(sQuestSubmenuOptions), 0);
    } 
    //CopyItemName(QuestMenu_GetItemIdBySlotId(data[1]), gStringVar1);
    //StringExpandPlaceholders(gStringVar4, gText_StrVar1);
    
    StringCopy(gStringVar4, sText_QuestMenu_SelectedQuest);
    //StringExpandPlaceholders(gStringVar4, sText_QuestMenu_SelectedQuest);
    
    QuestMenu_AddTextPrinterParameterized(windowId, 2, gStringVar4, 0, 2, 1, 0, 0, 1);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Task_QuestMenuSubmenuRun;
}

static void Task_QuestMenuSubmenuRun(u8 taskId)
{
    u8 questIndex = QuestMenu_GetCursorPosition();
    s8 input = Menu_ProcessInputNoWrapAround_other();
    
    switch (input)
    {
    case LIST_NOTHING_CHOSEN:
        PlaySE(SE_SELECT);
        Task_QuestMenuCancel(taskId);
        break;
    case LIST_CANCEL:
        break;
    default:
        PlaySE(SE_SELECT);
        if (GetSetQuestFlag(questIndex, FLAG_GET_COMPLETED))
            sCompletedQuestSubmenuOptions[input].func.void_u8(taskId);
        else if (IsActiveQuest(questIndex))
            sActiveQuestSubmenuOptions[input].func.void_u8(taskId);
        else       
            sQuestSubmenuOptions[input].func.void_u8(taskId);
    }
}

static void QuestMenuSubmenuSelectionMessage(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    ClearStdWindowAndFrameToTransparent(4, FALSE);
    QuestMenu_DestroySubwindow(0);
    ClearWindowTilemap(4);
    data[8] = 1;
    PutWindowTilemap(0);
    ScheduleBgCopyTilemapToVram(0);
}

static void Task_QuestMenuDetails(u8 taskId)
{
    u8 questIndex = QuestMenu_GetCursorPosition();
    
    QuestMenuSubmenuSelectionMessage(taskId);
    StringCopy(gStringVar1, sSideQuests[questIndex].poc);
    StringCopy(gStringVar2, sSideQuests[questIndex].map);
    StringExpandPlaceholders(gStringVar4, sText_QuestMenu_DisplayDetails);
    QuestMenu_DisplaySubMenuMessage(taskId);
}

static void Task_QuestMenuReward(u8 taskId)
{
    u8 questIndex = QuestMenu_GetCursorPosition();
    
    QuestMenuSubmenuSelectionMessage(taskId);
    StringCopy(gStringVar1, sSideQuests[questIndex].reward);
    StringExpandPlaceholders(gStringVar4, sText_QuestMenu_DisplayReward);
    QuestMenu_DisplaySubMenuMessage(taskId);
}

static void Task_QuestMenuEndQuest(u8 taskId)
{
    u8 questIndex = QuestMenu_GetCursorPosition();
    
    ResetActiveQuest();
    QuestMenuSubmenuSelectionMessage(taskId);
    StringCopy(gStringVar1, sSideQuests[questIndex].name);
    StringExpandPlaceholders(gStringVar4, sText_QuestMenu_EndQuest);
    QuestMenu_DisplaySubMenuMessage(taskId);
}

static void Task_QuestMenuBeginQuest(u8 taskId)
{
    u8 questIndex = QuestMenu_GetCursorPosition();
    
    SetActiveQuest(questIndex);
    QuestMenuSubmenuSelectionMessage(taskId);
    StringCopy(gStringVar1, sSideQuests[questIndex].name);
    StringExpandPlaceholders(gStringVar4, sText_QuestMenu_BeginQuest);
    QuestMenu_DisplaySubMenuMessage(taskId);
}

static void QuestMenu_DisplaySubMenuMessage(u8 taskId)
{
    s16 * data = gTasks[taskId].data;
    u8 windowId;
    
    windowId = QuestMenu_GetOrCreateSubwindow(2);
    AddTextPrinterParameterized(windowId, 2, gStringVar4, 0, 2, 0, NULL);
    gTasks[taskId].func = Task_QuestMenuRefreshAfterAcknowledgement;
}

static void Task_QuestMenuRefreshAfterAcknowledgement(u8 taskId)
{
    if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        Task_QuestMenuCleanUp(taskId);
    }
}

static void Task_QuestMenuCleanUp(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    QuestMenu_DestroySubwindow(2);
    PutWindowTilemap(1);
    DestroyListMenuTask(data[0], &sListMenuState.scroll, &sListMenuState.row);
    
    QuestMenu_InitItems();
    
    QuestMenu_SetCursorPosition();
    QuestMenu_BuildListMenuTemplate();
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, sListMenuState.scroll, sListMenuState.row);
    ScheduleBgCopyTilemapToVram(0);
    QuestMenu_ReturnFromSubmenu(taskId);
}

static void Task_QuestMenuCancel(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    ClearStdWindowAndFrameToTransparent(4, FALSE);
    QuestMenu_DestroySubwindow(0);
    ClearWindowTilemap(4);
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    QuestMenu_PrintOrRemoveCursor(data[0], 1);
    ScheduleBgCopyTilemapToVram(0);
    QuestMenu_ReturnFromSubmenu(taskId);
}

// pokefirered text_window.c
void TextWindow_SetStdFrame0_WithPal(u8 windowId, u16 destOffset, u8 palIdx)
{
    LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), sFR_StdFrame0, 0x120, destOffset);
    LoadPalette(GetTextWindowPalette(3), palIdx, 32);
}
void TextWindow_LoadResourcesStdFrame0(u8 windowId, u16 destOffset, u8 palIdx)
{
    LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), sFR_MessageBoxTiles, 0x280, destOffset);
    LoadPalette(GetTextWindowPalette(0), palIdx, 32);
}

static void QuestMenu_InitWindows(void)
{
    u8 i;

    InitWindows(sQuestMenuHeaderWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 0x3C0, 0xE0);
    
    TextWindow_SetStdFrame0_WithPal(0, 0x3A3, 0xC0); 
    TextWindow_LoadResourcesStdFrame0(0, 0x3AC, 0xB0);
    //LoadMessageBoxGfx(0, 0x3A3, 0xC0);
    //LoadMessageBoxGfx(0, 0x3AC, 0xB0);
    
    LoadPalette(GetTextWindowPalette(2), 0xD0, 0x20);
    LoadPalette(sMainWindowPal, 0xF0, 0x20);
    for (i = 0; i < 3; i++)
    {
        FillWindowPixelBuffer(i, 0x00);
        PutWindowTilemap(i);
    }
    
    ScheduleBgCopyTilemapToVram(0);
    for (i = 0; i < 3; i++)
        sSubmenuWindowIds[i] = 0xFF;
}

static void QuestMenu_AddTextPrinterParameterized(u8 windowId, u8 fontId, const u8 * str, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorIdx)
{
    AddTextPrinterParameterized4(windowId, fontId, x, y, letterSpacing, lineSpacing, sQuestMenuWindowFontColors[colorIdx], speed, str);
}

static void QuestMenu_SetBorderStyleOnWindow(u8 windowId)
{
    DrawStdFrameWithCustomTileAndPalette(windowId, FALSE, 0x3C0, 14);
}

static u8 QuestMenu_GetOrCreateSubwindow(u8 idx)
{
    if (sSubmenuWindowIds[idx] == 0xFF)
    {
        sSubmenuWindowIds[idx] = AddWindow(&sQuestMenuSubWindowTemplates[idx]);
        DrawStdFrameWithCustomTileAndPalette(sSubmenuWindowIds[idx], TRUE, 0x3A3, 0x0C);
    }

    return sSubmenuWindowIds[idx];
}

static void QuestMenu_DestroySubwindow(u8 idx)
{
    ClearStdWindowAndFrameToTransparent(sSubmenuWindowIds[idx], FALSE);
    ClearWindowTilemap(sSubmenuWindowIds[idx]); // redundant
    RemoveWindow(sSubmenuWindowIds[idx]);
    sSubmenuWindowIds[idx] = 0xFF;
}

// Start Menu Function
void Task_OpenQuestMenuFromStartMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        QuestMenu_Init(tItemPcParam, CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

s8 GetSetQuestFlag(u8 quest, u8 caseId)
{
    switch (caseId)
    {
    case FLAG_GET_UNLOCKED:
        #ifdef DEBUG_BUILD
            return TRUE;
        #else
            return (gSaveBlock2Ptr->questStatus[quest] >= QUEST_STATUS_UNLOCKED);
        #endif
    break;
    case FLAG_SET_UNLOCKED:
        if(gSaveBlock2Ptr->questStatus[quest] == QUEST_STATUS_LOCKED)
            gSaveBlock2Ptr->questStatus[quest] = QUEST_STATUS_UNLOCKED;
        return 1;
    break;
    case FLAG_GET_COMPLETED:
        return (gSaveBlock2Ptr->questStatus[quest] >= QUEST_STATUS_COMPLETED);
    break;
    case FLAG_SET_COMPLETED:
        if(gSaveBlock2Ptr->questStatus[quest] < QUEST_STATUS_COMPLETED)
            gSaveBlock2Ptr->questStatus[quest] = QUEST_STATUS_COMPLETED;
        return 1;
    break;
    }
    
    return FALSE;  //failure
}

s8 GetActiveQuestIndex(void)
{
    if (gSaveBlock2Ptr->activeQuest > 0)
        return (gSaveBlock2Ptr->activeQuest - 1);
    else
        return 0;
}

static bool8 IsActiveQuest(u8 questId)
{
    if ((u8)GetActiveQuestIndex() == questId)
        return TRUE;
    
    return FALSE;
}

void SetActiveQuest(u8 questId)
{
    gSaveBlock2Ptr->activeQuest = questId + 1;  // 1-indexed
}

void ResetActiveQuest(void)
{
    gSaveBlock2Ptr->activeQuest = 0;
}

/*
static void DebugQuestMenu(void)
{
    GetSetQuestFlag(SIDE_QUEST_1, FLAG_SET_UNLOCKED);
    GetSetQuestFlag(SIDE_QUEST_2, FLAG_SET_UNLOCKED);
    GetSetQuestFlag(SIDE_QUEST_3, FLAG_SET_UNLOCKED);
    GetSetQuestFlag(SIDE_QUEST_5, FLAG_SET_UNLOCKED);
    GetSetQuestFlag(SIDE_QUEST_5, FLAG_SET_COMPLETED);    
    SetActiveQuest(SIDE_QUEST_2);
}
*/

void SetQuestMenuActive(void)
{
    FlagSet(FLAG_QUEST_MENU_ACTIVE);
}

void CopyQuestName(u8 *dst, u8 questId)
{
    StringCopy(dst, sSideQuests[questId].name);
}

#undef tBldYBak
#undef tBldCntBak
#undef tWin0Bottom
#undef tWin0Top
#undef tWin0Right
#undef tWin0Left
#undef tYSpeed
#undef tXSpeed
#undef tState