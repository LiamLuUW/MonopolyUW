#include "player.h"
#include <iostream>
#include <string>
using namespace std;

//default ctor
Player::Player(string plname, char piece){
	playerName=plname;
	this->piece = piece;
	position = 0; //start from OSAP
	cash = 0; //starting cash is 1500
	numofTimCup = 0; // start with no Tim Cups
	timLine = false;
	turninTimLine = 0;
	numofGym = 0;
	numofRes = 0;
	for(int i = 0; i < 8; i++){
		numofMonopolyBlock[i] = 0;
	}
	inAuction = false;
}

//default dtor
Player::~Player(){}

//setters:

void Player::setCash(int change){
	if (change >0){
		cout << "_______" << playerName <<" cash +" << change << "_______"<< endl;
	}else{
		cout << "_______"<< playerName <<" cash " << change << "________"<< endl;		
	}
	this->cash = this->cash + change;
}

void Player::setPosition(int newposition){
	position = newposition;
}

void Player::setNumofTimCups(int timCups){
	this->numofTimCup = timCups;
}

void Player::setTimLine(bool t){
	timLine = t;
}

void Player::setTurninTimLine(int n){
	turninTimLine = n;
}

void Player::addNumofGym(){
	numofGym++;
}

void Player::addNumofRes(){
	numofRes++;
}

void Player::setInAuction(bool t){
	inAuction = t;
}

void Player::addNumofMonopolyBlock(int MonopolyBlock){
	numofMonopolyBlock[MonopolyBlock]++;
}


//getters:

int Player::getCash(){
	return cash;
}

int Player::getPosition(){
	return position;
}

int Player::getNumofTimCups(){
	return numofTimCup;
}

bool Player::isTimLine(){
	return timLine;
}

int Player::getTurninTimLine(){
	return turninTimLine;
}

int Player::getNumofGym(){
	return numofGym;
}

int Player::getNumofRes(){
	return numofRes;
}

bool Player::isInAuction(){
	return inAuction;
}

string Player::getplayerName(){
	return playerName;
}

char Player::getPiece(){
	return piece;
}

bool Player::getMonopolyBlock(int MonopolyBlock){
	if(numofMonopolyBlock[MonopolyBlock]==3){
		return true;
	}else{
		return false;
	}
}

