#pragma once
#include <string>
#include <vector>
#include "Enemy.h"
#include "Warrior.h"
#include "Mage.h"
#include "Ranger.h"
#include "BlackSmith.h"

using namespace std;

class Outputs {
	private:
		int choice;
		int secondChoice;
		string name;
		Player* pointer;
		BlackSmith bob;
		vector<string> options;
		vector<string> fightOptions;
		vector<Enemy> enemies;

	public:
		Outputs();
		~Outputs();
		void introduction();
		void classSelect();
		void addOptions();
		void playGame();
		void displayOptions();
		void displayFightOptions();
		void addEnemies();
		Enemy randomEnemyGenerate();


};