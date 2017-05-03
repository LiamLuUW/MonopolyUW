#ifndef CONTROLLER_H
#define CONTROLLER_H


#include <iostream>
//#include "view.h"
class View;
class Board;

class Controller {
	
	std::string readinfile;

	View* view; 
	Board* bd;

	//check if the game is new started
	bool IsAnewgame;

	//call the win function in the Board to check if there exist a winner
	bool checkWin ( ) const;

	public :

	//	void init ( istream & input, Board& bd );
	//	bool const checkWin ( );

	Controller ( );
	~Controller ( ); 

	//set if the game start from new omr saved file
	void setNew(bool b);

	void setFile(std::string filename);

	// play the game 
	void Play ( );

	//Notify the board to see if there is any change
	void Notify ( char piece, std::string cellname, int numofimp );

	//Notify view change of movement
	void notifyMove(int oldpos, int newpos, char piece);

	//Notify View change of improvement
	void notifyImprove(int pos, int level);
};

#endif

