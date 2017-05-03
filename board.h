#include <iostream>
#include <string>
class Player;
class Cell; 
class Dice;
class Controller;

class Board {
     Player *players[6];
     int currentPlayer;
     Cell *cells[40];
     int numofpl; // number of players
     int faceVal; // face value of the dices
     Dice *dices[2];
     Controller *con;
     int roll;
     bool doubleroll;
  public:
  	//Defalut ctor
  	Board();
  	//Default dtor
  	~Board();
  	// init a game by create a list of players a gameoard and two dices,
  	// the arguments are the controller pointer and the number of players
  	void initialization(Controller *con, int n); 
  	// init a plyare based on the given info
  	void initialPlayer(std::string name, char piece, int timcups, int cash, int position, bool timline, int numoftimline);
    // set a gameboard by cretaing 40 cells
    void setBoard();
    //clean an existing board
    void cleanBoard();
    //creat a cell project (should be called by ctor)???????
    void initCell(std::string cellname, std::string owner, int numofImp);
    //delete a player object
    void deletePlayer(std::string plname);
    //create a dice object
    void getDice();
    //delete a dice object
    void deleteDice();
    //


    //following methods are called by a player because they are actions that an player can perform


    //Trade function that is called for trade propertites between players
    // it need overload since it can take different types of arguments
    void trade(std::string name, int give, std::string receive);
    void trade(std::string name, std::string give, int receive);
    void trade(std::string name, std::string give, std::string receive);
    //Bankruptcy function is called when a player declare a bankruptcy
    void bankruptcy();
    //set up the mortgage for a player
    void mortgage();
    //set up unmortgage for a player
    void unmortgage();
    //a player can call this roll function to roll a dice
    void rollDice();
    //getfacevalue will get the total value from two dices which is the movement that a player should g
    void getFaceValue();
    //set faec value this is only used by needles hall to change faceval value
    void setFaceValue(int n);
    //switch to the next player
    void next();
    //save the game and output status to a file
    void save(std::string savingFile);
    //buy imrpovement of the academic building
    void buyImprove();
    //sell improvement of a academic building
    void sellImprove();
    //display the asset of the current player
    void assets();
    //end the game
   // void exit();
    //buy a building
    void buyBuilding();

    //following function are used to check the status of the  current game

    //return true if there is a winner of this game and ends it otherwise return false
    bool checkWin();
    // return true if the num of Timcards in the game is at its Max which is 4 ortherwise return false
    bool checkTimCards(); //also use static so that it can be called by cell object

    //nofify methods
    
    //used to make moves which will delete the player pointer
    // from the old position and then notity the new cell
    void makemove();
    //notify the new cell that a new lander is here
    void notifyCell(int index);
    //notify the controller about a player's movement
    void notifyMove(int oldposition, int newposition, char piece);
    //notify the controller about a building's improvement
    void notifyImprove(int position, int level);

    //Helper
    //find current player's wealth
    int findWealth();
   

};

