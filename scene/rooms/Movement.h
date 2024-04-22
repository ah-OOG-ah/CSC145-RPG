#pragma once


/**
 * A tiny struct, used to pass data between a Floor and a Room
 */
struct Movement {
    bool isX = false;
    bool incX = false;
    bool isY = false;
    bool incY = false;

    [[nodiscard]] std::string toString() const;
    void reset();
};
