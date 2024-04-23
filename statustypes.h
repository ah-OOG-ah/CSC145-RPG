#pragma once

#include "Status.h"


namespace stypes {

    void poisonEffect(Entity *victim, Status *ailment);

    void paralyzeEffect(Entity *victim, Status *ailment);

    void sleepEffect(Entity *victim, Status *ailment);

    static const Status poison("Poison", 4, poisonEffect);
    static const Status longPoison("Long-Lasting Poison", 8, poisonEffect);
    static const Status paralysis("Paralysis", 5, paralyzeEffect);
    static const Status sleep("Sleep", 3, sleepEffect);
}