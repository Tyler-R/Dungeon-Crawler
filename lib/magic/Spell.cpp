#include "magic/spell.h"

Spell::Spell( int cost ) : cost( cost ) {

}

Spell::~Spell() {

}

int Spell::getCost() {
	return cost;
}
