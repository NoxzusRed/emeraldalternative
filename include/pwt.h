#ifndef GUARD_PWT_H
#define GUARD_PWT_H

#include "data.h"

// Pokemon World Tournament (PWT) trainer IDs.
// These IDs are independent from the regular trainer and Battle Frontier IDs.
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

#define PWT_MAX_PARTY_SIZE 6

// The actual team size is calculated from each team's array.
// For now each trainer has only one placeholder Pokemon.
struct PwtTrainerParty
{
    const struct TrainerMon *mons;
    u8 partySize;
};

extern const struct PwtTrainerParty gPwtTrainerParties[PWT_TRAINERS_COUNT];

#endif // GUARD_PWT_H
