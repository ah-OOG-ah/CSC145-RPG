#include "ShopMenu.h"
#include <cstdint>
#include <string>
#include <iostream>
#include <ostream>
#include <utility>
#include <vector>
#include "Inventory.h"
#include "game.h"


ShopMenu::ShopMenu(std::string merchant, const Dialogue& text, const std::vector<std::shared_ptr<Item>>& wares)
    : Menu(text.fmt()), text(text), merchantName(std::move(merchant)), wares(wares) { }

void ShopMenu::Buy() {
    int64_t itemChoice = 0;
    do {
        std::cout << merchantName << ": " << entries[2]<<std::endl;
        std::cout << "Gold: " << getPlayer()->inventory.getGold() << std::endl;
        for (int i = 1; i <= 3; i++) {
            std::cout << i << ". " << GetPurchase(i)->GetName() << "x" << GetPurchase(i)->GetAmount();
            if (GetPurchase(i)->isEquipment()) {
                std::cout<<" EQUIPMENT";
            }
            std::cout<<"   Price: " << GetPurchase(i)->GetPrice() << std::endl;
        }
        std::cout << "4. None of it " << std::endl;
        std::cin >> itemChoice;
        dispatch(itemChoice);
    } while (itemChoice != 4); 
}

void ShopMenu::Sell() {
    std::cout << merchantName<< ": " << entries[3] << std::endl;
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

std::shared_ptr<Item> ShopMenu::GetPurchase(int64_t selection) {
    switch (selection) {
        case 1: return purchase1;
        case 2: return purchase2;
        case 3: return purchase3;
        default: return nullptr;
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
    switch (choice) {
        case 1:
            if (getPlayer()->inventory.getGold() < purchase1->GetPrice()) {
                std::cout << merchantName << ": " << text.notEnoughGold << std::endl;
                return;
            }
            if (getPlayer()->inventory.AddItem(purchase1->copy(0))) {
                getPlayer()->inventory.AddGold(-1 * purchase1->GetPrice());
                std::cout << purchase1->GetPrice() << " gold given to " << merchantName << std::endl;
                std::cout << purchase1->GetName() << " was added to your Inventory" << std::endl;
                purchase1->ChangeAmount(-1);
                std::cout << merchantName<< ": " << text.youBought << std::endl;
            } else {
                std::cout << merchantName<< ": " << text.giveBack << std::endl;
            }
            break;
        case 2:
            if (getPlayer()->inventory.getGold() < purchase2->GetPrice()) {
                std::cout << merchantName << ": " << text.notEnoughGold <<std::endl;
                return;
            }
            if (getPlayer()->inventory.AddItem(purchase2->copy(0))) {
                getPlayer()->inventory.AddGold(-1 * purchase1->GetPrice());
                purchase1->ChangeAmount(-1);
                std::cout << purchase2->GetName() << " Added to Inventory" << std::endl;
                std::cout << purchase2->GetPrice() << " Given to " << merchantName << std::endl;
                std::cout << merchantName<< ": " << text.youBought << std::endl;
            } else { //Player replaced no item with purchased item when inventory full
                std::cout << merchantName<< ": " << text.giveBack << std::endl;
            }
            break;
        case 3:
            if (getPlayer()->inventory.getGold() < purchase1->GetPrice()) {
                std::cout << merchantName<< ": " << text.notEnoughGold <<std::endl;
                return;
            }
            if (getPlayer()->inventory.AddItem(purchase3->copy(0))) {
                getPlayer()->inventory.AddGold(-1 * purchase3->GetPrice());
                purchase3->ChangeAmount(-1);
                std::cout << purchase3->GetName() << " Added to Inventory" << std::endl;
                std::cout << purchase3->GetPrice() << " Given to " << merchantName << std::endl;
                std::cout << merchantName<< ": " << text.youBought << std::endl;
            } else { //Player replaced no item with purchased item when inventory full
                std::cout << merchantName<< ": " << text.giveBack << std::endl;
            }
            break;
        case 4:
            break;
        default:
            std::cout << merchantName<< ": " << text.youHaveNotEnough << std::endl;
            break;
    }
}
