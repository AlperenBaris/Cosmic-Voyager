//
// Created by alper on 12.03.2024.
//

#include "Ship.h"

constexpr int spentFuel = 33;

int Ship::GetFuel() const { return this->fuel; }
int Ship::GetMoney() const { return this->money; }
int Ship::GetHealth() const { return this->health; }


void Ship::UpdateFuel() { this->fuel -= spentFuel; }
void Ship::UpdateMoney(int moneyChange) { this->money += moneyChange; }
