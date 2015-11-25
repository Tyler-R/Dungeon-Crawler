#include "Formula/Dice.h"

Dice::Dice( int numberOfDie, int dieMaxValue ) : numberOfDie( numberOfDie ), dieMaxValue( dieMaxValue ) {

}

Dice::~Dice() {

}

int Dice::getDiceRollValue() {
	int result = 0;

	for( int i = 0; i < numberOfDie; i++ ) {
		result += ( random() % dieMaxValue );
	}

	return numberOfDie * dieMaxValue;
}