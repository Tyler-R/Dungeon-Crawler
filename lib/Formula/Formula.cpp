#include "Formula/Formula.h"

Formula::Formula( int numberOfDice, int maxValueOfDice, int levelMultiplier, int constant ) 
		: dice( numberOfDice, maxValueOfDice ), levelMultiplier(levelMultiplier), constant(constant) 
{

}

Formula::~Formula() {

}

int Formula::calculateValue( unsigned int level ) {
	return dice.getDiceRollValue() + (level * levelMultiplier) + constant;
}
