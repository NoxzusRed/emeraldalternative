Route127_Cave_MapScripts::
	.byte 0

Route127_Cave_EventScript_Camerupt::
	playmoncry SPECIES_CAMERUPT, CRY_MODE_NORMAL
	msgbox Route127_Cave_Text_Vruuubuh, MSGBOX_SIGN
	end

Route127_Cave_EventScript_Carkol::
	playmoncry SPECIES_CARKOL, CRY_MODE_NORMAL
	msgbox Route127_Cave_Text_Skreeevruuum, MSGBOX_SIGN
	end

Route127_Cave_EventScript_Golbat::
	playmoncry SPECIES_GOLBAT, CRY_MODE_NORMAL
	msgbox Route127_Cave_Text_GolbatPokeball, MSGBOX_SIGN
	end

Route127_Cave_EventScript_MagmaGrunt::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_FLAMETHROWER, Route127_Cave_EventScript_ReceivedFlamethrower
	msgbox Route127_Cave_Text_BringRevive, MSGBOX_DEFAULT
	checkitem ITEM_REVIVE
	goto_if_eq VAR_RESULT, TRUE, Route127_Cave_EventScript_AskToTradeForRevive
	release
	end

Route127_Cave_EventScript_AskToTradeForRevive::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox Route127_Cave_Text_TradeReviveForFlamethrower, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route127_Cave_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, Route127_Cave_EventScript_DeclineTrade
	end

Route127_Cave_EventScript_AcceptTrade::
	msgbox Route127_Cave_Text_IllTradeYouFlamethrower, MSGBOX_DEFAULT
	giveitem ITEM_TM_FLAMETHROWER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_REVIVE
	setflag FLAG_RECEIVED_TM_FLAMETHROWER
	goto Route127_Cave_EventScript_ReceivedFlamethrower
	end

Route127_Cave_EventScript_ReceivedFlamethrower::
	msgbox Route127_Cave_Text_ThankYouForHelpingGolbat, MSGBOX_DEFAULT
	release
	end

Route127_Cave_EventScript_DeclineTrade::
	msgbox Route127_Cave_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

Route127_Cave_Text_Vruuubuh:
	.string "Vruuu-buh...$"	

Route127_Cave_Text_Skreeevruuum:
	.string "Skreee-vruuum!$"	

Route127_Cave_Text_GolbatPokeball:
	.string "There seems to be a Golbat in this\n"
	.string "Pokeball.$"

Route127_Cave_Text_BringRevive:
	.string "I got stranded in this island and my\n"
	.string "Golbat fainted. Can you bring me a\l"
	.string "Revive so I can heal it?\p"
	.string "I'll make it worth your while...$"

Route127_Cave_Text_TradeReviveForFlamethrower:
	.string "Oh! You have a Revive?\n"
	.string "Will you trade it for a TM Flamethrower?$"

Route127_Cave_Text_IllTradeYouFlamethrower:
	.string "Great!\n"
	.string "I can finally heal my Golbat!\p"
	.string "Okay, I'll trade you a TM Flamethrower!$"

Route127_Cave_Text_ThankYouForHelpingGolbat:
	.string "Thank you for helping my Golbat. Now I\n"
	.string "can go back to the Hideout.$"

Route127_Cave_Text_ThatsDisappointing:
	.string "But... Golbat is agonizing...$"
