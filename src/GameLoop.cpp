#include <iostream>
#include <limits>
#include <string>
#include "../inc/FastShip.h"
#include "../inc/NormalShip.h"
#include "../inc/StrongShip.h"

 Ship* GameLoop::selectShip() {
    std::cout << "Select your ship (1: Normal, 2: Fast, 3: Strong): ";
    int choice;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> choice;

    switch (choice) {
        case 1:
            return new NormalShip();
        case 2:
            return new FastShip();
        case 3:
            return new StrongShip();
        default:
            std::cout << "Otomatically selected Normal Ship." << std::endl;
            return new NormalShip();
    }
}

void GameLoop::getInput() {
    std::cout << "Press Enter to continue for next Event";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}