LittlerootTown_StartersHouse_MapScripts::
    .byte 0

@ Offer one Egg for each starter that the player did not choose.
@ Keep the old trade flag numbers for existing save file progress.

LittlerootTown_StartersHouse_EventScript_SnivyEggGift::
    lock
    faceplayer
    goto_if_unset FLAG_SYS_POKEMON_GET, LittlerootTown_StartersHouse_EventScript_NoStarter
    goto_if_eq VAR_STARTER_MON, 0, LittlerootTown_StartersHouse_EventScript_AlreadyChoseThisStarter
    goto_if_set FLAG_RECEIVED_SNIVY_EGG, LittlerootTown_StartersHouse_EventScript_AlreadyReceivedEgg
    msgbox LittlerootTown_StartersHouse_Text_OfferSnivyEgg, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, LittlerootTown_StartersHouse_EventScript_DeclineEgg
    getpartysize
    goto_if_eq VAR_RESULT, PARTY_SIZE, LittlerootTown_StartersHouse_EventScript_PartyFull
    giveegg SPECIES_SNIVY
    goto_if_ne VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_StartersHouse_EventScript_PartyFull
    setflag FLAG_RECEIVED_SNIVY_EGG
    goto LittlerootTown_StartersHouse_EventScript_ReceivedEgg

LittlerootTown_StartersHouse_EventScript_FennekinEggGift::
    lock
    faceplayer
    goto_if_unset FLAG_SYS_POKEMON_GET, LittlerootTown_StartersHouse_EventScript_NoStarter
    goto_if_eq VAR_STARTER_MON, 1, LittlerootTown_StartersHouse_EventScript_AlreadyChoseThisStarter
    goto_if_set FLAG_RECEIVED_FENNEKIN_EGG, LittlerootTown_StartersHouse_EventScript_AlreadyReceivedEgg
    msgbox LittlerootTown_StartersHouse_Text_OfferFennekinEgg, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, LittlerootTown_StartersHouse_EventScript_DeclineEgg
    getpartysize
    goto_if_eq VAR_RESULT, PARTY_SIZE, LittlerootTown_StartersHouse_EventScript_PartyFull
    giveegg SPECIES_FENNEKIN
    goto_if_ne VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_StartersHouse_EventScript_PartyFull
    setflag FLAG_RECEIVED_FENNEKIN_EGG
    goto LittlerootTown_StartersHouse_EventScript_ReceivedEgg

LittlerootTown_StartersHouse_EventScript_MudkipEggGift::
    lock
    faceplayer
    goto_if_unset FLAG_SYS_POKEMON_GET, LittlerootTown_StartersHouse_EventScript_NoStarter
    goto_if_eq VAR_STARTER_MON, 2, LittlerootTown_StartersHouse_EventScript_AlreadyChoseThisStarter
    goto_if_set FLAG_RECEIVED_MUDKIP_EGG, LittlerootTown_StartersHouse_EventScript_AlreadyReceivedEgg
    msgbox LittlerootTown_StartersHouse_Text_OfferMudkipEgg, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, LittlerootTown_StartersHouse_EventScript_DeclineEgg
    getpartysize
    goto_if_eq VAR_RESULT, PARTY_SIZE, LittlerootTown_StartersHouse_EventScript_PartyFull
    giveegg SPECIES_MUDKIP
    goto_if_ne VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_StartersHouse_EventScript_PartyFull
    setflag FLAG_RECEIVED_MUDKIP_EGG
    goto LittlerootTown_StartersHouse_EventScript_ReceivedEgg

LittlerootTown_StartersHouse_EventScript_ReceivedEgg::
    playfanfare MUS_OBTAIN_ITEM
    message LittlerootTown_StartersHouse_Text_ReceivedEgg
    waitfanfare
    waitmessage
    waitbuttonpress
    release
    end

LittlerootTown_StartersHouse_EventScript_NoStarter::
    msgbox LittlerootTown_StartersHouse_Text_NoStarter, MSGBOX_DEFAULT
    release
    end

LittlerootTown_StartersHouse_EventScript_AlreadyChoseThisStarter::
    msgbox LittlerootTown_StartersHouse_Text_AlreadyChoseThisStarter, MSGBOX_DEFAULT
    release
    end

LittlerootTown_StartersHouse_EventScript_AlreadyReceivedEgg::
    msgbox LittlerootTown_StartersHouse_Text_AlreadyReceivedEgg, MSGBOX_DEFAULT
    release
    end

LittlerootTown_StartersHouse_EventScript_DeclineEgg::
    msgbox LittlerootTown_StartersHouse_Text_DeclineEgg, MSGBOX_DEFAULT
    release
    end

LittlerootTown_StartersHouse_EventScript_PartyFull::
    msgbox LittlerootTown_StartersHouse_Text_PartyFull, MSGBOX_DEFAULT
    release
    end

LittlerootTown_StartersHouse_Text_OfferSnivyEgg:
    .string "I've got an EGG that will hatch\n"
    .string "into a SNIVY.\p"
    .string "Would you like to raise it?$"

LittlerootTown_StartersHouse_Text_OfferFennekinEgg:
    .string "I've got an EGG that will hatch\n"
    .string "into a FENNEKIN.\p"
    .string "Would you like to raise it?$"

LittlerootTown_StartersHouse_Text_OfferMudkipEgg:
    .string "I've got an EGG that will hatch\n"
    .string "into a MUDKIP.\p"
    .string "Would you like to raise it?$"

LittlerootTown_StartersHouse_Text_ReceivedEgg:
    .string "{PLAYER} received the EGG!$"

LittlerootTown_StartersHouse_Text_NoStarter:
    .string "You haven't chosen your first\n"
    .string "POKéMON yet?\p"
    .string "Come back after meeting\n"
    .string "PROF. BIRCH!$"

LittlerootTown_StartersHouse_Text_AlreadyChoseThisStarter:
    .string "You already chose this POKéMON\n"
    .string "as your first partner!\p"
    .string "I'll save this EGG for another\n"
    .string "TRAINER.$"

LittlerootTown_StartersHouse_Text_AlreadyReceivedEgg:
    .string "I hope the EGG I gave you\n"
    .string "hatches into a strong POKéMON!$"

LittlerootTown_StartersHouse_Text_DeclineEgg:
    .string "No problem! Come back if you\n"
    .string "change your mind.$"

LittlerootTown_StartersHouse_Text_PartyFull:
    .string "Your party is full!\p"
    .string "Come back with room for\n"
    .string "the EGG.$"
