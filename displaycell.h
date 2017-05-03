#ifndef DISPLAYCELL_H
#define DISPLAYCELL_H
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>


class DisplayCell {
	//show the improment of the cell
	int impro;
	//there are 6 pieces in the cell max
	char piece[6];

public:

	DisplayCell ( );
	~DisplayCell ( );

	//getter and setter;
	void setimpro (int impro);
	void setpiece (char piece);
	char getpiece (int p);
	int getimpro ( );

};




#endif

