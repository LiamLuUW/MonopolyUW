#include "cell.h"
#include "academic.h"
#include "board.h"
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

#include "player.h"



class Board;
class Cell;
using namespace std;


Cell::Cell(string cellName, int index, bool ownable, Board *bd): 
		cellName (cellName), index (index), Ownable(ownable), bd(bd) {
			numberoflander = 0;
			for ( int i = 1; i < 6; i++ ) {
				lander[i] = NULL;
			}
		}


Cell::~Cell(){};

int Cell::getIndex ( ) {
	return this->index;
}

string Cell::getName ( ) {
	return this->cellName;
}


bool Cell::isOwnable ( ) {
	return this->Ownable;
}

void Cell::setlander (Player* lander, int pl){
	numberoflander++;
	if ( numberoflander < 6) {
		this->lander[pl] = lander;
	}
}


void Cell::deletelander (int pl ) {
	lander[pl] = NULL;
	numberoflander--;
}



Player* Cell::getPlayer (string name) {
	for (int i = 0; i < numberoflander; i++) {
		if (lander[i]->getplayerName() == name) {
			return lander[i];
		}
	}
}

//Virtuals::

void Cell::addNeighbour(Academic *neighbours){}
void Cell::setRent(){}
    //buy improvements
void Cell::buyImprovements(){}
    //sell Improvements
void Cell::sellImprovements(){}
    //function for owner to charge the rent from lander
void Cell::charge(int amount, Player * pl){}
void Cell::setNumofImp(int numofImp){}
		
//notify that the cell has Neighbour
void Cell::notifyPlayer (){}
//notify neighbours that this buildings change on monopoly
void Cell::notifyNeighbours(){}
//set rent List
void Cell::setRentList(int a, int b, int c, int d, int e, int f){}
bool Cell::isMonopoly ( ){}
int Cell::getMonopolyBlock(){}
int Cell::getTotalCost ( ){}
int Cell::getNumofImp ( ){}
int Cell::getImpFee ( ){}

//Ownable::
void Cell::setOwnerExist(bool owner){}
void Cell::setOwner(Player * owner){}
bool Cell::getOwnerExist ( ){}
//get the cout that player need to pay to get this building
int Cell::getPurchaseCost ( ){}
//get the cost lander need to pay when landing on a owned buiding
int Cell::getRent ( ){}
//get the number of players in the auction
int Cell::getPlayersInAuction ( ){}
//get if the player wants an auction
bool Cell::isAuction( ){}
//get the owner of the building
Player * Cell::getOwner( ){}
//get if the player wants mortage the owned building 
bool Cell::isMortgage ( ){}

//Gym and Res
void Cell::notifyPlayerGym(){}
void Cell::notifyPlayerRes(){}

//for Unownable:
void Cell::Effect(Player * curruttPlayer){}


