OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	lock
	faceplayer
	special BufferLeadMonFriendship
	msgbox OldaleTown_PokemonCenter_1F_Text_FriendshipOfLeadMon, MSGBOX_DEFAULT
	special BufferLeadMonIVsEVs
	msgbox OldaleTown_PokemonCenter_1F_Text_IVsEVsOfLeadMon, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_FriendshipOfLeadMon:
	.string "Déjame ver a {STR_VAR_1}…\p"
	.string "Su amistad contigo es de\n"
	.string "{STR_VAR_2} sobre 255.$"

OldaleTown_PokemonCenter_1F_Text_IVsEVsOfLeadMon:
	.string "Sus valores individuales, sobre 31:\p"
	.string "{STR_VAR_2}\p"
	.string "Sus valores de esfuerzo, sobre 255:\p"
	.string "{STR_VAR_3}$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "¡Los CENTROS POKéMON son geniales!\p"
	.string "Puedes usar sus servicios cuanto\n"
	.string "quieras, ¡y todo es gratis!\l"
	.string "¡Nunca hay de qué preocuparse!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "El POKéMON WIRELESS CLUB del\n"
	.string "segundo piso se construyó hace poco.\p"
	.string "Pero dicen que aún hacen ajustes.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "El POKéMON WIRELESS CLUB del\n"
	.string "segundo piso se construyó hace poco.\p"
	.string "Yo intercambié POKéMON enseguida.$"

