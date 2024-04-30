#pragma once

#include <string>
#include "Item.h"
#include "Room.h"
#include "ShopMenu.h"
#include "ShopDialogue.h"
#include <cstdint>
#include <vector>


class ShopRoom : public Room {
  protected:
    std::string mapDisplay = "S";
    std::string merchantName;
    std::shared_ptr<Item> purchase1 = nullptr;
    std::shared_ptr<Item> purchase2 = nullptr;
    std::shared_ptr<Item> purchase3 = nullptr;

    Dialogue dialogue;

  public:
    ShopRoom(std::shared_ptr<Movement> m, uint8_t mask, int64_t nice);

    /*
    Name: GetMerchant
    Return type: string
    Arguments: None
    Use: returns the "merchant" string
    */
    [[nodiscard]] std::string GetMerchant() const;
    /*
    Name: GetPurchase
    Return type: Item pointer
    Arguments: An int64_t integer from 1-3
    Use: Takes in an integer and returns one of the "purchase" Item pointers based on the integer
    */
    std::shared_ptr<Item> GetPurchase(int64_t);
    /*
    Name: GetPurchase
    Return type: string
    Arguments: An int64_t integer from 1-8
    Use: Takes in an integer and gives the corresponding dialogue members based on the number given
    */
    std::string GetDialogue(int64_t);
    void GoToShop();
};