#include "goosenest.h"
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
class Board; 
#include "cell.h"
#include "unownable.h"

using namespace std;


GooseNest::GooseNest(std::string cellName, int index, bool ownable, Board *bd) :
	UnOwnable(cellName, index, ownable, bd) {}


GooseNest::~GooseNest ( ) {}


void GooseNest::Effect (Player * curruttPlayer ) {
	cout << "Ohhhhh!!! Goose coming!!!!" << endl;
}


