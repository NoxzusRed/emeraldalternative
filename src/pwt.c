#include "global.h"
#include "pwt.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/species.h"

#include "data/battle_frontier/pwt_trainer_mons.h"

// Independent PWT team registry. The facility will use this table when
// its battle flow is implemented; for now it does not affect other modes.
const struct PwtTrainerParty gPwtTrainerParties[PWT_TRAINERS_COUNT] =
{
    [PWT_TRAINER_BLUE]    = { .mons = sPwtTeamBlue,    .partySize = ARRAY_COUNT(sPwtTeamBlue) },
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
