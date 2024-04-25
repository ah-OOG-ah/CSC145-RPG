#include <string>
#include "Movement.h"


std::string Movement::toString() const {
    std::string ret = "x: .., y: ..";
    std::snprintf(
            ret.data(),
            ret.size() + 1,
            "x: %+d, y: %+d", isX ? (incX ? 1 : -1) : 0, isY ? (incY ? 1 : -1) : 0);
    return ret;
}

void Movement::reset() {
    isX = false;
    isY = false;
    incX = false;
    incY = false;

    leaveFloor = false;
}
