#include "academic.h"
#include "cell.h"
#include "ownable.h"
#include "player.h"
#include "board.h"
using namespace std;

Academic::Academic(std::string cellName, int index, bool ownable, Board *bd, int PurchaseCost, 
	int PlayersInAuction,int NumofImp, int TotalCost, int ImpFee, int blocknum):Ownable(cellName, index, ownable, bd, PurchaseCost, PlayersInAuction),
	Monopoly(false), NumofImp(NumofImp), TotalCost(TotalCost), ImpFee(ImpFee), MonopolyBlock(blocknum), numofNeighbour(0){}

Academic::~Academic(){}

void Academic::setRent(){
	if(isMonopoly() && NumofImp==0){
		Rent = 2 * rentList[0];
	}else{
		Rent = rentList[NumofImp];
	}
}

void Academic::setRentList(int a, int b, int c, int d, int e, int f){
	rentList[0] = a;
	rentList[1] = b;
	rentList[2] = c;
	rentList[3] = d;
	rentList[4] = e;
	rentList[5] = f;
}

//add neighbours for this cell
void Academic::addNeighbour(Academic *neighbours){
	this->neighbours[numofNeighbour] = neighbours;
	numofNeighbour++;
}

//set number of improvemnts when init a cell from saved file
void Academic::setNumofImp(int numofImp){
	this->NumofImp = numofImp;
	this->TotalCost = numofImp * this->ImpFee + this->getPurchaseCost();
}

//buy improvements
void Academic::buyImprovements(){
	if(isMonopoly()){
		if(NumofImp == 5){
			cout << "No More Improvements can be bought" << endl;
		}else{
			NumofImp++; //increment number of improvement by 1
			TotalCost += ImpFee; //total cost of this building increse 
			charge(-ImpFee, Owner); //charge the improvemnt fee from the owner
		}
	}else{
		cout << "You have not own this Monopoly Block yet!" << endl;
	}
}

//sell Improvements
void Academic::sellImprovements(){
	if(NumofImp == 0){
		cout << "There is no improvement left" << endl;
	}else{
		NumofImp--;
		TotalCost -= ImpFee;
		charge(ImpFee, Owner);
	}
}

//increse or decresde cash from the owner of this land
void Academic::charge(int amount, Player * pl){
	pl->setCash(amount);
	this->bd->bankruptcy();
}

//notify owner's monopolyblock filed that this block need increment
void Academic::notifyPlayer(){
	this->Owner->numofMonopolyBlock[this->MonopolyBlock]++;
	bool status= Owner->getMonopolyBlock(this->MonopolyBlock);
		this->Monopoly = status;
		notifyNeighbours();
}


//notify neighbour blocks that this cell has become monopoly
void Academic::notifyNeighbours(){
	for(int i=0; i<numofNeighbour; i++){
		neighbours[i]->notifyByNeighbours(this->Monopoly);
	}
}

void Academic::notifyByNeighbours(bool Monopoly){
	this->Monopoly = Monopoly;
}

//getters:
bool Academic::isMonopoly(){
	return Monopoly;
}

int Academic::getTotalCost(){
	return TotalCost;
}

int Academic::getNumofImp(){
	return NumofImp;
}

int Academic::getImpFee(){
	return ImpFee;
}

int Academic::getMonopolyBlock(){
	return MonopolyBlock;
}

