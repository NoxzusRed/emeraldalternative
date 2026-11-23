#ifndef GUARD_PWT_TRAINER_MONS_H
#define GUARD_PWT_TRAINER_MONS_H

// Pokemon World Tournament - 3 variants per Champion.
// Each team must contain exactly FOUR Pokemon.
//
// TRAINER_PARTY_IVS / TRAINER_PARTY_EVS stat order:
//   HP, Attack, Defense, Speed, Sp. Attack, Sp. Defense

// Blue - Variant 1
static const struct TrainerMon sPwtTeamBlue1[] =
{
    {
        .species = SPECIES_VENUSAUR,
        .lvl = 50,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_SLEEP_POWDER, MOVE_LEECH_SEED},
        .heldItem = ITEM_BLACK_SLUDGE,
        .ability = ABILITY_OVERGROW,
        .nature = NATURE_BOLD,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 252, 0, 0, 4),
    },
    {
        .species = SPECIES_ARCANINE,
        .lvl = 50,
        .moves = {MOVE_FLARE_BLITZ, MOVE_EXTREME_SPEED, MOVE_CLOSE_COMBAT, MOVE_WILD_CHARGE},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .ability = ABILITY_INTIMIDATE,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 252, 0, 252, 0, 4),
    },
    {
        .species = SPECIES_TYRANITAR,
        .lvl = 50,
        .moves = {MOVE_STONE_EDGE, MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_SAND_STREAM,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
    {
        .species = SPECIES_ALAKAZAM,
        .lvl = 50,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_FOCUS_BLAST, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .ability = ABILITY_MAGIC_GUARD,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 0, 0, 252, 252, 4),
    },
};

// Blue - Variant 2
static const struct TrainerMon sPwtTeamBlue2[] =
{
    {
        .species = SPECIES_CHARIZARD,
        .lvl = 50,
        .moves = {MOVE_FLAMETHROWER, MOVE_AIR_SLASH, MOVE_FOCUS_BLAST, MOVE_ROOST},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .ability = ABILITY_BLAZE,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 0, 0, 252, 252, 4),
    },
    {
        .species = SPECIES_GYARADOS,
        .lvl = 50,
        .moves = {MOVE_DRAGON_DANCE, MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ICE_FANG},
        .heldItem = ITEM_LUM_BERRY,
        .ability = ABILITY_INTIMIDATE,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_EXEGGUTOR,
        .lvl = 50,
        .moves = {MOVE_GIGA_DRAIN, MOVE_PSYCHIC, MOVE_SLEEP_POWDER, MOVE_LEECH_SEED},
        .heldItem = ITEM_SITRUS_BERRY,
        .ability = ABILITY_HARVEST,
        .nature = NATURE_BOLD,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 252, 0, 4, 0),
    },
    {
        .species = SPECIES_HERACROSS,
        .lvl = 50,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_MEGAHORN, MOVE_STONE_EDGE, MOVE_KNOCK_OFF},
        .heldItem = ITEM_CHOICE_SCARF,
        .ability = ABILITY_MOXIE,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
};

// Blue - Variant 3
static const struct TrainerMon sPwtTeamBlue3[] =
{
    {
        .species = SPECIES_BLASTOISE,
        .lvl = 50,
        .moves = {MOVE_SHELL_SMASH, MOVE_SURF, MOVE_ICE_BEAM, MOVE_DARK_PULSE},
        .heldItem = ITEM_WHITE_HERB,
        .ability = ABILITY_TORRENT,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_RHYPERIOR,
        .lvl = 50,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_MEGAHORN, MOVE_ICE_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_SOLID_ROCK,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
    {
        .species = SPECIES_PIDGEOT,
        .lvl = 50,
        .moves = {MOVE_BRAVE_BIRD, MOVE_RETURN, MOVE_U_TURN, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_CHOICE_BAND,
        .ability = ABILITY_BIG_PECKS,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 252, 4, 252, 0, 0),
    },
    {
        .species = SPECIES_ALAKAZAM,
        .lvl = 50,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_FOCUS_BLAST, MOVE_NASTY_PLOT},
        .heldItem = ITEM_FOCUS_SASH,
        .ability = ABILITY_MAGIC_GUARD,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 0, 0, 252, 252, 4),
    },
};

// Red - Variant 1
static const struct TrainerMon sPwtTeamRed1[] =
{
    {
        .species = SPECIES_PIKACHU,
        .lvl = 50,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_SURF, MOVE_GRASS_KNOT},
        .heldItem = ITEM_LIGHT_BALL,
        .ability = ABILITY_STATIC,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_VENUSAUR,
        .lvl = 50,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_SLEEP_POWDER, MOVE_LEECH_SEED},
        .heldItem = ITEM_BLACK_SLUDGE,
        .ability = ABILITY_OVERGROW,
        .nature = NATURE_BOLD,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 252, 0, 0, 4),
    },
    {
        .species = SPECIES_LAPRAS,
        .lvl = 50,
        .moves = {MOVE_SURF, MOVE_FREEZE_DRY, MOVE_THUNDERBOLT, MOVE_PSYCHIC},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_WATER_ABSORB,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 252, 4),
    },
    {
        .species = SPECIES_SNORLAX,
        .lvl = 50,
        .moves = {MOVE_CURSE, MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_THICK_FAT,
        .nature = NATURE_CAREFUL,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 4, 0, 0, 0, 252),
    },
};

// Red - Variant 2
static const struct TrainerMon sPwtTeamRed2[] =
{
    {
        .species = SPECIES_PIKACHU,
        .lvl = 50,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_SURF, MOVE_GRASS_KNOT},
        .heldItem = ITEM_LIGHT_BALL,
        .ability = ABILITY_STATIC,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_CHARIZARD,
        .lvl = 50,
        .moves = {MOVE_FLAMETHROWER, MOVE_AIR_SLASH, MOVE_FOCUS_BLAST, MOVE_ROOST},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .ability = ABILITY_BLAZE,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 0, 0, 252, 252, 4),
    },
    {
        .species = SPECIES_LAPRAS,
        .lvl = 50,
        .moves = {MOVE_SURF, MOVE_FREEZE_DRY, MOVE_THUNDERBOLT, MOVE_PSYCHIC},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_WATER_ABSORB,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 252, 4),
    },
    {
        .species = SPECIES_SNORLAX,
        .lvl = 50,
        .moves = {MOVE_CURSE, MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_THICK_FAT,
        .nature = NATURE_CAREFUL,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 4, 0, 0, 0, 252),
    },
};

// Red - Variant 3
static const struct TrainerMon sPwtTeamRed3[] =
{
    {
        .species = SPECIES_PIKACHU,
        .lvl = 50,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_SURF, MOVE_GRASS_KNOT},
        .heldItem = ITEM_LIGHT_BALL,
        .ability = ABILITY_STATIC,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_BLASTOISE,
        .lvl = 50,
        .moves = {MOVE_SHELL_SMASH, MOVE_SURF, MOVE_ICE_BEAM, MOVE_DARK_PULSE},
        .heldItem = ITEM_WHITE_HERB,
        .ability = ABILITY_TORRENT,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_LAPRAS,
        .lvl = 50,
        .moves = {MOVE_SURF, MOVE_FREEZE_DRY, MOVE_THUNDERBOLT, MOVE_PSYCHIC},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_WATER_ABSORB,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 252, 4),
    },
    {
        .species = SPECIES_SNORLAX,
        .lvl = 50,
        .moves = {MOVE_CURSE, MOVE_BODY_SLAM, MOVE_EARTHQUAKE, MOVE_REST},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_THICK_FAT,
        .nature = NATURE_CAREFUL,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 4, 0, 0, 0, 252),
    },
};

// Lance - Variant 1
static const struct TrainerMon sPwtTeamLance1[] =
{
    {
         .species = SPECIES_FLYGON,
        .lvl = 50,
        .moves = {MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_U_TURN, MOVE_STONE_EDGE},
        .heldItem = ITEM_CHOICE_SCARF,
        .ability = ABILITY_LEVITATE,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_AMPHAROS,
        .lvl = 50,
        .moves = {MOVE_THUNDERBOLT, MOVE_DRAGON_PULSE, MOVE_FOCUS_BLAST, MOVE_VOLT_SWITCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_STATIC,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 252, 4),
    },
    {
        .species = SPECIES_DRAGONITE,
        .lvl = 50,
        .moves = {MOVE_DRAGON_DANCE, MOVE_DRAGON_CLAW, MOVE_EARTHQUAKE, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .ability = ABILITY_MULTISCALE,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_SALAMENCE,
        .lvl = 50,
        .moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_DUAL_WINGBEAT, MOVE_FIRE_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .ability = ABILITY_MOXIE,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
};

// Lance - Variant 2
static const struct TrainerMon sPwtTeamLance2[] =
{
    {
        .species = SPECIES_KINGDRA,
        .lvl = 50,
        .moves = {MOVE_DRACO_METEOR, MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_FLIP_TURN},
        .heldItem = ITEM_CHOICE_SPECS,
        .ability = ABILITY_SNIPER,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_SCEPTILE,
        .lvl = 50,
        .moves = {MOVE_LEAF_STORM, MOVE_DRAGON_PULSE, MOVE_FOCUS_BLAST, MOVE_GIGA_DRAIN},
        .heldItem = ITEM_LIFE_ORB,
        .ability = ABILITY_OVERGROW,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_DRAGONITE,
        .lvl = 50,
        .moves = {MOVE_DRAGON_DANCE, MOVE_DRAGON_CLAW, MOVE_EARTHQUAKE, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .ability = ABILITY_MULTISCALE,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_SALAMENCE,
        .lvl = 50,
        .moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_DUAL_WINGBEAT, MOVE_FIRE_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .ability = ABILITY_MOXIE,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
};

// Lance - Variant 3
static const struct TrainerMon sPwtTeamLance3[] =
{
    {
        .species = SPECIES_ARCHALUDON,
        .lvl = 50,
        .moves = {MOVE_IRON_DEFENSE, MOVE_BODY_PRESS, MOVE_FLASH_CANNON, MOVE_DRAGON_PULSE},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_STAMINA,
        .nature = NATURE_BOLD,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 252, 0, 4, 0),
    },
    {
         .species = SPECIES_DRAGALGE,
        .lvl = 50,
        .moves = {MOVE_DRACO_METEOR, MOVE_SLUDGE_WAVE, MOVE_HYDRO_PUMP, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_ADAPTABILITY,
        .nature = NATURE_HARDY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 252, 4),
    },
    {
        .species = SPECIES_DRAGONITE,
        .lvl = 50,
        .moves = {MOVE_DRAGON_DANCE, MOVE_DRAGON_CLAW, MOVE_EARTHQUAKE, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .ability = ABILITY_MULTISCALE,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_SALAMENCE,
        .lvl = 50,
        .moves = {MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_DUAL_WINGBEAT, MOVE_FIRE_FANG},
        .heldItem = ITEM_CHOICE_SCARF,
        .ability = ABILITY_MOXIE,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
};

// Steven - Variant 1
static const struct TrainerMon sPwtTeamSteven1[] =
{
    {
        .species = SPECIES_CLAYDOL,
        .lvl = 50,
        .moves = {MOVE_CALM_MIND, MOVE_EARTH_POWER, MOVE_PSYCHIC, MOVE_ICE_BEAM},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_LEVITATE,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 252, 4),
    },
    {
        .species = SPECIES_CARRACOSTA,
        .lvl = 50,
        .moves = {MOVE_SHELL_SMASH, MOVE_WATERFALL, MOVE_STONE_EDGE, MOVE_AQUA_JET},
        .heldItem = ITEM_WHITE_HERB,
        .ability = ABILITY_STURDY,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_METAGROSS,
        .lvl = 50,
        .moves = {MOVE_METEOR_MASH, MOVE_ZEN_HEADBUTT, MOVE_EARTHQUAKE, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_CLEAR_BODY,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
    {
        .species = SPECIES_AGGRON,
        .lvl = 50,
        .moves = {MOVE_STONE_EDGE, MOVE_IRON_HEAD, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH},
        .heldItem = ITEM_LIFE_ORB,
        .ability = ABILITY_FILTER,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
};

// Steven - Variant 2
static const struct TrainerMon sPwtTeamSteven2[] =
{
    {
        .species = SPECIES_SKARMORY,
        .lvl = 50,
        .moves = {MOVE_BRAVE_BIRD, MOVE_BODY_PRESS, MOVE_ROOST, MOVE_IRON_DEFENSE},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_STURDY,
        .nature = NATURE_IMPISH,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 252, 0, 0, 4),
    },
    {
        .species = SPECIES_ARMALDO,
        .lvl = 50,
        .moves = {MOVE_STONE_EDGE, MOVE_X_SCISSOR, MOVE_EARTHQUAKE, MOVE_AQUA_JET},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_BATTLE_ARMOR,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
    {
        .species = SPECIES_METAGROSS,
        .lvl = 50,
        .moves = {MOVE_METEOR_MASH, MOVE_ZEN_HEADBUTT, MOVE_EARTHQUAKE, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_CLEAR_BODY,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
    {
        .species = SPECIES_AGGRON,
        .lvl = 50,
        .moves = {MOVE_STONE_EDGE, MOVE_IRON_HEAD, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH},
        .heldItem = ITEM_LIFE_ORB,
        .ability = ABILITY_FILTER,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
};

// Steven - Variant 3
static const struct TrainerMon sPwtTeamSteven3[] =
{
    {
        .species = SPECIES_BASTIODON,
        .lvl = 50,
        .moves = {MOVE_IRON_DEFENSE, MOVE_BODY_PRESS, MOVE_HEAVY_SLAM, MOVE_STEALTH_ROCK},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_STURDY,
        .nature = NATURE_IMPISH,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 252, 0, 0, 4),
    },
    {
        .species = SPECIES_CRADILY,
        .lvl = 50,
        .moves = {MOVE_GIGA_DRAIN, MOVE_POWER_GEM, MOVE_RECOVER, MOVE_TOXIC},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_STORM_DRAIN,
        .nature = NATURE_CALM,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 4, 0, 0, 252),
    },
    {
        .species = SPECIES_METAGROSS,
        .lvl = 50,
        .moves = {MOVE_METEOR_MASH, MOVE_ZEN_HEADBUTT, MOVE_EARTHQUAKE, MOVE_BULLET_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_CLEAR_BODY,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
    {
        .species = SPECIES_AGGRON,
        .lvl = 50,
        .moves = {MOVE_STONE_EDGE, MOVE_IRON_HEAD, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH},
        .heldItem = ITEM_LIFE_ORB,
        .ability = ABILITY_FILTER,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
};

// Wallace - Variant 1
static const struct TrainerMon sPwtTeamWallace1[] =
{
    {
        .species = SPECIES_WALREIN,
        .lvl = 50,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_FREEZE_DRY, MOVE_EARTH_POWER},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_THICK_FAT,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 252, 4),
    },
    {
        .species = SPECIES_SHARPEDO,
        .lvl = 50,
        .moves = {MOVE_PROTECT, MOVE_CRUNCH, MOVE_LIQUIDATION, MOVE_PSYCHIC_FANGS},
        .heldItem = ITEM_LIFE_ORB,
        .ability = ABILITY_STRONG_JAW,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_MILOTIC,
        .lvl = 50,
        .moves = {MOVE_SCALD, MOVE_RECOVER, MOVE_ICE_BEAM, MOVE_HAZE},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_COMPETITIVE,
        .nature = NATURE_BOLD,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 252, 0, 0, 4),
    },
    {
        .species = SPECIES_LUDICOLO,
        .lvl = 50,
        .moves = {MOVE_RAIN_DANCE, MOVE_HYDRO_PUMP, MOVE_GIGA_DRAIN, MOVE_ICE_BEAM},
        .heldItem = ITEM_DAMP_ROCK,
        .ability = ABILITY_SWIFT_SWIM,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
};

// Wallace - Variant 2
static const struct TrainerMon sPwtTeamWallace2[] =
{
    {
        .species = SPECIES_WAILORD,
        .lvl = 50,
        .moves = {MOVE_WAVE_CRASH, MOVE_DOUBLE_EDGE, MOVE_AMNESIA, MOVE_NOBLE_ROAR},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_RECKLESS,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 4, 0, 0),
    },
    {
        .species = SPECIES_WHISCASH,
        .lvl = 50,
        .moves = {MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE, MOVE_WATERFALL, MOVE_STONE_EDGE},
        .heldItem = ITEM_LIFE_ORB,
        .ability = ABILITY_OBLIVIOUS,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_MILOTIC,
        .lvl = 50,
        .moves = {MOVE_SCALD, MOVE_RECOVER, MOVE_ICE_BEAM, MOVE_HAZE},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_COMPETITIVE,
        .nature = NATURE_BOLD,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 252, 0, 0, 4),
    },
    {
        .species = SPECIES_LUDICOLO,
        .lvl = 50,
        .moves = {MOVE_RAIN_DANCE, MOVE_HYDRO_PUMP, MOVE_GIGA_DRAIN, MOVE_ICE_BEAM},
        .heldItem = ITEM_DAMP_ROCK,
        .ability = ABILITY_SWIFT_SWIM,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
};

// Wallace - Variant 3
static const struct TrainerMon sPwtTeamWallace3[] =
{
    {
        .species = SPECIES_GYARADOS,
        .lvl = 50,
        .moves = {MOVE_DRAGON_DANCE, MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_ICE_FANG},
        .heldItem = ITEM_LUM_BERRY,
        .ability = ABILITY_INTIMIDATE,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_HUNTAIL,
        .lvl = 50,
        .moves = {MOVE_SHELL_SMASH, MOVE_WATERFALL, MOVE_CRUNCH, MOVE_ICE_FANG},
        .heldItem = ITEM_WHITE_HERB,
        .ability = ABILITY_WATER_VEIL,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_MILOTIC,
        .lvl = 50,
        .moves = {MOVE_SCALD, MOVE_RECOVER, MOVE_ICE_BEAM, MOVE_HAZE},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_COMPETITIVE,
        .nature = NATURE_BOLD,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 252, 0, 0, 4),
    },
    {
        .species = SPECIES_LUDICOLO,
        .lvl = 50,
        .moves = {MOVE_RAIN_DANCE, MOVE_HYDRO_PUMP, MOVE_GIGA_DRAIN, MOVE_ICE_BEAM},
        .heldItem = ITEM_DAMP_ROCK,
        .ability = ABILITY_SWIFT_SWIM,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
};

// Cynthia - Variant 1
static const struct TrainerMon sPwtTeamCynthia1[] =
{
    {
        .species = SPECIES_LUCARIO,
        .lvl = 50,
        .moves = {MOVE_SWORDS_DANCE, MOVE_CLOSE_COMBAT, MOVE_METEOR_MASH, MOVE_EXTREME_SPEED},
        .heldItem = ITEM_LIFE_ORB,
        .ability = ABILITY_JUSTIFIED,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_SPIRITOMB,
        .lvl = 50,
        .moves = {MOVE_CALM_MIND, MOVE_DARK_PULSE, MOVE_WILL_O_WISP, MOVE_PAIN_SPLIT},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_PRESSURE,
        .nature = NATURE_BOLD,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 252, 0, 0, 4),
    },
    {
        .species = SPECIES_TOGEKISS,
        .lvl = 50,
        .moves = {MOVE_AIR_SLASH, MOVE_THUNDER_WAVE, MOVE_DAZZLING_GLEAM, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_SERENE_GRACE,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_GARCHOMP,
        .lvl = 50,
        .moves = {MOVE_SWORDS_DANCE, MOVE_EARTHQUAKE, MOVE_DRAGON_CLAW, MOVE_POISON_JAB},
        .heldItem = ITEM_LIFE_ORB,
        .ability = ABILITY_ROUGH_SKIN,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
};

// Cynthia - Variant 2
static const struct TrainerMon sPwtTeamCynthia2[] =
{
    {
        .species = SPECIES_ROSERADE,
        .lvl = 50,
        .moves = {MOVE_LEAF_STORM, MOVE_SLUDGE_BOMB, MOVE_SHADOW_BALL, MOVE_SLEEP_POWDER},
        .heldItem = ITEM_LIFE_ORB,
        .ability = ABILITY_NATURAL_CURE,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_MILOTIC,
        .lvl = 50,
        .moves = {MOVE_SCALD, MOVE_RECOVER, MOVE_ICE_BEAM, MOVE_HAZE},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_COMPETITIVE,
        .nature = NATURE_BOLD,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 252, 0, 0, 4),
    },
    {
        .species = SPECIES_TOGEKISS,
        .lvl = 50,
        .moves = {MOVE_AIR_SLASH, MOVE_THUNDER_WAVE, MOVE_DAZZLING_GLEAM, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_SERENE_GRACE,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_GARCHOMP,
        .lvl = 50,
        .moves = {MOVE_SWORDS_DANCE, MOVE_EARTHQUAKE, MOVE_DRAGON_CLAW, MOVE_POISON_JAB},
        .heldItem = ITEM_LIFE_ORB,
        .ability = ABILITY_ROUGH_SKIN,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
};

// Cynthia - Variant 3
static const struct TrainerMon sPwtTeamCynthia3[] =
{
    {
        .species = SPECIES_PORYGON_Z,
        .lvl = 50,
        .moves = {MOVE_TRI_ATTACK, MOVE_DARK_PULSE, MOVE_THUNDERBOLT, MOVE_PSYCHIC},
        .heldItem = ITEM_CHOICE_SCARF,
        .ability = ABILITY_ADAPTABILITY,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_GLACEON,
        .lvl = 50,
        .moves = {MOVE_ICE_BEAM, MOVE_FREEZE_DRY, MOVE_SHADOW_BALL, MOVE_WATER_PULSE},
        .heldItem = ITEM_CHOICE_SPECS,
        .ability = ABILITY_SNOW_CLOAK,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 252, 4),
    },
    {
        .species = SPECIES_TOGEKISS,
        .lvl = 50,
        .moves = {MOVE_AIR_SLASH, MOVE_THUNDER_WAVE, MOVE_DAZZLING_GLEAM, MOVE_ROOST},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_SERENE_GRACE,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_GARCHOMP,
        .lvl = 50,
        .moves = {MOVE_SWORDS_DANCE, MOVE_EARTHQUAKE, MOVE_DRAGON_CLAW, MOVE_POISON_JAB},
        .heldItem = ITEM_LIFE_ORB,
        .ability = ABILITY_ROUGH_SKIN,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
};

// Alder - Variant 1
static const struct TrainerMon sPwtTeamAlder1[] =
{
    {
        .species = SPECIES_CONKELDURR,
        .lvl = 50,
        .moves = {MOVE_DRAIN_PUNCH, MOVE_MACH_PUNCH, MOVE_KNOCK_OFF, MOVE_FACADE},
        .heldItem = ITEM_FLAME_ORB,
        .ability = ABILITY_GUTS,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
    {
        .species = SPECIES_BRAVIARY,
        .lvl = 50,
        .moves = {MOVE_BRAVE_BIRD, MOVE_CLOSE_COMBAT, MOVE_U_TURN, MOVE_ROCK_SLIDE},
        .heldItem = ITEM_CHOICE_SCARF,
        .ability = ABILITY_DEFIANT,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_VOLCARONA,
        .lvl = 50,
        .moves = {MOVE_QUIVER_DANCE, MOVE_FIERY_DANCE, MOVE_BUG_BUZZ, MOVE_GIGA_DRAIN},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .ability = ABILITY_FLAME_BODY,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_BOUFFALANT,
        .lvl = 50,
        .moves = {MOVE_HEAD_CHARGE, MOVE_EARTHQUAKE, MOVE_MEGAHORN, MOVE_WILD_CHARGE},
        .heldItem = ITEM_CHOICE_BAND,
        .ability = ABILITY_RECKLESS,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
};

// Alder - Variant 2
static const struct TrainerMon sPwtTeamAlder2[] =
{
    {
        .species = SPECIES_ACCELGOR,
        .lvl = 50,
        .moves = {MOVE_BUG_BUZZ, MOVE_FOCUS_BLAST, MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB},
        .heldItem = ITEM_FOCUS_SASH,
        .ability = ABILITY_UNBURDEN,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_CHANDELURE,
        .lvl = 50,
        .moves = {MOVE_SHADOW_BALL, MOVE_FLAMETHROWER, MOVE_ENERGY_BALL, MOVE_PSYCHIC},
        .heldItem = ITEM_CHOICE_SCARF,
        .ability = ABILITY_FLAME_BODY,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_VOLCARONA,
        .lvl = 50,
        .moves = {MOVE_QUIVER_DANCE, MOVE_FIERY_DANCE, MOVE_BUG_BUZZ, MOVE_GIGA_DRAIN},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .ability = ABILITY_FLAME_BODY,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_BOUFFALANT,
        .lvl = 50,
        .moves = {MOVE_HEAD_CHARGE, MOVE_EARTHQUAKE, MOVE_MEGAHORN, MOVE_WILD_CHARGE},
        .heldItem = ITEM_CHOICE_BAND,
        .ability = ABILITY_RECKLESS,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
};

// Alder - Variant 3
static const struct TrainerMon sPwtTeamAlder3[] =
{
    {
        .species = SPECIES_ESCAVALIER,
        .lvl = 50,
        .moves = {MOVE_MEGAHORN, MOVE_IRON_HEAD, MOVE_KNOCK_OFF, MOVE_DRILL_RUN},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_OVERCOAT,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
    {
        .species = SPECIES_VANILLUXE,
        .lvl = 50,
        .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY, MOVE_FLASH_CANNON, MOVE_AURORA_VEIL},
        .heldItem = ITEM_LIGHT_CLAY,
        .ability = ABILITY_SNOW_WARNING,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_VOLCARONA,
        .lvl = 50,
        .moves = {MOVE_QUIVER_DANCE, MOVE_FIERY_DANCE, MOVE_BUG_BUZZ, MOVE_GIGA_DRAIN},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .ability = ABILITY_FLAME_BODY,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_BOUFFALANT,
        .lvl = 50,
        .moves = {MOVE_HEAD_CHARGE, MOVE_EARTHQUAKE, MOVE_MEGAHORN, MOVE_WILD_CHARGE},
        .heldItem = ITEM_CHOICE_BAND,
        .ability = ABILITY_RECKLESS,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
};

// Iris - Variant 1
static const struct TrainerMon sPwtTeamIris1[] =
{
    {
        .species = SPECIES_ARCHEOPS,
        .lvl = 50,
        .moves = {MOVE_STONE_EDGE, MOVE_DUAL_WINGBEAT, MOVE_EARTHQUAKE, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .ability = ABILITY_DEFEATIST,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_LAPRAS,
        .lvl = 50,
        .moves = {MOVE_SURF, MOVE_FREEZE_DRY, MOVE_THUNDERBOLT, MOVE_PSYCHIC},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_WATER_ABSORB,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 252, 4),
    },
    {
        .species = SPECIES_HYDREIGON,
        .lvl = 50,
        .moves = {MOVE_DRACO_METEOR, MOVE_DARK_PULSE, MOVE_FLAMETHROWER, MOVE_FLASH_CANNON},
        .heldItem = ITEM_CHOICE_SPECS,
        .ability = ABILITY_LEVITATE,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_HAXORUS,
        .lvl = 50,
        .moves = {MOVE_DRAGON_DANCE, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_POISON_JAB},
        .heldItem = ITEM_LUM_BERRY,
        .ability = ABILITY_MOLD_BREAKER,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
};

// Iris - Variant 2
static const struct TrainerMon sPwtTeamIris2[] =
{
    {
        .species = SPECIES_AGGRON,
        .lvl = 50,
        .moves = {MOVE_HEAD_SMASH, MOVE_HEAVY_SLAM, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .ability = ABILITY_ROCK_HEAD,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
    {
        .species = SPECIES_DRUDDIGON,
        .lvl = 50,
        .moves = {MOVE_DRAGON_CLAW, MOVE_EARTHQUAKE, MOVE_FIRE_PUNCH, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_ROUGH_SKIN,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
    {
        .species = SPECIES_HYDREIGON,
        .lvl = 50,
        .moves = {MOVE_DRACO_METEOR, MOVE_DARK_PULSE, MOVE_FLAMETHROWER, MOVE_FLASH_CANNON},
        .heldItem = ITEM_CHOICE_SPECS,
        .ability = ABILITY_LEVITATE,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_HAXORUS,
        .lvl = 50,
        .moves = {MOVE_DRAGON_DANCE, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_POISON_JAB},
        .heldItem = ITEM_LUM_BERRY,
        .ability = ABILITY_MOLD_BREAKER,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
};

// Iris - Variant 3
static const struct TrainerMon sPwtTeamIris3[] =
{
    {
        .species = SPECIES_EXCADRILL,
        .lvl = 50,
        .moves = {MOVE_SWORDS_DANCE, MOVE_EARTHQUAKE, MOVE_IRON_HEAD, MOVE_ROCK_SLIDE},
        .heldItem = ITEM_LIFE_ORB,
        .ability = ABILITY_MOLD_BREAKER,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_EMOLGA,
        .lvl = 50,
        .moves = {MOVE_THUNDERBOLT, MOVE_AIR_SLASH, MOVE_VOLT_SWITCH, MOVE_ENCORE},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .ability = ABILITY_MOTOR_DRIVE,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_HYDREIGON,
        .lvl = 50,
        .moves = {MOVE_DRACO_METEOR, MOVE_DARK_PULSE, MOVE_FLAMETHROWER, MOVE_FLASH_CANNON},
        .heldItem = ITEM_CHOICE_SPECS,
        .ability = ABILITY_LEVITATE,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_HAXORUS,
        .lvl = 50,
        .moves = {MOVE_DRAGON_DANCE, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_POISON_JAB},
        .heldItem = ITEM_LUM_BERRY,
        .ability = ABILITY_MOLD_BREAKER,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
};

// Diantha - Variant 1
static const struct TrainerMon sPwtTeamDiantha1[] =
{
    {
        .species = SPECIES_HAWLUCHA,
        .lvl = 50,
        .moves = {MOVE_SWORDS_DANCE, MOVE_CLOSE_COMBAT, MOVE_ACROBATICS, MOVE_STONE_EDGE},
        .heldItem = ITEM_WHITE_HERB,
        .ability = ABILITY_UNBURDEN,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_TYRANTRUM,
        .lvl = 50,
        .moves = {MOVE_HEAD_SMASH, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_CLOSE_COMBAT},
        .heldItem = ITEM_CHOICE_SCARF,
        .ability = ABILITY_ROCK_HEAD,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_GOODRA,
        .lvl = 50,
        .moves = {MOVE_DRACO_METEOR, MOVE_FLAMETHROWER, MOVE_THUNDERBOLT, MOVE_SURF},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_SAP_SIPPER,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 252, 4),
    },
    {
        .species = SPECIES_GARDEVOIR,
        .lvl = 50,
        .moves = {MOVE_MOONBLAST, MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHOICE_SCARF,
        .ability = ABILITY_TRACE,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
};

// Diantha - Variant 2
static const struct TrainerMon sPwtTeamDiantha2[] =
{
    {
        .species = SPECIES_GOURGEIST,
        .lvl = 50,
        .moves = {MOVE_POLTERGEIST, MOVE_POWER_WHIP, MOVE_WILL_O_WISP, MOVE_SYNTHESIS},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_FRISK,
        .nature = NATURE_IMPISH,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 252, 0, 0, 4),
    },
    {
        .species = SPECIES_AURORUS,
        .lvl = 50,
        .moves = {MOVE_HYPER_VOICE, MOVE_FREEZE_DRY, MOVE_EARTH_POWER, MOVE_POWER_GEM},
        .heldItem = ITEM_CHOICE_SPECS,
        .ability = ABILITY_REFRIGERATE,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_GOODRA,
        .lvl = 50,
        .moves = {MOVE_DRACO_METEOR, MOVE_FLAMETHROWER, MOVE_THUNDERBOLT, MOVE_SURF},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_SAP_SIPPER,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 252, 4),
    },
    {
        .species = SPECIES_GARDEVOIR,
        .lvl = 50,
        .moves = {MOVE_MOONBLAST, MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHOICE_SCARF,
        .ability = ABILITY_TRACE,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
};

// Diantha - Variant 3
static const struct TrainerMon sPwtTeamDiantha3[] =
{
    {
        .species = SPECIES_TYRANTRUM,
        .lvl = 50,
        .moves = {MOVE_HEAD_SMASH, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_CLOSE_COMBAT},
        .heldItem = ITEM_CHOICE_SCARF,
        .ability = ABILITY_ROCK_HEAD,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_AURORUS,
        .lvl = 50,
        .moves = {MOVE_HYPER_VOICE, MOVE_FREEZE_DRY, MOVE_EARTH_POWER, MOVE_POWER_GEM},
        .heldItem = ITEM_CHOICE_SPECS,
        .ability = ABILITY_REFRIGERATE,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_GOODRA,
        .lvl = 50,
        .moves = {MOVE_DRACO_METEOR, MOVE_FLAMETHROWER, MOVE_THUNDERBOLT, MOVE_SURF},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_SAP_SIPPER,
        .nature = NATURE_MODEST,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 252, 4),
    },
    {
        .species = SPECIES_GARDEVOIR,
        .lvl = 50,
        .moves = {MOVE_MOONBLAST, MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_FOCUS_BLAST},
        .heldItem = ITEM_CHOICE_SCARF,
        .ability = ABILITY_TRACE,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
};

// Leon - Variant 1
static const struct TrainerMon sPwtTeamLeon1[] =
{
    {
        .species = SPECIES_RILLABOOM,
        .lvl = 50,
        .moves = {MOVE_GRASSY_GLIDE, MOVE_WOOD_HAMMER, MOVE_KNOCK_OFF, MOVE_U_TURN},
        .heldItem = ITEM_CHOICE_BAND,
        .ability = ABILITY_GRASSY_SURGE,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_SEISMITOAD,
        .lvl = 50,
        .moves = {MOVE_LIQUIDATION, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_POWER_WHIP},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_WATER_ABSORB,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
    {
        .species = SPECIES_AEGISLASH,
        .lvl = 50,
        .moves = {MOVE_KINGS_SHIELD, MOVE_SWORDS_DANCE, MOVE_SHADOW_SNEAK, MOVE_SACRED_SWORD},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_STANCE_CHANGE,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
    {
        .species = SPECIES_CHARIZARD,
        .lvl = 50,
        .moves = {MOVE_DRAGON_DANCE, MOVE_FLARE_BLITZ, MOVE_DUAL_WINGBEAT, MOVE_EARTHQUAKE},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .ability = ABILITY_BLAZE,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
};

// Leon - Variant 2
static const struct TrainerMon sPwtTeamLeon2[] =
{
    {
        .species = SPECIES_CINDERACE,
        .lvl = 50,
        .moves = {MOVE_PYRO_BALL, MOVE_HIGH_JUMP_KICK, MOVE_U_TURN, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_LIFE_ORB,
        .ability = ABILITY_LIBERO,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_DRAGAPULT,
        .lvl = 50,
        .moves = {MOVE_DRAGON_DARTS, MOVE_PHANTOM_FORCE, MOVE_U_TURN, MOVE_SUCKER_PUNCH},
        .heldItem = ITEM_CHOICE_BAND,
        .ability = ABILITY_INFILTRATOR,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
    {
        .species = SPECIES_AEGISLASH,
        .lvl = 50,
        .moves = {MOVE_KINGS_SHIELD, MOVE_SWORDS_DANCE, MOVE_SHADOW_SNEAK, MOVE_SACRED_SWORD},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_STANCE_CHANGE,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
    {
        .species = SPECIES_CHARIZARD,
        .lvl = 50,
        .moves = {MOVE_DRAGON_DANCE, MOVE_FLARE_BLITZ, MOVE_DUAL_WINGBEAT, MOVE_EARTHQUAKE},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .ability = ABILITY_BLAZE,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
};

// Leon - Variant 3
static const struct TrainerMon sPwtTeamLeon3[] =
{
    {
        .species = SPECIES_INTELEON,
        .lvl = 50,
        .moves = {MOVE_FOCUS_ENERGY, MOVE_SNIPE_SHOT, MOVE_ICE_BEAM, MOVE_DARK_PULSE},
        .heldItem = ITEM_SCOPE_LENS,
        .ability = ABILITY_SNIPER,
        .nature = NATURE_TIMID,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
    },
    {
        .species = SPECIES_RHYPERIOR,
        .lvl = 50,
        .moves = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_MEGAHORN, MOVE_ICE_PUNCH},
        .heldItem = ITEM_ASSAULT_VEST,
        .ability = ABILITY_SOLID_ROCK,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
    {
        .species = SPECIES_AEGISLASH,
        .lvl = 50,
        .moves = {MOVE_KINGS_SHIELD, MOVE_SWORDS_DANCE, MOVE_SHADOW_SNEAK, MOVE_SACRED_SWORD},
        .heldItem = ITEM_LEFTOVERS,
        .ability = ABILITY_STANCE_CHANGE,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
    },
    {
        .species = SPECIES_CHARIZARD,
        .lvl = 50,
        .moves = {MOVE_DRAGON_DANCE, MOVE_FLARE_BLITZ, MOVE_DUAL_WINGBEAT, MOVE_EARTHQUAKE},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .ability = ABILITY_BLAZE,
        .nature = NATURE_JOLLY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
    },
};

#endif // GUARD_PWT_TRAINER_MONS_H
