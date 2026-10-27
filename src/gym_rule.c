#include "global.h"
#include "gym_rule.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_setup.h"
#include "data.h"
#include "mail.h"
#include "permadeath.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "constants/maps.h"
#include "constants/trainers.h"

// box.gymUsed: the Pokemon fought in an earlier battle of the gym the player is in.
// box.gymUsedNow: it has been sent out in the battle in progress. It becomes gymUsed at the end.

static const u16 sGymMaps[] =
{
    MAP_DEWFORD_TOWN_GYM,
    MAP_LAVARIDGE_TOWN_GYM_1F,
    MAP_LAVARIDGE_TOWN_GYM_B1F,
    MAP_PETALBURG_CITY_GYM,
    MAP_MAUVILLE_CITY_GYM,
    MAP_RUSTBORO_CITY_GYM,
    MAP_FORTREE_CITY_GYM,
    MAP_MOSSDEEP_CITY_GYM,
    MAP_SOOTOPOLIS_CITY_GYM_1F,
    MAP_SOOTOPOLIS_CITY_GYM_B1F,
};

static bool8 IsInGymMap(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sGymMaps); i++)
    {
        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(sGymMaps[i])
         && gSaveBlock1Ptr->location.mapNum == MAP_NUM(sGymMaps[i]))
            return TRUE;
    }
    return FALSE;
}

static bool8 IsGymTrainerBattle(void)
{
    if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
        return FALSE;
    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED | BATTLE_TYPE_FRONTIER | BATTLE_TYPE_PYRAMID
                          | BATTLE_TYPE_TRAINER_HILL | BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))
        return FALSE;
    return !gSaveBlock2Ptr->optionsGymRuleOff && IsInGymMap();
}

static bool8 CanFight(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG);

    return species != SPECIES_NONE && species != SPECIES_EGG && GetMonData(mon, MON_DATA_HP) != 0;
}

// TRUE if the Pokemon fought in this gym, for the mark in the party menu
bool8 GymRule_IsMonUsed(struct Pokemon *mon)
{
    return mon->box.gymUsed && !gSaveBlock2Ptr->optionsGymRuleOff && IsInGymMap();
}

// TRUE if the Pokemon already fought in this gym and another Pokemon that hasn't can still fight
bool8 GymRule_IsMonBlocked(struct Pokemon *mon)
{
    u8 i;

    if (!mon->box.gymUsed || !IsGymTrainerBattle())
        return FALSE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (CanFight(&gPlayerParty[i]) && !gPlayerParty[i].box.gymUsed)
            return TRUE;
    }
    return FALSE;
}

void GymRule_MarkBattlerSentIn(u8 battler)
{
    if (GetBattlerSide(battler) == B_SIDE_PLAYER && IsGymTrainerBattle() && gBattlerPartyIndexes[battler] < PARTY_SIZE)
        gPlayerParty[gBattlerPartyIndexes[battler]].box.gymUsedNow = TRUE;
}

// A Pokemon that fought earlier in the gym does not lead the battle if one that hasn't can
void GymRule_PrepareLead(void)
{
    u8 leadCount = (gBattleTypeFlags & BATTLE_TYPE_DOUBLE) ? 2 : 1;
    u8 slot, other;
    struct Pokemon tmp;

    if (!IsGymTrainerBattle())
        return;

    for (slot = 0; slot < leadCount; slot++)
    {
        if (!CanFight(&gPlayerParty[slot]) || !gPlayerParty[slot].box.gymUsed)
            continue;
        for (other = leadCount; other < PARTY_SIZE; other++)
        {
            if (CanFight(&gPlayerParty[other]) && !gPlayerParty[other].box.gymUsed)
            {
                tmp = gPlayerParty[slot];
                gPlayerParty[slot] = gPlayerParty[other];
                gPlayerParty[other] = tmp;
                break;
            }
        }
    }
}

void GymRule_EndOfBattle(void)
{
    bool8 isGymBattle = IsGymTrainerBattle();
    u8 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (isGymBattle && gPlayerParty[i].box.gymUsedNow)
            gPlayerParty[i].box.gymUsed = TRUE;
        gPlayerParty[i].box.gymUsedNow = FALSE;
    }
}

// After a won trainer battle in a gym, each Pokemon that has fought goes to the current box and the next
// Pokemon of that box that hasn't fought takes its party slot. Runs after the permadeath graveyard pass,
// so the dead never come back through here. The Gym Leader battle is left alone: the gym is over.
void GymRule_SwapUsedWithBox(void)
{
    u8 box = gPokemonStoragePtr->currentBox;
    u8 pos = 0;
    u8 i;

    if (!IsGymTrainerBattle() || gBattleOutcome != B_OUTCOME_WON || IsGraveyardBox(box))
        return;
    if (gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_LEADER)
        return;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        u16 species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG);
        struct Pokemon next;

        if (species == SPECIES_NONE || species == SPECIES_EGG || !mon->box.gymUsed
         || ItemIsMail(GetMonData(mon, MON_DATA_HELD_ITEM)))
            continue;

        for (; pos < IN_BOX_COUNT; pos++)
        {
            struct BoxPokemon *boxMon = GetBoxedMonPtr(box, pos);
            u16 boxSpecies = GetBoxMonData(boxMon, MON_DATA_SPECIES_OR_EGG);

            if (boxSpecies != SPECIES_NONE && boxSpecies != SPECIES_EGG && !boxMon->gymUsed)
                break;
        }
        if (pos == IN_BOX_COUNT)
            return;

        BoxMonAtToMon(box, pos, &next);
        SetBoxMonAt(box, pos, &mon->box);
        *mon = next;
        pos++;
    }
    CalculatePlayerPartyCount();
}

// Leaving the gym clears the list, in the party and in the boxes; every gym starts with all the Pokemon available
void GymRule_OnMapLoaded(void)
{
    bool8 inGym = IsInGymMap();
    u8 i, j;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        gPlayerParty[i].box.gymUsedNow = FALSE;
        if (!inGym)
            gPlayerParty[i].box.gymUsed = FALSE;
    }
    if (inGym)
        return;
    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            gPokemonStoragePtr->boxes[i][j].gymUsed = FALSE;
            gPokemonStoragePtr->boxes[i][j].gymUsedNow = FALSE;
        }
    }
}
