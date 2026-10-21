LavaridgeTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavaridgeTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_LAVARIDGE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Woman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether:
	.string "I think POKéMON get closer to their\n"
	.string "TRAINERS if they spend time together.\p"
	.string "The longer the better.\n"
	.string "That's what I think.$"

LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate:
	.string "It's sort of magical how just sitting\n"
	.string "in a hot-spring pool can invigorate.\p"
	.string "I wish I could let my POKéMON\n"
	.string "soak, too.$"

LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo:
	.string "Hohoho! Hey, kid, you can reach\n"
	.string "the hot springs from here.\p"
	.string "If POKéMON are getting rest, so too\n"
	.string "should their TRAINERS.$"

@ Jazz: swaps the ability of a party Pokemon for 15000
LavaridgeTown_PokemonCenter_1F_EventScript_AbilityChanger::
	lock
	faceplayer
	msgbox LavaridgeTown_PokemonCenter_1F_Text_AbilityIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_PokemonCenter_1F_EventScript_AbilityDeclined
	checkmoney 15000
	goto_if_eq VAR_RESULT, FALSE, LavaridgeTown_PokemonCenter_1F_EventScript_AbilityNoMoney
	msgbox LavaridgeTown_PokemonCenter_1F_Text_AbilityWhichMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LavaridgeTown_PokemonCenter_1F_EventScript_AbilityDeclined
	special PreviewMonAbilityChange
	goto_if_eq VAR_RESULT, 2, LavaridgeTown_PokemonCenter_1F_EventScript_AbilityCannot
	msgbox LavaridgeTown_PokemonCenter_1F_Text_AbilityConfirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_PokemonCenter_1F_EventScript_AbilityDeclined
	special ChangeMonAbilityFromScript
	removemoney 15000
	msgbox LavaridgeTown_PokemonCenter_1F_Text_AbilityDone, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_AbilityDeclined::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_AbilityBye, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_AbilityNoMoney::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_AbilityNoMoney, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_AbilityCannot::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_AbilityCannot, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_PokemonCenter_1F_Text_AbilityIntro:
	.string "Puedo cambiar la HABILIDAD de un\nPOKéMON por ¥15.000.\p¿Quieres que lo haga?$"

LavaridgeTown_PokemonCenter_1F_Text_AbilityWhichMon:
	.string "¿A qué POKéMON se la cambio?$"

LavaridgeTown_PokemonCenter_1F_Text_AbilityConfirm:
	.string "Su habilidad es {STR_VAR_2}.\n¿La cambio a {STR_VAR_3}?$"

LavaridgeTown_PokemonCenter_1F_Text_AbilityDone:
	.string "¡Listo!\pAhora su habilidad es {STR_VAR_3}.$"

LavaridgeTown_PokemonCenter_1F_Text_AbilityBye:
	.string "Vuelve cuando quieras.$"

LavaridgeTown_PokemonCenter_1F_Text_AbilityNoMoney:
	.string "No tienes suficiente dinero.$"

LavaridgeTown_PokemonCenter_1F_Text_AbilityCannot:
	.string "Ese POKéMON solo tiene una\nhabilidad. No hay nada que cambiar.$"
