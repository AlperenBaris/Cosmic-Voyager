#ifndef COSMIC_VOYAGER_NORMALSHIP_H
#define COSMIC_VOYAGER_NORMALSHIP_H

#include "Ship.h"

class NormalShip : public Ship //Inherited fast ship from ship class
{
public:
    NormalShip() : Ship(), speed{1} {}

    void UpdateHealth(int normalDamage) override
    {
        //Calculating health with the help of the amount of damage received for the normal ship
        int currentHealth = this->health - normalDamage;

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

#endif // COSMIC_VOYAGER_NORMALSHIP_H
