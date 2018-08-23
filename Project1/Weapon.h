#pragma once

#include <string>
using namespace std;

class Weapon {
private:
	int accuracy;
	int damage;
	string weaponType;
	int condition;
public:
	Weapon();
	Weapon(string wep, int damage);
	~Weapon();
	
	int getDamage();
	string getWeaponType();
	int getCondition();

	void setDamage(int d);
	void setWeaponType(string wt);
	void setCondition(int c);
	void decreaseCondition();

};
