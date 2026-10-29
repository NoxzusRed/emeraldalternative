EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_EventScript_VictoryRoadSign::
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CitySign::
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign::
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

EverGrandeCity_EventScript_Mienshao::
	playmoncry SPECIES_MIENSHAO, CRY_MODE_NORMAL
	msgbox EverGrandeCity_Text_Mienshao, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_Flygon::
	playmoncry SPECIES_FLYGON, CRY_MODE_NORMAL
	msgbox EverGrandeCity_Text_Flygon, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_Zebstrika::
	playmoncry SPECIES_ZEBSTRIKA, CRY_MODE_NORMAL
	msgbox EverGrandeCity_Text_Zebstrika, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_Rapidash::
	playmoncry SPECIES_RAPIDASH, CRY_MODE_NORMAL
	msgbox EverGrandeCity_Text_Rapidash, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_Klinklang::
	playmoncry SPECIES_KLINKLANG, CRY_MODE_NORMAL
	msgbox EverGrandeCity_Text_Klinklang, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CoolTrainerF::
	msgbox EverGrandeCity_Text_CoolTrainerF, MSGBOX_NPC
	end

EverGrandeCity_EventScript_Expert::
	msgbox EverGrandeCity_Text_Expert, MSGBOX_NPC
	end

EverGrandeCity_EventScript_BlackBelt::
	msgbox EverGrandeCity_Text_BlackBelt, MSGBOX_NPC
	end

EverGrandeCity_EventScript_Scientist::
	msgbox EverGrandeCity_Text_Scientist, MSGBOX_NPC
	end

EverGrandeCity_Text_Scientist:
	.string "A trainer called DANTE beat my\n"
	.string "Klinklang with his own Klinklang.\p"
	.string "WE WANT REVENGE!!!$"

EverGrandeCity_Text_BlackBelt:
	.string "I'm not here to challenge the Pokémon\n"
	.string "League, nor to defeat the Victory Road.\p"
	.string "I came to fight in the Ever Grande\n"
	.string "Arena. Powerful trainers come here to\l"
	.string "test their skills.$"

EverGrandeCity_Text_Expert:
	.string "I caught Flygon when I was young. He\n"
	.string "was just a Trapinch at the time.\p"
	.string "Now, we've decided to challenge the\n"
	.string "League. I know we are not enough, but\l"
	.string "we wanted to have our last adventure\l"
	.string "together...$"

EverGrandeCity_Text_CoolTrainerF:
	.string "I'm going to let them run around and\n"
	.string "play for a while before going inside.$"

EverGrandeCity_Text_Klinklang:
	.string "Ggggr-t-t-t-t...!$"

EverGrandeCity_Text_Rapidash:
	.string "Klak-klak-hiiiigh!$"

EverGrandeCity_Text_Zebstrika:
	.string "Vzt-brrrrzt!$"

EverGrandeCity_Text_Flygon:
	.string "Kryyy-rrrr...$"

EverGrandeCity_Text_Mienshao:
	.string "Fwww-tsuu!$"

EverGrandeCity_Text_EnteringVictoryRoad:
	.string "ENTERING VICTORY ROAD$"

EverGrandeCity_Text_EnteringPokemonLeague:
	.string "ENTERING POKéMON LEAGUE\n"
	.string "CENTER GATE$"

EverGrandeCity_Text_CitySign:
	.string "EVER GRANDE CITY\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and POKéMON.”$"

