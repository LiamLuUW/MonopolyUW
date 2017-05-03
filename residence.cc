#include "residence.h"
#include "player.h"
#include <iostream>
#include <string>
#include "ownable.h"
#include "cell.h"
#include "player.h"
#include "board.h"

using namespace std;


Residence::Residence (std::string cellName, int index, bool ownable, Board *bd, int PurchaseCost,int PlayersInAuction) 
			: Ownable(cellName, index, ownable, bd, PurchaseCost, PlayersInAuction) {}


Residence::~Residence ( ) {}


//set the rent field
void Residence::setRent() {
	if(Owner->getNumofRes()==1){
		cout << "Owner has 1 residence, and you pay $25"<<endl;
		Rent = 25;
	}else if(Owner->getNumofRes()==2){
		cout << "Owner has 2 residences, and you pay $50"<<endl;
		Rent = 50;
	}else if(Owner->getNumofRes()==3){
		cout << "Owner has 3 residences, and you pay $100"<<endl;
		Rent = 100;
	}else if(Owner->getNumofRes()==4){
		cout << "Owner has 4 residences, and you pay $200"<<endl;
		Rent = 200;
	}else{
		cout << "Wrong Numer of Residences" << endl;
	}
}
		

//function for owner to charge the rent from lander
//amount = rent
void Residence::charge(int amount, Player *pl) {
	pl->setCash(amount);
	this->bd->bankruptcy();
}

//notify Player a residence has been bought
void Residence::notifyPlayerRes(){
	Owner->addNumofRes();
}

int Residence::getTotalCost(){
	return getPurchaseCost();
}





