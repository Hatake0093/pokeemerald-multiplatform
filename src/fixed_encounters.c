#include "global.h"
#include "event_data.h"
#include "script_pokemon_util.h"
#include "constants/species.h"
#include "data/fixed_encounters.h"

// Jazz: the species of the 14 fixed wild encounters (8 Kecleon, 5 Voltorb, 1 fossil) are decided per seed
// by tools/randomize_wild.pl, which writes data/fixed_encounters.h.
//
// Script special. VAR_0x8004 = index in sFixedEncounterSpecies, VAR_0x8005 = level.
// Starts the scripted wild Pokemon like setwildbattle does and leaves its species in
// VAR_0x8006 so the script can play its cry.
void SetFixedEncounterWildMon(void)
{
    u16 species = sFixedEncounterSpecies[gSpecialVar_0x8004];

    gSpecialVar_0x8006 = species;
    CreateScriptedWildMon(species, gSpecialVar_0x8005, 0);
}
