PacifidlogTown_House6_MapScripts::
	.byte 0

PacifidlogTown_House6_EventScript_Girl::
	msgbox PacifidlogTown_House6_Text_PowerItems, MSGBOX_NPC
	end

PacifidlogTown_House6_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart PacifidlogTown_House6Clerk
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PacifidlogTown_House6Clerk:
	.2byte ITEM_POWER_WEIGHT
	.2byte ITEM_POWER_BRACER
	.2byte ITEM_POWER_BELT
	.2byte ITEM_POWER_LENS
	.2byte ITEM_POWER_BAND
	.2byte ITEM_POWER_ANKLET
	pokemartlistend

PacifidlogTown_House6_Text_PowerItems:
	.string "We brought Power Items from Alola. They\n"
	.string "use them to climb the Battle Tree.\p"
	.string "Ever since the Battle Frontier was\n"
	.string "opened in Hoenn I thought we could use\l"
	.string "them in here as well.$"

