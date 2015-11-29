#pragma once
#include <stdlib.h>
#include <time.h>  

class Dice {
public:
	Dice( int numberOfDie, int dieMaxValue );
	~Dice();

	int getDiceRollValue();

private:
	int numberOfDie;
	int dieMaxValue;
};