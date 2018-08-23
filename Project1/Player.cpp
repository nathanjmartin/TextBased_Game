#include <string>
#include <iostream>
#include "Player.h"

//a player will be able to be a warrior, mage, or ranger.
//Warrior, mage, and ranger classes will need to extend player

using namespace std;

//default constructor
Player::Player() {
	name = "Unknown";
	level = 1;
	experience = 0;
	experienceWorth = 10;
	gold = 100;
	healthPoints = 100;
	experienceNeeded = 10;

}
//overloaded constructor to accept a character name
Player::Player(string n) {
	name = n;
	level = 1;
	experience = 0;
	experienceWorth = 10;
	gold = 100;
	healthPoints = 100;
}

//destructor
Player::~Player() {
}

//getters
string Player::getName() {
	return name;
}

int Player::getLevel() {
	return level;
}

int Player::getExperience() {
	return experience;
}

int Player::getExperienceWorth() {
	return experienceWorth;
}

int Player::getGold() {
	return gold;
}

int Player::getHP() {
	return healthPoints;
}

int Player::getExperienceNeeded() {
	return experienceNeeded;
}

//Mutators / setters
void Player::setExperienceNeeded(int ex) {
	experienceNeeded = ex;
}

void Player::setName(string n) {
	name = n;
}

void Player::setLevel(int l) {
	level = l;
}

void Player::setExperience(int e) {
	experience = e;
}

void Player::setWorth(int w) {
	experienceWorth = w;
}

void Player::setGold(int g) {
	gold = g;
}

void Player::setHP(int h) {
	healthPoints = h;
}

void Player::levelUp() {
	if (experience == 10) {
		cout << "Congrats " << name << "!" << " You are now level 2!" << endl;
		level++;
	}

	if (experience == 20) {
		cout << "Congrats " << name << "!" << " You are now level 3!" << endl;
		level++;
	}

	if (experience == 30) {
		cout << "Congrats " << name << "!" << " You are now level 4!" << endl;
		level++;
	}
	if (experience == 40) {
		cout << "Congrats " << name << "!" << " You are now level 5!" << endl;
		level++;
	}
}

void Player::gainXp(int xp) {
	experience += xp;
}


