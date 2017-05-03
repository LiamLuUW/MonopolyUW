#ifndef OWNABLE_H
#define OWNABLE_H

#include <string>
#include "cell.h"
//#include "player.h"
class Player;
class Board;

class Ownable: public Cell {
	//check if the owner exist 
	bool OwnerExist; 
	//the cout that player need to pay to get this building
	int PurchaseCost;  
	//the number of players in the auction
	int PlayersInAuction;
	//check if the player wants an auction
	bool IfAuction;
	//check if the player wants mortage the owned building 
	bool IfMortgage;
	
	protected:
	//pointer to the owner of the building
	Player* Owner;
	//the cost lander need to pay when landing on a owned buiding
	int Rent;


	public:
		//ctor, the bool fields are defult to false in .cc, owner is NULL
		Ownable(std::string cellName, int index, bool ownable, Board *bd, int PurchaseCost, int PlayersInAuction);
		//dtor
		virtual ~Ownable( ) = 0;
		//set the Ownable of parent class
		void setOwnerExist(bool owner);
		//virtual function to set the rent field
		virtual void setRent() = 0;
		//set the owner 
		void setOwner(Player * owner);
		//virtual function for owner to charge the rent from lander
		virtual void charge(int amount, Player *pl)= 0;

		//notifyed the player that the cell has a owner
		void notify(Player* Owner); //???????????????????


		//getters
		//check if the owner exist
		bool getOwnerExist ( );
		//get the cout that player need to pay to get this building
		int getPurchaseCost ( );
		//get the cost lander need to pay when landing on a owned buiding
		int getRent ( );
		//get the number of players in the auction
		int getPlayersInAuction ( );
		//get if the player wants an auction
		bool isAuction( );
		//get the owner of the building
		Player * getOwner( );
		//get if the player wants mortage the owned building 
		bool isMortgage ( ); 

};



#endif

