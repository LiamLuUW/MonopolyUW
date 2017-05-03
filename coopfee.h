#ifndef COOPFEE_H
#define COOPFEE_H

#include <string>
//#include "cell.h"
#include "unownable.h"
class Player;
class Board;
class CoopFee : public UnOwnable{
	int Fee;

	public:
		//ctor
		CoopFee(std::string cellName, int index, bool ownable, Board *bd);
		//dtor 
		~CoopFee ( );
		void Effect ( Player * curruttPlayer );
};

#endif


