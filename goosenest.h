#ifndef GOOSENEST_H
#define GOOSENEST_H

#include <string>
//#include "cell.h"
#include "unownable.h"
class Player;
class Board;
class GooseNest : public UnOwnable{
	public:
		//ctor
		GooseNest(std::string cellName, int index, bool ownable, Board *bd);
		//dtor 
		~GooseNest ( );
		void Effect (Player * curruttPlayer );
};

#endif

