#ifndef GOTOTIM_H
#define GOTOTIM_H
#include <iostream>
#include <string>
//#include "cell.h"
#include "unownable.h"
class Player;
class Board;
class GoToTim : public UnOwnable{
	public:
		//ctor
		GoToTim(std::string cellName, int index, bool ownable, Board *bd);
		//dtor 
		~GoToTim ( );
		void Effect ( Player * curruttPlayer);
};

#endif

