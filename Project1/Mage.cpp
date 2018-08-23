#include "Mage.h"
#include <iostream>
#include <string>

//FUNCTIONAL AS OF 7/31/2018


using namespace std;

//CONSTRUCTOR
//Constructor takes the string 'n' parameter and passes it to the Player constructor.


Mage::Mage(string n) : Player(n) {
	//'Player.name = n'
	name = n;
	staff = Weapon("Staff", 15);
	classType = "Mage";
	damage = staff.getDamage();
}


//DESTRUCTOR
Mage::~Mage() {
}

//GETTER METHOD 
Weapon& Mage::getWeapon() {
	return staff;
}

string Mage::getClass() {
	return classType;
}


void Mage::fight(Player &p) {
	if (this->getHP() > 0 && p.getHP() > 0) {
		cout << this->name << " hit " << p.getName() << " for " << damage << " by casting spells with their " << staff.getWeaponType() << "!" << endl;
		p.setHP(p.getHP() - this->getWeapon().getDamage());
	}

	if (this->getHP() > 0 && p.getHP() <= 0) {
		p.setHP(0);
		cout << name << " won!" << endl;
		staff.decreaseCondition();

		if (this->getLevel() < 5) {
			gainXp(p.getExperienceWorth());
			levelUp();
		}
	}
}