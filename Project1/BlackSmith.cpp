#include "BlackSmith.h"
#include <string>
#include <iostream>
#include "Weapon.h"
#include "Player.h"

using namespace std;

BlackSmith::BlackSmith() {
	BSname = "Bob";
	price = 100;
	userInput = "";
}

int BlackSmith::getPrice() {
	return price;
}

string BlackSmith::getName() {
	return BSname;
}

string BlackSmith::getInput() {
	return userInput;
}

//mutators
void BlackSmith::setPrice(int p) {
	price = p;
}

void BlackSmith::setName(string n) {
	BSname = n;
}

//methods

void BlackSmith::talk(Weapon& w) {
	cout << "Hello! My name is " << BSname << " it costs " << price << " gold to get your weapon repaired!" << endl;
	cout << "Would you like to repair your weapon? (y/n)" << endl;
	cin >> userInput;

	if (userInput == "y" && w.getCondition() != 100) {
			w.setCondition(100);
			cout << "Fixed your " << w.getWeaponType() << " right up for you! Thanks for stopping by! " << endl;
	}

	else {
		cout << "Thanks for stopping by! " << endl;
	}
	cout << "Come back next time!\n" << endl;
}