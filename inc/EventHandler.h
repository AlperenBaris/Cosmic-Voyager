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
    void AsteroidBelt(Ship* ship);
    void AbandonedPlanet(Ship* ship);
    void SpacePirates(Ship* ship);
    void EventRandomizer();
protected:
private:

};

#endif //COSMIC_VOYAGER_EVENTHANDLER_H
