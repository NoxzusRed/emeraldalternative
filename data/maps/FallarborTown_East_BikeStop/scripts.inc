FallarborTown_East_BikeStop_MapScripts::
	.byte 0

FallarborTown_East_BikeStop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, FallarborTown_East_BikeStop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, FallarborTown_East_BikeStop_EventScript_SkipGreeting
	msgbox FallarborTown_East_BikeStop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox FallarborTown_East_BikeStop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FallarborTown_East_BikeStop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, FallarborTown_East_BikeStop_EventScript_NotFar
	end

FallarborTown_East_BikeStop_EventScript_SkipGreeting::
	msgbox FallarborTown_East_BikeStop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FallarborTown_East_BikeStop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, FallarborTown_East_BikeStop_EventScript_NotFar
	end

FallarborTown_East_BikeStop_EventScript_ChooseBike::
	message FallarborTown_East_BikeStop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, FallarborTown_East_BikeStop_EventScript_GetMachBike
	case 1, FallarborTown_East_BikeStop_EventScript_GetAcroBike
	end

FallarborTown_East_BikeStop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox FallarborTown_East_BikeStop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

FallarborTown_East_BikeStop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto FallarborTown_East_BikeStop_EventScript_ChooseBike
	end

FallarborTown_East_BikeStop_EventScript_GetMachBike::
	msgbox FallarborTown_East_BikeStop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto FallarborTown_East_BikeStop_EventScript_ComeBackToSwitchBikes
	end

FallarborTown_East_BikeStop_EventScript_GetAcroBike::
	msgbox FallarborTown_East_BikeStop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto FallarborTown_East_BikeStop_EventScript_ComeBackToSwitchBikes
	end

FallarborTown_East_BikeStop_EventScript_ComeBackToSwitchBikes::
	msgbox FallarborTown_East_BikeStop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

FallarborTown_East_BikeStop_EventScript_AskSwitchBikes::
	msgbox FallarborTown_East_BikeStop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FallarborTown_East_BikeStop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, FallarborTown_East_BikeStop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
FallarborTown_East_BikeStop_EventScript_SwitchBikes::
	msgbox FallarborTown_East_BikeStop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_East_BikeStop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_East_BikeStop_EventScript_SwitchMachForAcro
	msgbox FallarborTown_East_BikeStop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

FallarborTown_East_BikeStop_EventScript_KeepBike::
	msgbox FallarborTown_East_BikeStop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

FallarborTown_East_BikeStop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox FallarborTown_East_BikeStop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto FallarborTown_East_BikeStop_EventScript_ComeBackToSwitchBikes
	end

FallarborTown_East_BikeStop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox FallarborTown_East_BikeStop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto FallarborTown_East_BikeStop_EventScript_ComeBackToSwitchBikes
	end

FallarborTown_East_BikeStop_Text_RydelGreeting:
	.string "Well, well, what have we here?\n"
	.string "A most energetic customer!\p"
	.string "Me? You may call me RYDEL.\n"
	.string "I'm the owner of this cycle shop.$"

FallarborTown_East_BikeStop_Text_DidYouComeFromFarAway:
	.string "RYDEL: Your RUNNING SHOES…\n"
	.string "They're awfully filthy.\p"
	.string "Did you come from far away?$"

FallarborTown_East_BikeStop_Text_GuessYouDontNeedBike:
	.string "RYDEL: Is that right?\p"
	.string "Then, I guess you have no need for\n"
	.string "any of my BIKES.$"

FallarborTown_East_BikeStop_Text_ExplainBikesChooseWhichOne:
	.string "RYDEL: Hm, hm… … … … …\p"
	.string "You're saying that you came all this\n"
	.string "way from LITTLEROOT?\p"
	.string "My goodness!\n"
	.string "That's ridiculously far!\p"
	.string "If you had one of my BIKES, you could\n"
	.string "go anywhere easily while feeling the\l"
	.string "gentle caress of the wind!\p"
	.string "I'll tell you what!\n"
	.string "I'll give you a BIKE!\p"
	.string "Oh, wait a second!\p"
	.string "I forgot to tell you that there are\n"
	.string "two kinds of BIKES!\p"
	.string "They are the MACH BIKE and\n"
	.string "the ACRO BIKE!\p"
	.string "The MACH BIKE is for cyclists who want\n"
	.string "to feel the wind with their bodies!\p"
	.string "And an ACRO BIKE is for those who\n"
	.string "prefer technical rides!\p"
	.string "I'm a real sweetheart, so you can\n"
	.string "have whichever one you like!\p"
	.string "Which one will you choose?$"

FallarborTown_East_BikeStop_Text_ChoseMachBike:
	.string "{PLAYER} chose the MACH BIKE.$"

FallarborTown_East_BikeStop_Text_ChoseAcroBike:
	.string "{PLAYER} chose the ACRO BIKE.$"

FallarborTown_East_BikeStop_Text_ComeBackToSwitchBikes:
	.string "RYDEL: If you get the urge to switch\n"
	.string "BIKES, just come see me!$"

FallarborTown_East_BikeStop_Text_WantToSwitchBikes:
	.string "RYDEL: Oh? Were you thinking about\n"
	.string "switching BIKES?$"

FallarborTown_East_BikeStop_Text_IllSwitchBikes:
	.string "RYDEL: Okay, no problem!\n"
	.string "I'll switch BIKES for you!$"

FallarborTown_East_BikeStop_Text_ExchangedMachForAcro:
	.string "{PLAYER} got the MACH BIKE exchanged\n"
	.string "for an ACRO BIKE.$"

FallarborTown_East_BikeStop_Text_ExchangedAcroForMach:
	.string "{PLAYER} got the ACRO BIKE exchanged\n"
	.string "for a MACH BIKE.$"

FallarborTown_East_BikeStop_Text_HappyYouLikeIt:
	.string "RYDEL: Good, good!\n"
	.string "I'm happy that you like it!$"

FallarborTown_East_BikeStop_Text_OhYourBikeIsInPC:
	.string "Oh? What happened to that BIKE\n"
	.string "I gave you?\p"
	.string "Oh, I get it, you stored it using your PC.\p"
	.string "Well, take it out of PC storage,\n"
	.string "and I'll be happy to exchange it!\p"
	.string "May the wind always be at your back\n"
	.string "on your adventure!$"
