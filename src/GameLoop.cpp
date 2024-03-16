#include <iostream>
#include <limits>
#include <string>
#include "FastShip.h"
#include "NormalShip.h"
#include "StrongShip.h"
#include "GameLoop.h"
#include "Printer.h"

 Ship* GameLoop::SelectShip() {
    std::cout << "Select your ship (1: Normal, 2: Fast, 3: Strong): ";
    int choice;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> choice;

    switch (choice) {
        case 1:
            Printer::PrintNormalShipASCII();
            return new NormalShip();
        case 2:
            Printer::PrintFastShipASCII();
            return new FastShip();
        case 3:
            Printer::PrintStrongShipASCII();
            return new StrongShip();
        default:
            std::cout << "Otomatically selected Normal Ship." << std::endl;
            Printer::PrintNormalShipASCII();
            return new NormalShip();
    }
}

void GameLoop::GetInput() {
    std::cout << "Press Enter to continue";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}