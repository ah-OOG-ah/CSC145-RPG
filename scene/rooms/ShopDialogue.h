#pragma once

#include <vector>
#include <cstdint>
#include "ShopMenu.h"
#include "Room.h"
#include "Item.h"
#include <string>

struct Dialogue {
    std::string enterString;
    std::string buyOrSell;
    std::string whatAreYouBuying;
    std::string merchantBuying;
    std::string takeThatFor;
    std::string youBought;
    std::string theyBought;
    std::string notEnough;
    std::string invalid;
    std::string youHaveNotEnough;
    std::string merchantHaveNotEnough;
    std::string amountSelling;
    std::string exitString;
    std::string giveBack;
    std::string failedSale;
    std::string howMany;

    [[nodiscard]] std::string operator[](size_t i) const {
        switch (i) {
            case 0: return enterString;
            case 1: return buyOrSell;
            case 2: return whatAreYouBuying;
            case 3: return merchantBuying;
            case 4: return takeThatFor;
            case 5: return youBought;
            case 6: return theyBought;
            case 7: return notEnough;
            case 8: return invalid;
            case 9: return youHaveNotEnough;
            case 10: return merchantHaveNotEnough;
            case 11: return amountSelling;
            case 12: return exitString;
            case 13: return giveBack;
            case 14: return failedSale;
            default: return howMany;
        }
    }

    [[nodiscard]] std::vector<std::string> fmt() const {
        return {
            enterString,
            buyOrSell,
            whatAreYouBuying,
            merchantBuying,
            takeThatFor,
            youBought,
            theyBought,
            notEnough,
            invalid,
            youHaveNotEnough,
            merchantHaveNotEnough,
            amountSelling,
            exitString,
            giveBack,
            failedSale,
            howMany
        };
    }
};

