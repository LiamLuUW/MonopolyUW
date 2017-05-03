#include "ownable.h"
#include "player.h"
#include "board.h"
#include <iostream>
#include <string>
using namespace std;

Ownable::Ownable(string cellName, int index, bool ownable, Board *bd, 
	int PurchaseCost, int PlayersInAuction):Cell(cellName, index, ownable, bd),
	OwnerExist(false), PurchaseCost(PurchaseCost), Rent(0),
	PlayersInAuction(PlayersInAuction), IfAuction(false), IfMortgage(false), Owner(NULL){}

Ownable::~Ownable(){}

void Ownable::setOwnerExist(bool owner){
	OwnerExist=owner;
}

void Ownable::setOwner(Player * owner){
	Owner = owner;
}

bool Ownable::getOwnerExist(){
	return OwnerExist;
}

int Ownable::getPurchaseCost(){
	return PurchaseCost;
}

int Ownable::getRent(){
	return Rent;
}

int Ownable::getPlayersInAuction(){
	return PlayersInAuction;
}

bool Ownable::isAuction(){
	return IfAuction;
}

Player * Ownable::getOwner(){
	return Owner;
}

bool Ownable::isMortgage(){
	return this->IfMortgage;
}


