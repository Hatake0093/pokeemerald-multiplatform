OldaleTown_House1_MapScripts::
	.byte 0

@ Jazz: this woman gives the {POKEBLOCK} CASE (it used to come from the Contest Hall)
OldaleTown_House1_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POKEBLOCK_CASE, OldaleTown_House1_EventScript_WomanTip
	msgbox OldaleTown_House1_Text_GiveCase, MSGBOX_DEFAULT
	giveitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_POKEBLOCK_CASE
	msgbox OldaleTown_House1_Text_CaseExplanation, MSGBOX_DEFAULT
	release
	end

OldaleTown_House1_EventScript_WomanTip::
	msgbox OldaleTown_House1_Text_LeftPokemonGoesOutFirst, MSGBOX_DEFAULT
	release
	end

OldaleTown_House1_Text_LeftPokemonGoesOutFirst:
	.string "When a POKéMON battle starts, the one\n"
	.string "at the left of the list goes out first.\p"
	.string "So, when you get more POKéMON in your\n"
	.string "party, try switching around the order\l"
	.string "of your POKéMON.\p"
	.string "It could give you an advantage.$"

OldaleTown_House1_Text_GiveCase:
	.string "¡Hola!\pAntes preparaba {POKEBLOCK}S para mis\nPOKéMON, pero ya no los uso.\pToma, te regalo mi {POKEBLOCK} CASE.$"

OldaleTown_House1_Text_CaseExplanation:
	.string "Ahí guardas los {POKEBLOCK}S.\pSe los puedes dar a tus POKéMON,\ny en la tienda de flores de la\nRUTA 104 venden algunos.$"
