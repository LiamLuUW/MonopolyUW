#include "displaycell.h"

using namespace std;


DisplayCell::DisplayCell ( ) {
	impro = 0;
	for (int i = 0; i < 6; i++) {
		piece[i] = char(32);
	}
}


DisplayCell::~DisplayCell ( ) { }

void DisplayCell::setimpro (int impro) {
	this->impro += impro;
}

void DisplayCell::setpiece (char piece) {
	//when the player arrival we need to add piece
	int i = 0;
	while (i < 6) {
		if (this->piece[i] == char(32)) {
			this->piece[i] = piece;
			return;
		}
		else {
			this->piece[i] = char(32);
			return;
		}
	}
}

char DisplayCell::getpiece (int index) {
	return piece[index];
}


int DisplayCell::getimpro ( ) {
	return impro;
}
