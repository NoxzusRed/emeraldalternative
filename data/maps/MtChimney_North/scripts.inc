MtChimney_North_MapScripts::
	.byte 0

@ Only the first team variant is used here. These are not tournament runs.
@ PWT Champion Blue: variant 1, repeatable test battle.
MtChimney_North_EventScript_PwtBlue::
    lock
    faceplayer
    trainerbattle_no_intro TRAINER_PWT_TEST_BLUE, MtChimney_North_Text_PwtDefeat
    release
    end

@ PWT Champion Red: variant 1, repeatable test battle.
MtChimney_North_EventScript_PwtRed::
    lock
    faceplayer
    trainerbattle_no_intro TRAINER_PWT_TEST_RED, MtChimney_North_Text_PwtDefeat
    release
    end

@ PWT Champion Lance: variant 1, repeatable test battle.
MtChimney_North_EventScript_PwtLance::
    lock
    faceplayer
    trainerbattle_no_intro TRAINER_PWT_TEST_LANCE, MtChimney_North_Text_PwtDefeat
    release
    end

@ PWT Champion Steven: variant 1, repeatable test battle.
MtChimney_North_EventScript_PwtSteven::
    lock
    faceplayer
    trainerbattle_no_intro TRAINER_PWT_TEST_STEVEN, MtChimney_North_Text_PwtDefeat
    release
    end

@ PWT Champion Wallace: variant 1, repeatable test battle.
MtChimney_North_EventScript_PwtWallace::
    lock
    faceplayer
    trainerbattle_no_intro TRAINER_PWT_TEST_WALLACE, MtChimney_North_Text_PwtDefeat
    release
    end

@ PWT Champion Cynthia: variant 1, repeatable test battle.
MtChimney_North_EventScript_PwtCynthia::
    lock
    faceplayer
    trainerbattle_no_intro TRAINER_PWT_TEST_CYNTHIA, MtChimney_North_Text_PwtDefeat
    release
    end

@ PWT Champion Alder: variant 1, repeatable test battle.
MtChimney_North_EventScript_PwtAlder::
    lock
    faceplayer
    trainerbattle_no_intro TRAINER_PWT_TEST_ALDER, MtChimney_North_Text_PwtDefeat
    release
    end

@ PWT Champion Iris: variant 1, repeatable test battle.
MtChimney_North_EventScript_PwtIris::
    lock
    faceplayer
    trainerbattle_no_intro TRAINER_PWT_TEST_IRIS, MtChimney_North_Text_PwtDefeat
    release
    end

@ PWT Champion Diantha: variant 1, repeatable test battle.
MtChimney_North_EventScript_PwtDiantha::
    lock
    faceplayer
    trainerbattle_no_intro TRAINER_PWT_TEST_DIANTHA, MtChimney_North_Text_PwtDefeat
    release
    end

@ PWT Champion Leon: variant 1, repeatable test battle.
MtChimney_North_EventScript_PwtLeon::
    lock
    faceplayer
    trainerbattle_no_intro TRAINER_PWT_TEST_LEON, MtChimney_North_Text_PwtDefeat
    release
    end

MtChimney_North_Text_PwtDefeat:
    .string "Well fought!$"
