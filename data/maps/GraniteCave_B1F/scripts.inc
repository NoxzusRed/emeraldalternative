GraniteCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, GraniteCave_B1F_SetHoleWarp
	.byte 0

GraniteCave_B1F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_GRANITE_CAVE_B2F
	end

GraniteCave_B1F_EventScript_BugCatcher::
	trainerbattle_single TRAINER_BUG_CATCHER_GRANITE_CAVE_B1F, GraniteCave_B1F_Text_BugCatcherIntro, GraniteCave_B1F_Text_BugCatcherDefeat
	msgbox GraniteCave_B1F_Text_BugCatcherPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCave_B1F_Text_BugCatcherIntro:
	.string "My BUG POKéMON love dark caves!$"

GraniteCave_B1F_Text_BugCatcherDefeat:
	.string "I got caught in my own trap!$"

GraniteCave_B1F_Text_BugCatcherPostBattle:
	.string "I'll catch even stronger BUGS!$"
