#include "global.h"
#include "permadeath.h"
#include "event_data.h"
#include "item.h"
#include "mail.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "string_util.h"
#include "constants/battle.h"
#include "constants/flags.h"
#include "constants/items.h"

extern u32 gBattleTypeFlags;

static const u8 sGraveyardBoxNames[GRAVEYARD_BOXES_COUNT][BOX_NAME_LENGTH + 1] =
{
    _("GRAVE 1"),
    _("GRAVE 2"),
};

// Jazz: once the League has been won (the Hall of Fame is entered) the graveyard opens up: the
// dead can be taken out of their boxes and revived, so the MVPs can join the commemorative rounds
bool8 IsPermadeathOn(void)
{
    return gSaveBlock2Ptr->optionsPermadeath && !FlagGet(FLAG_SYS_GAME_CLEAR);
}

bool8 IsGraveyardBox(u8 boxId)
{
    return !FlagGet(FLAG_SYS_GAME_CLEAR) && boxId >= FIRST_GRAVEYARD_BOX && boxId < TOTAL_BOXES_COUNT;
}

void InitGraveyardBoxNames(void)
{
    s32 i;

    for (i = 0; i < GRAVEYARD_BOXES_COUNT; i++)
        StringCopy(GetBoxNamePtr(FIRST_GRAVEYARD_BOX + i), sGraveyardBoxNames[i]);
}

static bool8 IsMonFainted(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG);

    return species != SPECIES_NONE && species != SPECIES_EGG && GetMonData(mon, MON_DATA_HP) == 0;
}

// TRUE if the party has Pokemon and every one of them is fainted
bool8 IsPartyWiped(void)
{
    s32 i;
    bool8 anyMon = FALSE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);

        if (species == SPECIES_NONE || species == SPECIES_EGG)
            continue;
        anyMon = TRUE;
        if (GetMonData(&gPlayerParty[i], MON_DATA_HP) != 0)
            return FALSE;
    }
    return anyMon;
}

static bool8 TryPutMonInGraveyard(struct Pokemon *mon)
{
    s32 box, pos;
    u16 item = GetMonData(mon, MON_DATA_HELD_ITEM);

    // The held item goes back to the bag when there is room
    if (item != ITEM_NONE && !ItemIsMail(item) && AddBagItem(item, 1))
    {
        u16 none = ITEM_NONE;

        SetMonData(mon, MON_DATA_HELD_ITEM, &none);
    }

    for (box = FIRST_GRAVEYARD_BOX; box < TOTAL_BOXES_COUNT; box++)
    {
        for (pos = 0; pos < IN_BOX_COUNT; pos++)
        {
            if (GetBoxMonDataAt(box, pos, MON_DATA_SPECIES) == SPECIES_NONE)
            {
                SetBoxMonAt(box, pos, &mon->box);
                return TRUE;
            }
        }
    }
    return FALSE;
}

// Fainted party Pokemon move to the graveyard boxes. A fully wiped party is left alone: it is game over.
void SendFaintedMonsToGraveyard(void)
{
    s32 i;

    if (!IsPermadeathOn() || IsPartyWiped())
        return;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (IsMonFainted(&gPlayerParty[i]) && TryPutMonInGraveyard(&gPlayerParty[i]))
            ZeroMonData(&gPlayerParty[i]);
    }
    CompactPartySlots();
    CalculatePlayerPartyCount();
}

void SendFaintedMonsToGraveyardAfterBattle(void)
{
    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_RECORDED
                          | BATTLE_TYPE_FRONTIER | BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER
                          | BATTLE_TYPE_TRAINER_HILL | BATTLE_TYPE_WALLY_TUTORIAL | BATTLE_TYPE_FIRST_BATTLE
                          | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_SAFARI))
        return;

    SendFaintedMonsToGraveyard();
}
