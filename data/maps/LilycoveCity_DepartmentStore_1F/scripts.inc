LilycoveCity_DepartmentStore_1F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_1F_EventScript_Greeter::
	msgbox LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
	end

@ Jazz: pick a number from 1 to 3. A new number is drawn every 1000 steps. If it matches the player
@ wins the prize of that number (Rare Candy, PP Max, Luxury Ball), otherwise an Ultra Ball.
LilycoveCity_DepartmentStore_1F_EventScript_LotteryClerk::
	lock
	faceplayer
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_JAZZ_LOTTERY_PLAYED, LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow
	msgbox LilycoveCity_DepartmentStore_1F_Text_JazzLotteryIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain
	message LilycoveCity_DepartmentStore_1F_Text_JazzLotteryPick
	waitmessage
	multichoice 15, 0, MULTI_LOTTERY_NUMBER, FALSE
	goto_if_ge VAR_RESULT, 3, LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain
	copyvar VAR_0x8008, VAR_RESULT
	setflag FLAG_JAZZ_LOTTERY_PLAYED
	msgbox LilycoveCity_DepartmentStore_1F_Text_JazzLotteryChecking, MSGBOX_DEFAULT
	applywaitmovement LOCALID_LOTTERY_CLERK, Common_Movement_WalkInPlaceFasterRight
	playse SE_PC_ON
	special DoLotteryCornerComputerEffect
	special CheckJazzLottery
	delay 220
	special EndLotteryCornerComputerEffect
	delay 10
	applywaitmovement LOCALID_LOTTERY_CLERK, Common_Movement_FacePlayer
	bufferitemname STR_VAR_1, VAR_0x8005
	goto_if_eq VAR_0x8004, 0, LilycoveCity_DepartmentStore_1F_EventScript_JazzLotteryLost
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	msgbox LilycoveCity_DepartmentStore_1F_Text_JazzLotteryWon, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_1F_EventScript_JazzLotteryGivePrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_JazzLotteryLost::
	msgbox LilycoveCity_DepartmentStore_1F_Text_JazzLotteryLost, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_1F_EventScript_JazzLotteryGivePrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_JazzLotteryGivePrize::
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
	end

LilycoveCity_DepartmentStore_1F_Text_JazzLotteryIntro:
	.string "¡Bienvenido a la LOTERÍA!\pElige un número del 1 al 3.\nSi coincide con el sorteo, ganas el\npremio de ese número.\pEl sorteo cambia cada 1000 pasos.\p¿Quieres jugar?$"

LilycoveCity_DepartmentStore_1F_Text_JazzLotteryPick:
	.string "¿Qué número eliges?$"

LilycoveCity_DepartmentStore_1F_Text_JazzLotteryChecking:
	.string "Muy bien, voy a comprobar el sorteo…$"

LilycoveCity_DepartmentStore_1F_Text_JazzLotteryWon:
	.string "¡Tu número coincide!\p¡Has ganado {STR_VAR_1}!$"

LilycoveCity_DepartmentStore_1F_Text_JazzLotteryLost:
	.string "Tu número no coincide…\pPero toma esto de consolación:\n{STR_VAR_1}.$"

LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow::
	msgbox LilycoveCity_DepartmentStore_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_NoMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
	end

LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_FullMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom::
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize::
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_PokefanF::
	msgbox LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_LittleGirl::
	msgbox LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_PokefanM::
	msgbox LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox LilycoveCity_DepartmentStore_1F_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_FloorNamesSign::
	msgbox LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign, MSGBOX_SIGN
	end

LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore:
	.string "Welcome to LILYCOVE DEPARTMENT STORE.$"

LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings:
	.string "Whenever I come to the DEPARTMENT\n"
	.string "STORE, I always end up buying all sorts\l"
	.string "of things because it's so fun.$"

LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture:
	.string "Today, my mom is going to buy me some\n"
	.string "nice furniture.$"

LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill:
	.string "I'm buying something for my AZUMARILL\n"
	.string "as a reward for winning a CONTEST.$"

LilycoveCity_DepartmentStore_1F_Text_Azumarill:
	.string "AZUMARILL: Maririroo!$"

LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign:
	.string "1F: SERVICE COUNTER\n"
	.string "    LOTTERY CORNER\p"
	.string "2F: TRAINER'S ZONE\p"
	.string "3F: BATTLE COLLECTION\p"
	.string "4F: TM CORNER\p"
	.string "5F: POKé DOLL FLOOR\p"
	.string "ROOFTOP: ROOFTOP PLAZA$"

@ Unused
LilycoveCity_DepartmentStore_1F_Text_WirelessCommIsFun:
	.string "Wireless Communication is a\n"
	.string "lot of fun, isn't it?\p"
	.string "I think it lets you do things that\n"
	.string "weren't possible before.\p"
	.string "For instance, you can now trade\n"
	.string "with people you couldn't before.\p"
	.string "I think it's going to be exciting!$"

@ Unused
LilycoveCity_DepartmentStore_1F_Text_SpreadWordAboutWirelessComm:
	.string "I want to spread the word about how\n"
	.string "fun Wireless Communication can be.$"

