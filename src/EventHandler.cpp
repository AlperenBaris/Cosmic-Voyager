//
// Created by alper on 12.03.2024.
//

#include "EventHandler.h"
#include "Ship.h"
#include "Printer.h"
#include <string>
#include <random>
#include <memory>
#include <chrono>
#include <thread>


const double normalProbability = 0.5;
const double dealProbability = 0.333;
const int gainedMoney = 10;
const int piratesDamage = 30;
const int asteroidDamage = 10;
const int lowLose = -10;
const int mediumLose = -20;
const int highLose = -30;

void EventHandler::AsteroidBelt(const std::shared_ptr<Ship>& ship)
{
    Printer::PrintAsteroidASCII();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);

    const double randomNumber = dis(gen);

    const double escapeProbability = normalProbability * ship->GetSpeed();

    if (randomNumber > escapeProbability)
    {
        std::cout << "Taken Damage!"
                  << "\n";
        ship->UpdateHealth(asteroidDamage);
    }
    else
    {
        std::cout << "You Escaped from Asteroid Belt successfully!"
                  << "\n";
    }
}

void EventHandler::AbandonedPlanet(const std::shared_ptr<Ship>& ship)
{
    Printer::PrintPlanetASCII();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);

    const double randomNumber = dis(gen);

    if (randomNumber < normalProbability)
    {
        std::cout << "Gained 10 Gold!"
                  << "\n";
        ship->UpdateMoney(gainedMoney);
    }
    else
    {
        std::cout << "You Faced Against Space Pirates!"
                  << "\n";

        std::this_thread::sleep_for(std::chrono::seconds(2));

        EventHandler::SpacePirates(ship);
    }
}

void EventHandler::SpacePirates(const std::shared_ptr<Ship>& ship)
{
    static int runFlag = 0;
    static int dealFlag = 0;
    static int messageFlag = 1;

    if (messageFlag == 1)
    {
        Printer::PrintPiratesASCII();
    }

    std::string spacePiratesChoice;

    if (runFlag == 0 && dealFlag == 0)
    {
        std::cout << "Run, Fight Or Deal!"
                  << "\n";
    }
    else if (runFlag == 0 && dealFlag == 1)
    {
        std::cout << "Run Or Fight!"
                  << "\n";
    }
    else if (runFlag == 1 && dealFlag == 0)
    {
        std::cout << "Fight Or Deal!"
                  << "\n";
    }
    else if (runFlag == 1 && dealFlag == 1)
    {
        std::cout << "Your Only Choice Is Fight!!!!"
                  << "\n";
    }

    std::cin >> spacePiratesChoice;

    if (spacePiratesChoice == "Run")
    {
        if (runFlag == 0)
        {
            if (ship->GetFuel() < 33)
            {
                std::cout << "You Do Not Have Sufficient Fuel!"
                          << "\n";
                runFlag = 1;
                messageFlag = 0;
                EventHandler::SpacePirates(ship);
            }
            else
            {
                ship->UpdateFuel();

                std::random_device rd;
                std::mt19937 gen(rd()); // Güvenli rastgele sayı üreteci
                std::uniform_real_distribution<double> dis(0.0, 1.0);

                const double randomNumber = dis(gen);
                const double escapeProbability = normalProbability * ship->GetSpeed();
                if (randomNumber > escapeProbability)
                {
                    std::cout << "You Did Not Escape!"
                              << "\n";

                    if (ship->GetFuel() < 33)
                    {
                        runFlag = 1;
                    }

                    messageFlag = 0;
                    EventHandler::SpacePirates(ship);
                }
                else
                {
                    std::cout << "You Escaped!"
                              << "\n";
                    dealFlag = 0;
                    messageFlag = 1;
                }
            }
        }
        else
        {
            std::cout << "You Can Not Select This Action!"
                      << "\n";
            messageFlag = 0;
            EventHandler::SpacePirates(ship);
        }
    }

    else if (spacePiratesChoice == "Fight")
    {
        std::random_device rd;
        std::mt19937 gen(rd()); // Güvenli rastgele sayı üreteci
        std::uniform_real_distribution<double> dis(0.0, 1.0);

        const double randomNumber = dis(gen);

        if (randomNumber < normalProbability)
        {
            std::cout << "You Lost Fight!"
                      << "\n";
            ship->UpdateHealth(piratesDamage);
        }
        else
        {
            std::cout << "You Won Fight!"
                      << "\n";
        }

        runFlag = 0;
        dealFlag = 0;
        messageFlag = 1;
    }
    else if (spacePiratesChoice == "Deal")
    {
        if (dealFlag == 0)
        {
            std::random_device rd;
            std::mt19937 gen(rd()); // Güvenli rastgele sayı üreteci
            std::uniform_real_distribution<double> dis(0.0, 1.0);

            const double randomNumber = dis(gen);

            if (randomNumber < dealProbability)
            {
                if(ship->GetMoney() < 10)
                {
                    dealFlag = 1;
                    messageFlag = 0;

                    std::cout << "You Do Not Have Sufficient Gold!"
                              << "\n";

                    EventHandler::SpacePirates(ship);
                }
                else
                {
                    std::cout << "You Lost 10 Gold!"
                              << "\n";
                    ship->UpdateMoney(lowLose);
                    runFlag = 0;
                    messageFlag = 1;
                }
            }
            else if (randomNumber < dealProbability * 2)
            {
                if(ship->GetMoney() < 20)
                {
                    dealFlag = 1;
                    messageFlag = 0;

                    std::cout << "You Do Not Have Sufficient Gold!"
                              << "\n";

                    EventHandler::SpacePirates(ship);
                }
                else
                {
                    std::cout << "You Lost 20 Gold!"
                              << "\n";
                    ship->UpdateMoney(mediumLose);
                    runFlag = 0;
                    messageFlag = 1;
                }
            }
            else
            {
                if(ship->GetMoney() < 30)
                {
                    dealFlag = 1;
                    messageFlag = 0;

                    std::cout << "You Do Not Have Sufficient Gold!"
                              << "\n";

                    EventHandler::SpacePirates(ship);
                }
                else
                {
                    std::cout << "You Lost 30 Gold!"
                              << "\n";
                    ship->UpdateMoney(highLose);
                    runFlag = 0;
                    messageFlag = 1;
                }
            }
        }
        else
        {
            std::cout << "You Can Not Select This Action!"
                      << "\n";
            messageFlag = 0;
            EventHandler::SpacePirates(ship);
        }

    }
    else
    {
        std::cout << "There is No Action!"
                  << "\n";
        messageFlag = 0;
        EventHandler::SpacePirates(ship);
    }
}

void EventHandler::EventRandomizer(const std::shared_ptr<Ship>& ship)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 2);

    int randomNumber = dis(gen); // This generates number from 0 to 2

    if (randomNumber == 0)
    {
        EventHandler::AsteroidBelt(ship);
    }
    else if (randomNumber == 1)
    {
        EventHandler::AbandonedPlanet(ship);
    }
    if (randomNumber == 2)
    {
        EventHandler::SpacePirates(ship);
    }
}
