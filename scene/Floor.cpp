#include "Floor.h"

size_t Floor::index(int64_t x, int64_t y) const { return x + y * size; }
