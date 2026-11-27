BattleFrontier_OutsideNorth_MapScripts::
	.byte 0

BattleFrontier_OutsideNorth_EventScript_BlueRedTalk::
	lockall
	msgbox BattleFrontier_OutsideNorth_Text_Blue, MSGBOX_DEFAULT
	msgbox BattleFrontier_OutsideNorth_Text_Red, MSGBOX_DEFAULT
	msgbox BattleFrontier_OutsideNorth_Text_BlueReply, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_OutsideNorth_EventScript_LanceIrisTalk::
	lockall
	msgbox BattleFrontier_OutsideNorth_Text_Iris, MSGBOX_DEFAULT
	msgbox BattleFrontier_OutsideNorth_Text_Lance, MSGBOX_DEFAULT
	msgbox BattleFrontier_OutsideNorth_Text_IrisReply, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_OutsideNorth_EventScript_Diantha::
	msgbox BattleFrontier_OutsideNorth_Text_Diantha, MSGBOX_NPC
	end

BattleFrontier_OutsideNorth_EventScript_Gardevoir::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GARDEVOIR, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideNorth_Text_Gardevoir, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideNorth_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideNorth_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideNorth_EventScript_Alder::
	msgbox BattleFrontier_OutsideNorth_Text_Alder, MSGBOX_NPC
	end

BattleFrontier_OutsideNorth_EventScript_Triathlete::
	msgbox BattleFrontier_OutsideNorth_Text_Triathlete, MSGBOX_NPC
	end

BattleFrontier_OutsideNorth_Text_Blue:
	.string "Blue: So, Red, ready to find out\n"
	.string "who's the strongest this time?\l"
	.string "I hope you haven't gotten rusty!$"

BattleFrontier_OutsideNorth_Text_Red:
	.string "Red: ... ... ...$"

BattleFrontier_OutsideNorth_Text_BlueReply:
	.string "Blue: Heh! Still the same as ever.\n"
	.string "I'll take that as a yes!$"

BattleFrontier_OutsideNorth_Text_Iris:
	.string "Iris: I can't wait! I want to see\n"
	.string "how strong everyone has gotten!\p"
	.string "Right, Lance? Let's show them\n"
	.string "what our Dragon-type Pokemon\l"
	.string "can do!$"

BattleFrontier_OutsideNorth_Text_Lance:
	.string "Lance: A title isn't enough to\n"
	.string "win a battle, Iris.\p"
	.string "A true Champion never stops\n"
	.string "learning from others.$"

BattleFrontier_OutsideNorth_Text_IrisReply:
	.string "Iris: Then let's see what we can\n"
	.string "learn! This is going to be fun!$"

BattleFrontier_OutsideNorth_Text_Diantha:
	.string "A battle is rather like a film.\n"
	.string "No two performances are alike.\p"
	.string "Gardevoir and I have shared so\n"
	.string "many wonderful moments together.\p"
	.string "I'm looking forward to the next\n"
	.string "one, here at the tournament.$"

BattleFrontier_OutsideNorth_Text_Gardevoir:
	.string "Gardevoir: Garde!$"

BattleFrontier_OutsideNorth_Text_Pikachu:
	.string "Pikachu: Pika-pika!$"

BattleFrontier_OutsideNorth_Text_Alder:
	.string "Ha ha! Look at all these young\n"
	.string "Trainers eager to prove\l"
	.string "themselves.\p"
	.string "Winning is a wonderful feeling,\n"
	.string "but it's not everything.\p"
	.string "Cherish your time with your\n"
	.string "Pokemon, wherever you may go.$"

BattleFrontier_OutsideNorth_Text_Triathlete:
	.string "I've trained for races all over\n"
	.string "Hoenn, but look at this place!\p"
	.string "Champions from every region,\n"
	.string "gathered in one spot!\p"
	.string "Now that's a finish line worth\n"
	.string "running toward!$"

BattleFrontier_OutsideNorth_EventScript_Woman5::
	msgbox BattleFrontier_OutsideNorth_Text_Woman5, MSGBOX_NPC
	end

BattleFrontier_OutsideNorth_EventScript_Man1::
	msgbox BattleFrontier_OutsideNorth_Text_Man1, MSGBOX_NPC
	end

BattleFrontier_OutsideNorth_EventScript_SchoolKid::
	msgbox BattleFrontier_OutsideNorth_Text_SchoolKid, MSGBOX_NPC
	end

BattleFrontier_OutsideNorth_EventScript_AromaLady::
	msgbox BattleFrontier_OutsideNorth_Text_AromaLady, MSGBOX_NPC
	end

BattleFrontier_OutsideNorth_EventScript_Lady::
	msgbox BattleFrontier_OutsideNorth_Text_Lady, MSGBOX_NPC
	end

BattleFrontier_OutsideNorth_EventScript_Pokemaniac::
	msgbox BattleFrontier_OutsideNorth_Text_Pokemaniac, MSGBOX_NPC
	end

BattleFrontier_OutsideNorth_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideNorth_Text_PokefanF, MSGBOX_NPC
	end

BattleFrontier_OutsideNorth_EventScript_Grovyle::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GROVYLE, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideNorth_Text_Grovyle, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideNorth_Text_Woman5:
	.string "I came here just to watch the\n"
	.string "tournament.\p"
	.string "Seeing Champions from so many\n"
	.string "regions in one place is amazing!$"

BattleFrontier_OutsideNorth_Text_Man1:
	.string "See how the Champions battle?\n"
	.string "Every move has a purpose.\p"
	.string "You can learn a lot just by\n"
	.string "watching a good match.$"

BattleFrontier_OutsideNorth_Text_SchoolKid:
	.string "I'm taking notes on every battle!\n"
	.string "My teacher will be so impressed!\p"
	.string "Someday, I'll be a Champion too!$"

BattleFrontier_OutsideNorth_Text_AromaLady:
	.string "The flowers here smell wonderful.\n"
	.string "Even my Pokemon seem relaxed.\p"
	.string "A little peace before a big\n"
	.string "battle can do wonders, you know.$"

BattleFrontier_OutsideNorth_Text_Lady:
	.string "Diantha is so elegant, isn't she?\n"
	.string "Even when she's battling!\p"
	.string "I'd love to see her Gardevoir\n"
	.string "in action at the tournament.$"

BattleFrontier_OutsideNorth_Text_Pokemaniac:
	.string "Oh! That was Red's Pikachu!\n"
	.string "And Diantha's Gardevoir!\p"
	.string "So many rare sights in one place!\n"
	.string "I don't know where to look next!$"

BattleFrontier_OutsideNorth_Text_PokefanF:
	.string "My Grovyle gets so excited when\n"
	.string "it sees other strong Pokemon.\p"
	.string "Maybe one day we'll enter the\n"
	.string "tournament together!$"

BattleFrontier_OutsideNorth_Text_Grovyle:
	.string "Grovyle: Groo-vyle!$"
