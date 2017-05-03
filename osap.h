#ifndef OSAP_H
#define OSAP_H

#include <string>
//#include "cell.h"
#include "unownable.h"
class Player;
class Board;
class OSAP : public UnOwnable {

	public:
		//ctor
		OSAP(std::string cellName, int index, bool ownable, Board *bd);
		//dtor 
		~OSAP ( );
		void Effect (Player * curruttPlayer );
};

#endif



