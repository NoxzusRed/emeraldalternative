Underwater_Route124_MapScripts::
	.byte 0

Underwater_Route124_EventScript_Skrelp::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_RED_SHARD, Underwater_Route124_EventScript_ReceivedRedShard
	msgbox Underwater_Route124_Text_Skrelp, MSGBOX_DEFAULT
	giveitem ITEM_RED_SHARD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_RED_SHARD
	release
	end

Underwater_Route124_EventScript_ReceivedRedShard::
	msgbox Underwater_Route124_Text_Skrelp, MSGBOX_DEFAULT
	release
	end

Underwater_Route124_EventScript_Chinchou::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_YELLOW_SHARD, Underwater_Route124_EventScript_ReceivedYellowShard
	msgbox Underwater_Route124_Text_Chinchou, MSGBOX_DEFAULT
	giveitem ITEM_YELLOW_SHARD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_YELLOW_SHARD
	release
	end

Underwater_Route124_EventScript_ReceivedYellowShard::
	msgbox Underwater_Route124_Text_Chinchou, MSGBOX_DEFAULT
	release
	end

Underwater_Route124_Text_Skrelp:
	.string "Kelp... kelp!$"

Underwater_Route124_Text_Chinchou:
	.string "Chin-chou!$"
