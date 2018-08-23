//Warrior header
#pragma once
#include <string>
#include "Weapon.h"
#include "Player.h"

//FUNCTIONAL CLASS AS OF 7/31/2018

using namespace std;

class Warrior : public Player {
	private:
		Weapon sword;
		string name;
		string classType;
		int damage;
	public:
		//default constructor
		Warrior(string n);

		//tostring
		string toString();

		//destructor
		~Warrior();

		//getter Method for weapon
		Weapon& getWeapon();
		string getClass();

		void fight(Player &p);

};
