Route111_East_MapScripts::
	.byte 0

Route111_East_EventScript_HexManiac::
    trainerbattle_single TRAINER_HEX_MANIAC_ROUTE111_EAST, Route111_East_Text_HexManiacIntro, Route111_East_Text_HexManiacDefeat
    msgbox Route111_East_Text_HexManiacDefeat, MSGBOX_AUTOCLOSE
    end

Route111_East_Text_HexManiacIntro:
    .string "Can you hear the voices of the\n"
    .string "desert?$"

Route111_East_Text_HexManiacDefeat:
    .string "The spirits have abandoned me...$"
