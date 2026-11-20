GraniteCave_B2F_MapScripts::
	.byte 0

GraniteCave_B2F_EventScript_Hiker::
	trainerbattle_single TRAINER_MARCELO, GraniteCave_B2F_Text_HikerIntro, GraniteCave_B2F_Text_HikerDefeat
	msgbox GraniteCave_B2F_Text_HikerPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCave_B2F_Text_HikerIntro:
	.string "My POKéMON are tough as stone!$"

GraniteCave_B2F_Text_HikerDefeat:
	.string "You shattered my confidence!$"

GraniteCave_B2F_Text_HikerPostBattle:
	.string "Back to training in the depths!$"
