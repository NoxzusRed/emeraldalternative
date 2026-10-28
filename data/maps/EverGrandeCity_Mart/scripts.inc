EverGrandeCity_Mart_MapScripts::
	.byte 0

EverGrandeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EverGrandeCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
EverGrandeCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	pokemartlistend

SootopolisCity_Mart_EventScript_CoolTrainerF::
	lock
	faceplayer
	msgbox EverGrandeCity_Mart_Text_CoolTrainerF, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Mart_EventScript_CoolTrainerM::
	lock
	faceplayer
	msgbox EverGrandeCity_Mart_Text_CoolTrainerM, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_Mart_Text_CoolTrainerM:
	.string "I am having to refill again for the\n"
	.string "fourth time...\p"
	.string "After beating Norman I did not think it\n"
	.string "could get any harder.$"

EverGrandeCity_Mart_Text_CoolTrainerF:
	.string "I have to get a bunch of Hyper Potions\n"
	.string "and Full Heals before going into\l"
	.string "Victory Road.$"
