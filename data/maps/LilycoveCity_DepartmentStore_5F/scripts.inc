LilycoveCity_DepartmentStore_5F_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LilycoveCity_DepartmentStore_5F_OnWarp
	.byte 0

@ During the abnormal weather from Kyogre/Groudon awakening the dept store rooftop is inaccessible
@ Likely done to avoid dealing with showing the weather. Technically the rooftop is indoors
LilycoveCity_DepartmentStore_5F_OnWarp:
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 2, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 3, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
	.2byte 0

LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs::
	setobjectxy LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN, 16, 2
	turnobject LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN, DIR_NORTH
	end

@ Jazz: the four clerks sell held items (the POKEBLOCK vendor script below is used by the flower shop)
LilycoveCity_DepartmentStore_5F_EventScript_ClerkFarLeft::
	lock
	faceplayer
	message gText_PlayerWhatCanIDoForYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_5F_Pokemart_Types1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_ClerkMidLeft::
	lock
	faceplayer
	message gText_PlayerWhatCanIDoForYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_5F_Pokemart_Types2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_ClerkMidRight::
	lock
	faceplayer
	message gText_PlayerWhatCanIDoForYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_5F_Pokemart_Battle
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_ClerkFarRight::
	lock
	faceplayer
	message gText_PlayerWhatCanIDoForYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_5F_Pokemart_Growth
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_PokeblockClerk::
	lock
	faceplayer
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_5F_EventScript_NoPokeblockCase
	message LilycoveCity_DepartmentStore_5F_Text_PokeblocksForSale
	waitmessage
	showmoneybox 0, 0
	goto LilycoveCity_DepartmentStore_5F_EventScript_PokeblockMenu
	end

LilycoveCity_DepartmentStore_5F_EventScript_PokeblockMenu::
	multichoice 17, 0, MULTI_POKEBLOCK_SHOP, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_DepartmentStore_5F_EventScript_BuyPokeblock
	case 1, LilycoveCity_DepartmentStore_5F_EventScript_BuyPokeblock
	case 2, LilycoveCity_DepartmentStore_5F_EventScript_BuyPokeblock
	case 3, LilycoveCity_DepartmentStore_5F_EventScript_BuyPokeblock
	case 4, LilycoveCity_DepartmentStore_5F_EventScript_BuyPokeblock
	hidemoneybox
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_BuyPokeblock::
	copyvar VAR_0x8004, VAR_0x8000
	special BuyPokeblock
	switch VAR_RESULT
	case 1, LilycoveCity_DepartmentStore_5F_EventScript_NotEnoughMoneyForPokeblock
	case 2, LilycoveCity_DepartmentStore_5F_EventScript_NoRoomForPokeblock
	playse SE_SHOP
	updatemoneybox
	msgbox LilycoveCity_DepartmentStore_5F_Text_ThankYouPokeblock, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_5F_EventScript_PokeblockMenu
	end

LilycoveCity_DepartmentStore_5F_EventScript_NotEnoughMoneyForPokeblock::
	msgbox LilycoveCity_DepartmentStore_5F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_5F_EventScript_PokeblockMenu
	end

LilycoveCity_DepartmentStore_5F_EventScript_NoRoomForPokeblock::
	msgbox LilycoveCity_DepartmentStore_5F_Text_NoRoomInCase, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_5F_EventScript_PokeblockMenu
	end

LilycoveCity_DepartmentStore_5F_EventScript_NoPokeblockCase::
	msgbox LilycoveCity_DepartmentStore_5F_Text_NeedPokeblockCase, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_5F_Text_PokeblocksForSale:
	.string "Welcome!\n"
	.string "{POKEBLOCK}S are ¥500 each.\p"
	.string "Which one would you like?$"

LilycoveCity_DepartmentStore_5F_Text_ThankYouPokeblock:
	.string "Thank you!\n"
	.string "Anything else?$"

LilycoveCity_DepartmentStore_5F_Text_NotEnoughMoney:
	.string "You don't have enough money.$"

LilycoveCity_DepartmentStore_5F_Text_NoRoomInCase:
	.string "Your {POKEBLOCK} CASE is full.$"

LilycoveCity_DepartmentStore_5F_Text_NeedPokeblockCase:
	.string "You need a {POKEBLOCK} CASE to carry\n"
	.string "{POKEBLOCK}S.$"

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Types1:
	.2byte ITEM_CHARCOAL
	.2byte ITEM_MYSTIC_WATER
	.2byte ITEM_MIRACLE_SEED
	.2byte ITEM_MAGNET
	.2byte ITEM_NEVER_MELT_ICE
	.2byte ITEM_BLACK_BELT
	.2byte ITEM_POISON_BARB
	.2byte ITEM_SOFT_SAND
	.2byte ITEM_SHARP_BEAK
	pokemartlistend

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Types2:
	.2byte ITEM_TWISTED_SPOON
	.2byte ITEM_SILVER_POWDER
	.2byte ITEM_HARD_STONE
	.2byte ITEM_SPELL_TAG
	.2byte ITEM_DRAGON_FANG
	.2byte ITEM_BLACK_GLASSES
	.2byte ITEM_METAL_COAT
	.2byte ITEM_SILK_SCARF
	pokemartlistend

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Battle:
	.2byte ITEM_LEFTOVERS
	.2byte ITEM_SHELL_BELL
	.2byte ITEM_SCOPE_LENS
	.2byte ITEM_FOCUS_BAND
	.2byte ITEM_QUICK_CLAW
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_CHOICE_BAND
	.2byte ITEM_SMOKE_BALL
	.2byte ITEM_BRIGHT_POWDER
	.2byte ITEM_WHITE_HERB
	.2byte ITEM_MENTAL_HERB
	pokemartlistend

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Growth:
	.2byte ITEM_EXP_SHARE
	.2byte ITEM_LUCKY_EGG
	.2byte ITEM_AMULET_COIN
	.2byte ITEM_SOOTHE_BELL
	.2byte ITEM_EVERSTONE
	.2byte ITEM_MACHO_BRACE
	.2byte ITEM_LIGHT_BALL
	.2byte ITEM_LUCKY_PUNCH
	.2byte ITEM_STICK
	.2byte ITEM_THICK_CLUB
	.2byte ITEM_METAL_POWDER
	.2byte ITEM_DEEP_SEA_TOOTH
	.2byte ITEM_DEEP_SEA_SCALE
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_LAX_INCENSE
	pokemartlistend

LilycoveCity_DepartmentStore_5F_EventScript_PokefanF::
	msgbox LilycoveCity_DepartmentStore_5F_Text_PlaceFullOfCuteDolls, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_5F_EventScript_Woman::
	lockall
	applywaitmovement LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN, Common_Movement_FacePlayer
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal
	goto LilycoveCity_DepartmentStore_5F_EventScript_WomanLegendaryWeather
	end

LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal::
	msgbox LilycoveCity_DepartmentStore_5F_Text_SellManyCuteMatsHere, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

LilycoveCity_DepartmentStore_5F_EventScript_WomanLegendaryWeather::
	msgbox LilycoveCity_DepartmentStore_5F_Text_ClosedRooftopForWeather, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN, Common_Movement_WalkInPlaceFasterUp
	releaseall
	end

LilycoveCity_DepartmentStore_5F_EventScript_LittleGirl::
	msgbox LilycoveCity_DepartmentStore_5F_Text_GettingDollInsteadOfPokemon, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_5F_Text_PlaceFullOfCuteDolls:
	.string "This place is full of cute DOLLS.\p"
	.string "I should buy some for me, instead of\n"
	.string "just for my children.$"

LilycoveCity_DepartmentStore_5F_Text_GettingDollInsteadOfPokemon:
	.string "I'm not big enough to raise POKéMON,\n"
	.string "so I'm getting a cute DOLL instead.$"

LilycoveCity_DepartmentStore_5F_Text_SellManyCuteMatsHere:
	.string "They sell many cute MATS here.\p"
	.string "I wonder which one I should get?\n"
	.string "Maybe I'll buy them all…$"

LilycoveCity_DepartmentStore_5F_Text_ClosedRooftopForWeather:
	.string "I think they closed the rooftop\n"
	.string "because the weather is wild today.$"
