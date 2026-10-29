EverGrandeCity_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_OnWarp
    map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_OnFrame
    .byte 0

EverGrandeCity_OnTransition:
    call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
    setflag FLAG_TEMP_5
    setflag FLAG_TEMP_6
    setflag FLAG_TEMP_7
    setflag FLAG_TEMP_8
    setflag FLAG_TEMP_9
    setflag FLAG_TEMP_A
    setflag FLAG_TEMP_B
    setflag FLAG_TEMP_C
    setflag FLAG_TEMP_D
    goto_if_ne VAR_EVER_GRANDE_ARENA_OPPONENT, 0, EverGrandeCity_OnTransition_ArenaChallenge
    goto_if_unset FLAG_DEFEATED_METEOR_FALLS_STEVEN, EverGrandeCity_OnTransition_End
    clearflag FLAG_TEMP_5
    call_if_eq VAR_EVER_GRANDE_CITY_STATE, 1, EverGrandeCity_EventScript_ArenaWallaceAtRed

EverGrandeCity_OnTransition_End:
    end

EverGrandeCity_OnWarp:
    map_script_2 VAR_EVER_GRANDE_ARENA_OPPONENT, 1, EverGrandeCity_EventScript_ArenaFacePlayer
    map_script_2 VAR_EVER_GRANDE_ARENA_OPPONENT, 2, EverGrandeCity_EventScript_ArenaFacePlayer
    map_script_2 VAR_EVER_GRANDE_ARENA_OPPONENT, 3, EverGrandeCity_EventScript_ArenaFacePlayer
    map_script_2 VAR_EVER_GRANDE_ARENA_OPPONENT, 4, EverGrandeCity_EventScript_ArenaFacePlayer
    map_script_2 VAR_EVER_GRANDE_ARENA_OPPONENT, 5, EverGrandeCity_EventScript_ArenaFacePlayer
    map_script_2 VAR_EVER_GRANDE_ARENA_OPPONENT, 6, EverGrandeCity_EventScript_ArenaFacePlayer
    .2byte 0

EverGrandeCity_OnFrame:
    map_script_2 VAR_EVER_GRANDE_ARENA_OPPONENT, 1, EverGrandeCity_EventScript_ArenaOpponentPreview
    map_script_2 VAR_EVER_GRANDE_ARENA_OPPONENT, 2, EverGrandeCity_EventScript_ArenaOpponentPreview
    map_script_2 VAR_EVER_GRANDE_ARENA_OPPONENT, 3, EverGrandeCity_EventScript_ArenaOpponentPreview
    map_script_2 VAR_EVER_GRANDE_ARENA_OPPONENT, 4, EverGrandeCity_EventScript_ArenaOpponentPreview
    map_script_2 VAR_EVER_GRANDE_ARENA_OPPONENT, 5, EverGrandeCity_EventScript_ArenaOpponentPreview
    map_script_2 VAR_EVER_GRANDE_ARENA_OPPONENT, 6, EverGrandeCity_EventScript_ArenaOpponentPreview
    .2byte 0

EverGrandeCity_EventScript_ArenaFacePlayer::
    turnobject LOCALID_PLAYER, DIR_EAST
    end

EverGrandeCity_OnTransition_ArenaChallenge:
    call_if_eq VAR_EVER_GRANDE_ARENA_OPPONENT, 1, EverGrandeCity_EventScript_ArenaShowMay
    call_if_eq VAR_EVER_GRANDE_ARENA_OPPONENT, 2, EverGrandeCity_EventScript_ArenaShowBrendan
    call_if_eq VAR_EVER_GRANDE_ARENA_OPPONENT, 3, EverGrandeCity_EventScript_ArenaShowWally
    call_if_eq VAR_EVER_GRANDE_ARENA_OPPONENT, 4, EverGrandeCity_EventScript_ArenaShowMagma
    call_if_eq VAR_EVER_GRANDE_ARENA_OPPONENT, 5, EverGrandeCity_EventScript_ArenaShowWallace
    call_if_eq VAR_EVER_GRANDE_ARENA_OPPONENT, 6, EverGrandeCity_EventScript_ArenaShowAqua
    end

EverGrandeCity_EventScript_ArenaShowMay::
    clearflag FLAG_TEMP_6
    return

EverGrandeCity_EventScript_ArenaShowBrendan::
    clearflag FLAG_TEMP_7
    return

EverGrandeCity_EventScript_ArenaShowWally::
    clearflag FLAG_TEMP_8
    return

EverGrandeCity_EventScript_ArenaShowMagma::
    clearflag FLAG_TEMP_9
    clearflag FLAG_TEMP_A
    return

EverGrandeCity_EventScript_ArenaShowWallace::
    clearflag FLAG_TEMP_B
    return

EverGrandeCity_EventScript_ArenaShowAqua::
    clearflag FLAG_TEMP_C
    clearflag FLAG_TEMP_D
    return

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
    waitfieldeffect FLDEFF_EXCLAMATION_MARK_ICON
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
	call EverGrandeCity_EventScript_ArenaOpponentMenu
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

EverGrandeCity_Movement_ArenaApproachLeft:
    walk_left
	walk_up
    walk_up
    step_end

EverGrandeCity_Movement_ArenaApproachRight:
    walk_up
    walk_up
    step_end

EverGrandeCity_Movement_ArenaWallaceToRedLeft:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
	face_down
    step_end

EverGrandeCity_Movement_ArenaPlayerToRedLeft:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
	face_up
    step_end

EverGrandeCity_Movement_ArenaWallaceToRedRight:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
	face_down
    step_end

EverGrandeCity_Movement_ArenaPlayerToRedRight:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    face_up
    step_end

EverGrandeCity_Movement_ArenaWallaceClearPath:
    walk_right
    step_end

EverGrandeCity_Movement_ArenaPlayerDescend:
    walk_down
    walk_down
	walk_right
    step_end

EverGrandeCity_EventScript_ArenaWallaceAfter::
    lock
    faceplayer
    msgbox EverGrandeCity_Text_ArenaWallaceAfter, MSGBOX_DEFAULT
    closemessage
    call EverGrandeCity_EventScript_ArenaOpponentMenu
    applymovement LOCALID_EVER_GRANDE_CITY_ARENA_WALLACE, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    setobjectmovementtype LOCALID_EVER_GRANDE_CITY_ARENA_WALLACE, MOVEMENT_TYPE_FACE_DOWN
    release
    end

EverGrandeCity_EventScript_ArenaOpponentMenu::
    checkplayergender
    goto_if_eq VAR_RESULT, MALE, EverGrandeCity_EventScript_ArenaMenuMay
    goto EverGrandeCity_EventScript_ArenaMenuBrendan

EverGrandeCity_EventScript_ArenaMenuMay::
    dynmultichoice 1, 1, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, EverGrandeCity_Text_ArenaOptionMay, EverGrandeCity_Text_ArenaOptionWally, EverGrandeCity_Text_ArenaOptionTabithaCourtney, EverGrandeCity_Text_ArenaOptionWallace, EverGrandeCity_Text_ArenaOptionMattShelly, EverGrandeCity_Text_ArenaOptionCancel
    goto EverGrandeCity_EventScript_ArenaMenuResult

EverGrandeCity_EventScript_ArenaMenuBrendan::
    dynmultichoice 1, 1, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, EverGrandeCity_Text_ArenaOptionBrendan, EverGrandeCity_Text_ArenaOptionWally, EverGrandeCity_Text_ArenaOptionTabithaCourtney, EverGrandeCity_Text_ArenaOptionWallace, EverGrandeCity_Text_ArenaOptionMattShelly, EverGrandeCity_Text_ArenaOptionCancel
    goto EverGrandeCity_EventScript_ArenaMenuResult

EverGrandeCity_EventScript_ArenaMenuResult::
    switch VAR_RESULT
    case 0, EverGrandeCity_EventScript_ArenaSelectRival
    case 1, EverGrandeCity_EventScript_ArenaSelectWally
    case 2, EverGrandeCity_EventScript_ArenaSelectTabithaCourtney
    case 3, EverGrandeCity_EventScript_ArenaSelectWallace
    case 4, EverGrandeCity_EventScript_ArenaSelectMattShelly
    case 5, EverGrandeCity_EventScript_ArenaCancel
    case MULTI_B_PRESSED, EverGrandeCity_EventScript_ArenaCancel
    return

EverGrandeCity_EventScript_ArenaSelectRival::
    checkplayergender
    goto_if_eq VAR_RESULT, MALE, EverGrandeCity_EventScript_ArenaChooseMay
    goto EverGrandeCity_EventScript_ArenaChooseBrendan

EverGrandeCity_EventScript_ArenaChooseMay::
    setvar VAR_EVER_GRANDE_ARENA_OPPONENT, 1
    goto EverGrandeCity_EventScript_ArenaStartChallenge

EverGrandeCity_EventScript_ArenaChooseBrendan::
    setvar VAR_EVER_GRANDE_ARENA_OPPONENT, 2
    goto EverGrandeCity_EventScript_ArenaStartChallenge

EverGrandeCity_EventScript_ArenaSelectWally::
    setvar VAR_EVER_GRANDE_ARENA_OPPONENT, 3
    goto EverGrandeCity_EventScript_ArenaStartChallenge

EverGrandeCity_EventScript_ArenaSelectTabithaCourtney::
    setvar VAR_EVER_GRANDE_ARENA_OPPONENT, 4
    goto EverGrandeCity_EventScript_ArenaStartChallenge

EverGrandeCity_EventScript_ArenaSelectWallace::
    setvar VAR_EVER_GRANDE_ARENA_OPPONENT, 5
    goto EverGrandeCity_EventScript_ArenaStartChallenge

EverGrandeCity_EventScript_ArenaSelectMattShelly::
    setvar VAR_EVER_GRANDE_ARENA_OPPONENT, 6
    goto EverGrandeCity_EventScript_ArenaStartChallenge

EverGrandeCity_EventScript_ArenaStartChallenge::
    closemessage
    warpsilent MAP_EVER_GRANDE_CITY, 32, 54
    waitstate
    end

EverGrandeCity_EventScript_ArenaNotReady::
    msgbox EverGrandeCity_Text_ArenaNotReady, MSGBOX_DEFAULT
    closemessage
    return

EverGrandeCity_EventScript_ArenaCancel::
    msgbox EverGrandeCity_Text_ArenaCancel, MSGBOX_DEFAULT
    closemessage
    return

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

EverGrandeCity_EventScript_Scientist::
	msgbox EverGrandeCity_Text_Scientist, MSGBOX_NPC
	end

EverGrandeCity_EventScript_ArenaWallace::
    goto_if_eq VAR_EVER_GRANDE_CITY_STATE, 1, EverGrandeCity_EventScript_ArenaWallaceAfter

    msgbox EverGrandeCity_Text_ArenaWallaceBefore, MSGBOX_NPC
    end

@----------------------------------------------
@ EVER GRANDE ARENA
@----------------------------------------------

EverGrandeCity_EventScript_ArenaOpponentPreview::
    lockall
    switch VAR_EVER_GRANDE_ARENA_OPPONENT
    case 1, EverGrandeCity_EventScript_ArenaFightMay
    case 2, EverGrandeCity_EventScript_ArenaFightBrendan
    case 3, EverGrandeCity_EventScript_ArenaFightWally
    case 4, EverGrandeCity_EventScript_ArenaFightMagma
    case 5, EverGrandeCity_EventScript_ArenaFightWallace
    case 6, EverGrandeCity_EventScript_ArenaFightAqua
    goto EverGrandeCity_EventScript_ArenaReturn

@----------------------------------------------
@ MAY
@----------------------------------------------

EverGrandeCity_EventScript_ArenaFightMay::
    setvar VAR_LAST_TALKED, LOCALID_EVER_GRANDE_CITY_ARENA_MAY
    msgbox EverGrandeCity_Text_ArenaMayIntro, MSGBOX_DEFAULT
    closemessage
    setvar VAR_EVER_GRANDE_ARENA_OPPONENT, 0
    switch VAR_STARTER_MON
    case 0, EverGrandeCity_EventScript_ArenaMaySnivy
    case 1, EverGrandeCity_EventScript_ArenaMayFennekin
    case 2, EverGrandeCity_EventScript_ArenaMayMudkip
    goto EverGrandeCity_EventScript_ArenaMayMudkip

EverGrandeCity_EventScript_ArenaMaySnivy::
    trainerbattle_no_intro TRAINER_ARENA_MAY_SNIVY, EverGrandeCity_Text_ArenaMayDefeat
    goto EverGrandeCity_EventScript_ArenaBattleWon

EverGrandeCity_EventScript_ArenaMayFennekin::
    trainerbattle_no_intro TRAINER_ARENA_MAY_FENNEKIN, EverGrandeCity_Text_ArenaMayDefeat
    goto EverGrandeCity_EventScript_ArenaBattleWon

EverGrandeCity_EventScript_ArenaMayMudkip::
    trainerbattle_no_intro TRAINER_ARENA_MAY_MUDKIP, EverGrandeCity_Text_ArenaMayDefeat
    goto EverGrandeCity_EventScript_ArenaBattleWon

@----------------------------------------------
@ BRENDAN
@----------------------------------------------

EverGrandeCity_EventScript_ArenaFightBrendan::
    setvar VAR_LAST_TALKED, LOCALID_EVER_GRANDE_CITY_ARENA_BRENDAN
    msgbox EverGrandeCity_Text_ArenaBrendanIntro, MSGBOX_DEFAULT
    closemessage
    setvar VAR_EVER_GRANDE_ARENA_OPPONENT, 0
    switch VAR_STARTER_MON
    case 0, EverGrandeCity_EventScript_ArenaBrendanSnivy
    case 1, EverGrandeCity_EventScript_ArenaBrendanFennekin
    case 2, EverGrandeCity_EventScript_ArenaBrendanMudkip
    goto EverGrandeCity_EventScript_ArenaBrendanMudkip

EverGrandeCity_EventScript_ArenaBrendanSnivy::
    trainerbattle_no_intro TRAINER_ARENA_BRENDAN_SNIVY, EverGrandeCity_Text_ArenaBrendanDefeat
    goto EverGrandeCity_EventScript_ArenaBattleWon

EverGrandeCity_EventScript_ArenaBrendanFennekin::
    trainerbattle_no_intro TRAINER_ARENA_BRENDAN_FENNEKIN, EverGrandeCity_Text_ArenaBrendanDefeat
    goto EverGrandeCity_EventScript_ArenaBattleWon

EverGrandeCity_EventScript_ArenaBrendanMudkip::
    trainerbattle_no_intro TRAINER_ARENA_BRENDAN_MUDKIP, EverGrandeCity_Text_ArenaBrendanDefeat
    goto EverGrandeCity_EventScript_ArenaBattleWon

@----------------------------------------------
@ WALLY
@----------------------------------------------

EverGrandeCity_EventScript_ArenaFightWally::
    setvar VAR_LAST_TALKED, LOCALID_EVER_GRANDE_CITY_ARENA_WALLY
    msgbox EverGrandeCity_Text_ArenaWallyIntro, MSGBOX_DEFAULT
    closemessage
    setvar VAR_EVER_GRANDE_ARENA_OPPONENT, 0
    trainerbattle_no_intro TRAINER_ARENA_WALLY, EverGrandeCity_Text_ArenaWallyDefeat
    goto EverGrandeCity_EventScript_ArenaBattleWon

@----------------------------------------------
@ TEAM MAGMA
@----------------------------------------------

EverGrandeCity_EventScript_ArenaFightMagma::
    setvar VAR_LAST_TALKED, LOCALID_EVER_GRANDE_CITY_ARENA_TABITHA
    msgbox EverGrandeCity_Text_ArenaMagmaIntro, MSGBOX_DEFAULT
    closemessage
    setvar VAR_EVER_GRANDE_ARENA_OPPONENT, 0
    trainerbattle_two_trainers TRAINER_ARENA_TABITHA, EverGrandeCity_Text_ArenaTabithaDefeat, TRAINER_ARENA_COURTNEY, EverGrandeCity_Text_ArenaCourtneyDefeat
    goto EverGrandeCity_EventScript_ArenaBattleWon

@----------------------------------------------
@ WALLACE
@----------------------------------------------

EverGrandeCity_EventScript_ArenaFightWallace::
    setvar VAR_LAST_TALKED, LOCALID_EVER_GRANDE_CITY_ARENA_WALLACE_OPPONENT
    msgbox EverGrandeCity_Text_ArenaWallaceBattleIntro, MSGBOX_DEFAULT
    closemessage
    setvar VAR_EVER_GRANDE_ARENA_OPPONENT, 0
    trainerbattle_no_intro TRAINER_STEVEN, EverGrandeCity_Text_ArenaWallaceDefeat
    goto EverGrandeCity_EventScript_ArenaBattleWon

@----------------------------------------------
@ TEAM AQUA
@----------------------------------------------

EverGrandeCity_EventScript_ArenaFightAqua::
    setvar VAR_LAST_TALKED, LOCALID_EVER_GRANDE_CITY_ARENA_MATT
    msgbox EverGrandeCity_Text_ArenaAquaIntro, MSGBOX_DEFAULT
    closemessage
    setvar VAR_EVER_GRANDE_ARENA_OPPONENT, 0
    trainerbattle_two_trainers TRAINER_ARENA_MATT, EverGrandeCity_Text_ArenaMattDefeat, TRAINER_ARENA_SHELLY, EverGrandeCity_Text_ArenaShellyDefeat
    goto EverGrandeCity_EventScript_ArenaBattleWon

@----------------------------------------------
@ POST BATTLE
@----------------------------------------------

EverGrandeCity_EventScript_ArenaBattleWon::
    msgbox EverGrandeCity_Text_ArenaBattleWon, MSGBOX_DEFAULT
    goto EverGrandeCity_EventScript_ArenaReturn

EverGrandeCity_EventScript_ArenaReturn::
    closemessage
    setvar VAR_EVER_GRANDE_ARENA_OPPONENT, 0
    warpsilent MAP_EVER_GRANDE_CITY, 39, 53
    waitstate
    end

@----------------------------------------------
@ DIALOGUES
@----------------------------------------------

EverGrandeCity_Text_ArenaMayIntro:
    .string "MAY: I've been looking forward\n"
    .string "to battling you again!$"

EverGrandeCity_Text_ArenaMayDefeat:
    .string "Wow! You've really improved!$"

EverGrandeCity_Text_ArenaBrendanIntro:
    .string "BRENDAN: Let's see how much\n"
    .string "we've both learned!$"

EverGrandeCity_Text_ArenaBrendanDefeat:
    .string "I still have a lot to learn!$"

EverGrandeCity_Text_ArenaWallyIntro:
    .string "WALLY: I won't hold back\n"
    .string "this time!$"

EverGrandeCity_Text_ArenaWallyDefeat:
    .string "You're still one step ahead!$"

EverGrandeCity_Text_ArenaMagmaIntro:
    .string "TABITHA: This time, you'll\n"
    .string "face both of us together!$"

EverGrandeCity_Text_ArenaTabithaDefeat:
    .string "Impossible!$"

EverGrandeCity_Text_ArenaCourtneyDefeat:
    .string "I...lost?$"

EverGrandeCity_Text_ArenaWallaceBattleIntro:
    .string "WALLACE: Show me how much\n"
    .string "stronger you've become!$"

EverGrandeCity_Text_ArenaWallaceDefeat:
    .string "Magnificent! You've surpassed\n"
    .string "my expectations!$"

EverGrandeCity_Text_ArenaAquaIntro:
    .string "MATT: Let's see if you can\n"
    .string "handle the two of us!$"

EverGrandeCity_Text_ArenaMattDefeat:
    .string "You're too strong!$"

EverGrandeCity_Text_ArenaShellyDefeat:
    .string "We need to train harder!$"

EverGrandeCity_Text_ArenaBattleWon:
    .string "You won the challenge!$"

EverGrandeCity_Text_ArenaOptionMay:
    .string "MAY$"

EverGrandeCity_Text_ArenaOptionBrendan:
    .string "BRENDAN$"

EverGrandeCity_Text_ArenaOptionWally:
    .string "WALLY$"

EverGrandeCity_Text_ArenaOptionTabithaCourtney:
    .string "MAGMA$"

EverGrandeCity_Text_ArenaOptionWallace:
    .string "WALLACE$"

EverGrandeCity_Text_ArenaOptionMattShelly:
    .string "AQUA$"

EverGrandeCity_Text_ArenaOptionCancel:
    .string "CANCEL$"

EverGrandeCity_Text_ArenaNotReady:
    .string "WALLACE: That challenge isn't\n"
    .string "available just yet.$"

EverGrandeCity_Text_ArenaCancel:
    .string "WALLACE: Not ready to battle yet?\p"
    .string "Take your time! The ARENA will\n"
    .string "be here whenever you're ready.$"

EverGrandeCity_Text_ArenaWallaceBefore:
    .string "WALLACE: Come down the steps.\n"
    .string "There's something I want to show you.$"

EverGrandeCity_Text_ArenaWallaceAfter:
    .string "WALLACE: Welcome to the\n"
    .string "EVER GRANDE ARENA!\p"
    .string "Which Trainer would you\n"
    .string "like to challenge?$"

EverGrandeCity_Text_ArenaIntro:
    .string "WALLACE: {PLAYER}{KUN}!\p"
    .string "I was hoping you'd return to\n"
    .string "EVER GRANDE CITY.\p"
    .string "After our battle in METEOR FALLS,\n"
    .string "I knew you were ready for more.\p"
    .string "A new challenge awaits here:\n"
    .string "the EVER GRANDE ARENA!\p"
    .string "Come with me. I'll explain\n"
    .string "how the challenges work.$"

EverGrandeCity_Text_ArenaAtRed:
    .string "WALLACE: Here we are!\p"
    .string "Welcome to the EVER GRANDE\n"
    .string "ARENA!\p"
    .string "I'll be organizing five special\n"
    .string "challenges for you.\p"
    .string "You may choose who you'd\n"
    .string "like to face first!$"

EverGrandeCity_Text_Scientist:
	.string "A trainer called DANTE beat my\n"
	.string "Klinklang with his own Klinklang.\p"
	.string "WE WANT REVENGE!!!$"

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

EverGrandeCity_Text_EnteringVictoryRoad:
	.string "ENTERING VICTORY ROAD$"

EverGrandeCity_Text_EnteringPokemonLeague:
	.string "ENTERING POKéMON LEAGUE\n"
	.string "CENTER GATE$"

EverGrandeCity_Text_CitySign:
	.string "EVER GRANDE CITY\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and POKéMON.”$"
