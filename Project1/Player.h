//Player HEADER

#pragma once

#include <string>
//a player will be able to be a warrior, mage, or ranger.
//Warrior, mage, and ranger classes will need to extend player

using namespace std;

class Player {
private:
	string name;
	int level;
	int experience;
	int experienceWorth;
	int gold;
	int healthPoints;
	int experienceNeeded;

public:
	//default constructor
	Player();

	//overloaded constructor
	Player(string n);
	
	//deconstructor
	~Player();

	//getters
	string getName();
	int getLevel();
	int getExperience();
	int getExperienceWorth();
	int getExperienceNeeded();
	int getGold();
	int getHP();
	
	//mutators
	void setName(string n);
	void setLevel(int l);
	void setExperience(int e);
	void setWorth(int w);
	void setGold(int g);
	void setHP(int h);
	void setExperienceNeeded(int ex);
	//methods
	void levelUp();
	void gainXp(int xp);


	//virtual methods
	virtual void fight(Player &p) = 0;

};
