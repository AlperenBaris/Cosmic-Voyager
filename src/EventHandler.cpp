//
// Created by alper on 12.03.2024.
//

#include "EventHandler.h"
#include "Ship.h"
#include "Printer.h"
#include <string>
#include <random>


const double normalProbability = 0.5;
const double dealProbability = 0.333;
const int gainedMoney = 10;
const int piratesDamage = 30;
const int asteroidDamage = 10;
const int lowLose = -10;
const int mediumLose = -20;
const int highLose = -30;

void EventHandler::AsteroidBelt(Ship *ship)
{
    Printer::PrintAsteroidASCII();

    std::random_device rd;
    std::mt19937 gen(rd()); // Güvenli rastgele sayı üreteci
    std::uniform_real_distribution<double> dis(0.0, 1.0);

    const double randomNumber = dis(gen);

    const double escapeProbability = normalProbability * ship->GetSpeed();

    if (randomNumber > escapeProbability)
    {
        std::cout << "Hasar aldınız!"
                  << "\n";
        ship->UpdateHealth(asteroidDamage);
    }
}

void EventHandler::AbandonedPlanet(Ship *ship)
{
    Printer::PrintPlanetASCII();

    std::random_device rd;
    std::mt19937 gen(rd()); // Güvenli rastgele sayı üreteci
    std::uniform_real_distribution<double> dis(0.0, 1.0);

    const double randomNumber = dis(gen);

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
        EventHandler::SpacePirates(ship);
    }
}

void EventHandler::SpacePirates(Ship *ship)
{
    static int runFlag = 0;
    static int dealFlag = 0;

    Printer::PrintPiratesASCII();
    std::string spacePiratesChoice;

    if (runFlag == 0 && dealFlag == 0)
    {
        std::cout << "Kaç Savaş ya da Pazarlık Et!"
                  << "\n";
    }
    else if (runFlag == 0 && dealFlag == 1)
    {
        std::cout << "Kaç ya da Savaş!"
                  << "\n";
    }
    else if (runFlag == 1 && dealFlag == 0)
    {
        std::cout << "Savaş ya da Pazarlık Et!"
                  << "\n";
    }
    else if (runFlag == 1 && dealFlag == 1)
    {
        std::cout << "Tek Seçeneğin Savaşmak!"
                  << "\n";
    }

    std::cin >> spacePiratesChoice;

    if (spacePiratesChoice == "Run")
    {
        if (runFlag == 0)
        {
            if (ship->GetFuel() < 33)
            {
                std::cout << "Yeterli yakıtınız bulunmamaktadır!"
                          << "\n";
                runFlag = 1;
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
                    std::cout << "Kaçamadınız!"
                              << "\n";
                    EventHandler::SpacePirates(ship);
                }
                else
                {
                    std::cout << "Kaçtınız!"
                              << "\n";
                    dealFlag = 0;
                }
            }
        }
        else
        {
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
            std::cout << "Savaşı Kaybettiniz!"
                      << "\n";
            ship->UpdateHealth(piratesDamage);
        }
        else
        {
            std::cout << "Savaşı Kazandınız!"
                      << "\n";
        }

        runFlag = 0;
        dealFlag = 0;
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
                    EventHandler::SpacePirates(ship);
                }
                else
                {
                    std::cout << "10 Altın kaybettiniz!"
                              << "\n";
                    ship->UpdateMoney(lowLose);
                    runFlag = 0;
                }
            }
            else if (randomNumber < dealProbability * 2)
            {
                if(ship->GetMoney() < 20)
                {
                    dealFlag = 1;
                    EventHandler::SpacePirates(ship);
                }
                else
                {
                    std::cout << "20 Altın kaybettiniz!"
                              << "\n";
                    ship->UpdateMoney(mediumLose);
                    runFlag = 0;
                }
            }
            else
            {
                if(ship->GetMoney() < 30)
                {
                    dealFlag = 1;
                    EventHandler::SpacePirates(ship);
                }
                else
                {
                    std::cout << "30 Altın kaybettiniz!"
                              << "\n";
                    ship->UpdateMoney(highLose);
                    runFlag = 0;
                }
            }
        }
        else
        {
            EventHandler::SpacePirates(ship);
        }

    }
}

void EventHandler::EventRandomizer(Ship* ship)
{
    std::random_device rd;
    std::mt19937 gen(rd()); // Rastgele sayı üreteci başlatılıyor
    std::uniform_int_distribution<int> dis(0, 2);

    int randomNumber = dis(gen); // This generates number from 0 to 2

    if (randomNumber == 0)
    {
        EventHandler::AsteroidBelt(ship); // EventHandler::AsteroidBelt de olabilir buna sonra bak hata veriyor mu diye !!!!!!
    }
    else if (randomNumber == 1)
    {
        EventHandler::AbandonedPlanet(ship); // EventHandler::AbandonedPlanet de olabilir buna sonra bak hata veriyor mu diye !!!!!!
    }
    if (randomNumber == 2)
    {
        EventHandler::SpacePirates(ship); // EventHandler::SpacePirates de olabilir buna sonra bak hata veriyor mu diye !!!!!!
    }
}
