#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>
#include "player.h"

class Academic;
class Board;
//class Player;

class Cell{
    std::string cellName; //name of this Cell
    int index; //index that represent this cell
    int numberoflander;

  protected:
    Player* lander [6]; // a pointer a array of players who is currently on this cell
    bool Ownable; // a boolean value that is true if this cell can be bought
    Board * bd;    

  public:
  	//default ctor
  	Cell(std::string cellName, int index, bool ownable, Board *bd);
  	//default dtor
  	virtual ~Cell() = 0;

    //set the lander called by notifycell in the board
    void setlander( Player* lander, int pl);
    void deletelander (int pl );


    //getters:
    int getIndex();
    std::string getName();
    bool isOwnable();
    Player *getPlayer(std::string name);

    //virtual:

    //for academic:
    virtual void addNeighbour(Academic *neighbours);
    virtual void setRent();
    //buy improvements
    virtual void buyImprovements();
    //sell Improvements
    virtual void sellImprovements();
    //function for owner to charge the rent from lander
    virtual void charge(int amount, Player * pl);
    virtual void setNumofImp(int numofImp);
    
    //notify that the cell has Neighbour
    virtual void notifyPlayer ();
    //notify neighbours that this buildings change on monopoly
    virtual void notifyNeighbours();
    //set rent List
    virtual void setRentList(int a, int b, int c, int d, int e, int f);
    virtual bool isMonopoly ( );
    virtual int getMonopolyBlock();
    virtual int getTotalCost ( );
    virtual int getNumofImp ( );
    virtual int getImpFee ( );

    //For Ownable::
    virtual void setOwnerExist(bool owner);
    virtual void setOwner(Player * owner);
    virtual bool getOwnerExist ( );
    //get the cout that player need to pay to get this building
    virtual int getPurchaseCost ( );
    //get the cost lander need to pay when landing on a owned buiding
    virtual int getRent ( );
    //get the number of players in the auction
    virtual int getPlayersInAuction ( );
    //get if the player wants an auction
    virtual bool isAuction( );
    //get the owner of the building
    virtual Player * getOwner( );
    //get if the player wants mortage the owned building 
    virtual bool isMortgage ( ); 

    //For Gym and Res
    virtual void notifyPlayerGym();
    virtual void notifyPlayerRes();

    //For Unownable:
    virtual void Effect (Player * curruttPlayer);
};



#endif

