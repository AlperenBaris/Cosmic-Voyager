//
// Created by alper on 12.03.2024.
//

#ifndef COSMIC_VOYAGER_SHIP_H
#define COSMIC_VOYAGER_SHIP_H

class Ship
{
public:
    Ship() : fuel{100}, money{0}, health{100} {}
    virtual ~Ship() = default;
    virtual float GetSpeed() const = 0;
    int GetFuel() const;
    int GetMoney() const;
    int GetHealth() const;
    void UpdateFuel();
    void UpdateMoney(int moneyChange);
    virtual void UpdateHealth(int normalDamage) = 0;

protected:
    int fuel;
    int money;
    int health;
private:
};

#endif // COSMIC_VOYAGER_SHIP_H
