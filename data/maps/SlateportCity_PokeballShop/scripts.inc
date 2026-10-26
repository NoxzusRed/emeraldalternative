SlateportCity_PokeballShop_MapScripts::
	.byte 0

SlateportCity_PokeballShop_EventScript_Glalie::
	lock
	playmoncry SPECIES_GLALIE, CRY_MODE_NORMAL
	msgbox SlateportCity_PokeballShop_Text_Glalie, MSGBOX_SIGN
	waitmoncry
	release
	end

SlateportCity_PokeballShop_EventScript_Clerk::
    lock
    faceplayer
    message gText_HowMayIServeYou
    waitmessage
    pokemart SlateportCity_PokeballShop_Pokemart
    msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
    release
    end

    .align 2
SlateportCity_PokeballShop_Pokemart:
    .2byte ITEM_POKE_BALL
    .2byte ITEM_GREAT_BALL
    .2byte ITEM_ULTRA_BALL
    .2byte ITEM_NET_BALL
    .2byte ITEM_NEST_BALL
    .2byte ITEM_DIVE_BALL
    .2byte ITEM_TIMER_BALL
    .2byte ITEM_REPEAT_BALL
    .2byte ITEM_LUXURY_BALL
    pokemartlistend

SlateportCity_PokeballShop_Text_Glalie:
	.string "Shhh-krrr...!$"
