Route111_Cave_MapScripts::
	.byte 0

Route111_Cave_EventScript_RuinManiac::
    trainerbattle_single TRAINER_RUIN_MANIAC_ROUTE111_CAVE, Route111_Cave_Text_RuinManiacIntro, Route111_Cave_Text_RuinManiacDefeat
    msgbox Route111_Cave_Text_RuinManiacPostBattle, MSGBOX_AUTOCLOSE
    end

Route111_Cave_EventScript_Beauty::
    trainerbattle_single TRAINER_CAMILA, Route111_Cave_Text_BeautyIntro, Route111_Cave_Text_BeautyDefeat
    msgbox Route111_Cave_Text_BeautyPostBattle, MSGBOX_AUTOCLOSE
    end

Route111_Cave_Text_RuinManiacIntro:
    .string "There is a treasure at the end of this\n"
    .string "cave... and I'm gonna have it!$"

Route111_Cave_Text_RuinManiacDefeat:
    .string "I'm not getting any treasure...$"

Route111_Cave_Text_RuinManiacPostBattle:
    .string "I'll look for treasure somewhere else.$"

Route111_Cave_Text_BeautyIntro:
    .string "The desert sun is a nightmare for my\n"
    .string "skin!\p"
	.string "Don't mistake my hiding in this cave for\n"
	.string "weakness though!$"

Route111_Cave_Text_BeautyDefeat:
    .string "Oh, no!\n"
	.string "Stressing over a loss gives me wrinkles!$"

Route111_Cave_Text_BeautyPostBattle:
    .string "The iron oxides and silicates in these\n"
	.string "rocks make a flawless exfoliating mask.\l"
	.string "I'm not leaving until sunset!$"
