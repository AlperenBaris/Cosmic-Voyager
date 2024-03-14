//
// Created by alper on 12.03.2024.
//

#include "../inc/Ship.h"

constexpr int spentFuel = 33;


float Ship::GetSpeed() const { return this->propertyCoefficient; }
float Ship::GetFuel() const { return this->fuel; }
float Ship::GetMoney() const { return this->money; }
float Ship::GetHealth() const { return this->health; }


void Ship::UpdateFuel() { this->fuel -= spentFuel; }
void Ship::UpdateMoney(int moneyChange) { this->money += moneyChange; }
void Ship::UpdateHealth(int normalDamage) { this->health -= this->propertyCoefficient*normalDamage;}
