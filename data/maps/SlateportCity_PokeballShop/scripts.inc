SlateportCity_PokeballShop_MapScripts::
	.byte 0

SlateportCity_PokeballShop_EventScript_Glalie::
	lock
	playmoncry SPECIES_GLALIE, CRY_MODE_NORMAL
	msgbox SlateportCity_PokeballShop_Text_Glalie, MSGBOX_SIGN
	waitmoncry
	release
	end

SlateportCity_PokeballShop_Text_Glalie:
	.string "Shhh-krrr...!$"
