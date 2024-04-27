#pragma once


// Enemies can do one of four things -
// - attack
// - self-item (heal, status)
// - allies item (heal, status)
// - enemy item (attack)
enum ActionEnum {
    ATTACK,
    SELF_ITEM,
    ALLIES_ITEM,
    ENEMY_ITEM
};