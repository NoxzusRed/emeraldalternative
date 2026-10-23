Route115_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route115_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route115_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route115_OnFrame
	.byte 0

Route115_OnLoad:
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST, AbnormalWeather_EventScript_PlaceTilesRoute115West
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST, AbnormalWeather_EventScript_PlaceTilesRoute115East
	end

Route115_OnTransition:
    call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
    call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST, AbnormalWeather_StartGroudonWeather
    call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST, AbnormalWeather_StartGroudonWeather
    call Route115_EventScript_UpdateRioluQuestObjects
    call Route115_EventScript_PrepareRioluQuestCamera
    end

Route115_OnFrame:
    map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
    .2byte 0

Route115_EventScript_Woman::
	msgbox Route115_Text_NeverKnowWhenCavePokemonWillAppear, MSGBOX_NPC
	end

Route115_EventScript_RouteSignRustboro::
	msgbox Route115_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route115_EventScript_MeteorFallsSign::
	msgbox Route115_Text_MeteorFallsSign, MSGBOX_SIGN
	end

Route115_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY_1, Route115_Text_TimothyIntro, Route115_Text_TimothyDefeat, Route115_EventScript_RegisterTimothy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route115_EventScript_RematchTimothy
	msgbox Route115_Text_TimothyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterTimothy::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_TimothyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TIMOTHY_1
	release
	end

Route115_EventScript_RematchTimothy::
	trainerbattle_rematch TRAINER_TIMOTHY_1, Route115_Text_TimothyRematchIntro, Route115_Text_TimothyRematchDefeat
	msgbox Route115_Text_TimothyPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Koichi::
	trainerbattle_single TRAINER_KOICHI, Route115_Text_KoichiIntro, Route115_Text_KoichiDefeat
	msgbox Route115_Text_KoichiPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Nob::
	trainerbattle_single TRAINER_NOB_1, Route115_Text_NobIntro, Route115_Text_NobDefeat, Route115_EventScript_RegisterNob
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route115_EventScript_RematchNob
	msgbox Route115_Text_NobPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterNob::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_NobRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NOB_1
	release
	end

Route115_EventScript_RematchNob::
	trainerbattle_rematch TRAINER_NOB_1, Route115_Text_NobRematchIntro, Route115_Text_NobRematchDefeat
	msgbox Route115_Text_NobPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Cyndy::
	trainerbattle_single TRAINER_CYNDY_1, Route115_Text_CyndyIntro, Route115_Text_CyndyDefeat, Route115_EventScript_RegisterCyndy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route115_EventScript_RematchCyndy
	msgbox Route115_Text_CyndyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterCyndy::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_CyndyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CYNDY_1
	release
	end

Route115_EventScript_RematchCyndy::
	trainerbattle_rematch TRAINER_CYNDY_1, Route115_Text_CyndyRematchIntro, Route115_Text_CyndyRematchDefeat
	msgbox Route115_Text_CyndyPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Hector::
	trainerbattle_single TRAINER_HECTOR, Route115_Text_HectorIntro, Route115_Text_HectorDefeat
	msgbox Route115_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Kyra::
	trainerbattle_single TRAINER_KYRA, Route115_Text_KyraIntro, Route115_Text_KyraDefeat
	msgbox Route115_Text_KyraPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Jaiden::
	trainerbattle_single TRAINER_JAIDEN, Route115_Text_JaidenIntro, Route115_Text_JaidenDefeat
	msgbox Route115_Text_JaidenPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Alix::
	trainerbattle_single TRAINER_ALIX, Route115_Text_AlixIntro, Route115_Text_AlixDefeat
	msgbox Route115_Text_AlixPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Helene::
	trainerbattle_single TRAINER_HELENE, Route115_Text_HeleneIntro, Route115_Text_HeleneDefeat
	msgbox Route115_Text_HelenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Marlene::
	trainerbattle_single TRAINER_MARLENE, Route115_Text_MarleneIntro, Route115_Text_MarleneDefeat
	msgbox Route115_Text_MarlenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_UpdateRioluQuestObjects::
    goto_if_eq VAR_RIOLU_QUEST_STATE, 1, Route115_EventScript_ShowRioluQuestObjects
	setflag FLAG_HIDE_ROUTE115_AQUA
    clearflag FLAG_HIDE_ROUTE115_GREEN_NPC
    return

Route115_EventScript_ShowRioluQuestObjects::
    clearflag FLAG_HIDE_ROUTE115_AQUA
    setflag FLAG_HIDE_ROUTE115_GREEN_NPC
    return


Route115_EventScript_RioluQuestAquaBattle::
    lock
    faceplayer
    applymovement LOCALID_ROUTE115_RIOLU_QUEST_AQUA_1, Common_Movement_ExclamationMark
    waitmovement 0
    msgbox Route115_Text_RioluQuestAquaIntro, MSGBOX_DEFAULT
    applymovement LOCALID_ROUTE115_RIOLU_QUEST_LUCARIO, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 0
    playmoncry SPECIES_LUCARIO, CRY_MODE_NORMAL
    waitmoncry
    trainerbattle_no_intro TRAINER_GRUNT_ROUTE115_RIOLU_QUEST, Route115_Text_RioluQuestAquaDefeat
    msgbox Route115_Text_RioluQuestAquaRetreat, MSGBOX_DEFAULT
    delay 20
    special StorePlayerCoordsInVars
    call Route115_EventScript_SelectAqua1Retreat
    call Route115_EventScript_SelectAqua2Retreat
    applymovement LOCALID_ROUTE115_RIOLU_QUEST_SHARPEDO_1, Route115_Movement_Sharpedo1Retreat
    applymovement LOCALID_ROUTE115_RIOLU_QUEST_SHARPEDO_2, Route115_Movement_Sharpedo2Retreat
    waitmovement LOCALID_ROUTE115_RIOLU_QUEST_AQUA_1
    waitmovement LOCALID_ROUTE115_RIOLU_QUEST_AQUA_2
    waitmovement LOCALID_ROUTE115_RIOLU_QUEST_SHARPEDO_1
    waitmovement LOCALID_ROUTE115_RIOLU_QUEST_SHARPEDO_2
    msgbox Route115_Text_RioluQuestLucarioSafe, MSGBOX_DEFAULT
	playmoncry SPECIES_LUCARIO, CRY_MODE_NORMAL
    waitmoncry
	applymovement LOCALID_ROUTE115_RIOLU_QUEST_LUCARIO, Route115_Movement_LucarioRetreat
	waitmovement LOCALID_ROUTE115_RIOLU_QUEST_LUCARIO
    setflag FLAG_HIDE_ROUTE115_AQUA
    removeobject LOCALID_ROUTE115_RIOLU_QUEST_AQUA_1
    removeobject LOCALID_ROUTE115_RIOLU_QUEST_AQUA_2
    removeobject LOCALID_ROUTE115_RIOLU_QUEST_LUCARIO
    removeobject LOCALID_ROUTE115_RIOLU_QUEST_SHARPEDO_1
    removeobject LOCALID_ROUTE115_RIOLU_QUEST_SHARPEDO_2
    setvar VAR_RIOLU_QUEST_STATE, 2
	release
    end


Route115_EventScript_RioluQuestAqua2::
    msgbox Route115_Text_RioluQuestAqua2, MSGBOX_NPC
	applymovement LOCALID_ROUTE115_RIOLU_QUEST_AQUA_2, Common_Movement_FaceRight
    end

Route115_EventScript_RioluQuestLucario::
    lock
    playmoncry SPECIES_LUCARIO, CRY_MODE_NORMAL
    msgbox Route115_Text_RioluQuestLucario, MSGBOX_DEFAULT
	waitmoncry
    release
    end

Route115_EventScript_Sharpedo::
	lock
	playmoncry SPECIES_SHARPEDO, CRY_MODE_NORMAL
    msgbox Route115_Text_Sharpedo, MSGBOX_DEFAULT
	waitmoncry
	release
    end

Route115_EventScript_SelectAqua1Retreat::
    goto_if_ne VAR_0x8004, 11, Route115_EventScript_Aqua1RetreatDefault
    goto_if_ne VAR_0x8005, 68, Route115_EventScript_Aqua1RetreatDefault
    applymovement LOCALID_ROUTE115_RIOLU_QUEST_AQUA_1, Route115_Movement_Aqua1Retreat_Below
    return

Route115_EventScript_Aqua1RetreatDefault::
    applymovement LOCALID_ROUTE115_RIOLU_QUEST_AQUA_1, Route115_Movement_Aqua1Retreat
    return

Route115_EventScript_SelectAqua2Retreat::
    goto_if_ne VAR_0x8004, 10, Route115_EventScript_Aqua2RetreatDefault
    goto_if_ne VAR_0x8005, 67, Route115_EventScript_Aqua2RetreatDefault
    applymovement LOCALID_ROUTE115_RIOLU_QUEST_AQUA_2, Route115_Movement_Aqua2Retreat_Left
    return

Route115_EventScript_Aqua2RetreatDefault::
    applymovement LOCALID_ROUTE115_RIOLU_QUEST_AQUA_2, Route115_Movement_Aqua2Retreat
    return

Route115_Movement_Aqua1Retreat:
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
	walk_left
	walk_left
    walk_down
	walk_down
    step_end

Route115_Movement_Aqua2Retreat:
    walk_left
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
	walk_down
	walk_left
	walk_down
	walk_down
    step_end

Route115_Movement_Aqua1Retreat_Below:
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_left
    walk_down
    walk_down
    step_end

Route115_Movement_Aqua2Retreat_Left:
	walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_left
    walk_left
    walk_down
    walk_down
    step_end

Route115_Movement_LucarioRetreat:
    walk_right
    walk_right
    walk_right
    walk_down
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
	walk_right
	walk_right
	walk_right
    step_end

Route115_Movement_Sharpedo1Retreat:
    walk_faster_down
    walk_faster_down
    walk_faster_down
    walk_faster_down
    walk_faster_down
	walk_faster_down
    step_end

Route115_Movement_Sharpedo2Retreat:
    walk_faster_down
    walk_faster_down
    walk_faster_down
    walk_faster_down
    walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
    step_end

@ ==================================================
@ RIOLU QUEST - CAMERA CUTSCENE
@ ==================================================

Route115_EventScript_PrepareRioluQuestCamera::
    goto_if_ne VAR_RIOLU_QUEST_STATE, 1, Route115_EventScript_PrepareRioluQuestCameraEnd
    goto_if_ne VAR_RIOLU_QUEST_CAMERA_STATE, 0, Route115_EventScript_PrepareRioluQuestCameraEnd
    setvar VAR_RIOLU_QUEST_CAMERA_STATE, 1

Route115_EventScript_PrepareRioluQuestCameraEnd::
    return

Route115_EventScript_RioluQuestCamera::
    lockall
    setvar VAR_RIOLU_QUEST_CAMERA_STATE, 2
    delay 20
    special SpawnCameraObject
    applymovement LOCALID_CAMERA, Route115_Movement_CameraToGrunts
    waitmovement 0
    delay 60
    applymovement LOCALID_CAMERA, Route115_Movement_CameraReturn
    waitmovement 0
    special RemoveCameraObject
    releaseall
    end

Route115_Movement_CameraToGrunts:
    walk_slow_diag_northwest
    walk_slow_diag_northwest
    walk_slow_diag_northwest
    walk_slow_diag_northwest
    walk_slow_diag_northwest
    walk_slow_diag_northwest
    step_end

Route115_Movement_CameraReturn:
    walk_slow_diag_southeast
    walk_slow_diag_southeast
    walk_slow_diag_southeast
    walk_slow_diag_southeast
    walk_slow_diag_southeast
    walk_slow_diag_southeast
    step_end

Route115_Text_RioluQuestAquaIntro:
    .string "TEAM AQUA: Hey! Stay out of our\n"
    .string "business!$"

Route115_Text_RioluQuestAquaDefeat:
    .string "What?! How did I lose?!$"

Route115_Text_RioluQuestAquaRetreat:
    .string "TEAM AQUA: This isn't worth it!\n"
    .string "We're getting out of here!$"

Route115_Text_RioluQuestAqua2:
    .string "TEAM AQUA: Back off!\n"
    .string "You're not stopping us!$"

Route115_Text_RioluQuestLucario:
    .string "Luca!$"

Route115_Text_RioluQuestLucarioSafe:
    .string "LUCARIO seems relieved!\p"
    .string "It runs back toward RUSTBORO!$"

Route115_Text_NeverKnowWhenCavePokemonWillAppear:
	.string "Exploring a cave isn't like walking\n"
	.string "on a road.\p"
	.string "You never know when wild POKéMON will\n"
	.string "appear. It's full of suspense.$"

Route115_Text_RouteSignRustboro:
	.string "ROUTE 115\n"
	.string "{DOWN_ARROW} RUSTBORO CITY$"

Route115_Text_MeteorFallsSign:
	.string "METEOR FALLS\n"
	.string "FALLARBOR TOWN THROUGH HERE$"

Route115_Text_Sharpedo:
    .string "Shriiiink-grrr!$"
