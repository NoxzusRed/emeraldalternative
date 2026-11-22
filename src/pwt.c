#include "global.h"
#include "pwt.h"
#include "random.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/species.h"

#include "data/battle_frontier/pwt_trainer_mons.h"

// One entry per Champion, with three independent editable team variants.
// No PWT facility or battle is connected to this registry yet.
const struct PwtTrainerParty gPwtTrainerParties[PWT_TRAINERS_COUNT][PWT_VARIANTS_PER_TRAINER] =
{
    [PWT_TRAINER_BLUE] =
    {
        [PWT_VARIANT_1] = { .mons = sPwtTeamBlue1, .partySize = ARRAY_COUNT(sPwtTeamBlue1) },
        [PWT_VARIANT_2] = { .mons = sPwtTeamBlue2, .partySize = ARRAY_COUNT(sPwtTeamBlue2) },
        [PWT_VARIANT_3] = { .mons = sPwtTeamBlue3, .partySize = ARRAY_COUNT(sPwtTeamBlue3) },
    },
    [PWT_TRAINER_RED] =
    {
        [PWT_VARIANT_1] = { .mons = sPwtTeamRed1, .partySize = ARRAY_COUNT(sPwtTeamRed1) },
        [PWT_VARIANT_2] = { .mons = sPwtTeamRed2, .partySize = ARRAY_COUNT(sPwtTeamRed2) },
        [PWT_VARIANT_3] = { .mons = sPwtTeamRed3, .partySize = ARRAY_COUNT(sPwtTeamRed3) },
    },
    [PWT_TRAINER_LANCE] =
    {
        [PWT_VARIANT_1] = { .mons = sPwtTeamLance1, .partySize = ARRAY_COUNT(sPwtTeamLance1) },
        [PWT_VARIANT_2] = { .mons = sPwtTeamLance2, .partySize = ARRAY_COUNT(sPwtTeamLance2) },
        [PWT_VARIANT_3] = { .mons = sPwtTeamLance3, .partySize = ARRAY_COUNT(sPwtTeamLance3) },
    },
    [PWT_TRAINER_STEVEN] =
    {
        [PWT_VARIANT_1] = { .mons = sPwtTeamSteven1, .partySize = ARRAY_COUNT(sPwtTeamSteven1) },
        [PWT_VARIANT_2] = { .mons = sPwtTeamSteven2, .partySize = ARRAY_COUNT(sPwtTeamSteven2) },
        [PWT_VARIANT_3] = { .mons = sPwtTeamSteven3, .partySize = ARRAY_COUNT(sPwtTeamSteven3) },
    },
    [PWT_TRAINER_WALLACE] =
    {
        [PWT_VARIANT_1] = { .mons = sPwtTeamWallace1, .partySize = ARRAY_COUNT(sPwtTeamWallace1) },
        [PWT_VARIANT_2] = { .mons = sPwtTeamWallace2, .partySize = ARRAY_COUNT(sPwtTeamWallace2) },
        [PWT_VARIANT_3] = { .mons = sPwtTeamWallace3, .partySize = ARRAY_COUNT(sPwtTeamWallace3) },
    },
    [PWT_TRAINER_CYNTHIA] =
    {
        [PWT_VARIANT_1] = { .mons = sPwtTeamCynthia1, .partySize = ARRAY_COUNT(sPwtTeamCynthia1) },
        [PWT_VARIANT_2] = { .mons = sPwtTeamCynthia2, .partySize = ARRAY_COUNT(sPwtTeamCynthia2) },
        [PWT_VARIANT_3] = { .mons = sPwtTeamCynthia3, .partySize = ARRAY_COUNT(sPwtTeamCynthia3) },
    },
    [PWT_TRAINER_ALDER] =
    {
        [PWT_VARIANT_1] = { .mons = sPwtTeamAlder1, .partySize = ARRAY_COUNT(sPwtTeamAlder1) },
        [PWT_VARIANT_2] = { .mons = sPwtTeamAlder2, .partySize = ARRAY_COUNT(sPwtTeamAlder2) },
        [PWT_VARIANT_3] = { .mons = sPwtTeamAlder3, .partySize = ARRAY_COUNT(sPwtTeamAlder3) },
    },
    [PWT_TRAINER_IRIS] =
    {
        [PWT_VARIANT_1] = { .mons = sPwtTeamIris1, .partySize = ARRAY_COUNT(sPwtTeamIris1) },
        [PWT_VARIANT_2] = { .mons = sPwtTeamIris2, .partySize = ARRAY_COUNT(sPwtTeamIris2) },
        [PWT_VARIANT_3] = { .mons = sPwtTeamIris3, .partySize = ARRAY_COUNT(sPwtTeamIris3) },
    },
    [PWT_TRAINER_DIANTHA] =
    {
        [PWT_VARIANT_1] = { .mons = sPwtTeamDiantha1, .partySize = ARRAY_COUNT(sPwtTeamDiantha1) },
        [PWT_VARIANT_2] = { .mons = sPwtTeamDiantha2, .partySize = ARRAY_COUNT(sPwtTeamDiantha2) },
        [PWT_VARIANT_3] = { .mons = sPwtTeamDiantha3, .partySize = ARRAY_COUNT(sPwtTeamDiantha3) },
    },
    [PWT_TRAINER_LEON] =
    {
        [PWT_VARIANT_1] = { .mons = sPwtTeamLeon1, .partySize = ARRAY_COUNT(sPwtTeamLeon1) },
        [PWT_VARIANT_2] = { .mons = sPwtTeamLeon2, .partySize = ARRAY_COUNT(sPwtTeamLeon2) },
        [PWT_VARIANT_3] = { .mons = sPwtTeamLeon3, .partySize = ARRAY_COUNT(sPwtTeamLeon3) },
    },
};

// Select the opponents for an entire tournament in one call.
// Selecting distinct trainer IDs (rather than variant IDs) ensures that
// no Champion appears twice with another team during the same run.
void ChoosePwtOpponents(struct PwtOpponent opponents[PWT_BATTLES_PER_TOURNAMENT])
{
    u8 available[PWT_TRAINERS_COUNT];
    u8 i;

    for (i = 0; i < PWT_TRAINERS_COUNT; i++)
        available[i] = i;

    // First three steps of Fisher-Yates: sample 3 unique Champions.
    for (i = 0; i < PWT_BATTLES_PER_TOURNAMENT; i++)
    {
        u8 pick = i + (Random() % (PWT_TRAINERS_COUNT - i));
        u8 trainerId = available[pick];

        available[pick] = available[i];
        available[i] = trainerId;

        opponents[i].trainerId = trainerId;
        opponents[i].variantId = Random() % PWT_VARIANTS_PER_TRAINER;
    }
}

const struct PwtTrainerParty *GetPwtOpponentParty(const struct PwtOpponent *opponent)
{
    const struct PwtTrainerParty *party;

    if (opponent == NULL
     || opponent->trainerId >= PWT_TRAINERS_COUNT
     || opponent->variantId >= PWT_VARIANTS_PER_TRAINER)
        return NULL;

    party = &gPwtTrainerParties[opponent->trainerId][opponent->variantId];

    // Reject incomplete or oversized parties: each PWT team must have 4 mons.
    if (party->partySize != PWT_MAX_PARTY_SIZE)
        return NULL;

    return party;
}
