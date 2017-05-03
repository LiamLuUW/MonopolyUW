#include "slc.h"
#include "board.h"
#include <cstdlib>
#include <iostream>
using namespace std;

SLC::SLC(string cellName, int index, bool ownable, Board *bd):UnOwnable(cellName, index, ownable, bd){}

SLC::~SLC(){}

void SLC::Effect (Player * curruttPlayer ){
	
	int r1 = rand() % 100;
	if(r1== 1 && (!bd->checkTimCards())){
		cout << "Crongrates, you get a Tim Cup!" << endl;
		int temp = curruttPlayer->getNumofTimCups();
		curruttPlayer->setNumofTimCups(temp++);
	}else{
		int r2 = rand() % 24;
		if(r2>= 0 && r2 <=2){
			cout << "You move 3 steps back!" << endl;
			bd->setFaceValue(-3);
			bd->makemove();
		}else if(r2 >=3 && r2 <= 6){
			cout << "You move 2 steps back!" << endl;
			bd->setFaceValue(-2);
			bd->makemove();
		}else if(r2 >=7 && r2 <= 10){
			cout << "You move 1 steps back!" << endl;
			bd->setFaceValue(-1);
			bd->makemove();
		}else if(r2 >=11 && r2 <= 13){
			cout << "You move 1 steps forward!" << endl;
			bd->setFaceValue(1);
			bd->makemove();
		}else if(r2 >=14 && r2 <= 17){
			cout << "You move 2 steps forward!" << endl;
			bd->setFaceValue(2);
			bd->makemove();
		}else if(r2 >=18 && r2 <= 21){
			cout << "You move 3 steps forward!" << endl;
			bd->setFaceValue(3);
			bd->makemove();
		}else if(r2 == 22){
			cout << "You move to DC TIM LINE!" << endl;
			int steps = 0;
			int cur = getIndex();
			if(cur == 2){
				steps = 28;
			}else if(cur == 17){
				steps = 13;
			}else {
				steps = -3;
			}
			bd->setFaceValue(steps);
			bd->makemove();
		}else if(r2 == 23){
			cout << "You move to OSAP" << endl;
			int cur = getIndex();
			int steps =0;
			if(cur == 2){
				steps = -2;
			}else if(cur == 17){
				steps = 23;
			}else {
				steps = 7;
			}
			bd->setFaceValue(steps);
			bd->makemove();
		}else{
			cout << "Wrong Random Num from SLC" <<endl;
		}
	}

}

