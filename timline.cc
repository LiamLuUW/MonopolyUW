#include "timline.h"
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

#include "cell.h"
#include "unownable.h"
class Board;
using namespace std;


TimLine::TimLine(std::string cellName, int index, bool ownable, Board *bd):
		UnOwnable(cellName, index, ownable, bd) {}



TimLine::~TimLine ( ) {}

void TimLine::Effect (Player * curruttPlayer ) {
	cout << "Pass by Tim Line" << endl;
}

