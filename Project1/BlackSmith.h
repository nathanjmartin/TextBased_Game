#pragma once
#include <string>
#include "Weapon.h"

using namespace std;

class BlackSmith {
	private:
		int price;
		string BSname;
		string userInput;

	public:
		//getter methods
		BlackSmith();
		int getPrice();
		string getName();
		string getInput();

		//setter methods
		void setPrice(int p);
		void setName(string n);

		//method
		void talk(Weapon& w);



};