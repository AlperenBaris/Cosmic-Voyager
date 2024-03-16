//
// Created by alper on 15.03.2024.
//

#ifndef COSMIC_VOYAGER_NORMALSHIP_H
#define COSMIC_VOYAGER_NORMALSHIP_H

#include "Ship.h"

class FastShip : public Ship {
public:
    NormalShip() : Ship(), speed{1} {}
    void UpdateHealth(int normalDamage)
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
protected:
private:


};


#endif //COSMIC_VOYAGER_NORMALSHIP_H
