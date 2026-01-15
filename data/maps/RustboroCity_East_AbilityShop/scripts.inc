RustboroCity_East_AbilityShop_MapScripts::
	.byte 0

RustboroCity_East_AbilityShop_EventScript_CoolTrainer::
	msgbox RustboroCity_East_AbilityShop_Text_Kalos, MSGBOX_NPC
	end

RustboroCity_East_AbilityShop_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart RustboroCity_East_AbilityShop_Clerk
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
RustboroCity_East_AbilityShop_Clerk:
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_ABILITY_PATCH
	pokemartlistend

RustboroCity_East_AbilityShop_Text_Kalos:
	.string "Did you know they import the capsules\n"
	.string "from Kalos?\p"
	.string "I was in Slateport while they were\n"
	.string "unloading the cargo from the ships.\p"
	.string "That's how I learnt about the shop!$"
