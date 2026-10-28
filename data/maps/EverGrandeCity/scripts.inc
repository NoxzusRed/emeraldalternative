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

