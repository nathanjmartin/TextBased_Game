#pragma once
#include "Weapon.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Enemy : public Player {
	private:
		vector<Weapon> potentialWeapons;
		Weapon weapon;
		string name;
		string classType;
		int damage;

	public:
		//default constructor
		Enemy(string n);

		//destructor
		~Enemy();

		//getter Method for weapon
		Weapon getWeapon();
		string getClass();

		void fight(Player &p);
		Weapon chooseWeapon(vector<Weapon> weaponList);

	};
