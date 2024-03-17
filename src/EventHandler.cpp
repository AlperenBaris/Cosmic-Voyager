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

// Base numbers required to avoid magic numbers in the code
const double normalProbability = 0.5;
const double dealProbability = 0.333;
const int gainedMoney = 10;
const int piratesDamage = 30;
const int asteroidDamage = 10;
const int lowLose = -10;
const int mediumLose = -20;
const int highLose = -30;

void EventHandler::AsteroidBelt(const std::shared_ptr<Ship>& ship) //Asteroid belt event 
{
    Printer::PrintAsteroidASCII();

    std::random_device rd; //Uniformly distributed integer random number generator parameter
    std::mt19937 gen(rd()); //That produces 32 bit random numbers using the well-known algorithm named Mersenne Twister (more safer)
    std::uniform_real_distribution<double> dis(0.0, 1.0); //Lowest and uppest boundaries

    const double randomNumber = dis(gen);

    const double escapeProbability = normalProbability * ship->GetSpeed(); //Probablibity of escape by ship type

    if (randomNumber > escapeProbability) //Ship can not escape
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

void EventHandler::AbandonedPlanet(const std::shared_ptr<Ship>& ship) //Abandoned planet event 
{
    Printer::PrintPlanetASCII();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);

    const double randomNumber = dis(gen);

    if (randomNumber < normalProbability) // Gaining gold with 50% probability
    {
        std::cout << "Gained 10 Gold!"
                  << "\n";
        ship->UpdateMoney(gainedMoney);
    }
    else // 50% chance of switching to space pirates
    {
        std::cout << "You Faced Against Space Pirates!"
                  << "\n";

        std::this_thread::sleep_for(std::chrono::seconds(2));

        EventHandler::SpacePirates(ship);
    }
}

void EventHandler::SpacePirates(const std::shared_ptr<Ship>& ship) //Spece pirates event 
{
    //Flags that required for some important conditions
    static int runFlag = 0;
    static int dealFlag = 0;
    static int messageFlag = 1;

    if (messageFlag == 1)
    {
        Printer::PrintPiratesASCII();
    }

    std::string spacePiratesChoice;

    if (runFlag == 0 && dealFlag == 0) //Sufficient fuel and gold
    {
        std::cout << "Run, Fight Or Deal!"
                  << "\n";
    }
    else if (runFlag == 0 && dealFlag == 1) //Inadequate gold
    {
        std::cout << "Run Or Fight!"
                  << "\n";
    }
    else if (runFlag == 1 && dealFlag == 0) //Inadequate fuel
    {
        std::cout << "Fight Or Deal!"
                  << "\n";
    }
    else if (runFlag == 1 && dealFlag == 1) //Inadequate gold and fuel
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
                ship->UpdateFuel(); //Fuel is reduced by 33

                std::random_device rd;
                std::mt19937 gen(rd()); 
                std::uniform_real_distribution<double> dis(0.0, 1.0);

                const double randomNumber = dis(gen);
                const double escapeProbability = normalProbability * ship->GetSpeed();
                if (randomNumber > escapeProbability) //Can not escape by ship type 
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
                else //Escape probability by ship type 
                {
                    std::cout << "You Escaped!"
                              << "\n";
                    dealFlag = 0;
                    messageFlag = 1;
                }
            }
        }
        else //Unwanted data entry
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
        std::mt19937 gen(rd()); 
        std::uniform_real_distribution<double> dis(0.0, 1.0);

        const double randomNumber = dis(gen);

        if (randomNumber < normalProbability) //Lost fight with 50% probability
        {
            std::cout << "You Lost Fight!"
                      << "\n";
            ship->UpdateHealth(piratesDamage); //Taken damage by ship type
        }
        else //Winning fight with 50% probability
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
            std::mt19937 gen(rd()); 
            std::uniform_real_distribution<double> dis(0.0, 1.0);

            const double randomNumber = dis(gen);

            if (randomNumber < dealProbability) // If 10 gold coins arrive probabilistically, check the register condition.
            {
                if(ship->GetMoney() < 10) //Insufficient gold
                {
                    dealFlag = 1;
                    messageFlag = 0;

                    std::cout << "You Do Not Have Sufficient Gold!"
                              << "\n";

                    EventHandler::SpacePirates(ship);
                }
                else //Deal completed
                {
                    std::cout << "You Lost 10 Gold!" 
                              << "\n";
                    ship->UpdateMoney(lowLose);
                    runFlag = 0;
                    messageFlag = 1;
                }
            }
            else if (randomNumber < dealProbability * 2) //If 20 gold coins arrive probabilistically, check the register condition.
            {
                if(ship->GetMoney() < 20) //Insufficient gold
                {
                    dealFlag = 1;
                    messageFlag = 0;

                    std::cout << "You Do Not Have Sufficient Gold!"
                              << "\n";

                    EventHandler::SpacePirates(ship);
                }
                else //Deal completed
                {
                    std::cout << "You Lost 20 Gold!"
                              << "\n";
                    ship->UpdateMoney(mediumLose);
                    runFlag = 0;
                    messageFlag = 1;
                }
            }
            else //If 30 gold coins arrive probabilistically, check the register condition.
            {
                if(ship->GetMoney() < 30) //Insufficient gold
                {
                    dealFlag = 1;
                    messageFlag = 0;

                    std::cout << "You Do Not Have Sufficient Gold!"
                              << "\n";

                    EventHandler::SpacePirates(ship);
                }
                else //Deal completed
                {
                    std::cout << "You Lost 30 Gold!"
                              << "\n";
                    ship->UpdateMoney(highLose);
                    runFlag = 0;
                    messageFlag = 1;
                }
            }
        }
        else //Unwanted data entry
        {
            std::cout << "You Can Not Select This Action!"
                      << "\n";
            messageFlag = 0;
            EventHandler::SpacePirates(ship);
        }

    }
    else //No action condition
    {
        std::cout << "There is No Action!"
                  << "\n";
        messageFlag = 0;
        EventHandler::SpacePirates(ship);
    }
}

void EventHandler::EventRandomizer(const std::shared_ptr<Ship>& ship) //Function that determines which event will occur
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 2);

    int randomNumber = dis(gen); // Generating a number from 0 to 2

    //For the situation where every event can occur with equal probability

    if (randomNumber == 0) //If generated number is 0 (33.3%)
    {
        EventHandler::AsteroidBelt(ship);
    }
    else if (randomNumber == 1) //If generated number is 1 (33.3%)
    {
        EventHandler::AbandonedPlanet(ship);
    }
    if (randomNumber == 2) //If generated number is 2 (33.3%)
    {
        EventHandler::SpacePirates(ship);
    }
}
