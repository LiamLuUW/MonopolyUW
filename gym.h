#ifndef GYM_H
#define GYM_H
#include <string>
#include "ownable.h"
//#include "cell.h"
#include "dice.h"
class Player;
class Board;

class Gym : public Ownable {
	Dice dice[2];
	int diceVal;

	public:
		//ctor
		Gym (std::string cellName, int index, bool ownable, Board *bd, int PurchaseCost, int PlayersInAuction);
		//dtor
		~Gym ( );
		//set the rent field
		void setRent();
		//function for owner to charge the rent from lander
		void charge(int amount, Player *pl);
		//set the dice in the Gym
		void setDice();
		//notify player to change numofGym
		void notifyPlayerGym();
		int getTotalCost();
};


#endif


