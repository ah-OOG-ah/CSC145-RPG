#include "ShopRoom.h"
#include <string>
#include <utility>
#include "Item.h"
#include "ShopMenu.h"
#include "game.h"
#include "ItemDefs.h"
#include "ShopDialogue.h"


ShopRoom::ShopRoom(std::shared_ptr<Movement> m, uint8_t mask, int64_t nice) : Room("Shop", std::move(m), mask, nice) {
    Dialogue text;

    switch (randUint() % 4) {
        case 0:
            purchase1 = IDefs::dart->copy(0);
            purchase1->multiply(3);
            break;
        case 1:
            purchase1 = IDefs::cookie->copy(0);
            purchase1->multiply(5);
            break;
        case 2:
            purchase1 = IDefs::spear->copy(0);
            purchase1->multiply(2);
            break;
        case 3:
            purchase1 = IDefs::hammer->copy(0);
            break;
    }

    //Multi switch statement to determine merchant's name
    auto rand1 = randUint() % 4;
    auto rand2 = randUint() % 4;
    switch (rand1) {
        case 1:
            text = {
                "Hello me chum, welcome to me shop.",
                "Ye buying or ye selling\?",
                "Which of me fine items would ye be interested in buying today",
                "What junk do ye have\?",
                "For that, I can spare you about... ",
                "Aye! Pleasure doing buisness.",
                "Thanks for the item!",
                "Oi! You do not have enough money, lad! Get a job!",
                "Oi! What was that \?",
                "Oi! What do ye take me for\? Ye are trying to sell things ye do not have.",
                "Sorry, lad, I do not have enough of that.",
                "How many of ye fine items will ye be selling to me\?",
                "Take care of yeself, mate!",
                "Oi! I am always here when you have more room.",
                "Well if you ever change yer mind come and have a talk.",
                "How many of ye fine items will you be selling to me today\?"
            };
            switch (rand2) {
                case 1:
                    merchantName = "Grisly Beard";
                    break;
                case 2:
                    merchantName = "Jerome";
                    break;
                case 3:
                    merchantName = "Jackson";
                    break;
                default:
                    merchantName = "Hobo Gregor";
                    break;
            }
            description = "a warm room with the faint smell of salt in the air and a weather beaten shack in the corner.";
            break;
        case 2:
            text = {
                    "Welcome, sir, to my shop!",
                    "Are you buying items or selling them, sir\?",
                    "Which item would you be interested in today\?",
                    "What would you like me to buy\?",
                    "That will give about... ",
                    "Much apprieciated, sir!",
                    "This is a very fine item, my good sir. Thank you!",
                    "It seems you do not have enough money for that item at the moment.",
                    "Excuse me \? What was that, sir\?",
                    "I\'m sorry, sir, but you seems you do not have that amount to sell.",
                    "Sir, I am afraid that I do not that amount to give to you.",
                    "How many items will you be selling today, sir\?",
                    "Have a blessed day, sire!",
                    "I am sorry for your lack of space, sir.",
                    "If you ever need to part with your items in the future, sir, I will be right here.",
                    "How many of your fine items will you be selling to me today\?"
            };
            switch (rand2) {
                case 1:
                    merchantName = "Hilda";
                    break;
                case 2:
                    merchantName = "Serena";
                    break;
                case 3:
                    merchantName = "Sir Jack";
                    break;
                default:
                    merchantName = "Sir Michel";
                    break;
            }
            description = "a polished room with a mahogany door on one wall.";
            break;
        case 3:
            text = {
                "Hello there!",
                "What do you want\?",
                "Anything you interested in\?",
                "What do you have\?",
                "I can take that off your hands for ",
                "Oh, Money, you do make the world go round!",
                "This will make a fine addition to my collection",
                "Hey, rat! You don\'t seem to have enough money to buy that",
                "Speak up, kid, I can\'t hear you.",
                "Enough jokes, kid. If you want to do business at least try to be serious",
                "Can you please make a reasonable request\?",
                "How many would you like me take off your hands\?",
                "Be careful. You never know what could be lurking out there.",
                "Bit off more than you can chew, huh\?",
                "Do you feel an overbearing need to waste my time or what\?",
                "How many are you selling\?"
            };
            switch (rand2) {
                case 1:
                    merchantName = "Sam";
                    break;
                case 2:
                    merchantName = "Aaron";
                    break;
                case 3:
                    merchantName = "Ridley";
                    break;
                default:
                    merchantName = "Scott";
                    break;
            }
            description = "an undecorated room with metal flooring. A blast door is inset on one of the walls.";
            break;
        default:
            text = {
                "((|)..(|)) \n     -",
                "Ooh ooh, ah ah",
                "What are you buying\?",
                "What items do you have\?",
                "I can make a transactional purchase for that item which will gain you approximately ",
                "This will make a good offering for the boss",
                "Monkey Bob is happy you are ridding yourself of your items. It makes you easier to kill.",
                "Monkey Bob did not like that",
                "Monkey Bob really did not like that",
                "Monkey Bob wants to steal all you have",
                "Monkey Bob has not given me that amount of items",
                "How many items will you be handing over to Monkey Bob, your primate overlord\?",
                "Monkey Bob is coming for you",
                "Monkey Bob delights in your lack of space.",
                "Your items will be Monkey Bob's in due time",
                "How many of your items will you tribute to the Casear that is Monkey Bob\?"
            };
            description = "a noisy room filled with screeching. A large money surrounded with knickknacks crouches in the corner.\n"
                          "You can't see where the screeches are coming from.";
            merchantName = "Merchant Bob";
    }
    dialogue = text;

    // Add the menu to the list
    entries.emplace_back("Enter Shop");
    funcs.emplace_back([this](){
        this->display();
    });
}

std::string ShopRoom::GetMerchant() const { return merchantName; }

std::shared_ptr<Item> ShopRoom::GetPurchase(int64_t selection) {
    switch(selection) {
        case 1:
            return purchase1;
        case 2:
            return purchase2;
        case 3:
            return purchase3;
        default:
            return nullptr;
    }
}

std::string ShopRoom::GetDialogue(int64_t i) { return dialogue[i]; }

void ShopRoom::GoToShop() {
    ShopMenu shopMenu(merchantName, dialogue, purchase1, purchase2, purchase3);
    shopMenu.display();
}
