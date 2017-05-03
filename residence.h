#ifndef RESIDENCE_H
#define RESIDENCE_H
#include <string>
#include "ownable.h"
//#include "cell.h"

class Player;

class Residence :  public Ownable {

	public:
		//ctor
		Residence (std::string cellName, int index, bool ownable, Board *bd, int PurchaseCost, int PlayersInAuction);
		//dtor
		~Residence ( );
		//set the rent field
		void setRent();
		//function for owner to charge the rent from lander
		void charge(int amount, Player *pl);
		//notify Player that he bought a residence
		void notifyPlayerRes();
		int getTotalCost();

};

#endif


