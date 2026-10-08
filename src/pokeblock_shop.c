#include "global.h"
#include "event_data.h"
#include "money.h"
#include "pokeblock.h"

// Jazz: the Pokeblock vendor of the Lilycove Department Store (5F)
#define POKEBLOCK_SHOP_PRICE 500

static const struct Pokeblock sPokeblocksForSale[] =
{
    //  color             spicy dry sweet bitter sour feel
    {PBLOCK_CLR_RED,       20,   0,   0,    0,    0,  25},
    {PBLOCK_CLR_BLUE,       0,  20,   0,    0,    0,  25},
    {PBLOCK_CLR_PINK,       0,   0,  20,    0,    0,  25},
    {PBLOCK_CLR_GREEN,      0,   0,   0,   20,    0,  25},
    {PBLOCK_CLR_YELLOW,     0,   0,   0,    0,   20,  25},
};

// Script special. VAR_0x8004 = index in sPokeblocksForSale.
// VAR_RESULT: 0 = bought, 1 = not enough money, 2 = no room in the POKEBLOCK CASE
void BuyPokeblock(void)
{
    if (!IsEnoughMoney(&gSaveBlock1Ptr->money, POKEBLOCK_SHOP_PRICE))
    {
        gSpecialVar_Result = 1;
    }
    else if (!AddPokeblock(&sPokeblocksForSale[gSpecialVar_0x8004]))
    {
        gSpecialVar_Result = 2;
    }
    else
    {
        RemoveMoney(&gSaveBlock1Ptr->money, POKEBLOCK_SHOP_PRICE);
        gSpecialVar_Result = 0;
    }
}
