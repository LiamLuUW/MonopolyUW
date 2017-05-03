#ifndef SLC_H
#define SLC_H

#include <string>
//#include "cell.h"
#include "unownable.h"
class Player;

class Board;

class SLC : public UnOwnable{
	int Steps;

	public:
		//ctor
		SLC(std::string cellName, int index, bool ownable, Board *bd);
		//dtor 
		~SLC ( );

		void Effect (Player * curruttPlayer );
};

#endif

