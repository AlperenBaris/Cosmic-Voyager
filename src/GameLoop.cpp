#include <iostream>
#include <string>
#include "FastShip.h"
#include "NormalShip.h"
#include "StrongShip.h"
#include "GameLoop.h"
#include "Printer.h"
#include <memory>

std::shared_ptr<Ship> GameLoop::SelectShip() {
    std::cout << "Select your ship (1: Normal, 2: Fast, 3: Strong): ";
    int choice;

    std::cin >> choice;


    switch (choice) {
        case 1:
            Printer::PrintNormalShipASCII();
            return std::make_shared<NormalShip>();
        case 2:
            Printer::PrintFastShipASCII();
            return std::make_shared<FastShip>();
        case 3:
            Printer::PrintStrongShipASCII();
            return std::make_shared<StrongShip>();
        default:
            std::cout << "Otomatically selected Normal Ship." << std::endl;
            Printer::PrintNormalShipASCII();
            return std::make_shared<NormalShip>();
    }
}

void GameLoop::GetInput() {
    std::cout << "Press Enter to continue" << std::endl;
    std::cin.get();
}