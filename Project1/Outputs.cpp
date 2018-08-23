#include "Outputs.h"
#include "Enemy.h"
#include "Mage.h"
#include "Warrior.h"
#include "Ranger.h"
#include "Player.h"
#include "Weapon.h"
#include "BlackSmith.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

//constructor
Outputs::Outputs() {
	choice;
	secondChoice = 0;
	Player* pointer = NULL;
	BlackSmith bob;
}

//deconstructor
Outputs::~Outputs() {
}

//introduction to the game
//FUNCTIONAL
void Outputs::introduction() {
	try {
		cout << "Welcome! What would you like your character name to be?" << endl;
		cin >> name;
		cout << "\nHello, " << name << "! Please choose your class.\n1. Warrior\n2. Mage\n3. Ranger." << endl;
		cin >> choice;
		while (choice < 1 || choice > 3) {
			cout << "Please enter a valid number." << endl;
			cin >> choice;
		}
	}
	catch (...) {
		cout << "Error." << endl;
	}
}

//class selection method
//FUNCTIONAL
void Outputs::classSelect() {
	//Warrior options
	if (choice == 1) {
		Warrior newPlayer(name);
		while (secondChoice != 5) {
			displayOptions();
			cin >> secondChoice;
				if (secondChoice == 1 && newPlayer.getWeapon().getCondition() != 0) {
					Enemy newEnemy = randomEnemyGenerate();
					while (newPlayer.getHP() > 0 && newEnemy.getHP() > 0) {
						newPlayer.fight(newEnemy);
						newEnemy.fight(newPlayer);

						if (newPlayer.getHP() == 0) {
							cout << "You have died and lost! See you next time!" << endl;
							secondChoice = 5;
						}
						else if (newPlayer.getHP() > 0 && newEnemy.getHP() <= 0) {
							newPlayer.setGold(newPlayer.getGold() + newEnemy.getGold());
						}
					}
				}
				else if (secondChoice == 1 && newPlayer.getWeapon().getCondition() == 0) {
					cout << "You cannot fight until your weapon is repaired!" << endl;
				}
				else if (secondChoice == 2) {
					cout << "Resting up!" << endl;
					newPlayer.setHP(100);
				}
				else if (secondChoice == 3) {
					cout << "--------------CHARACTER INFORMATION--------------" << endl;
					cout << newPlayer.getName() << ": " << newPlayer.getClass() << " Weapon: " << newPlayer.getWeapon().getWeaponType() << endl;
					cout << "Level: " << newPlayer.getLevel() << endl;
					cout << newPlayer.getHP() << " hitpoints " << endl;
					cout << newPlayer.getGold() << " gold" << endl;
					cout << newPlayer.getWeapon().getCondition() << "% weapon condition.\n" << endl;
				}
				else if (secondChoice == 4) {
					if (newPlayer.getGold() < bob.getPrice()) {
						cout << "You do not have enough gold. It costs " << bob.getPrice() << " for me to repair your weapon!\n" << endl;
					}
					else if(newPlayer.getGold() >= bob.getPrice() && newPlayer.getWeapon().getCondition() != 100) {
						bob.talk(newPlayer.getWeapon());
						newPlayer.setGold(newPlayer.getGold() - bob.getPrice());
					}
					else {
						cout << "Your weapon does not need to be repaired! " << endl;
					}
				}
				//or if input is not an integer
				else if (secondChoice < 0 || secondChoice > 5) {
					cout << "Please enter a valid number." << endl;
				}
			}
	}

	//Mage options
	else if (choice == 2) {
		Mage newPlayer(name);
		while (secondChoice != 5) {
			displayOptions();
			cin >> secondChoice;
			if (secondChoice == 1 && newPlayer.getWeapon().getCondition() != 0) {
				Enemy newEnemy = randomEnemyGenerate();
				while (newPlayer.getHP() > 0 && newEnemy.getHP() > 0) {
					newPlayer.fight(newEnemy);
					newEnemy.fight(newPlayer);

					if (newPlayer.getHP() == 0) {
						cout << "You have died and lost! See you next time!" << endl;
						secondChoice = 5;
					}
					else if (newPlayer.getHP() > 0 && newEnemy.getHP() <= 0) {
						newPlayer.setGold(newPlayer.getGold() + newEnemy.getGold());
					}
				}
			}
			else if (secondChoice == 1 && newPlayer.getWeapon().getCondition() == 0) {
				cout << "You can't fight until your weapon is repaired!" << endl;
			}
			else if (secondChoice == 2) {
				cout << "Resting up!" << endl;
				newPlayer.setHP(100);
			}
			else if (secondChoice == 3) {
				cout << "--------------CHARACTER INFORMATION--------------" << endl;
				cout << newPlayer.getName() << ": " << newPlayer.getClass() << " Weapon: " << newPlayer.getWeapon().getWeaponType() << endl;
				cout << "Level: " << newPlayer.getLevel() << endl;
				cout << newPlayer.getHP() << " hitpoints " << endl;
				cout << newPlayer.getGold() << " gold" << endl;
				cout << newPlayer.getWeapon().getCondition() << "% weapon condition.\n" << endl;
			}
			else if (secondChoice == 4) {
				if (newPlayer.getGold() < bob.getPrice()) {
					cout << "You do not have enough gold. It costs " << bob.getPrice() << " for me to repair your weapon!\n" << endl;
				}
				else if (newPlayer.getGold() >= bob.getPrice() && newPlayer.getWeapon().getCondition() != 100) {
					bob.talk(newPlayer.getWeapon());
					newPlayer.setGold(newPlayer.getGold() - bob.getPrice());
				}
				else {
					cout << "Your weapon does not need to be repaired! " << endl;
				}
			}
			else if (secondChoice < 0 || secondChoice > 5) {
				cout << "Please enter a valid number." << endl;
			}
		}
	}

	//Ranger options
	else if (choice == 3) {
		Ranger newPlayer(name);
		while (secondChoice != 5) {
			displayOptions();
			cin >> secondChoice;
			if (secondChoice == 1) {
				Enemy newEnemy = randomEnemyGenerate();
				while (newPlayer.getHP() > 0 && newEnemy.getHP() > 0) {
					newPlayer.fight(newEnemy);
					newEnemy.fight(newPlayer);

					if (newPlayer.getHP() == 0) {
						cout << "You have died and lost! See you next time!" << endl;
						secondChoice = 5;
					}
					else if (newPlayer.getHP() > 0 && newEnemy.getHP() <= 0) {
						newPlayer.setGold(newPlayer.getGold() + newEnemy.getGold());
					}
				}
			}
			else if (secondChoice == 2) {
				cout << "Resting up!" << endl;
				newPlayer.setHP(100);
			}
			else if (secondChoice == 3) {
				cout << "--------------CHARACTER INFORMATION--------------" << endl;
				cout << newPlayer.getName() << ": " << newPlayer.getClass() << " Weapon: " << newPlayer.getWeapon().getWeaponType() << endl;
				cout << "Level: " << newPlayer.getLevel() << endl;
				cout << newPlayer.getHP() << " hitpoints " << endl;
				cout << newPlayer.getGold() << " gold" << endl;
				cout << newPlayer.getWeapon().getCondition() << "% weapon condition.\n" << endl;
			}
			else if (secondChoice == 4) {
				if (newPlayer.getGold() < bob.getPrice()) {
					cout << "You do not have enough gold. It costs " << bob.getPrice() << " for me to repair your weapon!\n" << endl;
				}
				else if (newPlayer.getGold() >= bob.getPrice() && newPlayer.getWeapon().getCondition() != 100) {
					bob.talk(newPlayer.getWeapon());
					newPlayer.setGold(newPlayer.getGold() - bob.getPrice());
				}
				else {
					cout << "Your weapon does not need to be repaired! " << endl;
				}
			}
			else if (secondChoice < 0 || secondChoice > 5) {
				cout << "Please enter a valid number." << endl;
			}
		}
	}
	cout << "Thanks for playing " << name << "!" << endl;
}


//correctly implemented for how it is supposed to be.
void Outputs::displayOptions() {
	for (unsigned int i = 0; i < options.size(); i++) {
		cout << options.at(i) << endl;
	}
}


//correctly implemented
void Outputs::addOptions() {

	cout << "\nWhat would you like to do next?" << endl;
	options.push_back("1. Fight");
	options.push_back("2. Rest");
	options.push_back("3. Display Information");
	options.push_back("4. Repair Weapon");  
	options.push_back("5. Quit");
}

void Outputs::playGame() {
	introduction();
	addEnemies();
	addOptions();
	classSelect();
}

//creates and adds enemies to the enemies vector
void Outputs::addEnemies() {
	Enemy one("Tuloid");
	Enemy two("Dios");
	Enemy three("Nikalo");
	Enemy four("Theare");
	Enemy five("Jalop");

	enemies.push_back(one);
	enemies.push_back(two);
	enemies.push_back(three);
	enemies.push_back(four);
	enemies.push_back(five);
}


//chooses a random enemy from the enemies vector (from 0 to 5)
Enemy Outputs::randomEnemyGenerate() {
	int randNum = (rand() % 5);
	Enemy temp = enemies.at(randNum);
	return temp;
}

void Outputs::displayFightOptions() {
	//This will be developed as the game grows (such as special attacks, etc)
}