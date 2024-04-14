#include "Menu.h"
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

Menu::Menu(std::vector<std::string> entries) : entries(entries) {}

void Menu::display() {

    for (size_t i = 0; i < entries.size(); ++i) {
        std::cout << i << ". " << this->entries.at(i) << std::endl;
    }

    std::string choice;
    size_t i = -1;
    
    while (true) {

        std::getline(std::cin, choice);

        try {
            i = std::stoi(choice);
        } catch (std::invalid_argument&) {
            std::cout << "Not a number" << std::endl;
            continue;
        }

        if (i >= this->entries.size()) {
            std::cout << "Invalid option" << std::endl;
            continue;
        }

        break;
    }

    this->dispatch(i);
        
}
