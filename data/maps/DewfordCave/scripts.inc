DewfordCave_MapScripts::
	.byte 0

DewfordCave_EventScript_BlackBelt::
	trainerbattle_single TRAINER_BLACK_BELT_DEWFORD_CAVE, DewfordCave_Text_BlackBeltIntro, DewfordCave_Text_BlackBeltDefeat
	msgbox DewfordCave_Text_BlackBeltPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordCave_Text_BlackBeltIntro:
	.string "Training in this cave sharpens my\\n"
	.string "focus! Show me your fighting spirit!$"

DewfordCave_Text_BlackBeltDefeat:
	.string "Your strikes broke through my guard!$"

DewfordCave_Text_BlackBeltPostBattle:
	.string "Next time, my stance will be stronger.$"
