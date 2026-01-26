FortreeCity_House7_MapScripts::
	.byte 0
	
FortreeCity_House7_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FortreeCity_House7_Clerk
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_House7_Clerk:
	.2byte ITEM_TM90
	.2byte ITEM_TM91
	.2byte ITEM_TM92
	pokemartlistend
