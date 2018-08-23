//MAGE HEADER

#pragma once

#include <string>
#include "Weapon.h"
#include "Player.h"

//FUNCTIONAL CLASS AS OF 7/31/2018

using namespace std;

class Mage : public Player {
private:
	Weapon staff;
	string name;
	string classType;
	int damage;
public:
	//default constructor
	Mage(string n);

	//destructor
	~Mage();

	//getter Method for weapon
	Weapon& getWeapon();
	string getClass();

	//tostring
	string toString();

	void fight(Player &p);

};
