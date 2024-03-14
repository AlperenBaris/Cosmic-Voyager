//
// Created by alper on 12.03.2024.
//

#ifndef COSMIC_VOYAGER_EVENTHANDLER_H
#define COSMIC_VOYAGER_EVENTHANDLER_H

#include "EventEnums.h"
#include <string>
#include <iostream>

using namespace std;


class EventHandler {
public:
    Events AsteroidBelt(Ship* ship);
    Events AbandonedPlanet(Ship* ship);
    Events SpacePirates(Ship* ship, bool flag = 0);
protected:
private:

};

#endif //COSMIC_VOYAGER_EVENTHANDLER_H
