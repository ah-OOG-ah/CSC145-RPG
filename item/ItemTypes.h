#pragma once


struct ItemProps {
    bool good;
    bool group;
    bool inst;
};

enum ItemType {
    NONE,
    ATTACK,
    HEAL,
    STATUS,
    WEAPON,
    ARMOR
};