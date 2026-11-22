#include "global.h"
#include "pwt.h"
#include "random.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/species.h"

#include "data/battle_frontier/pwt_trainer_mons.h"

// Independent PWT team registry. The facility will use these tables once
// its battle flow is implemented. Blue's additional teams are indexed by
// PwtBlueVariant, but Blue remains a single opponent for random selection.
const struct PwtTrainerParty gPwtBlueVariants[PWT_BLUE_VARIANT_COUNT] =
{
    [PWT_BLUE_VENUSAUR]  = { .mons = sPwtTeamBlueVenusaur,  .partySize = ARRAY_COUNT(sPwtTeamBlueVenusaur) },
    [PWT_BLUE_CHARIZARD] = { .mons = sPwtTeamBlueCharizard, .partySize = ARRAY_COUNT(sPwtTeamBlueCharizard) },
    [PWT_BLUE_BLASTOISE] = { .mons = sPwtTeamBlueBlastoise, .partySize = ARRAY_COUNT(sPwtTeamBlueBlastoise) },
};

// The Blue entry is a default party for code expecting a single-party table.
// PWT battles should call GetPwtOpponentParty to select the chosen variant.
const struct PwtTrainerParty gPwtTrainerParties[PWT_TRAINERS_COUNT] =
{
    [PWT_TRAINER_BLUE]    = { .mons = sPwtTeamBlueVenusaur, .partySize = ARRAY_COUNT(sPwtTeamBlueVenusaur) },
    [PWT_TRAINER_RED]     = { .mons = sPwtTeamRed,     .partySize = ARRAY_COUNT(sPwtTeamRed) },
    [PWT_TRAINER_LANCE]   = { .mons = sPwtTeamLance,   .partySize = ARRAY_COUNT(sPwtTeamLance) },
    [PWT_TRAINER_STEVEN]  = { .mons = sPwtTeamSteven,  .partySize = ARRAY_COUNT(sPwtTeamSteven) },
    [PWT_TRAINER_WALLACE] = { .mons = sPwtTeamWallace, .partySize = ARRAY_COUNT(sPwtTeamWallace) },
    [PWT_TRAINER_CYNTHIA] = { .mons = sPwtTeamCynthia, .partySize = ARRAY_COUNT(sPwtTeamCynthia) },
    [PWT_TRAINER_ALDER]   = { .mons = sPwtTeamAlder,   .partySize = ARRAY_COUNT(sPwtTeamAlder) },
    [PWT_TRAINER_IRIS]    = { .mons = sPwtTeamIris,    .partySize = ARRAY_COUNT(sPwtTeamIris) },
    [PWT_TRAINER_DIANTHA] = { .mons = sPwtTeamDiantha, .partySize = ARRAY_COUNT(sPwtTeamDiantha) },
    [PWT_TRAINER_LEON]    = { .mons = sPwtTeamLeon,    .partySize = ARRAY_COUNT(sPwtTeamLeon) },
};

const struct PwtTrainerParty *GetPwtOpponentParty(const struct PwtOpponent *opponent)
{
    if (opponent == NULL || opponent->trainerId >= PWT_TRAINERS_COUNT)
        return NULL;

    if (opponent->trainerId == PWT_TRAINER_BLUE)
    {
        if (opponent->variantId >= PWT_BLUE_VARIANT_COUNT)
            return NULL;
        return &gPwtBlueVariants[opponent->variantId];
    }

    if (opponent->variantId != 0)
        return NULL;

    return &gPwtTrainerParties[opponent->trainerId];
}

// Select three distinct Champions, not three distinct team variants.
// The caller should invoke this once per tournament and retain the result
// throughout all three battles. This is not connected to an NPC yet.
void ChoosePwtOpponents(struct PwtOpponent opponents[PWT_BATTLES_PER_TOURNAMENT])
{
    u8 available[PWT_TRAINERS_COUNT];
    u8 i;

    for (i = 0; i < PWT_TRAINERS_COUNT; i++)
        available[i] = i;

    for (i = 0; i < PWT_BATTLES_PER_TOURNAMENT; i++)
    {
        u8 pickIndex = i + (Random() % (PWT_TRAINERS_COUNT - i));
        u8 chosen = available[pickIndex];

        available[pickIndex] = available[i];
        available[i] = chosen;

        opponents[i].trainerId = chosen;
        opponents[i].variantId = (chosen == PWT_TRAINER_BLUE)
                                 ? Random() % PWT_BLUE_VARIANT_COUNT
                                 : 0;
    }
}
