PetalburgCity_House3_MapScripts::
	.byte 0

PetalburgCity_House3_EventScript_Lady::
	lock
	faceplayer
	msgbox PetalburgCity_House3_Text_Lady, MSGBOX_DEFAULT
	release
	end

PetalburgCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox PetalburgCity_House3_Text_Man, MSGBOX_DEFAULT
	release
	end

PetalburgCity_House3_Text_Lady:
	.string "I bought my daughter an Eevee. She\n"
	.string "wanted to become a trainer so badly,\l"
	.string "but she spends most of her time in the\l"
	.string "city.$"

PetalburgCity_House3_Text_Man:
	.string "Trainers start so young nowadays. Just\n"
	.string "look at all those youngsters.$"