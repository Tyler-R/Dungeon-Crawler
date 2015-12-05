#include "Formula/Dice.h"

Dice::Dice( int numberOfDie, int dieMaxValue ) : numberOfDie( numberOfDie ), dieMaxValue( dieMaxValue ) {

}

Dice::~Dice() {

}

int Dice::getDiceRollValue() {
	int result = 0;
	
	srand (time(NULL));

	for( int i = 0; i < numberOfDie; i++ ) {
		result += ( rand() % dieMaxValue );
	}

	return numberOfDie * dieMaxValue;
}