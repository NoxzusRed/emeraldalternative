MauvilleCity_TMShop_MapScripts::
	.byte 0

MauvilleCity_TMShop_EventScript_RichBoy::
	msgbox MauvilleCity_TMShop_Text_MauvilleIsGrowing, MSGBOX_NPC
	end

MauvilleCity_TMShop_EventScript_Woman::
	msgbox MauvilleCity_TMShop_Text_SwarmSolosis, MSGBOX_NPC
	end

MauvilleCity_TMShop_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MauvilleCity_TMShop_Clerk
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_TMShop_Clerk:
	.2byte ITEM_TM58
	.2byte ITEM_TM59
	.2byte ITEM_TM65
	.2byte ITEM_TM71
	.2byte ITEM_TM73
	.2byte ITEM_TM80
	pokemartlistend

MauvilleCity_TMShop_Text_MauvilleIsGrowing:
	.string "Mauville has been growing a lot lately.\p"
	.string "I heard they have plans to renovate\n"
	.string "the entire city.$"

MauvilleCity_TMShop_Text_SwarmSolosis:
	.string "I got swarmed by a group of Solosis on\n"
	.string "my way from Slateport.\p"
	.string "So I came here to get a new TM so I can\n"
	.string "defend myself when I go back.$"
