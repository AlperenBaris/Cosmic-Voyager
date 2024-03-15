//
// Created by alper on 15.03.2024.
//

#ifndef COSMIC_VOYAGER_NORMALSHIP_H
#define COSMIC_VOYAGER_NORMALSHIP_H

#include "Ship.h"

class FastShip : public Ship {
public:
    NormalShip() : Ship(), speed{1} {}
    void UpdateHealth(int normalDamage) { this->health -= normalDamage;}
protected:
private:


};


#endif //COSMIC_VOYAGER_NORMALSHIP_H
