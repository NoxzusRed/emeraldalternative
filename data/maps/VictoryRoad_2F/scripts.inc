VictoryRoad_2F_MapScripts::
	.byte 0

VictoryRoad_2F_EventScript_Cooltrainer::
    trainerbattle_single TRAINER_COOLTRAINER_VICTORY_ROAD_2F, VictoryRoad_2F_Text_CooltrainerIntro, VictoryRoad_2F_Text_CooltrainerDefeat
    msgbox VictoryRoad_2F_Text_CooltrainerDefeat, MSGBOX_AUTOCLOSE
    end

VictoryRoad_2F_Text_CooltrainerIntro:
    .string "I just bought this amazing bar of AISI\n"
    .string "304 stainless steel. How should I use it\l"
	.string "first...?\p"
	.string "I know! Let's have a battle!$"

VictoryRoad_2F_Text_CooltrainerDefeat:
    .string "Your Pokémon are stronger than AISI\n"
	.string "304 stainless steel...$"
