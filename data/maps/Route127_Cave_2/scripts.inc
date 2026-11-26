Route127_Cave_2_MapScripts::
	.byte 0

Route127_Cave_2_EventScript_Ranger::
	trainerbattle_single TRAINER_CARLOS, Route127_Cave_2_Text_RangerIntro, Route127_Cave_2_Text_RangerDefeat
	msgbox Route127_Cave_2_Text_RangerAfter, MSGBOX_AUTOCLOSE
	end

Route127_Cave_2_EventScript_AromaLady::
	trainerbattle_single TRAINER_LILIA, Route127_Cave_2_Text_AromaIntro, Route127_Cave_2_Text_AromaDefeat
	msgbox Route127_Cave_2_Text_AromaAfter, MSGBOX_AUTOCLOSE
	end

Route127_Cave_2_EventScript_DragonTamer::
	lock
	faceplayer
	goto_if_defeated TRAINER_ORNSTEIN, Route127_Cave_2_EventScript_Reward
	goto_if_not_defeated TRAINER_CARLOS, Route127_Cave_2_EventScript_NotReady
	goto_if_not_defeated TRAINER_LILIA, Route127_Cave_2_EventScript_NotReady
	trainerbattle_single TRAINER_ORNSTEIN, Route127_Cave_2_Text_DragonIntro, Route127_Cave_2_Text_DragonDefeat, Route127_Cave_2_EventScript_Reward
	goto Route127_Cave_2_EventScript_Reward

Route127_Cave_2_EventScript_NotReady::
	msgbox Route127_Cave_2_Text_NotReady, MSGBOX_DEFAULT
	release
	end

Route127_Cave_2_EventScript_Reward::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HYPER_VOICE, Route127_Cave_2_EventScript_DragonAfter
	msgbox Route127_Cave_2_Text_Reward, MSGBOX_DEFAULT
	giveitem ITEM_TM102
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HYPER_VOICE
	release
	end

Route127_Cave_2_EventScript_DragonAfter::
	msgbox Route127_Cave_2_Text_DragonAfter, MSGBOX_DEFAULT
	release
	end

Route127_Cave_2_Text_RangerIntro:
	.string "Even the quietest cave can echo with\n"
	.string "the sound of a fierce battle!$"

Route127_Cave_2_Text_RangerDefeat:
	.string "What a powerful Trainer!$"

Route127_Cave_2_Text_RangerAfter:
	.string "You did great!$"

Route127_Cave_2_Text_AromaIntro:
	.string "Listen closely to the echoes here.\n"
	.string "Can your POKéMON match mine?$"

Route127_Cave_2_Text_AromaDefeat:
	.string "Your strength resonates!$"

Route127_Cave_2_Text_AromaAfter:
	.string "Such a great smell your Pokémon have!$"

Route127_Cave_2_Text_NotReady:
	.string "You are not worthy.$"

Route127_Cave_2_Text_DragonIntro:
	.string "You've defeated both my companions!\n"
	.string "Now hear the roar of my dragons!$"

Route127_Cave_2_Text_DragonDefeat:
	.string "Even my dragons fell silent!$"

Route127_Cave_2_Text_Reward:
	.string "Your strength deserves a reward.\n"
	.string "Take this TM. It contains HYPER VOICE!$"

Route127_Cave_2_Text_DragonAfter:
	.string "Let your POKéMON's voice echo\n"
	.string "through every battle!$"
