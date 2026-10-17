FallarborTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

FallarborTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FALLARBOR_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl::
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Lanette::
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_LanetteGreeting, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth::
	applywaitmovement LOCALID_FALLARBOR_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest::
	applywaitmovement LOCALID_FALLARBOR_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExited::
	playse SE_SLIDING_DOOR
	removeobject LOCALID_FALLARBOR_LANETTE
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Text_LanetteGreeting:
	.string "Oh, hello.\n"
	.string "You are?\p"
	.string "Okay, your name's {PLAYER}{KUN}.\n"
	.string "I can see that you're a TRAINER.\p"
	.string "So that means you use the POKéMON\n"
	.string "Storage System I developed.\p"
	.string "How I arrived at that conclusion is\n"
	.string "a simple deductive process.\p"
	.string "You spoke to me because you wanted\n"
	.string "to access something on this PC.\p"
	.string "Oh, I'm sorry. I'm LANETTE.\p"
	.string "Honestly, I'm glad to meet you--it's\n"
	.string "great you're using the Storage System.\p"
	.string "If you could, please visit me at home.\n"
	.string "My house is on ROUTE 114.$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown:
	.string "I wonder what POKéMON looked like\n"
	.string "long, long ago?\p"
	.string "Maybe the FOSSIL MANIAC at the edge\n"
	.string "of town will know.$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees:
	.string "In the fields of FALLARBOR, we plant\n"
	.string "seedlings of hardy trees that thrive\l"
	.string "even in volcanic ash.$"

@ Jazz: changes the nature of a party Pokemon for 15000. The player picks the stat to raise and the
@ stat to lower (the same one twice gives a neutral nature).
FallarborTown_PokemonCenter_1F_EventScript_NatureChanger::
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_NatureIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FallarborTown_PokemonCenter_1F_EventScript_NatureDeclined
	checkmoney 15000
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_PokemonCenter_1F_EventScript_NatureNoMoney
	msgbox FallarborTown_PokemonCenter_1F_Text_NatureWhichMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_PokemonCenter_1F_EventScript_NatureDeclined
	msgbox FallarborTown_PokemonCenter_1F_Text_NatureRaise, MSGBOX_DEFAULT
	multichoice 15, 0, MULTI_NATURE_STAT, FALSE
	goto_if_ge VAR_RESULT, 5, FallarborTown_PokemonCenter_1F_EventScript_NatureDeclined
	copyvar VAR_0x8005, VAR_RESULT
	msgbox FallarborTown_PokemonCenter_1F_Text_NatureLower, MSGBOX_DEFAULT
	multichoice 15, 0, MULTI_NATURE_STAT, FALSE
	goto_if_ge VAR_RESULT, 5, FallarborTown_PokemonCenter_1F_EventScript_NatureDeclined
	copyvar VAR_0x8006, VAR_RESULT
	special ChangeMonNatureFromScript
	goto_if_eq VAR_RESULT, 1, FallarborTown_PokemonCenter_1F_EventScript_NatureSame
	goto_if_eq VAR_RESULT, 2, FallarborTown_PokemonCenter_1F_EventScript_NatureCannot
	removemoney 15000
	msgbox FallarborTown_PokemonCenter_1F_Text_NatureDone, MSGBOX_DEFAULT
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_NatureDeclined::
	msgbox FallarborTown_PokemonCenter_1F_Text_NatureBye, MSGBOX_DEFAULT
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_NatureNoMoney::
	msgbox FallarborTown_PokemonCenter_1F_Text_NatureNoMoney, MSGBOX_DEFAULT
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_NatureSame::
	msgbox FallarborTown_PokemonCenter_1F_Text_NatureSame, MSGBOX_DEFAULT
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_NatureCannot::
	msgbox FallarborTown_PokemonCenter_1F_Text_NatureCannot, MSGBOX_DEFAULT
	release
	end

FallarborTown_PokemonCenter_1F_Text_NatureIntro:
	.string "Puedo cambiar la NATURALEZA de un\nPOKéMON por ¥15.000.\p¿Quieres que lo haga?$"

FallarborTown_PokemonCenter_1F_Text_NatureWhichMon:
	.string "¿A qué POKéMON se la cambio?$"

FallarborTown_PokemonCenter_1F_Text_NatureRaise:
	.string "¿Qué estadística quieres que\nsuba?$"

FallarborTown_PokemonCenter_1F_Text_NatureLower:
	.string "¿Y cuál quieres que baje?\pSi eliges la misma, la naturaleza\nserá neutra.$"

FallarborTown_PokemonCenter_1F_Text_NatureDone:
	.string "¡Listo!\pLa naturaleza ahora es {STR_VAR_2}.$"

FallarborTown_PokemonCenter_1F_Text_NatureBye:
	.string "Vuelve cuando quieras.$"

FallarborTown_PokemonCenter_1F_Text_NatureNoMoney:
	.string "No tienes suficiente dinero.$"

FallarborTown_PokemonCenter_1F_Text_NatureSame:
	.string "Ya tiene la naturaleza {STR_VAR_2}.\nNo hace falta cambiarla.$"

FallarborTown_PokemonCenter_1F_Text_NatureCannot:
	.string "A ese POKéMON no le puedo cambiar\nla naturaleza.$"
