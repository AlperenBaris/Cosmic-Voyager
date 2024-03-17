#include "Ship.h"

constexpr int spentFuel = 33; //Defined variable to avoid magic number

int Ship::GetFuel() const { return this->fuel; } //Function that shows remaining fuel
int Ship::GetMoney() const { return this->money; } //Function that shows remaining gold
int Ship::GetHealth() const { return this->health; } //Function that shows remaining health


void Ship::UpdateFuel() { this->fuel -= spentFuel; } //Function that updates fuel
void Ship::UpdateMoney(int moneyChange) { this->money += moneyChange; } // Function that updates gold
