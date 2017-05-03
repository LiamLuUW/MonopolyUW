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
#include <fstream>
using namespace std;
//default ctor
Board::Board(){
		//set all player pointers to NULL
	for(int i=0; i<6; i++){
		players[i]=NULL;
	}

	//set all cells to NULL
	for(int i=0; i<40; i++){
		cells[i]=NULL;
	}

	//set all int fields to 0
	numofpl = 0;
	faceVal = 0;
	currentPlayer = 0;
	roll = 0;
	//set dice to NULL
	dices[0]=NULL;
	dices[1]=NULL;

	//set controller to NULL
	con=NULL;
}


//delete a single players and 
void Board::deletePlayer(string plname){
	int i=0; //index for the player who is suppose to be deleted
	//find this player whos name is plname
	for(; i<numofpl; i++){
		if(players[i]->getplayerName()==plname){
			break;
		}
	}

	delete players[i];
	players[i]= NULL;
	//update the array
	for(int j=i+1; j<numofpl; j++){
		players[i]=players[j];
		i++;
	}
	numofpl--; //decrement number of player by 1
}
	

//default dtor
Board::~Board(){
	cleanBoard();
}
/*
void Board::dynamicCast(){
	OSAP * c0 = dynamic_cast<OSAP *>(cells[0]);
	Academic * c1 = dynamic_cast<Academic *>(cells[1]);
	SLC * c2 = dynamic_cast<SLC *>(cells[2]);
	Academic * c3 = dynamic_cast<Academic *>(cells[3]);
	Tuition * c4 = dynamic_cast<Tuition *>(cells[4]);
	Residence * c5 = dynamic_cast<Residence *>(cells[5]);
	Academic * c6 = dynamic_cast<Academic *>(cells[6]);
	NeedlesHall * c7 = dynamic_cast<NeedlesHall *>(cells[7]);
	Academic * c8 = dynamic_cast<Academic *>(cells[8]);
	Academic * c9 = dynamic_cast<Academic *>(cells[9]);
	TimLine * c10 = dynamic_cast<TimLine *>(cells[10]);
	Academic * c11 = dynamic_cast<Academic *>(cells[11]);
	Gym * c12 = dynamic_cast<Gym *>(cells[12]);
	Academic * c13 = dynamic_cast<Academic *>(cells[13]);
	Academic * c14 = dynamic_cast<Academic *>(cells[14]);
	Residence * c15 = dynamic_cast<Residence *>(cells[15]);
	Academic * c16 = dynamic_cast<Academic *>(cells[16]);
	SLC * c17 = dynamic_cast<SLC *>(cells[17]);
	Academic * c18 = dynamic_cast<Academic *>(cells[18]);
	Academic * c19 = dynamic_cast<Academic *>(cells[19]);
	GooseNest * c20 = dynamic_cast<GooseNest *>(cells[20]);
	Academic * c21 = dynamic_cast<Academic *>(cells[21]);
	NeedlesHall * c22 = dynamic_cast<NeedlesHall *>(cells[22]);
	Academic * c23 = dynamic_cast<Academic *>(cells[23]);
	Academic * c24 = dynamic_cast<Academic *>(cells[24]);
	Residence * c25 = dynamic_cast<Residence *>(cells[25]);
	Academic * c26 = dynamic_cast<Academic *>(cells[26]);
	Academic * c27 = dynamic_cast<Academic *>(cells[27]);
	Gym * c28 = dynamic_cast<Gym *>(cells[28]);
	Academic * c29 = dynamic_cast<Academic *>(cells[29]);
	GoToTim * c30 = dynamic_cast<GoToTim *>(cells[30]);
	Academic * c31 = dynamic_cast<Academic *>(cells[31]);
	Academic * c32 = dynamic_cast<Academic *>(cells[32]);
	SLC * c33 = dynamic_cast<SLC *>(cells[33]);
	Academic * c34 = dynamic_cast<Academic *>(cells[34]);
	Residence * c35 = dynamic_cast<Residence *>(cells[35]);
	NeedlesHall * c36 = dynamic_cast<NeedlesHall *>(cells[36]);
	Academic * c37 = dynamic_cast<Academic *>(cells[37]);
	Academic * c39 = dynamic_cast<Academic *>(cells[39]);
}*/

//clear the board
void Board::cleanBoard(){
	//delete all players
	for(int i=0; i<numofpl; i++){
		delete players[i];
	}

	//delete all cells
	for(int i=0; i<40; i++){
		delete cells[i];
	}
 
	//delete all dices
	delete dices[0];
	delete dices[1];

}

//initial a player's fields
void Board::initialPlayer(string name, char piece, int timcups, 
	int cash, int position, bool timline, int numoftimline){
	Player * newpl = new Player(name, piece);
	newpl->setNumofTimCups(timcups);
	newpl->setCash(cash);
	newpl->setPosition(position);
	newpl->setTimLine(timline);
	newpl->setTurninTimLine(numoftimline);
	//put newpl to the players array;
	players[numofpl] = newpl;
	//increment num of players by 1
	numofpl++;
	cout<< "___________" << newpl->getplayerName() << " has been created, you initial cash is $" << newpl->getCash() << " position is " << newpl->getPosition() << " num of Tim Cups is " << newpl->getNumofTimCups() << " and you spend " << newpl->getTurninTimLine() << " turns in Tim Line______" << endl;
	notifyMove(0, position, piece);
}

//set a board
void Board::setBoard(){
	cells[0]= new OSAP("OSAP", 0, false, this);
	cells[1]= new Academic("AL", 1, true, this, 40, 0, 0, 40, 50, 1);
	cells[2]= new SLC("SLC", 2, false, this);
	cells[3]= new Academic("ML", 3, true, this, 60, 0, 0, 60, 50, 1);
	cells[4]= new Tuition("Tuition", 4, false, this);
	cells[5]= new Residence("MKV", 5, true, this, 200, 0);
	cells[6]= new Academic("ECH", 6, true, this, 100, 0, 0, 100, 50, 2);
	cells[7]= new NeedlesHall("Needles Hall", 7, false ,this);
	cells[8]= new Academic("PAS", 8, true, this, 100, 0, 0, 100, 50, 2);
	cells[9]= new Academic("HH", 9, true, this, 120, 0, 0, 120, 50, 2);
	cells[10]= new TimLine("DC Tims Line", 10, false, this);
	cells[11]= new Academic("RCH", 11, true, this, 140, 0, 0, 140, 100, 3);
	cells[12]= new Gym("PAC", 12, true, this, 150, 0);
	cells[13]= new Academic("DWE", 13, true, this, 140, 0, 0, 140, 100, 3);
	cells[14]= new Academic("CPH", 14, true, this, 160, 0, 0, 160, 100, 3);
	cells[15]= new Residence("UWP", 15, true, this, 200, 0);
	cells[16]= new Academic("LHI", 16, true, this, 180, 0, 0, 180, 100, 4);
	cells[17]= new SLC("SLC", 17, false, this);
	cells[18]= new Academic("BMH", 18, true, this, 180, 0, 0, 180, 100, 4);
	cells[19]= new Academic("OPT", 19, true, this, 200, 0, 0, 200, 100, 4);
	cells[20]= new GooseNest("Goose Nesting", 20, false, this);
	cells[21]= new Academic("EV1", 21, true, this, 220, 0, 0, 220, 150, 5);
	cells[22]= new NeedlesHall("Needles Hall", 22, false, this);
	cells[23]= new Academic("EV2", 23, true, this, 220, 0, 0, 220, 150, 5);
	cells[24]= new Academic("EV3", 24, true, this, 240, 0, 0, 240, 150, 5);
	cells[25]= new Residence("V1", 25, true, this, 200, 0);
	cells[26]= new Academic("PHYS", 26, true, this, 260, 0, 0, 260, 150, 6);
	cells[27]= new Academic("B1", 27, true, this, 260, 0, 0, 260, 150, 6);
	cells[28]= new Gym("CIF", 28, true, this, 150, 0);
	cells[29]= new Academic("B2", 29, true, this, 280, 0, 0, 280, 150, 6);
	cells[30]= new GoToTim("GO TO TIMS", 30, false, this);
	cells[31]= new Academic("EIT", 31, true, this, 300, 0, 0, 300, 200, 7);
	cells[32]= new Academic("ESC", 32, true, this, 300, 0, 0, 300, 200, 7);
	cells[33]= new SLC("SLC", 33, false, this);
	cells[34]= new Academic("C2", 34, true, this, 320, 0, 0, 320, 200, 7);
	cells[35]= new Residence("REV", 35, true, this, 200, 0);
	cells[36]= new NeedlesHall("Needles Hall", 36, false, this);
	cells[37]= new Academic("MC", 37, true, this, 350, 0, 0, 350, 200, 8);
	cells[38]= new CoopFee("COOP FEE", 38, false, this);
	cells[39]= new Academic("DC", 39, true, this, 400, 0, 0, 400, 200, 8);
	// add neighbouts for each academic cell
	Academic * c1 = dynamic_cast<Academic *>(cells[1]);
	Academic * c3 = dynamic_cast<Academic *>(cells[3]);
	Academic * c6 = dynamic_cast<Academic *>(cells[6]);
	Academic * c8 = dynamic_cast<Academic *>(cells[8]);
	Academic * c9 = dynamic_cast<Academic *>(cells[9]);
	Academic * c11 = dynamic_cast<Academic *>(cells[11]);
	Academic * c13 = dynamic_cast<Academic *>(cells[13]);
	Academic * c14 = dynamic_cast<Academic *>(cells[14]);
	Academic * c16 = dynamic_cast<Academic *>(cells[16]);
	Academic * c18 = dynamic_cast<Academic *>(cells[18]);
	Academic * c19 = dynamic_cast<Academic *>(cells[19]);
	Academic * c21 = dynamic_cast<Academic *>(cells[21]);
	Academic * c23 = dynamic_cast<Academic *>(cells[23]);
	Academic * c24 = dynamic_cast<Academic *>(cells[24]);
	Academic * c26 = dynamic_cast<Academic *>(cells[26]);
	Academic * c27 = dynamic_cast<Academic *>(cells[27]);
	Academic * c29 = dynamic_cast<Academic *>(cells[29]);
	Academic * c31 = dynamic_cast<Academic *>(cells[31]);
	Academic * c32 = dynamic_cast<Academic *>(cells[32]);
	Academic * c34 = dynamic_cast<Academic *>(cells[34]);
	Academic * c37 = dynamic_cast<Academic *>(cells[37]);
	Academic * c39 = dynamic_cast<Academic *>(cells[39]);

	cells[1]->addNeighbour(c3);
	cells[3]->addNeighbour(c1);
	cells[6]->addNeighbour(c8);
	cells[6]->addNeighbour(c9);
	cells[8]->addNeighbour(c6);
	cells[8]->addNeighbour(c9);
	cells[9]->addNeighbour(c6);
	cells[9]->addNeighbour(c8);
	cells[11]->addNeighbour(c13);
	cells[11]->addNeighbour(c14);
	cells[13]->addNeighbour(c11);
	cells[13]->addNeighbour(c14);
	cells[14]->addNeighbour(c11);
	cells[14]->addNeighbour(c13);
	cells[16]->addNeighbour(c18);
	cells[16]->addNeighbour(c19);
	cells[18]->addNeighbour(c16);
	cells[18]->addNeighbour(c19);
	cells[19]->addNeighbour(c16);
	cells[19]->addNeighbour(c18);
	cells[21]->addNeighbour(c23);
	cells[21]->addNeighbour(c24);
	cells[23]->addNeighbour(c21);
	cells[23]->addNeighbour(c24);
	cells[24]->addNeighbour(c23);
	cells[24]->addNeighbour(c21);
	cells[26]->addNeighbour(c27);
	cells[26]->addNeighbour(c29);
	cells[27]->addNeighbour(c26);
	cells[27]->addNeighbour(c29);
	cells[29]->addNeighbour(c26);
	cells[29]->addNeighbour(c27);
	cells[31]->addNeighbour(c32);
	cells[31]->addNeighbour(c34);
	cells[32]->addNeighbour(c31);
	cells[32]->addNeighbour(c34);
	cells[34]->addNeighbour(c31);
	cells[34]->addNeighbour(c32);
	cells[37]->addNeighbour(c39);
	cells[39]->addNeighbour(c37);

	//set rent List
	c1->setRentList(2, 10, 30, 90, 160, 250);
	c3->setRentList(4, 20, 60, 180, 320, 450);
	c6->setRentList(6, 30, 90, 270, 400, 550);
	c8->setRentList(6, 30, 90, 270, 400, 550);
	c9->setRentList(8, 40, 100, 300, 450, 600);
	c11->setRentList(10, 50, 150, 450, 620, 750);
	c13->setRentList(10, 50, 150, 450, 620, 750);
	c14->setRentList(12, 60, 180, 500, 700, 900);
	c16->setRentList(14, 70, 200, 550, 750, 950);
	c18->setRentList(14, 70, 200, 550, 750, 950);
	c19->setRentList(16, 80, 220, 600, 800, 1000);
	c21->setRentList(18, 90, 250, 700, 875, 1050);
	c23->setRentList(18, 90, 250, 700, 875, 1050);
	c24->setRentList(20, 100, 300, 750, 925, 1100);
	c26->setRentList(22, 110, 330, 800, 975, 1150);
	c27->setRentList(22, 110, 330, 800, 975, 1150);
	c29->setRentList(24, 120, 360, 850, 1025, 1200);
	c31->setRentList(26, 130, 390, 900, 1100, 1275);
	c32->setRentList(26, 130, 390, 900, 1100, 1275);
	c34->setRentList(28, 150, 450, 1000, 1200, 1400);
	c37->setRentList(35, 175, 500, 1100, 1300, 1500);
	c39->setRentList(50, 200, 600, 1400, 1700, 2000);

	cout << "___________Game Board created___________" << endl;

}

//initial a cell
void Board::initCell(string cellname, string owner, int numofImp){
	Player *ownerp;
	//finder the owner pointer
	for(int i=0; i<numofpl; i++){
		if(players[i]->getplayerName()==owner){
			ownerp=players[i];
			break;
		}
	}


	for(int i=0; i<40; i++){
		if((cells[i]->getName()==cellname) && (owner != "BANK")){
			cells[i]->setOwnerExist(true);
			cells[i]->setOwner(ownerp);
			cells[i]->setNumofImp(numofImp);
			if(cellname == "MKV" || cellname == "UWP" || cellname == "V1" || cellname == "REV"){
				cells[i]->notifyPlayerRes();
			}else if (cellname == "CIF" || cellname == "PAC"){
				cells[i]->notifyPlayerGym();
			}else{
				cells[i]->notifyPlayer();
			}

			notifyMove(cells[i]->getIndex(), cells[i]->getIndex(), ownerp->getPiece());
			notifyImprove(cells[i]->getIndex(), numofImp);

		}
	}

}

//initial a game which will set controller pointer and create a board
void Board::initialization(Controller *con, int n){
	setBoard();
	getDice();
	this->con = con;
}

//initial two dice object
void Board::getDice(){
	Dice *dice1 = new Dice;
	Dice *dice2 = new Dice;
	dices[0]=dice1;
	dices[1]=dice2;
}

//delete two created dices
void Board::deleteDice(){
	delete dices[0];
	delete dices[1];
}

//roll dices
void Board::rollDice(){
	dices[0]->roll();
	dices[1]->roll();
}

//get value of two dices
void Board::getFaceValue(){
	rollDice();
	int r1 = dices[0]->getVal();
	int r2 = dices[1]->getVal();
	int total = r1 + r2;
	if(r1==r2){
		doubleroll = true;
		cout << "WOW, It is a double" << endl;
		cout << "Your total face value is " << total << endl;
	}else{
		doubleroll = false;
		cout << "Your total face value is " << total << endl;
		roll = 0;
	}
	
	cout << "You rolled a "<< r1 <<  " and a " << r2 << endl;
	this ->faceVal = total;
}

void Board::setFaceValue(int n){
	this->faceVal = n;
}

//check how many players are still playing and return true of
//there is only one player left
bool Board::checkWin(){
	if(numofpl > 1){
		return false;
	}else if (numofpl == 1){
		int i=0;
		for(; i < 6; i++){
			if(players[i]!= NULL)break;
		}
		cout << "Game Over! The Winner is " << players[i]->getplayerName() << endl;
		return true;
	}else{
		cout << "checkWin Error" << endl;
	}
}

bool Board::checkTimCards(){
	int totalcard = 0;
	for(int i=0; i< numofpl; i++){
		totalcard += players[i]->getNumofTimCups();
	}

	if(totalcard <= 4){
		return true;
	}else {
		return false;
	}
}

//set current player to the next player
void Board::next(){
	roll = 0;
	if(currentPlayer == numofpl - 1){
		currentPlayer = 0;
	}else{
		currentPlayer++;
	}
	cout << "Now it is " << players[currentPlayer]->getplayerName()
	      << "'s turn." << endl;
}

//notify the cell that a lander is here
void Board::notifyCell(int index){
	cells[index]->setlander(players[currentPlayer], currentPlayer);
}

void Board::buyBuilding(){
	int index = players[currentPlayer]->getPosition();
	Cell *cur = cells[index];
	if(!cur->isOwnable()){
		cout << "Sorry this Square is Unownable!" << endl;
	}else{
		if(cur->getOwnerExist()){
			cout << "Sorry this buidling has a owner alreaday" << endl;
		}else{
			int cost = cur->getPurchaseCost();
			cur->setOwner(players[currentPlayer]);
			if(index == 5 || index == 15 || index ==25 || index ==35){
				cout << "You bought a residence and its name is " << cur->getName() << endl;
				cur->notifyPlayerRes(); 
			}else if ( index == 12 || index == 28){
				cout << "You bought a Gym and its name is " << cur->getName() << endl;
				cur->notifyPlayerGym(); 
			}else{
				cout << "You bought a Academic Building and its name is " << cur->getName() << endl;
				cur->notifyPlayer();
			}

			cur->charge(-cost, players[currentPlayer]);
			cout << "You paid $" << cost << endl;
		}// if for getOwnerExist
	}// if for is Ownable
}


int Board::findWealth(){
	int wealth=0;
	Player *pl = players[currentPlayer];
	for(int i=0; i<40; i++){
		Cell *cur = cells[i];
		
		if(cur->getOwner()== pl){
			wealth += cur->getTotalCost();
		}
	}
	wealth+=pl->getCash();
	//cout << pl->getplayerName() << "'s total wealth is " << wealth << endl;
	return wealth;
}

void Board::bankruptcy() {
	if (players[currentPlayer]->getCash() <= 0 && (findWealth() > 0) ) {
		cout << "You still have some properties! Sell them to survival!" << endl;
	}
	else if (players[currentPlayer]->getCash() > 0 && (findWealth() > 0) ) {
		cout << "You still have MONEY ~~~" << endl;
	}
	else {
		cout << "There is not enough money for you to play the game... Sorry, you are bankruptcy. Byebye~~" << endl;
		deletePlayer (players[currentPlayer]->getplayerName());
		//checkWin();
	}
}

void Board::assets ( ) {
	cout << "Name : " << players[currentPlayer]->getplayerName() << endl; 
	cout << "The Player has " << players[currentPlayer]->getCash() << " cash." << endl;
	cout << "The Player has " << findWealth() << " wealth in total(this include cash,and properties)." << endl;
	cout << "The Player has " << players[currentPlayer]->getNumofTimCups() << " Tim cups." << endl;
}

/*

void Board::exit ( ) {
	string e;
	cout << "Do you want to EXIT ( T / F )?" << endl;
	cin >> e;

	if ( e == "T") {
		return;
	}
	else {
		cout << "Keep paly!" << endl;
	}
	
	while ( e != "T" && e != "F") {
		cout << "Wrong choice~ Please choose T or F ! " << endl;
		cin >> e;
	}
}

*/


void Board::buyImprove(){
	cout << "Please type the name of your property that you want to improve" << endl;
	string name;
	cin >> name;
	int i=0;
	for(; i< 40; i++){
		if(cells[i]->getName()==name)break;
	}
	Cell *cur = cells[i];
	if(cur->getOwner()->getplayerName()==players[currentPlayer]->getplayerName()){
		cur->buyImprovements();

		////////////
		notifyImprove (i, cur->getNumofImp( ));
		//

	}else{
		cout << "This is not your property!" << endl;
	}
}

void Board::sellImprove(){
	cout << "Please type the name of your property that you want to sell improve" << endl;
	string name;
	cin >> name;
	int i=0;
	for(; i< 40; i++){
		if(cells[i]->getName()==name)break;
	}
	Cell *cur = cells[i];
	if(cur->getOwner()->getplayerName()==players[currentPlayer]->getplayerName()){
		cur->sellImprovements();
		//////////////
				notifyImprove (i, cur->getNumofImp( ));
		//
	}else{
		cout << "This is not your property!" << endl;
	}
}

///////////////
void Board::makemove(){
	Player *pl = players[currentPlayer];
	//bool doubleroll = false;
	//rollDice();
	roll++;
	int steps = this->faceVal;
	/*
	if(dices[1]->getVal()==dices[0]->getVal()){
		doubleroll = true;
		cout << "WOW, It is a double" << endl;
		cout << "Your total face value is " << steps << endl;
	}else{
		cout << "Your total face value is " << steps << endl;
		roll = 0;
	}*/

	if(pl->isTimLine()){
		pl->setTurninTimLine(1+pl->getTurninTimLine());
		cout << "Opps, you are still in Tim Line" <<endl;
		if(doubleroll){
			cout << "But you rolled a double, so you can move on next turn" << endl;
			pl->setTimLine(false);
			pl->setTurninTimLine(0);
			doubleroll = false;
		}else{
			cout << "Do you want to pay Cash or Tim Card to get out of line? (Cash/Card/Wait)" << endl;
			string answer;
			while(cin >> answer){
				if (answer == "Cash"){
					pl->setCash(-50);
					bankruptcy();
					pl->setTimLine(false);
					pl->setTurninTimLine(0);
					cout << "You paid $50 and you can move for next turn" << endl;
					break;
				}else if (answer == "Card"){
					if(pl->getNumofTimCups()==0){
						cout << "You do not have Time Cups, Try again!"<<endl;
					}else{
						cout << "You used one of your tim cups " << endl;
						pl->setNumofTimCups(pl->getNumofTimCups()-1);
						pl->setTimLine(false);
						pl->setTurninTimLine(0);
						break;
					}
				}else if(answer == "Wait"){
					cout << "Alright, wait another turn!" << endl;
					break;
				}else{
					cout << "Wrong Command, Try again!" <<endl;
				}
			}	

			if(pl->getTurninTimLine() == 3){
				cout << "Oh, This is your thrid turn in the line, you have to pay $50 or use Tim Card" << endl;
				cout <<"(Cash/Card)" << endl;
				
				string temp;
				while(true){
					cin >> temp;
					if(temp == "Cash" || temp == "Card"){ 
						break;
					}else{
						cout << "Wrong Command, Try Again!" << endl;
					}
				}

				if (temp == "Cash"){
					pl->setCash(-50);
					bankruptcy();
					pl->setTimLine(false);
					pl->setTurninTimLine(0);
					cout << "You paid $50 and you can move for next turn" << endl;
				}else{
					if(pl->getNumofTimCups()==0){
						cout << "You do not have Time Cups, so you are forced to leave by pay $50"<<endl;
						pl->setCash(-50);
						bankruptcy();
						pl->setTimLine(false);
						pl->setTurninTimLine(0);
					}else{
						cout << "You used one of your tim cups " << endl;
						pl->setNumofTimCups(pl->getNumofTimCups()-1);
						pl->setTimLine(false);
						pl->setTurninTimLine(0);
					}
				}

			}else{
				cout << "You did not roll a double so wait fot next turn"<<endl;
				pl->setTurninTimLine(pl->getTurninTimLine()+1);
			}
		}		

	}else{
		
			int oldpos = pl->getPosition();
			int newpos = steps + oldpos;
			if (newpos >= 40){
				newpos -= 40;
				cells[0]->Effect(players[currentPlayer]); // pass by OSAP so give the player $200
			}
			Cell *cur = cells[newpos];
			cout << "You are moving to " << cur->getName() << endl;
			pl->setPosition(newpos);
			notifyCell(newpos);
			cells[oldpos]->deletelander(currentPlayer);
			notifyMove(oldpos, newpos, pl->getPiece());
			if(cur->isOwnable()){
				if(cur->getOwnerExist()){
					Player * owner = cur->getOwner();
					if(!(owner->getplayerName()==pl->getplayerName())){
						cur->setRent();
						cout << "You landed on someone's owned property!" << endl;
						int amount = cur->getRent();
					
						cout << "You need pay $" << amount << " to " << owner->getplayerName() << endl;
						bankruptcy(); // ??????????????
						cur->charge(amount, owner);
						cur->charge(-amount, pl);
					}else{
						cout << "You landed on your own property!"<<endl;
	
					}
				}else{
					cout << "You landed on an unowned property" <<endl;
					int amount = cur->getPurchaseCost();
					cout << "This property cost is $" << amount << endl;
					cout << "You can either (Buy/Auction) this property" <<endl;
					string temp;
					while(true){
						cin >> temp;
						if(temp=="Buy" || temp=="Auction"){
							break;
						}else{
							cout << "Wrong command, Try Again!"<<endl;
						}
					}
	
					if(temp=="Buy"){
						cur->setOwner(pl);
						cur->setOwnerExist(true);
						cur->charge(-amount, pl);
						if(cur->getIndex()==12 || cur->getIndex()==28){
							cout << "You just bought a Gym called " << cur->getName() << endl;
							cout << "You paid $" << amount << endl;
							cur->notifyPlayerGym();
						}else if (cur->getIndex()==5 || cur->getIndex()==15 || cur->getIndex()==25 || cur->getIndex()==35){
							cout << "You just bought a Residence called " << cur->getName() << endl;
							cout << "You paid $" << amount << endl;
							cur->notifyPlayerRes();
						}else{
							cout << "You just bought an Academic Building called " << cur->getName() << endl;
							cout << "You paid $" << amount << endl;
							cur->notifyPlayer();
						}
					}else{
						cout << "Auction feature is not ready yet!";
					}
				}// unowned property
	
			}else{
				cout << "You landed on an unownable cell!" << endl;
				// Goto Tim Line case
				if(cur->getIndex()==30){
					cout << "You are now sent to Tim Line" << endl;
					cout << "You are in TimLine now" << endl;
					pl->setPosition(10);
					pl->setTimLine(true);
					pl->setTurninTimLine(1);
					notifyCell(10);
					cells[30]->deletelander(currentPlayer);
				}else{
					cur->Effect(players[currentPlayer]);
				}// unownable other than goto Tim Line
	
			}// Not Ownable

		if(roll < 3 && doubleroll){
			cout << "Since you rolled a double, you can roll again" << endl;
			doubleroll=false;

		}else if (roll == 3){
			 
			cout << "You rolled doulble too many times so you are sending to Tim Line now" << endl;
			pl->setPosition(10);
			pl->setTimLine(true);
			pl->setTurninTimLine(1);
			notifyCell(10);
			cur->deletelander(currentPlayer);
			roll = 0;
		}else {
			return;
		}

	}// not in Time Line
}


void Board::notifyMove(int oldposition, int newposition, char piece){
	this->con->notifyMove(oldposition, newposition, piece);
}

void Board::notifyImprove(int position, int level){
	this->con->notifyImprove(position, level);
}


void Board::save (string savingFile ) {
	cout << "Saving......" << endl;

	//(output) Allow output operations on the stream.
	ofstream file;
	file.open(savingFile.c_str());

	file << numofpl << endl;

	for (int i = 0; i < numofpl; i++) {
		file << players[i]->getplayerName() << " " << players[i]->getPiece() << " " << players[i]->getNumofTimCups() 
			<<" " << players[i]->getCash() << " " << players[i]->getPosition();
		if (players[i]->getPosition() == 10 ) {
			file << " ";
			if ( players[i]->isTimLine()) {
				file << 1 <<" " << players[i]->getTurninTimLine() << endl;
			}
			else {
				file << 0 << endl;
			}
		}
		else {
			file << endl;
		}
	}

	for ( int i = 0; i < 40; i++) {
		if (cells[i]->isOwnable()) {
			file << cells[i]->getName() << " " ;
			if (cells[i]->getOwnerExist()) {
				file << cells[i]->getOwner()->getplayerName()<< " " ;
			}
			else {
				file << "BANK" << " ";
			}
			if ( cells[i]->isMortgage() ) {
				file << -1 << endl;
			}
			else if ( !cells[i]->isMonopoly()) {
				file << 0 << endl;
			}
			else {
				file << cells[i]->getNumofImp() << endl;
			}
		}
	}

	file.close();

}



////////////////////////////////////////////

void Board::trade(std::string name, int give, std::string receive){}
void Board::trade(std::string name, std::string give, int receive){}
void Board::trade(std::string name, std::string give, std::string receive){}
void Board::mortgage(){}
void Board::unmortgage(){}





