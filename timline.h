#ifndef TIMLINE_H
#define TIMLINE_H

#include <string>
//#include "cell.h"
#include "unownable.h"
class Player;
class Board;
class TimLine : public UnOwnable{
	
	public:
		//ctor
		TimLine(std::string cellName, int index, bool ownable, Board *bd);
		//dtor 
		~TimLine ( );
		void Effect (Player * curruttPlayer );
};

#endif




