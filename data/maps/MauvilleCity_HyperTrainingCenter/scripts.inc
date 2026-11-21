MauvilleCity_HyperTrainingCenter_MapScripts::
	.byte 0

MauvilleCity_HyperTrainingCenter_EventScript_Trainer::
	lock
	faceplayer
	msgbox MauvilleCity_HyperTrainingCenter_Text_Intro, MSGBOX_YESNO
	goto_if_ne VAR_RESULT, YES, MauvilleCity_HyperTrainingCenter_EventScript_Exit
	goto MauvilleCity_HyperTrainingCenter_EventScript_CheckCaps

MauvilleCity_HyperTrainingCenter_EventScript_CheckCaps::
	checkitem ITEM_BOTTLE_CAP
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_HyperTrainingCenter_EventScript_ChooseMon
	checkitem ITEM_GOLD_BOTTLE_CAP
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_HyperTrainingCenter_EventScript_ChooseMon
	msgbox MauvilleCity_HyperTrainingCenter_Text_NoCaps, MSGBOX_DEFAULT
	goto MauvilleCity_HyperTrainingCenter_EventScript_Exit

MauvilleCity_HyperTrainingCenter_EventScript_ChooseMon::
	msgbox MauvilleCity_HyperTrainingCenter_Text_ChooseMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_HyperTrainingCenter_EventScript_Exit
	specialvar VAR_RESULT, HyperTraining_CheckMon
	goto_if_eq VAR_RESULT, 1, MauvilleCity_HyperTrainingCenter_EventScript_IsEgg
	goto_if_eq VAR_RESULT, 2, MauvilleCity_HyperTrainingCenter_EventScript_MonPerfect
	goto_if_ne VAR_RESULT, 0, MauvilleCity_HyperTrainingCenter_EventScript_Exit
	goto MauvilleCity_HyperTrainingCenter_EventScript_ChooseCap

MauvilleCity_HyperTrainingCenter_EventScript_IsEgg::
	msgbox MauvilleCity_HyperTrainingCenter_Text_Egg, MSGBOX_DEFAULT
	goto MauvilleCity_HyperTrainingCenter_EventScript_ChooseMon

MauvilleCity_HyperTrainingCenter_EventScript_MonPerfect::
	msgbox MauvilleCity_HyperTrainingCenter_Text_MonPerfect, MSGBOX_DEFAULT
	goto MauvilleCity_HyperTrainingCenter_EventScript_ChooseMon

MauvilleCity_HyperTrainingCenter_EventScript_ChooseCap::
	msgbox MauvilleCity_HyperTrainingCenter_Text_ChooseCap, MSGBOX_DEFAULT
	multichoice 13, 0, MULTI_HYPER_TRAINING_CAPS, FALSE
	goto_if_eq VAR_RESULT, 0, MauvilleCity_HyperTrainingCenter_EventScript_UseBottleCap
	goto_if_eq VAR_RESULT, 1, MauvilleCity_HyperTrainingCenter_EventScript_UseGoldCap
	goto MauvilleCity_HyperTrainingCenter_EventScript_Exit

MauvilleCity_HyperTrainingCenter_EventScript_UseBottleCap::
	checkitem ITEM_BOTTLE_CAP
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_HyperTrainingCenter_EventScript_MissingCap
	setvar VAR_0x8006, 0
	goto MauvilleCity_HyperTrainingCenter_EventScript_ChooseStat

MauvilleCity_HyperTrainingCenter_EventScript_UseGoldCap::
	checkitem ITEM_GOLD_BOTTLE_CAP
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_HyperTrainingCenter_EventScript_MissingCap
	setvar VAR_0x8006, 1
	msgbox MauvilleCity_HyperTrainingCenter_Text_ConfirmGold, MSGBOX_YESNO
	goto_if_ne VAR_RESULT, YES, MauvilleCity_HyperTrainingCenter_EventScript_ChooseCap
	goto MauvilleCity_HyperTrainingCenter_EventScript_ApplyCap

MauvilleCity_HyperTrainingCenter_EventScript_MissingCap::
	msgbox MauvilleCity_HyperTrainingCenter_Text_MissingCap, MSGBOX_DEFAULT
	goto MauvilleCity_HyperTrainingCenter_EventScript_ChooseCap

MauvilleCity_HyperTrainingCenter_EventScript_ChooseStat::
	msgbox MauvilleCity_HyperTrainingCenter_Text_ChooseStat, MSGBOX_DEFAULT
	multichoice 17, 0, MULTI_HYPER_TRAINING_STATS, FALSE
	goto_if_ge VAR_RESULT, 6, MauvilleCity_HyperTrainingCenter_EventScript_ChooseCap
	copyvar VAR_0x8005, VAR_RESULT
	specialvar VAR_RESULT, HyperTraining_CanTrainStat
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_HyperTrainingCenter_EventScript_StatPerfect
	msgbox MauvilleCity_HyperTrainingCenter_Text_ConfirmStat, MSGBOX_YESNO
	goto_if_ne VAR_RESULT, YES, MauvilleCity_HyperTrainingCenter_EventScript_ChooseStat
	goto MauvilleCity_HyperTrainingCenter_EventScript_ApplyCap

MauvilleCity_HyperTrainingCenter_EventScript_StatPerfect::
	msgbox MauvilleCity_HyperTrainingCenter_Text_StatPerfect, MSGBOX_DEFAULT
	goto MauvilleCity_HyperTrainingCenter_EventScript_ChooseStat

MauvilleCity_HyperTrainingCenter_EventScript_ApplyCap::
	specialvar VAR_RESULT, HyperTraining_ApplyCap
	goto_if_eq VAR_RESULT, 0, MauvilleCity_HyperTrainingCenter_EventScript_Trained
	goto_if_eq VAR_RESULT, 1, MauvilleCity_HyperTrainingCenter_EventScript_MissingCap
	goto_if_eq VAR_RESULT, 2, MauvilleCity_HyperTrainingCenter_EventScript_MonPerfect
	goto MauvilleCity_HyperTrainingCenter_EventScript_Exit

MauvilleCity_HyperTrainingCenter_EventScript_Trained::
	goto_if_eq VAR_0x8006, 1, MauvilleCity_HyperTrainingCenter_EventScript_TrainedAll
	msgbox MauvilleCity_HyperTrainingCenter_Text_TrainedStat, MSGBOX_DEFAULT
	goto MauvilleCity_HyperTrainingCenter_EventScript_AskAgain

MauvilleCity_HyperTrainingCenter_EventScript_TrainedAll::
	msgbox MauvilleCity_HyperTrainingCenter_Text_TrainedAll, MSGBOX_DEFAULT

MauvilleCity_HyperTrainingCenter_EventScript_AskAgain::
	msgbox MauvilleCity_HyperTrainingCenter_Text_AskAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_HyperTrainingCenter_EventScript_CheckCaps

MauvilleCity_HyperTrainingCenter_EventScript_Exit::
	release
	end

MauvilleCity_HyperTrainingCenter_Text_Intro:
	.string "Welcome! Ready to bring out your\n"
	.string "Pokémon's full potential?\p"
	.string "With a BOTTLE CAP, I can raise one IV\n"
	.string "to 31. A GOLD BOTTLE CAP raises all six!\p"
	.string "Shall we get started?$"

MauvilleCity_HyperTrainingCenter_Text_NoCaps:
	.string "You need a BOTTLE CAP or a GOLD BOTTLE\n"
	.string "CAP to train your Pokémon.\p"
	.string "Come back when you have one!$"

MauvilleCity_HyperTrainingCenter_Text_ChooseMon:
	.string "Which Pokémon should I train?$"

MauvilleCity_HyperTrainingCenter_Text_Egg:
	.string "I can't train an EGG!\n"
	.string "Please choose another POKéMON.$"

MauvilleCity_HyperTrainingCenter_Text_MonPerfect:
	.string "{STR_VAR_1} already has perfect\n"
	.string "IVs! No CAP is needed.$"

MauvilleCity_HyperTrainingCenter_Text_ChooseCap:
	.string "Which type of BOTTLE CAP would you like\n"
	.string "to use?$"

MauvilleCity_HyperTrainingCenter_Text_MissingCap:
	.string "You don't have that kind of CAP.\n"
	.string "Please choose another.$"

MauvilleCity_HyperTrainingCenter_Text_ChooseStat:
	.string "Which stat should I maximize?$"

MauvilleCity_HyperTrainingCenter_Text_StatPerfect:
	.string "{STR_VAR_1}'s {STR_VAR_2} IV is\n"
	.string "already 31. No CAP needed!$"

MauvilleCity_HyperTrainingCenter_Text_ConfirmStat:
	.string "Use one BOTTLE CAP to maximize\n"
	.string "{STR_VAR_1}'s {STR_VAR_2} IV?$"

MauvilleCity_HyperTrainingCenter_Text_ConfirmGold:
	.string "Use one GOLD BOTTLE CAP to max\n"
	.string "all of {STR_VAR_1}'s IVs?$"

MauvilleCity_HyperTrainingCenter_Text_TrainedStat:
	.string "Excellent! {STR_VAR_1}'s {STR_VAR_2}\n"
	.string "now has an IV of 31!$"

MauvilleCity_HyperTrainingCenter_Text_TrainedAll:
	.string "Excellent! All of {STR_VAR_1}'s\n"
	.string "IVs are now 31!$"

MauvilleCity_HyperTrainingCenter_Text_AskAgain:
	.string "Would you like to train another\n"
	.string "Pokémon?$"

MauvilleCity_HyperTrainingCenter_EventScript_Woman::
	msgbox MauvilleCity_HyperTrainingCenter_Text_Woman, MSGBOX_NPC
	end

MauvilleCity_HyperTrainingCenter_EventScript_ManNearEntrance::
	msgbox MauvilleCity_HyperTrainingCenter_Text_ManNearEntrance, MSGBOX_NPC
	end

MauvilleCity_HyperTrainingCenter_EventScript_ManByWall::
	msgbox MauvilleCity_HyperTrainingCenter_Text_ManByWall, MSGBOX_NPC
	end

MauvilleCity_HyperTrainingCenter_EventScript_Cooltrainer::
	msgbox MauvilleCity_HyperTrainingCenter_Text_Cooltrainer, MSGBOX_NPC
	end

MauvilleCity_HyperTrainingCenter_Text_Woman:
	.string "Everyone trains their Pokémon to\n"
	.string "higher levels, but there's more\l"
	.string "to strength than experience.\p"
	.string "Each Pokémon has hidden values\n"
	.string "called IVs. 31 is the highest!$"

MauvilleCity_HyperTrainingCenter_Text_ManNearEntrance:
	.string "My POKéMON had a weak DEFENSE IV.\n"
	.string "One BOTTLE CAP raised it to 31!\p"
	.string "You have to pick the stat, though.\n"
	.string "Each CAP only improves one.$"

MauvilleCity_HyperTrainingCenter_Text_ManByWall:
	.string "A GOLD BOTTLE CAP raises all six\n"
	.string "IVs to 31 in one go!\p"
	.string "But if only one stat needs help,\n"
	.string "I'd save the gold one for later.$"

MauvilleCity_HyperTrainingCenter_Text_Cooltrainer:
	.string "I just finished HYPER TRAINING!\p"
	.string "My POKéMON's IVs improved for\n"
	.string "good, and its stats went up\l"
	.string "right away!\p"
	.string "EV training is different, though.\n"
	.string "There's always more to work on!$"

