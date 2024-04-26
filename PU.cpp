#include <iostream>
#include <iomanip>
#include "PU.h"


void PU::print(Pad p, const std::string& s, int len) {
    if (s.size() > len) {
        std::cout << std::setw(len) << s;
        return;
    }

    uint64_t pre = 0;
    switch (p) {
        case CENTER: pre = (len - s.size()) / 2;
    }

    std::cout << std::string(pre, ' ') << s << std::string(len - s.size() - pre, ' ');
}
