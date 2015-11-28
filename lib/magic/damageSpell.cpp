#include "magic/damageSpell.h"

DamageSpell::DamageSpell( int manaCost, std::shared_ptr<Formula> formula) : Spell( manaCost, formula ) {

}

DamageSpell::~DamageSpell() {

}

void DamageSpell::castSpell( /*Entity target*/ ) {
	
}
