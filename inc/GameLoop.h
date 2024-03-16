//
// Created by alper on 13.03.2024.
//

#ifndef COSMIC_VOYAGER_GAMELOOP_H
#define COSMIC_VOYAGER_GAMELOOP_H

#include "Ship.h"

class GameLoop{
public:
    Ship* selectShip();
    void getInput();
};

#endif //COSMIC_VOYAGER_GAMELOOP_H
