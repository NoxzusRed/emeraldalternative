Route111_Cave_MapScripts::
	.byte 0

Route111_Cave_EventScript_RuinManiac::
    trainerbattle_single TRAINER_RUIN_MANIAC_ROUTE111_CAVE, Route111_Cave_Text_RuinManiacIntro, Route111_Cave_Text_RuinManiacDefeat
    msgbox Route111_Cave_Text_RuinManiacPostBattle, MSGBOX_AUTOCLOSE
    end

Route111_Cave_Text_RuinManiacIntro:
    .string "There is a treasure at the end of this\n"
    .string "cave... and I'm gonna have it!$"

Route111_Cave_Text_RuinManiacDefeat:
    .string "I'm not getting any treasure...$"

Route111_Cave_Text_RuinManiacPostBattle:
    .string "I'll look for treasure somewhere else.$"
