#ifndef DICE_H
#define DICE_H

#include <iostream>

class Dice {
      int val; //face value
      int maxval; //max value of a dice
   public:
   	  //default ctor
   	  Dice();
   	  //default dtor
   	  ~Dice();
   	  // roll will generate a random number between 1 and 6
   	  void roll();
   	  // getter for value
   	  int getVal();
};

#endif

