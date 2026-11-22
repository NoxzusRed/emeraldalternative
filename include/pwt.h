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

// Three different Blue teams. All variants represent the same trainer ID.
enum PwtBlueVariant
{
    PWT_BLUE_VENUSAUR,
    PWT_BLUE_CHARIZARD,
    PWT_BLUE_BLASTOISE,
    PWT_BLUE_VARIANT_COUNT
};

#define PWT_MAX_PARTY_SIZE 6
#define PWT_BATTLES_PER_TOURNAMENT 3

// The actual team size is calculated from each team's array.
// All teams currently contain Litwick level 5 placeholders.
struct PwtTrainerParty
{
    const struct TrainerMon *mons;
    u8 partySize;
};

// One unique trainer ID per champion, regardless of how many teams they have.
// Only the Blue variant table contains multiple selectable parties.
struct PwtOpponent
{
    u8 trainerId;  // enum PwtTrainerId
    u8 variantId;  // enum PwtBlueVariant for Blue; 0 for everyone else
};

extern const struct PwtTrainerParty gPwtTrainerParties[PWT_TRAINERS_COUNT];
extern const struct PwtTrainerParty gPwtBlueVariants[PWT_BLUE_VARIANT_COUNT];

// Choose all three opponents ONCE at the beginning of a tournament.
// Trainer IDs will always be distinct (so Blue can never be fought twice).
// The caller must preserve the resulting array across the three matches.
void ChoosePwtOpponents(struct PwtOpponent opponents[PWT_BATTLES_PER_TOURNAMENT]);

// Resolve the actual party from a selected opponent + team variant.
const struct PwtTrainerParty *GetPwtOpponentParty(const struct PwtOpponent *opponent);

#endif // GUARD_PWT_H
