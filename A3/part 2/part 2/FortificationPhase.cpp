#include <iostream>
#include <string>
#include "FortificationPhase.h"

using namespace std;

FortificationPhase::FortificationPhase() {
	fortifying = true;
}

FortificationPhase::FortificationPhase(Player* player) {
	this->player = player;
	fortifying = true;
}

void FortificationPhase::setPlayer(Player* player) {
	this->player = player;
}

Player * FortificationPhase::getPlayer()
{
	return player;
}

void FortificationPhase::moveArmy() {
	system("CLS");
	Notify();
	cout << "Do you want to move an army from a country to another?" << endl;
	string playerChoice = "";
	cin >> playerChoice;
	if (playerChoice == "yes") {
		selectFromCountry();
		selectToCountry();
		selectArmySize();
		fortifying = false;
		return;
	}
	else {
		fortifying = false;
		return;
	}

}

void FortificationPhase::selectFromCountry() {
	cout << "Please enter the corresponding number of the country you want to move armies from: " << endl;
	int i = 1;
	for (auto it = player->getCountries().begin(); it != player->getCountries().end(); ++it) {
		cout << i << ". " << (*it)->getCountryName() << " with an army of " << (*it)->getArmyNumber() << endl;
		i++;
	}
	while (true) {

		int playerChoice = 0;
		cin >> playerChoice;
		fromCountry = player->getCountries()[playerChoice - 1];
		if (fromCountry->getArmyNumber() < 2) {
			cout << "Please choose a country where there is an army of 2 or more." << endl;
		}
		else {
			cout << "You're gonna move armies from " << fromCountry->getCountryName() << endl;
			break;
		}
	}
}

void FortificationPhase::selectToCountry() {
	cout << "Please enter the corresponding number of the country you want to move armies to: " << endl;
	int i = 1;
	for (auto it = fromCountry->getAdjacentCountries().begin(); it != fromCountry->getAdjacentCountries().end(); ++it) {
		if ((*it)->getOwner() == player) {
			toCountries.push_back(*it);
			cout << i << ". " << (*it)->getCountryName() << " with an army of " << (*it)->getArmyNumber() << endl;
			i++;
		}
	}
	int playerChoice = 0;
	cin >> playerChoice;
	toCountry = toCountries[playerChoice - 1];
	cout << "You are moving armies from " << fromCountry->getCountryName() << " to " << toCountry->getCountryName() << endl;
}

void FortificationPhase::selectArmySize() {
	cout << "How many armies do you want to move?" << endl;
	while (true) {
		int playerChoice = 0;
		cin >> playerChoice;
		if (playerChoice >= fromCountry->getArmyNumber()) {
			cout << "Please keep at least one army left on " << fromCountry->getCountryName() << endl;
		}
		else {
			system("pause");
			system("CLS");
			
			int fromCountrySize = fromCountry->getArmyNumber();
			int toCountrySize = toCountry->getArmyNumber();
			fromCountry->setArmyNumber(fromCountrySize - playerChoice);
			toCountry->setArmyNumber(toCountrySize + playerChoice);
			Notify();
			cout << fromCountry->getCountryName() << " has now " << fromCountry->getArmyNumber() << endl;
			cout << toCountry->getCountryName() << " has now " << toCountry->getArmyNumber() << endl;
			break;
		}
	}
}