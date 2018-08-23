#include "Warrior.h"
#include <iostream>
#include <string>

//FUNCTIONAL AS OF 7/31/2018


using namespace std;

//CONSTRUCTOR
//Constructor takes the string 'n' parameter and passes it to the Player constructor.


Warrior::Warrior(string n) : Player(n) {
	//'Player.name = n'
	name = n;
	sword = Weapon("Sword", 10);
	classType = "Warrior";
	damage = sword.getDamage();
}


//DESTRUCTOR
Warrior::~Warrior() {
}

//GETTER METHOD 
Weapon& Warrior::getWeapon() {
	return sword;
}

string Warrior::getClass() {
	return classType;
}

//methods
void Warrior::fight(Player &p) {
		if (this->getHP() > 0 && p.getHP() > 0) {
			cout << this->name << " hit " << p.getName() << " for " << damage <<  " while using a " << sword.getWeaponType() << "!" << endl;
			p.setHP(p.getHP() - this->getWeapon().getDamage());
		}

		if (this->getHP() > 0 && p.getHP() <= 0) {
			p.setHP(0);
			cout << name << " won!" << endl;
			sword.decreaseCondition();

			if (this->getLevel() < 5) {
				gainXp(p.getExperienceWorth());
				levelUp();
			}
		}
}