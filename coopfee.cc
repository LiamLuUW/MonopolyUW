#include "coopfee.h"
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "board.h"
#include "cell.h"
#include "unownable.h"

using namespace std;

CoopFee::CoopFee(std::string cellName, int index, bool ownable, Board *bd) :
		UnOwnable(cellName, index, ownable, bd), Fee (150) {}


////no pointer no dy memory delete what???
CoopFee::~CoopFee ( ) {}

void CoopFee::Effect (Player * curruttPlayer ) {
	curruttPlayer->setCash (-Fee);
	this->bd->bankruptcy();
	cout << "You need to pay the Co-op fee !!! $150!!! " << endl;
}

