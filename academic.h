#ifndef ACADEMIC_H
#define ACADEMIC_H
#include <string>
#include "ownable.h"
//#include "cell.h"
class Board;
class Player;

class Academic:public Ownable {
	//if the building is Monopoly
	bool Monopoly;
	//the number of improvements for the builiding
	int NumofImp;
	//Total cost of the building: includeing the PurchaseCost 
	//and the cost of improvements
	int TotalCost;
	//cost of improvements
	int ImpFee;
	//a integer represent the block number
	int MonopolyBlock;
	//a list of buildings that are in the same block
	Academic *neighbours[3];
	//number of neighbours
	int numofNeighbour;
	//a list of rnt based on different improbment fee
	int rentList[6];

	public:
		//ctor: set Monopoly to be TREU, 
		Academic (std::string cellName, int index, bool ownable, Board *bd, int PurchaseCost, int PlayersInAuction,
		  int NumofImp, int TotalCost, int ImpFee, int blocknum);
		//dtor
		~Academic ( ); 
		//set the rent field
		void setRent();
		//buy improvements
		void buyImprovements();
		//sell Improvements
		void sellImprovements();
		//function for owner to charge the rent from lander
		void charge(int amount, Player * pl);
		//add a neighbout to this class
		virtual void addNeighbour(Academic *neighbours);
		//setter for number of improvements
		void setNumofImp(int numofImp);
		
		//notify that the cell has Neighbour
		void notifyPlayer ();
		//notify neighbours that this buildings change on monopoly
		void notifyNeighbours();
		//be notifed by other buildings that their status of monopoly
		//has been changed
		void notifyByNeighbours(bool Monopoly);
		//set rent List
		void setRentList(int a, int b, int c, int d, int e, int f);
		


		//getters
		bool isMonopoly ( );
		int getMonopolyBlock();
		int getTotalCost ( );
		int getNumofImp ( );
		int getImpFee ( );
};


#endif
