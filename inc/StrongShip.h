#ifndef COSMIC_VOYAGER_STRONGSHIP_H
#define COSMIC_VOYAGER_STRONGSHIP_H

#include "Ship.h"

class StrongShip : public Ship //Inherited strong ship from ship class
{
public:
    StrongShip() : Ship(), speed{0.5} {}

    void UpdateHealth(int normalDamage) override
    {
        //Calculating health with the help of the amount of damage received for the strong ship
        int currentHealth = this->health - static_cast<int>(normalDamage * 0.5);

        // Health is clamped to 0

        if (currentHealth <= 0)
        {
            this->health = 0;
        }
        else
        {
            this->health = currentHealth;
        }
    }

    float GetSpeed() const override { return this->speed; }

protected:
private:
    float speed;
};

#endif // COSMIC_VOYAGER_STRONGSHIP_H
