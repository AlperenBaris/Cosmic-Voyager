#include "Printer.h"
#include "GameStateEnum.h"
#include "GameLoop.h"
#include "Ship.h"
#include "EventHandler.h"
#include <memory>

int main()
{
    GameState state = proceed;
    std::unique_ptr<EventHandler> eventHandler(new EventHandler());
    Ship* ship = nullptr;

    int eventCounter = 0;
    while (state == proceed)
    {
        if (eventCounter == 0)
        {
            Printer::PrintWelcomeMessage();
            GameLoop::GetInput();
            ship = GameLoop::SelectShip(); // Buraya bak hata verebilir mi diye
        }

        eventHandler->EventRandomizer();
        eventCounter++;

        Printer::PrintStatus(ship);

        if (ship->GetHealth() <= 0 || ship->GetFuel() <= 0)
        {
            state = lose;
        }
        else if (eventCounter == 5)
        {
            state = win;
        }


    }

    Printer::PrintEndingMessage(state, ship);

    delete ship;
}