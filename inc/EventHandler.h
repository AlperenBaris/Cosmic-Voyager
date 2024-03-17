#ifndef COSMIC_VOYAGER_EVENTHANDLER_H
#define COSMIC_VOYAGER_EVENTHANDLER_H

#include <string>
#include <iostream>
#include "Ship.h"
#include <memory>


/*In this section, the methods and parameters of the EventHandler class are defined*/
class EventHandler {
public:
    static void AsteroidBelt(const std::shared_ptr<Ship>& ship);
    static void AbandonedPlanet(const std::shared_ptr<Ship>& ship);
    static void SpacePirates(const std::shared_ptr<Ship>& ship);
    static void EventRandomizer(const std::shared_ptr<Ship>& ship);
protected:
private:

};

#endif //COSMIC_VOYAGER_EVENTHANDLER_H
