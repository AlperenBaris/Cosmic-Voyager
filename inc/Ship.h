//
// Created by alper on 12.03.2024.
//

#ifndef COSMIC_VOYAGER_SHIP_H
#define COSMIC_VOYAGER_SHIP_H

class Ship {
public:
    float GetTakenDamage();
    float GetSpeed();
    float GetFuel();
    float GetMoney(int moneyChange);
    float GetHeath();
    void UpdateFuel();
    void UpdateMoney();
    void UpdateHeath();

protected:
    float takenDamage;
    float speed;
    float fuel;
    float money;
    float heath;
private:

};







#endif //COSMIC_VOYAGER_SHIP_H
