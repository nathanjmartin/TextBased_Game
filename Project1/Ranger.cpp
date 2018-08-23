//Ranger.cpp

#include "Ranger.h"
#include <iostream>
#include <string>

//FUNCTIONAL AS OF 7/31/2018


using namespace std;

//CONSTRUCTOR
//Constructor takes the string 'n' parameter and passes it to the Player constructor.


Ranger::Ranger(string n) : Player(n) {
	//'Player.name = n'
	name = n;
	bow = Weapon("Bow", 10);
	classType = "Ranger";
	damage = bow.getDamage();
}


//DESTRUCTOR
Ranger::~Ranger() {
}

//GETTER METHOD 
Weapon& Ranger::getWeapon() {
	return bow;
}



string Ranger::getClass() {
	return classType;
}


void Ranger::fight(Player &p) {
	if (this->getHP() > 0 && p.getHP() > 0) {
		cout << this->name << " hit " << p.getName() << " for " << damage << " with a " << bow.getWeaponType() << "!" << endl;
		p.setHP(p.getHP() - this->getWeapon().getDamage());
	}

	if (this->getHP() > 0 && p.getHP() <= 0) {
		p.setHP(0);
		cout << name << " won!" << endl;
		bow.decreaseCondition();

		if (this->getLevel() < 5) {
			gainXp(p.getExperienceWorth());
			levelUp();
		}
	}
}