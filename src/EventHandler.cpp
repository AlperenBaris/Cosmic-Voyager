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
        std::cout << "Hasar aldınız!"
                  << "\n";
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
        std::cout << "Altın kazandınız!"
                  << "\n";
        ship->UpdateMoney(gainedMoney);
    }
    else
    {
        std::cout << "Altın kazananmadınız, uzay korsanlarına geçiş!"
                  << "\n";
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
                    std::cout << "Kaçamadınız!"
                              << "\n";
                    SpacePirates(ship, 0);
                }
                else
                {
                    std::cout << "Kaçtınız!"
                              << "\n";
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
            std::cout << "10 Altın kazandınız!"
                      << "\n";
            ship->UpdateMoney(lowLose);
        }
        else if (randomNumber < dealProbability * 2)
        {
            std::cout << "20 Altın kazandınız!"
                      << "\n";
            ship->UpdateMoney(mediumLose);
        }
        else
        {
            std::cout << "30 Altın kazandınız!"
                      << "\n";
            ship->UpdateMoney(highLose);
        }
    }

    return spacePirates;
}

void EventHandler::EventRandomizer()
{
    srand(time(0));

    int randomNumber = rand() % 3; // This generates number from 0 to 2

    if (randomNumber == 0)
    {
        EventHandler::AsteroidBelt(); // EventHandler::AsteroidBelt de olabilir buna sonra bak hata veriyor mu diye !!!!!!
    }
    else if (randomNumber == 1)
    {
        EventHandler::AbandonedPlanet(); // EventHandler::AbandonedPlanet de olabilir buna sonra bak hata veriyor mu diye !!!!!!
    }
    if (randomNumber == 2)
    {
        EventHandler::SpacePirates(); // EventHandler::SpacePirates de olabilir buna sonra bak hata veriyor mu diye !!!!!!
    }
}
