#include "ShopMenu.h"
#include <cstdint>
#include <string>
#include <iostream>
#include <ostream>
#include <utility>
#include <vector>
#include "Inventory.h"
#include "game.h"


ShopMenu::ShopMenu(std::string merchant, Dialogue text, std::vector<std::shared_ptr<Item>> wares)
    : Menu({ "" }), text(std::move(text)), merchantName(std::move(merchant)), wares(std::move(wares)) { }

void ShopMenu::Buy() {
    int64_t itemChoice = 0;
    do {
        std::cout << merchantName << ": " << text.whatAreYouBuying << std::endl;
        std::cout << "Gold: " << getPlayer()->inventory.getGold() << std::endl;

        for (int i = 0; i < wares.size(); i++) {
            std::cout << i << ". " << wares[i]->GetName() << "x" << wares[i]->GetAmount();
            if (wares[i]->isEquipment()) {
                std::cout << " EQUIPMENT";
            }
            std::cout<<"   Price: " << wares[i]->GetPrice() << std::endl;
        }

        std::cout << "4. None of it " << std::endl;
        std::cin >> itemChoice;
        dispatch(itemChoice);
    } while (itemChoice != 4); 
}

void ShopMenu::Sell() {
    std::cout << merchantName << ": " << entries[3] << std::endl;
    std::cout << "Please input the number for the item you want to sell. Enter 0 to exit" << std::endl;
    getPlayer()->inventory.print(true);
    int64_t choice = 0;

    std::cin >> choice; // Choice will subtracted by one to account for the fact that array starts as zero but inventory numbers at 1
    if (choice > 0 && choice <= getPlayer()->inventory.getUsedSlots()) {
        int64_t sellAmnt = 1;
        if (getPlayer()->inventory[choice]->isStackable()) {
            std::cout << merchantName<< ": " << entries[15] << " ";
            std::cin >> sellAmnt;
        }
        std::cout << merchantName<< ": " << entries[4] << " ";
        std::cout << ((getPlayer()->inventory[choice]->GetPrice()) * sellAmnt) / (.8) << std::endl;
        std::cout<< "Sell\?" << std::endl;
        std::string sellChoice;
        std::getline(std::cin, sellChoice);
        if (sellChoice == "Yes" || sellChoice == "yes"  || sellChoice == "YES" || sellChoice == "Y" || sellChoice == "Y") {
            getPlayer()->inventory.AddGold(getPlayer()->inventory[choice]->GetPrice() * sellAmnt * .8);
            getPlayer()->inventory.RemoveItem(choice, -1 * sellAmnt);
            std::cout << merchantName<< ": " << entries[6] << std::endl;
        } else {
            std::cout << merchantName<< ": " << entries[14] << std::endl;
        }
    }
}

void ShopMenu::display() {
    std::cout << merchantName << ": " << text.enterString << std::endl;
    
    int64_t choice = 0;
    while (choice != 3) {
        std::cout << merchantName << ": " << text.buyOrSell <<std::endl;
        std::cout << "Gold: " << getPlayer()->inventory.getGold() << std::endl;
        std::cout << "1. I want to buy" << std::endl;
        std::cout << "2. I want to sell" << std::endl;
        std::cout << "3. I was just leaving" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1: Buy(); break;
            case 2: Sell(); break;
            case 3: break;
            default: std::cout << merchantName << ": " << text.invalid << std::endl;
        }
    }
    std::cout << merchantName << ": " << text.exitString << std::endl;
}

void ShopMenu::dispatch(int64_t choice) {
    --choice;

    if (choice == wares.size())
        return;

    if (choice > wares.size()) {
        std::cout << merchantName << ": " << text.invalid << std::endl;
        return;
    }

    if (getPlayer()->inventory.getGold() < wares[choice]->GetPrice()) {
        std::cout << merchantName << ": " << text.notEnoughGold << std::endl;
        return;
    }

    if (getPlayer()->inventory.AddItem(wares[choice]->copy(0))) {
        getPlayer()->inventory.AddGold(-1 * wares[choice]->GetPrice());
        std::cout << wares[choice]->GetPrice() << " gold given to " << merchantName << std::endl;
        std::cout << wares[choice]->GetName() << " was added to your Inventory" << std::endl;
        wares[choice]->ChangeAmount(-1);
        std::cout << merchantName<< ": " << text.youBought << std::endl;
    } else {
        std::cout << merchantName<< ": " << text.giveBack << std::endl;
    }
}
