#ifndef GUARD_PERMADEATH_H
#define GUARD_PERMADEATH_H

// The last boxes of the PC are read-only graveyard boxes
#include "pokemon_storage_system.h"

#define GRAVEYARD_BOXES_COUNT 2
#define FIRST_GRAVEYARD_BOX   (TOTAL_BOXES_COUNT - GRAVEYARD_BOXES_COUNT)

bool8 IsPermadeathOn(void);
bool8 IsGraveyardBox(u8 boxId);
bool8 IsPartyWiped(void);
void InitGraveyardBoxNames(void);
void SendFaintedMonsToGraveyard(void);
void SendFaintedMonsToGraveyardAfterBattle(void);
void CB2_InitPermadeathGameOver(void);

#endif // GUARD_PERMADEATH_H
