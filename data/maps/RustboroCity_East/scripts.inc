RustboroCity_East_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_East_OnTransition
    .byte 0

RustboroCity_East_OnTransition:
    goto_if_ge VAR_RIOLU_QUEST_STATE, 2, RustboroCity_East_EventScript_ShowQuestLucario
    setflag FLAG_HIDE_RUSTBORO_EAST_LUCARIO
    end

RustboroCity_East_EventScript_ShowQuestLucario::
    clearflag FLAG_HIDE_RUSTBORO_EAST_LUCARIO
    end

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

RustboroCity_East_EventScript_Wooper::
	playmoncry SPECIES_WOOPER, CRY_MODE_NORMAL
	msgbox RustboroCity_East_Text_Paaah, MSGBOX_SIGN
	end

RustboroCity_East_EventScript_Jumpluff::
	playmoncry SPECIES_JUMPLUFF, CRY_MODE_NORMAL
	msgbox RustboroCity_East_Text_PluffPluff, MSGBOX_SIGN
	end

RustboroCity_East_EventScript_Lucario::
    faceplayer
	playmoncry SPECIES_LUCARIO, CRY_MODE_NORMAL
	msgbox RustboroCity_East_Text_Lucario, MSGBOX_DEFAULT
	end

RustboroCity_East_EventScript_RioluQuestNPC::
    lock
    faceplayer
    goto_if_eq VAR_RIOLU_QUEST_STATE, 0, RustboroCity_East_EventScript_RioluQuestStart
    goto_if_eq VAR_RIOLU_QUEST_STATE, 1, RustboroCity_East_EventScript_RioluQuestWaiting
    goto_if_eq VAR_RIOLU_QUEST_STATE, 2, RustboroCity_East_EventScript_RioluQuestReward
    goto RustboroCity_East_EventScript_RioluQuestDone
    end

RustboroCity_East_EventScript_RioluQuestStart::
    msgbox RustboroCity_East_Text_RioluQuestStart, MSGBOX_DEFAULT
    setvar VAR_RIOLU_QUEST_STATE, 1
    release
    end

RustboroCity_East_EventScript_RioluQuestWaiting::
    msgbox RustboroCity_East_Text_RioluQuestWaiting, MSGBOX_DEFAULT
    release
    end

RustboroCity_East_EventScript_RioluQuestReward::
    getpartysize
    goto_if_eq VAR_RESULT, PARTY_SIZE, RustboroCity_East_EventScript_RioluQuestPartyFull
    msgbox RustboroCity_East_Text_RioluQuestThanks, MSGBOX_DEFAULT
    playfanfare MUS_OBTAIN_ITEM
    message RustboroCity_East_Text_RioluQuestReceivedEgg
    waitfanfare
    giveegg SPECIES_RIOLU
    setvar VAR_RIOLU_QUEST_STATE, 3
    release
    end

RustboroCity_East_EventScript_RioluQuestPartyFull::
    msgbox RustboroCity_East_Text_RioluQuestPartyFull, MSGBOX_DEFAULT
    release
    end

RustboroCity_East_EventScript_RioluQuestDone::
    msgbox RustboroCity_East_Text_RioluQuestDone, MSGBOX_DEFAULT
    release
    end

RustboroCity_East_Text_RioluQuestStart:
    .string "Lucario went on guard duty, but he\n"
    .string "hasn't returned yet.\p"
    .string "He was supposed to watch over Routes\n"
    .string "104, 115 and 116.\p"
    .string "Could you look for him?$"

RustboroCity_East_Text_RioluQuestWaiting:
    .string "Have you seen Lucario?\p"
    .string "He was supposed to watch over Routes\n"
    .string "104, 115 and 116.$"

RustboroCity_East_Text_RioluQuestThanks:
    .string "LUCARIO made it back safely!\n"
    .string "Thank you for helping it!\p"
    .string "Please accept this as a reward!$"

RustboroCity_East_Text_RioluQuestReceivedEgg:
    .string "{PLAYER} received an EGG!$"

RustboroCity_East_Text_RioluQuestPartyFull:
    .string "Your party is full.\n"
    .string "Make room for the EGG first.$"

RustboroCity_East_Text_RioluQuestDone:
    .string "Thank you again!\p"
    .string "Please raise that Pokemon with care.$"

RustboroCity_East_Text_Lucario:
	.string "Rrrio!$"

RustboroCity_East_Text_Paaah:
	.string "Paaah!$"

RustboroCity_East_Text_PluffPluff:
	.string "Pluff-Pluff!$"

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
