#ifndef UNOWNABLE_H
#define UNOWNABLE_H

#include <string>
#include "cell.h"
class Player;
class Board;

class UnOwnable: public Cell {
	public:
		//ctor 
		UnOwnable (std::string cellName, int index, bool ownable, Board *bd);
		//dtor
		~UnOwnable ( ) = 0;
		//do something to the player when they landing on this cell
		virtual void Effect (Player * curruttPlayer ) = 0;
};

#endif




