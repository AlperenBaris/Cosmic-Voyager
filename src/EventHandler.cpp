//
// Created by alper on 12.03.2024.
//

#include "../inc/EventHandler.h"
#include "../inc/EventEnums.h"
#include "Ship.cpp"
#include <cstdlib>
#include <ctime>

const double normalProbability = 0.5;

Events EventHandler::AsteroidBelt(Ship *ship)
{
    srand(time(0));
    const double randomNumber = ((double)rand() / RAND_MAX);
    const double escapeProbability = normalProbability * ship->GetSpeed();

    if (randomNumber > escapeProbability)
    {
        ship->UpdateHealth();
    }
}

Events EventHandler::AbandonedPlanet(Ship *ship)
{
    srand(time(0));
    const double randomNumber = ((double)rand() / RAND_MAX);

    if (randomNumber < normalProbability)
    {
        ship->UpdateMoney(10);
    }
    else
    {
        SpacePirates(ship);
    }
}

Events EventHandler::SpacePirates(Ship *ship)
{
    string spacePiratesChoice;
    std::cout << "Kaç Savaş ya da Pazarlık Et!"
              << "\n";
    getline(cin, spacePiratesChoice, ' ');

    if (spacePiratesChoice.compare("Kaç") == 0)
    {
        if (ship->GetFuel() < 33)
        {
            std::cout << "Yeterli yakıtınız bulunmamaktadır!"
                      << "\n";
            // check for next option (savas or pazarlık et)
        }
        else
        {
            ship->UpdateFuel();
            srand(time(0));
            const double randomNumber = ((double)rand() / RAND_MAX);
            const double escapeProbability = normalProbability * ship->GetSpeed();
            if (randomNumber > escapeProbability)
            {
                SpacePirates(ship);
            }
        }
    }

    else if (spacePiratesChoice.compare("Savaş") == 0)
    {
        srand(time(0));
        const double randomNumber = ((double)rand() / RAND_MAX);
        if (randomNumber < normalProbability)
        {
            ship->UpdateHealth();
        }
        }
    else if (spacePiratesChoice.compare("Pazarlık Et") == 0)
    {
       // ship->UpdateMoney(); // 102030??
    }

    return spacePirates;
}
