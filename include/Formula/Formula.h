#pragma once
#include <stdlib.h>
#include <memory>

#include "Formula/Dice.h"

class Formula {
public:
	Formula( int numberOfDice, int maxValueOfDice, int levelMultiplier, int constant );
	~Formula();

	int calculateValue( unsigned int level );

private:
	Dice dice;
	int levelMultiplier;
	int constant;
};