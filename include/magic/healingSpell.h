#pragma once

#include "spell.h"

class HealingSpell : public Spell {
public:
    HealingSpell( int manaCost, std::shared_ptr<Formula> healingFormula );
    ~HealingSpell( );


    // TODO: implement a entity class that player and enemy subclass from
    void castSpell( /*Entity target*/ ) override; 

private:
	// health that the spell heals
};
