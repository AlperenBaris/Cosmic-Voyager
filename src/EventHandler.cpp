//
// Created by alper on 12.03.2024.
//

#include "../inc/EventHandler.h"
#include "../inc/EventEnums.h"
#include "Ship.cpp"
#include <cstdlib>
#include <ctime>

const double normalProbability = 0.5;

Events EventHandler::AsteroidBelt(Ship* ship) {

    srand(time(0));
    const double randomNumber = ((double)rand() / RAND_MAX); // Random number from 0 to 1
    const double escapeProbability = normalProbability * ship->GetSpeed();

    if (randomNumber > escapeProbability) {
        ship->UpdateHeath();
    }


    return asteroidBelt;
}


