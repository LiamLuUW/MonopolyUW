#ifndef NEEDLESHALL_H
#define NEEDLESHALL_H

#include <string>
//#include "cell.h"
#include "unownable.h"
class Player;
class Board;

class NeedlesHall : public UnOwnable{
	int Fee;

	public:
		//ctor: set rc to be NULL
		NeedlesHall(std::string cellName, int index, bool ownables, Board *bd);
		//dtor 
		~NeedlesHall ( );

		void Effect (Player * curruttPlayer );
};

#endif

