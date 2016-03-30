#include "Formula/randomHealthFormula.h"

RandomHealthFormula::RandomHealthFormula( float randomMinMultiplier, int randomMinConstant, 
		float randomMaxMultiplier, int randomMaxConstant )
		: Formula(0,0,0,0), randomMinMultiplier(randomMinMultiplier), randomMinConstant(randomMinConstant),
		randomMaxMultiplier(randomMaxMultiplier), randomMaxConstant(randomMaxConstant) 
{
	
}

RandomHealthFormula::~RandomHealthFormula() {

}

int RandomHealthFormula::calculateValue( User *caster ) {
	srand (time(NULL));

	int min = (int) ( ( caster->getHealth() * randomMinMultiplier) + randomMinConstant );
	int max = (int) ( ( caster->getHealth() * randomMaxMultiplier) + randomMaxConstant );

	int random = ( rand() % ( min - max ) ) + min;

	return random;
}
