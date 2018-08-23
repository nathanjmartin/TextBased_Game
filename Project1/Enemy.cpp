#include <string>
#include <iostream>
#include "Enemy.h"

using namespace std;

Enemy::Enemy(string n) : Player(n) {
	//'Player.name = n'
	name = n;
	vector<Weapon> potentialWeapons = { Weapon("Sword", 10), Weapon("Bow", 10), Weapon("Staff", 10) };
	classType = "Enemy";
	weapon = chooseWeapon(potentialWeapons);
	damage = weapon.getDamage();
}

//DESTRUCTOR
Enemy::~Enemy() {
}

//GETTER METHOD 
Weapon Enemy::getWeapon() {
	return weapon;
}

string Enemy::getClass() {
	return classType;
}

//methods
Weapon Enemy::chooseWeapon(vector<Weapon> weaponList) {
	int random = (rand() % 3);
	Weapon temp = weaponList.at(random);

	return temp;
}

void Enemy::fight(Player &p) {
	if (this->getHP() > 0 && p.getHP() > 0) {
		cout << this->getName() << " hit " << p.getName() << " for " << damage << " while using a " << weapon.getWeaponType() << "!" << endl;
		p.setHP(p.getHP() - this->getWeapon().getDamage());
	}

	if (this->getHP() > 0 && p.getHP() <= 0) {
		p.setHP(0);
		cout << this->getName() << " won!" << endl;
		weapon.decreaseCondition();
	}
}