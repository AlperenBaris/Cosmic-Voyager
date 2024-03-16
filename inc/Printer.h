//
// Created by alper on 15.03.2024.
//

#ifndef COSMIC_VOYAGER_PRINTER_H
#define COSMIC_VOYAGER_PRINTER_H

#include "../inc/Ship.h"
#include "../inc/ShipEnums.h"

class Printer {
public:
    void PrintWelcomeMessage() const;
    void PrintFastShipASCII() const;
    void PrintNormalShipASCII() const;
    void PrintStrongShipASCII() const;
    void PrintAsteroidASCII() const;
    void PrintPlanetASCII() const;
    void PrintPiratesASCII() const;
    void PrintStatus(const Ship& ship) const;
};

#endif //COSMIC_VOYAGER_PRINTER_H
