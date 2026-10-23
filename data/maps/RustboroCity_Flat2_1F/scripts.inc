RustboroCity_Flat2_1F_MapScripts::
	.byte 0

RustboroCity_Flat2_1F_EventScript_OldWoman::
	msgbox RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere, MSGBOX_NPC
	end

RustboroCity_Flat2_1F_EventScript_Chingling::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHINGLING, CRY_MODE_NORMAL
	msgbox RustboroCity_Flat2_1F_Text_Chingling, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere:
	.string "DEVON CORPORATION's workers live in\n"
	.string "this building.$"

RustboroCity_Flat2_1F_Text_Chingling:
	.string "Chiiiiing!$"

