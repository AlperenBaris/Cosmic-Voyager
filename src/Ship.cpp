//
// Created by alper on 12.03.2024.
//

#include "../inc/Ship.h"

constexpr int spentFuel = 33;

float Ship::GetTakenDamage() { return this->takenDamage; }
float Ship::GetSpeed() { return this->speed; }
float Ship::GetFuel() { return this->fuel; }
float Ship::GetMoney() { return this->money; }
float Ship::GetHeath() { return this->heath; }


void Ship::UpdateFuel() { this->fuel -= spentFuel; }
void Ship::UpdateMoney(int moneyChange) { this->money += moneyChange; }
void Ship::UpdateHeath() { this->heath -= this->takenDamage; }