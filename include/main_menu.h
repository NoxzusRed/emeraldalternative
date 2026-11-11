#ifndef GUARD_MAIN_MENU_H
#define GUARD_MAIN_MENU_H

void CB2_InitMainMenu(void);
void MainMenu_ReturnFromInlineOptions(u8 taskId);
void MainMenu_QueueInlineBackgroundSwap(bool8 showOptions);
bool8 MainMenu_IsInlineBackgroundSwapPending(void);
void MainMenu_StartInlineOptionsBlackout(void);
void MainMenu_FinishInlineOptionsBlackout(void);
struct WindowTemplate;
void DrawMainMenuWindowBorder(const struct WindowTemplate *template, u16 baseTileNum);
void CreateYesNoMenuParameterized(u8 x, u8 y, u16 baseTileNum, u16 baseBlock, u8 yesNoPalNum, u8 winPalNum);
void NewGameBirchSpeech_SetDefaultPlayerName(u8);

#endif // GUARD_MAIN_MENU_H
