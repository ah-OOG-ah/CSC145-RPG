#include "ShopMenu.h"
#include <cstdint>
#include <string>
#include <iostream>
#include <ostream>
#include <utility>
#include <vector>
#include "Inventory.h"
#include "game.h"


ShopMenu::ShopMenu(std::string merchant, const Dialogue& text, std::shared_ptr<Item> stock1, std::shared_ptr<Item> stock2, std::shared_ptr<Item> stock3)
    : Menu(text.fmt()), merchantName(std::move(merchant)), purchase1(std::move(stock1)), purchase2(std::move(stock2)), purchase3(std::move(stock3)) { }

void ShopMenu::Buy() {
    int64_t itemChoice = 0;
    do {
        std::cout << merchantName << ": " <<entries[2]<<std::endl;
        std::cout << "GOLD" << getPlayer()->inventory.getGold() << std::endl;
        for (int i = 1; i <= 3; i++) {
            std::cout<< i << ". " << GetPurchase(i)->GetName() << "x" << GetPurchase(i)->GetAmount();
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
    std::cout << merchantName<< ": " << entries[0] <<std::endl;
    
    int64_t choice = 0;
    while (choice != 3) {
        std::cout << merchantName<< ": " << entries[1] <<std::endl;
        std::cout << "GOLD" << getPlayer()->inventory.getGold() << std::endl;
        std::cout << "1. I want to buy"<<std::endl;
        std::cout << "2. I want to sell"<<std::endl;
        std::cout << "3. I was just leaving"<<std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1:
                Buy();
                break;
            case 2:
                Sell();
                break;
            case 3:
                break;
            default:
                std::cout << merchantName<< ": " << entries[8] << std::endl;
        }
    }
    std::cout << merchantName<< ": " << entries[12] <<std::endl;
}

void ShopMenu::dispatch(int64_t choice) {
    switch (choice) {
        case 1:
            if (getPlayer()->inventory.getGold() < purchase1->GetPrice()) {
                std::cout << merchantName<< ": " << entries[7] <<std::endl;
                return;
            }
            if (getPlayer()->inventory.AddItem(purchase1->copy(0))) {
                getPlayer()->inventory.AddGold(-1 * purchase1->GetPrice());
                purchase1->ChangeAmount(-1);
                std::cout << purchase1->GetName() << " Added to Inventory" << std::endl;
                std::cout << purchase1->GetPrice() << " Given to " << merchantName << std::endl;
                std::cout << merchantName<< ": " << entries[5] << std::endl;
            } else {
                std::cout << merchantName<< ": " << entries[13] << std::endl;
            }
            break;
        case 2:
            if (getPlayer()->inventory.getGold() < purchase2->GetPrice()) {
                std::cout << merchantName<< ": " << entries[7] <<std::endl;
                return;
            }
            if (getPlayer()->inventory.AddItem(purchase2->copy(0))) {
                getPlayer()->inventory.AddGold(-1 * purchase1->GetPrice());
                purchase1->ChangeAmount(-1);
                std::cout << purchase2->GetName() << " Added to Inventory" << std::endl;
                std::cout << purchase2->GetPrice() << " Given to " << merchantName << std::endl;
                std::cout << merchantName<< ": " << entries[5] << std::endl;
            } else { //Player replaced no item with purchased item when inventory full
                std::cout << merchantName<< ": " << entries[13] << std::endl;
            }
            break;
        case 3:
            if (getPlayer()->inventory.getGold() < purchase1->GetPrice()) {
                std::cout << merchantName<< ": " << entries[7] <<std::endl;
                return;
            }
            if (getPlayer()->inventory.AddItem(purchase3->copy(0))) {
                getPlayer()->inventory.AddGold(-1 * purchase3->GetPrice());
                purchase3->ChangeAmount(-1);
                std::cout << purchase3->GetName() << " Added to Inventory" << std::endl;
                std::cout << purchase3->GetPrice() << " Given to " << merchantName << std::endl;
                std::cout << merchantName<< ": " << entries[5] << std::endl;
            } else { //Player replaced no item with purchased item when inventory full
                std::cout << merchantName<< ": " << entries[13] << std::endl;
            }
            break;
        case 4:
            break;
        default:
            std::cout << merchantName<< ": " << entries[8] << std::endl;
            break;
    }
}

//OLD SELL FUNCTION
/*
std::string choice;
    do
    {
    std::cout << merchantName<< ": " << entries[3] << std::endl;
    std::cout << "Enter \"Nothing\" or \"Exit\" to exit this menu" << std::endl;
    getPlayer()->Inven.PrintInven();
    std::getline(std::cin, choice);
    if(getPlayer()->playerInven.GetItem(choice) != nullptr)
    {
        int64_t amnt = 0;
        do{
        std::cout << merchantName<< ": " << entries[11] << std::endl;
        std::cin>>amnt;
        if(amnt > getPlayer()->Inven.GetItem(choice)->GetAmount() || amnt <= 0)
        {
            std::cout << merchantName<< ": " << entries[10] << std::endl;
        }
        }while(amnt <= getPlayer()->Inven.GetItem(choice)->GetAmount());
        int64_t total = amnt * getPlayer()->Inven.GetItem(choice)->GetPrice();
        //std::cout << merchantName<< ": " << entries[4] << (amnt * getPlayer()->Inven.GetElement(choice)->GetAmount()) << " Gold" << std::endl;
        getPlayer()->Inven.AddGold(total);
        getPlayer()->Inven.GetItem(choice)->ChangeAmount( -1 * amnt);
        std::cout << total << "Gold added to Inventory" << std::endl;
        std::cout << merchantName<< ": " << entries[6] << std::endl;
    }
    else
    {
        std::cout << merchantName<< ": " << entries[8] << std::endl;
    }
    } while(choice != "Nothing" || choice != "nothing" || choice != "NOTHING" || choice != "Exit" || choice != "exit" || choice != "EXIT");


    int64_t amnt = 0;
            while(amnt > 0)
            {
                std::cin>>amnt;
                if(amnt < 0 || amnt > getPlayer()->Inven.GetEquip(choice -1))
            }
*/