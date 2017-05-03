#include "board.h"
#include "dice.h"
#include "player.h"
#include "cell.h"
#include "ownable.h"
#include "unownable.h"
#include "academic.h"
#include "gym.h"
#include "gototim.h"
#include "goosenest.h"
#include "needleshall.h"
#include "osap.h"
#include "residence.h"
#include "slc.h"
#include "timline.h"
#include "tuition.h"
#include "osap.h"
#include "coopfee.h"
#include "controller.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[]) {
	srand(time(NULL));
	bool isnew = true;
	Controller *con = new Controller;
	string arg = argv[1];
	cout << arg << endl;
	if(arg ==  "-testing"){
		isnew = true;
		con->setNew(isnew);
	}else if(arg == "-load"){
		isnew = false;
		string filename = argv[2];
		con->setFile(filename);
		con->setNew(isnew);
	}else{
		cout << "Wrong command line argument, start from a new one" << endl;
		con->setNew(isnew);
	}
	con->Play();
	delete con;
}

