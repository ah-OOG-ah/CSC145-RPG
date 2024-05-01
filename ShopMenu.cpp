#include "ShopMenu.h"
#include <cstdint>
#include <string>
#include <iostream>
#include <ostream>
#include <utility>
#include <vector>
#include <cmath>
#include "Inventory.h"
#include "game.h"


ShopMenu::ShopMenu(std::string merchant, Dialogue text, std::vector<std::shared_ptr<Item>> wares)
    : text(std::move(text)), merchantName(std::move(merchant)), wares(std::move(wares)) { }

void ShopMenu::Buy() {
    // Present the wares
    std::cout << merchantName << ": " << text.whatAreYouBuying << std::endl;
    std::cout << "Gold: " << getPlayer()->inventory.getGold() << std::endl;

    std::cout << "0. Nothing " << std::endl;
    for (size_t i = 0; i < wares.size(); i++) {
        std::cout << i + 1;

        if (wares[i]->GetAmount() < 1) {
            std::cout << " Out of stock!" << std::endl;
            continue;
        }

        std::cout << ". " << wares[i]->GetName() << " x " << wares[i]->GetAmount();
        std::cout << "   Price: " << wares[i]->GetPrice() << std::endl;
    }

    int64_t choice;
    std::cin >> choice;

    if (choice == 0) return;

    if (choice > wares.size()) {
        std::cout << merchantName << ": " << text.invalid << std::endl;
        return;
    }

    --choice;

    if (wares[choice]->GetAmount() < 1) {
        std::cout << merchantName << ": " << text.merchantHaveNotEnough << std::endl;
        return;
    }

    if (getPlayer()->inventory.getGold() < wares[choice]->GetPrice()) {
        std::cout << merchantName << ": " << text.notEnoughGold << std::endl;
        return;
    }

    if (getPlayer()->inventory.AddItem(wares[choice]->copy(1))) {
        getPlayer()->inventory.AddGold(-1 * wares[choice]->GetPrice());
        std::cout << wares[choice]->GetPrice() << " gold given to " << merchantName << std::endl;
        std::cout << wares[choice]->GetName() << " was added to your Inventory" << std::endl;
        wares[choice]->ChangeAmount(-1);
        std::cout << merchantName << ": " << text.youBought << std::endl;
    } else {
        std::cout << merchantName << ": " << text.giveBack << std::endl;
    }
}

void ShopMenu::Sell() {
    std::cout << merchantName << ": " << text.merchantBuying << std::endl;
    std::cout << "Please input the number for the item you want to sell. Enter 0 to exit" << std::endl;
    getPlayer()->inventory.print(true);
    int64_t choice = 0;

    std::cin >> choice;
    if (choice > 0 && choice <= getPlayer()->inventory.getUsedSlots()) {
        --choice;

        // Get the sale amount
        int64_t sellAmnt = 1;
        if (getPlayer()->inventory[choice]->isStackable()) {
            std::cout << merchantName << ": " << text.howMany << " ";
            std::cin >> sellAmnt;
        }

        const int64_t gold = std::floor(getPlayer()->inventory[choice]->GetPrice() * sellAmnt * 0.8l);
        std::cout << merchantName << ": " << text.takeThatFor << " " << gold << std::endl;
        std::cout << "Sell\? (y/N)" << std::endl;
        std::string shouldSell;
        std::cin >> shouldSell;

        // Handle the sale
        if (shouldSell == "Y" || shouldSell == "y") {
            getPlayer()->inventory.AddGold(gold);
            getPlayer()->inventory.RemoveItem(choice, sellAmnt);
            std::cout << merchantName << ": " << text.theyBought << std::endl;
        } else {
            std::cout << merchantName << ": " << text.failedSale << std::endl;
        }
    }
}

void ShopMenu::displayMany(int64_t& i, bool& exit) {
    std::cout << merchantName << ": " << text.buyOrSell <<std::endl;
    std::cout << "Gold: " << getPlayer()->inventory.getGold() << std::endl;
    std::cout << "1. I want to buy" << std::endl;
    std::cout << "2. I want to sell" << std::endl;
    std::cout << "3. I was just leaving" << std::endl;
    std::cin >> i;
    switch (i) {
        case 1: Buy(); displayMany(i, exit); exit = true; break;
        case 2: Sell(); displayMany(i, exit); exit = true; break;
        case 3: exit = true; break;
        default: std::cout << merchantName << ": " << text.invalid << std::endl; break;
    }
}

void ShopMenu::displayOnce() {
    std::cout << merchantName << ": " << text.enterString << std::endl;
    
    int64_t choice = 0;
    auto exit = false;
    while (!exit) {
        displayMany(choice, exit);
    }
    std::cout << merchantName << ": " << text.exitString << std::endl << std::endl;
}
