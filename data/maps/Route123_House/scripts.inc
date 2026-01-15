Route123_House_MapScripts::
	.byte 0

Route123_House_EventScript_Dusclops::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EVIOLITE, Route123_House_EventScript_ReceivedEviolite
	msgbox Route123_House_Text_Dusclops, MSGBOX_DEFAULT
	giveitem ITEM_EVIOLITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EVIOLITE
	release
	end

Route123_House_EventScript_ReceivedEviolite::
	msgbox Route123_House_Text_Dusclops, MSGBOX_DEFAULT
	release
	end

Route123_House_Text_Dusclops:
	.string "Duuuusss...$"
