#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include "view.h"

class DisplayCell;

//helper function
//cout the piece in the cell
//void coutpiece (DisplayCell* cell) { };


class TextDisplay: public View {
	
	DisplayCell* displaycell[40];

public:
	TextDisplay ( );
	~TextDisplay ( );

 	void Notify (char piece, std::string cellname, int numofimp);
	void notify (int oldpos, int newpos, char piece );
	void notify (int pos, int level );
	void draw ( );

	
};



#endif




