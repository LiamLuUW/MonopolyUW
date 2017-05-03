#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player{
   	 std::string playerName;
   	 char piece;
   	 int position; // current position of the player
   	 int cash; //current cash that avaliable for the player
   	 int numofTimCup; // number of Tim Cups
   	 bool timLine; // a boolean value that is true if the player is in TimLine
   	 int turninTimLine; //number of truns this player has stayyed in TimLine
   	 int numofGym; //number of Gyms this player owns
   	 int numofRes; //number of Residences the player owns
     
   	 bool inAuction; // a boolean value that is true if the player is in auction
  public:
     int numofMonopolyBlock[8]; // an array represent 8 different blocks
  public:
  	 Player(std::string plname, char piece);
  	 ~Player();

  	 //setter for cash
  	 void setCash(int change); //change is the amount it decrease/increase
  	 //setter for position
  	 void setPosition(int newposition);
  	 //setter for number of Tim Cups
  	 void setNumofTimCups(int timCups);
  	 //setter for timLine
  	 void setTimLine(bool t);
  	 //setter for turns in TimLine
  	 void setTurninTimLine(int n);
  	 //setter for number of Gyms
  	 void addNumofGym();
  	 //setter for number of Residences
  	 void addNumofRes();
  	 //setter for Auction status
  	 void setInAuction(bool t);
     //setter for Monopoly Block
     void addNumofMonopolyBlock(int MonopolyBlock);

  	 //getter for cash
  	 int getCash(); //change is the amount it decrease/increase
  	 //getter for position
  	 int getPosition();
  	 //getter for number of Tim Cups
  	 int getNumofTimCups();
  	 //getter for timLine
  	 bool isTimLine();
  	 //getter for turns in TimLine
  	 int getTurninTimLine();
  	 //getter for number of Gyms
  	 int getNumofGym();
  	 //getter for number of Residences
  	 int getNumofRes();
  	 //getter for Auction status
  	 bool isInAuction();
     //getter for name
     std::string getplayerName();
     //getter for piece
     char getPiece();
     //check if this single block is in Monopoly
     bool getMonopolyBlock(int MonopolyBlock);

};

#endif

