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
    std::shared_ptr<Ship> ship = nullptr; // Allocating space from memory for the ship to be selected

    int eventCounter = 0; // When it reaches 5 the game will be over
    while (state == proceed)
    {
        if (eventCounter == 0) // Game starts
        {
            Printer::PrintWelcomeMessage();
            GameLoop::GetInput();
            ship = GameLoop::SelectShip(); // Assign the selected ship to "ship" value
        }

        // Sleep terminal for 2 seconds to avoiding text overlapping
        std::this_thread::sleep_for(std::chrono::seconds(2));

        EventHandler::EventRandomizer(ship); // Random event occurrence
        eventCounter++;

        // Sleep terminal again for 2 seconds to avoiding text overlapping
        std::this_thread::sleep_for(std::chrono::seconds(2));

        // Print the status of ship
        Printer::PrintStatus(ship);

        if (ship->GetHealth() <= 0 || ship->GetFuel() <= 0) // Losing condition (If fuel or currency drops below zero)
        {
            state = lose;
        }
        else if (eventCounter == 5) // Winnig condition
        {
            state = win;
        }
    }

    Printer::PrintEndingMessage(state, ship); // Game ends
}