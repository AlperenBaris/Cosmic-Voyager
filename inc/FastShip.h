#ifndef COSMIC_VOYAGER_FASTSHIP_H
#define COSMIC_VOYAGER_FASTSHIP_H

#include "Ship.h"

class FastShip : public Ship //Inherited fast ship from ship class
{
public:
    FastShip() : Ship(), speed{1.5} {};

    void UpdateHealth(int normalDamage) override 
    {
        //Calculating health with the help of the amount of damage received for the fast ship
        int currentHealth = this->health - static_cast<int>(normalDamage * 1.5);

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

#endif // COSMIC_VOYAGER_FASTSHIP_H
