#include "ShopRoom.h"
#include <string>
#include <utility>
#include "Item.h"
#include "ShopMenu.h"
#include "game.h"
#include "itemlist.h"


std::string ShopRoom::GetMerchant() const { return merchantName; }

Item* ShopRoom::GetPurchase(int64_t selection) {
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

std::string ShopRoom::GetDialogue(int64_t i) { return entries[i]; }

ShopRoom::ShopRoom(std::shared_ptr<Movement> m, uint8_t mask) : Room("Shop", std::move(m), mask) {
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

    switch (getRand() % 4) {
        case 0:
            purchase1 = new AttackItem(dart);
            purchase1->copy(3);
            break;
        case 1:
            purchase1 = new HealItem(cookie);
            purchase1->copy(5);
            break;
        case 2:
            purchase1 = new Weapon(spear);
            purchase1->copy(2);
            break;
        case 3:
            purchase1 = new Weapon(hammer);
            break;
    }

    //Multi switch statement to determine merchant's name
    auto rand1 = getRand() % 4;
    auto rand2 = getRand() % 4;
    switch(rand1) {
        case 1:
            enterString = "Hello me chum, welcome to me shop.";
            buyOrSell = "Ye buying or ye selling\?";
            whatAreYouBuying = "Which of me fine items would ye be interested in buying today";
            merchantBuying = "What junk do ye have\?";
            takeThatFor = "For that, I can spare you about... ";
            youBought = "Aye! Pleasure doing buisness.";
            theyBought = "Thanks for the item!";
            notEnough = "Oi! You do not have enough money, lad! Get a job!";
            invalid = "Oi! What was that \?";
            youHaveNotEnough = "Oi! What do ye take me for\? Ye are trying to sell things ye do not have.";
            merchantHaveNotEnough = "Sorry, lad, I do not have enough of that.";
            amountSelling = "How many of ye fine items will ye be selling to me\?";
            exitString = "Take care of yeself, mate!";
            giveBack = "Oi! I am always here when you have more room.";
            failedSale = "Well if you ever change yer mind come and have a talk.";
            howMany = "How many of ye fine items will you be selling to me today\?";
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
            break;
        case 2:
            enterString = "Welcome, sir, to my shop!";
            buyOrSell = "Are you buying items or selling them, sir\?";
            whatAreYouBuying = "Which item would you be interested in today\?";
            merchantBuying = "What would you like me to buy\?";
            takeThatFor = "That will give about... ";
            youBought = "Much apprieciated, sir!";
            theyBought = "This is a very fine item, my good sir. Thank you!";
            notEnough = "It seems you do not have enough money for that item at the moment.";
            invalid = "Excuse me \? What was that, sir\?";
            youHaveNotEnough = "I\'m sorry, sir, but you seems you do not have that amount to sell.";
            merchantHaveNotEnough = "Sir, I am afraid that I do not that amount to give to you.";
            amountSelling = "How many items will you be selling today, sir\?";
            exitString = "Have a blessed day, sire!";
            giveBack = "I am sorry for your lack of space, sir.";
            failedSale = "If you ever need to part with your items in the future, sir, I will be right here.";
            switch(rand2) {
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
            break;
        case 3:
            enterString = "Hello there!";
            buyOrSell = "What do you want\?";
            whatAreYouBuying = "Anything you interested in\?";
            merchantBuying = "What do you have\?";
            takeThatFor = "I can take that off your hands for ";
            youBought = "Oh, Money, you do make the world go round!";
            theyBought = "This will make a fine addition to my collection";
            notEnough = "Hey, rat! You don\'t seem to have enough money to buy that";
            invalid = "Speak up, kid, I can\'t hear you.";
            youHaveNotEnough = "Enough jokes, kid. If you want to do buisness at least try to be serious";
            merchantHaveNotEnough = "Can you please make a reasonable request\?";
            amountSelling = "How many would you like me take off your hands\?";
            exitString = "Be careful. You never know what could be lurking out there.";
            giveBack = "Bit off more than you can chew, huh\?";
            failedSale = "Do you feel an overbearing need to waste my time or what\?";
            howMany = "How many are you selling\?";
            switch(rand2) {
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
            break;
        default:
            enterString = "((|)..(|)) \n     -";
            buyOrSell = "Ooh ooh, ah ah";
            whatAreYouBuying = "What are you buying\?";
            merchantBuying = "What items do you have\?";
            takeThatFor = "I can make a transactional purchase for that item which will gain you approximately ";
            youBought = "This will make a good offering for the boss";
            theyBought = "Monkey Bob is happy you are ridding yourself of your items. It makes you easier to kill.";
            notEnough = "Monkey Bob did not like that";
            invalid = "Monkey Bob really did not like that";
            youHaveNotEnough = "Monkey Bob wants to steal all you have";
            merchantHaveNotEnough = "Monkey Bob has not given me that amount of items";
            amountSelling = "How many items will you be handing over to Monkey Bob, your primate overlord\?";
            exitString = "Monkey Bob is coming for you";
            giveBack = "Monkey Bob delights in your lack of space.";
            failedSale = "Your items will be Monkey Bob's in due time";
            howMany = "How many of your items will you tribute to the Casear that is Monkey Bob\?";
            merchantName = "Merchant Bob";
    }
    entries = {enterString, buyOrSell, whatAreYouBuying, merchantBuying, takeThatFor, youBought, theyBought, notEnough, invalid, youHaveNotEnough, merchantHaveNotEnough, amountSelling, exitString, giveBack, failedSale, howMany};
}

void ShopRoom::GoToShop() {
    ShopMenu shopMenu(merchantName, entries, purchase1, purchase2, purchase3);
    shopMenu.display();
}
