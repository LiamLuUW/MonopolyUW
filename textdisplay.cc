#include "textdisplay.h"
#include "displaycell.h"

using namespace std;

TextDisplay::TextDisplay ( ) {
	for ( int i = 0; i < 40 ; i++) {
			displaycell[i] = new DisplayCell ( );
	}
}

TextDisplay::~TextDisplay ( ) {
	for ( int i = 0; i < 40; i++ ) {
		delete displaycell[i];
//		displaycell[i] = 0;
	}
}


void TextDisplay::Notify (char piece, string cellname, int numofimp) {
if ( cellname == "OSAP") {
	displaycell[0]->setimpro(numofimp);
	displaycell[0]->setpiece(piece);
}
if ( cellname == "AL") {
	displaycell[1]->setimpro(numofimp);
	displaycell[1]->setpiece(piece);
}
if ( cellname == "SLC") {
	displaycell[2]->setimpro(numofimp);
	displaycell[2]->setpiece(piece);
}
if ( cellname == "ML") {
	displaycell[3]->setimpro(numofimp);
	displaycell[3]->setpiece(piece);
}
if ( cellname == "Tuition") {
	displaycell[4]->setimpro(numofimp);
	displaycell[4]->setpiece(piece);
}
if ( cellname == "MKV") {
	displaycell[5]->setimpro(numofimp);
	displaycell[5]->setpiece(piece);
}
if ( cellname == "ECH") {
	displaycell[6]->setimpro(numofimp);
	displaycell[6]->setpiece(piece);
}
if ( cellname == "Needles Hall") {
	displaycell[7]->setimpro(numofimp);
	displaycell[7]->setpiece(piece);
}
if ( cellname == "PAS") {
	displaycell[8]->setimpro(numofimp);
	displaycell[8]->setpiece(piece);
}
if ( cellname == "HH") {
	displaycell[9]->setimpro(numofimp);
	displaycell[9]->setpiece(piece);
}
if ( cellname == "DC Tims Line") {
	displaycell[10]->setimpro(numofimp);
	displaycell[10]->setpiece(piece);
}
if ( cellname == "RCH") {
	displaycell[11]->setimpro(numofimp);
	displaycell[11]->setpiece(piece);
}
if ( cellname == "PAC") {
	displaycell[12]->setimpro(numofimp);
	displaycell[12]->setpiece(piece);
}
if ( cellname == "DWE") {
	displaycell[13]->setimpro(numofimp);
	displaycell[13]->setpiece(piece);
}
if ( cellname == "CPH") {
	displaycell[14]->setimpro(numofimp);
	displaycell[14]->setpiece(piece);
}
if ( cellname == "UWP") {
	displaycell[15]->setimpro(numofimp);
	displaycell[15]->setpiece(piece);
}
if ( cellname == "LHI") {
	displaycell[16]->setimpro(numofimp);
	displaycell[16]->setpiece(piece);
}
if ( cellname == "SLC") {
	displaycell[17]->setimpro(numofimp);
	displaycell[17]->setpiece(piece);
}
if ( cellname == "BMH") {
	displaycell[18]->setimpro(numofimp);
	displaycell[18]->setpiece(piece);
}
if ( cellname == "OPT") {
	displaycell[19]->setimpro(numofimp);
	displaycell[19]->setpiece(piece);
}
if ( cellname == "Goose Nesting") {
	displaycell[20]->setimpro(numofimp);
	displaycell[20]->setpiece(piece);
}
if ( cellname == "EV1") {
	displaycell[21]->setimpro(numofimp);
	displaycell[21]->setpiece(piece);
}
if ( cellname == "Needles Hall") {
	displaycell[22]->setimpro(numofimp);
	displaycell[22]->setpiece(piece);
}
if ( cellname == "EV2") {
	displaycell[23]->setimpro(numofimp);
	displaycell[23]->setpiece(piece);
}
if ( cellname == "EV3") {
	displaycell[24]->setimpro(numofimp);
	displaycell[24]->setpiece(piece);
}
if ( cellname == "V1") {
	displaycell[25]->setimpro(numofimp);
	displaycell[25]->setpiece(piece);
}
if ( cellname == "PHYS") {
	displaycell[26]->setimpro(numofimp);
	displaycell[26]->setpiece(piece);
}
if ( cellname == "B1") {
	displaycell[27]->setimpro(numofimp);
	displaycell[27]->setpiece(piece);
}
if ( cellname == "CIF") {
	displaycell[28]->setimpro(numofimp);
	displaycell[28]->setpiece(piece);
}
if ( cellname == "B2") {
	displaycell[29]->setimpro(numofimp);
	displaycell[29]->setpiece(piece);
}
if ( cellname == "GO TO TIMS") {
	displaycell[30]->setimpro(numofimp);
	displaycell[30]->setpiece(piece);
}
if ( cellname == "EIT") {
	displaycell[31]->setimpro(numofimp);
	displaycell[31]->setpiece(piece);
}
if ( cellname == "ESC") {
	displaycell[32]->setimpro(numofimp);
	displaycell[32]->setpiece(piece);
}
if ( cellname == "SLC") {
	displaycell[33]->setimpro(numofimp);
	displaycell[33]->setpiece(piece);
}
if ( cellname == "C2") {
	displaycell[34]->setimpro(numofimp);
	displaycell[34]->setpiece(piece);
}
if ( cellname == "REV") {
	displaycell[35]->setimpro(numofimp);
	displaycell[35]->setpiece(piece);
}
if ( cellname == "Needles Hall") {
	displaycell[36]->setimpro(numofimp);
	displaycell[36]->setpiece(piece);
}
if ( cellname == "MC") {
	displaycell[37]->setimpro(numofimp);
	displaycell[37]->setpiece(piece);
}
if ( cellname == "COOP FEE") {
	displaycell[38]->setimpro(numofimp);
	displaycell[38]->setpiece(piece);
}
if ( cellname == "DC") {
	displaycell[39]->setimpro(numofimp);
	displaycell[39]->setpiece(piece);
}
draw( );
}

void TextDisplay::notify (int oldpos, int newpos, char piece ) {
	displaycell[oldpos]->setpiece(piece);
	displaycell[newpos]->setpiece(piece);
//	draw( );
}

void TextDisplay::notify (int pos, int level ) {
	displaycell[pos]->setimpro(level);
	draw( );
}

void coutpiece (DisplayCell* cell){
	for ( int i = 0; i < 6; i++) {
		cout << cell->getpiece(i);
	}
	cout << " ";
	/*
	char n[7];
	n[0] = cell->getpiece(0);
	n[1] = cell->getpiece(1);
	n[2] = cell->getpiece(2); 
	n[3] = cell->getpiece(3);
	n[4] = cell->getpiece(4);
	n[5] = cell->getpiece(5);
	n[6] = char(32);
	return n[7];
	*/
}

void TextDisplay::draw ( ) {

	//1
	cout << "_________________________________________________________________________________________" << endl;
	//2
	cout << "|Goose  |   "<< displaycell[21]->getimpro() << "   |NEEDLES|   " << displaycell[23]->getimpro();
	cout << "   |   " << displaycell[24]->getimpro() << "   |V1     |   " << displaycell[26]->getimpro();
	cout << "   |   " << displaycell[27]->getimpro() << "   |CIF    |   " << displaycell[29]->getimpro();
	cout << "   |GO TO  |" << endl;
	//3
	cout << "|Nesting|-------|HALL   |-------|-------|       |-------|-------|       |-------|TIMS   |" << endl;
	//4
	cout << "|       |EV1    |       |EV2    |EV3    |       |PHYS   |B1     |       |B2     |       |" << endl;
	//5
	cout << "|       |";
	coutpiece (displaycell[21]);
	cout << "|       |";
	coutpiece (displaycell[23]);
	cout << "|" ;
	coutpiece (displaycell[24]);
	cout << "|       |";
	coutpiece (displaycell[26]);
	cout << "|";
	coutpiece (displaycell[27]);
	cout << "|       |";
	coutpiece (displaycell[29]);
	cout << "|       |" <<endl;
	//6
	cout << "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|" << endl;
	//7
	cout << "|   " <<displaycell[19]->getimpro();
	cout << "   |                                                                       |   ";
	cout << displaycell[31]->getimpro() << "   |" << endl;
	//8
	cout << "|-------|                                                                       |-------|" << endl;
	//9
	cout << "|OPT    |                                                                       |EIT    |" << endl;
	//10
	cout << "|";
	coutpiece (displaycell[19]);
	cout << "|                                                                       |";
	coutpiece (displaycell[31]);
	cout << "|" << endl;
	//11
	cout << "|_______|                                                                       |_______|" << endl;
	//12
	cout << "|   " <<displaycell[18]->getimpro();
	cout << "   |                                                                       |   ";
	cout << displaycell[32]->getimpro() << "   |" << endl;
	//13
	cout << "|-------|                                                                       |-------|" << endl;
	//14
	cout << "|BMH    |                                                                       |ESC    |" << endl;
	//15
	cout << "|";
	coutpiece (displaycell[18]);
	cout << "|                                                                       |";
	coutpiece (displaycell[32]);
	cout << "|" << endl;
	//16
	cout << "|_______|                                                                       |_______|" << endl;
	//17
	cout << "|SLC    |                                                                       |SLC    |" << endl;
	//18
	cout << "|       |                      **************                                   |       |" << endl;
	//19
	cout << "|       |                      * Liam.LU    *                                   |       |" << endl;
	//20
	cout << "|       |                      * Fanny.ZHAO *                                   |       |" << endl;
	//21
	cout << "|_______|                      **************                                   |_______|" << endl;
	//22
	cout <<  "|   " <<displaycell[16]->getimpro();
	cout << "   |                                                                       |   ";
	cout << displaycell[34]->getimpro() << "   |" << endl;
	//23
	cout << "|-------|                                                                       |-------|" << endl;
	//24
	cout << "|LHI    |                                                                       |C2     |" << endl;
	//25
	cout << "|";
	coutpiece (displaycell[16]);
	cout << "|              __________________________________________               |";
	coutpiece (displaycell[34]);
	cout << "|" << endl;
	//26
	cout << "|_______|             |                                          |              |_______|" << endl;
	//27
	cout << "|UWP    |             |  ###    ###   #####  ###    ###    ###   |              |REV    |" << endl;
	//28
	cout << "|       |             |  #  #   #  #     #  #   #  #   #  #   #  |              |       |" << endl;
	//29
	cout << "|       |             |  ####   ####    #   #   #  #   #  #   #  |              |       |" << endl;
	//30
	cout << "|       |             |  #   #  #   #  #    #   #  #   #  #   #  |              |       |" << endl;
	//31
	cout << "|_______|             |  ####   ####  #      ###    ###    ###   |              |_______|" << endl;
	//32
	cout <<  "|   " <<displaycell[14]->getimpro();
	cout << "   |             |__________________________________________|              |NEEDLES|" << endl;
	//33
	cout << "|-------|                                                                       |HALL   |" << endl;
	//34
	cout << "|CPH    |                                                                       |       |" << endl;
	//35
	cout << '|';
	coutpiece (displaycell[14]);
	cout << "|                                                                       |       |" << endl;
	//36
	cout << "|_______|                                                                       |_______|" << endl;
	//37
	cout << "|   " <<displaycell[13]->getimpro();
	cout << "   |                                                                       |   ";
	cout << displaycell[37]->getimpro() << "   |" << endl;
	//38
	cout << "|-------|                                                                       |-------|" << endl;
	//39
	cout << "|DWE    |                                                                       |MC     |" << endl;
	//40
	cout << "|";
	coutpiece (displaycell[13]);
	cout << "|                                                                       |";
	coutpiece (displaycell[37]);
	cout << "|" << endl;
	//41
	cout << "|_______|                                                                       |_______|" << endl;
	//42
	cout << "|PAC    |                                                                       |COOP   |" << endl;
	//43
	cout << "|       |                                                                       |FEE    |" << endl;
	//44
	cout << "|       |                                                                       |       |" << endl;
	//45
	cout << "|       |                                                                       |       |" << endl;
	//46
	cout << "|_______|                                                                       |_______|" << endl;
	//47
	cout << "|   " <<displaycell[11]->getimpro();
	cout << "   |                                                                       |   ";
	cout << displaycell[39]->getimpro() << "   |" << endl;
	//48
	cout << "|-------|                                                                       |-------|" << endl;
	//49
	cout << "|RCH    |                                                                       |DC     |" << endl;
	//50
	cout << "|";
	coutpiece (displaycell[11]);
	cout << "|                                                                       |";
	coutpiece (displaycell[39]);
	cout << "|" << endl;
	//51
	cout << "|_______|_______________________________________________________________________|_______|" << endl;
	//52
	cout << "|DC Tims|   " << displaycell[9]->getimpro() << "   |   " << displaycell[8]->getimpro();
	cout << "   |NEEDLES|   " << displaycell[6]->getimpro() << "   |MKV    |TUITION|   ";
	cout << displaycell[3]->getimpro() << "   |SLC    |   " << displaycell[1]->getimpro() << "   |COLLECT|" << endl;
	//53
	cout << "|Line   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |" << endl;
	//54
	cout << "|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |" << endl;
	//55
	cout << "|       |";
	coutpiece (displaycell[9]);
	cout << "|";
	coutpiece (displaycell[8]);
	cout << "|       |";
	coutpiece (displaycell[6]);
	cout  << "|       |       |";
	coutpiece (displaycell[3]);
	cout << "|       |";
	coutpiece (displaycell[1]);
	cout << "|       |" << endl;
	//56
	cout << "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|" << endl;
}



