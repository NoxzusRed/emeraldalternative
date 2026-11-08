#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_METAL_BURST) == EFFECT_METAL_BURST);
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
}

SINGLE_BATTLE_TEST("Metal Burst returns 1.5 times the last physical or special damage taken")
{
    u32 incomingMove;
    s16 damageTaken;
    s16 damageReturned;

    PARAMETRIZE { incomingMove = MOVE_SCRATCH; }
    PARAMETRIZE { incomingMove = MOVE_WATER_GUN; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, incomingMove); MOVE(player, MOVE_METAL_BURST); }
    } SCENE {
        HP_BAR(player, captureDamage: &damageTaken);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_BURST, player);
        HP_BAR(opponent, captureDamage: &damageReturned);
    } THEN {
        EXPECT_EQ(damageReturned, damageTaken * 150 / 100);
    }
}

SINGLE_BATTLE_TEST("Metal Burst fails when used before taking damage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_METAL_BURST); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet used Metal Burst!");
        MESSAGE("But it failed!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_BURST, player);
    }
}

DOUBLE_BATTLE_TEST("Metal Burst hits the damaging foe, not the initially selected foe")
{
    s16 damageTaken;
    s16 damageReturned;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WYNAUT) { Speed(9); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft);
            MOVE(opponentRight, MOVE_CELEBRATE);
            MOVE(playerLeft, MOVE_METAL_BURST, target: opponentRight);
            MOVE(playerRight, MOVE_CELEBRATE);
        }
    } SCENE {
        HP_BAR(playerLeft, captureDamage: &damageTaken);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_BURST, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damageReturned);
        NONE_OF {
            HP_BAR(opponentRight);
        }
    } THEN {
        EXPECT_EQ(damageReturned, damageTaken * 150 / 100);
    }
}

DOUBLE_BATTLE_TEST("Metal Burst uses the last hit even if the damage category changes")
{
    u32 firstMove;
    u32 lastMove;
    s16 lastDamageTaken;
    s16 damageReturned;

    PARAMETRIZE { firstMove = MOVE_SCRATCH; lastMove = MOVE_WATER_GUN; }
    PARAMETRIZE { firstMove = MOVE_WATER_GUN; lastMove = MOVE_SCRATCH; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WYNAUT) { Speed(9); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, firstMove, target: playerLeft);
            MOVE(opponentRight, lastMove, target: playerLeft);
            MOVE(playerLeft, MOVE_METAL_BURST, target: opponentLeft);
            MOVE(playerRight, MOVE_CELEBRATE);
        }
    } SCENE {
        HP_BAR(playerLeft);
        HP_BAR(playerLeft, captureDamage: &lastDamageTaken);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_BURST, playerLeft);
        HP_BAR(opponentRight, captureDamage: &damageReturned);
        NONE_OF {
            HP_BAR(opponentLeft);
        }
    } THEN {
        EXPECT_EQ(damageReturned, lastDamageTaken * 150 / 100);
    }
}

DOUBLE_BATTLE_TEST("Metal Burst remembers the last opposing hit even if an ally attacks later")
{
    s16 damageTaken;
    s16 damageReturned;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(8); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WYNAUT) { Speed(9); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft);
            MOVE(playerRight, MOVE_SCRATCH, target: playerLeft);
            MOVE(playerLeft, MOVE_METAL_BURST, target: opponentRight);
            MOVE(opponentRight, MOVE_CELEBRATE);
        }
    } SCENE {
        HP_BAR(playerLeft, captureDamage: &damageTaken);
        HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_BURST, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damageReturned);
        NONE_OF {
            HP_BAR(playerRight);
            HP_BAR(opponentRight);
        }
    } THEN {
        EXPECT_EQ(damageReturned, damageTaken * 150 / 100);
    }
}

DOUBLE_BATTLE_TEST("Metal Burst fails if only an ally damaged the user")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(9); }
        OPPONENT(SPECIES_WYNAUT) { Speed(8); }
    } WHEN {
        TURN {
            MOVE(playerRight, MOVE_SCRATCH, target: playerLeft);
            MOVE(opponentLeft, MOVE_CELEBRATE);
            MOVE(opponentRight, MOVE_CELEBRATE);
            MOVE(playerLeft, MOVE_METAL_BURST, target: opponentLeft);
        }
    } SCENE {
        HP_BAR(playerLeft);
        MESSAGE("Wobbuffet used Metal Burst!");
        MESSAGE("But it failed!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_BURST, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Metal Burst redirects to the remaining opponent if the last attacker faints")
{
    s16 damageTaken;
    s16 damageReturned;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft);
            MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft);
            MOVE(playerLeft, MOVE_METAL_BURST, target: opponentRight);
            MOVE(opponentRight, MOVE_CELEBRATE);
        }
    } SCENE {
        HP_BAR(playerLeft, captureDamage: &damageTaken);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_BURST, playerLeft);
        HP_BAR(opponentRight, captureDamage: &damageReturned);
    } THEN {
        EXPECT_EQ(damageReturned, damageTaken * 150 / 100);
    }
}

SINGLE_BATTLE_TEST("Metal Burst returns only the final strike of a multi-hit move")
{
    s16 damageTaken[5];
    s16 damageReturned;

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BULLET_SEED) == EFFECT_MULTI_HIT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); Ability(ABILITY_SKILL_LINK); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_BULLET_SEED); MOVE(player, MOVE_METAL_BURST); }
    } SCENE {
        HP_BAR(player, captureDamage: &damageTaken[0]);
        HP_BAR(player, captureDamage: &damageTaken[1]);
        HP_BAR(player, captureDamage: &damageTaken[2]);
        HP_BAR(player, captureDamage: &damageTaken[3]);
        HP_BAR(player, captureDamage: &damageTaken[4]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_BURST, player);
        HP_BAR(opponent, captureDamage: &damageReturned);
    } THEN {
        EXPECT_EQ(damageReturned, damageTaken[4] * 150 / 100);
    }
}

SINGLE_BATTLE_TEST("Metal Burst fails if the opposing attack only hits Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_SUBSTITUTE); }
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_METAL_BURST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Wobbuffet used Metal Burst!");
        MESSAGE("But it failed!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_BURST, player);
    }
}

