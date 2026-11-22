#ifndef GUARD_PWT_TRAINER_MONS_H
#define GUARD_PWT_TRAINER_MONS_H

// Pokemon World Tournament - 10 Champions, 3 variants per Champion.
// Each team must contain exactly FOUR Pokemon; 4 Litwick Lv. 5 are placeholders.
// Edit each Pokemon's species, level, moves, item, ability, nature, IVs and EVs.
// Team variants are numbered 1, 2, 3 for EVERY Champion (including Blue).
//
// TRAINER_PARTY_IVS / TRAINER_PARTY_EVS stat order:
//   HP, Attack, Defense, Speed, Sp. Attack, Sp. Defense
//
// These teams are independent of existing trainer parties.
// PWT battles / lobby have not yet been connected.

// Blue - Variant 1
static const struct TrainerMon sPwtTeamBlue1[] =
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

// Blue - Variant 2
static const struct TrainerMon sPwtTeamBlue2[] =
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

// Blue - Variant 3
static const struct TrainerMon sPwtTeamBlue3[] =
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

// Red - Variant 1
static const struct TrainerMon sPwtTeamRed1[] =
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

// Red - Variant 2
static const struct TrainerMon sPwtTeamRed2[] =
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

// Red - Variant 3
static const struct TrainerMon sPwtTeamRed3[] =
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

// Lance - Variant 1
static const struct TrainerMon sPwtTeamLance1[] =
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

// Lance - Variant 2
static const struct TrainerMon sPwtTeamLance2[] =
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

// Lance - Variant 3
static const struct TrainerMon sPwtTeamLance3[] =
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

// Steven - Variant 1
static const struct TrainerMon sPwtTeamSteven1[] =
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

// Steven - Variant 2
static const struct TrainerMon sPwtTeamSteven2[] =
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

// Steven - Variant 3
static const struct TrainerMon sPwtTeamSteven3[] =
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

// Wallace - Variant 1
static const struct TrainerMon sPwtTeamWallace1[] =
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

// Wallace - Variant 2
static const struct TrainerMon sPwtTeamWallace2[] =
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

// Wallace - Variant 3
static const struct TrainerMon sPwtTeamWallace3[] =
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

// Cynthia - Variant 1
static const struct TrainerMon sPwtTeamCynthia1[] =
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

// Cynthia - Variant 2
static const struct TrainerMon sPwtTeamCynthia2[] =
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

// Cynthia - Variant 3
static const struct TrainerMon sPwtTeamCynthia3[] =
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

// Alder - Variant 1
static const struct TrainerMon sPwtTeamAlder1[] =
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

// Alder - Variant 2
static const struct TrainerMon sPwtTeamAlder2[] =
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

// Alder - Variant 3
static const struct TrainerMon sPwtTeamAlder3[] =
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

// Iris - Variant 1
static const struct TrainerMon sPwtTeamIris1[] =
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

// Iris - Variant 2
static const struct TrainerMon sPwtTeamIris2[] =
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

// Iris - Variant 3
static const struct TrainerMon sPwtTeamIris3[] =
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

// Diantha - Variant 1
static const struct TrainerMon sPwtTeamDiantha1[] =
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

// Diantha - Variant 2
static const struct TrainerMon sPwtTeamDiantha2[] =
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

// Diantha - Variant 3
static const struct TrainerMon sPwtTeamDiantha3[] =
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

// Leon - Variant 1
static const struct TrainerMon sPwtTeamLeon1[] =
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

// Leon - Variant 2
static const struct TrainerMon sPwtTeamLeon2[] =
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

// Leon - Variant 3
static const struct TrainerMon sPwtTeamLeon3[] =
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
