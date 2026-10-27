RusturfTunnel_High_MapScripts::
	.byte 0

RusturfTunnel_High_EventScript_Psychic::
    trainerbattle_single TRAINER_PSYCHIC_RUSTURF_HIGH, RusturfTunnel_High_Text_PsychicIntro, RusturfTunnel_High_Text_PsychicDefeat
    msgbox RusturfTunnel_High_Text_PsychicPostBattle, MSGBOX_AUTOCLOSE
    end

RusturfTunnel_High_EventScript_Gentleman::
    trainerbattle_single TRAINER_GENTLEMAN_RUSTURF_HIGH, RusturfTunnel_High_Text_GentlemanIntro, RusturfTunnel_High_Text_GentlemanDefeat
    msgbox RusturfTunnel_High_Text_GentlemanPostBattle, MSGBOX_AUTOCLOSE
    end

RusturfTunnel_High_Text_PsychicIntro:
    .string "I forsaw your coming long before you\n"
    .string "arrived in my dreams...$"

RusturfTunnel_High_Text_PsychicDefeat:
    .string "I didn't dream this outcome...$"

RusturfTunnel_High_Text_PsychicPostBattle:
    .string "Even psychic powers have their limits...$"

RusturfTunnel_High_Text_GentlemanIntro:
    .string "A true gentleman never refuses a\n"
    .string "challenge!$"

RusturfTunnel_High_Text_GentlemanDefeat:
    .string "What an impressive performance!$"

RusturfTunnel_High_Text_GentlemanPostBattle:
    .string "A splendid battle, indeed!\n"
    .string "You have my respect.$"
