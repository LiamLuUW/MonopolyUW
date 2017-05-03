#include "osap.h"
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "board.h"
#include "cell.h"
#include "unownable.h"

using namespace std;


OSAP::OSAP(std::string cellName, int index, bool ownable, Board *bd) :
		UnOwnable(cellName, index, ownable, bd){}

OSAP::~OSAP ( ) {}


void OSAP::Effect (Player * curruttPlayer ) {
	curruttPlayer->setCash (200);
	cout << "WOW!!! Lucky You! got $200!!!" << endl;
}



