//
// Created by alper on 12.03.2024.
//

#ifndef COSMIC_VOYAGER_EVENTHANDLER_H
#define COSMIC_VOYAGER_EVENTHANDLER_H

#include <string>
#include <iostream>
#include "Ship.h"



class EventHandler {
public:
    void AsteroidBelt(Ship* ship);
    void AbandonedPlanet(Ship* ship);
    void SpacePirates(Ship* ship);
    void EventRandomizer(Ship* ship);
protected:
private:

};

#endif //COSMIC_VOYAGER_EVENTHANDLER_H
