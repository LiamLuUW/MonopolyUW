#ifndef TUITION_H
#define TUITION_H

#include <string>
//#include "cell.h"
#include "unownable.h"
class Player;
class Board;
class Tuition : public UnOwnable{

	public:
		//ctor
		Tuition(std::string cellName, int index, bool ownable, Board *bd);
		//dtor 
		~Tuition ( );

		void Effect (Player * curruttPlayer );
};

#endif




