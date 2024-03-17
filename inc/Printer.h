//
// Created by alper on 15.03.2024.
//

#ifndef COSMIC_VOYAGER_PRINTER_H
#define COSMIC_VOYAGER_PRINTER_H

#include "Ship.h"
#include "GameStateEnum.h"
#include <memory>

class Printer {
public:
    static void PrintWelcomeMessage();
    static void PrintFastShipASCII();
    static void PrintNormalShipASCII();
    static void PrintStrongShipASCII();
    static void PrintAsteroidASCII();
    static void PrintPlanetASCII();
    static void PrintPiratesASCII();
    static void PrintStatus(const std::shared_ptr<Ship>& ship);
    static void PrintEndingMessage(GameState state, const std::shared_ptr<Ship>& ship);
};

#endif //COSMIC_VOYAGER_PRINTER_H
