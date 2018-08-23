#include <iostream>
#include <string>
#include "Weapon.h"

using namespace std;

//default constructor
Weapon::Weapon() {
	accuracy = 0;
	damage = 0;
	weaponType = "NO Weapon";
	condition = 100;
}

//overloaded Weapon constructor
Weapon::Weapon(string wep, int d) {
	damage = d;
	weaponType = wep;
	condition = 100;
}

//deconstructor
Weapon::~Weapon() {
}

//getters
int Weapon::getDamage() {
	return damage;
}
string Weapon::getWeaponType() {
	return weaponType;
}
int Weapon::getCondition() {
	return condition;
}

//Mutators / setters
void Weapon::setDamage(int d) {
	damage = d;
}
void Weapon::setWeaponType(string wt) {
	weaponType = wt;
}
void Weapon::setCondition(int c) {
	condition = c;
}

void Weapon::decreaseCondition() {
	condition -= 10;
	if (condition < 1) {
		cout << "Your weapon needs to be repaired!" << endl;
	}
}