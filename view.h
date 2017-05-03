#ifndef VIEW_H
#define VIEW_H
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>

class View {

public:
	View ( );
	virtual ~View( ) = 0;
	virtual void Notify (char piece, std::string cellname, int numofimp) = 0;
	virtual void notify (int oldpos, int newpos, char piece ) = 0;
	virtual void notify (int pos, int level ) = 0;
	virtual void draw ( ) = 0 ;

};


#endif




