#include "magic/spell.h"

Spell::Spell( int manaCost, int minimiumLevel, std::string name, std::shared_ptr<Formula> formula ) 
		: manaCost( manaCost ), minimiumLevel( minimiumLevel ), name( name ), formula( formula ) { //, int manacost, int minLevel

}

Spell::~Spell() {

}

int Spell::getManaCost() {
	return manaCost;
}

int Spell::getMinimiumLevel() {
	return minimiumLevel;
}

std::string Spell::getName() {
	return name;
}

std::shared_ptr<Formula> Spell::getFormula() {
	return formula;
}

