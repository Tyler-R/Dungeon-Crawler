#pragma once

#include "spell.h"

class HealingSpell : public Spell {
public:
    HealingSpell( int cost, int healing );
    ~HealingSpell( );


    // TODO: implement a entity class that player and enemy subclass from
    void castSpell( /*Entity target*/ ) override; 

private:
	// health that the spell heals
	int healing;
};
