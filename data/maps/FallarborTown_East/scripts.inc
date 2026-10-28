FallarborTown_East_MapScripts::
	.byte 0

FallarborTown_East_EventScript_BikeStopSign::
	msgbox FallarborTown_East_Text_BikeStopSign, MSGBOX_SIGN
	end

FallarborTown_East_EventScript_Quilava::
	playmoncry SPECIES_QUILAVA, CRY_MODE_NORMAL
	msgbox FallarborTown_East_Text_Quilava, MSGBOX_SIGN
	end

FallarborTown_East_Text_Quilava:
	.string "Gyaaa-fsssh!$"

FallarborTown_East_Text_BikeStopSign:
	.string "BIKE STOP$"
