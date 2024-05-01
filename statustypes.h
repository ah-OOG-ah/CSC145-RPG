#pragma once

#include "Status.h"


namespace stypes {

    void poisonEffect(Entity *victim, Status *ailment); //Reduces health by 10 each turn

    void paralyzeEffect(Entity *victim, Status *ailment); //Reduces speed by 10 each turn and has 1/3 chance to make victim unable to act

    void sleepEffect(Entity *victim, Status *ailment); //Makes victim unable to act until cured

    static const auto none = std::make_shared<Status>("None", INT64_MAX, [](Entity*, Status*){}, true);
    static const auto poison = std::make_shared<Status>("Poison", 4, poisonEffect, false);
    static const auto longPoison = std::make_shared<Status>("Long-Lasting Poison", 8, poisonEffect, false);
    static const auto paralysis = std::make_shared<Status>("Paralysis", 5, paralyzeEffect, false);
    static const auto sleep = std::make_shared<Status>("Sleep", 3, sleepEffect, false);
}