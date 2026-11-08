LittlerootTown_StartersHouse_MapScripts::
    .byte 0

@ Offer one Egg for each starter that the player did not choose.
@ Keep the old trade flag numbers for existing save file progress.

LittlerootTown_StartersHouse_EventScript_SnivyEggGift::
    lock
    faceplayer
    goto_if_eq VAR_STARTER_MON, 0, LittlerootTown_StartersHouse_EventScript_SnivyAlreadyChoseThisStarter
    goto_if_set FLAG_RECEIVED_SNIVY_EGG, LittlerootTown_StartersHouse_EventScript_SnivyAlreadyReceivedEgg
    msgbox LittlerootTown_StartersHouse_Text_OfferSnivyEgg, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, LittlerootTown_StartersHouse_EventScript_SnivyDeclineEgg
    getpartysize
    goto_if_eq VAR_RESULT, PARTY_SIZE, LittlerootTown_StartersHouse_EventScript_SnivyPartyFull
    giveegg SPECIES_SNIVY
    goto_if_ne VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_StartersHouse_EventScript_SnivyPartyFull
    setflag FLAG_RECEIVED_SNIVY_EGG
    goto LittlerootTown_StartersHouse_EventScript_ReceivedEgg

LittlerootTown_StartersHouse_EventScript_FennekinEggGift::
    lock
    faceplayer
    goto_if_eq VAR_STARTER_MON, 1, LittlerootTown_StartersHouse_EventScript_FennekinAlreadyChoseThisStarter
    goto_if_set FLAG_RECEIVED_FENNEKIN_EGG, LittlerootTown_StartersHouse_EventScript_FennekinAlreadyReceivedEgg
    msgbox LittlerootTown_StartersHouse_Text_OfferFennekinEgg, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, LittlerootTown_StartersHouse_EventScript_FennekinDeclineEgg
    getpartysize
    goto_if_eq VAR_RESULT, PARTY_SIZE, LittlerootTown_StartersHouse_EventScript_FennekinPartyFull
    giveegg SPECIES_FENNEKIN
    goto_if_ne VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_StartersHouse_EventScript_FennekinPartyFull
    setflag FLAG_RECEIVED_FENNEKIN_EGG
    goto LittlerootTown_StartersHouse_EventScript_ReceivedEgg

LittlerootTown_StartersHouse_EventScript_MudkipEggGift::
    lock
    faceplayer
    goto_if_eq VAR_STARTER_MON, 2, LittlerootTown_StartersHouse_EventScript_MudkipAlreadyChoseThisStarter
    goto_if_set FLAG_RECEIVED_MUDKIP_EGG, LittlerootTown_StartersHouse_EventScript_MudkipAlreadyReceivedEgg
    msgbox LittlerootTown_StartersHouse_Text_OfferMudkipEgg, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, LittlerootTown_StartersHouse_EventScript_MudkipDeclineEgg
    getpartysize
    goto_if_eq VAR_RESULT, PARTY_SIZE, LittlerootTown_StartersHouse_EventScript_MudkipPartyFull
    giveegg SPECIES_MUDKIP
    goto_if_ne VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_StartersHouse_EventScript_MudkipPartyFull
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

LittlerootTown_StartersHouse_EventScript_SnivyAlreadyChoseThisStarter::
    msgbox LittlerootTown_StartersHouse_Text_SnivyAlreadyChoseThisStarter, MSGBOX_DEFAULT
    release
    end

LittlerootTown_StartersHouse_EventScript_SnivyAlreadyReceivedEgg::
    msgbox LittlerootTown_StartersHouse_Text_SnivyAlreadyReceivedEgg, MSGBOX_DEFAULT
    release
    end

LittlerootTown_StartersHouse_EventScript_SnivyDeclineEgg::
    msgbox LittlerootTown_StartersHouse_Text_SnivyDeclineEgg, MSGBOX_DEFAULT
    release
    end

LittlerootTown_StartersHouse_EventScript_SnivyPartyFull::
    msgbox LittlerootTown_StartersHouse_Text_SnivyPartyFull, MSGBOX_DEFAULT
    release
    end

LittlerootTown_StartersHouse_EventScript_FennekinAlreadyChoseThisStarter::
    msgbox LittlerootTown_StartersHouse_Text_FennekinAlreadyChoseThisStarter, MSGBOX_DEFAULT
    release
    end

LittlerootTown_StartersHouse_EventScript_FennekinAlreadyReceivedEgg::
    msgbox LittlerootTown_StartersHouse_Text_FennekinAlreadyReceivedEgg, MSGBOX_DEFAULT
    release
    end

LittlerootTown_StartersHouse_EventScript_FennekinDeclineEgg::
    msgbox LittlerootTown_StartersHouse_Text_FennekinDeclineEgg, MSGBOX_DEFAULT
    release
    end

LittlerootTown_StartersHouse_EventScript_FennekinPartyFull::
    msgbox LittlerootTown_StartersHouse_Text_FennekinPartyFull, MSGBOX_DEFAULT
    release
    end

LittlerootTown_StartersHouse_EventScript_MudkipAlreadyChoseThisStarter::
    msgbox LittlerootTown_StartersHouse_Text_MudkipAlreadyChoseThisStarter, MSGBOX_DEFAULT
    release
    end

LittlerootTown_StartersHouse_EventScript_MudkipAlreadyReceivedEgg::
    msgbox LittlerootTown_StartersHouse_Text_MudkipAlreadyReceivedEgg, MSGBOX_DEFAULT
    release
    end

LittlerootTown_StartersHouse_EventScript_MudkipDeclineEgg::
    msgbox LittlerootTown_StartersHouse_Text_MudkipDeclineEgg, MSGBOX_DEFAULT
    release
    end

LittlerootTown_StartersHouse_EventScript_MudkipPartyFull::
    msgbox LittlerootTown_StartersHouse_Text_MudkipPartyFull, MSGBOX_DEFAULT
    release
    end

LittlerootTown_StartersHouse_Text_OfferSnivyEgg:
    .string "SNIVY are such graceful POKéMON!"
    .string "I've cared for this EGG myself.\p"
    .string "It deserves a thoughtful TRAINER.\n"
    .string "Would you like to raise it?$"

LittlerootTown_StartersHouse_Text_OfferFennekinEgg:
    .string "Hey, look! This EGG is so warm!\p"
    .string "There's a FENNEKIN inside,\n"
    .string "just waiting to meet someone!\p"
    .string "Wanna take it on an adventure?$"

LittlerootTown_StartersHouse_Text_OfferMudkipEgg:
    .string "A little MUDKIP is waiting\n"
    .string "inside this EGG.\p"
    .string "It needs a kind TRAINER to\n"
    .string "help it grow. Will you take it?$"

LittlerootTown_StartersHouse_Text_ReceivedEgg:
    .string "{PLAYER} received the EGG!$"

LittlerootTown_StartersHouse_Text_SnivyAlreadyChoseThisStarter:
    .string "You already chose SNIVY?\n"
    .string "What a lovely first partner!\p"
    .string "I'll save this EGG for someone\n"
    .string "who hasn't found theirs yet.$"

LittlerootTown_StartersHouse_Text_FennekinAlreadyChoseThisStarter:
    .string "You picked FENNEKIN already?\n"
    .string "No way! Great choice!\p"
    .string "I'll keep this EGG for another\n"
    .string "lucky new TRAINER.$"

LittlerootTown_StartersHouse_Text_MudkipAlreadyChoseThisStarter:
    .string "You already have a MUDKIP?\n"
    .string "Then you're in good hands!\p"
    .string "I'll find another caring\n"
    .string "TRAINER for this EGG.$"

LittlerootTown_StartersHouse_Text_SnivyAlreadyReceivedEgg:
    .string "How is your SNIVY EGG doing?\n"
    .string "A little patience goes a\n"
    .string "long way, you know.$"

LittlerootTown_StartersHouse_Text_FennekinAlreadyReceivedEgg:
    .string "Did your FENNEKIN hatch yet?\n"
    .string "I bet it's super cute!$"

LittlerootTown_StartersHouse_Text_MudkipAlreadyReceivedEgg:
    .string "Keep traveling with that EGG.\n"
    .string "It'll hatch when it's ready.$"

LittlerootTown_StartersHouse_Text_SnivyDeclineEgg:
    .string "Of course. A precious EGG\n"
    .string "should never be rushed.\p"
    .string "Come back when you're ready.$"

LittlerootTown_StartersHouse_Text_FennekinDeclineEgg:
    .string "Aw, really? Okay!\n"
    .string "I'll be here if you\n"
    .string "change your mind!$"

LittlerootTown_StartersHouse_Text_MudkipDeclineEgg:
    .string "That's all right. Caring for\n"
    .string "an EGG is a big responsibility.\p"
    .string "Come back whenever you're ready.$"

LittlerootTown_StartersHouse_Text_SnivyPartyFull:
    .string "Your party is already full!\p"
    .string "Please make some room before\n"
    .string "you take this EGG.$"

LittlerootTown_StartersHouse_Text_FennekinPartyFull:
    .string "Whoa! Six POKéMON already?\n"
    .string "Make a little space first!$"

LittlerootTown_StartersHouse_Text_MudkipPartyFull:
    .string "You have six POKéMON with you.\n"
    .string "Please come back with room\n"
    .string "for this EGG.$"
