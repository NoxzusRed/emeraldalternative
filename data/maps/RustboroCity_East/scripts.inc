RustboroCity_East_MapScripts::
	.byte 0

RustboroCity_East_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, RustboroCity_East_EventScript_ReceivedSootheBell
	msgbox RustboroCity_East_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_1_TO_49, RustboroCity_East_EventScript_GiveSootheBell
	release
	end

RustboroCity_East_EventScript_GiveSootheBell::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_East_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

RustboroCity_East_EventScript_ReceivedSootheBell::
	msgbox RustboroCity_East_Text_PokemonPlay, MSGBOX_DEFAULT
	release
	end

RustboroCity_East_EventScript_AbilityShopSign::
	msgbox RustboroCity_East_Text_AbilityShop, MSGBOX_SIGN
	end

RustboroCity_East_EventScript_Psychic::
	msgbox RustboroCity_East_Text_NewAbilityShop, MSGBOX_NPC
	end

RustboroCity_East_Text_AbilityShop:
	.string "ABILITY SHOP$"

RustboroCity_East_Text_NewAbilityShop:
	.string "I came to check out the new Ability\n"
	.string "Shop.$"

RustboroCity_East_Text_PokemonPlay:
	.string "I bring my Pokémon out to play every\n"
	.string "day.$"

RustboroCity_East_Text_ShowMePokemonThatLoveYou:
	.string "I love seeing POKéMON that love\n"
	.string "their TRAINERS.\p"
	.string "POKéMON are very sensitive to\n"
	.string "the feelings of their TRAINERS.\p"
	.string "If you treat your POKéMON with love\n"
	.string "and care, they'll love you back.\p"
	.string "When your POKéMON grow to love you,\n"
	.string "please come show me.$"

RustboroCity_East_Text_PokemonAdoresYou:
	.string "Your POKéMON really adores you.\p"
	.string "For you, a most compassionate\n"
	.string "TRAINER, a gift from the FAN CLUB!$"
