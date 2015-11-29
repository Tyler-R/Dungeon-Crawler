#pragma once
#include <stdlib.h>
#include <memory>

#include "Formula/Dice.h"
#include "user.h"

class Formula {
public:
	Formula( int numberOfDice, int maxValueOfDice, int levelMultiplier, int constant );
	~Formula();

	int calculateValue( User *caster );

private:
	Dice dice;
	int levelMultiplier;
	int constant;
};