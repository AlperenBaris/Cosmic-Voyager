//
// Created by alper on 12.03.2024.
//

#include "../inc/EventHandler.h"
#include "../inc/EventEnums.h"
#include "Ship.cpp"
#include <cstdlib>
#include <ctime>

const double normalProbability = 0.5;
const double dealProbability = 0.333;
const int gainedMoney = 10;
const int piratesDamage = 30;
const int asteroidDamage = 10;
const int lowLose = -10;
const int mediumLose = -20;
const int highLose = -30;

Events EventHandler::AsteroidBelt(Ship *ship)
{
    srand(time(0));
    const double randomNumber = ((double)rand() / RAND_MAX);
    const double escapeProbability = normalProbability * ship->GetSpeed();

    if (randomNumber > escapeProbability)
    {
        ship->UpdateHealth(asteroidDamage);
    }
    return asteroidBelt;
}

Events EventHandler::AbandonedPlanet(Ship *ship)
{
    srand(time(0));
    const double randomNumber = ((double)rand() / RAND_MAX);

    if (randomNumber < normalProbability)
    {
        ship->UpdateMoney(gainedMoney);
    }
    else
    {
        SpacePirates(ship);
    }
    return abandonedPlanet;
}

Events EventHandler::SpacePirates(Ship *ship, bool flag = 0)
{
    string spacePiratesChoice;

    if (flag == 0)
    {
        std::cout << "Kaç Savaş ya da Pazarlık Et!"
              << "\n";
    }
    else
    {
        std::cout << "Savaş ya da Pazarlık Et!"
              << "\n";
    }
    
    getline(cin, spacePiratesChoice, ' ');

    if (spacePiratesChoice.compare("Kaç") == 0)
    {
        if (flag == 0)
        {
            if (ship->GetFuel() < 33)
            {
                std::cout << "Yeterli yakıtınız bulunmamaktadır!"
                          << "\n";
                SpacePirates(ship, 1);
            }
            else
            {
                ship->UpdateFuel();
                srand(time(0));
                const double randomNumber = ((double)rand() / RAND_MAX);
                const double escapeProbability = normalProbability * ship->GetSpeed();
                if (randomNumber > escapeProbability)
                {
                    SpacePirates(ship, 0);
                }
            }
        }
        else
        {
            SpacePirates(ship, 1);
        }
        
    }

    else if (spacePiratesChoice.compare("Savaş") == 0)
    {
        srand(time(0));
        const double randomNumber = ((double)rand() / RAND_MAX);
        if (randomNumber < normalProbability)
        {
            std::cout << "Savaşı Kaybettiniz!"
                      << "\n";
            ship->UpdateHealth(piratesDamage);
        }
        else
        {
            std::cout << "Savaşı Kazandınız!"
                      << "\n";
        }
    }
    else if (spacePiratesChoice.compare("Pazarlık Et") == 0)
    {
        srand(time(0));
        const double randomNumber = ((double)rand() / RAND_MAX);
        if (randomNumber < dealProbability)
        {
            ship->UpdateMoney(lowLose);
        }
        else if (randomNumber < dealProbability * 2)
        {
            ship->UpdateMoney(mediumLose);
        }
        else
        {
            ship->UpdateMoney(highLose);
        }
    }

    return spacePirates;
}
