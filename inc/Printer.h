//
// Created by alper on 15.03.2024.
//

#ifndef COSMIC_VOYAGER_PRINTER_H
#define COSMIC_VOYAGER_PRINTER_H

#include "../inc/Ship.h"
#include "../inc/ShipEnums.h"

class Printer {
public:
    void printWelcomeMessage() const;
    void printShipASCII(Ships shipType) const;
    void printAsteroidASCII() const;
    void printPlanetASCII() const;
    void printPiratesASCII() const;
    void printStatus(const Ship& ship);
};

#endif //COSMIC_VOYAGER_PRINTER_H
