Route106_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route106_OnResume
	.byte 0

Route106_OnResume:
    call_if_set FLAG_TEMP_5, Route106_RemovePopplio1
    call_if_set FLAG_TEMP_6, Route106_RemovePopplio2
    call_if_set FLAG_TEMP_7, Route106_RemovePopplio3
    call_if_set FLAG_TEMP_8, Route106_RemoveBrionne
    end

Route106_RemovePopplio1::
    removeobject LOCALID_ROUTE106_POPPLIO_1
    return

Route106_RemovePopplio2::
    removeobject LOCALID_ROUTE106_POPPLIO_2
    return

Route106_RemovePopplio3::
    removeobject LOCALID_ROUTE106_POPPLIO_3
    return

Route106_RemoveBrionne::
    removeobject LOCALID_ROUTE106_BRIONNE
    return

Route106_EventScript_Popplio5::
    lock
    faceplayer
    playmoncry SPECIES_POPPLIO, CRY_MODE_NORMAL
    waitmoncry
    setflag FLAG_TEMP_5
    setwildbattle SPECIES_POPPLIO, 5
    dowildbattle
    release
    end

Route106_EventScript_Popplio7::
    lock
    faceplayer
    playmoncry SPECIES_POPPLIO, CRY_MODE_NORMAL
    waitmoncry
    setflag FLAG_TEMP_6
    setwildbattle SPECIES_POPPLIO, 7
    dowildbattle
    release
    end

Route106_EventScript_Popplio9::
    lock
    faceplayer
    playmoncry SPECIES_POPPLIO, CRY_MODE_NORMAL
    waitmoncry
    setflag FLAG_TEMP_7
    setwildbattle SPECIES_POPPLIO, 9
    dowildbattle
    release
    end

Route106_EventScript_Brionne24::
    lock
    faceplayer
    playmoncry SPECIES_BRIONNE, CRY_MODE_NORMAL
    waitmoncry
    setflag FLAG_TEMP_8
    setwildbattle SPECIES_BRIONNE, 24
    dowildbattle
    release
    end

Route106_EventScript_TrainerTipsSign::
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
	end

Route106_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS, Route106_Text_DouglasIntro, Route106_Text_DouglasDefeated
	msgbox Route106_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Kyla::
	trainerbattle_single TRAINER_KYLA, Route106_Text_KylaIntro, Route106_Text_KylaDefeated
	msgbox Route106_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Elliot::
	trainerbattle_single TRAINER_ELLIOT_1, Route106_Text_ElliotIntro, Route106_Text_ElliotDefeated, Route106_EventScript_ElliotRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route106_EventScript_ElliotRematch
	msgbox Route106_Text_ElliotPostBattle, MSGBOX_DEFAULT
	release
	end

Route106_EventScript_ElliotRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route106_Text_ElliotRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ELLIOT_1
	release
	end

Route106_EventScript_ElliotRematch::
	trainerbattle_rematch TRAINER_ELLIOT_1, Route106_Text_ElliotRematchIntro, Route106_Text_ElliotRematchDefeated
	msgbox Route106_Text_ElliotRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Ned::
	trainerbattle_single TRAINER_NED, Route106_Text_NedIntro, Route106_Text_NedDefeated
	msgbox Route106_Text_NedPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "Advice on catching POKéMON with a ROD:\n"
	.string "Press the A Button if you get a bite.$"

