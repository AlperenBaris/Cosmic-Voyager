#include "/inc/Printer.h"
#include "inc/GameStateEnum.h"
#include "inc/GameLoop.h"
#include "inc/Ship.h"
#include "inc/EventHandler.h"
#include <memory>

int main()
{
    GameState state = proceed;
    std::unique_ptr<Printer> printer(new Printer());
    std::unique_ptr<GameLoop> gameLoop(new GameLoop());
    std::unique_ptr<EventHandler> eventHandler(new EventHandler());
    std::unique_ptr<Ship> ship(nullptr);

    int eventCounter = 0;
    while (state == proceed)
    {
        if (eventCounter == 0)
        {
            printer->PrintWelcomeMessage();
            gameLoop->getInput();
            ship = gameLoop->selectShip(); // Buraya bak hata verebilir mi diye
        }

        eventHandler->EventRandomizer();
        eventCounter++;

        if (ship->GetHealth() <= 0 || ship->GetFuel() <= 0)
        {
            state = lose;
        }
        else if (eventCounter == 5)
        {
            state = win;
        }
    }

    printer->PrintEndingMessage(state);

}