SootopolisCity_OrbShop_MapScripts::
	.byte 0

SootopolisCity_OrbShop_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SootopolisCity_OrbShop_Clerk
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SootopolisCity_OrbShop_Clerk:
	.2byte ITEM_FLAME_ORB
	.2byte ITEM_TOXIC_ORB
	.2byte ITEM_LIFE_ORB
	pokemartlistend
