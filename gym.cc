#include "gym.h"
#include "player.h"
#include <iostream>
#include <string>
#include "ownable.h"
#include "cell.h"
#include "dice.h"
#include "player.h"
#include "board.h"

using namespace std;

Gym::Gym (std::string cellName, int index, bool ownable, Board *bd, int PurchaseCost, 
			int PlayersInAuction) : 
			Ownable(cellName, index, ownable, bd, PurchaseCost, 
					PlayersInAuction), diceVal(0){}


Gym::~Gym ( ) {
	//delete dice;
}



void Gym::setRent() {
	cout << "You need roll dice! (roll)" << endl;
	string t;
	while(cin >> t){
		if(t=="roll"){
			break;
		}else{
			cout << "Wrong Command, Try Again!" << endl;
		}
	}
	setDice();
	if(Owner->getNumofGym()==1){
		cout << "The Owner only has one Gym, so *4"<< endl;
		Rent = diceVal * 4;
		cout << "You need pay " << Rent << endl;
	}else if (Owner->getNumofGym()==2){
		cout << "The Owner has two Gyms, so *8"<< endl;
		Rent = diceVal * 8;
		cout << "You need pay " << Rent << endl;	
	}else{
		cout << "Wrong Number of Gyms" << endl;
	}
}


//amount = rent
void Gym::charge(int amount, Player *pl) {
	pl->setCash(amount);
	this->bd->bankruptcy();

}
		
//set the dice in the Gym
void Gym::setDice() {
	Dice d1;
	Dice d2;
	dice[0] = d1;
	dice[1] = d2;
	d1.roll();
	d2.roll();
	diceVal = d1.getVal()+d2.getVal();
	cout << "You rolled a " << diceVal << endl;
}

void Gym::notifyPlayerGym(){
	Owner->addNumofGym();
}

int Gym::getTotalCost(){
	return getPurchaseCost();
}



