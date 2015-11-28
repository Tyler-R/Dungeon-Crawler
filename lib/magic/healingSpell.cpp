#include "magic/healingSpell.h"

HealingSpell::HealingSpell( int manaCost, std::shared_ptr<Formula> healingFormula) : Spell( manaCost, healingFormula ){
	//, int healingFormula, std::string casterMessage, std::string targetMessage
}

HealingSpell::~HealingSpell() {

}

void HealingSpell::castSpell( /*Entity target*/ ) {
	
}
