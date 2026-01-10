FallarborTown_MintShop_MapScripts::
	.byte 0

FallarborTown_MintShop_EventScript_MintGirl::
	msgbox FallarborTown_MintShop_Text_SuspiciousMint, MSGBOX_NPC
	end

FallarborTown_MintShop_EventScript_Granddaughter::
	msgbox FallarborTown_MintShop_Text_Grandma, MSGBOX_NPC
	end
FallarborTown_MintShop_EventScript_MintClerk::
	message gText_PlayerWhatCanIDoForYou
	waitmessage
	pokemart FallarborTown_MintShop_Pokemart_Mints
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_MintShop_Pokemart_Mints:
	.2byte ITEM_LONELY_MINT
	.2byte ITEM_ADAMANT_MINT
	.2byte ITEM_NAUGHTY_MINT
	.2byte ITEM_BRAVE_MINT
	.2byte ITEM_BOLD_MINT
	.2byte ITEM_IMPISH_MINT
	.2byte ITEM_LAX_MINT
	.2byte ITEM_RELAXED_MINT
	.2byte ITEM_MODEST_MINT
	.2byte ITEM_MILD_MINT
	.2byte ITEM_RASH_MINT
	.2byte ITEM_QUIET_MINT
	.2byte ITEM_CALM_MINT
	.2byte ITEM_GENTLE_MINT
	.2byte ITEM_CAREFUL_MINT
	.2byte ITEM_SASSY_MINT
	.2byte ITEM_TIMID_MINT
	.2byte ITEM_HASTY_MINT
	.2byte ITEM_JOLLY_MINT
	.2byte ITEM_NAIVE_MINT
	.2byte ITEM_SERIOUS_MINT
	pokemartlistend

FallarborTown_MintShop_Text_SuspiciousMint:
	.string "I know it looks suspicious in here, but\n"
	.string "it's really just mint.$"

FallarborTown_MintShop_Text_Grandma:
	.string "I grew up in Mauville but it was getting\n"
	.string "too crowded.\p"
	.string "So I decided to move to Fallarbor with\n"
	.string "my sister and work with grandma.$"
