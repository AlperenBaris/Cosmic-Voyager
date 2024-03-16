//
// Created by alper on 15.03.2024.
//

#ifndef COSMIC_VOYAGER_NORMALSHIP_H
#define COSMIC_VOYAGER_NORMALSHIP_H

#include "Ship.h"

class NormalShip : public Ship {
public:
    NormalShip() : Ship(), speed{1} {}

    void UpdateHealth(int normalDamage) override
    {
        int currentHealth = this->health - normalDamage;

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


#endif //COSMIC_VOYAGER_NORMALSHIP_H
