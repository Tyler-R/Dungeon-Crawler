#pragma once

#include "spell.h"

class HealingSpell : public Spell {
public:
    HealingSpell( int manaCost, int minimiumLevel, std::string name, std::shared_ptr<Formula> formula );
    ~HealingSpell( );


    // TODO: implement a entity class that player and enemy subclass from
    void castSpell( User *caster, Entity *target ) override; 

private:
	// health that the spell heals
};
