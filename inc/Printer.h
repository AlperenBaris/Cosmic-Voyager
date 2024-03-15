//
// Created by alper on 15.03.2024.
//

#ifndef COSMIC_VOYAGER_PRINTER_H
#define COSMIC_VOYAGER_PRINTER_H

#include "../inc/Ship.h"
#include "../inc/ShipEnums.h"

class Printer {
public:
    void const printWelcomeMessage();
    void const printShipASCII(Ships shipType);
    void const printAsteroidASCII();
    void const printPlanetASCII();
    void const printPiratesASCII();
    void printStatus(const Ship& ship);
};

#endif //COSMIC_VOYAGER_PRINTER_H
