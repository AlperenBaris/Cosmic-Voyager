//
// Created by alper on 12.03.2024.
//

#ifndef COSMIC_VOYAGER_SHIP_H
#define COSMIC_VOYAGER_SHIP_H

class Ship
{
public:
    Ship() : fuel{100}, money{0}, health{100} {}
    float GetSpeed() const;
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
    float speed;

private:
};

#endif // COSMIC_VOYAGER_SHIP_H
