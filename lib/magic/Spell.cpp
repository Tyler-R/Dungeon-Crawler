#include "magic/spell.h"

Spell::Spell( int manaCost, std::shared_ptr<Formula> formula) : manaCost( manaCost ), formula(formula) { //, int manacost, int minLevel

}

Spell::~Spell() {

}

int Spell::getCost() {
	return manaCost;
}
