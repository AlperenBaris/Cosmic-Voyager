//
// Created by alper on 12.03.2024.
//

#ifndef COSMIC_VOYAGER_SHIP_H
#define COSMIC_VOYAGER_SHIP_H

class Ship
{
public:
    float GetSpeed() const = 0;
    float GetFuel() const;
    float GetMoney() const;
    float GetHealth() const;
    void UpdateFuel();
    void UpdateMoney(int moneyChange);
    void UpdateHealth(int normalDamage) = 0;

protected:
    float fuel;
    float money;
    float health;

private:
};

#endif // COSMIC_VOYAGER_SHIP_H
