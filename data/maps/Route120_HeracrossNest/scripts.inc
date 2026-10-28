Route120_HeracrossNest_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route120_HeracrossNest_OnResume
	.byte 0

Route120_HeracrossNest_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_TryRemoveKecleon
    call_if_set FLAG_TEMP_5, Route119_RemoveHeracross1
    call_if_set FLAG_TEMP_6, Route119_RemoveHeracross2
    call_if_set FLAG_TEMP_7, Route119_RemoveHeracross3
    call_if_set FLAG_TEMP_8, Route119_RemoveHeracross4
	end

Route119_RemoveHeracross1::
    removeobject LOCALID_ROUTE119_HERACROSS_1
    return

Route119_RemoveHeracross2::
    removeobject LOCALID_ROUTE119_HERACROSS_2
    return

Route119_RemoveHeracross3::
    removeobject LOCALID_ROUTE119_HERACROSS_3
    return

Route119_RemoveHeracross4::
    removeobject LOCALID_ROUTE119_HERACROSS_4
    return
