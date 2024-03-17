//
// Created by alper on 13.03.2024.
//

#ifndef COSMIC_VOYAGER_GAMELOOP_H
#define COSMIC_VOYAGER_GAMELOOP_H

#include "Ship.h"
#include <memory>
#include <iostream>

class GameLoop{
public:
    static std::shared_ptr<Ship> SelectShip();
    static void GetInput();
};

#endif //COSMIC_VOYAGER_GAMELOOP_H
