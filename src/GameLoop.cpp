#include <iostream>
#include <string>
#include "FastShip.h"
#include "NormalShip.h"
#include "StrongShip.h"
#include "GameLoop.h"
#include "Printer.h"
#include <memory>

std::shared_ptr<Ship> GameLoop::SelectShip() 
{
    std::cout << "Select your ship (1: Normal, 2: Fast, 3: Strong): "; 
    int choice;

    std::cin >> choice; //Player chooses the ship type 

    switch (choice)
    {
    case 1: //If  player chooses the normal ship
        Printer::PrintNormalShipASCII();
        return std::make_shared<NormalShip>();
    case 2://If the player chooses the fast ship
        Printer::PrintFastShipASCII();
        return std::make_shared<FastShip>();
    case 3: //If the player chooses the strong ship
        Printer::PrintStrongShipASCII();
        return std::make_shared<StrongShip>();
    default: //Default selected ship type by game is normal ship
        std::cout << "Otomatically selected Normal Ship." << std::endl;
        Printer::PrintNormalShipASCII();
        return std::make_shared<NormalShip>();
    }
}

void GameLoop::GetInput()
{
    // To start game, we want to press Enter key.
    std::cout << "Press Enter to continue" << std::endl;
    std::cin.get();
}