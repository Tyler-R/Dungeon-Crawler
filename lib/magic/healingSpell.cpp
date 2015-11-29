#include "magic/healingSpell.h"

HealingSpell::HealingSpell( int manaCost, int minimiumLevel, std::string name, std::shared_ptr<Formula> formula) 
		: Spell( manaCost, minimiumLevel, name, formula ) {
	//, int healingFormula, std::string casterMessage, std::string targetMessage
}

HealingSpell::~HealingSpell() {

}

void HealingSpell::castSpell( User *caster, Entity *target ) {
	int healingAmount = getFormula()->calculateValue( caster->getLevel() );
	caster->notifySession("you cast " + getName() + " healing " + to_string( healingAmount ) + " health");

	target->heal( healingAmount );
}
