#include "gototim.h"
#include <string>
#include <iostream>
class Board;
#include "cell.h"
#include "unownable.h"

using namespace std;

GoToTim::GoToTim(std::string cellName, int index, bool ownable, Board *bd) : 
		UnOwnable(cellName, index, ownable, bd) {}
		
GoToTim::~GoToTim ( ) {}


void  GoToTim::Effect ( Player * curruttPlayer) {
	cout << "See you in the Tims!!" << endl;
}



