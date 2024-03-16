//
// Created by alper on 15.03.2024.
//

#ifndef COSMIC_VOYAGER_STRONGSHIP_H
#define COSMIC_VOYAGER_STRONGSHIP_H

#include "Ship.h"

class StrongShip : public Ship {
public:
    StrongShip() : Ship(), speed{0.5} {}

    void UpdateHealth(int normalDamage) override
    {
        int currentHealth = this->health - static_cast<int>(normalDamage * 0.5);

        if(currentHealth <= 0)
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

#endif //COSMIC_VOYAGER_STRONGSHIP_H
