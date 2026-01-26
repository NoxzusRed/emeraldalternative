OldaleRuins_Underwater_MapScripts::
	.byte 0

OldaleRuins_Underwater_EventScript_Relicanth::
	playmoncry SPECIES_RELICANTH, CRY_MODE_NORMAL
	msgbox OldaleRuins_Underwater_Text_Relicanth, MSGBOX_DEFAULT
	release
	end

OldaleRuins_Underwater_Text_Relicanth:
	.string "Grooorgh...$"
