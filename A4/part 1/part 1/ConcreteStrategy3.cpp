#include <iostream>
#include <time.h>
#include "ConcreteStrategy3.h"

using namespace std;

ConcreteStrategy3::ConcreteStrategy3() {

}

ConcreteStrategy3::~ConcreteStrategy3() {
	
}

void ConcreteStrategy3::reinforce(Map* map, Player* player) {
	int x = map->getNumberOfCountries(*player);
	if (x < 3) {
		x = 3;
	}

	string name;
	cout << "-------------START OF REINFORCEMENT PHASE-------------\n" << endl;
	cout << "\nNUMBER OF COUNTRIES BY " << player->getName() << " : " << x << endl;
	cout << "Here are the countries owned by " << player->getName() << ": " << endl;
	vector<Country*> countries = player->getCountries();

	for (auto it = countries.begin(); it != countries.end(); ++it) {
		cout << "- " << (*it)->getCountryName() << " with armies value of " << (*it)->getArmyNumber() << endl;
	}

	cout << "\nThere are " << x << " armies to place." << endl;

	srand(time(0));
	int value = rand() % (countries.size());
	countries[value]->setArmyNumber(countries[value]->getArmyNumber() + x);

	cout << countries[value]->getCountryName() << " has just been reinforced randomly." << endl;
	cout << "NUMBER OF ARMIES OF " << map->getCountry(countries[value]->getCountryName())->getCountryName() << " : " << map->getCountry(countries[value]->getCountryName())->getArmyNumber() << endl;

	cout << "\n       -------- END OF REINFORCEMENT PHASE ---------\n" << endl;
	
}

void ConcreteStrategy3::attack(Player* player) {
	attacker = player;
	srand(time(0));
	// limiting attacks to 10 or upper limit would be infinite
	int numberOfAttack = rand() % 11;
	cout << "\n-------------START OF ATTACK PHASE-------------\n" << endl;

	// display countries of attacker
	cout << attacker->getName() << ", these are your countries: " << endl;
	for (auto it = player->getCountries().begin(); it != player->getCountries().end(); ++it) {
		cout << "- " << (*it)->getCountryName() << " with army values of " << (*it)->getArmyNumber() << endl;
		if ((*it)->getArmyNumber() > 1) {
			attackerCountries.push_back(*it);
		}
	}

	// randomly choose attacking country
	

	for (int i = 0; i < numberOfAttack; i++) {

	}
}
void ConcreteStrategy3::fortify(Player* player) {

}