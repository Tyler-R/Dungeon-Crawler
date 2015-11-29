#include "Formula/Formula.h"

Formula::Formula( int numberOfDice, int maxValueOfDice, float levelMultiplier, int constant ) 
		: dice( numberOfDice, maxValueOfDice ), levelMultiplier(levelMultiplier), constant(constant) 
{

}

Formula::~Formula() {

}

int Formula::calculateValue( User *caster ) {
	return (dice.getDiceRollValue() + (caster->getLevel() * levelMultiplier) + constant);
}
