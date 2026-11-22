#ifndef GUARD_PWT_H
#define GUARD_PWT_H

#include "data.h"

// A Champion has exactly one trainer ID, regardless of team variant.
// IDs are independent of normal trainers and other Battle Frontier modes.
enum PwtTrainerId
{
    PWT_TRAINER_BLUE,
    PWT_TRAINER_RED,
    PWT_TRAINER_LANCE,
    PWT_TRAINER_STEVEN,
    PWT_TRAINER_WALLACE,
    PWT_TRAINER_CYNTHIA,
    PWT_TRAINER_ALDER,
    PWT_TRAINER_IRIS,
    PWT_TRAINER_DIANTHA,
    PWT_TRAINER_LEON,
    PWT_TRAINERS_COUNT
};

// All Champions have three numbered, editable team variants.
// The enum starts at 0 for C array indexing, but teams are named 1, 2, 3.
enum PwtTeamVariant
{
    PWT_VARIANT_1,
    PWT_VARIANT_2,
    PWT_VARIANT_3,
    PWT_VARIANTS_PER_TRAINER
};

#define PWT_MAX_PARTY_SIZE 4
#define PWT_BATTLES_PER_TOURNAMENT 3

struct PwtTrainerParty
{
    const struct TrainerMon *mons;
    u8 partySize;
};

// Store one of these for each battle in a run. Keep the entire selection
// unchanged between fights (and persist it if saving/resuming is added).
struct PwtOpponent
{
    u8 trainerId; // PwtTrainerId
    u8 variantId; // PwtTeamVariant
};

extern const struct PwtTrainerParty gPwtTrainerParties[PWT_TRAINERS_COUNT][PWT_VARIANTS_PER_TRAINER];

// Pick 3 different Champions; independently choose one of 3 variants for each.
// Call ONCE per tournament, not before each battle.
void ChoosePwtOpponents(struct PwtOpponent opponents[PWT_BATTLES_PER_TOURNAMENT]);

// Return the 4-Pokemon party for the selected Champion/variant.
const struct PwtTrainerParty *GetPwtOpponentParty(const struct PwtOpponent *opponent);

#endif // GUARD_PWT_H
