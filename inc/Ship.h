//
// Created by alper on 12.03.2024.
//

#ifndef COSMIC_VOYAGER_SHIP_H
#define COSMIC_VOYAGER_SHIP_H

/*In this section, the methods and parameters of the Ship class are defined*/
class Ship //Interface class
{
public:
    Ship() : fuel{100}, money{0}, health{100} {} //Initial values ​​of features
    virtual ~Ship() = default;
    virtual float GetSpeed() const = 0; //Pure virtual
    int GetFuel() const;
    int GetMoney() const;
    int GetHealth() const;
    void UpdateFuel();
    void UpdateMoney(int moneyChange);
    virtual void UpdateHealth(int normalDamage) = 0; //Pure virtual 

protected:
    int fuel;
    int money;
    int health;
private:
};

#endif // COSMIC_VOYAGER_SHIP_H
