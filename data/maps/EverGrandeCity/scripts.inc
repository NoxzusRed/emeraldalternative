EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition:
    call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
    setflag FLAG_TEMP_5
    goto_if_unset FLAG_DEFEATED_METEOR_FALLS_STEVEN, EverGrandeCity_OnTransition_End
    clearflag FLAG_TEMP_5
    call_if_eq VAR_EVER_GRANDE_CITY_STATE, 1, EverGrandeCity_EventScript_ArenaWallaceAtRed

EverGrandeCity_OnTransition_End:
    end

EverGrandeCity_EventScript_ArenaWallaceAtRed::
    setobjectxyperm LOCALID_EVER_GRANDE_CITY_ARENA_WALLACE, 38, 52
    setobjectmovementtype LOCALID_EVER_GRANDE_CITY_ARENA_WALLACE, MOVEMENT_TYPE_FACE_DOWN
    return

EverGrandeCity_EventScript_ArenaIntro::
    goto_if_unset FLAG_DEFEATED_METEOR_FALLS_STEVEN, EverGrandeCity_EventScript_ArenaIntroEnd
    lockall
    getplayerxy VAR_TEMP_2, VAR_TEMP_3
    playse SE_PIN
    applymovement LOCALID_EVER_GRANDE_CITY_ARENA_WALLACE, Common_Movement_ExclamationMark
    waitmovement 0
    delay 12
    call_if_eq VAR_TEMP_2, 31, EverGrandeCity_EventScript_ArenaApproachLeft
    call_if_eq VAR_TEMP_2, 32, EverGrandeCity_EventScript_ArenaApproachRight
    applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
    applymovement LOCALID_EVER_GRANDE_CITY_ARENA_WALLACE, Common_Movement_FacePlayer
    waitmovement 0
    msgbox EverGrandeCity_Text_ArenaIntro, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_EVER_GRANDE_CITY_ARENA_WALLACE, EverGrandeCity_Movement_ArenaWallaceClearPath
    waitmovement 0
    applymovement LOCALID_PLAYER, EverGrandeCity_Movement_ArenaPlayerDescend
    waitmovement 0
    call_if_eq VAR_TEMP_2, 31, EverGrandeCity_EventScript_ArenaWalkToRedLeft
    call_if_eq VAR_TEMP_2, 32, EverGrandeCity_EventScript_ArenaWalkToRedRight
    applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    msgbox EverGrandeCity_Text_ArenaAtRed, MSGBOX_DEFAULT
    closemessage
    setvar VAR_EVER_GRANDE_CITY_STATE, 1
    applymovement LOCALID_EVER_GRANDE_CITY_ARENA_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setobjectmovementtype LOCALID_EVER_GRANDE_CITY_ARENA_WALLACE, MOVEMENT_TYPE_FACE_DOWN
    releaseall
    end

EverGrandeCity_EventScript_ArenaIntroEnd::
    end

EverGrandeCity_EventScript_ArenaApproachLeft::
    applymovement LOCALID_EVER_GRANDE_CITY_ARENA_WALLACE, EverGrandeCity_Movement_ArenaApproachLeft
    waitmovement 0
    return

EverGrandeCity_EventScript_ArenaApproachRight::
    applymovement LOCALID_EVER_GRANDE_CITY_ARENA_WALLACE, EverGrandeCity_Movement_ArenaApproachRight
    waitmovement 0
    return

EverGrandeCity_EventScript_ArenaWalkToRedLeft::
    applymovement LOCALID_EVER_GRANDE_CITY_ARENA_WALLACE, EverGrandeCity_Movement_ArenaWallaceToRedLeft
    applymovement LOCALID_PLAYER, EverGrandeCity_Movement_ArenaPlayerToRedLeft
    waitmovement 0
    return

EverGrandeCity_EventScript_ArenaWalkToRedRight::
    applymovement LOCALID_EVER_GRANDE_CITY_ARENA_WALLACE, EverGrandeCity_Movement_ArenaWallaceToRedRight
    applymovement LOCALID_PLAYER, EverGrandeCity_Movement_ArenaPlayerToRedRight
    waitmovement 0
    return

EverGrandeCity_Movement_ArenaWallaceToRedLeft:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

EverGrandeCity_Movement_ArenaPlayerToRedLeft:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

EverGrandeCity_Movement_ArenaWallaceToRedRight:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

EverGrandeCity_Movement_ArenaPlayerToRedRight:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

EverGrandeCity_Movement_ArenaWallaceClearPath:
    walk_right
    step_end

EverGrandeCity_Movement_ArenaPlayerDescend:
    walk_down
    walk_down
    step_end

EverGrandeCity_Movement_ArenaApproachLeft:
    walk_up
    walk_left
    walk_up
    step_end

EverGrandeCity_Movement_ArenaApproachRight:
    walk_up
    walk_up
    step_end

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

EverGrandeCity_EventScript_ArenaWallace::
    goto_if_eq VAR_EVER_GRANDE_CITY_STATE, 1, EverGrandeCity_EventScript_ArenaWallaceAfter

    msgbox EverGrandeCity_Text_ArenaWallaceBefore, MSGBOX_NPC
    end

EverGrandeCity_EventScript_ArenaWallaceAfter::
    msgbox EverGrandeCity_Text_ArenaWallaceAfter, MSGBOX_NPC
    end

EverGrandeCity_Text_ArenaWallaceBefore:
    .string "WALLACE: Come down the steps.\n"
    .string "There's something I want to show you.$"

EverGrandeCity_Text_ArenaWallaceAfter:
    .string "WALLACE: The EVER GRANDE ARENA\n"
    .string "is no ordinary challenge.\p"
    .string "Only the strongest Trainers\n"
    .string "can claim victory here!$"

EverGrandeCity_Text_ArenaIntro:
    .string "WALLACE: {PLAYER}{KUN}!\p"
    .string "I was hoping you'd return to\n"
    .string "EVER GRANDE CITY.\p"
    .string "After our battle in METEOR FALLS,\n"
    .string "I knew you were ready for more.\p"
    .string "A new challenge awaits here:\n"
    .string "the EVER GRANDE ARENA!\p"
    .string "Come with me. I'll show you\n"
    .string "who runs the challenges.$"

EverGrandeCity_Text_ArenaAtRed:
    .string "WALLACE: Here we are!\p"
    .string "This Trainer coordinates the\n"
    .string "EVER GRANDE ARENA.\p"
    .string "Five exceptional opponents\n"
    .string "await challengers here.\p"
    .string "You'll be able to choose\n"
    .string "who to challenge.$"

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

