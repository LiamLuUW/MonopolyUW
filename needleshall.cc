#include "needleshall.h"
#include "board.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

NeedlesHall::NeedlesHall(string cellName, int index, bool ownable, Board* bd):
	UnOwnable(cellName, index, ownable, bd){}

NeedlesHall::~NeedlesHall(){}

void NeedlesHall::Effect (Player * curruttPlayer ){
	int r1 = rand() % 100;
	if(r1== 1 && (!bd->checkTimCards())){
		cout << "Crongrates, you get a Tim Cup!" << endl;
		int temp = curruttPlayer->getNumofTimCups();
		curruttPlayer->setNumofTimCups(temp++);
	}else{
		int r2 = rand() % 18;
		if(r2 == 0){
			cout << "You need pay $200 to the register office" << endl;
			curruttPlayer->setCash(-200);
			bd->bankruptcy();
		}else if(r2 >= 1 && r2 <= 2){
			cout << "You need pay $100 to the register office" << endl;
			curruttPlayer->setCash(-100);
			bd->bankruptcy();
		}else if(r2 >= 3 && r2 <= 5){
			cout << "You need pay $50 to the register office" << endl;
			curruttPlayer->setCash(-50);
			bd->bankruptcy();
		}else if(r2 >= 6 && r2 <= 11){
			cout << "Congrats, You will get $25 from the register office" << endl;
			curruttPlayer->setCash(25);
			bd->bankruptcy();
		}else if(r2 >= 12 && r2 <= 14){
			cout << "Congrats, You will get $50 from the register office" << endl;
			curruttPlayer->setCash(50);
			bd->bankruptcy();			
		}else if(r2 >= 15 && r2 <=16){
			cout << "Congrats, You will get $100 from the register office" << endl;
			curruttPlayer->setCash(100);
			bd->bankruptcy();
		}else if(r2 == 17){
			cout << "Congrats, You will get $200 from the register office" << endl;
			curruttPlayer->setCash(200);
			bd->bankruptcy();
		}else{
			cout << "Wrong Random num for NeedlesHall" << endl;
		}
	}
}



