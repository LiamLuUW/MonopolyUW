#include "tuition.h"
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

#include "cell.h"
#include "unownable.h"
#include "board.h"
using namespace std;


Tuition::Tuition(string cellName, int index, bool ownable, Board *bd) :
		UnOwnable(cellName, index, ownable, bd){}

Tuition::~Tuition ( ) {}


void Tuition::Effect (Player * curruttPlayer ) {
	string payment;
	cout<< "You have to pay the tuitions!!" << endl;
	cout << "Choose a way to pay : $300 / 10%" << endl;
	cout << "ONLY TAP IN THE NUMBERS!!!" << endl;
	cin >> payment;
	if (payment == "300" ) {
			curruttPlayer->setCash (-300);
			this->bd->bankruptcy();
			cout << "You had paid $300." << endl;
	}
	if (payment == "10") {
		//Player *pl = this->getPlayer(curruttPlayer);
		//cout << pl->getCash();
		int fee = this->bd->findWealth() * 0.1;
		cout << fee << endl;
		curruttPlayer->setCash (-fee);
		this->bd->bankruptcy();
		cout << "You had paid 10% of your wealth, which is " << "$" <<fee << endl;
	}
}



