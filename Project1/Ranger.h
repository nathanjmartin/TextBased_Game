//Ranger Header

#pragma once
#include <string>
#include "Weapon.h"
#include "Player.h"

//FUNCTIONAL CLASS AS OF 7/31/2018

using namespace std;

class Ranger : public Player {
private:
	Weapon bow;
	string name;
	string classType;
	int damage;

public:
	//default constructor
	Ranger(string n);

	//destructor
	~Ranger();

	//getter Method for weapon
	Weapon& getWeapon();
	string getClass();

	//tostring
	string toString();

	void fight(Player &p);
};
