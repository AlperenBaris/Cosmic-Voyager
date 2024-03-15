//
// Created by alper on 15.03.2024.
//

#ifndef COSMIC_VOYAGER_FASTSHIP_H
#define COSMIC_VOYAGER_FASTSHIP_H

#include "Ship.h"

class FastShip : public Ship {
public:
    FastShip() : Ship(), speed{1.5} {}
    void UpdateHealth(int normalDamage) { this->health -= normalDamage * 1.5;}
protected:
private:


};



#endif //COSMIC_VOYAGER_FASTSHIP_H
