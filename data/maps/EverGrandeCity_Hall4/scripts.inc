EverGrandeCity_Hall4_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall4_OnWarp
	.byte 0

EverGrandeCity_Hall4_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall4_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_Hall4_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

@ Jazz: a PC before the Champion. The normal PC script is not used because its turn on/off
@ effect redraws the tile in front of the player as a PC screen.
EverGrandeCity_Hall4_EventScript_PCAttendant::
	lock
	faceplayer
	msgbox EverGrandeCity_Hall4_Text_UseThePC, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EverGrandeCity_Hall4_EventScript_PCDeclined
	setvar VAR_0x8004, PC_LOCATION_OTHER
	playse SE_PC_LOGIN
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	msgbox EverGrandeCity_Hall4_Text_GoodLuck, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_Hall4_EventScript_PCDeclined::
	msgbox EverGrandeCity_Hall4_Text_GoodLuck, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_Hall4_Text_UseThePC:
	.string "The CHAMPION waits beyond this hall.\p"
	.string "Would you like to use the PC before\n"
	.string "the final battle?$"

EverGrandeCity_Hall4_Text_GoodLuck:
	.string "Good luck!$"
