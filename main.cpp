#include "Printer.h"
#include "GameStateEnum.h"
#include "GameLoop.h"
#include "Ship.h"
#include "EventHandler.h"
#include <memory>
#include <chrono>
#include <thread>

int main()
{
    GameState state = proceed;
    std::shared_ptr<Ship> ship = nullptr;

    int eventCounter = 0;
    while (state == proceed)
    {
        if (eventCounter == 0)
        {
            Printer::PrintWelcomeMessage();
            GameLoop::GetInput();
            ship = GameLoop::SelectShip();
        }

        std::this_thread::sleep_for(std::chrono::seconds(2));

        EventHandler::EventRandomizer(ship);
        eventCounter++;

        std::this_thread::sleep_for(std::chrono::seconds(2));

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

}