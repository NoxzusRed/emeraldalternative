Underwater_Route126_MapScripts::
	.byte 0

Underwater_Route126_EventScript_Relicanth::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_GREEN_SHARD, Underwater_Route126_EventScript_ReceivedGreenShard
	msgbox Underwater_Route126_Text_Relicanth, MSGBOX_DEFAULT
	giveitem ITEM_GREEN_SHARD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_GREEN_SHARD
	release
	end

Underwater_Route126_EventScript_ReceivedGreenShard::
	msgbox Underwater_Route126_Text_Relicanth, MSGBOX_DEFAULT
	release
	end

Underwater_Route126_EventScript_Clamperl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BLUE_SHARD, Underwater_Route126_EventScript_ReceivedBlueShard
	msgbox Underwater_Route126_Text_Clamperl, MSGBOX_DEFAULT
	giveitem ITEM_BLUE_SHARD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_BLUE_SHARD
	release
	end

Underwater_Route126_EventScript_ReceivedBlueShard::
	msgbox Underwater_Route126_Text_Clamperl, MSGBOX_DEFAULT
	release
	end

Underwater_Route126_Text_Relicanth:
	.string "Grooorgh...$"

Underwater_Route126_Text_Clamperl:
	.string "Clac!$"

