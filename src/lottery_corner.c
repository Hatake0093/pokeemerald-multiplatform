#include "global.h"
#include "lottery_corner.h"
#include "event_data.h"
#include "pokemon.h"
#include "constants/items.h"
#include "random.h"
#include "string_util.h"
#include "text.h"
#include "pokemon_storage_system.h"

static EWRAM_DATA u16 sWinNumberDigit = 0;
static EWRAM_DATA u16 sOtIdDigit = 0;

// Jazz: the lottery number goes from 1 to 10 and a new one is drawn every LOTTERY_STEPS_PER_DRAW steps.
// The player picks a number: if it matches, the prize is chosen at random with the chances below
// (so picking a number says nothing about the prize), otherwise it is a consolation prize.
#define LOTTERY_NUMBERS 10

static const struct
{
    u16 item;
    u8 chance; // out of 100
} sLotteryPrizes[] =
{
    {ITEM_RARE_CANDY,  60},
    {ITEM_PP_MAX,      30},
    {ITEM_LUXURY_BALL, 10},
};

static u8 GetMatchingDigits(u16, u16);

void ResetLotteryCorner(void)
{
    SetLotteryNumber(1 + Random() % LOTTERY_NUMBERS);
    FlagClear(FLAG_JAZZ_LOTTERY_PLAYED);
    VarSet(VAR_POKELOT_PRIZE_ITEM, ITEM_NONE);
}

// Called every LOTTERY_STEPS_PER_DRAW steps
void DrawNewLotteryNumber(void)
{
    SetLotteryNumber(1 + Random() % LOTTERY_NUMBERS);
    FlagClear(FLAG_JAZZ_LOTTERY_PLAYED);
}

// Script special. VAR_0x8009 = 0 for the numbers 1 to 5 and 1 for the numbers 6 to 10,
// VAR_0x8008 = position of the number picked inside that group (0 to 4).
// VAR_0x8004 = 1 if the player won and 0 if not, VAR_0x8005 = prize item
void CheckJazzLottery(void)
{
    u32 picked = gSpecialVar_0x8009 * 5 + gSpecialVar_0x8008 + 1;

    if (picked == GetLotteryNumber())
    {
        u32 roll = Random() % 100;
        u32 i, total = 0;

        gSpecialVar_0x8004 = 1;
        for (i = 0; i < ARRAY_COUNT(sLotteryPrizes); i++)
        {
            total += sLotteryPrizes[i].chance;
            if (roll < total)
                break;
        }
        gSpecialVar_0x8005 = sLotteryPrizes[i].item;
    }
    else
    {
        gSpecialVar_0x8004 = 0;
        gSpecialVar_0x8005 = ITEM_ULTRA_BALL;
    }
}

void SetRandomLotteryNumber(u16 i)
{
    u32 var = Random();

    while (--i != 0xFFFF)
        var = ISO_RANDOMIZE2(var);

    SetLotteryNumber(var);
}

void RetrieveLotteryNumber(void)
{
    u16 lottoNumber = GetLotteryNumber();
    gSpecialVar_Result = lottoNumber;
}

void PickLotteryCornerTicket(void)
{
    u16 i;
    u16 j;
    u32 box;
    u32 slot;

    gSpecialVar_0x8004 = 0;
    slot = 0;
    box = 0;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];

        if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
        {
            // do not calculate ticket values for eggs.
            if (!GetMonData(mon, MON_DATA_IS_EGG))
            {
                u32 otId = GetMonData(mon, MON_DATA_OT_ID);
                u8 numMatchingDigits = GetMatchingDigits(gSpecialVar_Result, otId);

                if (numMatchingDigits > gSpecialVar_0x8004 && numMatchingDigits > 1)
                {
                    gSpecialVar_0x8004 = numMatchingDigits - 1;
                    box = TOTAL_BOXES_COUNT;
                    slot = i;
                }
            }
        }
        else // Pokémon are always arranged from populated spots first to unpopulated, so the moment a NONE species is found, that's the end of the list.
        {
            break;
        }
    }

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SPECIES) != SPECIES_NONE &&
            !GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_IS_EGG))
            {
                u32 otId = GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_OT_ID);
                u8 numMatchingDigits = GetMatchingDigits(gSpecialVar_Result, otId);

                if (numMatchingDigits > gSpecialVar_0x8004 && numMatchingDigits > 1)
                {
                    gSpecialVar_0x8004 = numMatchingDigits - 1;
                    box = i;
                    slot = j;
                }
            }
        }
    }

    if (gSpecialVar_0x8004 != 0)
    {
        gSpecialVar_0x8005 = sLotteryPrizes[gSpecialVar_0x8004 - 1].item;

        if (box == TOTAL_BOXES_COUNT)
        {
            gSpecialVar_0x8006 = 0;
            GetMonData(&gPlayerParty[slot], MON_DATA_NICKNAME, gStringVar1);
        }
        else
        {
            gSpecialVar_0x8006 = 1;
            GetBoxMonData(&gPokemonStoragePtr->boxes[box][slot], MON_DATA_NICKNAME, gStringVar1);
        }
        StringGet_Nickname(gStringVar1);
    }
}

static u8 GetMatchingDigits(u16 winNumber, u16 otId)
{
    u8 i;
    u8 matchingDigits = 0;

    for (i = 0; i < 5; i++)
    {
        sWinNumberDigit = winNumber % 10;
        sOtIdDigit = otId % 10;

        if (sWinNumberDigit == sOtIdDigit)
        {
            winNumber = winNumber / 10;
            otId = otId / 10;
            matchingDigits++;
        }
        else
        {
            break;
        }
    }
    return matchingDigits;
}

// lottery numbers go from 0 to 99999, not 65535 (0xFFFF). interestingly enough, the function that calls GetLotteryNumber shifts to u16, so it cant be anything above 65535 anyway.
void SetLotteryNumber(u32 lotteryNum)
{
    u16 lowNum = lotteryNum >> 16;
    u16 highNum = lotteryNum;

    VarSet(VAR_POKELOT_RND1, highNum);
    VarSet(VAR_POKELOT_RND2, lowNum);
}

u32 GetLotteryNumber(void)
{
    u16 highNum = VarGet(VAR_POKELOT_RND1);
    u16 lowNum = VarGet(VAR_POKELOT_RND2);

    return (lowNum << 16) | highNum;
}

// interestingly, this may have been the original lottery number set function, but GF tried to change it to 32-bit later but didnt finish changing all calls as one GetLotteryNumber still shifts to u16.
void SetLotteryNumber16_Unused(u16 lotteryNum)
{
    SetLotteryNumber(lotteryNum);
}
