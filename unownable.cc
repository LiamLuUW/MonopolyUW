#include "unownable.h"
#include "board.h"
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

#include "cell.h"

using namespace std;

UnOwnable::UnOwnable (std::string cellName, int index, bool ownable, Board *bd) :
		Cell( cellName, index, ownable, bd) {}


UnOwnable::~UnOwnable ( ) {}



