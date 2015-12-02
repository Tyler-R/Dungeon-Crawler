#pragma once
#include <stdlib.h>
#include <time.h>  

#include "Formula/Formula.h"

class RandomHealthFormula : public Formula {
public:
	RandomHealthFormula( float randomMinMultiplier, int randomMinConstant, 
						 float randomMaxMultiplier, int randomMaxConstant );

	~RandomHealthFormula();

	int calculateValue( User *caster ) ; // override;
private:
	float randomMinMultiplier;
	int randomMinConstant;
	float randomMaxMultiplier;
	int randomMaxConstant;
};