#ifndef GUARD_PWT_TRAINER_MONS_H
#define GUARD_PWT_TRAINER_MONS_H

// Pokemon World Tournament - editable teams for the ten Champions.
//
// Each array below is a separate team. Add up to six struct TrainerMon
// entries to each array; gPwtTrainerParties automatically tracks its size.
//
// Fields available on struct TrainerMon include:
//   .species, .lvl, .moves, .heldItem, .ability, .nature,
//   .iv, .ev, .gender, .friendship, .isShiny, .ball, etc.
//
// TRAINER_PARTY_IVS / TRAINER_PARTY_EVS stat order:
//   HP, Attack, Defense, Speed, Sp. Attack, Sp. Defense
//
// All teams currently contain only one Litwick at level 5 as a placeholder.
// No PWT battles or facility logic are connected yet.

// Blue
static const struct TrainerMon sPwtTeamBlue[] =
{
    {
        .species = SPECIES_LITWICK,
        .lvl = 5,
        .moves = {MOVE_EMBER, MOVE_ASTONISH, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_NONE,
        .ability = ABILITY_FLASH_FIRE,
        .nature = NATURE_HARDY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 0, 0),
    },
};

// Red
static const struct TrainerMon sPwtTeamRed[] =
{
    {
        .species = SPECIES_LITWICK,
        .lvl = 5,
        .moves = {MOVE_EMBER, MOVE_ASTONISH, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_NONE,
        .ability = ABILITY_FLASH_FIRE,
        .nature = NATURE_HARDY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 0, 0),
    },
};

// Lance
static const struct TrainerMon sPwtTeamLance[] =
{
    {
        .species = SPECIES_LITWICK,
        .lvl = 5,
        .moves = {MOVE_EMBER, MOVE_ASTONISH, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_NONE,
        .ability = ABILITY_FLASH_FIRE,
        .nature = NATURE_HARDY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 0, 0),
    },
};

// Steven
static const struct TrainerMon sPwtTeamSteven[] =
{
    {
        .species = SPECIES_LITWICK,
        .lvl = 5,
        .moves = {MOVE_EMBER, MOVE_ASTONISH, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_NONE,
        .ability = ABILITY_FLASH_FIRE,
        .nature = NATURE_HARDY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 0, 0),
    },
};

// Wallace
static const struct TrainerMon sPwtTeamWallace[] =
{
    {
        .species = SPECIES_LITWICK,
        .lvl = 5,
        .moves = {MOVE_EMBER, MOVE_ASTONISH, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_NONE,
        .ability = ABILITY_FLASH_FIRE,
        .nature = NATURE_HARDY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 0, 0),
    },
};

// Cynthia
static const struct TrainerMon sPwtTeamCynthia[] =
{
    {
        .species = SPECIES_LITWICK,
        .lvl = 5,
        .moves = {MOVE_EMBER, MOVE_ASTONISH, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_NONE,
        .ability = ABILITY_FLASH_FIRE,
        .nature = NATURE_HARDY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 0, 0),
    },
};

// Alder
static const struct TrainerMon sPwtTeamAlder[] =
{
    {
        .species = SPECIES_LITWICK,
        .lvl = 5,
        .moves = {MOVE_EMBER, MOVE_ASTONISH, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_NONE,
        .ability = ABILITY_FLASH_FIRE,
        .nature = NATURE_HARDY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 0, 0),
    },
};

// Iris
static const struct TrainerMon sPwtTeamIris[] =
{
    {
        .species = SPECIES_LITWICK,
        .lvl = 5,
        .moves = {MOVE_EMBER, MOVE_ASTONISH, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_NONE,
        .ability = ABILITY_FLASH_FIRE,
        .nature = NATURE_HARDY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 0, 0),
    },
};

// Diantha
static const struct TrainerMon sPwtTeamDiantha[] =
{
    {
        .species = SPECIES_LITWICK,
        .lvl = 5,
        .moves = {MOVE_EMBER, MOVE_ASTONISH, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_NONE,
        .ability = ABILITY_FLASH_FIRE,
        .nature = NATURE_HARDY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 0, 0),
    },
};

// Leon
static const struct TrainerMon sPwtTeamLeon[] =
{
    {
        .species = SPECIES_LITWICK,
        .lvl = 5,
        .moves = {MOVE_EMBER, MOVE_ASTONISH, MOVE_NONE, MOVE_NONE},
        .heldItem = ITEM_NONE,
        .ability = ABILITY_FLASH_FIRE,
        .nature = NATURE_HARDY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 0, 0),
    },
};

#endif // GUARD_PWT_TRAINER_MONS_H
