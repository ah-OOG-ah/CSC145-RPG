#pragma once

#include <cstdint>
#include <string>


enum Pad {
    CENTER
};

class PU {
  public:
    static void print(Pad, const std::string&, int len);
};
