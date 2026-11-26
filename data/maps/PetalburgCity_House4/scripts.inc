PetalburgCity_House4_MapScripts::
	.byte 0

PetalburgCity_House4_EventScript_Breeder::
	lock
	faceplayer
	msgbox PetalburgCity_House4_Text_Breeder, MSGBOX_DEFAULT
	release
	end

PetalburgCity_House4_EventScript_Eevee::
	lock
	faceplayer
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	msgbox PetalburgCity_House4_Text_Eevee, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PetalburgCity_House4_EventScript_Zigzagoon::
	lock
	faceplayer
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox PetalburgCity_House4_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PetalburgCity_House4_Text_Breeder:
	.string "Eevee and Zigzagoon get along so\n"
	.string "well, don't they?\p"
	.string "They spend all day playing together.\n"
	.string "I can hardly keep up with them!$"

PetalburgCity_House4_Text_Eevee:
	.string "Eevui!$"

PetalburgCity_House4_Text_Zigzagoon:
	.string "Zig-zag!$"
