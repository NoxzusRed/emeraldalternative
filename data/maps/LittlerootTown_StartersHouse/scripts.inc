LittlerootTown_StartersHouse_MapScripts::
	.byte 0

LittlerootTown_StartersHouse_EventScript_SprigatitoTrader::
	lock
	faceplayer
	goto_if_set FLAG_SPRIGATITO_TRADE_COMPLETED, LittlerootTown_StartersHouse_EventScript_SprigatitoTradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SPRIGATITO
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox LittlerootTown_StartersHouse_Text_WillingToTradeSprigatito, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_StartersHouse_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LittlerootTown_StartersHouse_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, LittlerootTown_StartersHouse_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox LittlerootTown_StartersHouse_Text_BeatFennekin, MSGBOX_DEFAULT
	setflag FLAG_SPRIGATITO_TRADE_COMPLETED
	release
	end

LittlerootTown_StartersHouse_EventScript_FennekinTrader::
	lock
	faceplayer
	goto_if_set FLAG_FENNEKIN_TRADE_COMPLETED, LittlerootTown_StartersHouse_EventScript_FennekinTradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_FENNEKIN
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox LittlerootTown_StartersHouse_Text_WillingToTradeFennekin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_StartersHouse_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LittlerootTown_StartersHouse_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, LittlerootTown_StartersHouse_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox LittlerootTown_StartersHouse_Text_BeatMudkip, MSGBOX_DEFAULT
	setflag FLAG_FENNEKIN_TRADE_COMPLETED
	release
	end

LittlerootTown_StartersHouse_EventScript_MudkipTrader::
	lock
	faceplayer
	goto_if_set FLAG_MUDKIP_TRADE_COMPLETED, LittlerootTown_StartersHouse_EventScript_MudkipTradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_MUDKIP
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox LittlerootTown_StartersHouse_Text_WillingToTradeMudkip, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_StartersHouse_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LittlerootTown_StartersHouse_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, LittlerootTown_StartersHouse_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox LittlerootTown_StartersHouse_Text_BeatSprigatito, MSGBOX_DEFAULT
	setflag FLAG_MUDKIP_TRADE_COMPLETED
	release
	end

LittlerootTown_StartersHouse_EventScript_DeclineTrade::
	msgbox LittlerootTown_StartersHouse_Text_ItsOkay, MSGBOX_DEFAULT
	release
	end

LittlerootTown_StartersHouse_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox LittlerootTown_StartersHouse_Text_NeedMon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_StartersHouse_EventScript_SprigatitoTradeCompleted::
	msgbox LittlerootTown_StartersHouse_Text_BeatFennekin, MSGBOX_DEFAULT
	release
	end

LittlerootTown_StartersHouse_EventScript_FennekinTradeCompleted::
	msgbox LittlerootTown_StartersHouse_Text_BeatMudkip, MSGBOX_DEFAULT
	release
	end

LittlerootTown_StartersHouse_EventScript_MudkipTradeCompleted::
	msgbox LittlerootTown_StartersHouse_Text_BeatSprigatito, MSGBOX_DEFAULT
	release
	end

LittlerootTown_StartersHouse_Text_WillingToTradeSprigatito:
	.string "I like {STR_VAR_2} but I can't beat\n"
	.string "Fennekin.\p"
	.string "If you like {STR_VAR_2} as well I can\n"
	.string "trade it for a {STR_VAR_1}.$"

LittlerootTown_StartersHouse_Text_BeatFennekin:
	.string "Thank you! Now I can beat Fennekin!$"

LittlerootTown_StartersHouse_Text_WillingToTradeFennekin:
	.string "I like {STR_VAR_2} but I can't beat\n"
	.string "Mudkip.\p"
	.string "If you like {STR_VAR_2} as well I can\n"
	.string "trade it for a {STR_VAR_1}.$"

LittlerootTown_StartersHouse_Text_BeatMudkip:
	.string "Thank you! Now I can beat Mudkip!$"

LittlerootTown_StartersHouse_Text_WillingToTradeMudkip:
	.string "I like {STR_VAR_2} but I can't beat\n"
	.string "Sprigatito.\p"
	.string "If you like {STR_VAR_2} as well I can\n"
	.string "trade it for a {STR_VAR_1}.$"

LittlerootTown_StartersHouse_Text_BeatSprigatito:
	.string "Thank you! Now I can beat Sprigatito!$"

LittlerootTown_StartersHouse_Text_NeedMon:
	.string "No, no, no! I need a {STR_VAR_1}!$"

LittlerootTown_StartersHouse_Text_ItsOkay:
	.string "It's okay. I'll just keep losing...$"
