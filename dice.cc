#include "dice.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Dice::Dice():val(0),maxval(6){}

Dice::~Dice(){}

// see "dice.h"
void Dice::roll(){
	// init random seeds
	
	int temp=0;
	temp = rand() % maxval + 1; // random a number from 1 to 6
	val = temp;
}

int Dice::getVal(){
	return val;
}

