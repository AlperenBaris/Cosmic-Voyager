//
// Created by alper on 12.03.2024.
//

#ifndef COSMIC_VOYAGER_EVENTHANDLER_H
#define COSMIC_VOYAGER_EVENTHANDLER_H

#include "EventEnums.h"


class EventHandler {
public:
    Events AsteroidBelt(Ship* ship);
    Events AbandonedPlanet(Ship* ship);
    Events SpacePirates(Ship* ship);
protected:
private:

};

#endif //COSMIC_VOYAGER_EVENTHANDLER_H
