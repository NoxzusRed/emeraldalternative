FallarborMines_B1F_MapScripts::
	.byte 0

FallarborMines_B1F_EventScript_Kindler::
    trainerbattle_single TRAINER_KINDLER_FALLARBOR_MINES, FallarborMines_B1F_Text_KindlerIntro, FallarborMines_B1F_Text_KindlerDefeat
    msgbox FallarborMines_B1F_Text_KindlerPostBattle, MSGBOX_AUTOCLOSE
    end

FallarborMines_B1F_Text_KindlerIntro:
    .string "These mines are hotter than they look!$"

FallarborMines_B1F_Text_KindlerDefeat:
    .string "My flames went out...$"

FallarborMines_B1F_Text_KindlerPostBattle:
    .string "The deeper you dig, the hotter it gets!$"
