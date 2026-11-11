#include "global.h"
#include "option_menu.h"
#include "bg.h"
#include "dma3.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "main_menu.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "overworld.h"
#include "menu.h"
#include "start_menu.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "gba/m4a_internal.h"
#include "constants/rgb.h"

#define tMenuSelection data[0]
#define tTextSpeed data[1]
#define tBattleSceneOff data[2]
#define tBattleStyle data[3]
#define tSound data[4]
#define tButtonMode data[5]
#define tWindowFrameType data[6]
#define tRandomCallsOff data[7]
#define tPlayerSpriteStyle data[9]

enum
{
    MENUITEM_TEXTSPEED,
    MENUITEM_BATTLESCENE,
    MENUITEM_BATTLESTYLE,
    MENUITEM_SOUND,
    MENUITEM_BUTTONMODE,
    MENUITEM_FRAMETYPE,
    MENUITEM_RANDOM_CALLS,
    MENUITEM_PLAYER_SPRITES,
    MENUITEM_CANCEL,
    MENUITEM_COUNT,
};

enum
{
    WIN_HEADER,
    WIN_OPTIONS
};

// Eight entries fit within the existing 14-tile options window.
#define OPTION_ROW_HEIGHT 14
#define OPTION_VISIBLE_ROWS 8
#define YPOS_TEXTSPEED    (MENUITEM_TEXTSPEED * OPTION_ROW_HEIGHT)
#define YPOS_BATTLESCENE  (MENUITEM_BATTLESCENE * OPTION_ROW_HEIGHT)
#define YPOS_BATTLESTYLE  (MENUITEM_BATTLESTYLE * OPTION_ROW_HEIGHT)
#define YPOS_SOUND        (MENUITEM_SOUND * OPTION_ROW_HEIGHT)
#define YPOS_BUTTONMODE   (MENUITEM_BUTTONMODE * OPTION_ROW_HEIGHT)
#define YPOS_FRAMETYPE    (MENUITEM_FRAMETYPE * OPTION_ROW_HEIGHT)
#define YPOS_RANDOM_CALLS (MENUITEM_RANDOM_CALLS * OPTION_ROW_HEIGHT)
#define YPOS_PLAYER_SPRITES (MENUITEM_PLAYER_SPRITES * OPTION_ROW_HEIGHT)

static void Task_OptionMenuFadeIn(u8 taskId);
static void Task_OptionMenuProcessInput(u8 taskId);
static void Task_OptionMenuSave(u8 taskId);
static void Task_OptionMenuFadeOut(u8 taskId);
static void Task_ReturnFromFieldOption(u8 taskId);
static void HighlightOptionMenuItem(u8 selection);
static u8 TextSpeed_ProcessInput(u8 selection);
static void TextSpeed_DrawChoices(u8 selection);
static u8 BattleScene_ProcessInput(u8 selection);
static void BattleScene_DrawChoices(u8 selection);
static u8 BattleStyle_ProcessInput(u8 selection);
static void BattleStyle_DrawChoices(u8 selection);
static u8 Sound_ProcessInput(u8 selection);
static void Sound_DrawChoices(u8 selection);
static u8 FrameType_ProcessInput(u8 selection);
static void FrameType_DrawChoices(u8 selection);
static u8 ButtonMode_ProcessInput(u8 selection);
static void ButtonMode_DrawChoices(u8 selection);
static void RandomCalls_DrawChoices(u8 selection);
static void PlayerSprites_DrawChoices(u8 selection);
static void RedrawOptionChoices(u8 taskId);
static void DrawHeaderText(void);
static void DrawOptionMenuTexts(void);
static void DrawBgWindowFrames(void);
static void LoadOptionWindowFrame(u8 selection);
static void Task_PrepareInlineOptions(u8 taskId);

EWRAM_DATA static bool8 sArrowPressed = FALSE;
static bool8 sOptionMenuOnMainMenu;
static bool8 sOptionMenuPreparingInline;
static bool8 sOptionMenuOnOverworld;
static MainCallback sOptionSavedFieldCallback1;
static u8 sFieldOptionTaskId;

// The field is never reloaded while OPTION is open. Save the graphical
// registers and OBJ priorities to restore them exactly when it closes.
static u16 sFieldSavedDispCnt;
static u16 sFieldSavedWin0H, sFieldSavedWin0V;
static u16 sFieldSavedWin1H, sFieldSavedWin1V;
static u16 sFieldSavedWinIn, sFieldSavedWinOut;
static u16 sFieldSavedBldCnt, sFieldSavedBldAlpha, sFieldSavedBldY;
static u8 sFieldSavedSpritePriorities[MAX_SPRITES];

// Match the main menu's dedicated UI palette and VRAM tile banks, while
// leaving all original title background palette banks untouched.
#define INLINE_OPTION_FRAME_TILE 0x1D5
#define INLINE_OPTION_FRAME_PALETTE 9
#define INLINE_OPTION_TEXT_PALETTE 10

static const u16 sOptionMenuText_Pal[] = INCBIN_U16("graphics/interface/option_menu_text.gbapal");
// note: this is only used in the Japanese release
static const u8 sEqualSignGfx[] = INCBIN_U8("graphics/interface/option_menu_equals_sign.4bpp");
static const u8 sText_RandomCalls[] = _("RANDOM CALLS");
static const u8 sText_PlayerSprites[] = _("SPRITES");
static const u8 sText_Emerald[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}EMERALD");
static const u8 sText_Ruby[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}RUBY");
static u8 sOptionMenuScrollOffset;
static bool8 sOptionMenuScrollRedraw;

static const u8 *const sOptionMenuItemsNames[MENUITEM_COUNT] =
{
    [MENUITEM_TEXTSPEED]   = gText_TextSpeed,
    [MENUITEM_BATTLESCENE] = gText_BattleScene,
    [MENUITEM_BATTLESTYLE] = gText_BattleStyle,
    [MENUITEM_SOUND]       = gText_Sound,
    [MENUITEM_BUTTONMODE]  = gText_ButtonMode,
    [MENUITEM_FRAMETYPE]   = gText_Frame,
    [MENUITEM_RANDOM_CALLS] = sText_RandomCalls,
    [MENUITEM_PLAYER_SPRITES] = sText_PlayerSprites,
    [MENUITEM_CANCEL]      = gText_OptionMenuCancel,
};

static const struct WindowTemplate sOptionMenuWinTemplates[] =
{
    [WIN_HEADER] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 26,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2
    },
    [WIN_OPTIONS] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 5,
        .width = 26,
        .height = 14,
        .paletteNum = 1,
        .baseBlock = 0x36
    },
    DUMMY_WIN_TEMPLATE
};

// The old OPTION window graphics are drawn on BG0 instead of rebuilding
// BG1/BG2. The two windows end at tile 0x1A1, before the frame at 0x1D5.
// GBA text-mode BG3: a separate 16 KiB charbase and tilemap. BG0's
// already visible main-menu graphics are never touched while preparing.
// The field map lives on BG1-BG3; only its interface BG0 is replaced.
static const struct WindowTemplate sFieldOptionWindowTemplates[] =
{
    [WIN_HEADER] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 26,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 2
    },
    [WIN_OPTIONS] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 5,
        .width = 26,
        .height = 14,
        .paletteNum = 15,
        .baseBlock = 0x36
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sInlineOptionWindowTemplates[] =
{
    [WIN_HEADER] = {
        .bg = 3,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 26,
        .height = 2,
        .paletteNum = INLINE_OPTION_TEXT_PALETTE,
        .baseBlock = 1
    },
    [WIN_OPTIONS] = {
        .bg = 3,
        .tilemapLeft = 2,
        .tilemapTop = 5,
        .width = 26,
        .height = 14,
        .paletteNum = INLINE_OPTION_TEXT_PALETTE,
        .baseBlock = 0x35
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sInlineOptionBgTemplate =
{
    .bg = 3,
    .charBaseIndex = 1,
    .mapBaseIndex = 29,
    .screenSize = 0,
    .paletteMode = 0,
    .priority = 0,
    .baseTile = 0
};

static const struct BgTemplate sOptionMenuBgTemplates[] =
{
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 0,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    }
};

static const u16 sOptionMenuBg_Pal[] = {RGB(17, 18, 31)};

static void MainCB2(void)
{
    if (sOptionMenuOnOverworld)
    {
        // Do not advance unrelated field tasks while OPTION is open.
        // None are destroyed, so they resume in the same state on exit.
        if (gTasks[sFieldOptionTaskId].isActive)
            gTasks[sFieldOptionTaskId].func(sFieldOptionTaskId);
    }
    else
    {
        RunTasks();
        AnimateSprites();
    }

    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_InitOptionMenu(void)
{
    switch (gMain.state)
    {
    default:
    case 0:
        sOptionMenuOnMainMenu = FALSE;
        sOptionMenuOnOverworld = FALSE;
        sOptionMenuScrollOffset = 0;
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sOptionMenuBgTemplates, ARRAY_COUNT(sOptionMenuBgTemplates));
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        ChangeBgX(3, 0, BG_COORD_SET);
        ChangeBgY(3, 0, BG_COORD_SET);
        InitWindows(sOptionMenuWinTemplates);
        DeactivateAllTextPrinters();
        // Keep the entire options panel white. The normal window-based
        // darkening is replaced by a movable arrow cursor on the selected row.
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        LoadBgTiles(1, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
        gMain.state++;
        break;
    case 4:
        LoadPalette(sOptionMenuBg_Pal, BG_PLTT_ID(0), sizeof(sOptionMenuBg_Pal));
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        gMain.state++;
        break;
    case 5:
        LoadPalette(sOptionMenuText_Pal, BG_PLTT_ID(1), sizeof(sOptionMenuText_Pal));
        gMain.state++;
        break;
    case 6:
        PutWindowTilemap(WIN_HEADER);
        DrawHeaderText();
        gMain.state++;
        break;
    case 7:
        gMain.state++;
        break;
    case 8:
        PutWindowTilemap(WIN_OPTIONS);
        DrawOptionMenuTexts();
        gMain.state++;
    case 9:
        DrawBgWindowFrames();
        gMain.state++;
        break;
    case 10:
    {
        u8 taskId = CreateTask(Task_OptionMenuFadeIn, 0);

        gTasks[taskId].tMenuSelection = 0;
        gTasks[taskId].tTextSpeed = gSaveBlock2Ptr->optionsTextSpeed;
        gTasks[taskId].tBattleSceneOff = gSaveBlock2Ptr->optionsBattleSceneOff;
        gTasks[taskId].tBattleStyle = gSaveBlock2Ptr->optionsBattleStyle;
        gTasks[taskId].tSound = gSaveBlock2Ptr->optionsSound;
        gTasks[taskId].tButtonMode = gSaveBlock2Ptr->optionsButtonMode;
        gTasks[taskId].tWindowFrameType = gSaveBlock2Ptr->optionsWindowFrameType;
        gTasks[taskId].tRandomCallsOff = gSaveBlock2Ptr->optionsRandomCallsOff;
        gTasks[taskId].tPlayerSpriteStyle = gSaveBlock2Ptr->optionsRubyPlayerSprites;

        TextSpeed_DrawChoices(gTasks[taskId].tTextSpeed);
        BattleScene_DrawChoices(gTasks[taskId].tBattleSceneOff);
        BattleStyle_DrawChoices(gTasks[taskId].tBattleStyle);
        Sound_DrawChoices(gTasks[taskId].tSound);
        ButtonMode_DrawChoices(gTasks[taskId].tButtonMode);
        FrameType_DrawChoices(gTasks[taskId].tWindowFrameType);
        RandomCalls_DrawChoices(gTasks[taskId].tRandomCallsOff);
        PlayerSprites_DrawChoices(gTasks[taskId].tPlayerSpriteStyle);
        HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);

        CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
        gMain.state++;
        break;
    }
    case 11:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        return;
    }
}

// In-game OPTION: replace only BG0 while retaining the real overworld.
// Do not fade or reset any field tasks, sprites or map graphics.
void CB2_InitFieldOptionMenu(void)
{
    switch (gMain.state)
    {
    case 0:
    {
        u8 i;

        sOptionMenuOnOverworld = TRUE;
        sOptionMenuOnMainMenu = FALSE;
        sOptionMenuScrollOffset = 0;
        // Stage all UI graphics in RAM until both windows are complete.
        sOptionMenuPreparingInline = TRUE;
        sArrowPressed = FALSE;

        // Freeze field input and tasks without destroying map tiles,
        // weather graphics, BG1-BG3, or the existing field VBlank.
        sOptionSavedFieldCallback1 = gMain.callback1;
        sFieldSavedDispCnt = GetGpuReg(REG_OFFSET_DISPCNT);
        sFieldSavedWin0H = GetGpuReg(REG_OFFSET_WIN0H);
        sFieldSavedWin0V = GetGpuReg(REG_OFFSET_WIN0V);
        sFieldSavedWin1H = GetGpuReg(REG_OFFSET_WIN1H);
        sFieldSavedWin1V = GetGpuReg(REG_OFFSET_WIN1V);
        sFieldSavedWinIn = GetGpuReg(REG_OFFSET_WININ);
        sFieldSavedWinOut = GetGpuReg(REG_OFFSET_WINOUT);
        sFieldSavedBldCnt = GetGpuReg(REG_OFFSET_BLDCNT);
        sFieldSavedBldAlpha = GetGpuReg(REG_OFFSET_BLDALPHA);
        sFieldSavedBldY = GetGpuReg(REG_OFFSET_BLDY);
        SetMainCallback1(NULL);

        // Remove the Start windows while the real map remains visible.
        // The replacement UI is completed before BG0 is shown again.
        HideBg(0);
        FreeAllWindowBuffers();
        UnsetBgTilemapBuffer(0);
        InitWindows(sFieldOptionWindowTemplates);
        DeactivateAllTextPrinters();

        // The overworld uses WIN0/WIN1 for map effects; inherited masks
        // can conceal BG0 and the map in unrelated horizontal strips.
        // They will be restored by the normal return-to-field reload.
        SetGpuReg(REG_OFFSET_DISPCNT, GetGpuReg(REG_OFFSET_DISPCNT)
                                    & ~(DISPCNT_WIN0_ON | DISPCNT_WIN1_ON));
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WIN1H, 0);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);

        // BG0 is the topmost layer. Ensure map sprites (including the
        // player) stay behind the opaque options boxes instead of
        // overlapping the foreground text.
        for (i = 0; i < MAX_SPRITES; i++)
        {
            sFieldSavedSpritePriorities[i] = gSprites[i].oam.priority;
            if (gSprites[i].inUse && gSprites[i].oam.priority == 0)
                gSprites[i].oam.priority = 1;
        }

        // Transparent BG0 tile zero reveals the overworld outside
        // the option windows; never clear the map's BG1-BG3 VRAM.
        DmaFill32(3, 0, (void *)BG_CHAR_ADDR(2), 32);
        CopyBgTilemapBufferToVram(0);
        gMain.state++;
        break;
    }
    case 1:
        LoadOptionWindowFrame(gSaveBlock2Ptr->optionsWindowFrameType);
        LoadPalette(sOptionMenuText_Pal, BG_PLTT_ID(15), sizeof(sOptionMenuText_Pal));
        PutWindowTilemap(WIN_HEADER);
        PutWindowTilemap(WIN_OPTIONS);
        DrawHeaderText();
        DrawOptionMenuTexts();
        DrawBgWindowFrames();
        gMain.state++;
        break;
    case 2:
    {
        u8 taskId = CreateTask(Task_OptionMenuProcessInput, 0);
        sFieldOptionTaskId = taskId;

        gTasks[taskId].tMenuSelection = 0;
        gTasks[taskId].tTextSpeed = gSaveBlock2Ptr->optionsTextSpeed;
        gTasks[taskId].tBattleSceneOff = gSaveBlock2Ptr->optionsBattleSceneOff;
        gTasks[taskId].tBattleStyle = gSaveBlock2Ptr->optionsBattleStyle;
        gTasks[taskId].tSound = gSaveBlock2Ptr->optionsSound;
        gTasks[taskId].tButtonMode = gSaveBlock2Ptr->optionsButtonMode;
        gTasks[taskId].tWindowFrameType = gSaveBlock2Ptr->optionsWindowFrameType;
        gTasks[taskId].tRandomCallsOff = gSaveBlock2Ptr->optionsRandomCallsOff;
        gTasks[taskId].tPlayerSpriteStyle = gSaveBlock2Ptr->optionsRubyPlayerSprites;

        TextSpeed_DrawChoices(gTasks[taskId].tTextSpeed);
        BattleScene_DrawChoices(gTasks[taskId].tBattleSceneOff);
        BattleStyle_DrawChoices(gTasks[taskId].tBattleStyle);
        Sound_DrawChoices(gTasks[taskId].tSound);
        ButtonMode_DrawChoices(gTasks[taskId].tButtonMode);
        FrameType_DrawChoices(gTasks[taskId].tWindowFrameType);
        RandomCalls_DrawChoices(gTasks[taskId].tRandomCallsOff);
        PlayerSprites_DrawChoices(gTasks[taskId].tPlayerSpriteStyle);
        HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);

        // Upload the complete header, all eight option rows and the
        // finished tilemap once; no intermediate window is ever shown.
        CopyWindowToVram(WIN_HEADER, COPYWIN_GFX);
        CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
        CopyBgTilemapBufferToVram(0);
        gMain.state++;
        break;
    }
    case 3:
        // The new header, options, values, cursor and frames must all be
        // in VRAM before turning the interface background back on.
        if (IsDma3ManagerBusyWithBgCopy()
         || CheckForSpaceForDma3Request(-1) != 0)
            break;

        sOptionMenuPreparingInline = FALSE;
        ShowBg(0);
        SetMainCallback2(MainCB2);
        break;
    }
}

// Called only for OPTION selected from the title's main menu.
// The current UI stays visible during BG3 preparation, and the fully
// rendered options replace it during VBlank with no palette fade.
void OptionMenu_OpenFromMainMenu(u8 taskId)
{
    sOptionMenuOnMainMenu = TRUE;
    sOptionMenuScrollOffset = 0;
    sOptionMenuPreparingInline = TRUE;
    sArrowPressed = FALSE;
    gTasks[taskId].data[8] = 0;
    gTasks[taskId].func = Task_PrepareInlineOptions;
}

static void Task_PrepareInlineOptions(u8 taskId)
{
    switch (gTasks[taskId].data[8])
    {
    case 0:
        FreeAllWindowBuffers();
        UnsetBgTilemapBuffer(0);
        InitBgFromTemplate(&sInlineOptionBgTemplate);
        ChangeBgX(3, 0, BG_COORD_SET);
        ChangeBgY(3, 0, BG_COORD_SET);
        InitWindows(sInlineOptionWindowTemplates);
        DeactivateAllTextPrinters();

        // Backgrounds BG0/BG1/BG2 remain visible and unchanged.
        LoadOptionWindowFrame(gSaveBlock2Ptr->optionsWindowFrameType);
        gTasks[taskId].tMenuSelection = 0;
        gTasks[taskId].tTextSpeed = gSaveBlock2Ptr->optionsTextSpeed;
        gTasks[taskId].tBattleSceneOff = gSaveBlock2Ptr->optionsBattleSceneOff;
        gTasks[taskId].tBattleStyle = gSaveBlock2Ptr->optionsBattleStyle;
        gTasks[taskId].tSound = gSaveBlock2Ptr->optionsSound;
        gTasks[taskId].tButtonMode = gSaveBlock2Ptr->optionsButtonMode;
        gTasks[taskId].tWindowFrameType = gSaveBlock2Ptr->optionsWindowFrameType;
        gTasks[taskId].tRandomCallsOff = gSaveBlock2Ptr->optionsRandomCallsOff;
        gTasks[taskId].tPlayerSpriteStyle = gSaveBlock2Ptr->optionsRubyPlayerSprites;
        PutWindowTilemap(WIN_HEADER);
        PutWindowTilemap(WIN_OPTIONS);
        DrawHeaderText();
        DrawOptionMenuTexts();
        gTasks[taskId].data[8] = 1;
        break;
    case 1:
        // While preparing, the text printers write only to RAM.
        TextSpeed_DrawChoices(gTasks[taskId].tTextSpeed);
        BattleScene_DrawChoices(gTasks[taskId].tBattleSceneOff);
        BattleStyle_DrawChoices(gTasks[taskId].tBattleStyle);
        Sound_DrawChoices(gTasks[taskId].tSound);
        ButtonMode_DrawChoices(gTasks[taskId].tButtonMode);
        FrameType_DrawChoices(gTasks[taskId].tWindowFrameType);
        RandomCalls_DrawChoices(gTasks[taskId].tRandomCallsOff);
        PlayerSprites_DrawChoices(gTasks[taskId].tPlayerSpriteStyle);
        HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);
        DrawMainMenuWindowBorder(&sInlineOptionWindowTemplates[WIN_HEADER], INLINE_OPTION_FRAME_TILE);
        DrawMainMenuWindowBorder(&sInlineOptionWindowTemplates[WIN_OPTIONS], INLINE_OPTION_FRAME_TILE);
        gTasks[taskId].data[8] = 2;
        break;
    case 2:
        // Exactly one graphic transfer per complete window.
        CopyWindowToVram(WIN_HEADER, COPYWIN_GFX);
        CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
        gTasks[taskId].data[8] = 3;
        break;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            break;

        // The main menu remains untouched until VBlank uploads these
        // colors and atomically activates BG3 instead of BG0.
        LoadPalette(sOptionMenuText_Pal, BG_PLTT_ID(INLINE_OPTION_TEXT_PALETTE),
                    sizeof(sOptionMenuText_Pal));
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal,
                    BG_PLTT_ID(INLINE_OPTION_FRAME_PALETTE), PLTT_SIZE_4BPP);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        sOptionMenuPreparingInline = FALSE;
        MainMenu_QueueInlineBackgroundSwap(TRUE);
        gTasks[taskId].data[8] = 4;
        break;
    case 4:
        // The UI is already complete, and BG3 is now visible. No
        // fade-in: accept inputs only once the VBlank swap has finished.
        if (!MainMenu_IsInlineBackgroundSwapPending())
            gTasks[taskId].func = Task_OptionMenuProcessInput;
        break;
    }
}

static void Task_OptionMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OptionMenuProcessInput;
}

static void Task_OptionMenuProcessInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        if (gTasks[taskId].tMenuSelection == MENUITEM_CANCEL)
            gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (gTasks[taskId].tMenuSelection > 0)
            gTasks[taskId].tMenuSelection--;
        else
            gTasks[taskId].tMenuSelection = MENUITEM_CANCEL;
        HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (gTasks[taskId].tMenuSelection < MENUITEM_CANCEL)
            gTasks[taskId].tMenuSelection++;
        else
            gTasks[taskId].tMenuSelection = 0;
        HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);
    }
    else
    {
        u8 previousOption;

        switch (gTasks[taskId].tMenuSelection)
        {
        case MENUITEM_TEXTSPEED:
            previousOption = gTasks[taskId].tTextSpeed;
            gTasks[taskId].tTextSpeed = TextSpeed_ProcessInput(gTasks[taskId].tTextSpeed);

            if (previousOption != gTasks[taskId].tTextSpeed)
                TextSpeed_DrawChoices(gTasks[taskId].tTextSpeed);
            break;
        case MENUITEM_BATTLESCENE:
            previousOption = gTasks[taskId].tBattleSceneOff;
            gTasks[taskId].tBattleSceneOff = BattleScene_ProcessInput(gTasks[taskId].tBattleSceneOff);

            if (previousOption != gTasks[taskId].tBattleSceneOff)
                BattleScene_DrawChoices(gTasks[taskId].tBattleSceneOff);
            break;
        case MENUITEM_BATTLESTYLE:
            previousOption = gTasks[taskId].tBattleStyle;
            gTasks[taskId].tBattleStyle = BattleStyle_ProcessInput(gTasks[taskId].tBattleStyle);

            if (previousOption != gTasks[taskId].tBattleStyle)
                BattleStyle_DrawChoices(gTasks[taskId].tBattleStyle);
            break;
        case MENUITEM_SOUND:
            previousOption = gTasks[taskId].tSound;
            gTasks[taskId].tSound = Sound_ProcessInput(gTasks[taskId].tSound);

            if (previousOption != gTasks[taskId].tSound)
                Sound_DrawChoices(gTasks[taskId].tSound);
            break;
        case MENUITEM_BUTTONMODE:
            previousOption = gTasks[taskId].tButtonMode;
            gTasks[taskId].tButtonMode = ButtonMode_ProcessInput(gTasks[taskId].tButtonMode);

            if (previousOption != gTasks[taskId].tButtonMode)
                ButtonMode_DrawChoices(gTasks[taskId].tButtonMode);
            break;
        case MENUITEM_FRAMETYPE:
            previousOption = gTasks[taskId].tWindowFrameType;
            gTasks[taskId].tWindowFrameType = FrameType_ProcessInput(gTasks[taskId].tWindowFrameType);

            if (previousOption != gTasks[taskId].tWindowFrameType)
                FrameType_DrawChoices(gTasks[taskId].tWindowFrameType);
            break;
        case MENUITEM_RANDOM_CALLS:
            previousOption = gTasks[taskId].tRandomCallsOff;
            gTasks[taskId].tRandomCallsOff = BattleScene_ProcessInput(gTasks[taskId].tRandomCallsOff);

            if (previousOption != gTasks[taskId].tRandomCallsOff)
                RandomCalls_DrawChoices(gTasks[taskId].tRandomCallsOff);
        PlayerSprites_DrawChoices(gTasks[taskId].tPlayerSpriteStyle);
            break;
        case MENUITEM_PLAYER_SPRITES:
            previousOption = gTasks[taskId].tPlayerSpriteStyle;
            gTasks[taskId].tPlayerSpriteStyle = BattleScene_ProcessInput(gTasks[taskId].tPlayerSpriteStyle);
            if (previousOption != gTasks[taskId].tPlayerSpriteStyle)
                PlayerSprites_DrawChoices(gTasks[taskId].tPlayerSpriteStyle);
            break;
        default:
            return;
        }

        if (sArrowPressed)
        {
            sArrowPressed = FALSE;
            CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
        }
    }
}

static void Task_OptionMenuSave(u8 taskId)
{
    gSaveBlock2Ptr->optionsTextSpeed = gTasks[taskId].tTextSpeed;
    gSaveBlock2Ptr->optionsBattleSceneOff = gTasks[taskId].tBattleSceneOff;
    gSaveBlock2Ptr->optionsBattleStyle = gTasks[taskId].tBattleStyle;
    gSaveBlock2Ptr->optionsSound = gTasks[taskId].tSound;
    gSaveBlock2Ptr->optionsButtonMode = gTasks[taskId].tButtonMode;
    gSaveBlock2Ptr->optionsWindowFrameType = gTasks[taskId].tWindowFrameType;
    gSaveBlock2Ptr->optionsRandomCallsOff = gTasks[taskId].tRandomCallsOff;
    if (gSaveBlock2Ptr->optionsRubyPlayerSprites != gTasks[taskId].tPlayerSpriteStyle)
    {
        gSaveBlock2Ptr->optionsRubyPlayerSprites = gTasks[taskId].tPlayerSpriteStyle;
        // Replace the current field sprite in-place, preserving map and
        // movement state, and affecting only the selected playable style.
        if (sOptionMenuOnOverworld)
        {
            struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
            ObjectEventSetGraphicsId(player, player->graphicsId);
        }
    }

    if (sOptionMenuOnMainMenu)
    {
        // Both B and CANCEL restore the previous main menu in hidden
        // BG0, then switch the complete interface in VBlank. No fade.
        sOptionMenuOnMainMenu = FALSE;
        MainMenu_ReturnFromInlineOptions(taskId);
        return;
    }

    if (sOptionMenuOnOverworld)
    {
        // The original map and field tasks are still in memory.
        gTasks[taskId].data[8] = 0;
        gTasks[taskId].func = Task_ReturnFromFieldOption;
        return;
    }

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_OptionMenuFadeOut;
}

// Rebuild only the field's UI; BG1-BG3, tilesets, weather and object
// sprites remain untouched. The map itself is visible between menus.
static void Task_ReturnFromFieldOption(u8 taskId)
{
    switch (gTasks[taskId].data[8])
    {
    case 0:
        HideBg(0);
        FreeAllWindowBuffers();
        UnsetBgTilemapBuffer(0);

        // Build the correct Start menu in one step, using the preserved
        // map/field state. Restoring callback1 temporarily makes link-mode
        // and special Start menus detect the original field context.
        SetMainCallback1(sOptionSavedFieldCallback1);
        RestoreStartMenuFromOptionsNoFade();
        SetMainCallback1(NULL);
        gTasks[taskId].data[8] = 1;
        break;
    case 1:
    {
        u8 i;

        if (IsDma3ManagerBusyWithBgCopy()
         || CheckForSpaceForDma3Request(-1) != 0)
            break;

        for (i = 0; i < MAX_SPRITES; i++)
        {
            if (gSprites[i].inUse)
                gSprites[i].oam.priority = sFieldSavedSpritePriorities[i];
        }

        SetGpuReg(REG_OFFSET_WIN0H, sFieldSavedWin0H);
        SetGpuReg(REG_OFFSET_WIN0V, sFieldSavedWin0V);
        SetGpuReg(REG_OFFSET_WIN1H, sFieldSavedWin1H);
        SetGpuReg(REG_OFFSET_WIN1V, sFieldSavedWin1V);
        SetGpuReg(REG_OFFSET_WININ, sFieldSavedWinIn);
        SetGpuReg(REG_OFFSET_WINOUT, sFieldSavedWinOut);
        SetGpuReg(REG_OFFSET_BLDCNT, sFieldSavedBldCnt);
        SetGpuReg(REG_OFFSET_BLDALPHA, sFieldSavedBldAlpha);
        SetGpuReg(REG_OFFSET_BLDY, sFieldSavedBldY);
        SetGpuReg(REG_OFFSET_DISPCNT, sFieldSavedDispCnt);

        DestroyTask(taskId);
        sOptionMenuOnOverworld = FALSE;
        SetMainCallback1(sOptionSavedFieldCallback1);
        ShowBg(0);
        SetMainCallback2(CB2_Overworld);
        break;
    }
    }
}

static void Task_OptionMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
    }
}

static void HighlightOptionMenuItem(u8 index)
{
    // Redraw only the 8px gutter to erase the previous cursor, without
    // touching the option labels or their selected red/gray values.
    u8 desiredOffset = index >= OPTION_VISIBLE_ROWS ? (index - OPTION_VISIBLE_ROWS + 1) : 0;

    if (sOptionMenuScrollOffset != desiredOffset)
    {
        u8 taskId = FindTaskIdByFunc(Task_OptionMenuProcessInput);
        if (taskId == TASK_NONE && sOptionMenuOnOverworld)
            taskId = sFieldOptionTaskId;
        sOptionMenuScrollOffset = desiredOffset;
        sOptionMenuScrollRedraw = TRUE;
        DrawOptionMenuTexts();
        if (taskId != TASK_NONE)
            RedrawOptionChoices(taskId);
        sOptionMenuScrollRedraw = FALSE;
    }

    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 0, 0, 8,
                        OPTION_ROW_HEIGHT * OPTION_VISIBLE_ROWS);

    // Reuse Pokemon's existing triangular menu cursor. FONT_SHORT has a
    // 14px height, so even CANCEL (the last row) stays inside the window.
    AddTextPrinterParameterized(WIN_OPTIONS, FONT_SHORT, gText_SelectorArrow3,
                                0, (index - sOptionMenuScrollOffset) * OPTION_ROW_HEIGHT,
                                TEXT_SKIP_DRAW, NULL);
    if (!sOptionMenuPreparingInline)
        CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}

static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style)
{
    u8 dst[16];
    u16 i;

    for (i = 0; *text != EOS && i < ARRAY_COUNT(dst) - 1; i++)
        dst[i] = *(text++);

    if (style != 0)
    {
        dst[2] = TEXT_COLOR_RED;
        dst[5] = TEXT_COLOR_LIGHT_RED;
    }

    dst[i] = EOS;
    if (y / OPTION_ROW_HEIGHT < sOptionMenuScrollOffset
     || y / OPTION_ROW_HEIGHT >= sOptionMenuScrollOffset + OPTION_VISIBLE_ROWS)
        return;
    AddTextPrinterParameterized(WIN_OPTIONS, FONT_NORMAL, dst, x,
                                y - sOptionMenuScrollOffset * OPTION_ROW_HEIGHT + 1,
                                TEXT_SKIP_DRAW, NULL);
}

static u8 TextSpeed_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection <= 1)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = 2;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void TextSpeed_DrawChoices(u8 selection)
{
    u8 styles[3];
    s32 widthSlow, widthMid, widthFast, xMid;

    styles[0] = 0;
    styles[1] = 0;
    styles[2] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_TextSpeedSlow, 104, YPOS_TEXTSPEED, styles[0]);

    widthSlow = GetStringWidth(FONT_NORMAL, gText_TextSpeedSlow, 0);
    widthMid = GetStringWidth(FONT_NORMAL, gText_TextSpeedMid, 0);
    widthFast = GetStringWidth(FONT_NORMAL, gText_TextSpeedFast, 0);

    widthMid -= 94;
    xMid = (widthSlow - widthMid - widthFast) / 2 + 104;
    DrawOptionMenuChoice(gText_TextSpeedMid, xMid, YPOS_TEXTSPEED, styles[1]);

    DrawOptionMenuChoice(gText_TextSpeedFast, GetStringRightAlignXOffset(FONT_NORMAL, gText_TextSpeedFast, 198), YPOS_TEXTSPEED, styles[2]);
}

static u8 BattleScene_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void BattleScene_DrawChoices(u8 selection)
{
    u8 styles[2];

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_BattleSceneOn, 104, YPOS_BATTLESCENE, styles[0]);
    DrawOptionMenuChoice(gText_BattleSceneOff, GetStringRightAlignXOffset(FONT_NORMAL, gText_BattleSceneOff, 198), YPOS_BATTLESCENE, styles[1]);
}

static void RandomCalls_DrawChoices(u8 selection)
{
    u8 styles[2] = {0, 0};

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_BattleSceneOn, 104, YPOS_RANDOM_CALLS, styles[0]);
    DrawOptionMenuChoice(gText_BattleSceneOff, GetStringRightAlignXOffset(FONT_NORMAL, gText_BattleSceneOff, 198), YPOS_RANDOM_CALLS, styles[1]);
}

static void PlayerSprites_DrawChoices(u8 selection)
{
    DrawOptionMenuChoice(sText_Emerald, 104, YPOS_PLAYER_SPRITES, selection == 0);
    DrawOptionMenuChoice(sText_Ruby,
                         GetStringRightAlignXOffset(FONT_NORMAL, sText_Ruby, 198),
                         YPOS_PLAYER_SPRITES, selection == 1);
}

static void RedrawOptionChoices(u8 taskId)
{
    TextSpeed_DrawChoices(gTasks[taskId].tTextSpeed);
    BattleScene_DrawChoices(gTasks[taskId].tBattleSceneOff);
    BattleStyle_DrawChoices(gTasks[taskId].tBattleStyle);
    Sound_DrawChoices(gTasks[taskId].tSound);
    ButtonMode_DrawChoices(gTasks[taskId].tButtonMode);
    FrameType_DrawChoices(gTasks[taskId].tWindowFrameType);
    RandomCalls_DrawChoices(gTasks[taskId].tRandomCallsOff);
    PlayerSprites_DrawChoices(gTasks[taskId].tPlayerSpriteStyle);
}

static u8 BattleStyle_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void BattleStyle_DrawChoices(u8 selection)
{
    u8 styles[2];

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_BattleStyleShift, 104, YPOS_BATTLESTYLE, styles[0]);
    DrawOptionMenuChoice(gText_BattleStyleSet, GetStringRightAlignXOffset(FONT_NORMAL, gText_BattleStyleSet, 198), YPOS_BATTLESTYLE, styles[1]);
}

static u8 Sound_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        SetPokemonCryStereo(selection);
        sArrowPressed = TRUE;
    }

    return selection;
}

static void Sound_DrawChoices(u8 selection)
{
    u8 styles[2];

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_SoundMono, 104, YPOS_SOUND, styles[0]);
    DrawOptionMenuChoice(gText_SoundStereo, GetStringRightAlignXOffset(FONT_NORMAL, gText_SoundStereo, 198), YPOS_SOUND, styles[1]);
}

static void LoadOptionWindowFrame(u8 selection)
{
    if (sOptionMenuOnMainMenu)
    {
        // BG3 has independent character tiles. Do not recolor visible
        // BG0 until the finished options layer is activated in VBlank.
        LoadBgTiles(3, GetWindowFrameTilesPal(selection)->tiles,
                    0x120, INLINE_OPTION_FRAME_TILE);
        if (!sOptionMenuPreparingInline)
            LoadPalette(GetWindowFrameTilesPal(selection)->pal,
                        BG_PLTT_ID(INLINE_OPTION_FRAME_PALETTE), PLTT_SIZE_4BPP);
    }
    else if (sOptionMenuOnOverworld)
    {
        // Do not replace the map's BG1 tiles or its palette.
        LoadBgTiles(0, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, BG_PLTT_ID(14), PLTT_SIZE_4BPP);
    }
    else
    {
        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, BG_PLTT_ID(7), PLTT_SIZE_4BPP);
    }
}

static u8 FrameType_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection < WINDOW_FRAMES_COUNT - 1)
            selection++;
        else
            selection = 0;

        LoadOptionWindowFrame(selection);
        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = WINDOW_FRAMES_COUNT - 1;

        LoadOptionWindowFrame(selection);
        sArrowPressed = TRUE;
    }
    return selection;
}

static void FrameType_DrawChoices(u8 selection)
{
    u8 text[16] = {EOS};
    u8 n = selection + 1;
    u16 i;

    for (i = 0; gText_FrameTypeNumber[i] != EOS && i <= 5; i++)
        text[i] = gText_FrameTypeNumber[i];

    // Convert a number to decimal string
    if (n / 10 != 0)
    {
        text[i] = n / 10 + CHAR_0;
        i++;
        text[i] = n % 10 + CHAR_0;
        i++;
    }
    else
    {
        text[i] = n % 10 + CHAR_0;
        i++;
        text[i] = CHAR_SPACER;
        i++;
    }

    text[i] = EOS;

    DrawOptionMenuChoice(gText_FrameType, 104, YPOS_FRAMETYPE, 0);
    DrawOptionMenuChoice(text, 128, YPOS_FRAMETYPE, 1);
}

static u8 ButtonMode_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection <= 1)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = 2;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void ButtonMode_DrawChoices(u8 selection)
{
    s32 widthNormal, widthLR, widthLA, xLR;
    u8 styles[3];

    styles[0] = 0;
    styles[1] = 0;
    styles[2] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_ButtonTypeNormal, 104, YPOS_BUTTONMODE, styles[0]);

    widthNormal = GetStringWidth(FONT_NORMAL, gText_ButtonTypeNormal, 0);
    widthLR = GetStringWidth(FONT_NORMAL, gText_ButtonTypeLR, 0);
    widthLA = GetStringWidth(FONT_NORMAL, gText_ButtonTypeLEqualsA, 0);

    widthLR -= 94;
    xLR = (widthNormal - widthLR - widthLA) / 2 + 104;
    DrawOptionMenuChoice(gText_ButtonTypeLR, xLR, YPOS_BUTTONMODE, styles[1]);

    DrawOptionMenuChoice(gText_ButtonTypeLEqualsA, GetStringRightAlignXOffset(FONT_NORMAL, gText_ButtonTypeLEqualsA, 198), YPOS_BUTTONMODE, styles[2]);
}

static void DrawHeaderText(void)
{
    FillWindowPixelBuffer(WIN_HEADER, PIXEL_FILL(1));
    AddTextPrinterParameterized(WIN_HEADER, FONT_NORMAL, gText_Option, 8, 1, TEXT_SKIP_DRAW, NULL);
    if (!sOptionMenuPreparingInline)
        CopyWindowToVram(WIN_HEADER, COPYWIN_FULL);
}

static void DrawOptionMenuTexts(void)
{
    u8 i;

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
    for (i = sOptionMenuScrollOffset; i < MENUITEM_COUNT
              && i < sOptionMenuScrollOffset + OPTION_VISIBLE_ROWS; i++)
        AddTextPrinterParameterized(WIN_OPTIONS, FONT_NORMAL, sOptionMenuItemsNames[i],
            8, (i - sOptionMenuScrollOffset) * OPTION_ROW_HEIGHT + 1,
            TEXT_SKIP_DRAW, NULL);
    if (!sOptionMenuPreparingInline && !sOptionMenuScrollRedraw)
        CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}

#define TILE_TOP_CORNER_L 0x1A2
#define TILE_TOP_EDGE     0x1A3
#define TILE_TOP_CORNER_R 0x1A4
#define TILE_LEFT_EDGE    0x1A5
#define TILE_RIGHT_EDGE   0x1A7
#define TILE_BOT_CORNER_L 0x1A8
#define TILE_BOT_EDGE     0x1A9
#define TILE_BOT_CORNER_R 0x1AA

static void DrawBgWindowFrames(void)
{
    const u8 bg = sOptionMenuOnOverworld ? 0 : 1;
    const u8 pal = sOptionMenuOnOverworld ? 14 : 7;
    //                     bg, tile,              x, y, width, height, palNum
    // Draw title window frame
    FillBgTilemapBufferRect(bg, TILE_TOP_CORNER_L,  1,  0,  1,  1, pal);
    FillBgTilemapBufferRect(bg, TILE_TOP_EDGE,      2,  0, 27,  1, pal);
    FillBgTilemapBufferRect(bg, TILE_TOP_CORNER_R, 28,  0,  1,  1, pal);
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE,     1,  1,  1,  2, pal);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE,   28,  1,  1,  2, pal);
    FillBgTilemapBufferRect(bg, TILE_BOT_CORNER_L,  1,  3,  1,  1, pal);
    FillBgTilemapBufferRect(bg, TILE_BOT_EDGE,      2,  3, 27,  1, pal);
    FillBgTilemapBufferRect(bg, TILE_BOT_CORNER_R, 28,  3,  1,  1, pal);

    // Draw options list window frame
    FillBgTilemapBufferRect(bg, TILE_TOP_CORNER_L,  1,  4,  1,  1, pal);
    FillBgTilemapBufferRect(bg, TILE_TOP_EDGE,      2,  4, 26,  1, pal);
    FillBgTilemapBufferRect(bg, TILE_TOP_CORNER_R, 28,  4,  1,  1, pal);
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE,     1,  5,  1, 18, pal);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE,   28,  5,  1, 18, pal);
    FillBgTilemapBufferRect(bg, TILE_BOT_CORNER_L,  1, 19,  1,  1, pal);
    FillBgTilemapBufferRect(bg, TILE_BOT_EDGE,      2, 19, 26,  1, pal);
    FillBgTilemapBufferRect(bg, TILE_BOT_CORNER_R, 28, 19,  1,  1, pal);

    // In-game OPTION uploads BG0 only once, after every option label,
    // value and border has been written into its RAM tilemap.
    if (!(sOptionMenuOnOverworld && sOptionMenuPreparingInline))
        CopyBgTilemapBufferToVram(bg);
}
