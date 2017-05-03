#include "controller.h"
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>

//
#include "view.h"
#include "board.h"
#include "textdisplay.h"
using namespace std;

Controller::Controller ( ) {
	view = new TextDisplay();
	bd = new Board ( );
}


Controller::~Controller(){
	//
	delete view;
	delete bd;
}

void Controller::setNew(bool b){
	IsAnewgame = b;
}
 
void Controller::setFile(string s){
	this->readinfile = s;
}

bool Controller::checkWin ( ) const {
	return bd->checkWin();
}


void Controller::Play ( ) {
	string cmd;
	char numofplayer;
	int numofpl=0;
	string name;
	char piece;
	string ownName;

	//plase all names & pieces in the array
	//use array to check if the name has been chosen
	string namelist[8] = {"Goose", "GRTBus", "TimHortons Doughnut","Professor", "Student", "Money", "Laptop", "PinkTie"};
	char namepiece[8] = {'G','B','D','P','S','$','L','T'};
	bool namechoose[8] = {false};


	cout << "Welcome to our UWBuildingBuyer!" << endl;
	cout << "Let's start the game! " << endl;
	
//first case, a new game started
if (IsAnewgame) {
		view->draw();
	cout << "Please choose the number of players (2 - 6) !" << endl;
	//get the number of players in the game
	while ( cin >> numofplayer ) {
			if ( ! (numofplayer >= '2' && numofplayer <= '6')) {
				cout << "Wrong number of player, only accept 2 - 6 players!" << endl;
				cout << "Please choose again! " << endl;

			}
			else {
				//set the numofpl feild in bd to be numofplayer
				cout << "You entered " << numofplayer <<endl;;
				break;
			}
	}
	numofpl = numofplayer - '0';
	//set the board
	bd->initialization(this, numofpl);

	//get the name and pieces for the palyers
	for ( int i = 0; i < numofpl; i++ ) {
		cout << "Namelist: Goose, GRTBus, TimHortons Doughnut, "
			<< "Professor, Student, Money, Laptop, PinkTie" << endl;

		cout << "Please choose a name in the game for player" << i + 1<< endl;
		cin >> name;

		cout << "Please set up your own name." << endl;
		cin >> ownName;

			for ( int a = 0; a < 8; a++) {
				if (name == namelist[a] && namechoose[a] == false) {
						namechoose[a] = true;
						cout << "Your piece is " << namepiece[a] << endl;

						bd->initialPlayer(ownName, namepiece[a], 0, 1500, 0, false, 0);
						break;
				}
				if ( a == 7) {
					cout << "Wrong name, please reenter a name." << endl;

				}

			}
	}

}

//when the game is started from half way
else {
	view->draw();
	int numPlayers;
	string players;
	char sym;
	int TimsCups;
	int money;
	int position;
	int numoftimline = -1;
	string cellname;
	string owner;
	int improvements;
	int intheTimLine;
	cout << readinfile << endl;
	ifstream file;
	file.open(readinfile.c_str(), ifstream::in);

	file >> cmd;

	//read the first line as numPlayers
	stringstream s(cmd);
	s >> numPlayers;
	//set the board
	bd->initialization(this, numPlayers);

	//read in lines that decribe the players
	//player1 char TimsCups money position
	int i = 0;
	while (i < numPlayers) {
		file >> players;
		file >> sym;
		file >> TimsCups;
		file >> money;
		file >> position;

		//when the player landing on the DC tims line
		if ( position == 10 ) {
			file >> intheTimLine ;
			if (intheTimLine == 0) {
				bd->initialPlayer(players, sym, TimsCups, money, 10, false, 0);
			}

			if (intheTimLine == 1) {
				file >> numoftimline;
				if (numoftimline>=0 && numoftimline <= 2) {
					bd->initialPlayer(players, sym, TimsCups, money, 10, true, numoftimline);
				}
			}
		}
		//when player landing on the other
		else {
			bd->initialPlayer(players, sym, TimsCups, money, position, false, 0);
		}
		i++;
	}

	//readin all buildings in the file
	//eg: AL owner improvements
	int a = 0;
	while ( a < 28) {
		file >> cellname;
		file >> owner;
		file >> improvements;

		if(improvements<0){
			improvements=0;
		}

		bd->initCell( cellname, owner, improvements);

		a++;
	}
}



while (!checkWin()) {
	string n;
	int give;
	int receive;
	string sgive;
	string sreceive;
	string tradeWay;


	cout << "Let's play! roll-trade-buy-mortgage-unmortgage-getFaceValue" 
		<< "-buyImprove-sellImprove-bankruptcy-assets-next-save-exit " << endl;
	cin >> cmd;
	if ( cmd == "roll") {
		bd->getFaceValue();
		bd->makemove();
	}
	else if (cmd == "trade" ) {
		cout << " Please choose a player to trade." << endl;
		cin >> n;
		cout << "Please choose a way of trading. money-property"
			 << "/property-money/property-property" << endl; 
		cin >> tradeWay;
		if (tradeWay == "money-property") {
			cout << "Please choose the amount of money you will pay." << endl;
			cin >> give;
			cout << "Please choose the name of property you want." << endl;
			cin >> sreceive;
			bd-> trade(n, give, sreceive);
		}
		else if ( tradeWay == "property-money") {
			cout << "Please choose the name of property you will trade." << endl;
			cin >> sgive;
			cout << "Please choose the amount of money you want." << endl;
			cin >> receive;
			bd-> trade(n, sgive, receive);
		}
		else {
			cout << "Please choose the name of property you will trade." << endl;
			cin >> sgive;
			cout << "Please choose the name of property you want." << endl;
			cin >> sreceive;
			bd-> trade(n, sgive, sreceive);
		}
	}
	else if (cmd == "buy") {
		cout << "You can not Buy yet!" << endl;
	}
	else if (cmd == "mortgage" ) {
		bd->mortgage();
	}
	else if (cmd == "unmortgage") {
		bd->unmortgage();
	}
	else if ( cmd == "getFaceValue") {
		bd->getFaceValue();
	}
	else if ( cmd == "buyImprove") {
		bd->buyImprove();
	}
	else if (cmd == "sellImprove") {
		bd->sellImprove();
	}
	else if  (cmd == "bankruptcy") {
		bd->bankruptcy();
	}
	else if (cmd == "assets") {
		bd->assets();
	}
	else if ( cmd == "next") {
		bd->next();
	}
	else if (cmd == "next") {
		bd->next();
	}
	else if ( cmd == "save") {
		string temp;
		cout << "Type a file name" << endl;
		cin >> temp;
		bd->save(temp);
	}
	else if (cmd == "exit") {
		//bd->exit();
		return;
	}
	else {
		cout << "Wrong command, please redo it. " << endl;
	}
}
}




void Controller::Notify ( char piece, string cellname, int numofimp ) {
	view->Notify (piece, cellname, numofimp);
}


void Controller::notifyMove(int oldpos, int newpos, char piece){
	view->notify(oldpos, newpos, piece);
}

void Controller::notifyImprove(int pos, int level){
	view->notify(pos, level);
}

















